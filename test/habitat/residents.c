#include "global.h"
#include "event_data.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "item.h"
#include "item_menu.h"
#include "pokedex.h"
#include "rtc.h"
#include "constants/berry.h"
#include "test/test.h"

#define SPOT_SKITTY 1
#define SPOT_MACHOP 3
#define SPOT_HERACROSS 5

TEST("Habitat residents: befriending registers an individual")
{
    EXPECT_EQ(Habitat_ResidentCount(), 0);
    Habitat_SetSpotState(SPOT_MACHOP, HABITAT_STATE_ACTIVE);
    Habitat_CompleteBefriendById(SPOT_MACHOP);
    EXPECT_EQ(Habitat_ResidentCount(), 1);
    ASSUME(Habitat_GetResident(0) != NULL);
    EXPECT_EQ(Habitat_GetResidentSpecies(Habitat_GetResident(0)), SPECIES_MACHOP);
    EXPECT_EQ(Habitat_GetResident(0)->assignment, 0);
    EXPECT_EQ(Habitat_FindResidentBySpecies(SPECIES_MACHOP), 0);
    EXPECT_EQ(Habitat_FindResidentBySpecies(SPECIES_SKITTY), -1);
}

TEST("Habitat residents: the individual cap leaves conditions dex-backed")
{
    u32 i;
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
        ASSUME(Habitat_TryAddResident(SPECIES_ZIGZAGOON) == (s32) i);
    EXPECT_EQ(Habitat_ResidentCount(), HABITAT_RESIDENT_COUNT);

    // 97th befriend: no individual slot, but dex caught (== befriended) sets.
    Habitat_SetSpotState(SPOT_MACHOP, HABITAT_STATE_ACTIVE);
    Habitat_CompleteBefriendById(SPOT_MACHOP);
    EXPECT_EQ(Habitat_ResidentCount(), HABITAT_RESIDENT_COUNT);
    EXPECT(GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_MACHOP), FLAG_GET_CAUGHT));
}

TEST("Habitat residents: RESIDENT_SPECIES and RESIDENT_COUNT read the dex")
{
    static const struct HabitatCondition sPinsir[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_PINSIR, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sOneFighting[] = {
        HABITAT_COND(COND_RESIDENT_COUNT, TYPE_FIGHTING, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sOneWater[] = {
        HABITAT_COND(COND_RESIDENT_COUNT, TYPE_WATER, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sAnyTwo[] = {
        HABITAT_COND(COND_RESIDENT_COUNT, HABITAT_TYPE_ANY, 2, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    Habitat_EvaluateConditions(sPinsir, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    Habitat_SetSpotState(SPOT_MACHOP, HABITAT_STATE_ACTIVE);
    Habitat_CompleteBefriendById(SPOT_MACHOP);   // Fighting
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_PINSIR), FLAG_SET_CAUGHT);

    Habitat_EvaluateConditions(sPinsir, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sOneFighting, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sOneWater, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);
    Habitat_EvaluateConditions(sAnyTwo, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);  // Machop + Pinsir
}

TEST("Habitat residents: Heracross chain closes (resident Pinsir + night + sap tree)")
{
    const struct HabitatSpot *heracross = Habitat_GetSpot(SPOT_HERACROSS);
    ASSUME(heracross != NULL);

    RtcInitLocalTimeOffset(22, 0);
    gSaveBlock1Ptr->berryTrees[6].berry = ItemIdToBerryType(ITEM_LEPPA_BERRY);  // zone-1 tree
    gSaveBlock1Ptr->berryTrees[6].stage = BERRY_STAGE_BERRIES;

    Habitat_RecomputeSpot(heracross);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_HERACROSS), HABITAT_STATE_STIRRING);  // 2 of 3

    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_PINSIR), FLAG_SET_CAUGHT);
    Habitat_RecomputeSpot(heracross);
    EXPECT_EQ(Habitat_GetSpotState(SPOT_HERACROSS), HABITAT_STATE_ACTIVE);
}
