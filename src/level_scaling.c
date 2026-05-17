#include "global.h"
#include "level_scaling.h"
#include "pokemon.h"
#include "move.h"
#include "data.h"
#include "caps.h"
#include "random.h"
#include "pokemon_storage_system.h"
#include "trainer_pools.h"
#include "constants/trainers.h"
#include "constants/pokemon.h"

#if B_LEVEL_SCALING_ENABLED

#include "data/level_scaling_rules.h"
#include "data/level_scaling_evolution_overrides.h"
#include "data/move_progression_tiers.h"
#include "data/item_progression_tiers.h"
#include "data/level_scaling_party_size_tiers.h"

// Party level cache for performance
static struct {
    u8 partyAverage;
    u8 partyHighest;
    u8 partyLowest;
    bool8 cached;
} sPartyLevelCache = {0};

// ============================================================================
// Internal Helper Functions - Party Level Calculation
// ============================================================================

static u8 GetPlayerPartyAverageLevel(bool8 excludeFainted)
{
    u32 totalLevel = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
            break;

        if (excludeFainted && GetMonData(mon, MON_DATA_HP) == 0)
            continue;

        totalLevel += GetMonData(mon, MON_DATA_LEVEL);
        count++;
    }

    if (count == 0)
        return 1; // Fallback if no valid mons

    return totalLevel / count;
}

static u8 GetPlayerPartyHighestLevel(bool8 excludeFainted)
{
    u8 highest = 1;
    u32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
            break;

        if (excludeFainted && GetMonData(mon, MON_DATA_HP) == 0)
            continue;

        u8 level = GetMonData(mon, MON_DATA_LEVEL);
        if (level > highest)
            highest = level;
    }

    return highest;
}

static u8 GetPlayerPartyLowestLevel(bool8 excludeFainted)
{
    u8 lowest = MAX_LEVEL;
    u32 i;
    bool8 foundMon = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
            break;

        if (excludeFainted && GetMonData(mon, MON_DATA_HP) == 0)
            continue;

        u8 level = GetMonData(mon, MON_DATA_LEVEL);
        if (level < lowest)
        {
            lowest = level;
            foundMon = TRUE;
        }
    }

    return foundMon ? lowest : 1;
}

static u8 GetPlayerPartySize(bool8 excludeFainted)
{
    u8 count = 0;
    u32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
            break;

        if (excludeFainted && GetMonData(mon, MON_DATA_HP) == 0)
            continue;

        count++;
    }

    return count > 0 ? count : 1;
}

// ============================================================================
// Internal Helper Functions - Level Manipulation
// ============================================================================

static u8 ApplyLevelVariation(u8 baseLevel, u8 variationPct)
{
    u8 maxReduction;

    if (variationPct == 0)
        return baseLevel;

    // Compute max reduction proportional to base level
    // Use u16 intermediate to avoid overflow before dividing
    maxReduction = (u8)((u16)baseLevel * variationPct / 100);

    // Guarantee at least 1 level of spread when pct is non-zero
    if (maxReduction == 0)
        maxReduction = 1;

    u8 reduction = Random() % (maxReduction + 1);
    if (baseLevel > reduction)
        return baseLevel - reduction;

    return 1; // Never go below 1
}

static u8 ClampLevel(u8 level, u8 minLevel, u8 maxLevel)
{
    // Apply minimum
    if (minLevel > 0 && level < minLevel)
        level = minLevel;

    // Apply maximum
    if (maxLevel > 0 && level > maxLevel)
        level = maxLevel;

    // Ensure level is always valid
    if (level < 1)
        level = 1;
    if (level > MAX_LEVEL)
        level = MAX_LEVEL;

    return level;
}

// ============================================================================
// Internal Helper Functions - Evolution Management
// ============================================================================

// Get the level required to evolve INTO this species (from its pre-evolution)
static u8 GetEvolutionLevelForSpecies(u16 species)
{
    u32 i, j;

    // Find what evolves into this species
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (!IsSpeciesEnabled(i))
            continue;

        const struct Evolution *evolutions = GetSpeciesEvolutions(i);
        if (evolutions == NULL)
            continue;

        for (j = 0; evolutions[j].method != EVOLUTIONS_END; j++)
        {
            if (evolutions[j].targetSpecies == species)
            {
                // Check if this is a level-based evolution
                if (evolutions[j].method == EVO_LEVEL || evolutions[j].method == EVO_LEVEL_BATTLE_ONLY)
                {
                    return evolutions[j].param;
                }
            }
        }
    }

    return 0; // No level-based evolution found
}

static bool8 IsSpeciesLegalAtLevel(u16 species, u8 level)
{
    u8 requiredLevel;
    #if B_SCALING_USE_OVERRIDES
    const struct EvolutionOverride *override;

    // Check evolution overrides first
    override = GetEvolutionOverride(species);
    if (override != NULL)
    {
        return level >= override->minimumLevel;
    }
    #endif

    // Check if this species is an evolved form
    u16 preEvo = GetSpeciesPreEvolution(species);
    if (preEvo == SPECIES_NONE)
    {
        // This is a base form, always legal
        return TRUE;
    }

    // This is an evolved form - check the level required to evolve into it
    requiredLevel = GetEvolutionLevelForSpecies(species);
    if (requiredLevel > 0 && level < requiredLevel)
    {
        // Level is too low for this evolution
        return FALSE;
    }

    // Recursively check if the pre-evolution is legal at this level
    // (handles multi-stage evolutions like Fuecoco -> Crocalor -> Skeledirge)
    return IsSpeciesLegalAtLevel(preEvo, level);
}

// ============================================================================
// Public API Functions
// ============================================================================

const struct EvolutionOverride *GetEvolutionOverride(u16 species)
{
    u32 i;

    for (i = 0; gEvolutionOverrides[i].species != SPECIES_NONE; i++)
    {
        if (gEvolutionOverrides[i].species == species)
            return &gEvolutionOverrides[i];
    }

    return NULL;
}

u16 ValidateSpeciesForLevel(u16 species, u8 targetLevel, bool8 manageEvolutions)
{
    if (!manageEvolutions)
        return species;

    // Check if current species is legal at this level
    if (IsSpeciesLegalAtLevel(species, targetLevel))
        return species;

    // Need to devolve - find pre-evolution
    u16 currentSpecies = species;
    u16 preEvo;
    u32 maxIterations = 10; // Prevent infinite loops

    while (maxIterations-- > 0)
    {
        preEvo = GetSpeciesPreEvolution(currentSpecies);

        if (preEvo == SPECIES_NONE)
        {
            // No pre-evolution found, use current species
            break;
        }

        currentSpecies = preEvo;

        // Check if this pre-evolution is legal
        if (IsSpeciesLegalAtLevel(currentSpecies, targetLevel))
            return currentSpecies;
    }

    // If we couldn't find a legal evolution, return the furthest devolved form
    return currentSpecies;
}

void InvalidatePartyLevelCache(void)
{
    sPartyLevelCache.cached = FALSE;
}

u8 CalculatePlayerPartyBaseLevel(u8 mode, bool8 excludeFainted)
{
    u8 baseLevel = 1;

    // Use cache if available
    if (sPartyLevelCache.cached)
    {
        switch (mode)
        {
            case LEVEL_SCALING_PARTY_AVG:
                return sPartyLevelCache.partyAverage;
            case LEVEL_SCALING_PARTY_HIGHEST:
                return sPartyLevelCache.partyHighest;
            case LEVEL_SCALING_PARTY_LOWEST:
                return sPartyLevelCache.partyLowest;
        }
    }

    // Calculate based on mode
    switch (mode)
    {
        case LEVEL_SCALING_NONE:
            return 0; // Signal to use original level

        case LEVEL_SCALING_TO_LEVEL_CAP:
            baseLevel = GetCurrentLevelCap();
            break;

        case LEVEL_SCALING_PARTY_AVG:
            baseLevel = GetPlayerPartyAverageLevel(excludeFainted);
            sPartyLevelCache.partyAverage = baseLevel;
            break;

        case LEVEL_SCALING_PARTY_HIGHEST:
            baseLevel = GetPlayerPartyHighestLevel(excludeFainted);
            sPartyLevelCache.partyHighest = baseLevel;
            break;

        case LEVEL_SCALING_PARTY_LOWEST:
            baseLevel = GetPlayerPartyLowestLevel(excludeFainted);
            sPartyLevelCache.partyLowest = baseLevel;
            break;

        default:
            baseLevel = 1;
            break;
    }

    // Mark cache as valid after first calculation
    sPartyLevelCache.cached = TRUE;

    return baseLevel;
}

const struct LevelScalingConfig *GetTrainerLevelScalingConfig(u16 trainerId)
{
    // Default configuration from config file
    static const struct LevelScalingConfig sDefaultConfig = {
        .mode = B_TRAINER_SCALING_DEFAULT_MODE,
        .levelAugmentAdd = B_TRAINER_SCALING_LEVEL_AUGMENT,
        .levelVariationPct = B_TRAINER_SCALING_LEVEL_VARIATION_PCT,
        .minLevel = B_TRAINER_SCALING_MIN_LEVEL,
        .maxLevel = B_TRAINER_SCALING_MAX_LEVEL,
        .manageEvolutions = B_TRAINER_SCALING_MANAGE_EVOLUTIONS,
        .excludeFainted = B_TRAINER_SCALING_EXCLUDE_FAINTED,
        .scaleEVs = B_TRAINER_SCALING_SCALE_EVS,
        .scaleMoves = B_TRAINER_SCALING_SCALE_MOVES,
        .scaleItems = B_TRAINER_SCALING_SCALE_ITEMS,
        .partySizeMode = B_TRAINER_PARTY_SIZE_MODE,
        .partySizeSort = B_TRAINER_PARTY_SIZE_SORT,
    };

    // Check bounds
    if (trainerId >= ARRAY_COUNT(gTrainerLevelScalingRules))
        return &sDefaultConfig;

    // Get config from rules array
    const struct LevelScalingConfig *config = &gTrainerLevelScalingRules[trainerId];

    // If mode is 0 (LEVEL_SCALING_NONE), check if this is:
    // 1. An explicit opt-out (trainer has config with mode = NONE), OR
    // 2. An undefined entry (zero-initialized)
    //
    // We distinguish by checking if ANY field is non-zero
    // If all fields are zero, it's undefined and we use default
    // If mode is NONE but other fields are set, it's an explicit opt-out
    if (config->mode == LEVEL_SCALING_NONE)
    {
        // Check if any other field is non-zero (indicates explicit config)
        if (config->levelAugmentAdd == 0 &&
            config->levelVariationPct == 0 &&
            config->minLevel == 0 &&
            config->maxLevel == 0 &&
            config->manageEvolutions == FALSE &&
            config->excludeFainted == FALSE &&
            config->scaleEVs == FALSE &&
            config->scaleMoves == FALSE &&
            config->scaleItems == FALSE &&
            config->partySizeMode == PARTY_SIZE_SCALING_INHERIT &&
            config->partySizeSort == PARTY_SIZE_SORT_INHERIT)
        {
            // All fields zero = undefined entry, use default
            return &sDefaultConfig;
        }
        // else: Explicit NONE config, return it
    }

    return config;
}

u8 CalculateScaledLevel(const struct LevelScalingConfig *config, u8 originalLevel)
{
    u8 baseLevel;
    s16 adjustedLevel;

    // Get base level from scaling mode
    baseLevel = CalculatePlayerPartyBaseLevel(config->mode, config->excludeFainted);

    // If mode is NONE, return original
    if (baseLevel == 0)
        return originalLevel;

    // Apply augmentation (can be positive or negative)
    adjustedLevel = (s16)baseLevel + (s16)config->levelAugmentAdd;

    // Ensure we don't go negative
    if (adjustedLevel < 1)
        adjustedLevel = 1;

    // Apply random variation
    adjustedLevel = ApplyLevelVariation((u8)adjustedLevel, config->levelVariationPct);

    // Clamp to configured min/max
    adjustedLevel = ClampLevel((u8)adjustedLevel, config->minLevel, config->maxLevel);

    if (B_SCALING_DEBUG_PRINT)
    {
        // Debug output would go here
    }

    return (u8)adjustedLevel;
}

u8 CalculateWildScaledLevel(u16 species, u8 originalLevel)
{
    #if B_WILD_SCALING_ENABLED
    static const struct LevelScalingConfig sWildConfig = {
        .mode = B_WILD_SCALING_DEFAULT_MODE,
        .levelAugmentAdd = B_WILD_SCALING_LEVEL_AUGMENT,
        .levelVariationPct = B_WILD_SCALING_LEVEL_VARIATION_PCT,
        .minLevel = B_WILD_SCALING_MIN_LEVEL,
        .maxLevel = B_WILD_SCALING_MAX_LEVEL,
        .manageEvolutions = B_WILD_SCALING_MANAGE_EVOLUTIONS,
        .excludeFainted = B_WILD_SCALING_EXCLUDE_FAINTED,
        .scaleEVs = FALSE,
        .scaleMoves = FALSE,
        .scaleItems = FALSE,
        .partySizeMode = PARTY_SIZE_SCALING_NONE,
        .partySizeSort = PARTY_SIZE_SORT_NONE,
    };

    u8 newLevel = CalculateScaledLevel(&sWildConfig, originalLevel);

    // Note: Species validation should happen in wild encounter code
    // as we can't modify the species from this function

    return newLevel;
    #else
    return originalLevel;
    #endif
}

// Calculate scaled species for wild encounters (called from wild_encounter.c)
u16 CalculateWildScaledSpecies(u16 species, u8 scaledLevel)
{
    #if B_WILD_SCALING_ENABLED && B_WILD_SCALING_MANAGE_EVOLUTIONS
    return ValidateSpeciesForLevel(species, scaledLevel, TRUE);
    #else
    return species;
    #endif
}

// Proportional EV scaling: budget = min(level * 10, 510). If defined EVs total <= budget, leave as-is.
// Otherwise scale each stat by budget/baseTotal. Truncation residual is dropped (negligible).
bool32 TryApplyScaledTrainerEVs(struct Pokemon *mon, const u8 *baseEVs, u16 trainerId, u8 scaledLevel)
{
    const struct LevelScalingConfig *config = GetTrainerLevelScalingConfig(trainerId);
    if (config->mode == LEVEL_SCALING_NONE || !config->scaleEVs)
        return FALSE;

    u32 baseTotal = 0;
    u32 i;
    for (i = 0; i < 6; i++)
        baseTotal += baseEVs[i];

    u32 budget = (u32)scaledLevel * 10;
    if (budget > 510)
        budget = 510;

    u8 out[6];
    if (baseTotal == 0 || baseTotal <= budget)
    {
        for (i = 0; i < 6; i++)
            out[i] = baseEVs[i];
    }
    else
    {
        for (i = 0; i < 6; i++)
            out[i] = (u8)(((u32)baseEVs[i] * budget) / baseTotal);
    }

    SetMonData(mon, MON_DATA_HP_EV,    &out[0]);
    SetMonData(mon, MON_DATA_ATK_EV,   &out[1]);
    SetMonData(mon, MON_DATA_DEF_EV,   &out[2]);
    SetMonData(mon, MON_DATA_SPATK_EV, &out[3]);
    SetMonData(mon, MON_DATA_SPDEF_EV, &out[4]);
    SetMonData(mon, MON_DATA_SPEED_EV, &out[5]);
    return TRUE;
}

// ============================================================================
// Move progression gate (Problem 2C — tier-bucket predicate)
// ============================================================================

bool32 IsMovePermittedAtLevel(u16 move, u8 level)
{
    if (move == MOVE_NONE || move >= MOVES_COUNT)
        return TRUE;

    u8 tier = gMoveProgressionTier[move];
    switch (tier)
    {
        case MOVE_TIER_MID:     return level >= B_SCALING_TIER_MID_MIN_LEVEL;
        case MOVE_TIER_LATE:    return level >= B_SCALING_TIER_LATE_MIN_LEVEL;
        case MOVE_TIER_ENDGAME: return level >= B_SCALING_TIER_ENDGAME_MIN_LEVEL;
        case MOVE_TIER_DEFAULT:
        default:                return TRUE;
    }
}

// ============================================================================
// Move filter + level-up topup (Problem 1B)
// ============================================================================

// TRUE if `move` is in the species' level-up learnset at level <= maxLevel.
static bool32 IsMoveInLevelUpLearnset(u16 species, u16 move, u8 maxLevel)
{
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    u32 i;
    for (i = 0; i < MAX_LEVEL_UP_MOVES && learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        if (learnset[i].level > maxLevel)
            break;
        if (learnset[i].move == move)
            return TRUE;
    }
    return FALSE;
}

// Pick the next level-up move for `species` at <= maxLevel that is not already in `existing`.
// Walks the learnset highest→lowest level so the strongest available natural move is preferred.
static u16 PickNextLevelUpMove(u16 species, u8 maxLevel, const u16 *existing, u32 existingCount)
{
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    s32 lastIdx = -1;
    s32 i;

    for (i = 0; i < MAX_LEVEL_UP_MOVES && learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        if (learnset[i].level <= maxLevel)
            lastIdx = i;
        else
            break;
    }

    for (i = lastIdx; i >= 0; i--)
    {
        u16 candidate = learnset[i].move;
        u32 j;
        bool32 dupe = FALSE;
        for (j = 0; j < existingCount; j++)
        {
            if (existing[j] == candidate)
            {
                dupe = TRUE;
                break;
            }
        }
        if (!dupe)
            return candidate;
    }
    return MOVE_NONE;
}

void MaybeFilterTrainerMoves(struct Pokemon *mon, u16 trainerId, u16 scaledSpecies, u8 scaledLevel)
{
    const struct LevelScalingConfig *config = GetTrainerLevelScalingConfig(trainerId);
    if (config->mode == LEVEL_SCALING_NONE || !config->scaleMoves)
        return;

    u16 finalMoves[MAX_MON_MOVES] = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_NONE};
    u32 outCount = 0;
    u32 j;

    // Pass 1: keep legal moves, drop the rest
    for (j = 0; j < MAX_MON_MOVES; j++)
    {
        u16 move = GetMonData(mon, MON_DATA_MOVE1 + j, NULL);
        if (move == MOVE_NONE)
            continue;
        if (IsMoveInLevelUpLearnset(scaledSpecies, move, scaledLevel)
            || IsMovePermittedAtLevel(move, scaledLevel))
        {
            finalMoves[outCount++] = move;
        }
    }

    // Pass 2: top up empty slots from level-up learnset
    while (outCount < MAX_MON_MOVES)
    {
        u16 fill = PickNextLevelUpMove(scaledSpecies, scaledLevel, finalMoves, outCount);
        if (fill == MOVE_NONE)
            break;
        finalMoves[outCount++] = fill;
    }

    // Write back
    for (j = 0; j < MAX_MON_MOVES; j++)
    {
        u16 move = finalMoves[j];
        u32 pp = (move != MOVE_NONE) ? GetMovePP(move) : 0;
        SetMonData(mon, MON_DATA_MOVE1 + j, &move);
        SetMonData(mon, MON_DATA_PP1 + j, &pp);
    }
}

// ============================================================================
// Party-size scaling
// ============================================================================

u8 GetScaledTrainerPartySize(u16 trainerId, u8 originalPartySize)
{
    const struct LevelScalingConfig *config = GetTrainerLevelScalingConfig(trainerId);

    if (config->mode == LEVEL_SCALING_NONE || originalPartySize <= 1)
        return originalPartySize;

    // Resolve INHERIT to the global default mode
    u8 mode = config->partySizeMode;
    if (mode == PARTY_SIZE_SCALING_INHERIT)
        mode = B_TRAINER_PARTY_SIZE_MODE;

    u8 cap;
    switch (mode)
    {
        case PARTY_SIZE_SCALING_BY_PLAYER_SIZE:
            cap = GetPlayerPartySize(config->excludeFainted);
            break;
        case PARTY_SIZE_SCALING_BY_PLAYER_LEVEL:
        {
            u8 avgLevel = GetPlayerPartyAverageLevel(config->excludeFainted);
            u32 i;
            cap = originalPartySize;
            for (i = 0; i < ARRAY_COUNT(gPartySizeScalingTiers); i++)
            {
                if (avgLevel <= gPartySizeScalingTiers[i].maxAvgLevel)
                {
                    cap = gPartySizeScalingTiers[i].maxPartySize;
                    break;
                }
            }
            break;
        }
        case PARTY_SIZE_SCALING_NONE:
        default:
            return originalPartySize;
    }

    if (cap < 1)
        cap = 1;
    if (cap > originalPartySize)
        cap = originalPartySize;

    return cap;
}

static u8 ResolvePartySizeSort(u16 trainerId)
{
    const struct LevelScalingConfig *config = GetTrainerLevelScalingConfig(trainerId);
    u8 sort = config->partySizeSort;
    if (sort == PARTY_SIZE_SORT_INHERIT)
        sort = B_TRAINER_PARTY_SIZE_SORT;
    return sort;
}

static u32 GetSpeciesBST(u16 species)
{
    u32 total = 0;
    u32 i;
    for (i = 0; i < NUM_STATS; i++)
        total += GetSpeciesBaseStat(species, i);
    return total;
}

// BST ceiling for a scaled level, per the shared tier-threshold bands.
static u32 GetMaxBstForLevel(u8 level)
{
    if (level < B_SCALING_TIER_MID_MIN_LEVEL)
        return B_SCALING_BST_BELOW_MID;
    if (level < B_SCALING_TIER_LATE_MIN_LEVEL)
        return B_SCALING_BST_MID;
    if (level < B_SCALING_TIER_ENDGAME_MIN_LEVEL)
        return B_SCALING_BST_LATE;
    return B_SCALING_BST_ABOVE_ENDGAME;
}

// Swap entry a/b across the three parallel arrays so they stay aligned.
static void SwapPartyEntries(u32 *mi, u8 *lv, u16 *sp, u32 a, u32 b)
{
    u32 ti = mi[a]; mi[a] = mi[b]; mi[b] = ti;
    u8  tl = lv[a]; lv[a] = lv[b]; lv[b] = tl;
    u16 ts = sp[a]; sp[a] = sp[b]; sp[b] = ts;
}

u8 SelectScaledTrainerParty(const struct Trainer *trainer, u16 trainerId,
                            u32 *monIndices, u8 *scaledLevels, u16 *scaledSpecies, u8 fullCount)
{
    if (fullCount == 0)
        return 0;

    u32 keptMi[PARTY_SIZE];
    u8  keptLv[PARTY_SIZE];
    u16 keptSp[PARTY_SIZE];
    bool8 keptAce[PARTY_SIZE];
    u8 kept = 0;
    u32 lowestBst = 0xFFFFFFFF;
    u8 lowestIdx = 0;
    u32 i;

    // BST filter: keep ace mons according to config, others only if their scaled
    // BST is within the level's tier ceiling. Track the single lowest-BST mon
    // as a floor so the trainer never fields an empty team.
    for (i = 0; i < fullCount; i++)
    {
        u32 bst = GetSpeciesBST(scaledSpecies[i]);
        bool32 isAce = B_TRAINER_PARTY_ACE_EXEMPT
                    && (trainer->party[monIndices[i]].tags & MON_POOL_TAG_ACE) != 0;

        if (bst < lowestBst)
        {
            lowestBst = bst;
            lowestIdx = i;
        }
        if (isAce || bst <= GetMaxBstForLevel(scaledLevels[i]))
        {
            keptMi[kept] = monIndices[i];
            keptLv[kept] = scaledLevels[i];
            keptSp[kept] = scaledSpecies[i];
            keptAce[kept] = isAce;
            kept++;
        }
    }

    if (kept == 0)
    {
        monIndices[0] = monIndices[lowestIdx];
        scaledLevels[0] = scaledLevels[lowestIdx];
        scaledSpecies[0] = scaledSpecies[lowestIdx];
        return 1;
    }

    // Reassemble: ace mons first (kept order), then the rest (kept order).
    u32 oMi[PARTY_SIZE];
    u8  oLv[PARTY_SIZE];
    u16 oSp[PARTY_SIZE];
    u8 o = 0, aceCount = 0;

    for (i = 0; i < kept; i++)
    {
        if (keptAce[i])
        {
            oMi[o] = keptMi[i]; oLv[o] = keptLv[i]; oSp[o] = keptSp[i];
            o++; aceCount++;
        }
    }
    for (i = 0; i < kept; i++)
    {
        if (!keptAce[i])
        {
            oMi[o] = keptMi[i]; oLv[o] = keptLv[i]; oSp[o] = keptSp[i];
            o++;
        }
    }

    u8 cap = GetScaledTrainerPartySize(trainerId, kept);
    if (cap < aceCount)
        cap = aceCount;     // never drop an ace to satisfy the cap
    if (cap > kept)
        cap = kept;

    // Order the non-ace remainder per the sort mode before truncating.
    if (cap < kept)
    {
        u32 n = kept - aceCount;
        u32 *mi = oMi + aceCount;
        u8  *lv = oLv + aceCount;
        u16 *sp = oSp + aceCount;
        u8 sort = ResolvePartySizeSort(trainerId);

        if (sort == PARTY_SIZE_SORT_RANDOM)
        {
            s32 k;
            for (k = (s32)n - 1; k > 0; k--)
            {
                u32 j = Random() % (k + 1);
                SwapPartyEntries(mi, lv, sp, k, j);
            }
        }
        else if (sort == PARTY_SIZE_SORT_KEEP_HIGHEST_BST || sort == PARTY_SIZE_SORT_KEEP_LOWEST_BST)
        {
            // Selection sort (n <= 6). HIGHEST puts biggest-BST first (drop the
            // lowest); LOWEST puts smallest first (drop the highest).
            bool32 highestFirst = (sort == PARTY_SIZE_SORT_KEEP_HIGHEST_BST);
            u32 a, b;
            for (a = 0; a + 1 < n; a++)
            {
                u32 best = a;
                u32 bestBst = GetSpeciesBST(sp[a]);
                for (b = a + 1; b < n; b++)
                {
                    u32 v = GetSpeciesBST(sp[b]);
                    if ((highestFirst && v > bestBst) || (!highestFirst && v < bestBst))
                    {
                        best = b;
                        bestBst = v;
                    }
                }
                if (best != a)
                    SwapPartyEntries(mi, lv, sp, a, best);
            }
        }
        // PARTY_SIZE_SORT_NONE: keep order, drop the tail.
    }

    for (i = 0; i < cap; i++)
    {
        monIndices[i] = oMi[i];
        scaledLevels[i] = oLv[i];
        scaledSpecies[i] = oSp[i];
    }
    return cap;
}

// ============================================================================
// Held item progression gate
// ============================================================================

bool32 IsItemPermittedAtLevel(u16 item, u8 level)
{
    if (item == ITEM_NONE || item >= ITEMS_COUNT)
        return TRUE;

    u8 tier = gItemProgressionTier[item];
    switch (tier)
    {
        case ITEM_TIER_MID:     return level >= B_SCALING_TIER_MID_MIN_LEVEL;
        case ITEM_TIER_LATE:    return level >= B_SCALING_TIER_LATE_MIN_LEVEL;
        case ITEM_TIER_ENDGAME: return level >= B_SCALING_TIER_ENDGAME_MIN_LEVEL;
        case ITEM_TIER_DEFAULT:
        default:                return TRUE;
    }
}

void MaybeStripTrainerItem(struct Pokemon *mon, u16 trainerId, u8 scaledLevel)
{
    const struct LevelScalingConfig *config = GetTrainerLevelScalingConfig(trainerId);
    if (config->mode == LEVEL_SCALING_NONE || !config->scaleItems)
        return;

    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    if (!IsItemPermittedAtLevel(item, scaledLevel))
    {
        u16 none = ITEM_NONE;
        SetMonData(mon, MON_DATA_HELD_ITEM, &none);
    }
}

#endif // B_LEVEL_SCALING_ENABLED
