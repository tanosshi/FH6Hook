#include "AudioDiagnostics.h"
#include "RadioTracker.h"
#include "FmodEngine.h"

#include <windows.h>
#include <string>
#include <unordered_map>
#include <cassert>
#include <tchar.h>

#include "tinyxml2.h"

// ============================================================
// CONFIGURATION
// ============================================================
namespace Config
{
    constexpr const char* XML_RELATIVE_PATH = "media\\Audio\\RadioInfo_EN.xml";
    constexpr const char* PIPE_NAME         = "\\\\.\\pipe\\molotov";
}

// ============================================================
// PIPE / LOGGING
// ============================================================
static HANDLE g_pipeHandle = INVALID_HANDLE_VALUE;

void PipeWriteLine(const std::string& line)
{
    if (g_pipeHandle == INVALID_HANDLE_VALUE) {
        HANDLE h = CreateFileA(Config::PIPE_NAME, GENERIC_WRITE, 0,
            nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (h == INVALID_HANDLE_VALUE) return;
        g_pipeHandle = h;
        OutputDebugStringA("[FH6] Pipe connected.\n");
    }
    std::string out = line + "\n";
    DWORD written = 0;
    if (!WriteFile(g_pipeHandle, out.data(), static_cast<DWORD>(out.size()), &written, nullptr)) {
        CloseHandle(g_pipeHandle);
        g_pipeHandle = INVALID_HANDLE_VALUE;
    }
}

static void Log(const char* level, const std::string& msg)
{
    SYSTEMTIME st; GetLocalTime(&st);
    char ts[16];
    wsprintfA(ts, "%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);
    std::string line = std::string("[") + ts + "] [" + level + "] " + msg;
    OutputDebugStringA((line + "\n").c_str());
    PipeWriteLine(line);
}

void LogInfo(const std::string& m)  { Log("INFO ", m); }
void LogWarn(const std::string& m)  { Log("WARN ", m); }
void LogError(const std::string& m) { Log("ERROR", m); }

// ============================================================
// PATH HELPERS
// ============================================================
static std::string GetExeDir()
{
    char path[MAX_PATH] = {};
    GetModuleFileNameA(nullptr, path, MAX_PATH);
    std::string s(path);
    size_t sl = s.rfind('\\');
    return (sl != std::string::npos) ? s.substr(0, sl + 1) : s;
}

static bool FileExistsA(const std::string& path)
{
    DWORD attrs = GetFileAttributesA(path.c_str());
    return (attrs != INVALID_FILE_ATTRIBUTES) && !(attrs & FILE_ATTRIBUTE_DIRECTORY);
}

// ============================================================
// XML PARSING
// ============================================================
static std::unordered_map<std::string, TrackInfo>
ParseRadioXml(const std::string& xmlPath)
{
    std::unordered_map<std::string, TrackInfo> table;
    LogInfo("Parsing RadioInfo XML: " + xmlPath);

    if (!FileExistsA(xmlPath)) { LogError("XML not found: " + xmlPath); return table; }

    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(xmlPath.c_str()) != tinyxml2::XML_SUCCESS) {
        LogError(std::string("XML parse error: ") + doc.ErrorStr()); return table;
    }

    auto* root = doc.FirstChildElement("Radio");
    auto* stEl = root ? root->FirstChildElement("RadioStations") : nullptr;
    if (!stEl) { LogError("XML: bad structure"); return table; }

    int n = 0;
    for (auto* st = stEl->FirstChildElement("RadioStation"); st;
         st = st->NextSiblingElement("RadioStation"))
    {
        const char* stName = st->Attribute("Name");
        if (!stName) stName = "Unknown";
        for (auto* sl = st->FirstChildElement("SampleList"); sl;
             sl = sl->NextSiblingElement("SampleList"))
        {
            const char* slType = sl->Attribute("Type");
            if (!slType) slType = "Unknown";
            for (auto* smp = sl->FirstChildElement("Sample"); smp;
                 smp = smp->NextSiblingElement("Sample"))
            {
                const char* sn = smp->Attribute("SoundName");
                if (!sn) continue;
                TrackInfo t;
                t.soundName   = sn;
                t.displayName = smp->Attribute("DisplayName") ? smp->Attribute("DisplayName") : "";
                t.artist      = smp->Attribute("Artist")      ? smp->Attribute("Artist")      : "";
                t.station     = stName;
                t.sampleType  = slType;
                smp->QueryUnsigned64Attribute("SampleLength", &t.sampleLength);
                table[t.soundName] = std::move(t);
                ++n;
            }
        }
    }
    LogInfo("Loaded " + std::to_string(n) + " samples.");
    return table;
}

// ============================================================
// BACKGROUND THREAD
// ============================================================
static DWORD WINAPI NowPlayingThread(LPVOID) {
    // Wait for the game to load, 4s is enough; the bank flood happens within the first second of DLL attach.
    Sleep(4000);

    InstallAudioDiagnosticHooks();

    std::string exeDir = GetExeDir();
    LogInfo("Injected, exe dir: " + exeDir);

    std::string xmlPath = exeDir + Config::XML_RELATIVE_PATH;
    auto table = ParseRadioXml(xmlPath);
    if (table.empty()) { LogError("Configuration error, no tracks loaded."); return 0; }

    AudioDiagnosticsSetTrackTable(&table);
    RadioTrackerInit(&table);
    LogInfo("Initiated entirely, safe from now on");

    DWORD iteration = 0;
    while (true)
    {
        ++iteration;

        if (iteration % 25 == 0) {
            PipeWriteLine("TICK|alive|iter=" + std::to_string(iteration));
        }
        FmodEngineTick();
        RunPeriodicDiagnostics();

        Sleep(200);
    }

    return 0;
}

// ============================================================
// AHeadLib ENTRY POINTS
// ============================================================
void GetOriginalLibraryPath(TCHAR* bufferPtr, int bufferLength, const TCHAR* libName)
{
    assert(bufferPtr && libName);
    GetSystemDirectory(bufferPtr, bufferLength);
    lstrcat(bufferPtr, TEXT("\\"));
    lstrcat(bufferPtr, libName);
}

void ExecuteUserCustomCodes()
{
    HANDLE h = CreateThread(nullptr, 0, NowPlayingThread, nullptr, 0, nullptr);
    if (h) CloseHandle(h);
}

bool ShouldExecuteAttachCode() { return true; }
