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
    echo "usage: tools/habitat/verify.sh [--no-interact | --scenario lab]" >&2
}

SCENARIO=boot
case "${1:-}" in
    ""|--no-interact) ;;
    --scenario)
        [ "${2:-}" = lab ] || {
            echo "hh-verify: scenario '${2:-}' is not available in the current approved slice" >&2
            echo "hh-verify: use --no-interact or --scenario lab" >&2
            exit 2
        }
        SCENARIO=lab
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

# -B makes this invocation's map and ROM derive from current sources. The
# subsequent symbol lookup is therefore unable to validate stale link output.
echo "hh-verify: building fresh verification ROM..."
if ! make -B HABITAT_TEST_PROBE=1 >"$OUT/build.log" 2>&1; then
    echo "hh-verify: BUILD FAILED" >&2
    tail -30 "$OUT/build.log" >&2
    exit 1
fi

sym() { awk -v s="$1" '$2 == s { print $1; exit }' pokeemerald.map; }
SB1=$(sym gSaveBlock1Ptr)
PROBE=$(sym gHabitatTestProbe)
if [ -z "$SB1" ] || [ -z "$PROBE" ]; then
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
    lab)
        SCRIPT='expect-probe:map_group,1;expect-probe:map_num,4;expect-probe:spot_id,0;shot:lab;pass:Lab probe baseline reached'
        ;;
esac

echo "hh-verify: running $SCENARIO scenario..."
if "$RUNNER" --rom "$ROM" --out "$OUT" --sb1ptr "$SB1" --probe "$PROBE" --script "$SCRIPT" 2>"$OUT/runner.log"; then
    echo "hh-verify: PASS"
    find "$OUT" -maxdepth 1 -name '*.png' -print
    exit 0
fi
echo "hh-verify: FAIL" >&2
cat "$OUT/result.txt" 2>/dev/null || true
tail -20 "$OUT/runner.log" 2>/dev/null || true
exit 1
