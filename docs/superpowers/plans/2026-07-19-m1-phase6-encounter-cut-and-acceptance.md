# M1 Phase 6: Encounter Cut & Slice Acceptance Implementation Plan

> Inline execution (as prior phases). Final M1 phase — closes with the M1
> completion report to Jay carrying the two batched design questions from
> phase 5 (lab frame↔species binding when choice is free; who battles the
> Machop bout).

**Goal:** the spec's "no wild battles exist anywhere else" law enforced
engine-wide, the Route 103 scenarios re-routed from the lab spawn, and the
full §7 vertical slice proven end-to-end headlessly — M1 done.

**Tasks:**
- **T1 Encounter cut (global law, not per-map surgery):**
  `HABITAT_NO_WILD_ENCOUNTERS` in `include/config/habitat.h` (default TRUE);
  early-return gates in `StandardWildEncounter`, `SweetScentWildEncounter`,
  and the fishing path in `src/wild_encounter.c` (model on the existing
  `sWildEncountersDisabled` short-circuit). The Deoxys exception (§ endgame)
  is a scripted battle, not a wild roll — unaffected. Native test: force an
  encounter roll on grass with the flag on → no battle. Wild encounter JSON
  stays untouched (it's upstream data; the gate is ours).
- **T2 Scenario re-route:** Skitty and Machop scenarios walk from the lab
  spawn (6,10) → Littleroot → Route 101 → Oldale → Route 103 using the
  phase-5 walk/until-map ops. Known interceptor (verified in map.json):
  Route 101's Birch-rescue coord triggers at (10,19)/(11,19) fire when
  `VAR_ROUTE101_STATE`==1, and OnFrame advances 0→1 on entry — slice init
  must set the var past the rescue (`VarSet(VAR_ROUTE101_STATE, 3)` — the
  vanilla post-rescue value, confirmed in scripts.inc:237 and debug.inc)
  and FlagSet
  `FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE`, `_ZIGZAGOON`,
  `_BIRCH_STARTERS_BAG` (ambient NPCs stay; renovation is Jay's map pass).
  Oldale swept: rival triggers key on `VAR_OLDALE_RIVAL_STATE`==1 (never
  set in-slice) and the (0,10) BlockedPath guards the west exit only — the
  south→north walk is clean. Route 103 has no coord triggers. Keep one shared
  `SCRIPT_TO_R103` prefix so all Route 103 scenarios reuse the same legs.
- **T3 Acceptance circuit (§7 proof, per the M1 plan):**
  1. Lab: place campfire → Torchic home → recruit (existing lab scenario).
  2. Grove: Torchic tends its plot; RTC reconcile ticks growth; harvest
     Leppa-line evidence via plot inspect (growth uses hours — use RTC
     offset, not real waiting).
  3. Route 103: Skitty loop (place doll → offer Persim → befriended);
     Machop bout click-through in-game (headless battle win), auto-befriend.
  4. Conditions breadth: Lotad (rain + resident Treecko + Cheri zone 1) and
     Heracross (resident Pinsir + night via RTC + mature Leppa tree) — these
     may run as native-test proofs + targeted scenario spot-checks rather
     than one mega-scenario if the walk legs get fragile; the law is that
     every §7 chain is proven somewhere headless.
  5. Scavenge finds: pick up one find (bookshelf) and place it at the
     Treecko frame → STIRRING advances (proves scavenge-and-place).
- **T4 Grove click-through:** in-game plot inspect / worker talk / harvest
  dialogues verified in the lab scenario's Grove leg (phase 4 debt).
- **T5 Gates & close:** full `make check`; EWRAM headroom check; CHANGELOG;
  merge `m1-phase6-acceptance` → main; M1 completion report under
  `docs/reports/` with the batched questions; memory update.

**Self-review:** no wild battles ✓ (engine law, reversible constant);
nothing-missable untouched ✓; no content authored beyond slice ✓; party
layer untouched ✓; Route 103 map-budget overage already tracked as Jay's
renovation pass ✓.
