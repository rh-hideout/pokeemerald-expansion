#include "global.h"
#include "battle_factory.h"
#include "battle_frontier.h"
#include "frontier_util.h"
#include "trainer_pools.h"
#include "test/test.h"
#include "constants/battle_frontier.h"
#include "constants/battle_frontier_mons.h"

static void ExpectFactoryPool(enum FrontierLevelMode lvlMode, u8 challengeNum, bool8 useBetterRange, u16 firstMonId, u16 lastMonId)
{
    const struct FrontierMonPool *pool = GetFactoryMonPool(lvlMode, challengeNum, useBetterRange);

    ASSUME(pool->monIds == NULL);
    EXPECT_EQ(GetTrainerMonPoolAt(pool, 0), firstMonId);
    EXPECT_EQ(GetTrainerMonPoolAt(pool, pool->size - 1), lastMonId);
    EXPECT_EQ(pool->size, lastMonId - firstMonId + 1);
}

TEST("battle factory pseudopools preserve vanilla level 50 rental ranges")
{
    ExpectFactoryPool(FRONTIER_LVL_50, 0, FALSE, FRONTIER_MON_GRIMER,     FRONTIER_MON_FURRET_1);
    ExpectFactoryPool(FRONTIER_LVL_50, 1, FALSE, FRONTIER_MON_DELCATTY_1, FRONTIER_MON_CLOYSTER_1);
    ExpectFactoryPool(FRONTIER_LVL_50, 2, FALSE, FRONTIER_MON_DELCATTY_2, FRONTIER_MON_CLOYSTER_2);
    ExpectFactoryPool(FRONTIER_LVL_50, 3, FALSE, FRONTIER_MON_DUGTRIO_1,  FRONTIER_MON_SLAKING_1);
    ExpectFactoryPool(FRONTIER_LVL_50, 4, FALSE, FRONTIER_MON_DUGTRIO_2,  FRONTIER_MON_SLAKING_2);
    ExpectFactoryPool(FRONTIER_LVL_50, 5, FALSE, FRONTIER_MON_DUGTRIO_3,  FRONTIER_MON_SLAKING_3);
    ExpectFactoryPool(FRONTIER_LVL_50, 6, FALSE, FRONTIER_MON_DUGTRIO_4,  FRONTIER_MON_SLAKING_4);
    ExpectFactoryPool(FRONTIER_LVL_50, 7, FALSE, FRONTIER_MON_DUGTRIO_1,  FRONTIER_MON_LATIOS_8);
    ExpectFactoryPool(FRONTIER_LVL_50, 8, FALSE, FRONTIER_MON_DUGTRIO_1,  FRONTIER_MON_LATIOS_8);
}

TEST("battle factory pseudopools preserve vanilla open level rental ranges")
{
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 0, FALSE, FRONTIER_MON_DUGTRIO_1, FRONTIER_MON_SLAKING_1);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 1, FALSE, FRONTIER_MON_DUGTRIO_2, FRONTIER_MON_SLAKING_2);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 2, FALSE, FRONTIER_MON_DUGTRIO_3, FRONTIER_MON_SLAKING_3);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 3, FALSE, FRONTIER_MON_DUGTRIO_4, FRONTIER_MON_SLAKING_4);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 4, FALSE, FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 5, FALSE, FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 6, FALSE, FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 7, FALSE, FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 8, FALSE, FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1);
}

TEST("battle factory pseudopools preserve vanilla better range advancement")
{
    ExpectFactoryPool(FRONTIER_LVL_50, 0, TRUE, FRONTIER_MON_DELCATTY_1, FRONTIER_MON_CLOYSTER_1);
    ExpectFactoryPool(FRONTIER_LVL_50, 6, TRUE, FRONTIER_MON_DUGTRIO_1,  FRONTIER_MON_LATIOS_8);
    ExpectFactoryPool(FRONTIER_LVL_50, 7, TRUE, FRONTIER_MON_DUGTRIO_1,  FRONTIER_MON_LATIOS_8);
    ExpectFactoryPool(FRONTIER_LVL_50, 8, TRUE, FRONTIER_MON_DUGTRIO_1,  FRONTIER_MON_LATIOS_8);

    ExpectFactoryPool(FRONTIER_LVL_OPEN, 0, TRUE, FRONTIER_MON_DUGTRIO_2, FRONTIER_MON_SLAKING_2);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 3, TRUE, FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 6, TRUE, FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 7, TRUE, FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1);
    ExpectFactoryPool(FRONTIER_LVL_OPEN, 8, TRUE, FRONTIER_MON_DUGTRIO_1, NUM_FRONTIER_MONS - 1);
}
