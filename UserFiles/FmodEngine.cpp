#include "FmodEngine.h"

#include <windows.h>
#include <psapi.h>

#include <cstdint>
#include <cstring>
#include <mutex>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "detours.h"

namespace FmodHookConfig {
    constexpr bool kEnableExeTextDetours = false;
    constexpr bool kEnableRdataSlotHook = false;
    constexpr uintptr_t kCandidateRvas[] = {
        0x6AC0, 0x6980, 0x67F0,
        0x7310, 0x7330, 0x7350, 0x7370, 0x7390, 0x73B0, 0x73D0, 0x73F0, 0x7410, 0x7430,
    };
    struct SlotCandidate {
        uintptr_t slotRva;
        uintptr_t targetRva;
    };
    constexpr SlotCandidate kSlotCandidates[] = {
        { 0x6325758, 0x6AC0 },
        { 0x6325760, 0x67F0 },
        { 0x6325778, 0x6980 },
        { 0x6325840, 0x7330 },
        { 0x6325890, 0x7370 },
        { 0x63258A0, 0x7350 },
        { 0x63258C0, 0x7430 },
        { 0x63258E0, 0x7310 },
        { 0x63258F0, 0x7390 },
        { 0x6325900, 0x73B0 },
        { 0x6325910, 0x73D0 },
        { 0x6325920, 0x73F0 },
        { 0x6325930, 0x7410 },
    };

    constexpr DWORD kHookWindowMs = 2500;
    constexpr DWORD kSlotHookWindowMs = 10000;
    constexpr DWORD kRearmCooldownMs = 1200;
}

extern void PipeWriteLine(const std::string& line);

extern "C" void FmodGhostDetour();
extern "C" void* g_fmodGhostOriginal = nullptr;

static uintptr_t g_exeBase = 0;
static bool g_hooksInstalled = false;
static bool g_allStationsReady = false;
static DWORD64 g_burstUntil = 0;
static DWORD64 g_hookRemoveAt = 0;
static DWORD64 g_nextInstallAllowedAt = 0;
static uint32_t g_fireCount = 0;
static uint32_t g_fireCountAtInstall = 0;
static size_t g_candidateIndex = 0;
static bool g_slotHookInstalled = false;
static uintptr_t g_slotHookSlot = 0;
static uintptr_t g_slotHookOriginalValue = 0;
static DWORD64 g_slotHookRemoveAt = 0;
static uint32_t g_slotFireCountAtInstall = 0;
static size_t g_slotCandidateIndex = 0;
static bool g_pointerScanDone = false;
static std::set<int> g_stationNumbersSeen;
static std::string g_stationPrefix;
static const std::unordered_map<std::string, TrackInfo>* g_table = nullptr;

static std::mutex g_outMtx;
static std::vector<std::string> g_outQueue;

static void QueueLine(std::string line)
{
    std::lock_guard<std::mutex> lk(g_outMtx);
    if (g_outQueue.size() < 128)
        g_outQueue.push_back(std::move(line));
}

static void FlushQueuedLines()
{
    std::vector<std::string> batch;
    {
        std::lock_guard<std::mutex> lk(g_outMtx);
        if (!g_outQueue.empty())
            batch.swap(g_outQueue);
    }

    for (const auto& line : batch)
        PipeWriteLine(line);
}

static std::string ToHex(uintptr_t v)
{
    static const char* digits = "0123456789ABCDEF";
    char tmp[2 + sizeof(uintptr_t) * 2 + 1]{};
    tmp[0] = '0';
    tmp[1] = 'x';

    bool started = false;
    int pos = 2;
    for (int shift = static_cast<int>((sizeof(uintptr_t) * 8) - 4); shift >= 0; shift -= 4) {
        unsigned nibble = static_cast<unsigned>((v >> shift) & 0xF);
        if (nibble || started || shift == 0) {
            tmp[pos++] = digits[nibble];
            started = true;
        }
    }
    tmp[pos] = '\0';
    return std::string(tmp);
}

static void Pipe(const char* phase, const std::string& msg)
{
    PipeWriteLine(std::string("FMOD|phase=") + phase + "|" + msg);
}

static bool IsReadableProtect(DWORD protect)
{
    protect &= 0xFF;
    return protect == PAGE_READONLY
        || protect == PAGE_READWRITE
        || protect == PAGE_WRITECOPY
        || protect == PAGE_EXECUTE_READ
        || protect == PAGE_EXECUTE_READWRITE
        || protect == PAGE_EXECUTE_WRITECOPY;
}

static bool IsSafeString(uintptr_t ptr, char* outBuf, size_t maxLen)
{
    if (!ptr || !outBuf || maxLen < 8)
        return false;

    MEMORY_BASIC_INFORMATION mbi{};
    if (VirtualQuery(reinterpret_cast<LPCVOID>(ptr), &mbi, sizeof(mbi)) == 0)
        return false;
    if (mbi.State != MEM_COMMIT || (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)))
        return false;
    if (!IsReadableProtect(mbi.Protect))
        return false;
    if (IsBadReadPtr(reinterpret_cast<const void*>(ptr), 8))
        return false;

    __try {
        const char* s = reinterpret_cast<const char*>(ptr);
        const bool hz6 = s[0] == 'H' && s[1] == 'Z' && s[2] == '6' && s[3] == '_' && s[4] == 'R';
        const bool eventPath = s[0] == 'e' && s[1] == 'v' && s[2] == 'e' && s[3] == 'n'
            && s[4] == 't' && s[5] == ':' && s[6] == '/';
        if (!hz6 && !eventPath)
            return false;

        size_t i = 0;
        for (; i < maxLen - 1 && s[i] != '\0'; ++i) {
            if (s[i] < 32 || s[i] > 126)
                return false;
            outBuf[i] = s[i];
        }
        outBuf[i] = '\0';
        return i >= 5;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

static bool TryReadBytes(uintptr_t address, unsigned char* out, size_t len)
{
    __try {
        memcpy(out, reinterpret_cast<const void*>(address), len);
        return true;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

static const char* ProtectName(DWORD protect)
{
    protect &= 0xFF;
    switch (protect) {
    case PAGE_READONLY: return "R";
    case PAGE_READWRITE: return "RW";
    case PAGE_WRITECOPY: return "WC";
    case PAGE_EXECUTE: return "X";
    case PAGE_EXECUTE_READ: return "XR";
    case PAGE_EXECUTE_READWRITE: return "XRW";
    case PAGE_EXECUTE_WRITECOPY: return "XWC";
    default: return "?";
    }
}

static bool GetSectionName(uintptr_t moduleBase, uintptr_t address, char out[9])
{
    memset(out, 0, 9);
    auto* base = reinterpret_cast<uint8_t*>(moduleBase);
    auto* dos = reinterpret_cast<IMAGE_DOS_HEADER*>(base);
    if (dos->e_magic != IMAGE_DOS_SIGNATURE)
        return false;
    auto* nt = reinterpret_cast<IMAGE_NT_HEADERS64*>(base + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE)
        return false;

    auto* sec = IMAGE_FIRST_SECTION(nt);
    const uintptr_t rva = address - moduleBase;
    for (int i = 0; i < nt->FileHeader.NumberOfSections; ++i, ++sec) {
        const uintptr_t start = sec->VirtualAddress;
        const uintptr_t size = sec->Misc.VirtualSize > sec->SizeOfRawData
            ? sec->Misc.VirtualSize
            : sec->SizeOfRawData;
        if (rva >= start && rva < start + size) {
            memcpy(out, sec->Name, 8);
            out[8] = '\0';
            return true;
        }
    }
    return false;
}

static bool RegionReadable(const MEMORY_BASIC_INFORMATION& mbi)
{
    if (mbi.State != MEM_COMMIT || (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)))
        return false;
    return IsReadableProtect(mbi.Protect);
}

static void ScanDataPointersToCandidates()
{
    if (g_pointerScanDone)
        return;
    g_pointerScanDone = true;

    g_exeBase = reinterpret_cast<uintptr_t>(GetModuleHandleW(nullptr));
    MODULEINFO mi{};
    if (!GetModuleInformation(GetCurrentProcess(), reinterpret_cast<HMODULE>(g_exeBase), &mi, sizeof(mi))) {
        Pipe("PTRSCAN", "failed|get_module_information");
        return;
    }

    const uintptr_t exeStart = reinterpret_cast<uintptr_t>(mi.lpBaseOfDll);
    const uintptr_t exeEnd = exeStart + mi.SizeOfImage;
    Pipe("PTRSCAN", "begin|exe=" + ToHex(exeStart) + "|size=" + ToHex(mi.SizeOfImage));

    size_t totalHits = 0;
    MEMORY_BASIC_INFORMATION mbi{};
    for (uintptr_t addr = exeStart; addr < exeEnd;) {
        if (!VirtualQuery(reinterpret_cast<LPCVOID>(addr), &mbi, sizeof(mbi)))
            break;

        const uintptr_t regionBase = reinterpret_cast<uintptr_t>(mbi.BaseAddress);
        const uintptr_t rawRegionEnd = regionBase + mbi.RegionSize;
        const uintptr_t regionEnd = rawRegionEnd < exeEnd ? rawRegionEnd : exeEnd;

        if (RegionReadable(mbi)) {
            const uintptr_t scanStart = addr > regionBase ? addr : regionBase;
            for (uintptr_t p = scanStart; p + sizeof(uintptr_t) <= regionEnd; p += sizeof(uintptr_t)) {
                uintptr_t value = 0;
                if (!TryReadBytes(p, reinterpret_cast<unsigned char*>(&value), sizeof(value)))
                    continue;

                for (size_t i = 0; i < sizeof(FmodHookConfig::kCandidateRvas) / sizeof(FmodHookConfig::kCandidateRvas[0]); ++i) {
                    const uintptr_t target = exeStart + FmodHookConfig::kCandidateRvas[i];
                    if (value != target)
                        continue;

                    char secName[9]{};
                    if (!GetSectionName(exeStart, p, secName))
                        strcpy_s(secName, "?");

                    const bool writable = (mbi.Protect & (PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)) != 0;
                    Pipe("PTRSCAN", "hit|slot=" + ToHex(p)
                        + "|slot_rva=" + ToHex(p - exeStart)
                        + "|target_rva=" + ToHex(FmodHookConfig::kCandidateRvas[i])
                        + "|section=" + secName
                        + "|protect=" + ProtectName(mbi.Protect)
                        + "|writable=" + std::to_string(writable ? 1 : 0));

                    ++totalHits;
                    if (totalHits >= 256) {
                        Pipe("PTRSCAN", "truncated|hits=256");
                        Pipe("PTRSCAN", "end|hits=" + std::to_string(totalHits));
                        return;
                    }
                }
            }
        }

        addr = regionEnd > addr ? regionEnd : addr + 0x1000;
    }

    Pipe("PTRSCAN", "end|hits=" + std::to_string(totalHits));
}

static bool WritePointerSlot(uintptr_t slot, uintptr_t value)
{
    DWORD oldProtect = 0;
    if (!VirtualProtect(reinterpret_cast<void*>(slot), sizeof(uintptr_t), PAGE_READWRITE, &oldProtect))
        return false;

    *reinterpret_cast<uintptr_t*>(slot) = value;

    DWORD ignored = 0;
    VirtualProtect(reinterpret_cast<void*>(slot), sizeof(uintptr_t), oldProtect, &ignored);
    return true;
}

static bool TryInstallRdataSlotHook()
{
    if (!FmodHookConfig::kEnableRdataSlotHook || g_slotHookInstalled || !g_allStationsReady)
        return g_slotHookInstalled;

    g_exeBase = reinterpret_cast<uintptr_t>(GetModuleHandleW(nullptr));
    const size_t count = sizeof(FmodHookConfig::kSlotCandidates) / sizeof(FmodHookConfig::kSlotCandidates[0]);
    const auto& c = FmodHookConfig::kSlotCandidates[g_slotCandidateIndex % count];
    const uintptr_t slot = g_exeBase + c.slotRva;
    const uintptr_t expected = g_exeBase + c.targetRva;

    uintptr_t current = 0;
    if (!TryReadBytes(slot, reinterpret_cast<unsigned char*>(&current), sizeof(current))) {
        Pipe("SLOTHOOK", "slot_unreadable|slot_rva=" + ToHex(c.slotRva));
        ++g_slotCandidateIndex;
        return false;
    }

    if (current != expected) {
        Pipe("SLOTHOOK", "slot_mismatch|slot_rva=" + ToHex(c.slotRva)
            + "|expected=" + ToHex(expected)
            + "|current=" + ToHex(current));
        ++g_slotCandidateIndex;
        return false;
    }

    g_fmodGhostOriginal = reinterpret_cast<void*>(current);
    if (!WritePointerSlot(slot, reinterpret_cast<uintptr_t>(FmodGhostDetour))) {
        Pipe("SLOTHOOK", "slot_write_failed|slot_rva=" + ToHex(c.slotRva)
            + "|target_rva=" + ToHex(c.targetRva));
        ++g_slotCandidateIndex;
        return false;
    }

    g_slotHookInstalled = true;
    g_slotHookSlot = slot;
    g_slotHookOriginalValue = current;
    g_slotHookRemoveAt = GetTickCount64() + FmodHookConfig::kSlotHookWindowMs;
    g_slotFireCountAtInstall = g_fireCount;

    Pipe("SLOTHOOK", "installed|slot_rva=" + ToHex(c.slotRva)
        + "|target_rva=" + ToHex(c.targetRva)
        + "|candidate=" + std::to_string(g_slotCandidateIndex)
        + "|remove_in_ms=" + std::to_string(FmodHookConfig::kSlotHookWindowMs));
    return true;
}

static void TryRemoveRdataSlotHook()
{
    if (!g_slotHookInstalled)
        return;

    const size_t count = sizeof(FmodHookConfig::kSlotCandidates) / sizeof(FmodHookConfig::kSlotCandidates[0]);
    const auto& c = FmodHookConfig::kSlotCandidates[g_slotCandidateIndex % count];
    const uint32_t firesThisWindow = g_fireCount - g_slotFireCountAtInstall;

    if (WritePointerSlot(g_slotHookSlot, g_slotHookOriginalValue)) {
        Pipe("SLOTHOOK", "removed|slot_rva=" + ToHex(c.slotRva)
            + "|target_rva=" + ToHex(c.targetRva)
            + "|window_fires=" + std::to_string(firesThisWindow));
    } else {
        Pipe("SLOTHOOK", "remove_failed|slot_rva=" + ToHex(c.slotRva));
    }

    g_slotHookInstalled = false;
    g_slotHookSlot = 0;
    g_slotHookOriginalValue = 0;
    if (firesThisWindow == 0)
        ++g_slotCandidateIndex;
}

static const char* SoundNameFromPath(const char* path)
{
    if (!path)
        return nullptr;

    const char* marker = strstr(path, "HZ6_R");
    return marker ? marker : path;
}

static void NotifyTrackPlayed(const char* path)
{
    if (!g_table || !path || !g_allStationsReady)
        return;

    const DWORD64 now = GetTickCount64();
    if (now > g_burstUntil)
        return;

    const char* soundName = SoundNameFromPath(path);
    if (!soundName || strncmp(soundName, "HZ6_R", 5) != 0)
        return;

    std::string sn(soundName);
    if (!g_stationPrefix.empty() && sn.rfind(g_stationPrefix, 0) != 0)
        return;

    auto it = g_table->find(sn);
    if (it == g_table->end() || it->second.sampleType != "Track")
        return;

    const auto& t = it->second;
    QueueLine("PLAY|" + t.artist + " - " + t.displayName + " [" + t.station + "]");

    // One successful hit is enough for this arm window.
    g_burstUntil = now;
}

extern "C" void __fastcall FmodGhostAfterCall(uintptr_t rcx, uintptr_t rdx, uintptr_t r8, uintptr_t r9)
{
    InterlockedIncrement(reinterpret_cast<volatile LONG*>(&g_fireCount));

    char pathBuf[256]{};
    const uintptr_t args[] = { rcx, rdx, r8, r9 };
    const char* names[] = { "RCX", "RDX", "R8", "R9" };

    for (int i = 0; i < 4; ++i) {
        if (IsSafeString(args[i], pathBuf, sizeof(pathBuf))) {
            QueueLine(std::string("FMOD|phase=HOOK|HIT|reg=") + names[i] + "|path=" + pathBuf);
            NotifyTrackPlayed(pathBuf);
        }
    }
}

static bool TryInstallGhostHook()
{
    if (!FmodHookConfig::kEnableExeTextDetours) {
        Pipe("SETUP", "exe_text_detours_disabled|reason=delayed_crash_after_zero_fire_candidates");
        return false;
    }

    if (g_hooksInstalled || !g_allStationsReady)
        return g_hooksInstalled;
    if (GetTickCount64() < g_nextInstallAllowedAt)
        return false;

    g_exeBase = reinterpret_cast<uintptr_t>(GetModuleHandleW(nullptr));
    const uintptr_t rva = FmodHookConfig::kCandidateRvas[
        g_candidateIndex % (sizeof(FmodHookConfig::kCandidateRvas) / sizeof(FmodHookConfig::kCandidateRvas[0]))];
    uintptr_t targetVA = g_exeBase + rva;

    unsigned char bytes[5]{};
    if (!TryReadBytes(targetVA, bytes, sizeof(bytes))) {
        Pipe("FAULT", "target_unreadable|rva=" + ToHex(rva));
        return false;
    }

    Pipe("SETUP", "target=" + ToHex(targetVA)
        + "|rva=" + ToHex(rva)
        + "|candidate=" + std::to_string(g_candidateIndex)
        + "|bytes=" + ToHex(bytes[0]) + " " + ToHex(bytes[1]) + " " + ToHex(bytes[2])
        + " " + ToHex(bytes[3]) + " " + ToHex(bytes[4]));

    g_fmodGhostOriginal = reinterpret_cast<void*>(targetVA);

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    LONG attach = DetourAttach(&g_fmodGhostOriginal, FmodGhostDetour);
    LONG commit = attach == NO_ERROR ? DetourTransactionCommit() : DetourTransactionAbort();

    if (attach == NO_ERROR && commit == NO_ERROR) {
        g_hooksInstalled = true;
        g_fireCountAtInstall = g_fireCount;
        g_hookRemoveAt = GetTickCount64() + FmodHookConfig::kHookWindowMs;
        Pipe("SETUP", "ghost_hook_installed|rva=" + ToHex(rva)
            + "|remove_in_ms=" + std::to_string(FmodHookConfig::kHookWindowMs));
        return true;
    }

    Pipe("FAULT", "ghost_install_failed|attach=" + std::to_string(attach)
        + "|commit=" + std::to_string(commit));
    return false;
}

static void TryUninstallGhostHook()
{
    if (!g_hooksInstalled)
        return;

    const uintptr_t rva = FmodHookConfig::kCandidateRvas[
        g_candidateIndex % (sizeof(FmodHookConfig::kCandidateRvas) / sizeof(FmodHookConfig::kCandidateRvas[0]))];

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    LONG detach = DetourDetach(&g_fmodGhostOriginal, FmodGhostDetour);
    LONG commit = detach == NO_ERROR ? DetourTransactionCommit() : DetourTransactionAbort();

    if (detach == NO_ERROR && commit == NO_ERROR) {
        g_hooksInstalled = false;
        const uint32_t firesThisWindow = g_fireCount - g_fireCountAtInstall;
        Pipe("SETUP", "ghost_hook_removed|rva=" + ToHex(rva)
            + "|window_fires=" + std::to_string(firesThisWindow));
        if (firesThisWindow == 0)
            ++g_candidateIndex;
        g_nextInstallAllowedAt = GetTickCount64() + FmodHookConfig::kRearmCooldownMs;
    } else {
        Pipe("FAULT", "ghost_remove_failed|detach=" + std::to_string(detach)
            + "|commit=" + std::to_string(commit));
    }
}

void FmodEngineInit(const std::unordered_map<std::string, TrackInfo>* table)
{
    g_table = table;
    Pipe("SETUP", "ghost_engine_v15_early_read_window");
}

void FmodEngineNotifyStationBank(int stationNumber)
{
    if (stationNumber >= 1 && stationNumber <= 9) {
        if (g_stationNumbersSeen.insert(stationNumber).second && g_stationNumbersSeen.size() >= 9) {
            g_allStationsReady = true;
            Pipe("SETUP", "gate_open_waiting_for_radio_switch");
        }
    }
}

void FmodEngineOnStationSwitch(const std::string& prefix)
{
    g_stationPrefix = prefix;
    const DWORD64 now = GetTickCount64();
    g_burstUntil = now + FmodHookConfig::kHookWindowMs;
    Pipe("SETUP", "station_arm|prefix=" + prefix + "|window_ms="
        + std::to_string(FmodHookConfig::kHookWindowMs));

    ScanDataPointersToCandidates();

    if (g_slotHookInstalled) {
        Pipe("SLOTHOOK", "station_arm_while_hooked|keeping_existing_remove_deadline");
        return;
    }

    if (TryInstallRdataSlotHook())
        return;

    if (g_hooksInstalled) {
        Pipe("SETUP", "station_arm_while_hooked|keeping_existing_remove_deadline");
        return;
    }

    TryInstallGhostHook();
}

void FmodEngineTick()
{
    FlushQueuedLines();

    if (g_slotHookInstalled && GetTickCount64() > g_slotHookRemoveAt)
        TryRemoveRdataSlotHook();

    if (g_hooksInstalled && GetTickCount64() > g_hookRemoveAt)
        TryUninstallGhostHook();

    static int ticks = 0;
    ++ticks;
    if (ticks % 25 == 0) {
        Pipe("TICK", "heartbeat|tick=" + std::to_string(ticks)
            + "|hooked=" + std::to_string(g_hooksInstalled ? 1 : 0)
            + "|fires=" + std::to_string(g_fireCount));
    }
}

void FmodEngineNotifyPreloadComplete() {}
void FmodEngineSubmitStackRvas(const std::vector<uintptr_t>&) {}
void FmodEngineTrySetup() {}
