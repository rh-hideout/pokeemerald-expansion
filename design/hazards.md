# Hazards and Natural Placement

Balance comes from the world pushing back, not from artificial limits. Pokemon appear where they naturally live, and the environment itself is the counterweight to powerful travel methods.

## Natural placement first

- **Pokemon live where their biology says they should.** Habitat, diet, climate, territory and food supply decide placement, never a rarity quota.
- **Rarity is a result, not a setting.** A species is rare because its habitat is small, its food is scarce, its young rarely survive or it needs unusual conditions. It is not rare because a table says so.
- **Good mounts are rare by nature.** Strong flyers nest on cliffs and storm peaks, big swimmers live in deep water, and fast runners range over wide plains. They are hard to find because they live in hard places.
- **No exceptions for convenience.** If the player needs a mount, they find one the way they find anything else: by exploring, observing and earning trust.
- Ecosystem rules apply to mounts too: they are tracked individuals that eat, move and get hurt.

## Environmental hazards

Hazards belong to terrain, weather and wildlife. They hit every traveler, with or without a Pokemon. Telegraphing rules still apply, so the player can read most of them before they strike.

### Air

| Hazard | Effect |
|---|---|
| **Hostile flyers** | Territorial birds and aerial predators attack riders in their range, especially large visible mounts |
| **Storms and lightning** | Reduce control, drain stamina fast, may force a landing |
| **Strong winds and downdrafts** | Push the mount off course, or pull it toward the ground |
| **Thin air at altitude** | Faster stamina drain above certain heights |
| **Fog and cloud banks** | Hide terrain and make landing blind |

### Water

| Hazard | Effect |
|---|---|
| **Whirlpools** | Pull riders in, spin them around, cost stamina, can strand them |
| **Strong currents and rapids** | Carry the mount downstream, make upstream travel slow |
| **Cold water** | Drains stamina and affects some species badly |
| **Deep-sea predators** | Hunt large mounts far from shore |
| **Storm swells** | Shake control, risk dumping the rider |

### Land and cliffs

| Hazard | Effect |
|---|---|
| **Loose rock and crumbling ledges** | Break underfoot and cause falls |
| **Slippery surfaces** | Wet rock, ice and mud cause slips and slides |
| **Rockfalls and landslides** | Triggered by weather, creatures or climbing too hard |
| **Thin ice and sinking mud** | Trap or drop the traveler |
| **Heat, toxic air and cold** | Drain stamina and affect Pokemon and the player |
| **Hostile wildlife in territory** | Chase, ambush from above, or defend nests |

## What happens when things go wrong

- **Falls:** a short drop costs stamina and may scatter dropped items. Longer falls hurt the player and Pokemon. They never end the save.
- **Mount trouble:** a hit or an overwork can make the mount panic, slow down, or force the player off. At altitude or at sea, this is serious.
- **Recovery:** the player and Pokemon recover at camps and with food. Lost items can sometimes be found where they fell.
- **Learning:** the world teaches. Repeated trouble in one place tells the player to avoid it or prepare.

## Telegraphing

- Dark clouds, rising wind and distant thunder before storms.
- Ripples and foam before whirlpools, eddies near rapids.
- Cracks, loose gravel and falling pebbles before rock slips.
- Feathers, nests and high-pitched calls near hostile flyers.
- Fleeing Pokemon and sudden silence for anything big nearby.

## Balance summary

| Power | Natural counter |
|---|---|
| Flying | Hostile flyers, storms, wind, altitude, stamina |
| Swimming and riding on water | Whirlpools, currents, cold, deep predators |
| Climbing | Crumbling rock, slips, rockfalls, stamina |
| Land riding | Terrain, wildlife, rough ground, stamina |
| Strong mounts | Natural scarcity, upkeep, visibility to predators |

## Engine notes

- Most hazards are map events or tile behaviors triggered by position, weather and time.
- Whirlpools, slips and falls need new player and mount states with animation.
- Hostile flyers and aquatic predators use the same wild Pokemon behavior system from the ecosystem design.
- All hazards need testing so they feel fair, not random.

## Open questions

- How hazards scale with region danger level.
- How the player's stamina and health are shown during hazards.
- Whether Pokemon in the party can warn the player or help avoid hazards.
