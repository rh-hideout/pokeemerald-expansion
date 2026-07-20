#include "global.h"
#include "event_data.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "item.h"
#include "pokemon.h"
#include "rtc.h"
#include "string_util.h"
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

TEST("Habitat Grove: type-berry table follows the Sleep mapping")
{
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_TORCHIC), ITEM_LEPPA_BERRY);   // Fire
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_TREECKO), ITEM_DURIN_BERRY);   // Grass
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_MUDKIP), ITEM_ORAN_BERRY);     // Water
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_SKITTY), ITEM_PERSIM_BERRY);   // Normal
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_LOTAD), ITEM_ORAN_BERRY);      // Water/Grass dual -> primary
    EXPECT_EQ(Habitat_BerryForSpecies(SPECIES_HERACROSS), ITEM_LUM_BERRY);   // Bug/Fighting -> primary
}

TEST("Habitat Grove: assignment honors slots and the six-out cap")
{
    u32 i;
    InitPlotsForTest();
    // Dynamic starter frames have no production default. This fixture chooses
    // the campfire explicitly before using frame 7 as a Torchic resident.
    Habitat_SetPlacedCount(3, 1);
    for (i = 0; i < 8; i++)
        gSaveBlock3Ptr->habitat.residents[i].originSpotId = 7;

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

TEST("Habitat Grove: tended plots grow by hours and harvest yields the crop")
{
    InitPlotsForTest();
    Habitat_SetPlacedCount(3, 1);
    ASSUME(Habitat_TryAddResident(7) == 0);
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

TEST("Habitat Grove: RTC reconcile credits offline hours exactly once")
{
    InitPlotsForTest();
    Habitat_SetPlacedCount(3, 1);
    ASSUME(Habitat_TryAddResident(7) == 0);
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

TEST("Habitat Grove: out residents leave their home spot invisible")
{
    const struct HabitatSpot *skitty = Habitat_GetSpot(1);
    ASSUME(skitty != NULL);
    InitPlotsForTest();

    Habitat_AddPlacedCount(1, 0, 1);
    Habitat_RecomputeSpot(skitty);
    Habitat_CompleteBefriendById(1);
    EXPECT(!FlagGet(skitty->hideFlag));  // home by default

    s32 idx = Habitat_FindResidentBySpot(1);
    ASSUME(idx >= 0);
    ASSUME(Habitat_AssignResidentToPlot(idx, 0));
    Habitat_SyncSpotObjectFlag(skitty);
    EXPECT(FlagGet(skitty->hideFlag));   // out at the Grove

    Habitat_SendResidentHome(idx);
    Habitat_SyncSpotObjectFlag(skitty);
    EXPECT(!FlagGet(skitty->hideFlag));  // came home
}

TEST("Habitat Grove: recruit flow assigns from the home spot dialogue")
{
    const struct HabitatSpot *skitty = Habitat_GetSpot(1);
    ASSUME(skitty != NULL);
    InitPlotsForTest();

    gSaveBlock1Ptr->location.mapGroup = skitty->mapGroup;
    gSaveBlock1Ptr->location.mapNum = skitty->mapNum;
    gSpecialVar_LastTalked = skitty->localId;

    Habitat_AddPlacedCount(1, 0, 1);
    Habitat_RecomputeSpot(skitty);
    Habitat_CompleteBefriendById(1);
    Habitat_OnInspectSpot();  // binds the interaction spot

    // Split flow: dialogue pre-checks, mutation runs after script release.
    EXPECT_EQ(Habitat_CanRecruitToGrove(), 1);
    Habitat_TryRecruitToGrove();
    EXPECT_EQ(Habitat_GetPlot(0)->berryItem, ITEM_PERSIM_BERRY);  // Normal-type crop
    EXPECT(Habitat_ResidentIsOut(Habitat_FindResidentBySpot(1)));

    EXPECT_EQ(Habitat_CanRecruitToGrove(), 0);  // already out
    Habitat_TryRecruitToGrove();                // guarded no-op when out
    EXPECT_EQ(Habitat_GetPlot(0)->worker2, 0xFF);  // no double assignment
}

TEST("Habitat Grove: worker talk resolves display slots to residents")
{
    u32 i;
    InitPlotsForTest();
    Habitat_SetPlacedCount(3, 1);
    for (i = 0; i < 3; i++)
        ASSUME(Habitat_TryAddResident(7 + i) == (s32) i);
    ASSUME(Habitat_AssignResidentToPlot(0, 0));  // Torchic -> slot 0
    ASSUME(Habitat_AssignResidentToPlot(2, 1));  // idx2 -> slot 1 (idx1 stays home)

    gSelectedObjectEvent = 0;
    gObjectEvents[0].trainerRange_berryTreeId = 1;  // display slot 1
    EXPECT(Habitat_OnTalkWorker() == TRUE);
    EXPECT(StringCompare(gStringVar1,
                         GetSpeciesName(Habitat_GetResolvedSpotSpecies(Habitat_GetSpot(9)))) == 0);

    Habitat_SendTalkedWorkerHome();
    EXPECT(!Habitat_ResidentIsOut(2));
    EXPECT(Habitat_ResidentIsOut(0));  // slot mapping recomputes; Torchic unaffected
}
