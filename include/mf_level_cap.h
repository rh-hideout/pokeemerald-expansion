#ifndef GUARD_MF_LEVEL_CAP_H
#define GUARD_MF_LEVEL_CAP_H

// S41 — runtime level caps (Difficulty LEVEL CAP).
// ME: GetCurrentPartyLevelCap() in src/tx_randomizer_and_challenges.c.
// Off / Normal / Hard are menu values 0 / 1 / 2. See ADR 0042.

#include "gba/types.h"

#define MF_LEVEL_CAP_OFF    0
#define MF_LEVEL_CAP_NORMAL 1
#define MF_LEVEL_CAP_HARD   2
// Badge counts 0..8 (no badges through all eight, pre-champion).
#define MF_LEVEL_CAP_BADGE_STAGES 9

// Pure lookup. gameClear lifts the cap (Hall of Fame). badgeCount above 8 uses the 8-badge row.
u8 MfResolvePartyLevelCap(u8 levelCapMode, u8 badgeCount, bool8 gameClear);

// Live ME GetCurrentPartyLevelCap. Off and post-game-clear return MAX_LEVEL.
u8 MfGetPartyLevelCap(void);

// TRUE only for menu Normal (1) and Hard (2).
bool8 MfIsPartyLevelCapEnabled(void);

// Player rule forces EXP_CAP_HARD. Otherwise the compile-time B_EXP_CAP_TYPE.
u32 MfGetEffectiveExpCapType(void);

// Exp candies clamp to the cap when a hard cap is active (rule or B_RARE_CANDY_CAP).
bool8 MfShouldClampExpItemsToLevelCap(void);

// Rare Candy is refused at or above the active hard cap.
bool8 MfIsRareCandyBlockedByLevelCap(u8 level);

#endif // GUARD_MF_LEVEL_CAP_H
