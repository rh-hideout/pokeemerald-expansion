#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI_FLAG_WEIGH_ABILITY_PREDICTION: AI will predict opposing ability based on its aiRating")
{
    PASSES_RANDOMLY(13, 23, RNG_AI_PREDICT_ABILITY);// (illuminate (0+3) + water absorb (7+3), out of illuminate + water absorb + volt absorb (7+3) )
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_WEIGH_ABILITY_PREDICTION);
        PLAYER(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); }
        OPPONENT(SPECIES_LANTURN) { Moves(MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_SURF); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_THUNDERBOLT); }
    }
}
