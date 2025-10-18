#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Minior Meteor transforms into Minior Core on switch-in if it has 1/2 or less health")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_MINIOR_METEOR) { Ability(ABILITY_SHIELDS_DOWN); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_CORE);
    }
}

SINGLE_BATTLE_TEST("Minior Core transforms into Minior Meteor on switch-in if it more then 1/2 health")
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

SINGLE_BATTLE_TEST("Shields Down protects Minior Meteor from status conditions")
{
    u32 species, hp;
    PARAMETRIZE { species = SPECIES_MINIOR_METEOR; hp = 300; }
    PARAMETRIZE { species = SPECIES_MINIOR_CORE; hp = 100; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(species) { Ability(ABILITY_SHIELDS_DOWN); HP(hp); MaxHP(300); }
    } WHEN {
        TURN { MOVE(player, MOVE_WILL_O_WISP); }
    } SCENE {
        if (species == SPECIES_MINIOR_METEOR)
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
    } THEN {
        if (species == SPECIES_MINIOR_METEOR)
            EXPECT_EQ(opponent->status1, STATUS1_NONE);
        else
            EXPECT(opponent->status1 & STATUS1_BURN);
    }
}
