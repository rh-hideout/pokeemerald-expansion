#include "global.h"
#include "event_data.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "item.h"
#include "rtc.h"
#include "constants/items.h"
#include "test/test.h"

static void InitPlotsForTest(void)
{
    u32 i;
    for (i = 0; i < HABITAT_PLOT_COUNT; i++)
    {
        gSaveBlock3Ptr->habitat.plots[i].worker1 = 0xFF;
        gSaveBlock3Ptr->habitat.plots[i].worker2 = 0xFF;
    }
}

TEST("Grove: type-berry table follows the Sleep mapping")
{
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_TORCHIC), ITEM_LEPPA_BERRY);   // Fire
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_TREECKO), ITEM_DURIN_BERRY);   // Grass
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_MUDKIP), ITEM_ORAN_BERRY);     // Water
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_SKITTY), ITEM_PERSIM_BERRY);   // Normal
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_LOTAD), ITEM_ORAN_BERRY);      // Water/Grass dual -> primary
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_HERACROSS), ITEM_LUM_BERRY);   // Bug/Fighting -> primary
}

TEST("Grove: assignment honors slots and the six-out cap")
{
    u32 i;
    InitPlotsForTest();
    for (i = 0; i < 8; i++)
        ASSUME(Habitat_TryAddResident(SPECIES_TORCHIC) == (s32) i);

    EXPECT(Habitat_AssignResidentToPlot(0, 0));
    EXPECT(Habitat_ResidentIsOut(0));
    EXPECT_EQ(Habitat_OutCount(), 1);
    EXPECT_EQ(Habitat_GetPlot(0)->berryItem, ITEM_LEPPA_BERRY);  // first worker sets crop
    EXPECT(!Habitat_AssignResidentToPlot(0, 1));   // already out

    EXPECT(Habitat_AssignResidentToPlot(1, 0));    // second slot ok
    EXPECT(!Habitat_AssignResidentToPlot(2, 0));   // plot full

    EXPECT(Habitat_AssignResidentToPlot(2, 1));
    EXPECT(Habitat_AssignResidentToPlot(3, 1));
    EXPECT(Habitat_AssignResidentToPlot(4, 2));
    EXPECT(Habitat_AssignResidentToPlot(5, 2));
    EXPECT_EQ(Habitat_OutCount(), 6);
    EXPECT(!Habitat_AssignResidentToPlot(6, 3));   // §3 six-out cap
    Habitat_SendResidentHome(5);
    EXPECT_EQ(Habitat_OutCount(), 5);
    EXPECT(Habitat_AssignResidentToPlot(6, 3));    // freed
}

TEST("Grove: tended plots grow by hours and harvest yields the crop")
{
    InitPlotsForTest();
    ASSUME(Habitat_TryAddResident(SPECIES_TORCHIC) == 0);
    ASSUME(Habitat_AssignResidentToPlot(0, 0));

    Habitat_TickPlots(HABITAT_PLOT_HOURS_PER_STAGE - 1);
    EXPECT_EQ(Habitat_GetPlot(0)->growthStage, 0);
    Habitat_TickPlots(1);
    EXPECT_EQ(Habitat_GetPlot(0)->growthStage, 1);
    EXPECT_EQ(Habitat_HarvestPlot(0), 0);  // not mature

    Habitat_TickPlots(HABITAT_PLOT_HOURS_PER_STAGE * HABITAT_PLOT_STAGE_MATURE);
    EXPECT_EQ(Habitat_GetPlot(0)->growthStage, HABITAT_PLOT_STAGE_MATURE);

    EXPECT(!CheckBagHasItem(ITEM_LEPPA_BERRY, 1));
    EXPECT_EQ(Habitat_HarvestPlot(0), HABITAT_PLOT_YIELD);
    EXPECT(CheckBagHasItem(ITEM_LEPPA_BERRY, HABITAT_PLOT_YIELD));
    EXPECT_EQ(Habitat_GetPlot(0)->growthStage, 0);

    // Untended plots never grow.
    Habitat_SendResidentHome(0);
    Habitat_TickPlots(100);
    EXPECT_EQ(Habitat_GetPlot(0)->growthStage, 0);
}

TEST("Grove: RTC reconcile credits offline hours exactly once")
{
    InitPlotsForTest();
    ASSUME(Habitat_TryAddResident(SPECIES_TORCHIC) == 0);
    ASSUME(Habitat_AssignResidentToPlot(0, 0));

    RtcInitLocalTimeOffset(1, 0);
    Habitat_ReconcileGrowthFromRtc();   // anchor the stamp
    u16 anchored = Habitat_GetPlot(0)->hoursProgress;

    RtcInitLocalTimeOffset(9, 30);      // +8.5h later
    Habitat_ReconcileGrowthFromRtc();
    EXPECT_EQ(Habitat_GetPlot(0)->hoursProgress, anchored + 8);
    Habitat_ReconcileGrowthFromRtc();   // same half-hour: no double credit
    EXPECT_EQ(Habitat_GetPlot(0)->hoursProgress, anchored + 8);
}

TEST("Grove: out residents leave their home spot invisible")
{
    const struct HabitatSpot *skitty = Habitat_GetSpot(1);
    ASSUME(skitty != NULL);
    InitPlotsForTest();

    Habitat_AddPlacedCount(1, 1);
    Habitat_RecomputeSpot(skitty);
    Habitat_CompleteBefriendById(1);
    EXPECT(!FlagGet(skitty->hideFlag));  // home by default

    s32 idx = Habitat_FindResidentBySpecies(SPECIES_SKITTY);
    ASSUME(idx >= 0);
    ASSUME(Habitat_AssignResidentToPlot(idx, 0));
    Habitat_SyncSpotObjectFlag(skitty);
    EXPECT(FlagGet(skitty->hideFlag));   // out at the Grove

    Habitat_SendResidentHome(idx);
    Habitat_SyncSpotObjectFlag(skitty);
    EXPECT(!FlagGet(skitty->hideFlag));  // came home
}
