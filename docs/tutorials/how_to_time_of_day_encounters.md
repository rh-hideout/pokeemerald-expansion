# Time-Based Encounters Tutorial

## What is the Time-Based Encounters feature? 
Time-Based Encounters (from here on known as TBE) lets you pick which Pokémon appear during your play session, per route!
Gen 2 had this feature, and Gen 4 brought it back- for instance, in Sinnoh's Route 201 you had a higher chance of catching a Bidoof than a Starly at night.

## Sounds rad, how do I add them to my romhack?
There are a couple of ways! The system is built to handle your unchanged `wild_encounters.json` file by default, so the most basic solution is to add an encounter group by editing that (by hand or with Porymap), and then add a supported suffix to the end of whatever name you give it. 

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
The script is at `migration_scripts/add_time_based_encounters.py`. It, in order:
- Checks to make sure you're running it from the root folder of your expansion project (specifically, wherever the project's `Makefile` is)
- Makes a backup of your `wild_encounters.json` file called `wild_encounters.json.bak`
- Runs through `wild_encounters.json` and adds dummy encounter groups for each time denomination to each group
  - ie, `gRoute101` becomes `gRoute101_Morning`, `gRoute101_Day`, `gRoute101_Evening`, and `gRoute101_Night`

This script works kind of like a "template" feature- when you open it up to edit either in Porymap or a text editor, you will see the encounter groups, but they won't be filled out with encounters. This lets you add Pokémon with your own encounter rates however you want.

### That's *still* a lot of editing.
You're *still* so right bestie! Luckily for you, there's an optional argument you can add when you run the script: `--copy`.
This duplicates the encounter group's encounters as well as their labels/map group values. When you open `wild_encounters.json` for editing either in Porymap or a text editor, you'll notice that each group (`gRoute101_Morning`, `gRoute101_Day`, `gRoute101_Evening`, and `gRoute101_Night`) now all have the same encounters as `gRoute101` did. If you only want to add a couple of Pokémon here and there for each time of day, this is probably the easier option.

- NOTE: the `--copy` option will use up an additional 9kb of ROM space. Obviously that's not much even for a GBA ROM, but it's something to keep in mind.