#!/bin/sh
# Headless, fresh-build verification for Hoenn Habitat.
#
# Usage: tools/habitat/verify.sh [--no-interact | --scenario NAME]
# A development-only ROM exposes the versioned HabitatTestProbe ABI. The
# runner asserts those named fields; it intentionally does not scrape text or
# private engine layouts.
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
cd "$ROOT"
. tools/habitat/env.sh

usage() {
    echo "usage: tools/habitat/verify.sh [--no-interact | --scenario NAME]" >&2
    echo "scenarios: lab-campfire lab-plant lab-basin starter-recovery skitty machop route103 bout-win bout-loss bout-flee bout-reset save-migration save-persistence grove item-chooser approved-icons" >&2
}

SCENARIO=boot
case "${1:-}" in
    ""|--no-interact) ;;
    --scenario)
        case "${2:-}" in
            lab-campfire|lab-plant|lab-basin|starter-recovery|skitty|machop|route103|bout-win|bout-loss|bout-flee|bout-reset|save-migration|save-persistence|grove|item-chooser|approved-icons) SCENARIO=$2 ;;
            *)
            echo "hh-verify: scenario '${2:-}' is not available in the current approved slice" >&2
            echo "hh-verify: use --no-interact or one of the documented scenarios" >&2
            exit 2
            ;;
        esac
        ;;
    --help|-h) usage; exit 0 ;;
    *) usage; exit 2 ;;
esac

if [ -n "${HH_VERIFY_OUT:-}" ]; then
    mkdir -p "$HH_VERIFY_OUT"
    OUT=$(CDPATH= cd -- "$HH_VERIFY_OUT" && pwd)
else
    OUT=$(mktemp -d "${TMPDIR:-/tmp}/hh-verify.XXXXXX")
fi
echo "hh-verify: output directory: $OUT"

# A caller can tune parallelism; avoid host-specific sysctl probes so this is
# also usable under restricted CI sandboxes.
HH_VERIFY_JOBS=${HH_VERIFY_JOBS:-4}
case "$HH_VERIFY_JOBS" in
    *[!0-9]*|'') echo "hh-verify: HH_VERIFY_JOBS must be a positive integer" >&2; exit 2 ;;
esac
[ "$HH_VERIFY_JOBS" -gt 0 ] || { echo "hh-verify: HH_VERIFY_JOBS must be positive" >&2; exit 2; }

# -B makes this invocation's map and ROM derive from current sources. The
# subsequent symbol lookup is therefore unable to validate stale link output.
echo "hh-verify: building fresh verification ROM..."
if ! make -B -j"$HH_VERIFY_JOBS" HABITAT_TEST_PROBE=1 >"$OUT/build.log" 2>&1; then
    echo "hh-verify: BUILD FAILED" >&2
    tail -30 "$OUT/build.log" >&2
    exit 1
fi

sym() { awk -v s="$1" '$2 == s { print $1; exit }' pokeemerald.map; }
SB1=$(sym gSaveBlock1Ptr)
PROBE=$(sym gHabitatTestProbe)
COMMAND=$(sym gHabitatTestCommand)
if [ -z "$SB1" ] || [ -z "$PROBE" ] || [ -z "$COMMAND" ]; then
    echo "hh-verify: fresh map is missing required verification symbols" >&2
    exit 1
fi

RUNNER="$OUT/hh-runner"
echo "hh-verify: building runner..."
cc -O2 -iquote include -I"$HH_MGBA_INCLUDE" tools/habitat/hh_runner.c \
   -L"$HH_MGBA_LIB" -lmgba -Wl,-rpath,"$HH_MGBA_LIB" -o "$RUNNER"

# Copying the just-built ROM into the resolved output directory keeps the
# emulator save and screenshots together. No caller directory is deleted.
ROM="$OUT/pokeemerald.gba"
cp pokeemerald.gba "$ROM"
case "$SCENARIO" in
    boot)
        SCRIPT='expect-probe:map_group,1;expect-probe:map_num,4;shot:zorua_lab_boot;pass:Zorua Lab overworld reached'
        ;;
    lab-campfire)
        SCRIPT='expect-probe:map_group,1;expect-probe:map_num,4;command:starter-campfire;expect-probe:spot_id,7;expect-probe:resolved_species,255;expect-probe:spot_state,3;expect-probe:resident_spot_id,7;shot:lab_campfire;pass:Campfire starter transition reached'
        ;;
    lab-plant)
        SCRIPT='expect-probe:map_group,1;expect-probe:map_num,4;command:starter-plant;expect-probe:spot_id,7;expect-probe:resolved_species,252;expect-probe:spot_state,3;expect-probe:resident_spot_id,7;shot:lab_plant;pass:Plant starter transition reached'
        ;;
    lab-basin)
        SCRIPT='expect-probe:map_group,1;expect-probe:map_num,4;command:starter-basin;expect-probe:spot_id,7;expect-probe:resolved_species,258;expect-probe:spot_state,3;expect-probe:resident_spot_id,7;shot:lab_basin;pass:Basin starter transition reached'
        ;;
    starter-recovery)
        SCRIPT='command:starter-campfire;expect-probe:resolved_species,255;command:recover-treecko;expect-probe:spot_id,8;expect-probe:spot_state,3;expect-probe:resolved_species,252;expect-probe:resident_spot_id,8;command:recover-mudkip;expect-probe:spot_id,9;expect-probe:spot_state,3;expect-probe:resolved_species,258;expect-probe:resident_spot_id,9;shot:starter_recovery;pass:Both unchosen starters recovered through their authored furnishing chains'
        ;;
    skitty)
        SCRIPT='command:skitty-place;expect-probe:spot_id,1;expect-probe:spot_state,2;expect-probe:available_verbs,5;shot:skitty_active;command:skitty-offer;expect-probe:spot_state,3;expect-probe:resolved_species,300;expect-probe:resident_spot_id,1;shot:skitty_befriended;pass:Skitty place offer befriend transition reached'
        ;;
    machop)
        SCRIPT='command:machop-offer;expect-probe:spot_id,3;expect-probe:spot_state,3;expect-probe:resolved_species,66;expect-probe:resident_spot_id,3;expect-probe:bout_outcome,0;shot:machop_befriended;pass:Machop Cheri transition has no battle'
        ;;
    route103)
        SCRIPT='goto:6,11;walk:D,2;until-map:0,9;wait:30;goto:10,17;goto:10,1;walk:U,2;until-map:0,16;wait:30;goto:6,15;goto:6,10;goto:16,10;goto:16,4;goto:10,4;goto:10,1;walk:U,2;until-map:0,10;wait:30;goto:10,1;walk:U,2;until-map:0,18;expect-probe:map_group,0;expect-probe:map_num,18;shot:route103;pass:Route 103 reached without a random battle'
        ;;
    bout-win)
        SCRIPT='command:bout-win;wait:180;shot:approved_bout_win_live;until-probe:bout_outcome,1;expect-probe:bout_outcome,1;pass:Live non-capture bout win returned through callback'
        ;;
    bout-loss)
        SCRIPT='command:bout-loss;wait:180;shot:approved_bout_loss_live;until-probe:bout_outcome,2;expect-probe:bout_outcome,2;pass:Live non-capture bout loss returned through callback'
        ;;
    bout-flee)
        SCRIPT='command:bout-flee;wait:180;shot:approved_bout_flee_live;until-probe:bout_outcome,3;expect-probe:bout_outcome,3;pass:Live non-capture bout flee returned through callback'
        ;;
    bout-reset)
        SCRIPT='command:bout-reset;wait:180;shot:approved_bout_reset_live;reset;until-probe:resident_spot_id,3;expect-probe:spot_id,3;expect-probe:spot_state,3;expect-probe:resident_spot_id,3;pass:Live bout reset recovered durable save'
        ;;
    save-migration)
        SCRIPT='command:save-migration;expect-probe:spot_id,3;expect-probe:spot_state,3;expect-probe:resolved_species,66;expect-probe:resident_spot_id,3;shot:save_migration;pass:Legacy resident migrated to stable origin'
        ;;
    save-persistence)
        SCRIPT='command:save-migration;command:save-persistence;expect-probe:spot_id,3;expect-probe:spot_state,3;expect-probe:resident_spot_id,3;shot:save_persistence;pass:Current save round trip preserved resident'
        ;;
    grove)
        SCRIPT='command:grove-assign;expect-probe:spot_id,7;expect-probe:resident_assignment,1;goto:6,11;walk:D,2;until-map:0,9;expect-probe:map_group,0;expect-probe:map_num,9;wait:60;shot:grove;pass:Grove worker visual checkpoint reached'
        ;;
    item-chooser)
        SCRIPT='command:skitty-place;goto:6,11;walk:D,2;until-map:0,9;wait:30;goto:10,17;goto:10,1;walk:U,2;until-map:0,16;wait:30;goto:6,15;goto:6,10;goto:16,10;goto:16,4;goto:10,4;goto:10,1;walk:U,2;until-map:0,10;wait:30;goto:10,1;walk:U,2;until-map:0,18;goto:19,14;face:U;tap:A;wait:45;tap:A;wait:45;shot:item_chooser;pass:Authored item chooser visual checkpoint reached'
        ;;
    approved-icons)
        SCRIPT='command:skitty-place;goto:6,11;walk:D,2;until-map:0,9;wait:30;goto:10,17;goto:10,1;walk:U,2;until-map:0,16;wait:30;goto:6,15;goto:6,10;goto:16,10;goto:16,4;goto:10,4;goto:10,1;walk:U,2;until-map:0,10;wait:30;goto:10,1;walk:U,2;until-map:0,18;goto:19,14;face:U;tap:A;wait:45;tap:A;wait:45;shot:approved_icons;pass:Furnishing icon provenance visual checkpoint reached'
        ;;
esac

echo "hh-verify: running $SCENARIO scenario..."
if "$RUNNER" --rom "$ROM" --out "$OUT" --sb1ptr "$SB1" --probe "$PROBE" --command "$COMMAND" --script "$SCRIPT" 2>"$OUT/runner.log"; then
    echo "hh-verify: PASS"
    find "$OUT" -maxdepth 1 -name '*.png' -print
    exit 0
fi
echo "hh-verify: FAIL" >&2
cat "$OUT/result.txt" 2>/dev/null || true
tail -20 "$OUT/runner.log" 2>/dev/null || true
exit 1
