#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "caps.h"
#include "pokemon.h"


u32 GetCurrentLevelCap(void)
{
    static const u32 sLevelCapFlagMap[][2] =
    {
        {FLAG_ROUTE102_CLEAR, 7},
        {FLAG_ROUTE104_PART1_CLEAR, 9},
        {FLAG_PB_WOODS_CLEAR, 10},
        {FLAG_ROUTE104_PART2_CLEAR, 12},
        {FLAG_ROUTE116_CLEAR, 14},
        {FLAG_BADGE01_GET, 16},
        {FLAG_RUSTBORO_RIVAL, 17},
        {FLAG_ROUTE106_CLEAR, 19},
        {FLAG_BADGE02_GET, 21},
        {FLAG_SLATEPORT_GRUNT, 23},
        {FLAG_ROUTE110_CLEAR, 26},
        {FLAG_ROUTE110_RIVAL, 28},
        {FLAG_MAUVILLE_WALLY, 30},
        {FLAG_ROUTE117_CLEAR, 31},
        {FLAG_BADGE03_GET, 34},
        {FLAG_ROUTE111_CLEAR, 38},
        {FLAG_ROUTE112_CLEAR, 40},
        {FLAG_MT_CHIMNEY_CLEAR, 42},
        {FLAG_ROUTE113_CLEAR, 44},
        {FLAG_ROUTE114_CLEAR, 45},
        {FLAG_DESERT_CLEAR, 46},
        {FLAG_METEOR_FALLS_CLEAR, 47},
        {FLAG_BADGE04_GET, 49},
        {FLAG_MEGA_RING_CLEAR, 51},
        {FLAG_BADGE05_GET, 52},
        {FLAG_ROUTE118_CLEAR, 55},
        {FLAG_ROUTE119_CLEAR, 56},
        {FLAG_WEATHER_INST_CLEAR, 57},
        {FLAG_ROUTE120_CLEAR, 59},
        {FLAG_BADGE06_GET, 60},
        {FLAG_ROUTE121_CLEAR, 62},    
        {FLAG_MT_PYRE_CLEAR, 63},
        {FLAG_ROUTE123_CLEAR, 64},
        {FLAG_MAGMA_HIDEOUT_CLEAR, 65},
        {FLAG_ROUTE124_CLEAR, 67},
        {FLAG_AQUA_HIDEOUT_CLEAR, 69},
        {FLAG_BADGE07_GET, 71},
        {FLAG_SPACE_CENTER_CLEAR, 72},
        {FLAG_SEA_CAVERN_CLEAR, 73},
        {FLAG_SHOAL_CAVE_CLEAR, 74},
        {FLAG_SKY_PILLAR_CLEAR, 75},
        {FLAG_SOOTOPOLIS_RIVAL, 76},
        {FLAG_ABANDONED_SHIP_CLEAR, 78},
        {FLAG_BADGE08_GET, 80},
        {FLAG_EVERGRANDE_RIVAL, 82},
        {FLAG_VICTORY_ROAD_WALLY, 83},
        {FLAG_VICTORY_ROAD_CLEAR, 84},
        {FLAG_IS_CHAMPION, 86},
    };

    u32 i;

    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (!FlagGet(sLevelCapFlagMap[i][0]))
                return sLevelCapFlagMap[i][1];
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }

    return MAX_LEVEL;
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
        {FLAG_BADGE01_GET, MAX_TOTAL_EVS *  1 / 17},
        {FLAG_BADGE02_GET, MAX_TOTAL_EVS *  3 / 17},
        {FLAG_BADGE03_GET, MAX_TOTAL_EVS *  5 / 17},
        {FLAG_BADGE04_GET, MAX_TOTAL_EVS *  7 / 17},
        {FLAG_BADGE05_GET, MAX_TOTAL_EVS *  9 / 17},
        {FLAG_BADGE06_GET, MAX_TOTAL_EVS * 11 / 17},
        {FLAG_BADGE07_GET, MAX_TOTAL_EVS * 13 / 17},
        {FLAG_BADGE08_GET, MAX_TOTAL_EVS * 15 / 17},
        {FLAG_IS_CHAMPION, MAX_TOTAL_EVS},
    };

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
