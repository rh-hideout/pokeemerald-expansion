# M1 Phase 5: Lab Opening & Slice Wiring Implementation Plan

> Inline execution (as prior phases). Two design questions ride as loud placeholders (batched for Jay): the lab frame↔species binding model when the player chooses freely (dev config pins Torchic, so the slice path is unambiguous), and who battles the Machop bout (party deferred — placeholder: the first resident steps up; refused with placeholder text when no residents exist).

**Goal:** §10's lab opening playable (place the campfire → Torchic comes home → recruit to the Grove), the Machop bout closing `BATTLE_WIN`, scavenge finds on Route 103, spawn moved to the lab, and the scenario DSL walking across maps — leaving phase 6 only the encounter cut and the full acceptance circuit.

**Tasks:**
- **T1 Furnishing items:** 6 new items (`ITEM_HH_CAMPFIRE`, `_POTTED_PLANT`, `_WATER_BASIN`, `_LAB_PC`, `_BOOKSHELF`, `_POKEBALL_HOLDER`), Items pocket, placeholder icon/descriptions.
- **T2 Multi-item placement:** placed-counter slots become per-(spot, condition-index); `Habitat_TryPlaceItem` places the first unsatisfied `COND_ITEM_PLACED` whose item is in the bag; `COND_ITEM_PLACED` reads its own slot by list position. Bare lab frames need distinct furniture sets; §2's water-bottles example always implied this. Native tests.
- **T3 Lab spots + spawn:** spots 7/8/9 in the professor's lab (Torchic: campfire [furnished frame]; Treecko: potted plant + bookshelf; Mudkip: water basin + lab PC + Pokéball holder) — **empty befriend lists**: the engine's offer-less rule makes starters "come home" on completion (§10 reading). Frame objects + signs in the lab map; spawn → lab interior; kit = 3 element items (+ doll/honey/Persim for Route 103); hide Birch/aides in the lab (abandoned fiction); zone 2 = lab.
- **T4 Machop bout:** ACTIVE Machop's verb prompt becomes a bout offer; script runs a scripted wild battle (`setwildbattle`/`dowildbattle`), win sets `HABITAT_SPOT_LOCAL_BATTLE_WON` via special → recompute auto-befriends (existing machinery). Battler = temp party mon from the first resident, removed after; no residents → refusal text.
- **T5 Scavenge finds:** bookshelf / lab PC / Pokéball holder as item-ball objects on Route 103 (proves scavenge-and-place in-slice).
- **T6 Scenario DSL + gates:** new ops `walk:DIR,N` (blind steps) and `until-map:G,N`; lab scenario (place campfire → Torchic manifests+auto-befriends → recruit → worker visible at Grove — screenshots); keep/adapt Route 103 scenarios (spawn changed: route to 103 via walks); full suite; CHANGELOG; merge.

**Self-review:** §10 lab-in-slice ✓ (choice model flagged, dev-pin path exact); §7 systems: lab slot choice ✓, battle-as-condition ✓, scavenge-and-place ✓, home-by-default render on a lab frame ✓; nothing-missable honored (finds respawn-free but ever-present until taken) ✓; party layer untouched ✓.
