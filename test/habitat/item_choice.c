#include "global.h"
#include "habitat/item_choice.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "item.h"
#include "test/test.h"

#define TEST_SPOT_ID 10
#define TEST_PLACE_COUNTER 20

static const struct HabitatCondition sAppear[] = {
    HABITAT_COND(COND_ITEM_PLACED, ITEM_POKE_DOLL, 3, TEST_PLACE_COUNTER, 0),
    HABITAT_CONDITIONS_END,
};

static const struct HabitatCondition sBefriend[] = {
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_POKE_DOLL, 2, 0, HABITAT_COND_OR_GROUP(1)),
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_POTION, 2, 0, HABITAT_COND_OR_GROUP(1)),
    HABITAT_CONDITIONS_END,
};

static const struct HabitatSpot sSpot = {
    .spotId = TEST_SPOT_ID,
    .species = SPECIES_SKITTY,
    .appearConditions = sAppear,
    .befriendConditions = sBefriend,
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
    AddBagItem(ITEM_POTION, 2);
    EXPECT(Habitat_FindConditionItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, &choice));
    EXPECT_EQ(choice.itemId, ITEM_POTION);
    EXPECT_EQ(choice.count, 2);
    EXPECT(Habitat_CanSubmitItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, ITEM_POTION, 2));
    EXPECT(!Habitat_CanSubmitItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, ITEM_POTION, 1));
}

TEST("Habitat item choice: submission consumes exactly the authored placement quantity")
{
    Habitat_SetSpotTableForTest(sSpots);
    AddBagItem(ITEM_POKE_DOLL, 3);
    EXPECT(Habitat_SubmitItem(&sSpot, HABITAT_ITEM_ACTION_PLACE, ITEM_POKE_DOLL, 3));
    EXPECT(!CheckBagHasItem(ITEM_POKE_DOLL, 1));
    EXPECT_EQ(Habitat_GetPlacedCount(TEST_PLACE_COUNTER), 3);
    EXPECT_EQ(Habitat_GetSpotState(TEST_SPOT_ID), HABITAT_STATE_ACTIVE);
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
    EXPECT_EQ(Habitat_GetAvailableVerbs(&sSpot),
              HABITAT_VERB_INSPECT | HABITAT_VERB_OFFER);

    AddBagItem(ITEM_POTION, 2);
    EXPECT(Habitat_SubmitItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, ITEM_POTION, 2));
    EXPECT(!CheckBagHasItem(ITEM_POTION, 1));
    EXPECT(!Habitat_CanSubmitItem(&sSpot, HABITAT_ITEM_ACTION_OFFER, ITEM_POTION, 2));
    EXPECT_EQ(Habitat_GetAvailableVerbs(&sSpot),
              HABITAT_VERB_INSPECT | HABITAT_VERB_RECRUIT);
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
