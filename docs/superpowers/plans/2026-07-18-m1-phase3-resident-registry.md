# M1 Phase 3: Resident Registry Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: superpowers:subagent-driven-development or superpowers:executing-plans. Inline execution (same rationale as prior phases).

**Goal:** Spec §5's resident registry — 96 individualized residents (4 B each: species, personality seed, assignment byte) created on befriend — plus the two resident conditions, closing the Heracross chain mechanic.

**Architecture — one load-bearing decision:** conditions run off the **dex caught flags**, not the registry. Spec §5 says dex caught == befriended and "overflow = befriended but non-individualized, **still counts for conditions**" — dex-backed conditions honor that exactly and are overflow-proof by construction. The registry's job is *individuals*: personality seeds and Grove work assignments (phase 4 consumes). `COND_RESIDENT_SPECIES(species, zone)` with zone 0 is therefore a caught-check; zone-scoped resident queries are deferred until content needs them (the 4 B record has no zone field in spec §5 — flagged in the report).

## Tasks

### T1: Registry storage + creation on befriend
- `include/habitat/save.h`: `struct HabitatResident { u16 species; u8 personalitySeed; u8 assignment; }` and `residents[HABITAT_RESIDENT_COUNT]` (96, config/habitat.h) appended to HabitatSave → SaveBlock3 336→720 B (guard test 340→724; static assert head-room 724 ≤ 1,624 ✓).
- `src/habitat/residents.c`: `Habitat_ResidentCount()`, `Habitat_GetResident(i)`, `Habitat_TryAddResident(species)` (cap-guarded, seeds personality from `Random()`, returns index or -1), `Habitat_FindResidentBySpecies(species)`.
- `spot_manager.c` `CompleteBefriend`: `Habitat_TryAddResident(spot->species)` before the notify.
- Tests: count grows on befriend; entries hold species+seed; 96-cap overflow leaves count at 96 while dex caught still sets; assignment byte starts 0.

### T2: Resident conditions (dex-backed)
- `conditions.c`: `COND_RESIDENT_SPECIES` → national-dex caught check of paramA (paramB zone: 0 supported; nonzero documented-unsupported until residents carry zones). `COND_RESIDENT_COUNT` → iterate species, count caught with type filter (paramA: TYPE_* or `HABITAT_TYPE_ANY` 0xFF), compare ≥ paramB.
- Tests: RESIDENT_SPECIES flips after `Habitat_CompleteBefriendById` on a slice spot; RESIDENT_COUNT with type filter counts befriended Machop (Fighting) but not for TYPE_WATER; ANY filter counts all.
- Heracross chain proof (native): set dex-caught Pinsir + night via `RtcInitLocalTimeOffset(22,0)` + mature zone-1 Leppa → recompute → Heracross ACTIVE. (Where the slice *player* obtains a Pinsir is a content question for Jay — engine mechanic proven regardless.)

### T3: Gates + wrap
- Full `make check`, `make verify` + `--scenario skitty`, EWRAM delta (expect +384 B ≈ +0.15 pt), CHANGELOG, commit per task, merge.

## Self-Review
§5 registry fields verbatim (4 B, cap 96, overflow semantics honored via dex-backed conditions) ✓; RESIDENT_SPECIES/COUNT land (last slice-needed condition types) ✓; personality seed stored for §8's open dialogue-pool format ✓; no Grove/menu/dialogue content (phases 4+, Jay's feel territory) ✓.
