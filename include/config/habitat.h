#ifndef GUARD_CONFIG_HABITAT_H
#define GUARD_CONFIG_HABITAT_H

// Hoenn Habitat engine configuration. Scale constants are full-game values
// from spec §5 — content grows into them; the layout never moves under saves.
#define HABITAT_SPOT_COUNT           320  // spot-state bytes reserved in SaveBlock3
#define HABITAT_TALK_COUNTER_COUNT   8    // spots needing >15 talk counts (Spiritomb-class)
#define HABITAT_PLACED_COUNTER_COUNT 8    // spots with COND_ITEM_PLACED persistence
#define HABITAT_PLACED_CONDITION_CAP 960  // authored COND_ITEM_PLACED.paramC ids (4-bit each)
#define HABITAT_RESIDENT_COUNT       96   // individualized residents (spec §5 cap)
#define HABITAT_PLOT_COUNT           12   // Grove berry plots (§5; slice uses 3)
#define HABITAT_GROVE_OUT_CAP        6    // global six-out cap; this Grove is one map
#define HABITAT_PLOT_HOURS_PER_STAGE 4    // growth pacing (dev-tunable)
#define HABITAT_PLOT_STAGE_MATURE    4    // stages 0..4; 4 = harvestable
#define HABITAT_PLOT_YIELD           3    // berries per harvest
#define HABITAT_GROVE_WORKER_SLOTS   6    // rendered worker objects on the Grove map

// Slice-only: new games start at the approved lab development position instead
// of the vanilla truck/bedroom opening. The presentation is deliberately
// limited to Zorua's existing follower graphics; unsupported locomotion stays
// unavailable until its own approved art exists.
// The Lab start and its stocked slice inventory are development aids. A
// release build must not silently ship this bypass of the authored opening.
#ifdef RELEASE
#define HABITAT_SLICE_SPAWN          FALSE
#else
#define HABITAT_SLICE_SPAWN          TRUE
#endif
#define HABITAT_ZORUA_PRESENTATION   TRUE
#define HABITAT_ZORUA_ON_FOOT_ONLY   TRUE

// Spec §2 law: "No wild battles exist anywhere else." Kills every wild
// encounter roll engine-wide (grass/surf, sweet scent, rock smash, fishing
// bites). Scripted battles — Machop's bout, the Deoxys finale — are
// setwildbattle/dowildbattle and don't pass through these gates.
#define HABITAT_NO_WILD_ENCOUNTERS   TRUE

// Habitat bouts never permit capture. The one durable finale completion flag
// is intentionally reserved for the authored Deoxys finale definition.
#define HABITAT_NO_CAPTURE                   TRUE
#define HABITAT_BOUT_ID_DEOXYS_FINALE        1
#define FLAG_HABITAT_DEOXYS_FINALE_WON       0x047  // audited unused FLAG_UNUSED_0x047

#endif // GUARD_CONFIG_HABITAT_H
