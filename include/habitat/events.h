#ifndef GUARD_HABITAT_EVENTS_H
#define GUARD_HABITAT_EVENTS_H

// Recompute triggers per spec §2: the engine recomputes spot conditions on
// events, never by polling. Game call sites fire these; the spot manager
// (M1 phase 2) subscribes.
enum HabitatEvent
{
    HABITAT_EVENT_MAP_LOAD,
    HABITAT_EVENT_TIME_TICK,
    HABITAT_EVENT_WEATHER_CHANGE,
    HABITAT_EVENT_PARTY_CHANGE,
    HABITAT_EVENT_INVENTORY_CHANGE,
    HABITAT_EVENT_RESIDENT_CHANGE,
    HABITAT_EVENT_SPOT_STATE_CHANGE,
};

void Habitat_NotifyEvent(enum HabitatEvent event);
void Habitat_CheckTimeTick(s32 hours);  // fires TIME_TICK on hour flips

#endif // GUARD_HABITAT_EVENTS_H
