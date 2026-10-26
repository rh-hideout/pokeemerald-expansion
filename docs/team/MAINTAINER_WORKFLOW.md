# Maintainer Workflow

How to run the project as owner and maintainer (`dabaquita`).
Friends' side: [ONBOARDING.md](ONBOARDING.md) and [DAILY_WORKFLOW.md](DAILY_WORKFLOW.md).

- **Repo:** <https://github.com/poke-pals/project-poke-flora> (`poke-pals` org, Free plan, public fork of RHH's `pokeemerald-expansion`)
- **Your clone:** `~/dev/pokeemerald-expansion` (`origin` = our repo, `rhh` = upstream, pushes disabled)

---

## Still to do

- [ ] **Give members write access:** org **Settings → Member privileges → Base permissions → Write**.
  - Right now it's **Read**, so friends couldn't push branches.
- [ ] **Protect `master`:** repo **Settings → Branches → Add rule** for `master`.
  - Turn on **Require a pull request before merging**.
  - Turn on **Require status checks to pass**, then pick **CI passed**.
- [ ] **Test Windows setup** with your first Windows friend (the scripts haven't run on real Windows yet).
- [ ] **PR template:** replace RHH's `.github/pull_request_template.md` with a short team one.
- [ ] **Decide on `CODEOWNERS`:** require your review for `src/`, `include/`, `Makefile`, `.github/`?

---

## Add a teammate

1. Get their GitHub username.
2. Invite them: <https://github.com/orgs/poke-pals/people> → **Invite member** → role **Member**.
3. Send them [ONBOARDING.md](ONBOARDING.md).
   - ↔ Their step: [§1 Accept the GitHub invite](ONBOARDING.md#1-accept-the-github-invite).
4. Let them work through it **without helping unless they're stuck**. Every stuck point is a doc fix.
5. Their last onboarding step is a test PR. Review and merge it (below).
6. Check nothing landed on RHH by mistake: <https://github.com/rh-hideout/pokeemerald-expansion/pulls?q=author:THEIR-USERNAME>.

---

## Review and merge a pull request

1. Open the PR: <https://github.com/poke-pals/project-poke-flora/pulls>.
2. Check **CI passed** is ✅.
   - The build runs on every PR (~5 min); tests run too (~25 min).
   - ❌? Open the failed job, find the error, and comment on the PR or help the friend fix it.
3. Read the **Files changed** tab.
   - Maps and text: skim them.
   - Code (`src/`, `include/`, `Makefile`): read carefully.
4. Play it when the change is visible in-game:
   ```bash
   gh pr checkout NUMBER
   ```
   Then build and play (`make`, or double-click **Build & Play**). Go back with `git checkout master`.
5. Merge with **Squash and merge**, then **Delete branch**.
6. If the friend gets a **merge conflict**, fix it with them on a call, or check out their branch, merge `master`, and push.

---

## Rules you enforce

- **Never publish a `.gba`.** Not as a CI artifact, a release file, or a Discord/forum upload. The repo is public.
  - If one ever gets uploaded, delete it and the run that made it:
    ```bash
    gh api -X DELETE repos/poke-pals/project-poke-flora/actions/artifacts/ARTIFACT_ID
    ```
    ```bash
    gh run delete RUN_ID
    ```
- **PRs go into our repo,** never `rh-hideout/pokeemerald-expansion`.
- **Track who owns what** (maps, flags, story beats) in GitHub Issues, so two people don't edit the same map.
- **Credit outside assets** (tilesets, sprites, music) in `CREDITS.md` when they're added.

---

## Update the tools

Versions are pinned in three places. Change them together, in one PR:

| Tool | Where |
|---|---|
| Poryscript | `PORYSCRIPT_VERSION` in `setup/setup-mac.sh` and `.github/workflows/build.yml`; `$PoryscriptVersion` in `setup/setup-windows.ps1` |
| Porymap | `PORYMAP_VERSION` (Mac script), `$PorymapVersion` (Windows script) |
| mGBA (Windows) | `$MgbaVersion` in `setup/setup-windows.ps1` |

Setup skips tools that are already installed. After a Poryscript update, teammates delete `tools/poryscript/poryscript` and run setup again.

---

## Pull in upstream (RHH) updates

Do this between milestones, not in the middle of big content work.

1. On GitHub, **Sync fork** works while `master` has no conflicting changes.
2. Once we've diverged, do it locally on a branch:
   ```bash
   git fetch rhh --tags
   ```
   ```bash
   git checkout -b update/rhh-1.17.1 master
   ```
   ```bash
   git merge expansion/1.17.1
   ```
3. Fix conflicts, build, play-test, and open a PR like any other.
4. When adding C features, watch the **memory report** at the end of each build (EWRAM/IWRAM).

---

## Release builds (later: when there's a playable demo)

Not needed during early alpha. Set this up when you have something worth sharing outside the team,
for example the first town through the first gym.

**What a release build is:** `make release` builds `pokeemerald-release.gba` with `RELEASE=1`,
which turns off debug-only features (the overworld debug menu, battle debug menu, sprite visualizer).

**How hacks are distributed:** as a **`.bps` patch**, never as a `.gba`. Players apply the patch to
their own Emerald ROM.

**Planned process**
1. Freeze content on `master`, play-test, and update `CHANGELOG.md`.
2. Tag the commit:
   ```bash
   git tag v0.1.0 && git push origin v0.1.0
   ```
3. A release workflow (to be added) builds `make release` on the tag, runs tests, and creates a **draft**
   GitHub Release with notes. It does **not** attach the ROM.
4. Locally, build the same tag with `make release`. Then make the patch with
   [Floating IPS](https://github.com/Alcaro/Flips) against your **own clean Emerald ROM**
   (kept outside the repo, never committed):
   ```bash
   flips --create --bps clean-emerald.gba pokeemerald-release.gba project-poke-flora-v0.1.0.bps
   ```
5. Upload the `.bps` to the draft release, check it applies with
   [Rom Patcher JS](https://www.marcrobledo.com/RomPatcher.js/), and publish.

**Versioning:** `v0.x.y` while in development (`x` = milestone such as a new gym, `y` = fixes); `v1.0.0` for the first complete game.

---

## Reference

| Thing | Where |
|---|---|
| Compiler (devkitARM) | `/opt/devkitpro` (env vars in `~/.zshrc`) |
| Poryscript | `tools/poryscript/poryscript` (gitignored) |
| Porymap, mGBA | `/Applications` |
| Build | `make -j$(sysctl -n hw.ncpu)` → `pokeemerald.gba` |
| Check your Mac's setup | `PFLORA_CHECK=1 bash setup/setup-mac.sh` |
