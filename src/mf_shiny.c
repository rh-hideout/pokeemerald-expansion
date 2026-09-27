#include "global.h"
#include "mf_rules.h"
#include "mf_shiny.h"
#include "pokemon.h"
#include "constants/pokemon.h"

u32 MfShinyOddsThresholdForChance(u8 shinyChance)
{
    if (shinyChance >= MF_SHINY_CHANCE_COUNT)
        shinyChance = MF_SHINY_CHANCE_8192;

    // SHINY_ODDS (8) → 8, 16, 32, 64, 128 for 1/8192 … 1/512.
    return (u32)SHINY_ODDS << shinyChance;
}

u32 MfGetShinyOddsThreshold(void)
{
    return MfShinyOddsThresholdForChance(MfRules_GetShinyChance());
}

bool32 MfIsShinyValue(u32 shinyValue)
{
    return shinyValue < MfGetShinyOddsThreshold();
}

bool32 MfIsShinyOtIdPersonality(u32 otId, u32 personality)
{
    return MfIsShinyValue(GET_SHINY_VALUE(otId, personality));
}
