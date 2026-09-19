#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_POLLEN_PUFF) == EFFECT_HIT_ENEMY_HEAL_ALLY);
}

DOUBLE_BATTLE_TEST("Pollen Puff heals partner by 50% when selected")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_POLLEN_PUFF, target: playerRight); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[1], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POLLEN_PUFF, playerLeft);
        HP_BAR(playerRight, damage: -maxHP / 2);
        NONE_OF {
            HP_BAR(opponentLeft);
            HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pollen Puff damage an enemy when selected")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_POLLEN_PUFF, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POLLEN_PUFF, playerLeft);
        NONE_OF {
            s32 maxHP = GetMonData(&PLAYER_PARTY[1], MON_DATA_MAX_HP);
            HP_BAR(playerRight, damage: -maxHP / 2);
        }
        HP_BAR(opponentLeft);
        NOT HP_BAR(opponentRight);
    }
}
