#include "global.h"
#include "battle_setup.h"
#include "config/habitat.h"
#include "event_data.h"
#include "habitat/bouts.h"
#include "habitat/finale.h"
#include "load_save.h"
#include "pokemon.h"
#include "constants/battle.h"
#include "constants/species.h"

static bool32 sBoutActive;
static enum HabitatBoutOutcome sLastBoutOutcome;
static struct HabitatBoutDefinition sBoutDefinition;
static bool32 sBoutAwardsFinaleFlag;

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
    sBoutAwardsFinaleFlag = Habitat_BoutIsApprovedFinaleDefinition(definition);
    if (definition != NULL)
        sBoutDefinition = *definition;
    else
        memset(&sBoutDefinition, 0, sizeof(sBoutDefinition));

    if (!IsValidHabitatBoutDefinition(&sBoutDefinition))
    {
        Habitat_BoutFinish(HABITAT_BOUT_ABORTED);
        return FALSE;
    }

    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    CreateMonWithIVs(&gParties[B_TRAINER_PLAYER][0], sBoutDefinition.playerSpecies,
                     sBoutDefinition.playerLevel, 0, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gParties[B_TRAINER_PLAYER][0]);
    gPartiesCount[B_TRAINER_PLAYER] = 1;
    CreateMonWithIVs(&gParties[B_TRAINER_OPPONENT_A][0], sBoutDefinition.opponentSpecies,
                     sBoutDefinition.opponentLevel, 0, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gParties[B_TRAINER_OPPONENT_A][0]);
    gPartiesCount[B_TRAINER_OPPONENT_A] = 1;

    BattleSetup_StartHabitatBout();
    return TRUE;
}

void Habitat_BoutFinish(enum HabitatBoutOutcome outcome)
{
    if (!sBoutActive)
        return;

    if (outcome == HABITAT_BOUT_WIN && sBoutAwardsFinaleFlag)
        FlagSet(gHabitatDeoxysFinale.bout->winFlag);

    LoadPlayerParty();
    sBoutActive = FALSE;
    sBoutAwardsFinaleFlag = FALSE;
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

bool32 Habitat_BoutIsApprovedFinaleDefinition(const struct HabitatBoutDefinition *definition)
{
    return definition == gHabitatDeoxysFinale.bout;
}

enum HabitatBoutOutcome Habitat_BoutOutcomeFromBattleOutcome(u8 battleOutcome)
{
    switch (battleOutcome)
    {
    case B_OUTCOME_WON:
        return HABITAT_BOUT_WIN;
    case B_OUTCOME_LOST:
    case B_OUTCOME_DREW:
    case B_OUTCOME_FORFEITED:
        return HABITAT_BOUT_LOSS;
    case B_OUTCOME_RAN:
    case B_OUTCOME_PLAYER_TELEPORTED:
    case B_OUTCOME_MON_FLED:
        return HABITAT_BOUT_FLED;
    default:
        return HABITAT_BOUT_ABORTED;
    }
}

bool32 Habitat_BoutReturnsToField(enum HabitatBoutOutcome outcome)
{
    return outcome != HABITAT_BOUT_NONE;
}
