#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI_FLAG_ASSUME_STAB sees the player's STAB moves")
{
    u32 aiFlag = 0;
    PARAMETRIZE { aiFlag = AI_FLAG_ASSUME_STAB; }
    PARAMETRIZE { aiFlag = AI_FLAG_OMNISCIENT; }
    PARAMETRIZE { aiFlag = 0; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | aiFlag);
        PLAYER(SPECIES_TYPHLOSION) { Speed(5); Moves(MOVE_TACKLE, MOVE_FLAMETHROWER); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); Moves(MOVE_TACKLE); Level(1); }
        OPPONENT(SPECIES_SCIZOR) { Speed(4); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_BLISSEY) { Speed(4); Moves(MOVE_TACKLE); }
    } WHEN {
        if (aiFlag == AI_FLAG_ASSUME_STAB || aiFlag == AI_FLAG_OMNISCIENT)
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 2); }
        else
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_ASSUME_STAB does not see the player's non-STAB moves")
{
    u32 aiFlag = 0;
    PARAMETRIZE { aiFlag = AI_FLAG_ASSUME_STAB; }
    PARAMETRIZE { aiFlag = AI_FLAG_OMNISCIENT; }
    PARAMETRIZE { aiFlag = 0; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | aiFlag);
        PLAYER(SPECIES_GOREBYSS) { Speed(5); Moves(MOVE_TACKLE, MOVE_FLAMETHROWER); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); Moves(MOVE_TACKLE); Level(1); }
        OPPONENT(SPECIES_SCIZOR) { Speed(4); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_BLISSEY) { Speed(4); Moves(MOVE_TACKLE); }
    } WHEN {
        if (aiFlag == AI_FLAG_OMNISCIENT)
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 2); }
        else
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 1); }
    }
}
