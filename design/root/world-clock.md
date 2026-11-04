# World clock — root decision

**Decision: LOCKED (2026-11-04).** Use an **in-game-only clock**. The world progresses during active gameplay; closing the game freezes the world. **No offline catch-up** on reopening, regardless of how many real days pass.

## Purpose and inspiration

The goal is a believable world of autonomous Pokémon and people, partly inspired by **Rain World**: creatures have their own needs, territory, schedules, interactions and outcomes, even when the player is elsewhere. This borrows its *simulation philosophy*, not its rain countdown, forced shelter deadline, universal hostility or permanent starvation. Our game is safe by default and dangerous by choice.

## Locked behavior

1. Time moves forward only when the game is actively simulating. Saving and closing the game preserve the current world timestamp.
2. Loading a save resumes from that timestamp; **never calculate progress from the device's wall clock**.
3. NPC routines, hunger, creature recovery/growth, plant regrowth and ecosystem updates all consume the same monotonic in-game elapsed-time service.
4. Off-screen entities may be updated in bounded batches, but only to catch up with **in-game time that actually passed** while playing. There is no time debt from a closed game.
5. Visual day/night cycles and weather should agree with the simulated time. Existing RTC-driven mechanics must be audited and adapted; simply leaving real-time berry growth enabled would contradict this decision.
6. No mandatory global countdown or Rain World-style death cycle. Local hazards and scarcity may still create pressure.

## Interfaces to design (not yet implementation)

- `WorldTime_Now()`: monotonic in-game tick or minute count persisted in save.
- `WorldTime_Advance(delta)`: called by active simulation; never by save-load elapsed wall time.
- `WorldTime_ElapsedSince(lastUpdate)`: elapsed simulated time, bounded for safe batch processing.
- `WorldTime_GetDayPhase()`: derive morning/day/evening/night for NPCs, species and visuals.

These are **conceptual interface names**, not claims about existing Expansion functions.

## Parameters still open

| Question | Status |
|---|---|
| Length of a full in-game day | Open |
| Which gameplay activities advance time (movement, battle, menus, dialogue, cutscenes) | Open |
| Whether explicit pause freezes time | Likely yes, confirm |
| Weather transition cadence | Open |
| Berry growth conversion from RTC to game time | Requires engine audit |
| Time arithmetic, rollover, save migration and clock-reset handling | Requires implementation design |

## Acceptance examples

- Close the game for a week; load: no NPC, hunger, growth or ecology progress occurs during that week.
- Walk for an hour of **simulated** time: NPCs and Pokémon update, including those off-screen.
- Change maps: update nearby/off-screen state without simulating the entire world frame by frame.
- Repeated save/load without playing does not move the clock.
