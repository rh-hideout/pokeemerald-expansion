#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ATTRACT) == EFFECT_ATTRACT);
    ASSUME(GetSpeciesGenderRatio(SPECIES_NIDOKING) == MON_MALE);
    ASSUME(GetSpeciesGenderRatio(SPECIES_NIDOQUEEN) == MON_FEMALE);
}

SINGLE_BATTLE_TEST("Attract causes the target to become infatuated with the user if they have opposite genders")
{
    GIVEN {
        PLAYER(SPECIES_NIDOQUEEN);
        OPPONENT(SPECIES_NIDOKING);
    } WHEN {
        TURN { MOVE(player, MOVE_ATTRACT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ATTRACT, player);
        MESSAGE("The opposing Nidoking fell in love!");
    } THEN {
        EXPECT(opponent->volatiles.infatuation);
    }
}

SINGLE_BATTLE_TEST("Attract ignores type immunity")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_ATTRACT) == TYPE_NORMAL);
        PLAYER(SPECIES_NIDOQUEEN);
        OPPONENT(SPECIES_MISDREAVUS) { Gender(MON_MALE); }
    } WHEN {
        TURN { MOVE(player, MOVE_ATTRACT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ATTRACT, player);
        MESSAGE("The opposing Misdreavus fell in love!");
    } THEN {
        EXPECT(opponent->volatiles.infatuation);
    }
}

SINGLE_BATTLE_TEST("Attract bypasses Substitute")
{
    GIVEN {
        PLAYER(SPECIES_NIDOQUEEN) { Speed(90); }
        OPPONENT(SPECIES_NIDOKING) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_ATTRACT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ATTRACT, player);
        MESSAGE("The opposing Nidoking fell in love!");
    } THEN {
        EXPECT(opponent->volatiles.infatuation);
    }
}

SINGLE_BATTLE_TEST("Attract fails if the target is already infatuated")
{
    GIVEN {
        PLAYER(SPECIES_NIDOQUEEN);
        OPPONENT(SPECIES_NIDOKING);
    } WHEN {
        TURN { MOVE(player, MOVE_ATTRACT); }
        TURN { MOVE(player, MOVE_ATTRACT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ATTRACT, player);
        MESSAGE("The opposing Nidoking fell in love!");
        MESSAGE("Nidoqueen used Attract!");
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(opponent->volatiles.infatuation);
    }
}

SINGLE_BATTLE_TEST("Attract fails when used on a Pokémon of the same gender")
{
    GIVEN {
        PLAYER(SPECIES_NIDOQUEEN);
        OPPONENT(SPECIES_NIDOQUEEN);
    } WHEN {
        TURN { MOVE(player, MOVE_ATTRACT); }
    } SCENE {
        MESSAGE("Nidoqueen used Attract!");
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(!(opponent->volatiles.infatuation));
    }
}

SINGLE_BATTLE_TEST("Attract fails when used on a genderless Pokémon")
{
    GIVEN {
        ASSUME(GetSpeciesGenderRatio(SPECIES_STARMIE) == MON_GENDERLESS);
        PLAYER(SPECIES_NIDOQUEEN);
        OPPONENT(SPECIES_STARMIE);
    } WHEN {
        TURN { MOVE(player, MOVE_ATTRACT); }
    } SCENE {
        MESSAGE("Nidoqueen used Attract!");
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(!(opponent->volatiles.infatuation));
    }
}
