#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TELEKINESIS) == EFFECT_TELEKINESIS);
}

SINGLE_BATTLE_TEST("Telekinesis makes the target unable to avoid any attacks made against it")
{
    GIVEN {
        #if B_MINIMIZE_EVASION >= GEN_5
        ASSUME_STAT_CHANGE(MOVE_MINIMIZE, evasion: +2);
        #else
        ASSUME_STAT_CHANGE(MOVE_MINIMIZE, evasion: +1);
        #endif
        ASSUME(GetMoveAccuracy(MOVE_SCREECH) < 100);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TELEKINESIS); MOVE(opponent, MOVE_MINIMIZE); }
        TURN { MOVE(player, MOVE_SCREECH, hit:FALSE); }
    } SCENE {
        MESSAGE("Wobbuffet used Telekinesis!");
        MESSAGE("The opposing Wynaut was hurled into the air!");
        MESSAGE("The opposing Wynaut used Minimize!");
        MESSAGE("Wobbuffet used Screech!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, player);
        NOT MESSAGE("The opposing Wynaut avoided the attack!");
    }
}

SINGLE_BATTLE_TEST("Telekinesis ends after 3 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TELEKINESIS); }
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Wobbuffet used Telekinesis!");
        MESSAGE("The opposing Wynaut was hurled into the air!");
        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wynaut was freed from the telekinesis!");
    }
}

SINGLE_BATTLE_TEST("Telekinesis makes the target immune to Ground-type attacks")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_BULLDOZE) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLDOZE); }
        TURN { MOVE(player, MOVE_TELEKINESIS); }
        TURN { MOVE(player, MOVE_BULLDOZE); }
    } SCENE {
        MESSAGE("Wobbuffet used Bulldoze!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLDOZE, player);
        HP_BAR(opponent);
        MESSAGE("Wobbuffet used Telekinesis!");
        MESSAGE("The opposing Wynaut was hurled into the air!");
        MESSAGE("Wobbuffet used Bulldoze!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLDOZE, player);
            HP_BAR(opponent);
        }
        MESSAGE("It doesn't affect the opposing Wynaut…");
    }
}

SINGLE_BATTLE_TEST("Baton Pass passes Telekinesis's effect")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { species = SPECIES_DIGLETT; }
    PARAMETRIZE { species = SPECIES_DUGTRIO; }
    PARAMETRIZE { species = SPECIES_SANDYGAST; }
    PARAMETRIZE { species = SPECIES_PALOSSAND; }

    KNOWN_FAILING;
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EEVEE);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_TELEKINESIS); }
        TURN { MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
    } THEN {
        EXPECT(opponent->volatiles.telekinesis);
        EXPECT_GT((u32)opponent->volatiles.telekinesisTimer, 0);
    }
}

SINGLE_BATTLE_TEST("Baton Pass removes Telekinesis's effect if the recipient is Mega Gengar")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        ASSUME(IsTelekinesisBannedSpecies(SPECIES_GENGAR_MEGA));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EEVEE);
        OPPONENT(SPECIES_GENGAR_MEGA);
    } WHEN {
        TURN { MOVE(player, MOVE_TELEKINESIS); }
        TURN { MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
    } THEN {
        EXPECT(!opponent->volatiles.telekinesis);
        EXPECT_EQ((u32)opponent->volatiles.telekinesisTimer, 0);
    }
}
