#include "global.h"
#include "event_data.h"
#include "list_menu.h"
#include "malloc.h"
#include "script.h"
#include "script_menu.h"
#include "string_util.h"
#include "text.h"
#include "constants/species.h"
#include "constants/vars.h"
#include "constants/trainers.h"
#include "random.h"

// The 12 Starters available to the player
static const u16 sStarterSpecies[] = {
    SPECIES_BULBASAUR,  SPECIES_CHARMANDER, SPECIES_SQUIRTLE,
    SPECIES_CHIKORITA,  SPECIES_CYNDAQUIL,  SPECIES_TOTODILE,
    SPECIES_TREECKO,    SPECIES_TORCHIC,    SPECIES_MUDKIP,
    SPECIES_TURTWIG,    SPECIES_CHIMCHAR,   SPECIES_PIPLUP
};

// Maps each Rival Starter to the specific TRAINER_RIVAL_OAKS_LAB constants
static const u16 sRivalTrainerMapping[] = {
    TRAINER_RIVAL_OAKS_LAB_BULBASAUR,
    TRAINER_RIVAL_OAKS_LAB_CHARMANDER,
    TRAINER_RIVAL_OAKS_LAB_SQUIRTLE,
    TRAINER_RIVAL_OAKS_LAB_CHIKORITA,
    TRAINER_RIVAL_OAKS_LAB_CYNDAQUIL,
    TRAINER_RIVAL_OAKS_LAB_TOTODILE,
    TRAINER_RIVAL_OAKS_LAB_TREECKO,
    TRAINER_RIVAL_OAKS_LAB_TORCHIC,
    TRAINER_RIVAL_OAKS_LAB_MUDKIP,
    TRAINER_RIVAL_OAKS_LAB_TURTWIG,
    TRAINER_RIVAL_OAKS_LAB_CHIMCHAR,
    TRAINER_RIVAL_OAKS_LAB_PIPLUP
};

// Helper: Categorizes starters into type groups for logic checks
static u8 GetStarterType(u16 species) {
    switch (species) {
        case SPECIES_BULBASAUR:  case SPECIES_CHIKORITA: 
        case SPECIES_TREECKO:    case SPECIES_TURTWIG:
            return 0; // Grass
        case SPECIES_CHARMANDER: case SPECIES_CYNDAQUIL: 
        case SPECIES_TORCHIC:    case SPECIES_CHIMCHAR:
            return 1; // Fire
        default:
            return 2; // Water
    }
}

// Helper: Maps a Species ID back to the constant Trainer ID for the script's switch statement
static u16 GetRivalTrainerIdBySpecies(u16 species) {
    u8 i;
    for (i = 0; i < 12; i++) {
        if (sStarterSpecies[i] == species) {
            return sRivalTrainerMapping[i];
        }
    }
    return TRAINER_RIVAL_OAKS_LAB_BULBASAUR; // Fallback
}

// Logic: Filters the 12 starters and picks one that isn't weak to the player
static u16 GetRandomRivalStarter(u16 playerStarterSpecies) {
    u16 validPool[12];
    u8 poolIdx = 0;
    u8 playerType = GetStarterType(playerStarterSpecies);
    
    // Rival's "Safe" types: Same as player (Type A) or Strong against player (Type B)
    u8 typeA = playerType;
    u8 typeB = (playerType + 1) % 3;

    for (u8 i = 0; i < 12; i++) {
        u8 currentType = GetStarterType(sStarterSpecies[i]);
        
        // Add to pool if type is Neutral or Advantage, and it's not the player's exact mon
        if ((currentType == typeA || currentType == typeB) && sStarterSpecies[i] != playerStarterSpecies) {
            validPool[poolIdx++] = sStarterSpecies[i];
        }
    }

    // Pick a random winner from the filtered valid pool
    if (poolIdx > 0) {
        return validPool[Random() % poolIdx];
    }
    
    return SPECIES_BULBASAUR; // Absolute safety fallback
}

// Called by the script to open the selection UI
u8 OpenStarterSelectionMenu(void) {
    u32 i;
    struct ListMenuItem *items = (struct ListMenuItem *)Alloc(sizeof(struct ListMenuItem) * 12);
    
    for (i = 0; i < 12; i++) {
        u8 *name = (u8 *)Alloc(20);
        StringCopy(name, GetSpeciesName(sStarterSpecies[i]));
        items[i].name = name;
        items[i].id = sStarterSpecies[i];
    }
    
    // Returns Species ID to VAR_RESULT
    return ScriptMenu_MultichoiceDynamic(0, 0, 12, items, TRUE, 6, 0, 0);
}

// Called by the script after selection to lock in the Rival's team
void SetRivalTrainer(void) {
    u16 playerStarter = VarGet(VAR_TEMP_2);
    u16 rivalStarter = GetRandomRivalStarter(playerStarter);

    // VAR_TEMP_3: The Rival's Species (use for buffermonname in scripts)
    VarSet(VAR_TEMP_3, rivalStarter);

    // VAR_TEMP_4: The Rival's Trainer ID (use for the switch/case battle logic)
    VarSet(VAR_TEMP_4, GetRivalTrainerIdBySpecies(rivalStarter));
}
