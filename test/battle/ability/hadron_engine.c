#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hadron Engine creates Electric Terrain when entering the battle")
{
    GIVEN {
        PLAYER(SPECIES_MIRAIDON) { Ability(ABILITY_HADRON_ENGINE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_HADRON_ENGINE);
        MESSAGE("An electric current ran across the battlefield!");
    }
}

SINGLE_BATTLE_TEST("Hadron Engine boosts the Pokemon's Special Attack on Electric Terrain even if not grounded", s16 damage)
{
    bool32 overrideTerrain, airBalloon;

    PARAMETRIZE { airBalloon = FALSE; overrideTerrain = TRUE; }
    PARAMETRIZE { airBalloon = FALSE; overrideTerrain = FALSE; }
    PARAMETRIZE { airBalloon = TRUE;  overrideTerrain = TRUE; }
    PARAMETRIZE { airBalloon = TRUE;  overrideTerrain = FALSE; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_AIR_BALLOON].holdEffect == HOLD_EFFECT_AIR_BALLOON);
        ASSUME(GetMoveEffect(MOVE_GRASSY_TERRAIN) == EFFECT_GRASSY_TERRAIN);
        ASSUME(GetMoveCategory(MOVE_POWER_GEM) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_MIRAIDON) { Ability(ABILITY_HADRON_ENGINE); Moves(MOVE_POWER_GEM, MOVE_CELEBRATE); Item(airBalloon ? ITEM_AIR_BALLOON : ITEM_NONE); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_GRASSY_TERRAIN, MOVE_CELEBRATE); Speed(2); }
    } WHEN {
        if (overrideTerrain)
            TURN { MOVE(opponent, MOVE_GRASSY_TERRAIN); }
        TURN { MOVE(player, MOVE_POWER_GEM); }
    } SCENE {
        if (overrideTerrain)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_GEM, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3333), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.3333), results[3].damage);
    }
}
