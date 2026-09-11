### Note: This guide was written for version 1.14.0, it doesn't apply to earlier versions of expansions. This guide also assumes you are using the default P_LEARNSET_HELPER_TEACHABLE config (TRUE)

# Generating and editing teachable learnsets

## Basics:
When you `make`, a file will be generated in `src/data/pokemon/teachable_learnsets.h` containing the learnsets of your Pokémon. The generated learnset is based on the official potential moves, the project's learnset overrides, the species' teaching type, and the TMs and tutors available in the game. We will explain each of these one by one.

### Table of Contents:

1. [Potential Teachables]
2. [Teaching Types]
    - [Default Learnset]
    - [TM Illiterate]
    - [All Teachables]
3. [Available Moves]
    - [TMs/Hms]
    - [Tutors from scripts]
    - [Extra Tutors]

## Potential Teachables

The official potential moveset of each Pokémon is defined in `src/data/pokemon/all_learnables.json`. If the file does not exist, `make` creates it from the official game data in `tools/learnset_helpers/porymoves_files`. The porymoves files are maintained by Expansion and should not be changed for a project.

Project-specific changes belong in `src/data/pokemon/learnset_overrides.json`. Each species can add or remove move constants:

```json
{
  "MEWTHREE": {
    "add": ["MOVE_FOCUS_PUNCH", "MOVE_WATER_PULSE"],
    "remove": ["MOVE_TOXIC"]
  }
}
```

The `add` and `remove` lists are optional; a custom species can be introduced with only an `add` list. If the same move appears in both lists, `remove` takes precedence. During a normal build, the helper combines the official file and these overrides into an internal file used to generate `teachable_learnsets.h`. Neither source file is overwritten.

Explicit overrides also take precedence over the final teaching rules: removals exclude universal moves and moves granted by `ALL_TEACHABLES`, while additions can allow signature moves or moves normally excluded by TM literacy or species-specific restrictions. Moves still require an available TM, HM, or tutor. Species and forms sharing a teachable array also share its overrides; use the array's species name (for example, `OINKOLOGNE` for `sOinkologneTeachableLearnset`).

To intentionally replace `all_learnables.json` with the latest official porymoves data, run:

```sh
make refresh-all-learnables
```

This command replaces only the official base file and preserves `learnset_overrides.json`. Review its changes before committing them.

### Migrating an existing customized file

Existing projects should create a proposed override file before refreshing their customized `all_learnables.json`:

```sh
make propose-learnset-overrides
```

This generates fresh official data and compares it with the project's current file. It writes the differences to `tools/learnset_helpers/build/proposed_learnset_overrides.json` without changing `all_learnables.json` or `learnset_overrides.json`.

The command refuses to overwrite an existing proposal. Move it somewhere safe before generating another proposal; the build directory is removed by cleaning commands. Proposals compare only the base files, so preserve any overrides you have already reviewed when merging the proposed changes.

Review every proposed addition and removal. Differences may represent intentional project customizations, but they may also come from official corrections made since the project's file was generated. Copy only the intended project changes into `src/data/pokemon/learnset_overrides.json`. Then run `make refresh-all-learnables` to replace the official base. Future refreshes will reapply the reviewed overrides without changing them.

## Teaching Types

In addition to the potential moves assembled from the official data and project overrides, Pokémon can learn additional moves based on the teaching types defined in the species data files (found in `species/data/pokemon/species_info/gen_X_families.h` for vanilla Pokémon and `species/data/pokemon/species_info.h` for fakemon). There are currently three teaching types in Expansion: Default Learning, TM Illiterate and All Teachables.

### Default Learning

This is the default one, so if a species don't have a teaching type defined in its species data, it will will default to this. If you want to explicitly make a species this way, then add `.teachingType = DEFAULT_LEARNING` to the species data.
Default Learning mean in addtion to the moves described in its additional moveset, the Pokemon will be able to learn the universal moves (like Tera Blast or Hidden Power). Universal moves are listed in `src/data/pokemon/special_movesets.json` (there are multiple lists in the file, make sure to edit the one named "universalMoves")

### TM Illiterate

`.teachingType = TM_ILLITERATE`
TM Illiterate mean a pokemon will only learn move from its potential moveset and not any universal moves. If the config `P_TM_LITERACY` is set to GEN_5 or lower. Universal moves will be removed from the pokemon potential learnset.

### All Teachables

`.teachingType = ALL_TEACHABLES`
All Teachables mean a pokemon will be able to learn every teachable move that are present in your game whether tutor or TM similarly to Mew in official games. If you want a TM or a Tutor move to not be accesible to All Teachables pokemon, you can add it to the signature teachables list in `src/data/pokemon/special_movesets.json` (there are multiple lists in the file, make sure to edit the one named "signatureTeachables")

So, for example, if you a remove a TM from your game, the move associated with that TM will be removed from the teachable elarnset of your pokemon.

## Available Moves

### Optional compatibility from level-up moves

Set `P_LEVEL_UP_TM_COMPATIBILITY` to `TRUE` in `include/config/pokemon.h` to grant compatibility when a move in the project's current `level_up_learnsets.h` is also an available TM or HM. The option defaults to `FALSE`. Ordinary builds refresh the derived compatibility after changes to level-up learnsets, species data, configuration, or the TM/HM list. They do not regenerate the editable level-up header.

The helper preprocesses the current species and learnset headers, including aliases and conditional forms. It uses each active species' `.levelUpLearnset` reference, without inheriting pre-evolution moves. Forms that share a `.teachableLearnset` array share the union of their active level-up TM/HM matches. Give forms separate teachable arrays if their compatibility must differ.

Tutor availability alone never grants compatibility under this option. However, the game uses the same teachable array for TMs and tutors: once compatibility is granted for a TM/HM move, a tutor offering that same move can also teach it. Explicit project removals take precedence over derived compatibility.

The derived data lives in `tools/learnset_helpers/build/level_up_tms.json`. Neither this policy nor editing TMs modifies `level_up_learnsets.h`, `all_learnables.json`, `learnset_overrides.json`, or official porymoves data. When the teachable helper is disabled, the policy has no effect.

The teachable learnset is based on the potential moveset and the universal moves as described in the sections above but it will only be conposed of moves that are available in your game. Let's see how the code detects the moves that are available.

### TMs/Hms

The script detects the TMs and HMs available in your game based on the list in `include/constants/tms_hms.h`. If you add a new TM, the pokemon with that move in their potential moveset will receive that move in their teachable learnset. And if you remove a TM, the move will be deleted from your pokemon's teachable learnsets.

### Tutors from scripts

The script look for tutors moves in your script files, wether map scripts `/data/maps/*/scripts.inc` or other function scripts `/data/scripts/*.inc`. It looks for the pattern used for move tutors in vanilla emerald `setvar VAR_0x8005, MOVE_*`. So try to add move tutors this way if you want them to be properl detected.

### Extra Tutors

If you somehow add a move that can be learned in new custom ways that don't fit with the previous patterns, you can add the move to the extra tutors list in `src/data/pokemon/special_movesets.json` (there are multiple lists in the file, make sure to edit the one named "extraTutors"). This shouldn't be necessary for most users and if you use this list, remember you will need to add/remove moves from this list and the code that teaches moves.
