// ============================================================================
// PER-TRAINER LEVEL SCALING CONFIGURATION
// ============================================================================
//
// This file allows you to override the default scaling behavior for specific trainers.
//
// HOW IT WORKS:
// - Default behavior is defined in include/config/level_scaling.h
// - If B_TRAINER_SCALING_DEFAULT_MODE is set to anything other than LEVEL_SCALING_NONE,
//   ALL trainers will use that default configuration
// - Trainers listed here can override the default with custom rules
// - Use LEVEL_SCALING_CONFIG_NONE to explicitly disable scaling for a specific trainer
//
// EXAMPLES:
//
// 1. Override with custom config:
//    [TRAINER_ROXANNE_1] = {
//        .mode = LEVEL_SCALING_TO_LEVEL_CAP,
//        .levelAugmentAdd = 2,         // +2 levels above cap
//        .levelVariation = 1,          // Random 0-1 level reduction
//        .minLevel = 10,
//        .maxLevel = 50,
//        .manageEvolutions = TRUE,
//        .excludeFainted = FALSE,
//    },
//
// 2. Use a preset macro:
//    [TRAINER_BRAWLY_1] = LEVEL_SCALING_CONFIG_PARTY_AVG,
//
// 3. Explicitly disable scaling (opt-out):
//    [TRAINER_WALLY_VR_1] = LEVEL_SCALING_CONFIG_NONE,
//
// Available macros: LEVEL_SCALING_CONFIG_NONE, LEVEL_SCALING_CONFIG_LEVEL_CAP,
//                   LEVEL_SCALING_CONFIG_PARTY_AVG, LEVEL_SCALING_CONFIG_PARTY_HIGHEST

#include "constants/opponents.h"

const struct LevelScalingConfig gTrainerLevelScalingRules[TRAINERS_COUNT] =
{
    // Trainers not listed here will use the default from config/level_scaling.h

    // ============================================================================
    // TEST TRAINERS - For debugging and testing level scaling
    // ============================================================================

    // Test 1: Scale to level cap
    [TRAINER_ROXANNE_1] = {
        .mode = LEVEL_SCALING_TO_LEVEL_CAP,
        .levelAugmentAdd = 0,
        .levelVariation = 0,
        .manageEvolutions = TRUE,
    },

    // Test 2: Scale to party average + 3
    [TRAINER_BRAWLY_1] = {
        .mode = LEVEL_SCALING_PARTY_AVG,
        .levelAugmentAdd = 3,
        .levelVariation = 0,
        .manageEvolutions = TRUE,
        .excludeFainted = TRUE,
    },

    // Test 3: Scale to party highest
    [TRAINER_WATTSON_1] = {
        .mode = LEVEL_SCALING_PARTY_HIGHEST,
        .levelAugmentAdd = 0,
        .levelVariation = 2,
        .manageEvolutions = TRUE,
    },

    // Test 4: Scale to party lowest + 5
    [TRAINER_FLANNERY_1] = {
        .mode = LEVEL_SCALING_PARTY_LOWEST,
        .levelAugmentAdd = 5,
        .levelVariation = 0,
        .manageEvolutions = TRUE,
    },

    // Test 5: Scale to party highest + augment with variation
    [TRAINER_NORMAN_1] = {
        .mode = LEVEL_SCALING_PARTY_HIGHEST,
        .levelAugmentAdd = 2,
        .levelVariation = 3,
        .minLevel = 25,
        .maxLevel = 50,
        .manageEvolutions = TRUE,
    },

    // Test 6: Evolution management test (should devolve illegal mons)
    [TRAINER_WINONA_1] = {
        .mode = LEVEL_SCALING_TO_LEVEL_CAP,
        .levelAugmentAdd = -20,  // Reduce levels significantly
        .levelVariation = 0,
        .manageEvolutions = TRUE,
    },

    // Example configurations (commented out by default):

    /*
    // Gym Leaders scale to level cap + 2
    [TRAINER_ROXANNE_1] = {
        .mode = LEVEL_SCALING_TO_LEVEL_CAP,
        .levelAugmentAdd = 2,
        .levelVariation = 1,
        .minLevel = 0,
        .maxLevel = 0,
        .manageEvolutions = TRUE,
        .excludeFainted = FALSE,
    },

    [TRAINER_BRAWLY_1] = {
        .mode = LEVEL_SCALING_TO_LEVEL_CAP,
        .levelAugmentAdd = 2,
        .levelVariation = 1,
        .manageEvolutions = TRUE,
    },

    // Rival battles scale to player's highest
    [TRAINER_BRENDAN_ROUTE_103_TREECKO] = {
        .mode = LEVEL_SCALING_PARTY_HIGHEST,
        .levelAugmentAdd = 0,
        .levelVariation = 1,
        .manageEvolutions = TRUE,
        .excludeFainted = TRUE,
    },

    // Elite Four scale to party average + 5
    [TRAINER_SIDNEY] = {
        .mode = LEVEL_SCALING_PARTY_AVG,
        .levelAugmentAdd = 5,
        .levelVariation = 2,
        .minLevel = 55,
        .maxLevel = 75,
        .manageEvolutions = TRUE,
        .excludeFainted = TRUE,
    },

    [TRAINER_PHOEBE] = {
        .mode = LEVEL_SCALING_PARTY_AVG,
        .levelAugmentAdd = 5,
        .levelVariation = 2,
        .minLevel = 55,
        .maxLevel = 75,
        .manageEvolutions = TRUE,
        .excludeFainted = TRUE,
    },

    [TRAINER_GLACIA] = {
        .mode = LEVEL_SCALING_PARTY_AVG,
        .levelAugmentAdd = 5,
        .levelVariation = 2,
        .minLevel = 55,
        .maxLevel = 75,
        .manageEvolutions = TRUE,
        .excludeFainted = TRUE,
    },

    [TRAINER_DRAKE] = {
        .mode = LEVEL_SCALING_PARTY_AVG,
        .levelAugmentAdd = 5,
        .levelVariation = 2,
        .minLevel = 55,
        .maxLevel = 75,
        .manageEvolutions = TRUE,
        .excludeFainted = TRUE,
    },

    // Champion scales to party or PC highest
    [TRAINER_WALLACE] = {
        .mode = LEVEL_SCALING_PARTY_OR_PC_HIGHEST,
        .levelAugmentAdd = 7,
        .levelVariation = 2,
        .minLevel = 60,
        .maxLevel = 80,
        .manageEvolutions = TRUE,
        .excludeFainted = TRUE,
    },
    */
};
