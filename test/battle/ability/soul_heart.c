#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Soul Heart boosts Sp. Atk after opponent uses Memento")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MEMENTO) == EFFECT_MEMENTO);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGEARNA);
    } WHEN {
        TURN { MOVE(player, MOVE_MEMENTO); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEMENTO, player);
        MESSAGE("Wobbuffet fainted");
        ABILITY_POPUP(opponent, ABILITY_SOUL_HEART);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStage[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Soul Heart (Ability) test titles")
