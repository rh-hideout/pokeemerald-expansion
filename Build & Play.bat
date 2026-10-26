@echo off
rem Double-click to build the game (inside Ubuntu/WSL) and open it in mGBA (Windows).
setlocal
cd /d "%~dp0"

where wsl.exe >nul 2>&1
if not "%errorlevel%"=="0" goto :missing
rem -e runs bash directly; without it WSL's login shell would expand $... before bash sees it.
rem errorlevel checks use "not 0" because wsl.exe reports its own failures as -1.
wsl.exe -d Ubuntu -e bash -c "command -v arm-none-eabi-gcc >/dev/null"
if not "%errorlevel%"=="0" goto :missing
if not exist "tools\poryscript\poryscript" goto :missing

set "MGBA=%LOCALAPPDATA%\Programs\mGBA\mGBA.exe"
if not exist "%MGBA%" for /r "%LOCALAPPDATA%\Programs\mGBA" %%f in (mGBA.exe) do if exist "%%f" set "MGBA=%%f"
if not exist "%MGBA%" set "MGBA=%ProgramFiles%\mGBA\mGBA.exe"
if not exist "%MGBA%" goto :missing

echo Building... (a few seconds, or a few minutes after big changes)
wsl.exe -d Ubuntu --cd "%CD%" -e bash -lc "set -o pipefail; make -j$(nproc) 2>&1 | tail -40"
if not "%errorlevel%"=="0" goto :buildfail
if not exist "pokeemerald.gba" goto :buildfail

echo.
echo Built pokeemerald.gba. Opening mGBA...
start "" "%MGBA%" "%CD%\pokeemerald.gba"
exit /b 0

:missing
echo.
echo Some tools aren't installed (Ubuntu/WSL, compiler, Poryscript, or mGBA).
echo Open PowerShell and run setup again:
echo    irm https://raw.githubusercontent.com/poke-pals/project-poke-flora/master/setup/setup-windows.ps1 ^| iex
echo.
pause
exit /b 1

:buildfail
echo.
echo Build failed. Take a screenshot of the errors above and send it to the maintainer.
echo.
pause
exit /b 1
