# 0028 — Dual static type charts + modern-type overlay

- **Type:** tech
- **Status:** Accepted
- **Date:** 2026-09-14
- **Story:** S28
- **ME reference:** `GetTypeBySpecies` modern list + `types_new` for Snubbull/Granbull; `gTypeEffectiveness` vs `gTypeEffectiveness_GenVI` selected by `tx_Mode_TypeEffectiveness`
- **Expansion config:** `P_UPDATED_TYPES` / `B_UPDATED_TYPE_MATCHUPS` stay Gen-latest baselines; runtime `modernTypes` / `typeEffectiveness`

## Context

S28 must make **POKéMON TYPES** and **TYPE CHART** player-toggleable. ME stores modern typings as the species default and falls back to `types_old` when off; expansion has no `types_old`/`types_new` fields. The type chart is on the damage hot path, so per-matchup `#if` / branching is unacceptable.

## Decision

1. **Modern types:** keep `gSpeciesInfo` vanilla (+ Fairy-on from S27). When `MfRules_HasModernTypes()`, `MfGetSpeciesType` overlays ME’s ~23 balance retypes from a compact table in `mf_types.c`. Snubbull/Granbull use ME’s `types_new` (Fairy/Normal) under modern-on; Fairy-off still wins via the S27 fallback (Normal/Normal).
2. **TYPE CHART:** `gTypeEffectivenessTable` remains the Gen VI+ matrix. ME Improved is a second static ROM table (`sMfTypeEffectivenessImproved`) with ME’s eight matchup diffs. `MfGetTypeEffectivenessTable()` returns one pointer; `GetTypeModifier` indexes that table (one rule check, then `table[atk][def]`).
3. **Upstream hooks:** extend the existing `GetSpeciesType` → `MfGetSpeciesType` body; add one include + table selection inside `GetTypeModifier` in `battle_util.c`. No second species_info fork.

## Alternatives considered

- Add `types_old`/`types_new` to `SpeciesInfo` like ME — rejected; large upstream struct / ROM cost for ~23 rows.
- Patch matchups with a runtime `if` list inside `GetTypeModifier` — rejected; story asks for dual static tables and hot-path cost.
- Treat TYPE CHART as “strip Fairy / Gen 1 chart” — rejected; ME labels are Gen VI+ vs Improved, and both charts keep Fairy.

## Consequences

- ~882 bytes ROM for the Improved matrix; overlay table is tiny.
- Dex / summary / battle stay consistent because they already call `GetSpeciesType` / `GetTypeModifier`.
- S56 (randomized chart) can swap the pointer Mf returns without a second battle hook.
- Upstream edits to Gen VI matchups must be mirrored into the Improved table (document the eight ME diffs in the data header).
