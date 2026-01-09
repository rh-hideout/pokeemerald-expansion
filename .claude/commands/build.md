---
allowed-tools: Bash(make:*)
description: Build the ROM with specified options
argument-hint: [game] [flags]
---

## Context

- Available games: emerald (default), firered, leafgreen
- Available flags: debug, release
- CPU cores: !`nproc`

## Task

Build the ROM with the following parameters:
- Game version: $1 (default: emerald)
- Build type: $2 (default: standard build)

Run the appropriate make command:
- Standard: `make -j$(nproc) $1`
- Debug: `make -j$(nproc) $1 DEBUG=1`
- Release: `make -j$(nproc) $1 RELEASE=1`

If no arguments provided, run `make -j$(nproc)` for a standard emerald build.

Report the build result and output ROM filename.
