#include "global.h"
#include "constants/habitat.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/species.h"
#include "habitat/bouts.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "habitat/test_probe.h"
#include "test/test.h"

TEST("Habitat verification probe: snapshots documented interaction and resident fields")
{
    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(MAP_ROUTE103);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(MAP_ROUTE103);
    Habitat_SetInteractionSpotForTest(1);

    Habitat_TestProbeRefresh();

    EXPECT_EQ(gHabitatTestProbe.version, HABITAT_TEST_PROBE_VERSION);
    EXPECT_EQ(gHabitatTestProbe.spotId, 1);
    EXPECT_EQ(gHabitatTestProbe.spotState, HABITAT_STATE_DORMANT);
    EXPECT_EQ(gHabitatTestProbe.resolvedSpecies, SPECIES_SKITTY);
    EXPECT_EQ(gHabitatTestProbe.residentSpotId, HABITAT_SPOT_NONE);
    EXPECT_EQ(gHabitatTestProbe.residentAssignment, 0);
    EXPECT_EQ(gHabitatTestProbe.mapGroup, MAP_GROUP(MAP_ROUTE103));
    EXPECT_EQ(gHabitatTestProbe.mapNum, MAP_NUM(MAP_ROUTE103));

    gSaveBlock3Ptr->habitat.spotStates[1] = HABITAT_STATE_BEFRIENDED;
    gSaveBlock3Ptr->habitat.residents[0].originSpotId = 1;
    gSaveBlock3Ptr->habitat.residents[0].assignment = 2;
    Habitat_TestProbeRefresh();

    EXPECT_EQ(gHabitatTestProbe.spotState, HABITAT_STATE_BEFRIENDED);
    EXPECT_EQ(gHabitatTestProbe.residentSpotId, 1);
    EXPECT_EQ(gHabitatTestProbe.residentAssignment, 2);
}

TEST("Habitat verification probe: development commands exercise approved item transitions")
{
    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    gHabitatTestCommand = HABITAT_TEST_COMMAND_STARTER_PLANT;
    Habitat_TestProbeRefresh();

    EXPECT_EQ(gHabitatTestCommand, HABITAT_TEST_COMMAND_NONE);
    EXPECT_EQ(gHabitatTestProbe.spotId, 7);
    EXPECT_EQ(gHabitatTestProbe.resolvedSpecies, SPECIES_TREECKO);
    EXPECT_EQ(gHabitatTestProbe.spotState, HABITAT_STATE_BEFRIENDED);
    EXPECT_EQ(gHabitatTestProbe.residentSpotId, 7);

    gHabitatTestCommand = HABITAT_TEST_COMMAND_SKITTY_PLACE;
    Habitat_TestProbeRefresh();
    EXPECT_EQ(gHabitatTestProbe.spotId, 1);
    EXPECT_EQ(gHabitatTestProbe.spotState, HABITAT_STATE_ACTIVE);
    EXPECT(gHabitatTestProbe.availableVerbs & HABITAT_VERB_OFFER);

    gHabitatTestCommand = HABITAT_TEST_COMMAND_SKITTY_OFFER;
    Habitat_TestProbeRefresh();
    EXPECT_EQ(gHabitatTestProbe.spotState, HABITAT_STATE_BEFRIENDED);
    EXPECT_EQ(gHabitatTestProbe.resolvedSpecies, SPECIES_SKITTY);
}

TEST("Habitat verification probe: non-finale bout commands report every field-return outcome")
{
    static const struct
    {
        u16 command;
        enum HabitatBoutOutcome outcome;
    } sCases[] = {
        { HABITAT_TEST_COMMAND_BOUT_WIN, HABITAT_BOUT_WIN },
        { HABITAT_TEST_COMMAND_BOUT_LOSS, HABITAT_BOUT_LOSS },
        { HABITAT_TEST_COMMAND_BOUT_FLEE, HABITAT_BOUT_FLED },
        { HABITAT_TEST_COMMAND_BOUT_RESET, HABITAT_BOUT_ABORTED },
    };
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCases); i++)
    {
        gHabitatTestCommand = sCases[i].command;
        Habitat_TestProbeRefresh();

        EXPECT_EQ(gHabitatTestCommand, HABITAT_TEST_COMMAND_NONE);
        EXPECT_EQ(gHabitatTestProbe.boutOutcome, sCases[i].outcome);
        EXPECT(!Habitat_BoutIsActive());
    }
}

TEST("Habitat verification probe: migration and save round-trip commands preserve a resident")
{
    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    gHabitatTestCommand = HABITAT_TEST_COMMAND_SAVE_MIGRATION;
    Habitat_TestProbeRefresh();

    EXPECT_EQ(gHabitatTestProbe.spotId, 3);
    EXPECT_EQ(gHabitatTestProbe.spotState, HABITAT_STATE_BEFRIENDED);
    EXPECT_EQ(gHabitatTestProbe.resolvedSpecies, SPECIES_MACHOP);
    EXPECT_EQ(gHabitatTestProbe.residentSpotId, 3);

    gHabitatTestCommand = HABITAT_TEST_COMMAND_SAVE_PERSISTENCE;
    Habitat_TestProbeRefresh();
    EXPECT_EQ(gHabitatTestProbe.spotId, 3);
    EXPECT_EQ(gHabitatTestProbe.residentSpotId, 3);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.saveVersion, HABITAT_SAVE_VERSION_CURRENT);
}

TEST("Habitat verification probe: Grove checkpoint command assigns an approved resident")
{
    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    gHabitatTestCommand = HABITAT_TEST_COMMAND_GROVE_ASSIGN;
    Habitat_TestProbeRefresh();

    EXPECT_EQ(gHabitatTestProbe.spotId, 7);
    EXPECT_EQ(gHabitatTestProbe.residentSpotId, 7);
    EXPECT_EQ(gHabitatTestProbe.residentAssignment, 1);
}
