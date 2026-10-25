#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_NORMAL_GEM].holdEffect == HOLD_EFFECT_GEMS);
}

static const enum Item sStruggleGemItems[] =
{
    ITEM_NORMAL_GEM,
#if B_UPDATED_MOVE_FLAGS >= GEN_2
    ITEM_FIRE_GEM,
    ITEM_WATER_GEM,
    ITEM_ELECTRIC_GEM,
    ITEM_GRASS_GEM,
    ITEM_ICE_GEM,
    ITEM_FIGHTING_GEM,
    ITEM_POISON_GEM,
    ITEM_GROUND_GEM,
    ITEM_FLYING_GEM,
    ITEM_PSYCHIC_GEM,
    ITEM_BUG_GEM,
    ITEM_ROCK_GEM,
    ITEM_GHOST_GEM,
    ITEM_DRAGON_GEM,
    ITEM_DARK_GEM,
    ITEM_STEEL_GEM,
    ITEM_FAIRY_GEM,
#endif
};

SINGLE_BATTLE_TEST("Gem is consumed when it corresponds to the type of a move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMAL_GEM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("The Fire Gem strengthened Wobbuffet's power!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("The Normal Gem strengthened Wobbuffet's power!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    }
}

SINGLE_BATTLE_TEST("Gem is not consumed when using Struggle", s16 damage)
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_NONE; }
    for (u32 j = 0; j < ARRAY_COUNT(sStruggleGemItems); j++)
        PARAMETRIZE { item = sStruggleGemItems[j]; }

    GIVEN {
        if (item != ITEM_NONE)
            ASSUME(GetItemHoldEffect(item) == HOLD_EFFECT_GEMS);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STRUGGLE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(player->item, item);
    } FINALLY {
        for (u32 j = 0; j < ARRAY_COUNT(sStruggleGemItems); j++)
            EXPECT_EQ(results[0].damage, results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Gem boost is only applied once")
{
    s16 boostedHit;
    s16 normalHit;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMAL_GEM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("The Normal Gem strengthened Wobbuffet's power!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &boostedHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &normalHit);
    } THEN {
        if (I_GEM_BOOST_POWER >= GEN_6)
            EXPECT_MUL_EQ(normalHit, Q_4_12(1.3), boostedHit);
        else
            EXPECT_MUL_EQ(normalHit, Q_4_12(1.5), boostedHit);
    }
}

SINGLE_BATTLE_TEST("Gem modifier is used for all hits of Multi Hit Moves")
{
    s16 firstHit;
    s16 secondHit;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMAL_GEM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_DOUBLE_HIT);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_HIT, player);
        HP_BAR(opponent, captureDamage: &firstHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_HIT, player);
        HP_BAR(opponent, captureDamage: &secondHit);
    } THEN {
        EXPECT_EQ(firstHit, secondHit);
    }
}

SINGLE_BATTLE_TEST("Gem is consumed if the move type is changed")
{
    GIVEN {
        PLAYER(SPECIES_DELCATTY) { Ability(ABILITY_NORMALIZE); Item(ITEM_NORMAL_GEM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_FEINT_ATTACK);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("The Normal Gem strengthened Delcatty's power!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FEINT_ATTACK, player);
    }
}
