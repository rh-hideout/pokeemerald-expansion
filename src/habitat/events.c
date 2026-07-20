// Event-driven condition invalidation. Shared mutation boundaries publish a
// dependency after a real write; nested writes are coalesced and drained.
#include "global.h"
#include "habitat/events.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "main.h"
#include "overworld.h"
#include "script.h"

#define HABITAT_MAX_NOTIFY_DRAINS 16

static bool8 sInRecompute;
static u32 sPendingDependencies;

static void SyncLiveSpotObjects(void)
{
    const struct HabitatMapSpan *span;
    const struct HabitatSpot *spots = Habitat_GetSpotTable();
    u32 i;
    u8 objectEventId;
    u8 mapGroup, mapNum;

    if (gMain.callback2 != CB2_Overworld)
        return;
    mapGroup = gSaveBlock1Ptr->location.mapGroup;
    mapNum = gSaveBlock1Ptr->location.mapNum;
    span = Habitat_GetMapSpan(mapGroup, mapNum);
    if (span == NULL)
        return;
    for (i = span->firstSpot; i < span->firstSpot + span->count; i++)
    {
        const struct HabitatSpot *spot = &spots[i];
        u16 graphicsId = 0;
        bool32 hidden = FlagGet(spot->hideFlag);
        bool32 spawned = !TryGetObjectEventIdByLocalIdAndMap(spot->localId, mapNum, mapGroup, &objectEventId);

        if (spot->graphicsVar != 0)
        {
            graphicsId = Habitat_GetResolvedSpotGraphicsId(spot);
            VarSet(spot->graphicsVar, graphicsId);
        }
        if (!hidden && !spawned)
            TrySpawnObjectEvent(spot->localId, mapNum, mapGroup);
        else if (!hidden && spot->graphicsVar != 0 && gObjectEvents[objectEventId].graphicsId != graphicsId)
            ObjectEventSetGraphicsId(&gObjectEvents[objectEventId], graphicsId);
        else if (hidden && spawned)
        {
            // Do not tear down the object currently executing its recruit
            // script. Its flag settles on the next map load.
            if (!(ScriptContext_IsEnabled() && objectEventId == gSelectedObjectEvent))
                RemoveObjectEventByLocalIdAndMap(spot->localId, mapNum, mapGroup);
        }
    }
}

void Habitat_NotifyDependency(enum HabitatDependency dependency)
{
    u32 drains = 0;

    if (dependency >= HABITAT_DEP_COUNT)
        return;
    sPendingDependencies |= HABITAT_DEP_MASK(dependency);
    if (sInRecompute)
        return;

    sInRecompute = TRUE;
    while (sPendingDependencies != 0 && drains++ < HABITAT_MAX_NOTIFY_DRAINS)
    {
        u32 pending = sPendingDependencies;
        u32 recomputeMask = pending;
        sPendingDependencies = 0;
        if (pending & HABITAT_DEP_MASK(HABITAT_DEP_MAP))
        {
            Habitat_ReconcileGrowthFromRtc();
            recomputeMask = HABITAT_DEP_MASK_ALL;
        }
        if (pending & HABITAT_DEP_MASK(HABITAT_DEP_TIME))
            Habitat_ReconcileGrowthFromRtc();
        Habitat_RecomputeCurrentMapDependencies(recomputeMask);
        if (pending & HABITAT_DEP_MASK(HABITAT_DEP_RESIDENT))
            Habitat_SyncGroveWorkersLive();
    }
    // A programming error must not leave future real mutations permanently
    // queued. The finite guard makes the failure bounded and deterministic.
    sPendingDependencies = 0;
    sInRecompute = FALSE;
    SyncLiveSpotObjects();
}

void Habitat_CheckTimeTick(s32 hours)
{
    static s32 sLastHour;
    static bool8 sHaveLastHour;

    if (!sHaveLastHour || hours != sLastHour)
    {
        sHaveLastHour = TRUE;
        sLastHour = hours;
        Habitat_NotifyDependency(HABITAT_DEP_TIME);
    }
}

u32 Habitat_GetConditionDependencyMask(const struct HabitatCondition *list)
{
    u32 mask = 0;
    u32 i;

    if (list == NULL)
        return 0;
    for (i = 0; list[i].type != COND_NONE && i < HABITAT_MAX_CONDITIONS; i++)
    {
        switch (list[i].type)
        {
        case COND_ITEM_PLACED: mask |= HABITAT_DEP_MASK(HABITAT_DEP_PLACEMENT); break;
        case COND_ITEM_OFFERED: mask |= HABITAT_DEP_MASK(HABITAT_DEP_INVENTORY); break;
        case COND_PARTY_SPECIES:
        case COND_PARTY_FRIENDSHIP:
        case COND_PARTY_MOVE:
        case COND_PARTY_NATURE: mask |= HABITAT_DEP_MASK(HABITAT_DEP_PARTY); break;
        case COND_RESIDENT_SPECIES:
        case COND_RESIDENT_COUNT:
        case COND_DEX_COUNT:
        case COND_SPOT_STATE:
        case COND_ZONE_COMPLETE: mask |= HABITAT_DEP_MASK(HABITAT_DEP_RESIDENT); break;
        case COND_TIME_OF_DAY: mask |= HABITAT_DEP_MASK(HABITAT_DEP_TIME); break;
        case COND_BERRY_MATURE: mask |= HABITAT_DEP_MASK(HABITAT_DEP_TIME) | HABITAT_DEP_MASK(HABITAT_DEP_GROVE); break;
        case COND_WEATHER: mask |= HABITAT_DEP_MASK(HABITAT_DEP_WEATHER); break;
        case COND_STORY_FLAG: mask |= HABITAT_DEP_MASK(HABITAT_DEP_STORY_FLAG); break;
        case COND_LIFETIME_STAT: mask |= HABITAT_DEP_MASK(HABITAT_DEP_LIFETIME_STAT); break;
        case COND_TALK_COUNT: mask |= HABITAT_DEP_MASK(HABITAT_DEP_TALK); break;
        default: break;
        }
    }
    return mask;
}
