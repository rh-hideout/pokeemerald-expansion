#include "global.h"
#include "event_data.h"
#include "ow_synchronize.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#if IS_HNS
#include "pokedex.h"
#endif

// Despite having a variable to track it, the roamer is
// hard-coded to only ever be in map group 0
#define ROAMER_MAP_GROUP 0

enum
{
    MAP_GRP, // map group
    MAP_NUM, // map number
};

#define ROAMER(index) (&gSaveBlock1Ptr->roamer[index])
EWRAM_DATA static u8 sLocationHistory[ROAMER_COUNT][3][2] = {0};
EWRAM_DATA static u8 sRoamerLocation[ROAMER_COUNT][2] = {0};
EWRAM_DATA u8 gEncounteredRoamerIndex = 0;

#define ___ MAP_NUM(MAP_UNDEFINED) // For empty spots in the location table

// Note: There are two potential softlocks that can occur with this table if its maps are
//       changed in particular ways. They can be avoided by ensuring the following:
//       - There must be at least 2 location sets that start with a different map,
//         i.e. every location set cannot start with the same map. This is because of
//         the while loop in RoamerMoveToOtherLocationSet.
//       - Each location set must have at least 3 unique maps. This is because of
//         the while loop in RoamerMove. In this loop the first map in the set is
//         ignored, and an additional map is ignored if the roamer was there recently.
//       - Additionally, while not a softlock, it's worth noting that if for any
//         map in the location table there is not a location set that starts with
//         that map then the roamer will be significantly less likely to move away
//         from that map when it lands there.
#if IS_HNS

enum
{
    ROAMER_LOC_TABLE_JOHTO,
    ROAMER_LOC_TABLE_KANTO,
    ROAMER_LOC_TABLE_COUNT,
};

static const u8 sRoamerLocationsJohto[][6] =
{
    { MAP_NUM(MAP_ROUTE29_HNS), MAP_NUM(MAP_ROUTE30_HNS), MAP_NUM(MAP_ROUTE46_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE30_HNS), MAP_NUM(MAP_ROUTE29_HNS), MAP_NUM(MAP_ROUTE31_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE31_HNS), MAP_NUM(MAP_ROUTE30_HNS), MAP_NUM(MAP_ROUTE29_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE32_HNS), MAP_NUM(MAP_ROUTE31_HNS), MAP_NUM(MAP_ROUTE33_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE33_HNS), MAP_NUM(MAP_ROUTE32_HNS), MAP_NUM(MAP_ROUTE34_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE34_HNS), MAP_NUM(MAP_ROUTE33_HNS), MAP_NUM(MAP_ROUTE35_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE35_HNS), MAP_NUM(MAP_ROUTE34_HNS), MAP_NUM(MAP_ROUTE36_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE36_HNS), MAP_NUM(MAP_ROUTE31_HNS), MAP_NUM(MAP_ROUTE32_HNS), MAP_NUM(MAP_ROUTE35_HNS), MAP_NUM(MAP_ROUTE37_HNS), ___ },
    { MAP_NUM(MAP_ROUTE37_HNS), MAP_NUM(MAP_ROUTE36_HNS), MAP_NUM(MAP_ROUTE38_HNS), MAP_NUM(MAP_ROUTE42_HNS), ___, ___ },
    { MAP_NUM(MAP_ROUTE38_HNS), MAP_NUM(MAP_ROUTE37_HNS), MAP_NUM(MAP_ROUTE39_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE39_HNS), MAP_NUM(MAP_ROUTE48_HNS), MAP_NUM(MAP_ROUTE35_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE42_HNS), MAP_NUM(MAP_ROUTE37_HNS), MAP_NUM(MAP_ROUTE38_HNS), MAP_NUM(MAP_ROUTE43_HNS), MAP_NUM(MAP_ROUTE44_HNS), ___ },
    { MAP_NUM(MAP_ROUTE43_HNS), MAP_NUM(MAP_ROUTE42_HNS), MAP_NUM(MAP_ROUTE44_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE44_HNS), MAP_NUM(MAP_ROUTE42_HNS), MAP_NUM(MAP_ROUTE45_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE45_HNS), MAP_NUM(MAP_ROUTE44_HNS), MAP_NUM(MAP_ROUTE46_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE46_HNS), MAP_NUM(MAP_ROUTE45_HNS), MAP_NUM(MAP_ROUTE29_HNS), ___, ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};

static const u8 sRoamerLocationsKanto[][6] =
{
    { MAP_NUM(MAP_ROUTE1_HNS),  MAP_NUM(MAP_ROUTE2_HNS),  MAP_NUM(MAP_ROUTE22_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE2_HNS),  MAP_NUM(MAP_ROUTE1_HNS),  MAP_NUM(MAP_ROUTE3_HNS),  ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE3_HNS),  MAP_NUM(MAP_ROUTE2_HNS),  MAP_NUM(MAP_ROUTE4_HNS),  ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE4_HNS),  MAP_NUM(MAP_ROUTE3_HNS),  MAP_NUM(MAP_ROUTE5_HNS),  MAP_NUM(MAP_ROUTE24_HNS), ___, ___ },
    { MAP_NUM(MAP_ROUTE5_HNS),  MAP_NUM(MAP_ROUTE4_HNS),  MAP_NUM(MAP_ROUTE6_HNS),  MAP_NUM(MAP_ROUTE9_HNS),  ___, ___ },
    { MAP_NUM(MAP_ROUTE6_HNS),  MAP_NUM(MAP_ROUTE5_HNS),  MAP_NUM(MAP_ROUTE7_HNS),  MAP_NUM(MAP_ROUTE11_HNS), ___, ___ },
    { MAP_NUM(MAP_ROUTE7_HNS),  MAP_NUM(MAP_ROUTE6_HNS),  MAP_NUM(MAP_ROUTE8_HNS),  MAP_NUM(MAP_ROUTE16_HNS), ___, ___ },
    { MAP_NUM(MAP_ROUTE8_HNS),  MAP_NUM(MAP_ROUTE7_HNS),  MAP_NUM(MAP_ROUTE9_HNS),  MAP_NUM(MAP_ROUTE10_HNS), ___, ___ },
    { MAP_NUM(MAP_ROUTE9_HNS),  MAP_NUM(MAP_ROUTE5_HNS),  MAP_NUM(MAP_ROUTE8_HNS),  MAP_NUM(MAP_ROUTE10_HNS), ___, ___ },
    { MAP_NUM(MAP_ROUTE10_HNS), MAP_NUM(MAP_ROUTE8_HNS),  MAP_NUM(MAP_ROUTE9_HNS),  ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE11_HNS), MAP_NUM(MAP_ROUTE6_HNS),  MAP_NUM(MAP_ROUTE12_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE12_HNS), MAP_NUM(MAP_ROUTE11_HNS), MAP_NUM(MAP_ROUTE13_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE13_HNS), MAP_NUM(MAP_ROUTE12_HNS), MAP_NUM(MAP_ROUTE14_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE14_HNS), MAP_NUM(MAP_ROUTE13_HNS), MAP_NUM(MAP_ROUTE15_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE15_HNS), MAP_NUM(MAP_ROUTE14_HNS), MAP_NUM(MAP_ROUTE18_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE16_HNS), MAP_NUM(MAP_ROUTE7_HNS),  MAP_NUM(MAP_ROUTE17_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE17_HNS), MAP_NUM(MAP_ROUTE16_HNS), MAP_NUM(MAP_ROUTE18_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE18_HNS), MAP_NUM(MAP_ROUTE17_HNS), MAP_NUM(MAP_ROUTE15_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE19_HNS), MAP_NUM(MAP_ROUTE20_HNS), MAP_NUM(MAP_ROUTE21_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE20_HNS), MAP_NUM(MAP_ROUTE19_HNS), MAP_NUM(MAP_ROUTE21_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE21_HNS), MAP_NUM(MAP_ROUTE19_HNS), MAP_NUM(MAP_ROUTE20_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE22_HNS), MAP_NUM(MAP_ROUTE1_HNS),  MAP_NUM(MAP_ROUTE23_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE23_HNS), MAP_NUM(MAP_ROUTE22_HNS), MAP_NUM(MAP_ROUTE1_HNS),  ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE24_HNS), MAP_NUM(MAP_ROUTE4_HNS),  MAP_NUM(MAP_ROUTE25_HNS), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE25_HNS), MAP_NUM(MAP_ROUTE24_HNS), MAP_NUM(MAP_ROUTE4_HNS),  ___, ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};

struct RoamerLocationTable
{
    const u8 (*locations)[6];
    u8 numSets;
};

static const struct RoamerLocationTable sRoamerLocationTables[ROAMER_LOC_TABLE_COUNT] =
{
    [ROAMER_LOC_TABLE_JOHTO] = { sRoamerLocationsJohto, ARRAY_COUNT(sRoamerLocationsJohto) - 1 },
    [ROAMER_LOC_TABLE_KANTO] = { sRoamerLocationsKanto, ARRAY_COUNT(sRoamerLocationsKanto) - 1 },
};

#else

static const u8 sRoamerLocationsHoenn[][6] =
{
    { MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE118), MAP_NUM(MAP_ROUTE134), ___ },
    { MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE118), ___, ___ },
    { MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE118), ___, ___ },
    { MAP_NUM(MAP_ROUTE118), MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE119), MAP_NUM(MAP_ROUTE123) },
    { MAP_NUM(MAP_ROUTE119), MAP_NUM(MAP_ROUTE118), MAP_NUM(MAP_ROUTE120), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE120), MAP_NUM(MAP_ROUTE119), MAP_NUM(MAP_ROUTE121), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE121), MAP_NUM(MAP_ROUTE120), MAP_NUM(MAP_ROUTE122), MAP_NUM(MAP_ROUTE123), ___, ___ },
    { MAP_NUM(MAP_ROUTE122), MAP_NUM(MAP_ROUTE121), MAP_NUM(MAP_ROUTE123), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE123), MAP_NUM(MAP_ROUTE122), MAP_NUM(MAP_ROUTE118), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE124), MAP_NUM(MAP_ROUTE121), MAP_NUM(MAP_ROUTE125), MAP_NUM(MAP_ROUTE126), ___, ___ },
    { MAP_NUM(MAP_ROUTE125), MAP_NUM(MAP_ROUTE124), MAP_NUM(MAP_ROUTE127), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE126), MAP_NUM(MAP_ROUTE124), MAP_NUM(MAP_ROUTE127), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE127), MAP_NUM(MAP_ROUTE125), MAP_NUM(MAP_ROUTE126), MAP_NUM(MAP_ROUTE128), ___, ___ },
    { MAP_NUM(MAP_ROUTE128), MAP_NUM(MAP_ROUTE127), MAP_NUM(MAP_ROUTE129), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE129), MAP_NUM(MAP_ROUTE128), MAP_NUM(MAP_ROUTE130), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE130), MAP_NUM(MAP_ROUTE129), MAP_NUM(MAP_ROUTE131), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE131), MAP_NUM(MAP_ROUTE130), MAP_NUM(MAP_ROUTE132), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE132), MAP_NUM(MAP_ROUTE131), MAP_NUM(MAP_ROUTE133), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE133), MAP_NUM(MAP_ROUTE132), MAP_NUM(MAP_ROUTE134), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE134), MAP_NUM(MAP_ROUTE133), MAP_NUM(MAP_ROUTE110), ___, ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};

enum
{
    ROAMER_LOC_TABLE_HOENN,
    ROAMER_LOC_TABLE_COUNT,
};

struct RoamerLocationTable
{
    const u8 (*locations)[6];
    u8 numSets;
};

static const struct RoamerLocationTable sRoamerLocationTables[ROAMER_LOC_TABLE_COUNT] =
{
    [ROAMER_LOC_TABLE_HOENN] = { sRoamerLocationsHoenn, ARRAY_COUNT(sRoamerLocationsHoenn) - 1 },
};

#endif

#undef ___
#define NUM_LOCATIONS_PER_SET 6

static inline const u8 (*GetRoamerLocations(u32 roamerIndex))[6]
{
    return sRoamerLocationTables[ROAMER(roamerIndex)->locationTableId].locations;
}

static inline u8 GetRoamerNumLocationSets(u32 roamerIndex)
{
    return sRoamerLocationTables[ROAMER(roamerIndex)->locationTableId].numSets;
}

static bool8 IsMapInRoamerTable(u32 roamerIndex, u8 mapNum)
{
    const u8 (*locs)[6] = GetRoamerLocations(roamerIndex);
    u8 numSets = GetRoamerNumLocationSets(roamerIndex);
    u32 i;

    for (i = 0; i < numSets; i++)
    {
        if (locs[i][0] == mapNum)
            return TRUE;
    }
    return FALSE;
}

static u8 CountLegendariesInParty(void)
{
    u8 count = 0;
    u32 i;

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        if (species != SPECIES_NONE
            && (gSpeciesInfo[species].isRestrictedLegendary
                || gSpeciesInfo[species].isSubLegendary
                || gSpeciesInfo[species].isMythical))
            count++;
    }
    return count;
}

static void TryAttractRoamer(u32 roamerIndex)
{
    u8 playerMapNum = gSaveBlock1Ptr->location.mapNum;
    u8 legendCount = CountLegendariesInParty();

    if (legendCount == 0)
        return;

    if (!IsMapInRoamerTable(roamerIndex, playerMapNum))
        return;

    // 2% per legendary in party (max 12% with 6)
    if ((Random() % 100) < (legendCount * 2))
        sRoamerLocation[roamerIndex][MAP_NUM] = playerMapNum;
}

void DeactivateAllRoamers(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
        SetRoamerInactive(i);
}

static void ClearRoamerLocationHistory(u32 roamerIndex)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sLocationHistory[roamerIndex]); i++)
    {
        sLocationHistory[roamerIndex][i][MAP_GRP] = 0;
        sLocationHistory[roamerIndex][i][MAP_NUM] = 0;
    }
}

void MoveAllRoamersToOtherLocationSets(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
        RoamerMoveToOtherLocationSet(i);
}

void MoveAllRoamers(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        RoamerMove(i);
        if (ROAMER(i)->active)
            TryAttractRoamer(i);
    }
}

static void CreateInitialRoamerMon(u8 index, u16 species, u8 level, u8 locationTableId)
{
    ClearRoamerLocationHistory(index);
    ROAMER(index)->locationTableId = locationTableId;
    u32 personality = GetMonPersonality(species,
        GetSynchronizedGender(ROAMER_ORIGIN, species),
        GetSynchronizedNature(ROAMER_ORIGIN, species),
        RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gEnemyParty[0], species, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[0]);
    ROAMER(index)->ivs = GetMonData(&gEnemyParty[0], MON_DATA_IVS);
    ROAMER(index)->personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);
    ROAMER(index)->species = species;
    ROAMER(index)->level = level;
    ROAMER(index)->statusA = 0;
    ROAMER(index)->statusB = 0;
    ROAMER(index)->hp = GetMonData(&gEnemyParty[0], MON_DATA_MAX_HP);
    ROAMER(index)->cool = GetMonData(&gEnemyParty[0], MON_DATA_COOL);
    ROAMER(index)->beauty = GetMonData(&gEnemyParty[0], MON_DATA_BEAUTY);
    ROAMER(index)->cute = GetMonData(&gEnemyParty[0], MON_DATA_CUTE);
    ROAMER(index)->smart = GetMonData(&gEnemyParty[0], MON_DATA_SMART);
    ROAMER(index)->tough = GetMonData(&gEnemyParty[0], MON_DATA_TOUGH);
    ROAMER(index)->shiny = GetMonData(&gEnemyParty[0], MON_DATA_IS_SHINY);
    ROAMER(index)->active = TRUE;
    sRoamerLocation[index][MAP_GRP] = ROAMER_MAP_GROUP;
    const u8 (*locs)[6] = GetRoamerLocations(index);
    u8 numSets = GetRoamerNumLocationSets(index);
    sRoamerLocation[index][MAP_NUM] = locs[Random() % numSets][0];
}

static u8 GetFirstInactiveRoamerIndex(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        if (!ROAMER(i)->active)
            return i;
    }
    return ROAMER_COUNT;
}

bool8 TryAddRoamer(u16 species, u8 level, u8 locationTableId)
{
    u8 index = GetFirstInactiveRoamerIndex();

    if (index < ROAMER_COUNT)
    {
        CreateInitialRoamerMon(index, species, level, locationTableId);
        return TRUE;
    }

    return FALSE;
}

#if IS_HNS
void InitRoamer(void)
{
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ENTEI), FLAG_SET_SEEN);
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_RAIKOU), FLAG_SET_SEEN);
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_SUICUNE), FLAG_SET_SEEN);
    TryAddRoamer(SPECIES_RAIKOU, 40, ROAMER_LOC_TABLE_JOHTO);
    TryAddRoamer(SPECIES_ENTEI, 40, ROAMER_LOC_TABLE_JOHTO);
}

void InitKantoRoamers(void)
{
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_LATIAS), FLAG_SET_SEEN);
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_LATIOS), FLAG_SET_SEEN);
    TryAddRoamer(SPECIES_LATIAS, 60, ROAMER_LOC_TABLE_KANTO);
    TryAddRoamer(SPECIES_LATIOS, 60, ROAMER_LOC_TABLE_KANTO);
}
#else
// gSpecialVar_0x8004 here corresponds to the options in the multichoice MULTI_TV_LATI (0 for 'Red', 1 for 'Blue')
void InitRoamer(void)
{
    if (gSpecialVar_0x8004 == 0) // Red
        TryAddRoamer(SPECIES_LATIAS, 40, ROAMER_LOC_TABLE_HOENN);
    else
        TryAddRoamer(SPECIES_LATIOS, 40, ROAMER_LOC_TABLE_HOENN);
}

void InitKantoRoamers(void)
{
}
#endif

void UpdateLocationHistoryForRoamer(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        sLocationHistory[i][2][MAP_GRP] = sLocationHistory[i][1][MAP_GRP];
        sLocationHistory[i][2][MAP_NUM] = sLocationHistory[i][1][MAP_NUM];

        sLocationHistory[i][1][MAP_GRP] = sLocationHistory[i][0][MAP_GRP];
        sLocationHistory[i][1][MAP_NUM] = sLocationHistory[i][0][MAP_NUM];

        sLocationHistory[i][0][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
        sLocationHistory[i][0][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;
    }
}

void RoamerMoveToOtherLocationSet(u32 roamerIndex)
{
    u8 mapNum = 0;

    if (!ROAMER(roamerIndex)->active)
        return;

    const u8 (*locs)[6] = GetRoamerLocations(roamerIndex);
    u8 numSets = GetRoamerNumLocationSets(roamerIndex);

    sRoamerLocation[roamerIndex][MAP_GRP] = ROAMER_MAP_GROUP;

    do
    {
        mapNum = locs[Random() % numSets][0];
        if (sRoamerLocation[roamerIndex][MAP_NUM] != mapNum)
        {
            sRoamerLocation[roamerIndex][MAP_NUM] = mapNum;
            return;
        }
    } while (sRoamerLocation[roamerIndex][MAP_NUM] == mapNum);
    sRoamerLocation[roamerIndex][MAP_NUM] = mapNum;
}

void RoamerMove(u32 roamerIndex)
{
    u8 locSet = 0;

    if ((Random() % 16) == 0)
    {
        RoamerMoveToOtherLocationSet(roamerIndex);
    }
    else
    {
        if (!ROAMER(roamerIndex)->active)
            return;

        const u8 (*locs)[6] = GetRoamerLocations(roamerIndex);
        u8 numSets = GetRoamerNumLocationSets(roamerIndex);

        while (locSet < numSets)
        {
            if (sRoamerLocation[roamerIndex][MAP_NUM] == locs[locSet][0])
            {
                u8 mapNum;
                do
                {
                    mapNum = locs[locSet][(Random() % (NUM_LOCATIONS_PER_SET - 1)) + 1];
                } while (mapNum == MAP_NUM(MAP_UNDEFINED));
                sRoamerLocation[roamerIndex][MAP_NUM] = mapNum;
                return;
            }
            locSet++;
        }
    }
}

bool8 IsRoamerAt(u32 roamerIndex, u8 mapGroup, u8 mapNum)
{
    if (ROAMER(roamerIndex)->active && mapGroup == sRoamerLocation[roamerIndex][MAP_GRP] && mapNum == sRoamerLocation[roamerIndex][MAP_NUM])
        return TRUE;
    else
        return FALSE;
}

void CreateRoamerMonInstance(u32 roamerIndex)
{
    u32 status = ROAMER(roamerIndex)->statusA + (ROAMER(roamerIndex)->statusB << 8);
    struct Pokemon *mon = &gEnemyParty[0];
    ZeroEnemyPartyMons();
    CreateMonWithIVsPersonality(mon, ROAMER(roamerIndex)->species, ROAMER(roamerIndex)->level, ROAMER(roamerIndex)->ivs, ROAMER(roamerIndex)->personality);
    SetMonData(mon, MON_DATA_STATUS, &status);
    SetMonData(mon, MON_DATA_HP, &ROAMER(roamerIndex)->hp);
    SetMonData(mon, MON_DATA_COOL, &ROAMER(roamerIndex)->cool);
    SetMonData(mon, MON_DATA_BEAUTY, &ROAMER(roamerIndex)->beauty);
    SetMonData(mon, MON_DATA_CUTE, &ROAMER(roamerIndex)->cute);
    SetMonData(mon, MON_DATA_SMART, &ROAMER(roamerIndex)->smart);
    SetMonData(mon, MON_DATA_TOUGH, &ROAMER(roamerIndex)->tough);
    SetMonData(mon, MON_DATA_IS_SHINY, &ROAMER(roamerIndex)->shiny);
}

bool8 TryStartRoamerEncounter(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        if (IsRoamerAt(i, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum) == TRUE && (Random() % 4) == 0)
        {
            CreateRoamerMonInstance(i);
            gEncounteredRoamerIndex = i;
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateRoamerHPStatus(struct Pokemon *mon)
{
    u32 status = GetMonData(mon, MON_DATA_STATUS);

    ROAMER(gEncounteredRoamerIndex)->hp = GetMonData(mon, MON_DATA_HP);
    ROAMER(gEncounteredRoamerIndex)->statusA = status;
    ROAMER(gEncounteredRoamerIndex)->statusB = status >> 8;

    RoamerMoveToOtherLocationSet(gEncounteredRoamerIndex);
}

void SetRoamerInactive(u32 roamerIndex)
{
    ROAMER(roamerIndex)->active = FALSE;
}

void GetRoamerLocation(u32 roamerIndex, u8 *mapGroup, u8 *mapNum)
{
    *mapGroup = sRoamerLocation[roamerIndex][MAP_GRP];
    *mapNum = sRoamerLocation[roamerIndex][MAP_NUM];
}

bool8 IsRoamerOnCurrentMap(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        if (IsRoamerAt(i, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
            return TRUE;
    }
    return FALSE;
}
