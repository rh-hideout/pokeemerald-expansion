#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Drowsy increases damage taken by 50%", s16 damage)
{
    u32 status;
    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_DROWSY; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status); }
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); }
    } SCENE {
        MESSAGE("Wobbuffet used Explosion!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[1].damage, uq4_12_multiply_half_down(results[0].damage, UQ_4_12(1.5)));
    }
}

SINGLE_BATTLE_TEST("Drowsy has a 25% chance of skipping the turn")
{
    PASSES_RANDOMLY(25, 100, RNG_DROWSY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_DROWSY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet is too drowsy to move!");
    }
}

SINGLE_BATTLE_TEST("Using Spark, Volt Tackle, or Wild Charge will cure the user of drowsiness")
{
    u32 move;
    PARAMETRIZE { move = MOVE_SPARK; }
    PARAMETRIZE { move = MOVE_VOLT_TACKLE; }
    PARAMETRIZE { move = MOVE_WILD_CHARGE; }
    PASSES_RANDOMLY(75, 100, RNG_DROWSY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_DROWSY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("Wobbuffet fought off its drowsiness!");
        STATUS_ICON(player, drowsy: FALSE);
    }
}
