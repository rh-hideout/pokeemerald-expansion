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
#define B_TRAINER_SCALING_SCALE_ITEMS       TRUE   // Strip held items above the allowed progression tier
                                                     // Opt-in default; per-trainer override in level_scaling_rules.h

// ============================================================================
// PARTY SIZE SCALING
// ============================================================================
// Dynamically caps how many Pokémon a scaled trainer fields, so early-game
// players don't face full 6-mon teams. Mode options (from level_scaling.h):
//   PARTY_SIZE_SCALING_NONE             - No cap (trainer fields full party)
//   PARTY_SIZE_SCALING_BY_PLAYER_SIZE   - Cap to the player's current party size
//   PARTY_SIZE_SCALING_BY_PLAYER_LEVEL  - Cap via the avg-level threshold table
//                                         in src/data/level_scaling_party_size_tiers.h
// Per-trainer overrides (level_scaling_rules.h) can set .partySizeMode; leaving
// it 0 (PARTY_SIZE_SCALING_INHERIT) falls back to this global default.
// Opt-in default; per-trainer override in level_scaling_rules.h

#define B_TRAINER_PARTY_SIZE_MODE           PARTY_SIZE_SCALING_BY_PLAYER_SIZE

// When the party-size cap reduces a trainer's team, this decides WHICH mons
// are dropped. BST is the post-scale, post-devolution species.
//   PARTY_SIZE_SORT_NONE             - Keep pool/declaration order (drop the tail)
//   PARTY_SIZE_SORT_KEEP_HIGHEST_BST - Drop lowest-BST mons (keep strongest team)
//   PARTY_SIZE_SORT_KEEP_LOWEST_BST  - Drop highest-BST mons (keep weakest team)
//   PARTY_SIZE_SORT_RANDOM           - Drop random mons
// Per-trainer override: .partySizeSort in level_scaling_rules.h (0 = inherit).

#define B_TRAINER_PARTY_SIZE_SORT           PARTY_SIZE_SORT_KEEP_LOWEST_BST

// When TRUE, ace-tagged mons (MON_POOL_TAG_ACE) are exempt from the BST filter
// and the party-size trim, so a trainer always fields their signature mon even
// if its scaled BST exceeds the level's ceiling. When FALSE, ace mons are
// gated/dropped like any other.

#define B_TRAINER_PARTY_ACE_EXEMPT          TRUE

// ============================================================================
// SHARED PROGRESSION TIER THRESHOLDS
// ============================================================================
// One set of scaled-level thresholds shared by move, item, and party BST
// gating. Per-move data: src/data/move_progression_tiers.h (default
// MOVE_TIER_DEFAULT). Per-item data: src/data/item_progression_tiers.h
// (default ITEM_TIER_DEFAULT).

#define B_SCALING_TIER_MID_MIN_LEVEL        20
#define B_SCALING_TIER_LATE_MIN_LEVEL       40
#define B_SCALING_TIER_ENDGAME_MIN_LEVEL    100

// Per-tier BST ceiling for trainer party members at a scaled level. A mon
// whose post-scale, post-devolution BST exceeds the ceiling for its band
// is dropped before the party-size cap is applied. A value of 999 means
// "no limit" once the level threshold is reached.
//   level <  MID_MIN_LEVEL                 -> BELOW_MID
//   MID_MIN_LEVEL    .. LATE_MIN_LEVEL-1   -> MID
//   LATE_MIN_LEVEL   .. ENDGAME_MIN_LEVEL-1-> LATE
//   level >= ENDGAME_MIN_LEVEL             -> ABOVE_ENDGAME

#define B_SCALING_BST_BELOW_MID             400
#define B_SCALING_BST_MID                   540
#define B_SCALING_BST_LATE                  999
#define B_SCALING_BST_ABOVE_ENDGAME         999

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
