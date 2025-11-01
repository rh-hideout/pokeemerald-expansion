#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Aura Break inverts Fairy Aura's effect")
{
    s16 damage[3];

	GIVEN {
		PLAYER(SPECIES_WOBBUFFET);
		PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FAIRY_AURA); }
		OPPONENT(SPECIES_WOBBUFFET);
		OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_AURA_BREAK); }
	} WHEN {
		TURN { MOVE(player, MOVE_PLAY_ROUGH); }
		TURN { SWITCH(player, 1); }
		TURN { MOVE(player, MOVE_PLAY_ROUGH); }
		TURN { MOVE(player, MOVE_PLAY_ROUGH); SWITCH(opponent, 1); }
	} SCENE {
		ANIMATION(ANIM_TYPE_MOVE, MOVE_PLAY_ROUGH, player);
		HP_BAR(opponent, captureDamage: &damage[0]);

		ANIMATION(ANIM_TYPE_MOVE, MOVE_PLAY_ROUGH, player);
		HP_BAR(opponent, captureDamage: &damage[1]);

		ANIMATION(ANIM_TYPE_MOVE, MOVE_PLAY_ROUGH, player);
		HP_BAR(opponent, captureDamage: &damage[2]);

	} THEN {
		EXPECT_MUL_EQ(damage[0], UQ_4_12(1.33), damage[1]);
		EXPECT_MUL_EQ(damage[0], UQ_4_12(0.75), damage[2]);
	}
}

SINGLE_BATTLE_TEST("Aura Break inverts Dark Aura's effect")
{
    s16 damage[3];

	GIVEN {
		PLAYER(SPECIES_WOBBUFFET);
		PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DARK_AURA); }
		OPPONENT(SPECIES_WOBBUFFET);
		OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_AURA_BREAK); }
	} WHEN {
		TURN { MOVE(player, MOVE_BITE); }
		TURN { SWITCH(player, 1); }
		TURN { MOVE(player, MOVE_BITE); }
		TURN { MOVE(player, MOVE_BITE); SWITCH(opponent, 1); }
	} SCENE {
		ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, player);
		HP_BAR(opponent, captureDamage: &damage[0]);

		ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, player);
		HP_BAR(opponent, captureDamage: &damage[1]);

		ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, player);
		HP_BAR(opponent, captureDamage: &damage[2]);

	} THEN {
		EXPECT_MUL_EQ(damage[0], UQ_4_12(1.33), damage[1]);
		EXPECT_MUL_EQ(damage[0], UQ_4_12(0.75), damage[2]);
	}
}

DOUBLE_BATTLE_TEST("Aura Break ignores Mold Breaker abilities")
{
    s16 damage[6];
    u32 ability = ABILITY_NONE;

    PARAMETRIZE { ability = ABILITY_SHADOW_TAG; }
    PARAMETRIZE { ability = ABILITY_MOLD_BREAKER; }
    PARAMETRIZE { ability = ABILITY_TERAVOLT; }
    PARAMETRIZE { ability = ABILITY_TURBOBLAZE; }

	GIVEN {
		PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
		PLAYER(SPECIES_WOBBUFFET);
		PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DARK_AURA); }
		PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FAIRY_AURA); }
		OPPONENT(SPECIES_WOBBUFFET);
		OPPONENT(SPECIES_WOBBUFFET);
		OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_AURA_BREAK); }
	} WHEN {
		TURN { MOVE(playerLeft, MOVE_BITE, target: opponentLeft); }
		TURN { MOVE(playerLeft, MOVE_PLAY_ROUGH, target: opponentLeft); }
		TURN { MOVE(playerLeft, MOVE_BITE, target: opponentRight); SWITCH(playerRight, 2); }
		TURN { MOVE(playerLeft, MOVE_PLAY_ROUGH, target: opponentRight); SWITCH(playerRight, 3); }
		TURN { MOVE(playerLeft, MOVE_BITE, target: opponentRight); SWITCH(playerRight, 2); SWITCH(opponentRight, 2); }
		TURN { MOVE(playerLeft, MOVE_PLAY_ROUGH, target: opponentRight); SWITCH(playerRight, 3); }
	} SCENE {
		ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerLeft);
		HP_BAR(opponentLeft, captureDamage: &damage[0]);

		ANIMATION(ANIM_TYPE_MOVE, MOVE_PLAY_ROUGH, playerLeft);
		HP_BAR(opponentLeft, captureDamage: &damage[1]);

		ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerLeft);
		HP_BAR(opponentRight, captureDamage: &damage[2]);

		ANIMATION(ANIM_TYPE_MOVE, MOVE_PLAY_ROUGH, playerLeft);
		HP_BAR(opponentRight, captureDamage: &damage[3]);

		ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerLeft);
		HP_BAR(opponentRight, captureDamage: &damage[4]);

		ANIMATION(ANIM_TYPE_MOVE, MOVE_PLAY_ROUGH, playerLeft);
		HP_BAR(opponentRight, captureDamage: &damage[5]);
    } THEN {
		EXPECT_MUL_EQ(damage[0], UQ_4_12(1.33), damage[2]);
		EXPECT_MUL_EQ(damage[0], UQ_4_12(0.75), damage[4]);
		EXPECT_MUL_EQ(damage[1], UQ_4_12(1.33), damage[3]);
		EXPECT_MUL_EQ(damage[1], UQ_4_12(0.75), damage[5]);
	}
}
