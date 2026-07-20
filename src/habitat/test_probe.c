#include "global.h"
#include "habitat/bouts.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "habitat/test_probe.h"
#include "constants/habitat.h"
#include "constants/species.h"

#if TESTING || HABITAT_TEST_PROBE
struct HabitatTestProbe gHabitatTestProbe;

void Habitat_TestProbeRefresh(void)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(Habitat_GetInteractionSpotId());
    s32 residentIdx = -1;

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
