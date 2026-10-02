---
name: implement-story
description: >-
  Implement a story from STORIES.md for Modern FireRed end to end: find the
  story, build it against PROJECT.md and the project conventions, verify it with
  a clean `make firered` build plus in-game checks, mark it complete and update
  phase status, and record any tech/product/UX decisions as decision docs so the
  project stays self-documenting. Use when the user asks to implement, work on,
  or pick up a story, names a story ID (e.g. "do S07"), or says "the next
  story".
---

# Implement a Story

Drives one story from `STORIES.md` to a verified, documented, complete state.

## Project map

- **Product scope:** `PROJECT.md`. Single source of truth for what is in and out of scope. If a story appears to conflict with it, `PROJECT.md` wins — stop and ask.
- **Build & repo rules:** `AGENTS.md`. Build command, upstream policy, and the "do not do" list.
- **Backlog:** `STORIES.md` (repo root, **not** `docs/`). Ordered stories `S01`–`S70` (S69 sits in Phase 5, S70 sits in Phase 7 after S42), a Milestones table, project conventions, and status conventions.
- **Decision records:** `docs-mf/decisions/`. One markdown file per non-trivial tech/product/UX decision (created on demand — see below). Note the `docs-mf/` prefix: upstream's `docs/` is their mdbook and will conflict on merge.
- **Upstream merge guide:** `docs-mf/UPSTREAM.md` (created in S03).
- **Expansion configs:** `include/config/*.h`. Always check for an existing config before writing new code — `PROJECT.md` says flip what exists first.
- **Feature reference:** [Modern Emerald](https://github.com/resetes12/pokeemerald) — a **spec, not a merge source** (see below).

## Build & verification commands

```bash
make firered -j$(sysctl -n hw.ncpu)   # the only build command; never bare `make`
make check TESTS='MF:'               # Modern FireRed tests on the Emerald TESTELF (ADR 0043)
make clean                            # required when switching between emerald/firered targets
```

Output is `pokefirered.gba`, opened in mGBA.

## Project conventions (while implementing)

`STORIES.md` → "Project conventions" is authoritative; these are the same rules restated for coding. They exist to keep merging from `RHH/master` cheap, and violating them is the main way this project becomes unmaintainable.

| Rule | What it means in practice |
|------|---------------------------|
| **Namespace everything** | Our configs are `MF_*` in `include/config/modern_firered.h`. Our sources are `src/mf_*.c` / `include/mf_*.h`. Never add a field to an upstream struct when a new struct will do. |
| **Minimal upstream diffs** | Prefer a one-line call into an `mf_` helper over inlining logic into an upstream function. Every upstream edit is a future merge conflict — if you touch an upstream file, say so in the summary. |
| **Runtime, not compile-time** | Anything a player can toggle in the rules or Options+ menus must resolve through the S13 accessor, not a `#if`. Adding a `#define` for a player-facing option is a bug. |
| **Never change the Makefile default** | Bare `make` must keep building Emerald. Always pass `firered`. |
| **Save compatibility** | Once S12 lands, changes to the rules struct are additive and go through the S64 versioning path. Never silently reshuffle fields. |
| **Respect GBA limits** | ROM size and save size are hard ceilings — `struct SaveBlock3` is capped at 1624 bytes and has a compile-time assertion. Battle and overworld code runs in hot loops; a rule check inside a damage calculation must be cheap. |
| **Display consistency** | If a change alters a Pokémon's type, stats, moves, or items, the Pokédex, summary screen, and battle UI must all agree. Stale UI is a common and confusing failure here. |

**Conflict rule:** `PROJECT.md`, `AGENTS.md`, `docs-mf/decisions/`, and this skill beat any general ROM-hacking habit or upstream default.

## Porting from Modern Emerald

Many stories cite ME files (`src/tx_rac_menu.c`, `src/tx_randomizer_and_challenges.c`, `src/tx_rac_viewer.c`, `src/options_plus_menu.c`, `include/tx_randomizer_and_challenges.h`).

- **Read ME for algorithms, option lists, data tables, and UX** — its label text, page ordering, and option value ranges are the spec we're matching.
- **Do not copy its C.** ME is pokeemerald + its own patches; our APIs, saveblocks, and UI layer differ, and FireRed's window/font/menu system is not Emerald's. Rewrite the integration.
- Fetch ME sources read-only rather than adding a remote:
  ```bash
  curl -s https://raw.githubusercontent.com/resetes12/pokeemerald/master/<path> -o /tmp/me_<name>
  ```
- **Never** add `resetes12/pokeemerald` as a git remote or merge from it.

## Workflow

Do **not** create a git branch or commit as part of this workflow — stop after implementing and summarizing so the user can review first.

Copy this checklist and track it:

```
- [ ] 1. Select the story
- [ ] 2. Load context (story + PROJECT.md scope + relevant decisions + ME reference)
- [ ] 3. Mark the story In progress + phase In progress
- [ ] 4. Implement per Scope, honoring the Definition of Done
- [ ] 5. Verify: clean build + make check TESTS='MF:' + in-game; confirm every Acceptance bullet
- [ ] 6. Record decisions (docs-mf/decisions/)
- [ ] 7. Mark the story Complete + update the Milestones table
- [ ] 8. Summarize to the user (always end with Manual verification)
```

### 1. Select the story
- If the user named an ID (e.g. `S12`), use it. Otherwise pick the **first** story whose status is `- [ ] **Status:** Not started`, top to bottom.
- **Check dependencies:** read the story's `Depends on:` line. Every listed story must be `Complete`. If not, stop and tell the user which dependency is unmet — do not skip ahead unless they confirm.

### 2. Load context
- Read the entire story (Goal, Depends on, Scope, Acceptance, Tests) **and its phase intro** — phase intros carry constraints that apply to every story beneath them (e.g. Phase 4's hot-path and display-consistency warnings, Phase 9's determinism rule).
- Read the relevant part of `PROJECT.md`. Implement to the product intent, not just the story summary.
- Skim `docs-mf/decisions/` for records relevant to this area so you stay consistent with prior choices.
- **Check for an existing expansion config first.** Grep `include/config/` before writing new code; the story usually names the macro and its current default. Flipping a config beats reimplementing it.
- If the story cites ME files, fetch and read them before designing (see "Porting from Modern Emerald").

### 3. Mark In progress
- Set the story's status marker to `- [ ] **Status:** In progress`.
- In the Milestones table, set the story's phase to `In progress` if it is currently `Not started`.

### 4. Implement
Follow the story's **Scope**. Honor the per-story **Definition of Done** from `STORIES.md`: acceptance criteria met, `make firered` builds clean with no new warnings, `make check TESTS='MF:'` passes, the ROM boots in mGBA, and any non-obvious decision is recorded.

- Apply the project conventions table above while coding.
- Keep the change scoped to this one story. If you discover necessary work outside its scope, note it for a follow-up story rather than expanding silently.
- Many stories embed a decision as an explicit task (e.g. save storage location in S12, preset rule tables in S14, enabled species range in S08, Nuzlocke tier bundles in S39). Make the decision, implement it, and record it (step 6).
- Some stories require **authoring FireRed-specific data** that has no Emerald equivalent — level-cap-by-badge maps (S41), mapsec encounter flags (S35), alternate encounter tables (S32). Verify against Kanto's actual data; do not assume Hoenn's shape.

### 5. Verify (evidence before "done")

Never mark a story Complete on unverified claims. In order:

1. **Build clean.** `make firered -j$(sysctl -n hw.ncpu)`. If you switched targets or changed a widely-included header, `make clean` first. Zero new warnings in our `mf_*` files.
2. **Test.** Run `make check TESTS='MF:'` and the story's own **Tests** bullet. The runner still targets the Emerald build — if a test cannot cover FR-only code, say so explicitly rather than claiming coverage you don't have. The full expansion suite is not part of the gate (ADR 0043).
3. **Boot.** Confirm `pokefirered.gba` loads in mGBA and reaches the overworld.
4. **Play the acceptance path.** Walk each **Acceptance** bullet in-game and confirm it is actually satisfied. If something fails, fix it and re-run from step 1.
5. **Check budgets** for data-heavy stories (dual tables, new save fields): report the ROM size delta and confirm any save-struct size assertion still holds.

For rules-engine work, the S17 debug inspector is the fastest way to confirm values landed. For new-game flow work, use the S05 mGBA save-state workflow rather than replaying the intro.

### 6. Record decisions (keep the project self-documenting)

Create a decision record whenever the story involved a non-trivial, hard-to-reverse, or preference-setting choice in any of these areas:

- **tech** — architecture, data layout, save format, performance trade-offs, tooling, upstream-divergence choices.
- **product** — scope, rule semantics, preset contents, difficulty balance, what to exclude from ME.
- **ux** — menu layout, option labels and descriptions, how a restriction is communicated to the player.

Do **not** write a record for trivial or obvious implementation details. When in doubt for a genuinely load-bearing choice, write it.

Two cases are specific to this project and should almost always get a record:
- **Deviating from ME** — if we drop, rename, or reshape one of its options, capture why so the omission reads as deliberate.
- **Diverging from an upstream expansion default** — if we override a `GEN_LATEST` config or fork upstream behavior, capture why, because the next `RHH/master` merge will surface it as a conflict.

See [decision record format](#decision-record-format) below.

### 7. Mark Complete
- Set the story's status marker to `- [x] **Status:** Complete`.
- Update the Milestones table: set the phase to `Complete` if **all** its stories are now Complete; otherwise leave it `In progress`.

### 8. Summarize
Report concisely: what was built, files touched (**call out any upstream files you had to modify, and why**), build and test results, ROM/save size impact if relevant, decision records created, and the next Not-started story.

**Always end the summary with a Manual verification section** — even when there is nothing to check by hand:

```markdown
## Manual verification
- …
```

Because this is a ROM hack, most stories land here rather than in automated tests. Give concrete mGBA steps: where to go, what to press, what should happen. Prefer short, ordered bullets, and include the setup needed to reach the state (which rules to select at new game, which debug-menu option to use, which save state to load).

If there is genuinely nothing to verify by hand (tooling, docs-only, or fully covered by `make check` with no in-game change), still include the section with a single line: `N/A`.

## Decision record format

- **Location:** `docs-mf/decisions/`
- **Filename:** `NNNN-<type>-<slug>.md` — `NNNN` is the next zero-padded sequence number across the folder; `<type>` is `tech` | `product` | `ux`; `<slug>` is a short kebab title. Example: `0004-tech-rules-save-storage.md`.
- On first use, create `docs-mf/decisions/README.md` as an index (a table of `ID | Type | Title | Story | Date`) and append a row for each new record.

Template:

```markdown
# NNNN — <Title>

- **Type:** tech | product | ux
- **Status:** Accepted
- **Date:** YYYY-MM-DD
- **Story:** S## (or —)
- **ME reference:** <ME file or option> (or —)
- **Expansion config:** <macro + default> (or —)

## Context
Why a decision was needed; the forces at play.

## Decision
What was decided, stated plainly.

## Alternatives considered
- <option> — why not chosen.

## Consequences
Trade-offs, follow-ups, upstream-merge implications, and any affected stories or future work.
```

## Guardrails

- **No git branch/commit:** Never checkout a new branch or commit code during this workflow. Leave all changes uncommitted on the current branch so the user can review first. Only branch or commit if the user explicitly asks afterward.
- **Never change the Makefile default target** to FireRed, and never build with bare `make`.
- **Never merge from Modern Emerald or `cawtds/pokefirered-expansion`.** ME is a read-only reference; the standalone FR expansion is obsolete.
- Never mark a story Complete without a clean `make firered` build, `make check TESTS='MF:'`, and confirming its Acceptance bullets in-game.
- Always end the story summary with a **Manual verification** section (concrete mGBA steps, or `N/A`).
- Never start a story with unmet dependencies without explicit user confirmation.
- **Never invent scope.** `PROJECT.md`'s "Explicitly out of scope" list (story edits, map changes, followers, music packs, Battle Frontier) is binding. If a story seems to require out-of-scope work, stop and ask.
- **Data-loss stories need extra care.** S36 (Nuzlocke faint deletion) and anything else that deletes player Pokémon must ship with a debug dry-run and tests for every deletion path, including the last-Pokémon case.
- **Randomizer stories must stay deterministic.** Route all randomness through the S16 seeded service; never call `Random()` directly. Assert progression is still possible (HM availability in Kanto) before marking complete.
- Edit `STORIES.md` status only for the story in flight (plus its Milestones row).
- Prefer editing existing docs over creating redundant ones; keep `PROJECT.md` authoritative and decision records specific.
