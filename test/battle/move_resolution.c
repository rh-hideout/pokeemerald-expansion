#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Moves hitting all other battlers activate all effects on allies, then effects on opponents")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        ASSUME(GetItemHoldEffect(ITEM_AIR_BALLOON) == HOLD_EFFECT_AIR_BALLOON);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_AIR_BALLOON); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SURF, criticalHit: TRUE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        MESSAGE("A critical hit on Wobbuffet!");
        MESSAGE("Wobbuffet's Air Balloon popped!");
        MESSAGE("A critical hit on the opposing Wobbuffet!");
        MESSAGE("A critical hit on the opposing Wynaut!");
        MESSAGE("The opposing Wobbuffet's Air Balloon popped!");
        MESSAGE("The opposing Wynaut's Air Balloon popped!");
    }
}

DOUBLE_BATTLE_TEST("Moves hitting all other battlers print effectiveness messages for allies, then opponents, from most effective to least")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_SURF) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_CHARMANDER, 0) == TYPE_FIRE || GetSpeciesType(SPECIES_CHARMANDER, 1) == TYPE_FIRE);
        ASSUME(GetSpeciesType(SPECIES_SQUIRTLE, 0) == TYPE_WATER || GetSpeciesType(SPECIES_SQUIRTLE, 1) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_LUDICOLO, 0) == TYPE_WATER && GetSpeciesType(SPECIES_LUDICOLO, 1) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CHARMANDER);
        OPPONENT(SPECIES_LUDICOLO);
        OPPONENT(SPECIES_SQUIRTLE);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        MESSAGE("It's super effective on Charmander!");
        MESSAGE("It's not very effective on the opposing Squirtle.");
        MESSAGE("It's mostly ineffective on the opposing Ludicolo.");
    }
}

DOUBLE_BATTLE_TEST("Moves hitting both opponents trigger effects on Left opponent then Right, then the next effect with same order")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        ASSUME(GetItemHoldEffect(ITEM_AIR_BALLOON) == HOLD_EFFECT_AIR_BALLOON);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_AIR_BALLOON); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SURF, criticalHit: TRUE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        MESSAGE("A critical hit on the opposing Wobbuffet!");
        MESSAGE("A critical hit on the opposing Wynaut!");
        MESSAGE("The opposing Wobbuffet's Air Balloon popped!");
        MESSAGE("The opposing Wynaut's Air Balloon popped!");
    }
}

DOUBLE_BATTLE_TEST("Moves hitting into Substitute and non-Substitute trigger effects on Substitute battler first")
{
    struct BattlePokemon *substituteUser = NULL;
    enum BattlerPosition substituteUserBattlerPosition;

    PARAMETRIZE { substituteUser = opponentLeft; substituteUserBattlerPosition = B_POSITION_OPPONENT_LEFT; }
    PARAMETRIZE { substituteUser = opponentRight; substituteUserBattlerPosition = B_POSITION_OPPONENT_RIGHT; }

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
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, substituteUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        SUB_HIT(substituteUser);
        if (substituteUserBattlerPosition == B_POSITION_OPPONENT_LEFT) {
            MESSAGE("A critical hit on the opposing Wobbuffet!");
            MESSAGE("The substitute took damage for the opposing Wobbuffet!");
            MESSAGE("The opposing Wobbuffet's Air Balloon popped!");
            MESSAGE("A critical hit on the opposing Wynaut!");
            MESSAGE("The opposing Wynaut's Air Balloon popped!");
        } else {
            MESSAGE("A critical hit on the opposing Wynaut!");
            MESSAGE("The substitute took damage for the opposing Wynaut!");
            MESSAGE("The opposing Wynaut's Air Balloon popped!");
            MESSAGE("A critical hit on the opposing Wobbuffet!");
            MESSAGE("The opposing Wobbuffet's Air Balloon popped!");
        }
    }
}
