#include "global.h"
#include "mf_rules.h"
#include "mf_nuzlocke.h"
#include "mf_random.h"
#include "gba/isagbprint.h"

// Null / compile-out defaults: vanilla Kanto progression + Phase 1 always-on
// modernization (phys/spec+Fairy+modern types/stats/moves/chart, reusable TMs,
// Gen4+ Sitrus, Gen5+ OW poison). Challenges / randomizer / Nuzlocke stay off.
// See ADR 0013 and docs-mf/RULES_ACCESSORS.md.
const struct ModernRules gMfRulesPhase1Defaults = {
    .version = MF_RULES_VERSION,
    .gamemodePreset = MF_GAMEMODE_MODERN,
    .rulesLocked = FALSE,

    .infiniteTms = TRUE,
    .survivePoison = TRUE,
    // Match GEN_LATEST compile baselines (S07/S11) so null / engine-off keeps
    // Gen8 Synchronize and Gen5+ Sturdy until a save picks Classic.
    .synchronize = TRUE,
    .mints = FALSE,
    .modernSitrus = TRUE,
    .modernTypes = TRUE,
    .fairyTypes = TRUE,
    .modernStats = TRUE,
    .sturdy = TRUE,
    .modernMoves = TRUE,
    .legendaryAbilities = FALSE,
    .newLegendaries = FALSE,
    .typeEffectiveness = TRUE,
    .alternateSpawns = 0,

    .shinyChance = 0,
    .wildItemDrops = FALSE,
    .easierFeebas = FALSE,
    .rtcType = FALSE,
    .shinyColors = FALSE,
    .wonderTrade = FALSE,
    .unlimitedWonderTrade = FALSE,
    .frontierBans = FALSE,

    .randomStarter = FALSE,
    .randomWild = FALSE,
    .randomTrainer = FALSE,
    .randomStatic = FALSE,
    .randomSimilar = FALSE,
    .randomMapBased = FALSE,
    .randomIncludeLegendaries = FALSE,
    .randomType = FALSE,
    .randomMoves = FALSE,
    .randomAbilities = FALSE,
    .randomEvolution = FALSE,
    .randomEvolutionMethods = FALSE,
    .randomTypeEffectiveness = FALSE,
    .randomItems = FALSE,
    .randomChaos = FALSE,
    .randomizerEnabled = FALSE,

    .nuzlocke = FALSE,
    .nuzlockeHardcore = FALSE,
    .nuzlockeEasy = FALSE,
    .nuzlockeSpeciesClause = FALSE,
    .nuzlockeShinyClause = FALSE,
    .nuzlockeNicknaming = FALSE,
    .nuzlockeDeletion = FALSE,

    .partyLimit = 0,
    .levelCap = 0,
    .expMultiplier = 0,
    .noItemPlayer = FALSE,
    .noItemTrainer = FALSE,
    .noEvs = FALSE,
    .scalingIvs = 0,
    .scalingEvs = 0,
    .maxPartyIvs = 0,
    .pokeCenterLimit = 0,
    .lockDifficulty = FALSE,
    .escapeRopeDig = FALSE,
    .hardExp = FALSE,
    .scaledExp = FALSE,
    .catchRate = 0,

    .evoLimit = 0,
    .baseStatEqualizer = 0,
    .lessEscapes = FALSE,
    .mirror = FALSE,
    .mirrorThief = FALSE,
    .noPcHeal = FALSE,
    .monotype = 31,
    .expensiveShops = 0,

    .randomizerSeed = 0,
};

void MfRules_ResetToEmpty(struct ModernRules *rules)
{
    if (rules == NULL)
        return;

    memset(rules, 0, sizeof(*rules));
    rules->version = MF_RULES_VERSION;
    rules->monotype = 31; // ME TX_CHALLENGE_TYPE_OFF
}

// Fill from MF_TX_* compile defaults (ME TX_* block). Gamemode fields are the
// Custom seed; Classic/Modern overwrite them via MfRules_ApplyGamemodePreset.
void MfRules_ApplyDevDefaults(struct ModernRules *rules)
{
    if (rules == NULL)
        return;

    memset(rules, 0, sizeof(*rules));

    rules->version = MF_RULES_VERSION;
    rules->rulesLocked = FALSE;

    rules->infiniteTms = MF_TX_MODE_INFINITE_TMS;
    rules->survivePoison = MF_TX_MODE_SURVIVE_POISON;
    rules->synchronize = MF_TX_MODE_SYNCHRONIZE;
    rules->mints = MF_TX_MODE_MINTS;
    rules->modernSitrus = MF_TX_MODE_NEW_CITRUS;
    rules->modernTypes = MF_TX_MODE_MODERN_TYPES;
    rules->fairyTypes = MF_TX_MODE_FAIRY_TYPES;
    rules->modernStats = MF_TX_MODE_NEW_STATS;
    rules->sturdy = MF_TX_MODE_STURDY;
    rules->modernMoves = MF_TX_MODE_MODERN_MOVES;
    rules->legendaryAbilities = MF_TX_MODE_LEGENDARY_ABILITIES;
    rules->newLegendaries = MF_TX_MODE_NEW_LEGENDARIES;
    rules->typeEffectiveness = MF_TX_MODE_TYPE_EFFECTIVENESS;
    rules->alternateSpawns = MF_TX_MODE_ALTERNATE_SPAWNS;

    rules->shinyChance = MF_TX_FEATURES_SHINY_CHANCE;
    rules->wildItemDrops = MF_TX_FEATURES_ITEM_DROP;
    rules->easierFeebas = MF_TX_FEATURES_EASIER_FEEBAS;
    rules->rtcType = MF_TX_FEATURES_RTC_TYPE;
    rules->shinyColors = MF_TX_FEATURES_SHINY_COLORS;
    rules->wonderTrade = MF_TX_FEATURES_WONDER_TRADE;
    rules->unlimitedWonderTrade = MF_TX_FEATURES_UNLIMITED_WT;
    rules->frontierBans = MF_TX_FEATURES_FRONTIER_BANS;

    rules->randomStarter = MF_TX_RANDOM_STARTER;
    rules->randomWild = MF_TX_RANDOM_WILD;
    rules->randomTrainer = MF_TX_RANDOM_TRAINER;
    rules->randomStatic = MF_TX_RANDOM_STATIC;
    // Similar/MapBased TX defaults seed when the S25 master turns on — keep them
    // off while the randomizer is disabled so map-based RNG keys stay inert.
    rules->randomSimilar = FALSE;
    rules->randomMapBased = FALSE;
    rules->randomIncludeLegendaries = MF_TX_RANDOM_INCLUDE_LEGENDARIES;
    rules->randomType = MF_TX_RANDOM_TYPE;
    rules->randomMoves = MF_TX_RANDOM_MOVES;
    rules->randomAbilities = MF_TX_RANDOM_ABILITIES;
    rules->randomEvolution = MF_TX_RANDOM_EVOLUTION;
    rules->randomEvolutionMethods = MF_TX_RANDOM_EVOLUTION_METHODS;
    rules->randomTypeEffectiveness = MF_TX_RANDOM_TYPE_EFFECTIVENESS;
    rules->randomItems = MF_TX_RANDOM_ITEMS;
    rules->randomChaos = MF_TX_RANDOM_CHAOS;
    rules->randomizerEnabled = FALSE;

    rules->nuzlocke = MF_TX_NUZLOCKE;
    rules->nuzlockeHardcore = MF_TX_NUZLOCKE_HARDCORE;
    rules->nuzlockeEasy = MF_TX_NUZLOCKE_EASY;
    rules->nuzlockeSpeciesClause = MF_TX_NUZLOCKE_SPECIES_CLAUSE;
    rules->nuzlockeShinyClause = MF_TX_NUZLOCKE_SHINY_CLAUSE;
    rules->nuzlockeNicknaming = MF_TX_NUZLOCKE_NICKNAMING;
    rules->nuzlockeDeletion = MF_TX_NUZLOCKE_DELETION;

    rules->partyLimit = MF_TX_DIFFICULTY_PARTY_LIMIT;
    rules->levelCap = MF_TX_DIFFICULTY_LEVEL_CAP;
    rules->expMultiplier = MF_TX_DIFFICULTY_EXP_MULTIPLIER;
    rules->noItemPlayer = MF_TX_DIFFICULTY_NO_ITEM_PLAYER;
    rules->noItemTrainer = MF_TX_DIFFICULTY_NO_ITEM_TRAINER;
    rules->noEvs = MF_TX_DIFFICULTY_NO_EVS;
    rules->scalingIvs = MF_TX_DIFFICULTY_SCALING_IVS;
    rules->scalingEvs = MF_TX_DIFFICULTY_SCALING_EVS;
    rules->maxPartyIvs = MF_TX_DIFFICULTY_MAX_PARTY_IVS;
    rules->pokeCenterLimit = MF_TX_DIFFICULTY_POKECENTER;
    rules->lockDifficulty = MF_TX_DIFFICULTY_LOCK_DIFFICULTY;
    rules->escapeRopeDig = MF_TX_DIFFICULTY_ESCAPE_ROPE_DIG;
    rules->hardExp = MF_TX_DIFFICULTY_HARD_EXP;
    rules->scaledExp = MF_TX_DIFFICULTY_SCALED_EXP;
    rules->catchRate = MF_TX_DIFFICULTY_CATCH_RATE;

    rules->evoLimit = MF_TX_CHALLENGE_EVO_LIMIT;
    rules->baseStatEqualizer = MF_TX_CHALLENGE_BASE_STAT_EQUALIZER;
    rules->lessEscapes = MF_TX_CHALLENGE_LESS_ESCAPES;
    rules->mirror = MF_TX_CHALLENGE_MIRROR;
    rules->mirrorThief = MF_TX_CHALLENGE_MIRROR_THIEF;
    rules->noPcHeal = MF_TX_CHALLENGE_NO_PC_HEAL;
    rules->monotype = MF_TX_CHALLENGE_TYPE;
    rules->expensiveShops = MF_TX_CHALLENGE_EXPENSIVE_SHOPS;

    rules->randomizerSeed = 0;
}

// Classic / Modern force Gamemode-page fields (ME DrawChoices_Mode_*).
// Custom leaves those fields alone (dev defaults or prior menu edits).
// newLegendaries stays FALSE in every preset — FR has no extra legendary maps
// (PROJECT.md / ADR 0014).
void MfRules_ApplyGamemodePreset(struct ModernRules *rules, enum MfGamemodePreset preset)
{
    if (rules == NULL)
        return;

    rules->gamemodePreset = preset;

    if (preset == MF_GAMEMODE_CLASSIC)
    {
        rules->alternateSpawns = 0;
        rules->infiniteTms = FALSE;
        rules->survivePoison = FALSE;
        rules->synchronize = FALSE;
        rules->mints = FALSE;
        rules->modernSitrus = FALSE;
        rules->modernTypes = FALSE;
        rules->fairyTypes = FALSE;
        rules->modernStats = FALSE;
        rules->sturdy = FALSE;
        rules->modernMoves = FALSE;
        rules->legendaryAbilities = FALSE;
        rules->newLegendaries = FALSE;
        rules->typeEffectiveness = FALSE;
    }
    else if (preset == MF_GAMEMODE_MODERN)
    {
        rules->alternateSpawns = 1;
        rules->infiniteTms = TRUE;
        rules->survivePoison = TRUE;
        rules->synchronize = TRUE;
        rules->mints = TRUE;
        rules->modernSitrus = TRUE;
        rules->modernTypes = TRUE;
        rules->fairyTypes = TRUE;
        rules->modernStats = TRUE;
        rules->sturdy = TRUE;
        rules->modernMoves = TRUE;
        rules->legendaryAbilities = TRUE;
        rules->newLegendaries = FALSE; // FR: no new maps (ME sets TRUE)
        rules->typeEffectiveness = TRUE;
    }
    // MF_GAMEMODE_CUSTOM: keep current gamemode fields
}

void MfRules_InitNewGame(void)
{
#if MF_RULES_ENGINE
    struct ModernRules *rules = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(rules);
    MfRules_ApplyGamemodePreset(rules, (enum MfGamemodePreset)MF_DEFAULT_GAMEMODE_PRESET);
    // Per-save randomizer seed (S16); must land before any seeded remap (S51+).
    MfRandom_EnsureSeed(rules);
    // Leave unlocked so the S19 new-game menu (and S20–S25 pages) can edit.
    // S26 SAVE calls MfRules_CommitAndLock().
#endif
}

void MfRules_Pack(const struct ModernRules *rules, u8 *out)
{
    if (rules == NULL || out == NULL)
        return;

    memcpy(out, rules, sizeof(struct ModernRules));
}

void MfRules_Unpack(const u8 *in, struct ModernRules *rules)
{
    if (in == NULL || rules == NULL)
        return;

    memcpy(rules, in, sizeof(struct ModernRules));
}

struct ModernRules *MfRules_GetSaveRules(void)
{
    return &gSaveBlock3Ptr->mfRules;
}

const struct ModernRules *MfRules_GetActiveRules(void)
{
#if !MF_RULES_ENGINE
    return &gMfRulesPhase1Defaults;
#else
    {
        const struct ModernRules *rules = MfRules_GetSaveRules();

        if (rules->version != MF_RULES_VERSION)
            return &gMfRulesPhase1Defaults;
        return rules;
    }
#endif
}

bool8 MfRules_GetBool(enum MfRuleBool id)
{
    const struct ModernRules *r = MfRules_GetActiveRules();

    switch (id)
    {
    case MF_RULE_BOOL_RULES_LOCKED:               return r->rulesLocked;
    case MF_RULE_BOOL_INFINITE_TMS:               return r->infiniteTms;
    case MF_RULE_BOOL_SURVIVE_POISON:             return r->survivePoison;
    case MF_RULE_BOOL_SYNCHRONIZE:                return r->synchronize;
    case MF_RULE_BOOL_MINTS:                      return r->mints;
    case MF_RULE_BOOL_MODERN_SITRUS:              return r->modernSitrus;
    case MF_RULE_BOOL_MODERN_TYPES:               return r->modernTypes;
    case MF_RULE_BOOL_FAIRY_TYPES:                return r->fairyTypes;
    case MF_RULE_BOOL_MODERN_STATS:               return r->modernStats;
    case MF_RULE_BOOL_STURDY:                     return r->sturdy;
    case MF_RULE_BOOL_MODERN_MOVES:               return r->modernMoves;
    case MF_RULE_BOOL_LEGENDARY_ABILITIES:        return r->legendaryAbilities;
    case MF_RULE_BOOL_NEW_LEGENDARIES:            return r->newLegendaries;
    case MF_RULE_BOOL_TYPE_EFFECTIVENESS:         return r->typeEffectiveness;
    case MF_RULE_BOOL_WILD_ITEM_DROPS:            return r->wildItemDrops;
    case MF_RULE_BOOL_EASIER_FEEBAS:              return r->easierFeebas;
    case MF_RULE_BOOL_RTC_TYPE:                   return r->rtcType;
    case MF_RULE_BOOL_SHINY_COLORS:               return r->shinyColors;
    case MF_RULE_BOOL_WONDER_TRADE:               return r->wonderTrade;
    case MF_RULE_BOOL_UNLIMITED_WONDER_TRADE:     return r->unlimitedWonderTrade;
    case MF_RULE_BOOL_FRONTIER_BANS:              return r->frontierBans;
    case MF_RULE_BOOL_RANDOMIZER_ENABLED:         return r->randomizerEnabled;
    case MF_RULE_BOOL_RANDOM_STARTER:             return r->randomStarter;
    case MF_RULE_BOOL_RANDOM_WILD:                return r->randomWild;
    case MF_RULE_BOOL_RANDOM_TRAINER:             return r->randomTrainer;
    case MF_RULE_BOOL_RANDOM_STATIC:              return r->randomStatic;
    case MF_RULE_BOOL_RANDOM_SIMILAR:             return r->randomSimilar;
    case MF_RULE_BOOL_RANDOM_MAP_BASED:           return r->randomMapBased;
    case MF_RULE_BOOL_RANDOM_INCLUDE_LEGENDARIES: return r->randomIncludeLegendaries;
    case MF_RULE_BOOL_RANDOM_TYPE:                return r->randomType;
    case MF_RULE_BOOL_RANDOM_MOVES:               return r->randomMoves;
    case MF_RULE_BOOL_RANDOM_ABILITIES:           return r->randomAbilities;
    case MF_RULE_BOOL_RANDOM_EVOLUTION:           return r->randomEvolution;
    case MF_RULE_BOOL_RANDOM_EVOLUTION_METHODS:   return r->randomEvolutionMethods;
    case MF_RULE_BOOL_RANDOM_TYPE_EFFECTIVENESS:  return r->randomTypeEffectiveness;
    case MF_RULE_BOOL_RANDOM_ITEMS:               return r->randomItems;
    case MF_RULE_BOOL_RANDOM_CHAOS:               return r->randomChaos;
    case MF_RULE_BOOL_NUZLOCKE:                   return r->nuzlocke;
    case MF_RULE_BOOL_NUZLOCKE_HARDCORE:          return r->nuzlockeHardcore;
    case MF_RULE_BOOL_NUZLOCKE_EASY:              return r->nuzlockeEasy;
    case MF_RULE_BOOL_NUZLOCKE_SPECIES_CLAUSE:    return r->nuzlockeSpeciesClause;
    case MF_RULE_BOOL_NUZLOCKE_SHINY_CLAUSE:      return r->nuzlockeShinyClause;
    case MF_RULE_BOOL_NUZLOCKE_NICKNAMING:        return r->nuzlockeNicknaming;
    case MF_RULE_BOOL_NUZLOCKE_DELETION:          return r->nuzlockeDeletion;
    case MF_RULE_BOOL_NO_ITEM_PLAYER:             return r->noItemPlayer;
    case MF_RULE_BOOL_NO_ITEM_TRAINER:            return r->noItemTrainer;
    case MF_RULE_BOOL_NO_EVS:                     return r->noEvs;
    case MF_RULE_BOOL_LOCK_DIFFICULTY:            return r->lockDifficulty;
    case MF_RULE_BOOL_ESCAPE_ROPE_DIG:            return r->escapeRopeDig;
    case MF_RULE_BOOL_HARD_EXP:                   return r->hardExp;
    case MF_RULE_BOOL_SCALED_EXP:                 return r->scaledExp;
    case MF_RULE_BOOL_LESS_ESCAPES:               return r->lessEscapes;
    case MF_RULE_BOOL_MIRROR:                     return r->mirror;
    case MF_RULE_BOOL_MIRROR_THIEF:               return r->mirrorThief;
    case MF_RULE_BOOL_NO_PC_HEAL:                 return r->noPcHeal;
    case MF_RULE_BOOL_COUNT:                      break;
    }
    return FALSE;
}

// S22 — Off/Easy/Normal/Hardcore from nuzlocke / easy / hardcore bits.
static u8 MfRules_PackNuzlockeMode(const struct ModernRules *r)
{
    if (r->nuzlocke)
        return r->nuzlockeHardcore ? MF_NUZLOCKE_HARDCORE : MF_NUZLOCKE_NORMAL;
    if (r->nuzlockeEasy)
        return MF_NUZLOCKE_EASY;
    return MF_NUZLOCKE_OFF;
}

u8 MfRules_GetValue(enum MfRuleValue id)
{
    const struct ModernRules *r = MfRules_GetActiveRules();

    switch (id)
    {
    case MF_RULE_VAL_GAMEMODE_PRESET:      return r->gamemodePreset;
    case MF_RULE_VAL_ALTERNATE_SPAWNS:     return r->alternateSpawns;
    case MF_RULE_VAL_SHINY_CHANCE:         return r->shinyChance;
    case MF_RULE_VAL_PARTY_LIMIT:          return r->partyLimit;
    case MF_RULE_VAL_LEVEL_CAP:            return r->levelCap;
    case MF_RULE_VAL_EXP_MULTIPLIER:       return r->expMultiplier;
    case MF_RULE_VAL_SCALING_IVS:          return r->scalingIvs;
    case MF_RULE_VAL_SCALING_EVS:          return r->scalingEvs;
    case MF_RULE_VAL_MAX_PARTY_IVS:        return r->maxPartyIvs;
    case MF_RULE_VAL_POKECENTER_LIMIT:     return r->pokeCenterLimit;
    case MF_RULE_VAL_CATCH_RATE:           return r->catchRate;
    case MF_RULE_VAL_EVO_LIMIT:            return r->evoLimit;
    case MF_RULE_VAL_BASE_STAT_EQUALIZER:  return r->baseStatEqualizer;
    case MF_RULE_VAL_MONOTYPE:             return r->monotype;
    case MF_RULE_VAL_EXPENSIVE_SHOPS:      return r->expensiveShops;
    case MF_RULE_VAL_NUZLOCKE_MODE:        return MfRules_PackNuzlockeMode(r);
    case MF_RULE_VAL_COUNT:                break;
    }
    return 0;
}

// --- S15 lock / writers -------------------------------------------------------

#ifndef NDEBUG
static bool8 sMfRulesDebugUnlockOverride;
#endif

void MfRules_CommitAndLock(void)
{
#if MF_RULES_ENGINE
    struct ModernRules *rules = MfRules_GetSaveRules();

    if (rules->version != MF_RULES_VERSION)
        return;

    MfRandom_EnsureSeed(rules);
    rules->rulesLocked = TRUE;
#endif
}

bool8 MfRules_DebugSetUnlockOverride(bool8 enable)
{
#ifdef NDEBUG
    (void)enable;
    return FALSE;
#else
    sMfRulesDebugUnlockOverride = enable;
    return TRUE;
#endif
}

bool8 MfRules_DebugHasUnlockOverride(void)
{
#ifdef NDEBUG
    return FALSE;
#else
    return sMfRulesDebugUnlockOverride;
#endif
}

bool8 MfRules_DebugRerollSeed(void)
{
#ifdef NDEBUG
    return FALSE;
#elif !MF_RULES_ENGINE
    return FALSE;
#else
    struct ModernRules *save;

    if (!MfRules_CanEdit(MF_RULE_EDIT_CORE))
    {
        if (!MfRules_DebugSetUnlockOverride(TRUE))
            return FALSE;
    }

    save = MfRules_GetSaveRules();
    if (save->version != MF_RULES_VERSION)
        return FALSE;

    save->randomizerSeed = MfRandom_GenerateNewSeed();
    return TRUE;
#endif
}

void MfRules_DebugDump(void)
{
#if !defined(NDEBUG) && MF_RULES_ENGINE
    const struct ModernRules *r = MfRules_GetActiveRules();

    DebugPrintfLevel(MGBA_LOG_DEBUG, "=== MF rules dump ===");
    DebugPrintfLevel(MGBA_LOG_DEBUG, "version=%u preset=%u locked=%u unlockOv=%u seed=0x%08X",
        r->version, r->gamemodePreset, r->rulesLocked,
        MfRules_DebugHasUnlockOverride(), r->randomizerSeed);

    DebugPrintfLevel(MGBA_LOG_DEBUG, "gamemode: infTm=%u survPsn=%u sync=%u mint=%u sitrus=%u types=%u fairy=%u stats=%u",
        r->infiniteTms, r->survivePoison, r->synchronize, r->mints,
        r->modernSitrus, r->modernTypes, r->fairyTypes, r->modernStats);
    DebugPrintfLevel(MGBA_LOG_DEBUG, "gamemode: sturdy=%u moves=%u legAbil=%u newLeg=%u typeEff=%u spawns=%u",
        r->sturdy, r->modernMoves, r->legendaryAbilities, r->newLegendaries,
        r->typeEffectiveness, r->alternateSpawns);

    DebugPrintfLevel(MGBA_LOG_DEBUG, "features: shiny=%u drops=%u feebas=%u rtc=%u shinyCol=%u wt=%u unlimWt=%u frBans=%u",
        r->shinyChance, r->wildItemDrops, r->easierFeebas, r->rtcType,
        r->shinyColors, r->wonderTrade, r->unlimitedWonderTrade, r->frontierBans);

    DebugPrintfLevel(MGBA_LOG_DEBUG, "random: on=%u start=%u wild=%u train=%u static=%u similar=%u map=%u legs=%u type=%u",
        r->randomizerEnabled, r->randomStarter, r->randomWild, r->randomTrainer, r->randomStatic,
        r->randomSimilar, r->randomMapBased, r->randomIncludeLegendaries, r->randomType);
    DebugPrintfLevel(MGBA_LOG_DEBUG, "random: moves=%u abil=%u evo=%u evoMeth=%u typeEff=%u items=%u chaos=%u",
        r->randomMoves, r->randomAbilities, r->randomEvolution, r->randomEvolutionMethods,
        r->randomTypeEffectiveness, r->randomItems, r->randomChaos);

    DebugPrintfLevel(MGBA_LOG_DEBUG, "nuzlocke: on=%u hard=%u easy=%u species=%u shiny=%u nick=%u del=%u usedAreas=%u",
        r->nuzlocke, r->nuzlockeHardcore, r->nuzlockeEasy, r->nuzlockeSpeciesClause,
        r->nuzlockeShinyClause, r->nuzlockeNicknaming, r->nuzlockeDeletion,
        MfNuzlockeCountUsedFrom(r->nuzlockeEncounterFlags));

    DebugPrintfLevel(MGBA_LOG_DEBUG, "diff: party=%u lvlCap=%u exp=%u noItemP=%u noItemT=%u noEv=%u",
        r->partyLimit, r->levelCap, r->expMultiplier, r->noItemPlayer, r->noItemTrainer, r->noEvs);
    DebugPrintfLevel(MGBA_LOG_DEBUG, "diff: scIv=%u scEv=%u maxIv=%u lockDiff=%u rope=%u hardExp=%u catch=%u lessEsc=%u",
        r->scalingIvs, r->scalingEvs, r->maxPartyIvs, r->lockDifficulty,
        r->escapeRopeDig, r->hardExp, r->catchRate, r->lessEscapes);

    DebugPrintfLevel(MGBA_LOG_DEBUG, "chal: pc=%u evo=%u bse=%u mirror=%u thief=%u noPcHeal=%u mono=%u shops=%u",
        r->pokeCenterLimit, r->evoLimit, r->baseStatEqualizer, r->mirror, r->mirrorThief,
        r->noPcHeal, r->monotype, r->expensiveShops);
#endif
}

bool8 MfRules_CanEdit(enum MfRuleEditClass editClass)
{
#if !MF_RULES_ENGINE
    (void)editClass;
    return FALSE;
#else
    const struct ModernRules *r = MfRules_GetActiveRules();

#ifndef NDEBUG
    if (sMfRulesDebugUnlockOverride)
        return TRUE;
#endif

    if (!r->rulesLocked)
        return TRUE;

    // Mid-run: Difficulty page stays editable unless LOCK DIFFICULTY is on.
    // lockDifficulty / rulesLocked themselves stay meta-only (ADR 0015).
    if (editClass == MF_RULE_EDIT_DIFFICULTY && !r->lockDifficulty)
        return TRUE;

    return FALSE;
#endif
}

static enum MfRuleEditClass MfRules_EditClassForBool(enum MfRuleBool id)
{
    switch (id)
    {
    case MF_RULE_BOOL_RULES_LOCKED:
    case MF_RULE_BOOL_LOCK_DIFFICULTY:
        return MF_RULE_EDIT_META;

    case MF_RULE_BOOL_NO_ITEM_PLAYER:
    case MF_RULE_BOOL_NO_ITEM_TRAINER:
    case MF_RULE_BOOL_NO_EVS:
    case MF_RULE_BOOL_ESCAPE_ROPE_DIG:
    case MF_RULE_BOOL_HARD_EXP:
    case MF_RULE_BOOL_SCALED_EXP:
    case MF_RULE_BOOL_LESS_ESCAPES: // Difficulty page in ME / S23
        return MF_RULE_EDIT_DIFFICULTY;

    default:
        return MF_RULE_EDIT_CORE;
    }
}

static enum MfRuleEditClass MfRules_EditClassForValue(enum MfRuleValue id)
{
    switch (id)
    {
    case MF_RULE_VAL_PARTY_LIMIT:
    case MF_RULE_VAL_LEVEL_CAP:
    case MF_RULE_VAL_EXP_MULTIPLIER:
    case MF_RULE_VAL_SCALING_IVS:
    case MF_RULE_VAL_SCALING_EVS:
    case MF_RULE_VAL_MAX_PARTY_IVS:
    case MF_RULE_VAL_CATCH_RATE:
        return MF_RULE_EDIT_DIFFICULTY;

    // pokeCenterLimit lives near difficulty in the struct but is Challenges (S24).
    default:
        return MF_RULE_EDIT_CORE;
    }
}

static bool8 MfRules_WriteBoolField(struct ModernRules *r, enum MfRuleBool id, bool8 value)
{
    switch (id)
    {
    case MF_RULE_BOOL_RULES_LOCKED:               r->rulesLocked = value; return TRUE;
    case MF_RULE_BOOL_INFINITE_TMS:               r->infiniteTms = value; return TRUE;
    case MF_RULE_BOOL_SURVIVE_POISON:             r->survivePoison = value; return TRUE;
    case MF_RULE_BOOL_SYNCHRONIZE:                r->synchronize = value; return TRUE;
    case MF_RULE_BOOL_MINTS:                      r->mints = value; return TRUE;
    case MF_RULE_BOOL_MODERN_SITRUS:              r->modernSitrus = value; return TRUE;
    case MF_RULE_BOOL_MODERN_TYPES:               r->modernTypes = value; return TRUE;
    case MF_RULE_BOOL_FAIRY_TYPES:                r->fairyTypes = value; return TRUE;
    case MF_RULE_BOOL_MODERN_STATS:               r->modernStats = value; return TRUE;
    case MF_RULE_BOOL_STURDY:                     r->sturdy = value; return TRUE;
    case MF_RULE_BOOL_MODERN_MOVES:               r->modernMoves = value; return TRUE;
    case MF_RULE_BOOL_LEGENDARY_ABILITIES:        r->legendaryAbilities = value; return TRUE;
    case MF_RULE_BOOL_NEW_LEGENDARIES:            r->newLegendaries = value; return TRUE;
    case MF_RULE_BOOL_TYPE_EFFECTIVENESS:         r->typeEffectiveness = value; return TRUE;
    case MF_RULE_BOOL_WILD_ITEM_DROPS:            r->wildItemDrops = value; return TRUE;
    case MF_RULE_BOOL_EASIER_FEEBAS:              r->easierFeebas = value; return TRUE;
    case MF_RULE_BOOL_RTC_TYPE:                   r->rtcType = value; return TRUE;
    case MF_RULE_BOOL_SHINY_COLORS:               r->shinyColors = value; return TRUE;
    case MF_RULE_BOOL_WONDER_TRADE:               r->wonderTrade = value; return TRUE;
    case MF_RULE_BOOL_UNLIMITED_WONDER_TRADE:     r->unlimitedWonderTrade = value; return TRUE;
    case MF_RULE_BOOL_FRONTIER_BANS:              r->frontierBans = value; return TRUE;
    case MF_RULE_BOOL_RANDOMIZER_ENABLED:         r->randomizerEnabled = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_STARTER:             r->randomStarter = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_WILD:                r->randomWild = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_TRAINER:             r->randomTrainer = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_STATIC:              r->randomStatic = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_SIMILAR:             r->randomSimilar = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_MAP_BASED:           r->randomMapBased = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_INCLUDE_LEGENDARIES: r->randomIncludeLegendaries = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_TYPE:                r->randomType = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_MOVES:               r->randomMoves = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_ABILITIES:           r->randomAbilities = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_EVOLUTION:           r->randomEvolution = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_EVOLUTION_METHODS:   r->randomEvolutionMethods = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_TYPE_EFFECTIVENESS:  r->randomTypeEffectiveness = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_ITEMS:               r->randomItems = value; return TRUE;
    case MF_RULE_BOOL_RANDOM_CHAOS:               r->randomChaos = value; return TRUE;
    case MF_RULE_BOOL_NUZLOCKE:                   r->nuzlocke = value; return TRUE;
    case MF_RULE_BOOL_NUZLOCKE_HARDCORE:          r->nuzlockeHardcore = value; return TRUE;
    case MF_RULE_BOOL_NUZLOCKE_EASY:              r->nuzlockeEasy = value; return TRUE;
    case MF_RULE_BOOL_NUZLOCKE_SPECIES_CLAUSE:    r->nuzlockeSpeciesClause = value; return TRUE;
    case MF_RULE_BOOL_NUZLOCKE_SHINY_CLAUSE:      r->nuzlockeShinyClause = value; return TRUE;
    case MF_RULE_BOOL_NUZLOCKE_NICKNAMING:        r->nuzlockeNicknaming = value; return TRUE;
    case MF_RULE_BOOL_NUZLOCKE_DELETION:          r->nuzlockeDeletion = value; return TRUE;
    case MF_RULE_BOOL_NO_ITEM_PLAYER:             r->noItemPlayer = value; return TRUE;
    case MF_RULE_BOOL_NO_ITEM_TRAINER:            r->noItemTrainer = value; return TRUE;
    case MF_RULE_BOOL_NO_EVS:                     r->noEvs = value; return TRUE;
    case MF_RULE_BOOL_LOCK_DIFFICULTY:            r->lockDifficulty = value; return TRUE;
    case MF_RULE_BOOL_ESCAPE_ROPE_DIG:            r->escapeRopeDig = value; return TRUE;
    case MF_RULE_BOOL_HARD_EXP:                   r->hardExp = value; return TRUE;
    case MF_RULE_BOOL_SCALED_EXP:                 r->scaledExp = value; return TRUE;
    case MF_RULE_BOOL_LESS_ESCAPES:               r->lessEscapes = value; return TRUE;
    case MF_RULE_BOOL_MIRROR:                     r->mirror = value; return TRUE;
    case MF_RULE_BOOL_MIRROR_THIEF:               r->mirrorThief = value; return TRUE;
    case MF_RULE_BOOL_NO_PC_HEAL:                 r->noPcHeal = value; return TRUE;
    case MF_RULE_BOOL_COUNT:                      break;
    }
    return FALSE;
}

static bool8 MfRules_WriteValueField(struct ModernRules *r, enum MfRuleValue id, u8 value)
{
    switch (id)
    {
    case MF_RULE_VAL_GAMEMODE_PRESET:     r->gamemodePreset = value & 3; return TRUE;
    case MF_RULE_VAL_ALTERNATE_SPAWNS:    r->alternateSpawns = value & 3; return TRUE;
    case MF_RULE_VAL_SHINY_CHANCE:        r->shinyChance = value & 0xF; return TRUE;
    case MF_RULE_VAL_PARTY_LIMIT:         r->partyLimit = value & 7; return TRUE;
    case MF_RULE_VAL_LEVEL_CAP:           r->levelCap = value & 3; return TRUE;
    case MF_RULE_VAL_EXP_MULTIPLIER:      r->expMultiplier = value & 3; return TRUE;
    case MF_RULE_VAL_SCALING_IVS:         r->scalingIvs = value & 3; return TRUE;
    case MF_RULE_VAL_SCALING_EVS:         r->scalingEvs = value & 3; return TRUE;
    case MF_RULE_VAL_MAX_PARTY_IVS:       r->maxPartyIvs = value & 3; return TRUE;
    case MF_RULE_VAL_POKECENTER_LIMIT:    r->pokeCenterLimit = value & 3; return TRUE;
    case MF_RULE_VAL_CATCH_RATE:          r->catchRate = value & 7; return TRUE;
    case MF_RULE_VAL_EVO_LIMIT:           r->evoLimit = value & 3; return TRUE;
    case MF_RULE_VAL_BASE_STAT_EQUALIZER: r->baseStatEqualizer = value & 3; return TRUE;
    case MF_RULE_VAL_MONOTYPE:            r->monotype = value & 0x1F; return TRUE;
    case MF_RULE_VAL_EXPENSIVE_SHOPS:     r->expensiveShops = value & 7; return TRUE;
    case MF_RULE_VAL_NUZLOCKE_MODE:       break; // handled in TrySetValue
    case MF_RULE_VAL_COUNT:               break;
    }
    return FALSE;
}

// S22 — pack Off/Easy/Normal/Hardcore into nuzlocke / easy / hardcore bits.
// Leaving full Nuzlocke clears clauses (ME save path). Entering Normal/Hard
// from Off/Easy seeds ME recommended defaults. Entering Hardcore also seeds
// Difficulty extras (ADR 0040) for Phase 7 enforcement.
static void MfRules_ApplyNuzlockeMode(struct ModernRules *r, u8 mode)
{
    u8 prev = MfRules_PackNuzlockeMode(r);
    bool8 wasFull = (prev == MF_NUZLOCKE_NORMAL || prev == MF_NUZLOCKE_HARDCORE);
    bool8 isFull;

    if (mode > MF_NUZLOCKE_HARDCORE)
        mode = MF_NUZLOCKE_OFF;

    switch (mode)
    {
    case MF_NUZLOCKE_EASY:
        r->nuzlocke = FALSE;
        r->nuzlockeHardcore = FALSE;
        r->nuzlockeEasy = TRUE;
        break;
    case MF_NUZLOCKE_NORMAL:
        r->nuzlocke = TRUE;
        r->nuzlockeHardcore = FALSE;
        r->nuzlockeEasy = FALSE;
        break;
    case MF_NUZLOCKE_HARDCORE:
        r->nuzlocke = TRUE;
        r->nuzlockeHardcore = TRUE;
        r->nuzlockeEasy = FALSE;
        break;
    case MF_NUZLOCKE_OFF:
    default:
        r->nuzlocke = FALSE;
        r->nuzlockeHardcore = FALSE;
        r->nuzlockeEasy = FALSE;
        break;
    }

    isFull = (mode == MF_NUZLOCKE_NORMAL || mode == MF_NUZLOCKE_HARDCORE);
    if (!isFull)
    {
        r->nuzlockeSpeciesClause = FALSE;
        r->nuzlockeShinyClause = FALSE;
        r->nuzlockeNicknaming = FALSE;
        r->nuzlockeDeletion = FALSE;
    }
    else if (!wasFull)
    {
        r->nuzlockeSpeciesClause = MF_TX_NUZLOCKE_SPECIES_CLAUSE;
        r->nuzlockeShinyClause = MF_TX_NUZLOCKE_SHINY_CLAUSE;
        r->nuzlockeNicknaming = MF_TX_NUZLOCKE_NICKNAMING;
        r->nuzlockeDeletion = MF_TX_NUZLOCKE_DELETION;
    }

    // Hardcore community extras: Set style + level cap + no player items.
    // Leaving Hardcore does not clear Difficulty fields (player may keep them).
    if (mode == MF_NUZLOCKE_HARDCORE && prev != MF_NUZLOCKE_HARDCORE)
        MfNuzlocke_ApplyHardcoreDifficultySeeds(r);
}

// S25 — master Off clears all remaps (ME SAVE path); On seeds Similar/MapBased.
static void MfRules_ApplyRandomizerEnabled(struct ModernRules *r, bool8 enabled)
{
    r->randomizerEnabled = enabled;
    if (!enabled)
    {
        r->randomStarter = FALSE;
        r->randomWild = FALSE;
        r->randomTrainer = FALSE;
        r->randomStatic = FALSE;
        r->randomSimilar = FALSE;
        r->randomMapBased = FALSE;
        r->randomIncludeLegendaries = FALSE;
        r->randomType = FALSE;
        r->randomMoves = FALSE;
        r->randomAbilities = FALSE;
        r->randomEvolution = FALSE;
        r->randomEvolutionMethods = FALSE;
        r->randomTypeEffectiveness = FALSE;
        r->randomItems = FALSE;
        r->randomChaos = FALSE;
    }
    else
    {
        r->randomSimilar = MF_TX_RANDOM_SIMILAR;
        r->randomMapBased = MF_TX_RANDOM_MAP_BASED;
    }
}

bool8 MfRules_TrySetBool(enum MfRuleBool id, bool8 value)
{
#if !MF_RULES_ENGINE
    (void)id;
    (void)value;
    return FALSE;
#else
    struct ModernRules *save;
    enum MfRuleEditClass editClass = MfRules_EditClassForBool(id);

    if (id >= MF_RULE_BOOL_COUNT)
        return FALSE;
    if (!MfRules_CanEdit(editClass))
        return FALSE;

    save = MfRules_GetSaveRules();
    if (save->version != MF_RULES_VERSION)
        return FALSE;

    // S25: master toggle clears or seeds remaps (ME SAVE spirit, live writes).
    if (id == MF_RULE_BOOL_RANDOMIZER_ENABLED)
    {
        MfRules_ApplyRandomizerEnabled(save, value);
        return TRUE;
    }

    if (!MfRules_WriteBoolField(save, id, value))
        return FALSE;

    // ME DrawChoices_Random_OffChaos: Chaos forces Balancing off.
    if (id == MF_RULE_BOOL_RANDOM_CHAOS && value)
        save->randomSimilar = FALSE;

    return TRUE;
#endif
}

bool8 MfRules_TrySetValue(enum MfRuleValue id, u8 value)
{
#if !MF_RULES_ENGINE
    (void)id;
    (void)value;
    return FALSE;
#else
    struct ModernRules *save;
    enum MfRuleEditClass editClass = MfRules_EditClassForValue(id);

    if (id >= MF_RULE_VAL_COUNT)
        return FALSE;
    if (!MfRules_CanEdit(editClass))
        return FALSE;

    save = MfRules_GetSaveRules();
    if (save->version != MF_RULES_VERSION)
        return FALSE;

    // S20: Classic/Modern bulk-set gamemode fields (ME selector + ADR 0014).
    if (id == MF_RULE_VAL_GAMEMODE_PRESET)
    {
        if (value > MF_GAMEMODE_CUSTOM)
            value = MF_GAMEMODE_CUSTOM;
        MfRules_ApplyGamemodePreset(save, (enum MfGamemodePreset)value);
        return TRUE;
    }

    // S22: Off/Easy/Normal/Hardcore packs three bitfields + clause defaults.
    if (id == MF_RULE_VAL_NUZLOCKE_MODE)
    {
        MfRules_ApplyNuzlockeMode(save, value);
        return TRUE;
    }

    return MfRules_WriteValueField(save, id, value);
#endif
}
