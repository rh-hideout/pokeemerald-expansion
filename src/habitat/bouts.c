#include "global.h"
#include "battle_setup.h"
#include "config/habitat.h"
#include "event_data.h"
#include "habitat/bouts.h"
#include "load_save.h"
#include "pokemon.h"
#include "constants/species.h"

static bool32 sBoutActive;
static enum HabitatBoutOutcome sLastBoutOutcome;
static const struct HabitatBoutDefinition *sBoutDefinition;

static bool32 IsValidHabitatBoutDefinition(const struct HabitatBoutDefinition *definition)
{
    return definition != NULL
        && definition->playerSpecies != SPECIES_NONE
        && definition->playerSpecies < NUM_SPECIES
        && definition->playerLevel != 0
        && definition->opponentSpecies != SPECIES_NONE
        && definition->opponentSpecies < NUM_SPECIES
        && definition->opponentLevel != 0;
}

bool32 Habitat_BoutBegin(const struct HabitatBoutDefinition *definition)
{
    if (sBoutActive)
        return FALSE;

    // SaveBlock1's player-party mirror is the project's durable party backup.
    // Saving is unavailable while the temporary party is installed.
    SavePlayerParty();
    sBoutActive = TRUE;
    sBoutDefinition = definition;

    if (!IsValidHabitatBoutDefinition(definition))
    {
        Habitat_BoutFinish(HABITAT_BOUT_ABORTED);
        return FALSE;
    }

    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    CreateMonWithIVs(&gParties[B_TRAINER_PLAYER][0], definition->playerSpecies,
                     definition->playerLevel, 0, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gParties[B_TRAINER_PLAYER][0]);
    gPartiesCount[B_TRAINER_PLAYER] = 1;
    CreateMonWithIVs(&gParties[B_TRAINER_OPPONENT_A][0], definition->opponentSpecies,
                     definition->opponentLevel, 0, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gParties[B_TRAINER_OPPONENT_A][0]);
    gPartiesCount[B_TRAINER_OPPONENT_A] = 1;

    BattleSetup_StartHabitatBout();
    return TRUE;
}

void Habitat_BoutFinish(enum HabitatBoutOutcome outcome)
{
    if (!sBoutActive)
        return;

    if (outcome == HABITAT_BOUT_WIN
     && sBoutDefinition->boutId == HABITAT_BOUT_ID_DEOXYS_FINALE
     && sBoutDefinition->winFlag == FLAG_HABITAT_DEOXYS_FINALE_WON)
        FlagSet(FLAG_HABITAT_DEOXYS_FINALE_WON);

    LoadPlayerParty();
    sBoutActive = FALSE;
    sBoutDefinition = NULL;
    sLastBoutOutcome = outcome;
}

bool32 Habitat_BoutIsActive(void)
{
    return sBoutActive;
}

enum HabitatBoutOutcome Habitat_GetLastBoutOutcome(void)
{
    return sLastBoutOutcome;
}
