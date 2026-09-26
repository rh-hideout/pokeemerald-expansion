# 0032 — Runtime ENCOUNTERS mode via FR modern wild tables

- **Type:** tech
- **Status:** Accepted
- **Date:** 2026-09-26
- **Story:** S32
- **ME reference:** `tx_Mode_Encounters` + `VAR_ENCOUNTER_TABLE` / triple headers in ME `wild_encounters.json`; `ChangeEncounterTable` in `src/script.c`
- **Expansion config:** `include/config/wild_encounter.h` has no alternate-table switch — unused

## Context

Gamemode `ENCOUNTERS` already stores Vanilla / Modern / Postgame in `alternateSpawns` (menu + presets). S32 must select different wild data at encounter time without new maps. ME keeps three consecutive headers per route and switches with a var + day/night. FR’s JSON already uses FireRed/LeafGreen `#ifdef` pairs, so a simple `i + offset` would land on the wrong twin. We also keep `OW_TIME_OF_DAY_ENCOUNTERS` off.

## Decision

1. **Vanilla** = stock `gWildMonHeaders` (FireRed `#ifdef` entries).
2. **Modern** = parallel `gMfModernWildMonHeaders[]` generated for every FireRed wild map (`tools/mf/gen_modern_encounters.py` → `src/data/mf_modern_wild_encounters.h`). Placement is **level- and biome-aware**: evo stage capped by route max level (basics only on early Kanto), type/biome scoring, and a curated early-land/water pool (ME Route101-style). Leftover coverage dumps go to Safari / Sevii / late areas — not Route 1–15. Mid-rate showcase slots (land 4 + 6 ≈ 15%) keep early routes visibly different. Unown chambers stay Unown-only; legendaries/mythicals stay static-only.
3. **Postgame** = vanilla until `FLAG_SYS_GAME_CLEAR`, then modern (ME parity; menu copy says “after the League”).
4. **Selection** = `MfShouldUseModernWildEncounters()` + `MfGetActiveWildMonHeaders()`. `GetCurrentMapWildMonHeaderId` and all `gWildMonHeaders[i]` encounter consumers (wild, OWE, DexNav, match call, Pokédex area) index the active table. Emerald / `make check` always uses stock headers (`#if FIRERED` around the modern array).
5. No day/night modern twin — FR does not enable time-of-day encounters.

## Alternatives considered

- ME-style interleaved triples in `wild_encounters.json` — rejected; conflicts with FireRed/LeafGreen ifdef pairing and enlarges the shared Emerald JSON merge surface.
- Species remap at `CreateWildMon` time — rejected; story asks for data-only alternate tables and would desync Pokédex area / DexNav.
- Hand-authored Kanto tables only — deferred; generator gives full Gen 1–3 coverage now and can be tuned later without API changes.

## Consequences

- ~190 KiB generated `.h` source; FR-only `.rodata` for modern tables. Re-run the generator after wild JSON or species-range policy changes.
- Upstream files touched for the active-header getter: `wild_encounter.c`, `wild_encounter_ow.c`, `dexnav.c`, `match_call.c`, `pokedex_area_screen.c`.
- S55 wild randomizer must compose with `MfGetActiveWildMonHeaders()` so it randomizes the table the player actually sees.
