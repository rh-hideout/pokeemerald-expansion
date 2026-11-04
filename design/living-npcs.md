# Living NPCs

NPCs are people with lives, not props waiting at a spot. They have homes, needs, routines and wants, and they act on them whether or not the player is watching. Nothing about their daily life is scripted by story.

## Core principles

1. **NPCs live in the world.** They sleep, eat, work, travel, explore and socialize.
2. **No fixed positions.** An NPC is somewhere because of what they are doing, not because a script placed them.
3. **Everyone is findable but never guaranteed.** The player may have to look, wait, ask around or follow a lead.
4. **The same survival rules apply.** NPCs need food, rest and safety like everyone else (see `berries.md`).

## What every NPC has

| Part | Meaning |
|---|---|
| **Home** | A place they return to, sleep in and keep food in |
| **Routine** | A loose daily pattern (work, meals, rest, errands) |
| **Needs** | Hunger, rest, and for some, safety |
| **Wants** | A personal goal that can pull them away from routine (explore, train, trade, visit someone) |
| **Temperament** | Homebody, wanderer, adventurer; sets how far and how often they leave |
| **Relationships** | Friends, rivals, family, former students |

## Life patterns

- **Daily:** wake, eat, work, socialize, go home, sleep. Shops close, houses fill at night, streets change by time of day.
- **Wandering:** some NPCs leave town to forage, train, fish or explore, and come back later.
- **Travelers:** some move between towns and regions by road or ferry and show up in unexpected places.
- **Seasonal or occasional:** festivals, harvests and trips happen on their own schedules.
- **Reactions to the world:** a failed harvest, a dangerous predator nearby or bad weather changes what they do.

## Gym leaders and notable NPCs

Gym leaders are people first. A leader may be at the gym, at home, out training, away on a trip or visiting another region.

- **No guaranteed availability.** If the leader is away, the player can wait, ask townspeople, follow a lead, or travel to find them.
- **Challenges happen when both sides are around.** Leaders can also be challenged in the wild, on the road or at a friend's place.
- **They talk about each other.** One leader may be out visiting another, which feeds the reputation and badge-recognition lore.
- **Others fill in.** A gym staff member can say where the leader went, or when they usually return.
- Their absence is never a bug or a gate. It is just life.

## Information flow

Since NPCs move, the player finds them through the world:

- Townspeople and neighbors know routines and say things like "she usually goes fishing at dusk."
- Notes, tracks and signs show who passed through.
- Shopkeepers and innkeepers hear news and pass it on.
- A traveler in one region may mention someone in another.

## NPCs and Pokemon

- NPC Pokemon eat, rest and recover like the player's.
- NPC trainers can encounter and battle wild Pokemon, and lose.
- NPC Pokemon can be tracked individuals just like wild ones (open question below).
- NPCs can become part of ecosystem events: visiting groves, driving off predators, or getting hurt and needing help.

## Engine reality check

Emerald's NPCs are fixed object events with simple movement types. Autonomy needs custom code:

- **On-screen:** real pathing between a few points of interest, driven by time of day and current goal.
- **Off-screen:** NPCs are updated in bulk when the player changes maps or time passes, using a coarse state (location, activity, hunger) instead of live movement.
- **Importance tiers** control cost: major NPCs (leaders, rivals, shopkeepers) get full state, minor ones get simple loops.
- **Save space:** a small record per tracked NPC (location, activity, state). Budget must be measured in the repo.

## Open questions

- How many NPCs get full autonomy versus simple loops.
- Whether NPCs can leave their region and how that is tracked.
- Whether NPC Pokemon are individually tracked.
- How the player gets notified of notable NPC events when far away.
