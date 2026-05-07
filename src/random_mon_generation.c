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

#define MAX_EXHAUSTIVE_SEARCH_POOL_SIZE 20

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

static enum Species GetRandomMonSpecies(u32 optionId);
static enum Species GetRandomMonFormSpecies(enum Species species);
static bool32 IsSpeciesAllowedByRandomBstVars(enum Species species);
static u32 GetRandomMonSpeciesPoolSize(const struct RandomSpeciesGeneratorOptions *options);
static enum Species GetRandomMonSpeciesAtIndex(const struct RandomSpeciesGeneratorOptions *options, u32 index);
static enum Species SlowPickRandomMonSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize);
static enum Species FastPickRandomMonSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize);
static enum Item GetRandomMonHeldItem(u32 optionId);
static u32 GetRandomMonHeldItemPoolSize(const struct RandomItemGeneratorOptions *options);
static enum Item GetRandomMonHeldItemAtIndex(const struct RandomItemGeneratorOptions *options, u32 index);
static enum Item SlowPickRandomMonHeldItem(const struct RandomItemGeneratorOptions *options, u32 poolSize);
static enum Item FastPickRandomMonHeldItem(const struct RandomItemGeneratorOptions *options, u32 poolSize);
static enum PokeBall GetRandomMonBall(void);
static enum Species ResolveRandomMonSpecies(enum Species species);
static enum Item ResolveRandomMonItem(enum Item item);
static enum PokeBall ResolveRandomMonBall(enum PokeBall ball);
static bool32 ShouldSwapRandomMonMoves(enum Move moveA, enum Move moveB);
static void SortRandomMonMoves(enum Move *moves);
static bool32 IsMoveInRandomMonMoveset(enum Move move, enum Move *moves, u32 count);
static bool32 HasRandomMonTeachableMoveCandidate(const u16 *teachableLearnset, u32 teachableCount, enum Move *moves, u32 count);
static void ResolveRandomMonMoves(enum Species species, enum Move *moves);

#if TESTING
#include "../test/random_mon_generator.h"
#else
#include "data/random_mon_generator.h"
#endif

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

/*
* The below function is uses VAR0x8007 and VAR0x8008 as BST centerpoint and BST leniency points.
* If a mon is within centerpoint +/- leniency, it's valid.
* This only applies if .filterFunc for your struct points to this function, and if
* the centerpoint/standard (VAR_0x8007) is >= 100.
*/

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

static u32 GetRandomMonSpeciesPoolSize(const struct RandomSpeciesGeneratorOptions *options)
{
    if (options->speciesPool != NULL && options->speciesPoolCount != 0)
        return options->speciesPoolCount;

    if (options->dexMode == RANDOM_MON_DEX_HOENN)
        return HOENN_DEX_COUNT - 1;

    return NATIONAL_DEX_COUNT;
}

static enum Species GetRandomMonSpeciesAtIndex(const struct RandomSpeciesGeneratorOptions *options, u32 index)
{
    if (options->speciesPool != NULL && options->speciesPoolCount != 0)
        return GET_BASE_SPECIES_ID(options->speciesPool[index]);

    if (options->dexMode == RANDOM_MON_DEX_HOENN)
        return NationalPokedexNumToSpecies(HoennToNationalOrder(index + 1));

    return NationalPokedexNumToSpecies(index + 1);
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

static enum Species GetRandomMonSpecies(u32 optionId)
{
    const struct RandomSpeciesGeneratorOptions *options = &sRandomSpeciesGeneratorOptions[optionId];
    enum Species species;
    u32 poolSize = GetRandomMonSpeciesPoolSize(options);

    if (options->speciesPool != NULL && options->speciesPoolCount != 0 && options->speciesPoolCount <= MAX_EXHAUSTIVE_SEARCH_POOL_SIZE)
        species = SlowPickRandomMonSpecies(options, poolSize);
    else
        species = FastPickRandomMonSpecies(options, poolSize);

    if (options->randomizeForms)
        species = GetRandomMonFormSpecies(species);

    return species;
}

static enum Species SlowPickRandomMonSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize)
{
    u32 i;
    u32 eligibleSpeciesCount = 0;
    enum Species eligibleSpecies[MAX_EXHAUSTIVE_SEARCH_POOL_SIZE];

    for (i = 0; i < poolSize; i++)
    {
        enum Species species = GetRandomMonSpeciesAtIndex(options, i);
        if (!IsSpeciesBannedByRandomMonOptions(species, options))
            eligibleSpecies[eligibleSpeciesCount++] = species;
    }

    if (eligibleSpeciesCount == 0)
    {
        errorf("Could not find a random species matching random mon options");
        return SPECIES_BULBASAUR;
    }

    return eligibleSpecies[RandomUniform(RNG_RANDOM_MON_GEN, 0, eligibleSpeciesCount - 1)];
}

static enum Species FastPickRandomMonSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize)
{
    u32 i;

    for (i = 0; i < poolSize; i++)
    {
        enum Species species = GetRandomMonSpeciesAtIndex(options, RandomUniform(RNG_RANDOM_MON_GEN, 0, poolSize - 1));
        if (!IsSpeciesBannedByRandomMonOptions(species, options))
            return species;
    }

    errorf("Could not get random species after %d tries", poolSize);
    return GetFirstValidRandomMonSpecies(options);
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
    if (item >= ITEMS_COUNT)
        return FALSE;
    if (item == ITEM_NONE)
        return options->heldItemPool != NULL && options->heldItemPoolCount != 0;

    return !IsRandomItemBannedHoldEffect(options, GetItemHoldEffect(item));
}

static u32 GetRandomMonHeldItemPoolSize(const struct RandomItemGeneratorOptions *options)
{
    if (options->heldItemPool != NULL && options->heldItemPoolCount != 0)
        return options->heldItemPoolCount;

    return ITEMS_COUNT - 1;
}

static enum Item GetRandomMonHeldItemAtIndex(const struct RandomItemGeneratorOptions *options, u32 index)
{
    if (options->heldItemPool != NULL && options->heldItemPoolCount != 0)
        return options->heldItemPool[index];

    return index + 1;
}

static enum Item SlowPickRandomMonHeldItem(const struct RandomItemGeneratorOptions *options, u32 poolSize)
{
    u32 i;
    u32 eligibleItemCount = 0;
    enum Item eligibleItems[MAX_EXHAUSTIVE_SEARCH_POOL_SIZE];

    for (i = 0; i < poolSize; i++)
    {
        enum Item item = GetRandomMonHeldItemAtIndex(options, i);
        if (IsRandomMonHeldItemAllowed(options, item))
            eligibleItems[eligibleItemCount++] = item;
    }

    if (eligibleItemCount == 0)
    {
        errorf("Could not find a random held item matching random mon options");
        return ITEM_NONE;
    }

    return eligibleItems[RandomUniform(RNG_RANDOM_MON_GEN, 0, eligibleItemCount - 1)];
}

static enum Item FastPickRandomMonHeldItem(const struct RandomItemGeneratorOptions *options, u32 poolSize)
{
    u32 i;

    for (i = 0; i < poolSize; i++)
    {
        enum Item item = GetRandomMonHeldItemAtIndex(options, RandomUniform(RNG_RANDOM_MON_GEN, 0, poolSize - 1));
        if (IsRandomMonHeldItemAllowed(options, item))
            return item;
    }

    errorf("Could not get random held item after %d tries", poolSize);
    for (i = 0; i < poolSize; i++)
    {
        enum Item item = GetRandomMonHeldItemAtIndex(options, i);
        if (IsRandomMonHeldItemAllowed(options, item))
            return item;
    }

    return ITEM_NONE;
}

static enum Item GetRandomMonHeldItem(u32 optionId)
{
    const struct RandomItemGeneratorOptions *options = &sRandomItemGeneratorOptions[optionId];
    u32 poolSize = GetRandomMonHeldItemPoolSize(options);

    if (options->heldItemPool != NULL && options->heldItemPoolCount != 0 && options->heldItemPoolCount <= MAX_EXHAUSTIVE_SEARCH_POOL_SIZE)
        return SlowPickRandomMonHeldItem(options, poolSize);

    return FastPickRandomMonHeldItem(options, poolSize);
}

static enum PokeBall GetRandomMonBall(void)
{
    return RandomUniform(RNG_RANDOM_MON_GEN, BALL_STRANGE, POKEBALL_COUNT - 1);
}

static enum Species ResolveRandomMonSpecies(enum Species species)
{
    if ((u32)species >= SPECIES_RANDOMLY_GENERATED_START && (u32)species < SPECIES_GENERATOR_END)
        return GetRandomMonSpecies(SPECIES_OPTION(species));

    return species;
}

static enum Item ResolveRandomMonItem(enum Item item)
{
    if (item < ITEMS_COUNT)
        return item;
    if ((u32)item >= ITEM_RANDOMLY_GENERATED_START && (u32)item < ITEM_GENERATOR_END)
        return GetRandomMonHeldItem(ITEM_OPTION(item));

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

static bool32 ShouldSwapRandomMonMoves(enum Move moveA, enum Move moveB)
{
    if (moveA == moveB)
        return FALSE;
    if (moveA == MOVE_NONE)
        return TRUE;
    if (moveA == MOVE_DEFAULT)
        return moveB != MOVE_NONE;
    if (moveA == MOVE_RANDOM_TEACHABLE)
        return moveB != MOVE_NONE && moveB != MOVE_DEFAULT;

    return FALSE;
}

static void SortRandomMonMoves(enum Move *moves)
{
    u32 i, j;
    enum Move temp;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        for (j = i; j < MAX_MON_MOVES; j++)
        {
            if (ShouldSwapRandomMonMoves(moves[i], moves[j]))
                SWAP(moves[i], moves[j], temp);
        }
    }
}

static bool32 IsMoveInRandomMonMoveset(enum Move move, enum Move *moves, u32 count)
{
    u32 i;

    if (move == MOVE_NONE)
        return FALSE;

    for (i = 0; i < count; i++)
    {
        if (moves[i] == move)
            return TRUE;
    }

    return FALSE;
}

static bool32 HasRandomMonTeachableMoveCandidate(const u16 *teachableLearnset, u32 teachableCount, enum Move *moves, u32 count)
{
    u32 i;

    for (i = 0; i < teachableCount; i++)
    {
        if (!IsMoveInRandomMonMoveset(teachableLearnset[i], moves, count))
            return TRUE;
    }

    return FALSE;
}

static void ResolveRandomMonMoves(enum Species species, enum Move *moves)
{
    u32 i;
    u32 teachableCount = 0;
    const u16 *teachableLearnset = GetSpeciesTeachableLearnset(species);

    SortRandomMonMoves(moves);

    while (teachableLearnset[teachableCount] != MOVE_UNAVAILABLE)
        teachableCount++;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] < MOVES_COUNT)
        {
            assertf(!IsMoveInRandomMonMoveset(moves[i], moves, i), "move %d was assigned twice", moves[i])
            {
                moves[i] = MOVE_NONE;
            }
            continue;
        }

        if (moves[i] == MOVE_RANDOM_TEACHABLE)
        {
            enum Move candidate;
            u32 j;

            if (!HasRandomMonTeachableMoveCandidate(teachableLearnset, teachableCount, moves, i))
            {
                moves[i] = MOVE_NONE;
                continue;
            }

            for (j = 0; j < teachableCount; j++)
            {
                candidate = teachableLearnset[RandomUniform(RNG_RANDOM_MON_GEN, 0, teachableCount - 1)];
                if (!IsMoveInRandomMonMoveset(candidate, moves, i))
                    break;
            }

            if (j == teachableCount)
            {
                for (j = 0; j < teachableCount; j++)
                {
                    candidate = teachableLearnset[j];
                    if (!IsMoveInRandomMonMoveset(candidate, moves, i))
                        break;
                }
            }

            moves[i] = candidate;
            continue;
        }

        assertf(moves[i] == MOVE_DEFAULT, "invalid move: %d", moves[i])
        {
            moves[i] = MOVE_NONE;
        }
    }

    SortRandomMonMoves(moves);
}

void ResolveRandomMonGeneration(enum Species *species, enum Item *item, enum PokeBall *ball, enum Move *moves)
{
    *species = ResolveRandomMonSpecies(*species);
    *item = ResolveRandomMonItem(*item);
    *ball = ResolveRandomMonBall(*ball);
    ResolveRandomMonMoves(*species, moves);
}
