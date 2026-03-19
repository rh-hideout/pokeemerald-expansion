# Editor UI Refactor: Semantic Area > NPC > Events Hierarchy

## Current Map Detail Structure (11 flat sections)
1. Map Preview
2. Wild Pokemon
3. Trainers
4. Items
5. Warps
6. Connections
7. NPCs / Objects
8. Dialogue / Text
9. Coordinate Events
10. Background Events
11. Map Properties

**Problem**: These sections are organized by internal data type, not by how a player thinks about a location. Trainers, NPCs, and dialogue are split across 4 separate sections even though they're all "people in this place and what they say."

## New Structure: Area > NPC > Events

### Tier 1: Area (the place itself)
- **Map Preview** - the map image
- **Properties** - music, weather, type, cycling, etc. (moved up - this is "what is this place?")
- **Routes & Doors** - connections + warps merged into one "Navigation" section
  - Subsection: Routes (connections to adjacent areas)
  - Subsection: Doors (warps to buildings/interiors)

### Tier 2: NPCs (who's here)
- **People & Pokemon** - unified section combining current Trainers + NPCs/Objects
  - Each NPC rendered as an expandable card showing:
    - Sprite, name, position, movement type
    - **Nested events** for that NPC:
      - Their dialogue text (pulled from scripts.inc matching their script label)
      - If trainer: party link, sight range, trainer type
      - Their script reference
      - Edit/Delete actions

### Tier 3: World Events (things in the environment)
- **Wild Pokemon** - encounter tables (unchanged)
- **Items** - item balls + hidden items (unchanged, already merged)
- **Signs & Triggers** - merge current "Background Events" + "Coordinate Events"
  - Signs: things you read
  - Step Triggers: things that happen when you walk somewhere

## Additional Player-Friendly Suggestions (included in this refactor)
1. **Rename "Warps" → "Doors"** in the UI (players think of these as doors)
2. **Rename "Connections" → "Routes"** (players think of adjacent areas as routes)
3. **Rename "Coordinate Events" → "Step Triggers"** (what players actually experience)
4. **Rename "Background Events" → "Signs"**
5. **Show NPC dialogue inline** under each NPC instead of in a separate section
6. **Rename "Object Scripts" section** → absorbed into unified NPCs section

## Files Changed
- `editor/app.js` - restructure `renderMapDetail()`, merge sections, add NPC card expansion
- `editor/style.css` - add styles for expandable NPC cards with nested events

## What Does NOT Change
- The underlying `map.json` format (no game data changes)
- The sidebar navigation (Areas / NPCs pages stay)
- The NPC list page (separate from map detail)
- Any save/edit modal logic (just reorganized in the UI)
- The build toolchain (`mapjson.cpp` etc.)
