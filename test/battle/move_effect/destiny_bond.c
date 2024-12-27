#include "global.h"
#include "test/battle.h"

ASSUMPTIONS 
{
    ASSUME(gMovesInfo[MOVE_DESTINY_BOND].effect == EFFECT_DESTINY_BOND);
}

SINGLE_BATTLE_TEST("Destiny Bond faints the opposing mon if it fainted from the attack")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Wobbuffet took its attacker down with it!");
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Destiny Bond fails if used sequentially in Gen 7+")
{
    GIVEN {
        ASSUME(B_DESTINY_BOND_FAIL >= GEN_7);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); }
        TURN { MOVE(player, MOVE_DESTINY_BOND); SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        MESSAGE("2 sent out Zigzagoon!");
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player); }
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Destiny Bond does not fail if used repeatedly separated by other moves in Gen 7+")
{
    GIVEN {
        ASSUME(B_DESTINY_BOND_FAIL >= GEN_7);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); }
        TURN { MOVE(player, MOVE_GROWL); SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_DESTINY_BOND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        MESSAGE("2 sent out Zigzagoon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        NOT { MESSAGE("But it failed!"); }
    }
}

SINGLE_BATTLE_TEST("Destiny Bond does not fail if used after failing in Gen 7+")
{
    GIVEN {
        ASSUME(B_DESTINY_BOND_FAIL >= GEN_7);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); }
        TURN { MOVE(player, MOVE_DESTINY_BOND); SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_DESTINY_BOND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        MESSAGE("2 sent out Zigzagoon!");
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player); }
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
    }
}
