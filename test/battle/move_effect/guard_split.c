#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_GUARD_SPLIT) == EFFECT_GUARD_SPLIT);
}

SINGLE_BATTLE_TEST("Guard Split averages users and targets Def and Sp. Def stats")
{
    GIVEN {
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_IVYSAUR);
    } WHEN {
        TURN { MOVE(player, MOVE_GUARD_SPLIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SPLIT, player);
    } THEN {
        EXPECT_EQ(player->defense, opponent->defense);
        EXPECT_EQ(player->spDefense, opponent->spDefense);
    }
}

SINGLE_BATTLE_TEST("Defense stat stages apply to Guard Split's altered stat", s16 damage)
{
    bool32 boostDefense;
    PARAMETRIZE { boostDefense = FALSE; }
    PARAMETRIZE { boostDefense = TRUE; }
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_IRON_DEFENSE, defense: +2);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Defense(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(100); Defense(200); }
    } WHEN {
        if (boostDefense)
            TURN { MOVE(player, MOVE_IRON_DEFENSE); }
        TURN { MOVE(player, MOVE_GUARD_SPLIT); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (boostDefense)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_IRON_DEFENSE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SPLIT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(player->defense, 110);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + (boostDefense ? 2 : 0));
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Assault Vest boosts Guard Split's altered Sp. Def stat", s16 damage)
{
    enum Item item;
    PARAMETRIZE { item = ITEM_ASSAULT_VEST; }
    PARAMETRIZE { item = ITEM_NONE; }
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_ASSAULT_VEST) == HOLD_EFFECT_ASSAULT_VEST);
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Attack(1); SpDefense(20); Speed(1); Item(item); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { SpAttack(100); SpDefense(200); Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GUARD_SPLIT); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SPLIT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Eviolite boosts Guard Split's altered Defense and Sp. Def stats", s16 damage)
{
    enum Item item;
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH;   item = ITEM_EVIOLITE; }
    PARAMETRIZE { move = MOVE_SCRATCH;   item = ITEM_NONE; }
    PARAMETRIZE { move = MOVE_WATER_GUN; item = ITEM_EVIOLITE; }
    PARAMETRIZE { move = MOVE_WATER_GUN; item = ITEM_NONE; }
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_EVIOLITE) == HOLD_EFFECT_EVIOLITE);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_PORYGON) { Defense(20); SpDefense(20); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(100); Defense(200); SpAttack(100); SpDefense(200); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GUARD_SPLIT); }
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SPLIT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage);
    }
}
