#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_BLACK_SLUDGE) == HOLD_EFFECT_BLACK_SLUDGE);
}

SINGLE_BATTLE_TEST("Black Sludge recovers 1/16 HP for Poison-type holders")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_EKANS, 0) == TYPE_POISON);
        PLAYER(SPECIES_EKANS) { MaxHP(160); HP(1); Item(ITEM_BLACK_SLUDGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Ekans restored a little HP using its Black Sludge!");
        HP_BAR(player, damage: -10);
    }
}

SINGLE_BATTLE_TEST("Black Sludge deals 1/8 max HP after its holder loses the Poison type")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_EKANS, 0) == TYPE_POISON);
        ASSUME(GetMoveEffect(MOVE_SONIC_BOOM) == EFFECT_FIXED_HP_DAMAGE);
        ASSUME(GetMoveFixedHPDamage(MOVE_SONIC_BOOM) == 20);
        ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
        PLAYER(SPECIES_EKANS) { MaxHP(160); HP(160); Item(ITEM_BLACK_SLUDGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SONIC_BOOM); }
        TURN { MOVE(opponent, MOVE_SOAK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, opponent);
        HP_BAR(player, damage: 20);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        HP_BAR(player, damage: -10);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOAK, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MON_HIT, player);
        HP_BAR(player, damage: 20);
    } THEN {
        EXPECT_EQ(player->hp, 130);
    }
}
