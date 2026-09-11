#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_QUICK_POWDER) == HOLD_EFFECT_QUICK_POWDER);
}

SINGLE_BATTLE_TEST("Quick Powder doubles an untransformed Ditto's Speed")
{
    enum Item item;
    u32 opponentSpeed;
    bool32 playerFirst;

    PARAMETRIZE { item = ITEM_NONE;         opponentSpeed = 199; playerFirst = FALSE; }
    PARAMETRIZE { item = ITEM_QUICK_POWDER; opponentSpeed = 199; playerFirst = TRUE;  }
    PARAMETRIZE { item = ITEM_QUICK_POWDER; opponentSpeed = 201; playerFirst = FALSE; }

    GIVEN {
        PLAYER(SPECIES_DITTO) { Speed(100); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(opponentSpeed); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (playerFirst) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            HP_BAR(opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
            HP_BAR(player);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
            HP_BAR(player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Quick Powder does not boost the Speed of non-Ditto holders")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_QUICK_POWDER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(150); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Quick Powder does not boost Ditto's Speed after it transforms")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
        ASSUME_STAT_CHANGE(MOVE_DRAGON_DANCE, attack: 1, speed: 1);
        PLAYER(SPECIES_DITTO) { Speed(100); Moves(MOVE_DRAGON_DANCE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_DITTO) { Speed(200); Item(ITEM_QUICK_POWDER); Moves(MOVE_TRANSFORM, MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_DANCE); MOVE(opponent, MOVE_TRANSFORM); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
    }
}
