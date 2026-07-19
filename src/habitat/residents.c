// Resident registry (spec §5): the individualized side of befriending.
// Conditions do NOT read this — they run off dex caught flags so that
// beyond-cap residents "still count for conditions". The registry exists
// for individuals: personality seeds (dialogue, spec §8) and Grove work
// assignments (phase 4).
#include "global.h"
#include "habitat/save.h"
#include "random.h"

u32 Habitat_ResidentCount(void)
{
    u32 i, n = 0;
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        if (gSaveBlock3Ptr->habitat.residents[i].species != SPECIES_NONE)
            n++;
    }
    return n;
}

const struct HabitatResident *Habitat_GetResident(u32 index)
{
    if (index >= HABITAT_RESIDENT_COUNT
     || gSaveBlock3Ptr->habitat.residents[index].species == SPECIES_NONE)
        return NULL;
    return &gSaveBlock3Ptr->habitat.residents[index];
}

s32 Habitat_TryAddResident(u16 species)
{
    u32 i;
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        struct HabitatResident *r = &gSaveBlock3Ptr->habitat.residents[i];
        if (r->species == SPECIES_NONE)
        {
            r->species = species;
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
        if (gSaveBlock3Ptr->habitat.residents[i].species == species)
            return i;
    }
    return -1;
}
