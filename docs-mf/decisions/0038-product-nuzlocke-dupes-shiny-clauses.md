# 0038 — Nuzlocke DUPES & SHINY clauses (ME parity, no re-roll)

- **Type:** product
- **Status:** Accepted
- **Date:** 2026-09-29
- **Story:** S37
- **ME reference:** `NuzlockeIsCaptureBlockedBySpeciesClause`, `SetNuzlockeChecks`, battle-end `NuzlockeFlagSet` guard in `battle_setup` / `battle_main` / `item_use`
- **Expansion config:** `MF_NUZLOCKE`; runtime `nuzlockeSpeciesClause` / `nuzlockeShinyClause`

## Context

S37 needs the standard Nuzlocke DUPES and SHINY clauses. The story allows either re-rolling a dupe encounter or allowing another encounter in the area. ME does not re-roll at generation time: a dupe blocks the ball and **does not consume** the mapsec flag, so the next wild battle can still be the area’s first catchable encounter. When every species on a route is already owned, ME leaves that soft-lock in place (endless non-consuming encounters, no catch). Expansion has no `gEvolutionLines` table; family membership must come from existing evo APIs.

## Decision

1. **DUPES = ME species clause (no re-roll).** With `nuzlockeSpeciesClause` on and encounter lock active:
   - Exact species already in the Pokédex → block catch (“already caught this Pokémon”).
   - Otherwise any member of the evolutionary family owned → block catch (“already caught a Pokémon in this evolution line”).
   - Either block **skips area consume** on wild-battle end (cached at `CreateWildMon` so a later catch cannot flip the check after dex update).
2. **Family walk** uses `GetEggSpecies` + recursive `GetSpeciesEvolutions` (not a static ME-style LUT). Forms normalize via `GET_BASE_SPECIES_ID` / `SanitizeSpeciesId`. Ownership is Pokédex **caught**, matching ME.
3. **All-owned case:** no special escape. Dupes keep blocking catch and keep skipping consume; the player must leave the area or turn the clause off (debug). Documented as intentional ME parity.
4. **SHINY clause** (`nuzlockeShinyClause`): if the wild mon is shiny (`IsMonShiny` / stored shininess), bypass **both** area lock and species clause for that battle. A shiny in an unused area still **consumes** the area on battle end (ME clears species-clause active, so the flag is set).
5. **UI:** Safari / bag ball refusal uses the three ME strings; first-encounter “1” stays hidden when DUPES would block (same as ME).

## Alternatives considered

- **Re-roll wild species until an unowned line appears** — rejected; heavier wild-gen hooks, HM/progression risk under randomizer, and diverges from ME.
- **Port ME `gEvolutionLines` table** — rejected; huge static data and merge cost when expansion already has evo graphs.
- **Treat “all owned” as auto-consume / unlock area** — rejected; changes challenge semantics and is not ME behavior.

## Consequences

- Upstream touches stay small: `CreateWildMon` call, ball-throw states, Safari selection scripts/strings, battle-end already routed through `MfNuzlocke_OnWildBattleEnd`.
- S39 tier bundles can keep defaulting DUPES/SHINY on via `MF_TX_NUZLOCKE_*`.
- Monotype (S48) can hide the first-encounter icon the same way DUPES does.
