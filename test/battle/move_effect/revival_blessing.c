#include "global.h"
#include "test/battle.h"

// Note: Since these tests are recorded battle, they don't test the right battle controller
// behaviors. These have been tested in-game, in double, in multi, and in link battles. AI will always
// revive their first fainted party member in order.

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_REVIVAL_BLESSING].effect == EFFECT_REVIVAL_BLESSING);
}

SINGLE_BATTLE_TEST("Revival Blessing revives a chosen fainted party member for the player")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REVIVAL_BLESSING, partyIndex:2); }
    } SCENE {
        MESSAGE("Wobbuffet used Revival Blessing!");
        MESSAGE("Wynaut was revived and is ready to fight again!");
    }
}

SINGLE_BATTLE_TEST("Revival Blessing revives a fainted party member for an opponent")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RAICHU);
        OPPONENT(SPECIES_PICHU) { HP(0); }
        OPPONENT(SPECIES_PIKACHU) { HP(0); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_REVIVAL_BLESSING, partyIndex:1); }
    } SCENE {
        MESSAGE("Foe Raichu used Revival Blessing!");
        MESSAGE("Pichu was revived and is ready to fight again!");
    }
}

SINGLE_BATTLE_TEST("Revival Blessing fails if no party members are fainted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REVIVAL_BLESSING); }
    } SCENE {
        MESSAGE("Wobbuffet used Revival Blessing!");
        MESSAGE("But it failed!");
    }
}

DOUBLE_BATTLE_TEST("Revival Blessing cannot revive a partner's party member")
{
    KNOWN_FAILING;
    struct BattlePokemon *user = NULL;
    gBattleTypeFlags |= BATTLE_TYPE_TWO_OPPONENTS;
    PARAMETRIZE { user = opponentLeft; }
    PARAMETRIZE { user = opponentRight; }
    GIVEN {
        ASSUME((gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) != FALSE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(user, MOVE_REVIVAL_BLESSING, partyIndex:4); }
    } SCENE {
        if (user == opponentLeft) {
            MESSAGE("Foe Wobbuffet used Revival Blessing!");
            MESSAGE("But it failed!");
        } else {
            MESSAGE("Foe Wynaut used Revival Blessing!");
            MESSAGE("Wynaut was revived and is ready to fight again!");
        }
    }
}

DOUBLE_BATTLE_TEST("Revival Blessing doesn't prevent revived battlers from losing their turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentRight);
               MOVE(opponentLeft, MOVE_REVIVAL_BLESSING, partyIndex: 1); }
    } SCENE {
        MESSAGE("Wobbuffet used Tackle!");
        MESSAGE("Foe Wynaut fainted!");
        MESSAGE("Foe Wobbuffet used Revival Blessing!");
        MESSAGE("Wynaut was revived and is ready to fight again!");
        NOT { MESSAGE("Wynaut used Celebrate!"); }
    }
}
