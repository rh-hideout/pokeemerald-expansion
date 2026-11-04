# Traversal

Ledges are no longer one-way drops. The player can climb, trek and cross terrain, often with the help of their Pokemon. How you get through the world is part of the exploration.

## Core principles

1. **Ledges become climbable.** What used to be a one-way hop is now a route you can go up or down.
2. **Pokemon are partners in movement.** Traversal depends on who is in your party and how they are doing.
3. **Terrain has cost.** Climbing, swimming and trekking use stamina and food (see `survival.md`).
4. **Discovery, not unlocks.** The player learns what each Pokemon can do by trying, not from story gates.
5. **Safe by default.** Gentle terrain needs no special help. Harsh terrain demands preparation.

## Climbing and trekking

| Terrain | How the player gets through |
|---|---|
| **Low ledges** | Walk or hop up and down freely |
| **Steep slopes and cliffs** | Climb by hand (slow, tiring) or with a Pokemon's help (faster, safer) |
| **Rock faces** | Climbers (for example Fighting, Rock, Bug types) can haul the player or find holds |
| **Rivers and waterfalls** | Swimmers carry the player across, strong swimmers can climb falls |
| **Chasms and gaps** | Flyers glide the player across, or the player builds or finds a crossing |
| **Dense growth** | Cutters, fire users or large Pokemon clear a way, or the player squeezes through slowly |
| **Mud, snow, sand, ice** | Terrain slows or slides the player, and some Pokemon handle it better |

## Pokemon as partners

- Each species has natural traversal traits (strength, climbing, swimming, flying, burrowing, squeezing).
- A Pokemon only helps if it is **fed, rested and willing**. A tired or hungry partner may refuse.
- Bigger and stronger Pokemon carry more risk and more reach. Smaller ones fit tight spots.
- Helping with traversal builds trust, and trusted Pokemon take on harder routes.
- The party's makeup shapes which routes feel easy, so different teams explore the same map differently.

## Stamina and trek cost

- Climbing and trekking use a stamina state for the player (and for Pokemon doing the work).
- Rest at camps, shrines and safe spots to recover.
- Food restores stamina, tying traversal into the survival system.
- Overreaching has consequences: slipping, backtracking, or collapsing from exhaustion. It never costs the save.

## Map design implications

- Maps are **layered vertically**: ledges, terraces, canopies and cliffs create elevation levels the player can move between.
- Routes branch by **how you travel**: an easy long way around, or a hard direct climb.
- Hidden spots reward climbing: ledge tops, cliff caves, canopy platforms.
- Visual cues show what is climbable (handholds, ropes, roots, slopes).
- Dense detail from `exploration.md` applies vertically too, so each level has something to find.

## Engine notes

- pokeemerald handles ledges as one-way tile behaviors with elevation levels.
- Climbing needs new tile behaviors, new player states and animations, and elevation transitions.
- Pokemon-assisted traversal needs a field-action system that checks the party member's species, hunger, trust and state.
- Per-map elevation and event limits must be checked in the repo before layouts are designed.

## Open questions

- The exact set of traversal traits and which species have them.
- How stamina is shown (bar, states or none).
- Whether the player can climb unaided on every slope or only on some.
- How Pokemon-assisted traversal is triggered (menu, contextual prompt or automatic).
