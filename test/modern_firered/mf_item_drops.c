#include "global.h"
#include "mf_item_drops.h"
#include "constants/battle.h"
#include "constants/items.h"
#include "test/test.h"

TEST("MF: wild item drop selection respects feature flag and held item")
{
    EXPECT_EQ(MfSelectWildItemDrop(ITEM_ORAN_BERRY, TRUE), ITEM_ORAN_BERRY);
    EXPECT_EQ(MfSelectWildItemDrop(ITEM_ORAN_BERRY, FALSE), ITEM_NONE);
    EXPECT_EQ(MfSelectWildItemDrop(ITEM_NONE, TRUE), ITEM_NONE);
    EXPECT_EQ(MfSelectWildItemDrop(ITEM_NONE, FALSE), ITEM_NONE);
    EXPECT_EQ(MfSelectWildItemDrop(ITEM_NUGGET, TRUE), ITEM_NUGGET);
}

TEST("MF: wild item drops only allowed in normal wild battles")
{
    EXPECT(MfWildBattleAllowsItemDrops(0));
    EXPECT(MfWildBattleAllowsItemDrops(BATTLE_TYPE_DOUBLE));

    EXPECT(!MfWildBattleAllowsItemDrops(BATTLE_TYPE_TRAINER));
    EXPECT(!MfWildBattleAllowsItemDrops(BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE));
    EXPECT(!MfWildBattleAllowsItemDrops(BATTLE_TYPE_FIRST_BATTLE));
    EXPECT(!MfWildBattleAllowsItemDrops(BATTLE_TYPE_SAFARI));
    EXPECT(!MfWildBattleAllowsItemDrops(BATTLE_TYPE_GHOST));
    EXPECT(!MfWildBattleAllowsItemDrops(BATTLE_TYPE_LINK));
    EXPECT(!MfWildBattleAllowsItemDrops(BATTLE_TYPE_FRONTIER));
}
