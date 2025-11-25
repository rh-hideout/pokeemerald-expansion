#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Perish Song (Move Effect) test titles")

#define NOT_PERISHI_SONG_AFFECTED \
    NONE_OF { \
        MESSAGE("Lanturn's perish count fell to 3!"); \
        MESSAGE("Voltorb's perish count fell to 3!"); \
    } \

DOUBLE_BATTLE_TEST("Perish Song will be can be absrobed and will not effect those")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_LANTURN) { HP(1); Ability(ABILITY_VOLT_ABSORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_ELECTRIFY, target: playerLeft);
            MOVE(playerLeft, MOVE_PERISH_SONG);
        }
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIFY, opponentLeft);
        ABILITY_POPUP(playerRight, ABILITY_VOLT_ABSORB);
        ABILITY_POPUP(opponentRight, ABILITY_SOUNDPROOF);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PERISH_SONG, playerLeft);
        NOT_PERISHI_SONG_AFFECTED;
        MESSAGE("The opposing Wobbuffet's perish count fell to 3!");
        NOT_PERISHI_SONG_AFFECTED;
        MESSAGE("Wobbuffet's perish count fell to 3!");
        NOT_PERISHI_SONG_AFFECTED;
        MESSAGE("The opposing Wobbuffet's perish count fell to 2!");
        MESSAGE("Wobbuffet's perish count fell to 2!");
        MESSAGE("The opposing Wobbuffet's perish count fell to 1!");
        MESSAGE("Wobbuffet's perish count fell to 1!");
        MESSAGE("The opposing Wobbuffet's perish count fell to 0!");
        HP_BAR(opponentLeft);
        MESSAGE("Wobbuffet's perish count fell to 0!");
        HP_BAR(playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Perish Song ignores protect")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { 
            MOVE(playerLeft, MOVE_PROTECT); 
            MOVE(opponentLeft, MOVE_PROTECT); 
            MOVE(playerRight, MOVE_PERISH_SONG); 
        }
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PERISH_SONG, playerRight);
        HP_BAR(playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        HP_BAR(playerRight);
    }
}

