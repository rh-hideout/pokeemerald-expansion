# 0029 — Classic Gen-3 base-stat fallback table

- **Type:** tech
- **Status:** Accepted
- **Date:** 2026-09-25
- **Story:** S29
- **ME reference:** `base*_old` on `SpeciesInfo` + `tx_Mode_New_Stats` in `CalculateMonStats` (`src/pokemon.c`)
- **Expansion config:** `P_UPDATED_STATS` stays `GEN_LATEST`; runtime `modernStats` / `MfRules_HasModernStats()`

## Context

S29 must make **POKéMON STATS** player-toggleable between original Gen III values and updated ones. ME stores dual `base*` / `base*_old` on every species and branches inside `CalculateMonStats`. Expansion already centralizes lookups in `GetSpeciesBase*` / `GetSpeciesBaseStat` (used by `CalculateMonStats`, dex, AI BST). Adding six `_old` fields to `SpeciesInfo` would bloat the struct and fight upstream merges. ME also applies custom viability buffs (Venusaur HP, Parasect HP, Spinda, Luvdisc, …) beyond official Gen updates — those are a separate product choice.

## Decision

1. **Keep `gSpeciesInfo` Gen-latest** (`P_UPDATED_STATS` unchanged). Modern-on reads those values.
2. **Classic fallback table** in `src/data/mf_classic_base_stats.h` (included by `src/mf_stats.c`): one row per species whose Gen-3 / intro-gen `P_UPDATED_STATS` else-branch differs from Gen-latest. Full classic six stored; sorted by species id; binary-searched only when modern is off.
3. **Single upstream hook:** `GetSpeciesBase*` and `GetSpeciesBaseStat` in `src/pokemon.c` call `MfGetSpeciesBaseStat`. Dex, summary, and battle calc already use these helpers — display stays consistent.
4. **Hot path:** `MfRules_HasModernStats()` true → one rule check, then `gSpeciesInfo` (no table walk). Classic path pays a binary search over ~64 rows.
5. **Not ME’s custom buffs.** Modern = expansion’s official Gen-latest updates only. Menu copy about “more viable” still matches official Gen 6/7 buffs; ME-only overlays (Venusaur 90 HP, etc.) are deferred unless a later product ADR adopts them.
6. **Debug toggle:** flipping `modernStats` in the S17 inspector calls `MfRecalculatePartyStats()` so already-caught party mons match the active table.

## Alternatives considered

- Add `base*_old` to `SpeciesInfo` like ME — rejected; large upstream struct / ROM cost for ~64 rows of diffs.
- Branch inside `CalculateMonStats` only — rejected; dex / AI / other `GetSpeciesBase*` callers would disagree.
- Ship ME’s custom modern buffs as a second overlay — deferred; expands product scope beyond `P_UPDATED_STATS` and needs its own ADR.
- Full dual `SpeciesInfo` tables — rejected; ROM size and merge cost for mostly-identical data.

## Consequences

- ~512 bytes ROM for the classic table; Modern runs pay only the existing accessor.
- Upstream merges that change `P_UPDATED_STATS` ternaries must regenerate `mf_classic_base_stats.h`.
- S49 BST equalizer must call `GetSpeciesBase*` (already gated) and document order: equalizer applies after S29’s modern/classic selection.
- Cosplay / hard-coded Pikachu forms that bake Gen-6 Def/SpDef without the macro are unchanged when classic is on (extra forms are off in the FR ROM per ADR 0008).
