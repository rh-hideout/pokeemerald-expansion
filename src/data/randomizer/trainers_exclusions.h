#include "constants/trainers.h"

// Trainers listed in those data structures will be excluded
// from the randomizer
const enum TrainerClassID RandomizerTrainerClassExclusions[] = {
    // The following are provided as an example
    // TRAINER_CLASS_LEADER,
    // TRAINER_CLASS_ELITE_FOUR,
    // TRAINER_CLASS_CHAMPION,
    // TRAINER_CLASS_MAGMA_LEADER,
    // TRAINER_CLASS_AQUA_LEADER,
    // TRAINER_CLASS_RIVAL,
};

const u8 RandomizerTrainerNamesExclusions[][TRAINER_NAME_LENGTH + 1] = {
    // The following are provided as an example
    // _("JOSH"),
};