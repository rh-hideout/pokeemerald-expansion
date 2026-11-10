#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_DEEP_SEA_SCALE) == HOLD_EFFECT_DEEP_SEA_SCALE);
}

SINGLE_BATTLE_TEST("Deep Sea Scale doubles Clamperl's Sp. Def", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_DEEP_SEA_SCALE; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_DRAGON_PULSE) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveEffect(MOVE_DRAGON_PULSE) == EFFECT_HIT);
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(200); }
        OPPONENT(SPECIES_CLAMPERL) { SpDefense(100); Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_PULSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_PULSE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2.0), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Deep Sea Scale does not reduce damage that targets Defense or damage to non-Clamperl holders", s16 damage)
{
    enum Item item;
    enum Move move;
    enum Species species;

    PARAMETRIZE { item = ITEM_NONE;           move = MOVE_SCRATCH;      species = SPECIES_CLAMPERL; }
    PARAMETRIZE { item = ITEM_DEEP_SEA_SCALE; move = MOVE_SCRATCH;      species = SPECIES_CLAMPERL; }
    PARAMETRIZE { item = ITEM_NONE;           move = MOVE_PSYSHOCK;     species = SPECIES_CLAMPERL; }
    PARAMETRIZE { item = ITEM_DEEP_SEA_SCALE; move = MOVE_PSYSHOCK;     species = SPECIES_CLAMPERL; }
    PARAMETRIZE { item = ITEM_NONE;           move = MOVE_DRAGON_PULSE; species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { item = ITEM_DEEP_SEA_SCALE; move = MOVE_DRAGON_PULSE; species = SPECIES_WOBBUFFET; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_PSYSHOCK) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveEffect(MOVE_PSYSHOCK) == EFFECT_PSYSHOCK);
        ASSUME(GetMoveCategory(MOVE_DRAGON_PULSE) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveEffect(MOVE_DRAGON_PULSE) == EFFECT_HIT);
        PLAYER(SPECIES_WOBBUFFET) { Attack(100); SpAttack(100); Moves(move); }
        OPPONENT(species) { Defense(200); SpDefense(200); Item(item); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[2].damage, results[3].damage);
        EXPECT_EQ(results[4].damage, results[5].damage);
    }
}
