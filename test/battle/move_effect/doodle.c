#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_DOODLE) == EFFECT_DOODLE);
}

DOUBLE_BATTLE_TEST("Doodle gives the target's ability to user and ally")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DOODLE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, playerLeft);
        MESSAGE("Wynaut copied the opposing Torchic's Ability!");
        MESSAGE("Wynaut copied the opposing Torchic's Ability!");
    } THEN {
        EXPECT(playerLeft->ability == ABILITY_BLAZE);
        EXPECT(playerRight->ability == ABILITY_BLAZE);
    }
}

DOUBLE_BATTLE_TEST("Doodle can't copy a banned ability")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GREAT_TUSK) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DOODLE, target: opponentLeft); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, playerLeft);
            MESSAGE("Wynaut copied the opposing Great Tusk's Ability!");
            MESSAGE("Wynaut copied the opposing Great Tusk's Ability!");
        }
    } THEN {
        EXPECT(playerLeft->ability != ABILITY_PROTOSYNTHESIS);
        EXPECT(playerRight->ability != ABILITY_PROTOSYNTHESIS);
    }
}

DOUBLE_BATTLE_TEST("Doodle fails if both user and partner have a banned ability")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DOODLE, target: opponentLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, playerLeft);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(playerLeft->ability == ABILITY_GULP_MISSILE);
        EXPECT(playerRight->ability == ABILITY_SHADOW_TAG);
    }
}

DOUBLE_BATTLE_TEST("Doodle will change either user's or partner's ability if one can't be changed")
{
    enum Species speciesAtk;
    enum Ability abilityAtk;

    enum Species speciesPartner;
    enum Ability abilityPartner;

    PARAMETRIZE {
        speciesAtk = SPECIES_CRAMORANT;      abilityAtk = ABILITY_GULP_MISSILE;
        speciesPartner = SPECIES_WYNAUT; abilityPartner = ABILITY_SHADOW_TAG;
    }
    PARAMETRIZE {
        speciesAtk = SPECIES_WYNAUT; abilityAtk = ABILITY_SHADOW_TAG;
        speciesPartner = SPECIES_CRAMORANT; abilityPartner = ABILITY_GULP_MISSILE;
    }

    GIVEN {
        PLAYER(speciesAtk) { Ability(abilityAtk); }
        PLAYER(speciesPartner) { Ability(abilityPartner); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DOODLE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, playerLeft);
        if (speciesAtk == SPECIES_WYNAUT) {
            MESSAGE("Wynaut copied the opposing Torchic's Ability!");
            NOT MESSAGE("Cramorant copied the opposing Torchic's Ability!");
        } else {
            NOT MESSAGE("Wynaut copied the opposing Torchic's Ability!");
            MESSAGE("Cramorant copied the opposing Torchic's Ability!");
        }
    } THEN {
        if (speciesAtk == SPECIES_WYNAUT) {
            EXPECT(playerLeft->ability == ABILITY_BLAZE);
            EXPECT(playerRight->ability == ABILITY_GULP_MISSILE);
        } else {
            EXPECT(playerLeft->ability == ABILITY_GULP_MISSILE);
            EXPECT(playerRight->ability == ABILITY_BLAZE);
        }
    }
}

DOUBLE_BATTLE_TEST("Doodle doesn't change the ability if user or partner have an Ability Shield")
{
    enum Item itemAttacker = ITEM_NONE;
    enum Item itemPartner = ITEM_NONE;

    PARAMETRIZE { itemAttacker = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { itemPartner = ITEM_ABILITY_SHIELD; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(itemAttacker); }
        PLAYER(SPECIES_WYNAUT) { Item(itemPartner); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DOODLE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, playerLeft);
        if (itemAttacker == ITEM_ABILITY_SHIELD) {
            MESSAGE("Wobbuffet copied the opposing Torchic's Ability!");
            NOT MESSAGE("Wynaut copied the opposing Torchic's Ability!");
        } else {
            NOT MESSAGE("Wobbuffet copied the opposing Torchic's Ability!");
            MESSAGE("Wynaut copied the opposing Torchic's Ability!");
        }
    } THEN {
        EXPECT(playerLeft->ability == ABILITY_GULP_MISSILE);
        EXPECT(playerRight->ability == ABILITY_SHADOW_TAG);
    }
}

