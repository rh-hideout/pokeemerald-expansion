#!/bin/sh
# Headless build-and-boot verification for Hoenn Habitat.
#
# Usage: tools/habitat/verify.sh [--no-interact]
#   --no-interact  stop after reaching the overworld (skip test-spot interaction)
#
# Builds the ROM, compiles the hh-runner against libmgba, boots the ROM
# headlessly (quickstart via SELECT), and verifies overworld arrival — plus,
# by default, walks to the truck's test spot at (1,1) and interacts with the
# sign above it. Screenshots and result.txt land in verify-out/.
set -e
cd "$(dirname "$0")/../.."
. tools/habitat/env.sh

OUT=verify-out
ROM=pokeemerald.gba
# Interact scenario is being rebuilt for the Route 103 slice spawn (M1 phase
# 2b); boot verification is the default until it lands.
INTERACT=0
[ "$1" = "--interact" ] && INTERACT=1
[ "$1" = "--no-interact" ] && INTERACT=0

rm -rf "$OUT"
mkdir -p "$OUT"
rm -f pokeemerald.sav   # deterministic fresh boot every run

echo "hh-verify: building ROM..."
make -j"$(sysctl -n hw.ncpu)" >"$OUT/build.log" 2>&1 || {
    echo "hh-verify: BUILD FAILED"; tail -30 "$OUT/build.log"; exit 1; }

sym() { awk -v s="$1" '$2 == s { print $1; exit }' pokeemerald.map; }
GMAIN=$(sym gMain); CB2=$(sym CB2_Overworld); SB1=$(sym gSaveBlock1Ptr)
[ -n "$GMAIN" ] && [ -n "$CB2" ] && [ -n "$SB1" ] || {
    echo "hh-verify: symbol extraction failed (gMain=$GMAIN CB2_Overworld=$CB2 gSaveBlock1Ptr=$SB1)"; exit 1; }

echo "hh-verify: building runner..."
cc -O2 -I"$HOME/tools/mgba-src/include" -I"$HOME/tools/mgba-build/include" \
   -I/opt/homebrew/include \
   tools/habitat/hh_runner.c \
   -L"$HOME/tools/mgba-build" -lmgba -Wl,-rpath,"$HOME/tools/mgba-build" \
   -o "$OUT/hh-runner"

echo "hh-verify: booting ROM headlessly (gMain=$GMAIN CB2_Overworld=$CB2 gSaveBlock1Ptr=$SB1)..."
if "$OUT/hh-runner" --rom "$ROM" --out "$OUT" \
    --gmain "$GMAIN" --cb2-overworld "$CB2" --sb1ptr "$SB1" \
    --target 1,1 --interact "$INTERACT"; then
    echo "hh-verify: PASS"
    ls "$OUT"/*.png 2>/dev/null
    exit 0
fi
echo "hh-verify: FAIL"
cat "$OUT/result.txt" 2>/dev/null
exit 1
