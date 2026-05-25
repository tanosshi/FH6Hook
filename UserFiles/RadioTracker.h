#pragma once

#include "AudioDiagnostics.h"
#include <string>

void RadioTrackerInit(const std::unordered_map<std::string, TrackInfo>* table);
void RadioTrackerQueueBankFile(const std::string& path);
void RadioTrackerTick();
