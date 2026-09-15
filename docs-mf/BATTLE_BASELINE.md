# Battle mechanics baseline (Phase 1 / S07)

Compile-time expansion defaults that Modern FireRed treats as **always-on** until Phase 4 makes Fairy / types / phys-spec player-toggleable via the rules engine (ADR 0003).

No FireRed-specific override of these macros was found under `include/config/` or FR `#ifdef` paths. FireRed and Emerald share the same battle/species data when `GEN_LATEST` is left alone.

## Generation pin

| Macro | File | Value | Role |
| ----- | ---- | ----- | ---- |
| `GEN_LATEST` | `include/config/general.h` | `GEN_9` | Default for nearly every gen-gated battle/Pokémon config |

**Decision:** Keep `GEN_LATEST` at Gen 9 for Phase 1. Do not blanket-downgrade for “Kanto feel.” Record per-mechanic exceptions in ADRs if a Gen 9 behavior proves undesirable later (none for phys/spec, Fairy, or the type chart as of S07 — see ADR 0007).

## Physical / Special split (“phys/spec on”)

| Macro | File | Required for modern split |
| ----- | ---- | ------------------------- |
| `B_PHYSICAL_SPECIAL_SPLIT` | `include/config/battle.h` | `>= GEN_4` (default `GEN_LATEST`) |

With the split on, `GetBattleMoveCategory` uses each move’s `.category` in `gMovesInfo` (e.g. Bite → physical, Shadow Ball → special). Below Gen 4 it would fall back to `gTypesInfo[type].damageCategory` (Dark/Ghost → special).

Related (not the split itself, but affect Kanto move identity):

| Macro | Effect when `GEN_LATEST` |
| ----- | ------------------------ |
| `B_UPDATED_MOVE_TYPES` | Bite is Dark (not Normal) |
| `B_UPDATED_MOVE_DATA` | Modern powers / secondary effects |

## Fairy + modern typings (“Fairy on”)

There is **no** single `FAIRY_ENABLED` switch. Fairy is live when all of the following hold:

| Piece | Source | What it does |
| ----- | ------ | ------------ |
| `TYPE_FAIRY` constant | `include/constants/pokemon.h` (`= 19`) | Type id exists in the engine |
| Fairy row/column in `gTypeEffectivenessTable` | `src/data/types_info.h` | Matchups (e.g. Dragon → Fairy immune; Fairy → Dragon 2×) |
| `gTypesInfo[TYPE_FAIRY]` | same file | Name, icons, pre-split damage category |
| `B_UPDATED_TYPE_MATCHUPS >= GEN_6` | `include/config/battle.h` | Gen-6+ chart tweaks that interact with Fairy/Steel/Ghost/Dark |
| `P_UPDATED_TYPES >= GEN_6` | `include/config/pokemon.h` | Species retypes: Clefairy line → Fairy; Jigglypuff → Normal/Fairy; Mr. Mime → Psychic/Fairy; etc. |

UI already knows Fairy (summary, dex, type icons). **S27** gates Gen-6 Fairy *species retypes* at runtime via `MfGetSpeciesType` / `MfRules_HasFairyTypes()` (ADR 0027). **S28** gates ME modern species typings and the Gen VI+ vs Improved type chart via the same helper / `MfGetTypeEffectivenessTable` (ADR 0028). Fairy chart rows and Fairy move types stay in both charts.

## Kanto spot-checks (expected under this baseline)

| Case | Expectation |
| ---- | ----------- |
| Clefairy / Clefable | Pure Fairy |
| Jigglypuff line | Normal / Fairy |
| Mr. Mime | Psychic / Fairy |
| Magnemite line | Electric / Steel (`P_UPDATED_TYPES >= GEN_2`) |
| Bite / Crunch | Dark + **physical** |
| Shadow Ball | Ghost + **special** |
| Dragon move vs Fairy | No effect |
| Fairy move vs Dragon | Super effective |

Automated lock: `test/modern_firered/mf_battle_baseline.c` (`make check`, filter `MF:`).

## Battle & overworld pace (S11)

Always-on QoL until Phase 10 Options+ (S61) exposes player toggles. See ADR 0011.

| Macro | File | Phase 1 value | Notes |
| ----- | ---- | ------------- | ----- |
| `B_FAST_INTRO_PKMN_TEXT` | `battle.h` | `TRUE` | Intro text overlaps send-out anim |
| `B_FAST_INTRO_NO_SLIDE` | `battle.h` | `TRUE` | Skip battle slide-in (ME Fast Intro) |
| `B_FAST_HP_DRAIN` / `B_FAST_EXP_GROW` | `battle.h` | `TRUE` | Faster bars |
| `B_WAIT_TIME_MULTIPLIER` | `battle.h` | `8` (vanilla `16`) | Shorter battle text pauses |
| `TEXT_SPEED_INSTANT` | `text.h` | `FALSE` | Options menu still owns text speed |
| `OW_RUNNING_INDOORS` | `overworld.h` | `GEN_LATEST` | Gen4+ indoor run (already default) |
| `OW_POISON_DAMAGE` | `overworld.h` | `GEN_LATEST` | Gen5+ no OW poison damage; S34 Gamemode toggle |

Config lock: `test/modern_firered/mf_speed_baseline.c`. Manual: [`manual-qa-s11-battle-ow-speed.md`](./manual-qa-s11-battle-ow-speed.md).

## After an upstream merge

If `include/config/battle.h` or `pokemon.h` conflicts, take RHH’s file then confirm the macros above still resolve to `GEN_LATEST` / the thresholds in this doc. Re-run `make check` — the MF battle-baseline tests should catch regressions.
