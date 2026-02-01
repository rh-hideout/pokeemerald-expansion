#ifndef GUARD_LEVEL_SCALING_H
#define GUARD_LEVEL_SCALING_H

#include "config/level_scaling.h"

// Forward declarations
struct Trainer;
struct Pokemon;

enum LevelScalingMode
{
    LEVEL_SCALING_NONE,                    // Vanilla behavior, no scaling
    LEVEL_SCALING_TO_LEVEL_CAP,            // Scale to current level cap (from caps.h)
    LEVEL_SCALING_PARTY_AVG,               // Scale to player's average party level
    LEVEL_SCALING_PARTY_HIGHEST,           // Scale to player's highest level
    LEVEL_SCALING_PARTY_LOWEST,            // Scale to player's lowest level
};

// Scaling configuration for a single entity (trainer or wild encounter)
struct LevelScalingConfig
{
    u8 mode;                    // enum LevelScalingMode
    s8 levelAugmentAdd;         // Add/subtract from calculated level (-128 to +127)
    u8 levelVariation;          // Random reduction range (0 = no variation)
    u8 minLevel;                // Minimum allowed level (0 = no minimum)
    u8 maxLevel;                // Maximum allowed level (0 = no maximum, use MAX_LEVEL)
    bool8 manageEvolutions;     // Enable automatic evolution validation
    bool8 excludeFainted;       // For PARTY_* modes, exclude fainted mons
};

// ============================================================================
// Configuration Macros (for use in level_scaling_rules.h)
// ============================================================================

// Explicitly disable scaling for a trainer (opt-out)
// Use this to prevent a trainer from being scaled when using default scaling
#define LEVEL_SCALING_CONFIG_NONE { \
    .mode = LEVEL_SCALING_NONE, \
    .levelAugmentAdd = 1, /* Non-zero to mark as explicit */ \
    .levelVariation = 0, \
    .minLevel = 0, \
    .maxLevel = 0, \
    .manageEvolutions = FALSE, \
    .excludeFainted = FALSE \
}

// Quick config macros for common scenarios
#define LEVEL_SCALING_CONFIG_LEVEL_CAP { \
    .mode = LEVEL_SCALING_TO_LEVEL_CAP, \
    .levelAugmentAdd = 0, \
    .levelVariation = 0, \
    .minLevel = 0, \
    .maxLevel = 0, \
    .manageEvolutions = TRUE, \
    .excludeFainted = FALSE \
}

#define LEVEL_SCALING_CONFIG_PARTY_AVG { \
    .mode = LEVEL_SCALING_PARTY_AVG, \
    .levelAugmentAdd = 0, \
    .levelVariation = 0, \
    .minLevel = 0, \
    .maxLevel = 0, \
    .manageEvolutions = TRUE, \
    .excludeFainted = FALSE \
}

#define LEVEL_SCALING_CONFIG_PARTY_HIGHEST { \
    .mode = LEVEL_SCALING_PARTY_HIGHEST, \
    .levelAugmentAdd = 0, \
    .levelVariation = 0, \
    .minLevel = 0, \
    .maxLevel = 0, \
    .manageEvolutions = TRUE, \
    .excludeFainted = FALSE \
}

// Evolution override for specific species
struct EvolutionOverride
{
    u16 species;                // Species that requires override
    u8 minimumLevel;            // Minimum level this species can appear at
    u8 padding;
};

#if B_LEVEL_SCALING_ENABLED

// Get current scaling config for a trainer
const struct LevelScalingConfig *GetTrainerLevelScalingConfig(u16 trainerId);

// Calculate scaled level for a trainer mon (internal use in battle_main.c)
u8 CalculateScaledLevel(const struct LevelScalingConfig *config, u8 originalLevel);

// Calculate scaled level for a wild Pokémon
u8 CalculateWildScaledLevel(u16 species, u8 originalLevel);

// Calculate scaled species for a wild Pokémon (handles evolution management)
u16 CalculateWildScaledSpecies(u16 species, u8 scaledLevel);

// Validate and potentially devolve species for target level
u16 ValidateSpeciesForLevel(u16 species, u8 targetLevel, bool8 manageEvolutions);

// Calculate base level from player's party based on mode
u8 CalculatePlayerPartyBaseLevel(u8 mode, bool8 excludeFainted);

// Check if evolution override exists for species
const struct EvolutionOverride *GetEvolutionOverride(u16 species);

// Invalidate cached party level data (call when party changes)
void InvalidatePartyLevelCache(void);

#else

// Empty inline functions when system is disabled
static inline void ApplyLevelScalingToTrainer(const struct Trainer *trainer, u16 trainerId,
                                               struct Pokemon *party, u8 partySize) { }
static inline u8 CalculateWildScaledLevel(u16 species, u8 originalLevel) { return originalLevel; }
static inline void InvalidatePartyLevelCache(void) { }

#endif // B_LEVEL_SCALING_ENABLED

#endif // GUARD_LEVEL_SCALING_H
