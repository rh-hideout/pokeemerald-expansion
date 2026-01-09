# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

pokeemerald-expansion is a GBA ROM hack framework built on pret's pokeemerald decompilation. It provides modern Pokemon features (Gen 1-9 mechanics, Mega Evolution, Dynamax, Z-moves, Terastallization) for ROM hack developers.

## Build Commands

```bash
make                           # Build ROM (pokeemerald.gba)
make -j$(nproc)                # Parallel build
make debug                     # Build with debug symbols (-Og -g)
make release                   # Optimized release build
```

## Testing

```bash
make check                     # Run all tests
make check -j$(nproc)          # Parallel test run
make check TESTS="Spikes"      # Run tests matching prefix
make check TESTS="*effect*"    # Run tests with pattern (infix)
make check TESTS="filename.c"  # Run tests from specific file
make pokeemerald-test.elf TESTS="Spikes"  # Build test ROM for visual inspection in mgba
```

### Test Structure

Tests use a DSL with three blocks:
- **GIVEN**: Initialize battle state (parties, abilities, items)
- **WHEN**: Define turns and actions
- **SCENE**: Verify observable outputs (animations, HP changes, messages)

Test macros: `SINGLE_BATTLE_TEST`, `DOUBLE_BATTLE_TEST`, `AI_SINGLE_BATTLE_TEST`, `WILD_BATTLE_TEST`

Tests automatically rig RNG so moves hit and effects activate unless specified otherwise.

## Code Style

### Naming Conventions
- Functions/Structs: `PascalCase`
- Variables/Fields: `camelCase`
- Global variables: prefix `g` (e.g., `gSaveBlock1`)
- Static variables: prefix `s` (e.g., `sMyStaticVar`)
- Macros/Constants: `CAPS_WITH_UNDERSCORES`

### Formatting
- C/H files: 4 spaces (not tabs)
- Assembly/Script files (.s, .inc): tabs
- Opening braces on next line for control structures
- Switch cases align with switch block (no extra indent)
- Single empty line after blocks

### Data Types
- Default to `u32`/`s32` for local variables
- Use smallest type for: saveblock, EWRAM, and global variables
- Use enums over magic numbers; use enum types in function signatures

### Config Checks
Check configs inline within normal control flow, not with preprocessor guards in function bodies:
```c
// Correct
if (!B_VAR_DIFFICULTY)
    return;

// Incorrect
#ifdef B_VAR_DIFFICULTY
    return;
#endif
```

## Architecture

### Source Organization
- `/src/` - C source files (~350 files)
  - `battle_*.c` - Battle system (main, AI, animations, controllers, scripts)
  - `field_*.c` - Overworld/field mechanics
  - `pokemon_*.c` - Pokemon data and UI screens
- `/include/` - Headers
  - `/include/config/` - Feature toggles (battle.h, pokemon.h, ai.h, etc.)
  - `/include/constants/` - Game constants
- `/data/` - Map layouts, encounter data, compiled resources
- `/graphics/` - Sprites and tilesets
- `/sound/` - M4A audio (songs, voicegroups, sound samples)
- `/test/` - Battle and compression tests

### Key Config Files
Generation-based behavior configs in `/include/config/battle.h` use `GEN_LATEST` pattern:
```c
#define B_CRIT_CHANCE GEN_LATEST  // Change to specific gen (e.g., GEN_3) to use that behavior
```

## Contributing Guidelines

- **Branch targets**: Bug fixes → `master`, all other PRs → `upcoming`
- New code should be minimally invasive; isolate large additions in their own files
- Mark unused functions with `UNUSED`
- Config philosophy:
  - Save-modifying features: OFF by default, gated behind config
  - Developer QoL or modern Pokemon emulation: ON by default
  - All other configs: OFF by default
