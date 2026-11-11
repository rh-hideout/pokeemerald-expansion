#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FOUL_PLAY) == EFFECT_FOUL_PLAY);
}

SINGLE_BATTLE_TEST("Foul Play uses the target's Attack stat and stat stages of target", s16 damage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_HIGH_HORSEPOWER; }
    PARAMETRIZE { move = MOVE_FOUL_PLAY; }

    GIVEN {
        ASSUME(GetMovePower(MOVE_HIGH_HORSEPOWER) == GetMovePower(MOVE_FOUL_PLAY));
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_SHELLDER);
        OPPONENT(SPECIES_SHELLDER);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Foul Play uses the user's held item Attack modifier", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_CHOICE_BAND; }

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_CHOICE_BAND) == HOLD_EFFECT_CHOICE_BAND);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(150); }
    } WHEN {
        TURN { MOVE(player, MOVE_FOUL_PLAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOUL_PLAY, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Foul Play uses the user's Ability Attack modifier", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_PICKUP; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER; }

    GIVEN {
        PLAYER(SPECIES_DIGGERSBY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(150); }
    } WHEN {
        TURN { MOVE(player, MOVE_FOUL_PLAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOUL_PLAY, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Foul Play uses the user's burn Attack modifier", s16 damage)
{
    u32 status1;

    PARAMETRIZE { status1 = STATUS1_NONE; }
    PARAMETRIZE { status1 = STATUS1_BURN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(status1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(150); }
    } WHEN {
        TURN { MOVE(player, MOVE_FOUL_PLAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOUL_PLAY, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2.0), results[0].damage);
    }
}
