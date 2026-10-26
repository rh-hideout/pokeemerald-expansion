# project-poke-flora: one-shot setup for Windows 10/11.
#
# Run in PowerShell (a normal window, NOT "Run as administrator"):
#   irm https://raw.githubusercontent.com/poke-pals/project-poke-flora/master/setup/setup-windows.ps1 | iex
#
# Safe to run again: anything already installed is skipped.
# If it asks you to restart Windows, restart and run the same command again.
#
# Overrides (for testing): $env:PFLORA_DIR, $env:PFLORA_REPO_URL, $env:PFLORA_BRANCH

$ErrorActionPreference = 'Continue'
$ProgressPreference = 'SilentlyContinue'   # much faster Invoke-WebRequest

$RepoUrl    = if ($env:PFLORA_REPO_URL) { $env:PFLORA_REPO_URL } else { 'https://github.com/poke-pals/project-poke-flora.git' }
$RepoBranch = if ($env:PFLORA_BRANCH)   { $env:PFLORA_BRANCH }   else { 'master' }
$ProjectDir = if ($env:PFLORA_DIR)      { $env:PFLORA_DIR }      else { Join-Path $HOME 'Documents\GitHub\project-poke-flora' }

$PorymapVersion    = '6.3.1'
$PoryscriptVersion = '3.6.1'
$MgbaVersion       = '0.10.5'
$Distro            = 'Ubuntu'
$ProgramsDir       = Join-Path $env:LOCALAPPDATA 'Programs'
$StartMenuDir      = Join-Path $env:APPDATA 'Microsoft\Windows\Start Menu\Programs'

$Results = New-Object System.Collections.Generic.List[string]
$script:Failed = $false
$script:NeedsReboot = $false
$Tmp = Join-Path $env:TEMP ("pflora-setup-" + [guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $Tmp -Force | Out-Null

function Say($m)  { Write-Host ""; Write-Host "==> $m" -ForegroundColor Cyan }
function Info($m) { Write-Host "    $m" }
function Ok($m)   { $Results.Add("[OK]   $m") }
function Bad($m)  { $Results.Add("[FAIL] $m"); $script:Failed = $true }
function Skip($m) { $Results.Add("[SKIP] $m") }

function Add-Shortcut($name, $target) {
    $ws = New-Object -ComObject WScript.Shell
    $lnk = $ws.CreateShortcut((Join-Path $StartMenuDir "$name.lnk"))
    $lnk.TargetPath = $target
    $lnk.WorkingDirectory = Split-Path $target
    $lnk.Save()
}

# wsl.exe prints UTF-16; strip NULs so the text can be matched.
function Get-WslText([string[]]$wslArgs) {
    $out = & wsl.exe @wslArgs 2>&1 | Out-String
    return ($out -replace "`0", '')
}

function Test-DistroInstalled {
    if (-not (Get-Command wsl.exe -ErrorAction SilentlyContinue)) { return $false }
    $list = Get-WslText @('-l', '-q')
    return ($list -split "`r?`n" | ForEach-Object { $_.Trim() }) -contains $Distro
}

function Find-Git {
    $cmd = Get-Command git.exe -ErrorAction SilentlyContinue
    if ($cmd) { return $cmd.Source }
    foreach ($p in @("$env:ProgramFiles\Git\cmd\git.exe", "$env:LOCALAPPDATA\Programs\Git\cmd\git.exe")) {
        if (Test-Path $p) { return $p }
    }
    return $null
}

function Find-Mgba {
    foreach ($p in @("$ProgramsDir\mGBA\mGBA.exe", "$env:ProgramFiles\mGBA\mGBA.exe")) {
        if (Test-Path $p) { return $p }
    }
    $found = Get-ChildItem "$ProgramsDir\mGBA" -Filter mGBA.exe -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($found) { return $found.FullName }
    return $null
}

Write-Host "project-poke-flora setup (Windows)" -ForegroundColor White
Write-Host "This installs the tools you need to work on the hack and builds the game once."
Write-Host "Project folder: $ProjectDir"

# ------------------------------------------------------------------ winget
Say "Windows Package Manager (winget)"
$HasWinget = [bool](Get-Command winget.exe -ErrorAction SilentlyContinue)
if ($HasWinget) { Ok "winget" } else { Bad "winget missing: install 'App Installer' from the Microsoft Store, then run this again" }

function Install-Winget($id, $label, [scriptblock]$isInstalled) {
    if (& $isInstalled) { Ok $label; return }
    if (-not $HasWinget) { Bad "$label (needs winget)"; return }
    Info "Installing $label..."
    winget install -e --id $id --silent --accept-package-agreements --accept-source-agreements | Out-Null
    if (& $isInstalled) { Ok $label } else { Bad $label }
}

# ------------------------------------------------------------------ apps
Say "Apps: Git, GitHub Desktop, VS Code"
Install-Winget 'Git.Git' 'Git' { [bool](Find-Git) }
Install-Winget 'GitHub.GitHubDesktop' 'GitHub Desktop' { Test-Path "$env:LOCALAPPDATA\GitHubDesktop\GitHubDesktop.exe" }
Install-Winget 'Microsoft.VisualStudioCode' 'VS Code' {
    (Test-Path "$ProgramsDir\Microsoft VS Code\Code.exe") -or (Test-Path "$env:ProgramFiles\Microsoft VS Code\Code.exe")
}

Say "mGBA (emulator)"
if (Find-Mgba) { Ok "mGBA" } else {
    Info "Downloading mGBA $MgbaVersion..."
    $archive = Join-Path $Tmp 'mgba.7z'
    try {
        Invoke-WebRequest -UseBasicParsing -Uri "https://github.com/mgba-emu/mgba/releases/download/$MgbaVersion/mGBA-$MgbaVersion-win64.7z" -OutFile $archive
        New-Item -ItemType Directory -Path "$ProgramsDir\mGBA" -Force | Out-Null
        tar.exe -xf $archive -C "$ProgramsDir\mGBA" 2>$null
    } catch { Info "Direct download failed: $($_.Exception.Message)" }
    if (-not (Find-Mgba) -and $HasWinget) {
        Info "Falling back to winget (older mGBA version)..."
        winget install -e --id JeffreyPfau.mGBA --silent --accept-package-agreements --accept-source-agreements | Out-Null
    }
    $mgba = Find-Mgba
    if ($mgba) { Add-Shortcut 'mGBA' $mgba; Ok "mGBA" } else { Bad "mGBA" }
}

Say "Porymap (map editor)"
$PorymapExe = Get-ChildItem "$ProgramsDir\porymap" -Filter porymap.exe -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1
if ($PorymapExe) { Ok "Porymap" } else {
    Info "Downloading Porymap $PorymapVersion..."
    $zip = Join-Path $Tmp 'porymap.zip'
    try {
        Invoke-WebRequest -UseBasicParsing -Uri "https://github.com/huderlem/porymap/releases/download/$PorymapVersion/porymap-windows.zip" -OutFile $zip
        Expand-Archive -Path $zip -DestinationPath "$ProgramsDir\porymap" -Force
    } catch { Info "Download failed: $($_.Exception.Message)" }
    $PorymapExe = Get-ChildItem "$ProgramsDir\porymap" -Filter porymap.exe -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($PorymapExe) { Add-Shortcut 'Porymap' $PorymapExe.FullName; Ok "Porymap" } else { Bad "Porymap" }
}

# ------------------------------------------------------------------ WSL
# WSL1 builds at full speed on the normal C: drive, so the project can live in
# Documents\GitHub where GitHub Desktop and Porymap expect it.
Say "Ubuntu (WSL) for building the game"
if (Test-DistroInstalled) {
    Ok "Ubuntu (WSL)"
} else {
    Write-Host ""
    Write-Host "    Windows will ask for administrator permission to install WSL. Click Yes." -ForegroundColor Yellow
    Write-Host "    If an Ubuntu window opens and asks for a username and password, create them" -ForegroundColor Yellow
    Write-Host "    (remember the password), then type 'exit' in that window." -ForegroundColor Yellow
    # --set-default-version only works once WSL exists, so it runs after --install
    # (on a fresh PC it can still fail until the restart; the WSL1 check below covers that).
    $wslCmd = "wsl --install -d $Distro --enable-wsl1; `$code = `$LASTEXITCODE; wsl --set-default-version 1; exit `$code"
    try {
        $p = Start-Process powershell.exe -Verb RunAs -Wait -PassThru -ArgumentList '-NoProfile', '-Command', $wslCmd
        Info "WSL installer finished (code $($p.ExitCode))."
    } catch {
        Info "Administrator permission was declined."
    }
    if (Test-DistroInstalled) {
        Ok "Ubuntu (WSL)"
    } else {
        $script:NeedsReboot = $true
        Bad "Ubuntu (WSL) not ready yet: RESTART Windows, then run this setup again"
    }
}

if (Test-DistroInstalled) {
    Say "WSL version"
    wsl.exe --set-default-version 1 | Out-Null
    if ((Get-WslText @('-l', '-v')) -match "$Distro\s+\S+\s+2") {
        Info "Switching Ubuntu to WSL1 (faster builds on the C: drive; a few minutes)..."
        wsl.exe --terminate $Distro | Out-Null
        wsl.exe --set-version $Distro 1 | Out-Host
    }
    if ((Get-WslText @('-l', '-v')) -match "$Distro\s+\S+\s+1") {
        Ok "Ubuntu uses WSL1"
    } else {
        Bad "Ubuntu is still on WSL2 (builds would be very slow): screenshot this and send it to the maintainer"
    }

    Say "Build packages inside Ubuntu"
    $check = 'command -v arm-none-eabi-gcc >/dev/null && dpkg -s libpng-dev >/dev/null 2>&1 && command -v make >/dev/null'
    wsl.exe -d $Distro -u root -e bash -c $check
    if ($LASTEXITCODE -eq 0) { Ok "Build packages (Ubuntu)" } else {
        Info "Installing compiler and libraries (5-10 minutes)..."
        $apt = 'export DEBIAN_FRONTEND=noninteractive; apt-get update -q && apt-get install -y -q build-essential binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi git libpng-dev python3'
        wsl.exe -d $Distro -u root -e bash -c $apt | Out-Host
        wsl.exe -d $Distro -u root -e bash -c $check
        if ($LASTEXITCODE -eq 0) { Ok "Build packages (Ubuntu)" } else { Bad "Build packages (Ubuntu)" }
    }
}

# ------------------------------------------------------------------ project
Say "Project files"
$git = Find-Git
if (Test-Path (Join-Path $ProjectDir '.git')) {
    Ok "Project folder: $ProjectDir"
} elseif (-not $git) {
    Bad "Project download (needs Git)"
} elseif (Test-Path $ProjectDir) {
    Bad "Folder exists but isn't a git repo: $ProjectDir"
} else {
    Info "Downloading the project (large; a few minutes)..."
    New-Item -ItemType Directory -Path (Split-Path $ProjectDir) -Force | Out-Null
    # autocrlf=false: build files must keep Unix line endings for the Linux build tools.
    & $git clone --branch $RepoBranch -c core.autocrlf=false $RepoUrl $ProjectDir
    if (Test-Path (Join-Path $ProjectDir '.git')) { Ok "Project folder: $ProjectDir" } else { Bad "Project download failed" }
}

Say "Poryscript (script compiler)"
$PoryBin = Join-Path $ProjectDir 'tools\poryscript\poryscript'
if (Test-Path $PoryBin) { Ok "Poryscript" } elseif (-not (Test-Path $ProjectDir)) { Bad "Poryscript (no project folder)" } else {
    # Builds run inside Ubuntu, so this is the Linux build of Poryscript.
    $zip = Join-Path $Tmp 'poryscript.zip'
    try {
        Invoke-WebRequest -UseBasicParsing -Uri "https://github.com/huderlem/poryscript/releases/download/$PoryscriptVersion/poryscript-linux.zip" -OutFile $zip
        Expand-Archive -Path $zip -DestinationPath (Join-Path $Tmp 'poryscript') -Force
        New-Item -ItemType Directory -Path (Split-Path $PoryBin) -Force | Out-Null
        Copy-Item (Join-Path $Tmp 'poryscript\poryscript-linux\poryscript') $PoryBin -Force
    } catch { Info "Download failed: $($_.Exception.Message)" }
    if (Test-Path $PoryBin) { Ok "Poryscript" } else { Bad "Poryscript" }
}

# ------------------------------------------------------------------ test build
Say "Test build"
if ($script:Failed) {
    Skip "Test build (skipped: fix the [FAIL] items first)"
} else {
    Info "Building the game for the first time (5-15 minutes on the first run)..."
    wsl.exe -d $Distro --cd "$ProjectDir" -e bash -lc 'make -j$(nproc)' | Out-Host
    if ($LASTEXITCODE -eq 0 -and (Test-Path (Join-Path $ProjectDir 'pokeemerald.gba'))) {
        Ok "Test build (pokeemerald.gba)"
    } else {
        Bad "Test build failed (screenshot the errors above)"
    }
}

Remove-Item $Tmp -Recurse -Force -ErrorAction SilentlyContinue

Write-Host ""
Write-Host "==== Summary ====" -ForegroundColor White
foreach ($r in $Results) {
    $color = if ($r.StartsWith('[OK]')) { 'Green' } elseif ($r.StartsWith('[FAIL]')) { 'Red' } else { 'Yellow' }
    Write-Host "  $r" -ForegroundColor $color
}

Write-Host ""
if ($script:NeedsReboot) {
    Write-Host "Restart Windows now, then run the same setup command again." -ForegroundColor Yellow
} elseif (-not $script:Failed) {
    Write-Host "All set! Next steps (see docs/team/ONBOARDING.md):" -ForegroundColor Green
    Write-Host "  1. Open GitHub Desktop, sign in, then File > Add local repository > $ProjectDir"
    Write-Host "  2. Open Porymap (Start menu) > File > Open Project > $ProjectDir"
    Write-Host "  3. To play: double-click 'Build & Play.bat' in the project folder"
} else {
    Write-Host "Some steps didn't finish. Take a screenshot of this window and send it to the maintainer." -ForegroundColor Red
    Write-Host "Running this setup again is always safe."
}
