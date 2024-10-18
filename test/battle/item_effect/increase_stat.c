#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("X Attack raises battler's Attack stat", s16 damage)
{
    u32 item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_X_ATTACK; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_ATTACK_1; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_ATTACK_2; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_ATTACK_3; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_ATTACK_6; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_X_ATTACK].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ATTACK_1].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ATTACK_2].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ATTACK_3].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ATTACK_6].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ATTACK_1].holdEffectParam == STAT_STAGE_1);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ATTACK_2].holdEffectParam == STAT_STAGE_2);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ATTACK_3].holdEffectParam == STAT_STAGE_3);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ATTACK_6].holdEffectParam == STAT_STAGE_6);
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (item != ITEM_NONE)
            TURN { USE_ITEM(player, item); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Tackle!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        if (B_X_ITEMS_BUFF >= GEN_7)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        else
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[3].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.5), results[4].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4.0), results[5].damage);
    }
}

SINGLE_BATTLE_TEST("X Defense raises battler's Defense stat", s16 damage)
{
    u32 item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_X_DEFENSE; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_DEFENSE_1; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_DEFENSE_2; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_DEFENSE_3; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_DEFENSE_6; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_X_DEFENSE].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_DEFENSE_1].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_DEFENSE_2].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_DEFENSE_3].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_DEFENSE_6].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_DEFENSE_1].holdEffectParam == STAT_STAGE_1);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_DEFENSE_2].holdEffectParam == STAT_STAGE_2);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_DEFENSE_3].holdEffectParam == STAT_STAGE_3);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_DEFENSE_6].holdEffectParam == STAT_STAGE_6);
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (item != ITEM_NONE)
            TURN { USE_ITEM(player, item); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Tackle!");
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        if (B_X_ITEMS_BUFF >= GEN_7)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
        else
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.66), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.66), results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.50), results[3].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.40), results[4].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.33), results[5].damage);
    }
}

SINGLE_BATTLE_TEST("X Sp. Atk raises battler's Sp. Attack stat", s16 damage)
{
    u32 item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_X_SP_ATK; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SP_ATK_1; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SP_ATK_2; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SP_ATK_3; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SP_ATK_6; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_X_SP_ATK].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_ATK_1].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_ATK_2].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_ATK_3].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_ATK_6].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_ATK_1].holdEffectParam == STAT_STAGE_1);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_ATK_2].holdEffectParam == STAT_STAGE_2);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_ATK_3].holdEffectParam == STAT_STAGE_3);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_ATK_6].holdEffectParam == STAT_STAGE_6);
        ASSUME(gMovesInfo[MOVE_DISARMING_VOICE].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (item != ITEM_NONE)
            TURN { USE_ITEM(player, item); }
        TURN { MOVE(player, MOVE_DISARMING_VOICE); }
    } SCENE {
        MESSAGE("Wobbuffet used Disarming Voice!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        if (B_X_ITEMS_BUFF >= GEN_7)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        else
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[3].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.5), results[4].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4.0), results[5].damage);
    }
}

SINGLE_BATTLE_TEST("X Sp. Def raises battler's Sp. Defense stat", s16 damage)
{
    u32 item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_X_SP_DEF; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SP_DEF_1; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SP_DEF_2; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SP_DEF_3; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SP_DEF_6; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_X_SP_DEF].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_DEF_1].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_DEF_2].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_DEF_3].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_DEF_6].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_DEF_1].holdEffectParam == STAT_STAGE_1);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_DEF_2].holdEffectParam == STAT_STAGE_2);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_DEF_3].holdEffectParam == STAT_STAGE_3);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SP_DEF_6].holdEffectParam == STAT_STAGE_6);
        ASSUME(gMovesInfo[MOVE_DISARMING_VOICE].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (item)
            TURN { USE_ITEM(player, item); }
        TURN { MOVE(opponent, MOVE_DISARMING_VOICE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Disarming Voice!");
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        if (B_X_ITEMS_BUFF >= GEN_7)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
        else
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.66), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.66), results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.50), results[3].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.40), results[4].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.33), results[5].damage);
    }
}

SINGLE_BATTLE_TEST("X Speed sharply raises battler's Speed stat", s16 damage)
{
    u32 item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_X_SPEED; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SPEED_1; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SPEED_2; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SPEED_3; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_SPEED_6; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_X_SPEED].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SPEED_1].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SPEED_2].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SPEED_3].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SPEED_6].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SPEED_1].holdEffectParam == STAT_STAGE_1);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SPEED_2].holdEffectParam == STAT_STAGE_2);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SPEED_3].holdEffectParam == STAT_STAGE_3);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_SPEED_6].holdEffectParam == STAT_STAGE_6);
        switch (item)
        {
        case ITEM_NONE:
            PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
            OPPONENT(SPECIES_WOBBUFFET) { Speed(40); }
            break;
        case ITEM_X_SPEED:
            if (B_X_ITEMS_BUFF >= GEN_7) {
                PLAYER(SPECIES_WOBBUFFET) { Speed(25); } // 25 * 2 = 50
                OPPONENT(SPECIES_WOBBUFFET) { Speed(49); }
            } else {
                PLAYER(SPECIES_WOBBUFFET) { Speed(34); } // 34 * 1.5 = 51
                OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
            }
            break;
        case ITEM_WONDER_LAUNCHER_X_SPEED_1:
            PLAYER(SPECIES_WOBBUFFET) { Speed(34); } // 34 * 1.5 = 51
            OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
            break;
        case ITEM_WONDER_LAUNCHER_X_SPEED_2:
            PLAYER(SPECIES_WOBBUFFET) { Speed(25); } // 25 * 2 = 50
            OPPONENT(SPECIES_WOBBUFFET) { Speed(49); }
            break;
        case ITEM_WONDER_LAUNCHER_X_SPEED_3:
            PLAYER(SPECIES_WOBBUFFET) { Speed(20); } // 20 * 2.5 = 50
            OPPONENT(SPECIES_WOBBUFFET) { Speed(49); }
            break;
        case ITEM_WONDER_LAUNCHER_X_SPEED_6:
            PLAYER(SPECIES_WOBBUFFET) { Speed(13); } // 13 * 4 = 52
            OPPONENT(SPECIES_WOBBUFFET) { Speed(51); }
            break;
        }
    } WHEN {
        if (item != ITEM_NONE)
            TURN { USE_ITEM(player, item); }
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        if (item != ITEM_NONE) {
            MESSAGE("Wobbuffet used Tackle!");
            MESSAGE("Foe Wobbuffet used Tackle!");
        } else {
            MESSAGE("Foe Wobbuffet used Tackle!");
            MESSAGE("Wobbuffet used Tackle!");
        }
    }
}

SINGLE_BATTLE_TEST("X Accuracy sharply raises battler's Accuracy stat")
{
    u32 item, j;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_X_ACCURACY; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_ACCURACY_1; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_ACCURACY_2; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_ACCURACY_3; }
    PARAMETRIZE { item = ITEM_WONDER_LAUNCHER_X_ACCURACY_6; }

    switch (item)
    {
    case ITEM_NONE:
        PASSES_RANDOMLY(gMovesInfo[MOVE_SING].accuracy, 100, RNG_ACCURACY);
        break;
    case ITEM_X_ACCURACY:
        if (B_X_ITEMS_BUFF >= GEN_7)
            PASSES_RANDOMLY(gMovesInfo[MOVE_SING].accuracy * 5 / 3, 100, RNG_ACCURACY);
        else
            PASSES_RANDOMLY(gMovesInfo[MOVE_SING].accuracy * 4 / 3, 100, RNG_ACCURACY);
        break;
    case ITEM_WONDER_LAUNCHER_X_ACCURACY_1:
        PASSES_RANDOMLY(gMovesInfo[MOVE_SING].accuracy * 4 / 3, 100, RNG_ACCURACY);
        break;
    case ITEM_WONDER_LAUNCHER_X_ACCURACY_3: // We lower Accuracy first for this to not surpass the 100%.
        //PASSES_RANDOMLY(gMovesInfo[MOVE_SING].accuracy * 6 / 3, 100, RNG_ACCURACY);
        //break;
    case ITEM_WONDER_LAUNCHER_X_ACCURACY_6: // We lower Accuracy first for this to not surpass the 100%.
        //PASSES_RANDOMLY(gMovesInfo[MOVE_SING].accuracy * 9 / 3, 100, RNG_ACCURACY);
        //break;
    case ITEM_WONDER_LAUNCHER_X_ACCURACY_2:
        PASSES_RANDOMLY(gMovesInfo[MOVE_SING].accuracy * 5 / 3, 100, RNG_ACCURACY);
        break;
    }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SING].accuracy == 55);
        ASSUME(gItemsInfo[ITEM_X_ACCURACY].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ACCURACY_1].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ACCURACY_2].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ACCURACY_3].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ACCURACY_6].battleUsage == EFFECT_ITEM_INCREASE_STAT);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ACCURACY_1].holdEffectParam == STAT_STAGE_1);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ACCURACY_2].holdEffectParam == STAT_STAGE_2);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ACCURACY_3].holdEffectParam == STAT_STAGE_3);
        ASSUME(gItemsInfo[ITEM_WONDER_LAUNCHER_X_ACCURACY_6].holdEffectParam == STAT_STAGE_6);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, item); }
        // Reduce Accuracy with Mud Slap Because there are no regular moves with accuracy lower than 50.
        if (gItemsInfo[item].holdEffectParam > 2) {
            for (j = 0; j < gItemsInfo[item].holdEffectParam - 2; j++) {
                TURN { MOVE(opponent, MOVE_MUD_SLAP); }
            }
        }
        TURN { MOVE(player, MOVE_SING); }
    } SCENE {
        MESSAGE("Wobbuffet used Sing!");
        MESSAGE("Foe Wobbuffet fell asleep!");
    }
}

SINGLE_BATTLE_TEST("Max Mushrooms raises battler's Attack stat", s16 damage)
{
    u16 useItem;
    PARAMETRIZE { useItem = FALSE; }
    PARAMETRIZE { useItem = TRUE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_MAX_MUSHROOMS].battleUsage == EFFECT_ITEM_INCREASE_ALL_STATS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (useItem) TURN { USE_ITEM(player, ITEM_MAX_MUSHROOMS); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Tackle!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Max Mushrooms raises battler's Defense stat", s16 damage)
{
    u16 useItem;
    PARAMETRIZE { useItem = FALSE; }
    PARAMETRIZE { useItem = TRUE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_MAX_MUSHROOMS].battleUsage == EFFECT_ITEM_INCREASE_ALL_STATS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (useItem) TURN { USE_ITEM(player, ITEM_MAX_MUSHROOMS); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Tackle!");
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.66), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Max Mushrooms raises battler's Sp. Attack stat", s16 damage)
{
    u16 useItem;
    PARAMETRIZE { useItem = FALSE; }
    PARAMETRIZE { useItem = TRUE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_MAX_MUSHROOMS].battleUsage == EFFECT_ITEM_INCREASE_ALL_STATS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (useItem) TURN { USE_ITEM(player, ITEM_MAX_MUSHROOMS); }
        TURN { MOVE(player, MOVE_DISARMING_VOICE); }
    } SCENE {
        MESSAGE("Wobbuffet used Disarming Voice!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Max Mushrooms battler's Sp. Defense stat", s16 damage)
{
    u16 useItem;
    PARAMETRIZE { useItem = FALSE; }
    PARAMETRIZE { useItem = TRUE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_MAX_MUSHROOMS].battleUsage == EFFECT_ITEM_INCREASE_ALL_STATS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (useItem) TURN { USE_ITEM(player, ITEM_MAX_MUSHROOMS); }
        TURN { MOVE(opponent, MOVE_DISARMING_VOICE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Disarming Voice!");
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.66), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Max Mushrooms raises battler's Speed stat", s16 damage)
{
    u16 useItem;
    PARAMETRIZE { useItem = FALSE; }
    PARAMETRIZE { useItem = TRUE; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_MAX_MUSHROOMS].battleUsage == EFFECT_ITEM_INCREASE_ALL_STATS);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        if (useItem) TURN { USE_ITEM(player, ITEM_MAX_MUSHROOMS); }
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        if (useItem)
        {
            MESSAGE("Wobbuffet used Tackle!");
            MESSAGE("Foe Wobbuffet used Tackle!");
        }
        else
        {
            MESSAGE("Foe Wobbuffet used Tackle!");
            MESSAGE("Wobbuffet used Tackle!");
        }
    }
}
