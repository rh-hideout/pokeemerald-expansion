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

## Editing and regenerating

Edit `src/data/pokemon/level_up_learnsets.h` directly to customize a species' moves or to add a learnset for a custom species. The [new Pokémon tutorial](how_to_new_pokemon.md) shows the required C array and species-data reference.

To intentionally discard the current header and recreate it from the selected official data, run:

```sh
make regenerate-level-up-learnsets
```

This overwrites the file without a prompt, so commit or back up project changes first. Alternatively, run `make clean-level-up-learnsets`; the next normal build creates a new header because it is missing.
