#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_HYPER_BEAM, MOVE_EFFECT_RECHARGE) == TRUE);
}

#if B_SKIP_RECHARGE != GEN_1

SINGLE_BATTLE_TEST("User must recharge after using a recharge move") //ie. Hyper Beam
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_HYPER_BEAM); }
        OPPONENT(SPECIES_CHANSEY) { MaxHP(999); HP(900); }
    } WHEN {
        TURN { MOVE(player, MOVE_HYPER_BEAM); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_BEAM, player);
        HP_BAR(opponent);
        MESSAGE("Wobbuffet must recharge!");
    }
}

#else

SINGLE_BATTLE_TEST("Recharge is skipped if target is KO'd") //gen1 only
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_HYPER_BEAM); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_HYPER_BEAM); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_BEAM, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet fainted!");
        NONE_OF { MESSAGE("Wobbuffet must recharge!"); }
    }
}

SINGLE_BATTLE_TEST("Recharge is not skipped if target is not KO'd") //gen1 only
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_HYPER_BEAM); }
        OPPONENT(SPECIES_CHANSEY) { MaxHP(999); HP(900); }
    } WHEN {
        TURN { MOVE(player, MOVE_HYPER_BEAM); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_BEAM, player);
        HP_BAR(opponent);
        MESSAGE("Wobbuffet must recharge!");
    }
}

#endif
