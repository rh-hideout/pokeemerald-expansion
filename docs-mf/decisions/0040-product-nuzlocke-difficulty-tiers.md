# 0040 — Nuzlocke difficulty tier bundles (Off / Easy / Normal / Hardcore)

- **Type:** product
- **Status:** Accepted
- **Date:** 2026-09-30
- **Story:** S39
- **ME reference:** `IsNuzlockeActive`, `tx_Nuzlocke_EasyMode` mini mode, `tx_Challenges_NuzlockeHardcore` + `ClearSaveData` on whiteout in `overworld.c` / `tx_rac_menu.c`
- **Expansion config:** `MF_NUZLOCKE`; runtime `nuzlocke` / `nuzlockeEasy` / `nuzlockeHardcore` (+ Difficulty `levelCap` / `noItemPlayer`)

## Context

S39 needs Off / Easy / Normal / Hardcore as coherent bundles and an `IsNuzlockeActive()` equivalent. ME’s Hardcore is Normal Nuzlocke plus wipe-save on whiteout; community “hardcore Nuzlocke” also implies Set battle style, gym level caps, and no healing items in battle — several of those live in Phase 7 (S41/S43). Menu packing already exists (ADR 0022); gameplay for Easy/Normal mostly exists (S35–S38).

## Decision

1. **Tier rule vectors** (asserted by `MfNuzlocke_FillTierBundle`):

   | Tier | Bits | Area lock | Faint | Clauses | Hard extras |
   |---|---|---|---|---|---|
   | **Off** | all clear | — | — | — | — |
   | **Easy** (ME mini) | `nuzlockeEasy` only | no | Cemetery always | disabled / cleared | — |
   | **Normal** | `nuzlocke` | yes (when active) | Cemetery/Release | editable; seeded on enter | — |
   | **Hardcore** | `nuzlocke` + `nuzlockeHardcore` | yes | same as Normal | same as Normal | see below |

2. **`MfNuzlocke_IsActive()`** mirrors ME `IsNuzlockeActive`: `nuzlocke` + starter (`FLAG_SYS_POKEMON_GET`) + Pokédex (`FLAG_SYS_POKEDEX_GET` on FRLG) + not game-clear. Encounter lock (`MfNuzlocke_IsEncounterLockActive`) is this helper — Easy never sets `nuzlocke`, so mini mode never locks areas.

3. **Hardcore extras (wire what exists; seed the rest):**
   - **Run-ender (ME, wired now):** any whiteout while Hardcore is active clears the save and soft-resets (`ClearSaveData` + `DoSoftReset`), until `FLAG_SYS_GAME_CLEAR`.
   - **Set battle style (wired now):** entering Hardcore writes `optionsBattleStyle = SET`; battle init forces Set while Hardcore is active so Options cannot cheat mid-run.
   - **Level cap Normal + no player battle items (seeded now, enforced in S41/S43):** entering Hardcore sets `noItemPlayer = TRUE` and, if `levelCap == 0`, raises it to `1` (Normal). Existing Normal/Hard caps are left alone. Leaving Hardcore does **not** clear these Difficulty fields.

4. **Menu copy** for Hard describes the full Hardcore bundle (Set / level cap / no items / wipe on loss), not ME’s wipe-only line.

## Alternatives considered

- **ME Hardcore = wipe only** — rejected for product; story asks for community hardcore extras and Phase 7 dependency wiring.
- **Auto-enforce level cap / item ban in S39** — rejected; S41/S43 own those systems; seeding the rule bits is enough so Hardcore is already “configured harder.”
- **Revert Difficulty seeds when leaving Hardcore** — rejected; player may have set them on the Difficulty page intentionally.

## Consequences

- Other systems should prefer `MfNuzlocke_IsActive()` over raw `MfRules_IsNuzlocke()` when they need progression-gated full Nuzlocke.
- S41 / S43 read `levelCap` / `noItemPlayer` as usual — Hardcore runs already carry the intended defaults.
- Upstream touch: `battle_main.c` (one-line Set force). Whiteout logic stays in `mf_nuzlocke.c`.
- Unit tests cover each tier’s rule vector, `IsActive` / end-run gates, and Hardcore seed behavior.
