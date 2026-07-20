#include "global.h"
#include "event_data.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "item.h"
#include "item_menu.h"
#include "constants/event_objects.h"
#include "constants/vars.h"
#include "test/test.h"

#define SPOT_FRAME_FURNISHED 7
#define SPOT_FRAME_BOOKSHELF 8
#define SPOT_FRAME_LAB       9

static bool32 PlaceStarterFurnishing(u16 spotId, u16 itemId)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(spotId);

    if (spot == NULL)
        return FALSE;
    AddBagItem(itemId, 1);
    return Habitat_SubmitItem(spot, HABITAT_ITEM_ACTION_PLACE, itemId, 1);
}

// Table-integrity guards: content is authored data; these catch the classic
// authoring mistakes (dup ids, unterminated condition lists, dead bindings)
// at test time instead of at runtime.

TEST("Habitat spots: table ids are unique and species are real")
{
    u32 i, j;
    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
    {
        EXPECT(gHabitatSpots[i].species != SPECIES_NONE || gHabitatSpots[i].speciesChoices != NULL);
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

TEST("Habitat starter: each first furnishing resolves its authored species")
{
    static const struct
    {
        u16 itemId;
        u16 species;
    } sChoices[] = {
        { ITEM_HH_CAMPFIRE, SPECIES_TORCHIC },
        { ITEM_HH_POTTED_PLANT, SPECIES_TREECKO },
        { ITEM_HH_WATER_BASIN, SPECIES_MUDKIP },
    };
    const struct HabitatSpot *furnished = Habitat_GetSpot(SPOT_FRAME_FURNISHED);
    const struct HabitatSpot *bare = Habitat_GetSpot(SPOT_FRAME_BOOKSHELF);
    u32 i;

    ASSUME(furnished != NULL);
    ASSUME(bare != NULL);
    for (i = 0; i < ARRAY_COUNT(sChoices); i++)
    {
        memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
        EXPECT(Habitat_IsSpeciesChoiceAvailable(furnished, sChoices[i].itemId));
        EXPECT(PlaceStarterFurnishing(SPOT_FRAME_FURNISHED, sChoices[i].itemId));
        EXPECT_EQ(Habitat_GetResolvedSpotSpecies(furnished), sChoices[i].species);
        EXPECT_EQ(Habitat_GetSpotState(SPOT_FRAME_FURNISHED), HABITAT_STATE_BEFRIENDED);
        EXPECT_EQ(Habitat_GetResidentSpecies(0), sChoices[i].species);
        EXPECT(!Habitat_IsSpeciesChoiceAvailable(bare, sChoices[i].itemId));
    }
}

TEST("Habitat starter: duplicate choices are blocked and the other starters recover")
{
    const struct HabitatSpot *furnished = Habitat_GetSpot(SPOT_FRAME_FURNISHED);
    const struct HabitatSpot *bookshelf = Habitat_GetSpot(SPOT_FRAME_BOOKSHELF);
    const struct HabitatSpot *lab = Habitat_GetSpot(SPOT_FRAME_LAB);

    ASSUME(furnished != NULL);
    ASSUME(bookshelf != NULL);
    ASSUME(lab != NULL);
    EXPECT(PlaceStarterFurnishing(SPOT_FRAME_FURNISHED, ITEM_HH_POTTED_PLANT));
    EXPECT(!Habitat_IsSpeciesChoiceAvailable(bookshelf, ITEM_HH_POTTED_PLANT));
    AddBagItem(ITEM_HH_POTTED_PLANT, 1);
    EXPECT(!Habitat_SubmitItem(bookshelf, HABITAT_ITEM_ACTION_PLACE, ITEM_HH_POTTED_PLANT, 1));
    EXPECT(CheckBagHasItem(ITEM_HH_POTTED_PLANT, 1));

    EXPECT(PlaceStarterFurnishing(SPOT_FRAME_BOOKSHELF, ITEM_HH_BOOKSHELF));
    EXPECT(PlaceStarterFurnishing(SPOT_FRAME_BOOKSHELF, ITEM_HH_CAMPFIRE));
    EXPECT_EQ(Habitat_GetResolvedSpotSpecies(bookshelf), SPECIES_TORCHIC);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_FRAME_BOOKSHELF), HABITAT_STATE_BEFRIENDED);

    EXPECT(PlaceStarterFurnishing(SPOT_FRAME_LAB, ITEM_HH_LAB_PC));
    EXPECT(PlaceStarterFurnishing(SPOT_FRAME_LAB, ITEM_HH_POKEBALL_HOLDER));
    EXPECT(PlaceStarterFurnishing(SPOT_FRAME_LAB, ITEM_HH_WATER_BASIN));
    EXPECT_EQ(Habitat_GetResolvedSpotSpecies(lab), SPECIES_MUDKIP);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_FRAME_LAB), HABITAT_STATE_BEFRIENDED);
    EXPECT_EQ(Habitat_ResidentCount(), 3);
    EXPECT_EQ(Habitat_GetResidentSpecies(0), SPECIES_TREECKO);
    EXPECT_EQ(Habitat_GetResidentSpecies(1), SPECIES_TORCHIC);
    EXPECT_EQ(Habitat_GetResidentSpecies(2), SPECIES_MUDKIP);
}

TEST("Habitat starter: the chosen furnishing survives save load and map reload")
{
    struct HabitatSave saved;
    const struct HabitatSpot *furnished = Habitat_GetSpot(SPOT_FRAME_FURNISHED);

    ASSUME(furnished != NULL);
    EXPECT(PlaceStarterFurnishing(SPOT_FRAME_FURNISHED, ITEM_HH_WATER_BASIN));
    memcpy(&saved, &gSaveBlock3Ptr->habitat, sizeof(saved));
    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    memcpy(&gSaveBlock3Ptr->habitat, &saved, sizeof(saved));

    gSaveBlock1Ptr->location.mapGroup = furnished->mapGroup;
    gSaveBlock1Ptr->location.mapNum = furnished->mapNum;
    Habitat_RecomputeCurrentMapSpots();
    Habitat_PrepareLabFrames();
    EXPECT_EQ(Habitat_GetResolvedSpotSpecies(furnished), SPECIES_MUDKIP);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_FRAME_FURNISHED), HABITAT_STATE_BEFRIENDED);
    EXPECT_EQ(Habitat_GetResidentSpecies(0), SPECIES_MUDKIP);
    EXPECT_EQ(VarGet(VAR_OBJ_GFX_ID_7), OBJ_EVENT_MON + SPECIES_MUDKIP);
    EXPECT_EQ(VarGet(VAR_OBJ_GFX_ID_8), OBJ_EVENT_GFX_ITEM_BALL);
}
