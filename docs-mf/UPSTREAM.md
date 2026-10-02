# Upstream merge workflow

How to pull from [rh-hideout/pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion) (`RHH/master`) without losing Modern FireRed work.

Our product docs and ADRs live under **`docs-mf/`**, not upstream’s `docs/` (their mdbook). Do not put Modern FireRed guides in `docs/`.

## Remotes

Expected remotes (names matter for the commands below):

| Remote | URL |
| ------ | --- |
| `origin` | this fork (`rdenman/modern-firered` or your fork) |
| `RHH` | `https://github.com/rh-hideout/pokeemerald-expansion.git` |

Check:

```bash
git remote -v
```

If `RHH` is missing:

```bash
git remote add RHH https://github.com/rh-hideout/pokeemerald-expansion.git
```

Do **not** add Modern Emerald (`resetes12/pokeemerald`) as a remote or merge from it. ME is a read-only spec — fetch individual files with `curl` when needed (see `AGENTS.md`).

## Fetch and merge

Prefer a normal merge (not rebase) so upstream history stays visible and conflict resolution is reviewable.

```bash
git fetch RHH master
git merge RHH/master
```

If the merge is a no-op (`Already up to date.`), you are current; still run the [post-merge checklist](#post-merge-checklist) after any local change that might interact with upstream headers or the Makefile.

### Conflict strategy by area

| Area | Prefer | Then |
| ---- | ------ | ---- |
| `include/config/*.h` | **Theirs** (RHH) for the shared file body | Re-apply our compile-time flips. Our knobs live in `modern_firered.h` / `mf_species_enabled.h` (ours). Re-apply the `modern_firered.h` include in `global.h` and the `mf_species_enabled.h` include immediately after `species_enabled.h` in `pokemon.h` if those files conflict. |
| `.github/workflows/build.yml` | **Ours** (FireRed ROM + `make check TESTS='MF:'` — ADR 0002 / 0043) | Re-apply any new shared install/cache steps from RHH that we still need. |
| `Makefile` | **Theirs** for shared rules | Keep our `mf_%.o` warning policy, the `MF_CPPFLAGS` hook, and never change the default target to FireRed. |
| `src/mf_*.c`, `include/mf_*.h`, `include/config/modern_firered.h`, `include/config/mf_species_enabled.h`, `docs-mf/` | **Ours** | These should not exist upstream; if they collide, something is wrong. |
| One-line call sites into `mf_` helpers inside upstream `.c` files | Resolve carefully | Keep the `mf_` call; take upstream’s surrounding logic. |
| `include/global.h` (MF include line) | Keep our `#include "config/modern_firered.h"` | Take upstream’s surrounding includes. |
| `include/global.h` (`SaveBlock3.mfRules`) | Keep `mf_rules.h` include + `mfRules` field (ADR 0012) | Take upstream’s other SB3 fields; re-append ours last. |
| `test/save.c` (`T_SAVEBLOCK3_SIZE`) | Update when SB3 layout changes | Upstream bumps this for their SB3 growth; reconcile with our `mfRules` size. |
| `include/config/pokemon.h` (MF species hook) | Keep `#include "config/mf_species_enabled.h"` right after `species_enabled.h` | Take upstream’s other pokemon config; extend `mf_species_enabled.h` if RHH adds new `P_GEN_*` / form switches (ADR 0008 / `SPECIES_BASELINE.md`). |
| `include/debug.h` / `src/debug.c` (MF debug hook) | Keep `struct DebugMenuOption` + public `DebugAction_OpenSubMenu` / `DebugAction_Cancel` / `Debug_RefreshCurrentMenu` / `Debug_CloseMenuFull` in the header, and the **Modern FireRed…** main-menu row | Take upstream’s other menu/API changes; re-point the main-menu row at `gMfDebugMenuOptions` if the table is rewritten. |

After resolving config conflicts, diff against `RHH/master` for each flipped macro and confirm our intended value is still present (Phase 1+ stories document which flips we own).

## Post-merge checklist

Run from a clean tree after the merge commit exists:

```bash
make clean
make firered -j$(sysctl -n hw.ncpu)
make check TESTS='MF:'
```

Confirm:

1. `pokefirered.gba` is produced and boots in mGBA.
2. `make check TESTS='MF:'` is green (Emerald TESTELF, MF tests only — ADR 0043).
3. No new warnings in `src/mf_*.c` / objects built by the `mf_%.o` rule.
4. If save structs changed upstream, re-read S12 / S64 notes before shipping — never silently reshuffle our rules blob.

## Naming conventions

Keep Modern FireRed symbols and files out of upstream namespaces so `RHH/master` merges stay cheap.

| Kind | Convention | Location |
| ---- | ---------- | -------- |
| Compile-time configs | `MF_*` | `include/config/modern_firered.h`; species-range overrides in `include/config/mf_species_enabled.h` (ADR 0008) |
| Runtime C sources | `mf_*.c` | `src/mf_*.c` |
| Runtime headers / helpers | `mf_*.h` | `include/mf_*.h` |
| Decision records | `NNNN-<type>-<slug>.md` | `docs-mf/decisions/` |
| Unit tests | `MF:`-prefixed `TEST` names | `test/modern_firered/` (Emerald `make check` — see `docs-mf/TESTING.md`) |

Rules:

1. **Do not** add Modern FireRed toggles to upstream `include/config/*.h` files. Put them in `modern_firered.h` (or `mf_species_enabled.h` for the S08 species-range overlay).
2. **Do not** add fields to upstream save/menu structs when a dedicated `mf_` type will do.
3. Prefer a one-line call into an `mf_` helper over inlining logic into an upstream `.c` function.
4. Master switches (`MF_RULES_ENGINE`, `MF_RANDOMIZER`, `MF_NUZLOCKE`, `MF_OPTIONS_PLUS`) compile out whole unfinished subsystems. They are not player options — those go through the runtime rules layer (ADR 0003).
5. `modern_firered.h` is included from `include/global.h` immediately after `config/general.h` (one upstream edit site). After an upstream merge that rewrites that region of `global.h`, re-apply that include. Do not hang it off `general.h` — tool and asm preprocess consumers of `general.h` break.
6. `mf_species_enabled.h` is included from `include/config/pokemon.h` immediately after `species_enabled.h`. After an upstream merge that touches that include, re-apply the hook; extend the MF override file rather than editing RHH’s `P_GEN_*` defaults.

Override a master switch without editing the header (do **not** pass bare `CPPFLAGS+=…` — that replaces the Makefile’s include paths):

```bash
make firered -j$(sysctl -n hw.ncpu) MF_CPPFLAGS='-DMF_RULES_ENGINE=0'
```

`MF_VERSION` in `modern_firered.h` is the compile-time stamp for this config contract (distinct from the save-backed rules `version` field owned by S12/S64).

## Trial merge log

| Date | `RHH/master` tip | Result |
| ---- | ---------------- | ------ |
| 2026-09-11 | `d74f64dc9f` (merge-base; 0 commits behind) | Already up to date. Post-merge checklist run green — see S03. |
| 2026-10-02 | `dfb0f84374` (1.17.1 / start of 1.17.2; 32 commits) | Clean merge on `merge-rhh`; no conflicts (hot files untouched). |
