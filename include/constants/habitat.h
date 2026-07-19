#ifndef GUARD_CONSTANTS_HABITAT_H
#define GUARD_CONSTANTS_HABITAT_H

// Shared between C and event scripts (data/event_scripts.s is preprocessed).
// Spot state machine per spec §2 — monotonic, 2-bit save encoding.
#define HABITAT_STATE_DORMANT    0
#define HABITAT_STATE_STIRRING   1
#define HABITAT_STATE_ACTIVE     2
#define HABITAT_STATE_BEFRIENDED 3

// Habitat_OnInspectSpot result when the talked object is not a habitat spot.
#define HABITAT_INSPECT_NOT_A_SPOT 0xFF

#endif // GUARD_CONSTANTS_HABITAT_H
