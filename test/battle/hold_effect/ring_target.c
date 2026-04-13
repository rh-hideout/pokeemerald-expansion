#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_RING_TARGET].holdEffect == HOLD_EFFECT_RING_TARGET);
}

SINGLE_BATTLE_TEST("Ring Target lets Ground-type moves hit ungrounded Flying-type holders")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 0) == TYPE_FLYING || GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Item(ITEM_RING_TARGET); }
    } WHEN {
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        HP_BAR(opponent);
        NOT MESSAGE("It doesn't affect the opposing Pidgey…");
    }
}

SINGLE_BATTLE_TEST("Ring Target lets Normal-type moves hit Ghost-type holders")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_GASTLY, 0) == TYPE_GHOST || GetSpeciesType(SPECIES_GASTLY, 1) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTLY) { Item(ITEM_RING_TARGET); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent);
        NOT MESSAGE("It doesn't affect the opposing Misdreavus…");
    }
}
