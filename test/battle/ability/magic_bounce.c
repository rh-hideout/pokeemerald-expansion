#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Magic Bounce bounces back status moves")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, opponent);
        STATUS_ICON(player, badPoison: TRUE);
    } THEN {
        EXPECT(player->status1 & STATUS1_TOXIC_POISON);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Magic Bounce wont activate if ability user protects")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, opponent);
            STATUS_ICON(player, badPoison: TRUE);
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Magic Bounce wont activate if ability user is in a semi-invulnerable position")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DIG) == EFFECT_SEMI_INVULNERABLE);
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DIG); MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIG, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, opponent);
            STATUS_ICON(player, badPoison: TRUE);
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Magic Bounce bounces back powder moves")
{
    GIVEN {
        ASSUME(IsPowderMove(MOVE_STUN_SPORE));
        ASSUME(GetMoveEffect(MOVE_STUN_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_STUN_SPORE) == MOVE_EFFECT_PARALYSIS);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_STUN_SPORE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, opponent);
        STATUS_ICON(player, paralysis: TRUE);
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_PARALYSIS);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Magic Bounce cannot bounce back powder moves against Grass Types")
{
    GIVEN {
        WITH_CONFIG(B_POWDER_GRASS, GEN_6);
        ASSUME(IsPowderMove(MOVE_STUN_SPORE));
        ASSUME(GetSpeciesType(SPECIES_ODDISH, 0) == TYPE_GRASS);
        PLAYER(SPECIES_ODDISH);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_STUN_SPORE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

DOUBLE_BATTLE_TEST("Magic Bounce bounces back moves hitting both foes at two foes")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        ASSUME(GetMoveTarget(MOVE_LEER) == TARGET_BOTH);
        PLAYER(SPECIES_ABRA);
        PLAYER(SPECIES_KADABRA);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LEER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);

        ABILITY_POPUP(opponentLeft, ABILITY_MAGIC_BOUNCE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, opponentLeft);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

DOUBLE_BATTLE_TEST("Magic Bounce activates on all opposing mons")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        ASSUME(GetMoveTarget(MOVE_LEER) == TARGET_BOTH);
        PLAYER(SPECIES_ABRA);
        PLAYER(SPECIES_KADABRA);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
        OPPONENT(SPECIES_NATU) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LEER); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_MAGIC_BOUNCE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, opponentLeft);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(playerRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 2);
    }
}

DOUBLE_BATTLE_TEST("Magic Bounce bounces back moves hitting foes field")
{
    enum Species battlerOne, battlerTwo;
    enum Ability abilityBattlerOne, abilityBattlerTwo;

    PARAMETRIZE { battlerOne = SPECIES_NATU; abilityBattlerOne = ABILITY_MAGIC_BOUNCE;
                  battlerTwo = SPECIES_ESPEON; abilityBattlerTwo = ABILITY_SYNCHRONIZE; }
    PARAMETRIZE { battlerOne = SPECIES_NATU; abilityBattlerOne = ABILITY_SYNCHRONIZE;
                  battlerTwo = SPECIES_ESPEON; abilityBattlerTwo = ABILITY_MAGIC_BOUNCE; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_STEALTH_ROCK) == TARGET_OPPONENTS_FIELD);
        PLAYER(SPECIES_ABRA);
        PLAYER(SPECIES_KADABRA);
        OPPONENT(battlerOne) { Ability(abilityBattlerOne); }
        OPPONENT(battlerTwo) { Ability(abilityBattlerTwo); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STEALTH_ROCK); }
    } SCENE {
        if (abilityBattlerOne == ABILITY_MAGIC_BOUNCE)
            ABILITY_POPUP(opponentLeft, ABILITY_MAGIC_BOUNCE);
        else
            ABILITY_POPUP(opponentRight, ABILITY_MAGIC_BOUNCE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, playerLeft);
        if (abilityBattlerOne == ABILITY_MAGIC_BOUNCE) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponentLeft);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponentRight);
        }
    } THEN {
        EXPECT(IsHazardOnSide(B_SIDE_PLAYER, HAZARDS_STEALTH_ROCK));
        EXPECT(!IsHazardOnSide(B_SIDE_OPPONENT, HAZARDS_STEALTH_ROCK));
    }
}

SINGLE_BATTLE_TEST("Magic Bounce bounced back status moves can not be bounced back by Magic Bounce")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        PLAYER(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, opponent);
        STATUS_ICON(player, badPoison: TRUE);
    } THEN {
        EXPECT(player->status1 & STATUS1_TOXIC_POISON);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Magic Bounce can't reflect back Stealth Rock from a semi-invulnerable posistion even with No Guard")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_STEALTH_ROCK) == TARGET_OPPONENTS_FIELD);
        ASSUME(GetMoveEffect(MOVE_DIG) == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DIG); MOVE(player, MOVE_STEALTH_ROCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIG, opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, player);
    } THEN {
        EXPECT(!IsHazardOnSide(B_SIDE_PLAYER, HAZARDS_STEALTH_ROCK));
        EXPECT(IsHazardOnSide(B_SIDE_OPPONENT, HAZARDS_STEALTH_ROCK));
    }
}

SINGLE_BATTLE_TEST("Magic Bounce bounces back status moves before Magic Coat")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_MAGIC_COAT); MOVE(player, MOVE_LEER); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, opponent);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Magic Bounce will trigger after all valid targets have been targetted")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_PACK].holdEffect == HOLD_EFFECT_EJECT_PACK);
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        ASSUME(GetMoveTarget(MOVE_LEER) == TARGET_BOTH);
        PLAYER(SPECIES_ABRA);
        PLAYER(SPECIES_KADABRA) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LEER); SEND_OUT(playerRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);

        ABILITY_POPUP(opponentLeft, ABILITY_MAGIC_BOUNCE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, opponentLeft);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
    } THEN {
        EXPECT_EQ(playerRight->species, SPECIES_WOBBUFFET);
    }
}
