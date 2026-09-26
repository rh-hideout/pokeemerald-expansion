#include "global.h"
#include "mf_rules.h"
#include "mf_stats.h"
#include "pokemon.h"

struct MfClassicBaseStats
{
    u16 species;
    u8 stats[NUM_STATS]; // STAT_HP … STAT_SPDEF
};

#include "data/mf_classic_base_stats.h"

static const u8 *FindClassicBaseStats(enum Species species)
{
    s32 lo = 0;
    s32 hi = (s32)ARRAY_COUNT(sClassicBaseStats) - 1;

    while (lo <= hi)
    {
        s32 mid = (lo + hi) / 2;
        u16 midSpecies = sClassicBaseStats[mid].species;

        if (midSpecies == species)
            return sClassicBaseStats[mid].stats;
        if (midSpecies < species)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return NULL;
}

static u32 ModernBaseStat(enum Species species, u32 statIndex)
{
    const struct SpeciesInfo *info = &gSpeciesInfo[species];

    switch (statIndex)
    {
    case STAT_HP:     return info->baseHP;
    case STAT_ATK:    return info->baseAttack;
    case STAT_DEF:    return info->baseDefense;
    case STAT_SPEED:  return info->baseSpeed;
    case STAT_SPATK:  return info->baseSpAttack;
    case STAT_SPDEF:  return info->baseSpDefense;
    }
    return 0;
}

u32 MfGetSpeciesBaseStat(enum Species species, u32 statIndex)
{
    enum Species sanitized = SanitizeSpeciesId(species);
    const u8 *classic;

    if (statIndex >= NUM_STATS)
        return 0;

    // Hot path: Modern (default) reads gSpeciesInfo with one rule check, no scan.
    if (MfRules_HasModernStats())
        return ModernBaseStat(sanitized, statIndex);

    classic = FindClassicBaseStats(sanitized);
    if (classic != NULL)
        return classic[statIndex];

    return ModernBaseStat(sanitized, statIndex);
}

void MfRecalculatePartyStats(void)
{
    u32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) != SPECIES_NONE)
            CalculateMonStats(&gParties[B_TRAINER_PLAYER][i]);
    }
}
