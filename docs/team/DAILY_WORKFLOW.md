# Daily Workflow

How to work on the hack day to day, once you've finished [ONBOARDING.md](ONBOARDING.md).

```
Pull → New branch → Edit → Build & Play → Commit → Push → Pull request → (merged) → back to master
```

---

## Before you start

- **Claim your work.** Check the team's task list (GitHub Issues) and say what you're working on, especially **which maps**.
  Two people editing the same map at the same time causes conflicts that are painful to fix.
- **Close Porymap** if it's open from last time; you'll reopen it after pulling.

---

## 1. Get the latest version

In GitHub Desktop:
1. **Current Branch → `master`**
2. Click **Fetch origin**, then **Pull origin** if it appears.

---

## 2. Make a branch for your task

1. **Current Branch → New Branch**
2. Name it after the task, with no spaces: `oldale-new-npc`, `route-102-trainers`, `rival-dialogue`
3. Make sure it's based on **master**, then **Create Branch**.

One branch per task. Small tasks are easier to review and merge.

---

## 3. Make your changes

| I want to change… | Use | Where |
|---|---|---|
| Map tiles, NPC placement, warps, signs | Porymap | Open the map from the **Groups** tab |
| Wild Pokémon | Porymap | **Wild Pokémon** tab on the map |
| Dialogue and events | VS Code | `data/maps/<MapName>/scripts.pory` |
| Trainer teams | VS Code | `src/data/trainers.party` |
| Anything else | **Ask first** | |

**Rules**
- Edit `.pory` files, **never** `scripts.inc` files next to them (those get regenerated on every build).
- In Porymap, keep the **padlock** in the Groups tab **locked**.
- Don't use maps ending in `_Frlg` (FireRed maps, not part of our game).
- If Porymap asks to **reload** because files changed, click **Yes**.
- Adding art or music from somewhere? Note the creator and link in `CREDITS.md` **now**, not later.

**Never share the game file (`.gba`).**
- Don't post `pokeemerald.gba` anywhere public (Discord servers, forums, file-sharing links), and don't send it to people outside the team.
- A built `.gba` contains the original Pokémon Emerald, so sharing it is sharing Nintendo's game. Everyone on the team builds their own copy with Build & Play.
- Show progress with **screenshots or videos** instead. Public releases will be **`.bps` patches** only, made by the maintainer.
- Git already ignores `.gba` files, so GitHub Desktop never lists them. Don't rename or move one to get around that.

---

## 4. Test it: Build & Play

1. **Save** everything (Porymap: **File → Save All**; VS Code: **File → Save**).
2. Double-click **`Build & Play`** in the project folder (`.command` on Mac, `.bat` on Windows).
3. The game opens in mGBA. Most changes take seconds; changes to settings files can take a minute or more.

**Testing tips**
- **Debug menu:** in the overworld, hold **S** and press **Return/Enter** → warp anywhere, give items/Pokémon, set flags.
- **Save states:** **Shift+F1** saves, **F1** loads (add **fn** on most Macs). Save right before the thing you're testing.
- **Build failed?** The window stays open with the error. Screenshot it and send it to the maintainer.
  To undo everything back to the last commit: GitHub Desktop → right-click the changed files → **Discard changes**.

Repeat steps 3 and 4 as many times as you like.

---

## 5. Commit (save a checkpoint)

1. In GitHub Desktop, look at the **Changes** list on the left.
   - ✅ Keep files you meant to change.
   - ❌ Uncheck anything unexpected, or right-click → **Discard changes**. If you're unsure, ask.
2. Write a short **Summary** of what you did: `Add Oldale fisherman NPC`, `Rebalance Route 102 trainers`.
3. Click **Commit to `your-branch`**.

You can commit several times on the same branch.

---

## 6. Push and open a pull request

1. Click **Publish branch** (first time) or **Push origin** (after that).
2. Click **Create Pull Request**. A browser page opens.
3. ⚠️ Check **base repository** = **`poke-pals/project-poke-flora`** and **base** = **`master`**.
   If it says `rh-hideout/pokeemerald-expansion`, change it. That's the original project, not ours.
4. Describe what you changed and how to see it in game (which map, what to talk to).
5. Click **Create pull request**.

**After you open it**
- GitHub automatically builds the game. A ✅ means it built; a ❌ means something broke (message the maintainer).
- GitHub does **not** provide a download of the game; to try someone else's change, switch to their branch in GitHub Desktop and use Build & Play.
- The maintainer reviews it and may leave comments. To make changes, just edit, commit, and push to the same branch again.

---

## 7. After it's merged

1. GitHub Desktop: **Current Branch → `master`** → **Pull origin**.
2. You can delete the old branch (**Branch → Delete**).
3. Start your next task at step 2.

---

## Quick reference

| Situation | What to do |
|---|---|
| "Merge conflict" in GitHub Desktop | Stop, don't guess. Screenshot it and message the maintainer. |
| Build & Play says tools are missing | Run the setup script again (see [ONBOARDING.md §2](ONBOARDING.md#2-run-the-setup)). |
| Map shows pink/magenta | It's a `_Frlg` (FireRed) map. Use a different map. |
| My change doesn't show in game | Did you save the file? Did Build & Play finish without errors? Are you testing the right map? |
| I edited the wrong branch | Don't commit. Message the maintainer; it's fixable. |
