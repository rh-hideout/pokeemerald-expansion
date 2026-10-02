#ifndef GUARD_MF_RULES_H
#define GUARD_MF_RULES_H

// Modern FireRed save-backed rules (S12–S16). Field checklist mirrors ME's
// tx_randomizer_and_challenges options (Gamemode / Features / Randomizer /
// Nuzlocke / Difficulty / Challenges). Packed bitfields match ME's density;
// storage lives in SaveBlock3 (see ADR 0012). Accessors: ADR 0013 +
// docs-mf/RULES_ACCESSORS.md. Presets / new-game init: ADR 0014.
// Mid-run lock: ADR 0015. Seeded RNG: ADR 0016 (`mf_random.h`).

#include "gba/types.h"
#include "constants/region_map_sections.h"

// Bump when the on-save layout of struct ModernRules changes (S64 migrates).
#define MF_RULES_VERSION 1

// Soft ceiling so Nuzlocke flags + seed never silently balloon SaveBlock3.
// Hard ceiling remains SAVE_BLOCK_3_CHUNK_SIZE * NUM_SECTORS_PER_SLOT (1624).
#define MF_RULES_MAX_BYTES 128

#define MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES ((MAPSEC_COUNT + 7) / 8)

// Gamemode page preset (S14 fills Classic / Modern / Custom vectors).
enum MfGamemodePreset
{
    MF_GAMEMODE_CLASSIC = 0,
    MF_GAMEMODE_MODERN = 1,
    MF_GAMEMODE_CUSTOM = 2,
};

// Nuzlocke page master toggle (S22). Packs nuzlocke / easy / hardcore bits.
// Easy = ME mini mode (faint retirement only; sub-options disabled).
enum MfNuzlockeMode
{
    MF_NUZLOCKE_OFF = 0,
    MF_NUZLOCKE_EASY = 1,
    MF_NUZLOCKE_NORMAL = 2,
    MF_NUZLOCKE_HARDCORE = 3,
};

// Packed player rules for one save. Do not reorder fields after S12 ships —
// additive changes only, via MF_RULES_VERSION + S64.
struct ModernRules
{
    /*0x00*/ u16 version;
    /*0x02*/ u8 gamemodePreset:2; // MfGamemodePreset
    /*0x02*/ u8 rulesLocked:1;    // S15 mid-run lock
    /*0x02*/ u8 padding0:5;

    /*0x03*/ // --- Gamemode (ME tx_Mode_*) ---
             u8 infiniteTms:1;
             u8 survivePoison:1;
             u8 synchronize:1;
             u8 mints:1;
             u8 modernSitrus:1;       // ME tx_Mode_New_Citrus
             u8 modernTypes:1;
             u8 fairyTypes:1;
             u8 modernStats:1;

    /*0x04*/ u8 sturdy:1;
             u8 modernMoves:1;
             u8 legendaryAbilities:1;
             u8 newLegendaries:1;     // ME parity; FR map content still out of scope
             u8 typeEffectiveness:1;  // ME tx_Mode_TypeEffectiveness
             u8 alternateSpawns:2;    // ME tx_Mode_Encounters
             u8 paddingGamemode:1;

    /*0x05*/ // --- Features (ME tx_Features_*) ---
             u8 shinyChance:4;
             u8 wildItemDrops:1;
             u8 easierFeebas:1;       // Hoenn leftover; unused in FR
             u8 rtcType:1;
             u8 shinyColors:1;

    /*0x06*/ u8 wonderTrade:1;
             u8 unlimitedWonderTrade:1;
             u8 frontierBans:1;       // ME parity; FR has no Frontier
             u8 paddingFeatures:5;

    /*0x07*/ // --- Randomizer (ME tx_Random_*) ---
             u8 randomStarter:1;
             u8 randomWild:1;
             u8 randomTrainer:1;
             u8 randomStatic:1;
             u8 randomSimilar:1;
             u8 randomMapBased:1;
             u8 randomIncludeLegendaries:1;
             u8 randomType:1;

    /*0x08*/ u8 randomMoves:1;
             u8 randomAbilities:1;
             u8 randomEvolution:1;
             u8 randomEvolutionMethods:1;
             u8 randomTypeEffectiveness:1;
             u8 randomItems:1;
             u8 randomChaos:1;
             u8 randomizerEnabled:1; // S25 master toggle (menu gate; clears remaps when off)

    /*0x09*/ // --- Nuzlocke (ME tx_Challenges_Nuzlocke* / tx_Nuzlocke_*) ---
             u8 nuzlocke:1;
             u8 nuzlockeHardcore:1;
             u8 nuzlockeEasy:1;       // ME tx_Nuzlocke_EasyMode / mini
             u8 nuzlockeSpeciesClause:1;
             u8 nuzlockeShinyClause:1;
             u8 nuzlockeNicknaming:1;
             u8 nuzlockeDeletion:1;
             u8 paddingNuzlocke:1;

    /*0x0A*/ // --- Difficulty (ME tx_Challenges_* / tx_Difficulty_*) ---
             u8 partyLimit:3;         // 0 = 6; value is (6 - maxParty)
             u8 levelCap:2;
             u8 expMultiplier:2;
             u8 noItemPlayer:1;

    /*0x0B*/ u8 noItemTrainer:1;
             u8 noEvs:1;
             u8 scalingIvs:2;
             u8 scalingEvs:2;
             u8 maxPartyIvs:2;

    /*0x0C*/ u8 pokeCenterLimit:2;    // 0 unlimited, 1 none (ME naming)
             u8 lockDifficulty:1;     // ME tx_Features_LimitDifficulty
             u8 escapeRopeDig:1;
             u8 hardExp:1;
             u8 catchRate:3;

    /*0x0D*/ // --- Challenges (ME tx_Challenges_*) ---
             u8 evoLimit:2;
             u8 baseStatEqualizer:2;
             u8 lessEscapes:1;
             u8 mirror:1;
             u8 mirrorThief:1;
             u8 noPcHeal:1;

    /*0x0E*/ u8 monotype:5;           // ME OneTypeChallenge; 31 = off
             u8 expensiveShops:3;

    /*0x0F*/ u8 scaledExp:1;          // S70; low bit of the old paddingTail byte
             u8 paddingTail:7;

    /*0x10*/ u32 randomizerSeed;

    /*0x14*/ u8 nuzlockeEncounterFlags[MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES];
};

typedef char mf_rules_fits_in_budget[(sizeof(struct ModernRules) <= MF_RULES_MAX_BYTES) ? 1 : -1];
typedef char mf_nuzlocke_flags_cover_mapsecs[(MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES * 8 >= MAPSEC_COUNT) ? 1 : -1];

#define MF_RULES_SERIALIZED_SIZE (sizeof(struct ModernRules))

// Boolean rule ids for MfRules_GetBool (every 1-bit field).
enum MfRuleBool
{
    MF_RULE_BOOL_RULES_LOCKED,
    MF_RULE_BOOL_INFINITE_TMS,
    MF_RULE_BOOL_SURVIVE_POISON,
    MF_RULE_BOOL_SYNCHRONIZE,
    MF_RULE_BOOL_MINTS,
    MF_RULE_BOOL_MODERN_SITRUS,
    MF_RULE_BOOL_MODERN_TYPES,
    MF_RULE_BOOL_FAIRY_TYPES,
    MF_RULE_BOOL_MODERN_STATS,
    MF_RULE_BOOL_STURDY,
    MF_RULE_BOOL_MODERN_MOVES,
    MF_RULE_BOOL_LEGENDARY_ABILITIES,
    MF_RULE_BOOL_NEW_LEGENDARIES,
    MF_RULE_BOOL_TYPE_EFFECTIVENESS,
    MF_RULE_BOOL_WILD_ITEM_DROPS,
    MF_RULE_BOOL_EASIER_FEEBAS,
    MF_RULE_BOOL_RTC_TYPE,
    MF_RULE_BOOL_SHINY_COLORS,
    MF_RULE_BOOL_WONDER_TRADE,
    MF_RULE_BOOL_UNLIMITED_WONDER_TRADE,
    MF_RULE_BOOL_FRONTIER_BANS,
    MF_RULE_BOOL_RANDOMIZER_ENABLED,
    MF_RULE_BOOL_RANDOM_STARTER,
    MF_RULE_BOOL_RANDOM_WILD,
    MF_RULE_BOOL_RANDOM_TRAINER,
    MF_RULE_BOOL_RANDOM_STATIC,
    MF_RULE_BOOL_RANDOM_SIMILAR,
    MF_RULE_BOOL_RANDOM_MAP_BASED,
    MF_RULE_BOOL_RANDOM_INCLUDE_LEGENDARIES,
    MF_RULE_BOOL_RANDOM_TYPE,
    MF_RULE_BOOL_RANDOM_MOVES,
    MF_RULE_BOOL_RANDOM_ABILITIES,
    MF_RULE_BOOL_RANDOM_EVOLUTION,
    MF_RULE_BOOL_RANDOM_EVOLUTION_METHODS,
    MF_RULE_BOOL_RANDOM_TYPE_EFFECTIVENESS,
    MF_RULE_BOOL_RANDOM_ITEMS,
    MF_RULE_BOOL_RANDOM_CHAOS,
    MF_RULE_BOOL_NUZLOCKE,
    MF_RULE_BOOL_NUZLOCKE_HARDCORE,
    MF_RULE_BOOL_NUZLOCKE_EASY,
    MF_RULE_BOOL_NUZLOCKE_SPECIES_CLAUSE,
    MF_RULE_BOOL_NUZLOCKE_SHINY_CLAUSE,
    MF_RULE_BOOL_NUZLOCKE_NICKNAMING,
    MF_RULE_BOOL_NUZLOCKE_DELETION,
    MF_RULE_BOOL_NO_ITEM_PLAYER,
    MF_RULE_BOOL_NO_ITEM_TRAINER,
    MF_RULE_BOOL_NO_EVS,
    MF_RULE_BOOL_LOCK_DIFFICULTY,
    MF_RULE_BOOL_ESCAPE_ROPE_DIG,
    MF_RULE_BOOL_HARD_EXP,
    MF_RULE_BOOL_SCALED_EXP,
    MF_RULE_BOOL_LESS_ESCAPES,
    MF_RULE_BOOL_MIRROR,
    MF_RULE_BOOL_MIRROR_THIEF,
    MF_RULE_BOOL_NO_PC_HEAL,
    MF_RULE_BOOL_COUNT,
};

// Multi-bit / small integer rule ids for MfRules_GetValue.
enum MfRuleValue
{
    MF_RULE_VAL_GAMEMODE_PRESET,
    MF_RULE_VAL_ALTERNATE_SPAWNS,
    MF_RULE_VAL_SHINY_CHANCE,
    MF_RULE_VAL_PARTY_LIMIT,
    MF_RULE_VAL_LEVEL_CAP,
    MF_RULE_VAL_EXP_MULTIPLIER,
    MF_RULE_VAL_SCALING_IVS,
    MF_RULE_VAL_SCALING_EVS,
    MF_RULE_VAL_MAX_PARTY_IVS,
    MF_RULE_VAL_POKECENTER_LIMIT,
    MF_RULE_VAL_CATCH_RATE,
    MF_RULE_VAL_EVO_LIMIT,
    MF_RULE_VAL_BASE_STAT_EQUALIZER,
    MF_RULE_VAL_MONOTYPE,
    MF_RULE_VAL_EXPENSIVE_SHOPS,
    MF_RULE_VAL_NUZLOCKE_MODE, // MfNuzlockeMode (packs nuzlocke/easy/hardcore)
    MF_RULE_VAL_COUNT,
};

// Phase 1 baseline used when MF_RULES_ENGINE is off or save version mismatches.
extern const struct ModernRules gMfRulesPhase1Defaults;

void MfRules_ResetToEmpty(struct ModernRules *rules);
void MfRules_Pack(const struct ModernRules *rules, u8 *out);
void MfRules_Unpack(const u8 *in, struct ModernRules *rules);
struct ModernRules *MfRules_GetSaveRules(void);

// S14 — new-game / preset helpers (writers). See ADR 0014.
void MfRules_ApplyDevDefaults(struct ModernRules *rules);
void MfRules_ApplyGamemodePreset(struct ModernRules *rules, enum MfGamemodePreset preset);
void MfRules_InitNewGame(void);

// S15 — mid-run lock. Writers go through TrySet*; see ADR 0015.
// Edit classes for CanEdit / menu greying (S18+).
enum MfRuleEditClass
{
    MF_RULE_EDIT_CORE,       // Gamemode / Features / Randomizer / Nuzlocke / Challenges
    MF_RULE_EDIT_DIFFICULTY, // Difficulty page (except lockDifficulty itself)
    MF_RULE_EDIT_META,       // rulesLocked / lockDifficulty — commit or debug only
};

void MfRules_CommitAndLock(void);
bool8 MfRules_CanEdit(enum MfRuleEditClass editClass);
bool8 MfRules_TrySetBool(enum MfRuleBool id, bool8 value);
bool8 MfRules_TrySetValue(enum MfRuleValue id, u8 value);

// Non-release only: session override so S17 debug inspector can write locked rules.
// No-ops / returns FALSE under NDEBUG (make release).
bool8 MfRules_DebugSetUnlockOverride(bool8 enable);
bool8 MfRules_DebugHasUnlockOverride(void);
// Non-release: assign a fresh randomizerSeed (uses unlock override if locked).
bool8 MfRules_DebugRerollSeed(void);
// Non-release: dump every rule field via DebugPrintf (ME PrintTXSaveData spirit).
void MfRules_DebugDump(void);

// Active rules for gameplay reads (null-safe). Prefer typed helpers on hot paths.
const struct ModernRules *MfRules_GetActiveRules(void);
bool8 MfRules_GetBool(enum MfRuleBool id);
u8 MfRules_GetValue(enum MfRuleValue id);

// --- Typed helpers (header-inlined; one GetActiveRules call + field load) ---

static inline bool8 MfRules_AreRulesLocked(void)
{
    return MfRules_GetActiveRules()->rulesLocked;
}

static inline bool8 MfRules_HasInfiniteTms(void)
{
    return MfRules_GetActiveRules()->infiniteTms;
}

static inline bool8 MfRules_HasSurvivePoison(void)
{
    return MfRules_GetActiveRules()->survivePoison;
}

static inline bool8 MfRules_HasSynchronize(void)
{
    return MfRules_GetActiveRules()->synchronize;
}

static inline bool8 MfRules_HasMints(void)
{
    return MfRules_GetActiveRules()->mints;
}

static inline bool8 MfRules_HasModernSitrus(void)
{
    return MfRules_GetActiveRules()->modernSitrus;
}

static inline bool8 MfRules_HasModernTypes(void)
{
    return MfRules_GetActiveRules()->modernTypes;
}

static inline bool8 MfRules_HasFairyTypes(void)
{
    return MfRules_GetActiveRules()->fairyTypes;
}

static inline bool8 MfRules_HasModernStats(void)
{
    return MfRules_GetActiveRules()->modernStats;
}

static inline bool8 MfRules_HasSturdy(void)
{
    return MfRules_GetActiveRules()->sturdy;
}

static inline bool8 MfRules_HasModernMoves(void)
{
    return MfRules_GetActiveRules()->modernMoves;
}

static inline bool8 MfRules_HasLegendaryAbilities(void)
{
    return MfRules_GetActiveRules()->legendaryAbilities;
}

static inline bool8 MfRules_HasTypeEffectiveness(void)
{
    return MfRules_GetActiveRules()->typeEffectiveness;
}

static inline u8 MfRules_GetAlternateSpawns(void)
{
    return MfRules_GetActiveRules()->alternateSpawns;
}

static inline u8 MfRules_GetShinyChance(void)
{
    return MfRules_GetActiveRules()->shinyChance;
}

static inline bool8 MfRules_HasWildItemDrops(void)
{
    return MfRules_GetActiveRules()->wildItemDrops;
}

static inline bool8 MfRules_IsNuzlocke(void)
{
    return MfRules_GetActiveRules()->nuzlocke;
}

static inline bool8 MfRules_IsNuzlockeHardcore(void)
{
    return MfRules_GetActiveRules()->nuzlockeHardcore;
}

static inline bool8 MfRules_IsNuzlockeEasy(void)
{
    return MfRules_GetActiveRules()->nuzlockeEasy;
}

static inline bool8 MfRules_HasNuzlockeSpeciesClause(void)
{
    return MfRules_GetActiveRules()->nuzlockeSpeciesClause;
}

static inline bool8 MfRules_HasNuzlockeShinyClause(void)
{
    return MfRules_GetActiveRules()->nuzlockeShinyClause;
}

static inline bool8 MfRules_HasNuzlockeNicknaming(void)
{
    return MfRules_GetActiveRules()->nuzlockeNicknaming;
}

static inline bool8 MfRules_HasNuzlockeDeletion(void)
{
    return MfRules_GetActiveRules()->nuzlockeDeletion;
}

// True when DUPES/SHINY/NICKNAMES/FAINTING may be edited (Normal or Hardcore).
static inline bool8 MfRules_NuzlockeSubOptionsActive(void)
{
    const struct ModernRules *r = MfRules_GetActiveRules();

    return r->nuzlocke && !r->nuzlockeEasy;
}

static inline u8 MfRules_GetPartyLimit(void)
{
    return MfRules_GetActiveRules()->partyLimit;
}

// ME: partyLimit stores (6 - maxParty); 0 = Off (party of 6).
// Prefer MfGetMaxPartySize() at enforcement sites (S40 / mf_party.h).
static inline u8 MfRules_GetMaxPartySize(void)
{
    u8 limit = MfRules_GetActiveRules()->partyLimit;

    if (limit > 5)
        limit = 5;
    return 6 - limit;
}

static inline u8 MfRules_GetLevelCap(void)
{
    return MfRules_GetActiveRules()->levelCap;
}

static inline u8 MfRules_GetExpMultiplier(void)
{
    return MfRules_GetActiveRules()->expMultiplier;
}

static inline bool8 MfRules_GetScaledExp(void)
{
    return MfRules_GetActiveRules()->scaledExp;
}

static inline bool8 MfRules_HasNoItemPlayer(void)
{
    return MfRules_GetActiveRules()->noItemPlayer;
}

static inline bool8 MfRules_HasNoItemTrainer(void)
{
    return MfRules_GetActiveRules()->noItemTrainer;
}

static inline u8 MfRules_GetPokeCenterLimit(void)
{
    return MfRules_GetActiveRules()->pokeCenterLimit;
}

static inline bool8 MfRules_HasNoPcHeal(void)
{
    return MfRules_GetActiveRules()->noPcHeal;
}

static inline u8 MfRules_GetMonotype(void)
{
    return MfRules_GetActiveRules()->monotype;
}

static inline bool8 MfRules_IsMonotypeActive(void)
{
    return MfRules_GetActiveRules()->monotype != 31;
}

static inline u8 MfRules_GetEvoLimit(void)
{
    return MfRules_GetActiveRules()->evoLimit;
}

static inline u8 MfRules_GetBaseStatEqualizer(void)
{
    return MfRules_GetActiveRules()->baseStatEqualizer;
}

static inline bool8 MfRules_IsMirror(void)
{
    return MfRules_GetActiveRules()->mirror;
}

static inline u32 MfRules_GetRandomizerSeed(void)
{
    return MfRules_GetActiveRules()->randomizerSeed;
}

// ME IsRandomizerActivated — any remapping feature (not Similar/MapBased alone).
static inline bool8 MfRules_IsRandomizerActive(void)
{
    const struct ModernRules *r = MfRules_GetActiveRules();

    return r->randomStarter
        || r->randomWild
        || r->randomTrainer
        || r->randomStatic
        || r->randomMoves
        || r->randomAbilities
        || r->randomEvolution
        || r->randomEvolutionMethods
        || r->randomType
        || r->randomTypeEffectiveness
        || r->randomItems
        || r->randomChaos;
}

static inline bool8 MfRules_IsRandomizerEnabled(void)
{
    return MfRules_GetActiveRules()->randomizerEnabled;
}

// Species remaps that unlock BALANCING / LEGENDARIES (ME CheckConditions).
static inline bool8 MfRules_RandomizerSpeciesActive(void)
{
    const struct ModernRules *r = MfRules_GetActiveRules();

    return r->randomizerEnabled
        && (r->randomStarter || r->randomWild || r->randomTrainer || r->randomStatic);
}

static inline bool8 MfRules_RandomizerBalancingEditable(void)
{
    const struct ModernRules *r = MfRules_GetActiveRules();

    return MfRules_RandomizerSpeciesActive() && !r->randomChaos;
}

// CHAOS editable when master on and any chaos-eligible remap is on (ME; items excluded).
static inline bool8 MfRules_RandomizerChaosEditable(void)
{
    const struct ModernRules *r = MfRules_GetActiveRules();

    return r->randomizerEnabled
        && (r->randomStarter
         || r->randomWild
         || r->randomTrainer
         || r->randomStatic
         || r->randomType
         || r->randomMoves
         || r->randomAbilities
         || r->randomEvolution
         || r->randomEvolutionMethods
         || r->randomTypeEffectiveness);
}

#endif // GUARD_MF_RULES_H
