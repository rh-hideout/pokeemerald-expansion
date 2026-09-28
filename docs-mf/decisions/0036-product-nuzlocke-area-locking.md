# 0036 — Per-mapsec Nuzlocke encounter locking

- **Type:** product
- **Status:** Accepted
- **Date:** 2026-09-27
- **Story:** S35
- **ME reference:** `NuzlockeFlagGet/Set/Clear`, `NuzlockeLUT`, `SetNuzlockeChecks`, `ItemUseInBattle_PokeBall` in `tx_randomizer_and_challenges` / `battle_setup` / `item_use`
- **Expansion config:** `MF_NUZLOCKE` (master compile switch)

## Context

S35 needs one catchable wild encounter per area. ME packs ~70 Hoenn mapsecs into a sparse LUT and 9 flag bytes on SaveBlock1. ADR 0012 already reserved `nuzlockeEncounterFlags[ceil(MAPSEC_COUNT/8)]` (~27 bytes) on `ModernRules` covering the full shared Emerald+FR mapsec enum. Gift / static / starter / fossil handling and postgame stop conditions need an explicit product call.

## Decision

1. **Bit index = raw `regionMapSectionId`** (no ME-style sparse LUT). `MAPSEC_COUNT` (~210) fits the reserved array; avoids FR/Emerald skew and a hand-maintained LUT.
2. **Lock active** only for Normal/Hardcore (`MfRules_IsNuzlocke()`), after `FLAG_SYS_POKEMON_GET` + Pokédex received, and **off after `FLAG_SYS_GAME_CLEAR`** (ME uses `FLAG_IS_CHAMPION`). On FRLG the Pokédex gate is `FLAG_SYS_POKEDEX_GET` — ME’s `FLAG_ADVENTURE_STARTED` is a stub (`0`) here and `FlagGet(0)` always fails. Easy mini-mode does not lock areas.
3. **Consume on wild-battle end** (flee / KO / catch), matching ME — not only on successful catch. Excluded battle types: trainer, first battle, legendary, ghost tower, link/recorded, frontier, catch tutorial, in-game partner, trainer hill.
4. **Gifts / fossils / starter** never go through that wild teardown path, so they do **not** consume an area. Scripted legendaries using `BATTLE_TYPE_LEGENDARY` also do not. Species / shiny clauses are deferred to S37.
5. **Kanto Safari** is one mapsec (`MAPSEC_KANTO_SAFARI_ZONE`) for all FR safari floors — one encounter for the whole park (Hoenn ME splits zones).
6. **Block balls** via `GetBallThrowableState` (`BALL_THROW_UNABLE_NUZLOCKE_AREA`) plus Safari selection script `BattleScript_MfNuzlockeCaptureBlocked`, with ME’s “already used your encounter for this area” copy.
7. **Surface used areas** in the S26 rules viewer (Nuzlocke row shows used count) and debug **Used areas…** / rules dump — not town-map markers (out of scope / map polish).
8. **Healthbox indicator** — ME’s red `nuzlocke_indicator` “1” tile in the caught-ball slot when Nuzlocke is on, the area is still unused, and the species is uncaught. Already-caught species keep the Poké Ball icon; used areas show neither.

## Alternatives considered

- **ME sparse LUT sized to catchable Kanto routes only** — rejected; ADR 0012 already sized for full `MAPSEC_COUNT`, and a LUT is merge/maintenance cost with no save savings that matter.
- **Consume only on catch** — rejected; breaks standard Nuzlocke “first encounter” and ME parity.
- **Town-map overlays for used areas** — deferred; viewer + debug dump satisfy the story’s “surface” requirement without map UI work.

## Consequences

- S37 (dupes / shiny) can clear or bypass the area block without changing flag storage.
- S36 faint deletion stays independent of encounter flags.
- Upstream touches: `item_use` ball state, `battle_main` Safari + battle-end mark, one battle string/script (same pattern as S34 drop strings).
