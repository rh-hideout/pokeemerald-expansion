#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Wish heals")
{
	GIVEN {
		PLAYER(SPECIES_TOGETIC);
		OPPONENT(SPECIES_LUNATONE);
	} WHEN {
		TURN { MOVE(player, MOVE_WISH); MOVE(opponent, MOVE_TACKLE); }
		TURN { MOVE(player, MOVE_SPLASH); MOVE(opponent, MOVE_TACKLE); }
	} SCENE {
		HP_BAR(player);
	}
}

SINGLE_BATTLE_TEST("Wish is blocked by Heal Block")
{
	GIVEN {
		PLAYER(SPECIES_TOGETIC);
		OPPONENT(SPECIES_LUNATONE);
	} WHEN {
		TURN { MOVE(player, MOVE_WISH); MOVE(opponent, MOVE_TACKLE); }
		TURN { MOVE(player, MOVE_SPLASH); MOVE(opponent, MOVE_HEAL_BLOCK); }
	} SCENE {
		MESSAGE("Togetic was prevented from healing!");
		NOT HP_BAR(player);
	}
}	
