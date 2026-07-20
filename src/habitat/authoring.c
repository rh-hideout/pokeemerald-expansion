#include "global.h"
#include "habitat/authoring.h"
#include "habitat/finale.h"
#include "habitat/spots.h"
#include "constants/flags.h"
#include "constants/game_stat.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "constants/weather.h"

#define HABITAT_CONDITION_ALLOWED_FLAGS (HABITAT_COND_NEGATE | HABITAT_COND_EXACT_STAGE | 0xF0)

static bool32 IsValidSpecies(u16 species);
static bool32 IsValidItem(u16 item);
static bool32 IsValidComparator(u16 comparator);
static bool32 HasOnlyZeroUnusedParams(const struct HabitatCondition *condition, u16 firstUnused);
static bool32 ValidateConditionParameters(const struct HabitatCondition *condition);
static bool32 MarkPlacedCounterIds(const struct HabitatCondition *list, u8 *seen);

bool32 Habitat_ConditionTypeIsSupported(u8 type)
{
    switch (type)
    {
    case COND_ITEM_PLACED:
    case COND_ITEM_OFFERED:
    case COND_PARTY_SPECIES:
    case COND_PARTY_FRIENDSHIP:
    case COND_PARTY_MOVE:
    case COND_PARTY_NATURE:
    case COND_RESIDENT_SPECIES:
    case COND_RESIDENT_COUNT:
    case COND_TIME_OF_DAY:
    case COND_WEATHER:
    case COND_STORY_FLAG:
    case COND_DEX_COUNT:
    case COND_BERRY_MATURE:
    case COND_LIFETIME_STAT:
    case COND_SPOT_STATE:
    case COND_ZONE_COMPLETE:
    case COND_BATTLE_WIN:
    case COND_TALK_COUNT:
        return TRUE;
    case COND_NONE:
    case COND_ILLUSION:
    case COND_GROVE_RECIPE_DONE:
    default:
        return FALSE;
    }
}

bool32 Habitat_ValidateConditionList(const struct HabitatCondition *list,
                                     enum HabitatConditionUsage usage)
{
    u8 groupCounts[16] = {0};
    u32 i;

    if (list == NULL || usage > HABITAT_CONDITION_DEOXYS_FINALE)
        return FALSE;
    for (i = 0; i < HABITAT_MAX_CONDITIONS; i++)
    {
        const struct HabitatCondition *condition = &list[i];
        u8 group;

        if (condition->type == COND_NONE)
        {
            for (group = 1; group < ARRAY_COUNT(groupCounts); group++)
                if (groupCounts[group] == 1)
                    return FALSE;
            return TRUE;
        }
        if (!Habitat_ConditionTypeIsSupported(condition->type)
         || (condition->flags & ~HABITAT_CONDITION_ALLOWED_FLAGS) != 0
         || (condition->flags & HABITAT_COND_EXACT_STAGE) != 0
         || (condition->type == COND_BATTLE_WIN && usage != HABITAT_CONDITION_DEOXYS_FINALE)
         || !ValidateConditionParameters(condition))
            return FALSE;
        group = HABITAT_COND_GROUP_OF(condition);
        if (group != 0)
            groupCounts[group]++;
    }
    return FALSE;
}

bool32 Habitat_ValidateAuthoredData(void)
{
    u32 i, finaleBattleWins = 0;

    if (!Habitat_ValidateSpotTable(gHabitatSpots)
     || gHabitatDeoxysFinale.species != SPECIES_DEOXYS
     || !Habitat_ValidateConditionList(gHabitatDeoxysFinale.conditions,
                                       HABITAT_CONDITION_DEOXYS_FINALE))
        return FALSE;
    for (i = 0; gHabitatDeoxysFinale.conditions[i].type != COND_NONE; i++)
        if (gHabitatDeoxysFinale.conditions[i].type == COND_BATTLE_WIN)
            finaleBattleWins++;
    return finaleBattleWins == 1;
}

bool32 Habitat_ValidateSpotTable(const struct HabitatSpot *spots)
{
    u32 i, j;
    u8 placedCounterIds[(HABITAT_PLACED_CONDITION_CAP + 7) / 8] = {0};

    if (spots == NULL)
        return FALSE;
    for (i = 0; i < HABITAT_SPOT_COUNT; i++)
    {
        const struct HabitatSpot *spot = &spots[i];

        if (spot->spotId == 0xFFFF)
            return TRUE;
        if (spot->spotId >= HABITAT_SPOT_COUNT
         || !IsValidSpecies(spot->species)
         || spot->tier < 1 || spot->tier > 4
         || Habitat_GetZone(spot->zoneId) == NULL
         || spot->hintDormant == NULL || spot->hintStirring == NULL || spot->hintActive == NULL
         || !Habitat_ValidateConditionList(spot->appearConditions, HABITAT_CONDITION_SPOT_APPEAR)
         || !Habitat_ValidateConditionList(spot->befriendConditions, HABITAT_CONDITION_SPOT_BEFRIEND)
         || !MarkPlacedCounterIds(spot->appearConditions, placedCounterIds)
         || !MarkPlacedCounterIds(spot->befriendConditions, placedCounterIds))
            return FALSE;
        for (j = 0; j < i; j++)
            if (spots[j].spotId == spot->spotId)
                return FALSE;
    }
    return FALSE;
}

static bool32 IsValidSpecies(u16 species)
{
    return species != SPECIES_NONE && species < NUM_SPECIES;
}

static bool32 IsValidItem(u16 item)
{
    return item != ITEM_NONE && item < ITEMS_COUNT;
}

static bool32 IsValidComparator(u16 comparator)
{
    return comparator <= HABITAT_CMP_LT;
}

static bool32 HasOnlyZeroUnusedParams(const struct HabitatCondition *condition, u16 firstUnused)
{
    if (firstUnused <= 1 && condition->paramA != 0)
        return FALSE;
    if (firstUnused <= 2 && condition->paramB != 0)
        return FALSE;
    return firstUnused > 3 || condition->paramC == 0;
}

static bool32 ValidateConditionParameters(const struct HabitatCondition *condition)
{
    switch (condition->type)
    {
    case COND_ITEM_PLACED:
        return IsValidItem(condition->paramA) && condition->paramB != 0
            && condition->paramB <= 15
            && condition->paramC != 0 && condition->paramC <= HABITAT_PLACED_CONDITION_CAP;
    case COND_ITEM_OFFERED:
        return IsValidItem(condition->paramA) && condition->paramB != 0
            && condition->paramB <= MAX_BAG_ITEM_CAPACITY && HasOnlyZeroUnusedParams(condition, 3);
    case COND_PARTY_SPECIES:
        return IsValidSpecies(condition->paramA) && condition->paramB != 0
            && condition->paramB <= PARTY_SIZE && HasOnlyZeroUnusedParams(condition, 3);
    case COND_PARTY_FRIENDSHIP:
        return IsValidComparator(condition->paramA) && condition->paramB <= 255
            && HasOnlyZeroUnusedParams(condition, 3);
    case COND_PARTY_MOVE:
        return condition->paramA != MOVE_NONE && condition->paramA < MOVES_COUNT
            && HasOnlyZeroUnusedParams(condition, 2);
    case COND_PARTY_NATURE:
        return condition->paramA < NUM_NATURES && HasOnlyZeroUnusedParams(condition, 2);
    case COND_RESIDENT_SPECIES:
        return IsValidSpecies(condition->paramA)
            && (condition->paramB == 0 || Habitat_GetZone(condition->paramB) != NULL)
            && HasOnlyZeroUnusedParams(condition, 3);
    case COND_RESIDENT_COUNT:
        return (condition->paramA == HABITAT_TYPE_ANY
             || (condition->paramA > TYPE_NONE && condition->paramA < NUMBER_OF_MON_TYPES))
            && condition->paramB != 0 && condition->paramB <= NUM_SPECIES
            && HasOnlyZeroUnusedParams(condition, 3);
    case COND_TIME_OF_DAY:
        return condition->paramA < 24 && condition->paramB < 24
            && HasOnlyZeroUnusedParams(condition, 3);
    case COND_WEATHER:
        return condition->paramA < WEATHER_COUNT && HasOnlyZeroUnusedParams(condition, 2);
    case COND_STORY_FLAG:
        return condition->paramA < FLAGS_COUNT && HasOnlyZeroUnusedParams(condition, 2);
    case COND_DEX_COUNT:
        return IsValidComparator(condition->paramA) && condition->paramB <= NUM_SPECIES
            && HasOnlyZeroUnusedParams(condition, 3);
    case COND_BERRY_MATURE:
        return IsValidItem(condition->paramA)
            && (condition->paramB == 0 || Habitat_GetZone(condition->paramB) != NULL)
            && HasOnlyZeroUnusedParams(condition, 3);
    case COND_LIFETIME_STAT:
        return condition->paramA < NUM_GAME_STATS && IsValidComparator(condition->paramB);
    case COND_SPOT_STATE:
        return Habitat_GetSpot(condition->paramA) != NULL && condition->paramB <= HABITAT_STATE_BEFRIENDED
            && HasOnlyZeroUnusedParams(condition, 3);
    case COND_ZONE_COMPLETE:
        return Habitat_GetZone(condition->paramA) != NULL && HasOnlyZeroUnusedParams(condition, 2);
    case COND_BATTLE_WIN:
        return HasOnlyZeroUnusedParams(condition, 1);
    case COND_TALK_COUNT:
        return condition->paramA != 0 && HasOnlyZeroUnusedParams(condition, 2);
    default:
        return FALSE;
    }
}

static bool32 MarkPlacedCounterIds(const struct HabitatCondition *list, u8 *seen)
{
    u32 i;

    for (i = 0; list[i].type != COND_NONE; i++)
    {
        u16 counterId;
        u8 mask;

        if (list[i].type != COND_ITEM_PLACED)
            continue;
        counterId = list[i].paramC - 1;
        mask = 1 << (counterId & 7);
        if (seen[counterId / 8] & mask)
            return FALSE;
        seen[counterId / 8] |= mask;
    }
    return TRUE;
}
