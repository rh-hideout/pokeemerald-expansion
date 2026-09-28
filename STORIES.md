# Modern FireRed — Implementation Stories

Ordered, self-contained backlog to take this fork of `pokeemerald-expansion` from "vanilla FireRed build" to a **Modern Emerald–equivalent FireRed hack**: a full start-of-run rules/randomizer/challenge engine plus a deep QoL layer, on stock Kanto.

Scope is defined in [`PROJECT.md`](./PROJECT.md). Build and repo rules are in [`AGENTS.md`](./AGENTS.md).

**Source of truth:** `PROJECT.md` defines what is in and out of scope. If a story appears to conflict with it, `PROJECT.md` wins.

**Feature inspiration:** [Modern Emerald](https://github.com/resetes12/pokeemerald) (`resetes12/pokeemerald`). Stories cite ME files as a **spec and reference implementation**. ME's C does not drop into expansion's FireRed build — reuse its algorithms, data tables, option lists, and UX; rewrite the integration.

## How to use this file

- Stories are in **implementation order**. A story's dependencies are always above it.
- Each story is **self-contained**: an agent should be able to pick it up from the story plus the cited files.
- **Each story has a single status marker** as its first bullet. Valid states:
  - `- [ ] **Status:** Not started`
  - `- [ ] **Status:** In progress`
  - `- [x] **Status:** Complete`
- **Milestones table:** a phase is `In progress` once any of its stories leaves Not started, and `Complete` once all its stories are Complete.
- **Implementing stories:** use the `implement-story` skill (`.agents/skills/implement-story/`), which finds the story, builds it against `PROJECT.md` and the conventions below, verifies it in-game, updates status here, and records decisions.
- **Playtesting stories:** use the `test-story` skill (`.agents/skills/test-story/`); it drives local mGBA against `pokefirered.gba` using `docs-mf/manual-qa/S##.md` and reports pass/fail only (no push required).
- **Definition of Done (per story):** acceptance criteria met, `make firered -j$(sysctl -n hw.ncpu)` builds clean with no new warnings, `make check` passes, the ROM boots in mGBA, and any non-obvious decision is recorded in `docs-mf/decisions/` (created in S03).

## Project conventions (apply to every story)

These exist to keep merging from `RHH/master` cheap. Violating them is the main way this project becomes unmaintainable.

- **Namespace everything.** Our configs are `MF_*` in `include/config/modern_firered.h`. Our sources are `src/mf_*.c` / `include/mf_*.h`. Never add a new field to an upstream struct when a new struct will do.
- **Touch upstream files minimally.** Prefer a one-line call into an `mf_` helper over inlining logic into an upstream function. Every upstream edit is a future merge conflict.
- **Never change the Makefile default target.** Always build with `make firered`.
- **Runtime, not compile-time.** ME's options are chosen by the *player* at new game; expansion's equivalents are compile-time `#define`s. Anything the Gamemode/Difficulty/Challenge menus can toggle must resolve through a runtime accessor (S14), not a `#if`.
- **Save compatibility.** Once S12 lands, any change to the rules struct goes through the versioning story (S64) — never silently reshuffle fields.

## Milestones

| Phase | Theme                                | Stories | Status      |
| ----- | ------------------------------------ | ------- | ----------- |
| 0     | Foundation & workflow                | S01–S06 | Complete    |
| 1     | Baseline modernization (compile-time)| S07–S11 | Complete |
| 2     | Rules engine core                    | S12–S17 | Complete    |
| 3     | Rules menu UI                        | S18–S26 | Complete    |
| 4     | Gamemode wiring                      | S27–S32 | Complete    |
| 5     | Features & item-friction wiring      | S33–S34, S69 | Complete |
| 6     | Nuzlocke                             | S35–S39 | In progress |
| 7     | Difficulty                           | S40–S45 | Not started |
| 8     | Challenges                           | S46–S50 | Not started |
| 9     | Randomizer                           | S51–S57 | Not started |
| 10    | Options+ QoL                         | S58–S63 | Not started |
| 11    | Polish, save safety & release        | S64–S68 | Not started |

---

## Phase 0 — Foundation & workflow

> Front-loaded so every later story sits on a reproducible build, green CI, and a merge strategy that survives upstream churn. No feature story should start before Phase 0 is complete.

### S01 — Reproducible FireRed build & toolchain pin

- [x] **Status:** Complete

- **Goal:** Anyone (human or agent) can build the ROM from a clean clone with one documented command.
- **Depends on:** —
- **Scope:**
  - Verify `make firered -j$(sysctl -n hw.ncpu)` produces `pokefirered.gba` from a clean tree on macOS.
  - Pin and document the toolchain: devkitARM version, `agbcc` (if used), Python version (`.python-version` is already present but untracked — decide whether to commit it).
  - Document the Emerald↔FireRed switch hazard (`make clean` between targets) in a `BUILDING.md` or a README section.
- **Acceptance:** Fresh clone → documented command → booting ROM in mGBA, with no undocumented manual steps.
- **Tests:** N/A (tooling). Verified by S02 running the same command in CI.

### S02 — CI green on the FireRed target

- [x] **Status:** Complete

- **Goal:** Every push proves the FireRed build and the test suite still work.
- **Depends on:** S01
- **Scope:**
  - `.github/workflows/build.yml` already has an Emerald `all` job, a `make firered` job, a `leafgreen` job, a `release` job, and a `make check` job. Decide which we keep — carrying jobs we never look at is merge cost for nothing.
  - Make the **FireRed** job the required check. Keep `make check` (currently the Emerald test build; note in the workflow that expansion's test runner targets Emerald).
  - Fail on new compiler warnings in our own `src/mf_*.c` files.
- **Acceptance:** A PR runs the workflow; green on a clean branch, red when the FireRed build breaks or a test fails.
- **Tests:** The workflow itself.

### S03 — Upstream merge workflow & decision log

- [x] **Status:** Complete

- **Goal:** Pulling from `RHH/master` is routine, and past choices are recoverable.
- **Depends on:** S01
- **Scope:**
  - Write `docs-mf/UPSTREAM.md`: how to fetch/merge `RHH/master`, how to handle conflicts in `include/config/*.h` (ours are additive — prefer theirs then re-apply our flips), and a "run this after merging" checklist (`make clean && make firered && make check`).
  - Create `docs-mf/decisions/` with a short ADR template (context / decision / consequences).
  - Use `docs-mf/` (not upstream's `docs/`, which is their mdbook and will conflict).
  - Record ADR-0001: "Runtime rules layer over compile-time expansion configs" — capture the core architectural bet before writing any of it.
- **Acceptance:** A trial merge from `RHH/master` follows the doc end to end and lands green.
- **Tests:** N/A (docs). Validated by performing one real upstream merge.

### S04 — `MF_` config namespace & feature-flag scaffold

- [x] **Status:** Complete

- **Goal:** One obvious place for every Modern FireRed toggle, isolated from upstream headers.
- **Depends on:** S01
- **Scope:**
  - Create `include/config/modern_firered.h` with an `MF_` prefix convention and a version stamp constant.
  - Include it from a single upstream include site (prefer `include/config/general.h` or `global.h`) so one edit reaches everything.
  - Add compile-time master switches so any half-finished subsystem can be disabled: `MF_RULES_ENGINE`, `MF_RANDOMIZER`, `MF_NUZLOCKE`, `MF_OPTIONS_PLUS`.
  - Document the naming rules in `docs-mf/UPSTREAM.md`.
- **Acceptance:** Header exists, is reachable from any translation unit, and toggling a master switch off compiles cleanly.
- **Tests:** Build with each master switch off and on.

### S05 — Debug & fast-iteration harness

- [x] **Status:** Complete

- **Goal:** Testing a rules-engine change should take seconds, not a full playthrough.
- **Depends on:** S04
- **Scope:**
  - Confirm `include/config/debug.h` menus (`DEBUG_OVERWORLD_MENU`, `DEBUG_BATTLE_MENU`) are active in non-release builds and reachable in the FireRed build.
  - Confirm `ENABLE_QUICKSTART` (`include/config/quickstart.h`) works on the FR title screen; document the button.
  - Add an `mf_debug` submenu stub under the existing debug menu — later stories hang rules inspection off it (S17).
  - Document a save-state workflow in mGBA for "just before Oak's speech" so the new-game menu can be re-tested repeatedly.
- **Acceptance:** From a cold boot you can reach the new-game flow and the debug menu in under 15 seconds.
- **Tests:** Manual, documented as a repeatable checklist in `docs-mf/`.

### S06 — Testing bar for rules logic

- [x] **Status:** Complete

- **Goal:** Pure rules logic is unit-tested, so gameplay wiring is the only thing needing manual QA.
- **Depends on:** S04, S02
- **Scope:**
  - Determine how far expansion's `test/` framework (`make check`, `TESTELF`) can cover our code given it targets the Emerald build. Record the finding.
  - Establish where our tests live (e.g. `test/modern_firered/`) and the convention for testing pure helpers (rule accessors, randomizer mapping, BST/level-cap math) independently of the FR-only build.
  - Write one trivial passing test to prove the path works.
  - Define the manual-QA checklist template that gameplay-wiring stories fill in.
- **Acceptance:** `make check` runs our sample test and passes in CI; the manual-QA template is committed.
- **Tests:** The sample test itself.

---

## Phase 1 — Baseline modernization (compile-time)

> This phase deliberately flips expansion configs to **always-on** compile-time defaults. That gets a genuinely modern, playable FireRed early and proves each feature works in the FR build *before* Phase 4 does the harder work of making them player-toggleable. Expect Phase 4 to revisit most of these call sites — that is the plan, not rework by accident.

### S07 — Battle mechanics baseline: phys/spec split, types, type chart

- [x] **Status:** Complete

- **Goal:** Battles use modern mechanics out of the box.
- **Depends on:** S01
- **Scope:**
  - Verify `B_PHYSICAL_SPECIAL_SPLIT` (`include/config/battle.h`, defaults `GEN_LATEST`) is actually in effect in the FireRed build — expansion defaults to Gen 9 but confirm nothing FR-specific overrides it.
  - Verify `P_UPDATED_TYPES` (`include/config/pokemon.h`) and the Fairy type chart are live; Fairy exists as `TYPE_FAIRY` in `include/constants/pokemon.h` with no single on/off macro, so document exactly which configs constitute "Fairy on".
  - Verify `GEN_LATEST` in `include/config/general.h` is the intended baseline; if any Gen 9 mechanic is undesirable for a Kanto game, record the exception in an ADR rather than blanket-downgrading.
  - Spot-check a handful of Kanto-relevant cases in battle: a Fairy-type matchup, a move whose split category changed (e.g. a Dark or Ghost move), and updated type assignments.
- **Acceptance:** Phys/spec split and Fairy typing verifiably affect damage in-game; the exact set of configs constituting the baseline is documented.
- **Tests:** `make check` for expansion's own battle tests; manual battle checks per the S06 template.

### S08 — Species, moves & movepool data availability for the FR dex

- [x] **Status:** Complete

- **Goal:** Know precisely which Pokémon, moves, abilities, and learnsets are available in this build before any randomizer or "modern movepool" work depends on it.
- **Depends on:** S07
- **Scope:**
  - Audit `include/config/species_enabled.h` (`P_GEN_*_POKEMON`) and decide the enabled generation range. `PROJECT.md` says a full National Dex dump is *not* a goal — pick a range and justify it in an ADR. Consider ROM size and build time.
  - Confirm cross-gen evolutions and Kanto-line additions behave sensibly given the chosen range.
  - Produce a short reference doc listing what's enabled, since Phases 4 and 9 both depend on it.
- **Acceptance:** The enabled species/move set is a deliberate, documented decision; ROM builds and boots within acceptable size.
- **Tests:** Build size check; manual dex/summary spot-checks.

### S09 — Summary screen IV/EV display

- [x] **Status:** Complete

- **Goal:** Players can see IVs and EVs without external tools.
- **Depends on:** S01
- **Scope:**
  - Enable `P_SUMMARY_SCREEN_IV_EV_INFO` and related macros in `include/config/summary_screen.h` (currently all `FALSE`); choose between the box-only and always-available variants, and whether to show raw values (`P_SUMMARY_SCREEN_IV_EV_VALUES`).
  - Verify the FireRed summary screen layout — FR's summary UI differs from Emerald's, so the expansion feature may need layout fixes in the FR build.
  - Note: `P_FLAG_SUMMARY_SCREEN_IV_EV_INFO` allows gating on a flag. Leave it at `0` for now; Phase 10 may bind it to an Options+ toggle.
- **Acceptance:** IV/EV info displays correctly and legibly on the FR summary screen with no graphical corruption.
- **Tests:** Manual across several Pokémon; checklist in [`docs-mf/manual-qa-s09-summary-iv-ev.md`](docs-mf/manual-qa-s09-summary-iv-ev.md) (screenshot there when playing). Config lock: `make check TESTS='MF: summary IV/EV'`.
- **Decisions:** [`docs-mf/decisions/0009-ux-summary-iv-ev-display.md`](docs-mf/decisions/0009-ux-summary-iv-ev-display.md) — always-on party+box, raw values, IV/EV tileset; flag left at 0 for Phase 10.

### S10 — Item & progression QoL baseline

- [x] **Status:** Complete

- **Goal:** Remove the most-felt vanilla item friction.
- **Depends on:** S01
- **Scope:**
  - Enable `I_REUSABLE_TMS` (`include/config/item.h`, currently `FALSE`).
  - Decide on Exp Share behavior: `I_EXP_SHARE_ITEM` is `GEN_LATEST` but `I_EXP_SHARE_FLAG` is `0` (disabled). Pick a flag or leave party-wide Exp Share off; record the choice, since Phase 7's EXP multiplier interacts with it.
  - Confirm nature mints exist and are obtainable in the FR build (items and `ItemUseOutOfBattle_Mint` are in `src/data/items.h`, but FR shop/gift placement may differ). Decide where they come from without editing maps or story.
  - Confirm Sitrus behavior (`I_SITRUS_BERRY_HEAL`) and note it as a future Gamemode toggle.
- **Acceptance:** TMs are reusable and survive use; Exp Share and mint decisions are documented.
- **Tests:** Manual: teach a TM twice; checklist in [`docs-mf/manual-qa-s10-item-qol.md`](docs-mf/manual-qa-s10-item-qol.md). Config lock: `make check TESTS='MF: item'`.
- **Decisions:** [`docs-mf/decisions/0010-product-item-qol-baseline.md`](docs-mf/decisions/0010-product-item-qol-baseline.md) — reusable TMs on; Gen5 held Exp Share (no Gen6 flag); mints usable, shop deferred to S34; Sitrus stays Gen4+ 25% (future Gamemode toggle). Solo trade-evo stock/bag-use is **S69**.

### S11 — Battle & overworld speed baseline

- [x] **Status:** Complete

- **Goal:** The game feels fast before any options menu exists.
- **Depends on:** S01
- **Scope:**
  - Tune `include/config/battle.h` speed knobs: `B_FAST_INTRO_PKMN_TEXT`, `B_FAST_INTRO_NO_SLIDE`, `B_FAST_HP_DRAIN`, `B_FAST_EXP_GROW`, and `B_WAIT_TIME_MULTIPLIER` (default `16`; lower is faster). Pick sensible always-on defaults; Phase 10 exposes the rest as player options.
  - Review `include/config/text.h` speed modifiers, including whether to enable `TEXT_SPEED_INSTANT`.
  - Enable `OW_RUNNING_INDOORS` (`include/config/overworld.h`).
  - Confirm `OW_POISON_DAMAGE` behavior and note it as a future Gamemode toggle (ME's "SURVIVE POISON").
- **Acceptance:** A full wild battle completes noticeably faster than vanilla with no animation glitches or softlocks.
- **Tests:** Manual timing comparison; checklist in [`docs-mf/manual-qa-s11-battle-ow-speed.md`](docs-mf/manual-qa-s11-battle-ow-speed.md). Config lock: `make check TESTS='MF: speed'`.
- **Decisions:** [`docs-mf/decisions/0011-product-battle-ow-speed-baseline.md`](docs-mf/decisions/0011-product-battle-ow-speed-baseline.md) — no-slide intro; wait×8; Options text intact; indoor run + Gen5+ poison already on; SURVIVE POISON deferred to S34.

---

## Phase 2 — Rules engine core

> The heart of the project. ME stores its choices as packed bitfields in `SaveBlock1` (see `NuzlockeEncounterFlags[9]` and the `tx_*` bitfields around offset `0x3D88` in ME's `include/global.h`). We build the equivalent for expansion, but the accessor API matters more than the storage: **every later phase reads rules through it.** Get the API right here and Phases 4–9 are mostly mechanical.

### S12 — Rules data model & save storage

- [x] **Status:** Complete

- **Goal:** Player rule choices persist across save/load without breaking existing saves or upstream merges.
- **Depends on:** S04, S06
- **Scope:**
  - Define `struct ModernRules` in `include/mf_rules.h`, covering every option across all six ME pages. Use ME's `include/tx_randomizer_and_challenges.h` as the field checklist (Gamemode, Features, Randomizer, Nuzlocke, Difficulty, Challenges), and pack with bitfields as ME does.
  - Include a `version` field from day one so S64 has something to migrate on.
  - Choose storage and justify it in an ADR. Options: `struct SaveBlock3` (`include/global.h`, documented max **1624 bytes**, and the cleanest low-conflict spot) versus space reclaimed via `include/config/save.h` `FREE_*` macros (up to ~3790 bytes; `FREE_MYSTERY_GIFT` alone is 876). Note that Nuzlocke needs per-mapsec encounter flags and the randomizer may need a stored seed, so budget bytes before choosing.
  - Add a compile-time size assertion so the struct can never silently overflow the save chunk.
- **Acceptance:** Rules write, save, reload, and read back identically; the size assertion holds; a save made before this change still loads.
- **Tests:** Unit tests for pack/unpack round-trips (`make check TESTS='MF: rules'`); manual save→reset→load in mGBA — [`docs-mf/manual-qa-s12-rules-storage.md`](docs-mf/manual-qa-s12-rules-storage.md).
- **Decisions:** [`docs-mf/decisions/0012-tech-rules-save-storage.md`](docs-mf/decisions/0012-tech-rules-save-storage.md) — `SaveBlock3.mfRules` (not `FREE_*` / SaveBlock1).

### S13 — Rule accessor API

- [x] **Status:** Complete

- **Goal:** One tiny, cheap, universally-used way to ask "is this rule on?".
- **Depends on:** S12
- **Scope:**
  - Implement `src/mf_rules.c` with inline-friendly accessors: a boolean getter, a multi-value getter, and typed helpers for the common ones.
  - Performance matters: these get called inside battle and overworld loops. Keep them branch-cheap and header-inlined where sensible.
  - Define and document the **null behavior**: what every accessor returns when `MF_RULES_ENGINE` is compiled out or the save predates the engine. Defaults must equal vanilla-plus-Phase-1 behavior so nothing breaks.
  - Provide the **runtime-gate pattern** that Phase 4 uses to convert a compile-time expansion config into a player-toggleable rule, and document it with a worked example in `docs-mf/`.
- **Acceptance:** Accessors are usable from battle, overworld, and menu code; disabling the master switch compiles and plays as Phase 1 did.
- **Tests:** Unit tests for every accessor including the null/default path (`make check TESTS='MF: rules'`); pattern doc [`docs-mf/RULES_ACCESSORS.md`](docs-mf/RULES_ACCESSORS.md).
- **Decisions:** [`docs-mf/decisions/0013-tech-rules-accessor-null-defaults.md`](docs-mf/decisions/0013-tech-rules-accessor-null-defaults.md).

### S14 — New-game initialization & Classic/Modern/Custom presets

- [x] **Status:** Complete

- **Goal:** A new game starts with a coherent, complete rule set even if the player never opens the menu.
- **Depends on:** S13
- **Scope:**
  - Hook rules initialization into `NewGameInitData()` (`src/new_game.c`) so rules are always valid before any gameplay code reads them.
  - Implement the three Gamemode presets from ME: **Classic** (vanilla-like), **Modern** (modernized), **Custom**. Define exactly which rules each preset sets — this is a product decision, so record it in an ADR with a table.
  - Provide dev-facing defaults mirroring ME's `#define TX_*` block so a build can ship with rules pre-chosen for testing.
- **Acceptance:** Starting a new game without touching the menu yields a fully-populated, self-consistent rules struct matching the chosen preset.
- **Tests:** Unit tests asserting each preset's exact rule vector; manual new-game check.
- **Decisions:** [`docs-mf/decisions/0014-product-classic-modern-custom-presets.md`](docs-mf/decisions/0014-product-classic-modern-custom-presets.md) — Classic/Modern gamemode table; `MF_TX_*` + default Modern skip-menu preset; `newLegendaries` always off.

### S15 — Rule immutability & mid-run lock semantics

- [x] **Status:** Complete

- **Goal:** Rules chosen at the start of a run can't be edited away mid-run — ME's menu warns "All selections are permanent."
- **Depends on:** S14
- **Scope:**
  - Add a "rules locked" state set once the run begins.
  - Decide and document which rules (if any) may change mid-run. ME has a `LOCK DIFFICULTY` challenge option; mirror that intent.
  - Ensure the debug menu can override the lock in non-release builds only.
- **Acceptance:** After the run starts, the menu is read-only for locked rules; debug override works only in debug builds.
- **Tests:** Unit tests for lock transitions; manual attempt to re-enter the menu mid-run.
- **Decisions:** [`docs-mf/decisions/0015-product-rules-mid-run-lock.md`](docs-mf/decisions/0015-product-rules-mid-run-lock.md) — commit lock; Difficulty editable iff `!lockDifficulty`; debug session override.

### S16 — Deterministic seeded RNG service

- [x] **Status:** Complete

- **Goal:** Randomized content is stable across save/load and soft-resets — a randomizer that reshuffles on reload is broken.
- **Depends on:** S12
- **Scope:**
  - Store a per-save randomizer seed in the rules struct.
  - Implement a pure, seeded mapping service: given (seed, category, input id) → deterministic output. No dependence on `Random()` call ordering or frame counters.
  - Support the categories ME randomizes: wild, trainer, moves, ability, evolution, evolution method, static (ME's `TX_RANDOM_T_*` constants).
  - Handle "map-based" randomization (ME's `TX_RANDOM_MAP_BASED`), where the mapping is keyed by location so an area stays consistent.
- **Acceptance:** The same seed and input always produce the same output, across resets and across a save/load cycle.
- **Tests:** Unit tests for determinism, distribution sanity, and stability across simulated reloads. This is the single most test-worthy piece in the project — cover it well.

### S17 — Debug rules inspector

- [x] **Status:** Complete

- **Goal:** See and change the active rules without replaying the menu.
- **Depends on:** S13, S05
- **Scope:**
  - Extend the `mf_debug` submenu (S05) to list every active rule and its value, paged.
  - Allow toggling rules at runtime in debug builds (bypassing S15's lock).
  - Port the spirit of ME's `PrintTXSaveData()` for dumping state.
- **Acceptance:** Every rule is visible and settable from the debug menu in a non-release build; absent from `make release`.
- **Tests:** Manual; confirm the menu compiles out of a release build.
- **Decisions:** [`docs-mf/decisions/0017-tech-debug-rules-inspector.md`](docs-mf/decisions/0017-tech-debug-rules-inspector.md) — paged mf_debug inspector; `Debug_RefreshCurrentMenu`; auto unlock; mGBA dump.

---

## Phase 3 — Rules menu UI

> Build the whole menu as **pure UI that writes to the rules struct**, with no gameplay effect yet. Phases 4–9 then wire behavior one page at a time. This split keeps the UI testable on its own and means a broken gameplay hook can never brick the new-game flow.
>
> ME's implementation is `src/tx_rac_menu.c` (menu), `src/tx_rac_viewer.c` (read-only viewer), `src/tx_randomizer_and_challenges.c` (logic). Reuse its option lists, ordering, and description strings; rewrite the rendering against FireRed's window/font system, which differs from Emerald's.

### S18 — Menu shell: paged list, cursor, description pane

- [x] **Status:** Complete

- **Goal:** A reusable, FR-styled options screen that all six pages plug into.
- **Depends on:** S13
- **Scope:**
  - Build `src/mf_rules_menu.c`: scrolling paged list, left/right value cycling, a live description pane for the highlighted option, and page navigation via a `NEXT` entry (ME uses `TX_MENU_ITEMS_PER_PAGE 6`).
  - Use FireRed's window/text/font conventions and palettes, not Emerald's. Verify against FR's existing `src/option_menu.c` for the house style.
  - Define the page as a **data table** (label, description strings, value list, rules-struct target) so adding a page is data, not code.
  - Handle text overflow: ME's labels are short and uppercase for a reason.
- **Acceptance:** A throwaway demo page renders, scrolls, cycles values, shows descriptions, and exits cleanly with no graphical artifacts.
- **Tests:** Manual per [`docs-mf/manual-qa-s18-rules-menu-shell.md`](docs-mf/manual-qa-s18-rules-menu-shell.md); screenshots under `docs-mf/qa-s18/` when capturing.
- **Decisions:** [`docs-mf/decisions/0018-tech-rules-menu-shell.md`](docs-mf/decisions/0018-tech-rules-menu-shell.md) — data-driven FR shell; 5 visible rows; demo via debug.

### S19 — Hook the menu into the FireRed new-game flow

- [x] **Status:** Complete

- **Goal:** The player chooses rules during the opening, as in ME.
- **Depends on:** S18, S14
- **Scope:**
  - Insert the menu into FR's new-game path. The relevant code is `src/main_menu.c` (`CB2_NewGame`, the naming-screen return path around `CB2_NewGameBirchSpeech_ReturnFromNamingScreen`) and `src/oak_speech.c`. Choose the insertion point carefully — after naming, before the overworld loads.
  - Ordering is critical: rules must be committed **before** `NewGameInitData()` finishes populating anything rule-dependent (starters, party, encounters).
  - Support ME's `Task_ChooseChallenge_NoNewGame` equivalent: entering the menu outside a fresh new game.
  - Keep the upstream diff to the smallest possible call site.
- **Acceptance:** Starting a new game presents the menu; choices persist into the save; cancelling or skipping yields valid preset rules.
- **Tests:** Manual full new-game run; verify via the S17 debug inspector that chosen values landed.

### S20 — Gamemode page

- [x] **Status:** Complete

- **Goal:** Page 1 of the menu, matching ME's option list.
- **Depends on:** S18
- **Scope:** Options, per ME's `sText_*` labels: `GAMEMODE` (Classic/Modern/Custom), `ENCOUNTERS`, `REUSABLE TMS`, `SURVIVE POISON`, `SYNCHRONIZE`, `NATURE MINTS`, `SITRUS BERRY`, `POKéMON TYPES`, `FAIRY TYPE`, `POKéMON STATS`, `STURDY`, `{PKMN} MOVEPOOL`, `LEGEN. ABILITIES`, `EXTRA LEGEND.`, `TYPE CHART`. Drop `EXTRA LEGEND.` if it requires new maps (out of scope per `PROJECT.md`). Selecting Classic or Modern bulk-sets the other options per S14's preset table.
- **Acceptance:** All options render with descriptions and write correct values; preset selection visibly updates dependent options.
- **Tests:** Manual; debug inspector confirms written values.

- **Decisions:** [`docs-mf/decisions/0020-ux-gamemode-page.md`](docs-mf/decisions/0020-ux-gamemode-page.md) — ME order; drop EXTRA LEGEND.; Custom gate; preset via TrySetValue.

### S21 — Features page

- [x] **Status:** Complete

- **Goal:** Page 2, trimmed to what makes sense in FireRed.
- **Depends on:** S18
- **Scope:** From ME: `SHINY CHANCE`, `ITEM DROP`, `SHINY COLORS`. Explicitly **exclude** ME entries that don't apply or are out of scope: `CLOCK TYPE` (FR has no RTC; `PROJECT.md` calls day/night optional-later), `FRONTIER BANS` (no FR Frontier), `EASIER FEEBAS` (Hoenn-specific), `WONDERTRADE`/`UNLIMITED WT` (deferred). Record each exclusion so the omissions are deliberate.
- **Acceptance:** Page renders the FR-appropriate subset; exclusions documented.
- **Tests:** Manual; debug inspector.
- **Decisions:** [`docs-mf/decisions/0021-ux-features-page-exclusions.md`](docs-mf/decisions/0021-ux-features-page-exclusions.md) — FR subset; omit CLOCK/WT/FEEBAS/FRONTIER.

### S22 — Nuzlocke page

- [x] **Status:** Complete

- **Goal:** Page 3, matching ME.
- **Depends on:** S18
- **Scope:** `NUZLOCKE` (Off/Easy/Normal/Hardcore), `DUPES CLAUSE`, `SHINY CLAUSE`, `NICKNAMES`, `FAINTING` (deletion behavior), plus ME's mini mode. Sub-options should grey out or hide when Nuzlocke is Off.
- **Acceptance:** Page renders; dependent options disable correctly when Nuzlocke is off.
- **Tests:** Manual; debug inspector.
- **Decisions:** [`docs-mf/decisions/0022-ux-nuzlocke-page.md`](docs-mf/decisions/0022-ux-nuzlocke-page.md) — packed Off/Easy/Normal/Hard; Easy mini-mode gate; Cemetery/Release.

### S23 — Difficulty page

- [x] **Status:** Complete

- **Goal:** Page 4, matching ME.
- **Depends on:** S18
- **Scope:** `PARTY LIMIT`, `LEVEL CAP`, `EXP. MULTIPLIER`, `PLAYER ITEMS`, `TRAINER ITEMS`, `PLAYER EVs`, `PLAYER IVs`, `TRAINER IVs`, `TRAINER EVs`, `CATCH RATE`, `LESS ESCAPES`, `ESC. ROPE / DIG`, `HARD MODE EXP.`, `LOCK DIFFICULTY`.
- **Acceptance:** Page renders all options with correct value ranges and descriptions.
- **Tests:** Manual; debug inspector.
- **Decisions:** [`docs-mf/decisions/0023-ux-difficulty-page.md`](docs-mf/decisions/0023-ux-difficulty-page.md) — ME order; Yes/No item bans; Off/Max/HP PLAYER IVs.

### S24 — Challenges page

- [x] **Status:** Complete

- **Goal:** Page 5, matching ME.
- **Depends on:** S18
- **Scope:** `POKéCENTER`, `PC HEALS {PKMN}`, `ULTRA EXPENSIVE!`, `EVO LIMIT` (off/first/none), `ONE TYPE ONLY` (type selector; ME uses `TX_CHALLENGE_TYPE_OFF 31` as the sentinel), `BST EQUALIZER` (off/100/255/500), `MIRROR MODE`, `MIRROR THIEF`.
- **Acceptance:** Page renders; the monotype selector cycles all types plus Off.
- **Tests:** Manual; debug inspector.
- **Decisions:** [`docs-mf/decisions/0024-ux-challenges-page.md`](docs-mf/decisions/0024-ux-challenges-page.md) — ME order; Off+18 types; gated PC heal / Mirror Thief.

### S25 — Randomizer page

- [x] **Status:** Complete

- **Goal:** Page 6, matching ME.
- **Depends on:** S18
- **Scope:** `RANDOMIZER` master toggle, `STARTER POKéMON`, `WILD POKéMON`, `TRAINER`, `STATIC POKéMON`, `BALANCING` (similar BST/evo stage), `LEGENDARIES`, `TYPE`, `MOVES`, `ABILITIES`, `EVOLUTIONS`, `EVO LINES`, `EFFECTIVENESS`, `ITEMS`, `CHAOS MODE`. Sub-options gate on the master toggle.
- **Acceptance:** Page renders; sub-options gate correctly; the master toggle drives an `IsRandomizerActivated()`-style helper.
- **Tests:** Manual; debug inspector.
- **Decisions:** [`docs-mf/decisions/0025-ux-randomizer-page.md`](docs-mf/decisions/0025-ux-randomizer-page.md) — master bit; nested ME gates; live clear/seed.

### S26 — Confirm, save & in-game rules viewer

- [x] **Status:** Complete

- **Goal:** Commit choices deliberately, and let the player re-read their active rules later.
- **Depends on:** S20, S21, S22, S23, S24, S25, S15
- **Scope:**
  - `SAVE` entry commits the rules and locks them (S15), with a confirmation reflecting ME's permanence warning.
  - Build a read-only viewer showing all active rules mid-run, modeled on ME's `src/tx_rac_viewer.c`. Reach it from an existing FR menu surface (Pokédex, trainer card, or the start menu) — no new maps or NPCs.
- **Acceptance:** Saving commits and locks; the viewer accurately reflects the active rule set at any point in a run.
- **Tests:** Manual: choose a distinctive rule set, save, reset, confirm the viewer still shows it.

---

## Phase 4 — Gamemode wiring

> Where the compile-time defaults from Phase 1 become player-toggleable. Each story converts a set of `#if`-driven behaviors into runtime checks via the S13 gate. Watch for two recurring traps: **hot paths** (a rule check inside the damage loop must be cheap) and **display consistency** (if the rule changes a Pokémon's type or stats, the Pokédex, summary screen, and battle UI must all agree).

### S27 — Runtime Fairy type toggle

- [x] **Status:** Complete

- **Goal:** `FAIRY TYPE` on/off actually changes typings and matchups.
- **Depends on:** S13, S07
- **Scope:**
  - Route Fairy type assignment and Fairy type-chart entries through the runtime gate.
  - Decide the "off" behavior for Fairy-only Pokémon and moves — ME reverts them to their pre-Gen-6 typing. Build the fallback table.
  - Ensure the Pokédex, summary screen, and battle type icons reflect the active setting.
- **Acceptance:** Toggling the rule at new game changes typings, damage calculations, and every UI surface consistently.
- **Tests:** Unit tests on the type-lookup helper for both states; manual battle and dex checks.

### S28 — Runtime modern types & type chart

- [x] **Status:** Complete

- **Goal:** `POKéMON TYPES` and `TYPE CHART` are player choices.
- **Depends on:** S27
- **Scope:**
  - Gate updated type assignments (ME's `TX_MODE_MODERN_TYPES`) and type-effectiveness changes (`TX_MODE_TYPE_EFFECTIVENESS`) behind runtime checks, replacing reliance on `P_UPDATED_TYPES`.
  - The type chart is read constantly in battle — pick a representation that keeps lookups fast (e.g. selecting between two static tables rather than branching per lookup).
- **Acceptance:** Both toggles measurably change matchups; no battle slowdown.
- **Tests:** Unit tests for effectiveness in both modes; battle tests via `make check` where possible.

### S29 — Runtime modern base stats

- [x] **Status:** Complete

- **Goal:** `POKéMON STATS` toggles between original and updated base stats.
- **Depends on:** S13, S08
- **Scope:**
  - Provide a gated alternate base-stat source; expansion has no runtime toggle for this, so this is a dual-table build.
  - Stat lookups are extremely hot — measure before and after.
  - Ensure recalculation is consistent for already-caught Pokémon and that the summary screen matches.
- **Acceptance:** Toggling produces different stat totals in battle and in the summary; no measurable performance regression.
- **Tests:** Unit tests on the stat-lookup helper; manual summary comparison.
- **Decisions:** [`docs-mf/decisions/0029-tech-runtime-modern-base-stats.md`](docs-mf/decisions/0029-tech-runtime-modern-base-stats.md) — Gen-3 classic fallback table; Gen-latest stays in `gSpeciesInfo`; no ME custom buffs.

### S30 — Runtime modern movepools

- [x] **Status:** Complete

- **Goal:** `{PKMN} MOVEPOOL` toggles between vanilla FR and modern learnsets.
- **Depends on:** S29
- **Scope:**
  - Build flag-gated dual learnset tables, as `PROJECT.md` explicitly prefers over forcing modern always-on.
  - Cover level-up learnsets, TM/HM compatibility, and tutor moves.
  - ROM size is the real risk: two full learnset tables is a lot of data. Measure the delta and record it; if it doesn't fit, propose an alternative (e.g. a diff/patch table) in an ADR before building it.
- **Acceptance:** Toggling changes what a Pokémon learns and can be taught; ROM still fits and boots.
- **Tests:** Unit tests on learnset lookup in both modes; manual level-up and TM checks.
- **Decisions:** [`docs-mf/decisions/0030-tech-runtime-modern-movepools.md`](docs-mf/decisions/0030-tech-runtime-modern-movepools.md) — FRLG classic tables from `frlg.json`; modern stays in `gSpeciesInfo`; ~55 KiB `.rodata`.

### S31 — Runtime item & ability behavior toggles

- [x] **Status:** Complete

- **Goal:** The small Gamemode switches all work at runtime.
- **Depends on:** S13, S10, S11
- **Scope:** Gate each of `REUSABLE TMS` (`I_REUSABLE_TMS`), `SITRUS BERRY` (`I_SITRUS_BERRY_HEAL`), `STURDY` (`B_STURDY`), `SYNCHRONIZE` (`OW_SYNCHRONIZE_NATURE` and `B_SYNCHRONIZE_TOXIC`), `SURVIVE POISON` (`OW_POISON_DAMAGE`), and `NATURE MINTS` (availability). Each is a small, similar change — do them together and keep the gate pattern identical across all six.
- **Acceptance:** Each toggle demonstrably changes behavior in-game.
- **Tests:** Unit test per gated behavior where the logic is pure; manual check per toggle.

### S32 — Encounters mode (data-only)

- [x] **Status:** Complete

- **Goal:** ME's `ENCOUNTERS` option (Vanilla / Postgame / Modern), within FR's existing map set.
- **Depends on:** S13, S08
- **Scope:**
  - Build alternate wild-encounter tables as **data-only remaps of existing FR routes** — `PROJECT.md` allows this explicitly and forbids anything needing new areas.
  - Vanilla = stock FR tables. Modern = broadened availability across the enabled species range. Postgame = vanilla until champion, then broadened.
  - Select the active table at encounter time through the runtime gate; check `include/config/wild_encounter.h` for existing hooks before adding new ones.
  - Design the Modern tables so every enabled species is obtainable — that's the point of the mode.
- **Acceptance:** Each mode yields visibly different encounters on the same route; Postgame flips only after the champion flag.
- **Tests:** Unit tests on table selection; manual encounter sampling on several routes.
- **Decisions:** [`docs-mf/decisions/0032-tech-runtime-encounters-mode.md`](docs-mf/decisions/0032-tech-runtime-encounters-mode.md) — parallel FR modern headers; Postgame uses `FLAG_SYS_GAME_CLEAR`; no day/night twin.

---

## Phase 5 — Features & item-friction wiring

> Shiny/item-drop Features (S33–S34) plus solo trade-evolution friction removal (S69). S69 is numbered after the original backlog but **runs here**, before Nuzlocke — it only needs the item baseline (S10) and optional Gamemode gating (S13/S20).

### S33 — Shiny chance & shiny clause plumbing

- [x] **Status:** Complete

- **Goal:** `SHINY CHANCE` is a player-selectable multiplier.
- **Depends on:** S13
- **Scope:**
  - `SHINY_ODDS` (`include/constants/pokemon.h`, default `8`) is a compile-time constant, so route shiny rolls through a runtime helper instead.
  - Offer ME-like tiers (e.g. off/vanilla/boosted/high) rather than a raw number.
  - Interacts with Shiny Charm (`I_SHINY_CHARM_ADDITIONAL_ROLLS`) — define the combined behavior.
  - Expose the helper for the Nuzlocke shiny clause (S37) to reuse.
- **Acceptance:** Higher tiers produce measurably more shinies; the debug menu can force-encounter to verify quickly.
- **Tests:** Unit tests on the odds helper per tier; statistical spot-check via a debug loop.

### S34 — Wild item drops

- [x] **Status:** Complete

- **Goal:** ME's `ITEM DROP` — defeated wild Pokémon can drop items.
- **Depends on:** S13
- **Scope:**
  - Grant an item on wild-battle victory based on the defeated species' held-item data or a drop table; use the seeded RNG (S16) if drops should be reproducible.
  - Decide whether drops go straight to the bag or require a prompt, and how it interacts with a full bag.
  - Keep the battle-end hook small and namespaced.
- **Acceptance:** With the rule on, wild victories yield items at a sane rate; off, behavior is vanilla.
- **Tests:** Unit test on the drop-selection helper; manual battles.
- **Decisions:** [`docs-mf/decisions/0034-tech-runtime-wild-item-drops.md`](docs-mf/decisions/0034-tech-runtime-wild-item-drops.md) — remaining held item → bag with battle prompt; bag-full loses the item; no extra RNG (uses `SetWildMonHeldItem` rates).

### S69 — Solo trade evolutions (Linking Cord & bag evo items)

- [x] **Status:** Complete

- **Goal:** Evolve trade-only and trade+held-item Pokémon without link trading (e.g. Haunter → Gengar, Scyther → Scizor).
- **Depends on:** S10, S13
- **Scope:**
  - Expansion already provides the mechanics: pure trade lines (`Haunter`, `Kadabra`, `Machoke`, `Graveler`) have `{EVO_ITEM, ITEM_LINKING_CORD, …}`; trade+held lines (`Scyther`/`Metal Coat`, `Seadra`/`Dragon Scale`, `Onix`, `Poliwhirl`/`King's Rock`, Gen 2 cross-evos like `Porygon`/`Upgrade`, etc.) have matching `{EVO_ITEM, ITEM_*, …}` methods.
  - Flip `I_USE_EVO_HELD_ITEMS_FROM_BAG` (`include/config/item.h`, currently `FALSE`) so hold items work from the bag like stones (PLA-style). Prefer a runtime Gamemode/Features gate via S13 if this should be toggleable (Modern on / Classic off); otherwise always-on is fine — record the choice in an ADR.
  - **Obtainability without map/NPC edits:** stock `ITEM_LINKING_CORD` and the Kanto-relevant held evo items in existing FireRed mart data (Celadon Dept Store is the natural FR spot). Cover every trade evo reachable under the S08 species ceiling; do not require link cable or Wonder Trade.
  - Confirm Linking Cord already uses `ItemUseOutOfBattle_EvolutionStone`; held items use `EVO_HELD_ITEM_*` macros gated by the config above.
  - Compose with the Challenges evo limit (S47): when evolution is blocked, bag use must refuse clearly.
  - Out of scope: Karrablast/Shelmet partner-species trades; Wonder Trade (still deferred).
- **Acceptance:** Without trading, a player can evolve Haunter → Gengar via Linking Cord and Scyther → Scizor via Metal Coat from the bag; required items are obtainable in-game on a normal playthrough (not debug-only).
- **Tests:** Manual checklist for each Kanto trade line under the enabled species set; config/unit lock that bag-use is enabled when the rule is on; spot-check that S47 evo limit still blocks.
- **Decisions:** [`docs-mf/decisions/0035-product-solo-trade-evolutions.md`](docs-mf/decisions/0035-product-solo-trade-evolutions.md) — always-on bag use (no Gamemode toggle); Celadon 4F stocks Linking Cord + S08 trade-held set.

---

## Phase 6 — Nuzlocke

> Highest-risk phase for **permanent player data loss** — deletion bugs destroy saves. Every deletion path needs an explicit test and a debug-only dry-run mode. Reference: ME's `NuzlockeFlagGet/Set/Clear`, `NuzlockeDeletePartyMon`, `NuzlockeDeleteFaintedPartyPokemon`.

### S35 — Per-area encounter locking

- [x] **Status:** Complete

- **Goal:** Only the first wild encounter in each area is catchable.
- **Depends on:** S13
- **Scope:**
  - Implement per-mapsec encounter flags (ME uses `NuzlockeEncounterFlags[9]` in the save) sized for FireRed's mapsec list — verify the count, since Kanto's differs from Hoenn's.
  - Set the flag on first encounter in an area; block catching afterward with a clear message.
  - Decide handling for gift/static/fossil Pokémon and the starter.
  - Surface which areas are used, ideally in the town map or the S26 viewer.
- **Acceptance:** Second encounters in an already-used area cannot be caught; flags persist across save/load.
- **Tests:** Unit tests on flag get/set/clear per mapsec; manual multi-route run.
- **Decisions:** [`docs-mf/decisions/0036-product-nuzlocke-area-locking.md`](docs-mf/decisions/0036-product-nuzlocke-area-locking.md) — raw mapsec bits; consume on wild battle end; gifts/starter/legendary excluded; viewer + debug dump for used areas.

### S36 — Faint handling & deletion

- [ ] **Status:** Not started

- **Goal:** Fainted Pokémon are permanently lost, safely.
- **Depends on:** S35
- **Scope:**
  - On faint, mark the Pokémon dead per the `FAINTING` rule: mark-only, move to a "cemetery" box, or delete outright.
  - Handle party/PC edge cases: last Pokémon fainting, whiteout, deletion mid-battle versus after.
  - ME renders dead Pokémon greyed (`TX_NUZLOCKE_CEMETERY_ICON_GRAY`) — mirror that so loss is visible, not silent.
  - Add a debug dry-run that logs what *would* be deleted without deleting.
- **Acceptance:** Fainted Pokémon are handled per the selected rule with no corruption, no softlock on whiteout, and no way to recover them normally.
- **Tests:** Unit tests for every deletion path including the last-Pokémon case; manual faint scenarios. **Do not ship this story without them.**

### S37 — Dupes & shiny clauses

- [ ] **Status:** Not started

- **Goal:** Standard Nuzlocke clauses.
- **Depends on:** S35, S33
- **Scope:**
  - Dupes clause: if the area's first encounter is an already-owned evolutionary line, re-roll or allow another encounter. Define the behavior when *every* species is owned.
  - Shiny clause: shinies are always catchable regardless of area lock.
- **Acceptance:** Duplicate lines don't consume an area's encounter; shinies bypass the lock.
- **Tests:** Unit tests on the clause predicates (including the all-owned case); manual verification.

### S38 — Forced nicknaming

- [ ] **Status:** Not started

- **Goal:** ME's `NICKNAMES` — every caught Pokémon must be nicknamed.
- **Depends on:** S13
- **Scope:** Force the naming screen on catch when the rule is on; handle the "no name entered" case; mirror ME's `IsNuzlockeNicknamingActive()`.
- **Acceptance:** Catching always prompts for a nickname with the rule on, never with it off.
- **Tests:** Manual catch flow.

### S39 — Nuzlocke difficulty tiers

- [ ] **Status:** Not started

- **Goal:** Off / Easy / Normal / Hardcore as coherent bundles.
- **Depends on:** S36, S37, S38
- **Scope:**
  - Define each tier's exact rule bundle and record it in an ADR. Hardcore conventionally means set battle style, level caps at gym leaders, and no healing items in battle — several of which are implemented in Phase 7, so define the dependency now and wire what exists.
  - Implement ME's mini mode.
  - Provide the `IsNuzlockeActive()` equivalent for other systems to query.
- **Acceptance:** Selecting a tier applies its full bundle; Hardcore is meaningfully harder than Normal.
- **Tests:** Unit tests asserting each tier's rule vector; manual play.

---

## Phase 7 — Difficulty

> Largely a matter of wiring `include/config/caps.h` and battle EXP configs to runtime values. Expansion already has the machinery; we're replacing compile-time constants with rule lookups.

### S40 — Party limit

- [ ] **Status:** Not started

- **Goal:** Cap how many Pokémon can be in the party.
- **Depends on:** S13
- **Scope:** Implement a `GetMaxPartySize()` equivalent driven by the rule; enforce it at catch, PC withdrawal, and gift acceptance; make the UI explain the refusal rather than silently failing.
- **Acceptance:** The party cannot exceed the limit through any path.
- **Tests:** Unit tests on the size helper; manual attempts via each path.

### S41 — Level caps

- [ ] **Status:** Not started

- **Goal:** Runtime-selectable level caps that actually bind.
- **Depends on:** S13
- **Scope:**
  - Wire `include/config/caps.h` to rules: `B_LEVEL_CAP_TYPE`, `B_LEVEL_CAP_VARIABLE`, `B_EXP_CAP_TYPE`, `B_RARE_CANDY_CAP`, `B_LEVEL_CAP_EXP_UP`. These are compile-time; route them through the gate.
  - Define FireRed's cap progression by badge/gym — the flag map is FR-specific and must be authored.
  - Implement ME's `GetCurrentPartyLevelCap()` equivalent.
- **Acceptance:** Pokémon stop gaining EXP (or levels) at the cap; the cap rises with badges.
- **Tests:** Unit tests on cap lookup per badge count; manual EXP checks at a cap boundary.

### S42 — EXP multiplier & hard-mode EXP

- [ ] **Status:** Not started

- **Goal:** Scale progression speed.
- **Depends on:** S41
- **Scope:**
  - Apply a runtime multiplier to EXP gain, respecting `B_TRAINER_EXP_MULTIPLIER`, `B_SPLIT_EXP`, and `B_SCALED_EXP`.
  - Implement `HARD MODE EXP.` (ME's `TX_DIFFICULTY_HARD_EXP`) — define precisely what it does and record it.
  - Note ME gates the multiplier behind Nuzlocke/randomizer in some builds (`TX_EXP_MULTIPLER_ONLY_ON_NUZLOCKE_AND_RANDOMIZER`); decide whether we do the same.
- **Acceptance:** Each multiplier setting measurably changes EXP gained from the same battle.
- **Tests:** Unit tests on the EXP calculation per setting.

### S43 — Item bans (player & trainer)

- [ ] **Status:** Not started

- **Goal:** ME's `PLAYER ITEMS` / `TRAINER ITEMS`.
- **Depends on:** S13
- **Scope:** Block in-battle item use for the player when banned; suppress AI item use for trainers. Decide whether the Bag option is hidden or shown-and-refused, and whether the ban covers Poké Balls (it must not, or catching breaks).
- **Acceptance:** Banned items are unusable in battle for the relevant side; catching still works.
- **Tests:** Battle tests via `make check` where possible; manual battles.

### S44 — IV/EV scaling

- [ ] **Status:** Not started

- **Goal:** ME's `PLAYER EVs`, `PLAYER IVs`, `TRAINER IVs`, `TRAINER EVs`.
- **Depends on:** S13
- **Scope:**
  - Trainer side: implement `GetCurrentTrainerIVs()` / `GetCurrentTrainerEVs()` equivalents that scale opponent quality with progression.
  - Player side: wire `B_EV_CAP_TYPE`, `B_EV_CAP_VARIABLE`, `B_EV_ITEMS_CAP` (`include/config/caps.h`) and a max-IV rule to runtime values.
  - Make the S09 summary IV/EV display reflect any caps so the numbers aren't confusing.
- **Acceptance:** Trainer Pokémon are measurably stronger at higher settings; player EV/IV caps bind.
- **Tests:** Unit tests on scaling math; manual battle inspection via the debug menu.

### S45 — Catch rate & escape restrictions

- [ ] **Status:** Not started

- **Goal:** ME's `CATCH RATE`, `LESS ESCAPES`, `ESC. ROPE / DIG`.
- **Depends on:** S13
- **Scope:**
  - Apply a runtime catch-rate modifier on top of expansion's existing bonuses (`B_INCAPACITATED_CATCH_BONUS`, `B_LOW_LEVEL_CATCH_BONUS`, `B_MISSING_BADGE_CATCH_MALUS`); there's no single global multiplier, so add one.
  - Restrict fleeing from wild battles and disable/limit Escape Rope and Dig per the rules.
  - Guard against softlocks: a player with no escape and no viable Pokémon must still have a path out.
- **Acceptance:** Catch difficulty changes per setting; escape restrictions apply without creating unwinnable states.
- **Tests:** Unit tests on the catch-rate helper; manual escape attempts including the edge case.

---

## Phase 8 — Challenges

### S46 — No Poké Center / no PC heal / expensive shops

- [ ] **Status:** Not started

- **Goal:** ME's `POKéCENTER`, `PC HEALS {PKMN}`, `ULTRA EXPENSIVE!`.
- **Depends on:** S13
- **Scope:**
  - Block or limit Nurse Joy healing (ME's `IsPokecenterChallengeActivated()`) with a clear in-game explanation, not a silent no-op.
  - Block PC-based healing.
  - Multiply shop prices; confirm sell prices scale coherently so the economy isn't exploitable.
  - Ensure the game stays completable: without healing, verify a path through the early game exists.
- **Acceptance:** Each challenge behaves as described and the game remains winnable.
- **Tests:** Manual: visit a Center, use a PC, check shop prices.

### S47 — Evolution limit

- [ ] **Status:** Not started

- **Goal:** ME's `EVO LIMIT` — off / first stage only / no evolution.
- **Depends on:** S13
- **Scope:** Block evolution beyond the allowed stage from every trigger (level-up, stone, trade, item); message the player when blocked.
- **Acceptance:** Evolution is blocked per setting across all trigger types.
- **Tests:** Unit tests on the evolution predicate; manual level-up and stone attempts.

### S48 — Monotype challenge

- [ ] **Status:** Not started

- **Goal:** ME's `ONE TYPE ONLY`.
- **Depends on:** S13, S27
- **Scope:**
  - Restrict the party to a chosen type (ME uses `31` as the off sentinel and `IsOneTypeChallengeActive()`).
  - Define behavior for dual-types (either type matches), for the starter (must be legal), and for Pokémon whose type changes with the Fairy or modern-types rules — this is why it depends on S27.
  - Enforce at catch and at PC withdrawal, with a clear message.
- **Acceptance:** Only Pokémon of the chosen type can enter the party; the starter selection respects it.
- **Tests:** Unit tests on the legality predicate including dual-type and Fairy interactions.

### S49 — BST equalizer

- [ ] **Status:** Not started

- **Goal:** ME's `BST EQUALIZER` — off / 100 / 255 / 500.
- **Depends on:** S13, S29
- **Scope:** Normalize every Pokémon's base stat total to the chosen value, preserving the relative stat distribution. Applies to wild, trainer, and player Pokémon alike. Must compose correctly with the S29 modern-stats toggle — decide the order of operations and document it.
- **Acceptance:** All Pokémon share the chosen BST with distributions intact; the summary screen agrees.
- **Tests:** Unit tests on the normalization math including rounding and the interaction with S29.

### S50 — Mirror mode (± thief)

- [ ] **Status:** Not started

- **Goal:** ME's `MIRROR MODE` and `MIRROR THIEF`.
- **Depends on:** S13
- **Scope:** Opponents mirror the player's party (species, and decide whether level/moves/items too). Thief variant steals from the player's actual party. Define the pre-first-catch behavior and how it interacts with the randomizer.
- **Acceptance:** Trainer battles present mirrored teams; the thief variant behaves as specified.
- **Tests:** Unit tests on team construction; manual trainer battles.

---

## Phase 9 — Randomizer

> The largest phase. It sits last among gameplay features because it touches nearly every data table and is far easier to build on top of a proven rules engine and seeded RNG. Reference: ME's `src/tx_randomizer_and_challenges.c`.
>
> Two rules apply throughout: **determinism** (everything routes through S16 — never `Random()`) and **display consistency** (the Pokédex, summary screen, and battle UI must show randomized data, not the original tables).

### S51 — Species mapping core

- [ ] **Status:** Not started

- **Goal:** The shared "given a species, return its randomized replacement" service.
- **Depends on:** S16, S25, S08
- **Scope:**
  - Implement the mapping with ME's constraint options: `BALANCING` (similar BST and evolution stage), `LEGENDARIES` (include or exclude), and map-based consistency.
  - Restrict candidates to the enabled species range from S08.
  - Guarantee the game stays completable: HM-move availability in Kanto is a hard requirement (Cut, Surf, Strength are progression-gating). Verify this explicitly — it's the classic randomizer softlock.
- **Acceptance:** Mapping is deterministic, respects every constraint, and never produces an uncompletable Kanto.
- **Tests:** Extensive unit tests: determinism, BST similarity bounds, legendary exclusion, and an HM-availability assertion across many seeds.

### S52 — Wild & static randomization

- [ ] **Status:** Not started

- **Goal:** ME's `WILD POKéMON` and `STATIC POKéMON`.
- **Depends on:** S51, S32
- **Scope:** Apply mapping to wild encounter tables (composing correctly with the S32 encounters mode) and to static, gift, fossil, and legendary encounters. An area's wilds must stay stable across visits.
- **Acceptance:** Wilds and statics are randomized, consistent per area, and stable across save/load.
- **Tests:** Unit tests on table transformation; manual route sampling and revisits.

### S53 — Trainer & starter randomization

- [ ] **Status:** Not started

- **Goal:** ME's `TRAINER` and `STARTER POKéMON`.
- **Depends on:** S51
- **Scope:**
  - Randomize trainer parties, preserving level and party size so difficulty curves survive.
  - Randomize the three Oak starters; the rival's starter should keep its type-advantage relationship if that relationship still makes sense.
  - Compose with S44's trainer IV/EV scaling and S50's mirror mode — define precedence.
- **Acceptance:** Trainer teams and starters are randomized deterministically; gym difficulty remains reasonable.
- **Tests:** Unit tests on party generation; manual gym battles and the starter selection.

### S54 — Move & ability randomization

- [ ] **Status:** Not started

- **Goal:** ME's `MOVES` and `ABILITIES`.
- **Depends on:** S51
- **Scope:**
  - Randomize learnsets and abilities per species, deterministically.
  - Every Pokémon must have at least one damaging move at low level, or early battles become unwinnable.
  - Ban or handle abilities that break progression or crash outside their intended context.
  - The summary screen and battle UI must show the randomized data.
- **Acceptance:** Moves and abilities are randomized without unwinnable early battles or crashes.
- **Tests:** Unit tests including the "has a damaging low-level move" invariant across many seeds.

### S55 — Evolution & evo-method randomization

- [ ] **Status:** Not started

- **Goal:** ME's `EVOLUTIONS` and `EVO LINES`.
- **Depends on:** S51
- **Scope:** Randomize evolution targets and methods. Every evolution method must be *achievable in FireRed* — no methods depending on Hoenn-only items, locations, or day/night that FR lacks. This is the main softlock risk here. Compose with S47's evolution limit.
- **Acceptance:** Evolutions are randomized and every generated method is reachable in Kanto.
- **Tests:** Unit tests asserting method achievability across many seeds.

### S56 — Type & type-effectiveness randomization

- [ ] **Status:** Not started

- **Goal:** ME's `TYPE` and `EFFECTIVENESS`.
- **Depends on:** S51, S28
- **Scope:** Randomize species types and, separately, the type-effectiveness chart. Both must be reflected in the Pokédex, summary screen, and battle UI. Keep the randomized chart lookup as fast as the static one (S28).
- **Acceptance:** Types and matchups are randomized consistently everywhere they're displayed or used.
- **Tests:** Unit tests on the randomized chart's determinism and validity.

### S57 — Item randomization & chaos mode

- [ ] **Status:** Not started

- **Goal:** ME's `ITEMS` and `CHAOS MODE`.
- **Depends on:** S51
- **Scope:**
  - Randomize field items, hidden items, and shop stock (ME's `IsRandomItemsActivated()`). Protect progression-critical items — HMs and key items must remain obtainable, or reachable another way.
  - Chaos mode: re-roll on every encounter rather than using a fixed mapping. Because this intentionally breaks the determinism guarantee, define exactly which subsystems it applies to and keep it isolated from the stable mapping path.
- **Acceptance:** Items are randomized without blocking progression; chaos mode re-rolls per encounter and doesn't corrupt the stable mappings.
- **Tests:** Unit tests on key-item protection; manual chaos-mode encounter sampling.

---

## Phase 10 — Options+ QoL

> ME's `src/options_plus_menu.c`. Unlike the rules menu, these are **mid-run, changeable, per-player-preference** settings — different storage (SaveBlock2 options area) and different lock semantics from Phase 2. This phase is deliberately late because it's low-risk and independent, but individual stories can be pulled forward if the friction gets annoying during development.

### S58 — Options+ menu shell

- [ ] **Status:** Not started

- **Goal:** Replace FireRed's options menu with a paged, described, ME-style one.
- **Depends on:** S18
- **Scope:**
  - Build `src/mf_options_menu.c` reusing S18's paged-list widget, replacing or extending `src/option_menu.c`.
  - Keep vanilla options (text speed, battle scene, battle style, sound, button mode, frame type) and add pages for the new ones.
  - Store settings in `SaveBlock2`'s options area or an `MF_`-namespaced extension; unlike rules, these are editable any time.
- **Acceptance:** The options menu opens from the start menu, pages correctly, shows descriptions, and persists across save/load.
- **Tests:** Manual; verify vanilla options still work.

### S59 — Autorun

- [ ] **Status:** Not started

- **Goal:** Run without holding B.
- **Depends on:** S58
- **Scope:** Invert the run/walk behavior when enabled (ME: "Run without pressing B"). Handle the bike, and Surf if a Surf-speed variant makes sense in FR. Respect places where running is disallowed.
- **Acceptance:** With autorun on, the player runs by default and walks while holding B.
- **Tests:** Manual across overworld, indoors, bike, and Surf.

### S60 — Even Faster Joy & healing speed

- [ ] **Status:** Not started

- **Goal:** ME's `EVEN FASTER JOY` — the single most-felt QoL item.
- **Depends on:** S58
- **Scope:** Skip or drastically shorten the Poké Center healing animation and dialogue when enabled; keep a "fast but animated" middle setting as ME does. Verify against FR's Center script, which differs from Emerald's.
- **Acceptance:** Healing completes near-instantly on the fastest setting with no script desync.
- **Tests:** Manual heal at several Centers.

### S61 — Battle & intro speed options

- [ ] **Status:** Not started

- **Goal:** Expose the Phase 1 speed constants as player choices.
- **Depends on:** S58, S11
- **Scope:** `FAST BATTLES`, `ANIM SPEED` (runtime `B_WAIT_TIME_MULTIPLIER`), `FAST INTRO`, `SKIP INTRO` (skips title screen, including on soft-reset), and `QUICK RUN` / `BALL PROMPT` if expansion's equivalents are available.
- **Acceptance:** Each option measurably changes speed; `SKIP INTRO` survives a soft-reset.
- **Tests:** Manual timing per setting.

### S62 — Battle information hints

- [ ] **Status:** Not started

- **Goal:** ME's `STAB/EFFECTIVE` hint.
- **Depends on:** S58, S28
- **Scope:** Wire `B_SHOW_TYPES` (default `SHOW_TYPES_NEVER`) and `B_SHOW_EFFECTIVENESS` (default `SHOW_EFFECTIVENESS_SEEN`) to runtime options; add a STAB indicator, which expansion has no config for. Hints must respect randomized types (S56) and the Fairy toggle (S27) — showing stale effectiveness is worse than showing none.
- **Acceptance:** Move effectiveness and STAB display correctly in the battle move menu under every type-affecting rule.
- **Tests:** Manual battles with Fairy on/off and with randomized types.

### S63 — Bag, cursor & input QoL

- [ ] **Status:** Not started

- **Goal:** Round out the friction removers.
- **Depends on:** S58
- **Scope:** Surface bag sorting properly in the FR bag UI (`SortItemsInBag` already exists in `src/item_menu.c` with name/type/amount/index sorts — the work is UX, and possibly a remembered sort preference); `CURSOR MEMORY`; `RUN PROMPT` (L/R); button-mode options; and `UNIT SYSTEM` if worth carrying. Skip ME's follower, music, and background options — out of scope per `PROJECT.md`.
- **Acceptance:** Sorting is discoverable and persists; cursor memory works across menu visits.
- **Tests:** Manual bag and menu interaction.

---

## Phase 11 — Polish, save safety & release

### S64 — Save versioning & migration

- [ ] **Status:** Not started

- **Goal:** Shipping an update must never brick a player's save.
- **Depends on:** S12
- **Scope:**
  - Use the `version` field from S12 to implement a migration path; define behavior when a save's version is newer or unrecognized.
  - Document the additive-only discipline for the rules struct in `docs-mf/`.
  - Add a save-size regression check so a future field addition can't silently overflow the chunk.
- **Acceptance:** A save from an older rules-struct version loads with sensible defaults for new fields.
- **Tests:** Unit tests for migration across at least one synthetic version bump.

### S65 — Rule interaction matrix & conflict resolution

- [ ] **Status:** Not started

- **Goal:** Combinations of rules don't produce unwinnable or nonsensical runs.
- **Depends on:** all gameplay phases (S32, S39, S45, S50, S57)
- **Scope:**
  - Build a matrix of rule pairs that interact (monotype + randomizer, Nuzlocke + no Poké Center, level cap + hard EXP, BST equalizer + modern stats, chaos + Nuzlocke, and so on).
  - For each dangerous combination, decide: allow, warn at selection, or forbid in the menu.
  - Implement the warnings and prohibitions in the S18 menu.
- **Acceptance:** Known-broken combinations are blocked or warned about at selection time; the matrix is documented.
- **Tests:** Unit tests on the legality checker per pair.

### S66 — Full playthrough QA matrix

- [ ] **Status:** Not started

- **Goal:** Real confidence that runs finish, not just that features toggle.
- **Depends on:** S65
- **Scope:**
  - Define and execute a QA matrix: at minimum Classic vanilla, Modern default, full randomizer, Hardcore Nuzlocke, and monotype — each played far enough to prove progression (Brock through at least Surge, ideally to the Elite Four).
  - Record every softlock, crash, and balance outlier as a follow-up story.
  - Verify save/load stability at multiple points in each run.
- **Acceptance:** Each matrix configuration is playable to the documented checkpoint with no blocking bugs.
- **Tests:** Manual playthroughs with a written log per configuration.

### S67 — Branding, credits & version stamp

- [ ] **Status:** Not started

- **Goal:** The ROM identifies itself and credits its sources.
- **Depends on:** S66
- **Scope:**
  - Add a Modern FireRed version stamp visible in-game (title screen or options menu).
  - Credit RHH's `pokeemerald-expansion` (required by upstream, with version number) and Modern Emerald as inspiration.
  - Update `README.md` to describe this project rather than upstream's, keeping the required attribution.
  - Cosmetic title-screen work only — no story or map edits.
- **Acceptance:** Version and credits are visible in-game and in the README; upstream attribution requirements are met.
- **Tests:** Manual; visual check.

### S68 — Release build & distribution

- [ ] **Status:** Not started

- **Goal:** A distributable release.
- **Depends on:** S67
- **Scope:**
  - Verify `make release` produces a clean build with debug menus and quickstart compiled out.
  - Produce a distributable patch (BPS/UPS) against a clean FireRed ROM — never distribute the ROM itself.
  - Write release notes and a player-facing feature list.
  - Add a CI job that builds the release artifact on tags.
- **Acceptance:** The patch applies to a clean FireRed ROM and produces a working, debug-free build.
- **Tests:** Apply the patch to a clean ROM on a fresh machine and complete a short playthrough.

---

## Deferred (post-v1)

Tracked so they aren't lost, but explicitly **out of v1** (see `PROJECT.md`):

- **Wonder Trade** (PC-based, no map work) — ME's `WONDERTRADE` / `UNLIMITED WT`. Viable after the rules engine lands.
- **Day/night & RTC** — ME's `CLOCK TYPE`. FR has no RTC; expansion's `OW_USE_FAKE_RTC` makes it possible but it's not a v1 goal.
- **HGSS-style Pokédex extras** — `include/config/pokedex_plus_hgss.h` exists; nice-to-have.
- **DexNav** — `include/config/dexnav.h` exists; evaluate later.
- **Extra legendaries** requiring new maps — out of scope.
- **Followers, big followers, surf cosmetics** — out of scope.
- **Music packs / BGM menus** — out of scope.
- **Battle Frontier modernization** — FR has no Emerald Frontier.
- **Full National Dex / Gen 9 dump** — only if deliberately decided later (see S08).
