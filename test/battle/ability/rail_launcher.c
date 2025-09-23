#include "global.h"
#include "test/battle.h"



SINGLE_BATTLE_TEST("Rail Launcher doubles power of beam moves", s16 damage)
{

    u32 move;
    u16 ability;
    PARAMETRIZE { move = MOVE_ICE_BEAM; ability = ABILITY_RAIL_LAUNCHER; }
    PARAMETRIZE { move = MOVE_ICE_BEAM; ability = ABILITY_STEADFAST; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_RAIL_LAUNCHER; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_STEADFAST; }

    GIVEN {
        PLAYER(SPECIES_VIKAVOLT) {  Ability(ability);}
        OPPONENT(SPECIES_WOBBUFFET) ;
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage); // Rail Launcher affects beam moves
        EXPECT_EQ(results[2].damage, results[3].damage); // Rail Launcher does not affect non-beam moves
    }
}


