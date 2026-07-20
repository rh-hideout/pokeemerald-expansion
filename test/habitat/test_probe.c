#include "global.h"
#include "battle.h"
#include "constants/habitat.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/species.h"
#include "event_object_movement.h"
#include "habitat/bouts.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "save.h"
#include "script.h"
#include "task.h"
#include "habitat/test_probe.h"
#include "test/test.h"

static const struct HabitatBoutDefinition sLiveBoutFixture = {
    .boutId = 1,
    .playerSpecies = SPECIES_TREECKO,
    .playerLevel = 12,
    .opponentSpecies = SPECIES_ZIGZAGOON,
    .opponentLevel = 9,
};

static void ResetHabitatSaveForTest(void)
{
    u32 i;

    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    gSaveBlock3Ptr->habitat.saveVersion = HABITAT_SAVE_VERSION_CURRENT;
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
        gSaveBlock3Ptr->habitat.residents[i].originSpotId = HABITAT_SPOT_NONE;
    for (i = 0; i < HABITAT_PLOT_COUNT; i++)
    {
        gSaveBlock3Ptr->habitat.plots[i].worker1 = 0xFF;
        gSaveBlock3Ptr->habitat.plots[i].worker2 = 0xFF;
    }
    Habitat_SetInteractionSpotForTest(HABITAT_SPOT_NONE);
}

TEST("Habitat verification probe: snapshots documented interaction and resident fields")
{
    ResetHabitatSaveForTest();
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
    ResetHabitatSaveForTest();
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
    AddBagItem(ITEM_PERSIM_BERRY, 1);
    Habitat_TestProbeRefresh();
    EXPECT(gHabitatTestProbe.availableVerbs & HABITAT_VERB_OFFER);

    gHabitatTestCommand = HABITAT_TEST_COMMAND_SKITTY_OFFER;
    Habitat_TestProbeRefresh();
    EXPECT_EQ(gHabitatTestProbe.spotState, HABITAT_STATE_BEFRIENDED);
    EXPECT_EQ(gHabitatTestProbe.resolvedSpecies, SPECIES_SKITTY);
}

TEST("Habitat verification probe: recovery commands actually befriend both unchosen starters")
{
    ResetHabitatSaveForTest();
    gHabitatTestCommand = HABITAT_TEST_COMMAND_STARTER_CAMPFIRE;
    Habitat_TestProbeRefresh();

    gHabitatTestCommand = HABITAT_TEST_COMMAND_RECOVER_TREECKO;
    Habitat_TestProbeRefresh();
    EXPECT_EQ(gHabitatTestProbe.spotId, 8);
    EXPECT_EQ(gHabitatTestProbe.spotState, HABITAT_STATE_BEFRIENDED);
    EXPECT_EQ(gHabitatTestProbe.resolvedSpecies, SPECIES_TREECKO);
    EXPECT_EQ(gHabitatTestProbe.residentSpotId, 8);

    gHabitatTestCommand = HABITAT_TEST_COMMAND_RECOVER_MUDKIP;
    Habitat_TestProbeRefresh();
    EXPECT_EQ(gHabitatTestProbe.spotId, 9);
    EXPECT_EQ(gHabitatTestProbe.spotState, HABITAT_STATE_BEFRIENDED);
    EXPECT_EQ(gHabitatTestProbe.resolvedSpecies, SPECIES_MUDKIP);
    EXPECT_EQ(gHabitatTestProbe.residentSpotId, 9);
}

TEST("Habitat verification probe: non-finale bout commands report every field-return outcome")
{
    static const struct
    {
        u16 command;
        u8 battleOutcome;
        enum HabitatBoutOutcome outcome;
    } sCases[] = {
        { HABITAT_TEST_COMMAND_BOUT_WIN, B_OUTCOME_WON, HABITAT_BOUT_WIN },
        { HABITAT_TEST_COMMAND_BOUT_LOSS, B_OUTCOME_LOST, HABITAT_BOUT_LOSS },
        { HABITAT_TEST_COMMAND_BOUT_FLEE, B_OUTCOME_RAN, HABITAT_BOUT_FLED },
    };
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCases); i++)
    {
        gHabitatTestCommand = sCases[i].command;
        Habitat_TestProbeRefresh();

        EXPECT_EQ(gHabitatTestCommand, HABITAT_TEST_COMMAND_NONE);
        EXPECT(Habitat_BoutIsActive());
        Habitat_BoutFinishFromBattleOutcome(sCases[i].battleOutcome);
        EXPECT_EQ(Habitat_GetLastBoutOutcome(), sCases[i].outcome);
        EXPECT(!Habitat_BoutIsActive());
        ResetTasks();
        UnfreezeObjectEvents();
        UnlockPlayerFieldControls();
    }
}

TEST("Habitat verification probe: live bout fixture reaches the callback only after cleanup")
{
    u32 i;

    ResetHabitatSaveForTest();
    EXPECT(Habitat_BoutBegin(&sLiveBoutFixture));
    EXPECT(Habitat_BoutIsActive());
    EXPECT(BattleMain_TestStartLiveBoutFixture());
    EXPECT(gMain.inBattle);
    EXPECT_NE(gBattleResources, NULL);
    EXPECT(BattleMain_TestFinishLiveBoutFixture(B_OUTCOME_WON));
    for (i = 0; i < 64 && gMain.inBattle; i++)
        EXPECT(BattleMain_TestRunLiveBoutFixtureFrame());
    EXPECT(BattleMain_TestHasFinishedCleanup());
    gMain.callback2();
    EXPECT_EQ(Habitat_GetLastBoutOutcome(), HABITAT_BOUT_WIN);
    EXPECT(!Habitat_BoutIsActive());
    SetMainCallback2(CB2_TestRunner);
    ResetTasks();
    UnfreezeObjectEvents();
    UnlockPlayerFieldControls();
}

TEST("Habitat verification probe: migration and save round-trip commands preserve a resident")
{
    ResetHabitatSaveForTest();
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
    EXPECT_EQ(gSaveFileStatus, SAVE_STATUS_OK);
}

TEST("Habitat verification probe: Grove checkpoint command assigns an approved resident")
{
    ResetHabitatSaveForTest();
    gHabitatTestCommand = HABITAT_TEST_COMMAND_GROVE_ASSIGN;
    Habitat_TestProbeRefresh();

    EXPECT_EQ(gHabitatTestProbe.spotId, 7);
    EXPECT_EQ(gHabitatTestProbe.residentSpotId, 7);
    EXPECT_EQ(gHabitatTestProbe.residentAssignment, 1);
}
