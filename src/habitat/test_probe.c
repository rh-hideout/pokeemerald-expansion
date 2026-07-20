#include "global.h"
#include "battle.h"
#include "habitat/bouts.h"
#include "habitat/migration.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "habitat/test_probe.h"
#include "constants/habitat.h"
#include "constants/items.h"
#include "constants/species.h"
#include "event_object_movement.h"
#include "item.h"
#include "main.h"
#include "script.h"
#include "save.h"
#include "task.h"

#if TESTING || HABITAT_TEST_PROBE
struct HabitatTestProbe gHabitatTestProbe;
u16 gHabitatTestCommand;
static u16 sTestProbeSpotId;
static bool8 sTestProbeSpotSelected;
static u8 sPendingBattleOutcome;
static u16 sPendingBattleFrames;
static bool8 sBattleOutcomePending;

// This is an explicit non-finale fixture. It exercises the production bout
// boundary without implying an unauthored Deoxys scene exists.
static const struct HabitatBoutDefinition sTestProbeBout = {
    .boutId = 1,
    .playerSpecies = SPECIES_TREECKO,
    .playerLevel = 12,
    .opponentSpecies = SPECIES_ZIGZAGOON,
    .opponentLevel = 9,
};

STATIC_ASSERT(sizeof(struct HabitatTestProbe) == HABITAT_TEST_PROBE_SIZE, HabitatTestProbeSize);
STATIC_ASSERT(offsetof(struct HabitatTestProbe, version) == HABITAT_TEST_PROBE_OFFSET_VERSION, HabitatTestProbeVersionOffset);
STATIC_ASSERT(offsetof(struct HabitatTestProbe, spotId) == HABITAT_TEST_PROBE_OFFSET_SPOT_ID, HabitatTestProbeSpotIdOffset);
STATIC_ASSERT(offsetof(struct HabitatTestProbe, spotState) == HABITAT_TEST_PROBE_OFFSET_SPOT_STATE, HabitatTestProbeSpotStateOffset);
STATIC_ASSERT(offsetof(struct HabitatTestProbe, availableVerbs) == HABITAT_TEST_PROBE_OFFSET_AVAILABLE_VERBS, HabitatTestProbeVerbsOffset);
STATIC_ASSERT(offsetof(struct HabitatTestProbe, resolvedSpecies) == HABITAT_TEST_PROBE_OFFSET_RESOLVED_SPECIES, HabitatTestProbeSpeciesOffset);
STATIC_ASSERT(offsetof(struct HabitatTestProbe, residentSpotId) == HABITAT_TEST_PROBE_OFFSET_RESIDENT_SPOT_ID, HabitatTestProbeResidentOffset);
STATIC_ASSERT(offsetof(struct HabitatTestProbe, residentAssignment) == HABITAT_TEST_PROBE_OFFSET_RESIDENT_ASSIGNMENT, HabitatTestProbeAssignmentOffset);
STATIC_ASSERT(offsetof(struct HabitatTestProbe, boutOutcome) == HABITAT_TEST_PROBE_OFFSET_BOUT_OUTCOME, HabitatTestProbeBoutOffset);
STATIC_ASSERT(offsetof(struct HabitatTestProbe, mapGroup) == HABITAT_TEST_PROBE_OFFSET_MAP_GROUP, HabitatTestProbeMapGroupOffset);
STATIC_ASSERT(offsetof(struct HabitatTestProbe, mapNum) == HABITAT_TEST_PROBE_OFFSET_MAP_NUM, HabitatTestProbeMapNumOffset);

static void SelectTestProbeSpot(u16 spotId)
{
    sTestProbeSpotId = spotId;
    sTestProbeSpotSelected = TRUE;
}

static void SubmitTestItem(u16 spotId, enum HabitatItemAction action, u16 itemId)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(spotId);

    SelectTestProbeSpot(spotId);
    AddBagItem(itemId, 1);
    Habitat_SubmitItem(spot, action, itemId, 1);
}

void Habitat_TestProbeOnBattleMainFrame(void)
{
    if (!sBattleOutcomePending)
        return;

    // Battle initialization can consume every task slot. Drive the probe's
    // deterministic finish from the real battle main callback instead of
    // competing with battle UI tasks for one more slot.
    if (++sPendingBattleFrames < 360)
        return;

    if (BattleMain_TestFinishWithOutcome(sPendingBattleOutcome))
    {
        sBattleOutcomePending = FALSE;
        sPendingBattleFrames = 0;
    }
}

static void RunTestBout(u8 battleOutcome)
{
    if (!Habitat_BoutBegin(&sTestProbeBout))
        return;

    // CB2_InitBattle clears all tasks. Retain only the outcome here, then
    // complete it from the first real BattleMainCB2 frame.
    sPendingBattleOutcome = battleOutcome;
    sPendingBattleFrames = 0;
    sBattleOutcomePending = TRUE;
}

static void RunTestMigration(void)
{
    struct HabitatSave *save = &gSaveBlock3Ptr->habitat;

    memset(save, 0, sizeof(*save));
    save->spotStates[3] = HABITAT_STATE_BEFRIENDED;
    // Legacy residents stored species in originSpotId's bytes.
    save->residents[0].originSpotId = SPECIES_MACHOP;
    save->residents[0].personalitySeed = 7;
    save->saveVersion = HABITAT_SAVE_VERSION_LEGACY;
    Habitat_MigrateSave();
    SelectTestProbeSpot(3);
}

static void RunTestPersistence(void)
{
    // Exercise the save engine's sector serializer and loader. A byte copy
    // would not detect an incompatible SaveBlock3 layout or migration hook.
    if (TrySavingData(SAVE_NORMAL) != SAVE_STATUS_OK)
        return;
    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    if (LoadGameSave(SAVE_NORMAL) != SAVE_STATUS_OK)
        return;
    SelectTestProbeSpot(3);
}

static void RunTestResetBout(void)
{
    // Persist a durable marker before the actual bout begins. The runner then
    // resets mGBA while this battle is live and reboots through the save.
    RunTestMigration();
    RunTestPersistence();
    RunTestBout(B_OUTCOME_WON);
}

static void RunTestGroveAssignment(void)
{
    s32 residentIdx;

    SubmitTestItem(7, HABITAT_ITEM_ACTION_PLACE, ITEM_HH_POTTED_PLANT);
    residentIdx = Habitat_FindResidentBySpot(7);
    if (residentIdx >= 0)
        Habitat_AssignResidentToPlot(residentIdx, 0);
    SelectTestProbeSpot(7);
}

static void RecoverTestTreecko(void)
{
    SubmitTestItem(8, HABITAT_ITEM_ACTION_PLACE, ITEM_HH_BOOKSHELF);
    SubmitTestItem(8, HABITAT_ITEM_ACTION_PLACE, ITEM_HH_POTTED_PLANT);
}

static void RecoverTestMudkip(void)
{
    SubmitTestItem(9, HABITAT_ITEM_ACTION_PLACE, ITEM_HH_LAB_PC);
    SubmitTestItem(9, HABITAT_ITEM_ACTION_PLACE, ITEM_HH_POKEBALL_HOLDER);
    SubmitTestItem(9, HABITAT_ITEM_ACTION_PLACE, ITEM_HH_WATER_BASIN);
}

static void ApplyTestCommand(void)
{
    u16 command = gHabitatTestCommand;

    gHabitatTestCommand = HABITAT_TEST_COMMAND_NONE;
    switch (command)
    {
    case HABITAT_TEST_COMMAND_STARTER_CAMPFIRE:
        SubmitTestItem(7, HABITAT_ITEM_ACTION_PLACE, ITEM_HH_CAMPFIRE);
        break;
    case HABITAT_TEST_COMMAND_STARTER_PLANT:
        SubmitTestItem(7, HABITAT_ITEM_ACTION_PLACE, ITEM_HH_POTTED_PLANT);
        break;
    case HABITAT_TEST_COMMAND_STARTER_BASIN:
        SubmitTestItem(7, HABITAT_ITEM_ACTION_PLACE, ITEM_HH_WATER_BASIN);
        break;
    case HABITAT_TEST_COMMAND_SELECT_FRAME_TREECKO:
        SelectTestProbeSpot(8);
        break;
    case HABITAT_TEST_COMMAND_SELECT_FRAME_MUDKIP:
        SelectTestProbeSpot(9);
        break;
    case HABITAT_TEST_COMMAND_SKITTY_PLACE:
        SubmitTestItem(1, HABITAT_ITEM_ACTION_PLACE, ITEM_POKE_DOLL);
        break;
    case HABITAT_TEST_COMMAND_SKITTY_OFFER:
        SubmitTestItem(1, HABITAT_ITEM_ACTION_OFFER, ITEM_PERSIM_BERRY);
        break;
    case HABITAT_TEST_COMMAND_MACHOP_OFFER:
        SelectTestProbeSpot(3);
        Habitat_RecomputeSpot(Habitat_GetSpot(3));
        SubmitTestItem(3, HABITAT_ITEM_ACTION_OFFER, ITEM_CHERI_BERRY);
        break;
    case HABITAT_TEST_COMMAND_BOUT_WIN:
        RunTestBout(B_OUTCOME_WON);
        break;
    case HABITAT_TEST_COMMAND_BOUT_LOSS:
        RunTestBout(B_OUTCOME_LOST);
        break;
    case HABITAT_TEST_COMMAND_BOUT_FLEE:
        RunTestBout(B_OUTCOME_RAN);
        break;
    case HABITAT_TEST_COMMAND_BOUT_RESET:
        RunTestResetBout();
        break;
    case HABITAT_TEST_COMMAND_SAVE_MIGRATION:
        RunTestMigration();
        break;
    case HABITAT_TEST_COMMAND_SAVE_PERSISTENCE:
        RunTestPersistence();
        break;
    case HABITAT_TEST_COMMAND_GROVE_ASSIGN:
        RunTestGroveAssignment();
        break;
    case HABITAT_TEST_COMMAND_RECOVER_TREECKO:
        RecoverTestTreecko();
        break;
    case HABITAT_TEST_COMMAND_RECOVER_MUDKIP:
        RecoverTestMudkip();
        break;
    case HABITAT_TEST_COMMAND_NONE:
    default:
        break;
    }
}

void Habitat_TestProbeRefresh(void)
{
    const struct HabitatSpot *spot;
    s32 residentIdx = -1;

    if (gHabitatTestCommand != HABITAT_TEST_COMMAND_NONE)
        ApplyTestCommand();
    if (sTestProbeSpotSelected)
        spot = Habitat_GetSpot(sTestProbeSpotId);
    else
    {
        spot = Habitat_GetSpot(Habitat_GetInteractionSpotId());
        // A console reset clears the probe's RAM-only selection. Use the
        // reset fixture's durable resident checkpoint until another command
        // or in-world interaction selects a spot.
        if (spot == NULL)
            spot = Habitat_GetSpot(3);
    }
    memset(&gHabitatTestProbe, 0, sizeof(gHabitatTestProbe));
    gHabitatTestProbe.version = HABITAT_TEST_PROBE_VERSION;
    gHabitatTestProbe.residentSpotId = HABITAT_SPOT_NONE;
    gHabitatTestProbe.boutOutcome = Habitat_GetLastBoutOutcome();
    gHabitatTestProbe.mapGroup = gSaveBlock1Ptr->location.mapGroup;
    gHabitatTestProbe.mapNum = gSaveBlock1Ptr->location.mapNum;
    if (spot == NULL)
        return;

    gHabitatTestProbe.spotId = spot->spotId;
    gHabitatTestProbe.spotState = Habitat_GetSpotState(spot->spotId);
    gHabitatTestProbe.availableVerbs = Habitat_GetAvailableVerbs(spot);
    gHabitatTestProbe.resolvedSpecies = Habitat_GetResolvedSpotSpecies(spot);
    residentIdx = Habitat_FindResidentBySpot(spot->spotId);
    if (residentIdx >= 0)
    {
        const struct HabitatResident *resident = Habitat_GetResident(residentIdx);
        gHabitatTestProbe.residentSpotId = resident->originSpotId;
        gHabitatTestProbe.residentAssignment = resident->assignment;
    }
}
#endif
