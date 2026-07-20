#!/bin/sh
# Self-tests for verifier contracts that do not require a ROM build.
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
cd "$ROOT"
. tools/habitat/env.sh
TEMP=$(mktemp -d)
trap 'rm -rf "$TEMP"' EXIT HUP INT TERM

cc -O2 -iquote include -I"$HH_MGBA_INCLUDE" tools/habitat/hh_runner.c \
    -L"$HH_MGBA_LIB" -lmgba -Wl,-rpath,"$HH_MGBA_LIB" -o "$TEMP/hh-runner"
"$TEMP/hh-runner" --validate-script 'expect-probe:map_group,1;pass:ok'
if "$TEMP/hh-runner" --validate-script 'until-sv4:ca' >"$TEMP/old.out" 2>&1; then
    echo "verify self-test: legacy message-byte operation was accepted" >&2
    exit 1
fi

tools/habitat/verify.sh --help 2>&1 | grep -q 'approved-icons'
"$TEMP/hh-runner" --validate-script 'command:bout-win;expect-probe:bout_outcome,1;pass:ok'
if make -n RELEASE=1 HABITAT_TEST_PROBE=1 >"$TEMP/release.out" 2>&1; then
    echo "verify self-test: release build accepted the development probe" >&2
    exit 1
fi
if grep -Eq 'rm[[:space:]]+-rf' tools/habitat/verify.sh; then
    echo "verify self-test: verifier contains a broad recursive delete" >&2
    exit 1
fi
grep -q 'make -B -j' tools/habitat/verify.sh
grep -q 'HH_VERIFY_JOBS' tools/habitat/verify.sh
grep -q 'HH_VERIFY_OUT' tools/habitat/verify.sh

echo "verify self-test: parser, release guard, fresh-build, and safe-output contracts pass"
