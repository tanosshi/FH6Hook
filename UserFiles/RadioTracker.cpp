#include "RadioTracker.h"
#include "FmodEngine.h"
#define NOMINMAX
#include <windows.h>
#include <atomic>
#include <mutex>
#include <string>
#include <unordered_set>
#include <vector>

extern void LogInfo(const std::string& m);
extern void PipeWriteLine(const std::string& line);

namespace {

// r1–r9 = 9 stations.
static constexpr int kRequiredStations = 9;

static ULONGLONG g_startTick    = GetTickCount64();
static constexpr DWORD kPreloadWindowMs = 20000;
static constexpr DWORD kDebounceMs      = 300;
static constexpr DWORD kReadWindowMs    = 60000;

static std::mutex               g_mtx;
static std::mutex               g_queueMtx;
static std::vector<std::string> g_pendingBankPaths;

static std::unordered_set<int>  g_stationNumbersSeen;
static bool                     g_preloadNotified = false;
static std::atomic<bool>        g_preloadNotifyPending{false};

static std::string g_pendingPrefix;
static std::string g_pendingBank;
static ULONGLONG   g_pendingSince = 0;

static void Emit(const std::string& tag, const std::string& body)
{
    PipeWriteLine(tag + "|" + body);
}

static std::string ToLower(std::string s)
{
    for (auto& c : s) c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    return s;
}

static std::string BaseName(const std::string& path)
{
    size_t p = path.find_last_of("\\/");
    return (p == std::string::npos) ? path : path.substr(p + 1);
}

static bool IsTrackBankPath(const std::string& pathLower)
{
    return pathLower.find("fmodbanks") != std::string::npos
        && pathLower.find("_tracks_")  != std::string::npos
        && pathLower.find(".bank")     != std::string::npos;
}

// Returns "HZ6_R3_" prefix, or "" if unparseable (should be avoided lmao).
static std::string BankPathToPrefix(const std::string& pathLower, int& stationNumberOut)
{
    stationNumberOut = 0;
    size_t pos = pathLower.find("_tracks_");
    if (pos == std::string::npos || pos < 2) return "";
    size_t digitEnd = pos - 1;
    if (pathLower[digitEnd] < '0' || pathLower[digitEnd] > '9') return "";
    size_t digitStart = digitEnd;
    while (digitStart > 0
        && pathLower[digitStart - 1] >= '0'
        && pathLower[digitStart - 1] <= '9')
        --digitStart;
    if (digitStart == 0 || pathLower[digitStart - 1] != 'r') return "";
    std::string num = pathLower.substr(digitStart, digitEnd - digitStart + 1);
    if (num.empty()) return "";
    stationNumberOut = std::stoi(num);
    return "HZ6_R" + num + "_";
}

static void TryFlushDebounce()
{
    if (g_pendingPrefix.empty()) return;
    ULONGLONG now = GetTickCount64();
    if (now - g_pendingSince < kDebounceMs) return;

    std::string prefix = g_pendingPrefix;
    std::string bank   = g_pendingBank;
    g_pendingPrefix.clear();
    g_pendingBank.clear();

    Emit("STATION", "armed|prefix=" + prefix + "|bank=" + bank);
    Emit("READ", "armed|prefix=" + prefix + "|bank=" + bank + "|window_ms=" + std::to_string(kReadWindowMs));
    LogInfo("Station armed: " + prefix + " (" + bank + ")");
    FmodEngineOnStationSwitch(prefix);
}

static void ScheduleArm(const std::string& prefix, const std::string& bank)
{
    g_pendingPrefix = prefix;
    g_pendingBank   = bank;
    g_pendingSince  = GetTickCount64();

    Emit("READ", "pending|prefix=" + prefix + "|bank=" + bank + "|window_ms=" + std::to_string(kReadWindowMs));
    AudioDiagnosticsArmReadWindow(prefix);
}

static void ProcessBankFile(const std::string& path)
{
    std::string lower  = ToLower(path);
    if (!IsTrackBankPath(lower)) return;

    std::string base = BaseName(lower);
    int stationNum   = 0;
    std::string prefix = BankPathToPrefix(lower, stationNum);
    if (prefix.empty() || stationNum < 1) return;

    ULONGLONG now        = GetTickCount64();
    const bool pastPreload = (now - g_startTick) >= kPreloadWindowMs;

    std::lock_guard<std::mutex> lock(g_mtx);

    Emit("STATION", "bank=" + base + "|prefix=" + prefix
        + "|station_num=" + std::to_string(stationNum)
        + "|past_preload=" + (pastPreload ? "1" : "0"));

    if (!pastPreload) {
        bool wasNew = g_stationNumbersSeen.insert(stationNum).second;
        if (wasNew) {
            FmodEngineNotifyStationBank(stationNum);

            int seen = static_cast<int>(g_stationNumbersSeen.size());
            Emit("STATION", "preload_progress|seen=" + std::to_string(seen)
                + "|required=" + std::to_string(kRequiredStations));

            if (!g_preloadNotified && seen >= kRequiredStations) {
                g_preloadNotified      = true;
                g_preloadNotifyPending = true;
                Emit("STATION", "preload_gate_met|all_" + std::to_string(kRequiredStations)
                    + "_stations_confirmed");
            }
        }
        return;
    }

    if (!g_preloadNotified) {
        g_preloadNotified      = true;
        g_preloadNotifyPending = true;
        Emit("STATION", "preload_gate_forced|past_window");
    }

    ScheduleArm(prefix, base);
}

static void FlushQueuedBankPaths()
{
    std::vector<std::string> batch;
    {
        std::lock_guard<std::mutex> lock(g_queueMtx);
        if (g_pendingBankPaths.empty()) return;
        batch.swap(g_pendingBankPaths);
    }
    for (const auto& p : batch)
        ProcessBankFile(p);
}

} // namespace

void RadioTrackerInit(const std::unordered_map<std::string, TrackInfo>* table)
{
    g_startTick = GetTickCount64();
    FmodEngineInit(table);
}

void RadioTrackerQueueBankFile(const std::string& path)
{
    std::lock_guard<std::mutex> lock(g_queueMtx);
    g_pendingBankPaths.push_back(path);
}

void RadioTrackerTick()
{
    FlushQueuedBankPaths();

    if (g_preloadNotifyPending.exchange(false))
        FmodEngineNotifyPreloadComplete();

    TryFlushDebounce();
    FmodEngineTick();
}
