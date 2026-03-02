#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveMakesContact(MOVE_SCRATCH));
    ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
}

TO_DO_BATTLE_TEST("TODO: Write Unseen Fist (Ability) test titles")

SINGLE_BATTLE_TEST("Unseen Fist ignores Protect when user has Protective Pads, but not with Punching Glove", s16 damage)
{
    u32 item;

    PARAMETRIZE { item = ITEM_PROTECTIVE_PADS; }
    PARAMETRIZE { item = ITEM_PUNCHING_GLOVE; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_MACH_PUNCH));
        ASSUME(IsPunchingMove(MOVE_MACH_PUNCH));
        ASSUME(GetItemHoldEffect(ITEM_PROTECTIVE_PADS) == HOLD_EFFECT_PROTECTIVE_PADS);
        ASSUME(GetItemHoldEffect(ITEM_PUNCHING_GLOVE) == HOLD_EFFECT_PUNCHING_GLOVE);
        PLAYER(SPECIES_URSHIFU) { Ability(ABILITY_UNSEEN_FIST); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_MACH_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        if (item != ITEM_PUNCHING_GLOVE)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MACH_PUNCH, player);
        else
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MACH_PUNCH, player);
    }
}
