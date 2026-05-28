@echo off
setlocal enabledelayedexpansion

cd /d "%~dp0" || exit /b 1

if not exist "Detours-src\include\detours.h" (
    echo ERROR: Detours-src\include\detours.h was not found.
    echo Run build_detours_x64.bat after placing Detours in Detours-src.
    exit /b 1
)

if not exist "Detours-src\lib.X64\detours.lib" (
    echo Building Detours...
    call "%~dp0build_detours_x64.bat" || exit /b 1
)

where msbuild >nul 2>nul
if errorlevel 1 (
    set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
    if not exist "!VSWHERE!" (
        echo ERROR: msbuild was not found, and vswhere.exe is missing.
        echo Open "x64 Native Tools Command Prompt for VS" and run this script again.
        exit /b 1
    )

    for /f "usebackq tokens=*" %%i in (`"!VSWHERE!" -latest -products * -requires Microsoft.Component.MSBuild -property installationPath`) do set "VSINSTALL=%%i"
    if not defined VSINSTALL (
        echo ERROR: Visual Studio with MSBuild was not found.
        exit /b 1
    )

    call "!VSINSTALL!\VC\Auxiliary\Build\vcvars64.bat" || exit /b 1
)

if exist "dist" rmdir /s /q "dist"
if exist "release" rmdir /s /q "release"
mkdir "release" || exit /b 1

msbuild version.sln /m /p:Configuration=Release /p:Platform=x64 /p:OutDir="%CD%\dist\\" || exit /b 1

if not exist "dist\version.dll" (
    echo ERROR: version.dll was not produced.
    exit /b 1
)

copy /y "dist\version.dll" "release\version.dll" >nul || exit /b 1

echo.
echo Built: %CD%\release\version.dll
