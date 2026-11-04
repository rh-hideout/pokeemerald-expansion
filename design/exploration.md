# Exploration

The world is wide but dense in detail. No corner is filler. Every stretch of map has something that makes the player stop, look and wonder. Exploration is the main game, and nothing is gated by story.

## Core principles

1. **Wide and dense.** Large regions, but no empty space. Distance is made interesting, not skipped.
2. **Everything is quirky.** Odd places, strange customs, unexpected creatures. Nothing is a copy of an expected Pokemon trope.
3. **Discovery over direction.** No quest markers, no forced path. The world rewards curiosity.
4. **Every region feels different** in terrain, rules, culture, sound and pace.
5. **Safe by default, dangerous by choice.** The player can wander comfortably or push into harsh zones.

## The density rule: something every stretch

No long walk without a reason to look around. Every few screens should offer at least one of:

- A **curiosity**: an odd structure, an unusual creature behavior, a strange sound.
- A **trace of life**: tracks, a camp, a half-finished meal, a lost item, a note.
- A **choice**: a branching path, a hidden door, a risky shortcut.
- A **resource**: berries, ingredients, a fishing spot, a rare plant.
- A **story fragment**: a ruin, a mural, a gravestone, an NPC's offhand remark.

If a stretch has none of these, it gets one or gets cut.

## Layers of discovery

| Layer | What the player finds |
|---|---|
| **Surface** | Towns, routes, visible landmarks, obvious paths |
| **Hidden** | Secret nooks, side caves, tide-only paths, behind-the-waterfall spots |
| **Conditional** | Things that only appear at night, in storms, in certain seasons, or after an event |
| **Lore** | Ruins, notes, NPC stories, patterns the player pieces together |
| **Emergent** | Things that happen because of the ecosystem and living NPCs, never the same twice |

## Making every region quirky

Each region gets one **defining quirk** that changes how exploration feels, for example:

- A region where the **landscape shifts** (tides, shifting sands, drifting fog).
- A region where **travel is vertical** (climbing, gliding, descending).
- A region where **sound or light** is the guide (echoes, glowing paths).
- A region with **odd local customs** that change how NPCs and trade work.

Quirks are set per region when each one is designed in detail.

## Movement and traversal

- Traversal methods are discoveries, not unlocks behind story: climbing, swimming, gliding, riding, boats, tunnels.
- Fast travel exists only between camps and safe places, and is limited so distance stays meaningful.
- Terrain matters: mud slows, ice slides, dense growth hides things, wind carries.
- Time and weather change the world's face, so the same place can feel new on a second visit.

## Navigation without hand-holding

- No quest markers. Direction comes from NPC hints, landmarks, tracks and the player's own notes.
- The player's map fills in as they explore.
- Landmarks are visible from far away so people can orient themselves.
- Locals give directions in their own way, which can be vague, quirky or misleading.

## Pace and rest

- Regions alternate between **open, calm stretches** and **dense, tense pockets**.
- Camps, shrines and small towns give frequent safe stops.
- The player always controls how fast they go.

## Content budget

Density makes maps costly. To keep scope manageable:

- Prefer **smaller, richer maps** over big empty ones.
- Reuse tile sets within a region, but change layout, color and props per sub-area.
- Generate quirks through **systems** (ecosystem, NPC life, weather, time) as much as hand-placed content.
- Build in phases: one region at a time, fully dense, before the next.

## Engine notes

- Hidden and conditional areas use existing flag and variable checks.
- Time and weather already exist in pokeemerald and can gate visibility of events.
- Traversal abilities need custom field effects. Some already exist (surf, climbing via ledges) and can be expanded.
- Map size and event limits per map must be checked against the engine's per-map caps.

## Open questions

- The defining quirk of each of the 14 regions.
- Which traversal methods exist and how the player acquires them.
- How the player's map and notes work (auto-filled, hand-drawn or both).
- How many hidden and conditional areas fit per region within ROM limits.
