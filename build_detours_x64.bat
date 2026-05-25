@echo off
setlocal
call "%ProgramFiles%\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat" || exit /b 1
cd /d "%~dp0Detours-src\src"
nmake clean
nmake "CFLAGS=/W4 /WX /Zi /MD /Gy /Gm- /Zl /Od /DWIN32_LEAN_AND_MEAN /D_WIN32_WINNT=0x501"
echo.
echo Built: %~dp0Detours-src\lib.X64\detours.lib
