#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Immunity prevents Toxic Orb poison without consuming the item")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_THICK_FAT; }
    PARAMETRIZE { ability = ABILITY_IMMUNITY; }
    GIVEN {
        PLAYER(SPECIES_SNORLAX) { Ability(ability); Item(ITEM_TOXIC_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(player->status1 & STATUS1_PSN_ANY, ability == ABILITY_IMMUNITY ? STATUS1_NONE : STATUS1_TOXIC_POISON);
        EXPECT_EQ(player->item, ITEM_TOXIC_ORB);
    }
}

SINGLE_BATTLE_TEST("Immunity cures regular and bad poison when gained through Skill Swap")
{
    u32 status;
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    GIVEN {
        PLAYER(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); Speed(100); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Status1(status); MaxHP(1000); HP(1000); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); }
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_IMMUNITY);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
        EXPECT_EQ(opponent->hp, 1000);
    }
}

SINGLE_BATTLE_TEST("Immunity stops preventing poison while suppressed")
{
    bool32 suppress;
    PARAMETRIZE { suppress = FALSE; }
    PARAMETRIZE { suppress = TRUE; }
    GIVEN {
        PLAYER(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); MaxHP(1000); HP(1000); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        if (suppress)
            TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(opponent, MOVE_TOXIC); }
    } THEN {
        EXPECT_EQ(player->status1 & STATUS1_PSN_ANY, suppress ? STATUS1_TOXIC_POISON : STATUS1_NONE);
    }
}

DOUBLE_BATTLE_TEST("Immunity does not protect its ally from poison")
{
    GIVEN {
        PLAYER(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); Speed(150); }
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1000); Speed(100); }
        OPPONENT(SPECIES_NIDOKING) { Ability(ABILITY_POISON_POINT); Speed(50); }
        OPPONENT(SPECIES_WYNAUT) { Speed(25); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TOXIC, target: playerRight); }
    } THEN {
        EXPECT_EQ(playerRight->status1 & STATUS1_PSN_ANY, STATUS1_TOXIC_POISON);
        EXPECT_EQ(playerLeft->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Immunity does not prevent burns or paralysis")
{
    enum Move move;
    u32 status;
    PARAMETRIZE { move = MOVE_WILL_O_WISP; status = STATUS1_BURN; }
    PARAMETRIZE { move = MOVE_THUNDER_WAVE; status = STATUS1_PARALYSIS; }
    GIVEN {
        PLAYER(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); MaxHP(1000); HP(1000); Speed(100); }
        OPPONENT(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, move); }
    } THEN {
        EXPECT_EQ(player->status1, status);
    }
}

SINGLE_BATTLE_TEST("Immunity prevents Poison Sting poison")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_POISON_STING, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); }
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_STING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_STING, player);
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Immunity prevents Toxic bad poison")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        MESSAGE("Wobbuffet used Toxic!");
        ABILITY_POPUP(opponent, ABILITY_IMMUNITY);
        MESSAGE("It doesn't affect the opposing Snorlax…");
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Immunity prevents Toxic Spikes poison")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Immunity doesn't prevent Pokémon from being poisoned by Toxic Spikes on switch-in if forced in by phazing with Mold Breaker, but it cures it immediately")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); }
        OPPONENT(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_DRAGON_TAIL); }
    } SCENE {
        STATUS_ICON(player, STATUS1_POISON);
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Immunity cures existing poison on turn 0")
{
    GIVEN {
        PLAYER(SPECIES_ZANGOOSE) {
            Ability(ABILITY_IMMUNITY);
            Status1(STATUS1_POISON);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } SCENE {
        ABILITY_POPUP(player, ABILITY_IMMUNITY);
        TURN { MOVE(player, MOVE_SPLASH); }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}
