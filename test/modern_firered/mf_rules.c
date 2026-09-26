#include "global.h"
#include "mf_rules.h"
#include "save.h"
#include "test/test.h"

static void FillRulesWithPattern(struct ModernRules *rules)
{
    MfRules_ResetToEmpty(rules);

    rules->gamemodePreset = MF_GAMEMODE_MODERN;
    rules->rulesLocked = TRUE;

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
    rules->typeEffectiveness = TRUE;
    rules->alternateSpawns = 2;

    rules->shinyChance = 9;
    rules->wildItemDrops = TRUE;
    rules->rtcType = TRUE;
    rules->shinyColors = TRUE;
    rules->wonderTrade = TRUE;

    rules->randomStarter = TRUE;
    rules->randomWild = TRUE;
    rules->randomTrainer = TRUE;
    rules->randomStatic = TRUE;
    rules->randomSimilar = TRUE;
    rules->randomMapBased = TRUE;
    rules->randomIncludeLegendaries = TRUE;
    rules->randomType = TRUE;
    rules->randomMoves = TRUE;
    rules->randomAbilities = TRUE;
    rules->randomEvolution = TRUE;
    rules->randomEvolutionMethods = TRUE;
    rules->randomTypeEffectiveness = TRUE;
    rules->randomItems = TRUE;
    rules->randomChaos = TRUE;

    rules->nuzlocke = TRUE;
    rules->nuzlockeHardcore = TRUE;
    rules->nuzlockeSpeciesClause = TRUE;
    rules->nuzlockeShinyClause = TRUE;
    rules->nuzlockeNicknaming = TRUE;
    rules->nuzlockeDeletion = TRUE;

    rules->partyLimit = 3;
    rules->levelCap = 2;
    rules->expMultiplier = 2;
    rules->noItemPlayer = TRUE;
    rules->noItemTrainer = TRUE;
    rules->noEvs = TRUE;
    rules->scalingIvs = 2;
    rules->scalingEvs = 3;
    rules->maxPartyIvs = 2;
    rules->pokeCenterLimit = 1;
    rules->lockDifficulty = TRUE;
    rules->escapeRopeDig = TRUE;
    rules->hardExp = TRUE;
    rules->catchRate = 5;

    rules->evoLimit = 2;
    rules->baseStatEqualizer = 3;
    rules->lessEscapes = TRUE;
    rules->mirror = TRUE;
    rules->mirrorThief = TRUE;
    rules->noPcHeal = TRUE;
    rules->monotype = 12;
    rules->expensiveShops = 4;

    rules->randomizerSeed = 0xA5A5F00Du;
    rules->nuzlockeEncounterFlags[0] = 0xAAu;
    rules->nuzlockeEncounterFlags[MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES - 1] = 0x55u;
}

static void LoadPatternIntoSave(void)
{
    FillRulesWithPattern(MfRules_GetSaveRules());
}

TEST("MF: rules struct fits save budget")
{
    EXPECT_LE(sizeof(struct ModernRules), MF_RULES_MAX_BYTES);
    EXPECT_LE(sizeof(struct SaveBlock3), SAVE_BLOCK_3_CHUNK_SIZE * NUM_SECTORS_PER_SLOT);
}

TEST("MF: rules pack/unpack round-trip")
{
    struct ModernRules original;
    struct ModernRules restored;
    u8 blob[MF_RULES_SERIALIZED_SIZE];

    FillRulesWithPattern(&original);
    memset(blob, 0xFF, sizeof(blob));
    memset(&restored, 0x00, sizeof(restored));

    MfRules_Pack(&original, blob);
    MfRules_Unpack(blob, &restored);

    EXPECT_EQ(memcmp(&original, &restored, sizeof(original)), 0);
    EXPECT_EQ(restored.version, MF_RULES_VERSION);
    EXPECT_EQ((u32)restored.gamemodePreset, (u32)MF_GAMEMODE_MODERN);
    EXPECT_EQ(restored.randomizerSeed, 0xA5A5F00Du);
    EXPECT_EQ((u32)restored.shinyChance, 9u);
    EXPECT_EQ((u32)restored.monotype, 12u);
    EXPECT_EQ(restored.nuzlockeEncounterFlags[0], 0xAAu);
    EXPECT_EQ(restored.nuzlockeEncounterFlags[MF_NUZLOCKE_ENCOUNTER_FLAG_BYTES - 1], 0x55u);
}

TEST("MF: rules reset sets version and monotype off")
{
    struct ModernRules rules;

    memset(&rules, 0xA5, sizeof(rules));
    MfRules_ResetToEmpty(&rules);

    EXPECT_EQ(rules.version, MF_RULES_VERSION);
    EXPECT_EQ((u32)rules.monotype, 31u);
    EXPECT_EQ((u32)rules.rulesLocked, (u32)FALSE);
    EXPECT_EQ(rules.randomizerSeed, 0u);
    EXPECT_EQ((u32)rules.nuzlocke, (u32)FALSE);
    EXPECT_EQ(rules.nuzlockeEncounterFlags[0], 0u);
}

TEST("MF: rules SaveBlock3 embeds ModernRules after dexNavChain")
{
    // Layout lock: older saves keep reading dexNavChain at the same offset;
    // mfRules is appended so pre-S12 saves still load.
    EXPECT_EQ(offsetof(struct SaveBlock3, dexNavChain), 0u);
    EXPECT_EQ(offsetof(struct SaveBlock3, mfRules), 4u);
}

TEST("MF: rules Phase 1 null defaults match vanilla-plus-Phase-1")
{
    EXPECT_EQ(gMfRulesPhase1Defaults.version, MF_RULES_VERSION);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.gamemodePreset, (u32)MF_GAMEMODE_MODERN);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.infiniteTms, (u32)TRUE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.survivePoison, (u32)TRUE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.synchronize, (u32)TRUE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.sturdy, (u32)TRUE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.modernSitrus, (u32)TRUE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.modernTypes, (u32)TRUE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.fairyTypes, (u32)TRUE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.modernStats, (u32)TRUE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.modernMoves, (u32)TRUE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.typeEffectiveness, (u32)TRUE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.nuzlocke, (u32)FALSE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.randomWild, (u32)FALSE);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.partyLimit, 0u);
    EXPECT_EQ((u32)gMfRulesPhase1Defaults.monotype, 31u);
    EXPECT_EQ(gMfRulesPhase1Defaults.randomizerSeed, 0u);
}

TEST("MF: rules active follow save when version matches")
{
    LoadPatternIntoSave();
    EXPECT_EQ(MfRules_GetActiveRules(), MfRules_GetSaveRules());
    EXPECT_EQ((u32)MfRules_HasFairyTypes(), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_IsNuzlocke(), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetShinyChance(), 9u);
    EXPECT_EQ((u32)MfRules_GetMaxPartySize(), 3u); // partyLimit 3 → 6-3
    EXPECT_EQ((u32)MfRules_IsMonotypeActive(), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_IsRandomizerActive(), (u32)TRUE);
    EXPECT_EQ(MfRules_GetRandomizerSeed(), 0xA5A5F00Du);
}

TEST("MF: rules active fall back on version mismatch (null path)")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    LoadPatternIntoSave();
    save->version = 0; // predate / junk

    EXPECT_EQ(MfRules_GetActiveRules(), &gMfRulesPhase1Defaults);
    EXPECT_EQ((u32)MfRules_HasFairyTypes(), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_HasInfiniteTms(), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_IsNuzlocke(), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_IsRandomizerActive(), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_GetMonotype(), 31u);
    EXPECT_EQ((u32)MfRules_IsMonotypeActive(), (u32)FALSE);
    EXPECT_EQ(MfRules_GetRandomizerSeed(), 0u);

    // Restore for later tests in the same process.
    save->version = MF_RULES_VERSION;
}

TEST("MF: rules GetBool covers every bool from save")
{
    LoadPatternIntoSave();

    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RULES_LOCKED), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_INFINITE_TMS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_SURVIVE_POISON), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_SYNCHRONIZE), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MINTS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MODERN_SITRUS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MODERN_TYPES), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_FAIRY_TYPES), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MODERN_STATS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_STURDY), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MODERN_MOVES), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_LEGENDARY_ABILITIES), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NEW_LEGENDARIES), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_TYPE_EFFECTIVENESS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_WILD_ITEM_DROPS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_EASIER_FEEBAS), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RTC_TYPE), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_SHINY_COLORS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_WONDER_TRADE), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_UNLIMITED_WONDER_TRADE), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_FRONTIER_BANS), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_STARTER), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_WILD), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_TRAINER), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_STATIC), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_SIMILAR), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_MAP_BASED), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_INCLUDE_LEGENDARIES), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_TYPE), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_MOVES), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_ABILITIES), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_EVOLUTION), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_EVOLUTION_METHODS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_TYPE_EFFECTIVENESS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_ITEMS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_CHAOS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_HARDCORE), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_EASY), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_SPECIES_CLAUSE), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_SHINY_CLAUSE), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_NICKNAMING), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_DELETION), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NO_ITEM_PLAYER), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NO_ITEM_TRAINER), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NO_EVS), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_LOCK_DIFFICULTY), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_ESCAPE_ROPE_DIG), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_HARD_EXP), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_LESS_ESCAPES), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MIRROR), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MIRROR_THIEF), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NO_PC_HEAL), (u32)TRUE);
}

TEST("MF: rules GetBool null path matches Phase 1 for every bool")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    LoadPatternIntoSave();
    save->version = 0;

    // Explicit expected vector from gMfRulesPhase1Defaults (not via GetBool).
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RULES_LOCKED), (u32)gMfRulesPhase1Defaults.rulesLocked);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_INFINITE_TMS), (u32)gMfRulesPhase1Defaults.infiniteTms);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_SURVIVE_POISON), (u32)gMfRulesPhase1Defaults.survivePoison);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_SYNCHRONIZE), (u32)gMfRulesPhase1Defaults.synchronize);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MINTS), (u32)gMfRulesPhase1Defaults.mints);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MODERN_SITRUS), (u32)gMfRulesPhase1Defaults.modernSitrus);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MODERN_TYPES), (u32)gMfRulesPhase1Defaults.modernTypes);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_FAIRY_TYPES), (u32)gMfRulesPhase1Defaults.fairyTypes);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MODERN_STATS), (u32)gMfRulesPhase1Defaults.modernStats);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_STURDY), (u32)gMfRulesPhase1Defaults.sturdy);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MODERN_MOVES), (u32)gMfRulesPhase1Defaults.modernMoves);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_LEGENDARY_ABILITIES), (u32)gMfRulesPhase1Defaults.legendaryAbilities);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NEW_LEGENDARIES), (u32)gMfRulesPhase1Defaults.newLegendaries);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_TYPE_EFFECTIVENESS), (u32)gMfRulesPhase1Defaults.typeEffectiveness);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_WILD_ITEM_DROPS), (u32)gMfRulesPhase1Defaults.wildItemDrops);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_EASIER_FEEBAS), (u32)gMfRulesPhase1Defaults.easierFeebas);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RTC_TYPE), (u32)gMfRulesPhase1Defaults.rtcType);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_SHINY_COLORS), (u32)gMfRulesPhase1Defaults.shinyColors);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_WONDER_TRADE), (u32)gMfRulesPhase1Defaults.wonderTrade);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_UNLIMITED_WONDER_TRADE), (u32)gMfRulesPhase1Defaults.unlimitedWonderTrade);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_FRONTIER_BANS), (u32)gMfRulesPhase1Defaults.frontierBans);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_STARTER), (u32)gMfRulesPhase1Defaults.randomStarter);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_WILD), (u32)gMfRulesPhase1Defaults.randomWild);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_TRAINER), (u32)gMfRulesPhase1Defaults.randomTrainer);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_STATIC), (u32)gMfRulesPhase1Defaults.randomStatic);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_SIMILAR), (u32)gMfRulesPhase1Defaults.randomSimilar);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_MAP_BASED), (u32)gMfRulesPhase1Defaults.randomMapBased);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_INCLUDE_LEGENDARIES), (u32)gMfRulesPhase1Defaults.randomIncludeLegendaries);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_TYPE), (u32)gMfRulesPhase1Defaults.randomType);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_MOVES), (u32)gMfRulesPhase1Defaults.randomMoves);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_ABILITIES), (u32)gMfRulesPhase1Defaults.randomAbilities);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_EVOLUTION), (u32)gMfRulesPhase1Defaults.randomEvolution);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_EVOLUTION_METHODS), (u32)gMfRulesPhase1Defaults.randomEvolutionMethods);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_TYPE_EFFECTIVENESS), (u32)gMfRulesPhase1Defaults.randomTypeEffectiveness);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_ITEMS), (u32)gMfRulesPhase1Defaults.randomItems);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_RANDOM_CHAOS), (u32)gMfRulesPhase1Defaults.randomChaos);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE), (u32)gMfRulesPhase1Defaults.nuzlocke);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_HARDCORE), (u32)gMfRulesPhase1Defaults.nuzlockeHardcore);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_EASY), (u32)gMfRulesPhase1Defaults.nuzlockeEasy);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_SPECIES_CLAUSE), (u32)gMfRulesPhase1Defaults.nuzlockeSpeciesClause);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_SHINY_CLAUSE), (u32)gMfRulesPhase1Defaults.nuzlockeShinyClause);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_NICKNAMING), (u32)gMfRulesPhase1Defaults.nuzlockeNicknaming);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE_DELETION), (u32)gMfRulesPhase1Defaults.nuzlockeDeletion);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NO_ITEM_PLAYER), (u32)gMfRulesPhase1Defaults.noItemPlayer);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NO_ITEM_TRAINER), (u32)gMfRulesPhase1Defaults.noItemTrainer);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NO_EVS), (u32)gMfRulesPhase1Defaults.noEvs);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_LOCK_DIFFICULTY), (u32)gMfRulesPhase1Defaults.lockDifficulty);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_ESCAPE_ROPE_DIG), (u32)gMfRulesPhase1Defaults.escapeRopeDig);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_HARD_EXP), (u32)gMfRulesPhase1Defaults.hardExp);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_LESS_ESCAPES), (u32)gMfRulesPhase1Defaults.lessEscapes);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MIRROR), (u32)gMfRulesPhase1Defaults.mirror);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_MIRROR_THIEF), (u32)gMfRulesPhase1Defaults.mirrorThief);
    EXPECT_EQ((u32)MfRules_GetBool(MF_RULE_BOOL_NO_PC_HEAL), (u32)gMfRulesPhase1Defaults.noPcHeal);

    save->version = MF_RULES_VERSION;
}

TEST("MF: rules GetValue covers every multi-value from save")
{
    LoadPatternIntoSave();

    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_GAMEMODE_PRESET), (u32)MF_GAMEMODE_MODERN);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_ALTERNATE_SPAWNS), 2u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_SHINY_CHANCE), 9u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_PARTY_LIMIT), 3u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_LEVEL_CAP), 2u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_EXP_MULTIPLIER), 2u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_SCALING_IVS), 2u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_SCALING_EVS), 3u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_MAX_PARTY_IVS), 2u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_POKECENTER_LIMIT), 1u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_CATCH_RATE), 5u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_EVO_LIMIT), 2u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_BASE_STAT_EQUALIZER), 3u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_MONOTYPE), 12u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_EXPENSIVE_SHOPS), 4u);
}

TEST("MF: rules GetValue null path matches Phase 1 defaults")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    LoadPatternIntoSave();
    save->version = 0;

    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_GAMEMODE_PRESET), (u32)MF_GAMEMODE_MODERN);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_ALTERNATE_SPAWNS), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_SHINY_CHANCE), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_PARTY_LIMIT), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_LEVEL_CAP), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_EXP_MULTIPLIER), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_SCALING_IVS), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_SCALING_EVS), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_MAX_PARTY_IVS), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_POKECENTER_LIMIT), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_CATCH_RATE), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_EVO_LIMIT), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_BASE_STAT_EQUALIZER), 0u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_MONOTYPE), 31u);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_EXPENSIVE_SHOPS), 0u);

    save->version = MF_RULES_VERSION;
}

TEST("MF: rules typed helpers agree with GetBool/GetValue")
{
    LoadPatternIntoSave();

    EXPECT_EQ((u32)MfRules_AreRulesLocked(), (u32)MfRules_GetBool(MF_RULE_BOOL_RULES_LOCKED));
    EXPECT_EQ((u32)MfRules_HasInfiniteTms(), (u32)MfRules_GetBool(MF_RULE_BOOL_INFINITE_TMS));
    EXPECT_EQ((u32)MfRules_HasFairyTypes(), (u32)MfRules_GetBool(MF_RULE_BOOL_FAIRY_TYPES));
    EXPECT_EQ((u32)MfRules_IsNuzlocke(), (u32)MfRules_GetBool(MF_RULE_BOOL_NUZLOCKE));
    EXPECT_EQ((u32)MfRules_GetShinyChance(), (u32)MfRules_GetValue(MF_RULE_VAL_SHINY_CHANCE));
    EXPECT_EQ((u32)MfRules_GetPartyLimit(), (u32)MfRules_GetValue(MF_RULE_VAL_PARTY_LIMIT));
    EXPECT_EQ((u32)MfRules_GetMonotype(), (u32)MfRules_GetValue(MF_RULE_VAL_MONOTYPE));
    EXPECT_EQ((u32)MfRules_GetMaxPartySize(), 3u);
}

TEST("MF: rules empty valid save reads Classic-like zeros")
{
    MfRules_ResetToEmpty(MfRules_GetSaveRules());

    EXPECT_EQ(MfRules_GetActiveRules(), MfRules_GetSaveRules());
    EXPECT_EQ((u32)MfRules_HasFairyTypes(), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_HasInfiniteTms(), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_IsNuzlocke(), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_GetMaxPartySize(), 6u);
    EXPECT_EQ((u32)MfRules_GetMonotype(), 31u);
    EXPECT_EQ((u32)MfRules_IsMonotypeActive(), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_IsRandomizerActive(), (u32)FALSE);
}

static void ExpectClassicGamemode(const struct ModernRules *r)
{
    EXPECT_EQ((u32)r->gamemodePreset, (u32)MF_GAMEMODE_CLASSIC);
    EXPECT_EQ((u32)r->alternateSpawns, 0u);
    EXPECT_EQ((u32)r->infiniteTms, (u32)FALSE);
    EXPECT_EQ((u32)r->survivePoison, (u32)FALSE);
    EXPECT_EQ((u32)r->synchronize, (u32)FALSE);
    EXPECT_EQ((u32)r->mints, (u32)FALSE);
    EXPECT_EQ((u32)r->modernSitrus, (u32)FALSE);
    EXPECT_EQ((u32)r->modernTypes, (u32)FALSE);
    EXPECT_EQ((u32)r->fairyTypes, (u32)FALSE);
    EXPECT_EQ((u32)r->modernStats, (u32)FALSE);
    EXPECT_EQ((u32)r->sturdy, (u32)FALSE);
    EXPECT_EQ((u32)r->modernMoves, (u32)FALSE);
    EXPECT_EQ((u32)r->legendaryAbilities, (u32)FALSE);
    EXPECT_EQ((u32)r->newLegendaries, (u32)FALSE);
    EXPECT_EQ((u32)r->typeEffectiveness, (u32)FALSE);
}

static void ExpectModernGamemode(const struct ModernRules *r)
{
    EXPECT_EQ((u32)r->gamemodePreset, (u32)MF_GAMEMODE_MODERN);
    EXPECT_EQ((u32)r->alternateSpawns, 1u);
    EXPECT_EQ((u32)r->infiniteTms, (u32)TRUE);
    EXPECT_EQ((u32)r->survivePoison, (u32)TRUE);
    EXPECT_EQ((u32)r->synchronize, (u32)TRUE);
    EXPECT_EQ((u32)r->mints, (u32)TRUE);
    EXPECT_EQ((u32)r->modernSitrus, (u32)TRUE);
    EXPECT_EQ((u32)r->modernTypes, (u32)TRUE);
    EXPECT_EQ((u32)r->fairyTypes, (u32)TRUE);
    EXPECT_EQ((u32)r->modernStats, (u32)TRUE);
    EXPECT_EQ((u32)r->sturdy, (u32)TRUE);
    EXPECT_EQ((u32)r->modernMoves, (u32)TRUE);
    EXPECT_EQ((u32)r->legendaryAbilities, (u32)TRUE);
    EXPECT_EQ((u32)r->newLegendaries, (u32)FALSE); // FR deviation from ME
    EXPECT_EQ((u32)r->typeEffectiveness, (u32)TRUE);
}

static void ExpectDevDefaultNonGamemode(const struct ModernRules *r)
{
    EXPECT_EQ(r->version, MF_RULES_VERSION);

    EXPECT_EQ((u32)r->shinyChance, (u32)MF_TX_FEATURES_SHINY_CHANCE);
    EXPECT_EQ((u32)r->wildItemDrops, (u32)MF_TX_FEATURES_ITEM_DROP);
    // Similar/MapBased stay off until the S25 master is enabled (seeded from TX_*).
    EXPECT_EQ((u32)r->randomSimilar, (u32)FALSE);
    EXPECT_EQ((u32)r->randomMapBased, (u32)FALSE);
    EXPECT_EQ((u32)r->randomizerEnabled, (u32)FALSE);
    EXPECT_EQ((u32)r->randomWild, (u32)MF_TX_RANDOM_WILD);
    EXPECT_EQ((u32)r->nuzlocke, (u32)MF_TX_NUZLOCKE);
    EXPECT_EQ((u32)r->nuzlockeSpeciesClause, (u32)MF_TX_NUZLOCKE_SPECIES_CLAUSE);
    EXPECT_EQ((u32)r->nuzlockeShinyClause, (u32)MF_TX_NUZLOCKE_SHINY_CLAUSE);
    EXPECT_EQ((u32)r->nuzlockeNicknaming, (u32)MF_TX_NUZLOCKE_NICKNAMING);
    EXPECT_EQ((u32)r->partyLimit, (u32)MF_TX_DIFFICULTY_PARTY_LIMIT);
    EXPECT_EQ((u32)r->monotype, (u32)MF_TX_CHALLENGE_TYPE);
    EXPECT_EQ(r->nuzlockeEncounterFlags[0], 0u);
}

TEST("MF: rules Classic preset gamemode vector")
{
    struct ModernRules rules;

    MfRules_ApplyDevDefaults(&rules);
    MfRules_ApplyGamemodePreset(&rules, MF_GAMEMODE_CLASSIC);

    ExpectClassicGamemode(&rules);
    ExpectDevDefaultNonGamemode(&rules);
    EXPECT_EQ(rules.randomizerSeed, 0u);
    EXPECT_EQ((u32)rules.rulesLocked, (u32)FALSE);
}

TEST("MF: rules Modern preset gamemode vector")
{
    struct ModernRules rules;

    MfRules_ApplyDevDefaults(&rules);
    MfRules_ApplyGamemodePreset(&rules, MF_GAMEMODE_MODERN);

    ExpectModernGamemode(&rules);
    ExpectDevDefaultNonGamemode(&rules);
    EXPECT_EQ(rules.randomizerSeed, 0u);
    EXPECT_EQ((u32)rules.rulesLocked, (u32)FALSE);
}

TEST("MF: rules Custom preset keeps MF_TX_ gamemode seed")
{
    struct ModernRules rules;

    MfRules_ApplyDevDefaults(&rules);
    MfRules_ApplyGamemodePreset(&rules, MF_GAMEMODE_CUSTOM);

    EXPECT_EQ((u32)rules.gamemodePreset, (u32)MF_GAMEMODE_CUSTOM);
    EXPECT_EQ((u32)rules.infiniteTms, (u32)MF_TX_MODE_INFINITE_TMS);
    EXPECT_EQ((u32)rules.fairyTypes, (u32)MF_TX_MODE_FAIRY_TYPES);
    EXPECT_EQ((u32)rules.modernMoves, (u32)MF_TX_MODE_MODERN_MOVES);
    EXPECT_EQ((u32)rules.alternateSpawns, (u32)MF_TX_MODE_ALTERNATE_SPAWNS);
    EXPECT_EQ((u32)rules.newLegendaries, (u32)MF_TX_MODE_NEW_LEGENDARIES);
    ExpectDevDefaultNonGamemode(&rules);
    EXPECT_EQ(rules.randomizerSeed, 0u);
    EXPECT_EQ((u32)rules.rulesLocked, (u32)FALSE);
}

TEST("MF: rules InitNewGame writes default preset into save")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    // Dirty the save so InitNewGame must fully replace it.
    memset(save, 0xA5, sizeof(*save));
    MfRules_DebugSetUnlockOverride(FALSE);
    MfRules_InitNewGame();

#if MF_RULES_ENGINE
    EXPECT_EQ(save->version, MF_RULES_VERSION);
#if MF_DEFAULT_GAMEMODE_PRESET == 0
    ExpectClassicGamemode(save);
#elif MF_DEFAULT_GAMEMODE_PRESET == 1
    ExpectModernGamemode(save);
#else
    EXPECT_EQ((u32)save->gamemodePreset, (u32)MF_GAMEMODE_CUSTOM);
    EXPECT_EQ((u32)save->infiniteTms, (u32)MF_TX_MODE_INFINITE_TMS);
#endif
    ExpectDevDefaultNonGamemode(save);
    // S16: InitNewGame assigns a non-zero per-save randomizer seed.
    EXPECT_NE(save->randomizerSeed, 0u);
    // S19: leave unlocked for the new-game menu; S26 SAVE commits.
    EXPECT_EQ((u32)save->rulesLocked, (u32)FALSE);
    EXPECT_EQ((u32)MfRules_AreRulesLocked(), (u32)FALSE);
    EXPECT_EQ(MfRules_GetActiveRules(), save);
#else
    // Engine off: InitNewGame is a no-op; accessors still use Phase 1 defaults.
    EXPECT_EQ(MfRules_GetActiveRules(), &gMfRulesPhase1Defaults);
#endif
}

TEST("MF: rules Classic then Custom leaves Classic gamemode editable")
{
    struct ModernRules rules;

    MfRules_ApplyDevDefaults(&rules);
    MfRules_ApplyGamemodePreset(&rules, MF_GAMEMODE_CLASSIC);
    MfRules_ApplyGamemodePreset(&rules, MF_GAMEMODE_CUSTOM);

    EXPECT_EQ((u32)rules.gamemodePreset, (u32)MF_GAMEMODE_CUSTOM);
    EXPECT_EQ((u32)rules.fairyTypes, (u32)FALSE);
    EXPECT_EQ((u32)rules.infiniteTms, (u32)FALSE);
    rules.fairyTypes = TRUE;
    EXPECT_EQ((u32)rules.fairyTypes, (u32)TRUE);
}

TEST("MF: rules TrySetValue GAMEMODE_PRESET applies Classic/Modern vectors")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_DebugSetUnlockOverride(FALSE);
    MfRules_ApplyDevDefaults(save);
    MfRules_ApplyGamemodePreset(save, MF_GAMEMODE_CUSTOM);
    save->fairyTypes = TRUE;
    save->infiniteTms = TRUE;

    EXPECT_EQ((u32)MfRules_TrySetValue(MF_RULE_VAL_GAMEMODE_PRESET, MF_GAMEMODE_CLASSIC), (u32)TRUE);
    ExpectClassicGamemode(save);

    EXPECT_EQ((u32)MfRules_TrySetValue(MF_RULE_VAL_GAMEMODE_PRESET, MF_GAMEMODE_MODERN), (u32)TRUE);
    ExpectModernGamemode(save);

    EXPECT_EQ((u32)MfRules_TrySetValue(MF_RULE_VAL_GAMEMODE_PRESET, MF_GAMEMODE_CUSTOM), (u32)TRUE);
    EXPECT_EQ((u32)save->gamemodePreset, (u32)MF_GAMEMODE_CUSTOM);
    EXPECT_EQ((u32)save->fairyTypes, (u32)TRUE);
    EXPECT_EQ((u32)save->infiniteTms, (u32)TRUE);
    EXPECT_EQ((u32)save->alternateSpawns, 1u);
}

TEST("MF: rules lock blocks core writes after commit")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_DebugSetUnlockOverride(FALSE);
    MfRules_ApplyDevDefaults(save);
    MfRules_ApplyGamemodePreset(save, MF_GAMEMODE_MODERN);
    EXPECT_EQ((u32)save->rulesLocked, (u32)FALSE);
    EXPECT_EQ((u32)MfRules_CanEdit(MF_RULE_EDIT_CORE), (u32)TRUE);

    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_FAIRY_TYPES, FALSE), (u32)TRUE);
    EXPECT_EQ((u32)save->fairyTypes, (u32)FALSE);

    MfRules_CommitAndLock();
    EXPECT_EQ((u32)MfRules_AreRulesLocked(), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_CanEdit(MF_RULE_EDIT_CORE), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_CanEdit(MF_RULE_EDIT_META), (u32)FALSE);

    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_FAIRY_TYPES, TRUE), (u32)FALSE);
    EXPECT_EQ((u32)save->fairyTypes, (u32)FALSE);
    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_NUZLOCKE, TRUE), (u32)FALSE);
    EXPECT_EQ((u32)save->nuzlocke, (u32)FALSE);
    EXPECT_EQ((u32)MfRules_TrySetValue(MF_RULE_VAL_SHINY_CHANCE, 5), (u32)FALSE);
    EXPECT_EQ((u32)save->shinyChance, (u32)MF_TX_FEATURES_SHINY_CHANCE);
    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_LOCK_DIFFICULTY, TRUE), (u32)FALSE);
}

TEST("MF: rules lock allows difficulty writes when LOCK DIFFICULTY off")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_DebugSetUnlockOverride(FALSE);
    MfRules_ApplyDevDefaults(save);
    save->lockDifficulty = FALSE;
    MfRules_CommitAndLock();

    EXPECT_EQ((u32)MfRules_CanEdit(MF_RULE_EDIT_DIFFICULTY), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_TrySetValue(MF_RULE_VAL_PARTY_LIMIT, 2), (u32)TRUE);
    EXPECT_EQ((u32)save->partyLimit, 2u);
    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_NO_ITEM_PLAYER, TRUE), (u32)TRUE);
    EXPECT_EQ((u32)save->noItemPlayer, (u32)TRUE);
    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_LESS_ESCAPES, TRUE), (u32)TRUE);
    EXPECT_EQ((u32)save->lessEscapes, (u32)TRUE);

    // Challenges / Features stay locked.
    EXPECT_EQ((u32)MfRules_TrySetValue(MF_RULE_VAL_POKECENTER_LIMIT, 1), (u32)FALSE);
    EXPECT_EQ((u32)save->pokeCenterLimit, 0u);
    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_WILD_ITEM_DROPS, TRUE), (u32)FALSE);
}

TEST("MF: rules lock blocks difficulty when LOCK DIFFICULTY on")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_DebugSetUnlockOverride(FALSE);
    MfRules_ApplyDevDefaults(save);
    save->lockDifficulty = TRUE;
    save->partyLimit = 0;
    MfRules_CommitAndLock();

    EXPECT_EQ((u32)MfRules_CanEdit(MF_RULE_EDIT_DIFFICULTY), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_TrySetValue(MF_RULE_VAL_PARTY_LIMIT, 3), (u32)FALSE);
    EXPECT_EQ((u32)save->partyLimit, 0u);
    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_HARD_EXP, TRUE), (u32)FALSE);
    EXPECT_EQ((u32)save->hardExp, (u32)FALSE);
}

TEST("MF: rules debug unlock override bypasses lock in non-release")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(save);
    save->fairyTypes = FALSE;
    MfRules_CommitAndLock();
    MfRules_DebugSetUnlockOverride(FALSE);

    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_FAIRY_TYPES, TRUE), (u32)FALSE);

#ifdef NDEBUG
    EXPECT_EQ((u32)MfRules_DebugSetUnlockOverride(TRUE), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_DebugHasUnlockOverride(), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_FAIRY_TYPES, TRUE), (u32)FALSE);
    EXPECT_EQ((u32)save->fairyTypes, (u32)FALSE);
#else
    EXPECT_EQ((u32)MfRules_DebugSetUnlockOverride(TRUE), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_DebugHasUnlockOverride(), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_CanEdit(MF_RULE_EDIT_CORE), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_FAIRY_TYPES, TRUE), (u32)TRUE);
    EXPECT_EQ((u32)save->fairyTypes, (u32)TRUE);
    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_LOCK_DIFFICULTY, TRUE), (u32)TRUE);
    EXPECT_EQ((u32)save->lockDifficulty, (u32)TRUE);
    MfRules_DebugSetUnlockOverride(FALSE);
    EXPECT_EQ((u32)MfRules_DebugHasUnlockOverride(), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_FAIRY_TYPES, FALSE), (u32)FALSE);
#endif
}

TEST("MF: rules TrySetValue NUZLOCKE_MODE packs bits and clause defaults")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_DebugSetUnlockOverride(FALSE);
    MfRules_ApplyDevDefaults(save);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_NUZLOCKE_MODE), (u32)MF_NUZLOCKE_OFF);
    EXPECT_EQ((u32)MfRules_NuzlockeSubOptionsActive(), (u32)FALSE);

    EXPECT_EQ((u32)MfRules_TrySetValue(MF_RULE_VAL_NUZLOCKE_MODE, MF_NUZLOCKE_EASY), (u32)TRUE);
    EXPECT_EQ((u32)save->nuzlockeEasy, (u32)TRUE);
    EXPECT_EQ((u32)save->nuzlocke, (u32)FALSE);
    EXPECT_EQ((u32)save->nuzlockeSpeciesClause, (u32)FALSE);
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_NUZLOCKE_MODE), (u32)MF_NUZLOCKE_EASY);
    EXPECT_EQ((u32)MfRules_NuzlockeSubOptionsActive(), (u32)FALSE);

    EXPECT_EQ((u32)MfRules_TrySetValue(MF_RULE_VAL_NUZLOCKE_MODE, MF_NUZLOCKE_NORMAL), (u32)TRUE);
    EXPECT_EQ((u32)save->nuzlocke, (u32)TRUE);
    EXPECT_EQ((u32)save->nuzlockeHardcore, (u32)FALSE);
    EXPECT_EQ((u32)save->nuzlockeEasy, (u32)FALSE);
    EXPECT_EQ((u32)save->nuzlockeSpeciesClause, (u32)MF_TX_NUZLOCKE_SPECIES_CLAUSE);
    EXPECT_EQ((u32)save->nuzlockeShinyClause, (u32)MF_TX_NUZLOCKE_SHINY_CLAUSE);
    EXPECT_EQ((u32)save->nuzlockeNicknaming, (u32)MF_TX_NUZLOCKE_NICKNAMING);
    EXPECT_EQ((u32)save->nuzlockeDeletion, (u32)MF_TX_NUZLOCKE_DELETION);
    EXPECT_EQ((u32)MfRules_NuzlockeSubOptionsActive(), (u32)TRUE);

    save->nuzlockeSpeciesClause = FALSE;
    EXPECT_EQ((u32)MfRules_TrySetValue(MF_RULE_VAL_NUZLOCKE_MODE, MF_NUZLOCKE_HARDCORE), (u32)TRUE);
    EXPECT_EQ((u32)save->nuzlockeHardcore, (u32)TRUE);
    EXPECT_EQ((u32)save->nuzlockeSpeciesClause, (u32)FALSE); // keep when already full
    EXPECT_EQ((u32)MfRules_GetValue(MF_RULE_VAL_NUZLOCKE_MODE), (u32)MF_NUZLOCKE_HARDCORE);

    EXPECT_EQ((u32)MfRules_TrySetValue(MF_RULE_VAL_NUZLOCKE_MODE, MF_NUZLOCKE_OFF), (u32)TRUE);
    EXPECT_EQ((u32)save->nuzlocke, (u32)FALSE);
    EXPECT_EQ((u32)save->nuzlockeHardcore, (u32)FALSE);
    EXPECT_EQ((u32)save->nuzlockeEasy, (u32)FALSE);
    EXPECT_EQ((u32)save->nuzlockeSpeciesClause, (u32)FALSE);
    EXPECT_EQ((u32)save->nuzlockeDeletion, (u32)FALSE);
}

TEST("MF: rules TrySetBool RANDOMIZER_ENABLED seeds and clears remaps")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_DebugSetUnlockOverride(FALSE);
    MfRules_ApplyDevDefaults(save);
    EXPECT_EQ((u32)MfRules_IsRandomizerEnabled(), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_IsRandomizerActive(), (u32)FALSE);
    EXPECT_EQ((u32)MfRules_RandomizerSpeciesActive(), (u32)FALSE);

    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_RANDOMIZER_ENABLED, TRUE), (u32)TRUE);
    EXPECT_EQ((u32)save->randomizerEnabled, (u32)TRUE);
    EXPECT_EQ((u32)save->randomSimilar, (u32)MF_TX_RANDOM_SIMILAR);
    EXPECT_EQ((u32)save->randomMapBased, (u32)MF_TX_RANDOM_MAP_BASED);
    EXPECT_EQ((u32)MfRules_IsRandomizerActive(), (u32)FALSE); // no remaps yet
    EXPECT_EQ((u32)MfRules_RandomizerChaosEditable(), (u32)FALSE);

    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_RANDOM_WILD, TRUE), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_IsRandomizerActive(), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_RandomizerSpeciesActive(), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_RandomizerBalancingEditable(), (u32)TRUE);
    EXPECT_EQ((u32)MfRules_RandomizerChaosEditable(), (u32)TRUE);

    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_RANDOM_CHAOS, TRUE), (u32)TRUE);
    EXPECT_EQ((u32)save->randomChaos, (u32)TRUE);
    EXPECT_EQ((u32)save->randomSimilar, (u32)FALSE);
    EXPECT_EQ((u32)MfRules_RandomizerBalancingEditable(), (u32)FALSE);

    EXPECT_EQ((u32)MfRules_TrySetBool(MF_RULE_BOOL_RANDOMIZER_ENABLED, FALSE), (u32)TRUE);
    EXPECT_EQ((u32)save->randomizerEnabled, (u32)FALSE);
    EXPECT_EQ((u32)save->randomWild, (u32)FALSE);
    EXPECT_EQ((u32)save->randomChaos, (u32)FALSE);
    EXPECT_EQ((u32)save->randomSimilar, (u32)FALSE);
    EXPECT_EQ((u32)save->randomMapBased, (u32)FALSE);
    EXPECT_EQ((u32)MfRules_IsRandomizerActive(), (u32)FALSE);
}

TEST("MF: rules debug reroll seed")
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(save);
    MfRules_CommitAndLock();
    MfRules_DebugSetUnlockOverride(FALSE);
    save->randomizerSeed = 0x11111111;

#ifdef NDEBUG
    EXPECT_EQ((u32)MfRules_DebugRerollSeed(), (u32)FALSE);
    EXPECT_EQ(save->randomizerSeed, 0x11111111u);
#else
    {
        u32 first;

        EXPECT_EQ((u32)MfRules_DebugRerollSeed(), (u32)TRUE);
        first = save->randomizerSeed;
        EXPECT(first != 0);
        EXPECT(first != 0x11111111u);
        EXPECT_EQ((u32)MfRules_DebugRerollSeed(), (u32)TRUE);
        EXPECT(save->randomizerSeed != 0);
        MfRules_DebugSetUnlockOverride(FALSE);
    }
#endif
}

TEST("MF: rules debug dump is callable")
{
    // Smoke: must not crash; under NDEBUG it is a no-op.
    MfRules_ApplyDevDefaults(MfRules_GetSaveRules());
    MfRules_DebugDump();
}
