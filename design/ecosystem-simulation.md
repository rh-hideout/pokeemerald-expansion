# Ecosystem Simulation

Inspired by Rain World's independent creature behavior and abstract off-screen ecosystem, adapted for a world that is **safe by default**. Its forced rain-cycle pressure is not adopted. Danger is the exception, found in specific places, never imposed everywhere.

## Core principles

1. **The world is generally safe.** Towns, routes and most wilderness are peaceful. Most wild Pokemon are passive or skittish.
2. **Danger is local and readable.** Dangerous areas are rare, telegraphed and optional (see `danger-and-ecosystem.md`).
3. **No forced pressure.** No global countdown, no forced battles and no forced story. Time still governs daily life everywhere, but danger and scarcity intensify only in harsher zones.
4. **The player is one creature in the ecosystem**, not the center of it.

## Finite means individuals

Every notable wild Pokemon is a specific, trackable individual, not a generic spawn.

### Lifecycle

1. **Living:** roams its home territory with a species, level, nature and history.
2. **Battle ends at 0 HP:** it faints on the ground, visible on the map.
3. **Recovering:** it stays down for a while, then slowly gets up and returns home.
4. **Growing:** each defeat and each stretch of time makes it stronger. It can evolve naturally and be met again later.
5. **Remembered:** it tracks how often the player has met and beaten it, so later meetings feel different.

Capturing removes **that specific individual** from the wild population. **Dynamic reproduction, migration and recovery are locked**; exact rates and accounting rules remain open. A capture does not imply the habitat can never recover.

### Memorable individuals

- Marks: a scar, tint or distinct cry after notable encounters.
- Epithets in battle text after repeated meetings.
- Reactions: it may flee, hold a grudge or challenge on sight.
- **Selective social memory (locked):** notable Pokémon remember meaningful encounters with the player and other Pokémon; trust, rivalry, fear and bonds can evolve and affect later behavior. See [Social memory](root/social-memory.md).
- **Evolving personality (locked):** notable Pokémon retain distinct behavioral tendencies that can gradually shift through consequential experiences, even off-screen. See [Evolving personality](root/evolving-personality.md).
- NPCs mention local individuals.

## Tiered persistence (locked design)

- **Persistent individuals:** named, notable, personally encountered or otherwise significant Pokémon keep stable identity, history and location across map changes and saves.
- **Abstract populations:** ordinary, unremarkable Pokémon are modeled as habitat populations, not as one saved record per animal.
- **Promotion (locked):** meaningful player interactions **or** remarkable independent ecosystem events can make a Pokémon persistent, even if the player never meets it. Ordinary sightings and routine fights do not automatically promote; precise thresholds remain open.
- **Simulation detail is separate from persistence:** a persistent individual can be simulated coarsely while off-screen without losing its identity.

See [Individual persistence](root/individual-persistence.md) for the identity contract and open lifecycle decisions. Exact record size and count must be measured; no six-byte assumption is valid.

## Off-screen simulation (abstracted)

The GBA cannot run every creature live.

- **On-screen creatures** use real movement AI, with **utility-based action selection** driven by needs, traits, memory and environment, plus urgent safety overrides. See [Utility AI](root/utility-ai.md). Perception is **multi-sensory and environment-aware**, not omniscient; see [Perception](root/multi-sensory-perception.md).
- **Off-screen creatures** update in bulk when the player changes maps or time passes: who moved, ate, fought, recovered, grew or evolved.
- **Ecological migration (locked):** persistent wild Pokémon may travel across connected regions when food, weather, territory, threats or social needs motivate them. Ordinary populations may migrate in aggregate. See [Ecological migration](root/ecological-migration.md).
- Predator vs prey fights between wild Pokemon end in fainting, never death.

## Food chain and population ecology

- Prey flees predators, predators hunt weaker Pokemon.
- Too little prey means predators roam farther.
- Over-hunting or resource scarcity can reduce local abundance; food recovery, reproduction and immigration can restore populations over in-game time.
- **Locked:** populations can grow, decline and recover according to ecology, with bounded simulation and safeguards against permanent progression soft-locks. See [Dynamic population ecology](root/population-ecology.md).
- **Hybrid reproduction (locked):** ordinary populations reproduce abstractly; notable Pokémon may maintain persistent mates, nests, eggs, offspring and family relationships. See [Hybrid reproduction](root/hybrid-reproduction.md).
- Fainting does not imply permanent death or automatically subtract an individual from a population.

## Pressure (soft and local)

There is no global clock. Pressure exists only where the land is dangerous:

- **Day and night:** predators may be more active at night. Uses the new in-game world clock (not real-world elapsed time).
- **Weather:** storms and blizzards make dangerous zones worse. Weather behavior must be driven consistently by in-game time.
- **Supplies:** long trips in Ur-Kalah drain items and party health, so planning matters.
- **Population drift:** an ignored rare Pokemon may grow, evolve or move on over time.

Safe regions and towns are never affected by any of this.

## Engine notes

- Existing weather and RTC support exist in Expansion, but the new living-world clock must not advance while the game is closed.
- Individual tracking and off-screen updates need custom C code and save space budgeting.
- Everything above must be tested on emulator and hardware limits before commitment.

## Open questions

- Exact record count that fits in the save block.
- Whether trainers' Pokemon follow the same individual rules.
- How visible overworld Pokemon are implemented (follower and overworld encounter code).
