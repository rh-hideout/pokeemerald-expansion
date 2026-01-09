#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
}

SINGLE_BATTLE_TEST("(Gen5+) Encore forces consecutive move uses for 4 turns: Encore used before move")
{
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; }
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TARGET, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
    } WHEN {
        TURN { MOVE(encoreUser, MOVE_CELEBRATE); MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { MOVE(encoreUser, MOVE_ENCORE); MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { FORCED_MOVE(encoreTarget); }
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
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, encoreTarget);
    }
}

SINGLE_BATTLE_TEST("(Gen5+) Encore forces consecutive move uses for 3 turns: Encore used after move")
{
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; }
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TARGET, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
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

SINGLE_BATTLE_TEST("(Gen4) Encore forces consecutive move uses for 4-8 turns: Encore used before move")
{
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; }
    PASSES_RANDOMLY(1, 5, RNG_ENCORE_TURNS);
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TURNS, GEN_4);
        WITH_CONFIG(CONFIG_ENCORE_TARGET, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
    } WHEN {
        TURN { MOVE(encoreUser, MOVE_CELEBRATE); MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { MOVE(encoreUser, MOVE_ENCORE); MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { FORCED_MOVE(encoreTarget); }
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
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, encoreTarget);
    }
}

SINGLE_BATTLE_TEST("(Gen4) Encore forces consecutive move uses for 3-7 turns: Encore used after move")
{
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    PASSES_RANDOMLY(1, 5, RNG_ENCORE_TURNS);
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; }
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TURNS, GEN_4);
        WITH_CONFIG(CONFIG_ENCORE_TARGET, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
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

SINGLE_BATTLE_TEST("(Gens2-3) Encore forces consecutive move uses for 3-7 turns: Encore used before move")
{
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; }
    PASSES_RANDOMLY(1, 5, RNG_ENCORE_TURNS);
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TURNS, GEN_3);
        WITH_CONFIG(CONFIG_ENCORE_TARGET, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
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

SINGLE_BATTLE_TEST("(Gens2-3) Encore forces consecutive move uses for 2-6 turns: Encore used after move")
{
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; }
    PASSES_RANDOMLY(1, 5, RNG_ENCORE_TURNS);
    GIVEN {
        WITH_CONFIG(CONFIG_ENCORE_TURNS, GEN_3);
        WITH_CONFIG(CONFIG_ENCORE_TARGET, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(encoreTarget, MOVE_CELEBRATE); MOVE(encoreUser, MOVE_ENCORE); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { MOVE(encoreTarget, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, encoreUser);
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

TO_DO_BATTLE_TEST("Encore's effect ends if the encored move runs out of PP");
TO_DO_BATTLE_TEST("Encore randomly chooses an opponent target");
