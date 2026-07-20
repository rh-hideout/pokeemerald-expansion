#include "global.h"
#include "event_data.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "item.h"
#include "item_menu.h"
#include "pokedex.h"
#include "rtc.h"
#include "constants/berry.h"
#include "test/test.h"

#define SPOT_SKITTY 1
#define SPOT_LOTAD 2
#define SPOT_MACHOP 3
#define SPOT_HERACROSS 5
#define SPOT_PINSIR 6
#define SPOT_FRAME_TREECKO 8

#define TEST_SPOT_SKITTY_ROUTE 280
#define TEST_SPOT_SKITTY_GROVE 281
#define TEST_SPOT_CASTFORM_NORMAL 282
#define TEST_SPOT_CASTFORM_SUNNY 283

static const struct HabitatCondition sTestConditions[] = {
    HABITAT_CONDITIONS_END,
};
static const u8 sTestHint[] = _("test$");
static const struct HabitatSpot sIdentityTestSpots[] = {
    {
        .spotId = TEST_SPOT_SKITTY_ROUTE, .species = SPECIES_SKITTY, .tier = 1, .zoneId = 1,
        .appearConditions = sTestConditions, .befriendConditions = sTestConditions,
        .hintDormant = sTestHint, .hintStirring = sTestHint, .hintActive = sTestHint,
        .hideFlag = FLAG_UNUSED_0x022, .mapGroup = 1, .mapNum = 1, .localId = 1,
    },
    {
        .spotId = TEST_SPOT_SKITTY_GROVE, .species = SPECIES_SKITTY, .tier = 1, .zoneId = 2,
        .appearConditions = sTestConditions, .befriendConditions = sTestConditions,
        .hintDormant = sTestHint, .hintStirring = sTestHint, .hintActive = sTestHint,
        .hideFlag = FLAG_UNUSED_0x023, .mapGroup = 2, .mapNum = 1, .localId = 1,
    },
    {
        .spotId = TEST_SPOT_CASTFORM_NORMAL, .species = SPECIES_CASTFORM_NORMAL, .tier = 1, .zoneId = 1,
        .appearConditions = sTestConditions, .befriendConditions = sTestConditions,
        .hintDormant = sTestHint, .hintStirring = sTestHint, .hintActive = sTestHint,
        .hideFlag = FLAG_UNUSED_0x024, .mapGroup = 3, .mapNum = 1, .localId = 1,
    },
    {
        .spotId = TEST_SPOT_CASTFORM_SUNNY, .species = SPECIES_CASTFORM_SUNNY, .tier = 1, .zoneId = 2,
        .appearConditions = sTestConditions, .befriendConditions = sTestConditions,
        .hintDormant = sTestHint, .hintStirring = sTestHint, .hintActive = sTestHint,
        .hideFlag = FLAG_UNUSED_0x025, .mapGroup = 4, .mapNum = 1, .localId = 1,
    },
    { .spotId = 0xFFFF },
};

TEST("Habitat residents: befriending registers an individual")
{
    EXPECT_EQ(Habitat_ResidentCount(), 0);
    Habitat_SetSpotState(SPOT_MACHOP, HABITAT_STATE_ACTIVE);
    Habitat_CompleteBefriendById(SPOT_MACHOP);
    EXPECT_EQ(Habitat_ResidentCount(), 1);
    ASSUME(Habitat_GetResident(0) != NULL);
    EXPECT_EQ(Habitat_GetResidentSpotId(0), SPOT_MACHOP);
    EXPECT_EQ(Habitat_GetResidentSpecies(0), SPECIES_MACHOP);
    EXPECT_EQ(Habitat_GetResident(0)->assignment, 0);
    EXPECT_EQ(Habitat_FindResidentBySpot(SPOT_MACHOP), 0);
    EXPECT_EQ(Habitat_FindResidentBySpot(SPOT_SKITTY), -1);
    EXPECT_EQ(Habitat_TryAddResident(SPOT_MACHOP), 0);
    EXPECT_EQ(Habitat_ResidentCount(), 1);
}

TEST("Habitat residents: adding the same origin spot never creates a second individual")
{
    static const struct HabitatCondition sMachop[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_MACHOP, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;
    u32 i;
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
        gSaveBlock3Ptr->habitat.residents[i].originSpotId = SPOT_LOTAD;
    EXPECT_EQ(Habitat_ResidentCount(), HABITAT_RESIDENT_COUNT);

    Habitat_SetSpotState(SPOT_MACHOP, HABITAT_STATE_ACTIVE);
    Habitat_CompleteBefriendById(SPOT_MACHOP);
    EXPECT_EQ(Habitat_ResidentCount(), HABITAT_RESIDENT_COUNT);
    EXPECT_EQ(Habitat_FindResidentBySpot(SPOT_MACHOP), -1);
    Habitat_EvaluateConditions(sMachop, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);  // overflow stays befriended for condition truth
}

TEST("Habitat residents: conditions count befriended origin spots, not caught dex flags")
{
    static const struct HabitatCondition sTreecko[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_TREECKO, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sTreeckoZone1[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_TREECKO, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sTreeckoZone2[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_TREECKO, 2, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sSceptile[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_SCEPTILE, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sAnyTwo[] = {
        HABITAT_COND(COND_RESIDENT_COUNT, HABITAT_TYPE_ANY, 2, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;
    const struct HabitatSpot *treeckoFrame = Habitat_GetSpot(SPOT_FRAME_TREECKO);

    ASSUME(treeckoFrame != NULL);
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_TREECKO), FLAG_SET_CAUGHT);
    Habitat_EvaluateConditions(sTreecko, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    // The frame's species comes from its placed element, not its historical
    // static binding. This is the Treecko selection's stable counter.
    Habitat_AddPlacedCount(4, 1);
    EXPECT_EQ(Habitat_GetResolvedSpotSpecies(treeckoFrame), SPECIES_TREECKO);
    // Both spots are befriended even when the resident registry is full.
    Habitat_SetSpotState(SPOT_FRAME_TREECKO, HABITAT_STATE_BEFRIENDED);
    Habitat_SetSpotState(SPOT_LOTAD, HABITAT_STATE_BEFRIENDED);  // Water/Grass, zone 1

    Habitat_EvaluateConditions(sTreecko, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sTreeckoZone1, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);
    Habitat_EvaluateConditions(sTreeckoZone2, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sSceptile, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sAnyTwo, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);  // Treecko + Lotad; caught Dex alone adds nothing
}

TEST("Habitat residents: origin spots distinguish duplicate species, zones, and forms")
{
    static const struct HabitatCondition sAnyOne[] = {
        HABITAT_COND(COND_RESIDENT_COUNT, HABITAT_TYPE_ANY, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sAnyTwo[] = {
        HABITAT_COND(COND_RESIDENT_COUNT, HABITAT_TYPE_ANY, 2, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sSkittyZone1[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_SKITTY, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sSkittyZone2[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_SKITTY, 2, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sCastformNormal[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_CASTFORM_NORMAL, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sCastformSunny[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_CASTFORM_SUNNY, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    Habitat_SetSpotTableForTest(sIdentityTestSpots);
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_CASTFORM_NORMAL), FLAG_SET_CAUGHT);
    Habitat_EvaluateConditions(sAnyOne, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);  // caught Dex alone is not a resident
    Habitat_EvaluateConditions(sAnyTwo, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);  // one caught Dex entry cannot expand into its form family

    Habitat_CompleteBefriendById(TEST_SPOT_CASTFORM_NORMAL);
    Habitat_EvaluateConditions(sCastformNormal, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sCastformSunny, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);  // sibling form shares the Dex number, not the origin
    Habitat_EvaluateConditions(sAnyOne, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sAnyTwo, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);  // one befriended form counts once, never as its sibling

    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));

    Habitat_CompleteBefriendById(TEST_SPOT_SKITTY_ROUTE);
    Habitat_CompleteBefriendById(TEST_SPOT_SKITTY_GROVE);
    EXPECT_EQ(Habitat_ResidentCount(), 2);
    EXPECT_EQ(Habitat_FindResidentBySpot(TEST_SPOT_SKITTY_ROUTE), 0);
    EXPECT_EQ(Habitat_FindResidentBySpot(TEST_SPOT_SKITTY_GROVE), 1);
    EXPECT_EQ(Habitat_GetResidentSpecies(0), SPECIES_SKITTY);
    EXPECT_EQ(Habitat_GetResidentSpecies(1), SPECIES_SKITTY);
    Habitat_EvaluateConditions(sSkittyZone1, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sSkittyZone2, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);

    gSaveBlock3Ptr->habitat.plots[0].worker1 = 0xFF;
    gSaveBlock3Ptr->habitat.plots[0].worker2 = 0xFF;
    gSaveBlock3Ptr->habitat.plots[1].worker1 = 0xFF;
    gSaveBlock3Ptr->habitat.plots[1].worker2 = 0xFF;
    EXPECT(Habitat_AssignResidentToPlot(0, 0));
    Habitat_SyncSpotObjectFlag(&sIdentityTestSpots[0]);
    Habitat_SyncSpotObjectFlag(&sIdentityTestSpots[1]);
    EXPECT(FlagGet(sIdentityTestSpots[0].hideFlag));
    EXPECT(!FlagGet(sIdentityTestSpots[1].hideFlag));
    EXPECT(Habitat_AssignResidentToPlot(1, 1));
    EXPECT(Habitat_ResidentIsOut(0));
    EXPECT(Habitat_ResidentIsOut(1));

    Habitat_SetSpotTableForTest(NULL);
}

TEST("Habitat residents: Heracross chain closes (resident Pinsir + night + sap tree)")
{
    const struct HabitatSpot *heracross = Habitat_GetSpot(SPOT_HERACROSS);
    ASSUME(heracross != NULL);

    RtcInitLocalTimeOffset(22, 0);
    gSaveBlock1Ptr->berryTrees[6].berry = ItemIdToBerryType(ITEM_LEPPA_BERRY);  // zone-1 tree
    gSaveBlock1Ptr->berryTrees[6].stage = BERRY_STAGE_BERRIES;

    Habitat_RecomputeSpot(heracross);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_HERACROSS), HABITAT_STATE_STIRRING);  // 2 of 3

    Habitat_SetSpotState(SPOT_PINSIR, HABITAT_STATE_BEFRIENDED);
    Habitat_RecomputeSpot(heracross);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_HERACROSS), HABITAT_STATE_ACTIVE);
}
