# Hoenn Habitat build environment. Source this before building:  . tools/habitat/env.sh
# Toolchain: Arm GNU Toolchain 14.2.Rel1 (darwin-arm64, includes newlib), installed
# under ~/tools by the M0 setup. brew's arm-none-eabi-gcc lacks newlib headers and
# cannot build this repo (see docs/reports/2026-07-18-milestone-0.md).
export HH_TOOLCHAIN="$HOME/tools/arm-gnu-toolchain-14.2.rel1-darwin-arm64-arm-none-eabi"
# coreutils gnubin: the repo's test harness (mgba-rom-test-hydra) execs unprefixed
# GNU `stdbuf`, which brew only exposes here.
export PATH="$HH_TOOLCHAIN/bin:/opt/homebrew/opt/coreutils/libexec/gnubin:$PATH"
# Headless emulator: mGBA 0.10.5 SDL frontend built from source with Lua scripting
# (brew's macOS mGBA is Qt-only, no --script flag).
export HH_MGBA="$HOME/tools/mgba-build/sdl/mgba"
