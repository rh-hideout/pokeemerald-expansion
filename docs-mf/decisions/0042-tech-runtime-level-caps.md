# 0042 — Runtime Kanto level caps

- **Type:** tech
- **Status:** Accepted
- **Date:** 2026-09-30
- **Story:** S41
- **ME reference:** `GetCurrentPartyLevelCap` / `sLevelCapTable_Normal` / `sLevelCapTable_Hard` in `src/tx_randomizer_and_challenges.c`
- **Expansion config:** `B_EXP_CAP_TYPE` (`EXP_CAP_NONE`), `B_LEVEL_CAP_TYPE` (`LEVEL_CAP_NONE`), `B_LEVEL_CAP_VARIABLE` (0), `B_RARE_CANDY_CAP` (`FALSE`), `B_LEVEL_CAP_EXP_UP` (`FALSE`)

## Context

Expansion’s level-cap machinery in `src/caps.c` is compile-time. `B_EXP_CAP_TYPE` defaults to off, and `sLevelCapFlagMap` is Hoenn (first unset badge flag, one level column). FireRed’s Difficulty page already stores `levelCap` as Off / Normal / Hard: Normal is the next leader’s highest level, Hard is that leader’s lowest. Those configs cannot be flipped globally without capping Emerald and every rule-off save.

## Decision

1. **Leave the `include/config/caps.h` defaults unchanged.** When `levelCap` is Normal or Hard, `GetCurrentLevelCap` / `GetSoftLevelCapExpValue` / the battle exp clamp / Rare Candy and Exp Candy use `EXP_CAP_HARD`. When the rule is Off, those sites keep the compile-time behavior (no cap). `B_LEVEL_CAP_EXP_UP` stays `FALSE`; the boost only runs while a cap type is active.
2. **Badge count, not first-unset flag.** `MfGetPartyLevelCap` matches ME: count `FLAG_BADGE01_GET` through `FLAG_BADGE08_GET`, index a 9-row table (0 badges through 8). Value `3` in the 2-bit field does not bind.
3. **Kanto rows** come from first-clear parties in `src/data/trainers_frlg.party`, standard route Brock → Misty → Surge → Erika → Koga → Sabrina → Blaine → Giovanni → Champion Blue:

   | Badges | Next fight | Normal | Hard |
   | --- | --- | --- | --- |
   | 0 | Brock | 14 | 12 |
   | 1 | Misty | 21 | 18 |
   | 2 | Lt. Surge | 24 | 18 |
   | 3 | Erika | 29 | 24 |
   | 4 | Koga | 43 | 37 |
   | 5 | Sabrina | 43 | 37 |
   | 6 | Blaine | 47 | 40 |
   | 7 | Giovanni | 50 | 42 |
   | 8 | Champion | 63 | 57 |

   Koga and Sabrina are both 43 / 37, so those two gyms can be swapped with no cap change. Eight badges use Blue’s party (Alakazam 57 on every team, starter 63), the same way ME uses the champion for the 8-badge row rather than the first Elite Four member.
4. **Hall of Fame lifts the cap** via `FLAG_SYS_GAME_CLEAR` (`EnterHallOfFame`), returning `MAX_LEVEL` and restoring the compile-time exp-cap type. ME checks `FLAG_IS_CHAMPION`, which on FireRed is the Sevii network link, not the championship.
5. **No ME “caps and hard mode” bonus tables** (`sLevelCapTable_*_Caps_And_Hard_Mode`). Those add levels when Emerald’s `optionsDifficulty == 2` raises gym parties. FireRed has no such option. `HARD MODE EXP.` stays S42.

## Alternatives considered

- Flip `B_EXP_CAP_TYPE` to `EXP_CAP_HARD` and replace `sLevelCapFlagMap` with Kanto numbers — rejected; always-on for Emerald, one level column, and it ignores Off.
- First unset badge flag in gym order — rejected; Kanto’s late gyms are not strictly ordered, and ME keys off badge count. Koga/Sabrina share a row, so the usual swap is free.
- Per-Elite-Four caps after the 8th badge — rejected; ME keeps one champion cap until Hall of Fame.
- Cap lift on `FLAG_IS_CHAMPION` — rejected on FireRed; that flag is set when Celio links Hoenn, after the player is already champion.

## Consequences

- Hardcore’s seeded `levelCap = 1` (ADR 0040) now enforces the Normal table.
- Upstream touch: `caps.c` (rule check + exp-cap type), `battle_script_commands.c` (hard-clamp condition), `pokemon.c` and `party_menu.c` (Rare Candy / Exp Candy). Hoenn `sLevelCapFlagMap` is unchanged for a compile-time flag list.
- The rules inspector shows the live cap after LvlCap (`1/14` is Normal with no badges; `1/100` means the cap is lifted).
- Rare Candy at or above the cap does not fall through into a level evolution. A level 100 Pokémon can still evolve that way when the cap is not what blocked the candy.
- A battle exp line is printed only when that Pokémon’s reward is greater than 0. Someone else who earned exp, including via Exp. Share, still gets their own line.
- A player who fights Blaine before Koga is still on the Koga/Sabrina row until they have six badges.
- S42 multiplies exp after this clamp; it should not reopen levels past the cap.
