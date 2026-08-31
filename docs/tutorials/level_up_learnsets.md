# Level-up Learnsets

`src/data/pokemon/level_up_learnsets.h` is the project's editable level-up learnset file. When the file does not exist, the next build initializes it from the official game data in `tools/learnset_helpers/porymoves_files`. The porymoves files are reference data maintained by Expansion and should not be edited for project-specific learnsets.

After the header has been created, normal builds never overwrite it. This lets a project edit level-up learnsets directly without later Expansion updates replacing those changes. The header is ignored by the upstream repository; remove it from `.gitignore` if the project needs to track its customized copy in Git.

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
