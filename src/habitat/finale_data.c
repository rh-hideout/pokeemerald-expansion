#include "global.h"
#include "config/habitat.h"
#include "habitat/finale.h"
#include "constants/species.h"

static const struct HabitatCondition sDeoxysFinaleConditions[] = {
    HABITAT_COND(COND_BATTLE_WIN, 0, 0, 0, 0),
    HABITAT_CONDITIONS_END,
};

// Finale combat data is intentionally incomplete until a separately approved encounter exists.
static const struct HabitatBoutDefinition sDeoxysFinaleBout = {
    .boutId = HABITAT_BOUT_ID_DEOXYS_FINALE,
    .opponentSpecies = SPECIES_DEOXYS,
    .winFlag = FLAG_HABITAT_DEOXYS_FINALE_WON,
};

const struct HabitatFinaleGate gHabitatDeoxysFinale = {
    .species = SPECIES_DEOXYS,
    .conditions = sDeoxysFinaleConditions,
    .bout = &sDeoxysFinaleBout,
};
