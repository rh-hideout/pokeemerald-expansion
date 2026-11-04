# Living-world Pokemon: design documents

**Status:** design proposals, not implemented features. Codebase: `rh-hideout/pokeemerald-expansion`, forked as `despairarc000/pokeemerald-expansion`.

**Start with [STATUS.md](STATUS.md).** It says what is locked, proposed, aspirational and open. It overrides any "locked" label inside individual files.

## Read in this order

1. [Overview](overview.md): the grouped vision.
2. [STATUS](STATUS.md): decision status.
3. [Dependencies](dependencies.md): what depends on what.
4. [Technical feasibility audit](technical-feasibility-audit.md): verified source facts and the Gate A to D test plan.
5. [Save budget](root/save-budget.md): storage structure, sizes still unmeasured.

## Topic documents

| Group | Document |
|---|---|
| World | [Regions](regions.md), [Exploration](exploration.md) |
| Risk | [Danger and ecosystem](danger-and-ecosystem.md), [Hazards](hazards.md) |
| Pokemon | [Ecosystem simulation](ecosystem-simulation.md) |
| Survival | [Food and survival](survival.md) |
| People | [Living NPCs](living-npcs.md), [Trainers and gyms](trainers-and-gyms.md) |
| Travel | [Traversal](traversal.md), [Riding and mounts](riding-and-mounts.md) |

## Root specifications (`root/`)

Detailed specs for individual systems. Each file's status is set in [STATUS.md](STATUS.md).

| Area | Files |
|---|---|
| Core pillars | `balanced-pokemon-sandbox`, `parallel-player-progression`, `hybrid-wild-encounters`, `hybrid-world-geography` |
| Time and persistence | `world-clock`, `individual-persistence`, `save-budget` |
| Wild Pokemon simulation | `utility-ai`, `hybrid-navigation`, `multi-sensory-perception`, `population-ecology`, `hybrid-reproduction`, `ecological-migration`, `social-memory`, `evolving-personality` |
| Off-screen simulation | `offscreen-scheduler`, `hybrid-catchup`, `adaptive-scheduling`, `shared-world-events` |
| NPC simulation | `npc-persistence`, `npc-routine-utility`, `npc-social-memory`, `npc-evolving-personality`, `npc-hybrid-navigation`, `npc-contextual-perception`, `npc-information-sharing`, `npc-dynamic-groups`, `npc-long-term-goals`, `npc-hierarchical-planning`, `npc-resource-management` |
| Economy | `regional-dynamic-economy` |

## Provenance

- Original source: `despairarc000/pokeclaude`, branch `design-docs`, commit `f16c0f9853ffd4556a0be8af15a505cdae64dc66`.
- Backup: `despairarc000/atlasgba`, branch `archive/pokeclaude-design-docs-2026-11-04`, commit `77fdd3ed888ea2d33043728b616fa81940168e52`. A second backup is in Google Drive.
- `pokeclaude` was removed because GitHub allows one fork per account within a fork network.
