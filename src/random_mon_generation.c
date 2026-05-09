#include "global.h"
#include "event_data.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "random_mon_generation.h"
#include "script.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokedex.h"
#include "constants/pokeball.h"
#include "constants/species.h"
#include "constants/vars.h"

#define MAX_EXHAUSTIVE_SEARCH_POOL_SIZE 20
#define RANDOM_MON_MAX_FORMS 70

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
    bool32 (*filterFunc)(enum Species species, u16 arg1, u16 arg2);
};

struct RandomItemGeneratorOptions
{
    const enum Item *heldItemPool;
    u16 heldItemPoolCount;
    const enum HoldEffect *bannedHoldEffects;
    u16 bannedHoldEffectsCount;
};

static enum Species GetSpeciesCandidateForm(enum Species species, const struct RandomSpeciesGeneratorOptions *options, u16 arg1, u16 arg2);
static bool32 IsSpeciesAllowedByRandomBstArgs(enum Species species, u16 arg1, u16 arg2);
static u32 GetRandomMonSpeciesPoolSize(const struct RandomSpeciesGeneratorOptions *options);
static enum Species GetRandomMonSpeciesAtIndex(const struct RandomSpeciesGeneratorOptions *options, u32 index);
static enum Species SlowPickRandomMonSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize, u16 arg1, u16 arg2);
static enum Species FastPickRandomMonSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize, u16 arg1, u16 arg2);
static enum Item GetRandomMonHeldItemAtIndex(const struct RandomItemGeneratorOptions *options, u32 index);
static enum Item SlowPickRandomMonHeldItem(const struct RandomItemGeneratorOptions *options, u32 poolSize);
static enum Item FastPickRandomMonHeldItem(const struct RandomItemGeneratorOptions *options, u32 poolSize);
static enum PokeBall GetRandomMonBall(void);
static enum PokeBall ResolveRandomMonBall(enum PokeBall ball);
static bool32 MoveOrder(u16 moveA, u16 moveB);
static void SortMoves(enum Move *moves);
static bool32 IsMoveInMoveset(enum Move move, enum Move *moves, u32 count);
static void ResolveRandomMonMoves(enum Species species, enum Move *moves);

#if TESTING
#include "../test/random_mon_generator.h"
#else
#include "data/random_mon_generator.h"
#endif

static bool32 IsSpeciesBannedByRandomMonOptions(enum Species species, const struct RandomSpeciesGeneratorOptions *options, u16 arg1, u16 arg2)
{
    enum Species baseSpecies = GET_BASE_SPECIES_ID(species);
    const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[species];

    for (u32 i = 0; i < options->bannedSpeciesCount; i++)
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
    if (options->filterFunc != NULL && !options->filterFunc(species, arg1, arg2))
        return TRUE;

    return FALSE;
}

/*
* The below function uses arg1 and arg2 as BST centerpoint and BST leniency points.
* If a mon is within centerpoint +/- leniency, it's valid.
* This only applies if .filterFunc for your struct points to this function, and if
* the centerpoint/standard (arg1) is >= 100.
*/

static bool32 IsSpeciesAllowedByRandomBstArgs(enum Species species, u16 arg1, u16 arg2)
{
    u16 bstStandard = arg1;
    u16 bstLeniency = arg2;
    u16 bst = GetSpeciesBaseStatTotal(GET_BASE_SPECIES_ID(species));
    u16 minBst;
    u16 maxBst;

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
        return options->speciesPool[index];

    if (options->dexMode == RANDOM_MON_DEX_HOENN)
        return NationalPokedexNumToSpecies(HoennToNationalOrder(index + 1));

    return NationalPokedexNumToSpecies(index + 1);
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
    for (u32 i = 0; formTable[i] != FORM_SPECIES_END; i++)
    {
        const struct FormChange *formChanges = GetSpeciesFormChanges(formTable[i]);

        for (u32 j = 0; formChanges != NULL && formChanges[j].method != FORM_CHANGE_TERMINATOR; j++)
        {
            if (formChanges[j].targetSpecies == species)
                return TRUE;
        }
    }

    return FALSE;
}

static bool32 IsSpeciesInRandomMonFusionTables(enum Species species, const u16 *formTable)
{
    for (u32 i = 0; formTable[i] != FORM_SPECIES_END; i++)
    {
        const struct Fusion *fusionTable = gFusionTablePointers[formTable[i]];

        for (u32 j = 0; fusionTable != NULL && fusionTable[j].fusionStorageIndex != FUSION_TERMINATOR; j++)
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

static enum Species GetSpeciesCandidateForm(enum Species species, const struct RandomSpeciesGeneratorOptions *options, u16 arg1, u16 arg2)
{
    const u16 *formTable = GetSpeciesFormTable(species);
    u16 validFormsCount = 0;
    u16 validForms[RANDOM_MON_MAX_FORMS];

    if (!options->randomizeForms || formTable == NULL)
    {
        if (IsSpeciesBannedByRandomMonOptions(species, options, arg1, arg2))
            return SPECIES_NONE;
        return species;
    }

    for (u32 i = 0; formTable[i] != FORM_SPECIES_END; i++)
    {
        assertf(validFormsCount < ARRAY_COUNT(validForms), "too many valid forms for species %d", species)
        {
            break;
        }

        if (IsRandomMonFormAllowed(formTable[i], formTable)
         && !IsSpeciesBannedByRandomMonOptions(formTable[i], options, arg1, arg2))
            validForms[validFormsCount++] = i;
    }

    if (validFormsCount == 0)
        return SPECIES_NONE;

    return formTable[validForms[RandomUniform(RNG_RANDOM_MON_GEN, 0, validFormsCount - 1)]];
}

enum Species GetRandomSpecies(u32 optionId, u16 arg1, u16 arg2)
{
    const struct RandomSpeciesGeneratorOptions *options;
    u32 poolSize;
    u32 optionIndex = optionId;

    if (optionId >= SPECIES_RANDOMLY_GENERATED_START && optionId < SPECIES_GENERATOR_END)
        optionIndex = SPECIES_OPTION(optionId);

    assertf(optionIndex < RANDOM_SPECIES_OPTIONS_COUNT, "invalid random species option: %d", optionId)
    {
        return SPECIES_BULBASAUR;
    }

    options = &sRandomSpeciesGeneratorOptions[optionIndex];
    poolSize = GetRandomMonSpeciesPoolSize(options);

    if (options->speciesPool != NULL && options->speciesPoolCount != 0 && options->speciesPoolCount <= MAX_EXHAUSTIVE_SEARCH_POOL_SIZE)
        return SlowPickRandomMonSpecies(options, poolSize, arg1, arg2);

    return FastPickRandomMonSpecies(options, poolSize, arg1, arg2);
}

static enum Species SlowPickRandomMonSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize, u16 arg1, u16 arg2)
{
    u32 eligibleSpeciesCount = 0;
    enum Species eligibleSpecies[MAX_EXHAUSTIVE_SEARCH_POOL_SIZE];

    for (u32 i = 0; i < poolSize; i++)
    {
        enum Species species = GetSpeciesCandidateForm(GetRandomMonSpeciesAtIndex(options, i), options, arg1, arg2);
        if (species != SPECIES_NONE)
            eligibleSpecies[eligibleSpeciesCount++] = species;
    }

    if (eligibleSpeciesCount == 0)
    {
        errorf("Could not find a random species matching random mon options");
        return SPECIES_BULBASAUR;
    }

    return eligibleSpecies[RandomUniform(RNG_RANDOM_MON_GEN, 0, eligibleSpeciesCount - 1)];
}

static enum Species FastPickRandomMonSpecies(const struct RandomSpeciesGeneratorOptions *options, u32 poolSize, u16 arg1, u16 arg2)
{
    for (u32 i = 0; i < poolSize; i++)
    {
        enum Species species = GetSpeciesCandidateForm(GetRandomMonSpeciesAtIndex(options, RandomUniform(RNG_RANDOM_MON_GEN, 0, poolSize - 1)), options, arg1, arg2);
        if (species != SPECIES_NONE)
            return species;
    }

    errorf("Could not get random species after %d tries", poolSize);
    return SPECIES_BULBASAUR;
}

static bool32 IsRandomItemBannedHoldEffect(const struct RandomItemGeneratorOptions *options, enum HoldEffect holdEffect)
{
    for (u32 i = 0; i < options->bannedHoldEffectsCount; i++)
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
        return options->heldItemPoolCount != 0;

    return !IsRandomItemBannedHoldEffect(options, GetItemHoldEffect(item));
}

static enum Item GetRandomMonHeldItemAtIndex(const struct RandomItemGeneratorOptions *options, u32 index)
{
    if (options->heldItemPoolCount != 0)
        return options->heldItemPool[index];

    return index + 1;
}

static enum Item SlowPickRandomMonHeldItem(const struct RandomItemGeneratorOptions *options, u32 poolSize)
{
    u32 eligibleItemCount = 0;
    enum Item eligibleItems[MAX_EXHAUSTIVE_SEARCH_POOL_SIZE];

    for (u32 i = 0; i < poolSize; i++)
    {
        enum Item item = GetRandomMonHeldItemAtIndex(options, i);
        if (IsRandomMonHeldItemAllowed(options, item))
            eligibleItems[eligibleItemCount++] = item;
    }

    assertf(eligibleItemCount > 0, "Could not find a random held item matching random mon options")
    {
        return ITEM_NONE;
    }

    return eligibleItems[RandomUniform(RNG_RANDOM_MON_GEN, 0, eligibleItemCount - 1)];
}

static enum Item FastPickRandomMonHeldItem(const struct RandomItemGeneratorOptions *options, u32 poolSize)
{
    for (u32 i = 0; i < poolSize; i++)
    {
        enum Item item = GetRandomMonHeldItemAtIndex(options, RandomUniform(RNG_RANDOM_MON_GEN, 0, poolSize - 1));
        if (IsRandomMonHeldItemAllowed(options, item))
            return item;
    }

    errorf("Could not get random held item after %d tries", poolSize);

    return ITEM_NONE;
}

enum Item GetRandomItem(u32 optionId)
{
    const struct RandomItemGeneratorOptions *options;
    u32 optionIndex = optionId;
    u32 poolSize;

    if (optionId >= ITEM_RANDOMLY_GENERATED_START && optionId < ITEM_GENERATOR_END)
        optionIndex = ITEM_OPTION(optionId);

    assertf(optionIndex < RANDOM_ITEM_OPTIONS_COUNT, "invalid random item option: %d", optionId)
    {
        return ITEM_NONE;
    }

    options = &sRandomItemGeneratorOptions[optionIndex];

    if (options->heldItemPoolCount != 0)
    {
        assertf(options->heldItemPool != NULL, "positive heldItemPoolCount passed with empty heldItemPool")
        {
            return ITEM_NONE;
        }
        poolSize = options->heldItemPoolCount;
    }
    else
    {
        poolSize = ITEMS_COUNT - 1;
    }

    if (options->heldItemPoolCount != 0 && options->heldItemPoolCount <= MAX_EXHAUSTIVE_SEARCH_POOL_SIZE)
        return SlowPickRandomMonHeldItem(options, poolSize);

    return FastPickRandomMonHeldItem(options, poolSize);
}

static enum PokeBall GetRandomMonBall(void)
{
    return RandomUniform(RNG_RANDOM_MON_GEN, BALL_STRANGE, POKEBALL_COUNT - 1);
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

static bool32 MoveOrder(u16 moveA, u16 moveB)
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

static void SortMoves(enum Move *moves)
{
    u16 temp;

    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        for (u32 j = i; j < MAX_MON_MOVES; j++)
        {
            if (MoveOrder(moves[i], moves[j]))
                SWAP(moves[i], moves[j], temp);
        }
    }
}

static bool32 IsMoveInMoveset(enum Move move, enum Move *moves, u32 count)
{
    if (move == MOVE_NONE)
        return FALSE;

    for (u32 i = 0; i < count; i++)
    {
        if (moves[i] == move)
            return TRUE;
    }

    return FALSE;
}

#define IS_DUPLICATE_MOVE(move) IsMoveInMoveset(move, moves, i)

static void ResolveRandomMonMoves(enum Species species, enum Move *moves)
{
    u32 teachableCount = 0;
    const u16 *teachableLearnset = GetSpeciesTeachableLearnset(species);

    SortMoves(moves);

    while (teachableLearnset[teachableCount] != MOVE_UNAVAILABLE)
        teachableCount++;

    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] < MOVES_COUNT)
        {
            assertf(!IS_DUPLICATE_MOVE(moves[i]), "move %d was assigned twice", moves[i])
            {
                moves[i] = MOVE_NONE;
            }
            continue;
        }

        if (moves[i] == MOVE_RANDOM_TEACHABLE)
        {
            bool32 noCandidateFlag;
            enum Move candidate;

            if (teachableCount <= i)
            {
                noCandidateFlag = TRUE;
                for (u32 j = 0; j < teachableCount; j++)
                {
                    if (!IS_DUPLICATE_MOVE(teachableLearnset[j]))
                    {
                        noCandidateFlag = FALSE;
                        break;
                    }
                }

                if (noCandidateFlag)
                {
                    moves[i] = MOVE_NONE;
                    continue;
                }
            }

            do {
                candidate = teachableLearnset[RandomUniform(RNG_RANDOM_MON_GEN, 0, teachableCount - 1)];
            } while (IS_DUPLICATE_MOVE(candidate));

            moves[i] = candidate;
            continue;
        }

        assertf(moves[i] == MOVE_DEFAULT, "invalid move: %d", moves[i])
        {
            moves[i] = MOVE_NONE;
        }
    }

    SortMoves(moves);
}

void ResolveRandomMonGeneration(enum Species species, enum PokeBall *ball, enum Move *moves)
{
    *ball = ResolveRandomMonBall(*ball);
    ResolveRandomMonMoves(species, moves);
}

void ScrCmd_getrandomspecies(struct ScriptContext *ctx)
{
    u16 destVar = ScriptReadHalfword(ctx);
    u16 speciesOptionId = VarGet(ScriptReadHalfword(ctx));
    u16 arg1 = VarGet(ScriptReadHalfword(ctx));
    u16 arg2 = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    VarSet(destVar, GetRandomSpecies(speciesOptionId, arg1, arg2));
}

void ScrCmd_getrandomitem(struct ScriptContext *ctx)
{
    u16 destVar = ScriptReadHalfword(ctx);
    u16 itemOptionId = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    VarSet(destVar, GetRandomItem(itemOptionId));
}
