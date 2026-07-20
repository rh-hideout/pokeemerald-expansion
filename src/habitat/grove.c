// The Grove: plots, assignment, growth (spec §3/§4). Two rules run the
// economy: workers grow their type's berry, and a Pokémon's default want is
// its type's berry. Growth is event-driven only — TIME_TICK hours credit
// tended plots; map load reconciles offline time from an RTC-minute stamp.
#include "global.h"
#include "habitat/events.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "item.h"
#include "pokemon.h"
#include "rtc.h"
#include "constants/items.h"

#define WORKER_NONE 0xFF

// §4 type→berry table [CANON, Sleep mapping — verified 2026-07-19].
static const u16 sTypeBerryTable[NUMBER_OF_MON_TYPES] =
{
    [TYPE_NORMAL]   = ITEM_PERSIM_BERRY,
    [TYPE_FIRE]     = ITEM_LEPPA_BERRY,
    [TYPE_WATER]    = ITEM_ORAN_BERRY,
    [TYPE_GRASS]    = ITEM_DURIN_BERRY,
    [TYPE_ELECTRIC] = ITEM_GREPA_BERRY,
    [TYPE_ICE]      = ITEM_RAWST_BERRY,
    [TYPE_FIGHTING] = ITEM_CHERI_BERRY,
    [TYPE_POISON]   = ITEM_CHESTO_BERRY,
    [TYPE_GROUND]   = ITEM_FIGY_BERRY,
    [TYPE_FLYING]   = ITEM_PAMTRE_BERRY,
    [TYPE_PSYCHIC]  = ITEM_MAGO_BERRY,
    [TYPE_BUG]      = ITEM_LUM_BERRY,
    [TYPE_ROCK]     = ITEM_SITRUS_BERRY,
    [TYPE_GHOST]    = ITEM_BLUK_BERRY,
    [TYPE_DRAGON]   = ITEM_YACHE_BERRY,
    [TYPE_DARK]     = ITEM_WIKI_BERRY,
    [TYPE_STEEL]    = ITEM_BELUE_BERRY,
    [TYPE_FAIRY]    = ITEM_PECHA_BERRY,
};

u16 Habitat_BerryForSpecies(u16 species)
{
    // Duals default to the primary type (recast note, 2026-07-19).
    u32 type = gSpeciesInfo[species].types[0];
    if (type >= NUMBER_OF_MON_TYPES || sTypeBerryTable[type] == ITEM_NONE)
        return ITEM_ORAN_BERRY;  // safe fallback (Mystery/Stellar-class)
    return sTypeBerryTable[type];
}

bool32 Habitat_ResidentIsOut(u32 residentIdx)
{
    const struct HabitatResident *r = Habitat_GetResident(residentIdx);
    return r != NULL && r->assignment != 0;
}

u32 Habitat_OutCount(void)
{
    u32 i, n = 0;
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        if (Habitat_ResidentIsOut(i))
            n++;
    }
    return n;
}

struct HabitatPlot *Habitat_GetPlot(u32 plotIdx)
{
    if (plotIdx >= HABITAT_PLOT_COUNT)
        return NULL;
    return &gSaveBlock3Ptr->habitat.plots[plotIdx];
}

bool32 Habitat_AssignResidentToPlot(u32 residentIdx, u32 plotIdx)
{
    struct HabitatPlot *plot = Habitat_GetPlot(plotIdx);
    const struct HabitatResident *r = Habitat_GetResident(residentIdx);
    u8 *slot;

    if (plot == NULL || r == NULL)
        return FALSE;
    if (Habitat_ResidentIsOut(residentIdx))
        return FALSE;  // already working; send home first
    if (Habitat_OutCount() >= HABITAT_GROVE_OUT_CAP)
        return FALSE;  // §3 six-out rule
    if (plot->worker1 != WORKER_NONE && plot->worker2 != WORKER_NONE)
        return FALSE;  // plot full

    slot = (plot->worker1 == WORKER_NONE) ? &plot->worker1 : &plot->worker2;
    *slot = residentIdx;
    if (plot->worker1 != WORKER_NONE && plot->worker2 == WORKER_NONE)
        plot->berryItem = Habitat_BerryForSpecies(Habitat_GetResidentSpecies(residentIdx));  // first worker sets the crop
    gSaveBlock3Ptr->habitat.residents[residentIdx].assignment = plotIdx + 1;
    Habitat_NotifyDependency(HABITAT_DEP_GROVE);
    return TRUE;
}

void Habitat_SendResidentHome(u32 residentIdx)
{
    struct HabitatResident *r;
    u32 plotIdx;
    struct HabitatPlot *plot;

    if (residentIdx >= HABITAT_RESIDENT_COUNT)
        return;
    r = &gSaveBlock3Ptr->habitat.residents[residentIdx];
    if (r->assignment == 0)
        return;
    plotIdx = r->assignment - 1;
    plot = Habitat_GetPlot(plotIdx);
    if (plot != NULL)
    {
        if (plot->worker1 == residentIdx)
            plot->worker1 = WORKER_NONE;
        if (plot->worker2 == residentIdx)
            plot->worker2 = WORKER_NONE;
        if (plot->worker1 == WORKER_NONE && plot->worker2 == WORKER_NONE)
        {
            // Untended plots rest: crop stays visible in data but stops
            // growing (no worker => no credit in Habitat_TickPlots).
        }
    }
    r->assignment = 0;
    Habitat_NotifyDependency(HABITAT_DEP_GROVE);
}

void Habitat_TickPlots(u32 hours)
{
    u32 i;
    for (i = 0; i < HABITAT_PLOT_COUNT; i++)
    {
        struct HabitatPlot *plot = &gSaveBlock3Ptr->habitat.plots[i];
        u32 progress;
        if (plot->worker1 == WORKER_NONE && plot->worker2 == WORKER_NONE)
            continue;
        if (plot->growthStage >= HABITAT_PLOT_STAGE_MATURE)
            continue;
        progress = plot->hoursProgress + hours;
        if (progress > 0xFFFF)
            progress = 0xFFFF;
        plot->hoursProgress = progress;
        plot->growthStage = min(HABITAT_PLOT_STAGE_MATURE,
                                plot->hoursProgress / HABITAT_PLOT_HOURS_PER_STAGE);
    }
}

// Offline catch-up: credit whole hours elapsed since the last stamp. Called
// on map load (events.c); cheap and idempotent within the same hour.
void Habitat_ReconcileGrowthFromRtc(void)
{
    u32 nowMinutes, elapsed;

    RtcCalcLocalTime();
    nowMinutes = (u32) gLocalTime.days * 24 * 60
               + (u32) gLocalTime.hours * 60
               + (u32) gLocalTime.minutes;
    if (nowMinutes <= gSaveBlock3Ptr->habitat.lastGrowthMinutes)
    {
        // Clock went backwards (RTC edit / new save): re-anchor, no credit.
        gSaveBlock3Ptr->habitat.lastGrowthMinutes = nowMinutes;
        return;
    }
    elapsed = nowMinutes - gSaveBlock3Ptr->habitat.lastGrowthMinutes;
    if (elapsed < 60)
        return;
    Habitat_TickPlots(elapsed / 60);
    gSaveBlock3Ptr->habitat.lastGrowthMinutes = nowMinutes - (elapsed % 60);
}

u32 Habitat_HarvestPlot(u32 plotIdx)
{
    struct HabitatPlot *plot = Habitat_GetPlot(plotIdx);
    if (plot == NULL || plot->growthStage < HABITAT_PLOT_STAGE_MATURE
     || plot->berryItem == ITEM_NONE)
        return 0;
    if (!AddBagItem(plot->berryItem, HABITAT_PLOT_YIELD))
        return 0;  // bag full: harvest stays on the plant
    plot->growthStage = 0;
    plot->hoursProgress = 0;
    Habitat_NotifyDependency(HABITAT_DEP_GROVE);
    return HABITAT_PLOT_YIELD;
}
