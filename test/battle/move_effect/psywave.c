#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_PSYWAVE) == EFFECT_PSYWAVE);
}

TO_DO_BATTLE_TEST("TODO: Write Psywave (Move Effect) test titles")

SINGLE_BATTLE_TEST("Psywave is unaffected by type immunities (Gen 1)")
{
    s16 damage;

    GIVEN {
        WITH_CONFIG(B_UPDATED_MOVE_DATA, GEN_1);
        ASSUME(IsSpeciesOfType(SPECIES_UMBREON, TYPE_DARK));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_UMBREON);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYWAVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYWAVE, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_GT(damage, 0);
    }
}
