#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MILK_DRINK) == EFFECT_MILK_DRINK);
    ASSUME(GetMoveTarget(MOVE_MILK_DRINK) == TARGET_USER_OR_ALLY);
}

SINGLE_BATTLE_TEST("Milk Drink heals the user for 50% HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MILK_DRINK, target: player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MILK_DRINK, player);
        HP_BAR(player);
    } THEN {
        EXPECT(player->hp == 51);
    }
}

DOUBLE_BATTLE_TEST("Milk Drink heals the partner for 50% HP")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_MOVE_DATA, GEN_CHAMPIONS);
        ASSUME(GetMoveTarget(MOVE_MILK_DRINK) == TARGET_USER_OR_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MILK_DRINK, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MILK_DRINK, playerLeft);
        HP_BAR(playerRight);
    } THEN {
        EXPECT(playerRight->hp == 51);
    }
}

DOUBLE_BATTLE_TEST("Milk Drink heals the partner through protect")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_MOVE_DATA, GEN_CHAMPIONS);
        ASSUME(GetMoveTarget(MOVE_MILK_DRINK) == TARGET_USER_OR_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_PROTECT); MOVE(playerLeft, MOVE_MILK_DRINK, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MILK_DRINK, playerLeft);
        HP_BAR(playerRight);
    } THEN {
        EXPECT(playerRight->hp == 51);
    }
}
