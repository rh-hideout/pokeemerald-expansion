#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_POWER_SPLIT) == EFFECT_POWER_SPLIT);
}

SINGLE_BATTLE_TEST("Power Split averages user and targets Atk and Sp. Atk stats")
{
    GIVEN {
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_IVYSAUR);
    } WHEN {
        TURN { MOVE(player, MOVE_POWER_SPLIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_SPLIT, player);
    } THEN {
        EXPECT_EQ(player->attack, opponent->attack);
        EXPECT_EQ(player->spAttack, opponent->spAttack);
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Power Split to improve its stats")
{

    u32 player, opponent;

    PARAMETRIZE { player = SPECIES_SHUCKLE; opponent = SPECIES_PHEROMOSA; }
    PARAMETRIZE { player = SPECIES_PHEROMOSA; opponent = SPECIES_SHUCKLE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POWER_SPLIT) == EFFECT_POWER_SPLIT);
        ASSUME(gSpeciesInfo[SPECIES_PHEROMOSA].baseAttack > gSpeciesInfo[SPECIES_WOBBUFFET].baseAttack);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].baseAttack > gSpeciesInfo[SPECIES_SHUCKLE].baseAttack);
        ASSUME(gSpeciesInfo[SPECIES_PHEROMOSA].baseSpAttack > gSpeciesInfo[SPECIES_WOBBUFFET].baseSpAttack);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].baseSpAttack > gSpeciesInfo[SPECIES_SHUCKLE].baseSpAttack);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(player);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_POWER_SPLIT, MOVE_TACKLE, MOVE_ROUND); }
        OPPONENT(opponent) { Moves(MOVE_TACKLE, MOVE_ROUND); }
    } WHEN {
        if (player == SPECIES_PHEROMOSA)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_POWER_SPLIT, target:playerLeft); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_POWER_SPLIT, target:opponentRight); }
    }
}

