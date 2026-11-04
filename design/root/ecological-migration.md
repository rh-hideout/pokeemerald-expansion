# Ecological migration — Pokémon movement across regions

**Decision: LOCKED (2026-11-04).** Persistent wild Pokémon can move between habitats and across region boundaries when ecological or social circumstances motivate travel. This is **not** unrestricted world roaming: routes must be physically possible and appropriate for the creature.

## Motivation and Rain World inspiration

Pokémon should have lives independent of the player. Territory, hunger, food availability, seasons/weather, threats, competition and social bonds can motivate movement. The player may later encounter a familiar individual far from its former home. The simulation should support emergent stories without requiring scripted encounters.

## Locked rules

1. **Cross-region migration is possible**, not mandatory for every species or individual.
2. **Habitat and geography constrain travel.** Land, sea, air, caves, climate, barriers and species traversal traits determine reachable destinations. No teleportation to arbitrary regions.
3. **Migration requires motivation.** Resource shortage, weather, territory displacement, threats, breeding/social needs or other plausible ecology may change destinations.
4. **Identity is preserved.** A migrating persistent Pokémon keeps its ID, meaningful history, condition and ownership; changing maps or regions must not create a duplicate.
5. **World time governs travel.** Progress occurs during active game-time only; closing the game freezes journeys.
6. **Off-screen migration is abstracted.** Distant individuals use bounded route/region transitions, not continuous pathfinding or active overworld sprites.
7. **Player freedom and safety remain intact.** Migration may affect local ecology and encounters but must not produce unavoidable surprise attacks or a global danger escalation.
8. **Ordinary populations can also drift** between suitable habitats through aggregate migration, without allocating a permanent ID to every member. Aggregate arrivals and departures contribute to [dynamic population ecology](population-ecology.md).

## Conceptual model

`home habitat -> reason to leave -> choose reachable destination -> travel through connected habitat graph -> arrive/settle/return`

A persistent individual needs at least a logical current location, home or territory reference, and a journey state when traveling. **This is a logical contract, not a verified binary save layout.** Routes may span multiple map groups and regions. Temporary active instances must be synchronized with the persistent record on map transitions.

## Design boundaries and unresolved parameters

- Hybrid navigation is locked: a habitat/region graph handles long-distance travel and bounded local pathfinding handles visible movement. The graph's actual topology and species-specific edge permissions are not yet finalized. See [Hybrid navigation](hybrid-navigation.md).
- How frequently individuals reconsider migration, and how quickly they move, remains open.
- Group movement, family bonds, territorial disputes, weather disruptions and navigation memory require later behavior specs.
- Which routes are impassable, dangerous or seasonal is content-dependent.
- Whether an individual returns home, settles permanently, or roams cyclically is an AI design choice to refine.
- Save budgets and entity-pool limits are not measured; do not invent counts or record bytes.

## Acceptance scenarios

1. A known Absol leaves a food-poor habitat, travels through connected terrain, and later appears in another region with the same identity and history.
2. A non-swimming, non-flying Pokémon cannot spontaneously cross open ocean without a plausible route.
3. Closing the game for a week does not move a Pokémon along its journey.
4. Off-screen population movement changes local abundance without storing one individual record per ordinary Pokémon.
5. Save/load and map changes never spawn both the origin and destination instance of the same persistent Pokémon.

See [Individual persistence](individual-persistence.md), [World clock](world-clock.md), [Regions](../regions.md), and [Ecosystem simulation](../ecosystem-simulation.md).
