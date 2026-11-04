# Living-world Pokémon — design documents

**Status:** These are game-design proposals and decisions, not implemented gameplay features. The codebase is `rh-hideout/pokeemerald-expansion`, forked here as `despairarc000/pokeemerald-expansion`.

## Read in this order

1. [Overview](overview.md) — the grouped vision, agreed direction and unsettled choices.
2. [Dependencies](dependencies.md) — the real prerequisite relationships and root decisions.
3. [World clock](root/world-clock.md) — locked game-time model and remaining tuning parameters.
4. [Individual persistence](root/individual-persistence.md) — locked tiered identity rules and unresolved lifecycle details.
5. [Ecological migration](root/ecological-migration.md) — locked cross-region wildlife movement, constrained by habitat and geography.
6. [Dynamic population ecology](root/population-ecology.md) — locked reproduction, decline, recovery and bounded ecosystem change.
7. [Hybrid reproduction](root/hybrid-reproduction.md) — locked abstract births and persistent family relationships.
8. [Selective social memory](root/social-memory.md) — locked evolving relationships and bounded meaningful memories.
9. [Utility-based wild AI](root/utility-ai.md) — locked need-driven behavior selection and safety overrides.
10. [Evolving personality](root/evolving-personality.md) — locked gradual, experience-driven individual behavioral traits.
11. [Save budget investigation](root/save-budget.md) — verified storage structure, pending measured sizes.

Detailed topic documents follow.

## Topic documents

| Group | Document |
|---|---|
| World | [Regions](regions.md) |
| World | [Exploration](exploration.md) |
| Risk | [Danger and ecosystem](danger-and-ecosystem.md) |
| Risk | [Hazards and natural placement](hazards.md) |
| Pokémon | [Ecosystem simulation](ecosystem-simulation.md) |
| Survival | [Food and survival](survival.md) |
| People | [Living NPCs](living-npcs.md) |
| People | [Trainers and gyms](trainers-and-gyms.md) |
| Travel | [Traversal](traversal.md) |
| Travel | [Riding and mounts](riding-and-mounts.md) |

## Status and provenance

- **Locked foundation:** the Expansion fork is the codebase. This is not a pending rebase.
- **Locked:** the Expansion codebase and the in-game-only world clock (no offline progression). See [World clock](root/world-clock.md).
- **Locked:** tiered Pokémon persistence, with memorable individuals permanently tracked and ordinary populations abstracted. See [Individual persistence](root/individual-persistence.md).
- **Locked:** ecologically motivated migration between reachable habitats and regions. See [Ecological migration](root/ecological-migration.md).
- **Locked:** dynamic populations, natural reproduction and recovery with bounded, playable ecological behavior. See [Population ecology](root/population-ecology.md).
- **Locked:** hybrid reproduction — abstract births for ordinary populations and persistent families for notable Pokémon. See [Hybrid reproduction](root/hybrid-reproduction.md).
- **Locked:** selective evolving relationships and memory for notable Pokémon. See [Social memory](root/social-memory.md).
- **Locked:** utility-based wild Pokémon AI, with urgent safety overrides and bounded updates. See [Utility AI](root/utility-ai.md).
- **Locked:** notable Pokémon have evolving individual personalities shaped gradually by meaningful experiences. See [Evolving personality](root/evolving-personality.md).
- **Still open:** save-space measurement, exact clock tuning, record serialization/limits and several world-balancing details. See [Dependencies](dependencies.md).
- **Original source:** `despairarc000/pokeclaude`, branch `design-docs`, commit `f16c0f9853ffd4556a0be8af15a505cdae64dc66`.
- **Preserved original backup:** `despairarc000/atlasgba`, branch `archive/pokeclaude-design-docs-2026-11-04`, commit `77fdd3ed888ea2d33043728b616fa81940168e52`; a second complete backup is in Google Drive.
- **Revision note:** This directory now organizes and reconciles those plans. Original wording remains recoverable from the archive.
