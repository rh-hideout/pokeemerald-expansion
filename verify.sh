#!/bin/bash
# verify.sh - One-command build, test, and verification for pokeemerald-expansion
#
# Usage:
#   ./verify.sh              Run full build + all tests
#   ./verify.sh --tests-only Skip build, run all tests
#   ./verify.sh --build-only Build ROM without running tests
#   ./verify.sh "Spikes"     Build + run only tests matching "Spikes"

set -euo pipefail

NPROC=$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)
TESTS_PATTERN=""
BUILD=true
TEST=true

# Parse arguments
for arg in "$@"; do
    case "$arg" in
        --tests-only)
            BUILD=false
            ;;
        --build-only)
            TEST=false
            ;;
        --help|-h)
            echo "Usage: ./verify.sh [OPTIONS] [TEST_PATTERN]"
            echo ""
            echo "Options:"
            echo "  --build-only   Build the ROM without running tests"
            echo "  --tests-only   Run tests without a full ROM build first"
            echo "  -h, --help     Show this help message"
            echo ""
            echo "Examples:"
            echo "  ./verify.sh                  Full build + all tests"
            echo "  ./verify.sh \"Spikes\"         Full build + only Spikes tests"
            echo "  ./verify.sh --tests-only     Run all tests (skip ROM build)"
            echo "  ./verify.sh --build-only     Build ROM only"
            exit 0
            ;;
        *)
            TESTS_PATTERN="$arg"
            ;;
    esac
done

PASS=0
FAIL=0

step() {
    echo ""
    echo "==== $1 ===="
}

pass() {
    echo "  -> PASS: $1"
    PASS=$((PASS + 1))
}

fail() {
    echo "  -> FAIL: $1"
    FAIL=$((FAIL + 1))
}

# Step 1: Build
if [ "$BUILD" = true ]; then
    step "Building ROM (make -j$NPROC)"
    if make -j"$NPROC" UNUSED_ERROR=1 DEPRECATED_ERROR=1 all; then
        pass "ROM build succeeded"
    else
        fail "ROM build failed"
        echo ""
        echo "Build failed. Fix compile errors above before running tests."
        exit 1
    fi
fi

# Step 2: Tests
if [ "$TEST" = true ]; then
    if [ -n "$TESTS_PATTERN" ]; then
        step "Running tests matching \"$TESTS_PATTERN\" (make check -j$NPROC)"
        if make -j"$NPROC" check TESTS="$TESTS_PATTERN"; then
            pass "Tests matching \"$TESTS_PATTERN\" passed"
        else
            fail "Tests matching \"$TESTS_PATTERN\" failed"
        fi
    else
        step "Running all tests (make check -j$NPROC)"
        if make -j"$NPROC" check; then
            pass "All tests passed"
        else
            fail "Some tests failed"
        fi
    fi
fi

# Summary
echo ""
echo "==============================="
echo "  Verification Summary"
echo "==============================="
echo "  Passed: $PASS"
echo "  Failed: $FAIL"
echo "==============================="

if [ "$FAIL" -gt 0 ]; then
    echo "  RESULT: ISSUES FOUND"
    exit 1
else
    echo "  RESULT: ALL CLEAR"
    exit 0
fi
