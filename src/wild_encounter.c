#include "global.h"
#include "battle_setup.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "event_data.h"
#include "fieldmap.h"
#include "fishing.h"
#include "follower_npc.h"
#include "random.h"
#include "field_player_avatar.h"
#include "link.h"
#include "malloc.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "ow_synchronize.h"
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

#define NUM_FEEBAS_SPOTS 6

// Number of accessible fishing spots in each section of Route 119
// Each section is an area of the route between the y coordinates in sRoute119WaterTileData
#define NUM_FISHING_SPOTS_1 131
#define NUM_FISHING_SPOTS_2 167
#define NUM_FISHING_SPOTS_3 149
#define NUM_FISHING_SPOTS (NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2 + NUM_FISHING_SPOTS_3)

#define WILD_CHECK_REPEL    (1 << 0)
#define WILD_CHECK_KEEN_EYE (1 << 1)

struct WildMonFilterArg {
    u8 type;
};

typedef bool32 (WildMonFilterFunc)(u32 species, struct WildMonFilterArg);

static u16 FeebasRandom(void);
static void FeebasSeedRng(u16 seed);
static bool8 IsWildLevelAllowedByRepel(u8 level);
static void ApplyFluteEncounterRateMod(u32 *encRate);
static void ApplyCleanseTagEncounterRateMod(u32 *encRate);
static u8 GetMaxLevelOfSpeciesInWildTable(const struct WildPokemonInfo *wildMonInfo, u16 species);
static bool8 IsAbilityAllowingEncounter(u8 level);

EWRAM_DATA static u8 sWildEncountersDisabled = 0;
EWRAM_DATA static u32 sFeebasRngValue = 0;
EWRAM_DATA bool8 gIsFishingEncounter = 0;
EWRAM_DATA bool8 gIsSurfingEncounter = 0;
EWRAM_DATA u8 gChainFishingDexNavStreak = 0;

#include "data/wild_encounters.h"

static const struct WildPokemonInfo sWildFeebas = {
    .encounterRate = 0,
    .numSlots = 1,
    .totalWeight = 1,
    .wildPokemon = {
        { .minLevel = 20, .maxLevel = 25, .species = SPECIES_FEEBAS, .weight = 1 }
    }
};

static const u16 sRoute119WaterTileData[] =
{
//yMin, yMax, numSpots in previous sections
     0,  45,  0,
    46,  91,  NUM_FISHING_SPOTS_1,
    92, 139,  NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2,
};

void DisableWildEncounters(bool8 disabled)
{
    sWildEncountersDisabled = disabled;
}

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

static bool8 CheckFeebas(void)
{
    u8 i;
    u16 feebasSpots[NUM_FEEBAS_SPOTS];
    s16 x, y;
    u8 route119Section = 0;
    u16 spotId;

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_ROUTE119)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ROUTE119))
    {
        GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
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

static u32 ChooseTypeFilteredWildMonIndex(const struct WildPokemonInfo *encounterTable, enum Type type, bool32 equalizeWeights)
{
    struct FilteredSlot {
        u16 index;
        u16 threshold;
    };

    u32 filteredCount = 0;
    u32 filteredWeightTotal = 0;
    struct FilteredSlot *filteredSlots = NULL;

    filteredSlots = Alloc(sizeof(struct FilteredSlot) * encounterTable->numSlots);
    for (u32 i = 0; i < encounterTable->numSlots; i++)
    {
        const struct WildPokemon *slot = &encounterTable->wildPokemon[i];
        if (IsSpeciesOfType(slot->species, type))
        {
            filteredWeightTotal += slot->weight;
            filteredSlots[filteredCount++] = (struct FilteredSlot) {
                .index = i,
                .threshold = filteredWeightTotal
            };
        }
    }

    u32 index;
    if (equalizeWeights && filteredCount > 0)
    {
        u32 filteredIdx = (Random() * filteredCount) >> 16;
        index = filteredSlots[filteredIdx].index;
    }
    else if (filteredWeightTotal > 0)
    {
        u32 val = (Random() * filteredWeightTotal) >> 16;
        u32 filteredIdx = 0;
        while (val >= filteredSlots[filteredIdx].threshold)
            filteredIdx++;
        index = filteredSlots[filteredIdx].index;
    }
    else
    {
        index = ChooseWildMonIndex(encounterTable);
    }

    Free(filteredSlots);
    return index;
}

inline u32 ChooseWildMonIndex(const struct WildPokemonInfo *encounterTable)
{
    u32 val = (Random() * encounterTable->totalWeight) >> 16;
    u32 index = 0;
    u32 cumulativeWeight = encounterTable->wildPokemon[0].weight;
    while (val >= cumulativeWeight) {
        index++;
        cumulativeWeight += encounterTable->wildPokemon[index].weight;
    }
    return index;
}

static u8 ChooseWildMonLevel(const struct WildPokemonInfo *wildMonInfo, u8 wildMonIndex)
{
    u8 min;
    u8 max;
    u8 range;
    u8 rand;

    if (LURE_STEP_COUNT == 0)
    {
        // Make sure minimum level is less than maximum level
        if (wildMonInfo->wildPokemon[wildMonIndex].maxLevel >= wildMonInfo->wildPokemon[wildMonIndex].minLevel)
        {
            min = wildMonInfo->wildPokemon[wildMonIndex].minLevel;
            max = wildMonInfo->wildPokemon[wildMonIndex].maxLevel;
        }
        else
        {
            min = wildMonInfo->wildPokemon[wildMonIndex].maxLevel;
            max = wildMonInfo->wildPokemon[wildMonIndex].minLevel;
        }
        range = max - min + 1;
        rand = Random() % range;

        // check ability for max level mon
        if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        {
            enum Ability ability = GetMonAbility(&gPlayerParty[0]);
            if (ability == ABILITY_HUSTLE || ability == ABILITY_VITAL_SPIRIT || ability == ABILITY_PRESSURE)
            {
                if (Random() % 2 == 0)
                    return max;

                if (rand != 0)
                    rand--;
            }
        }
        return min + rand;
    }
    else
    {
        // Looks for the max level of all slots that share the same species as the selected slot.
        max = GetMaxLevelOfSpeciesInWildTable(wildMonInfo, wildMonInfo->wildPokemon[wildMonIndex].species);
        if (max > 0)
            return max + 1;
        else // Failsafe
            return wildMonInfo->wildPokemon[wildMonIndex].maxLevel + 1;
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

enum TimeOfDay GetTimeOfDayForEncounters(u32 headerId, enum WildPokemonArea area)
{
    const struct WildPokemonInfo *wildMonInfo;
    enum TimeOfDay timeOfDay = GetTimeOfDay();

    if (!OW_TIME_OF_DAY_ENCOUNTERS)
        return TIME_OF_DAY_DEFAULT;

    if (InBattlePike() || CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
        return OW_TIME_OF_DAY_FALLBACK;

    switch (area)
    {
    default:
    case WILD_AREA_LAND:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
        break;
    case WILD_AREA_WATER:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;
        break;
    case WILD_AREA_ROCKS:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].rockSmashMonsInfo;
        break;
    case WILD_AREA_FISHING_OLD_ROD:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].fishingMonsOldRodInfo;
        break;
    case WILD_AREA_FISHING_GOOD_ROD:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].fishingMonsGoodRodInfo;
        break;
    case WILD_AREA_FISHING_SUPER_ROD:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].fishingMonsSuperRodInfo;
        break;
    case WILD_AREA_HIDDEN:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].hiddenMonsInfo;
        break;
    }

    if (wildMonInfo == NULL && !OW_TIME_OF_DAY_DISABLE_FALLBACK)
        return OW_TIME_OF_DAY_FALLBACK;
    else
        return GenConfigTimeOfDay(timeOfDay);
}

static u8 PickWildMonNature(u32 species)
{
    u8 i;
    struct Pokeblock *safariPokeblock;
    u8 natures[NUM_NATURES];

    if (GetSafariZoneFlag() == TRUE && Random() % 100 < 80)
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

void CreateWildMon(u16 species, u8 level)
{
    ZeroEnemyPartyMons();
    u32 personality = GetMonPersonality(species, GetSynchronizedGender(WILDMON_ORIGIN, species), PickWildMonNature(species), RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gEnemyParty[0], species, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[0]);
}

static bool8 TryGenerateWildMon(const struct WildPokemonInfo *wildMonInfo, enum WildPokemonArea area, u8 flags)
{
    u8 wildMonIndex = 0;
    u8 level;

    if (wildMonInfo->numSlots == 0)
        return FALSE;

    if ((area == WILD_AREA_LAND || area == WILD_AREA_WATER)
        && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG)
        && Random() % 2)
    {
        switch (GetMonAbility(&gPlayerParty[0]))
        {
        case ABILITY_MAGNET_PULL:
            wildMonIndex = ChooseTypeFilteredWildMonIndex(wildMonInfo, TYPE_STEEL, TRUE);
            break;
        case ABILITY_STATIC:
            wildMonIndex = ChooseTypeFilteredWildMonIndex(wildMonInfo, TYPE_ELECTRIC, TRUE);
            break;
        case ABILITY_LIGHTNING_ROD:
            if (OW_LIGHTNING_ROD >= GEN_8)
                wildMonIndex = ChooseTypeFilteredWildMonIndex(wildMonInfo, TYPE_ELECTRIC, TRUE);
            else
                ChooseWildMonIndex(wildMonInfo);
            break;
        case ABILITY_FLASH_FIRE:
            if (OW_FLASH_FIRE >= GEN_8)
                wildMonIndex = ChooseTypeFilteredWildMonIndex(wildMonInfo, TYPE_FIRE, TRUE);
            else
                ChooseWildMonIndex(wildMonInfo);
            break;
        case ABILITY_HARVEST:
            if (OW_HARVEST >= GEN_8)
                wildMonIndex = ChooseTypeFilteredWildMonIndex(wildMonInfo, TYPE_GRASS, TRUE);
            else
                ChooseWildMonIndex(wildMonInfo);
            break;
        case ABILITY_STORM_DRAIN:
            if (OW_STORM_DRAIN >= GEN_8)
                wildMonIndex = ChooseTypeFilteredWildMonIndex(wildMonInfo, TYPE_WATER, TRUE);
            else
                ChooseWildMonIndex(wildMonInfo);
            break;
        default:
            wildMonIndex = ChooseWildMonIndex(wildMonInfo);
            break;
        }
    }
    else
        wildMonIndex = ChooseWildMonIndex(wildMonInfo);

    level = ChooseWildMonLevel(wildMonInfo, wildMonIndex);
    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(level))
        return FALSE;
    if (gMapHeader.mapLayoutId != LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS && flags & WILD_CHECK_KEEN_EYE && !IsAbilityAllowingEncounter(level))
        return FALSE;

    CreateWildMon(wildMonInfo->wildPokemon[wildMonIndex].species, level);
    return TRUE;
}

static u16 GenerateFishingWildMon(const struct WildEncounterTypes *encTypes, enum FishingRod rod)
{
    const struct WildPokemonInfo *wildMonInfo = NULL;
    switch (rod)
    {
        case OLD_ROD:
            wildMonInfo = encTypes->fishingMonsOldRodInfo;
            break;
        case GOOD_ROD:
            wildMonInfo = encTypes->fishingMonsGoodRodInfo;
            break;
        case SUPER_ROD:
            wildMonInfo = encTypes->fishingMonsSuperRodInfo;
            break;
    }
    u8 wildMonIndex = ChooseWildMonIndex(wildMonInfo);
    u16 wildMonSpecies = wildMonInfo->wildPokemon[wildMonIndex].species;
    u8 level = ChooseWildMonLevel(wildMonInfo, wildMonIndex);

    UpdateChainFishingStreak();
    CreateWildMon(wildMonSpecies, level);
    return wildMonSpecies;
}

static bool8 SetUpMassOutbreakEncounter(u8 flags)
{
    u16 i;

    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(gSaveBlock1Ptr->outbreakPokemonLevel))
        return FALSE;

    CreateWildMon(gSaveBlock1Ptr->outbreakPokemonSpecies, gSaveBlock1Ptr->outbreakPokemonLevel);
    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(&gEnemyParty[0], gSaveBlock1Ptr->outbreakPokemonMoves[i], i);

    return TRUE;
}

static bool8 DoMassOutbreakEncounterTest(void)
{
    if (gSaveBlock1Ptr->outbreakPokemonSpecies != SPECIES_NONE
     && gSaveBlock1Ptr->location.mapNum == gSaveBlock1Ptr->outbreakLocationMapNum
     && gSaveBlock1Ptr->location.mapGroup == gSaveBlock1Ptr->outbreakLocationMapGroup)
    {
        if (Random() % 100 < gSaveBlock1Ptr->outbreakPokemonProbability)
            return TRUE;
    }
    return FALSE;
}

static bool8 EncounterOddsCheck(u16 encounterRate)
{
    if (Random() % MAX_ENCOUNTER_RATE < encounterRate)
        return TRUE;
    else
        return FALSE;
}

// Returns true if it will try to create a wild encounter.
static bool8 WildEncounterCheck(u32 encounterRate, bool8 ignoreAbility)
{
    encounterRate *= 16;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        encounterRate = encounterRate * 80 / 100;
    ApplyFluteEncounterRateMod(&encounterRate);
    ApplyCleanseTagEncounterRateMod(&encounterRate);
    if (LURE_STEP_COUNT != 0)
        encounterRate *= 2;
    if (!ignoreAbility && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
    {
        enum Ability ability = GetMonAbility(&gPlayerParty[0]);

        if (ability == ABILITY_STENCH && gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
            encounterRate = encounterRate * 3 / 4;
        else if (ability == ABILITY_STENCH)
            encounterRate /= 2;
        else if (ability == ABILITY_ILLUMINATE)
            encounterRate *= 2;
        else if (ability == ABILITY_WHITE_SMOKE)
            encounterRate /= 2;
        else if (ability == ABILITY_ARENA_TRAP)
            encounterRate *= 2;
        else if (ability == ABILITY_SAND_VEIL && gSaveBlock1Ptr->weather == WEATHER_SANDSTORM)
            encounterRate /= 2;
        else if (ability == ABILITY_SNOW_CLOAK && gSaveBlock1Ptr->weather == WEATHER_SNOW)
            encounterRate /= 2;
        else if (ability == ABILITY_QUICK_FEET)
            encounterRate /= 2;
        else if (ability == ABILITY_INFILTRATOR && OW_INFILTRATOR >= GEN_8)
            encounterRate /= 2;
        else if (ability == ABILITY_NO_GUARD)
            encounterRate *= 2;
    }
    if (encounterRate > MAX_ENCOUNTER_RATE)
        encounterRate = MAX_ENCOUNTER_RATE;
    return EncounterOddsCheck(encounterRate);
}

// When you first step on a different type of metatile, there's a 40% chance it
// skips the wild encounter check entirely.
static bool8 AllowWildCheckOnNewMetatile(void)
{
    if (Random() % 100 >= 60)
        return FALSE;
    else
        return TRUE;
}

static bool8 AreLegendariesInSootopolisPreventingEncounters(void)
{
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(MAP_SOOTOPOLIS_CITY)
     || gSaveBlock1Ptr->location.mapNum != MAP_NUM(MAP_SOOTOPOLIS_CITY))
    {
        return FALSE;
    }

    return FlagGet(FLAG_LEGENDARIES_IN_SOOTOPOLIS);
}

bool8 StandardWildEncounter(u16 curMetatileBehavior, u16 prevMetatileBehavior)
{
    u32 headerId;
    enum TimeOfDay timeOfDay;
    struct Roamer *roamer;

    if (sWildEncountersDisabled == TRUE)
        return FALSE;

    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gBattlePikeWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            else if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;
            else if (!TryGenerateBattlePikeWildMon(TRUE))
                return FALSE;

            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gBattlePyramidWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            else if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(curMetatileBehavior) == TRUE)
        {
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo == NULL)
                return FALSE;
            else if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter())
            {
                roamer = &gSaveBlock1Ptr->roamer[gEncounteredRoamerIndex];
                if (!IsWildLevelAllowedByRepel(roamer->level))
                    return FALSE;

                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else
            {
                if (DoMassOutbreakEncounterTest() == TRUE && SetUpMassOutbreakEncounter(WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    BattleSetup_StartWildBattle();
                    return TRUE;
                }

                // try a regular wild land encounter
                if (TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    if (TryDoDoubleWildBattle())
                    {
                        struct Pokemon mon1 = gEnemyParty[0];
                        TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE);
                        gEnemyParty[1] = mon1;
                        BattleSetup_StartDoubleWildBattle();
                    }
                    else
                    {
                        BattleSetup_StartWildBattle();
                    }
                    return TRUE;
                }

                return FALSE;
            }
        }
        else if (MetatileBehavior_IsWaterWildEncounter(curMetatileBehavior) == TRUE
                 || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING) && MetatileBehavior_IsBridgeOverWater(curMetatileBehavior) == TRUE))
        {
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);

            if (AreLegendariesInSootopolisPreventingEncounters() == TRUE)
                return FALSE;
            else if (gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo == NULL)
                return FALSE;
            else if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter())
            {
                roamer = &gSaveBlock1Ptr->roamer[gEncounteredRoamerIndex];
                if (!IsWildLevelAllowedByRepel(roamer->level))
                    return FALSE;

                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else // try a regular surfing encounter
            {
                if (TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo, WILD_AREA_WATER, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    gIsSurfingEncounter = TRUE;
                    if (TryDoDoubleWildBattle())
                    {
                        struct Pokemon mon1 = gEnemyParty[0];
                        TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo, WILD_AREA_WATER, WILD_CHECK_KEEN_EYE);
                        gEnemyParty[1] = mon1;
                        BattleSetup_StartDoubleWildBattle();
                    }
                    else
                    {
                        BattleSetup_StartWildBattle();
                    }
                    return TRUE;
                }

                return FALSE;
            }
        }
    }

    return FALSE;
}

void RockSmashWildEncounter(void)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;

    if (headerId != HEADER_NONE)
    {
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_ROCKS);

        const struct WildPokemonInfo *wildPokemonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].rockSmashMonsInfo;

        if (wildPokemonInfo == NULL)
        {
            gSpecialVar_Result = FALSE;
        }
        else if (WildEncounterCheck(wildPokemonInfo->encounterRate, TRUE) == TRUE
         && TryGenerateWildMon(wildPokemonInfo, WILD_AREA_ROCKS, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
        {
            if (TryDoDoubleWildBattle())
            {
                struct Pokemon mon1 = gEnemyParty[0];
                TryGenerateWildMon(wildPokemonInfo, WILD_AREA_ROCKS, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE);
                gEnemyParty[1] = mon1;
                BattleSetup_StartDoubleWildBattle();
                gSpecialVar_Result = TRUE;
            }
            else {
                BattleSetup_StartWildBattle();
                gSpecialVar_Result = TRUE;
            }
        }
        else
        {
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

bool8 SweetScentWildEncounter(void)
{
    s16 x, y;
    u32 headerId;
    enum TimeOfDay timeOfDay;

    PlayerGetDestCoords(&x, &y);
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            TryGenerateBattlePikeWildMon(FALSE);
            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter())
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            if (DoMassOutbreakEncounterTest() == TRUE)
                SetUpMassOutbreakEncounter(0);
            else
                TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0);

            BattleSetup_StartWildBattle();
            return TRUE;
        }
        else if (MetatileBehavior_IsWaterWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);

            if (AreLegendariesInSootopolisPreventingEncounters() == TRUE)
                return FALSE;
            if (gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter())
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo, WILD_AREA_WATER, 0);
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

bool8 DoesCurrentMapHaveFishingMons(enum FishingRod rod)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_FISHING_START + (int)rod);

    if (headerId != HEADER_NONE)
    {
        const struct WildEncounterTypes *encTypes = &gWildMonHeaders[headerId].encounterTypes[timeOfDay];
        switch (rod)
        {
            case OLD_ROD:
                return encTypes->fishingMonsOldRodInfo != NULL;
            case GOOD_ROD:
                return encTypes->fishingMonsGoodRodInfo != NULL;
            case SUPER_ROD:
                return encTypes->fishingMonsSuperRodInfo != NULL;
        }
    }

    return FALSE;
}

void FishingWildEncounter(enum FishingRod rod)
{
    u16 species;
    u32 headerId;
    enum TimeOfDay timeOfDay;

    gIsFishingEncounter = TRUE;
    if (CheckFeebas() == TRUE)
    {
        u8 level = ChooseWildMonLevel(&sWildFeebas, 0);

        species = sWildFeebas.wildPokemon[0].species;
        CreateWildMon(species, level);
    }
    else
    {
        headerId = GetCurrentMapWildMonHeaderId();
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_FISHING_START + (int)rod);
        species = GenerateFishingWildMon(&gWildMonHeaders[headerId].encounterTypes[timeOfDay], rod);
    }

    IncrementGameStat(GAME_STAT_FISHING_ENCOUNTERS);
    SetPokemonAnglerSpecies(species);
    BattleSetup_StartWildBattle();
}

u16 GetLocalWildMon(bool8 *isWaterMon)
{
    u32 headerId;
    enum TimeOfDay timeOfDay;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;

    *isWaterMon = FALSE;
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
        return SPECIES_NONE;

    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
    landMonsInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;

    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);
    waterMonsInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;

    // Neither
    if (landMonsInfo == NULL && waterMonsInfo == NULL)
        return SPECIES_NONE;
    // Land Pokémon
    else if (landMonsInfo != NULL && waterMonsInfo == NULL)
        return landMonsInfo->wildPokemon[ChooseWildMonIndex(landMonsInfo)].species;
    // Water Pokémon
    else if (landMonsInfo == NULL && waterMonsInfo != NULL)
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex(waterMonsInfo)].species;
    }
    // Either land or water Pokémon
    if ((Random() % 100) < 80)
    {
        return landMonsInfo->wildPokemon[ChooseWildMonIndex(landMonsInfo)].species;
    }
    else
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex(waterMonsInfo)].species;
    }
}

u16 GetLocalWaterMon(void)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;

    if (headerId != HEADER_NONE)
    {
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);

        const struct WildPokemonInfo *waterMonsInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;

        if (waterMonsInfo)
            return waterMonsInfo->wildPokemon[ChooseWildMonIndex(waterMonsInfo)].species;
    }
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

static bool8 IsWildLevelAllowedByRepel(u8 wildLevel)
{
    u8 i;

    if (!REPEL_STEP_COUNT)
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (I_REPEL_INCLUDE_FAINTED == GEN_1 || I_REPEL_INCLUDE_FAINTED >= GEN_6 || GetMonData(&gPlayerParty[i], MON_DATA_HP))
        {
            if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
                return wildLevel >= GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
        }
    }

    return FALSE;
}

static bool8 IsAbilityAllowingEncounter(u8 level)
{
    enum Ability ability;

    if (GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        return TRUE;

    ability = GetMonAbility(&gPlayerParty[0]);
    if (ability == ABILITY_KEEN_EYE || ability == ABILITY_INTIMIDATE)
    {
        u8 playerMonLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
        if (playerMonLevel > 5 && level <= playerMonLevel - 5 && !(Random() % 2))
            return FALSE;
    }

    return TRUE;
}

#include "data.h"

static u8 GetMaxLevelOfSpeciesInWildTable(const struct WildPokemonInfo *wildMonInfo, u16 species)
{
    u8 i, maxLevel = 0;

    for (i = 0; i < wildMonInfo->numSlots; i++)
    {
        if (wildMonInfo->wildPokemon[i].species == species && wildMonInfo->wildPokemon[i].maxLevel > maxLevel)
            maxLevel = wildMonInfo->wildPokemon[i].maxLevel;
    }

    return maxLevel;
}

static void ApplyFluteEncounterRateMod(u32 *encRate)
{
    if (FlagGet(FLAG_SYS_ENC_UP_ITEM) == TRUE)
        *encRate += *encRate / 2;
    else if (FlagGet(FLAG_SYS_ENC_DOWN_ITEM) == TRUE)
        *encRate = *encRate / 2;
}

static void ApplyCleanseTagEncounterRateMod(u32 *encRate)
{
    if (GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM) == ITEM_CLEANSE_TAG)
        *encRate = *encRate * 2 / 3;
}

bool8 TryDoDoubleWildBattle(void)
{
    if (GetSafariZoneFlag()
      || (B_DOUBLE_WILD_REQUIRE_2_MONS == TRUE && GetMonsStateToDoubles() != PLAYER_HAS_TWO_USABLE_MONS))
        return FALSE;
    if (FollowerNPCIsBattlePartner() && FNPC_FLAG_PARTNER_WILD_BATTLES != 0
     && (FNPC_FLAG_PARTNER_WILD_BATTLES == FNPC_ALWAYS || FlagGet(FNPC_FLAG_PARTNER_WILD_BATTLES)) && FNPC_NPC_FOLLOWER_WILD_BATTLE_VS_2 == TRUE)
        return TRUE;
    else if (B_FLAG_FORCE_DOUBLE_WILD != 0 && FlagGet(B_FLAG_FORCE_DOUBLE_WILD))
        return TRUE;
    else if (B_DOUBLE_WILD_CHANCE != 0 && ((Random() % 100) + 1 <= B_DOUBLE_WILD_CHANCE))
        return TRUE;
    return FALSE;
}

bool8 StandardWildEncounter_Debug(void)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

    if (TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
        return FALSE;

    DoStandardWildBattle_Debug();
    return TRUE;
}

bool32 MapHasNoEncounterData(void)
{
    return (GetCurrentMapWildMonHeaderId() == HEADER_NONE);
}
