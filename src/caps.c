#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "caps.h"
#include "pokemon.h"
#include "save.h"

u32 GetNewGamePlusLevelOffset(void)
{
    u32 ngpRuns = gSaveBlock2Ptr->newGamePlus;

    if (ngpRuns > 0)
        return ngpRuns * 75;

    return 0;
}

u32 GetCurrentLevelCap(void)
{
    static const u32 sLevelCapFlagMap[][2] =
    {
        {FLAG_BEAT_RIVAL_ROUTE_103, 7},
        {FLAG_BEAT_FIRST_GRUNT, 10},
        {FLAG_BADGE01_GET, 15},
        {FLAG_BADGE02_GET, 19},
        {FLAG_BADGE03_GET, 24},
        {FLAG_BADGE04_GET, 29},
        {FLAG_BADGE05_GET, 31},
        {FLAG_BADGE06_GET, 36},
        {FLAG_RECEIVED_RED_OR_BLUE_ORB, 39},
        {FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS, 42},
        {FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 45},
        {FLAG_BADGE07_GET, 48},
        {FLAG_SPACE_CENTER_LEVEL_CAP, 50},
        {FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS, 54},
        {FLAG_BADGE08_GET, 58},
        {FLAG_IS_CHAMPION, 65},
        {FLAG_BEAT_CHAMPION_CHALLENGER_1, 66},
        {FLAG_BEAT_CHAMPION_CHALLENGER_2, 67},
        {FLAG_BEAT_CHAMPION_CHALLENGER_3, 68},
        {FLAG_BEAT_CHAMPION_CHALLENGER_4, 69},
        {FLAG_BEAT_CHAMPION_CHALLENGER_5, 70},
        {FLAG_BEAT_CHAMPION_CHALLENGER_6, 71},
        {FLAG_BEAT_CHAMPION_CHALLENGER_7, 72},
        {FLAG_BEAT_CHAMPION_CHALLENGER_8, 73},
        {FLAG_BEAT_CHAMPION_CHALLENGER_9, 74},
    };

    u32 i;

    // CUSTOM - CAP PLAYER (100) BELOW MAX LEVEL (1000)
    u32 playerLevelCap = 100 + GetNewGamePlusLevelOffset();

    if (playerLevelCap > MAX_LEVEL) {
        playerLevelCap = MAX_LEVEL;
    }

    // Check if level cap is disabled
    if (FlagGet(FLAG_LEVEL_CAP_OFF))
    {
        return playerLevelCap;
    }

    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (!FlagGet(sLevelCapFlagMap[i][0]))
            {
                u32 baseCap = sLevelCapFlagMap[i][1];
                baseCap += GetNewGamePlusLevelOffset();

                if (baseCap > MAX_LEVEL) {
                    return MAX_LEVEL;
                }

                return baseCap;
            }
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }

    return playerLevelCap;
}

u32 GetSoftLevelCapExpValue(u32 level, u32 expValue)
{
    static const u32 sExpScalingDown[5] = { 4, 8, 16, 32, 64 };
    static const u32 sExpScalingUp[5]   = { 16, 8, 4, 2, 1 };

    u32 levelDifference;
    u32 currentLevelCap = GetCurrentLevelCap();

    if (B_EXP_CAP_TYPE == EXP_CAP_NONE)
        return expValue;

    if (level < currentLevelCap)
    {
        if (B_LEVEL_CAP_EXP_UP)
        {
            levelDifference = currentLevelCap - level;
            if (levelDifference > ARRAY_COUNT(sExpScalingUp) - 1)
                return expValue + (expValue / sExpScalingUp[ARRAY_COUNT(sExpScalingUp) - 1]);
            else
                return expValue + (expValue / sExpScalingUp[levelDifference]);
        }
        else
        {
            return expValue;
        }
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_HARD)
    {
        return 0;
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_SOFT)
    {
        levelDifference = level - currentLevelCap;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown) - 1)
            return expValue / sExpScalingDown[ARRAY_COUNT(sExpScalingDown) - 1];
        else
            return expValue / sExpScalingDown[levelDifference];
    }
    else
    {
       return expValue;
    }
}

u32 GetCurrentEVCap(void)
{
    static const u16 sEvCapFlagMap[][2] = {
        // Define EV caps for each milestone
        {FLAG_BADGE01_GET, 30},
        {FLAG_BADGE02_GET, 60},
        {FLAG_BADGE03_GET, 90},
        {FLAG_BADGE04_GET, 120},
        {FLAG_BADGE05_GET, 150},
        {FLAG_BADGE06_GET, 200},
        {FLAG_BADGE07_GET, 240},
        {FLAG_BADGE08_GET, 300},
        {FLAG_IS_CHAMPION, MAX_TOTAL_EVS},
    };

    if (gSaveBlock2Ptr->newGamePlus > 0)
        return MAX_TOTAL_EVS;

    if (FlagGet(FLAG_LEVEL_CAP_OFF)) {
        return MAX_TOTAL_EVS;
    }

    if (B_EV_CAP_TYPE == EV_CAP_FLAG_LIST)
    {
        for (u32 evCap = 0; evCap < ARRAY_COUNT(sEvCapFlagMap); evCap++)
        {
            if (!FlagGet(sEvCapFlagMap[evCap][0]))
                return sEvCapFlagMap[evCap][1];
        }
    }
    else if (B_EV_CAP_TYPE == EV_CAP_VARIABLE)
    {
        return VarGet(B_EV_CAP_VARIABLE);
    }
    else if (B_EV_CAP_TYPE == EV_CAP_NO_GAIN)
    {
        return 0;
    }

    return MAX_TOTAL_EVS;
}
