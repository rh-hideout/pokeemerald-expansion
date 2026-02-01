#ifndef GUARD_CONFIG_LEVEL_SCALING_H
#define GUARD_CONFIG_LEVEL_SCALING_H

// ============================================================================
// MASTER TOGGLE
// ============================================================================
#define B_LEVEL_SCALING_ENABLED         TRUE

// ============================================================================
// TRAINER SCALING DEFAULTS
// ============================================================================
// These settings apply to ALL trainers by default unless overridden in
// src/data/level_scaling_rules.h
//
// Scaling mode options (defined in level_scaling.h):
//   LEVEL_SCALING_NONE                 - Vanilla behavior, no scaling
//   LEVEL_SCALING_TO_LEVEL_CAP         - Scale to current level cap (from caps.h)
//   LEVEL_SCALING_PARTY_AVG            - Scale to player's average party level
//   LEVEL_SCALING_PARTY_HIGHEST        - Scale to player's highest level
//   LEVEL_SCALING_PARTY_LOWEST         - Scale to player's lowest level
//
// Set B_TRAINER_SCALING_ENABLED to FALSE to disable all trainer scaling
// Set B_TRAINER_SCALING_DEFAULT_MODE to LEVEL_SCALING_NONE for opt-in behavior
//   (only trainers in level_scaling_rules.h are scaled)
// Set to any other mode for opt-out behavior (all trainers scaled unless explicitly disabled)

#define B_TRAINER_SCALING_ENABLED           TRUE
#define B_TRAINER_SCALING_DEFAULT_MODE      LEVEL_SCALING_PARTY_AVG
#define B_TRAINER_SCALING_LEVEL_AUGMENT     2       // Add/subtract levels from base (-127 to +127)
                                                     // Example: -2 makes trainers 2 levels lower
                                                     //          +5 makes trainers 5 levels higher
#define B_TRAINER_SCALING_LEVEL_VARIATION   4       // Random level reduction (0 to 255)
                                                     // Example: 3 means random(0-3) levels lower
                                                     //          Creates variety in trainer teams
#define B_TRAINER_SCALING_MIN_LEVEL         0       // Minimum level (0 = no minimum)
#define B_TRAINER_SCALING_MAX_LEVEL         0       // Maximum level (0 = no maximum)
#define B_TRAINER_SCALING_MANAGE_EVOLUTIONS TRUE    // Auto-devolve Pokemon if level too low
#define B_TRAINER_SCALING_EXCLUDE_FAINTED   FALSE   // Exclude fainted Pokemon from PARTY_* calculations

// ============================================================================
// WILD POKÉMON SCALING DEFAULTS
// ============================================================================
// These settings apply to ALL wild Pokémon encounters unless you implement
// per-area or per-species overrides (future enhancement)

#define B_WILD_SCALING_ENABLED              TRUE
#define B_WILD_SCALING_DEFAULT_MODE         LEVEL_SCALING_PARTY_AVG
#define B_WILD_SCALING_LEVEL_AUGMENT        -8       // Add/subtract levels from base (-127 to +127)
                                                     // Example: -5 makes wild Pokémon 5 levels lower
#define B_WILD_SCALING_LEVEL_VARIATION      4       // Random level reduction (0 to 255)
                                                     // Example: 3 means random(0-3) levels lower
                                                     //          Creates variety in wild encounters
#define B_WILD_SCALING_MIN_LEVEL            0       // Minimum level (0 = no minimum)
#define B_WILD_SCALING_MAX_LEVEL            0       // Maximum level (0 = no maximum)
#define B_WILD_SCALING_MANAGE_EVOLUTIONS    TRUE    // Auto-devolve wild Pokémon if level too low
#define B_WILD_SCALING_EXCLUDE_FAINTED      FALSE    // Exclude fainted Pokémon from PARTY_* calculations

// ============================================================================
// EVOLUTION OVERRIDE SYSTEM
// ============================================================================
// Controls whether evolution overrides (in level_scaling_evolution_overrides.h) are used
// Overrides allow Pokemon that don't evolve via level-up to appear at specific minimum levels
// Example: Gengar (trade evolution) can be set to appear at level 30+

#define B_SCALING_USE_OVERRIDES         TRUE    // Enable evolution overrides for trade/stone/special evolutions

// ============================================================================
// DEBUG OPTIONS
// ============================================================================

#define B_SCALING_DEBUG_PRINT           TRUE    // Print scaling calculations to debug console

#endif // GUARD_CONFIG_LEVEL_SCALING_H
