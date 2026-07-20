// Resident registry (spec §5): the individualized side of befriending.
// Conditions do NOT read this — they run off dex caught flags so that
// beyond-cap residents "still count for conditions". The registry exists
// for individuals: personality seeds (dialogue, spec §8) and Grove work
// assignments (phase 4).
#include "global.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "random.h"

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

s32 Habitat_TryAddResident(u16 species)
{
    u32 i;

    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
        if (gHabitatSpots[i].species == species)
            return Habitat_TryAddResidentAtSpot(gHabitatSpots[i].spotId);
    return -1;
}

s32 Habitat_TryAddResidentAtSpot(u16 originSpotId)
{
    u32 i;

    if (Habitat_GetSpot(originSpotId) == NULL)
        return -1;
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

s32 Habitat_FindResidentBySpecies(u16 species)
{
    u32 i;
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        if (Habitat_GetResidentSpecies(&gSaveBlock3Ptr->habitat.residents[i]) == species)
            return i;
    }
    return -1;
}

u16 Habitat_GetResidentSpecies(const struct HabitatResident *resident)
{
    const struct HabitatSpot *spot;

    if (resident == NULL || ResidentSlotIsEmpty(resident))
        return SPECIES_NONE;
    spot = Habitat_GetSpot(resident->originSpotId);
    return spot == NULL ? SPECIES_NONE : spot->species;
}
