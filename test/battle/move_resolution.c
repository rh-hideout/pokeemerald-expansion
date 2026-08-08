#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Moves hitting into Substitute and non-Substitute trigger effects on Substitute battler first")
{
    struct BattlePokemon *substituteUser = NULL;
    enum BattlerId substituteUserBattlerId;

    PARAMETRIZE { substituteUser = opponentLeft; substituteUserBattlerId = B_POSITION_OPPONENT_LEFT; }
    PARAMETRIZE { substituteUser = opponentRight; substituteUserBattlerId = B_POSITION_OPPONENT_RIGHT; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        ASSUME(GetItemHoldEffect(ITEM_AIR_BALLOON) == HOLD_EFFECT_AIR_BALLOON);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_AIR_BALLOON); }
    } WHEN {
        TURN { MOVE(substituteUser, MOVE_SUBSTITUTE); MOVE(playerLeft, MOVE_SURF, criticalHit: TRUE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        SUB_HIT(substituteUser);
        if (substituteUserBattlerId == B_POSITION_OPPONENT_LEFT) {
            MESSAGE("The substitute took damage for the opposing Wobbuffet!");
            MESSAGE("A critical hit on the opposing Wobbuffet!");
            MESSAGE("The opposing Wobbuffet's Air Balloon popped!");
            MESSAGE("A critical hit on the opposing Wynaut!");
            MESSAGE("The opposing Wynaut's Air Balloon popped!");
        } else {
            MESSAGE("The substitute took damage for the opposing Wynaut!");
            MESSAGE("A critical hit on the opposing Wynaut!");
            MESSAGE("The opposing Wynaut's Air Balloon popped!");
            MESSAGE("A critical hit on the opposing Wobbuffet!");
            MESSAGE("The opposing Wobbuffet's Air Balloon popped!");
        }
    }
}
