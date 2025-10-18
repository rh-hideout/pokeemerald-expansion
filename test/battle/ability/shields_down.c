#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Minior Core doesn't transform into Minior Meteor on switch-in if it has 1/2 or less health")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_MINIOR_CORE) { Ability(ABILITY_SHIELDS_DOWN); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
        }
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_CORE);
    }
}

SINGLE_BATTLE_TEST("Minior Core transforms into Minior Meteor on switch-in if has it more then 1/2 health")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_MINIOR_CORE) { Ability(ABILITY_SHIELDS_DOWN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_METEOR);
    }
}

SINGLE_BATTLE_TEST("Minior Core transforms into Minior Meteor on battle start if it has more then 1/2 health")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_MINIOR_CORE) { Ability(ABILITY_SHIELDS_DOWN); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_METEOR);
    }
}
