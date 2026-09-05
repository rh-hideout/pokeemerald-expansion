#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Rock Head prevents physical and special recoil without changing damage", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_DOUBLE_EDGE; ability = ABILITY_LIGHTNING_ROD; }
    PARAMETRIZE { move = MOVE_DOUBLE_EDGE; ability = ABILITY_ROCK_HEAD; }
    PARAMETRIZE { move = MOVE_BRAVE_BIRD; ability = ABILITY_LIGHTNING_ROD; }
    PARAMETRIZE { move = MOVE_BRAVE_BIRD; ability = ABILITY_ROCK_HEAD; }
    PARAMETRIZE { move = MOVE_HEAD_SMASH; ability = ABILITY_LIGHTNING_ROD; }
    PARAMETRIZE { move = MOVE_HEAD_SMASH; ability = ABILITY_ROCK_HEAD; }
    PARAMETRIZE { move = MOVE_LIGHT_OF_RUIN; ability = ABILITY_LIGHTNING_ROD; }
    PARAMETRIZE { move = MOVE_LIGHT_OF_RUIN; ability = ABILITY_ROCK_HEAD; }
    GIVEN {
        ASSUME(GetMoveRecoil(move) > 0);
        PLAYER(SPECIES_CUBONE) { Ability(ability); MaxHP(600); HP(600); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (ability == ABILITY_ROCK_HEAD)
            EXPECT_EQ(player->hp, 600);
        else
            EXPECT_LT(player->hp, 600);
    } FINALLY {
        for (u32 j = 0; j < 8; j += 2)
            EXPECT_EQ(results[j].damage, results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Rock Head does not prevent Struggle recoil")
{
    GIVEN {
        PLAYER(SPECIES_CUBONE) { Ability(ABILITY_ROCK_HEAD); MaxHP(600); HP(600); Item(ITEM_NONE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_STRUGGLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        HP_BAR(opponent);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, 450);
    }
}

SINGLE_BATTLE_TEST("Rock Head does not prevent Life Orb damage")
{
    GIVEN {
        PLAYER(SPECIES_CUBONE) { Ability(ABILITY_ROCK_HEAD); MaxHP(600); HP(600); Item(ITEM_LIFE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, 540);
    }
}

SINGLE_BATTLE_TEST("Rock Head does not prevent Rocky Helmet damage")
{
    GIVEN {
        PLAYER(SPECIES_CUBONE) { Ability(ABILITY_ROCK_HEAD); MaxHP(600); HP(600); Item(ITEM_NONE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, 500);
    }
}

SINGLE_BATTLE_TEST("Rock Head does not prevent crash damage")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_JUMP_KICK; }
    PARAMETRIZE { move = MOVE_HIGH_JUMP_KICK; }
    GIVEN {
        PLAYER(SPECIES_CUBONE) { Ability(ABILITY_ROCK_HEAD); MaxHP(600); HP(600); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, 300);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
    }
}

SINGLE_BATTLE_TEST("Suppressing Rock Head restores recoil")
{
    bool32 suppress;
    PARAMETRIZE { suppress = FALSE; }
    PARAMETRIZE { suppress = TRUE; }
    GIVEN {
        PLAYER(SPECIES_CUBONE) { Ability(ABILITY_ROCK_HEAD); MaxHP(600); HP(600); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, suppress ? MOVE_GASTRO_ACID : MOVE_CELEBRATE); MOVE(player, MOVE_DOUBLE_EDGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_EDGE, player);
        HP_BAR(opponent);
    } THEN {
        if (suppress)
            EXPECT_LT(player->hp, 600);
        else
            EXPECT_EQ(player->hp, 600);
    }
}
