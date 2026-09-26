#include "global.h"
#include "mf_moves.h"
#include "mf_rules.h"
#include "pokemon.h"

struct MfClassicLevelUpPtr
{
    u16 species;
    const struct LevelUpMove *learnset;
};

struct MfClassicU16LearnsetPtr
{
    u16 species;
    const u16 *learnset;
};

#include "data/mf_classic_level_up_learnsets.h"
#include "data/mf_classic_teachable_learnsets.h"
#include "data/mf_classic_egg_moves.h"

static const struct LevelUpMove *FindClassicLevelUp(enum Species species)
{
    s32 lo = 0;
    s32 hi = (s32)ARRAY_COUNT(sClassicLevelUpLearnsets) - 1;

    while (lo <= hi)
    {
        s32 mid = (lo + hi) / 2;
        u16 midSpecies = sClassicLevelUpLearnsets[mid].species;

        if (midSpecies == species)
            return sClassicLevelUpLearnsets[mid].learnset;
        if (midSpecies < species)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return NULL;
}

static const u16 *FindClassicU16Learnset(const struct MfClassicU16LearnsetPtr *table, u32 count, enum Species species)
{
    s32 lo = 0;
    s32 hi = (s32)count - 1;

    while (lo <= hi)
    {
        s32 mid = (lo + hi) / 2;
        u16 midSpecies = table[mid].species;

        if (midSpecies == species)
            return table[mid].learnset;
        if (midSpecies < species)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return NULL;
}

static const struct LevelUpMove *ModernLevelUpLearnset(enum Species species)
{
    const struct LevelUpMove *learnset = gSpeciesInfo[species].levelUpLearnset;

    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].levelUpLearnset;
    return learnset;
}

static const u16 *ModernTeachableLearnset(enum Species species)
{
    const u16 *learnset = gSpeciesInfo[species].teachableLearnset;

    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].teachableLearnset;
    return learnset;
}

static const u16 *ModernEggMoves(enum Species species)
{
    const u16 *learnset = gSpeciesInfo[species].eggMoveLearnset;

    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].eggMoveLearnset;
    return learnset;
}

const struct LevelUpMove *MfGetSpeciesLevelUpLearnset(enum Species species)
{
    enum Species sanitized = SanitizeSpeciesId(species);
    const struct LevelUpMove *classic;

    // Hot path: Modern (default) reads gSpeciesInfo with one rule check.
    if (MfRules_HasModernMoves())
        return ModernLevelUpLearnset(sanitized);

    classic = FindClassicLevelUp(sanitized);
    if (classic != NULL)
        return classic;

    return ModernLevelUpLearnset(sanitized);
}

const u16 *MfGetSpeciesTeachableLearnset(enum Species species)
{
    enum Species sanitized = SanitizeSpeciesId(species);
    const u16 *classic;

    if (MfRules_HasModernMoves())
        return ModernTeachableLearnset(sanitized);

    classic = FindClassicU16Learnset(sClassicTeachableLearnsets,
                                     ARRAY_COUNT(sClassicTeachableLearnsets),
                                     sanitized);
    if (classic != NULL)
        return classic;

    return ModernTeachableLearnset(sanitized);
}

const u16 *MfGetSpeciesEggMoves(enum Species species)
{
    enum Species sanitized = SanitizeSpeciesId(species);
    const u16 *classic;

    if (MfRules_HasModernMoves())
        return ModernEggMoves(sanitized);

    classic = FindClassicU16Learnset(sClassicEggMoveLearnsets,
                                     ARRAY_COUNT(sClassicEggMoveLearnsets),
                                     sanitized);
    if (classic != NULL)
        return classic;

    return ModernEggMoves(sanitized);
}
