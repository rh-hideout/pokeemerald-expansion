#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
    ASSUME(GetMoveEffect(MOVE_MAGIC_POWDER) == EFFECT_SOAK);
}

SINGLE_BATTLE_TEST("Soak/Magic Powder changes the target's type to pure Water/Psychic")
{
    enum Move move;
    enum Type type;

    PARAMETRIZE { move = MOVE_SOAK; type = TYPE_WATER; }
    PARAMETRIZE { move = MOVE_MAGIC_POWDER; type = TYPE_PSYCHIC; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 0) == TYPE_ROCK);
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 1) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLEM);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        switch (move) {
            case MOVE_SOAK:         MESSAGE("The opposing Golem transformed into the Water type!"); break;
            case MOVE_MAGIC_POWDER: MESSAGE("The opposing Golem transformed into the Psychic type!"); break;
            default: break;
        }
    } THEN {
        EXPECT_EQ(opponent->types[0], type);
        EXPECT_EQ(opponent->types[1], type);
    }
}

SINGLE_BATTLE_TEST("Soak/Magic Powder's type change is overwitten if the target changes form")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SOAK; }
    PARAMETRIZE { move = MOVE_MAGIC_POWDER; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        switch (move) {
            case MOVE_SOAK:         MESSAGE("Mimikyu transformed into the Water type!"); break;
            case MOVE_MAGIC_POWDER: MESSAGE("Mimikyu transformed into the Psychic type!"); break;
            default: break;
        }
        // Turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT MESSAGE("It doesn't affect Mimikyu…");
        ABILITY_POPUP(player, ABILITY_DISGUISE);
        // Turn 3
        MESSAGE("It doesn't affect Mimikyu…");
    }
}

SINGLE_BATTLE_TEST("Soak/Magic Powder's type change is overwritten if the target transforms")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SOAK; }
    PARAMETRIZE { move = MOVE_MAGIC_POWDER; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 0) == TYPE_ROCK);
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 1) == TYPE_GROUND);
        PLAYER(SPECIES_GOLEM) { Speed(20); }
        OPPONENT(SPECIES_DITTO) { Speed(10); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponent);
    } THEN {
        EXPECT_EQ(opponent->types[0], TYPE_ROCK);
        EXPECT_EQ(opponent->types[1], TYPE_GROUND);
    }
}

SINGLE_BATTLE_TEST("(TERA) Soak/Magic Powder's type change is overwritten if the target Terastalizes")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SOAK; }
    PARAMETRIZE { move = MOVE_MAGIC_POWDER; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_VINE_WHIP) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLEM) { TeraType(TYPE_FIRE); }
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
        TURN { MOVE(player, MOVE_VINE_WHIP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VINE_WHIP, player);
        MESSAGE("It's not very effective…");
    }
}

SINGLE_BATTLE_TEST("Soak/Magic Powder fails if the target is behind a Substitute")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SOAK; }
    PARAMETRIZE { move = MOVE_MAGIC_POWDER; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_GOLEM) { Speed(20); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(opponent->types[0], TYPE_ROCK);
        EXPECT_EQ(opponent->types[1], TYPE_GROUND);
    }
}

SINGLE_BATTLE_TEST("Soak/Magic Powder fails if the target is already Water/Psychic")
{
    enum Move move;
    enum Species species;

    PARAMETRIZE { move = MOVE_SOAK; species = SPECIES_MAGIKARP; }
    PARAMETRIZE { move = MOVE_MAGIC_POWDER; species = SPECIES_WOBBUFFET; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_MAGIKARP, 0) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_MAGIKARP, 1) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Soak/Magic Powder fails if the target has Multitype or RKS System")
{
    enum Move move;
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { move = MOVE_SOAK; species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { move = MOVE_SOAK; species = SPECIES_SILVALLY; ability = ABILITY_RKS_SYSTEM; }
    PARAMETRIZE { move = MOVE_MAGIC_POWDER; species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { move = MOVE_MAGIC_POWDER; species = SPECIES_SILVALLY; ability = ABILITY_RKS_SYSTEM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("But it failed!");
    }
}
