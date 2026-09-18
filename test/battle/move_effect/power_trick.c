#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_POWER_TRICK, MOVE_EFFECT_POWER_TRICK));
}

SINGLE_BATTLE_TEST("Power Trick swap the user's Attack and Defense stats")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_POUND) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POUND); }
        TURN { MOVE(player, MOVE_POWER_TRICK); }
        TURN { MOVE(player, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        HP_BAR(opponent, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_TRICK, player);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        HP_BAR(opponent, captureDamage: &damage[1]);

    } THEN {
        EXPECT_GT(damage[1], damage[0]);
    }
}
