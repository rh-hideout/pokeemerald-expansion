#include "global.h"
#include "field_weather.h"
#include "event_data.h"
#include "habitat/events.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "pokemon.h"
#include "pokedex.h"
#include "pokemon_storage_system.h"
#include "overworld.h"
#include "item.h"
#include "fake_rtc.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/game_stat.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
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
static const struct HabitatCondition sSpotStateCondition[] = {
    HABITAT_COND(COND_SPOT_STATE, 10, HABITAT_STATE_ACTIVE, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sNestedSpotStateCondition[] = {
    HABITAT_COND(COND_SPOT_STATE, 12, HABITAT_STATE_ACTIVE, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sPartySpeciesCondition[] = {
    HABITAT_COND(COND_PARTY_SPECIES, SPECIES_SKITTY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sPartyMoveCondition[] = {
    HABITAT_COND(COND_PARTY_MOVE, MOVE_TACKLE, 0, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sPartyNatureCondition[] = {
    HABITAT_COND(COND_PARTY_NATURE, NATURE_HARDY, 0, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sPartyEvolutionCondition[] = {
    HABITAT_COND(COND_PARTY_SPECIES, SPECIES_VULPIX, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sPlacementCondition[] = {
    HABITAT_COND(COND_ITEM_PLACED, ITEM_POKE_DOLL, 1, 1, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sTimeCondition[] = {
    HABITAT_COND(COND_TIME_OF_DAY, 0, 0, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sResidentCondition[] = {
    HABITAT_COND(COND_RESIDENT_COUNT, HABITAT_TYPE_ANY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sDexCondition[] = {
    HABITAT_COND(COND_DEX_COUNT, HABITAT_CMP_GE, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sStatCondition[] = {
    HABITAT_COND(COND_LIFETIME_STAT, GAME_STAT_STEPS, HABITAT_CMP_GE, 1, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sStatSetCondition[] = {
    HABITAT_COND(COND_LIFETIME_STAT, GAME_STAT_STEPS, HABITAT_CMP_GE, 4, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sTalkCondition[] = {
    HABITAT_COND(COND_TALK_COUNT, 1, 0, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const u16 sTalkTestSpots[] = { 15, 0xFFFF };
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
        .spotId = 15, .species = SPECIES_HERACROSS, .tier = 1, .zoneId = 1,
        .appearConditions = sTalkCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x026, .mapGroup = 1, .mapNum = 1, .localId = 6,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_TALK) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 14, .species = SPECIES_PINSIR, .tier = 1, .zoneId = 1,
        .appearConditions = sStatCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x025, .mapGroup = 1, .mapNum = 1, .localId = 5,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_LIFETIME_STAT) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 12, .species = SPECIES_MACHOP, .tier = 1, .zoneId = 1,
        .appearConditions = sSpotStateCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x023, .mapGroup = 1, .mapNum = 1, .localId = 3,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_RESIDENT) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 16, .species = SPECIES_POOCHYENA, .tier = 1, .zoneId = 1,
        .appearConditions = sNestedSpotStateCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x027, .mapGroup = 1, .mapNum = 1, .localId = 7,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_RESIDENT) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 13, .species = SPECIES_VULPIX, .tier = 1, .zoneId = 1,
        .appearConditions = sDexCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x024, .mapGroup = 1, .mapNum = 1, .localId = 4,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_RESIDENT) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 11, .species = SPECIES_LOTAD, .tier = 1, .zoneId = 1,
        .appearConditions = sFriendshipCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x022, .mapGroup = 1, .mapNum = 1, .localId = 2,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_PARTY) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 17, .species = SPECIES_TAILLOW, .tier = 1, .zoneId = 1,
        .appearConditions = sPartySpeciesCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x028, .mapGroup = 1, .mapNum = 1, .localId = 8,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_PARTY) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 18, .species = SPECIES_ZIGZAGOON, .tier = 1, .zoneId = 1,
        .appearConditions = sPartyMoveCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x029, .mapGroup = 1, .mapNum = 1, .localId = 9,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_PARTY) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 19, .species = SPECIES_WURMPLE, .tier = 1, .zoneId = 1,
        .appearConditions = sPartyNatureCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x02A, .mapGroup = 1, .mapNum = 1, .localId = 10,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_PARTY) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 20, .species = SPECIES_SHROOMISH, .tier = 1, .zoneId = 1,
        .appearConditions = sPartyEvolutionCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x02B, .mapGroup = 1, .mapNum = 1, .localId = 11,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_PARTY) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 21, .species = SPECIES_WHISMUR, .tier = 1, .zoneId = 1,
        .appearConditions = sPlacementCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x02C, .mapGroup = 1, .mapNum = 1, .localId = 12,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_PLACEMENT) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 22, .species = SPECIES_MAKUHITA, .tier = 1, .zoneId = 1,
        .appearConditions = sTimeCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x02D, .mapGroup = 1, .mapNum = 1, .localId = 13,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_TIME) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 23, .species = SPECIES_ARON, .tier = 1, .zoneId = 1,
        .appearConditions = sResidentCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x02E, .mapGroup = 1, .mapNum = 1, .localId = 14,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_RESIDENT) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    {
        .spotId = 24, .species = SPECIES_ELECTRIKE, .tier = 1, .zoneId = 1,
        .appearConditions = sStatSetCondition, .befriendConditions = sOfferBefriendConditions,
        .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        .hideFlag = FLAG_UNUSED_0x02F, .mapGroup = 1, .mapNum = 1, .localId = 15,
        .dependencyMask = HABITAT_DEP_MASK(HABITAT_DEP_LIFETIME_STAT) | HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY),
    },
    { .spotId = 0xFFFF },
};
static const struct HabitatMapSpan sDependencyTestSpans[] = {
    { .mapGroup = 1, .mapNum = 1, .firstSpot = 0, .count = 15 },
    { 0 },
};

static void UseDependencyTestTable(void)
{
    Habitat_SetSpotTableForTest(sDependencyTestSpots);
    Habitat_SetMapSpansForTest(sDependencyTestSpans);
    Habitat_SetTalkCounterSpotsForTest(sTalkTestSpots);
    gSaveBlock1Ptr->location.mapGroup = 1;
    gSaveBlock1Ptr->location.mapNum = 1;
}

static void RestoreProductionTable(void)
{
    Habitat_SetMapSpansForTest(NULL);
    Habitat_SetSpotTableForTest(NULL);
    Habitat_SetTalkCounterSpotsForTest(NULL);
}

TEST("Habitat event: delayed and no-delay weather changes immediately recompute dependent spots")
{
    const struct HabitatSpot *lotad;
    u32 i;
    RestoreProductionTable();
    lotad = Habitat_GetSpot(SPOT_LOTAD);
    ASSUME(lotad != NULL);

    gSaveBlock1Ptr->location.mapGroup = lotad->mapGroup;
    gSaveBlock1Ptr->location.mapNum = lotad->mapNum;

    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    SetCurrentAndNextWeather(WEATHER_SUNNY);
    SetNextWeather(WEATHER_RAIN);
    for (i = 0; i < 64 && GetCurrentWeather() != WEATHER_RAIN; i++)
        Weather_RunMainTaskForTest();
    EXPECT_EQ(GetCurrentWeather(), WEATHER_RAIN);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_LOTAD), HABITAT_STATE_STIRRING);

    Habitat_ResetRecomputeCountForTest();
    SetCurrentAndNextWeather(WEATHER_RAIN);  // same-weather no-op
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 0);

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

TEST("Habitat event: time ticks and map-load reconciliation target the current map")
{
    u32 i;

    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    UseDependencyTestTable();
    FakeRtc_ManuallySetTime(0, 5, 0, 0);

    Habitat_CheckTimeTick(4);
    Habitat_ResetRecomputeCountForTest();
    Habitat_CheckTimeTick(5);
    EXPECT_EQ(Habitat_GetSpotState(22), HABITAT_STATE_ACTIVE);
    Habitat_ResetRecomputeCountForTest();
    Habitat_CheckTimeTick(5);
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 0);

    // The map-load entry signal performs the full current-map reconciliation.
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);
    CalculatePlayerPartyCount();
    FlagClear(TEST_STORY_FLAG);
    Habitat_ResetRecomputeCountForTest();
    Habitat_NotifyDependency(HABITAT_DEP_MAP);
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 15);
    RestoreProductionTable();
}

TEST("Habitat event: befriend and Grove assignment boundaries settle resident dependents")
{
    s32 residentIdx;

    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    UseDependencyTestTable();
    FlagSet(TEST_STORY_FLAG);
    Habitat_CompleteBefriendById(10);
    EXPECT_EQ(Habitat_GetSpotState(23), HABITAT_STATE_ACTIVE);
    residentIdx = Habitat_FindResidentBySpot(10);
    ASSUME(residentIdx >= 0);
    Habitat_GetPlot(0)->worker1 = 0xFF;
    Habitat_GetPlot(0)->worker2 = 0xFF;

    Habitat_ResetRecomputeCountForTest();
    EXPECT(Habitat_AssignResidentToPlot(residentIdx, 0));
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 4);
    Habitat_TickPlots(HABITAT_PLOT_HOURS_PER_STAGE * HABITAT_PLOT_STAGE_MATURE);
    EXPECT_EQ(Habitat_GetPlot(0)->growthStage, HABITAT_PLOT_STAGE_MATURE);
    EXPECT_EQ(Habitat_HarvestPlot(0), HABITAT_PLOT_YIELD);

    Habitat_ResetRecomputeCountForTest();
    Habitat_SendResidentHome(residentIdx);
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 4);
    Habitat_TickPlots(HABITAT_PLOT_HOURS_PER_STAGE * HABITAT_PLOT_STAGE_MATURE);
    EXPECT_EQ(Habitat_GetPlot(0)->growthStage, 0);  // sent home: no growth credit
    RestoreProductionTable();
}

TEST("Habitat event: party add, removal, replacement, and compaction publish immediately")
{
    u32 i;

    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    UseDependencyTestTable();
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);
    CalculatePlayerPartyCount();
    Habitat_NotifyDependency(HABITAT_DEP_MAP);
    EXPECT_EQ(Habitat_GetSpotState(17), HABITAT_STATE_DORMANT);

    CreateMon(&gParties[B_TRAINER_PLAYER][0], SPECIES_SKITTY, 10, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(gPartiesCount[B_TRAINER_PLAYER], 1);
    EXPECT_EQ(Habitat_GetSpotState(17), HABITAT_STATE_ACTIVE);

    Habitat_ResetRecomputeCountForTest();
    ZeroMonData(&gParties[B_TRAINER_PLAYER][0]);
    EXPECT_EQ(gPartiesCount[B_TRAINER_PLAYER], 0);
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 5);

    CreateMon(&gParties[B_TRAINER_PLAYER][1], SPECIES_SKITTY, 10, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(gPartiesCount[B_TRAINER_PLAYER], 0);  // a noncontiguous slot waits for compaction
    Habitat_ResetRecomputeCountForTest();
    EXPECT_EQ(CompactPartySlots(), 0);
    EXPECT_EQ(gPartiesCount[B_TRAINER_PLAYER], 1);
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 5);

    // Exercise the actual storage move helpers: party -> box purges through
    // SetMovingMonData/PurgeMonOrBoxMon, and box -> party places through
    // SetPlacedMonData.
    Habitat_ResetRecomputeCountForTest();
    EXPECT(Habitat_TestDepositPartyMonToPc(0, 0, 0));
    EXPECT_EQ(gPartiesCount[B_TRAINER_PLAYER], 0);
    EXPECT_EQ(GetBoxMonDataAt(0, 0, MON_DATA_SPECIES), SPECIES_SKITTY);
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 5);
    Habitat_ResetRecomputeCountForTest();
    EXPECT(Habitat_TestWithdrawPcMonToParty(0, 0, 0));
    EXPECT_EQ(gPartiesCount[B_TRAINER_PLAYER], 1);
    EXPECT_EQ(GetBoxMonDataAt(0, 0, MON_DATA_SPECIES), SPECIES_NONE);
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 5);
    RestoreProductionTable();
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
    EXPECT_EQ(Habitat_GetSpotState(12), HABITAT_STATE_DORMANT);
    EXPECT_EQ(Habitat_GetSpotState(13), HABITAT_STATE_DORMANT);
    EXPECT_EQ(Habitat_GetSpotState(14), HABITAT_STATE_DORMANT);
    EXPECT_EQ(Habitat_GetSpotState(15), HABITAT_STATE_DORMANT);

    FlagSet(TEST_STORY_FLAG);
    EXPECT_EQ(Habitat_GetSpotState(10), HABITAT_STATE_ACTIVE);
    EXPECT_EQ(Habitat_GetSpotState(11), HABITAT_STATE_DORMANT);
    EXPECT_EQ(Habitat_GetSpotState(12), HABITAT_STATE_ACTIVE);
    EXPECT_EQ(Habitat_GetSpotState(16), HABITAT_STATE_ACTIVE);

    Habitat_ResetRecomputeCountForTest();
    FlagClear(TEST_STORY_FLAG);
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 1);
    EXPECT(!FlagGet(TEST_STORY_FLAG));
    FlagSet(TEST_STORY_FLAG);

    gSpecialVar_0x8004 = 15;
    Habitat_OnInspectSpotById();
    EXPECT_EQ(gSpecialVar_Result, HABITAT_STATE_ACTIVE);
    EXPECT_EQ(Habitat_GetTalkCount(15), 1);

    // Visibility flags are engine outputs. Synchronizing one must not route
    // back through generic story-flag invalidation or re-evaluate a sibling.
    Habitat_ResetRecomputeCountForTest();
    Habitat_SyncSpotObjectFlag(Habitat_GetSpot(10));
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 0);

    CreateMon(&gParties[B_TRAINER_PLAYER][0], SPECIES_SKITTY, 10, 0, OTID_STRUCT_PLAYER_ID);
    CalculatePlayerPartyCount();
    EXPECT_EQ(Habitat_GetSpotState(17), HABITAT_STATE_ACTIVE);
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_FRIENDSHIP, &friendship);
    EXPECT_EQ(Habitat_GetSpotState(11), HABITAT_STATE_ACTIVE);
    Habitat_ResetRecomputeCountForTest();
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_FRIENDSHIP, &friendship);
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 0);

    {
        u16 move = MOVE_TACKLE;
        u32 personality = 0;
        SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE1, &move);
        EXPECT_EQ(Habitat_GetSpotState(18), HABITAT_STATE_ACTIVE);
        SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_PERSONALITY, &personality);
        EXPECT_EQ(Habitat_GetSpotState(19), HABITAT_STATE_ACTIVE);
        SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES, &(u16){ SPECIES_VULPIX });
        EXPECT_EQ(Habitat_GetSpotState(20), HABITAT_STATE_ACTIVE);
    }

    // Placement publishes only after the item has actually left the bag and
    // its persisted placement counter changed.
    EXPECT(AddBagItem(ITEM_POKE_DOLL, 1));
    EXPECT(Habitat_SubmitItem(Habitat_GetSpot(21), HABITAT_ITEM_ACTION_PLACE, ITEM_POKE_DOLL, 1));
    EXPECT_EQ(Habitat_GetSpotState(21), HABITAT_STATE_ACTIVE);

    // Bag mutation boundaries always publish inventory; no failed removal
    // churns the dispatcher.
    Habitat_ResetRecomputeCountForTest();
    EXPECT(AddBagItem(ITEM_ORAN_BERRY, 1));
    EXPECT(Habitat_GetRecomputeCountForTest() > 0);
    Habitat_ResetRecomputeCountForTest();
    EXPECT(RemoveBagItem(ITEM_ORAN_BERRY, 1));
    EXPECT(Habitat_GetRecomputeCountForTest() > 0);
    Habitat_ResetRecomputeCountForTest();
    EXPECT(!RemoveBagItem(ITEM_ORAN_BERRY, 1));
    EXPECT_EQ(Habitat_GetRecomputeCountForTest(), 0);

    memset(gSaveBlock1Ptr->dexCaught, 0, sizeof(gSaveBlock1Ptr->dexCaught));
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_VULPIX), FLAG_SET_CAUGHT);
    EXPECT_EQ(Habitat_GetSpotState(13), HABITAT_STATE_ACTIVE);

    SetGameStat(GAME_STAT_STEPS, 0);  // no-op while already zero
    EXPECT_EQ(Habitat_GetSpotState(14), HABITAT_STATE_DORMANT);
    IncrementGameStat(GAME_STAT_STEPS);
    EXPECT_EQ(Habitat_GetSpotState(14), HABITAT_STATE_ACTIVE);
    SetGameStat(GAME_STAT_STEPS, 4);
    EXPECT_EQ(Habitat_GetSpotState(24), HABITAT_STATE_ACTIVE);

    // Toggle is a changed story-flag boundary too; state is monotonic, so
    // the flag's second toggle must be safe without recompute churn.
    FlagToggle(TEST_STORY_FLAG);
    FlagToggle(TEST_STORY_FLAG);

    // Compaction is the public PC-deposit cleanup boundary; it must publish
    // the party change after moving a non-empty party slot.
    ZeroMonData(&gParties[B_TRAINER_PLAYER][0]);
    CreateMon(&gParties[B_TRAINER_PLAYER][1], SPECIES_LOTAD, 10, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(CompactPartySlots(), 0);
    RestoreProductionTable();
}
