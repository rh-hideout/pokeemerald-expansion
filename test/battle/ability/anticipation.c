#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Anticipation causes notifies if an opponent has a super-effective move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_CLOSE_COMBAT) == TYPE_FIGHTING);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 1) == TYPE_NORMAL);
        PLAYER(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Moves(MOVE_CLOSE_COMBAT, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation does not trigger even when a move is super effective on only 1 type")
{
    GIVEN {
        PLAYER(TEST_SPECIES_SWAMPERT) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_PIKACHU) { Moves(MOVE_CELEBRATE, MOVE_THUNDERBOLT); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation causes notifies if an opponent has a One-hit KO move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FISSURE) == EFFECT_OHKO);
        PLAYER(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Moves(MOVE_FISSURE, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation treats Self-Destruct and Explosion like all other Normal types (Gen5+)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_EXPLOSION) == EFFECT_EXPLOSION);
        PLAYER(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Moves(MOVE_EXPLOSION, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation doesn't consider Normalize into their effectiveness (Gen5+)")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_CLOSE_COMBAT) == TYPE_FIGHTING);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 1) == TYPE_NORMAL);
        PLAYER(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_SNORLAX) { Ability(ABILITY_NORMALIZE); Moves(MOVE_CLOSE_COMBAT, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation doesn't consider Scrappy into their effectiveness (Gen5+)")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_CLOSE_COMBAT) == TYPE_FIGHTING);
        ASSUME(GetSpeciesType(TEST_SPECIES_DUSKNOIR, 0) == TYPE_GHOST);
        ASSUME(GetSpeciesType(TEST_SPECIES_DUSKNOIR, 1) == TYPE_GHOST);
        PLAYER(TEST_SPECIES_DUSKNOIR) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_SNORLAX) { Ability(ABILITY_SCRAPPY); Moves(MOVE_CLOSE_COMBAT, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation doesn't consider Gravity into their effectiveness (Gen5+)")
{
    GIVEN {
        ASSUME(GetSpeciesType(TEST_SPECIES_CORVISQUIRE, 0) == TYPE_FLYING);
        ASSUME(GetSpeciesType(TEST_SPECIES_CORVISQUIRE, 1) == TYPE_FLYING);
        PLAYER(TEST_SPECIES_CORVISQUIRE);
        OPPONENT(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); Moves(MOVE_EARTHQUAKE, MOVE_GRAVITY, MOVE_SCRATCH, MOVE_POUND); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRAVITY); MOVE(player, MOVE_SKILL_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRAVITY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation counts Counter, Metal Burst or Mirror Coat as attacking moves of their types (Gen5+)")
{
    u32 move, species;
    enum Type typeAtk, typeDef;
    PARAMETRIZE { move = MOVE_COUNTER;     species = TEST_SPECIES_SNORLAX;   typeAtk = TYPE_FIGHTING; typeDef = TYPE_NORMAL; }
    PARAMETRIZE { move = MOVE_METAL_BURST; species = TEST_SPECIES_GARGANACL; typeAtk = TYPE_STEEL;    typeDef = TYPE_ROCK; }
    PARAMETRIZE { move = MOVE_MIRROR_COAT; species = TEST_SPECIES_WEEZING;   typeAtk = TYPE_PSYCHIC;  typeDef = TYPE_POISON; }
    GIVEN {
        ASSUME(GetMoveType(move) == typeAtk);
        ASSUME(GetSpeciesType(species, 0) == typeDef);
        ASSUME(GetSpeciesType(species, 1) == typeDef);
        PLAYER(species);
        OPPONENT(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); Moves(move, MOVE_SKILL_SWAP, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation considers Synchronoise as an ordinary Psychic-type move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SYNCHRONOISE) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(TEST_SPECIES_WEEZING, 0) == TYPE_POISON);
        ASSUME(GetSpeciesType(TEST_SPECIES_WEEZING, 1) == TYPE_POISON);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 0) != TYPE_POISON);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 1) != TYPE_POISON);
        PLAYER(TEST_SPECIES_WEEZING);
        OPPONENT(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); Moves(MOVE_SYNCHRONOISE, MOVE_SKILL_SWAP, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation considers Freeze-Dry as an ordinary Ice-type move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_FREEZE_DRY) == TYPE_ICE);
        ASSUME(GetSpeciesType(TEST_SPECIES_BLASTOISE, 0) == TYPE_WATER);
        ASSUME(GetSpeciesType(TEST_SPECIES_BLASTOISE, 1) == TYPE_WATER);
        PLAYER(TEST_SPECIES_BLASTOISE);
        OPPONENT(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); Moves(MOVE_FREEZE_DRY, MOVE_SKILL_SWAP, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation considers Flying Press as an ordinary Fighting-type move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_FLYING_PRESS) == TYPE_FIGHTING);
        ASSUME(GetSpeciesType(TEST_SPECIES_MEGANIUM, 0) == TYPE_GRASS);
        ASSUME(GetSpeciesType(TEST_SPECIES_MEGANIUM, 1) == TYPE_GRASS);
        PLAYER(TEST_SPECIES_MEGANIUM);
        OPPONENT(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); Moves(MOVE_FLYING_PRESS, MOVE_SKILL_SWAP, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation considers Aura Wheel as an ordinary Electric-type move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_AURA_WHEEL) == TYPE_ELECTRIC);
        ASSUME(GetSpeciesType(TEST_SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(TEST_SPECIES_WOBBUFFET, 1) == TYPE_PSYCHIC);
        PLAYER(TEST_SPECIES_WOBBUFFET);
        PLAYER(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(SPECIES_MORPEKO) { Ability(ABILITY_HUNGER_SWITCH); Moves(MOVE_AURA_WHEEL, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation treats dynamic move types as their base type (Normal), Judgment")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_JUDGMENT) == EFFECT_CHANGE_TYPE_ON_ITEM);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 1) == TYPE_NORMAL);
        PLAYER(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_SNORLAX) { Item(ITEM_FIST_PLATE); Moves(MOVE_JUDGMENT, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation treats dynamic move types as their base type (Normal), Weather Ball")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WEATHER_BALL) == EFFECT_WEATHER_BALL);
        ASSUME(GetSpeciesType(TEST_SPECIES_REGISTEEL, 0) == TYPE_STEEL);
        ASSUME(GetSpeciesType(TEST_SPECIES_REGISTEEL, 1) == TYPE_STEEL);
        PLAYER(TEST_SPECIES_REGISTEEL) { Ability(ABILITY_ANTICIPATION); Speed(2); }
        OPPONENT(TEST_SPECIES_ENTEI) { Ability(ABILITY_DROUGHT); Moves(MOVE_WEATHER_BALL, MOVE_SKILL_SWAP, MOVE_POUND, MOVE_CELEBRATE); Speed(4); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); MOVE(player, MOVE_SKILL_SWAP); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation treats dynamic move types as their base type (Normal), Natural Gift")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NATURAL_GIFT) == EFFECT_NATURAL_GIFT);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 1) == TYPE_NORMAL);
        PLAYER(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Item(ITEM_LEPPA_BERRY); Moves(MOVE_NATURAL_GIFT, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation treats dynamic move types as their base type (Normal), Techno Blast")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TECHNO_BLAST) == EFFECT_CHANGE_TYPE_ON_ITEM);
        ASSUME(GetSpeciesType(TEST_SPECIES_REGISTEEL, 0) == TYPE_STEEL);
        ASSUME(GetSpeciesType(TEST_SPECIES_REGISTEEL, 1) == TYPE_STEEL);
        PLAYER(TEST_SPECIES_REGISTEEL) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_PINSIR) { Item(ITEM_BURN_DRIVE); Moves(MOVE_TECHNO_BLAST, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation treats dynamic move types as their base type (Normal), Revelation Dance")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_REVELATION_DANCE) == EFFECT_REVELATION_DANCE);
        ASSUME(GetSpeciesType(TEST_SPECIES_REGISTEEL, 0) == TYPE_STEEL);
        ASSUME(GetSpeciesType(TEST_SPECIES_REGISTEEL, 1) == TYPE_STEEL);
        ASSUME(GetSpeciesType(TEST_SPECIES_ENTEI, 0) == TYPE_FIRE);
        PLAYER(TEST_SPECIES_REGISTEEL) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_ENTEI) { Moves(MOVE_REVELATION_DANCE, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation treats dynamic move types as their base type (Normal), Multi-Attack")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MULTI_ATTACK) == EFFECT_CHANGE_TYPE_ON_ITEM);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 1) == TYPE_NORMAL);
        PLAYER(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_SNORLAX) { Item(ITEM_FIGHTING_MEMORY); Moves(MOVE_MULTI_ATTACK, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation does not consider Strong Winds on type matchups")
{
    GIVEN {
        ASSUME(GetSpeciesType(TEST_SPECIES_CORVISQUIRE, 0) == TYPE_FLYING);
        ASSUME(GetSpeciesType(TEST_SPECIES_CORVISQUIRE, 1) == TYPE_FLYING);
        PLAYER(TEST_SPECIES_CORVISQUIRE) { Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); Moves(MOVE_ROCK_SLIDE, MOVE_SKILL_SWAP, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DELTA_STREAM);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation does not consider ate-abilities")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(TEST_SPECIES_MEGANIUM, 0) == TYPE_GRASS);
        ASSUME(GetSpeciesType(TEST_SPECIES_MEGANIUM, 1) == TYPE_GRASS);
        PLAYER(TEST_SPECIES_MEGANIUM) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_REGICE) { Ability(ABILITY_REFRIGERATE); Moves(MOVE_GROWL, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

SINGLE_BATTLE_TEST("Anticipation treats Hidden Power as its dynamic type (Gen6+)")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(TEST_SPECIES_SNORLAX, 1) == TYPE_NORMAL);
        PLAYER(TEST_SPECIES_SNORLAX) { Ability(ABILITY_ANTICIPATION); Item(ITEM_CHOPLE_BERRY); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Moves(MOVE_HIDDEN_POWER, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); HPIV(30); AttackIV(2); DefenseIV(31); SpAttackIV(30); SpDefenseIV(30); SpeedIV(30); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ANTICIPATION);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent); // Check that the item is triggered
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER, opponent);
        HP_BAR(opponent);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Anticipation considers Inverse Battle types")
{
    GIVEN {
        FLAG_SET(B_FLAG_INVERSE_BATTLE);
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(TEST_SPECIES_REGISTEEL, 0) == TYPE_STEEL);
        ASSUME(GetSpeciesType(TEST_SPECIES_REGISTEEL, 1) == TYPE_STEEL);
        PLAYER(TEST_SPECIES_REGISTEEL) { Ability(ABILITY_ANTICIPATION); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Moves(MOVE_GROWL, MOVE_SCRATCH, MOVE_POUND, MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ANTICIPATION);
    }
}

TO_DO_BATTLE_TEST("Anticipation causes notifies if an opponent has a Self-Destruct or Explosion (Gen4)");
TO_DO_BATTLE_TEST("Anticipation considers Scrappy and Normalize into their effectiveness (Gen4)");
TO_DO_BATTLE_TEST("Anticipation considers Gravity into their effectiveness (Gen4)");
TO_DO_BATTLE_TEST("Anticipation doesn't trigger from Counter, Metal Burst or Mirror Coat (Gen4)");
TO_DO_BATTLE_TEST("Anticipation treats Hidden Power as Normal Type (Gen4-5)");
