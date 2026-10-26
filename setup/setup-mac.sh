#!/bin/bash
# project-poke-flora: one-shot setup for macOS.
#
# Run in Terminal:
#   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/poke-pals/project-poke-flora/master/setup/setup-mac.sh)"
#
# Safe to run again: anything already installed is skipped.
# To only report what is installed (change nothing), put PFLORA_CHECK=1 in front:
#   PFLORA_CHECK=1 /bin/bash -c "$(curl -fsSL ...)"
# (or pass --check when running a local copy: bash setup/setup-mac.sh --check)
#
# Overrides (for testing): PFLORA_DIR, PFLORA_REPO_URL, PFLORA_BRANCH

set -u

REPO_URL="${PFLORA_REPO_URL:-https://github.com/poke-pals/project-poke-flora.git}"
REPO_BRANCH="${PFLORA_BRANCH:-master}"
PROJECT_DIR="${PFLORA_DIR:-$HOME/Documents/GitHub/project-poke-flora}"

PORYMAP_VERSION="6.3.1"
PORYSCRIPT_VERSION="3.6.1"
DKP_PACMAN_VERSION="v6.0.2"

CHECK_ONLY=0
if [ "${1:-}" = "--check" ] || [ "${PFLORA_CHECK:-0}" = "1" ]; then CHECK_ONLY=1; fi

BOLD=$'\033[1m'; GREEN=$'\033[32m'; RED=$'\033[31m'; YELLOW=$'\033[33m'; RESET=$'\033[0m'
RESULTS=()
FAILED=0

say()  { printf '\n%s==> %s%s\n' "$BOLD" "$1" "$RESET"; }
info() { printf '    %s\n' "$1"; }
ok()   { RESULTS+=("${GREEN}✅${RESET} $1"); }
bad()  { RESULTS+=("${RED}❌${RESET} $1"); FAILED=1; }
skip() { RESULTS+=("${YELLOW}➖${RESET} $1"); }

TMP_DIR="$(mktemp -d)"
trap 'rm -rf "$TMP_DIR"' EXIT

if [ "$(uname -s)" != "Darwin" ]; then
    echo "This script is for macOS. On Windows, use setup/setup-windows.ps1."
    exit 1
fi

cat <<EOF
${BOLD}project-poke-flora setup (macOS)${RESET}
This installs the tools you need to work on the hack and builds the game once.
You'll be asked for your Mac password a few times (nothing shows while you type).
Project folder: ${PROJECT_DIR}
EOF
[ $CHECK_ONLY -eq 1 ] && echo "${YELLOW}Check mode: nothing will be installed or changed.${RESET}"

# ---------------------------------------------------------------- Xcode CLT
step_xcode_clt() {
    say "Apple Command Line Tools"
    if xcode-select -p >/dev/null 2>&1; then
        # With full Xcode installed, Homebrew refuses to run until its license is accepted.
        if [[ "$(xcode-select -p)" == *Xcode*.app* ]] && ! xcodebuild -license check >/dev/null 2>&1; then
            if [ $CHECK_ONLY -eq 1 ]; then bad "Xcode license not accepted"; return; fi
            info "Xcode is installed but its license hasn't been accepted (Homebrew needs this)."
            info "Accepting it now. Enter your Mac password if asked."
            sudo xcodebuild -license accept || { bad "Xcode license (run: sudo xcodebuild -license accept)"; return; }
        fi
        ok "Apple Command Line Tools"; return
    fi
    if [ $CHECK_ONLY -eq 1 ]; then bad "Apple Command Line Tools (missing)"; return; fi
    info "A window will pop up. Click 'Install' and wait for it to finish."
    xcode-select --install >/dev/null 2>&1
    for _ in $(seq 1 180); do
        xcode-select -p >/dev/null 2>&1 && break
        sleep 10
    done
    if xcode-select -p >/dev/null 2>&1; then ok "Apple Command Line Tools"; else bad "Apple Command Line Tools (finish the install window, then run this again)"; fi
}

# ---------------------------------------------------------------- Homebrew
find_brew() {
    for b in /opt/homebrew/bin/brew /usr/local/bin/brew; do
        [ -x "$b" ] && { eval "$("$b" shellenv)"; return 0; }
    done
    return 1
}

step_homebrew() {
    say "Homebrew"
    if find_brew; then ok "Homebrew"; return; fi
    if [ $CHECK_ONLY -eq 1 ]; then bad "Homebrew (missing)"; return; fi
    info "Installing Homebrew. Press Return and enter your password when it asks."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    if find_brew; then ok "Homebrew"; else bad "Homebrew"; fi
}

# ---------------------------------------------------------------- Apps (casks)
install_cask() {  # $1 = cask, $2 = app name in /Applications, $3 = label
    if [ -d "/Applications/$2.app" ]; then ok "$3"; return; fi
    if [ $CHECK_ONLY -eq 1 ]; then bad "$3 (missing)"; return; fi
    if ! command -v brew >/dev/null; then bad "$3 (needs Homebrew)"; return; fi
    info "Installing $3..."
    if brew install --cask "$1" >"$TMP_DIR/brew.log" 2>&1 && [ -d "/Applications/$2.app" ]; then
        ok "$3"
    else
        tail -5 "$TMP_DIR/brew.log"
        bad "$3"
    fi
}

step_apps() {
    say "Apps: GitHub Desktop, VS Code, mGBA"
    install_cask github "GitHub Desktop" "GitHub Desktop"
    install_cask visual-studio-code "Visual Studio Code" "VS Code"
    install_cask mgba-app "mGBA" "mGBA (emulator)"
}

# ---------------------------------------------------------------- Porymap
step_porymap() {
    say "Porymap (map editor)"
    if [ -d "/Applications/porymap.app" ]; then ok "Porymap"; return; fi
    if [ $CHECK_ONLY -eq 1 ]; then bad "Porymap (missing)"; return; fi
    local asset="porymap-macos-latest"
    [ "$(uname -m)" = "x86_64" ] && asset="porymap-macos-15-intel"
    local url="https://github.com/huderlem/porymap/releases/download/${PORYMAP_VERSION}/${asset}.zip"
    info "Downloading Porymap ${PORYMAP_VERSION}..."
    if ! curl -fsSL -o "$TMP_DIR/porymap.zip" "$url"; then bad "Porymap (download failed)"; return; fi
    unzip -q -o "$TMP_DIR/porymap.zip" -d "$TMP_DIR/porymap"
    local dmg mount
    dmg="$(find "$TMP_DIR/porymap" -name '*.dmg' | head -1)"
    mount="$(hdiutil attach -nobrowse -readonly "$dmg" 2>/dev/null | tail -1 | awk -F'\t' '{print $NF}')"
    cp -R "$mount/porymap.app" /Applications/ 2>/dev/null
    hdiutil detach "$mount" -quiet
    if [ -d "/Applications/porymap.app" ]; then ok "Porymap"; else bad "Porymap"; fi
}

# ---------------------------------------------------------------- Build tools
step_build_libs() {
    say "Build libraries (libpng, pkg-config)"
    if command -v brew >/dev/null && brew list libpng >/dev/null 2>&1 && brew list pkgconf >/dev/null 2>&1; then
        ok "libpng and pkg-config"; return
    fi
    if [ $CHECK_ONLY -eq 1 ]; then bad "libpng / pkg-config (missing)"; return; fi
    if ! command -v brew >/dev/null; then bad "libpng / pkg-config (needs Homebrew)"; return; fi
    if brew install libpng pkgconf >"$TMP_DIR/brew.log" 2>&1; then
        ok "libpng and pkg-config"
    else
        tail -5 "$TMP_DIR/brew.log"
        bad "libpng / pkg-config"
    fi
}

step_devkitarm() {
    say "GBA compiler (devkitARM)"
    if [ -x /opt/devkitpro/devkitARM/bin/arm-none-eabi-gcc ]; then ok "devkitARM compiler"; return; fi
    if [ $CHECK_ONLY -eq 1 ]; then bad "devkitARM compiler (missing)"; return; fi
    if [ ! -x /opt/devkitpro/pacman/bin/pacman ]; then
        info "Downloading the devkitPro installer..."
        local url="https://github.com/devkitPro/pacman/releases/download/${DKP_PACMAN_VERSION}/devkitpro-pacman-installer.pkg"
        if ! curl -fsSL -o "$TMP_DIR/devkitpro.pkg" "$url"; then bad "devkitARM (download failed)"; return; fi
        info "Installing it. Enter your Mac password if asked."
        sudo installer -pkg "$TMP_DIR/devkitpro.pkg" -target / || { bad "devkitARM (installer failed)"; return; }
    fi
    info "Installing the GBA toolchain (this takes a few minutes)..."
    # dkp-pacman puts devkitPro's own gpg on PATH; plain pacman fails signature checks.
    sudo /usr/local/bin/dkp-pacman -Sy --noconfirm >/dev/null &&
        sudo /usr/local/bin/dkp-pacman -S --noconfirm --needed gba-dev devkitarm-rules >/dev/null
    if [ -x /opt/devkitpro/devkitARM/bin/arm-none-eabi-gcc ]; then ok "devkitARM compiler"; else bad "devkitARM compiler"; fi
}

step_shell_env() {
    say "Shell settings (Homebrew, DEVKITPRO / DEVKITARM)"
    # Apple Silicon Homebrew isn't on PATH in new Terminal windows unless ~/.zprofile loads it;
    # without it, rebuilding the build tools can't find pkg-config/libpng.
    local profile="$HOME/.zprofile"
    if [ -x /opt/homebrew/bin/brew ]; then
        if grep -qs "brew shellenv" "$profile" "$HOME/.zshrc"; then
            ok "Homebrew in ~/.zprofile"
        elif [ $CHECK_ONLY -eq 1 ]; then
            bad "Homebrew not loaded in ~/.zprofile"
        else
            {
                echo ''
                echo 'eval "$(/opt/homebrew/bin/brew shellenv)"'
            } >> "$profile"
            ok "Homebrew in ~/.zprofile"
        fi
    fi

    local rc="$HOME/.zshrc"
    if grep -q "DEVKITPRO=" "$rc" 2>/dev/null; then ok "DEVKITPRO in ~/.zshrc"; return; fi
    if [ $CHECK_ONLY -eq 1 ]; then bad "DEVKITPRO not set in ~/.zshrc"; return; fi
    {
        echo ''
        echo '# devkitPro (GBA toolchain for project-poke-flora)'
        echo 'export DEVKITPRO=/opt/devkitpro'
        echo 'export DEVKITARM=$DEVKITPRO/devkitARM'
    } >> "$rc"
    ok "DEVKITPRO in ~/.zshrc"
}

# ---------------------------------------------------------------- Project
step_clone() {
    say "Project files"
    if [ -d "$PROJECT_DIR/.git" ]; then ok "Project folder: $PROJECT_DIR"; return; fi
    if [ $CHECK_ONLY -eq 1 ]; then bad "Project folder missing: $PROJECT_DIR"; return; fi
    if [ -e "$PROJECT_DIR" ]; then bad "Project folder exists but isn't a git repo: $PROJECT_DIR"; return; fi
    info "Downloading the project (large; a few minutes)..."
    mkdir -p "$(dirname "$PROJECT_DIR")"
    if git clone --branch "$REPO_BRANCH" -c core.autocrlf=false "$REPO_URL" "$PROJECT_DIR"; then
        ok "Project folder: $PROJECT_DIR"
    else
        bad "Project download failed"
    fi
}

step_poryscript() {
    say "Poryscript (script compiler)"
    local bin="$PROJECT_DIR/tools/poryscript/poryscript"
    # Run it, not just check it exists: an Apple Silicon binary can't run on an Intel Mac.
    if "$bin" -v >/dev/null 2>&1; then ok "Poryscript"; return; fi
    if [ $CHECK_ONLY -eq 1 ]; then bad "Poryscript (missing)"; return; fi
    if [ ! -d "$PROJECT_DIR" ]; then bad "Poryscript (no project folder)"; return; fi
    mkdir -p "$(dirname "$bin")"
    rm -f "$bin"
    if [ "$(uname -m)" = "x86_64" ]; then
        # Poryscript only publishes an Apple Silicon Mac build, so compile it here.
        info "Building Poryscript ${PORYSCRIPT_VERSION} for this Intel Mac (needs Go)..."
        if ! command -v go >/dev/null; then
            command -v brew >/dev/null && brew install go >"$TMP_DIR/brew.log" 2>&1
        fi
        if ! command -v go >/dev/null; then tail -5 "$TMP_DIR/brew.log" 2>/dev/null; bad "Poryscript (couldn't install Go)"; return; fi
        local src="https://github.com/huderlem/poryscript/archive/refs/tags/${PORYSCRIPT_VERSION}.tar.gz"
        if ! curl -fsSL "$src" | tar -xz -C "$TMP_DIR"; then bad "Poryscript (download failed)"; return; fi
        (cd "$TMP_DIR/poryscript-${PORYSCRIPT_VERSION}" && go build -o "$bin" .) || { bad "Poryscript (build failed)"; return; }
    else
        local url="https://github.com/huderlem/poryscript/releases/download/${PORYSCRIPT_VERSION}/poryscript-mac.zip"
        if ! curl -fsSL -o "$TMP_DIR/poryscript.zip" "$url"; then bad "Poryscript (download failed)"; return; fi
        unzip -q -o "$TMP_DIR/poryscript.zip" -d "$TMP_DIR/poryscript"
        cp "$TMP_DIR/poryscript/poryscript-mac/poryscript" "$bin" && chmod +x "$bin"
    fi
    if "$bin" -v >/dev/null 2>&1; then ok "Poryscript"; else bad "Poryscript"; fi
}

step_test_build() {
    say "Test build"
    if [ $CHECK_ONLY -eq 1 ]; then skip "Test build (skipped in check mode)"; return; fi
    if [ $FAILED -ne 0 ]; then skip "Test build (skipped: fix the ❌ items first)"; return; fi
    info "Building the game for the first time (2–5 minutes)..."
    export DEVKITPRO=/opt/devkitpro DEVKITARM=/opt/devkitpro/devkitARM
    local log="$TMP_DIR/build.log"
    if (cd "$PROJECT_DIR" && make -j"$(sysctl -n hw.ncpu)") >"$log" 2>&1 && [ -f "$PROJECT_DIR/pokeemerald.gba" ]; then
        ok "Test build (pokeemerald.gba)"
    else
        cp "$log" "$HOME/Desktop/poke-flora-build-error.log" 2>/dev/null
        tail -20 "$log"
        bad "Test build failed (log saved to Desktop: poke-flora-build-error.log)"
    fi
}

step_xcode_clt
step_homebrew
step_apps
step_porymap
step_build_libs
step_devkitarm
step_shell_env
step_clone
step_poryscript
step_test_build

printf '\n%s==== Summary ====%s\n' "$BOLD" "$RESET"
for r in "${RESULTS[@]}"; do printf '  %s\n' "$r"; done

if [ $FAILED -eq 0 ]; then
    cat <<EOF

${GREEN}${BOLD}All set!${RESET} Next steps (see docs/team/ONBOARDING.md):
  1. Open GitHub Desktop, sign in, then File → Add Local Repository → ${PROJECT_DIR}
  2. Open Porymap → File → Open Project → ${PROJECT_DIR}
  3. To play: double-click "Build & Play.command" in the project folder
EOF
    exit 0
else
    cat <<EOF

${RED}${BOLD}Some steps didn't finish.${RESET}
Take a screenshot of this window and send it to the maintainer.
Running this setup again is always safe.
EOF
    exit 1
fi
