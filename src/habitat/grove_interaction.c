// Grove-side interaction: worker display objects, plot inspect/harvest, and
// the recruit flow appended to befriended home-spot dialogue. All prose is
// engine placeholder in the §7 register (species voice + narrator aside);
// Jay rewrites it wholesale.
#include "global.h"
#include "habitat/events.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "item.h"
#include "main.h"
#include "overworld.h"
#include "pokemon.h"
#include "script.h"
#include "string_util.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/map_groups.h"
#include "constants/vars.h"

#define WORKER_NONE 0xFF

#define GROVE_MAP_GROUP MAP_GROUP(MAP_LITTLEROOT_TOWN)
#define GROVE_MAP_NUM   MAP_NUM(MAP_LITTLEROOT_TOWN)

static const u16 sWorkerGfxVars[HABITAT_GROVE_WORKER_SLOTS] =
{
    VAR_OBJ_GFX_ID_A, VAR_OBJ_GFX_ID_B, VAR_OBJ_GFX_ID_C,
    VAR_OBJ_GFX_ID_D, VAR_OBJ_GFX_ID_E, VAR_OBJ_GFX_ID_F,
};
static const u16 sWorkerHideFlags[HABITAT_GROVE_WORKER_SLOTS] =
{
    FLAG_UNUSED_0x036, FLAG_UNUSED_0x037, FLAG_UNUSED_0x038,
    FLAG_UNUSED_0x039, FLAG_UNUSED_0x03A, FLAG_UNUSED_0x03B,
};

// Display slot i = i-th out resident in registry order. Deterministic pure
// function of assignments; objects re-sync whenever assignments change.
static s32 DisplaySlotResident(u32 slot)
{
    u32 i, n = 0;
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        if (!Habitat_ResidentIsOut(i))
            continue;
        if (n == slot)
            return i;
        n++;
    }
    return -1;
}

// special (Littleroot ON_TRANSITION, before objects load): stamp worker
// graphics vars and visibility flags from current assignments.
void Habitat_PrepareGroveWorkers(void)
{
    u32 slot;
    for (slot = 0; slot < HABITAT_GROVE_WORKER_SLOTS; slot++)
    {
        s32 residentIdx = DisplaySlotResident(slot);
        if (residentIdx >= 0)
        {
            VarSet(sWorkerGfxVars[slot],
                   OBJ_EVENT_MON + Habitat_GetResidentSpecies(residentIdx));
            FlagClearNoNotify(sWorkerHideFlags[slot]);
        }
        else
        {
            FlagSetNoNotify(sWorkerHideFlags[slot]);
        }
    }
}

// Live re-sync after assignment changes while standing in the Grove.
void Habitat_SyncGroveWorkersLive(void)
{
    u32 slot;
    u8 objectEventId;

    if (gSaveBlock1Ptr->location.mapGroup != GROVE_MAP_GROUP
     || gSaveBlock1Ptr->location.mapNum != GROVE_MAP_NUM
     || gMain.callback2 != CB2_Overworld)
        return;
    Habitat_PrepareGroveWorkers();
    for (slot = 0; slot < HABITAT_GROVE_WORKER_SLOTS; slot++)
    {
        u8 localId = LOCALID_HABITAT_WORKER_0 + slot;
        bool32 hidden = FlagGet(sWorkerHideFlags[slot]);
        bool32 spawned = !TryGetObjectEventIdByLocalIdAndMap(localId, GROVE_MAP_NUM,
                                                             GROVE_MAP_GROUP, &objectEventId);
        if (!hidden && !spawned)
            TrySpawnObjectEvent(localId, GROVE_MAP_NUM, GROVE_MAP_GROUP);
        else if (hidden && spawned)
        {
            if (ScriptContext_IsEnabled() && objectEventId == gSelectedObjectEvent)
                continue;
            RemoveObjectEventByLocalIdAndMap(localId, GROVE_MAP_NUM, GROVE_MAP_GROUP);
        }
    }
}

// ---- worker dialogue ----

static s32 TalkedWorkerResident(void)
{
    u32 slot = gObjectEvents[gSelectedObjectEvent].trainerRange_berryTreeId;
    if (slot >= HABITAT_GROVE_WORKER_SLOTS)
        return -1;
    return DisplaySlotResident(slot);
}

// special: buffers the worker's species into STR_VAR_1 and its plot's crop
// into STR_VAR_2; VAR_RESULT = TRUE if resolved.
u16 Habitat_OnTalkWorker(void)
{
    s32 residentIdx = TalkedWorkerResident();
    const struct HabitatResident *r = Habitat_GetResident(residentIdx < 0 ? 0xFFFF : residentIdx);
    const struct HabitatPlot *plot;

    if (r == NULL || r->assignment == 0)
        return FALSE;
    plot = Habitat_GetPlot(r->assignment - 1);
    StringCopy(gStringVar1, GetSpeciesName(Habitat_GetResidentSpecies(residentIdx)));
    CopyItemName(plot != NULL ? plot->berryItem : ITEM_NONE, gStringVar2);
    return TRUE;
}

// special: sends the talked worker home. VAR_RESULT unused.
u16 Habitat_SendTalkedWorkerHome(void)
{
    s32 residentIdx = TalkedWorkerResident();
    if (residentIdx >= 0)
        Habitat_SendResidentHome(residentIdx);
    return TRUE;
}

// ---- plot dialogue ----

static u32 TalkedPlotIndex(void)
{
    return gObjectEvents[gSelectedObjectEvent].trainerRange_berryTreeId;
}

// special: VAR_RESULT = 0 untended, 1 growing, 2 mature. Buffers crop name
// into STR_VAR_1 and growth stage digits into STR_VAR_2.
u16 Habitat_OnInspectPlot(void)
{
    const struct HabitatPlot *plot = Habitat_GetPlot(TalkedPlotIndex());

    if (plot == NULL || (plot->worker1 == WORKER_NONE && plot->worker2 == WORKER_NONE))
        return 0;
    CopyItemName(plot->berryItem, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, plot->growthStage, STR_CONV_MODE_LEFT_ALIGN, 1);
    return plot->growthStage >= HABITAT_PLOT_STAGE_MATURE ? 2 : 1;
}

// special: harvest; VAR_RESULT = berries received (0 = failed/not mature).
u16 Habitat_TryHarvestPlot(void)
{
    u32 got = Habitat_HarvestPlot(TalkedPlotIndex());
    if (got > 0)
    {
        const struct HabitatPlot *plot = Habitat_GetPlot(TalkedPlotIndex());
        CopyItemName(plot->berryItem, gStringVar1);
        ConvertIntToDecimalStringN(gStringVar2, got, STR_CONV_MODE_LEFT_ALIGN, 1);
    }
    return got;
}

// ---- recruiting from the home spot ----

// special: pre-check only — no state changes during dialogue (mutating the
// locked, talked-to object's visibility mid-script kills the script engine;
// found the hard way). VAR_RESULT: 0 cannot, 1 can, 2 Grove globally full.
u16 Habitat_CanRecruitToGrove(void)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(Habitat_GetInteractionSpotId());
    s32 residentIdx;
    u32 plotIdx;

    if (spot == NULL)
        return 0;
    residentIdx = Habitat_FindResidentBySpot(spot->spotId);
    if (residentIdx < 0 || Habitat_ResidentIsOut(residentIdx))
        return 0;
    StringCopy(gStringVar1, GetSpeciesName(Habitat_GetResolvedSpotSpecies(spot)));
    if (Habitat_OutCount() >= HABITAT_GROVE_OUT_CAP)
        return 2;
    for (plotIdx = 0; plotIdx < HABITAT_PLOT_COUNT; plotIdx++)
    {
        const struct HabitatPlot *plot = Habitat_GetPlot(plotIdx);
        if (plot->worker1 == WORKER_NONE || plot->worker2 == WORKER_NONE)
            return 1;
    }
    return 0;
}

// special: the actual assignment — runs after dialogue closed and released.
void Habitat_TryRecruitToGrove(void)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(Habitat_GetInteractionSpotId());
    s32 residentIdx;
    u32 plotIdx;

    if (spot == NULL)
        return;
    residentIdx = Habitat_FindResidentBySpot(spot->spotId);
    if (residentIdx < 0 || Habitat_ResidentIsOut(residentIdx))
        return;
    for (plotIdx = 0; plotIdx < HABITAT_PLOT_COUNT; plotIdx++)
    {
        const struct HabitatPlot *plot = Habitat_GetPlot(plotIdx);
        if (plot->worker1 == WORKER_NONE || plot->worker2 == WORKER_NONE)
        {
            if (Habitat_AssignResidentToPlot(residentIdx, plotIdx))
                return;
        }
    }
}
