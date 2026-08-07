# FH6Hooks
Real-time radio tracking for FH6.

The DLL watches radio bank file activity, maps read offsets back to FSB5 samples, correlates those samples with `RadioInfo_EN.xml` in the game's directory, and emits now-playing telemetry through a named pipe.

The game does not expose a now-playing API. The hook reconstructs the active track from file reads against FMOD `.bank` files.

The DLL was originally made for the [Python scrobbler for Last.fm integration](https://github.com/tanosshi/FH6Scrobbler) and could be used for other purposes

The hook currently observes file activity and does not intentionally modify memory. Use it at your own risk.

## Hook Summary

1. The proxy DLL is loaded by the game as `version.dll`, which now follows up by loading the original DLL from the windows directory.
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
9. When a read offset lands inside a known track range, the DLL emits its log events through `\\.\pipe\molotov`.

The hooks are deliberately narrow. They only track radio `.bank` files and queue telemetry out of the hook path so the game thread is not blocked by pipe I/O.

## Hook's Telemetry
The DLL writes line-based messages to the named pipe:

```txt
PLAY|Artist - Track [Station]
PING|Artist - Track [Station]
STOP|music_inactive|last=Artist - Track [Station]
```

The following message types will be given; `FILE`, `READ`, `STATION`, `FMOD`, and `TICK`.

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

## File Summary

`UserFiles/UserImplementations.cpp` - Starts the hook

`UserFiles/AudioDiagnostics.cpp` - Tracks the bank file reads and emits them

`UserFiles/RadioTracker.cpp` - Detects the station and song changes

`UserFiles/tinyxml2.h` and `UserFiles/tinyxml2.cpp` - Parses `RadioInfo_EN.xml`.

## Runtime Notes

- The named pipe is `\\.\pipe\molotov`.
- The XML metadata path must be `media\Audio\RadioInfo_EN.xml`, relative to the game executable directory.
- Startup radio-bank preload is noisy, so station detection waits for preload progress or the preload timeout before arming normal read windows.
- Track detection is based on observed file reads, not direct FMOD event callbacks.

---

__Please note that I am not affiliated with Microsoft, Turn 10 Studios, Playground Games, Xbox Games Studio, CBS Corporation or Last.fm. This is an unofficial fan-made mod created as a hobby project, I am not funded or asked to make this.__
