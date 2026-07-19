// Event-driven recomputation (spec §2: "no polling loops"). Game call sites
// fire Habitat_NotifyEvent; this routes them into spot recomputation and,
// when the overworld is live, spawns/despawns spot sprites whose visibility
// flags changed. Call sites wired:
//   MAP_LOAD       overworld.c InitObjectEventsLocal/Link (before object spawn)
//   TIME_TICK      overworld.c UpdateTimeOfDay -> Habitat_CheckTimeTick (hour flips)
//   WEATHER_CHANGE field_weather.c SetCurrentAndNextWeather + transition completion
//   PARTY_CHANGE   script_pokemon_util.c ScriptGiveMonParameterized
//   RESIDENT_CHANGE spot_manager.c befriend resolution (registry consumes phase 3)
#include "global.h"
#include "habitat/events.h"
#include "habitat/spots.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "main.h"
#include "overworld.h"

static bool8 sInRecompute, sPendingRecompute;

static void SyncLiveSpotObjects(void)
{
    u32 i;
    u8 objectEventId;
    u8 mapGroup, mapNum;

    if (gMain.callback2 != CB2_Overworld)
        return;  // headless/test/menu contexts: flags alone are enough
    mapGroup = gSaveBlock1Ptr->location.mapGroup;
    mapNum = gSaveBlock1Ptr->location.mapNum;

    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
    {
        const struct HabitatSpot *spot = &gHabitatSpots[i];
        bool32 hidden, spawned;
        if (spot->mapGroup != mapGroup || spot->mapNum != mapNum)
            continue;
        hidden = FlagGet(spot->hideFlag);
        spawned = !TryGetObjectEventIdByLocalIdAndMap(spot->localId, mapNum, mapGroup, &objectEventId);
        if (!hidden && !spawned)
            TrySpawnObjectEvent(spot->localId, mapNum, mapGroup);
        else if (hidden && spawned)
            RemoveObjectEventByLocalIdAndMap(spot->localId, mapNum, mapGroup);
    }
}

static void RecomputeAndSync(void)
{
    if (sInRecompute)
    {
        // Befriend resolution notifies from inside a recompute; drain once.
        sPendingRecompute = TRUE;
        return;
    }
    sInRecompute = TRUE;
    do
    {
        sPendingRecompute = FALSE;
        Habitat_RecomputeCurrentMapSpots();
    } while (sPendingRecompute);
    sInRecompute = FALSE;
    SyncLiveSpotObjects();
}

void Habitat_NotifyEvent(enum HabitatEvent event)
{
    switch (event)
    {
    case HABITAT_EVENT_MAP_LOAD:
        // Objects spawn right after this; correct flags are all that's needed.
        RecomputeAndSync();
        break;
    case HABITAT_EVENT_TIME_TICK:
    case HABITAT_EVENT_WEATHER_CHANGE:
    case HABITAT_EVENT_PARTY_CHANGE:
    case HABITAT_EVENT_INVENTORY_CHANGE:
    case HABITAT_EVENT_RESIDENT_CHANGE:
        RecomputeAndSync();
        break;
    case HABITAT_EVENT_SPOT_STATE_CHANGE:
        break;  // reserved; state changes already happen inside recompute
    }
}

// Called every UpdateTimeOfDay with the current local hour; notifies once per
// flip. (Statics stay zero-initialized — .data is discarded by the test link.)
void Habitat_CheckTimeTick(s32 hours)
{
    static s32 sLastHour;
    static bool8 sHaveLastHour;
    if (!sHaveLastHour || hours != sLastHour)
    {
        sHaveLastHour = TRUE;
        sLastHour = hours;
        Habitat_NotifyEvent(HABITAT_EVENT_TIME_TICK);
    }
}
