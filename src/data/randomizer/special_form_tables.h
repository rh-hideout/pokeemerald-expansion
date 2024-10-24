#include "global.h"
#include "constants/species.h"

const u16 sPaldeanTaurosFormChoices[] = {
    SPECIES_TAUROS_PALDEA_AQUA,
    SPECIES_TAUROS_PALDEA_BLAZE,
    SPECIES_TAUROS_PALDEA_COMBAT,
};

const u16 sFloetteFormChoices[] = {
    SPECIES_FLOETTE_BLUE,
    SPECIES_FLOETTE_ORANGE,
    SPECIES_FLOETTE_RED,
    SPECIES_FLOETTE_WHITE,
    SPECIES_FLOETTE_YELLOW,
};

const u16 sMiniorFormChoices[] = {
    SPECIES_MINIOR_METEOR_GREEN,
    SPECIES_MINIOR_METEOR_INDIGO,
    SPECIES_MINIOR_METEOR_BLUE,
    SPECIES_MINIOR_METEOR_ORANGE,
    SPECIES_MINIOR_METEOR_VIOLET,
    SPECIES_MINIOR_METEOR_RED,
    SPECIES_MINIOR_METEOR_YELLOW,
};

struct RandomizerRareFormInfo {
    u16 commonForm;
    u16 rareForm;
    // The rare form has a 1/inverseRareFormChance of appearing.
    u32 inverseRareFormChance;
};

const struct RandomizerRareFormInfo sMausholdRareFormInfo =
{
    .commonForm = SPECIES_MAUSHOLD_FOUR,
    .rareForm = SPECIES_MAUSHOLD_THREE,
    .inverseRareFormChance = 100
};

const struct RandomizerRareFormInfo sSinisteaRareFormInfo =
{
    .commonForm = SPECIES_SINISTEA_PHONY,
    .rareForm = SPECIES_SINISTEA_ANTIQUE,
    .inverseRareFormChance = 100
};

const struct RandomizerRareFormInfo sPoltchageistRareFormInfo =
{
    .commonForm = SPECIES_POLTCHAGEIST_COUNTERFEIT,
    .rareForm = SPECIES_POLTCHAGEIST_ARTISAN,
    .inverseRareFormChance = 100
};

const struct RandomizerRareFormInfo sSinistchaRareFormInfo =
{
    .commonForm = SPECIES_SINISTCHA_UNREMARKABLE,
    .rareForm = SPECIES_SINISTCHA_MASTERPIECE,
    .inverseRareFormChance = 100
};

const struct RandomizerRareFormInfo sPolteageistRareFormInfo =
{
    .commonForm = SPECIES_POLTEAGEIST_PHONY,
    .rareForm = SPECIES_POLTEAGEIST_ANTIQUE,
    .inverseRareFormChance = 100
};

const struct RandomizerRareFormInfo sDudunsparceRareFormInfo =
{
    .commonForm = SPECIES_DUDUNSPARCE_TWO_SEGMENT,
    .rareForm = SPECIES_DUDUNSPARCE_THREE_SEGMENT,
    .inverseRareFormChance = 100
};