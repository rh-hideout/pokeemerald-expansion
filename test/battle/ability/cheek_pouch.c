#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Cheek Pouch restores 33% max HP")
{
    s16 berryHeal, cheekPouchHeal;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffectParam == 10);
        PLAYER(SPECIES_GREEDENT) { Ability(ABILITY_CHEEK_POUCH); MaxHP(60); HP(31); Item(ITEM_ORAN_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPER_FANG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        HP_BAR(player, captureDamage: &berryHeal);
        ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
        HP_BAR(player, captureDamage: &cheekPouchHeal);
    } THEN {
        EXPECT_LT(berryHeal, 0);
        EXPECT_EQ(cheekPouchHeal, -(player->maxHP / 3));
    }
}

SINGLE_BATTLE_TEST("Cheek Pouch restores HP after the berry's effect")
{
    u16 hpAfterBerry, hpAfterCheekPouch;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffectParam == 10);
        PLAYER(SPECIES_GREEDENT) { Ability(ABILITY_CHEEK_POUCH); MaxHP(60); HP(31); Item(ITEM_ORAN_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPER_FANG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        HP_BAR(player, captureHP: &hpAfterBerry);
        ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
        HP_BAR(player, captureHP: &hpAfterCheekPouch);
    } THEN {
        EXPECT_GT(hpAfterCheekPouch, hpAfterBerry);
    }
}

SINGLE_BATTLE_TEST("Cheek Pouch activates via Bug Bite/Pluck if it would trigger an effect")
{
    u16 move;
    s16 berryHeal, cheekPouchHeal;

    PARAMETRIZE { move = MOVE_BUG_BITE; }
    PARAMETRIZE { move = MOVE_PLUCK; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(move, MOVE_EFFECT_BUG_BITE));
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffectParam == 10);
        PLAYER(SPECIES_GREEDENT) { Ability(ABILITY_CHEEK_POUCH); MaxHP(60); HP(30); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ORAN_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        HP_BAR(player, captureDamage: &berryHeal);
        ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
        HP_BAR(player, captureDamage: &cheekPouchHeal);
    } THEN {
        EXPECT_LT(berryHeal, 0);
        EXPECT_EQ(cheekPouchHeal, -(player->maxHP / 3));
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Cheek Pouch activates when receiving from Fling if it would trigger an effect")
{
    s16 berryHeal, cheekPouchHeal;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffectParam == 10);
        PLAYER(SPECIES_WOBBUFFET) { Attack(1); Item(ITEM_ORAN_BERRY); }
        OPPONENT(SPECIES_GREEDENT) { Ability(ABILITY_CHEEK_POUCH); MaxHP(60); HP(30); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        HP_BAR(opponent, captureDamage: &berryHeal);
        ABILITY_POPUP(opponent, ABILITY_CHEEK_POUCH);
        HP_BAR(opponent, captureDamage: &cheekPouchHeal);
    } THEN {
        EXPECT_LT(berryHeal, 0);
        EXPECT_EQ(cheekPouchHeal, -(opponent->maxHP / 3));
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Cheek Pouch doesn't activate when using Natural Gift")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NATURAL_GIFT) == EFFECT_NATURAL_GIFT);
        PLAYER(SPECIES_GREEDENT) { Ability(ABILITY_CHEEK_POUCH); MaxHP(60); HP(40); Item(ITEM_ORAN_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_NATURAL_GIFT); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Cheek Pouch doesn't activate when user uses Fling")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        PLAYER(SPECIES_GREEDENT) { Ability(ABILITY_CHEEK_POUCH); MaxHP(60); HP(40); Item(ITEM_ORAN_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Cheek Pouch doesn't activate when using a berry from the bag")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffectParam == 10);
        PLAYER(SPECIES_GREEDENT) { Ability(ABILITY_CHEEK_POUCH); MaxHP(60); HP(20); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_ORAN_BERRY, partyIndex: 0); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
    }
}

SINGLE_BATTLE_TEST("Cheek Pouch doesn't activate under Heal Block's effect")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HEAL_BLOCK) == EFFECT_HEAL_BLOCK);
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffectParam == 10);
        PLAYER(SPECIES_GREEDENT) { Ability(ABILITY_CHEEK_POUCH); MaxHP(60); HP(31); Item(ITEM_ORAN_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); }
        TURN { MOVE(opponent, MOVE_SUPER_FANG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BLOCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, opponent);
        HP_BAR(player);
        NOT ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
    } THEN {
        EXPECT_EQ(player->item, ITEM_ORAN_BERRY);
    }
}

SINGLE_BATTLE_TEST("Cheek Pouch doesn't activate on Corrosive Gas after previously eating a berry")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(GetMoveEffect(MOVE_CORROSIVE_GAS) == EFFECT_CORROSIVE_GAS);
        ASSUME(GetMoveEffect(MOVE_RECYCLE) == EFFECT_RECYCLE);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffectParam == 10);
        PLAYER(SPECIES_GREEDENT) { Ability(ABILITY_CHEEK_POUCH); MaxHP(60); HP(31); Item(ITEM_ORAN_BERRY); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPER_FANG); }
        TURN { MOVE(player, MOVE_RECYCLE); }
        TURN { MOVE(opponent, MOVE_CORROSIVE_GAS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, opponent);
        ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECYCLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CORROSIVE_GAS, opponent);
        NOT ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
    } THEN {
        EXPECT_EQ(player->hp, 46);
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Cheek Pouch doesn't activate when user flings a berry restored by Recycle")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        ASSUME(GetMoveEffect(MOVE_RECYCLE) == EFFECT_RECYCLE);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffectParam == 10);
        PLAYER(SPECIES_GREEDENT) { Ability(ABILITY_CHEEK_POUCH); MaxHP(60); HP(31); Item(ITEM_ORAN_BERRY); Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPER_FANG); }
        TURN { MOVE(player, MOVE_RECYCLE); }
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, opponent);
        ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECYCLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        NOT ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
    } THEN {
        EXPECT_EQ(player->hp, 46);
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Cheek Pouch activation doesn't mutate damage when restoring HP mid battle")
{
    s16 damage, healing;

    GIVEN {
        PLAYER(SPECIES_GREEDENT) { Ability(ABILITY_CHEEK_POUCH); Item(ITEM_CHOPLE_BERRY); HP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_KARATE_CHOP); }
        ABILITY_POPUP(player, ABILITY_CHEEK_POUCH);
        HP_BAR(player, captureDamage: &healing);
        HP_BAR(player, captureDamage: &damage);
    } THEN {
        EXPECT_LT(healing, 0);
        EXPECT_GT(damage, 0);
    }
}
