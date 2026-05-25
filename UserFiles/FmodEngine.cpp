#include "FmodEngine.h"

#include <set>
#include <string>
#include <unordered_map>

extern void PipeWriteLine(const std::string& line);

namespace {

static constexpr int kRequiredStations = 9;
static constexpr int kHeartbeatIntervalTicks = 25;

static bool g_allStationsReady = false;
static int g_tickCount = 0;
static std::set<int> g_stationNumbersSeen;
static std::string g_stationPrefix;

static void Pipe(const char* phase, const std::string& msg)
{
    PipeWriteLine(std::string("FMOD|phase=") + phase + "|" + msg);
}

} // namespace

void FmodEngineInit(const std::unordered_map<std::string, TrackInfo>*)
{
    g_allStationsReady = false;
    g_tickCount = 0;
    g_stationNumbersSeen.clear();
    g_stationPrefix.clear();
    Pipe("SETUP", "engine_ready");
}

void FmodEngineNotifyStationBank(int stationNumber)
{
    if (stationNumber < 1 || stationNumber > kRequiredStations)
        return;

    if (g_stationNumbersSeen.insert(stationNumber).second
        && static_cast<int>(g_stationNumbersSeen.size()) >= kRequiredStations) {
        g_allStationsReady = true;
        Pipe("SETUP", "gate_open");
    }
}

void FmodEngineOnStationSwitch(const std::string& prefix)
{
    g_stationPrefix = prefix;
    Pipe("SETUP", "station_switch|prefix=" + prefix
        + "|ready=" + std::to_string(g_allStationsReady ? 1 : 0));
}

void FmodEngineTick()
{
    ++g_tickCount;
    if (g_tickCount % kHeartbeatIntervalTicks == 0) {
        Pipe("TICK", "heartbeat|tick=" + std::to_string(g_tickCount)
            + "|ready=" + std::to_string(g_allStationsReady ? 1 : 0)
            + "|prefix=" + g_stationPrefix);
    }
}
