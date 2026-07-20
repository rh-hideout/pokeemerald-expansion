// Resident registry (spec §5): the individualized side of befriending.
// Conditions use befriended authored spots directly, so overflow residents
// still count even though only this registry can work in the Grove.
#include "global.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "random.h"

#if TESTING
static const struct HabitatSpot *sTestSpotTable;
#endif

const struct HabitatSpot *Habitat_GetSpotTable(void)
{
#if TESTING
    if (sTestSpotTable != NULL)
        return sTestSpotTable;
#endif
    return gHabitatSpots;
}

#if TESTING
void Habitat_SetSpotTableForTest(const struct HabitatSpot *spots)
{
    sTestSpotTable = spots;
}
#endif

static const struct HabitatSpot *FindSpot(u16 spotId)
{
    const struct HabitatSpot *spots = Habitat_GetSpotTable();
    u32 i;

    for (i = 0; spots[i].spotId != 0xFFFF; i++)
        if (spots[i].spotId == spotId)
            return &spots[i];
    return NULL;
}

static bool32 ResidentSlotIsEmpty(const struct HabitatResident *resident)
{
    return resident->originSpotId == 0 || resident->originSpotId == HABITAT_SPOT_NONE;
}

u32 Habitat_ResidentCount(void)
{
    u32 i, n = 0;
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        if (!ResidentSlotIsEmpty(&gSaveBlock3Ptr->habitat.residents[i]))
            n++;
    }
    return n;
}

const struct HabitatResident *Habitat_GetResident(u32 index)
{
    if (index >= HABITAT_RESIDENT_COUNT
     || ResidentSlotIsEmpty(&gSaveBlock3Ptr->habitat.residents[index]))
        return NULL;
    return &gSaveBlock3Ptr->habitat.residents[index];
}

s32 Habitat_TryAddResident(u16 originSpotId)
{
    u32 i;

    if (FindSpot(originSpotId) == NULL)
        return -1;
    i = Habitat_FindResidentBySpot(originSpotId);
    if ((s32) i >= 0)
        return i;
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        struct HabitatResident *r = &gSaveBlock3Ptr->habitat.residents[i];
        if (ResidentSlotIsEmpty(r))
        {
            r->originSpotId = originSpotId;
            r->personalitySeed = Random() & 0xFF;
            r->assignment = 0;
            return i;
        }
    }
    return -1;  // cap reached: befriended but non-individualized (spec §5)
}

s32 Habitat_FindResidentBySpot(u16 originSpotId)
{
    u32 i;
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        if (Habitat_GetResidentSpotId(i) == originSpotId)
            return i;
    }
    return -1;
}

u16 Habitat_GetResidentSpotId(u32 residentIndex)
{
    const struct HabitatResident *resident = Habitat_GetResident(residentIndex);
    return resident == NULL ? HABITAT_SPOT_NONE : resident->originSpotId;
}

u16 Habitat_GetResidentSpecies(u32 residentIndex)
{
    const struct HabitatSpot *spot;
    u16 originSpotId = Habitat_GetResidentSpotId(residentIndex);

    if (originSpotId == HABITAT_SPOT_NONE)
        return SPECIES_NONE;
    spot = FindSpot(originSpotId);
    return spot == NULL ? SPECIES_NONE : spot->species;
}
