#include "global.h"
#include "event_data.h"
#include "ow_abilities.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#include "pokedex.h"
#include "string_util.h"
#include "caps.h"
#include "constants/global.h"
#include "constants/species.h"
#include "constants/characters.h"

// Despite having a variable to track it, the roamer is
// hard-coded to only ever be in map group 0
#define ROAMER_MAP_GROUP 0

enum
{
    MAP_GRP, // map group
    MAP_NUM, // map number
};

#define ROAMER(index) (&gSaveBlock1Ptr->roamer[index])
EWRAM_DATA u8 sLocationHistory[ROAMER_COUNT][3][2] = {0};
EWRAM_DATA u8 sRoamerLocation[ROAMER_COUNT][2] = {0};
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
static const u8 sRoamerLocations[][6] =
{
    { MAP_NUM(MAP_ROUTE101), MAP_NUM(MAP_ROUTE102), MAP_NUM(MAP_ROUTE103), MAP_NUM(MAP_ROUTE104), MAP_NUM(MAP_ROUTE105), ___ },
    { MAP_NUM(MAP_ROUTE106), MAP_NUM(MAP_ROUTE107), MAP_NUM(MAP_ROUTE108), MAP_NUM(MAP_ROUTE109), ___, ___ },
    { MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE112), MAP_NUM(MAP_ROUTE113), ___, ___ },
    { MAP_NUM(MAP_ROUTE114), MAP_NUM(MAP_ROUTE115), MAP_NUM(MAP_ROUTE116), MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE118), MAP_NUM(MAP_ROUTE119) },
    { MAP_NUM(MAP_ROUTE120), MAP_NUM(MAP_ROUTE121), MAP_NUM(MAP_ROUTE122), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE123), MAP_NUM(MAP_ROUTE124), MAP_NUM(MAP_ROUTE125), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE126), MAP_NUM(MAP_ROUTE127), MAP_NUM(MAP_ROUTE128), MAP_NUM(MAP_ROUTE129), ___, ___ },
    { MAP_NUM(MAP_ROUTE130), MAP_NUM(MAP_ROUTE101), MAP_NUM(MAP_ROUTE102), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE103), MAP_NUM(MAP_ROUTE104), MAP_NUM(MAP_ROUTE105), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE107), MAP_NUM(MAP_ROUTE106), MAP_NUM(MAP_ROUTE108), MAP_NUM(MAP_ROUTE109), ___, ___ },
    { MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE112), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE113), MAP_NUM(MAP_ROUTE114), MAP_NUM(MAP_ROUTE115), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE116), MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE118), MAP_NUM(MAP_ROUTE119), ___, ___ },
    { MAP_NUM(MAP_ROUTE121), MAP_NUM(MAP_ROUTE120), MAP_NUM(MAP_ROUTE122), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE124), MAP_NUM(MAP_ROUTE123), MAP_NUM(MAP_ROUTE125), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE127), MAP_NUM(MAP_ROUTE126), MAP_NUM(MAP_ROUTE128), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE129), MAP_NUM(MAP_ROUTE130), MAP_NUM(MAP_ROUTE101), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE102), MAP_NUM(MAP_ROUTE103), MAP_NUM(MAP_ROUTE104), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE105), MAP_NUM(MAP_ROUTE106), MAP_NUM(MAP_ROUTE107), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE108), MAP_NUM(MAP_ROUTE109), MAP_NUM(MAP_ROUTE110), ___, ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};

#undef ___
#define NUM_LOCATION_SETS (ARRAY_COUNT(sRoamerLocations) - 1)
#define NUM_LOCATIONS_PER_SET (ARRAY_COUNT(sRoamerLocations[0]))

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
        RoamerMove(i);
}

static void CreateInitialRoamerMon(u8 index, enum Species species, u16 level)
{
    ClearRoamerLocationHistory(index);
    u32 personality = GetMonPersonality(species,
        GetSynchronizedGender(ROAMER_ORIGIN, species),
        GetSynchronizedNature(ROAMER_ORIGIN, species),
        RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gParties[B_TRAINER_OPPONENT_A][0], species, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gParties[B_TRAINER_OPPONENT_A][0]);
    ROAMER(index)->ivs = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_IVS);
    ROAMER(index)->personality = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_PERSONALITY);
    ROAMER(index)->species = species;
    ROAMER(index)->level = level;
    ROAMER(index)->statusA = 0;
    ROAMER(index)->statusB = 0;
    ROAMER(index)->hp = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_MAX_HP);
    ROAMER(index)->cool = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_COOL);
    ROAMER(index)->beauty = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_BEAUTY);
    ROAMER(index)->cute = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_CUTE);
    ROAMER(index)->smart = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SMART);
    ROAMER(index)->tough = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_TOUGH);
    ROAMER(index)->shiny = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_IS_SHINY);
    ROAMER(index)->active = TRUE;
    sRoamerLocation[index][MAP_GRP] = ROAMER_MAP_GROUP;
    sRoamerLocation[index][MAP_NUM] = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
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

bool8 TryAddRoamer(enum Species species, u16 level)
{
    u8 index = GetFirstInactiveRoamerIndex();

    if (index < ROAMER_COUNT)
    {
        // Create the roamer and stop searching
        CreateInitialRoamerMon(index, species, level);
        return TRUE;
    }

    // Maximum active roamers found: do nothing and let the calling function know
    return FALSE;
}

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

    sRoamerLocation[roamerIndex][MAP_GRP] = ROAMER_MAP_GROUP;

    // Choose a location set that starts with a map
    // different from the roamer's current map
    do
    {
        mapNum = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
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

        while (locSet < NUM_LOCATION_SETS)
        {
            // Find the location set that starts with the roamer's current map
            if (sRoamerLocation[roamerIndex][MAP_NUM] == sRoamerLocations[locSet][0])
            {
                u8 mapNum;
                // Choose a new map (excluding the first) within this set
                // Also exclude a map if the roamer was there 2 moves ago
                do
                {
                    mapNum = sRoamerLocations[locSet][(Random() % (NUM_LOCATIONS_PER_SET - 1)) + 1];
                } while ((sLocationHistory[roamerIndex][2][MAP_GRP] == ROAMER_MAP_GROUP
                        && sLocationHistory[roamerIndex][2][MAP_NUM] == mapNum)
                        || mapNum == MAP_NUM(MAP_UNDEFINED));
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
    struct Pokemon *mon = &gParties[B_TRAINER_OPPONENT_A][0];
    ZeroEnemyPartyMons();
    ROAMER(roamerIndex)->level = GetCurrentLevelCap();
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

    // If an overworld code recently detected a nearby roamer and set an override,
    // prefer that roamer for the next wild encounter.
    if (gRoamerNearbyIndexOverride < ROAMER_COUNT)
    {
        u8 idx = gRoamerNearbyIndexOverride;
        if (IsRoamerAt(idx, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum) == TRUE && ROAMER(idx)->active)
        {
            ROAMER(idx)->level = GetCurrentLevelCap();
            CreateRoamerMonInstance(idx);
            gEncounteredRoamerIndex = idx;
            gRoamerNearbyIndexOverride = ROAMER_COUNT;
            return TRUE;
        }
        // If override doesn't match current location/active state, clear it
        gRoamerNearbyIndexOverride = ROAMER_COUNT;
    }

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        if (IsRoamerAt(i, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum) == TRUE && (Random() % 4) == 0)
        {
            ROAMER(i)->level = GetCurrentLevelCap();
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
    u16 hp = GetMonData(mon, MON_DATA_HP);

    if (hp == 0)
    {
        hp = GetMonData(mon, MON_DATA_MAX_HP);
        status = 0; // Clear status if fainted
    }

    ROAMER(gEncounteredRoamerIndex)->hp = hp;
    ROAMER(gEncounteredRoamerIndex)->statusA = status;
    ROAMER(gEncounteredRoamerIndex)->statusB = status >> 8;

    RoamerMoveToOtherLocationSet(gEncounteredRoamerIndex);
}

void SetRoamerInactive(u32 roamerIndex)
{
    ROAMER(roamerIndex)->active = FALSE;
}

const u16 gRoamableSpecies[] = {
    SPECIES_ARTICUNO,
    SPECIES_ARTICUNO_GALAR,
    SPECIES_ZAPDOS,
    SPECIES_ZAPDOS_GALAR,
    SPECIES_MOLTRES,
    SPECIES_MOLTRES_GALAR,
    SPECIES_MEWTWO,
    SPECIES_MEW,
    SPECIES_RAIKOU,
    SPECIES_ENTEI,
    SPECIES_SUICUNE,
    SPECIES_LUGIA,
    SPECIES_HO_OH,
    SPECIES_CELEBI,
    SPECIES_LATIAS,
    SPECIES_LATIOS,
    SPECIES_JIRACHI,
    SPECIES_DEOXYS_NORMAL,
    SPECIES_ROTOM,
    SPECIES_UXIE,
    SPECIES_MESPRIT,
    SPECIES_AZELF,
    SPECIES_DIALGA,
    SPECIES_PALKIA,
    SPECIES_HEATRAN,
    SPECIES_REGIGIGAS,
    SPECIES_GIRATINA,
    SPECIES_CRESSELIA,
    SPECIES_PHIONE,
    SPECIES_MANAPHY,
    SPECIES_DARKRAI,
    SPECIES_SHAYMIN_LAND,
    SPECIES_ARCEUS,
    SPECIES_VICTINI,
    SPECIES_COBALION,
    SPECIES_VIRIZION,
    SPECIES_TORNADUS_INCARNATE,
    SPECIES_THUNDURUS_INCARNATE,
    SPECIES_LANDORUS_INCARNATE,
    SPECIES_RESHIRAM,
    SPECIES_ZEKROM,
    SPECIES_KYUREM,
    SPECIES_MELOETTA,
    SPECIES_GENESECT,
    SPECIES_XERNEAS,
    SPECIES_YVELTAL,
    SPECIES_ZYGARDE_COMPLETE,
    SPECIES_DIANCIE,
    SPECIES_HOOPA_CONFINED,
    SPECIES_VOLCANION,
    SPECIES_TAPU_KOKO,
    SPECIES_TAPU_LELE,
    SPECIES_TAPU_BULU,
    SPECIES_TAPU_FINI,
    SPECIES_COSMOG,
    SPECIES_COSMOG,
    SPECIES_NIHILEGO,
    SPECIES_BUZZWOLE,
    SPECIES_PHEROMOSA,
    SPECIES_XURKITREE,
    SPECIES_CELESTEELA,
    SPECIES_KARTANA,
    SPECIES_GUZZLORD,
    SPECIES_NECROZMA,
    SPECIES_MAGEARNA,
    SPECIES_MARSHADOW,
    SPECIES_POIPOLE,
    SPECIES_NAGANADEL,
    SPECIES_STAKATAKA,
    SPECIES_BLACEPHALON,
    SPECIES_ZERAORA,
    SPECIES_MELTAN,
    SPECIES_ZACIAN,
    SPECIES_ZAMAZENTA,
    SPECIES_ETERNATUS,
    SPECIES_KUBFU,
    SPECIES_KUBFU,
    SPECIES_ZARUDE,
    SPECIES_REGIELEKI,
    SPECIES_REGIDRAGO,
    SPECIES_GLASTRIER,
    SPECIES_SPECTRIER,
    SPECIES_CALYREX,
    SPECIES_ENAMORUS_INCARNATE,
    SPECIES_GREAT_TUSK,
    SPECIES_SCREAM_TAIL,
    SPECIES_BRUTE_BONNET,
    SPECIES_FLUTTER_MANE,
    SPECIES_SLITHER_WING,
    SPECIES_SANDY_SHOCKS,
    SPECIES_IRON_TREADS,
    SPECIES_IRON_BUNDLE,
    SPECIES_IRON_HANDS,
    SPECIES_IRON_JUGULIS,
    SPECIES_IRON_MOTH,
    SPECIES_IRON_THORNS,
    SPECIES_WO_CHIEN,
    SPECIES_CHIEN_PAO,
    SPECIES_TING_LU,
    SPECIES_CHI_YU,
    SPECIES_ROARING_MOON,
    SPECIES_IRON_VALIANT,
    SPECIES_KORAIDON,
    SPECIES_MIRAIDON,
    SPECIES_WALKING_WAKE,
    SPECIES_IRON_LEAVES,
    SPECIES_OKIDOGI,
    SPECIES_MUNKIDORI,
    SPECIES_FEZANDIPITI,
    SPECIES_OGERPON,
    SPECIES_ARCHALUDON,
    SPECIES_HYDRAPPLE,
    SPECIES_GOUGING_FIRE,
    SPECIES_RAGING_BOLT,
    SPECIES_IRON_BOULDER,
    SPECIES_IRON_CROWN,
    SPECIES_TERAPAGOS,
    SPECIES_PECHARUNT,
};

#define NUM_ROAMABLE_SPECIES ARRAY_COUNT(gRoamableSpecies)
#define MAX_ACTIVE_ROAMERS 5

u8 GetActiveRoamerCount(void)
{
    u8 count = 0;
    for (u8 i = 0; i < ROAMER_COUNT; i++)
    {
        if (ROAMER(i)->active)
            count++;
    }
    return count;
}

EWRAM_DATA u8 gRoamerNearbyIndexOverride = 0;

void NextRoamer(u32 roamerIndex)
{
    // Mark the current roamer as inactive
    if (roamerIndex >= 0 && roamerIndex < ROAMER_COUNT) {
        ROAMER(roamerIndex)->active = FALSE;
    }

    u8 activeCount = GetActiveRoamerCount();

    while (activeCount < MAX_ACTIVE_ROAMERS)
    {
        // Ensure the roamerIndex is within valid bounds
        if (roamerIndex >= ROAMER_COUNT)
        {
            // Handle invalid index
            NextRoamer(Random() % NUM_ROAMABLE_SPECIES);
        }

        // Check if there are any available roamer slots
        u8 availableRoamerIndex = ROAMER_COUNT; // Initialize to an invalid index
        for (u8 i = 0; i < ROAMER_COUNT; i++)
        {
            if (!ROAMER(i)->active)
            {
                availableRoamerIndex = i;
                break; // Found an available slot
            }
        }

        // If no available roamer slots, we can't spawn a new roamer
        if (availableRoamerIndex == ROAMER_COUNT)
        {
            // Handle case where all roamer slots are in use
            activeCount = MAX_ACTIVE_ROAMERS;
            return;
        }

        // Find an uncaught roamer species that hasn't been used in any roamer slot
        u16 nextRoamerSpecies = SPECIES_NONE;
        int attempts = 0; // Prevent infinite loops
        while (nextRoamerSpecies == SPECIES_NONE && attempts < NUM_ROAMABLE_SPECIES * 2)
        {
            u32 randomIndex = Random() % NUM_ROAMABLE_SPECIES;
            u16 potentialSpecies = gRoamableSpecies[randomIndex];

            // Check if this species has already been used in any roamer slot
            bool8 speciesAlreadyUsed = FALSE;
            for (u8 i = 0; i < ROAMER_COUNT; i++)
            {

                if (ROAMER(i)->species == potentialSpecies)
                {
                    speciesAlreadyUsed = TRUE;
                    break;
                }
            }

            if (!speciesAlreadyUsed)
            {
                nextRoamerSpecies = potentialSpecies;
            }
            attempts++;
        }

        // If we failed to find an unused species (means all roamable species have been caught)
        if (nextRoamerSpecies == SPECIES_NONE)
        {
            // All roamers have been caught. No new roamer will spawn.
            activeCount = MAX_ACTIVE_ROAMERS;
            return;
        }

        // Determine the level for the new roamer.
        u16 nextRoamerLevel = GetCurrentLevelCap();

        // Create the new roamer in the available slot
        TryAddRoamer(nextRoamerSpecies, nextRoamerLevel);
        StringCopy(gStringVar1, GetSpeciesName(nextRoamerSpecies));
        activeCount++;
    }
}

void GetRoamerLocation(u32 roamerIndex, u8 *mapGroup, u8 *mapNum)
{
    *mapGroup = sRoamerLocation[roamerIndex][MAP_GRP];
    *mapNum = sRoamerLocation[roamerIndex][MAP_NUM];
}
