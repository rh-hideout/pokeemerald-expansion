#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Shell Bell restores 1/8 HP of damage dealt")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(16); Item(ITEM_SHELL_BELL); HP(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(16); };
    } WHEN {
        TURN { MOVE(player, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, player);
        HP_BAR(opponent);
        HP_BAR(player, damage: -2);
    }
}

SINGLE_BATTLE_TEST("Shell Bell doesn't restore HP for damage dealt by a foreseen move")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_FUTURE_SIGHT].effect == EFFECT_FUTURE_SIGHT);
        PLAYER(SPECIES_WOBBUFFET) { Level(16); Item(ITEM_SHELL_BELL); HP(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(16); };
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { }
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("The opposing Wobbuffet took the Future Sight attack!");
        HP_BAR(opponent);
        NONE_OF {
            HP_BAR(player);
        }
    }
}
