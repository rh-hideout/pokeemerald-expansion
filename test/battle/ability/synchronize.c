#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("xx")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_TOXIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, badPoison: TRUE);
        ABILITY_POPUP(opponent, ABILITY_SYNCHRONIZE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, badPoison: TRUE);
    }
}
