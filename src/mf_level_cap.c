#include "global.h"
#include "caps.h"
#include "event_data.h"
#include "mf_level_cap.h"
#include "mf_rules.h"

// Standard Kanto route, first-clear parties in src/data/trainers_frlg.party.
// Normal = next leader's highest level. Hard = that leader's lowest level.
// 0 Brock, 1 Misty, 2 Lt. Surge, 3 Erika, 4 Koga, 5 Sabrina,
// 6 Blaine, 7 Giovanni, 8 Champion (all three Blue teams: Alakazam 57, starter 63).
// Koga and Sabrina are both 43 / 37, so swapping those two gyms does not change the cap.
static const u8 sLevelCapNormal[MF_LEVEL_CAP_BADGE_STAGES] =
{
    14, 21, 24, 29, 43, 43, 47, 50, 63,
};

static const u8 sLevelCapHard[MF_LEVEL_CAP_BADGE_STAGES] =
{
    12, 18, 18, 24, 37, 37, 40, 42, 57,
};

u8 MfResolvePartyLevelCap(u8 levelCapMode, u8 badgeCount, bool8 gameClear)
{
    const u8 *table;

    if (levelCapMode == MF_LEVEL_CAP_NORMAL)
        table = sLevelCapNormal;
    else if (levelCapMode == MF_LEVEL_CAP_HARD)
        table = sLevelCapHard;
    else
        return MAX_LEVEL;

    if (gameClear)
        return MAX_LEVEL;

    if (badgeCount >= MF_LEVEL_CAP_BADGE_STAGES)
        badgeCount = MF_LEVEL_CAP_BADGE_STAGES - 1;

    return table[badgeCount];
}

static u8 MfCountBadges(void)
{
    u8 count = 0;
    u32 flag;

    for (flag = FLAG_BADGE01_GET; flag < FLAG_BADGE01_GET + NUM_BADGES; flag++)
    {
        if (FlagGet(flag))
            count++;
    }
    return count;
}

u8 MfGetPartyLevelCap(void)
{
    return MfResolvePartyLevelCap(MfRules_GetLevelCap(), MfCountBadges(), FlagGet(FLAG_SYS_GAME_CLEAR));
}

bool8 MfIsPartyLevelCapEnabled(void)
{
    u8 mode = MfRules_GetLevelCap();

    return mode == MF_LEVEL_CAP_NORMAL || mode == MF_LEVEL_CAP_HARD;
}

u32 MfGetEffectiveExpCapType(void)
{
    // Hall of Fame lifts the cap, so postgame uses the compile-time setting again.
    if (MfIsPartyLevelCapEnabled() && !FlagGet(FLAG_SYS_GAME_CLEAR))
        return EXP_CAP_HARD;
    return B_EXP_CAP_TYPE;
}

bool8 MfShouldClampExpItemsToLevelCap(void)
{
    if (MfGetEffectiveExpCapType() != EXP_CAP_HARD)
        return FALSE;
    // Compile-time rare-candy cap, or a player level-cap rule (which implies it).
    return B_RARE_CANDY_CAP || MfIsPartyLevelCapEnabled();
}

bool8 MfIsRareCandyBlockedByLevelCap(u8 level)
{
    if (!MfShouldClampExpItemsToLevelCap())
        return FALSE;
    return level >= GetCurrentLevelCap();
}
