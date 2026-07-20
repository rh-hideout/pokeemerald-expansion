#!/bin/sh
# Headless build-and-verify for Hoenn Habitat.
#
# Usage: tools/habitat/verify.sh [--no-interact | --scenario NAME]
#   default / lab    the §10 opening: place campfire -> Torchic home ->
#                    recruit -> Grove worker confirmed
#   --scenario skitty  overland walk to Route 103 west bank + full loop:
#                      place doll -> manifests -> offer Persim -> befriended
#   --scenario machop  overland walk + staged hint at the relocated spot
#   --no-interact    boot to the Zorua Lab overworld only
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
# ...ends with a plot inspect: Torchic's assignment planted its type berry,
# so the plot answers "Growing:..." (G) — proves the plot dialogue wiring.
SCRIPT_LAB='goto:4,7;face:U;dismiss-until:ca;wait:40;shot:lab_frame_dormant;dismiss-until:d1;dismiss-until:cd;wait:40;shot:lab_torchic_home;clear-sv4;dismiss-until:ca;dismiss-until:bb;clear-sv4;dismiss-until:c1;wait:120;tap:A;wait:90;tap:A;wait:90;tap:A;wait:90;goto:6,11;walk:D,2;until-map:0,9;wait:30;goto:11,17;goto:11,13;face:U;clear-sv4;dismiss-until:ce;wait:40;shot:grove_worker;wait:120;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;goto:12,14;face:U;clear-sv4;dismiss-until:c1;wait:40;shot:grove_plot;wait:120;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;pass:lab choice + recruit + grove worker + plot'

# The overland leg: lab -> Littleroot -> Route 101 -> Oldale -> Route 103
# west bank. Waypoints charted from decoded layout walkability (Y-first goto:
# every leg's vertical-then-horizontal L-path is clear). Littleroot uses
# column x=10 (x=11 is the Grove worker row - blocked when a worker is out).
# Route 101 crosses the row-10 tall grass: this leg headlessly PROVES the
# HABITAT_NO_WILD_ENCOUNTERS gate - a wild battle here would eat the run.
LEG_TO_R103='goto:6,11;walk:D,2;until-map:0,9;wait:30;goto:10,17;goto:10,1;walk:U,2;until-map:0,16;wait:30;goto:6,15;goto:6,10;goto:16,10;goto:16,4;goto:10,4;goto:10,1;walk:U,2;until-map:0,10;wait:30;goto:10,1;walk:U,2;until-map:0,18;wait:30;goto:10,17'

# Skitty at (19,13): place the doll -> manifests -> offer Persim -> befriended.
SCRIPT_SKITTY="$LEG_TO_R103;goto:20,13;face:L;dismiss-until:ca;wait:40;shot:skitty_dormant;dismiss-until:d1;dismiss-until:cd;wait:40;shot:skitty_placed;clear-sv4;dismiss-until:ca;wait:40;shot:skitty_manifested;dismiss-until:c9;clear-sv4;dismiss-until:bc;wait:120;tap:A;wait:90;tap:A;wait:90;shot:skitty_befriended;pass:overland walk + skitty place/offer/befriend"

# Machop at (12,7): born ACTIVE (empty appear list); staged hint after the
# full overland walk proves the west-bank relocation is reachable on foot.
# (row 12 hedge spans x0-13: cross east via the row-13 grass at x=14 first)
# Ends with a scavenge-find pickup, proven positionally: the obtain message
# starts with the player's name (no stable first letter), so tap through it
# blind, then goto the ball's own tile — only walkable once collected.
SCRIPT_MACHOP="$LEG_TO_R103;goto:10,13;goto:14,13;goto:14,8;goto:12,8;face:U;dismiss-until:ca;wait:40;shot:machop_hint;wait:120;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;tap:B;wait:75;goto:15,8;face:D;tap:A;wait:150;tap:A;wait:90;tap:A;wait:90;tap:A;wait:90;tap:A;wait:90;tap:A;wait:90;tap:A;wait:90;goto:15,9;wait:20;shot:find_taken;pass:overland walk + machop hint + find pickup"

SCRIPT="$SCRIPT_LAB"
case "$1" in
  --no-interact) SCRIPT='wait:1;shot:zorua_lab_boot;pass:Zorua Lab overworld reached' ;;
  --scenario)
    case "$2" in
      lab) SCRIPT="$SCRIPT_LAB" ;;
      skitty) SCRIPT="$SCRIPT_SKITTY" ;;
      machop) SCRIPT="$SCRIPT_MACHOP" ;;
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
