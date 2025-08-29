#include "global.h"
#include "battle.h"
#include "battle_factory.h"
#include "battle_factory_screen.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "frontier_util.h"
#include "battle_tower.h"
#include "random.h"
#include "pokedex.h"
#include "constants/battle_ai.h"
#include "constants/battle_factory.h"

#include "fieldmap.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "main.h"
#include "palette.h"
#include "script_pokemon_util.h"
#include "starter_choose.h"
#include "task.h"
#include "constants/battle_frontier.h"
#include "constants/battle_frontier_mons.h"
#include "constants/battle_tent.h"
#include "constants/frontier_util.h"
#include "constants/layouts.h"
#include "constants/trainers.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/factory_pools.h"
#include "constants/rgb.h"
#include "data/battle_frontier/facility_classes_types.h"

static bool8 sPerformedRentalSwap;
static struct Pokemon sFactoryRewardBuffer;
extern const u8 BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardResumeScript[];
extern const u8 BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardSaveAndExitScript[];
static bool8 sFactoryPoolsReady = FALSE;

static void InitFactoryChallenge(void);
static void GetBattleFactoryData(void);
static void SetBattleFactoryData(void);
static void SaveFactoryChallenge(void);
static void FactoryDummy1(void);
static void FactoryDummy2(void);
static void SelectInitialRentalMons(void);
static void SwapRentalMons(void);
static void SetPerformedRentalSwap(void);
static void SetRentalsToOpponentParty(void);
static void SetPlayerAndOpponentParties(void);
static void SetOpponentGfxVar(void);
static void GenerateOpponentMons(void);
static void GenerateInitialRentalMons(void);
static void GetOpponentMostCommonMonType(void);
static void GetOpponentBattleStyle(void);
static void RestorePlayerPartyHeldItems(void);
static u16 GetFactoryMonId(u8 lvlMode, u8 challengeNum, bool8 useBetterRange);
static u8 GetMoveBattleStyle(u16 move);
void DebugAction_FactoryWinChallenge(void);
const u8 *GetFacilityClassTypeWhitelist(u8 facilityClass, u8 *count);
static void GetOpponentFrontierClass();
void GetOpponentFrontierClassInternal(u8 trainerId);
static void SelectRewardMonFromParty();
static void GiveRewardMonFromParty();
static void CB2_SelectReward();
static void CB2_GiveReward();

// Number of moves needed on the team to be considered using a certain battle style
static const u8 sRequiredMoveCounts[FACTORY_NUM_STYLES - 1] = {
    [FACTORY_STYLE_PREPARATION - 1]   = 3,
    [FACTORY_STYLE_SLOW_STEADY - 1]   = 3,
    [FACTORY_STYLE_ENDURANCE - 1]     = 3,
    [FACTORY_STYLE_HIGH_RISK - 1]     = 2,
    [FACTORY_STYLE_WEAKENING - 1]     = 2,
    [FACTORY_STYLE_UNPREDICTABLE - 1] = 2,
    [FACTORY_STYLE_WEATHER - 1]       = 2
};
static const u16 sMoves_TotalPreparation[] =
{
    MOVE_SWORDS_DANCE, MOVE_GROWTH, MOVE_MEDITATE, MOVE_AGILITY, MOVE_DOUBLE_TEAM, MOVE_HARDEN,
    MOVE_MINIMIZE, MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_BARRIER, MOVE_FOCUS_ENERGY, MOVE_AMNESIA,
    MOVE_ACID_ARMOR, MOVE_SHARPEN, MOVE_CONVERSION, MOVE_CONVERSION_2, MOVE_BELLY_DRUM, MOVE_PSYCH_UP,
    MOVE_CHARGE, MOVE_SNATCH, MOVE_TAIL_GLOW, MOVE_COSMIC_POWER, MOVE_IRON_DEFENSE, MOVE_HOWL, MOVE_BULK_UP, MOVE_CALM_MIND, MOVE_DRAGON_DANCE,
    MOVE_NONE
};

static const u16 sMoves_ImpossibleToPredict[] =
{
    MOVE_MIMIC, MOVE_METRONOME, MOVE_MIRROR_MOVE, MOVE_TRANSFORM, MOVE_SUBSTITUTE, MOVE_SKETCH, MOVE_CURSE,
    MOVE_PRESENT, MOVE_FOLLOW_ME, MOVE_TRICK, MOVE_ROLE_PLAY, MOVE_ASSIST, MOVE_SKILL_SWAP, MOVE_CAMOUFLAGE,
    MOVE_NONE
};

static const u16 sMoves_WeakeningTheFoe[] =
{
    MOVE_SAND_ATTACK, MOVE_TAIL_WHIP, MOVE_LEER, MOVE_GROWL, MOVE_STRING_SHOT, MOVE_SCREECH, MOVE_SMOKESCREEN, MOVE_KINESIS,
    MOVE_FLASH, MOVE_COTTON_SPORE, MOVE_SPITE, MOVE_SCARY_FACE, MOVE_CHARM, MOVE_KNOCK_OFF, MOVE_SWEET_SCENT, MOVE_FEATHER_DANCE,
    MOVE_FAKE_TEARS, MOVE_METAL_SOUND, MOVE_TICKLE,
    MOVE_NONE
};

static const u16 sMoves_HighRiskHighReturn[] =
{
    MOVE_GUILLOTINE, MOVE_HORN_DRILL, MOVE_DOUBLE_EDGE, MOVE_HYPER_BEAM, MOVE_COUNTER, MOVE_FISSURE,
    MOVE_BIDE, MOVE_SELF_DESTRUCT, MOVE_SKY_ATTACK, MOVE_EXPLOSION, MOVE_FLAIL, MOVE_REVERSAL, MOVE_DESTINY_BOND,
    MOVE_PERISH_SONG, MOVE_PAIN_SPLIT, MOVE_MIRROR_COAT, MOVE_MEMENTO, MOVE_GRUDGE, MOVE_FACADE, MOVE_FOCUS_PUNCH,
    MOVE_BLAST_BURN, MOVE_HYDRO_CANNON, MOVE_OVERHEAT, MOVE_FRENZY_PLANT, MOVE_PSYCHO_BOOST, MOVE_VOLT_TACKLE,
    MOVE_NONE
};

static const u16 sMoves_Endurance[] =
{
    MOVE_MIST, MOVE_RECOVER, MOVE_LIGHT_SCREEN, MOVE_HAZE, MOVE_REFLECT, MOVE_SOFT_BOILED, MOVE_REST, MOVE_PROTECT,
    MOVE_DETECT, MOVE_ENDURE, MOVE_MILK_DRINK, MOVE_HEAL_BELL, MOVE_SAFEGUARD, MOVE_BATON_PASS, MOVE_MORNING_SUN,
    MOVE_SYNTHESIS, MOVE_MOONLIGHT, MOVE_SWALLOW, MOVE_WISH, MOVE_INGRAIN, MOVE_MAGIC_COAT, MOVE_RECYCLE, MOVE_REFRESH,
    MOVE_MUD_SPORT, MOVE_SLACK_OFF, MOVE_AROMATHERAPY, MOVE_WATER_SPORT,
    MOVE_NONE
};

static const u16 sMoves_SlowAndSteady[] =
{
    MOVE_SING, MOVE_SUPERSONIC, MOVE_DISABLE, MOVE_LEECH_SEED, MOVE_POISON_POWDER, MOVE_STUN_SPORE, MOVE_SLEEP_POWDER,
    MOVE_THUNDER_WAVE, MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_CONFUSE_RAY, MOVE_GLARE, MOVE_POISON_GAS, MOVE_LOVELY_KISS, MOVE_SPORE,
    MOVE_SPIDER_WEB, MOVE_SWEET_KISS, MOVE_SPIKES, MOVE_SWAGGER, MOVE_MEAN_LOOK, MOVE_ATTRACT, MOVE_ENCORE, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_WILL_O_WISP, MOVE_TAUNT, MOVE_YAWN, MOVE_IMPRISON, MOVE_SNATCH, MOVE_TEETER_DANCE, MOVE_GRASS_WHISTLE, MOVE_BLOCK,
    MOVE_NONE
};

static const u16 sMoves_DependsOnTheBattlesFlow[] =
{
    MOVE_SANDSTORM, MOVE_RAIN_DANCE, MOVE_SUNNY_DAY, MOVE_HAIL, MOVE_WEATHER_BALL,
    MOVE_NONE
};

// Excludes FACTORY_STYLE_NONE
static const u16 *const sMoveStyles[FACTORY_NUM_STYLES - 1] =
{
    [FACTORY_STYLE_PREPARATION - 1]   = sMoves_TotalPreparation,
    [FACTORY_STYLE_SLOW_STEADY - 1]   = sMoves_SlowAndSteady,
    [FACTORY_STYLE_ENDURANCE - 1]     = sMoves_Endurance,
    [FACTORY_STYLE_HIGH_RISK - 1]     = sMoves_HighRiskHighReturn,
    [FACTORY_STYLE_WEAKENING - 1]     = sMoves_WeakeningTheFoe,
    [FACTORY_STYLE_UNPREDICTABLE - 1] = sMoves_ImpossibleToPredict,
    [FACTORY_STYLE_WEATHER - 1]       = sMoves_DependsOnTheBattlesFlow,
};

static void (*const sBattleFactoryFunctions[])(void) =
{
    [BATTLE_FACTORY_FUNC_INIT]                   = InitFactoryChallenge,
    [BATTLE_FACTORY_FUNC_GET_DATA]               = GetBattleFactoryData,
    [BATTLE_FACTORY_FUNC_SET_DATA]               = SetBattleFactoryData,
    [BATTLE_FACTORY_FUNC_SAVE]                   = SaveFactoryChallenge,
    [BATTLE_FACTORY_FUNC_NULL]                   = FactoryDummy1,
    [BATTLE_FACTORY_FUNC_NULL2]                  = FactoryDummy2,
    [BATTLE_FACTORY_FUNC_SELECT_RENT_MONS]       = SelectInitialRentalMons,
    [BATTLE_FACTORY_FUNC_SWAP_RENT_MONS]         = SwapRentalMons,
    [BATTLE_FACTORY_FUNC_SET_SWAPPED]            = SetPerformedRentalSwap,
    [BATTLE_FACTORY_FUNC_SET_OPPONENT_MONS]      = SetRentalsToOpponentParty,
    [BATTLE_FACTORY_FUNC_SET_PARTIES]            = SetPlayerAndOpponentParties,
    [BATTLE_FACTORY_FUNC_SET_OPPONENT_GFX]       = SetOpponentGfxVar,
    [BATTLE_FACTORY_FUNC_GENERATE_OPPONENT_MONS] = GenerateOpponentMons,
    [BATTLE_FACTORY_FUNC_GENERATE_RENTAL_MONS]   = GenerateInitialRentalMons,
    [BATTLE_FACTORY_FUNC_GET_OPPONENT_MON_TYPE]  = GetOpponentMostCommonMonType,
    [BATTLE_FACTORY_FUNC_GET_OPPONENT_STYLE]     = GetOpponentBattleStyle,
    [BATTLE_FACTORY_FUNC_RESET_HELD_ITEMS]       = RestorePlayerPartyHeldItems,
    [BATTLE_FACTORY_FUNC_GET_OPPONENT_CLASS]     = GetOpponentFrontierClass,
    [BATTLE_FACTORY_FUNC_SELECT_REWARD_MON]      = SelectRewardMonFromParty,
    [BATTLE_FACTORY_FUNC_GIVE_REWARD_MON]        = GiveRewardMonFromParty
};

static const u32 sWinStreakFlags[][2] =
{
    {STREAK_FACTORY_SINGLES_50, STREAK_FACTORY_SINGLES_OPEN},
    {STREAK_FACTORY_DOUBLES_50, STREAK_FACTORY_DOUBLES_OPEN},
};

static const u32 sWinStreakMasks[][2] =
{
    {~(STREAK_FACTORY_SINGLES_50), ~(STREAK_FACTORY_SINGLES_OPEN)},
    {~(STREAK_FACTORY_DOUBLES_50), ~(STREAK_FACTORY_DOUBLES_OPEN)},
};

static const u8 sFixedIVTable[][2] =
{
    {3, 6},
    {6, 9},
    {9, 12},
    {12, 15},
    {15, 18},
    {21, 31},
    {31, 31},
    {31, 31},
};

// code
static void EnsureFactoryPoolsReady(void)
{
    if (!sFactoryPoolsReady)
    {
        InitFactoryRankPools();
        sFactoryPoolsReady = TRUE;
    }
}

void CallBattleFactoryFunction(void)
{
    DebugPrintf("🚩 CallBattleFactoryFunction: index = %d", gSpecialVar_0x8004);
    sBattleFactoryFunctions[gSpecialVar_0x8004]();
}

static void InitFactoryChallenge(void) {
    DebugPrintf("Battle Factory init");
    u8 i;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    EnsureFactoryPoolsReady();

    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;
    if (!(gSaveBlock2Ptr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]))
    {
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = 0;
        gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = 0;
    }

    sPerformedRentalSwap = FALSE;
    for (i = 0; i < ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); i++)
        gSaveBlock2Ptr->frontier.rentalMons[i].monId = 0xFFFF;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        gFrontierTempParty[i] = 0xFFFF;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
    TRAINER_BATTLE_PARAM.opponentA = 0;
}

static void GetBattleFactoryData(void) {
    DebugPrintf("GetBattleFactoryData");

    int lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    int battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case FACTORY_DATA_WIN_STREAK:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
        break;
    case FACTORY_DATA_WIN_STREAK_ACTIVE:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]) != 0);
        break;
    case FACTORY_DATA_WIN_STREAK_SWAPS:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
        break;
    }
}

static void SetBattleFactoryData(void) {
    DebugPrintf("SetBattleFactoryData");

    int lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    int battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case FACTORY_DATA_WIN_STREAK:
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case FACTORY_DATA_WIN_STREAK_ACTIVE:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.winStreakActiveFlags &= sWinStreakMasks[battleMode][lvlMode];
        break;
    case FACTORY_DATA_WIN_STREAK_SWAPS:
        if (sPerformedRentalSwap == TRUE)
        {
            gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = gSpecialVar_0x8006;
            sPerformedRentalSwap = FALSE;
        }
        break;
    }
}

static void SaveFactoryChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void FactoryDummy1(void)
{

}

static void FactoryDummy2(void)
{

}

static void SelectInitialRentalMons(void) {
    DebugPrintf("SelectInitialRentalMons");
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

static void SwapRentalMons(void)
{
    DoBattleFactorySwapScreen();
}

static void SetPerformedRentalSwap(void)
{
    sPerformedRentalSwap = TRUE;
}

static void GenerateOpponentMons(void)
{
    int i, j, k;
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    int firstMonId = 0;
    u16 trainerId = 0;
    u8 facilityClass = 0;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    u32 challengeNum = winStreak / FRONTIER_STAGES_PER_CHALLENGE;
    gFacilityTrainers = gBattleFrontierTrainers;

    do
    {
        // Choose a random trainer, ensuring no repeats in this challenge
        trainerId = GetRandomScaledFrontierTrainerId(challengeNum, gSaveBlock2Ptr->frontier.curChallengeBattleNum);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    TRAINER_BATTLE_PARAM.opponentA = trainerId;
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < FRONTIER_STAGES_PER_CHALLENGE - 1)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = trainerId;

    facilityClass = gFacilityTrainers[trainerId].facilityClass;

    i = 0;

    u8 typeCount;
    const u8 *whitelist = GetFacilityClassTypeWhitelist(facilityClass, &typeCount);
    //
    // DebugPrintf("📋 Facility class: %d", facilityClass);
    // DebugPrintf("📦 Allowed types:");
    //
    // for (int t = 0; t < typeCount; t++)
    // {
    //     DebugPrintf(" - Type %d", whitelist[t]);
    // }
    while (i != FRONTIER_PARTY_SIZE)
    {
        u16 monId = GetFactoryMonId(lvlMode, challengeNum, FALSE);

        u16 speciesId = gFacilityTrainerMons[monId].species;
        u8 type1 = gSpeciesInfo[speciesId].types[0];
        u8 type2 = gSpeciesInfo[speciesId].types[1];


        bool8 matchesType = FALSE;
        for (int t = 0; t < typeCount; t++) {
            if (whitelist[t] == type1 || whitelist[t] == type2) {
                matchesType = TRUE;
                break;
            }
        }

        if (!matchesType)
            continue; // Doesn't fit this trainer's theme

        // Unown (FRONTIER_MON_UNOWN) is forbidden on opponent Factory teams.
        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;

        // Ensure none of the opponent's Pokémon are the same as the potential rental Pokémon for the player
        for (j = 0; j < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); j++)
        {
            if (gFacilityTrainerMons[monId].species == gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[j].monId].species)
                break;
        }
        if (j != (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons))
            continue;

        // Ensure this species hasn't already been chosen for the opponent
        for (k = firstMonId; k < firstMonId + i; k++)
        {
            if (species[k] == gFacilityTrainerMons[monId].species)
                break;
        }
        if (k != firstMonId + i)
            continue;

        // Ensure held items don't repeat on the opponent's team
        for (k = firstMonId; k < firstMonId + i; k++)
        {
            if (heldItems[k] != ITEM_NONE && heldItems[k] == gFacilityTrainerMons[monId].heldItem)
                break;
        }
        if (k != firstMonId + i)
            continue;

        // Successful selection
        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gFacilityTrainerMons[monId].heldItem;
        gFrontierTempParty[i] = monId;
        i++;
    }
}

static void SetOpponentGfxVar(void)
{
    SetBattleFacilityTrainerGfxId(TRAINER_BATTLE_PARAM.opponentA, 0);
}

static void SetRentalsToOpponentParty(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].monId = gFrontierTempParty[i];
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].ivs = GetBoxMonData(&gEnemyParty[i].box, MON_DATA_ATK_IV, NULL);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].personality = GetMonData(&gEnemyParty[i], MON_DATA_PERSONALITY, NULL);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].abilityNum = GetBoxMonData(&gEnemyParty[i].box, MON_DATA_ABILITY_NUM, NULL);
        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gFacilityTrainerMons[gFrontierTempParty[i]].heldItem);
    }
}

static void SetPlayerAndOpponentParties(void)
{
    int i;
    u8 monLevel;
    u16 monId;
    u8 ivs;

    if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_TENT)
    {
        gFacilityTrainerMons = gSlateportBattleTentMons;
        monLevel = TENT_MIN_LEVEL;
    }
    else
    {
        gFacilityTrainerMons = gBattleFrontierMons;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
            monLevel = FRONTIER_MAX_LEVEL_OPEN;
        else
            monLevel = FRONTIER_MAX_LEVEL_50;
    }

    if (gSpecialVar_0x8005 < 2)
    {
        ZeroPlayerPartyMons();
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            monId = gSaveBlock2Ptr->frontier.rentalMons[i].monId;
            ivs = gSaveBlock2Ptr->frontier.rentalMons[i].ivs;

            CreateFacilityMon(&gFacilityTrainerMons[monId], monLevel, ivs, OT_ID_PLAYER_ID, FLAG_FRONTIER_MON_FACTORY, &gPlayerParty[i]);
        }
    }

    switch (gSpecialVar_0x8005)
    {
    case 0:
    case 2:
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            monId = gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].monId;
            ivs = gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].ivs;
            CreateFacilityMon(&gFacilityTrainerMons[monId], monLevel, ivs, OT_ID_PLAYER_ID, FLAG_FRONTIER_MON_FACTORY, &gEnemyParty[i]);
        }
        break;
    }
}

static void GenerateInitialRentalMons(void)
{
    int i;
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
    u8 rentalRank = GetNumPastRentalsRank(battleMode, lvlMode);
    u16 monId;
    u16 species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];

    DebugPrintf("GenerateInitialRentalMons");
    DebugPrintf("challengeNum = %d (streak = %d)", challengeNum, gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode]);

    gFacilityTrainerMons = gBattleFrontierMons;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = SPECIES_NONE;
        monIds[i] = 0;
        heldItems[i] = ITEM_NONE;
    }

    i = 0;
    int retry = 0;

    while (i < PARTY_SIZE && retry < 5000)
    {
        retry++;

        bool8 useBetterRange = (i < rentalRank);
        monId = GetFactoryMonId(lvlMode, challengeNum, useBetterRange);

        u16 thisSpecies = gBattleFrontierMons[monId].species;
        u16 item = gBattleFrontierMons[monId].heldItem;

        DebugPrintf("Trying monId %d: species=%d, item=%d", monId, thisSpecies, item);

        // Skip Unown
        if (thisSpecies == SPECIES_UNOWN)
        {
            DebugPrintf("❌ Skipped: Unown");
            continue;
        }

        // Check duplicate species
        bool8 dupSpecies = FALSE;
        for (int j = 0; j < i; j++)
        {
            if (thisSpecies == species[j])
            {
                dupSpecies = TRUE;
                break;
            }
        }
        if (dupSpecies)
        {
            DebugPrintf("❌ Skipped: Duplicate species");
            continue;
        }

        // Check duplicate held items
        bool8 dupItem = FALSE;
        for (int j = 0; j < i; j++)
        {
            if (item != ITEM_NONE && heldItems[j] == item)
            {
                dupItem = TRUE;
                break;
            }
        }
        if (dupItem)
        {
            DebugPrintf("❌ Skipped: Duplicate held item");
            continue;
        }

        // ✅ Passed all checks
        gSaveBlock2Ptr->frontier.rentalMons[i].monId = monId;
        species[i] = thisSpecies;
        heldItems[i] = item;
        monIds[i] = monId;
        DebugPrintf("✅ Selected monId %d", monId);
        i++;
    }

    if (retry >= 5000)
        DebugPrintf("‼️ Rental loop bailed out after 5000 attempts.");
}


// Determines if the upcoming opponent has a single most-common
// type in its party. If there are two different types that are
// tied, then the opponent is deemed to have no preferred type,
// and NUMBER_OF_MON_TYPES is the result.
static void GetOpponentMostCommonMonType(void)
{
    u8 i;
    u8 typeCounts[NUMBER_OF_MON_TYPES];
    u8 mostCommonTypes[2];

    gFacilityTrainerMons = gBattleFrontierMons;

    // Count the number of times each type occurs in the opponent's party.
    for (i = TYPE_NORMAL; i < NUMBER_OF_MON_TYPES; i++)
        typeCounts[i] = 0;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u32 species = gFacilityTrainerMons[gFrontierTempParty[i]].species;
        typeCounts[gSpeciesInfo[species].types[0]]++;
        if (gSpeciesInfo[species].types[0] != gSpeciesInfo[species].types[1])
            typeCounts[gSpeciesInfo[species].types[1]]++;
    }

    // Determine which are the two most-common types.
    // The second most-common type is only updated if
    // its count is equal to the most-common type.
    mostCommonTypes[0] = 0;
    mostCommonTypes[1] = 0;
    for (i = 1; i < NUMBER_OF_MON_TYPES; i++)
    {
        if (typeCounts[mostCommonTypes[0]] < typeCounts[i])
            mostCommonTypes[0] = i;
        else if (typeCounts[mostCommonTypes[0]] == typeCounts[i])
            mostCommonTypes[1] = i;
    }

    if (typeCounts[mostCommonTypes[0]] != 0)
    {
        // The most-common type must be strictly greater than
        // the second-most-common type, or the top two must be
        // the same type.
        if (typeCounts[mostCommonTypes[0]] > typeCounts[mostCommonTypes[1]])
            gSpecialVar_Result = mostCommonTypes[0];
        else if (mostCommonTypes[0] == mostCommonTypes[1])
            gSpecialVar_Result = mostCommonTypes[0];
        else
            gSpecialVar_Result = NUMBER_OF_MON_TYPES;
    }
    else
    {
        gSpecialVar_Result = NUMBER_OF_MON_TYPES;
    }
}

static void GetOpponentBattleStyle(void)
{
    u8 i, j, count;
    u8 stylePoints[FACTORY_NUM_STYLES];

    count = 0;
    gFacilityTrainerMons = gBattleFrontierMons;
    for (i = 0; i < FACTORY_NUM_STYLES; i++)
        stylePoints[i] = 0;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gFrontierTempParty[i];
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            u8 battleStyle = GetMoveBattleStyle(gFacilityTrainerMons[monId].moves[j]);
            stylePoints[battleStyle]++;
        }
    }

    gSpecialVar_Result = FACTORY_STYLE_NONE;
    for (i = 1; i < FACTORY_NUM_STYLES; i++)
    {
        if (stylePoints[i] >= sRequiredMoveCounts[i - 1])
        {
            gSpecialVar_Result = i;
            count++;
        }
    }

    // Has no singular style
    if (count > 2)
        gSpecialVar_Result = FACTORY_NUM_STYLES;
}

static u8 GetMoveBattleStyle(u16 move)
{
    const u16 *moves;
    u8 i, j;

    for (i = 0; i < ARRAY_COUNT(sMoveStyles); i++)
    {
        for (j = 0, moves = sMoveStyles[i]; moves[j] != MOVE_NONE; j++)
        {
            if (moves[j] == move)
                return i + 1;
        }
    }
    return FACTORY_STYLE_NONE;
}

bool8 InBattleFactory(void)
{
    return gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM
        || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM;
}

static void RestorePlayerPartyHeldItems(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        SetMonData(&gPlayerParty[i],
                   MON_DATA_HELD_ITEM,
                   &gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[i].monId].heldItem);
    }
}

// Get the IV to use for the opponent's pokémon.
// The IVs get higher for each subsequent challenge and for
// the last trainer in each challenge. Noland is an exception
// to this, as he uses the IVs that would be used by the regular
// trainers 2 challenges ahead of the current one.
// Due to a mistake in FillFactoryFrontierTrainerParty, the
// challenge number used to determine the IVs for regular trainers
// is Battle Tower's instead of Battle Factory's.
u8 GetFactoryMonFixedIV(u8 challengeNum, bool8 isLastBattle)
{
    u8 ivSet;
    bool8 useHigherIV = isLastBattle ? TRUE : FALSE;

// The Factory has an out-of-bounds access when generating the rental draft for round 9 (challengeNum==8),
// or the "elevated" rentals from round 8 (challengeNum+1==8)
// This happens to land on a number higher than 31, which is interpreted as "random IVs"
#ifdef BUGFIX
    if (challengeNum >= ARRAY_COUNT(sFixedIVTable))
#else
    if (challengeNum > ARRAY_COUNT(sFixedIVTable))
#endif
        ivSet = ARRAY_COUNT(sFixedIVTable) - 1;
    else
        ivSet = challengeNum;

    return sFixedIVTable[ivSet][useHigherIV];
}

void FillFactoryBrainParty(void)
{
    int i, j, k;
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    int monLevel;
    u8 fixedIV;
    u32 otId;

    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
    fixedIV = GetFactoryMonFixedIV(challengeNum + 2, FALSE);
    monLevel = SetFacilityPtrsGetLevel();
    i = 0;
    otId = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);

    while (i != FRONTIER_PARTY_SIZE)
    {
        u16 monId = GetFactoryMonId(lvlMode, challengeNum, FALSE);

        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;

        for (j = 0; j < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); j++)
        {
            if (monId == gSaveBlock2Ptr->frontier.rentalMons[j].monId)
                break;
        }
        if (j != (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons))
            continue;

        for (k = 0; k < i; k++)
        {
            if (species[k] == gFacilityTrainerMons[monId].species)
                break;
        }
        if (k != i)
            continue;

        for (k = 0; k < i; k++)
        {
            if (heldItems[k] != ITEM_NONE && heldItems[k] == gFacilityTrainerMons[monId].heldItem)
                break;
        }
        if (k != i)
            continue;

        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gFacilityTrainerMons[monId].heldItem;
        CreateFacilityMon(&gFacilityTrainerMons[monId],
                monLevel, fixedIV, otId, FLAG_FRONTIER_MON_FACTORY,
                &gEnemyParty[i]);
        i++;
    }
}

static const u16 *GetFactoryRentalPool(u8 lvlMode, u8 challengeNum, u16 *poolSize)
{
    if (challengeNum < 1) {
        *poolSize = gFactoryPoolRank1Count;
        DebugPrintf("Using Rank 1 pool, size=%d", *poolSize);
        return sFactoryPoolRank1;
    } else if (challengeNum < 2) {
        *poolSize = gFactoryPoolRank2Count;
        DebugPrintf("Using Rank 2 pool, size=%d", *poolSize);
        return sFactoryPoolRank2;
    } else if (challengeNum < 3) {
        *poolSize = gFactoryPoolRank3Count;
        DebugPrintf("Using Rank 3 pool, size=%d", *poolSize);
        return sFactoryPoolRank3;
    } else {
        *poolSize = gFactoryPoolRank4Count;
        DebugPrintf("Using Rank 4 pool, size=%d", *poolSize);
        return sFactoryPoolRank4;
    }
}


static u16 GetFactoryMonId(u8 lvlMode, u8 challengeNum, bool8 useBetterRange)
{
    DebugPrintf("GetFactoryMonId");

    EnsureFactoryPoolsReady();

    u16 poolSize;
    const u16 *pool = GetFactoryRentalPool(lvlMode, challengeNum, &poolSize);

    DebugPrintf("lvlMode: %d", lvlMode);
    DebugPrintf("challengeNum: %d", challengeNum);
    DebugPrintf("poolSize: %d", poolSize);

    if (pool == NULL || poolSize == 0)
    {
        DebugPrintfLevel(MGBA_LOG_FATAL, "❌ No factory rental pool found for challengeNum=%d", challengeNum);
        return 0;
    }

    u16 monId = pool[Random() % poolSize];

    DebugPrintf("BF: selected monId = %d", monId);
    return monId;
}


u8 GetNumPastRentalsRank(u8 battleMode, u8 lvlMode)
{
    u8 ret;
    u8 rents = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];

    if (rents < 15)
        ret = 0;
    else if (rents < 22)
        ret = 1;
    else if (rents < 29)
        ret = 2;
    else if (rents < 36)
        ret = 3;
    else if (rents < 43)
        ret = 4;
    else
        ret = 5;

    return ret;
}

u64 GetAiScriptsInBattleFactory(void)
{
    return AI_FLAG_SMART_TRAINER;
}

void SetMonMoveAvoidReturn(struct Pokemon *mon, u16 moveArg, u8 moveSlot)
{
    u16 move = moveArg;
    if (moveArg == MOVE_RETURN)
        move = MOVE_FRUSTRATION;
    SetMonMoveSlot(mon, move, moveSlot);
}

void DebugAction_FactoryWinChallenge(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    DebugPrintf("Complete factory challenge triggered");

    // Simulate full challenge win
    gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] += 7;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 6;
    gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = 0;
    gSaveBlock2Ptr->frontier.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];

    DebugPrintf("Simulated full Factory challenge win.");
    DebugPrintf("Total wins: %d → challengeNum: %d",
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode],
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE);

    // Now end the battle
    BattleDebug_WonBattle();
}

void MarkAllFactorySpeciesAsSeen(void)
{
    for (int i = NUM_ORIGINAL_FRONTIER_MONS; i < NUM_FRONTIER_MONS; i++)
    {
        u16 species = gBattleFrontierMons[i].species;
        u16 nationalDexNo = SpeciesToNationalPokedexNum(species);

        if (nationalDexNo != 0)
            GetSetPokedexFlag(nationalDexNo, FLAG_SET_SEEN);
    }
}

const u8 *GetFacilityClassTypeWhitelist(u8 facilityClass, u8 *count)
{
    switch (facilityClass)
    {
        case FACILITY_CLASS_YOUNGSTER:
            *count = FACILITY_CLASS_YOUNGSTER_TYPE_COUNT;
            return gSpeciesListFacilityClassYoungsterType;
        case FACILITY_CLASS_LASS:
            *count = FACILITY_CLASS_LASS_TYPE_COUNT;
            return gSpeciesListFacilityClassLassType;
        case FACILITY_CLASS_SCHOOL_KID_M:
        case FACILITY_CLASS_SCHOOL_KID_F:
            *count = FACILITY_CLASS_SCHOOL_KID_TYPE_COUNT;
            return gSpeciesListFacilityClassSchoolKidType;
        case FACILITY_CLASS_RICH_BOY:
            *count = FACILITY_CLASS_RICH_BOY_TYPE_COUNT;
            return gSpeciesListFacilityClassRichBoyType;
        case FACILITY_CLASS_LADY:
            *count = FACILITY_CLASS_LADY_TYPE_COUNT;
            return gSpeciesListFacilityClassLadyType;
        case FACILITY_CLASS_CAMPER:
            *count = FACILITY_CLASS_CAMPER_TYPE_COUNT;
            return gSpeciesListFacilityClassCamperType;
        case FACILITY_CLASS_PICNICKER:
            *count = FACILITY_CLASS_PICNICKER_TYPE_COUNT;
            return gSpeciesListFacilityClassPicnickerType;
        case FACILITY_CLASS_TUBER_M:
            *count = FACILITY_CLASS_TUBER_M_TYPE_COUNT;
            return gSpeciesListFacilityClassTuberMType;
        case FACILITY_CLASS_TUBER_F:
            *count = FACILITY_CLASS_TUBER_F_TYPE_COUNT;
            return gSpeciesListFacilityClassTuberFType;
        case FACILITY_CLASS_SWIMMER_M:
            *count = FACILITY_CLASS_SWIMMER_M_TYPE_COUNT;
            return gSpeciesListFacilityClassSwimmerMType;
        case FACILITY_CLASS_SWIMMER_F:
            *count = FACILITY_CLASS_SWIMMER_F_TYPE_COUNT;
            return gSpeciesListFacilityClassSwimmerFType;
        case FACILITY_CLASS_POKEFAN_M:
            *count = FACILITY_CLASS_POKEFAN_TYPE_COUNT;
            return gSpeciesListFacilityClassPokefanType;
        case FACILITY_CLASS_POKEFAN_F:
            *count = FACILITY_CLASS_POKEFAN_TYPE_COUNT;
            return gSpeciesListFacilityClassPokefanType;
        case FACILITY_CLASS_PARASOL_LADY:
            *count = FACILITY_CLASS_PARASOL_LADY_TYPE_COUNT;
            return gSpeciesListFacilityClassParasolLadyType;
        case FACILITY_CLASS_GUITARIST:
            *count = FACILITY_CLASS_GUITARIST_TYPE_COUNT;
            return gSpeciesListFacilityClassGuitaristType;
        case FACILITY_CLASS_BIRD_KEEPER:
            *count = FACILITY_CLASS_BIRD_KEEPER_TYPE_COUNT;
            return gSpeciesListFacilityClassBirdKeeperType;
        case FACILITY_CLASS_HIKER:
            *count = FACILITY_CLASS_HIKER_TYPE_COUNT;
            return gSpeciesListFacilityClassHikerType;
        case FACILITY_CLASS_KINDLER:
            *count = FACILITY_CLASS_KINDLER_TYPE_COUNT;
            return gSpeciesListFacilityClassKindlerType;
        case FACILITY_CLASS_CYCLING_TRIATHLETE_M:
        case FACILITY_CLASS_CYCLING_TRIATHLETE_F:
        case FACILITY_CLASS_RUNNING_TRIATHLETE_M:
        case FACILITY_CLASS_RUNNING_TRIATHLETE_F:
        case FACILITY_CLASS_SWIMMING_TRIATHLETE_M:
        case FACILITY_CLASS_SWIMMING_TRIATHLETE_F:
            *count = FACILITY_CLASS_TRIATHLETE_TYPE_COUNT;
            return gSpeciesListFacilityClassTriathleteType;
        case FACILITY_CLASS_BLACK_BELT:
            *count = FACILITY_CLASS_BLACK_BELT_TYPE_COUNT;
            return gSpeciesListFacilityClassBlackBeltType;
        case FACILITY_CLASS_EXPERT_M:
        case FACILITY_CLASS_EXPERT_F:
            *count = FACILITY_CLASS_EXPERT_TYPE_COUNT;
            return gSpeciesListFacilityClassExpertType;
        case FACILITY_CLASS_PSYCHIC_M:
        case FACILITY_CLASS_PSYCHIC_F:
            *count = FACILITY_CLASS_PSYCHIC_TYPE_COUNT;
            return gSpeciesListFacilityClassPsychicType;
        case FACILITY_CLASS_POKEMANIAC:
            *count = FACILITY_CLASS_POKEMANIAC_TYPE_COUNT;
            return gSpeciesListFacilityClassPokemaniacType;
        case FACILITY_CLASS_GENTLEMAN:
            *count = FACILITY_CLASS_GENTLEMAN_TYPE_COUNT;
            return gSpeciesListFacilityClassGentlemanType;
        case FACILITY_CLASS_COLLECTOR:
            *count = FACILITY_CLASS_COLLECTOR_TYPE_COUNT;
            return gSpeciesListFacilityClassCollectorType;
        case FACILITY_CLASS_BEAUTY:
            *count = FACILITY_CLASS_BEAUTY_TYPE_COUNT;
            return gSpeciesListFacilityClassBeautyType;
        case FACILITY_CLASS_COOLTRAINER_M:
        case FACILITY_CLASS_COOLTRAINER_F:
            *count = FACILITY_CLASS_COOLTRAINER_TYPE_COUNT;
            return gSpeciesListFacilityClassCooltrainerType;
        case FACILITY_CLASS_PKMN_RANGER_M:
        case FACILITY_CLASS_PKMN_RANGER_F:
            *count = FACILITY_CLASS_PKMN_RANGER_TYPE_COUNT;
            return gSpeciesListFacilityClassPkmnRangerType;
        case FACILITY_CLASS_PKMN_BREEDER_M:
        case FACILITY_CLASS_PKMN_BREEDER_F:
            *count = FACILITY_CLASS_PKMN_BREEDER_TYPE_COUNT;
            return gSpeciesListFacilityClassPkmnBreederType;
        case FACILITY_CLASS_FISHERMAN:
            *count = FACILITY_CLASS_FISHERMAN_TYPE_COUNT;
            return gSpeciesListFacilityClassFishermanType;
        case FACILITY_CLASS_RUIN_MANIAC:
            *count = FACILITY_CLASS_RUIN_MANIAC_TYPE_COUNT;
            return gSpeciesListFacilityClassRuinManiacType;
        case FACILITY_CLASS_SAILOR:
            *count = FACILITY_CLASS_SAILOR_TYPE_COUNT;
            return gSpeciesListFacilityClassSailorType;
        case FACILITY_CLASS_DRAGON_TAMER:
            *count = FACILITY_CLASS_DRAGON_TAMER_TYPE_COUNT;
            return gSpeciesListFacilityClassDragonTamerType;
        case FACILITY_CLASS_BUG_CATCHER:
            *count = FACILITY_CLASS_BUG_CATCHER_TYPE_COUNT;
            return gSpeciesListFacilityClassBugCatcherType;
        case FACILITY_CLASS_BUG_MANIAC:
            *count = FACILITY_CLASS_BUG_MANIAC_TYPE_COUNT;
            return gSpeciesListFacilityClassBugManiacType;
        case FACILITY_CLASS_AROMA_LADY:
            *count = FACILITY_CLASS_AROMA_LADY_TYPE_COUNT;
            return gSpeciesListFacilityClassAromaLadyType;
        case FACILITY_CLASS_HEX_MANIAC:
            *count = FACILITY_CLASS_HEX_MANIAC_TYPE_COUNT;
            return gSpeciesListFacilityClassHexManiacType;
        case FACILITY_CLASS_NINJA_BOY:
            *count = FACILITY_CLASS_NINJA_BOY_TYPE_COUNT;
            return gSpeciesListFacilityClassNinjaBoyType;
        case FACILITY_CLASS_BATTLE_GIRL:
            *count = FACILITY_CLASS_BATTLE_GIRL_TYPE_COUNT;
            return gSpeciesListFacilityClassBattleGirlType;
        default:
            DebugPrintf("facilityClass not found: $s", facilityClass);
            *count = FACILITY_CLASS_DEFAULT_TYPE_COUNT;
            return gSpeciesListFacilityClassDefaultType;
    }
}

static void GetOpponentFrontierClass(void)
{
    DebugPrintf("🚩 CallBattleFactoryFunction: index = %d", gSpecialVar_0x8008);
    GetOpponentFrontierClassInternal(TRAINER_BATTLE_PARAM.opponentA);
}

void GetOpponentFrontierClassInternal(u8 trainerId)
{
    u8 facilityClass = gFacilityTrainers[trainerId].facilityClass;
    DebugPrintf("Trainer ID: %d, Facility Class: %d", trainerId, gFacilityTrainers[trainerId].facilityClass);

    if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
        gSpecialVar_Result = facilityClass;
    }
    else {
        gSpecialVar_Result = 0;
    }

}

static void SelectRewardMonFromParty(void)
{
    // gFactoryRewardMode = TRUE;
    // DoBattleFactorySelectScreen();
    gStarterSelectionOverride = gPlayerParty;
    gStarterSelectionOverrideCount = FRONTIER_PARTY_SIZE;

    SetMainCallback2(CB2_ChooseStarter);
    gMain.savedCallback = CB2_SelectReward;
}

static void GiveRewardMonFromParty(void)
{
    SetMainCallback2(CB2_GiveReward);
    gMain.savedCallback = CB2_GiveReward;
}

static void CB2_SelectReward(void)
{
    u8 selected = gSpecialVar_Result;
    DebugPrintf("Selected reward %d", selected);

    for (int i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
        DebugPrintf("Slot %d: species=%d", i, species);
    }

    if (selected >= FRONTIER_PARTY_SIZE)
        selected = 0;

    CopyMon(&sFactoryRewardBuffer, &gPlayerParty[selected], sizeof(struct Pokemon));

    gStarterSelectionOverride = NULL;
    gStarterSelectionOverrideCount = 0;

    ScriptContext_SetupScript(BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardResumeScript);
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void CB2_GiveReward(void)
{
    u8 result = GiveMonToPlayer(&sFactoryRewardBuffer);
    DebugPrintf("GiveMonToPlayer: %d", result);

    u16 species = GetMonData(&sFactoryRewardBuffer, MON_DATA_SPECIES);
    u16 nationalDexNum = SpeciesToNationalPokedexNum(species);
    if (nationalDexNum != 0)
    {
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
    }

    ScriptContext_SetupScript(BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardSaveAndExitScript);
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}
