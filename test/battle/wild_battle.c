#include "global.h"
#include "test/battle.h"

WILD_BATTLE_TEST("An item given by the player to the wild mon is not duplicated if the mon is caught")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK) == EFFECT_TRICK);
        WITH_CONFIG(B_STEAL_WILD_ITEMS, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SUPER_POTION); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_HYPER_POTION); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
        TURN { USE_ITEM(player, ITEM_MASTER_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, player);
    } THEN {
        EXPECT_EQ(FALSE, CheckBagHasItem(ITEM_HYPER_POTION, 1));
        EXPECT_EQ(FALSE, CheckBagHasItem(ITEM_SUPER_POTION, 1));
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_HELD_ITEM), ITEM_HYPER_POTION);
    }
}
