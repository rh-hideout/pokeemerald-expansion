# AGENTS.md

Instructions for AI agents and contributors working in this fork of `rh-hideout/pokeemerald-expansion`.

## Scope

This fork is the base for a living-world Pokemon game. The `design/` folder holds the design docs. Engine code is unchanged from upstream until Gate A passes (see `design/technical-feasibility-audit.md`).

## Where to start

1. `design/STATUS.md` is the **single source of truth** for decision status. If any other file says "LOCKED" and STATUS.md disagrees, STATUS.md wins.
2. `design/README.md` has the reading order.
3. `design/technical-feasibility-audit.md` has the verified source facts and the Gate A to D test plan.

## Active specs in `design/root/` (read and use)

- `balanced-pokemon-sandbox.md`
- `parallel-player-progression.md`
- `hybrid-wild-encounters.md`
- `hybrid-world-geography.md`
- `world-clock.md`
- `individual-persistence.md`
- `save-budget.md`

## ARCHIVED specs in `design/root/` (do NOT read, cite or implement)

These 20 files are speculative simulation designs written before the baseline build ran and before save space was measured. They are kept only so nothing is lost. **Do not enter them, do not treat anything in them as locked or decided, and do not build against them.** They are reconsidered one at a time only after the gate they depend on passes, and only when the project owner asks.

- Wild Pokemon: `utility-ai`, `hybrid-navigation`, `multi-sensory-perception`, `population-ecology`, `hybrid-reproduction`, `ecological-migration`, `social-memory`, `evolving-personality`
- Off-screen: `offscreen-scheduler`, `hybrid-catchup`, `adaptive-scheduling`, `shared-world-events`
- NPCs: `npc-persistence`, `npc-routine-utility`, `npc-social-memory`, `npc-evolving-personality`, `npc-hybrid-navigation`, `npc-contextual-perception`, `npc-information-sharing`, `npc-dynamic-groups`, `npc-long-term-goals`, `npc-hierarchical-planning`, `npc-resource-management`
- Economy: `regional-dynamic-economy`

Topic docs in `design/` (for example `ecosystem-simulation.md`, `living-npcs.md`) are active at the level of detail STATUS.md allows. Where they link to an archived spec, ignore the link.

## Rules

1. **Never mark anything "locked"** or change its level in STATUS.md without an explicit decision from the project owner.
2. **Measure before specifying.** No byte counts, population caps or performance claims without a measured build.
3. **Do not change engine code** before Gate A (an unchanged compile with recorded ROM size and memory use) passes.
4. **Report build state honestly.** Never say something builds or works unless it was actually run.
5. **Work on a branch and open a pull request.** Do not commit directly to the default branch.
6. **Keep one source of truth.** Update STATUS.md when status changes, and do not duplicate status lists elsewhere.
7. **Build in phases.** Prove the first vertical slice (a compact Meadowmere) before expanding.
