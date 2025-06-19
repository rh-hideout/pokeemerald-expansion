#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "item.h"
#include "pokemon.h"
#include "test/overworld_script.h"
#include "test/test.h"

TEST("TMs and HMs are sorted correctly in the bag")
{
    RUN_OVERWORLD_SCRIPT(
        additem ITEM_HM07;
        additem ITEM_TM25;
        additem ITEM_TM14;
        additem ITEM_TM42;
        additem ITEM_HM05;
        additem ITEM_TM05;
        additem ITEM_TM01;
        additem ITEM_HM02;
    );

    struct BagPocket *pocket = &gBagPockets[POCKET_TM_HM];
    SortBerriesOrTMHMs(POCKET_TM_HM);

    EXPECT_EQ(pocket->itemSlots[0].itemId, ITEM_TM01);
    EXPECT_EQ(pocket->itemSlots[1].itemId, ITEM_TM05);
    EXPECT_EQ(pocket->itemSlots[2].itemId, ITEM_TM14);
    EXPECT_EQ(pocket->itemSlots[3].itemId, ITEM_TM25);
    EXPECT_EQ(pocket->itemSlots[4].itemId, ITEM_TM42);
    EXPECT_EQ(pocket->itemSlots[5].itemId, ITEM_HM02);
    EXPECT_EQ(pocket->itemSlots[6].itemId, ITEM_HM05);
    EXPECT_EQ(pocket->itemSlots[7].itemId, ITEM_HM07);
    EXPECT_EQ(pocket->itemSlots[8].itemId, ITEM_NONE);
}