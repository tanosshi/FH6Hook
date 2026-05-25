#pragma once

#include <windows.h>
#include <Psapi.h>

#define DISABLE_REPORT_ERROR_BY_MESSAGEBOX 0

#if DISABLE_REPORT_ERROR_BY_MESSAGEBOX
#define AHEAD_LIB_SHOW_MESSAGE_BOX(...) 
#else
#define AHEAD_LIB_SHOW_MESSAGE_BOX(...) MessageBox(__VA_ARGS__)
#endif

BOOL ReplaceMemory(void* dest, const void* source, int length);
BOOL FindModuleSection(HMODULE module, const char* segmentName, void** outSectionStart, LONGLONG* outSize);
void* SearchInSection(HMODULE module, const char* segmentName, const void* signature, int length);
void* SearchInMemory(const void* startPos, const void* endPos, const void* signature, int length);
BOOL PatchMemory(HMODULE module, const char* segmentName, const void* signature, const void* newBytes, int length);
BOOL PatchMultipleMemories(HMODULE module, const char* segmentName, const void** signaturePtr, const void** newBytesPtr, const int* lengthPtr, int count);

