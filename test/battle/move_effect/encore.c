#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
}

SINGLE_BATTLE_TEST("Encore forces consecutive move uses for 3 turns: Encore used before move (Gen5+)")
{
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    u32 speedPlayer, speedOpponent;
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; speedPlayer = 10; speedOpponent = 20; }
    PARAMETRIZE { encoreUser = player; encoreTarget = opponent; speedPlayer = 20; speedOpponent = 10; }
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TARGET, GEN_4);
        WITH_CONFIG(CONFIG_ENCORE_TURNS, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedPlayer); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speedOpponent); }
    } WHEN {
        TURN { MOVE(encoreUser, MOVE_CELEBRATE); MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { MOVE(encoreUser, MOVE_ENCORE); MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { MOVE(encoreTarget, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, encoreUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, encoreTarget);
    }
}

SINGLE_BATTLE_TEST("Encore forces consecutive move uses for 4 turns: Encore used after move (Gen5+)")
{
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    u32 speedPlayer, speedOpponent;
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; speedPlayer = 20; speedOpponent = 10; }
    PARAMETRIZE { encoreUser = player; encoreTarget = opponent; speedPlayer = 10; speedOpponent = 20; }
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TARGET, GEN_4);
        WITH_CONFIG(CONFIG_ENCORE_TURNS, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedPlayer); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speedOpponent); }
    } WHEN {
        TURN { MOVE(encoreTarget, MOVE_CELEBRATE); MOVE(encoreUser, MOVE_ENCORE); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { MOVE(encoreTarget, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, encoreUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, encoreTarget);
    }
}

SINGLE_BATTLE_TEST("Encore has no effect if no previous move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Encore!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Encore overrides the chosen move if it occurs first")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are immune to Encore")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_ENCORE); }
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet used Encore!");
        MESSAGE("But it failed!");
        MESSAGE("Wobbuffet used Max Flare!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can be encored immediately after reverting")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }; // yes, this speed is necessary
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_ARM_THRUST, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(player, MOVE_ARM_THRUST); }
        TURN { MOVE(player, MOVE_ARM_THRUST); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("The opposing Wobbuffet used Encore!");
        MESSAGE("Wobbuffet used Arm Thrust!");
    }
}

SINGLE_BATTLE_TEST("Encore's effect ends if the encored move runs out of PP")
{
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TURNS, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); MovesWithPP({MOVE_SCRATCH, 2}, {MOVE_CELEBRATE, 10}); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_ENCORE, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    }
}

// NOTE: AI test is required to validate RNG range without MOVE/FORCED_MOVE invalids; there may be a better approach.
AI_SINGLE_BATTLE_TEST("Encore lasts for 2-6 turns (Gen 2-3)")
{
    u32 count, turns;

    PARAMETRIZE { turns = 2; }
    PARAMETRIZE { turns = 3; }
    PARAMETRIZE { turns = 4; }
    PARAMETRIZE { turns = 5; }
    PARAMETRIZE { turns = 6; }
    PASSES_RANDOMLY(1, 5, RNG_ENCORE_TURNS);
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TURNS, GEN_3);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_ENCORE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_ENCORE); }
        for (count = 0; count < turns - 1; ++count)
            TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, player);
        for (count = 0; count < turns - 1; ++count)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("The opposing Wobbuffet ended its encore!");
    }
}

AI_SINGLE_BATTLE_TEST("Encore lasts for 3-7 turns (Gen 4)")
{
    u32 count, turns;

    PARAMETRIZE { turns = 3; }
    PARAMETRIZE { turns = 4; }
    PARAMETRIZE { turns = 5; }
    PARAMETRIZE { turns = 6; }
    PARAMETRIZE { turns = 7; }
    PASSES_RANDOMLY(1, 5, RNG_ENCORE_TURNS);
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TURNS, GEN_4);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_ENCORE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_ENCORE); }
        for (count = 0; count < turns - 1; ++count)
            TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, player);
        for (count = 0; count < turns - 1; ++count)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("The opposing Wobbuffet ended its encore!");
    }
}

DOUBLE_BATTLE_TEST("Encore randomly chooses an opponent target (Gen 2-4)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TARGET, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_ENCORE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft);
        }
        TURN {
            MOVE(opponentLeft, MOVE_ENCORE, target: playerLeft, WITH_RNG(RNG_RANDOM_TARGET, 1));
            MOVE(playerLeft, MOVE_CELEBRATE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft, target: opponentRight);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Encore allows choosing an opponent target (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TARGET, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_ENCORE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft);
        }
        TURN {
            MOVE(opponentLeft, MOVE_ENCORE, target: playerLeft);
            MOVE(playerLeft, MOVE_TACKLE, target: opponentRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft, target: opponentRight);
        HP_BAR(opponentRight);
    }
}
