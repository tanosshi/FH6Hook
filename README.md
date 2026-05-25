# FH6Hook
Real-time radio tracking for Forza Horizon 6.

This project hooks into FH6’s audio pipeline to figure out what song is currently playing on the in-game radio, then streams structured track events to an external listener for Last.fm scrobbling, overlays, logging, or other integrations.

The game doesn’t expose a proper “Now Playing” API, so the tracker reconstructs track information by watching FMOD bank activity, parsing FSB5 data, and correlating read offsets with metadata loaded from the game’s XML files.

## How it works
At startup, the DLL loads the game’s radio metadata from `RadioInfo_EN.xml`, building an in-memory track table containing:
* Track names
* Artists
* Stations
* Sample lengths
* FMOD cue names

The DLL then hooks low-level Windows file APIs using Microsoft Detours:
* `CreateFileW`
* `ReadFile`
* `CloseHandle`

Whenever FH6 opens a radio bank, the tracker monitors read activity and maps byte ranges back to individual tracks inside the FSB5 bank.
Because the game aggressively preloads audio during startup, the tracker uses several filtering stages to reduce false positives:

* Station preload detection
* Debounced station switching
* Time-bounded read windows
* Unique sample correlation

Once a track is confidently identified, the DLL emits structured telemetry events through a named pipe.

## Expected output

```txt id="r8z6uw"
PLAY|Netsky - Iron Heart [Hospital Records] - Playing
PING|Netsky - Iron Heart [Hospital Records] - Still Playing
STOP|music_inactive|last=Netsky - Iron Heart [Hospital Records] - Stopped/menu
```

## Architecture

```txt id="r9go6j"
FH6 (game process)
│
├─ Injected DLL
│  ├─ WinAPI hooks
│  ├─ FMOD bank parser
│  ├─ Track correlation
│  └─ Named pipe telemetry
│
└─ External listener
   ├─ Python pipe server
   ├─ Logging
   └─ Event processing
```

## Technical details

### AudioDiagnostics
Handles low-level instrumentation and bank tracking.

Responsibilities:

* Hooking file APIs
* Tracking `.bank` handles
* Parsing FSB5 headers
* Mapping offsets to samples
* Queuing telemetry safely off-thread

### RadioTracker
Responsible for filtering and station state management.

Responsibilities:

* Detecting active stations
* Handling preload noise
* Debouncing station changes
* Managing read windows

### FmodEngine
Experimental FMOD event extraction layer.

Currently optional and disabled by default for stability.

### listener.py
External named-pipe listener built with Python + Win32 APIs.

Provides:

* Timestamped logs
* Console highlighting
* Structured event output


## Stack
* C++17
* Windows API
* Microsoft Detours
* x64 assembly
* Python 3
* Named Pipes
* FMOD / FSB5 parsing


Which focused on:

* Low-latency instrumentation
* Thread safety
* Binary parsing
* Signal filtering
* Runtime telemetry
* Stable event generation

## Current status
The extraction pipeline is fully functional and already produces proper events, although there are some bugs to watch out for, the code automatically recovers from them and continues tracking without crashing the game.