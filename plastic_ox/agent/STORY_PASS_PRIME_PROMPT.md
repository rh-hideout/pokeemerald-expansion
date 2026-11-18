# Pokémon Plastic Ox — Goldenrod-area story pass (prime-agent subagent runs 6-9)

You are a prime-agent subagent working in `/home/eddie/repos/poke-plastic-ox` (pokeemerald-expansion 1.16.3, branch `codex/metamon-trainer-ai`). A coordinator drives SEQUENTIAL subagent runs (builds conflict in parallel, so never run concurrently with another subagent). Your task names exactly ONE run — execute only that run, then reply to the parent with your summary. Leave all changes uncommitted; the coordinator reviews the diff between runs.

## Run map (context only — you execute the one your task names)

- RUN 6 — Goldenrod City overworld (goals: Rocket NPC removal; unique NPC/sign dialogue; north gate wiring; natural south exit)
- RUN 7 — Underground + Bill's family (haircut brothers day-of-week; underground trainers; Bill family dialogue; kimono girl + Ancient Steel Tablet gate)
- RUN 8 — Radio Tower + Department Store (5F Zapdos gate; unique tower dialogue; mart redesign; vending machine 1000 coins)
- RUN 9 — Route 35 / National Park (park gatehouse transition; sudowoodo/north path; route 35 trainers)

## Environment facts (verified, trust these)

- Repo: `~/repos/poke-plastic-ox`, pokeemerald-expansion 1.16.3, branch `codex/metamon-trainer-ai`. Build: `DEVKITARM=~/devkitpro/opt/devkitpro/devkitARM make -j8` from repo root (toolchain NOT in PATH). ROM/elf land at repo root. Incremental rebuilds after data edits are quick.
- The working tree carries UNCOMMITTED in-flight work (earlier agent runs plus unrelated camera-seam/src edits such as `src/overworld.c`, `src/fieldmap.c`, `src/dma3_manager.c`, `src/wild_encounter.c`, `data/wild_encounters.json`). Do NOT revert, stash, or commit anything; work on top. Leave your own changes uncommitted too.
- `src/data/trainers.h` is AUTO-GENERATED from `src/data/trainers.party` via trainerproc (`trainer_rules.mk`). Edit the `.party` file, never the generated `.h`. Story battles use custom `TRAINER_PLASTIC_OX_*` trainers wired through `data/scripts/plastic_ox_story.inc` and friends — never break existing trainer ids.
- Map data: `data/maps/<Map>/map.json` (object_events, warp_events, coord_events, bg_events, connections). The build regenerates `events.inc`/`header.inc` from map.json — edit the JSON, not the generated .inc. Scripts live in `data/maps/<Map>/scripts.inc` and `data/scripts/*.inc`.
- Imported Johto (HNS) maps must keep `"layout_version": "hns"` and `"include_in_versions": ["emerald"]`; HNS layouts use 640 primary metatiles with Emerald-format 16-bit attributes and a 2x2 border. Never let an HNS map fall back to Emerald partitioning. Donor checkout for more Johto assets: `~/repos/pokehns-expansion`.
- mGBA Python bindings: `~/.venvs/mgba311/bin/python` (system python3 lacks mgba). Harnesses: `plastic_ox/demo/walklib.py`, `plastic_ox/demo/test_story.py` (StoryGame: warp(mapname,x,y), story flags), `plastic_ox/battle/metamon/gym_smoke.py` (boot pattern), and prior playtests `plastic_ox/demo/test_warps_v1.py`, `test_sudowoodo_v1.py`, `test_goldenrod.py`.
- Map audit tools: `python3 /home/eddie/.codex/skills/plastic-ox-map-port/scripts/audit_imports.py /home/eddie/repos/poke-plastic-ox` and `python3 .agents/skills/plastic-ox-map-baseline/scripts/audit_map_baseline.py data/maps/<Map>`.
- Regression suites that must stay green: `plastic_ox/encounter_tables/test_pre_mt_moon_v5_5.py`, `plastic_ox/encounter_tables/test_nu_encounters_v1.py`, `plastic_ox/agent/test_trainer_teams_v2.py`.
- Story bible: `plastic_ox/plastic_ox_story_v7.md` (progression, Bill/Champion reveal, Rocket beats). Dialogue and gating must stay consistent with it. Region flavor: the world is a merged Kanto/Johto/Hoenn region, but NPCs are ordinary citizens — keep meta-commentary subtle, varied, and never repeated verbatim between NPCs. No NPC may share identical dialogue text with another NPC.
- Trainer teams must be Gen 3 PU-compatible (species 1-386, moves/abilities/items as of Gen 3, following the team patterns in `plastic_ox/agent/TRAINER_TEAMS_V2_REPORT.md`).
- ROM space is fine (~26.34 MB used, ~5.66 MB free to the 32 MB wall; see `plastic_ox/battle/metamon/ROM_SPACE_AUDIT.md`).
- Do not break the metamon trainer-AI wiring under `plastic_ox/battle/metamon/` and `src/metamon_*.c`.

## Protocol (every run)

1. Read your run's goals below; study the named files before editing.
2. Apply edits in coherent batches; rebuild (`DEVKITARM=~/devkitpro/opt/devkitpro/devkitARM make -j8`) with zero errors after each batch.
3. Verify dynamically with mGBA (`~/.venvs/mgba311/bin/python`, harnesses under `plastic_ox/demo/`: `walklib.py`, `test_story.py` (StoryGame: warp(mapname,x,y), story flags), `test_warps_v1.py`, `test_sudowoodo_v1.py`, `test_goldenrod.py`); extend harnesses where coverage is missing. Every behavioral change must be exercised in-emulator, not just statically.
4. Keep the regression suites green: `plastic_ox/encounter_tables/test_pre_mt_moon_v5_5.py`, `plastic_ox/encounter_tables/test_nu_encounters_v1.py`, `plastic_ox/agent/test_trainer_teams_v2.py`.
5. Write `plastic_ox/agent/<RUN>_REPORT.md` (goals, changes with files+specifics, dynamic-test evidence, blocked items), then reply to the parent with a concise summary (goals done/blocked, files touched, tests run, ROM size).

---

# RUN 6 — Goldenrod City overworld

## Goals


1. **Remove the Team Rocket NPCs from Goldenrod City.** `data/maps/GoldenrodCity_hns/map.json` currently has ~10 objects with `OBJ_EVENT_GFX_ROCKET_M`/`OBJ_EVENT_GFX_ROCKET_F` graphics (scripts `GoldenrodCity_EventScript_Npc3/5/6/10/11/13/14/15/16/17`). Delete those object events and their now-dead script/text blocks in `data/maps/GoldenrodCity_hns/scripts.inc`. If a removed NPC left an important spot visually empty, you may replace it with an ordinary citizen NPC (non-Rocket graphics) with unique dialogue — but do not force one-for-one replacement; Rocket presence in Goldenrod is not part of the current story stage.
2. **Every remaining Goldenrod City NPC and sign gets unique dialogue.** Right now most city NPCs (`GoldenrodCity_EventScript_Npc5/6/9/10/11/13..19`) all repeat the exact same string ("Roads keep ending somewhere they didn't used to."), and the signs are on-the-nose meta jokes ("The city where maps negotiate", "UNDERGROUND: entrances may vary", "BIKE SHOP: cross-region models"). Rewrite every NPC and sign text so each is unique, grounded in ordinary city life (shopping, the gym, the train, radio, the flower shop, bikes), with at most light references to the merged region. The bike-shop-adjacent NPC should say something like they just got a bike shipment from Hoenn — a concrete trade fact, not a wink at the player. Do NOT change scripts outside Goldenrod City in this run (Radio Tower NPCs are a separate run).
3. **Fix the north gate to Route 35.** The city's north exit is currently a bare coordinate teleport (`GoldenrodCity_hns` coord event (33,9) → script `PoxRegion_goldenrod_route35_a` in `data/scripts/plastic_ox_region.inc`, warping straight to `MAP_ROUTE35_HNS 15,47`), while the imported gatehouse interior `data/maps/Gate_GoldenrodCity_Route35_hns` exists with NPCs but NO warps and is never entered. Make this a natural, traditional transition: the player walks into the gatehouse door (warp event on the city's north opening), crosses the gate interior (wire its two door warps + any guard scripts sensibly), and exits into Route 35 just outside the gate on the route side, matching how the source games handle Goldenrod's north gate. Keep the closed/locked fallback behavior if the current story gating requires it, but the open path must go through the gate interior, not teleport past it. Use the `~/repos/pokehns-expansion` donor (`Gate_GoldenrodCity_Route35_hns`) to confirm the intended warp positions/behavior of the original gate.
4. **Fix the unnatural south exit to Route 33.** The city's south opening (coord event (32,45) → `PoxRegion_route33_goldenrod_b`, warping to `MAP_ROUTE33_HNS 0,23`) is an unnatural mid-map teleport. Rework it into a natural seam: walk out of the city's south edge into the matching edge position of Route 33 (prefer a real map connection or aligned warp pair so the transition reads as walking down the road). Whatever you choose, the arrival position and facing must be continuous with the road (see `plastic_ox/agent/WARP_PLAYTEST_V1_REPORT.md` for the convention this project uses).

## Constraints

- Keep `Pox_WhitneyGuide`, `Pox_ParkRoad`, `Pox_SquirtBottle` and other `Pox_*` story scripts working exactly as now (you may touch their display texts only if a text is duplicated — the Squirtbottle giver is a woman near the flower shop).
- Goal 3/4 changes must keep the story gating intact: study how `FLAG_POX_TRIGGERS_ENABLED` and related flags are used in `plastic_ox_region.inc` before changing the transition scripts, and preserve the closed-fallback semantics the story relies on.
- HNS map rules apply (see environment facts) if you touch layout or connection data.

## Verification (all required)

1. Rebuild with zero errors after each coherent batch.
2. Run the map audit scripts (imports + baseline) for Goldenrod City, the gate map, and Route 33/35 if touched.
3. Drive mGBA checks (`~/.venvs/mgba311/bin/python` with `plastic_ox/demo/test_story.py`/`walklib.py` or `test_goldenrod.py`): walk out the north gate (through the gatehouse interior, both directions), walk out the south edge to Route 33 and back, talk to every remaining city NPC and read the signs (verify no two texts identical, no Rocket NPCs remain, no dead scripts referenced).
4. Keep the three regression suites green; run them at the end.


---

# RUN 7 — Underground + Bill's family

## Goals


1. **Haircut brothers become day-of-week dependent, following the original games.** Today both brothers (`PoxGoldenrod_OlderHaircut`, `PoxGoldenrod_YoungerHaircut` in `data/scripts/plastic_ox_goldenrod.inc`, objects in `data/maps/GoldenrodCity_UndergroundTunnel_hns/map.json` at (6,20) and (6,16)) stand side by side every day and both maximize friendship. Follow the Gen 2 original schedule: the OLDER brother works Tuesdays, Thursdays and Saturdays (good haircut: friendship boost toward maximum, keep current pay ¥500); the YOUNGER brother works Sundays, Mondays and Wednesdays (cheaper ¥300, but a BAD haircut: instead of raising friendship it sets the selected POKéMON's friendship to 0). Neither works on Fridays. Implement with the day-of-week script commands (`getdayofweek`/`VAR_0x8004` pattern; see how the base game gates day-of-week NPCs, e.g. `data/scripts/*.inc` usage) and hidden/visible object events or script-side early exits; the brother who is off-duty must not be standing there that day. The younger brother's text must be honest about the risk after the first bad cut (or play it straight the first time — your call, document it).
2. **Trainers in the Underground with Gen 3 PU-compatible teams.** The underground (tunnel + switches + storage maps: `GoldenrodCity_UndergroundTunnel_hns`, `GoldenrodCity_UndergroundSwitches_hns`, `GoldenrodCity_UndergroundStorage_hns`) currently has only flavor NPCs. Add several (4-6) proper trainers across the underground — varying Pokémon, PU-tier teams (follow the team patterns in `plastic_ox/agent/TRAINER_TEAMS_V2_REPORT.md`; new `TRAINER_PLASTIC_OX_UNDERGROUND_*` entries in `src/data/trainers.party`, never hand-edit `trainers.h`). Give them sight ranges and normal trainer interaction (see how `Pox_PU_ROUTE35` / `TRAINER_PLASTIC_OX_PU_ROUTE35` are wired in `data/scripts/plastic_ox_story.inc` + `data/maps/Route35_hns/map.json` for the established pattern). Keep the coin case item ball, the herb shop granny, and existing flavor NPCs.
3. **Bill's family in Goldenrod gets unique dialogue; grandfather moves out.** `data/maps/GoldenrodCity_BillsHouse_hns/` has three objects: (5,4) male sprite (`OBJ_EVENT_GFX_BILL`) running `Pox_Family` in `data/scripts/plastic_ox_story.inc`, plus Npc2 (woman) and Npc3 (twin). Problems: the `Pox_Family` script speaks the mother's dancer text through a male sprite, all three family members lack distinct voices, and the story bible (`plastic_ox/plastic_ox_story_v7.md`) says the first gift Eevee now comes from the SEA COTTAGE (check where `Pox_Family`/`FLAG_POX_GIFT_FAMILY` is referenced before keeping or moving the Eevee gift — keep it wherever the v7 story needs it, but the Goldenrod house dialogue must work for all members). Required end state: each family member (the mother — the former Ecruteak dancer, the father, and the little sister) has unique dialogue consistent with the v7 story; nobody is a duplicate of another; the grandfather is NOT in this house (he is watching the Sea Cottage); one family member mentions that grandfather is at the cottage. Give the male sprite an appropriate non-Bill civilian graphics id (Bill himself must never be at home — he is the eventual Champion reveal; check available HNS object gfx ids in `include/constants/map_object_constants.h` or the graphics folder).
4. **(DROPPED, pox-2ma.7)** The Kimono Girl / Ancient Steel Tablet gate was never built and is not in the story bible. The Tunnel stair at (12,10) is deliberately open; the kimono guard is a plain NPC beside it, `FLAG_POX_KIMONO_GATE_OPEN` and `FLAG_POX_HIDDEN_UNDERGROUND_STEEL_TABLET` are retired, and `ITEM_ANCIENT_STEEL_TABLET` does not exist. Revisit only if the bible adds a Registeel/Steel Tablet beat.

## Constraints

- Do not touch the switch puzzle mechanics in `UndergroundSwitches_hns` beyond making the kimono gate work; Registeel is explicitly out of scope.
- The bad-haircut friendship reset must apply to the selected party member only (reuse the existing `ChoosePartyMon`/`VAR_0x8004` selection pattern in the current haircut script), must respect the egg case (eggs can't have friendship reset messages shown — handle gracefully), and must not corrupt party data.
- New trainers must be wired the same way as existing PU trainers (trainer_type, sight range, defeat+rematch-less post-battle dialogue), and must appear in `plastic_ox/agent/test_trainer_teams_v2.py`-style checks (extend the suite if it enumerates trainers).

## Verification (all required)

1. Rebuild with zero errors.
2. mGBA (`~/.venvs/mgba311/bin/python`, harnesses in `plastic_ox/demo/`): (a) talk to each haircut brother on at least his working day and an off day (set the day-of-week via the debugger/flags or boot with different RTC day — use whatever the harness supports, e.g. walklib/test_story date control; if day control is impossible in-harness, verify the script logic statically and say so); (b) verify the younger brother's bad cut sets friendship to 0 on the selected mon (read party memory); (c) fight every new underground trainer (species/levels/moves as configured); (d) walk the kimono gate in both states (no tablet → blocked with dialogue; tablet → she takes it and the path opens; re-enter map → still open); (e) talk to all Bill's family members — three distinct dialogues, no dancer text on the male sprite, no grandfather present.
3. Regression suites green at the end.


---

# RUN 8 — Radio Tower + Department Store

## Goals


1. **Top floor of the Radio Tower is inaccessible until the player can catch Zapdos.** `data/maps/GoldenrodCity_RadioTower_4F_hns` has two stair warps to 5F at (19,5)→warp 0 and (29,5)→warp 1 of `MAP_GOLDENROD_CITY_RADIO_TOWER_5F_HNS`; today anyone walks up. The 5F (director/owner floor) must be gated: a guard (or equivalent) blocks both 4F→5F stairs until the player is far enough along to catch ZAPDOS (Zapdos lives in `data/maps/PowerPlant_Frlg` with `FLAG_FOUGHT_ZAPDOS` set when it is caught or defeated — study `PowerPlant_Frlg/scripts.inc` and pick the faithful gating condition; if a cleaner "zapdos encounter available" story flag exists or is trivially addable in the POX flags, you may add one, but document the choice). When locked: unique refusal dialogue from the blocker (manager on a tour / stairwell closed, with a subtle hint at the POWER PLANT's bird). When unlocked: the stairs work normally and the blocker's dialogue changes to something ordinary. Implement with object events + script flags (follow the established `FLAG_POX_*` gating pattern used across `data/scripts/plastic_ox_story.inc`), and make sure BOTH stair warps are blocked (a single visible guard at the choke point is fine if geometry allows, else two).
2. **Radio Tower NPC dialogue becomes unique per NPC.** Every floor's NPCs (`GoldenrodCity_RadioTower_1F..5F_hns` scripts) currently share boilerplate ("GOLDENROD RADIO TOWER! Our voices reach every region." etc. — check all five floors' `scripts.inc`; the 5F trio is identical). Give every NPC unique dialogue grounded in radio work (requests, contests, tech, the lottery, music), consistent with the merged-region setting but subtle; no two NPCs anywhere in the Radio Tower may share identical text (also not with the Goldenrod City overworld texts from run 6). Keep 5F's post-gate NPC dialogue appropriate to the unlocked state.
3. **Department Store mart items per floor, dramatically changed to match the game's real needs.** The store's clerk inventories live in `data/scripts/plastic_ox_goldenrod.inc` (`PoxGoldenrod_Shop2F_Items` ... `PoxGoldenrod_Shop5F_Items`, wired to clerk objects on `GoldenrodCity_DepartmentStore_2F/3F/4F/5F`). Today they sell generic vanilla stock. Redesign each floor's inventory dramatically to serve the actual game: consult the progression/story bible (`plastic_ox/plastic_ox_story_v7.md`), the competitive tier structure (PU/NU/OU trainers; see `plastic_ox/agent/TRAINER_TEAMS_V2_REPORT.md`), and Plastic Ox's changed mechanics (e.g. friendship/haircut economy, coin economy, item ball placement). Each floor should have a clear identity (e.g. competitive battle supplies: healing/status/holds for the current challenge tier; evolution stones; vitamins; useful TMs the game actually teaches) — richer and more useful than now, tuned to when Goldenrod is reached. Do not sell items that would trivialize the story gates. Prices stay engine-standard.
4. **The vending machine gives the player 1000 coins each time it is interacted with.** There is currently NO vending machine in the Goldenrod store (check the floor maps' bg_events/scripts). Add one (a bg_event or object with a vending-machine-looking position on an appropriate floor, or wire the rooftop-style machine) whose interaction pays out 1000 COINS into the COIN CASE (`addcoins` script command; see `data/scripts/obtain_item.inc` for the coin-case/checkcoins pattern — require the COIN CASE, which the game gives in the Underground item ball, and give a clear message when the case is missing or the 9999-coin cap is hit). This is intentionally generous (the Game Corner is in Goldenrod): every interaction pays 1000 coins, unlimited times.

## Constraints

- 5F's existing objects/scripts stay after unlocking (no content deletion, just gating).
- Item ids must exist in `include/constants/items.h` — never invent item ids for marts; the vending machine gives COINS (the coin-case currency), not an item.
- Mart redesign must keep the clerk object wiring intact (`PoxGoldenrod_Shop2F..5F` script hooks; item lists end with `ITEM_NONE` and `.align 2`).
- Do not touch the elevator script (`PoxGoldenrod_Elevator`) destinations; floors stay where they are.

## Verification (all required)

1. Rebuild with zero errors.
2. mGBA (`~/.venvs/mgba311/bin/python`, `plastic_ox/demo/` harnesses): (a) with gating flags unset, walk to both 4F stairs → blocked with the refusal dialogue, cannot reach 5F; set the zapdos-availability flag via the harness → both stairs open, 5F reachable; (b) talk to every Radio Tower NPC on all five floors and diff the texts (no duplicates); (c) open each floor's mart and confirm the new inventories render and purchase correctly (buy a few items); (d) interact with the vending machine without a coin case → refusal; with a case → +1000 coins (read the coin count from memory; also verify the 9999 cap path).
3. Regression suites green at the end.


---

# RUN 9 — Route 35 / National Park

## Goals


1. **Route 35 → National Park gate must be a natural gatehouse transition.** Today `data/maps/Route35_hns/map.json` has a coord event at (17,7) → `PoxRegion_route35_park_a` in `data/scripts/plastic_ox_region.inc`, which teleports the player deep into `MAP_NATIONAL_PARK_NORMAL_HNS` at (39,28) — skipping the gate entirely. The donor checkout `~/repos/pokehns-expansion` has the real Johto gatehouse `Gate_NationalPark_hns` (plus `Gate_GoldenrodCity_Route35_hns` already imported in this repo). Import/wire the National Park gatehouse (following the established HNS import pattern — see environment facts and `plastic_ox/agent/` import scripts) and make the transition natural: walk to the gate entrance on Route 35, warp into the gatehouse interior, cross it, and warp out into the National Park entrance area just past the gate (and the reverse direction), exactly like the source games' Route 35→National Park gate. Preserve the closed/locked fallback semantics if the story needs it (study how `FLAG_POX_TRIGGERS_ENABLED` gating is used in `plastic_ox_region.inc`), but the open path must pass through the gate interior — no mid-map teleports. If a full gatehouse import is disproportionate, a minimal alternative is acceptable ONLY if it still reads as a traditional gate transition — document whichever you choose.
2. **Route 35 → Sudowoodo / north cut path must be a natural transition too.** Route 35's north side leads toward Route 36 and the Sudowoodo tree (`Pox_Sudowoodo` in `data/scripts/plastic_ox_story.inc`, object in `data/maps/Route36_hns`), but today the connection is an unnatural scripted teleport (study `Route35_hns`'s north edge, the cut tree object at (31,6), `EventScript_CutTree` wiring, and any coord events/scripts in `plastic_ox_region.inc` covering route35→route36 movement). Rework it so the player physically walks the path: the cut tree where it belongs, and after cutting it the player walks through the opening and crosses the seam to Route 36 naturally (aligned warp pair or map connection — follow the conventions in `plastic_ox/agent/WARP_PLAYTEST_V1_REPORT.md`). The Sudowoodo encounter chain (`SQUIRTBOTTLE` → battle → tree cleared) must keep working exactly as now (it was playtested green in run 5).
3. **Route 35's NPC-ified trainers become real trainers again.** `data/maps/Route35_hns/map.json` currently has plain NPC objects at (18,41) rocker `Route35_EventScript_Npc2`, (21,23) picnicker Npc3, (22,23) camper Npc4, (14,23) camper Npc5, (15,11) hiker Npc6, (30,7) bug catcher Npc8 (plus `Pox_PU_ROUTE35` at (10,38) which is already a trainer — leave it). Convert each to a proper trainer: `trainer_type` normal with sight ranges, `TRAINER_PLASTIC_OX_ROUTE35_<NAME>` entries in `src/data/trainers.party` with varied Gen 3 PU-tier teams (follow `plastic_ox/agent/TRAINER_TEAMS_V2_REPORT.md` team patterns; never hand-edit `trainers.h`), pre-battle intro and post-defeat dialogue following the established `Pox_PU_ROUTE35` wiring in `data/scripts/plastic_ox_story.inc` (or per-map scripts.inc if that's the pattern used). Trainer rosters must be varied — no two trainers on the route with identical party compositions. Keep `POX_PU_MailGuard` (20,6) and the berry tree working.

## Constraints

- Do not regress run 5's green fixes: re-run `plastic_ox/demo/test_sudowoodo_v1.py` and `plastic_ox/demo/test_warps_v1.py` after your changes (extend `test_warps_v1.py` to cover the new gate/park and route35→36 transitions — it is the project's warp regression harness).
- New trainer ids must not collide with existing `TRAINER_PLASTIC_OX_*` ids (check `include/constants/opponents.h` generation — the build generates it from the party file; verify after build).
- If you import `Gate_NationalPark_hns`, follow the HNS import rules exactly (layout_version hns, include_in_versions emerald, matching tileset assets, behaviors remapped by name — `plastic_ox/agent/remap_metatile_behaviors.py`), and run the import audit afterward.
- The park gate must work in BOTH directions (park→route35→gatehouse→route 35 and back), and arriving positions/facings must be continuous with the roads (conventions in `WARP_PLAYTEST_V1_REPORT.md`).

## Verification (all required)

1. Rebuild with zero errors; run the import audit if you imported assets.
2. mGBA (`~/.venvs/mgba311/bin/python`, `plastic_ox/demo/` harnesses): (a) walk Route 35 → National Park THROUGH the gate interior both directions, verify arrival positions/facing and no mid-map teleport (before/after map-name and coordinates); (b) walk the route 35 north path: cut tree blocks → cut → walk through to Route 36 and back; re-run the Sudowoodo chain test; (c) battle every new Route 35 trainer (verify rosters, levels, moves, sight activation), and confirm the PU route trainer still works; (d) `test_warps_v1.py` and `test_sudowoodo_v1.py` green (extended where noted).
3. Regression suites green at the end.
