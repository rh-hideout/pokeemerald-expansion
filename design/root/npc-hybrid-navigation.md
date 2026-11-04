# Hybrid NPC navigation — root design decision

**Decision: LOCKED (2026-11-04).** NPCs use **bounded local pathfinding and obstacle avoidance when nearby**, and a **connected world-route graph** for journeys across maps, settlements and regions. Roads, terrain, transport access, schedules and environmental conditions constrain travel. Distant journeys are simulated abstractly, never tile by tile across the whole world.

## Locked invariants

1. **Two scales of navigation.** Nearby active NPCs use legal local movement; distant travelers use graph edges and logical travel progress.
2. **Grounded world connections.** Roads, paths, caves, gates, bridges, boats, stations and other valid connections must correspond to actual world access. No arbitrary teleportation.
3. **Actor-specific access.** NPC abilities, available transport, route permissions, weather, hazards and temporary closures affect route validity. Pokémon-only routes are not automatically human routes.
4. **Decisions and navigation separate.** [NPC routine/utility AI](npc-routine-utility.md) selects goals and commitments; navigation checks reachability, finds a route and reports delays, blocks or failures.
5. **Travel consumes in-game time.** Route progress advances only while the game runs; no wall-clock catch-up when closed.
6. **Local movement is bounded.** Search radius, explored nodes, retries, replanning frequency and active jobs must fit measured GBA CPU/RAM budgets. Unreachable goals use a safe fallback rather than infinite loops.
7. **Coherent materialization.** A notable NPC's graph position, travel state and visible object instance reference one canonical identity. Save/load and map transitions must never duplicate or reset a traveler.
8. **Tiered fidelity.** Notable NPCs preserve coarse route/progress off-screen; ordinary crowds use lightweight schedules or aggregate traffic. No global per-person pathfinding.
9. **Event causality.** [Shared NPC–Pokémon events](shared-world-events.md) require actors to plausibly meet along reachable paths at compatible times. No cross-region interaction without a valid journey.
10. **Social travel.** Visiting friends, delivering goods, rescuing others and changing plans may cause a traveler to reroute, wait, return or seek shelter; relationships do not override route legality.
11. **Essential-service safety.** Important NPC travel cannot irreversibly remove critical shops, gyms, recovery or required progression; substitutes, discoverable schedules or alternative access must exist.
12. **Fair scheduling.** Off-screen route updates share the bounded adaptive scheduler, without starving distant travelers or blocking map entry.
13. **No fabricated arrival.** If an area cannot reconcile overdue travel within budget, use a safe consistent representation rather than showing an actor in two locations.

## Conceptual navigation contract — not implemented code

`routine/utility destination -> route-access check -> local path or graph itinerary -> bounded movement/progress -> validate transition -> update canonical position -> notify behavior and shared events`

### Local layer

- Uses active map collision, occupied tiles, doors, elevation and authorized traversal.
- May use small-grid search, cached waypoints or lightweight steering; algorithm is not locked.
- Reports reached, blocked, unreachable or interrupted to behavior selection.
- Handles moving obstacles through bounded retries and safe fallback.

### World-route graph

- Nodes represent reachable settlements, maps, junctions, habitats or transport stops, not every tile.
- Edges encode actual traversable connections, access restrictions and conditional availability.
- Time/cost may depend on transport, conditions and the NPC's capabilities.
- Logical progress is saved for notable travelers; off-screen updates can be coarse.
- NPC and Pokémon navigation may share geographic topology but require different traversal permissions and journey logic.

## Example

A traveling merchant normally walks from a market to a neighboring village. A bridge closure forces a valid detour or delay; the merchant cannot simply appear across the river. If they learn a friend needs help, utility AI may select a new reachable destination. When the player arrives, the merchant appears at a location consistent with the journey and keeps their identity, memories and personality.

## Open engineering decisions

- World graph granularity, edge representation, transport schedules and conditional access.
- Local pathfinding algorithm, search budget, collision handling and waypoint mapping.
- How local warp/object-event behavior maps to graph arrival and departure.
- Exact travel time, fatigue, cargo and companion handling.
- Handling route closures during an ongoing off-screen journey.
- Serialization of itinerary, progress and last-update timestamps.
- Safe fallbacks for unavailable NPC services and overdue activation reconciliation.
- ROM/RAM/save budgets, performance profiling and graph connectivity tests.

Do not lock numeric limits or claim implementation until measured.

## Acceptance scenarios

1. A nearby NPC routes around a wall without clipping through it.
2. An unreachable target terminates safely rather than replanning forever.
3. A pedestrian cannot use a water-only route without authorized transport.
4. A notable traveler crosses connected regions over in-game time while preserving identity and memories.
5. An NPC–Pokémon meeting only occurs when routes and times plausibly intersect.
6. Saving/loading mid-journey neither duplicates nor teleports a traveler.
7. Ordinary crowds do not require a separate pathfinding job per person off-screen.
8. A bridge closure delays or reroutes travel without trapping critical services permanently.
9. Closing the game advances no travel.
10. Route processing stays within measured budgets and does not stall map entry.

See [Pokémon hybrid navigation](hybrid-navigation.md), [NPC routines and utility](npc-routine-utility.md), [NPC persistence](npc-persistence.md), [Off-screen scheduler](offscreen-scheduler.md), and [Shared events](shared-world-events.md).
