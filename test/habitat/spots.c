#include "global.h"
#include "habitat/spots.h"
#include "test/test.h"

// Table-integrity guards: content is authored data; these catch the classic
// authoring mistakes (dup ids, unterminated condition lists, dead bindings)
// at test time instead of at runtime.

TEST("Habitat spots: table ids are unique and species are real")
{
    u32 i, j;
    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
    {
        EXPECT(gHabitatSpots[i].species != SPECIES_NONE);
        EXPECT(gHabitatSpots[i].tier >= 1 && gHabitatSpots[i].tier <= 4);
        EXPECT(gHabitatSpots[i].hideFlag != 0);
        EXPECT(Habitat_GetZone(gHabitatSpots[i].zoneId) != NULL);
        for (j = i + 1; gHabitatSpots[j].spotId != 0xFFFF; j++)
            EXPECT(gHabitatSpots[i].spotId != gHabitatSpots[j].spotId);
    }
    EXPECT(i >= 6);  // the six slice spots exist (§7 recast)
}

TEST("Habitat spots: per-map spot density respects the object budget law")
{
    // §3 map budget law: NPCs + spots <= ~13 per map. The NPC half is an
    // authoring checklist; the spot half is checkable here.
    u32 i, j;
    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
    {
        u32 n = 0;
        for (j = 0; gHabitatSpots[j].spotId != 0xFFFF; j++)
        {
            if (gHabitatSpots[j].mapGroup == gHabitatSpots[i].mapGroup
             && gHabitatSpots[j].mapNum == gHabitatSpots[i].mapNum)
                n++;
        }
        EXPECT(n <= 13);
    }
}

TEST("Habitat spots: condition lists terminate within the mask width")
{
    u32 i, n;
    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
    {
        for (n = 0; gHabitatSpots[i].appearConditions[n].type != COND_NONE; n++)
            EXPECT(n < HABITAT_MAX_CONDITIONS);
        for (n = 0; gHabitatSpots[i].befriendConditions[n].type != COND_NONE; n++)
            EXPECT(n < HABITAT_MAX_CONDITIONS);
        EXPECT(gHabitatSpots[i].hintDormant != NULL);
        EXPECT(gHabitatSpots[i].hintStirring != NULL);
        EXPECT(gHabitatSpots[i].hintActive != NULL);
    }
}

TEST("Habitat spots: lookups round-trip")
{
    const struct HabitatSpot *spot = Habitat_GetSpot(1);
    ASSUME(spot != NULL);
    EXPECT_EQ(spot->species, SPECIES_SKITTY);
    EXPECT(Habitat_GetSpotByObject(spot->mapGroup, spot->mapNum, spot->localId) == spot);
    EXPECT(Habitat_GetSpot(0x7777) == NULL);
    EXPECT(Habitat_GetSpotByObject(0xFE, 0xFE, 0xFE) == NULL);
}
