#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Smack Down does not ground mons behind substitutes")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SMACK_DOWN, MOVE_EFFECT_SMACK_DOWN) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SKARMORY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_SMACK_DOWN); }
    } SCENE {
        NOT MESSAGE("The opposing Skarmory fell straight down!");
    }
}

SINGLE_BATTLE_TEST("Thousand Arrows does not ground mons behind substitutes")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_THOUSAND_ARROWS, MOVE_EFFECT_SMACK_DOWN));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SKARMORY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_THOUSAND_ARROWS); }
    } SCENE {
        NOT MESSAGE("The opposing Skarmory fell straight down!");
    }
}
