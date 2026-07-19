# M1 Phase 4: The Grove Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: superpowers:subagent-driven-development or superpowers:executing-plans. Inline execution (serial/stateful, as prior phases).

**Goal:** Spec §3/§4/§7's Grove, small: 3 plots on the Littleroot placeholder map, diegetic worker assignment (talk to a resident at home → it comes; talk at the Grove → it rests/harvests), the two-rule berry economy (workers grow their type's berry — Torchic→Leppa proves it), six-out enforcement, and home/out sprite sync completing §3's home-by-default law.

**Architecture:**
- **Map:** Littleroot Town is the Grove placeholder (it hosts §10's lab, so phase 5's spawn-move lands here). Plot markers are map-template objects; **worker sprites are runtime-spawned** (`SpawnSpecialObjectEventParameterized` with species gfx — only 4 var-gfx slots exist, six-out needs 6, and followers prove the programmatic path).
- **Save (§5 envelope):** `struct HabitatPlot { u16 berryItem; u8 growthStage; u8 worker1, worker2; u8 flags; u16 hoursProgress; }` ×12 (96 B) + one u32 last-tick RTC-minutes stamp → SaveBlock3 720→820 B (guard updated with measured value). Registry `assignment` byte: 0 = home, 1..12 = working plot N; "out" ≡ assignment ≠ 0; six-out counts it.
- **Growth:** event-driven only — each TIME_TICK hour credits `hoursProgress` on plots with ≥1 worker; map-load reconciles offline hours from the RTC stamp. Stage = progress / `HABITAT_PLOT_HOURS_PER_STAGE` (config, 4) capped at `HABITAT_PLOT_STAGE_MATURE` (4). Harvest yields `HABITAT_PLOT_YIELD` (3) of the plot's berry, resets progress. Plot berry = worker's **primary-type** berry from the §4 table (18-entry const, Sleep-verified) — dual-type default per the recast note.
- **Dialogue register (§7 feel target):** species voice + *italic narrator* placeholder lines; contextual prompts only (assignment offered only to befriended residents at home; rest/harvest only where applicable). Prose is Jay's to rewrite.
- **Verification split (honest):** all logic native-tested (assignment, six-out, growth math, reconcile, harvest, type→berry, home/out visibility). In-game Grove click-through lands with phase 5's spawn-move to Littleroot (cross-map `goto` pathing doesn't exist yet); Route 103 scenarios must stay green this phase.

## Tasks
- **T1 Save + assignment:** config counts, HabitatPlot array + stamp in save.h, accessors + `Habitat_AssignResidentToPlot / Habitat_SendResidentHome / Habitat_ResidentIsOut / Habitat_OutCount` (six-out refusal), guard test update, native tests.
- **T2 Growth + economy:** `sTypeBerryTable[18]`, `Habitat_BerryForSpecies(species)` (primary type), `Habitat_TickPlots(hours)`, map-load reconcile via RTC stamp, `Habitat_HarvestPlot` (bag add, reset), TIME_TICK wiring in events.c, native tests incl. time-warp reconcile.
- **T3 Home/out sync:** spot visibility subtracts out-residents (BEFRIENDED && !out), spot→resident link via first registry match on species (slice-sufficient; noted), tests.
- **T4 Grove presence:** Littleroot map objects (3 plot markers), `Habitat_SyncGroveWorkers` (spawn/remove worker objects on map load/assignment change), interact scripts + specials: plot inspect/harvest, worker rest dialogue, home-spot assignment prompt appended to the BEFRIENDED ambient path; placeholder species-voice text.
- **T5 Gates:** `TESTS='Habitat'`, both Route 103 scenarios, full suite, EWRAM, CHANGELOG/docs, merge.

## Self-Review
§7 slice-Grove scope only (3 plots, dialogue assignment, Torchic→Leppa; pair-recipe stretch deferred) ✓; §3 six-out + home-by-default completed ✓; §4 two rules as engine data with the verified table ✓; no hint NPC/Groupon/board (not in slice systems list) ✓; feel target honored as placeholder register ✓; nothing invalidates Route 103 scenarios ✓.
