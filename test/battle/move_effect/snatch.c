#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SNATCH) == EFFECT_SNATCH);
    ASSUME(MoveCanBeSnatched(MOVE_SWORDS_DANCE));
}

SINGLE_BATTLE_TEST("Snatch steals stat-boosting moves from the opponent")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_SNATCH); MOVE(opponent, MOVE_SWORDS_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNATCH, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Snatch fails if user moves last")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SNATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SNATCH, player);
    }
}

DOUBLE_BATTLE_TEST("Snatch works when partner slot is empty after fainting")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(15); }
        PLAYER(SPECIES_WYNAUT) { HP(1); Speed(25); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TACKLE, target: playerRight); }
        TURN {
            MOVE(playerLeft, MOVE_SNATCH);
            MOVE(opponentRight, MOVE_SWORDS_DANCE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentLeft);
        MESSAGE("Wynaut fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNATCH, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, playerLeft);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

TO_DO_BATTLE_TEST("Snatch does not steal moves that cannot be snatched");
TO_DO_BATTLE_TEST("Snatch can steal healing moves");
