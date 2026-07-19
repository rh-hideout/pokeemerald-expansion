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

# Scenario scripts. Slice spawn is (6,10) inside the professor's lab (§10).
# Message identity by gStringVar4 first byte: ca=hint/ambient(P), d1=place
# prompt(W), cd=SET DOWN!(S), bb=recruit prompt(A), c1=GROVE-BOUND!(G),
# ce=worker status (Torchic...=T).
#
# Default: the §10 -> Grove circuit. Place the campfire at the furnished
# frame -> Torchic comes home (auto-befriend) -> recruit it -> walk out to
# the Grove -> its worker sprite is there.
SCRIPT_LAB='goto:4,7;face:U;dismiss-until:ca;wait:40;shot:lab_frame_dormant;dismiss-until:d1;dismiss-until:cd;wait:40;shot:lab_torchic_home;clear-sv4;dismiss-until:ca;dismiss-until:bb;clear-sv4;dismiss-until:c1;wait:100;tap:B;wait:30;tap:B;wait:30;tap:B;wait:30;tap:B;wait:30;goto:6,11;walk:D,2;until-map:0,9;wait:30;goto:3,13;face:U;clear-sv4;dismiss-until:ce;wait:40;shot:grove_worker;pass:lab choice + recruit + grove worker'
# Route 103 scenarios (skitty/machop) are PENDING re-route from the lab
# spawn — restored with phase 6's acceptance circuit.

SCRIPT="$SCRIPT_LAB"
case "$1" in
  --no-interact) SCRIPT='wait:1;shot:boot;pass:overworld reached' ;;
  --scenario)
    case "$2" in
      lab) SCRIPT="$SCRIPT_LAB" ;;
      *) echo "scenario '$2' pending phase-6 re-route"; exit 2 ;;
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
