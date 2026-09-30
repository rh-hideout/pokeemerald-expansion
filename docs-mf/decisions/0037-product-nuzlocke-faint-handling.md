# 0037 — Nuzlocke faint handling: Cemetery / Release after battle

- **Type:** product
- **Status:** Accepted
- **Date:** 2026-09-29
- **Story:** S36
- **ME reference:** `NuzlockeDeletePartyMon`, `NuzlockeDeletePartyMonOption`, `NuzlockeDeleteFaintedPartyPokemon`, `DoWhiteOut` / `MoveFirstBoxPokemon`, `TX_NUZLOCKE_CEMETERY_ICON_GRAY`, `MON_DATA_NUZLOCKE_RIBBON`
- **Expansion config:** `MF_NUZLOCKE`, `MF_NUZLOCKE_CEMETERY_ICON_GRAY` (default TRUE)

## Context

S36 must permanently retire fainted party Pokémon under Nuzlocke without corrupting the party/PC or softlocking on whiteout. ME offers two FAINTING modes (Cemetery / Release), runs deletion at battle end (not mid-battle), greys cemetery PC icons, and soft-resets when no living box mon remains. Easy mini-mode always cemeteries. Death needs a persistent per-mon mark that survives PC deposit.

## Decision

1. **Death mark** — claim spare substruct3 bit `unused_0B` as `mfNuzlockeDead` (`MON_DATA_MF_NUZLOCKE_DEAD`), matching ME’s ribbon bit approach without inventing a parallel save table.
2. **FAINTING semantics** (menu already Cemetery/Release via `nuzlockeDeletion`):
   - **Cemetery** (`deletion=FALSE`): set dead → `CopyMonToPC` → zero party slot; held item returned to bag first.
   - **Release** (`deletion=TRUE`): zero party slot (no PC copy).
   - **Easy** (`nuzlockeEasy && !nuzlocke`): always Cemetery (ME `NuzlockeDeletePartyMonOption`).
3. **Timing** — delete in `HandleEndTurn_FinishBattle` via `MfNuzlocke_OnBattleEnd` (after battle, not mid-faint). Link / tutorial / frontier / partner battles excluded (ME mask).
4. **Full Nuzlocke gates** — same as encounter lock (starter + Pokédex, off after `FLAG_SYS_GAME_CLEAR`). Easy faint handling ignores those gates (ME).
5. **Whiteout** — if faint handling is active and no living non-dead box mon exists → `DoSoftReset`. Otherwise always pull the first living non-dead box mon into party slot 0 **before** heal/warp. ME only auto-fills under full Nuzlocke; we also fill on Easy so an emptied party cannot softlock (ADR deviation).
6. **PC UX** — greyscale display sprite when `MF_NUZLOCKE_CEMETERY_ICON_GRAY`; blend box icons; block withdraw / place-into-party / give-item until game clear (`"{PKMN} fainted in Nuzlocke!"`).
7. **Debug** — `Faint dry-run` toggles log-only deletions; `Faint plan…` dumps current party victims to mGBA logs.

## Alternatives considered

- **Mark-only (dead stay in party)** — rejected; not in ME’s FAINTING control and would break battling with greyed party slots.
- **Dedicated cemetery box** — rejected; ME dumps into the first free PC slot with a death mark; same visibility via greyscale.
- **ME Easy whiteout (soft-reset gate without MoveFirstBoxPokemon)** — rejected; empty-party whiteout with boxed living mons softlocks; story requires no softlock.
- **Separate death-flag array in ModernRules** — rejected; per-mon mark is required once the mon is in the PC, and the spare Pokémon bit is free.

## Consequences

- Upstream touches: `pokemon.h` / `pokemon.c` (death field + MON_DATA), `battle_main.c` (battle-end hook), `overworld.c` (whiteout), `pokemon_storage_system.c` (grey + locks). Logic stays in `mf_nuzlocke.*`.
- S39 tiers can keep relying on `nuzlockeDeletion` / Easy packing; no new rules fields.
- Unit tests cover fate resolution, battle exclusions, plan masks, release, last-mon empty party, cemetery PC mark, dry-run, and multi-slot compact.
