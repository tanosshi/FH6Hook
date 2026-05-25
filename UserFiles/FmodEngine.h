#pragma once

#include "AudioDiagnostics.h"
#include <string>
#include <unordered_map>

void FmodEngineNotifyStationBank(int stationNumber);
void FmodEngineInit(const std::unordered_map<std::string, TrackInfo>* table);
void FmodEngineNotifyPreloadComplete();
void FmodEngineTrySetup();
void FmodEngineOnStationSwitch(const std::string& stationPrefix);
void FmodEngineTick();
void FmodEngineSubmitStackRvas(const std::vector<uintptr_t>& rvas);
