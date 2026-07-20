# Lab Habitat Bays Design

**Date:** 2026-07-20  
**Status:** Approved direction; pending written-spec review

## Problem

The professor's lab currently exposes three habitat interactions without drawing
the habitat frames described by the canonical opening. The map object at each
coordinate is reserved for the eventual resident Pokémon and remains hidden
until the spot activates. As a result, the player sees no placement target.
When the first resident appears, its current north-wall position overlaps the
lab's foreground furniture tiles, making the sprite read as part of a cropped
bookshelf.

The opening must instead communicate three habitat footprints from the moment
the player enters the lab. The first must visibly contain Birch's retained
furnishings and one open slot; the other two must read as empty versions of the
same structure.

## Chosen Layout

Rearrange the lab with existing, repository-native lab tiles. Three shallow,
equal-width habitat bays occupy the back half of the room. Each bay has:

- a visible floor boundary that distinguishes it from ordinary walking space;
- a clear entrance facing the room's central aisle;
- a single interaction coordinate at that entrance;
- an unobstructed resident position inside the boundary; and
- no foreground metatile between the camera and the resident's lower body.

The initially furnished bay contains the canonical PC, bookshelf, and Pokéball
holder, arranged around one conspicuously empty furnishing position. The two
remaining bays use the same footprint with their furnishing positions empty,
so their silhouette teaches what is missing. Existing lab furniture and
machinery move to the side walls as needed. The entrance, central aisle, and
route between all three interactions remain at least one tile wide.

This design deliberately uses existing tiles rather than introducing temporary
custom habitat art. It fixes the presentation bug without creating new art or
provenance debt, and it leaves custom frame art as a later polish option.

## Runtime Behavior

The habitat state machine and save format do not change. The three background
events continue to address the same spot IDs, and the three variable object
events continue to render only the resolved resident species.

Map coordinates change together as one layout contract:

1. Each background event moves to its bay entrance.
2. Each resident object moves to the bay's unobstructed center.
3. The object event remains hidden while the spot is dormant or stirring and
   becomes visible under the existing active/home-by-default rules.
4. Interacting from the aisle inspects or completes the corresponding bay; the
   player does not need to guess which floor tile is active.

The furnishing choice remains permanent after completion. Existing saves keep
their selected starter, spot states, furnishings, and residents because none of
those records store lab coordinates.

## Interaction Feedback

The layout is the primary affordance: three repeated footprints and one visible
empty position explain where habitats belong without a tutorial overlay. The
interaction text should name the target as a habitat bay or open furnishing
position wherever existing approved text already permits it. This map fix does
not invent replacement narrative prose; any unapproved wording remains under
the existing narrative-content gate.

## Constraints and Failure Handling

- All bay entrance and resident coordinates must be walkable and in bounds.
- No entrance may overlap a warp, another background event, or an object event.
- No resident may spawn on an impassable or foreground-occluded metatile.
- The player must always be able to reach the lab exit after any starter choice.
- All three choices must resolve into their own bay without changing the other
  two spots.
- The design must fit the existing object-event budget and add no persistent
  state.

If the existing tileset cannot produce a complete decorative outline, clarity
takes precedence over ornament: use a repeated floor pattern with open fronts
rather than add placeholder custom graphics.

## Verification

Automated checks will cover:

- all three background-event coordinates matching the intended spot wrappers;
- all three object-event coordinates being distinct from their interaction
  coordinates and from foreground furniture;
- unchanged spot IDs, graphics variables, flags, and save behavior;
- each furnishing choice still resolving to Torchic, Treecko, or Mudkip; and
- the existing Habitat native test suite remaining green.

Fresh emulator captures will cover:

- a new-game lab view where all three habitat footprints are visible;
- the first bay before selection, with one obvious open furnishing position;
- Torchic, Treecko, and Mudkip each fully visible in the completed bay;
- the central aisle and exit remaining navigable; and
- dormant remaining bays continuing to read as placement targets after the
  first habitat completes.

The previous captures showing a resident merged with the north-wall bookshelf
are the failing visual baseline. Acceptance requires that no resident overlaps
or visually merges with lab furniture at native GBA resolution.
