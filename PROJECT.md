# Modern FireRed — project scope

FireRed ROM hack that brings **Modern Emerald’s modular challenge/randomizer/QoL philosophy** to Kanto, without rewriting the story or maps.

## References

- **Base:** [rh-hideout/pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion) — build FireRed via `make firered -j$(sysctl -n hw.ncpu)`
- **Feature inspiration:** [Modern Emerald (resetes12/pokeemerald)](https://github.com/resetes12/pokeemerald) — [PokéCommunity thread](https://www.pokecommunity.com/threads/pok%C3%A9mon-modern-emerald-3-5-open-source-double-speed-battles-following-pok%C3%A9mon-better-battle-frontier-and-more.494005/)
- **Not using:** standalone `cawtds/pokefirered-expansion` (frozen; points at RHH FRLG build), CFRU (wrong stack)

## Product intent

Play FireRed with ME-like **start-of-run customization** and strong QoL. Keep vanilla Kanto progression and geography.

### In scope (important)

**Start-of-game options (ME-style pages — all matter):**

1. **Gamemode** — Classic/Modern presets; toggles such as Fairy typing, modern types/stats/movepools, type-chart tweaks, Synchronize/Sturdy behavior, Sitrus behavior, survive poison, reusable TMs, nature mints  
2. **Features** — e.g. shiny rate, item drops (RTC/day-night only if useful later; not a must)  
3. **Randomizer** — modular: wild / trainer / static / starter, similar BST/evo stage, legendaries, types, moves, abilities, evolutions, evo methods, type effectiveness, items, chaos  
4. **Nuzlocke** — Off / Easy / Normal / Hardcore + species clause, shiny clause, nicknaming, faint deletion  
5. **Difficulty** — party limit, level caps, EXP multiplier, catch rate, player/trainer item bans, IV/EV scaling, escape/Dig restrictions, hard-mode EXP behavior  
6. **Challenges** — no Poké Centers, no PC heal, expensive shops, evo limits, monotype, BST equalizer, mirror (± thief)

**Battle modernization:**

- Physical/Special split (high priority; optional at runtime like ME if feasible)
- Fairy type + related move/type data
- New/modern moves and updated movepools (flag-gated dual tables preferred over forcing modern always-on)

**QoL (high priority):**

- Even Faster Joy (and fast Joy generally)
- Bag sorting
- Summary screen EV/IV display (L/R style or expansion’s IV/EV cycle)
- Autorun
- Fast battle intro / fast battles / anim speed
- Type effectiveness / STAB hints in battle where ME has them
- Solo trade evolutions (Linking Cord + bag-use for trade hold items; mart stock, no map/story work) — see STORIES S69
- Other “friction remover” Options+ items from ME that don’t require map/story work

### Explicitly out of scope

- Story changes
- Map changes, new dungeons, legendary dungeon content
- Followers / big followers / surf overworld cosmetics
- Music packs / BGM remix menus as a goal
- Battle Frontier modernization (FR doesn’t have Emerald’s Frontier)
- Turning this into a full National Dex / Gen 9 dump unless decided later

### Later / thin versions only

- Wonder Trade (PC-based; no map required) — after core rules engine
- “Modern encounters” as **data-only** remaps of existing FR routes — OK; anything needing new areas — no
- Extra legendaries that need new maps — no
- HGSS-style dex extras — nice-to-have, not v1 blockers

## Technical approach

1. Fork expansion; always `make firered -j$(sysctl -n hw.ncpu)` (do not Makefile-default to FireRed yet).  
2. Enable free expansion configs first: phys/spec, Fairy, summary IV/EV, reusable TMs, battle speed QoL.  
3. Implement save flags + Oak-speech challenge/randomizer menu (ME’s `tx_*` system as reference).  
4. Hook Nuzlocke → Randomizer → Difficulty/Challenges into gameplay systems.  
5. Port Options+ QoL.  
6. Add flag-gated modern types/stats/movepools for the FR dex.

**Copyability note:** ME C does not drop into FR/expansion cleanly. Reuse algorithms, data tables, and UX design; rewrite integration against expansion’s FireRed APIs and saveblocks.

## Success criteria (v1)

- New game presents a full ME-like options flow (pages above).  
- Chosen rules persist and actually affect gameplay.  
- Phys/spec + Fairy + modern move support work.  
- Core QoL (Joy speed, bag sort, EV/IV summary, autorun, fast battles) works.  
- Story/maps remain recognizable stock FireRed/Kanto.
