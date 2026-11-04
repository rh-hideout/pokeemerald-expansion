# Hybrid world geography — foundational world-structure decision

**Decision: LOCKED (2026-11-04).** The 14 original regions inhabit a geographically varied world comprising connected landmasses, island chains, oceans, underground networks and elevated regions. Land, water, air and subterranean travel all have meaningful roles. The world is neither one uniformly continuous continent nor 14 isolated menu-selected levels.

## World experience

- **Connected geography:** regions may share walkable borders, bridges, caves, mountain passes, shorelines or waterways. Other regions may be separated by sea or height.
- **Multiple routes where feasible:** land journeys, water travel, air traversal, underground passages and transport services can offer alternatives with different preparation and risk.
- **Nonlinear access:** players can set their own destinations. No mandatory storyline, gym badge count or fixed region order is required to unlock the world.
- **Geographical challenge, not story gates:** harsh terrain, weather, danger, distance, Pokémon-assisted movement and supplies can make routes difficult. A place may be temporarily unreachable without preparation, but should not depend on compulsory narrative completion.
- **Regions have distinct identities:** Meadowmere remains a forgiving starting area, Neonport a connected urban/travel hub, and Ur-Kalah an untamed expedition destination. The exact positions and links are not locked.
- **Vertical world layers:** caves, subterranean routes, cliffs and high places are real parts of navigation; the technical representation may use connected 2D maps rather than continuous 3D space.
- **Living-world continuity:** ecosystems, NPC travel, resource movement and off-screen simulation must interpret connections consistently, even when maps are not loaded.
- **Readable navigation:** landmarks, route knowledge and environmental cues should help players plan journeys. Specific map/notes UI is still open.

## Boundaries of this decision

**Locked:** hybrid topology and nonlinear, geography-driven travel.

**Not locked:** region coordinates, adjacency matrix, specific ports and bridges, map counts, continuous streaming, flight mechanics, exact transport unlocks, or whether any particular existing Hoenn map asset is reused. Do not assume the GBA engine supports one giant continuous map; verify map transitions, collision, objects and save constraints.

## Design integration

- [Regions](../regions.md): the 14 region identities and danger profiles.
- [Exploration](../exploration.md): dense, self-directed discovery.
- [Traversal](../traversal.md) and [Riding and mounts](../riding-and-mounts.md): terrain-dependent movement.
- [Parallel player progression](parallel-player-progression.md): knowledge, preparation and traversal grow without badge gating.
- [Dependencies](../dependencies.md): routes affect world events, ecology, trade, NPC movement and implementation limits.

## Next major work

1. Establish a **high-level world topology** with regional relationships and a small set of plausible travel corridors, not a detailed tile map.
2. Measure actual Expansion engine and save constraints before committing to region scale or seamless travel.
3. Validate one compact Meadowmere slice with a connected neighboring area, traversable route and return journey.

Avoid inventing exact borders, route counts or map sizes prematurely.
