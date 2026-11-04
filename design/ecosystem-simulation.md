# Ecosystem Simulation

Inspired by Rain World, adapted for a world that is **safe by default**. Danger is the exception, found in specific places, never imposed everywhere.

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

Capturing removes **that specific individual** from the wild population. Whether populations replenish through breeding or migration, and at what rate, remains undecided; a capture does not imply the habitat can never recover.

### Memorable individuals

- Marks: a scar, tint or distinct cry after notable encounters.
- Epithets in battle text after repeated meetings.
- Reactions: it may flee, hold a grudge or challenge on sight.
- NPCs mention local individuals.

## Tiered tracking (save space)

| Tier | Tracking |
|---|---|
| Unique, Very Rare, Rare | Always tracked individuals from the start |
| Common, Uncommon | Anonymous herds until battled, spared or noticed, then promoted to tracked individuals |

Record size and number are **not yet known**. The fields above are candidates, not a verified six-byte layout; exact IDs, time markers and other data must be designed after the Expansion save layout is measured.

## Off-screen simulation (abstracted)

The GBA cannot run every creature live.

- **On-screen creatures** use real movement AI.
- **Off-screen creatures** update in bulk when the player changes maps or time passes: who moved, ate, fought, recovered, grew or evolved.
- Predator vs prey fights between wild Pokemon end in fainting, never death.

## Food chain

- Prey flees predators, predators hunt weaker Pokemon.
- Too little prey means predators roam farther.
- Over-hunting a species can leave a habitat empty. Recovery is slow.

## Pressure (soft and local)

There is no global clock. Pressure exists only where the land is dangerous:

- **Day and night:** predators are more active at night. Uses the existing clock.
- **Weather:** storms and blizzards make dangerous zones worse. Uses the existing weather system.
- **Supplies:** long trips in Ur-Kalah drain items and party health, so planning matters.
- **Population drift:** an ignored rare Pokemon may grow, evolve or move on over time.

Safe regions and towns are never affected by any of this.

## Engine notes

- Weather and the real-time clock already exist in pokeemerald.
- Individual tracking and off-screen updates need custom C code and save space budgeting.
- Everything above must be tested on emulator and hardware limits before commitment.

## Open questions

- Exact record count that fits in the save block.
- Whether trainers' Pokemon follow the same individual rules.
- How visible overworld Pokemon are implemented (follower and overworld encounter code).
