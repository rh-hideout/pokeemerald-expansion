#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SAFEGUARD) == EFFECT_SAFEGUARD);
}

SINGLE_BATTLE_TEST("Safeguard has no effect on Flame Orb or Toxic Orb")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_FLAME_ORB; }
    PARAMETRIZE { item = ITEM_TOXIC_ORB; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_FLAME_ORB].holdEffect == HOLD_EFFECT_FLAME_ORB);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SAFEGUARD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAFEGUARD, player);
        if (item == ITEM_FLAME_ORB) {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
            STATUS_ICON(player, burn: TRUE);
        } else {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
            STATUS_ICON(player, badPoison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Safeguard prevents paralysis")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SAFEGUARD); MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAFEGUARD, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, player);
        MESSAGE("The opposing Wobbuffet is protected by Safeguard!");
    }
}