# FH6Hooks

Real-time radio tracking for FH6.

This project builds a `version.dll` proxy that runs inside the game process. It watches radio bank file activity, maps read offsets back to FSB5 samples, correlates those samples with `RadioInfo_EN.xml`, and emits now-playing telemetry through a named pipe.

The game does not expose a now-playing API. The hook reconstructs the active track from file reads against FMOD `.bank` files.

The DLL can be universally used by any external listener, such as the [Python scrobbler for Last.fm integration](https://github.com/tanosshi/FH6Scrobbler). You could also use the DLL for overlays, logging, or other creative uses.

The current method does **NOT** trigger the anti-cheat, anti-tamper or any suspicious activity as it only observes file reads and does not modify game code or memory. The hooks are narrow and efficient, and the telemetry is emitted asynchronously through a named pipe.

## Hook Summary

1. The proxy DLL is loaded by the game as `version.dll`, which follows up by loading the original dll from the game directory named `version_original.dll`.
2. `UserImplementations.cpp` starts a background thread.
3. The thread installs Detours hooks for:
   - `CreateFileW`
   - `ReadFile`
   - `CloseHandle`
4. The thread parses `media\Audio\RadioInfo_EN.xml` into a track metadata table.
5. `CreateFileW` detects radio track bank files as the game opens them.
6. `ReadFile` observes read offsets for tracked bank handles.
7. `AudioDiagnostics.cpp` parses each FSB5 bank and records byte ranges for each sample.
8. `RadioTracker.cpp` filters startup preload noise, detects station switches, and opens a short read window.
9. When a read offset lands inside a known track range, the DLL emits `PLAY`, `PING`, and `STOP` events through `\\.\pipe\molotov`.

The hooks are deliberately narrow. They only track radio `.bank` files and queue telemetry out of the hook path so the game thread is not blocked by pipe I/O.

## Hook's Telemetry
The DLL writes line-based messages to the named pipe:

```txt
PLAY|Artist - Track [Station]
PING|Artist - Track [Station]
STOP|music_inactive|last=Artist - Track [Station]
```

Important message types are `FILE`, `READ`, `STATION`, `FMOD`, and `TICK`.

## Project Layout

### UserFiles

`UserFiles/UserImplementations.cpp`

Entry point for the project. It creates the background thread, opens the named pipe lazily, provides logging helpers, loads `RadioInfo_EN.xml`, initializes the tracking modules, and keeps the periodic diagnostics loop running.

`UserFiles/AudioDiagnostics.h`

Shared audio-tracking declarations. It defines `TrackInfo`, which stores the parsed XML metadata used by the bank parser and radio tracker, and declares the public audio diagnostics functions.

`UserFiles/AudioDiagnostics.cpp`

Installs and owns the Windows API hooks. It tracks opened radio bank handles, converts wide paths to UTF-8, parses FSB5 sample tables from `.bank` files, maps sample byte ranges to `TrackInfo`, detects track reads during an armed read window, and emits `PLAY`, `PING`, and `STOP` telemetry.

`UserFiles/RadioTracker.h`

Public interface for the radio station tracker. It exposes initialization, queued bank-path processing, and the periodic tick.

`UserFiles/RadioTracker.cpp`

Filters bank-open events into station state. It ignores startup preload noise, tracks which station banks have been seen, extracts station prefixes such as `HZ6_R3_`, debounces station changes, and arms read windows in `AudioDiagnostics.cpp`.

`UserFiles/FmodEngine.h`

Small interface used by `RadioTracker.cpp` for station readiness and heartbeat reporting.

`UserFiles/FmodEngine.cpp`

Tracks station readiness and emits lightweight FMOD-phase telemetry. The previous experimental FMOD detour path has been removed; current track detection is handled by the file-read hooks in `AudioDiagnostics.cpp`.

`UserFiles/StringUtils.h`

Tools to follow the Do Not Repeat Yourself (DRY) principle for string conversions and formatting.

`UserFiles/tinyxml2.h` and `UserFiles/tinyxml2.cpp`

Vendored TinyXML2 parser used to read `RadioInfo_EN.xml`.

## Build Notes

Only target `Release|x64` for building.

The project expects Microsoft Detours headers and libraries under:
```txt
Detours-src\include
Detours-src\lib.X64
```
Use the build_detours_x64.bat script to build Detours if you don't have it already.

GitHub Actions downloads the Microsoft Detours and builds it automatically for release builds. Local builds still need `Detours-src` in the project folder.`.

Typical build command:
```powershell
msbuild version.sln /p:Configuration=Release /p:Platform=x64 /m
``` 
> (or press "rebuild version" in Visual Studio with the same configuration)

The output DLL is written to:

```txt
x64\Release\version.dll
```

## Runtime Notes

- The named pipe is `\\.\pipe\molotov`.
- The XML metadata path must be `media\Audio\RadioInfo_EN.xml`, relative to the game executable directory.
- Startup radio-bank preload is noisy, so station detection waits for preload progress or the preload timeout before arming normal read windows.
- Track detection is based on observed file reads, not direct FMOD event callbacks.

---

__Please note that I am not affiliated with Microsoft, Turn 10 Studios, Playground Games, Xbox Games Studio, CBS Corporation or Last.fm. This is an unofficial fan-made mod created as a hobby project, I am not funded or asked to make this.__
