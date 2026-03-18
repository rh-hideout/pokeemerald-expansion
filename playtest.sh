#!/bin/bash
# playtest.sh - Build and playtest your ROM in the browser
#
# Usage:
#   ./playtest.sh            Build ROM with debug enabled, open browser player
#   ./playtest.sh --skip-build  Skip build, just open browser player
#   ./playtest.sh --mgba     Build and open in mGBA instead of browser
#
# The browser player runs entirely locally - no files are uploaded anywhere.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
NPROC=$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)
SKIP_BUILD=false
USE_MGBA=false
PORT=8125

for arg in "$@"; do
    case "$arg" in
        --skip-build) SKIP_BUILD=true ;;
        --mgba) USE_MGBA=true ;;
        -h|--help)
            echo "Usage: ./playtest.sh [OPTIONS]"
            echo ""
            echo "Build your ROM and immediately playtest it."
            echo ""
            echo "Options:"
            echo "  --skip-build   Skip building, use existing ROM"
            echo "  --mgba         Open in mGBA desktop emulator instead of browser"
            echo "  -h, --help     Show this help"
            echo ""
            echo "Debug menus (enabled by default in non-release builds):"
            echo "  Overworld: Hold R + press START"
            echo "  Battle:    Press SELECT during battle"
            echo "  Sprites:   Press SELECT in summary screen"
            exit 0
            ;;
    esac
done

ROM_FILE="$SCRIPT_DIR/pokeemerald.gba"

# Build
if [ "$SKIP_BUILD" = false ]; then
    echo "Building ROM with debug features enabled..."
    make -C "$SCRIPT_DIR" -j"$NPROC" all
    echo ""
fi

# Verify ROM exists
if [ ! -f "$ROM_FILE" ]; then
    echo "Error: ROM not found at $ROM_FILE"
    echo "Run without --skip-build to build it first."
    exit 1
fi

ROM_SIZE=$(du -h "$ROM_FILE" | cut -f1)
echo "ROM ready: $ROM_FILE ($ROM_SIZE)"

# Launch
if [ "$USE_MGBA" = true ]; then
    echo "Opening in mGBA..."
    if command -v mgba-qt &>/dev/null; then
        mgba-qt "$ROM_FILE" &
    elif command -v mgba &>/dev/null; then
        mgba "$ROM_FILE" &
    else
        echo "Error: mGBA not found. Install it or use browser mode (default)."
        exit 1
    fi
else
    echo ""
    echo "Starting browser playtest server on http://localhost:$PORT"
    echo "  1. Your browser will open automatically"
    echo "  2. Drop the ROM file or it will auto-load"
    echo "  3. Press Ctrl+C to stop the server"
    echo ""
    echo "Debug menu reminder:"
    echo "  Overworld: Hold S key + press Enter"
    echo "  Battle:    Press Backspace"
    echo ""

    # Create a temp HTML that auto-loads the ROM via the local server
    PLAYTEST_DIR="$SCRIPT_DIR/tools/playtest"
    SERVE_DIR=$(mktemp -d)
    cp "$PLAYTEST_DIR/index.html" "$SERVE_DIR/index.html"
    cp "$ROM_FILE" "$SERVE_DIR/rom.gba"

    # Inject auto-load script
    sed -i 's|</body>|<script>fetch("rom.gba").then(r=>r.arrayBuffer()).then(b=>{loadROM(new File([b],"pokeemerald.gba"));});</script></body>|' "$SERVE_DIR/index.html" 2>/dev/null || true

    # Try python3 first, then python
    open_browser() {
        sleep 1
        if command -v xdg-open &>/dev/null; then
            xdg-open "http://localhost:$PORT" 2>/dev/null
        elif command -v open &>/dev/null; then
            open "http://localhost:$PORT"
        fi
    }

    cleanup() {
        rm -rf "$SERVE_DIR"
        echo ""
        echo "Server stopped."
    }
    trap cleanup EXIT

    open_browser &

    if command -v python3 &>/dev/null; then
        python3 -m http.server "$PORT" -d "$SERVE_DIR"
    elif command -v python &>/dev/null; then
        cd "$SERVE_DIR" && python -m SimpleHTTPServer "$PORT"
    else
        echo "Error: Python not found (needed for local server)."
        echo "Open tools/playtest/index.html directly and drag in your ROM."
        exit 1
    fi
fi
