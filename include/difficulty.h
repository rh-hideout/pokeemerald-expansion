#ifndef GUARD_DIFFICULTY_H
#define GUARD_DIFFICULTY_H

#include "constants/difficulty.h"

u32 GetCurrentDifficultyLevel(void);
u32 GetBattlePartnerDifficultyLevel(u16);
u32 GetTrainerDifficultyLevel(u16);
void Script_IncreaseDifficulty(void);
void Script_DecreaseDifficulty(void);
void Script_SetDifficulty(u32);

#endif // GUARD_DIFFICULTY_H
