#include "global.h"
#include "habitat/bouts.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "habitat/test_probe.h"
#include "constants/habitat.h"
#include "constants/items.h"
#include "constants/species.h"
#include "item.h"

#if TESTING || HABITAT_TEST_PROBE
struct HabitatTestProbe gHabitatTestProbe;
u16 gHabitatTestCommand;
static u16 sTestProbeSpotId = HABITAT_SPOT_NONE;

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
}

static void SubmitTestItem(u16 spotId, enum HabitatItemAction action, u16 itemId)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(spotId);

    SelectTestProbeSpot(spotId);
    AddBagItem(itemId, 1);
    Habitat_SubmitItem(spot, action, itemId, 1);
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
    spot = Habitat_GetSpot(sTestProbeSpotId != HABITAT_SPOT_NONE
                           ? sTestProbeSpotId : Habitat_GetInteractionSpotId());
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
