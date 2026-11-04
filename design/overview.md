# Design Overview: grouped vision

A survival-flavored, open-world Pokemon game on **pokeemerald-expansion**. The world lives independently of the player: **safe by default, dangerous by choice, alive everywhere**. Exploration matters more than a compulsory story.

This is the high-level vision, not an implementation checklist. **Decision status lives in [STATUS.md](STATUS.md)**: Locked, Proposed, Aspirational or Open. Where a file under `root/` says "locked", STATUS.md decides. Build order and test gates are in [Dependencies](dependencies.md) and the [technical audit](technical-feasibility-audit.md).

## Core pillars (locked)

- **Foundation:** this Expansion fork, not vanilla pokeemerald. Exact enabled roster and build settings still need verification.
- **Balanced sandbox:** exploration, collection, battles, care and bonding, survival and travel, and world participation are all legitimate ways to play. See [balanced sandbox](root/balanced-pokemon-sandbox.md).
- **Parallel progression:** training, relationships, exploration knowledge, traversal and optional gyms advance independently, with no compulsory global ladder. See [parallel progression](root/parallel-player-progression.md).
- **Hybrid encounters:** visible wild Pokemon you can observe, avoid, feed, befriend or battle, with traditional turn-based battle and capture kept compatible. See [wild encounters](root/hybrid-wild-encounters.md).
- **Hybrid geography:** landmasses, islands, oceans, underground networks and elevated regions, with nonlinear travel. Exact adjacency is open. See [geography](root/hybrid-world-geography.md).
- **Tiered persistence:** notable individuals keep identity; ordinary populations are abstracted until something makes them significant. See [individual persistence](root/individual-persistence.md).

## 1. World and exploration

See [Regions](regions.md) and [Exploration](exploration.md).

- 14 original regions: Meadowmere (gentle start), Neonport (travel hub), Veyra, Tundrael, Sandara, Mistvale, Cragmoor, Sunreach Steppe, Verdant Maw, Duskhollow, The Abyss, Undervale, Skyreach and Ur-Kalah (almost uncivilized, no gyms).
- Wide but dense: something worth stopping for in every stretch.
- The 1,000+ species roster is a coverage ambition, not a claim that all are configured, spawnable or tested.

## 2. Danger and hazards

See [Danger and ecosystem](danger-and-ecosystem.md) and [Hazards](hazards.md).

- Safe, Calm, Wild and Perilous describe local risk, not a strength ladder or global pressure timer.
- Danger is signaled by tracks, behavior and weather, and retreat is possible.
- Storms, predators, currents, falls and unstable terrain balance powerful travel, including flight.

## 3. Pokemon and ecosystem

See [Ecosystem simulation](ecosystem-simulation.md).

- Notable Pokemon are persistent individuals that faint, recover, grow, evolve and move.
- Wild behaviors: passive, skittish, territorial, predatory, with a living food chain.
- Habitat, diet, climate and food shape distribution. Rarity comes from ecology, not quotas.
- Distant activity is simulated in aggregate and updated in bounded batches (proposed; see STATUS.md).
- Deeper layers (social memory, personality, family trees) are aspirational.
- Inspiration: Rain World's autonomous creatures and off-screen abstraction, without its mandatory rain timer.

## 4. Survival

See [Food and survival](survival.md).

- Everyone eats: the player, NPCs, party Pokemon and wild creatures. Berries are the base food.
- Hunger states: Fed, Peckish, Hungry, Starving. Starving means weakness and collapse, never permanent death or a lost save.
- Safe areas have plentiful food; dangerous expeditions need planning.
- Time: the clock policy is proposed as in-game time only, with no offline catch-up, pending owner confirmation. See [world clock](root/world-clock.md).

## 5. People, trainers and gyms

See [Living NPCs](living-npcs.md) and [Trainers and gyms](trainers-and-gyms.md).

- NPCs have homes, needs, routines and relationships, and live whether or not the player is watching (proposed).
- Notable NPCs keep identity; background crowds are abstract (proposed).
- Richer NPC layers (social memory, personality, rumors, groups, long-term goals, planning, resources, regional economy) are aspirational.
- Trainers may propose battles and the player can decline. Gym leaders may be elsewhere, and the player learns where to find them.
- Each gym-bearing region has its own eight-badge circuit. Ur-Kalah has none. Which of the other 13 regions have gyms, and the total badge count, are open.

## 6. Traversal and mounts

See [Traversal](traversal.md), [Riding and mounts](riding-and-mounts.md) and [Hazards](hazards.md).

- Ledges can be climbed. Pokemon can help traverse land, water and air.
- Mounts are directly steered, with stamina, hunger and trust. Free flight is a real flight mode, not a teleport.
- Travel stays meaningful through geography, weather, predator territory and upkeep, not artificial rarity.
- Non-mount transport between safe stops may coexist; its scope is open.

## Root decisions

| Root | Status | Why it matters |
|---|---|---|
| Code foundation | Locked: Expansion fork | Species, forms, APIs, engine |
| Save and runtime budget | Needs measurement (Gate A, C) | Persistent record counts and simulation size |
| World clock | Proposed: in-game time only | Hunger, routines, growth, weather, ecology |
| Individual record | Tiered persistence locked; layout pending budget | Wild, captured and mounted Pokemon |

## Unresolved

- Whether all gym regions have 8 gyms, and which regions have circuits.
- Trainer Pokemon tracking, and how capture, migration and reproduction change wild populations.
- Species and habitat tagging, biome boundaries, map connections and layouts.
- Free flight, on-screen AI and player-facing menus.

Nothing marked Proposed, Aspirational or Open is implemented.
