#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Neutralizing Gas fainting as Discharge's ally restores Sheer Force before opposing secondary effects")
{
    KNOWN_FAILING;
    PASSES_RANDOMLY(100, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_DISCHARGE) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(MoveHasAdditionalEffect(MOVE_DISCHARGE, MOVE_EFFECT_PARALYSIS));
        ASSUME(MoveIsAffectedBySheerForce(MOVE_DISCHARGE));
        PLAYER(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DISCHARGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISCHARGE, playerLeft);
        HP_BAR(playerRight);
        NONE_OF {
            STATUS_ICON(opponentLeft, paralysis: TRUE);
            STATUS_ICON(opponentRight, paralysis: TRUE);
        }
    } THEN {
        EXPECT_EQ(playerRight->hp, 0);
        EXPECT(!playerRight->volatiles.neutralizingGas);
        EXPECT_LT(opponentLeft->hp, opponentLeft->maxHP);
        EXPECT_LT(opponentRight->hp, opponentRight->maxHP);
        EXPECT_EQ(opponentLeft->status1, 0);
        EXPECT_EQ(opponentRight->status1, 0);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas fainting as Discharge's foe allows 30% paralysis on the attacker's ally")
{
    KNOWN_FAILING;
    bool32 gasOnRight;
    PARAMETRIZE { gasOnRight = FALSE; }
    PARAMETRIZE { gasOnRight = TRUE; }
    PASSES_RANDOMLY(30, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_DISCHARGE) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(MoveHasAdditionalEffect(MOVE_DISCHARGE, MOVE_EFFECT_PARALYSIS));
        ASSUME(MoveIsAffectedBySheerForce(MOVE_DISCHARGE));
        PLAYER(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
        if (gasOnRight)
        {
            OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
            OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); }
        }
        else
        {
            OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); }
            OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
        }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DISCHARGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISCHARGE, playerLeft);
        HP_BAR(playerRight);
        STATUS_ICON(playerRight, paralysis: TRUE);
    } THEN {
        EXPECT_EQ((gasOnRight ? opponentRight : opponentLeft)->hp, 0);
        EXPECT(!(gasOnRight ? opponentRight : opponentLeft)->volatiles.neutralizingGas);
        EXPECT_EQ(playerRight->status1, STATUS1_PARALYSIS);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas overwritten by Insomnia reactivates switch-in Abilities before curing sleep")
{
    GIVEN {
        ASSUME(GetMoveOverwriteAbility(MOVE_WORRY_SEED) == ABILITY_INSOMNIA);
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); Status1(STATUS1_SLEEP); Speed(50); }
        OPPONENT(SPECIES_MASQUERAIN) { Ability(ABILITY_INTIMIDATE); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WORRY_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, opponent);
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(player, ABILITY_INSOMNIA);
        STATUS_ICON(player, sleep: FALSE);
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_INSOMNIA);
        EXPECT_EQ(player->status1, 0);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT(!player->volatiles.neutralizingGas);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas reactivates other Abilities before its replacement")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_ENTRAINMENT; }
    PARAMETRIZE { move = MOVE_ROLE_PLAY; }
    PARAMETRIZE { move = MOVE_DOODLE; }

    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); Speed(100); }
        OPPONENT(SPECIES_MASQUERAIN) { Ability(ABILITY_INTIMIDATE); Speed(50); }
    } WHEN {
        if (move == MOVE_ENTRAINMENT)
        {
            TURN { MOVE(opponent, move); }
        }
        else
        {
            TURN { MOVE(player, move); }
        }
    } SCENE {
        if (move == MOVE_ENTRAINMENT)
        {
            ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        }
        else
        {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
        }
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_INTIMIDATE);
        EXPECT(!player->volatiles.neutralizingGas);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas does not grant the replacement Ability's protection during reactivation")
{
    GIVEN {
        PLAYER(SPECIES_METAGROSS) { Ability(ABILITY_CLEAR_BODY); }
        PLAYER(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ENTRAINMENT, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENTRAINMENT, playerLeft);
        ABILITY_POPUP(playerRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
    } THEN {
        EXPECT_EQ(opponentLeft->ability, ABILITY_CLEAR_BODY);
        EXPECT(!opponentLeft->volatiles.neutralizingGas);
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas persists when only one of two holders has its Ability replaced")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_ENTRAINMENT; }
    PARAMETRIZE { move = MOVE_ROLE_PLAY; }

    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_MASQUERAIN) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
    } WHEN {
        if (move == MOVE_ENTRAINMENT)
        {
            TURN { MOVE(opponentLeft, move, target: playerLeft); }
        }
        else
        {
            TURN { MOVE(playerLeft, move, target: opponentLeft); }
        }
    } SCENE {
        if (move == MOVE_ENTRAINMENT)
        {
            ANIMATION(ANIM_TYPE_MOVE, move, opponentLeft);
        }
        else
        {
            ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        }
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
            ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
        }
    } THEN {
        EXPECT_EQ(playerLeft->ability, ABILITY_INTIMIDATE);
        EXPECT(!playerLeft->volatiles.neutralizingGas);
        EXPECT(playerRight->volatiles.neutralizingGas);
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas ends when Doodle replaces both holders' Abilities")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); Speed(100); }
        PLAYER(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); Speed(90); }
        OPPONENT(SPECIES_MASQUERAIN) { Ability(ABILITY_INTIMIDATE); Speed(80); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Speed(70); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DOODLE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
        ABILITY_POPUP(playerRight, ABILITY_INTIMIDATE);
    } THEN {
        EXPECT_EQ(playerLeft->ability, ABILITY_INTIMIDATE);
        EXPECT_EQ(playerRight->ability, ABILITY_INTIMIDATE);
        EXPECT(!playerLeft->volatiles.neutralizingGas);
        EXPECT(!playerRight->volatiles.neutralizingGas);
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas releases suppression when overwritten or suppressed")
{
    enum Move move;
    enum Ability ability;
    PARAMETRIZE { move = MOVE_WORRY_SEED; ability = ABILITY_INSOMNIA; }
    PARAMETRIZE { move = MOVE_SIMPLE_BEAM; ability = ABILITY_SIMPLE; }
    PARAMETRIZE { move = MOVE_GASTRO_ACID; ability = ABILITY_NEUTRALIZING_GAS; }

    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->ability, ability);
        EXPECT(!player->volatiles.neutralizingGas);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT(player->volatiles.gastroAcid == (move == MOVE_GASTRO_ACID));
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas ends when Mummy or Lingering Aroma overwrites the attacker's Ability")
{
    enum Species species;
    enum Ability ability;
    PARAMETRIZE { species = SPECIES_COFAGRIGUS; ability = ABILITY_MUMMY; }
    PARAMETRIZE { species = SPECIES_OINKOLOGNE_M; ability = ABILITY_LINGERING_AROMA; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_VINE_WHIP));
        ASSUME(GetMoveCategory(MOVE_VINE_WHIP) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(species) { Ability(ability); Item(ITEM_ABILITY_SHIELD); }
        OPPONENT(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_VINE_WHIP, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VINE_WHIP, playerLeft);
        HP_BAR(opponentLeft);
        ABILITY_POPUP(opponentLeft, ability);
        ABILITY_POPUP(opponentRight, ABILITY_INTIMIDATE);
    } THEN {
        EXPECT_EQ(playerLeft->ability, ability);
        EXPECT(!playerLeft->volatiles.neutralizingGas);
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas activates on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas prevents opponent's switch-in ability from activating")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_ZEKROM) { Ability(ABILITY_TERAVOLT); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_TERAVOLT);
            MESSAGE("The opposing Zekrom is radiating a bursting aura!");
        }
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas prevents ally's switch-in ability from activating")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_ZEKROM) { Ability(ABILITY_TERAVOLT); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_NEUTRALIZING_GAS);
        NONE_OF {
            ABILITY_POPUP(playerRight, ABILITY_TERAVOLT);
            MESSAGE("Zekrom is radiating a bursting aura!");
        }
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas ignores all battlers' ability effects")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_WATER_ABSORB); }
        OPPONENT(SPECIES_BELLIBOLT) { Ability(ABILITY_ELECTROMORPHOSIS); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SURF); MOVE(playerRight, MOVE_SURF); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        NONE_OF {
            ABILITY_POPUP(playerRight, ABILITY_TELEPATHY);
            ABILITY_POPUP(opponentLeft, ABILITY_WATER_ABSORB);
            ABILITY_POPUP(opponentRight, ABILITY_ELECTROMORPHOSIS);
        }
        HP_BAR(opponentLeft);
        HP_BAR(playerRight);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerRight);
        NONE_OF {
            ABILITY_POPUP(opponentLeft, ABILITY_WATER_ABSORB);
            ABILITY_POPUP(opponentRight, ABILITY_ELECTROMORPHOSIS);
        }
        HP_BAR(playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas ignores multipliers from attacker's ability", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NEUTRALIZING_GAS; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WEEZING) { Ability(ability); }
        OPPONENT(SPECIES_AZUMARILL) { Ability(ABILITY_HUGE_POWER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas ignores multipliers from target's ability", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NEUTRALIZING_GAS; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH) == TRUE);
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_WEEZING) { Ability(ability); }
        OPPONENT(SPECIES_BEWEAR) { Ability(ABILITY_FLUFFY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas ignores multipliers from target's ally's ability", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NEUTRALIZING_GAS; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; }
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_CLEFAIRY) { Ability(ABILITY_FRIEND_GUARD); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.75), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas ignores multipliers from ally's ability", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NEUTRALIZING_GAS; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WEEZING) { Ability(ability); }
        PLAYER(SPECIES_WO_CHIEN) { Ability(ABILITY_TABLETS_OF_RUIN); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.75), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas leaving the field allows abilities to activate in turn order")
{
    u32 speedPlayerRight, speedOppLeft, speedOppRight;
    PARAMETRIZE { speedPlayerRight = 5; speedOppLeft = 3; speedOppRight = 2; }
    PARAMETRIZE { speedPlayerRight = 3; speedOppLeft = 5; speedOppRight = 2; }
    PARAMETRIZE { speedPlayerRight = 2; speedOppLeft = 3; speedOppRight = 5; }
    PARAMETRIZE { speedPlayerRight = 3; speedOppLeft = 2; speedOppRight = 5; }
    PARAMETRIZE { speedPlayerRight = 2; speedOppLeft = 5; speedOppRight = 3; }
    PARAMETRIZE { speedPlayerRight = 5; speedOppLeft = 2; speedOppRight = 3; }
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); Speed(4); }
        PLAYER(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); Speed(speedPlayerRight); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); Speed(speedOppLeft); }
        OPPONENT(SPECIES_ZEKROM) { Ability(ABILITY_TERAVOLT); Speed(speedOppRight); }
    } WHEN {
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        SWITCH_OUT_MESSAGE("Weezing");
        MESSAGE("The effects of the neutralizing gas wore off!");
        if (speedPlayerRight > speedOppLeft)
        {
            if (speedPlayerRight > speedOppRight) {
                ABILITY_POPUP(playerRight, ABILITY_INTREPID_SWORD);
                if (speedOppRight > speedOppLeft) {
                    ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                    ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
                } else {
                    ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
                    ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                }
            } else {
                ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                ABILITY_POPUP(playerRight, ABILITY_INTREPID_SWORD);
                ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
            }

        } else {
            if (speedOppLeft > speedOppRight) {
                ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
                if (speedOppRight > speedPlayerRight) {
                    ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                    ABILITY_POPUP(playerRight, ABILITY_INTREPID_SWORD);
                } else {
                    ABILITY_POPUP(playerRight, ABILITY_INTREPID_SWORD);
                    ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                }
            } else {
                ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
                ABILITY_POPUP(playerRight, ABILITY_INTREPID_SWORD);
            }
        }
        SEND_IN_MESSAGE("Wobbuffet");
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas prevents Insomnia from blocking Rest")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_DROWZEE) { Ability(ABILITY_INSOMNIA); HP(1); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(player, MOVE_REST); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_INSOMNIA);
        // ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        // STATUS_ICON(player, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas prevents Trace from copying it")
{
    GIVEN {
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_TRACE);
            ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        }
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas prevents Contrary inverting stat boosts")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        PLAYER(SPECIES_INKAY) { Ability(ABILITY_CONTRARY); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); MOVE(opponent, MOVE_LEER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_GT(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_LT(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas exiting the field does not activate abilities that were not suppressed by it again")
{
    enum Species species;
    enum Ability ability;
    // These are the only abilities that could immediately activate again
    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW; ability = ABILITY_AS_ONE_SHADOW_RIDER; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; }

    GIVEN {
        ASSUME(gAbilitiesInfo[ability].cantBeSuppressed);
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ability);
        MESSAGE("The effects of the neutralizing gas wore off!");
        NOT ABILITY_POPUP(player, ability);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas exiting the field does not activate Imposter even if it did not activate before")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DITTO) { Ability(ABILITY_IMPOSTER); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_IMPOSTER);
        MESSAGE("The effects of the neutralizing gas wore off!");
        NOT ABILITY_POPUP(player, ABILITY_IMPOSTER);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas exiting the field does not activate Air Lock/Cloud Nine but their effects are kept")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_GOLDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RAIN_DANCE) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_RAIN_DANCE) == BATTLE_WEATHER_RAIN);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_LUDICOLO) { Ability(ABILITY_RAIN_DISH); }
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_AIR_LOCK);
        MESSAGE("The effects of the neutralizing gas wore off!");
        NOT ABILITY_POPUP(player, ABILITY_AIR_LOCK);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
        NOT ABILITY_POPUP(opponent, ABILITY_RAIN_DISH);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas only displays exiting message for the last user leaving the field")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        SEND_IN_MESSAGE("Wobbuffet");
        MESSAGE("The effects of the neutralizing gas wore off!");
        NOT MESSAGE("The effects of the neutralizing gas wore off!");
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas is active for the duration of a Spread Move even if Neutralizing Gas is no longer on the field")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_ORIGIN_PULSE) == TARGET_BOTH);
        PLAYER(SPECIES_WEEZING) { HP(1); Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_GOLEM) { Ability(ABILITY_STURDY); }
        OPPONENT(SPECIES_BASCULEGION) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ORIGIN_PULSE); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_NEUTRALIZING_GAS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ORIGIN_PULSE, opponentLeft);
        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        MESSAGE("Weezing fainted!");
        MESSAGE("Golem fainted!");
        NOT ABILITY_POPUP(playerRight, ABILITY_STURDY);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas is active until the last Dragon Darts hit even if Neutralizing Gas is no longer on the field")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_DRAGON_DARTS) == TARGET_SMART);
        PLAYER(SPECIES_WEEZING) { HP(1); Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_GOLEM) { HP(2); MaxHP(2); Ability(ABILITY_STURDY); }
        OPPONENT(SPECIES_BASCULEGION) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_DRAGON_DARTS, target: playerLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_NEUTRALIZING_GAS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, opponentLeft);
        HP_BAR(playerLeft);
        MESSAGE("Weezing fainted!");
        HP_BAR(playerRight);
        NOT MESSAGE("Golem fainted!");
        ABILITY_POPUP(playerRight, ABILITY_STURDY);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas doesn't reactivate Beads of Ruin after Chi-Yu faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); Speed(2); }
        OPPONENT(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); HP(1); Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("The opposing Chi-Yu fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft);
        MESSAGE("The effects of the neutralizing gas wore off!");
        NONE_OF {
            ABILITY_POPUP(opponentRight, ABILITY_BEADS_OF_RUIN);
            MESSAGE("The opposing Chi-Yu's Beads of Ruin weakened the Sp. Def of all surrounding Pokémon!");
        }
        MESSAGE("The opposing Weezing fainted!");
    }
}
