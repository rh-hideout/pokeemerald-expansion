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

// No-op until the spot framework subscribes, so call sites can be wired
// incrementally without ifdef noise.
void Habitat_NotifyEvent(enum HabitatEvent event);

#endif // GUARD_HABITAT_EVENTS_H
