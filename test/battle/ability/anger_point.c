#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Anger Point raises Attack stage to maximum after receiving a critical hit")
{
    GIVEN {
        ASSUME(MoveAlwaysCrits(MOVE_FROST_BREATH));
        PLAYER(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_ANGER_POINT); }
        OPPONENT(TEST_SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FROST_BREATH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FROST_BREATH, opponent);
        MESSAGE("A critical hit!");
        ABILITY_POPUP(player, ABILITY_ANGER_POINT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Anger Point maxed its Attack!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Anger Point does not trigger when already at maximum Attack stage")
{
    GIVEN {
        ASSUME(MoveAlwaysCrits(MOVE_FROST_BREATH));
        ASSUME(GetMoveEffect(MOVE_BELLY_DRUM) == EFFECT_BELLY_DRUM);
        PLAYER(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_ANGER_POINT); Speed(2); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); MOVE(opponent, MOVE_FROST_BREATH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet cut its own HP and maximized its Attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FROST_BREATH, opponent);
        MESSAGE("A critical hit!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_ANGER_POINT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Anger Point maxed its Attack!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
    }
}

TO_DO_BATTLE_TEST("Anger Point triggers when a substitute takes the hit (Gen4)");

SINGLE_BATTLE_TEST("Anger Point does not trigger when a substitute takes the hit (Gen5+)")
{
    GIVEN {
        ASSUME(MoveAlwaysCrits(MOVE_FROST_BREATH));
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_ANGER_POINT); Speed(2); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_FROST_BREATH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        MESSAGE("Wobbuffet put in a substitute!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FROST_BREATH, opponent);
        MESSAGE("A critical hit!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_ANGER_POINT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Anger Point maxed its Attack!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}
