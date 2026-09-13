#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Quick Feet boosts Speed while burned or poisoned")
{
    u32 status;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    GIVEN {
        PLAYER(SPECIES_GRANBULL) { Ability(ABILITY_QUICK_FEET); Status1(status); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(149); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Quick Feet boosts a paralyzed user's Speed instead of applying the paralysis penalty")
{
    GIVEN {
        PLAYER(SPECIES_GRANBULL) { Ability(ABILITY_QUICK_FEET); Status1(STATUS1_PARALYSIS); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(149); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_PARALYSIS, FALSE)); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Quick Feet does not boost Speed while the user is only confused")
{
    GIVEN {
        PLAYER(SPECIES_GRANBULL) { Ability(ABILITY_QUICK_FEET); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(101); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWAGGER); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_CONFUSION, FALSE)); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_CONFUSION, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWAGGER, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    } THEN {
        EXPECT(player->volatiles.confusionTimer > 0);
    }
}

SINGLE_BATTLE_TEST("Quick Feet stops boosting Speed after the user cures its status")
{
    GIVEN {
        PLAYER(SPECIES_GRANBULL) { Ability(ABILITY_QUICK_FEET); Status1(STATUS1_BURN); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(125); }
    } WHEN {
        TURN { MOVE(player, MOVE_REFRESH); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFRESH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Quick Feet stops boosting Speed while suppressed")
{
    GIVEN {
        PLAYER(SPECIES_GRANBULL) { Ability(ABILITY_QUICK_FEET); Status1(STATUS1_POISON); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(125); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Quick Feet stacks with Choice Scarf")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_CHOICE_SCARF; }
    GIVEN {
        PLAYER(SPECIES_GRANBULL) { Ability(ABILITY_QUICK_FEET); Item(item); Status1(STATUS1_BURN); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (item == ITEM_NONE)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        }
        else
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Quick Feet does not prevent full paralysis")
{
    PASSES_RANDOMLY(75, 100, RNG_PARALYSIS);
    GIVEN {
        PLAYER(SPECIES_GRANBULL) { Ability(ABILITY_QUICK_FEET); Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}
