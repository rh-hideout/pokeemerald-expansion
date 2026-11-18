# 2026-11-18 — goldenrodcity-hns (pox-2ma.7)

## Decision: no kimono / Steel Tablet gate

- The story bible (`plastic_ox_story_v7.md`) never mentions a Steel Tablet, a Registeel beat or a kimono gate here. Only `STORY_PASS_PRIME_PROMPT.md` run 7 goal 4 asked for it, and it needs a brand-new item plus a pickup, which is outside a conservative flag-cleanup bead. The bible wins, so the gate is dropped.
- Removed `FLAG_POX_KIMONO_GATE_OPEN` (0x911) and `FLAG_POX_HIDDEN_UNDERGROUND_STEEL_TABLET` (0x912) from `plastic_ox_flags.h`; ids left retired.
- The Kimono guard (Tunnel) and the Storage guard now use hide flag `0`, so they are plain permanent NPCs. The stair at Tunnel (12,10) stays open.
- Prompt goal 4 marked DROPPED; note open question marked RESOLVED.
- `plastic_ox/demo/test_goldenrod.py` `reservations()` lost its two stale cases that flipped the removed flag (the Radio Tower cases remain). Legacy `plastic_ox/alpha/goldenrod/*.json` snapshots are untouched.
