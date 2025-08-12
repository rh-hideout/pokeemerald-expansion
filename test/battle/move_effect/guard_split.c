#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_GUARD_SPLIT) == EFFECT_GUARD_SPLIT);
}

SINGLE_BATTLE_TEST("Guard Split averages users and targets Def and Sp. Def stats")
{
    GIVEN {
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_IVYSAUR);
    } WHEN {
        TURN { MOVE(player, MOVE_GUARD_SPLIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SPLIT, player);
    } THEN {
        EXPECT_EQ(player->defense, opponent->defense);
        EXPECT_EQ(player->spDefense, opponent->spDefense);
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Guard Split to improve its stats")
{

    u32 player, opponent;

    PARAMETRIZE { player = SPECIES_SHUCKLE; opponent = SPECIES_PHEROMOSA; }
    PARAMETRIZE { player = SPECIES_PHEROMOSA; opponent = SPECIES_SHUCKLE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GUARD_SPLIT) == EFFECT_GUARD_SPLIT);
        ASSUME(gSpeciesInfo[SPECIES_PHEROMOSA].baseDefense < gSpeciesInfo[SPECIES_WOBBUFFET].baseDefense);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].baseDefense < gSpeciesInfo[SPECIES_SHUCKLE].baseDefense);
        ASSUME(gSpeciesInfo[SPECIES_PHEROMOSA].baseSpDefense < gSpeciesInfo[SPECIES_WOBBUFFET].baseSpDefense);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].baseSpDefense < gSpeciesInfo[SPECIES_SHUCKLE].baseSpDefense);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(player);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_GUARD_SPLIT, MOVE_NIGHT_SHADE); }
        OPPONENT(opponent);
    } WHEN {
        if (player == SPECIES_SHUCKLE)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_GUARD_SPLIT, target:playerLeft); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_GUARD_SPLIT, target:opponentRight); }
    }
}

