#include "global.h"
#include "test/test.h"
#include "test/battle.h"
#include "difficulty.h"
#include "event_data.h"
#include "mf_exp.h"
#include "mf_level_cap.h"
#include "mf_rules.h"

static struct ModernRules *PrepareRules(void)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(save);
    save->rulesLocked = TRUE;
    FlagClear(FLAG_SYS_GAME_CLEAR);
    SetCurrentDifficultyLevel(DIFFICULTY_NORMAL);
    return save;
}

TEST("MF: exp pool multiplier and hard-mode factor")
{
    // ×1, ×1.5, ×2, ×0. Hard factor is 60% after the multiplier. ×0 wins.
    EXPECT_EQ(MfResolveExpPool(100, MF_EXP_MULT_1X, FALSE), 100u);
    EXPECT_EQ(MfResolveExpPool(100, MF_EXP_MULT_15X, FALSE), 150u);
    EXPECT_EQ(MfResolveExpPool(100, MF_EXP_MULT_2X, FALSE), 200u);
    EXPECT_EQ(MfResolveExpPool(100, MF_EXP_MULT_0X, FALSE), 0u);
    EXPECT_EQ(MfResolveExpPool(100, MF_EXP_MULT_0X, TRUE), 0u);

    EXPECT_EQ(MfResolveExpPool(100, MF_EXP_MULT_1X, TRUE), 60u);
    EXPECT_EQ(MfResolveExpPool(100, MF_EXP_MULT_15X, TRUE), 90u);
    EXPECT_EQ(MfResolveExpPool(100, MF_EXP_MULT_2X, TRUE), 120u);

    // Truncation matches (n * 3) / 2 and (n * 3) / 5.
    EXPECT_EQ(MfResolveExpPool(7, MF_EXP_MULT_15X, FALSE), 10u);
    EXPECT_EQ(MfResolveExpPool(1, MF_EXP_MULT_1X, TRUE), 0u);
    // Values outside the 2-bit menu stay at ×1.
    EXPECT_EQ(MfResolveExpPool(40, 255, FALSE), 40u);
}

TEST("MF: hard exp reduction is Hard level cap or Hard difficulty")
{
    EXPECT(!MfIsHardExpReductionActive(MF_LEVEL_CAP_OFF, FALSE, FALSE, FALSE));
    EXPECT(!MfIsHardExpReductionActive(MF_LEVEL_CAP_NORMAL, FALSE, FALSE, FALSE));
    EXPECT(MfIsHardExpReductionActive(MF_LEVEL_CAP_HARD, FALSE, FALSE, FALSE));
    // Normal (bit 1) keeps the full rate. Hall of Fame lifts the cut.
    EXPECT(!MfIsHardExpReductionActive(MF_LEVEL_CAP_HARD, TRUE, FALSE, FALSE));
    EXPECT(!MfIsHardExpReductionActive(MF_LEVEL_CAP_HARD, FALSE, FALSE, TRUE));
    EXPECT(MfIsHardExpReductionActive(MF_LEVEL_CAP_OFF, FALSE, TRUE, FALSE));
    EXPECT(!MfIsHardExpReductionActive(MF_LEVEL_CAP_OFF, FALSE, TRUE, TRUE));
    EXPECT(!MfIsHardExpReductionActive(MF_LEVEL_CAP_OFF, TRUE, TRUE, FALSE));
    // Both hard signals still mean one 60% factor, not 36%.
    EXPECT(MfIsHardExpReductionActive(MF_LEVEL_CAP_HARD, FALSE, TRUE, FALSE));
    EXPECT_EQ(MfResolveExpPool(100, MF_EXP_MULT_1X, TRUE), 60u);
}

TEST("MF: live exp scale follows rules, badges not required")
{
    struct ModernRules *save = PrepareRules();

    EXPECT_EQ(MfScaleCalculatedExp(100), 100u);
    EXPECT(!MfIsExpMultiplierZero());

    save->expMultiplier = MF_EXP_MULT_15X;
    EXPECT_EQ(MfScaleCalculatedExp(100), 150u);
    save->expMultiplier = MF_EXP_MULT_2X;
    EXPECT_EQ(MfScaleCalculatedExp(200), 400u);
    save->expMultiplier = MF_EXP_MULT_0X;
    EXPECT(MfIsExpMultiplierZero());
    EXPECT_EQ(MfScaleCalculatedExp(100), 0u);

    save->expMultiplier = MF_EXP_MULT_1X;
    save->levelCap = MF_LEVEL_CAP_HARD;
    save->hardExp = FALSE;
    EXPECT_EQ(MfScaleCalculatedExp(100), 60u);

    save->hardExp = TRUE;
    EXPECT_EQ(MfScaleCalculatedExp(100), 100u);

    save->hardExp = FALSE;
    FlagSet(FLAG_SYS_GAME_CLEAR);
    EXPECT_EQ(MfScaleCalculatedExp(100), 100u);
    FlagClear(FLAG_SYS_GAME_CLEAR);

    save->levelCap = MF_LEVEL_CAP_OFF;
    SetCurrentDifficultyLevel(DIFFICULTY_HARD);
    EXPECT_EQ(MfScaleCalculatedExp(100), 60u);

    save->hardExp = TRUE;
    EXPECT_EQ(MfScaleCalculatedExp(100), 100u);

    SetCurrentDifficultyLevel(DIFFICULTY_NORMAL);
}

TEST("MF: scaled exp gate follows the save bit")
{
    struct ModernRules *save = PrepareRules();

    EXPECT(!save->scaledExp);
    EXPECT(!MfIsScaledExpActive());

    save->scaledExp = TRUE;
    EXPECT(MfIsScaledExpActive());

    save->scaledExp = FALSE;
    EXPECT(!MfIsScaledExpActive());
}

static void SetBattleExpRules(u8 multiplier, u8 levelCap, bool8 hardExp, bool8 scaledExp)
{
    struct ModernRules *save = PrepareRules();

    save->expMultiplier = multiplier;
    save->levelCap = levelCap;
    save->hardExp = hardExp;
    save->scaledExp = scaledExp;
}

WILD_BATTLE_TEST("MF: each exp multiplier changes exp from the same battle", s32 exp)
{
    u8 multiplier = 0;

    PARAMETRIZE { multiplier = MF_EXP_MULT_1X; }
    PARAMETRIZE { multiplier = MF_EXP_MULT_15X; }
    PARAMETRIZE { multiplier = MF_EXP_MULT_2X; }

    GIVEN {
        SetBattleExpRules(multiplier, MF_LEVEL_CAP_OFF, FALSE, FALSE);
        PLAYER(SPECIES_WOBBUFFET) { Level(20); }
        OPPONENT(SPECIES_CATERPIE) { Level(10); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("The wild Caterpie fainted!");
        EXPERIENCE_BAR(player, captureGainedExp: &results[i].exp);
    } FINALLY {
        EXPECT_GT(results[1].exp, results[0].exp);
        EXPECT_GT(results[2].exp, results[1].exp);
        SetBattleExpRules(MF_EXP_MULT_1X, MF_LEVEL_CAP_OFF, FALSE, FALSE);
    }
}

WILD_BATTLE_TEST("MF: exp multiplier x0 grants no experience")
{
    u32 startExp = 0;

    GIVEN {
        SetBattleExpRules(MF_EXP_MULT_0X, MF_LEVEL_CAP_OFF, FALSE, FALSE);
        PLAYER(SPECIES_WOBBUFFET) { Level(20); }
        OPPONENT(SPECIES_CATERPIE) { Level(10); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("The wild Caterpie fainted!");
        NOT EXPERIENCE_BAR(player);
    } THEN {
        startExp = gExperienceTables[gSpeciesInfo[SPECIES_WOBBUFFET].growthRate][20];
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_EXP), startExp);
        SetBattleExpRules(MF_EXP_MULT_1X, MF_LEVEL_CAP_OFF, FALSE, FALSE);
    }
}

WILD_BATTLE_TEST("MF: hard exp cuts gain while the level cap is Hard", s32 exp)
{
    bool8 hardExpNormal = FALSE;

    PARAMETRIZE { hardExpNormal = FALSE; }
    PARAMETRIZE { hardExpNormal = TRUE; }

    GIVEN {
        SetBattleExpRules(MF_EXP_MULT_1X, MF_LEVEL_CAP_HARD, hardExpNormal, FALSE);
        // Under the 0-badge Hard cap (12) so the ceiling does not zero the reward.
        PLAYER(SPECIES_WOBBUFFET) { Level(10); }
        OPPONENT(SPECIES_CATERPIE) { Level(10); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("The wild Caterpie fainted!");
        EXPERIENCE_BAR(player, captureGainedExp: &results[i].exp);
    } FINALLY {
        EXPECT_GT(results[1].exp, results[0].exp);
        EXPECT(results[0].exp > 0);
        SetBattleExpRules(MF_EXP_MULT_1X, MF_LEVEL_CAP_OFF, FALSE, FALSE);
    }
}

WILD_BATTLE_TEST("MF: scaled exp off pays the same at two player levels", s32 exp)
{
    u8 level = 0;

    PARAMETRIZE { level = 10; }
    PARAMETRIZE { level = 20; }

    GIVEN {
        SetBattleExpRules(MF_EXP_MULT_1X, MF_LEVEL_CAP_OFF, FALSE, FALSE);
        PLAYER(SPECIES_WOBBUFFET) { Level(level); }
        OPPONENT(SPECIES_CATERPIE) { Level(10); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("The wild Caterpie fainted!");
        EXPERIENCE_BAR(player, captureGainedExp: &results[i].exp);
    } FINALLY {
        EXPECT_EQ(results[0].exp, results[1].exp);
        EXPECT(results[0].exp > 0);
        SetBattleExpRules(MF_EXP_MULT_1X, MF_LEVEL_CAP_OFF, FALSE, FALSE);
    }
}

WILD_BATTLE_TEST("MF: scaled exp on pays less to a higher-level Pokemon", s32 exp)
{
    u8 level = 0;

    PARAMETRIZE { level = 10; }
    PARAMETRIZE { level = 20; }

    GIVEN {
        SetBattleExpRules(MF_EXP_MULT_1X, MF_LEVEL_CAP_OFF, FALSE, TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Level(level); }
        OPPONENT(SPECIES_CATERPIE) { Level(10); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("The wild Caterpie fainted!");
        EXPERIENCE_BAR(player, captureGainedExp: &results[i].exp);
    } FINALLY {
        EXPECT_GT(results[0].exp, results[1].exp);
        SetBattleExpRules(MF_EXP_MULT_1X, MF_LEVEL_CAP_OFF, FALSE, FALSE);
    }
}
