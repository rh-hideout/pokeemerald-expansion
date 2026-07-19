#include "global.h"
#include "event_data.h"
#include "field_weather.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "item.h"
#include "item_menu.h"
#include "pokedex.h"
#include "string_util.h"
#include "constants/berry.h"
#include "constants/weather.h"
#include "test/overworld_script.h"
#include "test/test.h"

// Slice spot ids (spot_data.c).
#define SPOT_SKITTY 1
#define SPOT_LOTAD  2
#define SPOT_MACHOP 3

TEST("Habitat manager: empty appear list goes straight to ACTIVE and shows the sprite")
{
    const struct HabitatSpot *machop = Habitat_GetSpot(SPOT_MACHOP);
    ASSUME(machop != NULL);

    Habitat_RecomputeSpot(machop);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_MACHOP), HABITAT_STATE_ACTIVE);
    EXPECT(!FlagGet(machop->hideFlag));  // visible
}

TEST("Habitat manager: offer-less befriend completes on recompute after battle win")
{
    const struct HabitatSpot *machop = Habitat_GetSpot(SPOT_MACHOP);
    ASSUME(machop != NULL);

    Habitat_RecomputeSpot(machop);
    ASSUME(Habitat_GetSpotState(SPOT_MACHOP) == HABITAT_STATE_ACTIVE);
    EXPECT(!GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_MACHOP), FLAG_GET_CAUGHT));

    Habitat_AddSpotLocalFlags(SPOT_MACHOP, HABITAT_SPOT_LOCAL_BATTLE_WON);
    Habitat_RecomputeSpot(machop);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_MACHOP), HABITAT_STATE_BEFRIENDED);
    EXPECT(GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_MACHOP), FLAG_GET_CAUGHT));
    EXPECT(!FlagGet(machop->hideFlag));  // home-by-default: it stays (§3)
}

TEST("Habitat manager: offer-driven spots do not auto-befriend")
{
    const struct HabitatSpot *skitty = Habitat_GetSpot(SPOT_SKITTY);
    ASSUME(skitty != NULL);

    Habitat_RecomputeSpot(skitty);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_SKITTY), HABITAT_STATE_DORMANT);
    EXPECT(FlagGet(skitty->hideFlag));  // hidden while dormant

    Habitat_AddPlacedCount(SPOT_SKITTY, 1);   // the doll is set down
    Habitat_RecomputeSpot(skitty);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_SKITTY), HABITAT_STATE_ACTIVE);
    EXPECT(!FlagGet(skitty->hideFlag));

    Habitat_RecomputeSpot(skitty);            // ITEM_OFFERED can't pass with no offer
    EXPECT_EQ(Habitat_GetSpotState(SPOT_SKITTY), HABITAT_STATE_ACTIVE);
}

TEST("Habitat manager: befriended spots render at home (home-by-default)")
{
    const struct HabitatSpot *skitty = Habitat_GetSpot(SPOT_SKITTY);
    ASSUME(skitty != NULL);

    Habitat_AddPlacedCount(SPOT_SKITTY, 1);
    Habitat_RecomputeSpot(skitty);
    ASSUME(Habitat_GetSpotState(SPOT_SKITTY) == HABITAT_STATE_ACTIVE);

    Habitat_CompleteBefriendById(SPOT_SKITTY);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_SKITTY), HABITAT_STATE_BEFRIENDED);
    EXPECT(GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_SKITTY), FLAG_GET_CAUGHT));
    EXPECT(!FlagGet(skitty->hideFlag));  // home-by-default: sprite remains
}

TEST("Habitat manager: partial appear conditions stir the spot")
{
    const struct HabitatSpot *lotad = Habitat_GetSpot(SPOT_LOTAD);
    ASSUME(lotad != NULL);

    SetCurrentAndNextWeather(WEATHER_RAIN);      // 1 of 3 appear conditions
    Habitat_RecomputeSpot(lotad);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_LOTAD), HABITAT_STATE_STIRRING);
    EXPECT(FlagGet(lotad->hideFlag));            // stirring is still hidden

    // §7 recast: resident Treecko (dex-backed) + mature zone-1 Cheri.
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_TREECKO), FLAG_SET_CAUGHT);
    gSaveBlock1Ptr->berryTrees[5].berry = ItemIdToBerryType(ITEM_CHERI_BERRY);
    gSaveBlock1Ptr->berryTrees[5].stage = BERRY_STAGE_BERRIES;
    Habitat_RecomputeSpot(lotad);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_LOTAD), HABITAT_STATE_ACTIVE);
    EXPECT(!FlagGet(lotad->hideFlag));
}

TEST("Habitat manager: current-map recompute only touches this map's spots")
{
    const struct HabitatSpot *machop = Habitat_GetSpot(SPOT_MACHOP);
    ASSUME(machop != NULL);

    gSaveBlock1Ptr->location.mapGroup = machop->mapGroup;
    gSaveBlock1Ptr->location.mapNum = machop->mapNum;
    Habitat_RecomputeCurrentMapSpots();
    EXPECT_EQ(Habitat_GetSpotState(SPOT_MACHOP), HABITAT_STATE_ACTIVE);

    // From a different map, a fresh Machop-alike would stay dormant; emulate
    // by resetting save state and recomputing from elsewhere.
    memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));
    gSaveBlock1Ptr->location.mapGroup = machop->mapGroup + 1;
    Habitat_RecomputeCurrentMapSpots();
    EXPECT_EQ(Habitat_GetSpotState(SPOT_MACHOP), HABITAT_STATE_DORMANT);
}

TEST("Habitat interaction: inspect buffers the staged hint and returns state")
{
    const struct HabitatSpot *machop = Habitat_GetSpot(SPOT_MACHOP);
    ASSUME(machop != NULL);

    gSaveBlock1Ptr->location.mapGroup = machop->mapGroup;
    gSaveBlock1Ptr->location.mapNum = machop->mapNum;
    gSpecialVar_LastTalked = machop->localId;

    // Dormant: nothing recomputed yet. gStringVar4 must arrive fully
    // expanded (display re-expands it in place; see spot_interaction.c).
    u8 expected[256];
    Habitat_OnInspectSpot();
    EXPECT_EQ(gSpecialVar_Result, HABITAT_STATE_DORMANT);
    StringExpandPlaceholders(expected, machop->hintDormant);
    EXPECT(StringCompare(gStringVar4, expected) == 0);

    Habitat_RecomputeSpot(machop);
    Habitat_OnInspectSpot();
    EXPECT_EQ(gSpecialVar_Result, HABITAT_STATE_ACTIVE);
    StringExpandPlaceholders(expected, machop->hintActive);
    EXPECT(StringCompare(gStringVar4, expected) == 0);

    // Unbound object id resolves to the not-a-spot sentinel.
    gSpecialVar_LastTalked = 99;
    Habitat_OnInspectSpot();
    EXPECT_EQ(gSpecialVar_Result, HABITAT_INSPECT_NOT_A_SPOT);
}

TEST("Habitat verbs: PLACE moves the wanted item from bag to spot and manifests it")
{
    const struct HabitatSpot *skitty = Habitat_GetSpot(SPOT_SKITTY);
    ASSUME(skitty != NULL);
    gSaveBlock1Ptr->location.mapGroup = skitty->mapGroup;
    gSaveBlock1Ptr->location.mapNum = skitty->mapNum;
    gSpecialVar_LastTalked = skitty->localId;
    Habitat_OnInspectSpot();  // binds the interaction spot

    EXPECT(Habitat_TryPlaceItem() == FALSE);  // nothing in the bag

    AddBagItem(ITEM_POKE_DOLL, 1);
    EXPECT(Habitat_TryPlaceItem() == TRUE);
    EXPECT(!CheckBagHasItem(ITEM_POKE_DOLL, 1));       // consumed
    EXPECT_EQ(Habitat_GetPlacedCount(SPOT_SKITTY), 1);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_SKITTY), HABITAT_STATE_ACTIVE);  // recompute fired

    EXPECT(Habitat_TryPlaceItem() == FALSE);  // doll is gone
}

TEST("Habitat verbs: OFFER consumes the right item and befriends; wrong item is kept")
{
    const struct HabitatSpot *skitty = Habitat_GetSpot(SPOT_SKITTY);
    ASSUME(skitty != NULL);
    gSaveBlock1Ptr->location.mapGroup = skitty->mapGroup;
    gSaveBlock1Ptr->location.mapNum = skitty->mapNum;
    gSpecialVar_LastTalked = skitty->localId;

    AddBagItem(ITEM_POKE_DOLL, 1);
    AddBagItem(ITEM_PERSIM_BERRY, 1);
    AddBagItem(ITEM_PECHA_BERRY, 1);
    Habitat_OnInspectSpot();
    ASSUME(Habitat_TryPlaceItem() == TRUE);            // Skitty is now ACTIVE

    gSpecialVar_ItemId = ITEM_PECHA_BERRY;             // wrong offering
    EXPECT(Habitat_TryOffer() == FALSE);
    EXPECT(CheckBagHasItem(ITEM_PECHA_BERRY, 1));      // kept
    EXPECT_EQ(Habitat_GetSpotState(SPOT_SKITTY), HABITAT_STATE_ACTIVE);

    gSpecialVar_ItemId = ITEM_PERSIM_BERRY;            // Normal type-want (§4)
    EXPECT(Habitat_TryOffer() == TRUE);
    EXPECT(!CheckBagHasItem(ITEM_PERSIM_BERRY, 1));    // consumed
    EXPECT_EQ(Habitat_GetSpotState(SPOT_SKITTY), HABITAT_STATE_BEFRIENDED);
    EXPECT(GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_SKITTY), FLAG_GET_CAUGHT));

    gSpecialVar_ItemId = ITEM_ORAN_BERRY;              // already befriended
    EXPECT(Habitat_TryOffer() == FALSE);
}
