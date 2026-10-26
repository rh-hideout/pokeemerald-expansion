#!/bin/bash
# Double-click to build the game and open it in mGBA (macOS).

cd "$(dirname "$0")" || exit 1

# Homebrew provides pkg-config/libpng for rebuilding the build tools.
for b in /opt/homebrew/bin/brew /usr/local/bin/brew; do
    [ -x "$b" ] && { eval "$("$b" shellenv)"; break; }
done
export DEVKITPRO=/opt/devkitpro
export DEVKITARM=$DEVKITPRO/devkitARM
SETUP_CMD='/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/poke-pals/project-poke-flora/master/setup/setup-mac.sh)"'

fail() {
    echo ""
    echo "❌ $1"
    echo ""
    read -r -n 1 -p "Press any key to close this window..."
    exit 1
}

missing=()
[ -x "$DEVKITARM/bin/arm-none-eabi-gcc" ] || missing+=("GBA compiler (devkitARM)")
tools/poryscript/poryscript -v >/dev/null 2>&1 || missing+=("Poryscript")
[ -d /Applications/mGBA.app ]             || missing+=("mGBA")
if [ ${#missing[@]} -gt 0 ]; then
    printf 'Missing: %s\n' "${missing[@]}"
    fail "Some tools aren't installed. Run setup again in Terminal:
   $SETUP_CMD"
fi

echo "Building... (a few seconds, or a few minutes after big changes)"
log="$(mktemp)"
make -j"$(sysctl -n hw.ncpu)" >"$log" 2>&1
status=$?
tail -40 "$log"
rm -f "$log"
if [ $status -ne 0 ] || [ ! -f pokeemerald.gba ]; then
    fail "Build failed. Take a screenshot of the errors above and send it to the maintainer."
fi

echo ""
echo "✅ Built pokeemerald.gba. Opening mGBA..."
open -a mGBA pokeemerald.gba
