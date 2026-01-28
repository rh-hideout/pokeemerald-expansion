#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveTarget(MOVE_BREAKING_SWIPE) == MOVE_TARGET_BOTH);
    ASSUME(MoveMakesContact(MOVE_BREAKING_SWIPE));
}

DOUBLE_BATTLE_TEST("Pickpocket activates on a contact spread move even if the other target is immune")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_CLEFAIRY, 0) == TYPE_FAIRY
            || GetSpeciesType(SPECIES_CLEFAIRY, 1) == TYPE_FAIRY);
        ASSUME(GetMoveType(MOVE_BREAKING_SWIPE) == TYPE_DRAGON);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MAGOST_BERRY); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
        OPPONENT(SPECIES_CLEFAIRY);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BREAKING_SWIPE); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Magost Berry!");
    } THEN {
        EXPECT(opponentLeft->item == ITEM_MAGOST_BERRY);
        EXPECT(playerLeft->item == ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Pickpocket activates for the fastest itemless target when both are hit by a contact spread move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); Item(ITEM_MAGOST_BERRY); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        OPPONENT(SPECIES_SNEASEL) { Speed(40); Ability(ABILITY_PICKPOCKET); }
        OPPONENT(SPECIES_SNEASEL) { Speed(30); Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BREAKING_SWIPE); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Magost Berry!");
    } THEN {
        EXPECT(opponentLeft->item == ITEM_MAGOST_BERRY);
        EXPECT(opponentRight->item == ITEM_NONE);
        EXPECT(playerLeft->item == ITEM_NONE);
    }
}
