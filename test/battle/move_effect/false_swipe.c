#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
}

SINGLE_BATTLE_TEST("False Swipe always leaves the target with at least 1 HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(999); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); Defense(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_FALSE_SWIPE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, player);
        HP_BAR(opponent, damage: 99);
    } THEN {
        EXPECT_EQ(opponent->hp, 1);
    }
}

SINGLE_BATTLE_TEST("False Swipe still hits the target if it has 1 HP")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_FALSE_SWIPE));
        ASSUME(GetItemHoldEffect(ITEM_ROCKY_HELMET) == HOLD_EFFECT_ROCKY_HELMET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_FALSE_SWIPE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, player);
        HP_BAR(player);
        MESSAGE("Wobbuffet was hurt by the opposing Wobbuffet's Rocky Helmet!");
    } THEN {
        EXPECT_EQ(opponent->hp, 1);
    }
}

SINGLE_BATTLE_TEST("False Swipe does not reduce its damage when hitting a substitute", s16 damage, u16 substituteDamage)
{
    bool32 substitute;

    PARAMETRIZE { substitute = FALSE; }
    PARAMETRIZE { substitute = TRUE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        ASSUME(!MoveIgnoresSubstitute(MOVE_FALSE_SWIPE));
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(101); MaxHP(400); Speed(2); }
    } WHEN {
        TURN {
            MOVE(opponent, substitute ? MOVE_SUBSTITUTE : MOVE_CELEBRATE);
            MOVE(player, MOVE_FALSE_SWIPE);
        }
    } SCENE {
        if (substitute) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, player);
            SUB_HIT(opponent, captureDamage: &results[i].substituteDamage);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, player);
            HP_BAR(opponent, captureDamage: &results[i].damage);
        }
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].substituteDamage);
    }
}
