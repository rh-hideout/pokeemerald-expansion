#include "global.h"
#include "nuzlocke.h"
#include "event_data.h"
#include "pokemon.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/region_map_sections.h"
#include "pokemon_storage_system.h"
#include "sprite.h"
#include "battle.h"
#include "battle_interface.h"
#include "overworld.h"
#include "config/battle.h"
#include "config/nuzlocke.h"
#include "save.h"
#include "string_util.h"

// Check if Nuzlocke mode is active
bool8 IsNuzlockeActive(void)
{
    return FlagGet(FLAG_NUZLOCKE);
}

// Location conversion for Nuzlocke tracking
static u8 GetNuzlockeLocationId(u8 currLocation)
{
    switch (currLocation)
    {
        
    // Cities and towns that have encounters are treated as separate areas
    case MAPSEC_LITTLEROOT_TOWN:
    case MAPSEC_OLDALE_TOWN:
    case MAPSEC_DEWFORD_TOWN:
    case MAPSEC_LAVARIDGE_TOWN:
    case MAPSEC_FALLARBOR_TOWN:
    case MAPSEC_VERDANTURF_TOWN:
    case MAPSEC_PACIFIDLOG_TOWN:
    case MAPSEC_PETALBURG_CITY:
    case MAPSEC_SLATEPORT_CITY:
    case MAPSEC_MAUVILLE_CITY:
    case MAPSEC_RUSTBORO_CITY:
    case MAPSEC_FORTREE_CITY:
    case MAPSEC_LILYCOVE_CITY:
    case MAPSEC_MOSSDEEP_CITY:
    case MAPSEC_SOOTOPOLIS_CITY:
    case MAPSEC_EVER_GRANDE_CITY:
        return currLocation;
        
    // Routes are separate areas
    case MAPSEC_ROUTE_101:
    case MAPSEC_ROUTE_102:
    case MAPSEC_ROUTE_103:
    case MAPSEC_ROUTE_104:
    case MAPSEC_ROUTE_105:
    case MAPSEC_ROUTE_106:
    case MAPSEC_ROUTE_107:
    case MAPSEC_ROUTE_108:
    case MAPSEC_ROUTE_109:
    case MAPSEC_ROUTE_110:
    case MAPSEC_ROUTE_111:
    case MAPSEC_ROUTE_112:
    case MAPSEC_ROUTE_113:
    case MAPSEC_ROUTE_114:
    case MAPSEC_ROUTE_115:
    case MAPSEC_ROUTE_116:
    case MAPSEC_ROUTE_117:
    case MAPSEC_ROUTE_118:
    case MAPSEC_ROUTE_119:
    case MAPSEC_ROUTE_120:
    case MAPSEC_ROUTE_121:
    case MAPSEC_ROUTE_122:
    case MAPSEC_ROUTE_123:
    case MAPSEC_ROUTE_124:
    case MAPSEC_ROUTE_125:
    case MAPSEC_ROUTE_126:
    case MAPSEC_ROUTE_127:
    case MAPSEC_ROUTE_128:
    case MAPSEC_ROUTE_129:
    case MAPSEC_ROUTE_130:
    case MAPSEC_ROUTE_131:
    case MAPSEC_ROUTE_132:
    case MAPSEC_ROUTE_133:
    case MAPSEC_ROUTE_134:
        return currLocation;
        
    // Caves and special areas
    case MAPSEC_GRANITE_CAVE:
    case MAPSEC_MT_CHIMNEY:
    case MAPSEC_SAFARI_ZONE:
    case MAPSEC_BATTLE_FRONTIER:
    case MAPSEC_RUSTURF_TUNNEL:
    case MAPSEC_ABANDONED_SHIP:
    case MAPSEC_NEW_MAUVILLE:
    case MAPSEC_METEOR_FALLS:
    case MAPSEC_MT_PYRE:
    case MAPSEC_SHOAL_CAVE:
    case MAPSEC_SEAFLOOR_CAVERN:
    case MAPSEC_VICTORY_ROAD:
    case MAPSEC_MIRAGE_ISLAND:
    case MAPSEC_CAVE_OF_ORIGIN:
    case MAPSEC_FIERY_PATH:
    case MAPSEC_JAGGED_PASS:
    case MAPSEC_SEALED_CHAMBER:
    case MAPSEC_SCORCHED_SLAB:
        return currLocation;
        
    // Underwater areas consolidated with their surface counterparts
    case MAPSEC_UNDERWATER_124:
        return MAPSEC_ROUTE_124;
    case MAPSEC_UNDERWATER_126:
        return MAPSEC_ROUTE_126;
    case MAPSEC_UNDERWATER_127:
        return MAPSEC_ROUTE_127;
    case MAPSEC_UNDERWATER_128:
        return MAPSEC_ROUTE_128;
    case MAPSEC_UNDERWATER_SOOTOPOLIS:
        return MAPSEC_SOOTOPOLIS_CITY;
    case MAPSEC_UNDERWATER_SEAFLOOR_CAVERN:
        return MAPSEC_SEAFLOOR_CAVERN;
    case MAPSEC_UNDERWATER_SEALED_CHAMBER:
        return MAPSEC_SEALED_CHAMBER;
    
    // Multiple areas consolidated
    case MAPSEC_METEOR_FALLS2:
        return MAPSEC_METEOR_FALLS;
    case MAPSEC_FIERY_PATH2:
        return MAPSEC_FIERY_PATH;
    case MAPSEC_JAGGED_PASS2:
        return MAPSEC_JAGGED_PASS;
        
    // Default to the location itself if not handled above
    default:
        return currLocation;
    }
}

// Official Nuzlocke location tracking functions - much more robust than our map-based approach
bool8 HasWildPokemonBeenSeenInLocation(u8 location, bool8 setEncounteredIfFirst)
{
    u8 varToCheck, bitToCheck;
    u16 varValue;
    const u16 pokemonSeenVars[] = {
        VAR_NUZLOCKE_ENCOUNTERS_1,
        VAR_NUZLOCKE_ENCOUNTERS_2,
        VAR_NUZLOCKE_ENCOUNTERS_3,
        VAR_NUZLOCKE_ENCOUNTERS_4,
    };
    
    location = GetNuzlockeLocationId(location);
    
    if (!FlagGet(FLAG_NUZLOCKE) || !FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        // Clear all encounter tracking if Nuzlocke not active
        VarSet(VAR_NUZLOCKE_ENCOUNTERS_1, 0);
        VarSet(VAR_NUZLOCKE_ENCOUNTERS_2, 0);
        VarSet(VAR_NUZLOCKE_ENCOUNTERS_3, 0);
        VarSet(VAR_NUZLOCKE_ENCOUNTERS_4, 0);
        VarSet(VAR_NUZLOCKE_CATCHES_1, 0);
        VarSet(VAR_NUZLOCKE_CATCHES_2, 0);
        VarSet(VAR_NUZLOCKE_CATCHES_3, 0);
        VarSet(VAR_NUZLOCKE_CATCHES_4, 0);
        return 0;
    }
    
    // Map location to variable index and bit position
    varToCheck = location / 16;  // Each variable stores 16 locations (16 bits)
    bitToCheck = location % 16;
    
    if (varToCheck >= 4)  // Safety check - we only have 4 variables
        return 0;
    
    varValue = VarGet(pokemonSeenVars[varToCheck]);
    
    if ((varValue & (1 << bitToCheck)) != 0)
    {
        // Already encountered in this location
        return 1;
    }
    else if (setEncounteredIfFirst)
    {
        // First encounter - mark it
        VarSet(pokemonSeenVars[varToCheck], varValue | (1 << bitToCheck));
    }
    
    return 0;
}

bool8 HasWildPokemonBeenCaughtInLocation(u8 location, bool8 setCaughtIfCaught)
{
    u8 varToCheck, bitToCheck;
    u16 varValue;
    const u16 pokemonCaughtVars[] = {
        VAR_NUZLOCKE_CATCHES_1,
        VAR_NUZLOCKE_CATCHES_2,
        VAR_NUZLOCKE_CATCHES_3,
        VAR_NUZLOCKE_CATCHES_4,
    };
    
    location = GetNuzlockeLocationId(location);
    
    if (!FlagGet(FLAG_NUZLOCKE) || !FlagGet(FLAG_SYS_POKEDEX_GET))
        return 0;
    
    // Map location to variable index and bit position
    varToCheck = location / 16;  // Each variable stores 16 locations (16 bits)
    bitToCheck = location % 16;
    
    if (varToCheck >= 4)  // Safety check - we only have 4 variables
        return 0;
    
    varValue = VarGet(pokemonCaughtVars[varToCheck]);
    
    if ((varValue & (1 << bitToCheck)) != 0)
    {
        // Already caught in this location
        return 1;
    }
    else if (setCaughtIfCaught)
    {
        // Mark as caught
        VarSet(pokemonCaughtVars[varToCheck], varValue | (1 << bitToCheck));
    }
    
    return 0;
}

// Legacy compatibility functions (internal use and wild_encounter.c)
static bool8 HasEncounteredInArea(u16 mapGroup, u16 mapNum)
{
    // For legacy compatibility, use current location
    if (!IsNuzlockeActive())
        return FALSE;
    
    u8 currentLocation = GetCurrentRegionMapSectionId();
    return HasWildPokemonBeenSeenInLocation(currentLocation, FALSE);
}

bool8 IsFirstEncounterInArea(u16 mapGroup, u16 mapNum)
{
    return IsNuzlockeActive() && !HasEncounteredInArea(mapGroup, mapNum);
}

// Dead Pokemon functions
bool8 IsMonDead(struct Pokemon *mon)
{
    if (!IsNuzlockeActive())
        return FALSE;
    
    return GetMonData(mon, MON_DATA_IS_DEAD);
}

bool8 IsBoxMonDead(struct BoxPokemon *boxMon)
{
    if (!IsNuzlockeActive())
        return FALSE;
    
    return GetBoxMonData(boxMon, MON_DATA_IS_DEAD);
}

void SetMonDead(struct Pokemon *mon, bool8 isDead)
{
    if (!IsNuzlockeActive())
        return;
    
    u32 deadFlag = isDead ? 1 : 0;
    SetMonData(mon, MON_DATA_IS_DEAD, &deadFlag);
}

void SetBoxMonDead(struct BoxPokemon *boxMon, bool8 isDead)
{
    if (!IsNuzlockeActive())
        return;
    
    u32 deadFlag = isDead ? 1 : 0;
    SetBoxMonData(boxMon, MON_DATA_IS_DEAD, &deadFlag);
}

// Species checking for duplicate clause
bool8 PlayerOwnsSpecies(u16 species)
{
    int i, j;
    
    if (!IsNuzlockeActive())
        return FALSE;
    
    // Check party
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 partySpecies = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        if (partySpecies != SPECIES_NONE && partySpecies == species)
            return TRUE;
    }
    
    // Check PC boxes
    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(i, j);
            u16 boxSpecies = GetBoxMonData(boxMon, MON_DATA_SPECIES);
            
            // Early exit if empty slot
            if (boxSpecies == SPECIES_NONE)
                continue;
            
            if (boxSpecies == species)
                return TRUE;
        }
    }
    
    return FALSE;
}

// Handle Pokemon fainting (mark as dead in Nuzlocke mode)
void NuzlockeHandleFaint(struct Pokemon *mon)
{
    if (!IsNuzlockeActive())
        return;
    
    // Don't mark as dead until player receives Pokédex
    if (!FlagGet(FLAG_SYS_POKEDEX_GET))
        return;
    
    // Check if the Pokemon's HP is 0 (just fainted)
    if (GetMonData(mon, MON_DATA_HP) == 0)
    {
        SetMonDead(mon, TRUE);
    }
}

void NuzlockeHandleWhiteout(void)
{
    if (!IsNuzlockeActive())
        return;
    
    // Don't mark as dead until player receives Pokédex
    if (!FlagGet(FLAG_SYS_POKEDEX_GET))
        return;
    
    int i;
    
    // Mark all party Pokemon as dead
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE && 
            !GetMonData(mon, MON_DATA_SANITY_IS_EGG))
        {
            SetMonDead(mon, TRUE);
        }
    }
}

bool8 NuzlockeCanCatchPokemon(u16 species, u32 personality, u32 otId)
{
    u8 currentLocation;
    
    if (!IsNuzlockeActive())
    {
        return TRUE; // Not in Nuzlocke mode - always allow catching
    }

    // Boss wild battles are outside Nuzlocke rules - catching unrestricted
    if (FlagGet(FLAG_NUZLOCKE_SKIP_ENCOUNTER))
        return TRUE;

    currentLocation = GetCurrentRegionMapSectionId();
    
    // Shiny clause: always allow shiny Pokemon regardless of other rules
    u32 shinyValue = ((personality >> 16) ^ (personality & 0xFFFF)) ^ ((otId >> 16) ^ (otId & 0xFFFF));
    bool8 isShiny = (shinyValue < 8);
    
    if (isShiny)
    {
        return TRUE;
    }
    
    // Check if we've already had our "real" first encounter in this location
    // (an encounter of a species we don't own, which counts as the area's encounter)
    if (HasWildPokemonBeenSeenInLocation(currentLocation, FALSE))
    {
        return FALSE;
    }
    
    // This is a potential first encounter - check duplicate clause
    if (PlayerOwnsSpecies(species))
    {
        return FALSE; // Don't catch, but this encounter doesn't count - keep hunting
    }
    
    // We don't own this species - this is our "real" first encounter for this area
    return TRUE;
}

void NuzlockeOnBattleEnd(void)
{
    // Boss wild battles set this flag to opt out of encounter tracking
    if (FlagGet(FLAG_NUZLOCKE_SKIP_ENCOUNTER))
        return;

    // Mark the current location as encountered when certain wild battles end
    if (IsNuzlockeActive() && !(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
    {
        u8 currentLocation = GetCurrentRegionMapSectionId();
        
        // Check if this area has already been marked as encountered
        bool8 alreadyEncountered = HasWildPokemonBeenSeenInLocation(currentLocation, FALSE);
        
        if (!alreadyEncountered)
        {
            // Get wild Pokemon info
            u16 wildSpecies = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
            u32 wildPersonality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);
            u32 wildOtId = GetMonData(&gEnemyParty[0], MON_DATA_OT_ID);
            
            // Check if it's a shiny - shiny clause means it doesn't consume the encounter
            u32 shinyValue = ((wildPersonality >> 16) ^ (wildPersonality & 0xFFFF)) ^ ((wildOtId >> 16) ^ (wildOtId & 0xFFFF));
            bool8 isShiny = (shinyValue < 8);
            
            if (isShiny)
            {
                // Shiny clause: don't mark area as used, even if caught/defeated/ran
                return;
            }
            
            // Check if it's a duplicate species - duplicate clause means can keep trying
            if (PlayerOwnsSpecies(wildSpecies))
            {
                // Duplicate clause: don't mark area as used, player can keep trying
                return;
            }
            
            // This was a catchable (non-duplicate, non-shiny) encounter
            // Mark the area as used regardless of outcome (caught, defeated, ran, teleported)
            HasWildPokemonBeenSeenInLocation(currentLocation, TRUE);
        }
    }
}

u8 GetNuzlockeEncounterStatus(u16 species, u32 personality, u32 otId)
{
    u8 currentLocation;
    
    if (!IsNuzlockeActive())
    {
        return NUZLOCKE_ENCOUNTER_NORMAL;
    }

    // Boss wild battles opt out of Nuzlocke tracking entirely
    if (FlagGet(FLAG_NUZLOCKE_SKIP_ENCOUNTER))
        return NUZLOCKE_ENCOUNTER_NORMAL;

    currentLocation = GetCurrentRegionMapSectionId();
    
    // Check shiny clause first (highest priority)
    u32 shinyValue = ((personality >> 16) ^ (personality & 0xFFFF)) ^ ((otId >> 16) ^ (otId & 0xFFFF));
    bool8 isShiny = (shinyValue < 8);
    
    if (isShiny)
    {
        return NUZLOCKE_ENCOUNTER_SHINY;
    }
    
    // Check if location already used
    if (HasWildPokemonBeenSeenInLocation(currentLocation, FALSE))
    {
        return NUZLOCKE_ENCOUNTER_NORMAL;
    }
    
    // Check duplicate clause
    if (PlayerOwnsSpecies(species))
    {
        return NUZLOCKE_ENCOUNTER_DUPLICATE;
    }
    
    // New species, first encounter - catchable!
    return NUZLOCKE_ENCOUNTER_CATCHABLE;
}

// Silent save for Nuzlocke mode (no confirmation prompt)
// Uses SAVE_LINK for faster saving (skips PC storage)
void NuzlockeSilentSave(void)
{
    TrySavingData(SAVE_LINK);
}

// ==========================================
// Nurse Joy PC Transfer Functions
// ==========================================

// Count how many dead Pokemon are in the party
static u8 CountDeadPartyMons(void)
{
    u8 count = 0;

    if (!IsNuzlockeActive() || !I_NUZLOCKE_PERMADEATH)
        return 0;

    for (u8 i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_EGG)
            && GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0
            && GetMonData(&gPlayerParty[i], MON_DATA_IS_DEAD, NULL))
        {
            count++;
        }
    }

    return count;
}

// Check if we can deposit a specific party mon to PC
// Returns FALSE if depositing would leave party with 0 alive non-egg mons
static bool8 CanDepositDeadMonToPC(u8 partySlot)
{
    if (partySlot >= PARTY_SIZE)
        return FALSE;

    // Check if depositing this mon would leave us with at least 1 alive non-egg mon
    u8 aliveCount = CountPartyAliveNonEggMonsExcept(partySlot);

    return (aliveCount > 0);
}

// Special function: Count dead party mons and return result
u16 CountDeadPartyMonsSpecial(void)
{
    if (!I_NUZLOCKE_NURSE_PC_TRANSFER)
        return 0;

    if (!IsNuzlockeActive() || !I_NUZLOCKE_PERMADEATH)
        return 0;

    return CountDeadPartyMons();
}

// Special function: Check if we can deposit a dead mon
// Uses gSpecialVar_0x8004 as party slot index
// Returns TRUE if can deposit, FALSE otherwise
bool8 CanDepositDeadMonSpecial(void)
{
    if (!I_NUZLOCKE_NURSE_PC_TRANSFER)
        return FALSE;

    if (!IsNuzlockeActive() || !I_NUZLOCKE_PERMADEATH)
        return FALSE;

    u8 slot = gSpecialVar_0x8004;
    return CanDepositDeadMonToPC(slot);
}

// Special function: Prepare info for the next dead mon
// Finds the first dead Pokemon in party and buffers its info
// Sets gSpecialVar_0x8004 to party slot index
// Buffers nickname to gStringVar1
void PrepareNextDeadMonInfo(void)
{
    // Always initialize to invalid slot first
    gSpecialVar_0x8004 = PARTY_SIZE;
    gStringVar1[0] = 0; // Empty string

    if (!I_NUZLOCKE_NURSE_PC_TRANSFER)
    {
        return;
    }

    if (!IsNuzlockeActive() || !I_NUZLOCKE_PERMADEATH)
    {
        return;
    }

    // Find first dead party mon
    for (u8 i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_EGG)
            && GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0
            && GetMonData(&gPlayerParty[i], MON_DATA_IS_DEAD, NULL))
        {
            gSpecialVar_0x8004 = i;
            GetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, gStringVar1);
            return;
        }
    }
}

// Special function: Deposit a dead party mon to the PC
// Uses gSpecialVar_0x8004 as party slot index
// Sets gSpecialVar_0x8005 to destination box number
// Returns gSpecialVar_0x8005 = TOTAL_BOXES_COUNT if PC is full
void DepositDeadPartyMonToPC(void)
{
    // Always initialize to failure value first
    gSpecialVar_0x8005 = TOTAL_BOXES_COUNT;

    if (!I_NUZLOCKE_NURSE_PC_TRANSFER)
    {
        return;
    }

    if (!IsNuzlockeActive() || !I_NUZLOCKE_PERMADEATH)
    {
        return;
    }

    u8 partySlot = gSpecialVar_0x8004;

    // Validate party slot
    if (partySlot >= PARTY_SIZE)
    {
        gSpecialVar_0x8005 = TOTAL_BOXES_COUNT;
        return;
    }

    // Validate that this mon is actually dead (HP = 0 AND dead flag set)
    if (GetMonData(&gPlayerParty[partySlot], MON_DATA_HP) != 0
        || !GetMonData(&gPlayerParty[partySlot], MON_DATA_IS_DEAD, NULL))
    {
        gSpecialVar_0x8005 = TOTAL_BOXES_COUNT;
        return;
    }

    // Find first free box slot across all boxes
    for (u8 box = 0; box < TOTAL_BOXES_COUNT; box++)
    {
        s16 position = GetFirstFreeBoxSpot(box);
        if (position >= 0)
        {
            // Copy mon to PC box
            SetBoxMonAt(box, position, &gPlayerParty[partySlot].box);

            // Zero out party slot
            ZeroMonData(&gPlayerParty[partySlot]);

            // Compact party to remove gaps
            CompactPartySlots();

            // Store box number for messaging
            gSpecialVar_0x8005 = box;
            return;
        }
    }

    // No space found in any box
    gSpecialVar_0x8005 = TOTAL_BOXES_COUNT;
}

// Show whiteout options for Nuzlocke (disable nuzlocke or continue)
void NuzlockeShowWhiteoutOption(void)
{
    // TODO: implement whiteout option UI
    gSpecialVar_Result = 0;
}

// Check if the selected party mon (gSpecialVar_0x8004) is dead
void IsSelectedPartyMonDead(void)
{
    u8 slot = gSpecialVar_0x8004;
    if (slot < PARTY_SIZE
        && GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES) != SPECIES_NONE
        && !GetMonData(&gPlayerParty[slot], MON_DATA_SANITY_IS_EGG)
        && GetMonData(&gPlayerParty[slot], MON_DATA_HP) == 0)
    {
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}
