#ifndef GUARD_MF_EXP_H
#define GUARD_MF_EXP_H

// S42 — battle EXP multiplier and HARD MODE EXP. See ADR 0044.
// Menu values match sChoicesExpMult: 0 ×1, 1 ×1.5, 2 ×2, 3 ×0.

#include "gba/types.h"

#define MF_EXP_MULT_1X  0
#define MF_EXP_MULT_15X 1
#define MF_EXP_MULT_2X  2
#define MF_EXP_MULT_0X  3

// Multiplier first, then the 60% hard factor when applyHardReduction is set.
// ×0 returns 0 and ignores the hard factor.
u32 MfResolveExpPool(u32 calculatedExp, u8 expMultiplier, bool8 applyHardReduction);

// hardExpNormal is the save bit (1 = Normal, full rate). hardDifficulty is
// expansion DIFFICULTY_HARD. Level Cap Hard is the player-facing stand-in.
bool8 MfIsHardExpReductionActive(u8 levelCapMode, bool8 hardExpNormal, bool8 hardDifficulty, bool8 gameClear);

// Live pool scale. Reads the rules, level cap, difficulty, and Hall of Fame.
u32 MfScaleCalculatedExp(u32 calculatedExp);

// TRUE for menu ×0. Call after ApplyExperienceMultipliers: scaled exp adds 1.
bool8 MfIsExpMultiplierZero(void);

#endif // GUARD_MF_EXP_H
