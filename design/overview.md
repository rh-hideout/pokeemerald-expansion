# Design Overview — grouped vision

A survival-flavored, open-world Pokémon game based on **pokeemerald-expansion**. The world lives independently of the player: **safe by default, dangerous by choice, alive everywhere**. Exploration matters more than a compulsory story.

This is the authoritative **high-level vision**, not an implementation checklist. [Dependencies](dependencies.md) identifies what must be decided before each system can be finalized.

## Agreed direction

- **Foundation:** use this `pokeemerald-expansion` fork, not vanilla `pokeemerald`. Expansion provides a broader species and mechanics foundation; exact enabled roster/build settings must be verified.
- **World:** 14 original named regions, open exploration, no forced linear story. Meadowmere is the gentle start; Neonport is the travel hub. Ur-Kalah is almost uncivilized and has no gyms.
- **Tone:** Safe, Calm, Wild, and Perilous conditions; danger should be visible or reliably signaled, with an opportunity to avoid or escape. Unavoidable surprise encounters are not the design goal.
- **Time:** the world advances during active gameplay and pauses when the game is closed. There is no offline catch-up. See [World clock](root/world-clock.md).
- **Inspiration:** Rain World's autonomous creature ecology, individual interactions and off-screen abstraction inspire the design, but not its mandatory rain-cycle timer or global survival pressure.
- **Creatures:** visible wild Pokémon with autonomous behavior and a living food chain. **Tiered persistence is locked**: notable individuals retain identity; ordinary populations are abstracted until an individual becomes significant. See [Individual persistence](root/individual-persistence.md).
- **Survival:** player, NPCs, party Pokémon, and wild creatures eat; hunger matters but cannot permanently kill anyone or erase a save.
- **People:** NPCs have routines, needs and relationships; trainers' challenges are optional and gym leaders are not fixed in place. **Tiered NPC persistence is locked:** notable individuals retain identity and histories, while background crowds use lightweight or abstract state and can be promoted by meaningful events. See [NPC persistence](root/npc-persistence.md). **Shared NPC–Pokémon events are locked:** consequential interactions may affect relationships, resources and journeys off-screen. See [Shared living-world events](root/shared-world-events.md).
- **Travel:** ledges can be climbed, Pokémon can help traverse land/water/air, and mount travel is directly controlled rather than teleportation. Natural hazards and stamina matter.

## 1. World and exploration

See [Regions](regions.md) and [Exploration](exploration.md).

- **14 regions:** Meadowmere, Neonport, Veyra, Tundrael, Sandara, Mistvale, Cragmoor, Sunreach Steppe, Verdant Maw, Duskhollow, The Abyss, Undervale, Skyreach, and Ur-Kalah.
- Regions have distinct ecologies, cultures and landmarks. Content should be **wide but dense**, rewarding curiosity across the route rather than empty travel.
- The 1,000+ Pokémon roster is a **coverage ambition**, not a claim that all are configured, spawnable or tested already.
- Routes and landmarks invite exploration; story is optional and does not gate the whole world.

## 2. Danger and environmental rules

See [Danger and ecosystem](danger-and-ecosystem.md) and [Hazards](hazards.md).

- **Safe / Calm / Wild / Perilous** describe local risk, not an automatic strength ladder or global pressure timer.
- Signs, tracks, visible behavior and weather forecast danger. Retreat and recovery remain possible.
- Storms, predators, currents, falls and unstable terrain naturally challenge powerful travel methods, including flight.
- Ur-Kalah has no regional authority or gym circuit; most areas are Wild or Perilous.

## 3. Pokémon and ecosystem

See [Ecosystem simulation](ecosystem-simulation.md).

- Notable Pokémon are persistent individuals capable of fainting, recovering, growing, evolving, moving, and remembering encounters.
- **Locked:** ordinary populations are abstracted until significant. Promotion can come from **meaningful player interactions or noteworthy autonomous ecosystem events**, including events unseen by the player. Exact thresholds, record sizes and limits remain open.
- Visible overworld behaviors include passive, skittish, territorial and predatory.
- **Utility-based wild AI is locked:** Pokémon select actions by weighing needs, personality, relationships and conditions, with urgent safety overrides and bounded updates. See [Utility AI](root/utility-ai.md).
- **Evolving individual personality is locked:** notable Pokémon develop distinct behavioral tendencies that can gradually change through meaningful experiences, including off-screen events. See [Evolving personality](root/evolving-personality.md).
- **Multi-sensory perception is locked:** Pokémon use environment-affected sight, hearing and species-appropriate senses, with partial information rather than omniscient detection. See [Perception](root/multi-sensory-perception.md).
- **Hybrid navigation is locked:** nearby Pokémon use bounded local routing and obstacle avoidance, while distant journeys use a species-accessible habitat/region graph. See [Hybrid navigation](root/hybrid-navigation.md).
- Habitat, diet, climate and food shape distribution; rarity emerges from ecology rather than a hard-coded scarcity quota.
- **Dynamic population ecology is locked:** species can reproduce, expand, decline and recover based on resources, predators and environmental conditions, with bounded simulation and safeguards against irreversible soft-locks. See [Population ecology](root/population-ecology.md).
- **Hybrid reproduction is locked:** ordinary populations reproduce abstractly; notable Pokémon can have persistent mates, nests, eggs, offspring and family relationships. See [Hybrid reproduction](root/hybrid-reproduction.md).
- **Selective social memory is locked:** notable Pokémon can remember consequential interactions, develop evolving trust, rivalry, fear and family bonds, including relationships formed without player involvement. See [Social memory](root/social-memory.md).
- **Ecological migration is locked:** persistent Pokémon may travel across regions through reachable habitats, keeping their identity, when needs or circumstances motivate them. See [Ecological migration](root/ecological-migration.md).
- The GBA only simulates nearby activity in detail. **Hybrid scheduled off-screen simulation is locked:** distant activity advances through distributed jobs during gameplay and bounded relevance catch-up, using only elapsed in-game time. See [Off-screen scheduler](root/offscreen-scheduler.md). **Hybrid catch-up is locked:** aggregate ordinary ecology and selectively advance consequential events for notable individuals; see [Hybrid catch-up](root/hybrid-catchup.md). **Adaptive priority with fairness is locked:** nearby areas and consequential events are favored without starving distant habitats; see [Adaptive scheduling](root/adaptive-scheduling.md).

## 4. Survival

See [Food and survival](survival.md).

- Everyone needs food; berries are foundational, with prepared food, meat, fish and roots as proposed additions.
- Hunger progresses through Fed, Peckish, Hungry, Starving. Severe deprivation can cause weakness or collapse, **never permanent death**.
- Safe areas make food plentiful and normal travel forgiving; dangerous expeditions demand more planning.
- Hunger uses in-game world time, **not elapsed real-world time while the game is closed**. Exact decay rates and boxed Pokémon handling remain undecided.

## 5. People, trainers and gyms

See [Living NPCs](living-npcs.md) and [Trainers and gyms](trainers-and-gyms.md).

- NPCs have homes, needs, goals, routines and relationships, including travel when the player is away. **Tiered persistence is locked** for notable people and abstract background crowds; see [NPC persistence](root/npc-persistence.md).
- Gym leaders may be elsewhere; the player learns where to find them rather than being blocked by a script.
- Trainers may propose battles; the player can decline.
- **A gym-bearing region has its own eight-badge circuit.** Ur-Kalah has none. Which and how many of the other 13 regions will have gyms, and the resulting total badge count, remain **open**; the older claim of “64 badges across 8 regions” was inconsistent with “every region gets 8.”

## 6. Traversal and mounts

See [Traversal](traversal.md), [Riding and mounts](riding-and-mounts.md), and [Hazards](hazards.md).

- Traversal includes climbing, swimming, gliding and other movement based on terrain and Pokémon abilities.
- Mounts can carry the player over land, water and air, with direct steering, stamina, hunger and trust.
- Travel remains meaningful through geography, weather, predator territory and upkeep, **not artificial rarity quotas**.
- Non-mount transportation between established safe stops can coexist with direct mount travel; its exact scope is open.

## Root decisions to settle next

| Root | Status | Why it matters |
|---|---|---|
| Code foundation | **Decided: Expansion fork** | Species/forms, APIs and engine integration |
| Save-space and runtime budget | **Needs measurement** | Persistent Pokémon/NPC count and off-screen simulation |
| World-clock policy | **Decided: in-game-only; no offline catch-up** | Exact day length and pause rules still need tuning |
| Persistent individual record and identity | **Tiered persistence decided; binary format pending budget** | Wild Pokémon, captured Pokémon, mounts and possibly trainer teams |

For the detailed dependency graph and proposed validation order, see [Dependencies](dependencies.md).

## Other unresolved design questions

- Whether all gym-bearing regions have 8 gyms, and which regions have circuits.
- Trainer Pokémon individual tracking and how capture, migration and reproduction change wild populations.
- Exact species/habitat tagging, biome boundaries, map connections and layouts.
- The implementation details of free flight, on-screen AI and player-facing menus.

**Do not treat the above unresolved details as implemented or locked.**
