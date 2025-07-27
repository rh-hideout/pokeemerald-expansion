#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_DOUBLE_BATTLE_TEST("AI_FLAG_ENEMIES tries to kill the partner unless it can kill the player")
{
    ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == MOVE_TARGET_FOES_AND_ALLY);

    u32 move, level;

    PARAMETRIZE { move = MOVE_EARTHQUAKE; level = 1; }
    PARAMETRIZE { move = MOVE_FLAMETHROWER; level = 1; }
    PARAMETRIZE { move = MOVE_EARTHQUAKE; level = 100; }
    PARAMETRIZE { move = MOVE_FLAMETHROWER; level = 100; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == MOVE_TARGET_FOES_AND_ALLY);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_ENEMIES);
        PLAYER(SPECIES_WOBBUFFET) { Level(50); } 
        PLAYER(SPECIES_WOBBUFFET) { Level(10); } 
        OPPONENT(SPECIES_WOBBUFFET) { Level(50); Moves(move, MOVE_MUDDY_WATER); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(level); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN
        { 
            if (move == MOVE_FLAMETHROWER)
            {
                if (level == 1)
                    EXPECT_MOVE(opponentLeft, move, target: opponentRight);
                else
                    EXPECT_MOVE(opponentLeft, move, target: playerRight);
            }
            else
                EXPECT_MOVE(opponentLeft, move);
        } 
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_ENEMIES steps on its ally's weather")
{
    u32 weather1, move1, weather2, move2;

    PARAMETRIZE { weather1 = MOVE_SUNNY_DAY; move1 = MOVE_SOLAR_BEAM; weather2 = MOVE_RAIN_DANCE; move2 = MOVE_THUNDER; }
    PARAMETRIZE { weather1 = MOVE_RAIN_DANCE; move1 = MOVE_THUNDER; weather2 = MOVE_SUNNY_DAY; move2 = MOVE_SOLAR_BEAM; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_ENEMIES);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); } 
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); } 
        OPPONENT(SPECIES_WOBBUFFET) { Speed(75); Moves(weather1, move1, MOVE_HEADBUTT); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(weather2, move2, MOVE_HEADBUTT); }
    } WHEN {
        TURN
        { 
            EXPECT_MOVE(opponentLeft, weather1);
            EXPECT_MOVE(opponentRight, weather2);
        }
        TURN
        { 
            EXPECT_MOVE(opponentLeft, move1);
            EXPECT_MOVE(opponentRight, weather2);
        }
    }
}
