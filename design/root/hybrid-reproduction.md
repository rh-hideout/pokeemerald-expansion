# Hybrid Pokémon reproduction — design decision

**Decision: LOCKED (2026-11-04).** Ordinary wild populations reproduce through bounded abstract population updates; notable Pokémon can form **persistent family relationships**, including mates, nests, eggs and offspring. Reproduction follows the in-game-only world clock and does not progress while the game is closed.

## Goals and inspiration

Inspired by Rain World's autonomous creature relationships and observable ecology, the world should show families and reproductive behavior independent of the player. This is not a requirement to simulate or serialize every birth individually.

## Locked rules

1. **Ordinary population births are abstract.** A suitable habitat's population can increase based on reproduction and ecological conditions without creating permanent IDs for every offspring.
2. **Notable Pokémon can have persistent families.** Relevant parent, mate, offspring, nest and egg relationships survive map changes and saves, subject to later storage design. Family bonds may affect behavior through [selective social memory](social-memory.md).
3. **Individual visibility is not mandatory.** Off-screen reproduction and family progress use bounded updates; notable families can be encountered later.
4. **Significance determines persistence.** Ordinary newborns do not automatically consume persistent records. Offspring can become persistent when family importance, meaningful interactions or ecosystem events justify it; exact promotion triggers remain open.
5. **No duplicate accounting.** Births must enter either an aggregate population or a distinct individual record, not both. Promoting a newborn or adult adjusts aggregate counts exactly once.
6. **Ecological constraints matter.** Food, habitat, climate, safety, maturity and compatible species biology shape reproduction and offspring survival/recovery. Exact formulas are not yet locked.
7. **No permanent death assumption.** Fainting is not death; family separation, nest abandonment and population decline must be modeled consistently with the game's no-permanent-death principle.
8. **Capacity safety.** Save budgets, maximum active nests and family references must be measured and bounded. Existing persistent individuals are not silently deleted to make space for births.
9. **No offline progression.** Closing and reopening the game does not advance gestation, egg development, hatching or growth.

## Conceptual flows (not implementation)

### Ordinary habitat

`resources + suitable population -> bounded reproduction update -> aggregate juveniles/new members -> maturation or migration`

### Notable family

`persistent parent(s) -> bond / territory / nest -> egg or offspring -> persistent relationship -> growth, movement, possible later promotion`

An offspring's **relationship** may be meaningful before the implementation assigns it a full independent Pokémon record. The exact lifecycle, storage and presentation must be designed without claiming a specific byte count.

## Engineering questions still open

- Which species reproduce through eggs, which use other biology, and how Expansion's breeding/egg-group mechanics map to wild behavior.
- How mates are selected; whether permanent pairs, seasonal pairs or solitary parenting vary by species.
- How many family references, eggs, nests and offspring can be represented safely.
- Whether every offspring of a notable pair receives a persistent ID immediately or only upon significance; the latter is more compatible with tiered persistence but is not yet fixed.
- How to keep family relationships coherent across migration, capture, release, evolution and ownership transfer.
- How to prevent population inflation when a notable nest hatches and abstract habitat counts also update.
- How nesting, caregiving and juvenile behavior appear on-screen versus off-screen.

## Acceptance scenarios

1. A common habitat gradually grows its population without creating a saved Pokémon record for every newborn.
2. A notable pair can maintain a recognizable nest and offspring relationship across map transitions and saves.
3. Closing the game for a week does not hatch eggs or age offspring.
4. A notable offspring can later migrate while retaining its identity and family relationships.
5. Birth accounting never creates both an anonymous population member and a second copy of the same persistent Pokémon.
6. Exhausted save capacity does not silently erase a previously tracked parent or offspring.

See [Population ecology](population-ecology.md), [Individual persistence](individual-persistence.md), [Ecological migration](ecological-migration.md), and [World clock](world-clock.md).
