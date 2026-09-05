#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveMakesContact(MOVE_SCRATCH));
    ASSUME(!MoveMakesContact(MOVE_SWIFT));
}

SINGLE_BATTLE_TEST("Long Reach prevents Rocky Helmet damage")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_OVERGROW; }
    PARAMETRIZE { ability = ABILITY_LONG_REACH; }
    GIVEN {
        PLAYER(SPECIES_ROWLET) { Ability(ability); MaxHP(600); HP(600); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->hp, ability == ABILITY_LONG_REACH ? 600 : 500);
    }
}

SINGLE_BATTLE_TEST("Long Reach prevents Rough Skin and Iron Barbs damage")
{
    enum Ability ability, targetAbility;
    enum Species species;
    PARAMETRIZE { ability = ABILITY_OVERGROW; species = SPECIES_GARCHOMP; targetAbility = ABILITY_ROUGH_SKIN; }
    PARAMETRIZE { ability = ABILITY_LONG_REACH; species = SPECIES_GARCHOMP; targetAbility = ABILITY_ROUGH_SKIN; }
    PARAMETRIZE { ability = ABILITY_OVERGROW; species = SPECIES_FERROTHORN; targetAbility = ABILITY_IRON_BARBS; }
    PARAMETRIZE { ability = ABILITY_LONG_REACH; species = SPECIES_FERROTHORN; targetAbility = ABILITY_IRON_BARBS; }
    GIVEN {
        PLAYER(SPECIES_ROWLET) { Ability(ability); MaxHP(800); HP(800); }
        OPPONENT(species) { Ability(targetAbility); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->hp, ability == ABILITY_LONG_REACH ? 800 : 700);
    }
}

SINGLE_BATTLE_TEST("Long Reach prevents Pickpocket from stealing the user's item")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_OVERGROW; }
    PARAMETRIZE { ability = ABILITY_LONG_REACH; }
    GIVEN {
        PLAYER(SPECIES_ROWLET) { Ability(ability); Item(ITEM_MAGOST_BERRY); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->item, ability == ABILITY_LONG_REACH ? ITEM_MAGOST_BERRY : ITEM_NONE);
        EXPECT_EQ(opponent->item, ability == ABILITY_LONG_REACH ? ITEM_NONE : ITEM_MAGOST_BERRY);
    }
}

SINGLE_BATTLE_TEST("Long Reach bypasses Fluffy's contact damage reduction", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_OVERGROW; }
    PARAMETRIZE { ability = ABILITY_LONG_REACH; }
    GIVEN {
        PLAYER(SPECIES_ROWLET) { Ability(ability); Attack(200); }
        OPPONENT(SPECIES_STUFFUL) { Ability(ABILITY_FLUFFY); HP(1000); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.5), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Long Reach does not change damage from non-contact moves", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_OVERGROW; }
    PARAMETRIZE { ability = ABILITY_LONG_REACH; }
    GIVEN {
        PLAYER(SPECIES_ROWLET) { Ability(ability); }
        OPPONENT(SPECIES_STUFFUL) { Ability(ABILITY_FLUFFY); Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Long Reach avoids protective moves' contact penalties but does not bypass protection")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SPIKY_SHIELD; }
    PARAMETRIZE { move = MOVE_BANEFUL_BUNKER; }
    PARAMETRIZE { move = MOVE_BURNING_BULWARK; }
    PARAMETRIZE { move = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_SILK_TRAP; }
    PARAMETRIZE { move = MOVE_OBSTRUCT; }
    GIVEN {
        PLAYER(SPECIES_ROWLET) { Ability(ABILITY_LONG_REACH); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
    } THEN {
        EXPECT_EQ(opponent->hp, opponent->maxHP);
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Suppressing Long Reach restores contact with Rocky Helmet")
{
    bool32 suppress;
    PARAMETRIZE { suppress = FALSE; }
    PARAMETRIZE { suppress = TRUE; }
    GIVEN {
        PLAYER(SPECIES_ROWLET) { Ability(ABILITY_LONG_REACH); MaxHP(600); HP(600); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, suppress ? MOVE_GASTRO_ACID : MOVE_CELEBRATE); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->hp, suppress ? 500 : 600);
    }
}
