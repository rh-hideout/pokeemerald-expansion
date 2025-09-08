#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI uses Dynamax")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH); DynamaxLevel(10); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Dynamax -- Max Moves are scored based on max move effects, not base effects")
{
    KNOWN_FAILING;
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_EXPLOSION); DynamaxLevel(10); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_EXPLOSION, gimmick: GIMMICK_DYNAMAX); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Dynamax -- AI does not dynamax before using a utility move")
{
    KNOWN_FAILING;
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_FAKE_OUT); DynamaxLevel(10); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_FAKE_OUT, gimmick: GIMMICK_NONE); }
    }
}

// This test needs a better setup as well.
AI_DOUBLE_BATTLE_TEST("AI uses Dynamax -- AI can Copycat a Max Move")
{
    KNOWN_FAILING;
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TRICK_ROOM); DynamaxLevel(10); }
        OPPONENT(SPECIES_RIOLU) { Ability(ABILITY_PRANKSTER); Moves(MOVE_COPYCAT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft,  MOVE_TRICK_ROOM, gimmick: GIMMICK_DYNAMAX);        
               EXPECT_MOVE(opponentRight, MOVE_COPYCAT, target: opponentLeft); }
    }
}
