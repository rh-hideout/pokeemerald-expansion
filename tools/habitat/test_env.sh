#!/bin/sh
# Portable self-tests for tools/habitat/env.sh. Kept shell-only so a new
# checkout can diagnose its configured toolchain before the ROM builds.
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
TEMP=$(mktemp -d)
trap 'rm -rf "$TEMP"' EXIT HUP INT TERM
mkdir -p "$TEMP/toolchain/bin" "$TEMP/mgba/include" "$TEMP/mgba/lib" "$TEMP/mgba/bin"
: > "$TEMP/mgba/bin/mgba"
chmod +x "$TEMP/mgba/bin/mgba"

OUTPUT=$(HH_TOOLCHAIN="$TEMP/toolchain" HH_MGBA="$TEMP/mgba/bin/mgba" \
    HH_MGBA_INCLUDE="$TEMP/mgba/include" HH_MGBA_LIB="$TEMP/mgba/lib" \
    sh -c '. "$0/tools/habitat/env.sh"; printf "%s|%s|%s|%s" "$HH_TOOLCHAIN" "$HH_MGBA" "$HH_MGBA_INCLUDE" "$HH_MGBA_LIB"' "$ROOT")
EXPECTED="$TEMP/toolchain|$TEMP/mgba/bin/mgba|$TEMP/mgba/include|$TEMP/mgba/lib"
[ "$OUTPUT" = "$EXPECTED" ] || { echo "env self-test: caller configuration was not preserved" >&2; exit 1; }

if HH_TOOLCHAIN="$TEMP/missing" HH_MGBA="$TEMP/mgba/bin/mgba" \
    HH_MGBA_INCLUDE="$TEMP/mgba/include" HH_MGBA_LIB="$TEMP/mgba/lib" \
    sh -c '. "$0/tools/habitat/env.sh"' "$ROOT" >"$TEMP/missing.out" 2>&1; then
    echo "env self-test: missing toolchain unexpectedly succeeded" >&2
    exit 1
fi
grep -q 'HH_TOOLCHAIN' "$TEMP/missing.out" || { echo "env self-test: missing path was not named" >&2; exit 1; }

echo "env self-test: caller values, defaults, and missing-path diagnostics pass"
