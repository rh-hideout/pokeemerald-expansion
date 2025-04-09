# Time-Based Encounters Tutorial

## What is the Time-Based Encounters feature? 
Time-Based Encounters lets you pick which Pokémon appear based on the in-game clock, per route!
Gen 2 had this feature, and Gen 4 brought it back- for instance, in Sinnoh's Route 201 you had a higher chance of catching a Bidoof than a Starly at night.


## Sounds rad, how do I add them to my romhack?
There are a couple of ways! The system is built to handle your unchanged [`wild_encounters.json`](../../src/data/wild_encounters.json) file by default, so the most basic solution is to add an encounter group by editing that (by hand or with Porymap), and then add a supported suffix to the end of whatever name you give it. 

- NOTE: if you haven't specified/added any encounters, or have the option turned off, Expansion puts them into the `TIME_MORNING` slot to keep vanilla behavior. 

### What are "supported suffixes?"
Vanilla Pokémon games usually work with 4 different times of day:
- `TIME_MORNING`
- `TIME_DAY`
- `TIME_EVENING`
- `TIME_NIGHT`

So, the "supported suffixes" are just:
- `_Morning`
- `_Day`
- `_Evening`
- `_Night`

### That's a lot of manual editing. 
You're so right bestie! Luckily for you, there's a python script that can help you out!
The script is at [`migration_scripts/add_time_based_encounters.py`](../../migration_scripts/add_time_based_encounters.py). It, in order:
- Checks to make sure you're running it from the root folder of your expansion project (specifically, wherever the project's [`Makefile`](../../Makefile) is)
- Makes a backup of your [`wild_encounters.json`](../../src/data/wild_encounters.json) file called `wild_encounters.json.bak`
- Runs through `wild_encounters.json` and adds dummy encounter groups for each time denomination to each group
  - ie, `gRoute101` becomes `gRoute101_Morning`, `gRoute101_Day`, `gRoute101_Evening`, and `gRoute101_Night`

This script works kind of like a "template" feature- when you open it up to edit either in Porymap or a text editor, you will see the encounter groups, but they won't be filled out with encounters. This lets you add Pokémon with your own encounter rates however you want.

### That's *still* a lot of editing.
You're *still* so right bestie! Luckily for you, there's an optional argument you can add when you run the script: `--copy`.
This duplicates the encounter group's encounters as well as their labels/map group values. When you open [`wild_encounters.json`](../../src/data/wild_encounters.json) for editing either in Porymap or a text editor, you'll notice that each group (`gRoute101_Morning`, `gRoute101_Day`, `gRoute101_Evening`, and `gRoute101_Night`) now all have the same encounters as `gRoute101` did. If you only want to add a couple of Pokémon here and there for each time of day, this is probably the easier option.

- NOTE: the `--copy` option will use up an additional 9kb of ROM space. Obviously that's not much even for a GBA ROM, but it's something to keep in mind.

### So what are the `#define` options in [`overworld.h`](../../include/config/overworld.h)?
Great questie bestie!

Here's a rundown, with more information than what's in the comments at [`overworld.h`](../../include/config/overworld.h):
- `OW_TIME_OF_DAY_ENCOUNTERS            FALSE`
  - should be `TRUE` or `FALSE`, basically enables or disables the feature. You'll notice your used ROM space changing when this is enabled or disabled, as the [json->C header conversion file](../../tools/wild_encounters/wild_encounters_to_header.py) will generate the `encounterTypes` array in [`wild_encounter.h`](../../include/wild_encounter.h) with different sizes based on whether this value is `TRUE` or `FALSE`.
- `OW_TIME_OF_DAY_DISABLE_FALLBACK      FALSE`
  - this option controls the behavior of the game when an encounter table isn't populated. If this is set to `TRUE`, whenever the game detects that you're in a time of day (Morning/Day/Evening/Night) on a map without any encounters for that time, you won't encounter any mons. If this is set to `FALSE`, the game will look for encounters at the time specified in the `OW_TIME_OF_DAY_FALLBACK` option at the bottom.
- `OW_TIME_OF_DAY_DEFAULT               TIME_MORNING`
  - this option specifies what time is the first value in the [`TimesOfDay`](../../include/rtc.h) enum. This should always be the first value there (`TIME_MORNING` by default), because it's how both the [`migration_script`](../../migration_scripts/add_time_based_encounters.py) and the [json->C header conversion file](../../tools/wild_encounters/wild_encounters_to_header.py) determine what elements go where when the encounters are converted.
- `OW_TIME_OF_DAY_FALLBACK              OW_TIME_OF_DAY_DEFAULT`
  - this option controls which time is used when `OW_TIME_OF_DAY_DISABLE_FALLBACK` is `FALSE`. It's set to the same value as `OW_TIME_OF_DAY_DEFAULT` by... default. Keep in mind that if you enable `OW_TIME_OF_DAY_ENCOUNTERS` and set this to something other than `TIME_MORNING`, you should make sure that time has encounters, or you won't encounter anything.


## Examples

### Running the [`migration_script`](../../migration_scripts/add_time_based_encounters.py) without the `--copy` option
**Make sure you run this from the root folder of your project!**

```python3 migration_scripts/add_time_based_encounters.py```

#### Result:
```
"encounters": [
        {
          "map": "MAP_ROUTE101",
          "base_label": "gRoute101_Morning",
          "land_mons": {
            "encounter_rate": 20,
            "mons": [
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_ZIGZAGOON"
              }
            ]
          }
        },
        {
          "map": "MAP_ROUTE101",
          "base_label": "gRoute101_Day"
        },
        {
          "map": "MAP_ROUTE101",
          "base_label": "gRoute101_Evening"
        },
        {
          "map": "MAP_ROUTE101",
          "base_label": "gRoute101_Night"
        },
]
    
```
As you can see, the names change, but the encounters aren't touched, so you're free to add your own, piecemeal style.

### Running the [`migration_script`](../../migration_scripts/add_time_based_encounters.py) with the `--copy` option
**Make sure you run this from the root folder of your project!**

```python3 migration_scripts/add_time_based_encounters.py --copy```

#### Result:
```
"encounters": [
        {
          "map": "MAP_ROUTE101",
          "base_label": "gRoute101_Morning",
          "land_mons": {
            "encounter_rate": 20,
            "mons": [
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_ZIGZAGOON"
              }
            ]
          }
        },
        {
          "map": "MAP_ROUTE101",
          "base_label": "gRoute101_Day",
          "land_mons": {
            "encounter_rate": 20,
            "mons": [
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_ZIGZAGOON"
              }
            ]
          }
        },
        {
          "map": "MAP_ROUTE101",
          "base_label": "gRoute101_Evening",
          "land_mons": {
            "encounter_rate": 20,
            "mons": [
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_ZIGZAGOON"
              }
            ]
          }
        },
        {
          "map": "MAP_ROUTE101",
          "base_label": "gRoute101_Night",
          "land_mons": {
            "encounter_rate": 20,
            "mons": [
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_WURMPLE"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_POOCHYENA"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 2,
                "max_level": 2,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_ZIGZAGOON"
              },
              {
                "min_level": 3,
                "max_level": 3,
                "species": "SPECIES_ZIGZAGOON"
              }
            ]
          }
        },
    ]
```
As you can see, the group `gRoute101` was copied into groups that correspond with the four vanilla times of day (Morning/Day/Evening/Night).