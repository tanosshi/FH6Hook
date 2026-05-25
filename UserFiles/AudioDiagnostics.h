#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

struct TrackInfo
{
    std::string soundName;
    std::string displayName;
    std::string artist;
    std::string station;
    std::string sampleType;
    uint64_t sampleLength = 0;
};

void InstallAudioDiagnosticHooks();
void RunPeriodicDiagnostics();
void AudioDiagnosticsArmReadWindow(const std::string& stationPrefix);
void AudioDiagnosticsSetTrackTable(const std::unordered_map<std::string, TrackInfo>& table);
