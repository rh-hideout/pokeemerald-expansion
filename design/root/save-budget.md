# Save-space budget — initial code audit

**Status: RESEARCHED, NOT YET MEASURED.** This is the next root blocker before choosing individual-record layouts or tracked population counts. No numeric free-space claim is made.

## Verified in this Expansion fork

Source inspection on 2026-11-04:

- `include/save.h`: `SECTOR_DATA_SIZE = 3968` bytes; `SAVE_BLOCK_3_CHUNK_SIZE = 116` bytes; `NUM_SECTORS_PER_SLOT = 14`.
- `src/save.c`: sector 0 stores `SaveBlock2`; sectors 1–4 store `SaveBlock1`; sectors 5–13 store `PokemonStorage`. Each sector also carries a SaveBlock3 chunk.
- `src/save.c` has compile-time `STATIC_ASSERT` checks ensuring each structure fits its assigned sector budget.
- `include/global.h` declares `SaveBlock1`, `SaveBlock2`, and `SaveBlock3`, with conditional fields depending on feature flags. Actual sizes therefore depend on the chosen configuration.
- `src/rtc.c` supports RTC and a configurable fake RTC; this is **not** the same as the chosen in-game-only world clock.

## Container capacities (not free bytes)

| Storage region | Formula | Total container capacity |
|---|---|---|
| SaveBlock2 | 1 × 3968 | 3,968 bytes |
| SaveBlock1 | 4 × 3968 | 15,872 bytes |
| Pokémon storage | 9 × 3968 | 35,712 bytes |
| SaveBlock3 chunks | 14 × 116 | 1,624 bytes |

**Do not mistake these for available free space.** Existing Pokémon, inventory, flags, and Expansion systems already consume portions. Extra saves, compatibility and flash limits also matter.

## Required next measurements

1. Select the actual build configuration and feature flags.
2. Compile a small size report or inspect the build's ELF/map output to obtain `sizeof(struct SaveBlock1)`, `sizeof(struct SaveBlock2)`, `sizeof(struct SaveBlock3)`, and `sizeof(struct PokemonStorage)`.
3. Compute free capacity per structure **after** alignment and existing fields; reserve margin and compatibility space.
4. Audit runtime EWRAM/IWRAM/ROM and object-event limits separately; flash capacity is not RAM.
5. Decide canonical Pokémon storage ownership, entity ID strategy, record pool, NPC storage and save-version migration.
6. Prototype serialize/load/reload with checksum and bounds tests before setting record counts.

## Dependencies

- [World clock](world-clock.md) — chosen simulated-time semantics.
- [Dependencies](../dependencies.md) — record schema depends on this measurement.
- [Ecosystem simulation](../ecosystem-simulation.md) — individual tracking tiers depend on this budget.

**Persistence policy decided:** [Tiered individual persistence](individual-persistence.md). This does not establish record sizes or counts.

**Next deliverable:** measured structure sizes for a concrete build, then a versioned identity-record proposal.
