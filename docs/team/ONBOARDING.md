# Getting Started

Set up your computer to work on the game. You only do this **once per computer**.

- ⏱️ About 30–60 minutes, mostly waiting
- 💻 Works on Mac or Windows 10/11
- 🆘 Stuck at any point? Take a screenshot and send it to the maintainer.

**You'll need:**
- A free GitHub account: <https://github.com/signup>
- Your computer's password

---

## 1. Accept the GitHub invite

1. Send the maintainer your GitHub username.
2. Open the invite email and click **Join poke-pals**.
   - No email? Sign in to GitHub and go to <https://github.com/orgs/poke-pals/invitation>.

---

## 2. Run the setup

This installs everything and downloads the project. Just copy, paste, and wait.

### Mac

1. Press **⌘ + Space**, type **Terminal**, press **Return**.
2. Copy this line, paste it into Terminal, press **Return**:
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/poke-pals/project-poke-flora/master/setup/setup-mac.sh)"
   ```
3. When it asks for your **password**, type it and press **Return**.
   - Nothing shows while you type. That's normal.
   - It may ask a few times.
4. If a window pops up asking to install tools, click **Install**.

### Windows

1. Click **Start**, type **PowerShell**, click **Windows PowerShell**.
   - Open it normally. **Don't** pick "Run as administrator".
2. Copy this line, paste it (right-click), press **Enter**:
   ```powershell
   irm https://raw.githubusercontent.com/poke-pals/project-poke-flora/master/setup/setup-windows.ps1 | iex
   ```
3. Click **Yes** on any "allow changes" popups.
4. If it tells you to **restart**:
   1. Restart your computer.
   2. An **Ubuntu** window may open and ask for a username and password. Make up any; just remember the password.
   3. Open PowerShell again and run the **same line** again.

### When it finishes

- You'll see a checklist. Every line should be ✅.
- See a ❌? Screenshot the window and send it to the maintainer.
- Running the setup again is always safe.

Your project folder is now:
- **Mac:** `Documents/GitHub/project-poke-flora`
- **Windows:** `Documents\GitHub\project-poke-flora`

---

## 3. Connect GitHub Desktop

GitHub Desktop is how you save and share your work.

1. Open **GitHub Desktop** and **sign in** with your GitHub account.
2. Click **File → Add Local Repository…**
3. Click **Choose…** and pick your project folder (from step 2). Click **Add Repository**.
4. ⚠️ If it asks **"How are you planning to use this fork?"**, choose **"For my own purposes"**.
   - The other choice sends your work to the wrong project.

---

## 4. Open the project in Porymap

Porymap is the map editor.

1. Open **Porymap**.
2. Click **File → Open Project…** and pick your project folder.
   - Mac tip: press **⌘ + Shift + G** and paste `~/Documents/GitHub/project-poke-flora`.
3. If it asks for a game version, pick **pokeemerald**.

Porymap remembers this, so next time it opens straight to the project.

> **Pink maps?** Maps ending in `_Frlg` are FireRed maps we don't use. Ignore them.

---

## 5. Try it: make your first change

This checks that everything works, start to finish.

1. **Make a branch** (your own workspace)
   - GitHub Desktop: **Current Branch → New Branch**
   - Name it `yourname-first-change` and click **Create Branch**.
2. **Change some text**
   - Open **VS Code**, then **File → Open Folder…** and pick your project folder.
   - Open `data/maps/OldaleTown_House1/scripts.pory`.
   - Change the words inside any `format("...")`. For example:
     `"Oh, a new TRAINER! Are you just starting out on your journey?"` → `"Hi! I'm testing the game!"`
   - Save (**⌘ + S** or **Ctrl + S**).
3. **Play it**
   - In your project folder, double-click **Build & Play** (`.command` on Mac, `.bat` on Windows).
   - The game opens in mGBA.
4. **Find your change**
   - Go to **Oldale Town**, enter the **bottom-left house**, and talk to the woman.
   - Shortcut: hold **S** and press **Return/Enter** to open the debug menu, then pick **Utilities… → Warp to map warp…**
5. **Save your work** (commit)
   - GitHub Desktop shows your changed file.
   - Type a short summary (like `Test text change`) and click **Commit**.
6. **Share it**
   - Click **Publish branch**, then **Create Pull Request**.
   - ⚠️ On the web page, check that **base repository** says **`poke-pals/project-poke-flora`**. Then click **Create pull request**.
7. Tell the maintainer. Once they approve it, you're all set! 🎉

---

## ⚠️ The one big rule: never share the game file

- **Never** post or send `pokeemerald.gba` to anyone, anywhere (Discord, forums, file links).
- Why: it contains Nintendo's original game. Everyone on the team makes their own copy with Build & Play.
- Want to show progress? Share **screenshots or videos**.
- Public releases will be patch files (`.bps`), made by the maintainer.

---

## Game controls (mGBA)

| Game button | Keyboard |
|---|---|
| Move | Arrow keys |
| A / B | X / Z |
| L / R | A / S |
| Start | Return (Mac) / Enter (Windows) |
| Select | Delete (Mac) / Backspace (Windows) |
| Fast forward | Hold Tab |
| Save state 1 | Shift + F1 (Mac: add **fn**) |
| Load state 1 | F1 (Mac: add **fn**) |

Change keys: **Settings → Controllers** (Mac: **mGBA → Settings**; Windows: **Tools → Settings**).

---

## What's next

- Everyday steps: [DAILY_WORKFLOW.md](DAILY_WORKFLOW.md)
- Stuck? Screenshot it and message the maintainer.
