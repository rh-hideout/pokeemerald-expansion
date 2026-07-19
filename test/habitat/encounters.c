#include "global.h"
#include "event_data.h"
#include "wild_encounter.h"
#include "constants/metatile_behaviors.h"
#include "test/test.h"

// Spec §2 law: "No wild battles exist anywhere else." Every wild-roll entry
// point must be dead at the top of the function (before any map access —
// these run with no overworld loaded, so reaching map state would crash).

TEST("Habitat law: wild encounter entry points are dead")
{
    EXPECT(StandardWildEncounter(MB_TALL_GRASS, MB_TALL_GRASS) == FALSE);
    EXPECT(SweetScentWildEncounter() == FALSE);
    EXPECT(DoesCurrentMapHaveFishingMons() == FALSE);  // rods: "not even a nibble"

    gSpecialVar_Result = TRUE;
    RockSmashWildEncounter();
    EXPECT(gSpecialVar_Result == FALSE);  // script contract: FALSE ends the smash
}
