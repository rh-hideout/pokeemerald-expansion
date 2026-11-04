# Selective evolving relationships and memory — design decision

**Decision: LOCKED (2026-11-04).** Notable Pokémon can retain **selective, evolving social memories** of meaningful encounters with other Pokémon and with the player. Trust, fear, rivalry, family bonds and other salient relationships can influence future behavior. Do not store a complete social graph or every encounter for every creature.

## Purpose

Inspired by Rain World's emergent interactions, the world remembers meaningful history without making all wildlife player-centric. Pokémon can develop rivalries, trust and bonds with each other entirely off-screen.

## Locked rules

1. **Selective, not exhaustive.** Keep a bounded set of significant relationships and/or summarized memories for persistent individuals; ordinary populations have no per-individual permanent social history.
2. **Relationships evolve.** Consequential encounters can change trust, fear, rivalry, attachment and behavior over in-game time. A prior enemy may become an ally after rescue; relationships are not permanently fixed labels.
3. **Autonomous social life.** Pokémon–Pokémon events can form or change relationships without player involvement.
4. **Family relationships matter.** Parent, mate, offspring and caregiving ties from [Hybrid reproduction](hybrid-reproduction.md) can influence protection, travel and social behavior.
5. **Memory affects decisions.** Recognition, avoidance, cooperation, defense, warning and territory responses may depend on relationship state, constrained by species behavior and immediate danger.
6. **Identity-safe references.** Memories referring to a Pokémon must use stable persistent identity and survive map changes, migration and save/load; references must never silently attach to a different individual after record reuse.
7. **Bounded computation and storage.** Social updates must not require simulating every pair of creatures or saving an unbounded event log. Limits and eviction/summarization policies require measurement.
8. **No offline social updates.** Relationship changes and memory decay occur only during in-game simulation time; closing the game freezes them.
9. **No arbitrary deletion of essential bonds.** Capacity handling must preserve important family, player and narrative relationships according to an explicit priority policy to be designed.

## Conceptual model — not a binary format

A notable Pokémon may maintain:
- A small set of **relationship references** to stable identities (other Pokémon or player).
- **Salient dispositions** such as trust, fear, rivalry or attachment.
- **Summarized events** such as rescue, repeated territorial conflict or caregiving.
- A last-update in-game timestamp for gradual behavioral change.

An event may update existing dispositions without storing a separate full event record. Whether memories are directional, reciprocal, decaying or permanent varies by relationship and remains open.

## Example

Two notable Pokémon repeatedly contest a feeding ground and develop rivalry. One later protects the other during a predator encounter. Their remembered hostility may soften, leading to tolerance or cooperation on a future visit. The player need not witness either event.

## Unresolved engineering and design choices

- Maximum social references per individual and storage footprint.
- Which events qualify as meaningful, and how significance is measured.
- How to summarize/evict low-priority memories without breaking family or important history.
- Whether both participants require persistent records for a relationship to survive.
- Social memory and player relationship handling when Pokémon are captured, released or traded.
- Whether traits, species and nature affect emotional change, forgetting and social behavior.
- How social outcomes are communicated through animation, behavior, tracks or NPC dialogue.

No relationship slot count, numeric emotion range, or record byte size is locked.

## Acceptance scenarios

1. A notable Pokémon recognizes a previously encountered rival after a map transition and save/reload.
2. A rescue meaningfully changes a relationship and later behavior.
3. An off-screen Pokémon–Pokémon interaction can change their relationship without player presence.
4. Family ties remain coherent across ecological migration.
5. Routine anonymous encounters do not cause unbounded permanent memory growth.
6. Closing the game for a week does not decay memories or alter relationships.

See [Individual persistence](individual-persistence.md), [Hybrid reproduction](hybrid-reproduction.md), [Ecological migration](ecological-migration.md), and [World clock](world-clock.md).
