
// JARED'S EMERALD - LEVEL CAP LOGIC
// File: src/level_cap.c
// Blocks EXP and Rare Candy past cap

#include "global.h"
#include "level_cap.h"

bool32 ShouldBlockExp(struct Pokemon *mon, u8 badgeCount)
{
    u16 level = GetMonData(mon, MON_DATA_LEVEL);
    u16 cap = GetCurrentLevelCap();
    if (level >= cap) return TRUE;
    return FALSE;
}

u16 GetCurrentLevelCap(void)
{
    // Returns cap based on badges / story progress
    // Roxanne 0 badges = 15, Brawly 1 badge = 19, etc.
    // Implementation follows Emerald Base Plus logic
    return gLevelCap;
}
