#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Growth increases Sp. Atk and Sp. Def by 1 stage (Gen 1)") // Equivalent to raising Special
{
    KNOWN_FAILING; // fails because the moveeffect is built as gen 5
    GIVEN {
        WITH_CONFIG(B_GROWTH_STAT_RAISE, GEN_1);
        ASSUME(GetMoveEffect(MOVE_GROWTH) == EFFECT_SPECIAL_ATTACK_UP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
        TURN { MOVE(player, MOVE_GROWTH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWTH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Growth increases Sp. Atk by 1 stage (Gen 2-4)")
{
    KNOWN_FAILING; // fails because the moveeffect is built as gen 5
    GIVEN {
        WITH_CONFIG(B_GROWTH_STAT_RAISE, GEN_2);
        ASSUME(GetMoveEffect(MOVE_GROWTH) == EFFECT_SPECIAL_ATTACK_UP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
        TURN { MOVE(player, MOVE_GROWTH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWTH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}


SINGLE_BATTLE_TEST("Growth increases Attack and Sp. Atk by 1 stage or 2 stages under Sun (Gen 5+)")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE;}
    PARAMETRIZE { move = MOVE_SUNNY_DAY;}

    GIVEN {
        WITH_CONFIG(B_GROWTH_STAT_RAISE, GEN_5);
        ASSUME(GetMoveEffect(MOVE_GROWTH) == EFFECT_GROWTH);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_GROWTH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWTH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        if (move == MOVE_CELEBRATE) {
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        }
        else {
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        }
    }
}

