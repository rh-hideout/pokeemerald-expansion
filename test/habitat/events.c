#include "global.h"
#include "field_weather.h"
#include "event_data.h"
#include "habitat/events.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "pokemon.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/species.h"
#include "constants/weather.h"
#include "test/test.h"

#define SPOT_LOTAD 2
#define TEST_STORY_FLAG FLAG_UNUSED_0x020

static const struct HabitatCondition sStoryFlagCondition[] = {
    HABITAT_COND(COND_STORY_FLAG, TEST_STORY_FLAG, 0, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sFriendshipCondition[] = {
    HABITAT_COND(COND_PARTY_FRIENDSHIP, HABITAT_CMP_GE, 200, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sOfferBefriendConditions[] = {
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_ORAN_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const u8 sHint[] = _("test$");
static const struct HabitatSpot sDependencyTestSpots[] = {
    {
        .spotId = 10, .species = SPECIES_SKITTY, .tier = 1, .zoneId = 1,
        .appearConditions = sStoryFlagCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x021, .mapGroup = 1, .mapNum = 1, .localId = 1,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_STORY_FLAG) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 11, .species = SPECIES_LOTAD, .tier = 1, .zoneId = 1,
        .appearConditions = sFriendshipCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x022, .mapGroup = 1, .mapNum = 1, .localId = 2,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_PARTY) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    { .spotId = 0xFFFF },
};
static const struct HabitatMapSpan sDependencyTestSpans[] = {
    { .mapGroup = 1, .mapNum = 1, .firstSpot = 0, .count = 2 },
    { 0 },
};

static void UseDependencyTestTable(void)
{
    Habitat_SetSpotTableForTest(sDependencyTestSpots);
    Habitat_SetMapSpansForTest(sDependencyTestSpans);
    gSaveBlock1Ptr->location.mapGroup = 1;
    gSaveBlock1Ptr->location.mapNum = 1;
}

static void RestoreProductionTable(void)
{
    Habitat_SetMapSpansForTest(NULL);
    Habitat_SetSpotTableForTest(NULL);
}

TEST("Habitat event: delayed and no-delay weather changes immediately recompute dependent spots")
{
    const struct HabitatSpot *lotad;
    RestoreProductionTable();
    lotad = Habitat_GetSpot(SPOT_LOTAD);
    ASSUME(lotad != NULL);

    gSaveBlock1Ptr->location.mapGroup = lotad->mapGroup;
    gSaveBlock1Ptr->location.mapNum = lotad->mapNum;

    SetCurrentAndNextWeather(WEATHER_RAIN);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_LOTAD), HABITAT_STATE_STIRRING);

    // A no-delay transition follows the same notification path. The
    // monotonic state does not regress, but it must be safe and immediate.
    SetCurrentAndNextWeatherNoDelay(WEATHER_SUNNY);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_LOTAD), HABITAT_STATE_STIRRING);
}

TEST("Habitat event: dependency masks are the exact authored condition union")
{
    const struct HabitatSpot *lotad;
    u32 expected;

    RestoreProductionTable();
    lotad = Habitat_GetSpot(SPOT_LOTAD);

    ASSUME(lotad != NULL);
    expected = Habitat_GetConditionDependencyMask(lotad->appearConditions)
             | Habitat_GetConditionDependencyMask(lotad->befriendConditions);
    EXPECT_EQ(lotad->dependencyMask, expected);
}

TEST("Habitat event: changed flag and party mutation boundaries update only their dependents")
{
    u8 friendship = 255;

    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    UseDependencyTestTable();
    FlagClear(TEST_STORY_FLAG);
    Habitat_NotifyDependency(HABITAT_DEP_MAP);
    EXPECT_EQ(Habitat_GetSpotState(10), HABITAT_STATE_DORMANT);
    EXPECT_EQ(Habitat_GetSpotState(11), HABITAT_STATE_DORMANT);

    FlagSet(TEST_STORY_FLAG);
    EXPECT_EQ(Habitat_GetSpotState(10), HABITAT_STATE_ACTIVE);
    EXPECT_EQ(Habitat_GetSpotState(11), HABITAT_STATE_DORMANT);

    CreateMon(&gParties[B_TRAINER_PLAYER][0], SPECIES_SKITTY, 10, 0, OTID_STRUCT_PLAYER_ID);
    CalculatePlayerPartyCount();
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_FRIENDSHIP, &friendship);
    EXPECT_EQ(Habitat_GetSpotState(11), HABITAT_STATE_ACTIVE);
    RestoreProductionTable();
}
