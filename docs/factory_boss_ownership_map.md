# Factory Boss Ownership Map

This is the source-of-truth guide for where Battle Factory boss data should live.

## Core Principle

- `trainers.h` defines **who the trainer is in battle data terms**.
- Factory boss data is split into:
  - `factory_boss_text_strings.h` for raw string constants
  - `factory_boss_text_sets.h` for `FactoryBossTextSet` structs
  - `factory_boss_profiles.h` for boss profile rows (which trainer + behavior knobs + pointer to text set)
- Factory map scripts define **when/where text and flow happen**.

## What Belongs Where

### `src/data/trainers.h`

Own this here:
- `trainerName`
- `trainerClass` (this controls labels like `{PKMN} TRAINER`)
- `trainerPic` / battle visual identity
- party composition, items, AI flags

Important:
- `src/data/trainers.h` is auto-generated.
- Edit `src/data/trainers.party`, not `src/data/trainers.h`.
- Regenerate by building (`make`), which runs `trainerproc`.

Do **not** put Factory-specific orchestration logic here.

### `src/data/battle_factory/factory_boss_text_strings.h`

Own this here:
- only string constants for boss dialogue and slide lines.

Keep this file dumb data only.

### `src/data/battle_factory/factory_boss_text_sets.h`

Own this here:
- `FactoryBossTextSet` definitions that group all text pointers for one boss.

This is the bridge between raw strings and profile rows.

### `src/data/battle_factory/factory_boss_profiles.h`

Own this here:
- Which trainer is used as the active Factory boss (`trainerId`)
- Pointer to the boss text set (`.text`)
- Factory boss BGM / object gfx
- Boss-only combat behavior knobs (example: ace policy)
- Debug menu display name

Do **not** duplicate full trainer party/class definitions here.

### Factory scripts (`data/maps/BattleFrontier_*Factory*/scripts.inc`)

Own this here:
- Room flow (warp, movement, branching)
- Calling specials to fetch boss text
- Timing of message display (when intro/start/post-win appears)

Do **not** hardcode per-boss content in scripts when a profile hook exists.

### C runtime glue (`src/frontier_util.c`, `src/battle_factory.c`, etc.)

Own this here:
- Reading active boss id/profile
- Buffering profile text into script vars (`gStringVar4`)
- Bridging frontier brain systems to boss-specific behavior

## Decision Rules

When adding/changing something, use this checklist:

1. Is it trainer identity/team/class?  
   -> `trainers.h`

2. Is it Factory boss flavor/behavior for that identity?  
   -> text in `factory_boss_text_strings.h` + `factory_boss_text_sets.h`, wiring in `factory_boss_profiles.h`

3. Is it about map flow/timing of dialogue?  
   -> Factory `scripts.inc`

4. Is it runtime plumbing between systems?  
   -> `src/*.c` glue

## Add-New-Boss Minimal Flow

1. Add or choose trainer entry in `src/data/trainers.party` (generated into `src/data/trainers.h` during build).
2. Add boss constant in `include/constants/factory_boss.h`.
3. Add text strings in `src/data/battle_factory/factory_boss_text_strings.h`.
4. Add a text set in `src/data/battle_factory/factory_boss_text_sets.h`.
5. Add profile row in `src/data/battle_factory/factory_boss_profiles.h`.
6. Build and test via Debug -> `Trigger Boss`.
7. Test full in-game flow:
   - pre-battle call text
   - intro/start lines
   - post-win text
   - loss/win speech behavior

## Current Known Improvement Points

- Pool selection should be mode-driven (not `preferRandbatsPool` bias).
- Expand profile-driven trainer slide hooks beyond last-mon/low-HP when needed.
- Decide if trainer class/name needs a separate boss-specific override path, or stays trainer-data-driven only.

## Design Guardrails

- If a new idea increases coupling to one trainer (for example Steven-only branches), reject it unless there is no generic alternative.
- Prefer adding a profile/text-set field over adding another boss-specific script label.
- Do not add name/class overrides in boss profiles unless trainer-data-driven class behavior becomes a hard blocker.
