#ifndef GUARD_CONFIG_RANDOMIZER_H
#define GUARD_CONFIG_RANDOMIZER_H

// Global control. If FALSE, no randomizer functionality will be enabled.
// If this is TRUE, that doesn't necessarily mean that a particular part of the randomizer
// will be enabled.
#define RANDOMIZER_AVAILABLE                   TRUE
#define RANDOMIZER_SEED_IS_TRAINER_ID          TRUE

#if RANDOMIZER_AVAILABLE == TRUE

// If TRUE, the trainer ID (including secret ID) will be the randomizer seed.
#define RZ_TRAINER_ID_IS_SEED       TRUE

// If the longest evolutionary chain (excluding babies) is longer than this,
// the dynamic evolutionary stage randomization table will be generated
// incorrectly.
#define RANDOMIZER_MAX_EVO_STAGES   5

#define RANDOMIZER_MAX_TM           ITEM_TM50

#define RANDOMIZER_MON_MODE MON_RANDOM

// Vars and features

// These features allow you to force enable or disable individual randomization
// features.
// If undefined, the feature will be enabled if one of the flags below is set.
// If defined and set to TRUE, the feature will always be enabled.
// If defined and set to FALSE, the feature will always be disabled.
#define RANDOMIZE_WILD_MON      TRUE
#define RANDOMIZE_FIELD_ITEMS   FALSE
#define RANDOMIZE_TRAINER_MON   TRUE
#define RANDOMIZE_FIXED_MON     TRUE
#define RANDOMIZE_STARTERS      FALSE
#define RANDOMIZE_LEARNSET      TRUE
#define RANDOMIZE_ABILITIES     TRUE

#if RANDOMIZER_SEED_IS_TRAINER_ID == FALSE
#define RANDOMIZER_VAR_SEED_L               VAR_UNUSED_0x40FA
#define RANDOMIZER_VAR_SEED_H               VAR_UNUSED_0x40FB
#endif

#endif // RANDOMIZER_AVAILABLE

#endif // GUARD_CONFIG_RANDOMIZER_H