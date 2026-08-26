#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
    ASSUME(GetMoveDamagePercentage(MOVE_SUPER_FANG) == 50);
}

TO_DO_BATTLE_TEST("Super Fang does 50% damage to the target's current HP")
TO_DO_BATTLE_TEST("Super Fang always deals at least 1 HP of damage")
SINGLE_BATTLE_TEST("Super Fang is unaffected by type immunities (Gen 1)")
{
    s16 damage;

    GIVEN {
        WITH_CONFIG(B_UPDATED_MOVE_DATA, GEN_1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTLY) { MaxHP(100); HP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, 50);
    }
}
TO_DO_BATTLE_TEST("Super Fang doesn't hit Ghost-type Pokémon (Gen 2+)")

TO_DO_BATTLE_TEST("Guardian of Alola does 75% damage to the target's current HP")
