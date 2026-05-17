#ifndef GUARD_LEVEL_SCALING_H
#define GUARD_LEVEL_SCALING_H

#include "config/level_scaling.h"

// Forward declarations
struct Trainer;
struct Pokemon;

// Move progression tier — gates which moves trainer mons can carry at low scaled levels.
// Default (0) means no gate. Higher tiers require higher scaled levels (thresholds in config).
enum MoveProgressionTier
{
    MOVE_TIER_DEFAULT = 0,  // Always allowed (no gate)
    MOVE_TIER_MID,          // Allowed at >= B_SCALING_TIER_MID_MIN_LEVEL
    MOVE_TIER_LATE,         // Allowed at >= B_SCALING_TIER_LATE_MIN_LEVEL
    MOVE_TIER_ENDGAME,      // Allowed at >= B_SCALING_TIER_ENDGAME_MIN_LEVEL
};

// Item progression tier — gates which held items trainer mons can carry at low
// scaled levels. Default (0) means no gate. Mirrors MoveProgressionTier.
enum ItemProgressionTier
{
    ITEM_TIER_DEFAULT = 0,  // Always allowed (no gate)
    ITEM_TIER_MID,          // Allowed at >= B_SCALING_TIER_MID_MIN_LEVEL
    ITEM_TIER_LATE,         // Allowed at >= B_SCALING_TIER_LATE_MIN_LEVEL
    ITEM_TIER_ENDGAME,      // Allowed at >= B_SCALING_TIER_ENDGAME_MIN_LEVEL
};

enum LevelScalingMode
{
    LEVEL_SCALING_NONE,                    // Vanilla behavior, no scaling
    LEVEL_SCALING_TO_LEVEL_CAP,            // Scale to current level cap (from caps.h)
    LEVEL_SCALING_PARTY_AVG,               // Scale to player's average party level
    LEVEL_SCALING_PARTY_HIGHEST,           // Scale to player's highest level
    LEVEL_SCALING_PARTY_LOWEST,            // Scale to player's lowest level
};

// Party-size scaling source. INHERIT (0) lets a per-trainer rule fall back to
// the global B_TRAINER_PARTY_SIZE_MODE default; all other values are explicit.
enum PartySizeScalingMode
{
    PARTY_SIZE_SCALING_INHERIT = 0,    // Per-trainer: use global default
    PARTY_SIZE_SCALING_NONE,           // No party-size limit (full team)
    PARTY_SIZE_SCALING_BY_PLAYER_SIZE, // Cap to player's current party size
    PARTY_SIZE_SCALING_BY_PLAYER_LEVEL,// Cap via avg-level threshold table
};

// When party-size scaling reduces a trainer's team, this decides WHICH mons are
// dropped. INHERIT (0) falls back to the global B_TRAINER_PARTY_SIZE_SORT default.
enum PartySizeSortMode
{
    PARTY_SIZE_SORT_INHERIT = 0,        // Per-trainer: use global default
    PARTY_SIZE_SORT_NONE,               // Keep pool/declaration order (drop the tail)
    PARTY_SIZE_SORT_KEEP_HIGHEST_BST,   // Drop the lowest-BST mons (strongest team kept)
    PARTY_SIZE_SORT_KEEP_LOWEST_BST,    // Drop the highest-BST mons (weakest team kept)
    PARTY_SIZE_SORT_RANDOM,             // Drop random mons
};

// One row of the party-size threshold table (level_scaling_party_size_tiers.h).
struct PartySizeTier
{
    u8 maxAvgLevel;     // If player's avg party level <= this...
    u8 maxPartySize;    // ...cap the trainer's party to this many mons
};

// Scaling configuration for a single entity (trainer or wild encounter)
struct LevelScalingConfig
{
    u8 mode;                    // enum LevelScalingMode
    s8 levelAugmentAdd;         // Add/subtract from calculated level (-128 to +127)
    u8 levelVariationPct;       // Random reduction as % of base level (0 = no variation, 10 = up to 10%)
    u8 minLevel;                // Minimum allowed level (0 = no minimum)
    u8 maxLevel;                // Maximum allowed level (0 = no maximum, use MAX_LEVEL)
    bool8 manageEvolutions;     // Enable automatic evolution validation
    bool8 excludeFainted;       // For PARTY_* modes, exclude fainted mons
    bool8 scaleEVs;             // Scale defined EVs proportionally to scaled level (10/level, cap 510)
    bool8 scaleMoves;           // Filter trainer-defined moves by legality at scaled level; top up from level-up learnset
    bool8 scaleItems;           // Strip held items above the allowed progression tier at scaled level
    u8 partySizeMode;           // enum PartySizeScalingMode (INHERIT = use global default)
    u8 partySizeSort;           // enum PartySizeSortMode (INHERIT = use global default)
};

// ============================================================================
// Configuration Macros (for use in level_scaling_rules.h)
// ============================================================================

// Explicitly disable scaling for a trainer (opt-out)
// Use this to prevent a trainer from being scaled when using default scaling
#define LEVEL_SCALING_CONFIG_NONE { \
    .mode = LEVEL_SCALING_NONE, \
    .levelAugmentAdd = 1, /* Non-zero to mark as explicit */ \
    .levelVariationPct = 0, \
    .minLevel = 0, \
    .maxLevel = 0, \
    .manageEvolutions = FALSE, \
    .excludeFainted = FALSE, \
    .scaleEVs = FALSE, \
    .scaleMoves = FALSE, \
    .scaleItems = FALSE, \
    .partySizeMode = PARTY_SIZE_SCALING_NONE, \
    .partySizeSort = PARTY_SIZE_SORT_NONE \
}

// Quick config macros for common scenarios
#define LEVEL_SCALING_CONFIG_LEVEL_CAP { \
    .mode = LEVEL_SCALING_TO_LEVEL_CAP, \
    .levelAugmentAdd = 0, \
    .levelVariationPct = 0, \
    .minLevel = 0, \
    .maxLevel = 0, \
    .manageEvolutions = TRUE, \
    .excludeFainted = FALSE \
}

#define LEVEL_SCALING_CONFIG_PARTY_AVG { \
    .mode = LEVEL_SCALING_PARTY_AVG, \
    .levelAugmentAdd = 0, \
    .levelVariationPct = 0, \
    .minLevel = 0, \
    .maxLevel = 0, \
    .manageEvolutions = TRUE, \
    .excludeFainted = FALSE \
}

#define LEVEL_SCALING_CONFIG_PARTY_HIGHEST { \
    .mode = LEVEL_SCALING_PARTY_HIGHEST, \
    .levelAugmentAdd = 0, \
    .levelVariationPct = 0, \
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

// Apply scaled EVs to a mon if the trainer's config opts in. Returns TRUE if scaling applied
// (caller should skip the normal SetMonData EV path); FALSE means caller should set EVs normally.
bool32 TryApplyScaledTrainerEVs(struct Pokemon *mon, const u8 *baseEVs, u16 trainerId, u8 scaledLevel);

// TRUE if a move is permitted at the given scaled level (per its progression tier).
bool32 IsMovePermittedAtLevel(u16 move, u8 level);

// If trainer's config opts in (.scaleMoves), filter the moves currently set on `mon` against
// legality (species learnset at <= scaledLevel OR tier-gate predicate). Replace any dropped move
// with the next available level-up move from the scaled species. No-op if not opted in.
void MaybeFilterTrainerMoves(struct Pokemon *mon, u16 trainerId, u16 scaledSpecies, u8 scaledLevel);

// Resolve the scaled party size for a trainer (clamped to [1, originalPartySize]).
u8 GetScaledTrainerPartySize(u16 trainerId, u8 originalPartySize);

// Decide which of the `fullCount` drawn mons the trainer actually fields.
// Drops non-ace mons whose post-scale BST exceeds the level's tier ceiling,
// then applies the party-size cap using the resolved PartySizeSortMode (ace
// mons are always kept). The three parallel arrays (monIndices/scaledLevels/
// scaledSpecies) are reordered so the kept team occupies [0, return value).
u8 SelectScaledTrainerParty(const struct Trainer *trainer, u16 trainerId,
                            u32 *monIndices, u8 *scaledLevels, u16 *scaledSpecies, u8 fullCount);

// TRUE if a held item is permitted at the given scaled level (per its progression tier).
bool32 IsItemPermittedAtLevel(u16 item, u8 level);

// If trainer's config opts in (.scaleItems), clear the mon's held item when it
// is above the allowed progression tier for the scaled level. No-op otherwise.
void MaybeStripTrainerItem(struct Pokemon *mon, u16 trainerId, u8 scaledLevel);

#else

// Empty inline functions when system is disabled
static inline void ApplyLevelScalingToTrainer(const struct Trainer *trainer, u16 trainerId,
                                               struct Pokemon *party, u8 partySize) { }
static inline u8 CalculateWildScaledLevel(u16 species, u8 originalLevel) { return originalLevel; }
static inline void InvalidatePartyLevelCache(void) { }
static inline bool32 TryApplyScaledTrainerEVs(struct Pokemon *mon, const u8 *baseEVs, u16 trainerId, u8 scaledLevel) { return FALSE; }
static inline bool32 IsMovePermittedAtLevel(u16 move, u8 level) { return TRUE; }
static inline void MaybeFilterTrainerMoves(struct Pokemon *mon, u16 trainerId, u16 scaledSpecies, u8 scaledLevel) { }
static inline u8 GetScaledTrainerPartySize(u16 trainerId, u8 originalPartySize) { return originalPartySize; }
static inline u8 SelectScaledTrainerParty(const struct Trainer *trainer, u16 trainerId, u32 *monIndices, u8 *scaledLevels, u16 *scaledSpecies, u8 fullCount) { return fullCount; }
static inline bool32 IsItemPermittedAtLevel(u16 item, u8 level) { return TRUE; }
static inline void MaybeStripTrainerItem(struct Pokemon *mon, u16 trainerId, u8 scaledLevel) { }

#endif // B_LEVEL_SCALING_ENABLED

#endif // GUARD_LEVEL_SCALING_H
