#include "global.h"
#include "test/test.h"
#include "config/item.h"
#include "item.h"
#include "item_use.h"
#include "constants/items.h"
#include "constants/pokemon.h"

// S10: lock Phase 1 item QoL baseline (reusable TMs, Gen5 Exp Share, Gen4+ Sitrus).
// Shared Emerald TESTELF path — same item configs as the FireRed ROM.
// TM reuse / mint use in-game: docs-mf/manual-qa-s10-item-qol.md

TEST("MF: item QoL configs — reusable TMs, held Exp Share, Gen4+ Sitrus")
{
    EXPECT(I_REUSABLE_TMS);
    EXPECT_EQ(I_EXP_SHARE_FLAG, 0);
    EXPECT(I_EXP_SHARE_ITEM < GEN_6);
    EXPECT(I_SITRUS_BERRY_HEAL >= GEN_4);
}

// S69: PLA-style bag use for trade-held evo items (Metal Coat, Electirizer, …).
TEST("MF: item evo held items usable from bag (solo trade evolutions)")
{
    EXPECT(I_USE_EVO_HELD_ITEMS_FROM_BAG);
    EXPECT_EQ(GetItemType(ITEM_METAL_COAT), ITEM_USE_PARTY_MENU);
    EXPECT_EQ(GetItemType(ITEM_KINGS_ROCK), ITEM_USE_PARTY_MENU);
    EXPECT_EQ(GetItemType(ITEM_DRAGON_SCALE), ITEM_USE_PARTY_MENU);
    EXPECT_EQ(GetItemType(ITEM_UPGRADE), ITEM_USE_PARTY_MENU);
    EXPECT_EQ(GetItemType(ITEM_ELECTIRIZER), ITEM_USE_PARTY_MENU);
    EXPECT_EQ(GetItemFieldFunc(ITEM_METAL_COAT), ItemUseOutOfBattle_EvolutionStone);
    EXPECT_EQ(GetItemFieldFunc(ITEM_LINKING_CORD), ItemUseOutOfBattle_EvolutionStone);
    EXPECT_EQ(GetItemType(ITEM_LINKING_CORD), ITEM_USE_PARTY_MENU);
}

TEST("MF: item sample TMs are marked important (reusable)")
{
    EXPECT(GetItemImportance(ITEM_TM01));
    EXPECT(GetItemImportance(ITEM_TM05));
    EXPECT(GetItemImportance(ITEM_TM28));
}

TEST("MF: item nature mints exist and map to natures")
{
    EXPECT_EQ(gItemsInfo[ITEM_ADAMANT_MINT].secondaryId, NATURE_ADAMANT);
    EXPECT_EQ(gItemsInfo[ITEM_MODEST_MINT].secondaryId, NATURE_MODEST);
    EXPECT_EQ(gItemsInfo[ITEM_JOLLY_MINT].secondaryId, NATURE_JOLLY);
    EXPECT_EQ(gItemsInfo[ITEM_SERIOUS_MINT].secondaryId, NATURE_SERIOUS);
    EXPECT_EQ(GetItemPocket(ITEM_ADAMANT_MINT), POCKET_ITEMS);
}
