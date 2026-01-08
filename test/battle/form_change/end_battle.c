#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Xerneas returns its Neutral Form upon battle end")
{
    GIVEN {
        PLAYER(SPECIES_XERNEAS_NEUTRAL);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_XERNEAS_NEUTRAL);
    }
}

SINGLE_BATTLE_TEST("Zacian returns its Hero Form upon battle end")
{
    GIVEN {
        PLAYER(SPECIES_ZACIAN_HERO) { Item(ITEM_RUSTED_SWORD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_ZACIAN_HERO);
    }
}

SINGLE_BATTLE_TEST("Zacian returns its Hero Form upon battle end")
{
    GIVEN {
        ASSUME(GetMovePP(MOVE_BEHEMOTH_BLADE) == 5);
        PLAYER(SPECIES_ZACIAN_HERO) { Item(ITEM_RUSTED_SWORD); Moves(MOVE_IRON_HEAD, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        ASSUME(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES) == SPECIES_ZACIAN_HERO); // Assumes form change worked.
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_MOVE1), MOVE_IRON_HEAD);
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_PP1), 5); // Behemoth Blade's PP
    }
}

SINGLE_BATTLE_TEST("Zamazenta returns its Hero Form upon battle end")
{
    GIVEN {
        PLAYER(SPECIES_ZAMAZENTA_HERO) { Item(ITEM_RUSTED_SHIELD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_ZAMAZENTA_HERO);
    }
}

SINGLE_BATTLE_TEST("Zamazenta returns its Hero Form upon battle end")
{
    GIVEN {
        ASSUME(GetMovePP(MOVE_BEHEMOTH_BASH) == 5);
        PLAYER(SPECIES_ZAMAZENTA_HERO) { Item(ITEM_RUSTED_SHIELD); Moves(MOVE_IRON_HEAD, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        ASSUME(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES) == SPECIES_ZAMAZENTA_HERO); // Assumes form change worked.
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_MOVE1), MOVE_IRON_HEAD);
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_PP1), 5); // Behemoth Bash's PP
    }
}
