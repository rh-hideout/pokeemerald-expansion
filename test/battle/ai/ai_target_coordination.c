#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_DOUBLE_BATTLE_TEST("AI target coordination: only one ally attacks a protected 1 HP foe")
{
    u32 reverseOrder;
    bool32 enabled;

    PARAMETRIZE { reverseOrder = 0; enabled = TRUE; }
    PARAMETRIZE { reverseOrder = 100; enabled = TRUE; }
    PARAMETRIZE { reverseOrder = 0; enabled = FALSE; }
    PARAMETRIZE { reverseOrder = 100; enabled = FALSE; }

    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, enabled);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, reverseOrder);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(10); Moves(MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(40); Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(30); Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: enabled && reverseOrder ? playerRight : playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: enabled && !reverseOrder ? playerRight : playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: keep both attacks when neither ally can KO alone")
{
    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        TIE_BREAK_TARGET(TARGET_TIE_LO, 0);
        PLAYER(SPECIES_WOBBUFFET) { HP(150); MaxHP(500); Moves(MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(100); Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(100); Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: keep backup attacks for inaccurate partner moves")
{
    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Moves(MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_MEGA_KICK); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_MEGA_KICK, target: playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: preserve attacks through Focus Sash and Sturdy")
{
    enum Item item;
    enum Ability ability;

    PARAMETRIZE { item = ITEM_FOCUS_SASH; ability = ABILITY_SHADOW_TAG; }
    PARAMETRIZE { item = ITEM_NONE; ability = ABILITY_STURDY; }

    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        TIE_BREAK_TARGET(TARGET_TIE_LO, 0);
        PLAYER(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); Item(item); Ability(ability); Moves(MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(100); Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(100); Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: a partner's unusable KO move does not reserve a target")
{
    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Moves(MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_SEISMIC_TOSS, 0}, {MOVE_CELEBRATE, 10}); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: spread moves retain their value after a partner chooses a KO")
{
    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Moves(MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HYPER_VOICE, MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_HYPER_VOICE);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: keep the only effective target")
{
    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Moves(MOVE_PROTECT); }
        PLAYER(SPECIES_GENGAR);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: keep an urgent KO when the foe can remove the partner first")
{
    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(20); Moves(MOVE_SEISMIC_TOSS, MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(15); Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(30); Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: a possible max-roll KO still needs a backup attack")
{
    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        WITH_CONFIG(AI_ROLL_ATTACKING, AI_ROLL_MAX);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(40); Defense(100); Moves(MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); Defense(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(100); Attack(120); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerLeft);
        }
    } THEN {
        EXPECT_LT(gAiLogicData->simulatedDmg[B_BATTLER_1][B_BATTLER_0][MOVESLOT_0].minimum, 40);
        EXPECT_GE(gAiLogicData->simulatedDmg[B_BATTLER_1][B_BATTLER_0][MOVESLOT_0].maximum, 40);
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: incapacitated partners and delayed attacks do not reserve KOs")
{
    enum Move move;
    u32 status;

    PARAMETRIZE { move = MOVE_SEISMIC_TOSS; status = STATUS1_SLEEP; }
    PARAMETRIZE { move = MOVE_SEISMIC_TOSS; status = STATUS1_FREEZE; }
    PARAMETRIZE { move = MOVE_SEISMIC_TOSS; status = STATUS1_PARALYSIS; }
    PARAMETRIZE { move = MOVE_SOLAR_BEAM; status = STATUS1_NONE; }
    PARAMETRIZE { move = MOVE_FLY; status = STATUS1_NONE; }
    PARAMETRIZE { move = MOVE_FUTURE_SIGHT; status = STATUS1_NONE; }

    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Moves(MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move); Status1(status); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: recompute reservations after the partner switches")
{
    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SOUNDPROOF); HP(1); Speed(10); Moves(MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SOUNDPROOF); HP(500); MaxHP(500); Speed(20); Moves(MOVE_PERISH_SONG, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Speed(40); Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SOUNDPROOF); Speed(30); Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT, WITH_RNG(RNG_PROTECT_FAIL, 1));
            MOVE(playerRight, MOVE_PERISH_SONG);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerRight);
        }
        TURN { MOVE(playerLeft, MOVE_PROTECT, WITH_RNG(RNG_PROTECT_FAIL, 1)); EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS); EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS); }
        TURN { MOVE(playerLeft, MOVE_PROTECT, WITH_RNG(RNG_PROTECT_FAIL, 1)); EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS); EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS); }
        TURN {
            MOVE(playerLeft, MOVE_PROTECT, WITH_RNG(RNG_PROTECT_FAIL, 1));
            EXPECT_SWITCH(opponentLeft, 2);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerLeft);
        }
    }
}

AI_MULTI_BATTLE_TEST("AI target coordination: coordinate attacks across two opposing trainers")
{
    u32 reverseOrder;

    PARAMETRIZE { reverseOrder = 0; }
    PARAMETRIZE { reverseOrder = 100; }

    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, reverseOrder);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(10); Moves(MOVE_PROTECT); }
        PARTNER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); Speed(20); Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(40); Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(30); Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: reverseOrder ? playerRight : playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: reverseOrder ? playerLeft : playerRight);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: prediction passes do not reserve targets")
{
    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_PREDICT_MOVE | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(10); Moves(MOVE_PROTECT, MOVE_SEISMIC_TOSS); }
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); Speed(20); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(40); Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(30); Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerRight);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: a Substitute still needs a second attack")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_SHADOW_TAG; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; }

    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        TIE_BREAK_TARGET(TARGET_TIE_LO, 0);
        PLAYER(SPECIES_WOBBUFFET) { HP(150); MaxHP(500); Speed(20); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { HP(101); MaxHP(400); Speed(10); Moves(MOVE_SUBSTITUTE, MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); Speed(50); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); Level(100); Speed(40); Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(100); Speed(30); Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerRight, MOVE_SUBSTITUTE);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: playerLeft);
            SEND_OUT(playerLeft, 2);
        }
        TURN {
            MOVE(playerRight, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: playerRight);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: ability == ABILITY_INFILTRATOR ? playerLeft : playerRight);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI target coordination: either equally good foe can be chosen first")
{
    enum TargetTieResolution tie = TARGET_TIE_LO;
    struct BattlePokemon *firstTarget = NULL;
    struct BattlePokemon *secondTarget = NULL;

    PARAMETRIZE { tie = TARGET_TIE_LO; firstTarget = playerLeft; secondTarget = playerRight; }
    PARAMETRIZE { tie = TARGET_TIE_HI; firstTarget = playerRight; secondTarget = playerLeft; }

    GIVEN {
        WITH_CONFIG(AI_DOUBLE_TARGET_COORDINATION, TRUE);
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        TIE_BREAK_TARGET(tie, 0);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(10); Moves(MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(20); Moves(MOVE_PROTECT); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(40); Moves(MOVE_SEISMIC_TOSS); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(30); Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            MOVE(playerRight, MOVE_PROTECT);
            EXPECT_MOVE(opponentLeft, MOVE_SEISMIC_TOSS, target: firstTarget);
            EXPECT_MOVE(opponentRight, MOVE_SEISMIC_TOSS, target: secondTarget);
        }
    }
}
