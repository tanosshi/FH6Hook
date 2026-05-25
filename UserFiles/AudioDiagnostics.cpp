#include "AudioDiagnostics.h"
#include "FmodEngine.h"
#include "RadioTracker.h"
#include <windows.h>
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <mutex>

#if FH6_USE_DETOURS
#include <detours.h>
#endif

extern void PipeWriteLine(const std::string& line);
extern void LogInfo(const std::string& m);
extern void LogWarn(const std::string& m);

// ============================================================
//  Output queue written from hook thread, flushed on tick thread.
//  !! PipeWriteLine must NEVER be called from inside a hook.
// ============================================================
namespace {

    static std::mutex               g_outMtx;
    static std::vector<std::string> g_outQueue;
    static ULONGLONG                g_startTick = GetTickCount64();
    static ULONGLONG                g_readWindowUntil = 0;
    static constexpr DWORD          kReadWindowMs = 60000;
    static constexpr DWORD          kStopAfterMs = 7000;
    static constexpr DWORD          kPingEveryMs = 2000;
    static constexpr bool           kDebugReadOffsets = false;
    static std::mutex               g_readWindowMtx;
    static std::string              g_readWindowPrefix;
    static const std::unordered_map<std::string, TrackInfo>* g_trackTable = nullptr;

    struct BankRange {
        unsigned long long start = 0;
        unsigned long long end = 0;
        const TrackInfo* track = nullptr;
    };

    static std::mutex g_rangeMtx;
    static std::unordered_map<std::string, std::vector<BankRange>> g_bankRanges;
    static std::mutex g_musicMtx;
    static std::string g_currentPlay;
    static ULONGLONG g_lastMusicReadAt = 0;
    static ULONGLONG g_lastPingAt = 0;

    static void Enqueue(std::string line) {
        std::lock_guard<std::mutex> lk(g_outMtx);
        if (g_outQueue.size() < 512)
            g_outQueue.push_back(std::move(line));
    }

    static std::string BaseName(const std::string& path) {
        size_t p = path.find_last_of("\\/");
        return (p == std::string::npos) ? path : path.substr(p + 1);
    }

    static std::string ExeDir() {
        char path[MAX_PATH]{};
        GetModuleFileNameA(nullptr, path, MAX_PATH);
        std::string s(path);
        size_t p = s.find_last_of("\\/");
        return p == std::string::npos ? std::string() : s.substr(0, p + 1);
    }

    static std::string ResolvePath(const std::string& path) {
        if (path.size() > 2 && path[1] == ':') return path;
        if (path.rfind(".\\", 0) == 0 || path.rfind("./", 0) == 0) return ExeDir() + path.substr(2);
        return ExeDir() + path;
    }

    static std::string ToHex64(unsigned long long v) {
        static const char* digits = "0123456789ABCDEF";
        char buf[19]{};
        buf[0] = '0';
        buf[1] = 'x';
        bool started = false;
        int pos = 2;
        for (int shift = 60; shift >= 0; shift -= 4) {
            unsigned nibble = static_cast<unsigned>((v >> shift) & 0xF);
            if (nibble || started || shift == 0) {
                buf[pos++] = digits[nibble];
                started = true;
            }
        }
        return std::string(buf);
    }

    // ============================================================
    //  CreateFileW hook
    // ============================================================
    static bool g_hooksInstalled = false;

    typedef HANDLE(WINAPI* PFN_CreateFileW)(
        LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
    static PFN_CreateFileW g_origCreateFileW = nullptr;

    typedef BOOL(WINAPI* PFN_ReadFile)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED);
    static PFN_ReadFile g_origReadFile = nullptr;

    typedef BOOL(WINAPI* PFN_CloseHandle)(HANDLE);
    static PFN_CloseHandle g_origCloseHandle = nullptr;

    struct BankHandleInfo {
        std::string path;
        std::string base;
        unsigned readLogs = 0;
    };

    static std::mutex g_handleMtx;
    static std::unordered_map<HANDLE, BankHandleInfo> g_bankHandles;

    static std::string WideToUtf8(LPCWSTR w) {
        if (!w) return "";
        int n = WideCharToMultiByte(CP_UTF8, 0, w, -1, nullptr, 0, nullptr, nullptr);
        if (n <= 1) return "";
        std::string out(static_cast<size_t>(n - 1), '\0');
        WideCharToMultiByte(CP_UTF8, 0, w, -1, &out[0], n, nullptr, nullptr);
        return out;
    }

    static std::string ToLower(std::string s) {
        for (auto& c : s)
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        return s;
    }

    static int StationFromSound(const std::string& sound) {
        if (sound.rfind("HZ6_R", 0) != 0) return 0;
        size_t p = 5;
        int n = 0;
        while (p < sound.size() && sound[p] >= '0' && sound[p] <= '9') {
            n = n * 10 + (sound[p] - '0');
            ++p;
        }
        return n;
    }

    static int StationFromBank(const std::string& bank) {
        std::string lower = ToLower(bank);
        size_t r = lower.find('r');
        size_t marker = lower.find("_tracks_");
        if (r == std::string::npos || marker == std::string::npos || r + 1 >= marker) return 0;
        int n = 0;
        for (size_t i = r + 1; i < marker; ++i) {
            if (lower[i] < '0' || lower[i] > '9') return 0;
            n = n * 10 + (lower[i] - '0');
        }
        return n;
    }

    static unsigned long long Bits(unsigned long long value, int start, int length) {
        return (value >> start) & ((1ULL << length) - 1ULL);
    }

    static bool ReadAllBytes(const std::string& path, std::vector<unsigned char>& out) {
        std::ifstream f(path, std::ios::binary);
        if (!f) return false;
        f.seekg(0, std::ios::end);
        std::streamoff size = f.tellg();
        if (size <= 0) return false;
        f.seekg(0, std::ios::beg);
        out.resize(static_cast<size_t>(size));
        return static_cast<bool>(f.read(reinterpret_cast<char*>(out.data()), size));
    }

    static uint32_t U32(const std::vector<unsigned char>& d, size_t p) {
        if (p + 4 > d.size()) return 0;
        return static_cast<uint32_t>(d[p])
            | (static_cast<uint32_t>(d[p + 1]) << 8)
            | (static_cast<uint32_t>(d[p + 2]) << 16)
            | (static_cast<uint32_t>(d[p + 3]) << 24);
    }

    static uint64_t U64(const std::vector<unsigned char>& d, size_t p) {
        uint64_t v = 0;
        for (int i = 0; i < 8 && p + i < d.size(); ++i)
            v |= static_cast<uint64_t>(d[p + i]) << (i * 8);
        return v;
    }

    struct FsbSample {
        unsigned long long dataOffset = 0;
        unsigned long long decodedSamples = 0;
    };

    static std::vector<BankRange> BuildRangesForBank(const std::string& path, const std::string& bank) {
        std::vector<BankRange> ranges;
        if (!g_trackTable) return ranges;

        const int station = StationFromBank(bank);
        if (station <= 0) return ranges;

        std::unordered_map<unsigned long long, const TrackInfo*> uniqueByLength;
        std::unordered_map<unsigned long long, int> counts;
        for (const auto& kv : *g_trackTable) {
            const TrackInfo& t = kv.second;
            if (t.sampleType != "Track" || t.artist.empty() || t.displayName.empty()) continue;
            if (StationFromSound(t.soundName) != station || t.sampleLength == 0) continue;
            uniqueByLength[t.sampleLength] = &t;
            counts[t.sampleLength]++;
        }

        std::vector<unsigned char> data;
        if (!ReadAllBytes(ResolvePath(path), data)) return ranges;
        auto it = std::search(data.begin(), data.end(), "FSB5", "FSB5" + 4);
        if (it == data.end()) return ranges;
        const size_t fsb = static_cast<size_t>(it - data.begin());
        if (fsb + 0x40 > data.size()) return ranges;

        const uint32_t version = U32(data, fsb + 4);
        const uint32_t sampleCount = U32(data, fsb + 8);
        const uint32_t sampleHeadersSize = U32(data, fsb + 12);
        const uint32_t nameTableSize = U32(data, fsb + 16);
        const uint32_t dataSize = U32(data, fsb + 20);
        const size_t headerSize = version == 0 ? 0x40 : 0x3C;
        size_t p = fsb + headerSize;

        std::vector<FsbSample> samples;
        for (uint32_t i = 0; i < sampleCount && p + 8 <= data.size(); ++i) {
            const uint64_t raw = U64(data, p);
            p += 8;
            bool nextChunk = Bits(raw, 0, 1) != 0;
            FsbSample s;
            s.dataOffset = Bits(raw, 6, 28) * 16ULL;
            s.decodedSamples = Bits(raw, 34, 30);

            while (nextChunk && p + 4 <= data.size()) {
                const uint32_t chunk = U32(data, p);
                p += 4;
                nextChunk = Bits(chunk, 0, 1) != 0;
                const unsigned long long chunkSize = Bits(chunk, 1, 24);
                if (p + chunkSize > data.size()) break;
                p += static_cast<size_t>(chunkSize);
            }
            samples.push_back(s);
        }

        const unsigned long long dataStart = static_cast<unsigned long long>(fsb + headerSize + sampleHeadersSize + nameTableSize);
        for (size_t i = 0; i < samples.size(); ++i) {
            if (counts[samples[i].decodedSamples] != 1) continue;
            const TrackInfo* track = uniqueByLength[samples[i].decodedSamples];
            const unsigned long long start = dataStart + samples[i].dataOffset;
            const unsigned long long nextOffset = (i + 1 < samples.size()) ? samples[i + 1].dataOffset : dataSize;
            ranges.push_back(BankRange{ start, dataStart + nextOffset, track });
        }
        return ranges;
    }

    static const TrackInfo* FindTrackForRead(const BankHandleInfo& info, unsigned long long offset) {
        const std::string bank = ToLower(info.base);
        std::lock_guard<std::mutex> lk(g_rangeMtx);
        auto it = g_bankRanges.find(bank);
        if (it == g_bankRanges.end())
            it = g_bankRanges.emplace(bank, BuildRangesForBank(info.path, bank)).first;
        for (const auto& r : it->second) {
            if (offset >= r.start && offset < r.end)
                return r.track;
        }
        return nullptr;
    }

    static void NoteMusicRead(const TrackInfo& t) {
        const ULONGLONG now = GetTickCount64();
        const std::string play = "PLAY|" + t.artist + " - " + t.displayName + " [" + t.station + "]";
        const std::string ping = "PING|" + t.artist + " - " + t.displayName + " [" + t.station + "]";
        std::lock_guard<std::mutex> lk(g_musicMtx);
        g_lastMusicReadAt = now;
        if (play != g_currentPlay) {
            g_currentPlay = play;
            g_lastPingAt = now;
            Enqueue(play);
        } else if (now - g_lastPingAt >= kPingEveryMs) {
            g_lastPingAt = now;
            Enqueue(ping);
        }
    }

    static void CheckMusicStop() {
        std::lock_guard<std::mutex> lk(g_musicMtx);
        if (g_currentPlay.empty() || GetTickCount64() - g_lastMusicReadAt < kStopAfterMs)
            return;
        std::string last = g_currentPlay.substr(5);
        g_currentPlay.clear();
        g_lastMusicReadAt = 0;
        g_lastPingAt = 0;
        Enqueue("STOP|music_inactive|last=" + last);
    }

    static bool IsRadioTrackBank(const std::string& lower) {
        return lower.find("fmodbanks") != std::string::npos
            && lower.find("_tracks_") != std::string::npos
            && lower.find(".bank") != std::string::npos;
    }

    static bool ReadWindowActive(std::string& prefixOut) {
        std::lock_guard<std::mutex> lk(g_readWindowMtx);
        if (GetTickCount64() > g_readWindowUntil)
            return false;
        prefixOut = g_readWindowPrefix;
        return true;
    }

    static bool TryGetBankHandleInfo(HANDLE h, BankHandleInfo& out) {
        std::lock_guard<std::mutex> lk(g_handleMtx);
        auto it = g_bankHandles.find(h);
        if (it == g_bankHandles.end())
            return false;
        if (it->second.readLogs >= 512)
            return false;
        ++it->second.readLogs;
        out = it->second;
        return true;
    }

    static void RememberBankHandle(HANDLE h, const std::string& path) {
        if (!h || h == INVALID_HANDLE_VALUE)
            return;
        std::lock_guard<std::mutex> lk(g_handleMtx);
        if (g_bankHandles.size() < 128)
            g_bankHandles[h] = BankHandleInfo{ path, BaseName(path), 0 };
    }

    static void ForgetHandle(HANDLE h) {
        std::lock_guard<std::mutex> lk(g_handleMtx);
        g_bankHandles.erase(h);
    }

    // Check if its aradio bank, queue log line. Should return immediately
    static HANDLE WINAPI Hook_CreateFileW(
        LPCWSTR name, DWORD access, DWORD share,
        LPSECURITY_ATTRIBUTES sa, DWORD disp, DWORD attrs, HANDLE tmpl)
    {
        HANDLE result = g_origCreateFileW(name, access, share, sa, disp, attrs, tmpl);

        // Do all work AFTER the original call so we never delay the game's open.
        if (name) {
            std::string path = WideToUtf8(name);
            std::string lower = ToLower(path);
            if (IsRadioTrackBank(lower)) {
                RememberBankHandle(result, path);
                RadioTrackerQueueBankFile(path);
                Enqueue("FILE|path=" + path);
            }
        }

        return result;
    }

    static BOOL WINAPI Hook_ReadFile(
        HANDLE file, LPVOID buffer, DWORD bytesToRead, LPDWORD bytesRead, LPOVERLAPPED overlapped)
    {
        BOOL ok = g_origReadFile(file, buffer, bytesToRead, bytesRead, overlapped);
        DWORD lastError = GetLastError();

        std::string prefix;
        if (GetTickCount64() - g_startTick < 25000 || !ReadWindowActive(prefix)) {
            SetLastError(lastError);
            return ok;
        }

        BankHandleInfo info;
        if (!TryGetBankHandleInfo(file, info)) {
            SetLastError(lastError);
            return ok;
        }

        DWORD actual = bytesRead ? *bytesRead : 0;
        unsigned long long offset = 0;
        bool hasOffset = false;
        if (overlapped) {
            offset = (static_cast<unsigned long long>(overlapped->OffsetHigh) << 32) | overlapped->Offset;
            hasOffset = true;
        } else {
            LARGE_INTEGER zero{};
            LARGE_INTEGER pos{};
            if (SetFilePointerEx(file, zero, &pos, FILE_CURRENT)) {
                const unsigned long long cur = static_cast<unsigned long long>(pos.QuadPart);
                offset = cur >= actual ? cur - actual : cur;
                hasOffset = true;
            }
        }

        if (hasOffset) {
            if (const TrackInfo* track = FindTrackForRead(info, offset))
                NoteMusicRead(*track);
        }

        if (kDebugReadOffsets) {
            Enqueue("READ|prefix=" + prefix
                + "|bank=" + info.base
                + "|ok=" + std::to_string(ok ? 1 : 0)
                + "|req=" + std::to_string(bytesToRead)
                + "|got=" + std::to_string(actual)
                + "|ov=" + std::to_string(overlapped ? 1 : 0)
                + "|offset=" + (hasOffset ? ToHex64(offset) : std::string("unknown")));
        }

        SetLastError(lastError);
        return ok;
    }

    static BOOL WINAPI Hook_CloseHandle(HANDLE h)
    {
        ForgetHandle(h);
        return g_origCloseHandle(h);
    }

} // namespace

// ============================================================
//  Public API
// ============================================================

void InstallAudioDiagnosticHooks()
{
    if (g_hooksInstalled) return;
#if !FH6_USE_DETOURS
    LogWarn("Hooks disabled (FH6_USE_DETOURS=0)");
    return;
#else
    HMODULE k32 = GetModuleHandleA("kernel32.dll");
    if (!k32) { LogWarn("InstallAudioDiagnosticHooks: kernel32 not found"); return; }

    g_origCreateFileW = reinterpret_cast<PFN_CreateFileW>(
        GetProcAddress(k32, "CreateFileW"));
    if (!g_origCreateFileW) { LogWarn("InstallAudioDiagnosticHooks: CreateFileW not found"); return; }
    g_origReadFile = reinterpret_cast<PFN_ReadFile>(
        GetProcAddress(k32, "ReadFile"));
    if (!g_origReadFile) { LogWarn("InstallAudioDiagnosticHooks: ReadFile not found"); return; }
    g_origCloseHandle = reinterpret_cast<PFN_CloseHandle>(
        GetProcAddress(k32, "CloseHandle"));
    if (!g_origCloseHandle) { LogWarn("InstallAudioDiagnosticHooks: CloseHandle not found"); return; }

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    if (DetourAttach(reinterpret_cast<PVOID*>(&g_origCreateFileW), Hook_CreateFileW) != NO_ERROR) {
        DetourTransactionAbort();
        LogWarn("CreateFileW DetourAttach failed");
        return;
    }
    if (DetourAttach(reinterpret_cast<PVOID*>(&g_origReadFile), Hook_ReadFile) != NO_ERROR) {
        DetourTransactionAbort();
        LogWarn("ReadFile DetourAttach failed");
        return;
    }
    if (DetourAttach(reinterpret_cast<PVOID*>(&g_origCloseHandle), Hook_CloseHandle) != NO_ERROR) {
        DetourTransactionAbort();
        LogWarn("CloseHandle DetourAttach failed");
        return;
    }
    if (DetourTransactionCommit() != NO_ERROR) {
        LogWarn("CreateFileW DetourTransactionCommit failed");
        return;
    }

    g_hooksInstalled = true;
    LogInfo("Hooked CreateFileW/ReadFile/CloseHandle (radio bank read telemetry)");
#endif
}

void AudioDiagnosticsArmReadWindow(const std::string& stationPrefix)
{
    std::lock_guard<std::mutex> lk(g_readWindowMtx);
    g_readWindowPrefix = stationPrefix;
    g_readWindowUntil = GetTickCount64() + kReadWindowMs;
    PipeWriteLine("READ|armed|prefix=" + stationPrefix + "|window_ms=" + std::to_string(kReadWindowMs));
}

void AudioDiagnosticsSetTrackTable(const std::unordered_map<std::string, TrackInfo>* table)
{
    std::lock_guard<std::mutex> lk(g_rangeMtx);
    g_trackTable = table;
    g_bankRanges.clear();
}

// Called from RadioTrackerTick, its safe now
std::vector<uintptr_t> FlushStackQueue()
{
    // Flush text
    std::vector<std::string> batch;
    {
        std::lock_guard<std::mutex> lk(g_outMtx);
        if (!g_outQueue.empty()) batch.swap(g_outQueue);
    }
    for (const auto& line : batch)
        PipeWriteLine(line);

    // this code is dead
    return {};
}

void RunPeriodicDiagnostics()
{
    CheckMusicStop();
    FlushStackQueue();
    RadioTrackerTick();
}
