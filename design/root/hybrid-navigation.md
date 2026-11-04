# Hybrid Pokémon navigation — root design decision

**Decision: LOCKED (2026-11-04).** Wild Pokémon use **bounded local pathfinding and obstacle avoidance** for nearby movement, while **long-distance journeys use a species-accessible habitat/region connectivity graph**. [Hybrid NPC navigation](npc-hybrid-navigation.md) is separately locked; it may share world topology but uses human travel access and transport rules. Off-screen travel advances through abstract graph transitions, not continuous world-scale tile pathfinding.

## Purpose

A Pokémon should reach food, shelter, family, territory or a migration destination without walking through walls or teleporting arbitrarily. The GBA should not have to search all maps or keep distant overworld objects alive.

## Locked rules

1. **Two navigation scales:** detailed local movement on loaded/nearby maps; coarse graph-based movement for habitats, maps and regions.
2. **Terrain legality:** collision, water, elevation, cliffs, doors, caves, flight/swimming/burrowing and other movement capabilities determine whether a route is possible. Species restrictions apply at both scales.
3. **No arbitrary teleportation:** transitions between distant habitats follow valid connected edges and consume in-game travel time; a migration cannot jump through an impassable barrier.
4. **Navigation follows decisions:** [Utility AI](utility-ai.md) chooses goals; navigation determines reachable routes and reports failure, delay or changed conditions. A high utility score cannot override physical access.
5. **Local bounded search:** limit explored tiles, route length, replanning frequency and active navigation jobs. Exact algorithm and limits remain unselected pending engine measurements.
6. **Dynamic obstacle response:** nearby Pokémon avoid or replan around moving entities and temporary blockers where feasible; unreachable destinations cause safe fallback rather than infinite loops.
7. **Coherent transitions:** when a persistent Pokémon enters/leaves the visible area, its local instance and abstract journey reference the same stable identity, never duplicated.
8. **Off-screen efficiency:** notable travelers retain logical graph location/progress; ordinary populations migrate as aggregates. No per-frame pathfinding outside the active area. Their progress is driven by the [hybrid off-screen scheduler](offscreen-scheduler.md).
9. **No offline progression:** travel, waiting and replanning advance only while the game runs.
10. **Fairness and safety:** pathing must not create unavoidable surprise attacks or allow wild Pokémon to ignore intended safe-zone boundaries.
11. **World layout is authoritative:** graph edges must correspond to actual world connections and movement capabilities; invalid links must be testable.

## Conceptual layers

`utility goal -> choose reachable local target / graph destination -> plan bounded local route or habitat edge -> execute / advance abstract travel -> validate transition -> update identity and ecology`

### Local layer

- Operates on active-map collision and movement rules.
- May use a small-grid search, cached waypoints or lightweight steering (implementation not yet locked).
- Respects occupied tiles, terrain permissions and interrupting threats.
- Reports reached / blocked / unreachable / interrupted to the AI.

### Habitat/region graph

- Nodes represent habitats or map-scale travel areas, not necessarily every tile.
- Edges represent validated traversable connections with capability requirements and possibly environmental conditions.
- Travel cost/time and edge availability depend on species, conditions and in-game clock.
- A traveler can pause, turn back, settle or choose another reachable destination.
- Aggregates can drift along graph edges without instantiating every member.

## Example

A hungry wild Pokémon navigates around a boulder to reach nearby berries. When the habitat runs low on food, it may choose to migrate to a neighboring forest via a pass. A non-swimmer cannot cross an open-water edge, but a compatible flying or swimming Pokémon may use an appropriate connection. Off-screen migration advances along the forest/pass graph, not a tile-by-tile world simulation.

## Engineering boundaries

- Keep movement, path selection, collision, utility scoring and ecological population accounting separate.
- Do not assume vanilla map connections, warps or ledges automatically represent every usable wildlife route; verify map semantics.
- Define transition reconciliation so save/load and map changes do not create two copies of one notable Pokémon.
- Avoid deadlocks at crowded crossings; introduce bounded retries and safe fallback.
- Graph data and pathfinding workspaces must fit measured ROM/RAM budgets.

## Open parameters

- Local search algorithm, queue size, grid radius, caching and scheduling.
- Graph node granularity, edge metadata, species movement tags and travel costs.
- How weather, hazards, doors, tides, flying and climbing alter edges.
- How off-screen progress maps to a visible spawn location on arrival.
- How migration groups, parents/offspring and mounts travel together.
- Tests for graph connectivity, unreachable goals, performance and save consistency.

No route length, node count, search budget, graph byte size or travel rate is locked before profiling.

## Acceptance scenarios

1. A nearby Pokémon navigates around a solid obstacle to reach food without clipping through it.
2. An unreachable target causes a bounded fallback, not a freeze or infinite replanning loop.
3. A non-swimming/non-flying Pokémon cannot cross a water-only graph edge.
4. A notable migrant moves across connected habitats while preserving identity, family and social history.
5. Closing the game does not advance any journey.
6. Re-entering a map does not duplicate a persistent traveler.
7. Distant population migration works without creating one sprite or pathfinding job per creature.
8. Local navigation and graph travel stay within measured performance budgets.

See [Ecological migration](ecological-migration.md), [Utility AI](utility-ai.md), [Multi-sensory perception](multi-sensory-perception.md), and [Individual persistence](individual-persistence.md).
