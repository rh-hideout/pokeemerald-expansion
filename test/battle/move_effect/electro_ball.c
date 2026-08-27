#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ELECTRO_BALL) == EFFECT_ELECTRO_BALL);
}

SINGLE_BATTLE_TEST("Electro Ball's power increases with the user's Speed relative to the target", s16 damage)
{
    u32 speed;

    PARAMETRIZE { speed = 99;  } // 40 power
    PARAMETRIZE { speed = 100; } // 60 power
    PARAMETRIZE { speed = 200; } // 80 power
    PARAMETRIZE { speed = 300; } // 120 power
    PARAMETRIZE { speed = 400; } // 150 power

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(speed); SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(500); HP(500); Speed(100); SpDefense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRO_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_BALL, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(3.0), results[3].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(3.75), results[4].damage);
    }
}

SINGLE_BATTLE_TEST("Electro Ball considers Speed stat stages, status, held items, and abilities", s16 damage)
{
    enum Species species;
    enum Ability ability;
    enum Item item;
    enum Move setupMove;
    u32 status;

    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_SHADOW_TAG;  item = ITEM_NONE;      status = STATUS1_NONE;      setupMove = MOVE_CELEBRATE; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_SHADOW_TAG;  item = ITEM_NONE;      status = STATUS1_NONE;      setupMove = MOVE_AGILITY; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_SHADOW_TAG;  item = ITEM_NONE;      status = STATUS1_PARALYSIS; setupMove = MOVE_CELEBRATE; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_SHADOW_TAG;  item = ITEM_IRON_BALL; status = STATUS1_NONE;      setupMove = MOVE_CELEBRATE; }
    PARAMETRIZE { species = SPECIES_VENUSAUR;  ability = ABILITY_CHLOROPHYLL; item = ITEM_NONE;      status = STATUS1_NONE;      setupMove = MOVE_SUNNY_DAY; }

    GIVEN {
        WITH_CONFIG(B_PARALYSIS_SPEED, GEN_7);
        ASSUME_STAT_CHANGE(MOVE_AGILITY, speed: +2);
        ASSUME(GetItemHoldEffect(ITEM_IRON_BALL) == HOLD_EFFECT_IRON_BALL);
        PLAYER(species) { Ability(ability); Speed(100); SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); Status1(status); MaxHP(500); HP(500); Speed(100); SpDefense(100); }
    } WHEN {
        TURN { MOVE(player, setupMove); }
        TURN { MOVE(player, MOVE_ELECTRO_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_BALL, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3333), results[1].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
        EXPECT_EQ(results[2].damage, results[3].damage);
        EXPECT_EQ(results[3].damage, results[4].damage);
    }
}
