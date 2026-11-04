# Technical feasibility audit — initial repository inspection

**Date:** 2026-11-04  
**Status:** SOURCE-INSPECTED, NOT BUILT OR RUNTIME-TESTED  
**Baseline commit:** `173dd8b43b9c578c68792b3cab9ee6eae1c8587c`  
**Scope:** Actual fork source and configuration; this is not a claim of functional living-world implementation.

## Confirmed source facts

| Area | Evidence | Implication |
|---|---|---|
| Toolchain | `.github/workflows/build.yml` uses ARM GCC/binutils, Python, libpng and `make`; Emerald/FRLG/test jobs are defined | Build pipeline exists; no successful run verified in this audit |
| Species | `include/config/species_enabled.h`: `P_GEN_1_POKEMON` through `P_GEN_9_POKEMON` all `TRUE` | Broad generation support configured; exact species count/ROM fit not measured |
| Visible Pokémon graphics | `include/config/overworld.h`: `OW_POKEMON_OBJECT_EVENTS TRUE` | Necessary sprite infrastructure enabled |
| Generated overworld wild encounters | `include/config/wild_encounter.h`: `WE_OW_ENCOUNTERS FALSE` | Built-in encounter system exists but is currently off |
| Vanilla random encounters | `WE_VANILLA_RANDOM TRUE` | Existing random encounters remain on |
| Overworld graphics compression | `OW_GFX_COMPRESS TRUE` | OWE config warns about VRAM pressure; compare compression modes |
| Overworld encounter code | `src/wild_encounter_ow.c` exists | Inspect/reuse before writing new spawn and battle-transition code |
| NPC followers | `include/config/follower_npc.h`: `FNPC_ENABLE_NPC_FOLLOWERS FALSE` | Optional feature, not active |
| Map data | `data/maps/` lists 941 entries (includes non-playable metadata entry) | Numerous existing maps; does not establish capacity for 14 custom regions |
| Map structures | `include/global.fieldmap.h` defines `MapLayout`, `MapEvents`, `MapConnection` and object-event templates | Supports map-based geography; actual dynamic map/object ceilings unmeasured |
| Save config | `include/config/save.h`: all `FREE_*` reclaim toggles are `FALSE` | Optional save-space reclamation exists, but no free-byte amount established |
| Save structure audit | `design/root/save-budget.md` records sector containers and compile-time asserts | Container capacities are **not** unused capacity |
| Build results | GitHub Actions runs query returned no runs in the first response | Build success **not verified**; do not infer a successful ROM |

## Immediate engineering implications

1. **Do not rewrite overworld encounters first.** Inspect `src/wild_encounter_ow.c`, enable `WE_OW_ENCOUNTERS` on a controlled test branch, and test sprite/VRAM behavior.
2. **Retain traditional battle compatibility.** Verify generated overworld Pokémon initiate and return from battles correctly; then identify extension points for observing, feeding and identity reconciliation.
3. **Measure rather than guess.** Compile the exact fork and collect linker ROM/EWRAM/IWRAM usage, object-event occupancy, and `sizeof` save structures.
4. **Do not confuse feature flags with complete functionality.** Generation toggles and sprite infrastructure are evidence of available code paths, not proof of performance, content coverage or living-world AI.
5. **Separate baseline from custom work.** Existing Expansion mechanics are foundation; independent ecology, tiered individual persistence, autonomous NPC lives and world simulation still need implementation.

## Test sequence and acceptance

### Gate A — reproducible baseline
- Compile unchanged fork with documented toolchain; record exact commit, flags, ROM size and linker memory usage.
- Run smoke test in a GBA emulator, including movement, ordinary wild battle and save/load.
- Record pass/fail and actual build log, not inferred success.

### Gate B — existing OWE system
- Enable `WE_OW_ENCOUNTERS` in an isolated branch; compare `OW_GFX_COMPRESS` settings.
- Verify Pokémon appear, move, engage, flee and resolve a traditional battle without crashes.
- Count simultaneous active objects, sprites and memory use; repeat across map transitions.

### Gate C — persistence
- Measure `SaveBlock1`, `SaveBlock2`, `SaveBlock3`, `PokemonStorage` with concrete build settings.
- Prototype one persistent notable wild Pokémon through unload/reload/save/load/capture.
- Assert one canonical identity, no duplication or unintended disappearance.

### Gate D — first living-world slice
- Compact Meadowmere map and one connected route.
- At least one observable wild Pokémon, a meaningful noncombat interaction, one battle/capture, one independent NPC, and a save/reload check.
- Demonstrate more than one legitimate player path without a compulsory badge.

## Open blockers

- No reproducible build and runtime report yet.
- Exact free save bytes and RAM/VRAM headroom unknown.
- Max practical simultaneous wild/NPC objects unknown.
- Real OWE battle lifecycle and integration seams not yet traced.
- Species count and sprite asset completeness not yet verified.

**Next action:** execute Gate A, then Gate B. Do not promise all 14 regions or the full ecosystem before those results exist.
