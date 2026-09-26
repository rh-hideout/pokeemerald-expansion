# 0030 — FRLG classic movepool dual tables

- **Type:** tech
- **Status:** Accepted
- **Date:** 2026-09-25
- **Story:** S30
- **ME reference:** `tx_Mode_Modern_Moves` + `gLevelUpLearnsets` / `gLevelUpLearnsets_Original` / `gTMHMLearnsets_Old` in ME `src/pokemon.c`
- **Expansion config:** `P_LVL_UP_LEARNSETS` stays `GEN_LATEST`; runtime `modernMoves` / `MfRules_HasModernMoves()`

## Context

`{PKMN} MOVEPOOL` must switch between vanilla FireRed learnsets and modern ones at runtime. Expansion already ships per-gen level-up headers behind a compile-time `P_LVL_UP_LEARNSETS` switch, and a single modern teachable/egg table. ME keeps full dual tables and branches in every level-up / TM helper. Story S30 flags ROM size as the main risk and asks for a measured dual-table (or a diff/patch ADR if it does not fit).

## Decision

1. **Keep modern in `gSpeciesInfo`** (`P_LVL_UP_LEARNSETS == GEN_LATEST`, existing teachable/egg data). Modern-on is one rule check then the existing pointers.
2. **Classic = FRLG** from `tools/learnset_helpers/porymoves_files/frlg.json` (not RSE `gen_3.h` — FRLG Charmander learns Metal Claw, not Rage). Generator: `tools/mf/gen_classic_movepools.py`.
3. **Three classic tables** in `src/data/mf_classic_{level_up_learnsets,teachable_learnsets,egg_moves}.h`, included only from `src/mf_moves.c`. Sorted species→pointer rows; binary search when modern is off. Covers level-up, TM/HM+tutor teachables, and egg moves (menu copy promises Egg + TM).
4. **Single upstream hook:** `GetSpeciesLevelUpLearnset` / `GetSpeciesTeachableLearnset` / `GetSpeciesEggMoves` in `src/pokemon.c` call `MfGetSpecies*` — relearner, party menu, dex+, daycare, and `CanLearnTeachableMove` all stay consistent.
5. **Species missing from FRLG** (Gen 4+ forms in the Emerald TESTELF) fall back to the modern SpeciesInfo learnset when classic is selected.

## Alternatives considered

- Include both `gen_3.h` and `gen_9.h` with renamed symbols — rejected; FRLG ≠ RSE for several Kanto learnsets, and teachable/egg still need a second source.
- Diff/patch against modern — unnecessary; measured classic tables are ~55 KiB `.rodata` (~80 KiB payload vs post-S08 baseline including other Phase 4 work), with ~15.8 MiB pad remaining.
- ME-style bitfield TM tables — rejected; expansion’s teachable lists are the live TM/tutor API (`CanLearnTeachableMove`).
- Level-up only — rejected; story Scope and Gamemode copy require TM/tutor (and egg) gating.

## Consequences

- ~55 KiB ROM for classic movepools (`mf_moves.o` `.rodata`). Refresh `frlg.json` / re-run the generator after porymoves updates.
- Classic teachables are FRLG TM+tutor sets, not “modern teachable list filtered to Gen 3” — a species may refuse a current-ROM TM that was not FRLG-compatible.
- Randomizer move stories (S57+) should go through the same getters so they respect the active movepool rule.
