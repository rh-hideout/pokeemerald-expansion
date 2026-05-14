#include "global.h"
#include "nuzlocke.h"
#include "challenge_menu.h"
#include "event_data.h"
#include "item.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/party_menu.h"
#include "constants/region_map_sections.h"
#include "overworld.h"
#include "pokedex.h"
#include "constants/pokedex.h"
#include "battle.h"

EWRAM_DATA u8 NuzlockeIsCaptureBlocked = FALSE;
EWRAM_DATA u8 NuzlockeIsSpeciesClauseActive = FALSE;
EWRAM_DATA u8 OneTypeChallengeCaptureBlocked = FALSE;

// Zone-to-bit mapping for one-encounter-per-area tracking.
// Only locations with wild encounters should be listed.
// Egg hatching counts as an encounter in the hatching zone.
// Special/gift Pokemon do NOT consume the zone's encounter.
static const u8 sNuzlockeLUT[] =
{
#if IS_HNS
    // Kanto Routes
    [MAPSEC_ROUTE_1]          = 0x00,
    [MAPSEC_ROUTE_2]          = 0x01,
    [MAPSEC_ROUTE_3]          = 0x02,
    [MAPSEC_ROUTE_4]          = 0x03,
    [MAPSEC_ROUTE_5]          = 0x04,
    [MAPSEC_ROUTE_6]          = 0x05,
    [MAPSEC_ROUTE_7]          = 0x06,
    [MAPSEC_ROUTE_8]          = 0x07,
    [MAPSEC_ROUTE_9]          = 0x08,
    [MAPSEC_ROUTE_10]         = 0x09,
    [MAPSEC_ROUTE_11]         = 0x0A,
    [MAPSEC_ROUTE_12]         = 0x0B,
    [MAPSEC_ROUTE_13]         = 0x0C,
    [MAPSEC_ROUTE_14]         = 0x0D,
    [MAPSEC_ROUTE_15]         = 0x0E,
    [MAPSEC_ROUTE_16]         = 0x0F,
    [MAPSEC_ROUTE_17]         = 0x10,
    [MAPSEC_ROUTE_18]         = 0x11,
    [MAPSEC_ROUTE_19]         = 0x12,
    [MAPSEC_ROUTE_20]         = 0x13,
    [MAPSEC_ROUTE_21]         = 0x14,
    [MAPSEC_ROUTE_22]         = 0x15,
    [MAPSEC_ROUTE_23]         = 0x16,
    [MAPSEC_ROUTE_24]         = 0x17,
    [MAPSEC_ROUTE_25]         = 0x18,
    // Johto-Kanto Routes
    [MAPSEC_ROUTE_26]         = 0x19,
    [MAPSEC_ROUTE_27]         = 0x1A,
    [MAPSEC_ROUTE_28]         = 0x1B,
    // Johto Routes
    [MAPSEC_ROUTE_29]         = 0x1C,
    [MAPSEC_ROUTE_30]         = 0x1D,
    [MAPSEC_ROUTE_31]         = 0x1E,
    [MAPSEC_ROUTE_32]         = 0x1F,
    [MAPSEC_ROUTE_33]         = 0x20,
    [MAPSEC_ROUTE_34]         = 0x21,
    [MAPSEC_ROUTE_35]         = 0x22,
    [MAPSEC_ROUTE_36]         = 0x23,
    [MAPSEC_ROUTE_37]         = 0x24,
    [MAPSEC_ROUTE_38]         = 0x25,
    [MAPSEC_ROUTE_39]         = 0x26,
    [MAPSEC_ROUTE_40]         = 0x27,
    [MAPSEC_ROUTE_41]         = 0x28,
    [MAPSEC_ROUTE_42]         = 0x29,
    [MAPSEC_ROUTE_43]         = 0x2A,
    [MAPSEC_ROUTE_44]         = 0x2B,
    [MAPSEC_ROUTE_45]         = 0x2C,
    [MAPSEC_ROUTE_46]         = 0x2D,
    [MAPSEC_ROUTE_47]         = 0x2E,
    [MAPSEC_ROUTE_48]         = 0x2F,
    // Dungeons: Johto
    [MAPSEC_DARK_CAVE]        = 0x30,
    [MAPSEC_SPROUT_TOWER]     = 0x31,
    [MAPSEC_RUINS_OF_ALPH]    = 0x32,
    [MAPSEC_UNION_CAVE]       = 0x33,
    [MAPSEC_SLOWPOKE_WELL]    = 0x34,
    [MAPSEC_ILEX_FOREST]      = 0x35,
    [MAPSEC_NATIONAL_PARK]    = 0x36,
    [MAPSEC_LAKE_OF_RAGE]     = 0x37,
    [MAPSEC_ICE_PATH]         = 0x38,
    [MAPSEC_MT_SILVER]        = 0x39,
    [MAPSEC_TOHJO_FALLS]      = 0x3A,
    [MAPSEC_SAFARI_ZONE_GATE] = 0x3B,
    [MAPSEC_DRAGONS_DEN]      = 0x3C,
    [MAPSEC_CLIFF_CAVE]       = 0x3D,
    [MAPSEC_ROCKET_HIDEOUT]   = 0x3E,
    [MAPSEC_TIN_TOWER]        = 0x3F,
    [MAPSEC_MT_MORTAR]        = 0x40,
    [MAPSEC_WHIRL_ISLANDS]    = 0x41,
    [MAPSEC_BURNED_TOWER]     = 0x42,
    [MAPSEC_SAFARI_ZONE]      = 0x43,
    // Dungeons: Kanto
    [MAPSEC_ROCK_TUNNEL]      = 0x44,
    [MAPSEC_SEAFOAM_ISLANDS]  = 0x45,
    [MAPSEC_VIRIDIAN_FOREST]  = 0x46,
    [MAPSEC_MT_MOON]          = 0x47,
    [MAPSEC_DIGLETTS_CAVE]    = 0x48,
    [MAPSEC_VICTORY_ROAD]     = 0x49,
    [MAPSEC_CERULEAN_CAVE]    = 0x4A,
    // Cities/Towns: Johto
    [MAPSEC_OLIVINE_CITY]     = 0x4B,
    [MAPSEC_BLACKTHORN_CITY]  = 0x4C,
    [MAPSEC_AZALEA_TOWN]      = 0x4D,
    [MAPSEC_MAHOGANY_TOWN]    = 0x4E,
    [MAPSEC_CIANWOOD_CITY]    = 0x4F,
    [MAPSEC_GOLDENROD_CITY]   = 0x50,
    [MAPSEC_CHERRYGROVE_CITY] = 0x51,
    [MAPSEC_NEW_BARK_TOWN]    = 0x52,
    [MAPSEC_VIOLET_CITY]      = 0x53,
    [MAPSEC_ECRUTEAK_CITY]    = 0x54,
    // Cities/Towns: Kanto
    [MAPSEC_VERMILION_CITY]   = 0x55,
    [MAPSEC_CERULEAN_CITY]    = 0x56,
    [MAPSEC_CINNABAR_ISLAND]  = 0x57,
    [MAPSEC_SAFFRON_CITY]     = 0x58,
    [MAPSEC_FUCHSIA_CITY]     = 0x59,
    [MAPSEC_CELADON_CITY]     = 0x5A,
    [MAPSEC_PALLET_TOWN]      = 0x5B,
    [MAPSEC_VIRIDIAN_CITY]    = 0x5C,
    [MAPSEC_PEWTER_CITY]      = 0x5D,
    [MAPSEC_LAVENDER_TOWN]    = 0x5E,
    [MAPSEC_BATTLE_FRONTIER]  = 0x5F,
#else
    // Hoenn Routes
    [MAPSEC_ROUTE_101]        = 0x00,
    [MAPSEC_ROUTE_102]        = 0x01,
    [MAPSEC_ROUTE_103]        = 0x02,
    [MAPSEC_ROUTE_104]        = 0x03,
    [MAPSEC_ROUTE_105]        = 0x04,
    [MAPSEC_ROUTE_106]        = 0x05,
    [MAPSEC_ROUTE_107]        = 0x06,
    [MAPSEC_ROUTE_108]        = 0x07,
    [MAPSEC_ROUTE_109]        = 0x08,
    [MAPSEC_ROUTE_110]        = 0x09,
    [MAPSEC_ROUTE_111]        = 0x0A,
    [MAPSEC_ROUTE_112]        = 0x0B,
    [MAPSEC_ROUTE_113]        = 0x0C,
    [MAPSEC_ROUTE_114]        = 0x0D,
    [MAPSEC_ROUTE_115]        = 0x0E,
    [MAPSEC_ROUTE_116]        = 0x0F,
    [MAPSEC_ROUTE_117]        = 0x10,
    [MAPSEC_ROUTE_118]        = 0x11,
    [MAPSEC_ROUTE_119]        = 0x12,
    [MAPSEC_ROUTE_120]        = 0x13,
    [MAPSEC_ROUTE_121]        = 0x14,
    [MAPSEC_ROUTE_122]        = 0x15,
    [MAPSEC_ROUTE_123]        = 0x16,
    [MAPSEC_ROUTE_124]        = 0x17,
    [MAPSEC_ROUTE_125]        = 0x18,
    [MAPSEC_ROUTE_126]        = 0x19,
    [MAPSEC_ROUTE_127]        = 0x1A,
    [MAPSEC_ROUTE_128]        = 0x1B,
    [MAPSEC_ROUTE_129]        = 0x1C,
    [MAPSEC_ROUTE_130]        = 0x1D,
    [MAPSEC_ROUTE_131]        = 0x1E,
    [MAPSEC_ROUTE_132]        = 0x1F,
    [MAPSEC_ROUTE_133]        = 0x20,
    [MAPSEC_ROUTE_134]        = 0x21,
    // Hoenn Dungeons
    [MAPSEC_GRANITE_CAVE]     = 0x22,
    [MAPSEC_MT_CHIMNEY]       = 0x23,
    [MAPSEC_PETALBURG_WOODS]  = 0x24,
    [MAPSEC_RUSTURF_TUNNEL]   = 0x25,
    [MAPSEC_ABANDONED_SHIP]   = 0x26,
    [MAPSEC_NEW_MAUVILLE]     = 0x27,
    [MAPSEC_METEOR_FALLS]     = 0x28,
    [MAPSEC_MT_PYRE]          = 0x29,
    [MAPSEC_SHOAL_CAVE]       = 0x2A,
    [MAPSEC_SEAFLOOR_CAVERN]  = 0x2B,
    [MAPSEC_VICTORY_ROAD]     = 0x2C,
    [MAPSEC_CAVE_OF_ORIGIN]   = 0x2D,
    [MAPSEC_FIERY_PATH]       = 0x2E,
    [MAPSEC_JAGGED_PASS]      = 0x2F,
    [MAPSEC_SKY_PILLAR]       = 0x30,
    [MAPSEC_SAFARI_ZONE]      = 0x31,
    [MAPSEC_SCORCHED_SLAB]    = 0x32,
    [MAPSEC_ISLAND_CAVE]      = 0x33,
    [MAPSEC_DESERT_RUINS]     = 0x34,
    [MAPSEC_ANCIENT_TOMB]     = 0x35,
    [MAPSEC_MIRAGE_ISLAND]    = 0x36,
    [MAPSEC_ARTISAN_CAVE]     = 0x37,
    [MAPSEC_MARINE_CAVE]      = 0x38,
    [MAPSEC_TERRA_CAVE]       = 0x39,
    [MAPSEC_DESERT_UNDERPASS] = 0x3A,
    [MAPSEC_ALTERING_CAVE]    = 0x3B,
    // Kanto Routes
    [MAPSEC_ROUTE_1]          = 0x3C,
    [MAPSEC_ROUTE_2]          = 0x3D,
    [MAPSEC_ROUTE_3]          = 0x3E,
    [MAPSEC_ROUTE_4]          = 0x3F,
    [MAPSEC_ROUTE_5]          = 0x40,
    [MAPSEC_ROUTE_6]          = 0x41,
    [MAPSEC_ROUTE_7]          = 0x42,
    [MAPSEC_ROUTE_8]          = 0x43,
    [MAPSEC_ROUTE_9]          = 0x44,
    [MAPSEC_ROUTE_10]         = 0x45,
    [MAPSEC_ROUTE_11]         = 0x46,
    [MAPSEC_ROUTE_12]         = 0x47,
    [MAPSEC_ROUTE_13]         = 0x48,
    [MAPSEC_ROUTE_14]         = 0x49,
    [MAPSEC_ROUTE_15]         = 0x4A,
    [MAPSEC_ROUTE_16]         = 0x4B,
    [MAPSEC_ROUTE_17]         = 0x4C,
    [MAPSEC_ROUTE_18]         = 0x4D,
    [MAPSEC_ROUTE_19]         = 0x4E,
    [MAPSEC_ROUTE_20]         = 0x4F,
    [MAPSEC_ROUTE_21]         = 0x50,
    [MAPSEC_ROUTE_22]         = 0x51,
    [MAPSEC_ROUTE_23]         = 0x52,
    [MAPSEC_ROUTE_24]         = 0x53,
    [MAPSEC_ROUTE_25]         = 0x54,
    // Kanto Dungeons
    [MAPSEC_VIRIDIAN_FOREST]  = 0x55,
    [MAPSEC_MT_MOON]          = 0x56,
    [MAPSEC_DIGLETTS_CAVE]    = 0x57,
    [MAPSEC_KANTO_VICTORY_ROAD] = 0x58,
    [MAPSEC_ROCK_TUNNEL]      = 0x59,
    [MAPSEC_SEAFOAM_ISLANDS]  = 0x5A,
    [MAPSEC_CERULEAN_CAVE]    = 0x5B,
    [MAPSEC_POWER_PLANT]      = 0x5C,
    [MAPSEC_POKEMON_TOWER]    = 0x5D,
    [MAPSEC_POKEMON_MANSION]  = 0x5E,
    [MAPSEC_KANTO_SAFARI_ZONE] = 0x5F,
    // FRLG Islands
    [MAPSEC_MT_EMBER]         = 0x60,
    [MAPSEC_BERRY_FOREST]     = 0x61,
    [MAPSEC_ICEFALL_CAVE]     = 0x62,
    [MAPSEC_LOST_CAVE]        = 0x63,
    [MAPSEC_PATTERN_BUSH]     = 0x64,
    [MAPSEC_BATTLE_FRONTIER]  = 0x65,
#endif
};

bool8 IsNuzlockeActive(void)
{
    struct ChallengeSettings *cs = &gSaveBlock3Ptr->challengeSettings;

    if (!FlagGet(FLAG_SYS_POKEMON_GET))
        return FALSE;
    if (!FlagGet(FLAG_START_NUZLOCKE))
        return FALSE;
    if (FlagGet(FLAG_END_NUZLOCKE))
        return FALSE;

    return cs->tx_Challenges_Nuzlocke;
}

bool8 IsNuzlockeNicknamingActive(void)
{
    struct ChallengeSettings *cs = &gSaveBlock3Ptr->challengeSettings;

    if (!cs->tx_Challenges_Nuzlocke)
        return FALSE;
    if (FlagGet(FLAG_END_NUZLOCKE))
        return FALSE;

    return cs->tx_Nuzlocke_Nicknaming;
}

u8 NuzlockeFlagSet(u16 mapsec)
{
    u16 id = sNuzlockeLUT[mapsec];
    u8 *ptr = &gSaveBlock3Ptr->challengeSettings.nuzlockeEncounterFlags[id / 8];

    *ptr |= 1 << (id & 7);
    return 0;
}

u8 NuzlockeFlagClear(u16 mapsec)
{
    u16 id = sNuzlockeLUT[mapsec];
    u8 *ptr = &gSaveBlock3Ptr->challengeSettings.nuzlockeEncounterFlags[id / 8];

    *ptr &= ~(1 << (id & 7));
    return 0;
}

u8 NuzlockeFlagGet(u16 mapsec)
{
    u16 id = sNuzlockeLUT[mapsec];
    u8 *ptr = &gSaveBlock3Ptr->challengeSettings.nuzlockeEncounterFlags[id / 8];

    if (!((*ptr >> (id & 7)) & 1))
        return 0;
    return 1;
}

void NuzlockeDeletePartyMon(u8 position)
{
    struct ChallengeSettings *cs = &gSaveBlock3Ptr->challengeSettings;

    if (!cs->tx_Nuzlocke_Deletion)
    {
        CopyMonToPC(&gPlayerParty[position]);
    }
    PurgeMonOrBoxMon(TOTAL_BOXES_COUNT, position);
}

void NuzlockeDeletePartyMonOption(u8 position)
{
    CopyMonToPC(&gPlayerParty[position]);
    PurgeMonOrBoxMon(TOTAL_BOXES_COUNT, position);
}

void NuzlockeDeleteFaintedPartyPokemon(void)
{
    u8 i;
    struct Pokemon *pokemon;
    u16 item = ITEM_NONE;
    struct ChallengeSettings *cs = &gSaveBlock3Ptr->challengeSettings;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        pokemon = &gPlayerParty[i];
        if (GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES, NULL)
            && !GetMonData(pokemon, MON_DATA_IS_EGG, NULL))
        {
            if (GetMonAilment(pokemon) == AILMENT_FNT)
            {
                u32 monItem = GetMonData(pokemon, MON_DATA_HELD_ITEM, NULL);
                if (monItem != ITEM_NONE)
                {
                    AddBagItem(monItem, 1);
                    SetMonData(pokemon, MON_DATA_HELD_ITEM, &item);
                }
                if (cs->tx_Nuzlocke_EasyMode && !IsNuzlockeActive())
                    NuzlockeDeletePartyMonOption(i);
                else
                    NuzlockeDeletePartyMon(i);
            }
        }
    }
    CompactPartySlots();
}

u8 NuzlockeGetCurrentRegionMapSectionId(void)
{
    return GetCurrentRegionMapSectionId();
}

static bool8 IsEvoFamilyCaught(u16 species)
{
    const struct Evolution *evolutions;
    int i;

    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
        return TRUE;

    evolutions = GetSpeciesEvolutions(species);
    if (evolutions == NULL)
        return FALSE;

    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        if (IsEvoFamilyCaught(evolutions[i].targetSpecies))
            return TRUE;
    }
    return FALSE;
}

u8 NuzlockeIsCaptureBlockedBySpeciesClause(u16 species)
{
    u16 baseSpecies;
    struct ChallengeSettings *cs = &gSaveBlock3Ptr->challengeSettings;

    if (!cs->tx_Nuzlocke_SpeciesClause)
        return FALSE;

    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
        return 2;

    baseSpecies = species;
    while (GetSpeciesPreEvolution(baseSpecies) != SPECIES_NONE)
        baseSpecies = GetSpeciesPreEvolution(baseSpecies);

    if (IsEvoFamilyCaught(baseSpecies))
        return TRUE;

    return FALSE;
}

void SetNuzlockeChecks(void)
{
    if (IsOneTypeChallengeActive())
    {
        u8 typeChallenge = gSaveBlock3Ptr->challengeSettings.tx_Challenges_OneTypeChallenge;
        u16 species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
        OneTypeChallengeCaptureBlocked = (GetSpeciesType(species, 0) != typeChallenge
                                       && GetSpeciesType(species, 1) != typeChallenge);
    }
    else
    {
        OneTypeChallengeCaptureBlocked = FALSE;
    }

    if (IsNuzlockeActive())
    {
        NuzlockeIsSpeciesClauseActive = NuzlockeIsCaptureBlockedBySpeciesClause(
            GetMonData(&gEnemyParty[0], MON_DATA_SPECIES));

        NuzlockeIsCaptureBlocked = NuzlockeFlagGet(NuzlockeGetCurrentRegionMapSectionId());

        if (IsMonShiny(&gEnemyParty[0]) && gSaveBlock3Ptr->challengeSettings.tx_Nuzlocke_ShinyClause)
        {
            NuzlockeIsCaptureBlocked = FALSE;
            NuzlockeIsSpeciesClauseActive = FALSE;
        }

        {
            u16 species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
            if (gSpeciesInfo[species].isRestrictedLegendary
                || gSpeciesInfo[species].isSubLegendary
                || gSpeciesInfo[species].isMythical)
            {
                NuzlockeIsCaptureBlocked = FALSE;
                NuzlockeIsSpeciesClauseActive = FALSE;
            }
        }
    }
    else
    {
        NuzlockeIsCaptureBlocked = FALSE;
        NuzlockeIsSpeciesClauseActive = FALSE;
    }
}
