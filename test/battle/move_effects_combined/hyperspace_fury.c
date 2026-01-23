#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_HYPERSPACE_FURY) == EFFECT_HYPERSPACE_FURY);
    ASSUME(MoveHasAdditionalEffect(MOVE_HYPERSPACE_FURY, MOVE_EFFECT_FEINT));
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_HYPERSPACE_FURY, MOVE_EFFECT_DEF_MINUS_1));
    ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
}

SINGLE_BATTLE_TEST("Hyperspace Fury fails if used by a Pokémon other than Hoopa Unbound")
{
    u32 species;
    PARAMETRIZE { species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { species = SPECIES_HOOPA_CONFINED; }
    PARAMETRIZE { species = SPECIES_HOOPA_UNBOUND; }

    GIVEN {
        PLAYER(species);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HYPERSPACE_FURY); }
    } SCENE {
        switch (species)
        {
        case SPECIES_HOOPA_UNBOUND:
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player);
            break;
        case SPECIES_HOOPA_CONFINED:
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player);
            MESSAGE("But Hoopa can't use it the way it is now!");
            break;
        case SPECIES_WOBBUFFET:
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player);
            MESSAGE("But Wobbuffet can't use the move!");
            break;
        default:
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player);
            break;
        }
    }
}

SINGLE_BATTLE_TEST("Hyperspace Fury hits the target through Protect and breaks it")
{
    GIVEN {
        PLAYER(SPECIES_HOOPA_UNBOUND);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_HYPERSPACE_FURY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player); // TODO: Is this supposed to happen after the message?
        MESSAGE("It broke through the opposing Wobbuffet's protection!");
    } THEN {
        EXPECT_NE(opponent->hp, opponent->maxHP);
    }
}

SINGLE_BATTLE_TEST("Hyperspace Fury lowers the user's Defense by 1 stage after hitting the target")
{
    GIVEN {
        PLAYER(SPECIES_HOOPA_UNBOUND);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HYPERSPACE_FURY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Hyperspace Fury breaks Protection and lowers the user's Defense by 1 stage after use")
{
    GIVEN {
        PLAYER(SPECIES_HOOPA_UNBOUND);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_HYPERSPACE_FURY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player); // TODO: Is this supposed to happen after the message?
        MESSAGE("It broke through the opposing Wobbuffet's protection!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_NE(opponent->hp, opponent->maxHP);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}
