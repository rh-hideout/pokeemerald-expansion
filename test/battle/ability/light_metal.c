#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Light Metal and Heavy Metal affect the power of Low Kick", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_LIGHT_METAL; } //  10.0 - 24.9 kg  (40 power)
    PARAMETRIZE { ability = ABILITY_STALWART;    } //  25.0 - 49.9 kg  (60 power)
    PARAMETRIZE { ability = ABILITY_HEAVY_METAL; } //  50.0 - 99.9 kg  (80 power)

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
        ASSUME(GetMoveArgType(MOVE_SOAK) == TYPE_WATER);
        ASSUME(GetSpeciesWeight(SPECIES_DURALUDON) == 400);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DURALUDON) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SOAK); } // To remove super-effectiveness, as it was messing with calculations.
        TURN { MOVE(player, MOVE_LOW_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOW_KICK, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        // Calc 20 power increase, with the first iteration being 40 power
        if (i != 0)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12((i * 0.5) + 1), results[i].damage);
    }
}

TO_DO_BATTLE_TEST("Light Metal and Heavy Metal don't affect Heavy Ball's multiplier")
