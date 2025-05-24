#include "global.h"
#include "battle.h"
#include "item.h"
#include "event_data.h"
#include "test/overworld_script.h"
#include "test/test.h"
#include "constants/vars.h"

// TEST("TMs / HMs are sorted correctly in the bag")
// {
//     SetBagItemsPointers();

//     RUN_OVERWORLD_SCRIPT(
//         giveitem ITEM_HM07;
//         giveitem ITEM_TM25;
//         giveitem ITEM_TM14;
//         giveitem ITEM_TM42;
//         giveitem ITEM_HM05;
//         giveitem ITEM_TM05;
//         giveitem ITEM_TM01;
//         giveitem ITEM_HM02;
//     );

//     struct BagPocket *pocket = &gBagPockets[TMHM_POCKET];

//     EXPECT_EQ(pocket->itemSlots[0].itemId, ITEM_TM01);
//     EXPECT_EQ(pocket->itemSlots[1].itemId, ITEM_TM05);
//     EXPECT_EQ(pocket->itemSlots[2].itemId, ITEM_TM14);
//     EXPECT_EQ(pocket->itemSlots[3].itemId, ITEM_TM25);
//     EXPECT_EQ(pocket->itemSlots[4].itemId, ITEM_TM42);
//     EXPECT_EQ(pocket->itemSlots[5].itemId, ITEM_HM02);
//     EXPECT_EQ(pocket->itemSlots[6].itemId, ITEM_HM05);
//     EXPECT_EQ(pocket->itemSlots[7].itemId, ITEM_HM07);
// }
