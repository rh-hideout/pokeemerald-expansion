# 0044 — EXP multiplier and hard-mode EXP

- **Type:** product
- **Status:** Accepted
- **Date:** 2026-10-01
- **Story:** S42
- **ME reference:** `tx_Challenges_ExpMultiplier` / `tx_Difficulty_HardExp` in `src/battle_script_commands.c` (`calculatedExp *= 0.60` when `optionsDifficulty == 2`); `TX_EXP_MULTIPLER_ONLY_ON_NUZLOCKE_AND_RANDOMIZER` in `include/tx_randomizer_and_challenges.h`
- **Expansion config:** `B_TRAINER_EXP_MULTIPLIER`, `B_SPLIT_EXP`, `B_SCALED_EXP` (all `GEN_LATEST` / Gen 9). `B_VAR_DIFFICULTY` stays `0`.

## Context

The Difficulty page already stores `expMultiplier` (×1 / ×1.5 / ×2 / ×0) and `hardExp` (Default / Normal). ME applies the multiplier to the exp pool, then, only while options Hard is selected, multiplies by 0.60 unless the player picks Normal or has become champion. FireRed has no player-facing Easy/Normal/Hard difficulty (`B_VAR_DIFFICULTY` is 0; ADR 0042). ME’s compile flag that limits the multiplier to Nuzlocke or randomizer runs is `FALSE`.

## Decision

1. **The multiplier always applies.** It is not gated on Nuzlocke or the randomizer. Menu values are ×1, ×3/2, ×2, and 0. Integer math. ×0 returns 0 and is applied again after `ApplyExperienceMultipliers`, because Gen 5+ scaled exp adds 1 to a zero reward.
2. **It scales the shared pool** after the species yield divisor and `B_TRAINER_EXP_MULTIPLIER`, and before `B_SPLIT_EXP`. Lucky Egg, Exp. Charm, affection, the traded bonus, and `B_SCALED_EXP` still run per Pokémon. The S41 hard level-cap clamp stays last, so ×2 cannot pass the cap and the 60% cut can still reach it.
3. **HARD MODE EXP is ME’s 60% Hard factor** (`* 3 / 5`), after the multiplier. Default (`hardExp == 0`) applies it. Normal (`hardExp == 1`) does not. **Hall of Fame** (`FLAG_SYS_GAME_CLEAR`) turns it off. `FLAG_IS_CHAMPION` is the Sevii link on FireRed (ADR 0042).
4. **“Hard” is Level Cap Hard**, the only Hard the Difficulty page can select. Expansion `DIFFICULTY_HARD` also counts, if something later sets `B_VAR_DIFFICULTY`. The two do not stack. Level Cap Off or Normal leaves this row idle, so a default save (both fields 0) keeps full exp.
5. **Not ported from ME Hard/Easy:** Easy’s ×1.3, the traded-mon bonus skip, and the harsher Exp. Share split. Those key off `optionsDifficulty`, not this row. `B_SPLIT_EXP` stays Gen 9 (full exp to participants).
6. **Menu copy** for this row names the Hard level cap. Labels stay Default / Normal (ADR 0023).

## Alternatives considered

- Always-on 60% at `hardExp == 0` — rejected. That bit is already 0 on every save, so every run would slow down. ME only nerfs Hard, to offset higher trainer levels we do not have.
- Flip the default bit to 1 and make Default an always-on 60% — rejected. It redefines the zero value and would still cut any save that never touched the row.
- Wait for a real Hard difficulty — rejected. The row would do nothing, and no story adds Easy/Normal/Hard.
- Gate the multiplier on Nuzlocke or the randomizer — rejected. ME’s flag is off, and the page does not say the multiplier is conditional.
- Apply ×2 after the level-cap clamp — rejected. That reopens the cap unless a second clamp is added. Scaling the pool first keeps S41’s clamp as the ceiling.

## Consequences

- Choosing Level Cap Hard with HARD MODE EXP still on Default cuts battle exp to 60% until Hall of Fame, or until the player sets the row to Normal. The hard ceiling itself is unchanged.
- A default Modern/Classic save is still ×1 and uncapped, so exp matches the Gen 9 pool (no trainer ×1.5, no party split, scaled by level).
- Upstream touch: `battle_script_commands.c` (pool scale, and a ×0 clear after the per-mon multipliers).
- Daycare, Exp. Candy, and Rare Candy are not multiplied.
