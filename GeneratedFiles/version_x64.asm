.DATA
    EXTERNDEF CloseDriverPtr:QWORD
    EXTERNDEF DefDriverProcPtr:QWORD
    EXTERNDEF DllMainPtr:QWORD
    EXTERNDEF DriverCallbackPtr:QWORD
    EXTERNDEF DrvGetModuleHandlePtr:QWORD
    EXTERNDEF GetDriverModuleHandlePtr:QWORD
    EXTERNDEF GetFileVersionInfoAPtr:QWORD
    EXTERNDEF GetFileVersionInfoByHandlePtr:QWORD
    EXTERNDEF GetFileVersionInfoExAPtr:QWORD
    EXTERNDEF GetFileVersionInfoExWPtr:QWORD
    EXTERNDEF GetFileVersionInfoSizeAPtr:QWORD
    EXTERNDEF GetFileVersionInfoSizeExAPtr:QWORD
    EXTERNDEF GetFileVersionInfoSizeExWPtr:QWORD
    EXTERNDEF GetFileVersionInfoSizeWPtr:QWORD
    EXTERNDEF GetFileVersionInfoWPtr:QWORD
    EXTERNDEF HidD_FlushQueuePtr:QWORD
    EXTERNDEF HidD_FreePreparsedDataPtr:QWORD
    EXTERNDEF HidD_GetAttributesPtr:QWORD
    EXTERNDEF HidD_GetConfigurationPtr:QWORD
    EXTERNDEF HidD_GetFeaturePtr:QWORD
    EXTERNDEF HidD_GetHidGuidPtr:QWORD
    EXTERNDEF HidD_GetIndexedStringPtr:QWORD
    EXTERNDEF HidD_GetInputReportPtr:QWORD
    EXTERNDEF HidD_GetManufacturerStringPtr:QWORD
    EXTERNDEF HidD_GetMsGenreDescriptorPtr:QWORD
    EXTERNDEF HidD_GetNumInputBuffersPtr:QWORD
    EXTERNDEF HidD_GetPhysicalDescriptorPtr:QWORD
    EXTERNDEF HidD_GetPreparsedDataPtr:QWORD
    EXTERNDEF HidD_GetProductStringPtr:QWORD
    EXTERNDEF HidD_GetSerialNumberStringPtr:QWORD
    EXTERNDEF HidD_HelloPtr:QWORD
    EXTERNDEF HidD_SetConfigurationPtr:QWORD
    EXTERNDEF HidD_SetFeaturePtr:QWORD
    EXTERNDEF HidD_SetNumInputBuffersPtr:QWORD
    EXTERNDEF HidD_SetOutputReportPtr:QWORD
    EXTERNDEF HidP_GetButtonCapsPtr:QWORD
    EXTERNDEF HidP_GetCapsPtr:QWORD
    EXTERNDEF HidP_GetDataPtr:QWORD
    EXTERNDEF HidP_GetExtendedAttributesPtr:QWORD
    EXTERNDEF HidP_GetLinkCollectionNodesPtr:QWORD
    EXTERNDEF HidP_GetScaledUsageValuePtr:QWORD
    EXTERNDEF HidP_GetSpecificButtonCapsPtr:QWORD
    EXTERNDEF HidP_GetSpecificValueCapsPtr:QWORD
    EXTERNDEF HidP_GetUsageValuePtr:QWORD
    EXTERNDEF HidP_GetUsageValueArrayPtr:QWORD
    EXTERNDEF HidP_GetUsagesPtr:QWORD
    EXTERNDEF HidP_GetUsagesExPtr:QWORD
    EXTERNDEF HidP_GetValueCapsPtr:QWORD
    EXTERNDEF HidP_InitializeReportForIDPtr:QWORD
    EXTERNDEF HidP_MaxDataListLengthPtr:QWORD
    EXTERNDEF HidP_MaxUsageListLengthPtr:QWORD
    EXTERNDEF HidP_SetDataPtr:QWORD
    EXTERNDEF HidP_SetScaledUsageValuePtr:QWORD
    EXTERNDEF HidP_SetUsageValuePtr:QWORD
    EXTERNDEF HidP_SetUsageValueArrayPtr:QWORD
    EXTERNDEF HidP_SetUsagesPtr:QWORD
    EXTERNDEF HidP_TranslateUsagesToI8042ScanCodesPtr:QWORD
    EXTERNDEF HidP_UnsetUsagesPtr:QWORD
    EXTERNDEF HidP_UsageListDifferencePtr:QWORD
    EXTERNDEF OpenDriverPtr:QWORD
    EXTERNDEF PlaySoundPtr:QWORD
    EXTERNDEF PlaySoundAPtr:QWORD
    EXTERNDEF PlaySoundWPtr:QWORD
    EXTERNDEF SendDriverMessagePtr:QWORD
    EXTERNDEF VerFindFileAPtr:QWORD
    EXTERNDEF VerFindFileWPtr:QWORD
    EXTERNDEF VerInstallFileAPtr:QWORD
    EXTERNDEF VerInstallFileWPtr:QWORD
    EXTERNDEF VerLanguageNameAPtr:QWORD
    EXTERNDEF VerLanguageNameWPtr:QWORD
    EXTERNDEF VerQueryValueAPtr:QWORD
    EXTERNDEF VerQueryValueWPtr:QWORD
    EXTERNDEF WOWAppExitPtr:QWORD
    EXTERNDEF auxGetDevCapsAPtr:QWORD
    EXTERNDEF auxGetDevCapsWPtr:QWORD
    EXTERNDEF auxGetNumDevsPtr:QWORD
    EXTERNDEF auxGetVolumePtr:QWORD
    EXTERNDEF auxOutMessagePtr:QWORD
    EXTERNDEF auxSetVolumePtr:QWORD
    EXTERNDEF joyConfigChangedPtr:QWORD
    EXTERNDEF joyGetDevCapsAPtr:QWORD
    EXTERNDEF joyGetDevCapsWPtr:QWORD
    EXTERNDEF joyGetNumDevsPtr:QWORD
    EXTERNDEF joyGetPosPtr:QWORD
    EXTERNDEF joyGetPosExPtr:QWORD
    EXTERNDEF joyGetThresholdPtr:QWORD
    EXTERNDEF joyReleaseCapturePtr:QWORD
    EXTERNDEF joySetCapturePtr:QWORD
    EXTERNDEF joySetThresholdPtr:QWORD
    EXTERNDEF mciDriverNotifyPtr:QWORD
    EXTERNDEF mciDriverYieldPtr:QWORD
    EXTERNDEF mciExecutePtr:QWORD
    EXTERNDEF mciFreeCommandResourcePtr:QWORD
    EXTERNDEF mciGetCreatorTaskPtr:QWORD
    EXTERNDEF mciGetDeviceIDAPtr:QWORD
    EXTERNDEF mciGetDeviceIDFromElementIDAPtr:QWORD
    EXTERNDEF mciGetDeviceIDFromElementIDWPtr:QWORD
    EXTERNDEF mciGetDeviceIDWPtr:QWORD
    EXTERNDEF mciGetDriverDataPtr:QWORD
    EXTERNDEF mciGetErrorStringAPtr:QWORD
    EXTERNDEF mciGetErrorStringWPtr:QWORD
    EXTERNDEF mciGetYieldProcPtr:QWORD
    EXTERNDEF mciLoadCommandResourcePtr:QWORD
    EXTERNDEF mciSendCommandAPtr:QWORD
    EXTERNDEF mciSendCommandWPtr:QWORD
    EXTERNDEF mciSendStringAPtr:QWORD
    EXTERNDEF mciSendStringWPtr:QWORD
    EXTERNDEF mciSetDriverDataPtr:QWORD
    EXTERNDEF mciSetYieldProcPtr:QWORD
    EXTERNDEF midiConnectPtr:QWORD
    EXTERNDEF midiDisconnectPtr:QWORD
    EXTERNDEF midiInAddBufferPtr:QWORD
    EXTERNDEF midiInClosePtr:QWORD
    EXTERNDEF midiInGetDevCapsAPtr:QWORD
    EXTERNDEF midiInGetDevCapsWPtr:QWORD
    EXTERNDEF midiInGetErrorTextAPtr:QWORD
    EXTERNDEF midiInGetErrorTextWPtr:QWORD
    EXTERNDEF midiInGetIDPtr:QWORD
    EXTERNDEF midiInGetNumDevsPtr:QWORD
    EXTERNDEF midiInMessagePtr:QWORD
    EXTERNDEF midiInOpenPtr:QWORD
    EXTERNDEF midiInPrepareHeaderPtr:QWORD
    EXTERNDEF midiInResetPtr:QWORD
    EXTERNDEF midiInStartPtr:QWORD
    EXTERNDEF midiInStopPtr:QWORD
    EXTERNDEF midiInUnprepareHeaderPtr:QWORD
    EXTERNDEF midiOutCacheDrumPatchesPtr:QWORD
    EXTERNDEF midiOutCachePatchesPtr:QWORD
    EXTERNDEF midiOutClosePtr:QWORD
    EXTERNDEF midiOutGetDevCapsAPtr:QWORD
    EXTERNDEF midiOutGetDevCapsWPtr:QWORD
    EXTERNDEF midiOutGetErrorTextAPtr:QWORD
    EXTERNDEF midiOutGetErrorTextWPtr:QWORD
    EXTERNDEF midiOutGetIDPtr:QWORD
    EXTERNDEF midiOutGetNumDevsPtr:QWORD
    EXTERNDEF midiOutGetVolumePtr:QWORD
    EXTERNDEF midiOutLongMsgPtr:QWORD
    EXTERNDEF midiOutMessagePtr:QWORD
    EXTERNDEF midiOutOpenPtr:QWORD
    EXTERNDEF midiOutPrepareHeaderPtr:QWORD
    EXTERNDEF midiOutResetPtr:QWORD
    EXTERNDEF midiOutSetVolumePtr:QWORD
    EXTERNDEF midiOutShortMsgPtr:QWORD
    EXTERNDEF midiOutUnprepareHeaderPtr:QWORD
    EXTERNDEF midiStreamClosePtr:QWORD
    EXTERNDEF midiStreamOpenPtr:QWORD
    EXTERNDEF midiStreamOutPtr:QWORD
    EXTERNDEF midiStreamPausePtr:QWORD
    EXTERNDEF midiStreamPositionPtr:QWORD
    EXTERNDEF midiStreamPropertyPtr:QWORD
    EXTERNDEF midiStreamRestartPtr:QWORD
    EXTERNDEF midiStreamStopPtr:QWORD
    EXTERNDEF mixerClosePtr:QWORD
    EXTERNDEF mixerGetControlDetailsAPtr:QWORD
    EXTERNDEF mixerGetControlDetailsWPtr:QWORD
    EXTERNDEF mixerGetDevCapsAPtr:QWORD
    EXTERNDEF mixerGetDevCapsWPtr:QWORD
    EXTERNDEF mixerGetIDPtr:QWORD
    EXTERNDEF mixerGetLineControlsAPtr:QWORD
    EXTERNDEF mixerGetLineControlsWPtr:QWORD
    EXTERNDEF mixerGetLineInfoAPtr:QWORD
    EXTERNDEF mixerGetLineInfoWPtr:QWORD
    EXTERNDEF mixerGetNumDevsPtr:QWORD
    EXTERNDEF mixerMessagePtr:QWORD
    EXTERNDEF mixerOpenPtr:QWORD
    EXTERNDEF mixerSetControlDetailsPtr:QWORD
    EXTERNDEF mmDrvInstallPtr:QWORD
    EXTERNDEF mmGetCurrentTaskPtr:QWORD
    EXTERNDEF mmTaskBlockPtr:QWORD
    EXTERNDEF mmTaskCreatePtr:QWORD
    EXTERNDEF mmTaskSignalPtr:QWORD
    EXTERNDEF mmTaskYieldPtr:QWORD
    EXTERNDEF mmioAdvancePtr:QWORD
    EXTERNDEF mmioAscendPtr:QWORD
    EXTERNDEF mmioClosePtr:QWORD
    EXTERNDEF mmioCreateChunkPtr:QWORD
    EXTERNDEF mmioDescendPtr:QWORD
    EXTERNDEF mmioFlushPtr:QWORD
    EXTERNDEF mmioGetInfoPtr:QWORD
    EXTERNDEF mmioInstallIOProcAPtr:QWORD
    EXTERNDEF mmioInstallIOProcWPtr:QWORD
    EXTERNDEF mmioOpenAPtr:QWORD
    EXTERNDEF mmioOpenWPtr:QWORD
    EXTERNDEF mmioReadPtr:QWORD
    EXTERNDEF mmioRenameAPtr:QWORD
    EXTERNDEF mmioRenameWPtr:QWORD
    EXTERNDEF mmioSeekPtr:QWORD
    EXTERNDEF mmioSendMessagePtr:QWORD
    EXTERNDEF mmioSetBufferPtr:QWORD
    EXTERNDEF mmioSetInfoPtr:QWORD
    EXTERNDEF mmioStringToFOURCCAPtr:QWORD
    EXTERNDEF mmioStringToFOURCCWPtr:QWORD
    EXTERNDEF mmioWritePtr:QWORD
    EXTERNDEF mmsystemGetVersionPtr:QWORD
    EXTERNDEF sndPlaySoundAPtr:QWORD
    EXTERNDEF sndPlaySoundWPtr:QWORD
    EXTERNDEF timeBeginPeriodPtr:QWORD
    EXTERNDEF timeEndPeriodPtr:QWORD
    EXTERNDEF timeGetDevCapsPtr:QWORD
    EXTERNDEF timeGetSystemTimePtr:QWORD
    EXTERNDEF timeGetTimePtr:QWORD
    EXTERNDEF timeKillEventPtr:QWORD
    EXTERNDEF timeSetEventPtr:QWORD
    EXTERNDEF waveInAddBufferPtr:QWORD
    EXTERNDEF waveInClosePtr:QWORD
    EXTERNDEF waveInGetDevCapsAPtr:QWORD
    EXTERNDEF waveInGetDevCapsWPtr:QWORD
    EXTERNDEF waveInGetErrorTextAPtr:QWORD
    EXTERNDEF waveInGetErrorTextWPtr:QWORD
    EXTERNDEF waveInGetIDPtr:QWORD
    EXTERNDEF waveInGetNumDevsPtr:QWORD
    EXTERNDEF waveInGetPositionPtr:QWORD
    EXTERNDEF waveInMessagePtr:QWORD
    EXTERNDEF waveInOpenPtr:QWORD
    EXTERNDEF waveInPrepareHeaderPtr:QWORD
    EXTERNDEF waveInResetPtr:QWORD
    EXTERNDEF waveInStartPtr:QWORD
    EXTERNDEF waveInStopPtr:QWORD
    EXTERNDEF waveInUnprepareHeaderPtr:QWORD
    EXTERNDEF waveOutBreakLoopPtr:QWORD
    EXTERNDEF waveOutClosePtr:QWORD
    EXTERNDEF waveOutGetDevCapsAPtr:QWORD
    EXTERNDEF waveOutGetDevCapsWPtr:QWORD
    EXTERNDEF waveOutGetErrorTextAPtr:QWORD
    EXTERNDEF waveOutGetErrorTextWPtr:QWORD
    EXTERNDEF waveOutGetIDPtr:QWORD
    EXTERNDEF waveOutGetNumDevsPtr:QWORD
    EXTERNDEF waveOutGetPitchPtr:QWORD
    EXTERNDEF waveOutGetPlaybackRatePtr:QWORD
    EXTERNDEF waveOutGetPositionPtr:QWORD
    EXTERNDEF waveOutGetVolumePtr:QWORD
    EXTERNDEF waveOutMessagePtr:QWORD
    EXTERNDEF waveOutOpenPtr:QWORD
    EXTERNDEF waveOutPausePtr:QWORD
    EXTERNDEF waveOutPrepareHeaderPtr:QWORD
    EXTERNDEF waveOutResetPtr:QWORD
    EXTERNDEF waveOutRestartPtr:QWORD
    EXTERNDEF waveOutSetPitchPtr:QWORD
    EXTERNDEF waveOutSetPlaybackRatePtr:QWORD
    EXTERNDEF waveOutSetVolumePtr:QWORD
    EXTERNDEF waveOutUnprepareHeaderPtr:QWORD
    EXTERNDEF waveOutWritePtr:QWORD

.CODE

ASM_CloseDriver PROC
    jmp [CloseDriverPtr]
ASM_CloseDriver ENDP

ASM_DefDriverProc PROC
    jmp [DefDriverProcPtr]
ASM_DefDriverProc ENDP

ASM_DllMain PROC
    jmp [DllMainPtr]
ASM_DllMain ENDP

ASM_DriverCallback PROC
    jmp [DriverCallbackPtr]
ASM_DriverCallback ENDP

ASM_DrvGetModuleHandle PROC
    jmp [DrvGetModuleHandlePtr]
ASM_DrvGetModuleHandle ENDP

ASM_GetDriverModuleHandle PROC
    jmp [GetDriverModuleHandlePtr]
ASM_GetDriverModuleHandle ENDP

ASM_GetFileVersionInfoA PROC
    jmp [GetFileVersionInfoAPtr]
ASM_GetFileVersionInfoA ENDP

ASM_GetFileVersionInfoByHandle PROC
    jmp [GetFileVersionInfoByHandlePtr]
ASM_GetFileVersionInfoByHandle ENDP

ASM_GetFileVersionInfoExA PROC
    jmp [GetFileVersionInfoExAPtr]
ASM_GetFileVersionInfoExA ENDP

ASM_GetFileVersionInfoExW PROC
    jmp [GetFileVersionInfoExWPtr]
ASM_GetFileVersionInfoExW ENDP

ASM_GetFileVersionInfoSizeA PROC
    jmp [GetFileVersionInfoSizeAPtr]
ASM_GetFileVersionInfoSizeA ENDP

ASM_GetFileVersionInfoSizeExA PROC
    jmp [GetFileVersionInfoSizeExAPtr]
ASM_GetFileVersionInfoSizeExA ENDP

ASM_GetFileVersionInfoSizeExW PROC
    jmp [GetFileVersionInfoSizeExWPtr]
ASM_GetFileVersionInfoSizeExW ENDP

ASM_GetFileVersionInfoSizeW PROC
    jmp [GetFileVersionInfoSizeWPtr]
ASM_GetFileVersionInfoSizeW ENDP

ASM_GetFileVersionInfoW PROC
    jmp [GetFileVersionInfoWPtr]
ASM_GetFileVersionInfoW ENDP

ASM_HidD_FlushQueue PROC
    jmp [HidD_FlushQueuePtr]
ASM_HidD_FlushQueue ENDP

ASM_HidD_FreePreparsedData PROC
    jmp [HidD_FreePreparsedDataPtr]
ASM_HidD_FreePreparsedData ENDP

ASM_HidD_GetAttributes PROC
    jmp [HidD_GetAttributesPtr]
ASM_HidD_GetAttributes ENDP

ASM_HidD_GetConfiguration PROC
    jmp [HidD_GetConfigurationPtr]
ASM_HidD_GetConfiguration ENDP

ASM_HidD_GetFeature PROC
    jmp [HidD_GetFeaturePtr]
ASM_HidD_GetFeature ENDP

ASM_HidD_GetHidGuid PROC
    jmp [HidD_GetHidGuidPtr]
ASM_HidD_GetHidGuid ENDP

ASM_HidD_GetIndexedString PROC
    jmp [HidD_GetIndexedStringPtr]
ASM_HidD_GetIndexedString ENDP

ASM_HidD_GetInputReport PROC
    jmp [HidD_GetInputReportPtr]
ASM_HidD_GetInputReport ENDP

ASM_HidD_GetManufacturerString PROC
    jmp [HidD_GetManufacturerStringPtr]
ASM_HidD_GetManufacturerString ENDP

ASM_HidD_GetMsGenreDescriptor PROC
    jmp [HidD_GetMsGenreDescriptorPtr]
ASM_HidD_GetMsGenreDescriptor ENDP

ASM_HidD_GetNumInputBuffers PROC
    jmp [HidD_GetNumInputBuffersPtr]
ASM_HidD_GetNumInputBuffers ENDP

ASM_HidD_GetPhysicalDescriptor PROC
    jmp [HidD_GetPhysicalDescriptorPtr]
ASM_HidD_GetPhysicalDescriptor ENDP

ASM_HidD_GetPreparsedData PROC
    jmp [HidD_GetPreparsedDataPtr]
ASM_HidD_GetPreparsedData ENDP

ASM_HidD_GetProductString PROC
    jmp [HidD_GetProductStringPtr]
ASM_HidD_GetProductString ENDP

ASM_HidD_GetSerialNumberString PROC
    jmp [HidD_GetSerialNumberStringPtr]
ASM_HidD_GetSerialNumberString ENDP

ASM_HidD_Hello PROC
    jmp [HidD_HelloPtr]
ASM_HidD_Hello ENDP

ASM_HidD_SetConfiguration PROC
    jmp [HidD_SetConfigurationPtr]
ASM_HidD_SetConfiguration ENDP

ASM_HidD_SetFeature PROC
    jmp [HidD_SetFeaturePtr]
ASM_HidD_SetFeature ENDP

ASM_HidD_SetNumInputBuffers PROC
    jmp [HidD_SetNumInputBuffersPtr]
ASM_HidD_SetNumInputBuffers ENDP

ASM_HidD_SetOutputReport PROC
    jmp [HidD_SetOutputReportPtr]
ASM_HidD_SetOutputReport ENDP

ASM_HidP_GetButtonCaps PROC
    jmp [HidP_GetButtonCapsPtr]
ASM_HidP_GetButtonCaps ENDP

ASM_HidP_GetCaps PROC
    jmp [HidP_GetCapsPtr]
ASM_HidP_GetCaps ENDP

ASM_HidP_GetData PROC
    jmp [HidP_GetDataPtr]
ASM_HidP_GetData ENDP

ASM_HidP_GetExtendedAttributes PROC
    jmp [HidP_GetExtendedAttributesPtr]
ASM_HidP_GetExtendedAttributes ENDP

ASM_HidP_GetLinkCollectionNodes PROC
    jmp [HidP_GetLinkCollectionNodesPtr]
ASM_HidP_GetLinkCollectionNodes ENDP

ASM_HidP_GetScaledUsageValue PROC
    jmp [HidP_GetScaledUsageValuePtr]
ASM_HidP_GetScaledUsageValue ENDP

ASM_HidP_GetSpecificButtonCaps PROC
    jmp [HidP_GetSpecificButtonCapsPtr]
ASM_HidP_GetSpecificButtonCaps ENDP

ASM_HidP_GetSpecificValueCaps PROC
    jmp [HidP_GetSpecificValueCapsPtr]
ASM_HidP_GetSpecificValueCaps ENDP

ASM_HidP_GetUsageValue PROC
    jmp [HidP_GetUsageValuePtr]
ASM_HidP_GetUsageValue ENDP

ASM_HidP_GetUsageValueArray PROC
    jmp [HidP_GetUsageValueArrayPtr]
ASM_HidP_GetUsageValueArray ENDP

ASM_HidP_GetUsages PROC
    jmp [HidP_GetUsagesPtr]
ASM_HidP_GetUsages ENDP

ASM_HidP_GetUsagesEx PROC
    jmp [HidP_GetUsagesExPtr]
ASM_HidP_GetUsagesEx ENDP

ASM_HidP_GetValueCaps PROC
    jmp [HidP_GetValueCapsPtr]
ASM_HidP_GetValueCaps ENDP

ASM_HidP_InitializeReportForID PROC
    jmp [HidP_InitializeReportForIDPtr]
ASM_HidP_InitializeReportForID ENDP

ASM_HidP_MaxDataListLength PROC
    jmp [HidP_MaxDataListLengthPtr]
ASM_HidP_MaxDataListLength ENDP

ASM_HidP_MaxUsageListLength PROC
    jmp [HidP_MaxUsageListLengthPtr]
ASM_HidP_MaxUsageListLength ENDP

ASM_HidP_SetData PROC
    jmp [HidP_SetDataPtr]
ASM_HidP_SetData ENDP

ASM_HidP_SetScaledUsageValue PROC
    jmp [HidP_SetScaledUsageValuePtr]
ASM_HidP_SetScaledUsageValue ENDP

ASM_HidP_SetUsageValue PROC
    jmp [HidP_SetUsageValuePtr]
ASM_HidP_SetUsageValue ENDP

ASM_HidP_SetUsageValueArray PROC
    jmp [HidP_SetUsageValueArrayPtr]
ASM_HidP_SetUsageValueArray ENDP

ASM_HidP_SetUsages PROC
    jmp [HidP_SetUsagesPtr]
ASM_HidP_SetUsages ENDP

ASM_HidP_TranslateUsagesToI8042ScanCodes PROC
    jmp [HidP_TranslateUsagesToI8042ScanCodesPtr]
ASM_HidP_TranslateUsagesToI8042ScanCodes ENDP

ASM_HidP_UnsetUsages PROC
    jmp [HidP_UnsetUsagesPtr]
ASM_HidP_UnsetUsages ENDP

ASM_HidP_UsageListDifference PROC
    jmp [HidP_UsageListDifferencePtr]
ASM_HidP_UsageListDifference ENDP

ASM_OpenDriver PROC
    jmp [OpenDriverPtr]
ASM_OpenDriver ENDP

ASM_PlaySound PROC
    jmp [PlaySoundPtr]
ASM_PlaySound ENDP

ASM_PlaySoundA PROC
    jmp [PlaySoundAPtr]
ASM_PlaySoundA ENDP

ASM_PlaySoundW PROC
    jmp [PlaySoundWPtr]
ASM_PlaySoundW ENDP

ASM_SendDriverMessage PROC
    jmp [SendDriverMessagePtr]
ASM_SendDriverMessage ENDP

ASM_VerFindFileA PROC
    jmp [VerFindFileAPtr]
ASM_VerFindFileA ENDP

ASM_VerFindFileW PROC
    jmp [VerFindFileWPtr]
ASM_VerFindFileW ENDP

ASM_VerInstallFileA PROC
    jmp [VerInstallFileAPtr]
ASM_VerInstallFileA ENDP

ASM_VerInstallFileW PROC
    jmp [VerInstallFileWPtr]
ASM_VerInstallFileW ENDP

ASM_VerLanguageNameA PROC
    jmp [VerLanguageNameAPtr]
ASM_VerLanguageNameA ENDP

ASM_VerLanguageNameW PROC
    jmp [VerLanguageNameWPtr]
ASM_VerLanguageNameW ENDP

ASM_VerQueryValueA PROC
    jmp [VerQueryValueAPtr]
ASM_VerQueryValueA ENDP

ASM_VerQueryValueW PROC
    jmp [VerQueryValueWPtr]
ASM_VerQueryValueW ENDP

ASM_WOWAppExit PROC
    jmp [WOWAppExitPtr]
ASM_WOWAppExit ENDP

ASM_auxGetDevCapsA PROC
    jmp [auxGetDevCapsAPtr]
ASM_auxGetDevCapsA ENDP

ASM_auxGetDevCapsW PROC
    jmp [auxGetDevCapsWPtr]
ASM_auxGetDevCapsW ENDP

ASM_auxGetNumDevs PROC
    jmp [auxGetNumDevsPtr]
ASM_auxGetNumDevs ENDP

ASM_auxGetVolume PROC
    jmp [auxGetVolumePtr]
ASM_auxGetVolume ENDP

ASM_auxOutMessage PROC
    jmp [auxOutMessagePtr]
ASM_auxOutMessage ENDP

ASM_auxSetVolume PROC
    jmp [auxSetVolumePtr]
ASM_auxSetVolume ENDP

ASM_joyConfigChanged PROC
    jmp [joyConfigChangedPtr]
ASM_joyConfigChanged ENDP

ASM_joyGetDevCapsA PROC
    jmp [joyGetDevCapsAPtr]
ASM_joyGetDevCapsA ENDP

ASM_joyGetDevCapsW PROC
    jmp [joyGetDevCapsWPtr]
ASM_joyGetDevCapsW ENDP

ASM_joyGetNumDevs PROC
    jmp [joyGetNumDevsPtr]
ASM_joyGetNumDevs ENDP

ASM_joyGetPos PROC
    jmp [joyGetPosPtr]
ASM_joyGetPos ENDP

ASM_joyGetPosEx PROC
    jmp [joyGetPosExPtr]
ASM_joyGetPosEx ENDP

ASM_joyGetThreshold PROC
    jmp [joyGetThresholdPtr]
ASM_joyGetThreshold ENDP

ASM_joyReleaseCapture PROC
    jmp [joyReleaseCapturePtr]
ASM_joyReleaseCapture ENDP

ASM_joySetCapture PROC
    jmp [joySetCapturePtr]
ASM_joySetCapture ENDP

ASM_joySetThreshold PROC
    jmp [joySetThresholdPtr]
ASM_joySetThreshold ENDP

ASM_mciDriverNotify PROC
    jmp [mciDriverNotifyPtr]
ASM_mciDriverNotify ENDP

ASM_mciDriverYield PROC
    jmp [mciDriverYieldPtr]
ASM_mciDriverYield ENDP

ASM_mciExecute PROC
    jmp [mciExecutePtr]
ASM_mciExecute ENDP

ASM_mciFreeCommandResource PROC
    jmp [mciFreeCommandResourcePtr]
ASM_mciFreeCommandResource ENDP

ASM_mciGetCreatorTask PROC
    jmp [mciGetCreatorTaskPtr]
ASM_mciGetCreatorTask ENDP

ASM_mciGetDeviceIDA PROC
    jmp [mciGetDeviceIDAPtr]
ASM_mciGetDeviceIDA ENDP

ASM_mciGetDeviceIDFromElementIDA PROC
    jmp [mciGetDeviceIDFromElementIDAPtr]
ASM_mciGetDeviceIDFromElementIDA ENDP

ASM_mciGetDeviceIDFromElementIDW PROC
    jmp [mciGetDeviceIDFromElementIDWPtr]
ASM_mciGetDeviceIDFromElementIDW ENDP

ASM_mciGetDeviceIDW PROC
    jmp [mciGetDeviceIDWPtr]
ASM_mciGetDeviceIDW ENDP

ASM_mciGetDriverData PROC
    jmp [mciGetDriverDataPtr]
ASM_mciGetDriverData ENDP

ASM_mciGetErrorStringA PROC
    jmp [mciGetErrorStringAPtr]
ASM_mciGetErrorStringA ENDP

ASM_mciGetErrorStringW PROC
    jmp [mciGetErrorStringWPtr]
ASM_mciGetErrorStringW ENDP

ASM_mciGetYieldProc PROC
    jmp [mciGetYieldProcPtr]
ASM_mciGetYieldProc ENDP

ASM_mciLoadCommandResource PROC
    jmp [mciLoadCommandResourcePtr]
ASM_mciLoadCommandResource ENDP

ASM_mciSendCommandA PROC
    jmp [mciSendCommandAPtr]
ASM_mciSendCommandA ENDP

ASM_mciSendCommandW PROC
    jmp [mciSendCommandWPtr]
ASM_mciSendCommandW ENDP

ASM_mciSendStringA PROC
    jmp [mciSendStringAPtr]
ASM_mciSendStringA ENDP

ASM_mciSendStringW PROC
    jmp [mciSendStringWPtr]
ASM_mciSendStringW ENDP

ASM_mciSetDriverData PROC
    jmp [mciSetDriverDataPtr]
ASM_mciSetDriverData ENDP

ASM_mciSetYieldProc PROC
    jmp [mciSetYieldProcPtr]
ASM_mciSetYieldProc ENDP

ASM_midiConnect PROC
    jmp [midiConnectPtr]
ASM_midiConnect ENDP

ASM_midiDisconnect PROC
    jmp [midiDisconnectPtr]
ASM_midiDisconnect ENDP

ASM_midiInAddBuffer PROC
    jmp [midiInAddBufferPtr]
ASM_midiInAddBuffer ENDP

ASM_midiInClose PROC
    jmp [midiInClosePtr]
ASM_midiInClose ENDP

ASM_midiInGetDevCapsA PROC
    jmp [midiInGetDevCapsAPtr]
ASM_midiInGetDevCapsA ENDP

ASM_midiInGetDevCapsW PROC
    jmp [midiInGetDevCapsWPtr]
ASM_midiInGetDevCapsW ENDP

ASM_midiInGetErrorTextA PROC
    jmp [midiInGetErrorTextAPtr]
ASM_midiInGetErrorTextA ENDP

ASM_midiInGetErrorTextW PROC
    jmp [midiInGetErrorTextWPtr]
ASM_midiInGetErrorTextW ENDP

ASM_midiInGetID PROC
    jmp [midiInGetIDPtr]
ASM_midiInGetID ENDP

ASM_midiInGetNumDevs PROC
    jmp [midiInGetNumDevsPtr]
ASM_midiInGetNumDevs ENDP

ASM_midiInMessage PROC
    jmp [midiInMessagePtr]
ASM_midiInMessage ENDP

ASM_midiInOpen PROC
    jmp [midiInOpenPtr]
ASM_midiInOpen ENDP

ASM_midiInPrepareHeader PROC
    jmp [midiInPrepareHeaderPtr]
ASM_midiInPrepareHeader ENDP

ASM_midiInReset PROC
    jmp [midiInResetPtr]
ASM_midiInReset ENDP

ASM_midiInStart PROC
    jmp [midiInStartPtr]
ASM_midiInStart ENDP

ASM_midiInStop PROC
    jmp [midiInStopPtr]
ASM_midiInStop ENDP

ASM_midiInUnprepareHeader PROC
    jmp [midiInUnprepareHeaderPtr]
ASM_midiInUnprepareHeader ENDP

ASM_midiOutCacheDrumPatches PROC
    jmp [midiOutCacheDrumPatchesPtr]
ASM_midiOutCacheDrumPatches ENDP

ASM_midiOutCachePatches PROC
    jmp [midiOutCachePatchesPtr]
ASM_midiOutCachePatches ENDP

ASM_midiOutClose PROC
    jmp [midiOutClosePtr]
ASM_midiOutClose ENDP

ASM_midiOutGetDevCapsA PROC
    jmp [midiOutGetDevCapsAPtr]
ASM_midiOutGetDevCapsA ENDP

ASM_midiOutGetDevCapsW PROC
    jmp [midiOutGetDevCapsWPtr]
ASM_midiOutGetDevCapsW ENDP

ASM_midiOutGetErrorTextA PROC
    jmp [midiOutGetErrorTextAPtr]
ASM_midiOutGetErrorTextA ENDP

ASM_midiOutGetErrorTextW PROC
    jmp [midiOutGetErrorTextWPtr]
ASM_midiOutGetErrorTextW ENDP

ASM_midiOutGetID PROC
    jmp [midiOutGetIDPtr]
ASM_midiOutGetID ENDP

ASM_midiOutGetNumDevs PROC
    jmp [midiOutGetNumDevsPtr]
ASM_midiOutGetNumDevs ENDP

ASM_midiOutGetVolume PROC
    jmp [midiOutGetVolumePtr]
ASM_midiOutGetVolume ENDP

ASM_midiOutLongMsg PROC
    jmp [midiOutLongMsgPtr]
ASM_midiOutLongMsg ENDP

ASM_midiOutMessage PROC
    jmp [midiOutMessagePtr]
ASM_midiOutMessage ENDP

ASM_midiOutOpen PROC
    jmp [midiOutOpenPtr]
ASM_midiOutOpen ENDP

ASM_midiOutPrepareHeader PROC
    jmp [midiOutPrepareHeaderPtr]
ASM_midiOutPrepareHeader ENDP

ASM_midiOutReset PROC
    jmp [midiOutResetPtr]
ASM_midiOutReset ENDP

ASM_midiOutSetVolume PROC
    jmp [midiOutSetVolumePtr]
ASM_midiOutSetVolume ENDP

ASM_midiOutShortMsg PROC
    jmp [midiOutShortMsgPtr]
ASM_midiOutShortMsg ENDP

ASM_midiOutUnprepareHeader PROC
    jmp [midiOutUnprepareHeaderPtr]
ASM_midiOutUnprepareHeader ENDP

ASM_midiStreamClose PROC
    jmp [midiStreamClosePtr]
ASM_midiStreamClose ENDP

ASM_midiStreamOpen PROC
    jmp [midiStreamOpenPtr]
ASM_midiStreamOpen ENDP

ASM_midiStreamOut PROC
    jmp [midiStreamOutPtr]
ASM_midiStreamOut ENDP

ASM_midiStreamPause PROC
    jmp [midiStreamPausePtr]
ASM_midiStreamPause ENDP

ASM_midiStreamPosition PROC
    jmp [midiStreamPositionPtr]
ASM_midiStreamPosition ENDP

ASM_midiStreamProperty PROC
    jmp [midiStreamPropertyPtr]
ASM_midiStreamProperty ENDP

ASM_midiStreamRestart PROC
    jmp [midiStreamRestartPtr]
ASM_midiStreamRestart ENDP

ASM_midiStreamStop PROC
    jmp [midiStreamStopPtr]
ASM_midiStreamStop ENDP

ASM_mixerClose PROC
    jmp [mixerClosePtr]
ASM_mixerClose ENDP

ASM_mixerGetControlDetailsA PROC
    jmp [mixerGetControlDetailsAPtr]
ASM_mixerGetControlDetailsA ENDP

ASM_mixerGetControlDetailsW PROC
    jmp [mixerGetControlDetailsWPtr]
ASM_mixerGetControlDetailsW ENDP

ASM_mixerGetDevCapsA PROC
    jmp [mixerGetDevCapsAPtr]
ASM_mixerGetDevCapsA ENDP

ASM_mixerGetDevCapsW PROC
    jmp [mixerGetDevCapsWPtr]
ASM_mixerGetDevCapsW ENDP

ASM_mixerGetID PROC
    jmp [mixerGetIDPtr]
ASM_mixerGetID ENDP

ASM_mixerGetLineControlsA PROC
    jmp [mixerGetLineControlsAPtr]
ASM_mixerGetLineControlsA ENDP

ASM_mixerGetLineControlsW PROC
    jmp [mixerGetLineControlsWPtr]
ASM_mixerGetLineControlsW ENDP

ASM_mixerGetLineInfoA PROC
    jmp [mixerGetLineInfoAPtr]
ASM_mixerGetLineInfoA ENDP

ASM_mixerGetLineInfoW PROC
    jmp [mixerGetLineInfoWPtr]
ASM_mixerGetLineInfoW ENDP

ASM_mixerGetNumDevs PROC
    jmp [mixerGetNumDevsPtr]
ASM_mixerGetNumDevs ENDP

ASM_mixerMessage PROC
    jmp [mixerMessagePtr]
ASM_mixerMessage ENDP

ASM_mixerOpen PROC
    jmp [mixerOpenPtr]
ASM_mixerOpen ENDP

ASM_mixerSetControlDetails PROC
    jmp [mixerSetControlDetailsPtr]
ASM_mixerSetControlDetails ENDP

ASM_mmDrvInstall PROC
    jmp [mmDrvInstallPtr]
ASM_mmDrvInstall ENDP

ASM_mmGetCurrentTask PROC
    jmp [mmGetCurrentTaskPtr]
ASM_mmGetCurrentTask ENDP

ASM_mmTaskBlock PROC
    jmp [mmTaskBlockPtr]
ASM_mmTaskBlock ENDP

ASM_mmTaskCreate PROC
    jmp [mmTaskCreatePtr]
ASM_mmTaskCreate ENDP

ASM_mmTaskSignal PROC
    jmp [mmTaskSignalPtr]
ASM_mmTaskSignal ENDP

ASM_mmTaskYield PROC
    jmp [mmTaskYieldPtr]
ASM_mmTaskYield ENDP

ASM_mmioAdvance PROC
    jmp [mmioAdvancePtr]
ASM_mmioAdvance ENDP

ASM_mmioAscend PROC
    jmp [mmioAscendPtr]
ASM_mmioAscend ENDP

ASM_mmioClose PROC
    jmp [mmioClosePtr]
ASM_mmioClose ENDP

ASM_mmioCreateChunk PROC
    jmp [mmioCreateChunkPtr]
ASM_mmioCreateChunk ENDP

ASM_mmioDescend PROC
    jmp [mmioDescendPtr]
ASM_mmioDescend ENDP

ASM_mmioFlush PROC
    jmp [mmioFlushPtr]
ASM_mmioFlush ENDP

ASM_mmioGetInfo PROC
    jmp [mmioGetInfoPtr]
ASM_mmioGetInfo ENDP

ASM_mmioInstallIOProcA PROC
    jmp [mmioInstallIOProcAPtr]
ASM_mmioInstallIOProcA ENDP

ASM_mmioInstallIOProcW PROC
    jmp [mmioInstallIOProcWPtr]
ASM_mmioInstallIOProcW ENDP

ASM_mmioOpenA PROC
    jmp [mmioOpenAPtr]
ASM_mmioOpenA ENDP

ASM_mmioOpenW PROC
    jmp [mmioOpenWPtr]
ASM_mmioOpenW ENDP

ASM_mmioRead PROC
    jmp [mmioReadPtr]
ASM_mmioRead ENDP

ASM_mmioRenameA PROC
    jmp [mmioRenameAPtr]
ASM_mmioRenameA ENDP

ASM_mmioRenameW PROC
    jmp [mmioRenameWPtr]
ASM_mmioRenameW ENDP

ASM_mmioSeek PROC
    jmp [mmioSeekPtr]
ASM_mmioSeek ENDP

ASM_mmioSendMessage PROC
    jmp [mmioSendMessagePtr]
ASM_mmioSendMessage ENDP

ASM_mmioSetBuffer PROC
    jmp [mmioSetBufferPtr]
ASM_mmioSetBuffer ENDP

ASM_mmioSetInfo PROC
    jmp [mmioSetInfoPtr]
ASM_mmioSetInfo ENDP

ASM_mmioStringToFOURCCA PROC
    jmp [mmioStringToFOURCCAPtr]
ASM_mmioStringToFOURCCA ENDP

ASM_mmioStringToFOURCCW PROC
    jmp [mmioStringToFOURCCWPtr]
ASM_mmioStringToFOURCCW ENDP

ASM_mmioWrite PROC
    jmp [mmioWritePtr]
ASM_mmioWrite ENDP

ASM_mmsystemGetVersion PROC
    jmp [mmsystemGetVersionPtr]
ASM_mmsystemGetVersion ENDP

ASM_sndPlaySoundA PROC
    jmp [sndPlaySoundAPtr]
ASM_sndPlaySoundA ENDP

ASM_sndPlaySoundW PROC
    jmp [sndPlaySoundWPtr]
ASM_sndPlaySoundW ENDP

ASM_timeBeginPeriod PROC
    jmp [timeBeginPeriodPtr]
ASM_timeBeginPeriod ENDP

ASM_timeEndPeriod PROC
    jmp [timeEndPeriodPtr]
ASM_timeEndPeriod ENDP

ASM_timeGetDevCaps PROC
    jmp [timeGetDevCapsPtr]
ASM_timeGetDevCaps ENDP

ASM_timeGetSystemTime PROC
    jmp [timeGetSystemTimePtr]
ASM_timeGetSystemTime ENDP

ASM_timeGetTime PROC
    jmp [timeGetTimePtr]
ASM_timeGetTime ENDP

ASM_timeKillEvent PROC
    jmp [timeKillEventPtr]
ASM_timeKillEvent ENDP

ASM_timeSetEvent PROC
    jmp [timeSetEventPtr]
ASM_timeSetEvent ENDP

ASM_waveInAddBuffer PROC
    jmp [waveInAddBufferPtr]
ASM_waveInAddBuffer ENDP

ASM_waveInClose PROC
    jmp [waveInClosePtr]
ASM_waveInClose ENDP

ASM_waveInGetDevCapsA PROC
    jmp [waveInGetDevCapsAPtr]
ASM_waveInGetDevCapsA ENDP

ASM_waveInGetDevCapsW PROC
    jmp [waveInGetDevCapsWPtr]
ASM_waveInGetDevCapsW ENDP

ASM_waveInGetErrorTextA PROC
    jmp [waveInGetErrorTextAPtr]
ASM_waveInGetErrorTextA ENDP

ASM_waveInGetErrorTextW PROC
    jmp [waveInGetErrorTextWPtr]
ASM_waveInGetErrorTextW ENDP

ASM_waveInGetID PROC
    jmp [waveInGetIDPtr]
ASM_waveInGetID ENDP

ASM_waveInGetNumDevs PROC
    jmp [waveInGetNumDevsPtr]
ASM_waveInGetNumDevs ENDP

ASM_waveInGetPosition PROC
    jmp [waveInGetPositionPtr]
ASM_waveInGetPosition ENDP

ASM_waveInMessage PROC
    jmp [waveInMessagePtr]
ASM_waveInMessage ENDP

ASM_waveInOpen PROC
    jmp [waveInOpenPtr]
ASM_waveInOpen ENDP

ASM_waveInPrepareHeader PROC
    jmp [waveInPrepareHeaderPtr]
ASM_waveInPrepareHeader ENDP

ASM_waveInReset PROC
    jmp [waveInResetPtr]
ASM_waveInReset ENDP

ASM_waveInStart PROC
    jmp [waveInStartPtr]
ASM_waveInStart ENDP

ASM_waveInStop PROC
    jmp [waveInStopPtr]
ASM_waveInStop ENDP

ASM_waveInUnprepareHeader PROC
    jmp [waveInUnprepareHeaderPtr]
ASM_waveInUnprepareHeader ENDP

ASM_waveOutBreakLoop PROC
    jmp [waveOutBreakLoopPtr]
ASM_waveOutBreakLoop ENDP

ASM_waveOutClose PROC
    jmp [waveOutClosePtr]
ASM_waveOutClose ENDP

ASM_waveOutGetDevCapsA PROC
    jmp [waveOutGetDevCapsAPtr]
ASM_waveOutGetDevCapsA ENDP

ASM_waveOutGetDevCapsW PROC
    jmp [waveOutGetDevCapsWPtr]
ASM_waveOutGetDevCapsW ENDP

ASM_waveOutGetErrorTextA PROC
    jmp [waveOutGetErrorTextAPtr]
ASM_waveOutGetErrorTextA ENDP

ASM_waveOutGetErrorTextW PROC
    jmp [waveOutGetErrorTextWPtr]
ASM_waveOutGetErrorTextW ENDP

ASM_waveOutGetID PROC
    jmp [waveOutGetIDPtr]
ASM_waveOutGetID ENDP

ASM_waveOutGetNumDevs PROC
    jmp [waveOutGetNumDevsPtr]
ASM_waveOutGetNumDevs ENDP

ASM_waveOutGetPitch PROC
    jmp [waveOutGetPitchPtr]
ASM_waveOutGetPitch ENDP

ASM_waveOutGetPlaybackRate PROC
    jmp [waveOutGetPlaybackRatePtr]
ASM_waveOutGetPlaybackRate ENDP

ASM_waveOutGetPosition PROC
    jmp [waveOutGetPositionPtr]
ASM_waveOutGetPosition ENDP

ASM_waveOutGetVolume PROC
    jmp [waveOutGetVolumePtr]
ASM_waveOutGetVolume ENDP

ASM_waveOutMessage PROC
    jmp [waveOutMessagePtr]
ASM_waveOutMessage ENDP

ASM_waveOutOpen PROC
    jmp [waveOutOpenPtr]
ASM_waveOutOpen ENDP

ASM_waveOutPause PROC
    jmp [waveOutPausePtr]
ASM_waveOutPause ENDP

ASM_waveOutPrepareHeader PROC
    jmp [waveOutPrepareHeaderPtr]
ASM_waveOutPrepareHeader ENDP

ASM_waveOutReset PROC
    jmp [waveOutResetPtr]
ASM_waveOutReset ENDP

ASM_waveOutRestart PROC
    jmp [waveOutRestartPtr]
ASM_waveOutRestart ENDP

ASM_waveOutSetPitch PROC
    jmp [waveOutSetPitchPtr]
ASM_waveOutSetPitch ENDP

ASM_waveOutSetPlaybackRate PROC
    jmp [waveOutSetPlaybackRatePtr]
ASM_waveOutSetPlaybackRate ENDP

ASM_waveOutSetVolume PROC
    jmp [waveOutSetVolumePtr]
ASM_waveOutSetVolume ENDP

ASM_waveOutUnprepareHeader PROC
    jmp [waveOutUnprepareHeaderPtr]
ASM_waveOutUnprepareHeader ENDP

ASM_waveOutWrite PROC
    jmp [waveOutWritePtr]
ASM_waveOutWrite ENDP


END

