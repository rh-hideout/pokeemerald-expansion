#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_BODY_PRESS) == EFFECT_BODY_PRESS);
    ASSUME(GetMoveCategory(MOVE_BODY_PRESS) == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Body Press uses physical defense stat of target", s16 damage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_DRILL_PECK; }
    PARAMETRIZE { move = MOVE_BODY_PRESS; }

    GIVEN {
        ASSUME(GetMovePower(MOVE_DRILL_PECK) == GetMovePower(MOVE_BODY_PRESS));
        ASSUME_STAT_CHANGE(MOVE_CHARM, attack: -2);
        PLAYER(SPECIES_MEW);
        OPPONENT(SPECIES_SHELLDER);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARM); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Body Press's damage depends on the user's base Defense instead of its base Attack", s16 damage)
{
    u32 def, atk;
    PARAMETRIZE { def = 150; atk = 179; } // Atk is higher
    PARAMETRIZE { atk = 150; def = 179; } // Atk is lower
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Attack(atk); Defense(def); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_BODY_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_PRESS, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Body Press's damage depends on the user's Defense and not Attack stat stages", s16 damage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_IRON_DEFENSE; }
    PARAMETRIZE { move = MOVE_SWORDS_DANCE; }
    PARAMETRIZE { move = MOVE_CELEBRATE; } // Nothing, stats are default
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_IRON_DEFENSE, defense: +2);
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Attack(150); Defense(150); }
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, MOVE_BODY_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_PRESS, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Body Press uses Defense Stat even in Wonder Room", s16 damage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_WONDER_ROOM; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WONDER_ROOM) == EFFECT_WONDER_ROOM);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(50); Defense(150); }
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, MOVE_BODY_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_PRESS, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Body Press uses Special Defense stat Stages in Wonder Room", s16 damage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_IRON_DEFENSE; }
    PARAMETRIZE { move = MOVE_AMNESIA; }
    PARAMETRIZE { move = MOVE_CELEBRATE; } // Nothing, stats are default
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_IRON_DEFENSE, defense: +2);
        ASSUME_STAT_CHANGE(MOVE_AMNESIA, spDef: +2);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(150); Defense(150); }
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_WONDER_ROOM); }
        TURN { MOVE(opponent, MOVE_BODY_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_PRESS, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Body Press is influenced by Attack modifiers other than stat stages", s16 damage)
{
    enum Species species;
    enum Ability ability;
    enum Item item;
    u32 status;
    u32 maxHP, hp;

    PARAMETRIZE { species = SPECIES_WOBBUFFET;              ability = ABILITY_SHADOW_TAG;      item = ITEM_NONE;        status = STATUS1_NONE; maxHP = 100; hp = 100; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET;              ability = ABILITY_SHADOW_TAG;      item = ITEM_CHOICE_BAND; status = STATUS1_NONE; maxHP = 100; hp = 100; }
    PARAMETRIZE { species = SPECIES_AZUMARILL;              ability = ABILITY_HUGE_POWER;      item = ITEM_NONE;        status = STATUS1_NONE; maxHP = 100; hp = 100; }
    PARAMETRIZE { species = SPECIES_DARMANITAN_GALAR;       ability = ABILITY_GORILLA_TACTICS; item = ITEM_NONE;        status = STATUS1_NONE; maxHP = 100; hp = 100; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET;              ability = ABILITY_SHADOW_TAG;      item = ITEM_NONE;        status = STATUS1_BURN; maxHP = 100; hp = 100; }
    PARAMETRIZE { species = SPECIES_SWELLOW;                ability = ABILITY_GUTS;            item = ITEM_NONE;        status = STATUS1_BURN; maxHP = 100; hp = 100; }
    PARAMETRIZE { species = SPECIES_ARCHEOPS;               ability = ABILITY_DEFEATIST;       item = ITEM_NONE;        status = STATUS1_NONE; maxHP = 100; hp = 50;  }
    PARAMETRIZE { species = SPECIES_REGIGIGAS;              ability = ABILITY_SLOW_START;      item = ITEM_NONE;        status = STATUS1_NONE; maxHP = 100; hp = 100; }

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_CHOICE_BAND) == HOLD_EFFECT_CHOICE_BAND);
        PLAYER(species) { Ability(ability); Item(item); Status1(status); MaxHP(maxHP); HP(hp); Attack(100); Defense(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(500); HP(500); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_BODY_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_PRESS, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[3].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[4].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[5].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[6].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[7].damage);
    }
}

SINGLE_BATTLE_TEST("Body Press is not influenced by Defense modifiers other than stat stages", s16 damage)
{
    enum Species species;
    enum Ability ability;
    enum Item item;
    u32 status;

    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_SHADOW_TAG;  item = ITEM_NONE;         status = STATUS1_NONE; }
    PARAMETRIZE { species = SPECIES_FURFROU;   ability = ABILITY_FUR_COAT;    item = ITEM_NONE;         status = STATUS1_NONE; }
    PARAMETRIZE { species = SPECIES_MILOTIC;   ability = ABILITY_MARVEL_SCALE; item = ITEM_NONE;        status = STATUS1_POISON; }
    PARAMETRIZE { species = SPECIES_PORYGON;   ability = ABILITY_TRACE;       item = ITEM_EVIOLITE;     status = STATUS1_NONE; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_SHADOW_TAG;  item = ITEM_ASSAULT_VEST; status = STATUS1_NONE; }

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_EVIOLITE) == HOLD_EFFECT_EVIOLITE);
        ASSUME(GetItemHoldEffect(ITEM_ASSAULT_VEST) == HOLD_EFFECT_ASSAULT_VEST);
        PLAYER(species) { Ability(ability); Item(item); Status1(status); Attack(100); Defense(100); SpDefense(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(500); HP(500); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_BODY_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_PRESS, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
        EXPECT_EQ(results[2].damage, results[3].damage);
        EXPECT_EQ(results[3].damage, results[4].damage);
    }
}

// Unconfirmed by Bulbapedia:
// - Defeatist interaction
