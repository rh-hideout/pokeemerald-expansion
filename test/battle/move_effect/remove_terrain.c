#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ICE_SPINNER) == EFFECT_REMOVE_TERRAIN);
    ASSUME(GetMoveEffect(MOVE_STEEL_ROLLER) == EFFECT_REMOVE_TERRAIN_IF_SET);
}

SINGLE_BATTLE_TEST("Remove Terrain: Steel Roller and Ice Spinner can remove a terrain from the field")
{
    u32 j;
    static const u16 terrainMoves[] =
    {
        MOVE_ELECTRIC_TERRAIN,
        MOVE_PSYCHIC_TERRAIN,
        MOVE_GRASSY_TERRAIN,
        MOVE_MISTY_TERRAIN,
    };

    u16 terrainMove = MOVE_NONE;
    u16 removeTerrainMove = MOVE_NONE;

    for (j = 0; j < ARRAY_COUNT(terrainMoves); j++)
    {
        PARAMETRIZE { removeTerrainMove = MOVE_STEEL_ROLLER; terrainMove = terrainMoves[j]; }
        PARAMETRIZE { removeTerrainMove = MOVE_ICE_SPINNER; terrainMove =  terrainMoves[j]; }
    }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIC_TERRAIN) == EFFECT_ELECTRIC_TERRAIN);
        ASSUME(GetMoveEffect(MOVE_PSYCHIC_TERRAIN) == EFFECT_PSYCHIC_TERRAIN);
        ASSUME(GetMoveEffect(MOVE_GRASSY_TERRAIN) == EFFECT_GRASSY_TERRAIN);
        ASSUME(GetMoveEffect(MOVE_MISTY_TERRAIN) == EFFECT_MISTY_TERRAIN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, terrainMove); MOVE(player, removeTerrainMove); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, terrainMove, opponent);
        ANIMATION(ANIM_TYPE_MOVE, removeTerrainMove, player);
        switch (terrainMove)
        {
        case MOVE_ELECTRIC_TERRAIN:
            MESSAGE("The electricity disappeared from the battlefield.");
            break;
        case MOVE_PSYCHIC_TERRAIN:
            MESSAGE("The weirdness disappeared from the battlefield!");
            break;
        case MOVE_GRASSY_TERRAIN:
            MESSAGE("The grass disappeared from the battlefield.");
            break;
        case MOVE_MISTY_TERRAIN:
            MESSAGE("The mist disappeared from the battlefield.");
            break;
        }
    }
}

SINGLE_BATTLE_TEST("Remove Terrain: Terrain will not be removed if user faints during attack execution")
{
    u16 move;
    PARAMETRIZE { move = MOVE_ICE_SPINNER; }
    PARAMETRIZE { move = MOVE_STEEL_ROLLER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIFE_ORB); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NOT MESSAGE("The electricity disappeared from the battlefield.");
    }
}

SINGLE_BATTLE_TEST("Remove Terrain: Terrain will not be removed if user is switched out due to Red Card")
{
    u16 move;
    PARAMETRIZE { move = MOVE_ICE_SPINNER; }
    PARAMETRIZE { move = MOVE_STEEL_ROLLER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        NOT MESSAGE("The electricity disappeared from the battlefield.");
    }
}

SINGLE_BATTLE_TEST("Remove Terrain: Steel Roller will fail if there is no Terrain")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEEL_ROLLER); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_ROLLER, opponent);
        MESSAGE("The opposing Wobbuffet used Steel Roller!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Remove Terrain: Ice Spinner doesn't fail if there is no terrain on the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ICE_SPINNER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_SPINNER, player);
        NOT MESSAGE("But it failed!");
    }
}

AI_SINGLE_BATTLE_TEST("Remove Terrain: AI will not choose Steel Roller if it might fail")
{
    u32 move;

    PARAMETRIZE { move = MOVE_ELECTRIC_TERRAIN; }
    PARAMETRIZE { move = MOVE_NONE; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_STEEL_ROLLER, MOVE_ICE_SHARD); }
    } WHEN {
        if (move == MOVE_ELECTRIC_TERRAIN) {
            TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); EXPECT_MOVE(opponent, MOVE_ICE_SHARD); }
            TURN { EXPECT_MOVE(opponent, MOVE_STEEL_ROLLER); }
        } else {
            TURN { EXPECT_MOVE(opponent, MOVE_ICE_SHARD); }
        }
    }
}

AI_SINGLE_BATTLE_TEST("Remove Terrain: AI will can choose Ice Spinner regardless if there is a terrain or not")
{
    u32 move;

    PARAMETRIZE { move = MOVE_ELECTRIC_TERRAIN; }
    PARAMETRIZE { move = MOVE_NONE; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ICE_SPINNER, MOVE_ICE_SHARD); }
    } WHEN {
        if (move == MOVE_ELECTRIC_TERRAIN) {
            TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); EXPECT_MOVE(opponent, MOVE_ICE_SPINNER); }
            TURN { EXPECT_MOVE(opponent, MOVE_ICE_SPINNER); }
        } else {
            TURN { EXPECT_MOVE(opponent, MOVE_ICE_SPINNER); }
        }
    }
}
