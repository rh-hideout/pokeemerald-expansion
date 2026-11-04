# Riding and Mounts

Pokemon can carry the player across land, water and air, and the player controls them directly. Flying means actually flying through the map, not a teleport to a town. Riding on water works the same way surfing does today, extended to land and air.

## Core principles

1. **Direct control.** The player steers the mount in real time, like riding on water.
2. **No teleport travel.** Distance stays real. Flying covers ground quickly but can be seen, interrupted and risky.
3. **Mounts are individuals.** A mount is a specific Pokemon with its own stamina, hunger, trust and mood.
4. **Found through ecology, balanced through use.** Capable mounts belong in suitable habitats, whether common or uncommon there. Trust, stamina, terrain and weather limit travel; no artificial rarity quota is required.
5. **Every method has a counter.** Weather, predators, terrain and fatigue limit each type of riding.

## Mount types

| Type | Moves across | Typical limits |
|---|---|---|
| **Land riders** | Plains, forest, trails, desert | Blocked by cliffs, deep water, dense growth |
| **Water riders** | Rivers, lakes, open sea | Currents, cold, storms, deep-sea predators |
| **Air riders** | Over terrain, gaps, peaks | Wind, storms, altitude, aerial predators, low stamina |
| **Climbers and burrowers** | Rock faces, tunnels | Slow, tight spaces, narrow size range |

Each type has small, medium and large mounts. Larger mounts may carry more, use more food and be easier to spot, but do not automatically have to be rarer. Their abundance follows habitat and ecology.

## Stamina

- Every mount has its own stamina, drained by speed, distance, terrain, weight and weather.
- Flying drains fastest. Water and land riding drain slower.
- A drained mount slows, loses control, then has to land or stop. In the air it descends and sets the player down, and in the water it drifts to shore.
- Stamina recovers by resting and eating, so the survival system feeds directly into travel.

## Balance: the counters

Good mounts are the strongest travel tool in the game, so they carry real costs:

- **Habitat and encounter context.** Flyers, runners and swimmers live where adapted; reaching, observing and gaining their trust matters more than imposing rarity quotas. Persistent individual counts depend on the measured save budget.
- **Trust.** A wild or newly caught Pokemon will not carry the player until it trusts them. Trust is earned through care, feeding and time.
- **Upkeep.** Mounts eat more. Neglected mounts refuse to ride or tire quickly.
- **Stamina limits.** Long trips need planning, rest stops and food.
- **Hazards.** Storms ground flyers, predators target large visible mounts, and rough terrain tires them faster.
- **Party/team trade-off (open).** If mounts require active party slots, that could create a trade-off; this rule is not yet decided.
- **Local restrictions.** Some places cannot be crossed by mount: dense cave systems, narrow ledges, areas where mounts will not go (territorial zones, fog, ruins).
- **Care can fail.** An unfed or overworked mount can panic or collapse, which is dangerous at altitude or at sea.

## Alternatives for players without a specialized mount

- Basic riding options can exist (slow, short-range) so travel is not gated by acquiring an exceptional individual.
- Boats, ropes, trails and camps give routes that do not need a special Pokemon.
- NPC ferries, caravans and guides offer limited passage at a cost.
- Specialized mounts might be borrowed, hired or gained through NPC relationships; details remain open.

## How it fits the other systems

- **Traversal** (`traversal.md`): mounts extend climbing, swimming and crossing, and the same stamina rules apply.
- **Survival** (`survival.md`): mounts eat and tire, so food is travel fuel.
- **Ecosystem** (`ecosystem-simulation.md`): predators notice large mounts, and mounts are individuals that can be found, lost or hurt.
- **Exploration** (`exploration.md`): flying reveals big-picture landmarks but skips detail, so dense ground-level content stays valuable.

## Engine notes

- Water riding already exists as surfing, so land and air riding extend an existing player state.
- Free flight needs a new overworld mode: speed, altitude layers, camera behavior, collision with tall objects, and landing rules.
- Maps need to work when seen from the air, with larger visible space and ground detail still readable.
- Mount state (species, stamina, trust) uses a small record per mount, measured against save space.
- All of this needs testing on emulator and hardware limits before commitment.

## Open questions

- How altitude is shown and controlled (layers, shadow, simple up and down).
- How trust is built and shown.
- How many mounts can be active at once and how they are chosen.
- Whether the player can ride Pokemon they have not caught (for example, a tame wild one).
