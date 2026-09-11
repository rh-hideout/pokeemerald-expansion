# Level-up Learnsets

`src/data/pokemon/level_up_learnsets.h` is the project's editable level-up learnset file. When the file does not exist, the next build initializes it from the official game data in `tools/learnset_helpers/porymoves_files`. The porymoves files are reference data maintained by Expansion and should not be edited for project-specific learnsets.

After the header has been created, normal builds never overwrite it. This lets a project edit level-up learnsets directly without later Expansion updates replacing those changes. The header is ignored by the upstream repository; remove it from `.gitignore` if the project needs to track its customized copy in Git.

## Migrating generation-specific learnsets

Projects updating from the generation-specific headers should migrate their existing learnsets before building the updated project:

```sh
make migrate-level-up-learnsets
```

The migration reads `P_LVL_UP_LEARNSETS` through the same C preprocessor configuration as the build, then copies the corresponding legacy header to `src/data/pokemon/level_up_learnsets.h`. The contents are copied exactly, preserving project-specific changes. If Git has already removed the legacy file, the migration recovers its pre-update version from the merge index, `ORIG_HEAD`, or the project's Git history.

The script removes any remaining generation-specific headers and removes the new header from `.gitignore` so the project can commit its migrated data. Before deleting them, it saves any non-selected legacy headers that are still present to `level_up_learnsets_legacy_backup.zip`. Keep or move this archive until you are certain those inactive learnsets are no longer needed.

The migration refuses to overwrite `level_up_learnsets.h` when that file contains different data. If a build already created that file, back it up or remove it before running the migration. Review and stage the new header, the `.gitignore` change, and the legacy-file deletions before completing the merge or committing the migration. The backup archive is intended for local recovery and should not be committed.

If local changes prevent `git pull` from starting, commit or stash them first. If the pull reports modify/delete conflicts for the old headers, leave those files in the working tree and run the migration before resolving the deletions.

## Choosing the initial learnsets

Before the first build, set `P_LVL_UP_LEARNSETS` to choose the official data used to initialize the header. The setting is also used by the explicit regeneration command, but changing it does not alter an existing header.

The initialization uses the fallback rules described beside the config: species introduced after the selected generation use their first available learnset, while species absent from a later game keep their most recent available learnset. Generation 8 uses BDSP data for Pokémon found there, Sword and Shield data for the remaining available Pokémon, Legends: Arceus data for species introduced there, and USUM data as its fallback. Generation 9 uses Scarlet and Violet data where available, Legends: Z-A data for species introduced there, and the Generation 8 result otherwise.

Every `LevelMoves` entry is retained, including a move learned at more than one level, and entries are sorted numerically by level.

### Selecting a specific game

The generation defaults are recommended for most projects. To use one game's learnsets instead, set `P_LVL_UP_LEARNSETS_GAME` to one of the following values before initialization or explicit regeneration:

| Generation | Supported sources |
| --- | --- |
| 1 | `LEVEL_UP_LEARNSETS_GAME_RB`, `LEVEL_UP_LEARNSETS_GAME_YELLOW` |
| 2 | `LEVEL_UP_LEARNSETS_GAME_GS`, `LEVEL_UP_LEARNSETS_GAME_CRYSTAL` |
| 3 | `LEVEL_UP_LEARNSETS_GAME_RSE`, `LEVEL_UP_LEARNSETS_GAME_FRLG` |
| 4 | `LEVEL_UP_LEARNSETS_GAME_DP`, `LEVEL_UP_LEARNSETS_GAME_PLATINUM`, `LEVEL_UP_LEARNSETS_GAME_HGSS` |
| 5 | `LEVEL_UP_LEARNSETS_GAME_BW`, `LEVEL_UP_LEARNSETS_GAME_B2W2` |
| 6 | `LEVEL_UP_LEARNSETS_GAME_XY`, `LEVEL_UP_LEARNSETS_GAME_ORAS` |
| 7 | `LEVEL_UP_LEARNSETS_GAME_SM`, `LEVEL_UP_LEARNSETS_GAME_USUM`, `LEVEL_UP_LEARNSETS_GAME_LGPE` |
| 8 | `LEVEL_UP_LEARNSETS_GAME_SWSH`, `LEVEL_UP_LEARNSETS_GAME_BDSP`, `LEVEL_UP_LEARNSETS_GAME_LA` |
| 9 | `LEVEL_UP_LEARNSETS_GAME_SV`, `LEVEL_UP_LEARNSETS_GAME_ZA` |

For a species present in the selected game, the generator uses that game's data. If the species is absent, it uses the most recent earlier supported game containing that species. If no earlier game contains it because the species had not been introduced yet, it uses the species' first later appearance. This chronological fallback also supplies species outside the limited rosters of LGPE, Sword and Shield, BDSP, Legends: Arceus, Scarlet and Violet, and Legends: Z-A.

`LEVEL_UP_LEARNSETS_GAME_DEFAULT` disables the game override and restores the composite data selected by `P_LVL_UP_LEARNSETS`. Changing either setting never alters an existing project-owned header during a normal build.

## Editing and regenerating

Edit `src/data/pokemon/level_up_learnsets.h` directly to customize a species' moves or to add a learnset for a custom species. The [new Pokémon tutorial](how_to_new_pokemon.md) shows the required C array and species-data reference.

To intentionally discard the current header and recreate it from the selected official data, run:

```sh
make regenerate-level-up-learnsets
```

This overwrites the file without a prompt, so commit or back up project changes first. Alternatively, run `make clean-level-up-learnsets`; the next normal build creates a new header because it is missing.
