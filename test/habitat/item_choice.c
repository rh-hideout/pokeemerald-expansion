#include "global.h"
#include "event_data.h"
#include "habitat/item_choice.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "item.h"
#include "item_menu.h"
#include "test/test.h"

#define TEST_SPOT_ID 10
#define TEST_PLACE_COUNTER 20
#define TEST_SATURATED_COUNTER 21
#define TEST_OFFER_FLAG FLAG_UNUSED_0x022

static const struct HabitatCondition sAppear[] = {
    HABITAT_COND(COND_ITEM_PLACED, ITEM_POKE_DOLL, 3, TEST_PLACE_COUNTER, 0),
    HABITAT_CONDITIONS_END,
};

static const struct HabitatCondition sBefriend[] = {
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_POKE_DOLL, 2, 0, HABITAT_COND_OR_GROUP(1)),
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_POTION, 2, 0, HABITAT_COND_OR_GROUP(1)),
    HABITAT_CONDITIONS_END,
};

static const struct HabitatCondition sSaturatedAppear[] = {
    HABITAT_COND(COND_ITEM_PLACED, ITEM_POKE_DOLL, 15, TEST_SATURATED_COUNTER, 0),
    HABITAT_CONDITIONS_END,
};

static const struct HabitatCondition sEmptyAppear[] = {
    HABITAT_CONDITIONS_END,
};

static const struct HabitatCondition sBlockedBefriend[] = {
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_POTION, 2, 0, 0),
    HABITAT_COND(COND_STORY_FLAG, TEST_OFFER_FLAG, 0, 0, 0),
    HABITAT_CONDITIONS_END,
};

static const struct HabitatCondition sNoOfferBefriend[] = {
    HABITAT_COND(COND_STORY_FLAG, TEST_OFFER_FLAG, 0, 0, 0),
    HABITAT_CONDITIONS_END,
};

static const struct HabitatCondition sSameItemBefriend[] = {
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_POKE_DOLL, 1, 0, HABITAT_COND_OR_GROUP(1)),
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_POKE_DOLL, 3, 0, HABITAT_COND_OR_GROUP(1)),
    HABITAT_CONDITIONS_END,
};

static const struct HabitatSpot sSpot = {
    .spotId = TEST_SPOT_ID,
    .species = SPECIES_SKITTY,
    .appearConditions = sAppear,
    .befriendConditions = sBefriend,
};

static const struct HabitatSpot sSaturatedSpot = {
    .spotId = TEST_SPOT_ID,
    .species = SPECIES_SKITTY,
    .appearConditions = sSaturatedAppear,
    .befriendConditions = sBefriend,
};

static const struct HabitatSpot sBlockedOfferSpot = {
    .spotId = TEST_SPOT_ID,
    .species = SPECIES_SKITTY,
    .appearConditions = sEmptyAppear,
    .befriendConditions = sBlockedBefriend,
};

static const struct HabitatSpot sNoOfferSpot = {
    .spotId = TEST_SPOT_ID,
    .species = SPECIES_SKITTY,
    .appearConditions = sEmptyAppear,
    .befriendConditions = sNoOfferBefriend,
};

static const struct HabitatSpot sSpots[] = {
    {
        .spotId = TEST_SPOT_ID,
        .species = SPECIES_SKITTY,
        .appearConditions = sAppear,
        .befriendConditions = sBefriend,
    },
    { .spotId = 0xFFFF },
};

static const struct HabitatSpot sSameItemSpots[] = {
    {
        .spotId = TEST_SPOT_ID,
        .species = SPECIES_SKITTY,
        .appearConditions = sEmptyAppear,
        .befriendConditions = sSameItemBefriend,
    },
    { .spotId = 0xFFFF },
};

TEST("Habitat item choice: finds authored quantities in every bag pocket")
{
    struct HabitatItemChoice choice;

    AddBagItem(ITEM_POKE_DOLL, 3);
    EXPECT(Habitat_FindConditionItem(&sSpot, HABITAT_ITEM_ACTION_PLACE, &choice));
    EXPECT_EQ(choice.itemId, ITEM_POKE_DOLL);
    EXPECT_EQ(choice.count, 3);
}

TEST("Habitat item choice: non-berry OR offers are selectable at their authored count")
{
    struct HabitatItemChoice choice;

    Habitat_SetSpotState(TEST_SPOT_ID, HABITAT_STATE_ACTIVE);
    AddBagItem(ITEM_POKE_DOLL, 2);
    AddBagItem(ITEM_POTION, 2);
    EXPECT(Habitat_SelectConditionItem(&sSpot, HABITAT_ITEM_ACTION_OFFER,
                                       ITEM_POKE_DOLL, &choice));
    EXPECT_EQ(choice.itemId, ITEM_POKE_DOLL);
    EXPECT_EQ(choice.count, 2);
    EXPECT(Habitat_SelectConditionItem(&sSpot, HABITAT_ITEM_ACTION_OFFER,
                                       ITEM_POTION, &choice));
    EXPECT_EQ(choice.itemId, ITEM_POTION);
    EXPECT_EQ(choice.count, 2);
    EXPECT(Habitat_CanSubmitItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, ITEM_POTION, 2));
    EXPECT(!Habitat_CanSubmitItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, ITEM_POTION, 1));
}

TEST("Habitat item choice: placement failure restores the exact prior counter and inventory")
{
    Habitat_SetPlacedCount(TEST_SATURATED_COUNTER, 14);
    AddBagItem(ITEM_POKE_DOLL, 15);

    EXPECT(!Habitat_SubmitItem(&sSaturatedSpot, HABITAT_ITEM_ACTION_PLACE,
                               ITEM_POKE_DOLL, 15));
    EXPECT_EQ(Habitat_GetPlacedCount(TEST_SATURATED_COUNTER), 14);
    EXPECT(CheckBagHasItem(ITEM_POKE_DOLL, 15));
}

TEST("Habitat interaction: only fully viable offers expose the OFFER verb")
{
    Habitat_SetSpotState(TEST_SPOT_ID, HABITAT_STATE_ACTIVE);
    AddBagItem(ITEM_POTION, 2);
    FlagClear(TEST_OFFER_FLAG);
    EXPECT_EQ(Habitat_GetAvailableVerbs(&sBlockedOfferSpot), HABITAT_VERB_INSPECT);

    FlagSet(TEST_OFFER_FLAG);
    EXPECT_EQ(Habitat_GetAvailableVerbs(&sBlockedOfferSpot),
              HABITAT_VERB_INSPECT | HABITAT_VERB_OFFER);
}

TEST("Habitat interaction: OFFER requires a matching authored item want")
{
    Habitat_SetSpotState(TEST_SPOT_ID, HABITAT_STATE_ACTIVE);
    FlagSet(TEST_OFFER_FLAG);
    AddBagItem(ITEM_POTION, 2);

    EXPECT(!Habitat_CanSubmitItem(&sNoOfferSpot, HABITAT_ITEM_ACTION_OFFER,
                                  ITEM_POTION, 2));
    EXPECT_EQ(Habitat_GetAvailableVerbs(&sNoOfferSpot), HABITAT_VERB_INSPECT);
}

TEST("Habitat interaction: zero-argument verbs special resolves the current spot")
{
    const struct HabitatSpot *skitty = Habitat_GetSpot(1);
    ASSUME(skitty != NULL);
    gSaveBlock1Ptr->location.mapGroup = skitty->mapGroup;
    gSaveBlock1Ptr->location.mapNum = skitty->mapNum;
    gSpecialVar_LastTalked = skitty->localId;
    Habitat_OnInspectSpot();

    EXPECT_EQ(Habitat_GetInteractionAvailableVerbs(),
              Habitat_GetAvailableVerbs(skitty));
}

TEST("Habitat interaction: selector advances to and submits the chosen second OR offer")
{
    Habitat_SetSpotTableForTest(sSpots);
    Habitat_SetInteractionSpotForTest(TEST_SPOT_ID);
    Habitat_SetSpotState(TEST_SPOT_ID, HABITAT_STATE_ACTIVE);
    AddBagItem(ITEM_POKE_DOLL, 2);
    AddBagItem(ITEM_POTION, 2);

    EXPECT(Habitat_PreviewOfferItem());
    EXPECT_EQ(gSpecialVar_ItemId, ITEM_POKE_DOLL);
    EXPECT(Habitat_SelectOfferItem());
    EXPECT_EQ(gSpecialVar_ItemId, ITEM_POTION);
    EXPECT(CheckBagHasItem(ITEM_POKE_DOLL, 2));
    EXPECT(CheckBagHasItem(ITEM_POTION, 2));

    EXPECT(Habitat_TryOffer());
    EXPECT(CheckBagHasItem(ITEM_POKE_DOLL, 2));
    EXPECT(!CheckBagHasItem(ITEM_POTION, 1));
    Habitat_SetSpotTableForTest(NULL);
}

TEST("Habitat interaction: selector keeps same-item OR offers distinct by authored count")
{
    Habitat_SetSpotTableForTest(sSameItemSpots);
    Habitat_SetInteractionSpotForTest(TEST_SPOT_ID);
    Habitat_SetSpotState(TEST_SPOT_ID, HABITAT_STATE_ACTIVE);
    AddBagItem(ITEM_POKE_DOLL, 3);

    EXPECT(Habitat_PreviewOfferItem());
    EXPECT(Habitat_SelectOfferItem());
    EXPECT(Habitat_TryOffer());
    EXPECT(!CheckBagHasItem(ITEM_POKE_DOLL, 1));
    EXPECT_EQ(Habitat_GetSpotState(TEST_SPOT_ID), HABITAT_STATE_BEFRIENDED);
    Habitat_SetSpotTableForTest(NULL);
}

TEST("Habitat item choice: submission consumes exactly the authored placement quantity")
{
    Habitat_SetSpotTableForTest(sSpots);
    AddBagItem(ITEM_POKE_DOLL, 3);
    EXPECT(Habitat_SubmitItem(&sSpot, HABITAT_ITEM_ACTION_PLACE, ITEM_POKE_DOLL, 3));
    EXPECT(!CheckBagHasItem(ITEM_POKE_DOLL, 1));
    EXPECT_EQ(Habitat_GetPlacedCount(TEST_PLACE_COUNTER), 3);
    EXPECT_EQ(Habitat_GetSpotState(TEST_SPOT_ID), HABITAT_STATE_ACTIVE);
    Habitat_SetSpotTableForTest(NULL);
}

TEST("Habitat interaction: states expose only the relevant item and recruit actions")
{
    struct HabitatItemChoice choice;

    Habitat_SetSpotTableForTest(sSpots);
    EXPECT_EQ(Habitat_GetAvailableVerbs(&sSpot),
              HABITAT_VERB_INSPECT | HABITAT_VERB_PLACE);

    AddBagItem(ITEM_POKE_DOLL, 3);
    ASSUME(Habitat_SubmitItem(&sSpot, HABITAT_ITEM_ACTION_PLACE, ITEM_POKE_DOLL, 3));
    EXPECT(!Habitat_FindConditionItem(&sSpot, HABITAT_ITEM_ACTION_PLACE, &choice));
    EXPECT_EQ(Habitat_GetAvailableVerbs(&sSpot), HABITAT_VERB_INSPECT);

    AddBagItem(ITEM_POTION, 2);
    EXPECT_EQ(Habitat_GetAvailableVerbs(&sSpot),
              HABITAT_VERB_INSPECT | HABITAT_VERB_OFFER);
    EXPECT(Habitat_SubmitItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, ITEM_POTION, 2));
    EXPECT(!CheckBagHasItem(ITEM_POTION, 1));
    EXPECT(!Habitat_CanSubmitItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, ITEM_POTION, 2));
    EXPECT_EQ(Habitat_GetAvailableVerbs(&sSpot),
              HABITAT_VERB_INSPECT | HABITAT_VERB_RECRUIT);
    Habitat_SetSpotTableForTest(NULL);
}

TEST("Habitat item choice: cancelled, wrong, and insufficient offers do not remove items")
{
    Habitat_SetSpotState(TEST_SPOT_ID, HABITAT_STATE_ACTIVE);
    AddBagItem(ITEM_POTION, 1);
    AddBagItem(ITEM_ORAN_BERRY, 2);

    EXPECT(!Habitat_SubmitItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, ITEM_NONE, 0));
    EXPECT(!Habitat_SubmitItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, ITEM_ORAN_BERRY, 2));
    EXPECT(!Habitat_SubmitItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, ITEM_POTION, 2));
    EXPECT(CheckBagHasItem(ITEM_POTION, 1));
    EXPECT(CheckBagHasItem(ITEM_ORAN_BERRY, 2));
}
