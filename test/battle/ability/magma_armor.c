#include "global.h"
#include "test/battle.h"


SINGLE_BATTLE_TEST("Magma Armor prevents freezing from physical and special attacks")
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { ability = ABILITY_SOLID_ROCK; move = MOVE_ICE_PUNCH; }
    PARAMETRIZE { ability = ABILITY_MAGMA_ARMOR; move = MOVE_ICE_PUNCH; }
    PARAMETRIZE { ability = ABILITY_SOLID_ROCK; move = MOVE_ICE_BEAM; }
    PARAMETRIZE { ability = ABILITY_MAGMA_ARMOR; move = MOVE_ICE_BEAM; }
    GIVEN {
        ASSUME(!B_USE_FROSTBITE);
        PLAYER(SPECIES_CAMERUPT) { Ability(ability); MaxHP(1000); HP(1000); Speed(100); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->status1, ability == ABILITY_MAGMA_ARMOR ? STATUS1_NONE : STATUS1_FREEZE);
    }
}

SINGLE_BATTLE_TEST("Magma Armor cures an existing freeze when gained through Skill Swap")
{
    GIVEN {
        PLAYER(SPECIES_CAMERUPT) { Ability(ABILITY_MAGMA_ARMOR); Speed(100); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Status1(STATUS1_FREEZE); MaxHP(1000); HP(1000); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_SKILL_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        STATUS_ICON(opponent, freeze: FALSE);
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_MAGMA_ARMOR);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
        EXPECT_EQ(opponent->hp, 1000);
    }
}

SINGLE_BATTLE_TEST("Magma Armor no longer prevents freezing while suppressed")
{
    bool32 suppress;
    PARAMETRIZE { suppress = FALSE; }
    PARAMETRIZE { suppress = TRUE; }
    GIVEN {
        ASSUME(!B_USE_FROSTBITE);
        PLAYER(SPECIES_CAMERUPT) { Ability(ABILITY_MAGMA_ARMOR); MaxHP(1000); HP(1000); Speed(100); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Speed(50); }
    } WHEN {
        if (suppress)
            TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(opponent, MOVE_ICE_BEAM); }
    } THEN {
        EXPECT_EQ(player->status1, suppress ? STATUS1_FREEZE : STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Magma Armor does not prevent poison or paralysis")
{
    enum Move move;
    u32 status;
    PARAMETRIZE { move = MOVE_POISON_POWDER; status = STATUS1_POISON; }
    PARAMETRIZE { move = MOVE_STUN_SPORE; status = STATUS1_PARALYSIS; }
    GIVEN {
        PLAYER(SPECIES_CAMERUPT) { Ability(ABILITY_MAGMA_ARMOR); MaxHP(1000); HP(1000); Speed(100); }
        OPPONENT(SPECIES_VILEPLUME) { Ability(ABILITY_CHLOROPHYLL); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, move); }
    } THEN {
        EXPECT_EQ(player->status1, status);
    }
}

SINGLE_BATTLE_TEST("Magma Armor does not reduce Ice-type damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SOLID_ROCK; }
    PARAMETRIZE { ability = ABILITY_MAGMA_ARMOR; }
    GIVEN {
        PLAYER(SPECIES_CAMERUPT) { Ability(ability); MaxHP(1000); HP(1000); Speed(100); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ICE_BEAM); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, 0);
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
