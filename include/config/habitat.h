#ifndef GUARD_CONFIG_HABITAT_H
#define GUARD_CONFIG_HABITAT_H

// Hoenn Habitat engine configuration. Scale constants are full-game values
// from spec §5 — content grows into them; the layout never moves under saves.
#define HABITAT_SPOT_COUNT          320  // spot-state bytes reserved in SaveBlock3
#define HABITAT_TALK_COUNTER_COUNT  8    // spots needing >15 talk counts (Spiritomb-class)

#endif // GUARD_CONFIG_HABITAT_H
