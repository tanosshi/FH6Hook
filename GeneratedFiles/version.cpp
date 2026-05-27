#include <windows.h>
#include "MiniTools.h"

#if defined(_WIN64) || defined(_X64) || defined(WIN64) || defined( __LP64__ )
#define AHEAD_LIB_DOT_NET_X64_BUILD 1
#else
#define AHEAD_LIB_DOT_NET_X64_BUILD 0
#endif

// checked get function in native dll
namespace
{
    LPVOID CheckedGetFunction(HMODULE module, const char* methodName)
    {
        const auto Result = reinterpret_cast<LPVOID>(GetProcAddress(module, methodName));

        if (Result == nullptr)
        {
            char szMessage[256];
            wsprintfA(szMessage, "Failed bind method:%s", methodName);

            OutputDebugStringA(szMessage);

#if defined(DEBUG) || defined(_DEBUG)
            MessageBoxA(nullptr, szMessage, "AHeadLib.Net Error", 0);
            ExitProcess(-1);
#endif
        }

        return Result;
    }    
}

#define AHEAD_LIB_DOT_NET_BIND_FUNCTION(name) name##Ptr = CheckedGetFunction(module, #name)

// ReSharper disable IdentifierTypo
// ReSharper disable CppInconsistentNaming
extern "C" void* CloseDriverPtr = nullptr;
extern "C" void* DefDriverProcPtr = nullptr;
extern "C" void* DllMainPtr = nullptr;
extern "C" void* DriverCallbackPtr = nullptr;
extern "C" void* DrvGetModuleHandlePtr = nullptr;
extern "C" void* GetDriverModuleHandlePtr = nullptr;
extern "C" void* GetFileVersionInfoAPtr = nullptr;
extern "C" void* GetFileVersionInfoByHandlePtr = nullptr;
extern "C" void* GetFileVersionInfoExAPtr = nullptr;
extern "C" void* GetFileVersionInfoExWPtr = nullptr;
extern "C" void* GetFileVersionInfoSizeAPtr = nullptr;
extern "C" void* GetFileVersionInfoSizeExAPtr = nullptr;
extern "C" void* GetFileVersionInfoSizeExWPtr = nullptr;
extern "C" void* GetFileVersionInfoSizeWPtr = nullptr;
extern "C" void* GetFileVersionInfoWPtr = nullptr;
extern "C" void* HidD_FlushQueuePtr = nullptr;
extern "C" void* HidD_FreePreparsedDataPtr = nullptr;
extern "C" void* HidD_GetAttributesPtr = nullptr;
extern "C" void* HidD_GetConfigurationPtr = nullptr;
extern "C" void* HidD_GetFeaturePtr = nullptr;
extern "C" void* HidD_GetHidGuidPtr = nullptr;
extern "C" void* HidD_GetIndexedStringPtr = nullptr;
extern "C" void* HidD_GetInputReportPtr = nullptr;
extern "C" void* HidD_GetManufacturerStringPtr = nullptr;
extern "C" void* HidD_GetMsGenreDescriptorPtr = nullptr;
extern "C" void* HidD_GetNumInputBuffersPtr = nullptr;
extern "C" void* HidD_GetPhysicalDescriptorPtr = nullptr;
extern "C" void* HidD_GetPreparsedDataPtr = nullptr;
extern "C" void* HidD_GetProductStringPtr = nullptr;
extern "C" void* HidD_GetSerialNumberStringPtr = nullptr;
extern "C" void* HidD_HelloPtr = nullptr;
extern "C" void* HidD_SetConfigurationPtr = nullptr;
extern "C" void* HidD_SetFeaturePtr = nullptr;
extern "C" void* HidD_SetNumInputBuffersPtr = nullptr;
extern "C" void* HidD_SetOutputReportPtr = nullptr;
extern "C" void* HidP_GetButtonCapsPtr = nullptr;
extern "C" void* HidP_GetCapsPtr = nullptr;
extern "C" void* HidP_GetDataPtr = nullptr;
extern "C" void* HidP_GetExtendedAttributesPtr = nullptr;
extern "C" void* HidP_GetLinkCollectionNodesPtr = nullptr;
extern "C" void* HidP_GetScaledUsageValuePtr = nullptr;
extern "C" void* HidP_GetSpecificButtonCapsPtr = nullptr;
extern "C" void* HidP_GetSpecificValueCapsPtr = nullptr;
extern "C" void* HidP_GetUsageValuePtr = nullptr;
extern "C" void* HidP_GetUsageValueArrayPtr = nullptr;
extern "C" void* HidP_GetUsagesPtr = nullptr;
extern "C" void* HidP_GetUsagesExPtr = nullptr;
extern "C" void* HidP_GetValueCapsPtr = nullptr;
extern "C" void* HidP_InitializeReportForIDPtr = nullptr;
extern "C" void* HidP_MaxDataListLengthPtr = nullptr;
extern "C" void* HidP_MaxUsageListLengthPtr = nullptr;
extern "C" void* HidP_SetDataPtr = nullptr;
extern "C" void* HidP_SetScaledUsageValuePtr = nullptr;
extern "C" void* HidP_SetUsageValuePtr = nullptr;
extern "C" void* HidP_SetUsageValueArrayPtr = nullptr;
extern "C" void* HidP_SetUsagesPtr = nullptr;
extern "C" void* HidP_TranslateUsagesToI8042ScanCodesPtr = nullptr;
extern "C" void* HidP_UnsetUsagesPtr = nullptr;
extern "C" void* HidP_UsageListDifferencePtr = nullptr;
extern "C" void* OpenDriverPtr = nullptr;
extern "C" void* PlaySoundPtr = nullptr;
extern "C" void* PlaySoundAPtr = nullptr;
extern "C" void* PlaySoundWPtr = nullptr;
extern "C" void* SendDriverMessagePtr = nullptr;
extern "C" void* VerFindFileAPtr = nullptr;
extern "C" void* VerFindFileWPtr = nullptr;
extern "C" void* VerInstallFileAPtr = nullptr;
extern "C" void* VerInstallFileWPtr = nullptr;
extern "C" void* VerLanguageNameAPtr = nullptr;
extern "C" void* VerLanguageNameWPtr = nullptr;
extern "C" void* VerQueryValueAPtr = nullptr;
extern "C" void* VerQueryValueWPtr = nullptr;
extern "C" void* WOWAppExitPtr = nullptr;
extern "C" void* auxGetDevCapsAPtr = nullptr;
extern "C" void* auxGetDevCapsWPtr = nullptr;
extern "C" void* auxGetNumDevsPtr = nullptr;
extern "C" void* auxGetVolumePtr = nullptr;
extern "C" void* auxOutMessagePtr = nullptr;
extern "C" void* auxSetVolumePtr = nullptr;
extern "C" void* joyConfigChangedPtr = nullptr;
extern "C" void* joyGetDevCapsAPtr = nullptr;
extern "C" void* joyGetDevCapsWPtr = nullptr;
extern "C" void* joyGetNumDevsPtr = nullptr;
extern "C" void* joyGetPosPtr = nullptr;
extern "C" void* joyGetPosExPtr = nullptr;
extern "C" void* joyGetThresholdPtr = nullptr;
extern "C" void* joyReleaseCapturePtr = nullptr;
extern "C" void* joySetCapturePtr = nullptr;
extern "C" void* joySetThresholdPtr = nullptr;
extern "C" void* mciDriverNotifyPtr = nullptr;
extern "C" void* mciDriverYieldPtr = nullptr;
extern "C" void* mciExecutePtr = nullptr;
extern "C" void* mciFreeCommandResourcePtr = nullptr;
extern "C" void* mciGetCreatorTaskPtr = nullptr;
extern "C" void* mciGetDeviceIDAPtr = nullptr;
extern "C" void* mciGetDeviceIDFromElementIDAPtr = nullptr;
extern "C" void* mciGetDeviceIDFromElementIDWPtr = nullptr;
extern "C" void* mciGetDeviceIDWPtr = nullptr;
extern "C" void* mciGetDriverDataPtr = nullptr;
extern "C" void* mciGetErrorStringAPtr = nullptr;
extern "C" void* mciGetErrorStringWPtr = nullptr;
extern "C" void* mciGetYieldProcPtr = nullptr;
extern "C" void* mciLoadCommandResourcePtr = nullptr;
extern "C" void* mciSendCommandAPtr = nullptr;
extern "C" void* mciSendCommandWPtr = nullptr;
extern "C" void* mciSendStringAPtr = nullptr;
extern "C" void* mciSendStringWPtr = nullptr;
extern "C" void* mciSetDriverDataPtr = nullptr;
extern "C" void* mciSetYieldProcPtr = nullptr;
extern "C" void* midiConnectPtr = nullptr;
extern "C" void* midiDisconnectPtr = nullptr;
extern "C" void* midiInAddBufferPtr = nullptr;
extern "C" void* midiInClosePtr = nullptr;
extern "C" void* midiInGetDevCapsAPtr = nullptr;
extern "C" void* midiInGetDevCapsWPtr = nullptr;
extern "C" void* midiInGetErrorTextAPtr = nullptr;
extern "C" void* midiInGetErrorTextWPtr = nullptr;
extern "C" void* midiInGetIDPtr = nullptr;
extern "C" void* midiInGetNumDevsPtr = nullptr;
extern "C" void* midiInMessagePtr = nullptr;
extern "C" void* midiInOpenPtr = nullptr;
extern "C" void* midiInPrepareHeaderPtr = nullptr;
extern "C" void* midiInResetPtr = nullptr;
extern "C" void* midiInStartPtr = nullptr;
extern "C" void* midiInStopPtr = nullptr;
extern "C" void* midiInUnprepareHeaderPtr = nullptr;
extern "C" void* midiOutCacheDrumPatchesPtr = nullptr;
extern "C" void* midiOutCachePatchesPtr = nullptr;
extern "C" void* midiOutClosePtr = nullptr;
extern "C" void* midiOutGetDevCapsAPtr = nullptr;
extern "C" void* midiOutGetDevCapsWPtr = nullptr;
extern "C" void* midiOutGetErrorTextAPtr = nullptr;
extern "C" void* midiOutGetErrorTextWPtr = nullptr;
extern "C" void* midiOutGetIDPtr = nullptr;
extern "C" void* midiOutGetNumDevsPtr = nullptr;
extern "C" void* midiOutGetVolumePtr = nullptr;
extern "C" void* midiOutLongMsgPtr = nullptr;
extern "C" void* midiOutMessagePtr = nullptr;
extern "C" void* midiOutOpenPtr = nullptr;
extern "C" void* midiOutPrepareHeaderPtr = nullptr;
extern "C" void* midiOutResetPtr = nullptr;
extern "C" void* midiOutSetVolumePtr = nullptr;
extern "C" void* midiOutShortMsgPtr = nullptr;
extern "C" void* midiOutUnprepareHeaderPtr = nullptr;
extern "C" void* midiStreamClosePtr = nullptr;
extern "C" void* midiStreamOpenPtr = nullptr;
extern "C" void* midiStreamOutPtr = nullptr;
extern "C" void* midiStreamPausePtr = nullptr;
extern "C" void* midiStreamPositionPtr = nullptr;
extern "C" void* midiStreamPropertyPtr = nullptr;
extern "C" void* midiStreamRestartPtr = nullptr;
extern "C" void* midiStreamStopPtr = nullptr;
extern "C" void* mixerClosePtr = nullptr;
extern "C" void* mixerGetControlDetailsAPtr = nullptr;
extern "C" void* mixerGetControlDetailsWPtr = nullptr;
extern "C" void* mixerGetDevCapsAPtr = nullptr;
extern "C" void* mixerGetDevCapsWPtr = nullptr;
extern "C" void* mixerGetIDPtr = nullptr;
extern "C" void* mixerGetLineControlsAPtr = nullptr;
extern "C" void* mixerGetLineControlsWPtr = nullptr;
extern "C" void* mixerGetLineInfoAPtr = nullptr;
extern "C" void* mixerGetLineInfoWPtr = nullptr;
extern "C" void* mixerGetNumDevsPtr = nullptr;
extern "C" void* mixerMessagePtr = nullptr;
extern "C" void* mixerOpenPtr = nullptr;
extern "C" void* mixerSetControlDetailsPtr = nullptr;
extern "C" void* mmDrvInstallPtr = nullptr;
extern "C" void* mmGetCurrentTaskPtr = nullptr;
extern "C" void* mmTaskBlockPtr = nullptr;
extern "C" void* mmTaskCreatePtr = nullptr;
extern "C" void* mmTaskSignalPtr = nullptr;
extern "C" void* mmTaskYieldPtr = nullptr;
extern "C" void* mmioAdvancePtr = nullptr;
extern "C" void* mmioAscendPtr = nullptr;
extern "C" void* mmioClosePtr = nullptr;
extern "C" void* mmioCreateChunkPtr = nullptr;
extern "C" void* mmioDescendPtr = nullptr;
extern "C" void* mmioFlushPtr = nullptr;
extern "C" void* mmioGetInfoPtr = nullptr;
extern "C" void* mmioInstallIOProcAPtr = nullptr;
extern "C" void* mmioInstallIOProcWPtr = nullptr;
extern "C" void* mmioOpenAPtr = nullptr;
extern "C" void* mmioOpenWPtr = nullptr;
extern "C" void* mmioReadPtr = nullptr;
extern "C" void* mmioRenameAPtr = nullptr;
extern "C" void* mmioRenameWPtr = nullptr;
extern "C" void* mmioSeekPtr = nullptr;
extern "C" void* mmioSendMessagePtr = nullptr;
extern "C" void* mmioSetBufferPtr = nullptr;
extern "C" void* mmioSetInfoPtr = nullptr;
extern "C" void* mmioStringToFOURCCAPtr = nullptr;
extern "C" void* mmioStringToFOURCCWPtr = nullptr;
extern "C" void* mmioWritePtr = nullptr;
extern "C" void* mmsystemGetVersionPtr = nullptr;
extern "C" void* sndPlaySoundAPtr = nullptr;
extern "C" void* sndPlaySoundWPtr = nullptr;
extern "C" void* timeBeginPeriodPtr = nullptr;
extern "C" void* timeEndPeriodPtr = nullptr;
extern "C" void* timeGetDevCapsPtr = nullptr;
extern "C" void* timeGetSystemTimePtr = nullptr;
extern "C" void* timeGetTimePtr = nullptr;
extern "C" void* timeKillEventPtr = nullptr;
extern "C" void* timeSetEventPtr = nullptr;
extern "C" void* waveInAddBufferPtr = nullptr;
extern "C" void* waveInClosePtr = nullptr;
extern "C" void* waveInGetDevCapsAPtr = nullptr;
extern "C" void* waveInGetDevCapsWPtr = nullptr;
extern "C" void* waveInGetErrorTextAPtr = nullptr;
extern "C" void* waveInGetErrorTextWPtr = nullptr;
extern "C" void* waveInGetIDPtr = nullptr;
extern "C" void* waveInGetNumDevsPtr = nullptr;
extern "C" void* waveInGetPositionPtr = nullptr;
extern "C" void* waveInMessagePtr = nullptr;
extern "C" void* waveInOpenPtr = nullptr;
extern "C" void* waveInPrepareHeaderPtr = nullptr;
extern "C" void* waveInResetPtr = nullptr;
extern "C" void* waveInStartPtr = nullptr;
extern "C" void* waveInStopPtr = nullptr;
extern "C" void* waveInUnprepareHeaderPtr = nullptr;
extern "C" void* waveOutBreakLoopPtr = nullptr;
extern "C" void* waveOutClosePtr = nullptr;
extern "C" void* waveOutGetDevCapsAPtr = nullptr;
extern "C" void* waveOutGetDevCapsWPtr = nullptr;
extern "C" void* waveOutGetErrorTextAPtr = nullptr;
extern "C" void* waveOutGetErrorTextWPtr = nullptr;
extern "C" void* waveOutGetIDPtr = nullptr;
extern "C" void* waveOutGetNumDevsPtr = nullptr;
extern "C" void* waveOutGetPitchPtr = nullptr;
extern "C" void* waveOutGetPlaybackRatePtr = nullptr;
extern "C" void* waveOutGetPositionPtr = nullptr;
extern "C" void* waveOutGetVolumePtr = nullptr;
extern "C" void* waveOutMessagePtr = nullptr;
extern "C" void* waveOutOpenPtr = nullptr;
extern "C" void* waveOutPausePtr = nullptr;
extern "C" void* waveOutPrepareHeaderPtr = nullptr;
extern "C" void* waveOutResetPtr = nullptr;
extern "C" void* waveOutRestartPtr = nullptr;
extern "C" void* waveOutSetPitchPtr = nullptr;
extern "C" void* waveOutSetPlaybackRatePtr = nullptr;
extern "C" void* waveOutSetVolumePtr = nullptr;
extern "C" void* waveOutUnprepareHeaderPtr = nullptr;
extern "C" void* waveOutWritePtr = nullptr;

extern "C" void WINAPI ASM_CloseDriver();
extern "C" void WINAPI ASM_DefDriverProc();
extern "C" void WINAPI ASM_DllMain();
extern "C" void WINAPI ASM_DriverCallback();
extern "C" void WINAPI ASM_DrvGetModuleHandle();
extern "C" void WINAPI ASM_GetDriverModuleHandle();
extern "C" void WINAPI ASM_GetFileVersionInfoA();
extern "C" void WINAPI ASM_GetFileVersionInfoByHandle();
extern "C" void WINAPI ASM_GetFileVersionInfoExA();
extern "C" void WINAPI ASM_GetFileVersionInfoExW();
extern "C" void WINAPI ASM_GetFileVersionInfoSizeA();
extern "C" void WINAPI ASM_GetFileVersionInfoSizeExA();
extern "C" void WINAPI ASM_GetFileVersionInfoSizeExW();
extern "C" void WINAPI ASM_GetFileVersionInfoSizeW();
extern "C" void WINAPI ASM_GetFileVersionInfoW();
extern "C" void WINAPI ASM_HidD_FlushQueue();
extern "C" void WINAPI ASM_HidD_FreePreparsedData();
extern "C" void WINAPI ASM_HidD_GetAttributes();
extern "C" void WINAPI ASM_HidD_GetConfiguration();
extern "C" void WINAPI ASM_HidD_GetFeature();
extern "C" void WINAPI ASM_HidD_GetHidGuid();
extern "C" void WINAPI ASM_HidD_GetIndexedString();
extern "C" void WINAPI ASM_HidD_GetInputReport();
extern "C" void WINAPI ASM_HidD_GetManufacturerString();
extern "C" void WINAPI ASM_HidD_GetMsGenreDescriptor();
extern "C" void WINAPI ASM_HidD_GetNumInputBuffers();
extern "C" void WINAPI ASM_HidD_GetPhysicalDescriptor();
extern "C" void WINAPI ASM_HidD_GetPreparsedData();
extern "C" void WINAPI ASM_HidD_GetProductString();
extern "C" void WINAPI ASM_HidD_GetSerialNumberString();
extern "C" void WINAPI ASM_HidD_Hello();
extern "C" void WINAPI ASM_HidD_SetConfiguration();
extern "C" void WINAPI ASM_HidD_SetFeature();
extern "C" void WINAPI ASM_HidD_SetNumInputBuffers();
extern "C" void WINAPI ASM_HidD_SetOutputReport();
extern "C" void WINAPI ASM_HidP_GetButtonCaps();
extern "C" void WINAPI ASM_HidP_GetCaps();
extern "C" void WINAPI ASM_HidP_GetData();
extern "C" void WINAPI ASM_HidP_GetExtendedAttributes();
extern "C" void WINAPI ASM_HidP_GetLinkCollectionNodes();
extern "C" void WINAPI ASM_HidP_GetScaledUsageValue();
extern "C" void WINAPI ASM_HidP_GetSpecificButtonCaps();
extern "C" void WINAPI ASM_HidP_GetSpecificValueCaps();
extern "C" void WINAPI ASM_HidP_GetUsageValue();
extern "C" void WINAPI ASM_HidP_GetUsageValueArray();
extern "C" void WINAPI ASM_HidP_GetUsages();
extern "C" void WINAPI ASM_HidP_GetUsagesEx();
extern "C" void WINAPI ASM_HidP_GetValueCaps();
extern "C" void WINAPI ASM_HidP_InitializeReportForID();
extern "C" void WINAPI ASM_HidP_MaxDataListLength();
extern "C" void WINAPI ASM_HidP_MaxUsageListLength();
extern "C" void WINAPI ASM_HidP_SetData();
extern "C" void WINAPI ASM_HidP_SetScaledUsageValue();
extern "C" void WINAPI ASM_HidP_SetUsageValue();
extern "C" void WINAPI ASM_HidP_SetUsageValueArray();
extern "C" void WINAPI ASM_HidP_SetUsages();
extern "C" void WINAPI ASM_HidP_TranslateUsagesToI8042ScanCodes();
extern "C" void WINAPI ASM_HidP_UnsetUsages();
extern "C" void WINAPI ASM_HidP_UsageListDifference();
extern "C" void WINAPI ASM_OpenDriver();
extern "C" void WINAPI ASM_PlaySound();
extern "C" void WINAPI ASM_PlaySoundA();
extern "C" void WINAPI ASM_PlaySoundW();
extern "C" void WINAPI ASM_SendDriverMessage();
extern "C" void WINAPI ASM_VerFindFileA();
extern "C" void WINAPI ASM_VerFindFileW();
extern "C" void WINAPI ASM_VerInstallFileA();
extern "C" void WINAPI ASM_VerInstallFileW();
extern "C" void WINAPI ASM_VerLanguageNameA();
extern "C" void WINAPI ASM_VerLanguageNameW();
extern "C" void WINAPI ASM_VerQueryValueA();
extern "C" void WINAPI ASM_VerQueryValueW();
extern "C" void WINAPI ASM_WOWAppExit();
extern "C" void WINAPI ASM_auxGetDevCapsA();
extern "C" void WINAPI ASM_auxGetDevCapsW();
extern "C" void WINAPI ASM_auxGetNumDevs();
extern "C" void WINAPI ASM_auxGetVolume();
extern "C" void WINAPI ASM_auxOutMessage();
extern "C" void WINAPI ASM_auxSetVolume();
extern "C" void WINAPI ASM_joyConfigChanged();
extern "C" void WINAPI ASM_joyGetDevCapsA();
extern "C" void WINAPI ASM_joyGetDevCapsW();
extern "C" void WINAPI ASM_joyGetNumDevs();
extern "C" void WINAPI ASM_joyGetPos();
extern "C" void WINAPI ASM_joyGetPosEx();
extern "C" void WINAPI ASM_joyGetThreshold();
extern "C" void WINAPI ASM_joyReleaseCapture();
extern "C" void WINAPI ASM_joySetCapture();
extern "C" void WINAPI ASM_joySetThreshold();
extern "C" void WINAPI ASM_mciDriverNotify();
extern "C" void WINAPI ASM_mciDriverYield();
extern "C" void WINAPI ASM_mciExecute();
extern "C" void WINAPI ASM_mciFreeCommandResource();
extern "C" void WINAPI ASM_mciGetCreatorTask();
extern "C" void WINAPI ASM_mciGetDeviceIDA();
extern "C" void WINAPI ASM_mciGetDeviceIDFromElementIDA();
extern "C" void WINAPI ASM_mciGetDeviceIDFromElementIDW();
extern "C" void WINAPI ASM_mciGetDeviceIDW();
extern "C" void WINAPI ASM_mciGetDriverData();
extern "C" void WINAPI ASM_mciGetErrorStringA();
extern "C" void WINAPI ASM_mciGetErrorStringW();
extern "C" void WINAPI ASM_mciGetYieldProc();
extern "C" void WINAPI ASM_mciLoadCommandResource();
extern "C" void WINAPI ASM_mciSendCommandA();
extern "C" void WINAPI ASM_mciSendCommandW();
extern "C" void WINAPI ASM_mciSendStringA();
extern "C" void WINAPI ASM_mciSendStringW();
extern "C" void WINAPI ASM_mciSetDriverData();
extern "C" void WINAPI ASM_mciSetYieldProc();
extern "C" void WINAPI ASM_midiConnect();
extern "C" void WINAPI ASM_midiDisconnect();
extern "C" void WINAPI ASM_midiInAddBuffer();
extern "C" void WINAPI ASM_midiInClose();
extern "C" void WINAPI ASM_midiInGetDevCapsA();
extern "C" void WINAPI ASM_midiInGetDevCapsW();
extern "C" void WINAPI ASM_midiInGetErrorTextA();
extern "C" void WINAPI ASM_midiInGetErrorTextW();
extern "C" void WINAPI ASM_midiInGetID();
extern "C" void WINAPI ASM_midiInGetNumDevs();
extern "C" void WINAPI ASM_midiInMessage();
extern "C" void WINAPI ASM_midiInOpen();
extern "C" void WINAPI ASM_midiInPrepareHeader();
extern "C" void WINAPI ASM_midiInReset();
extern "C" void WINAPI ASM_midiInStart();
extern "C" void WINAPI ASM_midiInStop();
extern "C" void WINAPI ASM_midiInUnprepareHeader();
extern "C" void WINAPI ASM_midiOutCacheDrumPatches();
extern "C" void WINAPI ASM_midiOutCachePatches();
extern "C" void WINAPI ASM_midiOutClose();
extern "C" void WINAPI ASM_midiOutGetDevCapsA();
extern "C" void WINAPI ASM_midiOutGetDevCapsW();
extern "C" void WINAPI ASM_midiOutGetErrorTextA();
extern "C" void WINAPI ASM_midiOutGetErrorTextW();
extern "C" void WINAPI ASM_midiOutGetID();
extern "C" void WINAPI ASM_midiOutGetNumDevs();
extern "C" void WINAPI ASM_midiOutGetVolume();
extern "C" void WINAPI ASM_midiOutLongMsg();
extern "C" void WINAPI ASM_midiOutMessage();
extern "C" void WINAPI ASM_midiOutOpen();
extern "C" void WINAPI ASM_midiOutPrepareHeader();
extern "C" void WINAPI ASM_midiOutReset();
extern "C" void WINAPI ASM_midiOutSetVolume();
extern "C" void WINAPI ASM_midiOutShortMsg();
extern "C" void WINAPI ASM_midiOutUnprepareHeader();
extern "C" void WINAPI ASM_midiStreamClose();
extern "C" void WINAPI ASM_midiStreamOpen();
extern "C" void WINAPI ASM_midiStreamOut();
extern "C" void WINAPI ASM_midiStreamPause();
extern "C" void WINAPI ASM_midiStreamPosition();
extern "C" void WINAPI ASM_midiStreamProperty();
extern "C" void WINAPI ASM_midiStreamRestart();
extern "C" void WINAPI ASM_midiStreamStop();
extern "C" void WINAPI ASM_mixerClose();
extern "C" void WINAPI ASM_mixerGetControlDetailsA();
extern "C" void WINAPI ASM_mixerGetControlDetailsW();
extern "C" void WINAPI ASM_mixerGetDevCapsA();
extern "C" void WINAPI ASM_mixerGetDevCapsW();
extern "C" void WINAPI ASM_mixerGetID();
extern "C" void WINAPI ASM_mixerGetLineControlsA();
extern "C" void WINAPI ASM_mixerGetLineControlsW();
extern "C" void WINAPI ASM_mixerGetLineInfoA();
extern "C" void WINAPI ASM_mixerGetLineInfoW();
extern "C" void WINAPI ASM_mixerGetNumDevs();
extern "C" void WINAPI ASM_mixerMessage();
extern "C" void WINAPI ASM_mixerOpen();
extern "C" void WINAPI ASM_mixerSetControlDetails();
extern "C" void WINAPI ASM_mmDrvInstall();
extern "C" void WINAPI ASM_mmGetCurrentTask();
extern "C" void WINAPI ASM_mmTaskBlock();
extern "C" void WINAPI ASM_mmTaskCreate();
extern "C" void WINAPI ASM_mmTaskSignal();
extern "C" void WINAPI ASM_mmTaskYield();
extern "C" void WINAPI ASM_mmioAdvance();
extern "C" void WINAPI ASM_mmioAscend();
extern "C" void WINAPI ASM_mmioClose();
extern "C" void WINAPI ASM_mmioCreateChunk();
extern "C" void WINAPI ASM_mmioDescend();
extern "C" void WINAPI ASM_mmioFlush();
extern "C" void WINAPI ASM_mmioGetInfo();
extern "C" void WINAPI ASM_mmioInstallIOProcA();
extern "C" void WINAPI ASM_mmioInstallIOProcW();
extern "C" void WINAPI ASM_mmioOpenA();
extern "C" void WINAPI ASM_mmioOpenW();
extern "C" void WINAPI ASM_mmioRead();
extern "C" void WINAPI ASM_mmioRenameA();
extern "C" void WINAPI ASM_mmioRenameW();
extern "C" void WINAPI ASM_mmioSeek();
extern "C" void WINAPI ASM_mmioSendMessage();
extern "C" void WINAPI ASM_mmioSetBuffer();
extern "C" void WINAPI ASM_mmioSetInfo();
extern "C" void WINAPI ASM_mmioStringToFOURCCA();
extern "C" void WINAPI ASM_mmioStringToFOURCCW();
extern "C" void WINAPI ASM_mmioWrite();
extern "C" void WINAPI ASM_mmsystemGetVersion();
extern "C" void WINAPI ASM_sndPlaySoundA();
extern "C" void WINAPI ASM_sndPlaySoundW();
extern "C" void WINAPI ASM_timeBeginPeriod();
extern "C" void WINAPI ASM_timeEndPeriod();
extern "C" void WINAPI ASM_timeGetDevCaps();
extern "C" void WINAPI ASM_timeGetSystemTime();
extern "C" void WINAPI ASM_timeGetTime();
extern "C" void WINAPI ASM_timeKillEvent();
extern "C" void WINAPI ASM_timeSetEvent();
extern "C" void WINAPI ASM_waveInAddBuffer();
extern "C" void WINAPI ASM_waveInClose();
extern "C" void WINAPI ASM_waveInGetDevCapsA();
extern "C" void WINAPI ASM_waveInGetDevCapsW();
extern "C" void WINAPI ASM_waveInGetErrorTextA();
extern "C" void WINAPI ASM_waveInGetErrorTextW();
extern "C" void WINAPI ASM_waveInGetID();
extern "C" void WINAPI ASM_waveInGetNumDevs();
extern "C" void WINAPI ASM_waveInGetPosition();
extern "C" void WINAPI ASM_waveInMessage();
extern "C" void WINAPI ASM_waveInOpen();
extern "C" void WINAPI ASM_waveInPrepareHeader();
extern "C" void WINAPI ASM_waveInReset();
extern "C" void WINAPI ASM_waveInStart();
extern "C" void WINAPI ASM_waveInStop();
extern "C" void WINAPI ASM_waveInUnprepareHeader();
extern "C" void WINAPI ASM_waveOutBreakLoop();
extern "C" void WINAPI ASM_waveOutClose();
extern "C" void WINAPI ASM_waveOutGetDevCapsA();
extern "C" void WINAPI ASM_waveOutGetDevCapsW();
extern "C" void WINAPI ASM_waveOutGetErrorTextA();
extern "C" void WINAPI ASM_waveOutGetErrorTextW();
extern "C" void WINAPI ASM_waveOutGetID();
extern "C" void WINAPI ASM_waveOutGetNumDevs();
extern "C" void WINAPI ASM_waveOutGetPitch();
extern "C" void WINAPI ASM_waveOutGetPlaybackRate();
extern "C" void WINAPI ASM_waveOutGetPosition();
extern "C" void WINAPI ASM_waveOutGetVolume();
extern "C" void WINAPI ASM_waveOutMessage();
extern "C" void WINAPI ASM_waveOutOpen();
extern "C" void WINAPI ASM_waveOutPause();
extern "C" void WINAPI ASM_waveOutPrepareHeader();
extern "C" void WINAPI ASM_waveOutReset();
extern "C" void WINAPI ASM_waveOutRestart();
extern "C" void WINAPI ASM_waveOutSetPitch();
extern "C" void WINAPI ASM_waveOutSetPlaybackRate();
extern "C" void WINAPI ASM_waveOutSetVolume();
extern "C" void WINAPI ASM_waveOutUnprepareHeader();
extern "C" void WINAPI ASM_waveOutWrite();

#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:CloseDriver=ASM_CloseDriver")
#else
#pragma comment(linker, "/EXPORT:CloseDriver=_ASM_CloseDriver@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:DefDriverProc=ASM_DefDriverProc")
#else
#pragma comment(linker, "/EXPORT:DefDriverProc=_ASM_DefDriverProc@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:DllMain=ASM_DllMain")
#else
#pragma comment(linker, "/EXPORT:DllMain=_ASM_DllMain@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:DriverCallback=ASM_DriverCallback")
#else
#pragma comment(linker, "/EXPORT:DriverCallback=_ASM_DriverCallback@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:DrvGetModuleHandle=ASM_DrvGetModuleHandle")
#else
#pragma comment(linker, "/EXPORT:DrvGetModuleHandle=_ASM_DrvGetModuleHandle@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:GetDriverModuleHandle=ASM_GetDriverModuleHandle")
#else
#pragma comment(linker, "/EXPORT:GetDriverModuleHandle=_ASM_GetDriverModuleHandle@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:GetFileVersionInfoA=ASM_GetFileVersionInfoA")
#else
#pragma comment(linker, "/EXPORT:GetFileVersionInfoA=_ASM_GetFileVersionInfoA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:GetFileVersionInfoByHandle=ASM_GetFileVersionInfoByHandle")
#else
#pragma comment(linker, "/EXPORT:GetFileVersionInfoByHandle=_ASM_GetFileVersionInfoByHandle@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExA=ASM_GetFileVersionInfoExA")
#else
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExA=_ASM_GetFileVersionInfoExA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExW=ASM_GetFileVersionInfoExW")
#else
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExW=_ASM_GetFileVersionInfoExW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeA=ASM_GetFileVersionInfoSizeA")
#else
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeA=_ASM_GetFileVersionInfoSizeA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExA=ASM_GetFileVersionInfoSizeExA")
#else
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExA=_ASM_GetFileVersionInfoSizeExA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExW=ASM_GetFileVersionInfoSizeExW")
#else
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExW=_ASM_GetFileVersionInfoSizeExW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeW=ASM_GetFileVersionInfoSizeW")
#else
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeW=_ASM_GetFileVersionInfoSizeW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:GetFileVersionInfoW=ASM_GetFileVersionInfoW")
#else
#pragma comment(linker, "/EXPORT:GetFileVersionInfoW=_ASM_GetFileVersionInfoW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_FlushQueue=ASM_HidD_FlushQueue")
#else
#pragma comment(linker, "/EXPORT:HidD_FlushQueue=_ASM_HidD_FlushQueue@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_FreePreparsedData=ASM_HidD_FreePreparsedData")
#else
#pragma comment(linker, "/EXPORT:HidD_FreePreparsedData=_ASM_HidD_FreePreparsedData@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetAttributes=ASM_HidD_GetAttributes")
#else
#pragma comment(linker, "/EXPORT:HidD_GetAttributes=_ASM_HidD_GetAttributes@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetConfiguration=ASM_HidD_GetConfiguration")
#else
#pragma comment(linker, "/EXPORT:HidD_GetConfiguration=_ASM_HidD_GetConfiguration@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetFeature=ASM_HidD_GetFeature")
#else
#pragma comment(linker, "/EXPORT:HidD_GetFeature=_ASM_HidD_GetFeature@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetHidGuid=ASM_HidD_GetHidGuid")
#else
#pragma comment(linker, "/EXPORT:HidD_GetHidGuid=_ASM_HidD_GetHidGuid@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetIndexedString=ASM_HidD_GetIndexedString")
#else
#pragma comment(linker, "/EXPORT:HidD_GetIndexedString=_ASM_HidD_GetIndexedString@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetInputReport=ASM_HidD_GetInputReport")
#else
#pragma comment(linker, "/EXPORT:HidD_GetInputReport=_ASM_HidD_GetInputReport@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetManufacturerString=ASM_HidD_GetManufacturerString")
#else
#pragma comment(linker, "/EXPORT:HidD_GetManufacturerString=_ASM_HidD_GetManufacturerString@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetMsGenreDescriptor=ASM_HidD_GetMsGenreDescriptor")
#else
#pragma comment(linker, "/EXPORT:HidD_GetMsGenreDescriptor=_ASM_HidD_GetMsGenreDescriptor@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetNumInputBuffers=ASM_HidD_GetNumInputBuffers")
#else
#pragma comment(linker, "/EXPORT:HidD_GetNumInputBuffers=_ASM_HidD_GetNumInputBuffers@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetPhysicalDescriptor=ASM_HidD_GetPhysicalDescriptor")
#else
#pragma comment(linker, "/EXPORT:HidD_GetPhysicalDescriptor=_ASM_HidD_GetPhysicalDescriptor@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetPreparsedData=ASM_HidD_GetPreparsedData")
#else
#pragma comment(linker, "/EXPORT:HidD_GetPreparsedData=_ASM_HidD_GetPreparsedData@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetProductString=ASM_HidD_GetProductString")
#else
#pragma comment(linker, "/EXPORT:HidD_GetProductString=_ASM_HidD_GetProductString@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_GetSerialNumberString=ASM_HidD_GetSerialNumberString")
#else
#pragma comment(linker, "/EXPORT:HidD_GetSerialNumberString=_ASM_HidD_GetSerialNumberString@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_Hello=ASM_HidD_Hello")
#else
#pragma comment(linker, "/EXPORT:HidD_Hello=_ASM_HidD_Hello@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_SetConfiguration=ASM_HidD_SetConfiguration")
#else
#pragma comment(linker, "/EXPORT:HidD_SetConfiguration=_ASM_HidD_SetConfiguration@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_SetFeature=ASM_HidD_SetFeature")
#else
#pragma comment(linker, "/EXPORT:HidD_SetFeature=_ASM_HidD_SetFeature@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_SetNumInputBuffers=ASM_HidD_SetNumInputBuffers")
#else
#pragma comment(linker, "/EXPORT:HidD_SetNumInputBuffers=_ASM_HidD_SetNumInputBuffers@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidD_SetOutputReport=ASM_HidD_SetOutputReport")
#else
#pragma comment(linker, "/EXPORT:HidD_SetOutputReport=_ASM_HidD_SetOutputReport@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetButtonCaps=ASM_HidP_GetButtonCaps")
#else
#pragma comment(linker, "/EXPORT:HidP_GetButtonCaps=_ASM_HidP_GetButtonCaps@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetCaps=ASM_HidP_GetCaps")
#else
#pragma comment(linker, "/EXPORT:HidP_GetCaps=_ASM_HidP_GetCaps@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetData=ASM_HidP_GetData")
#else
#pragma comment(linker, "/EXPORT:HidP_GetData=_ASM_HidP_GetData@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetExtendedAttributes=ASM_HidP_GetExtendedAttributes")
#else
#pragma comment(linker, "/EXPORT:HidP_GetExtendedAttributes=_ASM_HidP_GetExtendedAttributes@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetLinkCollectionNodes=ASM_HidP_GetLinkCollectionNodes")
#else
#pragma comment(linker, "/EXPORT:HidP_GetLinkCollectionNodes=_ASM_HidP_GetLinkCollectionNodes@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetScaledUsageValue=ASM_HidP_GetScaledUsageValue")
#else
#pragma comment(linker, "/EXPORT:HidP_GetScaledUsageValue=_ASM_HidP_GetScaledUsageValue@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetSpecificButtonCaps=ASM_HidP_GetSpecificButtonCaps")
#else
#pragma comment(linker, "/EXPORT:HidP_GetSpecificButtonCaps=_ASM_HidP_GetSpecificButtonCaps@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetSpecificValueCaps=ASM_HidP_GetSpecificValueCaps")
#else
#pragma comment(linker, "/EXPORT:HidP_GetSpecificValueCaps=_ASM_HidP_GetSpecificValueCaps@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetUsageValue=ASM_HidP_GetUsageValue")
#else
#pragma comment(linker, "/EXPORT:HidP_GetUsageValue=_ASM_HidP_GetUsageValue@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetUsageValueArray=ASM_HidP_GetUsageValueArray")
#else
#pragma comment(linker, "/EXPORT:HidP_GetUsageValueArray=_ASM_HidP_GetUsageValueArray@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetUsages=ASM_HidP_GetUsages")
#else
#pragma comment(linker, "/EXPORT:HidP_GetUsages=_ASM_HidP_GetUsages@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetUsagesEx=ASM_HidP_GetUsagesEx")
#else
#pragma comment(linker, "/EXPORT:HidP_GetUsagesEx=_ASM_HidP_GetUsagesEx@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_GetValueCaps=ASM_HidP_GetValueCaps")
#else
#pragma comment(linker, "/EXPORT:HidP_GetValueCaps=_ASM_HidP_GetValueCaps@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_InitializeReportForID=ASM_HidP_InitializeReportForID")
#else
#pragma comment(linker, "/EXPORT:HidP_InitializeReportForID=_ASM_HidP_InitializeReportForID@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_MaxDataListLength=ASM_HidP_MaxDataListLength")
#else
#pragma comment(linker, "/EXPORT:HidP_MaxDataListLength=_ASM_HidP_MaxDataListLength@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_MaxUsageListLength=ASM_HidP_MaxUsageListLength")
#else
#pragma comment(linker, "/EXPORT:HidP_MaxUsageListLength=_ASM_HidP_MaxUsageListLength@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_SetData=ASM_HidP_SetData")
#else
#pragma comment(linker, "/EXPORT:HidP_SetData=_ASM_HidP_SetData@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_SetScaledUsageValue=ASM_HidP_SetScaledUsageValue")
#else
#pragma comment(linker, "/EXPORT:HidP_SetScaledUsageValue=_ASM_HidP_SetScaledUsageValue@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_SetUsageValue=ASM_HidP_SetUsageValue")
#else
#pragma comment(linker, "/EXPORT:HidP_SetUsageValue=_ASM_HidP_SetUsageValue@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_SetUsageValueArray=ASM_HidP_SetUsageValueArray")
#else
#pragma comment(linker, "/EXPORT:HidP_SetUsageValueArray=_ASM_HidP_SetUsageValueArray@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_SetUsages=ASM_HidP_SetUsages")
#else
#pragma comment(linker, "/EXPORT:HidP_SetUsages=_ASM_HidP_SetUsages@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_TranslateUsagesToI8042ScanCodes=ASM_HidP_TranslateUsagesToI8042ScanCodes")
#else
#pragma comment(linker, "/EXPORT:HidP_TranslateUsagesToI8042ScanCodes=_ASM_HidP_TranslateUsagesToI8042ScanCodes@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_UnsetUsages=ASM_HidP_UnsetUsages")
#else
#pragma comment(linker, "/EXPORT:HidP_UnsetUsages=_ASM_HidP_UnsetUsages@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:HidP_UsageListDifference=ASM_HidP_UsageListDifference")
#else
#pragma comment(linker, "/EXPORT:HidP_UsageListDifference=_ASM_HidP_UsageListDifference@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:OpenDriver=ASM_OpenDriver")
#else
#pragma comment(linker, "/EXPORT:OpenDriver=_ASM_OpenDriver@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:PlaySound=ASM_PlaySound")
#else
#pragma comment(linker, "/EXPORT:PlaySound=_ASM_PlaySound@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:PlaySoundA=ASM_PlaySoundA")
#else
#pragma comment(linker, "/EXPORT:PlaySoundA=_ASM_PlaySoundA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:PlaySoundW=ASM_PlaySoundW")
#else
#pragma comment(linker, "/EXPORT:PlaySoundW=_ASM_PlaySoundW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:SendDriverMessage=ASM_SendDriverMessage")
#else
#pragma comment(linker, "/EXPORT:SendDriverMessage=_ASM_SendDriverMessage@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:VerFindFileA=ASM_VerFindFileA")
#else
#pragma comment(linker, "/EXPORT:VerFindFileA=_ASM_VerFindFileA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:VerFindFileW=ASM_VerFindFileW")
#else
#pragma comment(linker, "/EXPORT:VerFindFileW=_ASM_VerFindFileW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:VerInstallFileA=ASM_VerInstallFileA")
#else
#pragma comment(linker, "/EXPORT:VerInstallFileA=_ASM_VerInstallFileA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:VerInstallFileW=ASM_VerInstallFileW")
#else
#pragma comment(linker, "/EXPORT:VerInstallFileW=_ASM_VerInstallFileW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:VerLanguageNameA=ASM_VerLanguageNameA")
#else
#pragma comment(linker, "/EXPORT:VerLanguageNameA=_ASM_VerLanguageNameA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:VerLanguageNameW=ASM_VerLanguageNameW")
#else
#pragma comment(linker, "/EXPORT:VerLanguageNameW=_ASM_VerLanguageNameW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:VerQueryValueA=ASM_VerQueryValueA")
#else
#pragma comment(linker, "/EXPORT:VerQueryValueA=_ASM_VerQueryValueA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:VerQueryValueW=ASM_VerQueryValueW")
#else
#pragma comment(linker, "/EXPORT:VerQueryValueW=_ASM_VerQueryValueW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:WOWAppExit=ASM_WOWAppExit")
#else
#pragma comment(linker, "/EXPORT:WOWAppExit=_ASM_WOWAppExit@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:auxGetDevCapsA=ASM_auxGetDevCapsA")
#else
#pragma comment(linker, "/EXPORT:auxGetDevCapsA=_ASM_auxGetDevCapsA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:auxGetDevCapsW=ASM_auxGetDevCapsW")
#else
#pragma comment(linker, "/EXPORT:auxGetDevCapsW=_ASM_auxGetDevCapsW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:auxGetNumDevs=ASM_auxGetNumDevs")
#else
#pragma comment(linker, "/EXPORT:auxGetNumDevs=_ASM_auxGetNumDevs@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:auxGetVolume=ASM_auxGetVolume")
#else
#pragma comment(linker, "/EXPORT:auxGetVolume=_ASM_auxGetVolume@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:auxOutMessage=ASM_auxOutMessage")
#else
#pragma comment(linker, "/EXPORT:auxOutMessage=_ASM_auxOutMessage@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:auxSetVolume=ASM_auxSetVolume")
#else
#pragma comment(linker, "/EXPORT:auxSetVolume=_ASM_auxSetVolume@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:joyConfigChanged=ASM_joyConfigChanged")
#else
#pragma comment(linker, "/EXPORT:joyConfigChanged=_ASM_joyConfigChanged@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:joyGetDevCapsA=ASM_joyGetDevCapsA")
#else
#pragma comment(linker, "/EXPORT:joyGetDevCapsA=_ASM_joyGetDevCapsA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:joyGetDevCapsW=ASM_joyGetDevCapsW")
#else
#pragma comment(linker, "/EXPORT:joyGetDevCapsW=_ASM_joyGetDevCapsW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:joyGetNumDevs=ASM_joyGetNumDevs")
#else
#pragma comment(linker, "/EXPORT:joyGetNumDevs=_ASM_joyGetNumDevs@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:joyGetPos=ASM_joyGetPos")
#else
#pragma comment(linker, "/EXPORT:joyGetPos=_ASM_joyGetPos@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:joyGetPosEx=ASM_joyGetPosEx")
#else
#pragma comment(linker, "/EXPORT:joyGetPosEx=_ASM_joyGetPosEx@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:joyGetThreshold=ASM_joyGetThreshold")
#else
#pragma comment(linker, "/EXPORT:joyGetThreshold=_ASM_joyGetThreshold@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:joyReleaseCapture=ASM_joyReleaseCapture")
#else
#pragma comment(linker, "/EXPORT:joyReleaseCapture=_ASM_joyReleaseCapture@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:joySetCapture=ASM_joySetCapture")
#else
#pragma comment(linker, "/EXPORT:joySetCapture=_ASM_joySetCapture@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:joySetThreshold=ASM_joySetThreshold")
#else
#pragma comment(linker, "/EXPORT:joySetThreshold=_ASM_joySetThreshold@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciDriverNotify=ASM_mciDriverNotify")
#else
#pragma comment(linker, "/EXPORT:mciDriverNotify=_ASM_mciDriverNotify@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciDriverYield=ASM_mciDriverYield")
#else
#pragma comment(linker, "/EXPORT:mciDriverYield=_ASM_mciDriverYield@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciExecute=ASM_mciExecute")
#else
#pragma comment(linker, "/EXPORT:mciExecute=_ASM_mciExecute@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciFreeCommandResource=ASM_mciFreeCommandResource")
#else
#pragma comment(linker, "/EXPORT:mciFreeCommandResource=_ASM_mciFreeCommandResource@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciGetCreatorTask=ASM_mciGetCreatorTask")
#else
#pragma comment(linker, "/EXPORT:mciGetCreatorTask=_ASM_mciGetCreatorTask@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciGetDeviceIDA=ASM_mciGetDeviceIDA")
#else
#pragma comment(linker, "/EXPORT:mciGetDeviceIDA=_ASM_mciGetDeviceIDA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDA=ASM_mciGetDeviceIDFromElementIDA")
#else
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDA=_ASM_mciGetDeviceIDFromElementIDA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDW=ASM_mciGetDeviceIDFromElementIDW")
#else
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDW=_ASM_mciGetDeviceIDFromElementIDW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciGetDeviceIDW=ASM_mciGetDeviceIDW")
#else
#pragma comment(linker, "/EXPORT:mciGetDeviceIDW=_ASM_mciGetDeviceIDW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciGetDriverData=ASM_mciGetDriverData")
#else
#pragma comment(linker, "/EXPORT:mciGetDriverData=_ASM_mciGetDriverData@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciGetErrorStringA=ASM_mciGetErrorStringA")
#else
#pragma comment(linker, "/EXPORT:mciGetErrorStringA=_ASM_mciGetErrorStringA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciGetErrorStringW=ASM_mciGetErrorStringW")
#else
#pragma comment(linker, "/EXPORT:mciGetErrorStringW=_ASM_mciGetErrorStringW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciGetYieldProc=ASM_mciGetYieldProc")
#else
#pragma comment(linker, "/EXPORT:mciGetYieldProc=_ASM_mciGetYieldProc@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciLoadCommandResource=ASM_mciLoadCommandResource")
#else
#pragma comment(linker, "/EXPORT:mciLoadCommandResource=_ASM_mciLoadCommandResource@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciSendCommandA=ASM_mciSendCommandA")
#else
#pragma comment(linker, "/EXPORT:mciSendCommandA=_ASM_mciSendCommandA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciSendCommandW=ASM_mciSendCommandW")
#else
#pragma comment(linker, "/EXPORT:mciSendCommandW=_ASM_mciSendCommandW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciSendStringA=ASM_mciSendStringA")
#else
#pragma comment(linker, "/EXPORT:mciSendStringA=_ASM_mciSendStringA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciSendStringW=ASM_mciSendStringW")
#else
#pragma comment(linker, "/EXPORT:mciSendStringW=_ASM_mciSendStringW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciSetDriverData=ASM_mciSetDriverData")
#else
#pragma comment(linker, "/EXPORT:mciSetDriverData=_ASM_mciSetDriverData@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mciSetYieldProc=ASM_mciSetYieldProc")
#else
#pragma comment(linker, "/EXPORT:mciSetYieldProc=_ASM_mciSetYieldProc@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiConnect=ASM_midiConnect")
#else
#pragma comment(linker, "/EXPORT:midiConnect=_ASM_midiConnect@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiDisconnect=ASM_midiDisconnect")
#else
#pragma comment(linker, "/EXPORT:midiDisconnect=_ASM_midiDisconnect@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInAddBuffer=ASM_midiInAddBuffer")
#else
#pragma comment(linker, "/EXPORT:midiInAddBuffer=_ASM_midiInAddBuffer@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInClose=ASM_midiInClose")
#else
#pragma comment(linker, "/EXPORT:midiInClose=_ASM_midiInClose@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInGetDevCapsA=ASM_midiInGetDevCapsA")
#else
#pragma comment(linker, "/EXPORT:midiInGetDevCapsA=_ASM_midiInGetDevCapsA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInGetDevCapsW=ASM_midiInGetDevCapsW")
#else
#pragma comment(linker, "/EXPORT:midiInGetDevCapsW=_ASM_midiInGetDevCapsW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInGetErrorTextA=ASM_midiInGetErrorTextA")
#else
#pragma comment(linker, "/EXPORT:midiInGetErrorTextA=_ASM_midiInGetErrorTextA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInGetErrorTextW=ASM_midiInGetErrorTextW")
#else
#pragma comment(linker, "/EXPORT:midiInGetErrorTextW=_ASM_midiInGetErrorTextW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInGetID=ASM_midiInGetID")
#else
#pragma comment(linker, "/EXPORT:midiInGetID=_ASM_midiInGetID@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInGetNumDevs=ASM_midiInGetNumDevs")
#else
#pragma comment(linker, "/EXPORT:midiInGetNumDevs=_ASM_midiInGetNumDevs@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInMessage=ASM_midiInMessage")
#else
#pragma comment(linker, "/EXPORT:midiInMessage=_ASM_midiInMessage@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInOpen=ASM_midiInOpen")
#else
#pragma comment(linker, "/EXPORT:midiInOpen=_ASM_midiInOpen@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInPrepareHeader=ASM_midiInPrepareHeader")
#else
#pragma comment(linker, "/EXPORT:midiInPrepareHeader=_ASM_midiInPrepareHeader@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInReset=ASM_midiInReset")
#else
#pragma comment(linker, "/EXPORT:midiInReset=_ASM_midiInReset@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInStart=ASM_midiInStart")
#else
#pragma comment(linker, "/EXPORT:midiInStart=_ASM_midiInStart@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInStop=ASM_midiInStop")
#else
#pragma comment(linker, "/EXPORT:midiInStop=_ASM_midiInStop@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiInUnprepareHeader=ASM_midiInUnprepareHeader")
#else
#pragma comment(linker, "/EXPORT:midiInUnprepareHeader=_ASM_midiInUnprepareHeader@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutCacheDrumPatches=ASM_midiOutCacheDrumPatches")
#else
#pragma comment(linker, "/EXPORT:midiOutCacheDrumPatches=_ASM_midiOutCacheDrumPatches@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutCachePatches=ASM_midiOutCachePatches")
#else
#pragma comment(linker, "/EXPORT:midiOutCachePatches=_ASM_midiOutCachePatches@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutClose=ASM_midiOutClose")
#else
#pragma comment(linker, "/EXPORT:midiOutClose=_ASM_midiOutClose@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsA=ASM_midiOutGetDevCapsA")
#else
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsA=_ASM_midiOutGetDevCapsA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsW=ASM_midiOutGetDevCapsW")
#else
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsW=_ASM_midiOutGetDevCapsW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextA=ASM_midiOutGetErrorTextA")
#else
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextA=_ASM_midiOutGetErrorTextA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextW=ASM_midiOutGetErrorTextW")
#else
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextW=_ASM_midiOutGetErrorTextW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutGetID=ASM_midiOutGetID")
#else
#pragma comment(linker, "/EXPORT:midiOutGetID=_ASM_midiOutGetID@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutGetNumDevs=ASM_midiOutGetNumDevs")
#else
#pragma comment(linker, "/EXPORT:midiOutGetNumDevs=_ASM_midiOutGetNumDevs@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutGetVolume=ASM_midiOutGetVolume")
#else
#pragma comment(linker, "/EXPORT:midiOutGetVolume=_ASM_midiOutGetVolume@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutLongMsg=ASM_midiOutLongMsg")
#else
#pragma comment(linker, "/EXPORT:midiOutLongMsg=_ASM_midiOutLongMsg@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutMessage=ASM_midiOutMessage")
#else
#pragma comment(linker, "/EXPORT:midiOutMessage=_ASM_midiOutMessage@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutOpen=ASM_midiOutOpen")
#else
#pragma comment(linker, "/EXPORT:midiOutOpen=_ASM_midiOutOpen@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutPrepareHeader=ASM_midiOutPrepareHeader")
#else
#pragma comment(linker, "/EXPORT:midiOutPrepareHeader=_ASM_midiOutPrepareHeader@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutReset=ASM_midiOutReset")
#else
#pragma comment(linker, "/EXPORT:midiOutReset=_ASM_midiOutReset@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutSetVolume=ASM_midiOutSetVolume")
#else
#pragma comment(linker, "/EXPORT:midiOutSetVolume=_ASM_midiOutSetVolume@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutShortMsg=ASM_midiOutShortMsg")
#else
#pragma comment(linker, "/EXPORT:midiOutShortMsg=_ASM_midiOutShortMsg@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiOutUnprepareHeader=ASM_midiOutUnprepareHeader")
#else
#pragma comment(linker, "/EXPORT:midiOutUnprepareHeader=_ASM_midiOutUnprepareHeader@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiStreamClose=ASM_midiStreamClose")
#else
#pragma comment(linker, "/EXPORT:midiStreamClose=_ASM_midiStreamClose@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiStreamOpen=ASM_midiStreamOpen")
#else
#pragma comment(linker, "/EXPORT:midiStreamOpen=_ASM_midiStreamOpen@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiStreamOut=ASM_midiStreamOut")
#else
#pragma comment(linker, "/EXPORT:midiStreamOut=_ASM_midiStreamOut@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiStreamPause=ASM_midiStreamPause")
#else
#pragma comment(linker, "/EXPORT:midiStreamPause=_ASM_midiStreamPause@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiStreamPosition=ASM_midiStreamPosition")
#else
#pragma comment(linker, "/EXPORT:midiStreamPosition=_ASM_midiStreamPosition@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiStreamProperty=ASM_midiStreamProperty")
#else
#pragma comment(linker, "/EXPORT:midiStreamProperty=_ASM_midiStreamProperty@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiStreamRestart=ASM_midiStreamRestart")
#else
#pragma comment(linker, "/EXPORT:midiStreamRestart=_ASM_midiStreamRestart@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:midiStreamStop=ASM_midiStreamStop")
#else
#pragma comment(linker, "/EXPORT:midiStreamStop=_ASM_midiStreamStop@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerClose=ASM_mixerClose")
#else
#pragma comment(linker, "/EXPORT:mixerClose=_ASM_mixerClose@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsA=ASM_mixerGetControlDetailsA")
#else
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsA=_ASM_mixerGetControlDetailsA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsW=ASM_mixerGetControlDetailsW")
#else
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsW=_ASM_mixerGetControlDetailsW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerGetDevCapsA=ASM_mixerGetDevCapsA")
#else
#pragma comment(linker, "/EXPORT:mixerGetDevCapsA=_ASM_mixerGetDevCapsA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerGetDevCapsW=ASM_mixerGetDevCapsW")
#else
#pragma comment(linker, "/EXPORT:mixerGetDevCapsW=_ASM_mixerGetDevCapsW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerGetID=ASM_mixerGetID")
#else
#pragma comment(linker, "/EXPORT:mixerGetID=_ASM_mixerGetID@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerGetLineControlsA=ASM_mixerGetLineControlsA")
#else
#pragma comment(linker, "/EXPORT:mixerGetLineControlsA=_ASM_mixerGetLineControlsA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerGetLineControlsW=ASM_mixerGetLineControlsW")
#else
#pragma comment(linker, "/EXPORT:mixerGetLineControlsW=_ASM_mixerGetLineControlsW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerGetLineInfoA=ASM_mixerGetLineInfoA")
#else
#pragma comment(linker, "/EXPORT:mixerGetLineInfoA=_ASM_mixerGetLineInfoA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerGetLineInfoW=ASM_mixerGetLineInfoW")
#else
#pragma comment(linker, "/EXPORT:mixerGetLineInfoW=_ASM_mixerGetLineInfoW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerGetNumDevs=ASM_mixerGetNumDevs")
#else
#pragma comment(linker, "/EXPORT:mixerGetNumDevs=_ASM_mixerGetNumDevs@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerMessage=ASM_mixerMessage")
#else
#pragma comment(linker, "/EXPORT:mixerMessage=_ASM_mixerMessage@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerOpen=ASM_mixerOpen")
#else
#pragma comment(linker, "/EXPORT:mixerOpen=_ASM_mixerOpen@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mixerSetControlDetails=ASM_mixerSetControlDetails")
#else
#pragma comment(linker, "/EXPORT:mixerSetControlDetails=_ASM_mixerSetControlDetails@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmDrvInstall=ASM_mmDrvInstall")
#else
#pragma comment(linker, "/EXPORT:mmDrvInstall=_ASM_mmDrvInstall@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmGetCurrentTask=ASM_mmGetCurrentTask")
#else
#pragma comment(linker, "/EXPORT:mmGetCurrentTask=_ASM_mmGetCurrentTask@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmTaskBlock=ASM_mmTaskBlock")
#else
#pragma comment(linker, "/EXPORT:mmTaskBlock=_ASM_mmTaskBlock@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmTaskCreate=ASM_mmTaskCreate")
#else
#pragma comment(linker, "/EXPORT:mmTaskCreate=_ASM_mmTaskCreate@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmTaskSignal=ASM_mmTaskSignal")
#else
#pragma comment(linker, "/EXPORT:mmTaskSignal=_ASM_mmTaskSignal@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmTaskYield=ASM_mmTaskYield")
#else
#pragma comment(linker, "/EXPORT:mmTaskYield=_ASM_mmTaskYield@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioAdvance=ASM_mmioAdvance")
#else
#pragma comment(linker, "/EXPORT:mmioAdvance=_ASM_mmioAdvance@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioAscend=ASM_mmioAscend")
#else
#pragma comment(linker, "/EXPORT:mmioAscend=_ASM_mmioAscend@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioClose=ASM_mmioClose")
#else
#pragma comment(linker, "/EXPORT:mmioClose=_ASM_mmioClose@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioCreateChunk=ASM_mmioCreateChunk")
#else
#pragma comment(linker, "/EXPORT:mmioCreateChunk=_ASM_mmioCreateChunk@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioDescend=ASM_mmioDescend")
#else
#pragma comment(linker, "/EXPORT:mmioDescend=_ASM_mmioDescend@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioFlush=ASM_mmioFlush")
#else
#pragma comment(linker, "/EXPORT:mmioFlush=_ASM_mmioFlush@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioGetInfo=ASM_mmioGetInfo")
#else
#pragma comment(linker, "/EXPORT:mmioGetInfo=_ASM_mmioGetInfo@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioInstallIOProcA=ASM_mmioInstallIOProcA")
#else
#pragma comment(linker, "/EXPORT:mmioInstallIOProcA=_ASM_mmioInstallIOProcA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioInstallIOProcW=ASM_mmioInstallIOProcW")
#else
#pragma comment(linker, "/EXPORT:mmioInstallIOProcW=_ASM_mmioInstallIOProcW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioOpenA=ASM_mmioOpenA")
#else
#pragma comment(linker, "/EXPORT:mmioOpenA=_ASM_mmioOpenA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioOpenW=ASM_mmioOpenW")
#else
#pragma comment(linker, "/EXPORT:mmioOpenW=_ASM_mmioOpenW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioRead=ASM_mmioRead")
#else
#pragma comment(linker, "/EXPORT:mmioRead=_ASM_mmioRead@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioRenameA=ASM_mmioRenameA")
#else
#pragma comment(linker, "/EXPORT:mmioRenameA=_ASM_mmioRenameA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioRenameW=ASM_mmioRenameW")
#else
#pragma comment(linker, "/EXPORT:mmioRenameW=_ASM_mmioRenameW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioSeek=ASM_mmioSeek")
#else
#pragma comment(linker, "/EXPORT:mmioSeek=_ASM_mmioSeek@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioSendMessage=ASM_mmioSendMessage")
#else
#pragma comment(linker, "/EXPORT:mmioSendMessage=_ASM_mmioSendMessage@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioSetBuffer=ASM_mmioSetBuffer")
#else
#pragma comment(linker, "/EXPORT:mmioSetBuffer=_ASM_mmioSetBuffer@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioSetInfo=ASM_mmioSetInfo")
#else
#pragma comment(linker, "/EXPORT:mmioSetInfo=_ASM_mmioSetInfo@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCA=ASM_mmioStringToFOURCCA")
#else
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCA=_ASM_mmioStringToFOURCCA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCW=ASM_mmioStringToFOURCCW")
#else
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCW=_ASM_mmioStringToFOURCCW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmioWrite=ASM_mmioWrite")
#else
#pragma comment(linker, "/EXPORT:mmioWrite=_ASM_mmioWrite@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:mmsystemGetVersion=ASM_mmsystemGetVersion")
#else
#pragma comment(linker, "/EXPORT:mmsystemGetVersion=_ASM_mmsystemGetVersion@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:sndPlaySoundA=ASM_sndPlaySoundA")
#else
#pragma comment(linker, "/EXPORT:sndPlaySoundA=_ASM_sndPlaySoundA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:sndPlaySoundW=ASM_sndPlaySoundW")
#else
#pragma comment(linker, "/EXPORT:sndPlaySoundW=_ASM_sndPlaySoundW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:timeBeginPeriod=ASM_timeBeginPeriod")
#else
#pragma comment(linker, "/EXPORT:timeBeginPeriod=_ASM_timeBeginPeriod@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:timeEndPeriod=ASM_timeEndPeriod")
#else
#pragma comment(linker, "/EXPORT:timeEndPeriod=_ASM_timeEndPeriod@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:timeGetDevCaps=ASM_timeGetDevCaps")
#else
#pragma comment(linker, "/EXPORT:timeGetDevCaps=_ASM_timeGetDevCaps@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:timeGetSystemTime=ASM_timeGetSystemTime")
#else
#pragma comment(linker, "/EXPORT:timeGetSystemTime=_ASM_timeGetSystemTime@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:timeGetTime=ASM_timeGetTime")
#else
#pragma comment(linker, "/EXPORT:timeGetTime=_ASM_timeGetTime@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:timeKillEvent=ASM_timeKillEvent")
#else
#pragma comment(linker, "/EXPORT:timeKillEvent=_ASM_timeKillEvent@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:timeSetEvent=ASM_timeSetEvent")
#else
#pragma comment(linker, "/EXPORT:timeSetEvent=_ASM_timeSetEvent@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInAddBuffer=ASM_waveInAddBuffer")
#else
#pragma comment(linker, "/EXPORT:waveInAddBuffer=_ASM_waveInAddBuffer@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInClose=ASM_waveInClose")
#else
#pragma comment(linker, "/EXPORT:waveInClose=_ASM_waveInClose@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInGetDevCapsA=ASM_waveInGetDevCapsA")
#else
#pragma comment(linker, "/EXPORT:waveInGetDevCapsA=_ASM_waveInGetDevCapsA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInGetDevCapsW=ASM_waveInGetDevCapsW")
#else
#pragma comment(linker, "/EXPORT:waveInGetDevCapsW=_ASM_waveInGetDevCapsW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInGetErrorTextA=ASM_waveInGetErrorTextA")
#else
#pragma comment(linker, "/EXPORT:waveInGetErrorTextA=_ASM_waveInGetErrorTextA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInGetErrorTextW=ASM_waveInGetErrorTextW")
#else
#pragma comment(linker, "/EXPORT:waveInGetErrorTextW=_ASM_waveInGetErrorTextW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInGetID=ASM_waveInGetID")
#else
#pragma comment(linker, "/EXPORT:waveInGetID=_ASM_waveInGetID@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInGetNumDevs=ASM_waveInGetNumDevs")
#else
#pragma comment(linker, "/EXPORT:waveInGetNumDevs=_ASM_waveInGetNumDevs@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInGetPosition=ASM_waveInGetPosition")
#else
#pragma comment(linker, "/EXPORT:waveInGetPosition=_ASM_waveInGetPosition@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInMessage=ASM_waveInMessage")
#else
#pragma comment(linker, "/EXPORT:waveInMessage=_ASM_waveInMessage@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInOpen=ASM_waveInOpen")
#else
#pragma comment(linker, "/EXPORT:waveInOpen=_ASM_waveInOpen@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInPrepareHeader=ASM_waveInPrepareHeader")
#else
#pragma comment(linker, "/EXPORT:waveInPrepareHeader=_ASM_waveInPrepareHeader@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInReset=ASM_waveInReset")
#else
#pragma comment(linker, "/EXPORT:waveInReset=_ASM_waveInReset@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInStart=ASM_waveInStart")
#else
#pragma comment(linker, "/EXPORT:waveInStart=_ASM_waveInStart@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInStop=ASM_waveInStop")
#else
#pragma comment(linker, "/EXPORT:waveInStop=_ASM_waveInStop@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveInUnprepareHeader=ASM_waveInUnprepareHeader")
#else
#pragma comment(linker, "/EXPORT:waveInUnprepareHeader=_ASM_waveInUnprepareHeader@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutBreakLoop=ASM_waveOutBreakLoop")
#else
#pragma comment(linker, "/EXPORT:waveOutBreakLoop=_ASM_waveOutBreakLoop@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutClose=ASM_waveOutClose")
#else
#pragma comment(linker, "/EXPORT:waveOutClose=_ASM_waveOutClose@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsA=ASM_waveOutGetDevCapsA")
#else
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsA=_ASM_waveOutGetDevCapsA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsW=ASM_waveOutGetDevCapsW")
#else
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsW=_ASM_waveOutGetDevCapsW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextA=ASM_waveOutGetErrorTextA")
#else
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextA=_ASM_waveOutGetErrorTextA@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextW=ASM_waveOutGetErrorTextW")
#else
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextW=_ASM_waveOutGetErrorTextW@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutGetID=ASM_waveOutGetID")
#else
#pragma comment(linker, "/EXPORT:waveOutGetID=_ASM_waveOutGetID@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutGetNumDevs=ASM_waveOutGetNumDevs")
#else
#pragma comment(linker, "/EXPORT:waveOutGetNumDevs=_ASM_waveOutGetNumDevs@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutGetPitch=ASM_waveOutGetPitch")
#else
#pragma comment(linker, "/EXPORT:waveOutGetPitch=_ASM_waveOutGetPitch@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutGetPlaybackRate=ASM_waveOutGetPlaybackRate")
#else
#pragma comment(linker, "/EXPORT:waveOutGetPlaybackRate=_ASM_waveOutGetPlaybackRate@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutGetPosition=ASM_waveOutGetPosition")
#else
#pragma comment(linker, "/EXPORT:waveOutGetPosition=_ASM_waveOutGetPosition@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutGetVolume=ASM_waveOutGetVolume")
#else
#pragma comment(linker, "/EXPORT:waveOutGetVolume=_ASM_waveOutGetVolume@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutMessage=ASM_waveOutMessage")
#else
#pragma comment(linker, "/EXPORT:waveOutMessage=_ASM_waveOutMessage@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutOpen=ASM_waveOutOpen")
#else
#pragma comment(linker, "/EXPORT:waveOutOpen=_ASM_waveOutOpen@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutPause=ASM_waveOutPause")
#else
#pragma comment(linker, "/EXPORT:waveOutPause=_ASM_waveOutPause@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutPrepareHeader=ASM_waveOutPrepareHeader")
#else
#pragma comment(linker, "/EXPORT:waveOutPrepareHeader=_ASM_waveOutPrepareHeader@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutReset=ASM_waveOutReset")
#else
#pragma comment(linker, "/EXPORT:waveOutReset=_ASM_waveOutReset@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutRestart=ASM_waveOutRestart")
#else
#pragma comment(linker, "/EXPORT:waveOutRestart=_ASM_waveOutRestart@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutSetPitch=ASM_waveOutSetPitch")
#else
#pragma comment(linker, "/EXPORT:waveOutSetPitch=_ASM_waveOutSetPitch@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutSetPlaybackRate=ASM_waveOutSetPlaybackRate")
#else
#pragma comment(linker, "/EXPORT:waveOutSetPlaybackRate=_ASM_waveOutSetPlaybackRate@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutSetVolume=ASM_waveOutSetVolume")
#else
#pragma comment(linker, "/EXPORT:waveOutSetVolume=_ASM_waveOutSetVolume@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutUnprepareHeader=ASM_waveOutUnprepareHeader")
#else
#pragma comment(linker, "/EXPORT:waveOutUnprepareHeader=_ASM_waveOutUnprepareHeader@8")
#endif
#if AHEAD_LIB_DOT_NET_X64_BUILD
#pragma comment(linker, "/EXPORT:waveOutWrite=ASM_waveOutWrite")
#else
#pragma comment(linker, "/EXPORT:waveOutWrite=_ASM_waveOutWrite@8")
#endif
// ReSharper restore IdentifierTypo
// ReSharper restore CppInconsistentNaming

// bind native dll first
extern void GetOriginalLibraryPath(TCHAR* bufferPtr, int bufferLength, const TCHAR* libName);

void CheckedLoad()
{
    TCHAR szPath[MAX_PATH] = TEXT("version_original.dll");

    const HMODULE module = LoadLibrary(szPath);

    if (module == nullptr)
    {
        TCHAR szMessage[MAX_PATH];
        wsprintf(szMessage, TEXT("Failed load dll from:%s"), szPath);
        AHEAD_LIB_SHOW_MESSAGE_BOX(nullptr, szMessage, TEXT("AHeadLib.Net Error"), 0);
        
        ExitProcess(1);
    }

    // ReSharper disable IdentifierTypo
    // ReSharper disable CppInconsistentNaming
    // ReSharper disable StringLiteralTypo
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(CloseDriver);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(DefDriverProc);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(DllMain);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(DriverCallback);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(DrvGetModuleHandle);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(GetDriverModuleHandle);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(GetFileVersionInfoA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(GetFileVersionInfoByHandle);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(GetFileVersionInfoExA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(GetFileVersionInfoExW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(GetFileVersionInfoSizeA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(GetFileVersionInfoSizeExA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(GetFileVersionInfoSizeExW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(GetFileVersionInfoSizeW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(GetFileVersionInfoW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_FlushQueue);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_FreePreparsedData);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetAttributes);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetConfiguration);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetFeature);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetHidGuid);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetIndexedString);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetInputReport);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetManufacturerString);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetMsGenreDescriptor);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetNumInputBuffers);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetPhysicalDescriptor);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetPreparsedData);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetProductString);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_GetSerialNumberString);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_Hello);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_SetConfiguration);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_SetFeature);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_SetNumInputBuffers);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidD_SetOutputReport);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetButtonCaps);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetCaps);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetData);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetExtendedAttributes);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetLinkCollectionNodes);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetScaledUsageValue);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetSpecificButtonCaps);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetSpecificValueCaps);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetUsageValue);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetUsageValueArray);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetUsages);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetUsagesEx);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_GetValueCaps);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_InitializeReportForID);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_MaxDataListLength);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_MaxUsageListLength);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_SetData);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_SetScaledUsageValue);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_SetUsageValue);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_SetUsageValueArray);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_SetUsages);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_TranslateUsagesToI8042ScanCodes);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_UnsetUsages);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(HidP_UsageListDifference);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(OpenDriver);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(PlaySound);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(PlaySoundA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(PlaySoundW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(SendDriverMessage);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(VerFindFileA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(VerFindFileW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(VerInstallFileA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(VerInstallFileW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(VerLanguageNameA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(VerLanguageNameW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(VerQueryValueA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(VerQueryValueW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(WOWAppExit);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(auxGetDevCapsA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(auxGetDevCapsW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(auxGetNumDevs);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(auxGetVolume);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(auxOutMessage);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(auxSetVolume);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(joyConfigChanged);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(joyGetDevCapsA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(joyGetDevCapsW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(joyGetNumDevs);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(joyGetPos);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(joyGetPosEx);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(joyGetThreshold);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(joyReleaseCapture);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(joySetCapture);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(joySetThreshold);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciDriverNotify);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciDriverYield);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciExecute);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciFreeCommandResource);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciGetCreatorTask);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciGetDeviceIDA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciGetDeviceIDFromElementIDA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciGetDeviceIDFromElementIDW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciGetDeviceIDW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciGetDriverData);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciGetErrorStringA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciGetErrorStringW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciGetYieldProc);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciLoadCommandResource);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciSendCommandA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciSendCommandW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciSendStringA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciSendStringW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciSetDriverData);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mciSetYieldProc);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiConnect);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiDisconnect);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInAddBuffer);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInClose);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInGetDevCapsA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInGetDevCapsW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInGetErrorTextA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInGetErrorTextW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInGetID);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInGetNumDevs);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInMessage);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInOpen);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInPrepareHeader);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInReset);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInStart);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInStop);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiInUnprepareHeader);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutCacheDrumPatches);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutCachePatches);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutClose);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutGetDevCapsA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutGetDevCapsW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutGetErrorTextA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutGetErrorTextW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutGetID);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutGetNumDevs);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutGetVolume);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutLongMsg);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutMessage);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutOpen);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutPrepareHeader);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutReset);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutSetVolume);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutShortMsg);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiOutUnprepareHeader);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiStreamClose);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiStreamOpen);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiStreamOut);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiStreamPause);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiStreamPosition);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiStreamProperty);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiStreamRestart);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(midiStreamStop);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerClose);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerGetControlDetailsA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerGetControlDetailsW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerGetDevCapsA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerGetDevCapsW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerGetID);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerGetLineControlsA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerGetLineControlsW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerGetLineInfoA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerGetLineInfoW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerGetNumDevs);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerMessage);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerOpen);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mixerSetControlDetails);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmDrvInstall);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmGetCurrentTask);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmTaskBlock);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmTaskCreate);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmTaskSignal);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmTaskYield);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioAdvance);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioAscend);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioClose);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioCreateChunk);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioDescend);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioFlush);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioGetInfo);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioInstallIOProcA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioInstallIOProcW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioOpenA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioOpenW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioRead);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioRenameA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioRenameW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioSeek);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioSendMessage);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioSetBuffer);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioSetInfo);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioStringToFOURCCA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioStringToFOURCCW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmioWrite);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(mmsystemGetVersion);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(sndPlaySoundA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(sndPlaySoundW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(timeBeginPeriod);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(timeEndPeriod);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(timeGetDevCaps);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(timeGetSystemTime);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(timeGetTime);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(timeKillEvent);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(timeSetEvent);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInAddBuffer);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInClose);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInGetDevCapsA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInGetDevCapsW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInGetErrorTextA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInGetErrorTextW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInGetID);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInGetNumDevs);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInGetPosition);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInMessage);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInOpen);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInPrepareHeader);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInReset);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInStart);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInStop);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveInUnprepareHeader);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutBreakLoop);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutClose);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutGetDevCapsA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutGetDevCapsW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutGetErrorTextA);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutGetErrorTextW);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutGetID);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutGetNumDevs);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutGetPitch);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutGetPlaybackRate);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutGetPosition);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutGetVolume);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutMessage);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutOpen);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutPause);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutPrepareHeader);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutReset);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutRestart);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutSetPitch);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutSetPlaybackRate);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutSetVolume);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutUnprepareHeader);
    AHEAD_LIB_DOT_NET_BIND_FUNCTION(waveOutWrite);    
    // ReSharper restore IdentifierTypo
    // ReSharper restore CppInconsistentNaming
    // ReSharper restore StringLiteralTypo
}


