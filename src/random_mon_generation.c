#include "global.h"
#include "event_data.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "random_mon_generation.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokedex.h"
#include "constants/pokeball.h"
#include "constants/species.h"
#include "constants/vars.h"

enum RandomMonDexMode
{
    RANDOM_MON_DEX_NATIONAL,
    RANDOM_MON_DEX_HOENN,
};

struct RandomSpeciesGeneratorOptions
{
    enum RandomMonDexMode dexMode;
    const enum Species *speciesPool;
    u16 speciesPoolCount;
    const enum Species *bannedSpecies;
    u16 bannedSpeciesCount;
    u8 allowLegendary:1;
    u8 allowMythical:1;
    u8 allowSubLegendary:1;
    u8 allowUltraBeast:1;
    u8 allowParadox:1;
    u8 randomizeForms:1;
    u8 padding:2;
    bool32 (*filterFunc)(enum Species species);
};

struct RandomItemGeneratorOptions
{
    const enum Item *heldItemPool;
    u16 heldItemPoolCount;
    const enum HoldEffect *bannedHoldEffects;
    u16 bannedHoldEffectsCount;
};

static bool32 TryGetRandomSpeciesOptions(enum Species species, const struct RandomSpeciesGeneratorOptions **options);
static bool32 TryGetRandomItemOptions(enum Item item, const struct RandomItemGeneratorOptions **options);
static enum Species GetRandomMonSpecies(const struct RandomSpeciesGeneratorOptions *options);
static enum Species GetRandomMonFormSpecies(enum Species species);
static bool32 IsSpeciesAllowedByRandomBstVars(enum Species species);
static enum Item GetRandomMonHeldItem(const struct RandomItemGeneratorOptions *options);
static enum PokeBall GetRandomMonBall(void);
static enum Species ResolveRandomMonSpecies(enum Species species);
static enum Item ResolveRandomMonItem(enum Item item);
static enum PokeBall ResolveRandomMonBall(enum PokeBall ball);
static void ResolveRandomMonMoves(enum Species species, enum Move *moves);

#include "data/random_mon_generator.h"

static bool32 TryGetRandomSpeciesOptions(enum Species species, const struct RandomSpeciesGeneratorOptions **options)
{
    u32 optionId;

    if (species < SPECIES_RANDOM_MON_OPTION_0)
        return FALSE;

    optionId = species - SPECIES_RANDOM_MON_OPTION_0;
    if (optionId >= ARRAY_COUNT(sRandomSpeciesGeneratorOptions))
        return FALSE;

    *options = &sRandomSpeciesGeneratorOptions[optionId];
    return TRUE;
}

static bool32 TryGetRandomItemOptions(enum Item item, const struct RandomItemGeneratorOptions **options)
{
    u32 optionId;

    if (item < ITEM_RANDOM_OPTION_0)
        return FALSE;

    optionId = item - ITEM_RANDOM_OPTION_0;
    if (optionId >= ARRAY_COUNT(sRandomItemGeneratorOptions))
        return FALSE;

    *options = &sRandomItemGeneratorOptions[optionId];
    return TRUE;
}

static u16 GetSpeciesBaseStatTotal(enum Species species)
{
    const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[species];

    return speciesInfo->baseHP
         + speciesInfo->baseAttack
         + speciesInfo->baseDefense
         + speciesInfo->baseSpeed
         + speciesInfo->baseSpAttack
         + speciesInfo->baseSpDefense;
}

static bool32 IsSpeciesBannedByRandomMonOptions(enum Species species, const struct RandomSpeciesGeneratorOptions *options)
{
    u32 i;
    enum Species baseSpecies = GET_BASE_SPECIES_ID(species);
    const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[baseSpecies];

    for (i = 0; i < options->bannedSpeciesCount; i++)
    {
        if (baseSpecies == GET_BASE_SPECIES_ID(options->bannedSpecies[i]))
            return TRUE;
    }

    if (!options->allowLegendary && speciesInfo->isRestrictedLegendary)
        return TRUE;
    if (!options->allowMythical && speciesInfo->isMythical)
        return TRUE;
    if (!options->allowSubLegendary && speciesInfo->isSubLegendary)
        return TRUE;
    if (!options->allowUltraBeast && speciesInfo->isUltraBeast)
        return TRUE;
    if (!options->allowParadox && speciesInfo->isParadox)
        return TRUE;
    if (options->filterFunc != NULL && !options->filterFunc(species))
        return TRUE;

    return FALSE;
}

static bool32 IsSpeciesAllowedByRandomBstVars(enum Species species)
{
    u16 bstStandard = VarGet(VAR_0x8007);
    u16 bstLeniency = VarGet(VAR_0x8008);
    u16 bst = GetSpeciesBaseStatTotal(GET_BASE_SPECIES_ID(species));
    u16 minBst;
    u16 maxBst;

    if (bstStandard < 100)
        return TRUE;

    minBst = (bstStandard > bstLeniency) ? bstStandard - bstLeniency : 0;
    maxBst = bstStandard + bstLeniency;

    return bst >= minBst && bst <= maxBst;
}

static enum Species GetRandomMonBaseSpeciesFromDex(const struct RandomSpeciesGeneratorOptions *options)
{
    if (options->dexMode == RANDOM_MON_DEX_HOENN)
    {
        enum HoennDexOrder hoennNum = RandomUniform(RNG_RANDOM_MON_GEN, 1, HOENN_DEX_COUNT - 1);
        return NationalPokedexNumToSpecies(HoennToNationalOrder(hoennNum));
    }
    else
    {
        enum NationalDexOrder nationalNum = RandomUniform(RNG_RANDOM_MON_GEN, 1, NATIONAL_DEX_COUNT);
        return NationalPokedexNumToSpecies(nationalNum);
    }
}

static enum Species GetRandomMonCandidateSpecies(const struct RandomSpeciesGeneratorOptions *options)
{
    if (options->speciesPool != NULL && options->speciesPoolCount != 0)
        return GET_BASE_SPECIES_ID(options->speciesPool[RandomUniform(RNG_RANDOM_MON_GEN, 0, options->speciesPoolCount - 1)]);

    return GetRandomMonBaseSpeciesFromDex(options);
}

static enum Species GetFirstValidRandomMonSpecies(const struct RandomSpeciesGeneratorOptions *options)
{
    u32 i;

    if (options->speciesPool != NULL && options->speciesPoolCount != 0)
    {
        for (i = 0; i < options->speciesPoolCount; i++)
        {
            enum Species species = GET_BASE_SPECIES_ID(options->speciesPool[i]);
            if (!IsSpeciesBannedByRandomMonOptions(species, options))
                return species;
        }
    }
    else
    {
        u32 maxDex = (options->dexMode == RANDOM_MON_DEX_HOENN) ? HOENN_DEX_COUNT - 1 : NATIONAL_DEX_COUNT;
        for (i = 1; i <= maxDex; i++)
        {
            enum Species species = (options->dexMode == RANDOM_MON_DEX_HOENN)
                ? NationalPokedexNumToSpecies(HoennToNationalOrder(i))
                : NationalPokedexNumToSpecies(i);

            if (!IsSpeciesBannedByRandomMonOptions(species, options))
                return species;
        }
    }

    return SPECIES_BULBASAUR;
}

static bool32 IsRandomMonFormTableException(enum Species species)
{
    switch (GET_BASE_SPECIES_ID(species))
    {
    case SPECIES_ROTOM:
    case SPECIES_ORICORIO:
    case SPECIES_TORNADUS:
    case SPECIES_THUNDURUS:
    case SPECIES_LANDORUS:
    case SPECIES_ENAMORUS:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool32 IsSpeciesInRandomMonFormChangeTables(enum Species species, const u16 *formTable)
{
    u32 i, j;

    for (i = 0; formTable[i] != FORM_SPECIES_END; i++)
    {
        const struct FormChange *formChanges = GetSpeciesFormChanges(formTable[i]);

        for (j = 0; formChanges != NULL && formChanges[j].method != FORM_CHANGE_TERMINATOR; j++)
        {
            if (formChanges[j].targetSpecies == species)
                return TRUE;
        }
    }

    return FALSE;
}

static bool32 IsSpeciesInRandomMonFusionTables(enum Species species, const u16 *formTable)
{
    u32 i, j;

    for (i = 0; formTable[i] != FORM_SPECIES_END; i++)
    {
        const struct Fusion *fusionTable = gFusionTablePointers[formTable[i]];

        for (j = 0; fusionTable != NULL && fusionTable[j].fusionStorageIndex != FUSION_TERMINATOR; j++)
        {
            if (fusionTable[j].targetSpecies1 == species
             || fusionTable[j].targetSpecies2 == species
             || fusionTable[j].fusingIntoMon == species)
                return TRUE;
        }
    }

    return FALSE;
}

static bool32 IsSpeciesInRandomMonFormOrFusionTables(enum Species species, const u16 *formTable)
{
    return IsSpeciesInRandomMonFormChangeTables(species, formTable)
        || IsSpeciesInRandomMonFusionTables(species, formTable);
}

static bool32 IsRandomMonFormAllowed(enum Species species, const u16 *formTable)
{
    const struct SpeciesInfo *speciesInfo;
    enum Species baseSpecies = GET_BASE_SPECIES_ID(species);

    switch (species) // Special case because darm has galarian forms (desired) and zen mode forms (not desired)
    {
    case SPECIES_DARMANITAN_ZEN:
    case SPECIES_DARMANITAN_GALAR_ZEN:
        return FALSE;
    case SPECIES_DARMANITAN_GALAR:
        return TRUE;
    default:
        break;
    }

    if (species != baseSpecies
     && !IsRandomMonFormTableException(baseSpecies)
     && IsSpeciesInRandomMonFormOrFusionTables(species, formTable))
        return FALSE;

    speciesInfo = &gSpeciesInfo[species];

    return !speciesInfo->isMegaEvolution
        && !speciesInfo->isGigantamax
        && !speciesInfo->isTotem
        && !speciesInfo->isUltraBurst
        && !speciesInfo->cannotBeTraded
        && !speciesInfo->isTeraForm
        && !speciesInfo->isPrimalReversion;
}

static enum Species GetRandomMonFormSpecies(enum Species species)
{
    u32 i;
    u32 eligibleFormCount = 0;
    enum Species eligibleForms[NUM_SPECIES];
    const u16 *formTable;

    formTable = GetSpeciesFormTable(species);

    if (formTable == NULL)
        return species;

    for (i = 0; formTable[i] != FORM_SPECIES_END; i++)
    {
        if (IsRandomMonFormAllowed(formTable[i], formTable))
        {
            eligibleForms[eligibleFormCount] = formTable[i];
            eligibleFormCount++;
        }
    }

    if (eligibleFormCount == 0)
        return species;

    return eligibleForms[RandomUniform(RNG_RANDOM_MON_GEN, 0, eligibleFormCount - 1)];
}

static enum Species GetRandomMonSpecies(const struct RandomSpeciesGeneratorOptions *options)
{
    u32 i;

    for (i = 0; i < 512; i++)
    {
        enum Species species = GetRandomMonCandidateSpecies(options);
        if (!IsSpeciesBannedByRandomMonOptions(species, options))
        {
            if (options->randomizeForms)
                species = GetRandomMonFormSpecies(species);
            return species;
        }
    }

    {
        enum Species species = GetFirstValidRandomMonSpecies(options);
        if (options->randomizeForms)
            species = GetRandomMonFormSpecies(species);
        return species;
    }
}

static bool32 IsRandomItemBannedHoldEffect(const struct RandomItemGeneratorOptions *options, enum HoldEffect holdEffect)
{
    u32 i;

    for (i = 0; i < options->bannedHoldEffectsCount; i++)
    {
        if (options->bannedHoldEffects[i] == holdEffect)
            return TRUE;
    }

    return FALSE;
}

static bool32 IsRandomMonHeldItemAllowed(const struct RandomItemGeneratorOptions *options, enum Item item)
{
    return item != ITEM_NONE
        && item < ITEMS_COUNT
        && !IsRandomItemBannedHoldEffect(options, GetItemHoldEffect(item));
}

static enum Item GetRandomMonHeldItemCandidate(const struct RandomItemGeneratorOptions *options)
{
    if (options->heldItemPool != NULL && options->heldItemPoolCount != 0)
        return options->heldItemPool[RandomUniform(RNG_RANDOM_MON_GEN, 0, options->heldItemPoolCount - 1)];

    return RandomUniform(RNG_RANDOM_MON_GEN, 1, ITEMS_COUNT - 1);
}

static enum Item GetRandomMonHeldItem(const struct RandomItemGeneratorOptions *options)
{
    u32 i;

    for (i = 0; i < 512; i++)
    {
        enum Item item = GetRandomMonHeldItemCandidate(options);
        if (IsRandomMonHeldItemAllowed(options, item))
            return item;
    }

    if (options->heldItemPool != NULL && options->heldItemPoolCount != 0)
    {
        for (i = 0; i < options->heldItemPoolCount; i++)
        {
            if (IsRandomMonHeldItemAllowed(options, options->heldItemPool[i]))
                return options->heldItemPool[i];
        }
    }
    else
    {
        for (i = 1; i < ITEMS_COUNT; i++)
        {
            if (IsRandomMonHeldItemAllowed(options, i))
                return i;
        }
    }

    return ITEM_NONE;
}

static enum PokeBall GetRandomMonBall(void)
{
    return RandomUniform(RNG_RANDOM_MON_GEN, BALL_STRANGE, POKEBALL_COUNT - 1);
}

static enum Species ResolveRandomMonSpecies(enum Species species)
{
    const struct RandomSpeciesGeneratorOptions *randomSpeciesOptions;

    if (TryGetRandomSpeciesOptions(species, &randomSpeciesOptions))
        return GetRandomMonSpecies(randomSpeciesOptions);

    return species;
}

static enum Item ResolveRandomMonItem(enum Item item)
{
    const struct RandomItemGeneratorOptions *randomItemOptions;

    if (item < ITEMS_COUNT)
        return item;
    if (TryGetRandomItemOptions(item, &randomItemOptions))
        return GetRandomMonHeldItem(randomItemOptions);

    errorf("Unknown item value %d", item);
    return ITEM_NONE;
}

static enum PokeBall ResolveRandomMonBall(enum PokeBall ball)
{
    if (ball < POKEBALL_COUNT)
        return ball;
    if (ball == BALL_RANDOM)
        return GetRandomMonBall();

    errorf("Unknown ball value %d", ball);
    return BALL_STRANGE;
}

static bool32 IsMoveInRandomMonMoves(enum Move move, enum Move *moves, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++)
    {
        if (moves[i] == move)
            return TRUE;
    }

    return FALSE;
}

static void ResolveRandomMonMoves(enum Species species, enum Move *moves)
{
    u32 i;
    u32 teachableCount = 0;
    const u16 *teachableLearnset = GetSpeciesTeachableLearnset(species);

    while (teachableLearnset[teachableCount] != MOVE_UNAVAILABLE)
        teachableCount++;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 j;

        if (moves[i] != MOVE_RANDOM_TEACHABLE)
            continue;

        for (j = 0; j < 64 && teachableCount != 0; j++)
        {
            enum Move move = teachableLearnset[RandomUniform(RNG_RANDOM_MON_GEN, 0, teachableCount - 1)];
            if (!IsMoveInRandomMonMoves(move, moves, MAX_MON_MOVES))
            {
                moves[i] = move;
                break;
            }
        }

        if (moves[i] == MOVE_RANDOM_TEACHABLE)
        {
            for (j = 0; j < teachableCount; j++)
            {
                if (!IsMoveInRandomMonMoves(teachableLearnset[j], moves, MAX_MON_MOVES))
                {
                    moves[i] = teachableLearnset[j];
                    break;
                }
            }
        }

        if (moves[i] == MOVE_RANDOM_TEACHABLE)
            moves[i] = MOVE_NONE;
    }
}

void ResolveRandomMonGeneration(enum Species *species, enum Item *item, enum PokeBall *ball, enum Move *moves)
{
    *species = ResolveRandomMonSpecies(*species);
    *item = ResolveRandomMonItem(*item);
    *ball = ResolveRandomMonBall(*ball);
    ResolveRandomMonMoves(*species, moves);
}
