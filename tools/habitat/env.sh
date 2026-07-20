# Hoenn Habitat build environment. Source this before building:
#   . tools/habitat/env.sh
#
# Callers may provide every HH_* value (CI and non-macOS builders do). Defaults
# are intentionally applied only when a value is unset, never when it is set.

if [ -z "${HH_TOOLCHAIN+x}" ]; then
    HH_TOOLCHAIN="$HOME/tools/arm-gnu-toolchain-14.2.rel1-darwin-arm64-arm-none-eabi"
fi
if [ -z "${HH_MGBA+x}" ]; then
    HH_MGBA="$HOME/tools/mgba-build/sdl/mgba"
fi
if [ -z "${HH_MGBA_INCLUDE+x}" ]; then
    HH_MGBA_INCLUDE="$HOME/tools/mgba-src/include"
fi
if [ -z "${HH_MGBA_LIB+x}" ]; then
    HH_MGBA_LIB="$(dirname "$(dirname "$HH_MGBA")")"
fi
if [ -z "${HH_COREUTILS_BIN+x}" ] && command -v brew >/dev/null 2>&1; then
    HH_COREUTILS_BIN="$(brew --prefix coreutils 2>/dev/null)/libexec/gnubin"
fi

if [ ! -d "$HH_TOOLCHAIN/bin" ]; then
    echo "habitat env: HH_TOOLCHAIN has no bin directory: $HH_TOOLCHAIN" >&2
    return 1
fi
if [ ! -x "$HH_MGBA" ]; then
    echo "habitat env: HH_MGBA is not executable: $HH_MGBA" >&2
    return 1
fi
if [ ! -d "$HH_MGBA_INCLUDE" ]; then
    echo "habitat env: HH_MGBA_INCLUDE is not a directory: $HH_MGBA_INCLUDE" >&2
    return 1
fi
if [ ! -d "$HH_MGBA_LIB" ]; then
    echo "habitat env: HH_MGBA_LIB is not a directory: $HH_MGBA_LIB" >&2
    return 1
fi

case ":$PATH:" in
    *":$HH_TOOLCHAIN/bin:"*) ;;
    *) PATH="$HH_TOOLCHAIN/bin:$PATH" ;;
esac

# The test runner requires GNU stdbuf. Configure an extra bin directory only
# when the caller supplies one; no machine-specific Homebrew path is baked in.
if [ -n "${HH_COREUTILS_BIN:-}" ]; then
    if [ ! -d "$HH_COREUTILS_BIN" ]; then
        echo "habitat env: HH_COREUTILS_BIN is not a directory: $HH_COREUTILS_BIN" >&2
        return 1
    fi
    case ":$PATH:" in
        *":$HH_COREUTILS_BIN:"*) ;;
        *) PATH="$HH_COREUTILS_BIN:$PATH" ;;
    esac
fi
export HH_TOOLCHAIN HH_MGBA HH_MGBA_INCLUDE HH_MGBA_LIB HH_COREUTILS_BIN PATH

# dyld uses this only as a fallback. It keeps the locally built libmGBA
# discoverable without encoding a developer-home rpath in generated runners.
if [ "$(uname)" = Darwin ]; then
    export DYLD_FALLBACK_LIBRARY_PATH="$HH_MGBA_LIB${DYLD_FALLBACK_LIBRARY_PATH:+:$DYLD_FALLBACK_LIBRARY_PATH}"
fi
