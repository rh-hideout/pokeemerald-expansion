#include "global.h"
#include "factory_boss_team.h"
#include "random.h"
#include "constants/battle_frontier_mons.h"
#include "constants/items.h"
#include "constants/pokemon.h"

static bool8 CanUseFactoryBossAceMonId(const struct TrainerMon *facilityMons,
                                       const struct RentalMon *rentalMons,
                                       u16 monId)
{
    s32 i;

    if (facilityMons[monId].species == SPECIES_UNOWN)
        return FALSE;

    for (i = 0; i < FRONTIER_PARTY_SIZE * 2; i++)
    {
        if (monId == rentalMons[i].monId)
            return FALSE;
    }

    return TRUE;
}

u16 ChooseFactoryBossAceMonIdInRange(const struct FactoryBossProfile *bossProfile,
                                     const struct TrainerMon *facilityMons,
                                     const struct RentalMon *rentalMons,
                                     s32 firstMonId,
                                     s32 lastMonId)
{
    s32 i;
    u16 count = 0;
    u16 chosenMonId = 0xFFFF;

    for (i = firstMonId; i <= lastMonId; i++)
    {
        if (facilityMons[i].species != bossProfile->aceSpecies)
            continue;
        if (!CanUseFactoryBossAceMonId(facilityMons, rentalMons, i))
            continue;

        // Reservoir sample to choose uniformly from all valid ace sets.
        count++;
        if ((Random() % count) == 0)
            chosenMonId = i;
    }

    return chosenMonId;
}

u16 ChooseFactoryBossAceMonId(const struct FactoryBossProfile *bossProfile,
                              const struct TrainerMon *facilityMons,
                              const struct RentalMon *rentalMons)
{
    return ChooseFactoryBossAceMonIdInRange(bossProfile, facilityMons, rentalMons, 0, NUM_FRONTIER_MONS - 1);
}

bool8 FactoryBossCanUseAceMonIdForSlot(const struct TrainerMon *facilityMons,
                                       const struct RentalMon *rentalMons,
                                       u16 monId,
                                       s32 aceSlot,
                                       const u16 *species,
                                       const u16 *heldItems)
{
    s32 i;

    if (!CanUseFactoryBossAceMonId(facilityMons, rentalMons, monId))
        return FALSE;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        if (i == aceSlot)
            continue;
        if (species[i] == facilityMons[monId].species)
            return FALSE;
    }

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        if (i == aceSlot)
            continue;
        if (heldItems[i] != ITEM_NONE && heldItems[i] == facilityMons[monId].heldItem)
            return FALSE;
    }

    return TRUE;
}
