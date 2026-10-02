# Building Modern FireRed

One-command FireRed build for this fork. For OS toolchain install steps, use upstream’s [INSTALL.md](./INSTALL.md) (macOS: [docs/install/mac/MAC_OS.md](./docs/install/mac/MAC_OS.md)).

## Build (FireRed)

```bash
make firered -j$(sysctl -n hw.ncpu)
```

- **Output:** `pokefirered.gba` — open in [mGBA](https://mgba.io/).
- **Do not** run bare `make` for this hack. Bare `make` still builds Emerald (`pokeemerald.gba`); keeping that default avoids upstream merge pain.

Linux / other hosts without `sysctl`: use `make firered -j$(nproc)` (or another parallel job count).

## Toolchain pin (verified on macOS arm64)

| Piece | Pin | Notes |
| ----- | --- | ----- |
| Base | pokeemerald-expansion **1.17.1** (`include/constants/expansion.h`) | Upstream remote: `https://github.com/rh-hideout/pokeemerald-expansion.git` |
| Compiler | **devkitARM** → `arm-none-eabi-gcc` **16.1.0** | Install via [devkitPro pacman](https://github.com/devkitPro/pacman/releases) (`gba-dev`). Set `DEVKITPRO` / `DEVKITARM` as in the macOS install guide. |
| `agbcc` | **Not used** | Expansion’s modern build (`MODERN=1`) is the only supported path; `make agbcc` is deprecated. |
| Python | **3.12** (`.python-version`) | Makefile calls `python3` directly. Keep 3.12+ on `PATH`. |

Also required by upstream install docs: Xcode CLT (macOS), `libpng`, `pkg-config`.

Override the compiler root only if needed:

```bash
make firered TOOLCHAIN="/path/to/devkitARM" -j$(sysctl -n hw.ncpu)
```

## Emerald ↔ FireRed switch hazard

Object files from one game target are **not** compatible with the other. After building Emerald (`make` / `make modern`) or LeafGreen (`make leafgreen`) in the same tree, always:

```bash
make clean
make firered -j$(sysctl -n hw.ncpu)
```

Skipping `make clean` produces confusing link/runtime failures.

## CI

GitHub Actions (`.github/workflows/build.yml`) on push/PR:

| Job | What it runs |
| --- | --- |
| `build-firered` | `make firered` — the product ROM |
| `test` | `make check TESTS='MF:'` — Modern FireRed unit tests on the Emerald test binary |
| `build` | Gate job; require this check in branch protection |

MF unit tests live under `test/modern_firered/`. CI runs that filter only (ADR 0043). A full `make check` still runs expansion’s battle suite locally. Coverage limits and the manual QA template: [`docs-mf/TESTING.md`](./docs-mf/TESTING.md).

Emerald ROM, LeafGreen, and release builds are intentionally not run here.

## Quick verify

1. `pokefirered.gba` exists at the repo root after the FireRed build.
2. Open it in mGBA; confirm the title/intro boots (stock FireRed until later stories change gameplay).
3. For a sub-15s path to overworld debug / Oak-speech save states, see [`docs-mf/DEBUG.md`](./docs-mf/DEBUG.md).
