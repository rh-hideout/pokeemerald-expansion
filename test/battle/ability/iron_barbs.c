#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Iron Barbs: Damages attackers that make contact")
{
    const u32 maxHP = 800;
    const u32 ironBarbsDamage = maxHP / 8;

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_POPULATION_BOMB));
        ASSUME(GetMoveEffect(MOVE_POPULATION_BOMB) == EFFECT_POPULATION_BOMB);
        ASSUME(GetItemHoldEffect(ITEM_LOADED_DICE) == HOLD_EFFECT_LOADED_DICE);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(maxHP); HP(maxHP); Item(ITEM_LOADED_DICE); }
        OPPONENT(SPECIES_FERROSEED) { Ability(ABILITY_IRON_BARBS); }
    } WHEN {
        TURN { MOVE(player, MOVE_POPULATION_BOMB, WITH_RNG(RNG_LOADED_DICE, 4)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        MESSAGE("The Pokémon was hit 4 times!");
        NONE_OF {
            HP_BAR(player);
            MESSAGE("Wobbuffet was hurt by the opposing Ferroseed's Iron Barbs!");
        }
    } THEN {
        EXPECT_EQ(player->hp, maxHP - ironBarbsDamage * 4);
    }
}

SINGLE_BATTLE_TEST("Rough Skin and Iron Barbs cause the attacker to take damage when using a contact move")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_GARCHOMP; ability = ABILITY_ROUGH_SKIN; }
    PARAMETRIZE { species = SPECIES_FERROTHORN; ability = ABILITY_IRON_BARBS; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (ability == ABILITY_ROUGH_SKIN)
            ABILITY_POPUP(opponent, ABILITY_ROUGH_SKIN);
        else
            ABILITY_POPUP(opponent, ABILITY_IRON_BARBS);
    }
}

SINGLE_BATTLE_TEST("Iron Barbs damages an attacker for one eighth of its maximum HP per contact hit")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(800); HP(800); }
        OPPONENT(SPECIES_FERROSEED) { Ability(ABILITY_IRON_BARBS); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent);
        HP_BAR(player, damage: 100);
    } THEN {
        EXPECT_EQ(player->hp, 700);
    }
}

SINGLE_BATTLE_TEST("Iron Barbs does not damage an attacker using a non-contact move")
{
    GIVEN {
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(800); HP(800); }
        OPPONENT(SPECIES_FERROSEED) { Ability(ABILITY_IRON_BARBS); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } SCENE {
        HP_BAR(opponent);
        NOT HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, 800);
    }
}

SINGLE_BATTLE_TEST("Iron Barbs does not trigger when a Substitute takes the contact hit")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Attack(1); MaxHP(800); HP(800); }
        OPPONENT(SPECIES_FERROSEED) { Ability(ABILITY_IRON_BARBS); Defense(200); MaxHP(1000); HP(1000); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, damage: 250);
        NOT HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, 800);
        EXPECT_EQ(opponent->hp, 750);
    }
}

SINGLE_BATTLE_TEST("Iron Barbs triggers when its user faints to the contact hit")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(800); HP(800); }
        OPPONENT(SPECIES_FERROSEED) { Ability(ABILITY_IRON_BARBS); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
        HP_BAR(player, damage: 100);
    } THEN {
        EXPECT_EQ(player->hp, 700);
    }
}

SINGLE_BATTLE_TEST("Iron Barbs can faint the attacker")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(800); HP(100); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_FERROSEED) { Ability(ABILITY_IRON_BARBS); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } SCENE {
        HP_BAR(opponent);
        HP_BAR(player, hp: 0);
    }
}

SINGLE_BATTLE_TEST("Iron Barbs does not damage the attacker while suppressed")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); MaxHP(800); HP(800); }
        OPPONENT(SPECIES_FERROSEED) { Ability(ABILITY_IRON_BARBS); }
    } WHEN {
        TURN { MOVE(player, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent);
        NOT HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, 800);
    }
}
