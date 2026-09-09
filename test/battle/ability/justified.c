#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Justified raises Attack after physical and special Dark-type damage")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_BITE; }
    PARAMETRIZE { move = MOVE_DARK_PULSE; }
    GIVEN {
        ASSUME(GetMoveType(move) == TYPE_DARK);
        ASSUME(GetMovePower(move) > 0);
        PLAYER(SPECIES_ARCANINE) { Ability(ABILITY_JUSTIFIED); MaxHP(1000); HP(1000); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        TURN { MOVE(opponent, move); }
    } THEN {
        EXPECT_LT(player->hp, 1000);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Justified activates once for each hit of Beat Up")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BEAT_UP) == EFFECT_BEAT_UP);
        ASSUME(GetMoveType(MOVE_BEAT_UP) == TYPE_DARK);
        PLAYER(SPECIES_ARCANINE) { Ability(ABILITY_JUSTIFIED); MaxHP(1000); HP(1000); }
        PLAYER(SPECIES_WEAVILE) { Ability(ABILITY_PRESSURE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_BEAT_UP, target: playerLeft); }
    } THEN {
        EXPECT_LT(playerLeft->hp, 1000);
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Justified does not activate when a Substitute takes the damage")
{
    GIVEN {
        PLAYER(SPECIES_ARCANINE) { Ability(ABILITY_JUSTIFIED); MaxHP(1000); HP(1000); Speed(100); }
        OPPONENT(SPECIES_UMBREON) { Ability(ABILITY_SYNCHRONIZE); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(opponent, MOVE_BITE); }
    } THEN {
        EXPECT_EQ(player->hp, 750);
        EXPECT(player->volatiles.substituteHP > 0);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Justified does not activate from non-damaging Dark-type moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_TAUNT) == TYPE_DARK);
        ASSUME(GetMovePower(MOVE_TAUNT) == 0);
        PLAYER(SPECIES_ARCANINE) { Ability(ABILITY_JUSTIFIED); }
        OPPONENT(SPECIES_UMBREON) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAUNT); }
    } THEN {
        EXPECT(player->volatiles.tauntTimer > 0);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Justified cannot raise Attack above the maximum stage")
{
    GIVEN {
        PLAYER(SPECIES_ARCANINE) { Ability(ABILITY_JUSTIFIED); MaxHP(1000); HP(1000); }
        OPPONENT(SPECIES_UMBREON) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(opponent, MOVE_BITE); }
    } THEN {
        EXPECT_LT(player->hp, 1000);
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Justified stops activating while suppressed")
{
    bool32 suppress;
    PARAMETRIZE { suppress = FALSE; }
    PARAMETRIZE { suppress = TRUE; }
    GIVEN {
        PLAYER(SPECIES_ARCANINE) { Ability(ABILITY_JUSTIFIED); MaxHP(1000); HP(1000); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        if (suppress)
            TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(opponent, MOVE_DARK_PULSE); }
    } THEN {
        EXPECT_LT(player->hp, 1000);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + !suppress);
    }
}
