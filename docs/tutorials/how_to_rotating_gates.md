# How to Use Rotating Gates

Rotating gates are map objects that provide the affine graphics and collision.
They are used in vanilla Emerald by the Fortree Gym and Trick House puzzles. 
They now activate automatically:
no map script, special, variable, or flag setup is required.

## Placing a gate in Porymap

Add an object event and choose one of these graphics IDs:

- `OBJ_EVENT_GFX_ROTATING_GATE_L1`
- `OBJ_EVENT_GFX_ROTATING_GATE_L2`
- `OBJ_EVENT_GFX_ROTATING_GATE_L3`
- `OBJ_EVENT_GFX_ROTATING_GATE_L4`
- `OBJ_EVENT_GFX_ROTATING_GATE_T1`
- `OBJ_EVENT_GFX_ROTATING_GATE_T2`
- `OBJ_EVENT_GFX_ROTATING_GATE_T3`
- `OBJ_EVENT_GFX_ROTATING_GATE_T4`

Place the object where you want it.
Set the movement type to choose the starting orientation:

| Movement type | Starting rotation |
| --- | --- |
| `MOVEMENT_TYPE_NONE` | Down / 0 degrees |
| `MOVEMENT_TYPE_FACE_DOWN` | Down / 0 degrees |
| `MOVEMENT_TYPE_FACE_RIGHT` | Right / 90 degrees clockwise |
| `MOVEMENT_TYPE_FACE_UP` | Up / 180 degrees clockwise |
| `MOVEMENT_TYPE_FACE_LEFT` | Left / 270 degrees clockwise |

Other movement types are invalid. Debug builds report an assertion; release
builds recover by using the down-facing orientation.

Note that rotating gates utilise 4 graphical frames, meaning that the default
Porymap settings will use a hflipped left facing gate for the right facing value.
This can be amended in the Porymap settings (coming soon).
Also note that gates are slightly misalligned in Porymap and actually appear 8px
to the left in-game comparitively (potential fix soon).

## Important limitations

Rotating-gate objects are always-active puzzle geometry, not normal object
events. The following standard object fields are intentionally ignored:

- elevation
- movement ranges
- trainer type
- script
- flag

The trainer range field is reserved for private rotating-gate state in the
runtime copy of the template. Its authored value is ignored and overwritten on
a fresh map load. The ROM map template and the template's `filler` field are
left untouched.

Gate markers do not consume normal object-event slots. Their orientation is
kept in the trainer range of the runtime map object template, so it survives
battles and menus without reserving temp variables, heap memory, or EWRAM. 
Loading another map resets the new map's gates to their default orientations.

## Graphics resource limits

The engine loads only the gate shapes used by the current map. Each visible
gate still needs one sprite slot and one OBJ affine matrix, and each used shape
needs OBJ tile VRAM. The GBA provides 32 OBJ affine matrices; see
[Tonc's affine object documentation](https://www.coranac.com/tonc/text/affobj.htm)
for the hardware model and center-based affine transformation behavior.

If a sprite slot, tile allocation, or affine matrix is temporarily unavailable,
the gate remains solid and its graphics are retried during a later viewport
update. Avoid designing a view that requires more affine sprites or tile data
than the rest of the scene can provide.
