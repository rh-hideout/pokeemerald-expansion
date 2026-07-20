#include "global.h"
#include "config/habitat.h"
#include "habitat/finale.h"
#include "constants/species.h"

static const struct HabitatCondition sDeoxysFinaleConditions[] = {
    HABITAT_COND(COND_BATTLE_WIN, 0, 0, 0, 0),
    HABITAT_CONDITIONS_END,
};

const struct HabitatFinaleGate gHabitatDeoxysFinale = {
    .species = SPECIES_DEOXYS,
    .conditions = sDeoxysFinaleConditions,
    .winFlag = FLAG_HABITAT_DEOXYS_FINALE_WON,
};
