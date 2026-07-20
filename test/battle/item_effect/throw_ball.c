#include "global.h"
#include "test/battle.h"

WILD_BATTLE_TEST("Habitat: every throw ball is rejected at the battle-item boundary and remains in the Bag")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CATERPIE);
        GIVE_PLAYER_ITEM(ITEM_POKE_BALL, 2);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
    } THEN {
        EXPECT(CheckBagHasItem(ITEM_POKE_BALL, 1));
    }
}

SINGLE_BATTLE_TEST("Habitat: normal battle Bag consumables are consumed once")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POTION, partyIndex: 0); }
    } SCENE {
        HP_BAR(player, damage: -20);
    } THEN {
        EXPECT(!CheckBagHasItem(ITEM_POTION, 1));
    }
}
