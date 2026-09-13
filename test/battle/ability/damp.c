#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Damp stops blocking Explosion while suppressed")
{
    bool32 suppress;
    PARAMETRIZE { suppress = FALSE; }
    PARAMETRIZE { suppress = TRUE; }
    GIVEN {
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); MaxHP(1000); HP(1000); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); MaxHP(100); HP(100); Attack(100); }
    } WHEN {
        if (suppress)
            TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(opponent, MOVE_EXPLOSION); }
    } THEN {
        EXPECT_EQ(opponent->hp, suppress ? 0 : 100);
        if (suppress)
            EXPECT_LT(player->hp, 1000);
        else
            EXPECT_EQ(player->hp, 1000);
    }
}

SINGLE_BATTLE_TEST("A benched Damp Pokemon does not block Explosion")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1000); Defense(500); }
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); MaxHP(100); HP(100); Attack(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EXPLOSION); }
    } THEN {
        EXPECT_EQ(opponent->hp, 0);
        EXPECT_LT(player->hp, 1000);
    }
}

SINGLE_BATTLE_TEST("Damp does not prevent Steel Beam HP loss")
{
    GIVEN {
        PLAYER(SPECIES_DURALUDON) { Ability(ABILITY_HEAVY_METAL); MaxHP(100); HP(100); }
        OPPONENT(SPECIES_PARAS) { Ability(ABILITY_DAMP); MaxHP(1000); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_STEEL_BEAM); }
    } THEN {
        EXPECT_EQ(player->hp, 50);
        EXPECT_LT(opponent->hp, 1000);
    }
}

SINGLE_BATTLE_TEST("Damp does not prevent Final Gambit from fainting its user")
{
    GIVEN {
        PLAYER(SPECIES_VICTINI) { Ability(ABILITY_VICTORY_STAR); MaxHP(100); HP(100); }
        OPPONENT(SPECIES_PARAS) { Ability(ABILITY_DAMP); MaxHP(200); HP(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); }
    } THEN {
        EXPECT_EQ(player->hp, 0);
        EXPECT_EQ(opponent->hp, 100);
    }
}

SINGLE_BATTLE_TEST("Damp does not prevent Healing Wish from fainting its user")
{
    GIVEN {
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); }
        OPPONENT(SPECIES_LATIAS) { Ability(ABILITY_LEVITATE); MaxHP(100); HP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEALING_WISH); SEND_OUT(opponent, 1); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_WOBBUFFET);
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Damp prevents Explosion-like moves from enemies")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_EXPLOSION; }
    PARAMETRIZE { move = MOVE_SELF_DESTRUCT; }
    PARAMETRIZE { move = MOVE_MIND_BLOWN; }
    PARAMETRIZE { move = MOVE_MISTY_EXPLOSION; }
    GIVEN {
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DAMP);
        NONE_OF { HP_BAR(player); HP_BAR(opponent); }
    }
}

DOUBLE_BATTLE_TEST("Damp prevents Explosion-like moves from enemies in a double battle")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_EXPLOSION; }
    PARAMETRIZE { move = MOVE_SELF_DESTRUCT; }
    PARAMETRIZE { move = MOVE_MIND_BLOWN; }
    PARAMETRIZE { move = MOVE_MISTY_EXPLOSION; }
    GIVEN {
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, move); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_DAMP);
        NONE_OF { HP_BAR(playerLeft); HP_BAR(opponentLeft); HP_BAR(playerRight); HP_BAR(opponentRight); }
    }
}

SINGLE_BATTLE_TEST("Damp prevents Explosion-like moves from self")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_EXPLOSION; }
    PARAMETRIZE { move = MOVE_SELF_DESTRUCT; }
    PARAMETRIZE { move = MOVE_MIND_BLOWN; }
    PARAMETRIZE { move = MOVE_MISTY_EXPLOSION; }
    GIVEN {
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DAMP);
        NONE_OF { HP_BAR(player); HP_BAR(opponent); }
    }
}

SINGLE_BATTLE_TEST("Damp prevents damage from Aftermath")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); }
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_AFTERMATH); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_AFTERMATH);
        ABILITY_POPUP(player, ABILITY_DAMP);
        NONE_OF { HP_BAR(player); }
    }
}

//TO_DO_BATTLE_TEST("Damp affects non-adjacent Pokémon (triples)")
