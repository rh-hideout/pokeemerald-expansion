#!/bin/sh
# Headless build-and-verify for Hoenn Habitat.
#
# Usage: tools/habitat/verify.sh [--no-interact | --scenario NAME]
#   default          boot + Machop inspect (staged ACTIVE hint)
#   --no-interact    boot to overworld only
#   --scenario skitty  full loop: place doll -> Skitty manifests -> offer
#                      Oran -> befriended (proves PLACE + OFFER + state saves)
#
# The runner observes the game through pokeemerald.map symbols and the
# gStringVar4 message buffer (every shown field message is expanded into it;
# distinct first letters identify texts: P=hint/placeholder, S=SET DOWN!,
# B=BEFRIENDED!).
set -e
cd "$(dirname "$0")/../.."
. tools/habitat/env.sh

OUT=verify-out
ROM=pokeemerald.gba

# Scenario scripts. Slice spawn is (48,12) on Route 103.
# Machop spot: (47,10), stand below at (47,11).
SCRIPT_DEFAULT='goto:47,11;face:U;tap:A;until-sv4:ca;wait:40;shot:interact;pass:machop hint shown'
# Skitty spot: (46,12), stand below at (46,13). Message identity by first
# byte: ca=hint(P), d1=place prompt(W), cd=SET DOWN!(S), c9=offer prompt(O),
# bc=BEFRIENDED!(B). Each msgbox needs one A to fast-forward the typewriter
# and one to answer/dismiss.
SCRIPT_SKITTY='goto:46,13;face:U;dismiss-until:ca;wait:40;shot:skitty_dormant;dismiss-until:d1;dismiss-until:cd;wait:40;shot:skitty_placed;clear-sv4;dismiss-until:ca;wait:40;shot:skitty_manifested;dismiss-until:c9;clear-sv4;dismiss-until:bc;wait:40;shot:skitty_befriended;pass:skitty placed+offered+befriended'

SCRIPT="$SCRIPT_DEFAULT"
case "$1" in
  --no-interact) SCRIPT='wait:1;shot:boot;pass:overworld reached' ;;
  --scenario)
    case "$2" in
      skitty) SCRIPT="$SCRIPT_SKITTY" ;;
      *) echo "unknown scenario: $2"; exit 2 ;;
    esac ;;
esac

rm -rf "$OUT"
mkdir -p "$OUT"
rm -f pokeemerald.sav   # deterministic fresh boot every run

echo "hh-verify: building ROM..."
make -j"$(sysctl -n hw.ncpu)" >"$OUT/build.log" 2>&1 || {
    echo "hh-verify: BUILD FAILED"; tail -30 "$OUT/build.log"; exit 1; }

sym() { awk -v s="$1" '$2 == s { print $1; exit }' pokeemerald.map; }
GMAIN=$(sym gMain); CB2=$(sym CB2_Overworld); SB1=$(sym gSaveBlock1Ptr); SV4=$(sym gStringVar4)
[ -n "$GMAIN" ] && [ -n "$CB2" ] && [ -n "$SB1" ] && [ -n "$SV4" ] || {
    echo "hh-verify: symbol extraction failed"; exit 1; }

echo "hh-verify: building runner..."
cc -O2 -I"$HOME/tools/mgba-src/include" -I"$HOME/tools/mgba-build/include" \
   -I/opt/homebrew/include \
   tools/habitat/hh_runner.c \
   -L"$HOME/tools/mgba-build" -lmgba -Wl,-rpath,"$HOME/tools/mgba-build" \
   -o "$OUT/hh-runner"

echo "hh-verify: running scenario..."
if "$OUT/hh-runner" --rom "$ROM" --out "$OUT" \
    --gmain "$GMAIN" --cb2-overworld "$CB2" --sb1ptr "$SB1" --strvar4 "$SV4" \
    --script "$SCRIPT" 2>"$OUT/runner.log"; then
    echo "hh-verify: PASS"
    ls "$OUT"/*.png 2>/dev/null
    exit 0
fi
echo "hh-verify: FAIL"
cat "$OUT/result.txt" 2>/dev/null
tail -10 "$OUT/runner.log" 2>/dev/null
exit 1
