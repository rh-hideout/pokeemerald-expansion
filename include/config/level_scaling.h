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
#define B_TRAINER_SCALING_DEFAULT_MODE      LEVEL_SCALING_TO_LEVEL_CAP
#define B_TRAINER_SCALING_LEVEL_AUGMENT     1       // Add/subtract levels from base (-127 to +127)
                                                     // Example: -2 makes trainers 2 levels lower
                                                     //          +5 makes trainers 5 levels higher
#define B_TRAINER_SCALING_LEVEL_VARIATION_PCT 10    // Random level reduction as % of base (0 = none)
                                                     // Example: 10 means up to 10% reduction
                                                     //          At level 10 → up to 1 level, level 50 → up to 5
#define B_TRAINER_SCALING_MIN_LEVEL         0       // Minimum level (0 = no minimum)
#define B_TRAINER_SCALING_MAX_LEVEL         0       // Maximum level (0 = no maximum)
#define B_TRAINER_SCALING_MANAGE_EVOLUTIONS TRUE    // Auto-devolve Pokemon if level too low
#define B_TRAINER_SCALING_EXCLUDE_FAINTED   FALSE   // Exclude fainted Pokemon from PARTY_* calculations
#define B_TRAINER_SCALING_SCALE_EVS         FALSE   // Scale defined EVs to scaled level (10 EVs/level, cap 510)
                                                     // Opt-in default; per-trainer override in level_scaling_rules.h
#define B_TRAINER_SCALING_SCALE_MOVES       FALSE   // Filter trainer-defined moves by legality at scaled level
                                                     // Opt-in default; per-trainer override in level_scaling_rules.h

// ============================================================================
// MOVE PROGRESSION TIER THRESHOLDS
// ============================================================================
// Minimum scaled level at which moves of each tier become available. Per-move tier
// data lives in src/data/move_progression_tiers.h. Moves not listed there default to
// MOVE_TIER_DEFAULT (no gate).

#define B_MOVE_TIER_MID_MIN_LEVEL           20
#define B_MOVE_TIER_LATE_MIN_LEVEL          40
#define B_MOVE_TIER_ENDGAME_MIN_LEVEL       100

// ============================================================================
// WILD POKÉMON SCALING DEFAULTS
// ============================================================================
// These settings apply to ALL wild Pokémon encounters unless you implement
// per-area or per-species overrides (future enhancement)

#define B_WILD_SCALING_ENABLED              TRUE
#define B_WILD_SCALING_DEFAULT_MODE         LEVEL_SCALING_PARTY_AVG
#define B_WILD_SCALING_LEVEL_AUGMENT        -3       // Add/subtract levels from base (-127 to +127)
                                                     // Example: -5 makes wild Pokémon 5 levels lower
#define B_WILD_SCALING_LEVEL_VARIATION_PCT  15      // Random level reduction as % of base (0 = none)
                                                     // Example: 15 means up to 15% reduction
                                                     //          At level 10 → up to 1-2 levels, level 50 → up to 7-8
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
