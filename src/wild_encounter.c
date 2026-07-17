#include "global.h"
#include "battle_setup.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "event_data.h"
#include "fieldmap.h"
#include "fishing.h"
#include "follower_npc.h"
#include "field_player_avatar.h"
#include "item.h"
#include "link.h"
#include "mass_outbreak.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "ow_abilities.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#include "safari_zone.h"
#include "script.h"
#include "tv.h"
#include "wild_encounter.h"
#include "battle_debug.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "constants/abilities.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/weather.h"

extern const u8 EventScript_SprayWoreOff[];

#define MAX_ENCOUNTER_RATE 2880

#define UNKNOWN_WILDMON_INDEX 0xFF

#define NUM_FEEBAS_SPOTS 6

// Number of accessible fishing spots in each section of Route 119
// Each section is an area of the route between the y coordinates in sRoute119WaterTileData
#define NUM_FISHING_SPOTS_1 131
#define NUM_FISHING_SPOTS_2 167
#define NUM_FISHING_SPOTS_3 149
#define NUM_FISHING_SPOTS (NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2 + NUM_FISHING_SPOTS_3)

static u16 FeebasRandom(void);
static void FeebasSeedRng(u16 seed);
static u8 GetMaxLevelOfSpeciesInWildTable(const struct WildPokemon *wildMon, enum Species species, enum WildEncounterType area);
static u32 GetMinLevelAllowedByAbility(void);
static u32 GetMinLevelAllowedByRepel(void);

EWRAM_DATA static u32 sFeebasRngValue = 0;
EWRAM_DATA bool8 gIsFishingEncounter = 0;
EWRAM_DATA bool8 gIsSurfingEncounter = 0;
EWRAM_DATA u8 gChainFishingDexNavStreak = 0;

#include "data/wild_encounters.h"

const struct WildPokemon gWildFeebas = {20, 25, SPECIES_FEEBAS};

static const u16 sRoute119WaterTileData[] =
{
//yMin, yMax, numSpots in previous sections
     0,  45,  0,
    46,  91,  NUM_FISHING_SPOTS_1,
    92, 139,  NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2,
};

// Each fishing spot on Route 119 is given a number between 1 and NUM_FISHING_SPOTS inclusive.
// The number is determined by counting the valid fishing spots left to right top to bottom.
// The map is divided into three sections, with each section having a pre-counted number of
// fishing spots to start from to avoid counting a large number of spots at the bottom of the map.
// Note that a spot is considered valid if it is surfable and not a waterfall. To exclude all
// of the inaccessible water metatiles (so that they can't be selected as a Feebas spot) they
// use a different metatile that isn't actually surfable because it has MB_NORMAL instead.
// This function is given the coordinates and section of a fishing spot and returns which number it is.
static u16 GetFeebasFishingSpotId(s16 targetX, s16 targetY, u8 section)
{
    u16 x, y;
    u16 yMin = sRoute119WaterTileData[section * 3 + 0];
    u16 yMax = sRoute119WaterTileData[section * 3 + 1];
    u16 spotId = sRoute119WaterTileData[section * 3 + 2];

    for (y = yMin; y <= yMax; y++)
    {
        for (x = 0; x < gMapHeader.mapLayout->width; x++)
        {
            u8 behavior = MapGridGetMetatileBehaviorAt(x + MAP_OFFSET, y + MAP_OFFSET);
            if (MetatileBehavior_IsSurfableAndNotWaterfall(behavior) == TRUE)
            {
                spotId++;
                if (targetX == x && targetY == y)
                    return spotId;
            }
        }
    }
    return spotId + 1;
}

bool8 CheckFeebasAtCoords(s16 x, s16 y)
{
    u8 i;
    u16 feebasSpots[NUM_FEEBAS_SPOTS];
    u8 route119Section = 0;
    u16 spotId;

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_ROUTE119)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ROUTE119))
    {
        x -= MAP_OFFSET;
        y -= MAP_OFFSET;

        // Get which third of the map the player is in
        if (y >= sRoute119WaterTileData[3 * 0 + 0] && y <= sRoute119WaterTileData[3 * 0 + 1])
            route119Section = 0;
        if (y >= sRoute119WaterTileData[3 * 1 + 0] && y <= sRoute119WaterTileData[3 * 1 + 1])
            route119Section = 1;
        if (y >= sRoute119WaterTileData[3 * 2 + 0] && y <= sRoute119WaterTileData[3 * 2 + 1])
            route119Section = 2;

        // 50% chance of encountering Feebas (assuming this is a Feebas spot)
        if (Random() % 100 > 49)
            return FALSE;

        FeebasSeedRng(gSaveBlock1Ptr->dewfordTrends[0].rand);

        // Assign each Feebas spot to a random fishing spot.
        // Randomness is fixed depending on the seed above.
        for (i = 0; i != NUM_FEEBAS_SPOTS;)
        {
            feebasSpots[i] = FeebasRandom() % NUM_FISHING_SPOTS;
            if (feebasSpots[i] == 0)
                feebasSpots[i] = NUM_FISHING_SPOTS;

            // < 1 below is a pointless check, it will never be TRUE.
            // >= 4 to skip fishing spots 1-3, because these are inaccessible
            // spots at the top of the map, at (9,7), (7,13), and (15,16).
            // The first accessible fishing spot is spot 4 at (18,18).
            if (feebasSpots[i] < 1 || feebasSpots[i] >= 4)
                i++;
        }

        // Check which fishing spot the player is at, and see if
        // it matches any of the Feebas spots.
        spotId = GetFeebasFishingSpotId(x, y, route119Section);
        for (i = 0; i < NUM_FEEBAS_SPOTS; i++)
        {
            if (spotId == feebasSpots[i])
                return TRUE;
        }
    }
    return FALSE;
}

static u16 FeebasRandom(void)
{
    sFeebasRngValue = ISO_RANDOMIZE2(sFeebasRngValue);
    return sFeebasRngValue >> 16;
}

static void FeebasSeedRng(u16 seed)
{
    sFeebasRngValue = seed;
}

// LAND_WILD_COUNT
u32 ChooseWildMonIndex_Land(void)
{
    u8 wildMonIndex = 0;
    bool8 swap = FALSE;
    u8 rand = Random() % ENCOUNTER_CHANCE_LAND_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_0)
        wildMonIndex = 0;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_1)
        wildMonIndex = 1;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_2)
        wildMonIndex = 2;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_3)
        wildMonIndex = 3;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_4)
        wildMonIndex = 4;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_5)
        wildMonIndex = 5;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_6)
        wildMonIndex = 6;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_7)
        wildMonIndex = 7;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_8)
        wildMonIndex = 8;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        wildMonIndex = 9;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_10)
        wildMonIndex = 10;
    else
        wildMonIndex = 11;

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    if (swap)
        wildMonIndex = 11 - wildMonIndex;

    return wildMonIndex;
}

// WATER_WILD_COUNT
u32 ChooseWildMonIndex_Water(void)
{
    u32 wildMonIndex = 0;
    bool8 swap = FALSE;
    u8 rand = Random() % ENCOUNTER_CHANCE_WATER_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_0)
        wildMonIndex = 0;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_1)
        wildMonIndex = 1;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_2)
        wildMonIndex = 2;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_3)
        wildMonIndex = 3;
    else
        wildMonIndex = 4;

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    if (swap)
        wildMonIndex = 4 - wildMonIndex;

    return wildMonIndex;
}

// ROCK_WILD_COUNT
u32 ChooseWildMonIndex_Rocks(void)
{
    u32 wildMonIndex = 0;
    bool8 swap = FALSE;
    u8 rand = Random() % ENCOUNTER_CHANCE_ROCK_SMASH_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0)
        wildMonIndex = 0;
    else if (rand >= ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1)
        wildMonIndex = 1;
    else if (rand >= ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2)
        wildMonIndex = 2;
    else if (rand >= ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3)
        wildMonIndex = 3;
    else
        wildMonIndex = 4;

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    if (swap)
        wildMonIndex = 4 - wildMonIndex;

    return wildMonIndex;
}

// FISH_WILD_COUNT
static u32 ChooseWildMonIndex_Fishing(u8 rod)
{
    u8 wildMonIndex = 0;
    bool8 swap = FALSE;
    u8 rand = Random() % max(max(ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL, ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL),
                             ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL);

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    switch (rod)
    {
    case OLD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0)
            wildMonIndex = 0;
        else
            wildMonIndex = 1;

        if (swap)
            wildMonIndex = 1 - wildMonIndex;
        break;
    case GOOD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2)
            wildMonIndex = 2;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3)
            wildMonIndex = 3;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
            wildMonIndex = 4;

        if (swap)
            wildMonIndex = 6 - wildMonIndex;
        break;
    case SUPER_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5)
            wildMonIndex = 5;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6)
            wildMonIndex = 6;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7)
            wildMonIndex = 7;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 8;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9)
            wildMonIndex = 9;

        if (swap)
            wildMonIndex = 14 - wildMonIndex;
        break;
    }
    return wildMonIndex;
}

u8 ChooseWildMonLevel(const struct WildPokemon *wildPokemon, u8 wildMonIndex, enum WildEncounterType encounterType)
{
    u8 min;
    u8 max;

    if (LURE_STEP_COUNT == 0)
    {
        min = wildPokemon[wildMonIndex].minLevel;
        max = wildPokemon[wildMonIndex].maxLevel;

        if (DoesLeadingMonHaveAbilityEffect(gForceMaxLevelAbilities))
        {
            if (RandomPercentage(RNG_NONE, FORCE_MAX_LEVEL_ABILITY_CHANCE))
                return max;
        }
        return RandomUniform(RNG_NONE, min, max);
    }
    else
    {
        // Looks for the max level of all slots that share the same species as the selected slot.
        max = GetMaxLevelOfSpeciesInWildTable(wildPokemon, wildPokemon[wildMonIndex].species, encounterType);
        if (max > 0)
            return max + 1;
        else // Failsafe
            return wildPokemon[wildMonIndex].maxLevel + 1;
    }
}

u16 GetCurrentMapWildMonHeaderId(void)
{
    u16 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader *wildHeader = &gWildMonHeaders[i];
        if (wildHeader->mapGroup == MAP_GROUP(MAP_UNDEFINED))
            break;

        if (gWildMonHeaders[i].mapGroup == gSaveBlock1Ptr->location.mapGroup &&
            gWildMonHeaders[i].mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_ALTERING_CAVE) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ALTERING_CAVE))
            {
                u16 alteringCaveId = VarGet(VAR_ALTERING_CAVE_WILD_SET);
                if (alteringCaveId >= NUM_ALTERING_CAVE_TABLES)
                    alteringCaveId = 0;

                i += alteringCaveId;
            }

            return i;
        }
    }

    return HEADER_NONE;
}

enum TimeOfDay GetTimeOfDayForEncounters(u32 headerId, enum WildEncounterType encounterType)
{
    const struct WildPokemonInfo *wildMonInfo;
    enum TimeOfDay timeOfDay = GetTimeOfDay();

    if (!OW_TIME_OF_DAY_ENCOUNTERS)
        return TIME_OF_DAY_DEFAULT;

     wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay][encounterType];

    if (wildMonInfo == NULL && !OW_TIME_OF_DAY_DISABLE_FALLBACK)
        return OW_TIME_OF_DAY_FALLBACK;
    else
        return GenConfigTimeOfDay(timeOfDay);
}

static u8 PickWildMonNature(enum Species species)
{
    u8 i;
    struct Pokeblock *safariPokeblock;
    u8 natures[NUM_NATURES];

    if (GetSafariZoneFlag() == TRUE && RandomPercentage(RNG_NONE, 80))
    {
        safariPokeblock = SafariZoneGetActivePokeblock();
        if (safariPokeblock != NULL)
        {
            for (i = 0; i < NUM_NATURES; i++)
                natures[i] = i;
            Shuffle(natures, NUM_NATURES, sizeof(natures[0]));
            for (i = 0; i < NUM_NATURES; i++)
            {
                if (PokeblockGetGain(natures[i], safariPokeblock) > 0)
                    return natures[i];
            }
        }
    }

    return GetSynchronizedNature(WILDMON_ORIGIN, species);
}

static void CreateWildMonInSlot(enum Species species, u8 level, u32 slot)
{
    ZeroEnemyPartyMons();
    u32 personality = GetMonPersonality(species, GetSynchronizedGender(WILDMON_ORIGIN, species), PickWildMonNature(species), RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gParties[B_TRAINER_OPPONENT_A][slot], species, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gParties[B_TRAINER_OPPONENT_A][slot]);
}

void CreateWildMon(enum Species species, u8 level)
{
    CreateWildMonInSlot(species, level, 0);
}

const u8 gEncounterTableSizes[WILD_ENCOUNTER_TYPES_COUNT] = {
    [WILD_LAND_MONS] = LAND_WILD_COUNT,
    [WILD_WATER_MONS] = WATER_WILD_COUNT,
    [WILD_ROCK_SMASH_MONS] = ROCK_WILD_COUNT,
    [WILD_FISHING_MONS] = FISH_WILD_COUNT,
    [WILD_HIDDEN_MONS] = HIDDEN_WILD_COUNT,
};

typedef u32 (*ChooseWildMonIndexFunction)(void);

static ChooseWildMonIndexFunction sEncounterTypeFunctions[WILD_ENCOUNTER_TYPES_COUNT] = {
    [WILD_LAND_MONS] = ChooseWildMonIndex_Land,
    [WILD_WATER_MONS] = ChooseWildMonIndex_Water,
    [WILD_ROCK_SMASH_MONS] = ChooseWildMonIndex_Rocks,
    [WILD_FISHING_MONS] = NULL,
    [WILD_HIDDEN_MONS] = ChooseHiddenMonIndex,
};

u32 ChooseWildMonIndex(enum WildEncounterType encounterType)
{
    return sEncounterTypeFunctions[encounterType]();
}

static bool8 TryGetRandomWildMonIndexByType(const struct WildPokemon *wildMon, enum Type type, u32 tableSize)
{
    u32 validIndexes[tableSize];
    u32 validMonCount = 0;

    for (u32 i = 0; i < tableSize; i++)
    {
        if (GetSpeciesType(wildMon[i].species, 0) == type || GetSpeciesType(wildMon[i].species, 1) == type)
            validIndexes[validMonCount++] = i;
    }

    if (validMonCount == 0 || validMonCount == tableSize)
        return UNKNOWN_WILDMON_INDEX;

    return validIndexes[RandomUniform(RNG_NONE, 0, validMonCount)];
}

void GenerateWildMon(const struct WildPokemonInfo *wildMonInfo, enum WildEncounterType encounterType, u32 minLevel, u32 slot)
{
    u8 wildMonIndex = UNKNOWN_WILDMON_INDEX;
    u8 level;

    enum Type type = GetWeightedTypeForWildmonEncounter();
    if (type != TYPE_NONE)
        wildMonIndex = TryGetRandomWildMonIndexByType(wildMonInfo->wildPokemon, type, gEncounterTableSizes[encounterType]);

    if (wildMonIndex == UNKNOWN_WILDMON_INDEX)
        wildMonIndex = ChooseWildMonIndex(encounterType);

    level = ChooseWildMonLevel(wildMonInfo->wildPokemon, wildMonIndex, encounterType);
    if (level >= minLevel)
        CreateWildMonInSlot(wildMonInfo->wildPokemon[wildMonIndex].species, level, slot);
}

static u16 GenerateFishingWildMon(const struct WildPokemonInfo *wildMonInfo, u8 rod)
{
    u8 wildMonIndex = ChooseWildMonIndex_Fishing(rod);
    enum Species wildMonSpecies = wildMonInfo->wildPokemon[wildMonIndex].species;
    u8 level = ChooseWildMonLevel(wildMonInfo->wildPokemon, wildMonIndex, WILD_FISHING_MONS);

    UpdateChainFishingStreak();
    CreateWildMon(wildMonSpecies, level);
    return wildMonSpecies;
}

static bool8 EncounterOddsCheck(u16 encounterRate)
{
    if (RandomChance(RNG_NONE, encounterRate, MAX_ENCOUNTER_RATE))
        return TRUE;
    else
        return FALSE;
}

static bool32 HasRepellingHeldItem()
{
    enum Item heldItem = GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HELD_ITEM);
    if (gItemsInfo[heldItem].holdEffect == HOLD_EFFECT_REPEL)
        return TRUE;
    return FALSE;
}

// Returns true if it will try to create a wild encounter.
static bool8 WildEncounterCheck(u32 encounterRate, bool8 ignoreAbility)
{
    encounterRate *= 16;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        encounterRate = encounterRate * 80 / 100;
    if (FlagGet(FLAG_SYS_ENC_UP_ITEM))
        encounterRate = encounterRate * 3 / 2;
    else if (FlagGet(FLAG_SYS_ENC_DOWN_ITEM))
        encounterRate /= 2;
    if (HasRepellingHeldItem())
        encounterRate = encounterRate * 2 / 3;
    if (LURE_STEP_COUNT != 0)
        encounterRate *= 2;
    if (!ignoreAbility)
    {
        if (DoesLeadingMonHaveAbilityEffect(gEncounterReducingAbilities))
        {
            if (InBattlePyramid())
                encounterRate = encounterRate * 3 / 4;
            else
                encounterRate /= 2;
        }
        else if (DoesLeadingMonHaveAbilityEffect(gEncounterIncreasingAbilities))
        {
            if (InBattlePyramid())
                encounterRate = encounterRate * 3 / 2;
            else
                encounterRate *= 2;
        }
        else if (gSaveBlock1Ptr->weather == WEATHER_SANDSTORM && DoesLeadingMonHaveAbilityEffect(gHiddenBySandstormAbilities))
        {
            encounterRate /= 2;
        }
        else if (gSaveBlock1Ptr->weather == WEATHER_SANDSTORM && DoesLeadingMonHaveAbilityEffect(gHiddenBySnowAbilities))
        {
            encounterRate /= 2;
        }
    }
    if (encounterRate > MAX_ENCOUNTER_RATE)
        encounterRate = MAX_ENCOUNTER_RATE;
    return EncounterOddsCheck(encounterRate);
}

bool8 AreLegendariesInSootopolisPreventingEncounters(void)
{
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(MAP_SOOTOPOLIS_CITY)
     || gSaveBlock1Ptr->location.mapNum != MAP_NUM(MAP_SOOTOPOLIS_CITY))
    {
        return FALSE;
    }

    return FlagGet(FLAG_LEGENDARIES_IN_SOOTOPOLIS);
}

enum WildEncounterType GetStandardWildEncounterType(u32 metatileBehavior)
{
    if (MetatileBehavior_IsLandWildEncounter(metatileBehavior))
        return WILD_LAND_MONS;
    else if (MetatileBehavior_IsWaterWildEncounter(metatileBehavior))
        return WILD_WATER_MONS;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING) && MetatileBehavior_IsBridgeOverWater(metatileBehavior))
        return WILD_WATER_MONS;
    else
        return WILD_ENCOUNTER_TYPES_COUNT;
}

const struct WildPokemonInfo *GetWildPokemonInfo(enum WildEncounterType encounterType)
{
    if (encounterType == WILD_ENCOUNTER_TYPES_COUNT)
        return NULL;
    if (encounterType == WILD_WATER_MONS && AreLegendariesInSootopolisPreventingEncounters())
        return NULL;
    u32 headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
        return NULL;
    enum TimeOfDay timeOfDay = GetTimeOfDayForEncounters(headerId, encounterType);
    return gWildMonHeaders[headerId].encounterTypes[timeOfDay][encounterType];
}

static void GenerateStandardWildmons(const struct WildPokemonInfo *wildPokemonInfo, enum WildEncounterType encounterType, u32 minLevel)
{
    GenerateWildMon(wildPokemonInfo, encounterType, minLevel, 0);
    if (CheckForDoubleWildBattle())
    {
        gBattleTypeFlags = BATTLE_TYPE_DOUBLE;
        GenerateWildMon(wildPokemonInfo, encounterType, minLevel, 1);
    }
}

u32 GetMinLevelEncounter(void)
{
    u32 minLevel = GetMinLevelAllowedByAbility();
    if (InBattlePike() || InBattlePyramid())
        return minLevel;
    return max(minLevel, GetMinLevelAllowedByRepel());
}

static bool32 StandardWildEncounterCheck(const struct WildPokemonInfo *wildPokemonInfo, bool32 isForced)
{
    u32 encounterRate;
    if (InBattlePike())
        encounterRate = GetBattlePikeEncounterRate();
    else if (InBattlePyramid())
        encounterRate = GetBattlePyramidEncounterRate();
    else if (wildPokemonInfo == NULL)
        return FALSE;
    else
        encounterRate = wildPokemonInfo->encounterRate;
    if (isForced)
        return TRUE;
    return WildEncounterCheck(encounterRate, FALSE);
}

bool32 StandardWildEncounter(u32 metatileBehavior, bool32 isForced)
{
    u32 minLevel;
    ZeroEnemyPartyMons();
    gBattleTypeFlags = 0;
    if (isForced)
        minLevel = MIN_LEVEL;
    else
        minLevel = GetMinLevelEncounter();

    enum WildEncounterType encounterType = GetStandardWildEncounterType(metatileBehavior);
    const struct WildPokemonInfo *wildPokemonInfo = GetWildPokemonInfo(encounterType);
    if (!StandardWildEncounterCheck(wildPokemonInfo, isForced))
        return FALSE;

    if (InBattlePike())
        GenerateBattlePikeWildMon(minLevel);
    else if (InBattlePyramid())
         GenerateBattlePyramidWildMon(minLevel);
    else if (CheckForRoamerEncounter())
        GenerateRoamerMon(gEncounteredRoamerIndex, minLevel);
    else if (encounterType == WILD_LAND_MONS && CheckForMassOutbreakEncounter())
        GenerateMassOutbreakMon(minLevel);
    else
        GenerateStandardWildmons(wildPokemonInfo, encounterType, minLevel);

    if (!GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP))
        return FALSE;
    BattleSetup_StartWildBattle();
    return TRUE;
}


static bool32 TryRockSmashWildEncounter(void)
{
    const struct WildPokemonInfo *wildPokemonInfo = GetWildPokemonInfo(WILD_ROCK_SMASH_MONS);
    if (wildPokemonInfo == NULL)
        return FALSE;

    if (!WildEncounterCheck(wildPokemonInfo->encounterRate, TRUE))
        return FALSE;

    GenerateStandardWildmons(wildPokemonInfo, WILD_ROCK_SMASH_MONS, FALSE);
    if (!GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP))
        return FALSE;
    BattleSetup_StartWildBattle();
    return TRUE;
}

void RockSmashWildEncounter(void)
{
    ZeroEnemyPartyMons();
    gSpecialVar_Result = TryRockSmashWildEncounter();
}

bool32 SweetScentWildEncounter(void)
{
    s16 x, y;
    PlayerGetDestCoords(&x, &y);
    u32 metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    return StandardWildEncounter(metatileBehavior, TRUE);
}

bool8 DoesCurrentMapHaveFishingMons(void)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_FISHING_MONS);

    if (headerId != HEADER_NONE && gWildMonHeaders[headerId].encounterTypes[timeOfDay][WILD_FISHING_MONS] != NULL)
        return TRUE;
    return FALSE;
}

void FishingWildEncounter(u8 rod)
{
    enum Species species;
    u32 headerId;
    s16 x, y;
    enum TimeOfDay timeOfDay;

    gIsFishingEncounter = TRUE;
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    if (CheckFeebasAtCoords(x, y) == TRUE)
    {
        u8 level = ChooseWildMonLevel(&gWildFeebas, 0, WILD_FISHING_MONS);

        species = gWildFeebas.species;
        CreateWildMon(species, level);
    }
    else
    {
        headerId = GetCurrentMapWildMonHeaderId();
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_FISHING_MONS);
        species = GenerateFishingWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay][WILD_FISHING_MONS], rod);
    }

    IncrementGameStat(GAME_STAT_FISHING_ENCOUNTERS);
    SetPokemonAnglerSpecies(species);
    BattleSetup_StartWildBattle();
}

u16 GetLocalWildMon(bool8 *isWaterMon)
{
    *isWaterMon = FALSE;

    const struct WildPokemonInfo *landMonsInfo = GetWildPokemonInfo(WILD_LAND_MONS);
    const struct WildPokemonInfo *waterMonsInfo = GetWildPokemonInfo(WILD_WATER_MONS);

    if (landMonsInfo == NULL && waterMonsInfo == NULL)
        return SPECIES_NONE;
    else if (landMonsInfo != NULL && waterMonsInfo == NULL)
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    else if (landMonsInfo == NULL && waterMonsInfo != NULL)
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_Water()].species;
    }
    // Either land or water Pokémon
    if (RandomPercentage(RNG_NONE, 80))
    {
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    }
    else
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_Water()].species;
    }
}

u16 GetLocalWaterMon(void)
{
    const struct WildPokemonInfo *waterMonsInfo = GetWildPokemonInfo(WILD_WATER_MONS);
    if (waterMonsInfo)
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_Water()].species;
    return SPECIES_NONE;
}

bool8 UpdateRepelCounter(void)
{
    u16 repelLureVar = VarGet(VAR_REPEL_STEP_COUNT);
    u16 steps = REPEL_LURE_STEPS(repelLureVar);
    bool32 isLure = IS_LAST_USED_LURE(repelLureVar);

    if (InBattlePike() || CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
        return FALSE;
    if (InUnionRoom() == TRUE)
        return FALSE;

    if (steps != 0)
    {
        steps--;
        if (!isLure)
        {
            VarSet(VAR_REPEL_STEP_COUNT, steps);
            if (steps == 0)
            {
                ScriptContext_SetupScript(EventScript_SprayWoreOff);
                return TRUE;
            }
        }
        else
        {
            VarSet(VAR_REPEL_STEP_COUNT, steps | REPEL_LURE_MASK);
            if (steps == 0)
            {
                ScriptContext_SetupScript(EventScript_SprayWoreOff);
                return TRUE;
            }
        }

    }
    return FALSE;
}

static u32 GetMinLevelAllowedByRepel(void)
{
    u8 i;

    if (!REPEL_STEP_COUNT)
        return MIN_LEVEL;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (I_REPEL_INCLUDE_FAINTED == GEN_1 || I_REPEL_INCLUDE_FAINTED >= GEN_6 || GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HP))
        {
            if (!GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_IS_EGG))
                return GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_LEVEL);
        }
    }

    return MIN_LEVEL;
}

static u32 GetMinLevelAllowedByAbility(void)
{
    if (DoesLeadingMonHaveAbilityEffect(gBlockLowLevelEncounterAbilities))
    {
        u32 playerMonLevel = GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_LEVEL);
        if (playerMonLevel > 5 && RandomPercentage(RNG_NONE, BLOCK_LOW_LEVEL_ABILITY_CHANCE))
            return playerMonLevel - 5;
    }
    return MIN_LEVEL;
}

#include "data.h"

static u8 GetMaxLevelOfSpeciesInWildTable(const struct WildPokemon *wildMon, enum Species species, enum WildEncounterType area)
{
    u32 maxLevel = 0;
    u32 numMon = gEncounterTableSizes[area];

    for (u32 i = 0; i < numMon; i++)
    {
        if (wildMon[i].species == species && wildMon[i].maxLevel > maxLevel)
            maxLevel = wildMon[i].maxLevel;
    }

    return maxLevel;
}

bool32 CheckForDoubleWildBattle(void)
{
    if (GetSafariZoneFlag())
        return FALSE;
    if (WE_DOUBLE_WILD_REQUIRE_2_MONS && GetMonsStateToDoubles() != PLAYER_HAS_TWO_USABLE_MONS)
        return FALSE;
    if (FollowerNPCIsBattlePartner() && FNPC_FLAG_PARTNER_WILD_BATTLES != 0
     && (FNPC_FLAG_PARTNER_WILD_BATTLES == FNPC_ALWAYS || FlagGet(FNPC_FLAG_PARTNER_WILD_BATTLES)) && FNPC_NPC_FOLLOWER_WILD_BATTLE_VS_2 == TRUE)
        return TRUE;
    else if (FlagGet(WE_FLAG_FORCE_DOUBLE_WILD))
        return TRUE;
    else if (RandomPercentage(RNG_NONE, WE_DOUBLE_WILD_CHANCE))
        return TRUE;
    return FALSE;
}

bool8 StandardWildEncounter_Debug(void)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_LAND_MONS);

    GenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay][WILD_LAND_MONS], WILD_LAND_MONS, MIN_LEVEL, 0);
    DoStandardWildBattle_Debug();
    return TRUE;
}

u32 ChooseHiddenMonIndex(void)
{
    #ifdef ENCOUNTER_CHANCE_HIDDEN_MONS_TOTAL
        u8 rand = Random() % ENCOUNTER_CHANCE_HIDDEN_MONS_TOTAL;

        if (rand < ENCOUNTER_CHANCE_HIDDEN_MONS_SLOT_0)
            return 0;
        else if (rand >= ENCOUNTER_CHANCE_HIDDEN_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_HIDDEN_MONS_SLOT_1)
            return 1;
        else
            return 2;
    #else
        return UNKNOWN_WILDMON_INDEX;
    #endif
}

bool32 MapHasNoEncounterData(void)
{
    return (GetCurrentMapWildMonHeaderId() == HEADER_NONE);
}
