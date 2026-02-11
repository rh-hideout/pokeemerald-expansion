### todo (exclude on finished project)
#### before submission
- credit RHH as stated in original readme: "If you use **`pokeemerald-expansion`**, please credit **RHH (Rom Hacking Hideout)**. Optionally, include the version number for clarity."
- test CTF inside submission environment (VM with emulator etc.), direclty comparing walkthrough guide with CTF step-by-step, eventually third-party tester
- test VM image delivery on different VM software / on the one Riebl uses and his OS 


# pre-requisites
## About this project
This project uses a GBA ROM hack base named **`pokeemerald-expansion`** which delivers developer tools to manipulate the decompiled gamefiles and extend the possibilites of the original game content.

A GBA ROM hack base is a decompiled base (cracked version) of the respective Game Boy Advanced game - in this case Pokemon Emerald. 

The repositorie's tools are utilized in a way to either manipulate or substitute the original games processes and graphical environment to fit the premiss of a Capture The Flag (CTF) game. The known graphical Pokemon environment is changed to fit the context of the projects assignment authority, hence the surroundings of the institution of DHBW located in Mannheim, Germany.

The player ventures the typical starting environment of the Pokemon game to soon encounter derivations from the original game. New characters with new splash arts and dialogue appear, Pokemon creatures from other locations appear where they should not and the DHBW logo appears in its fierceful red.

To advance in most stages of the game, it is necessary to acquire unspecified keywords (e.g. to capture flags) by puzzeling together hints in a correct logical order, leveraging basic computer science knowledge or simply by leaning into the game's graphical environment. The correct result must then be entered into a new game element called "terminal".

Each of the game's terminals are tied to a specific flag, hindering the player to advance further. Between the puzzels, the game environment regularly challenges the player with the common challenges of the Pokemon game itself, including fights, leveling and organization of one's own pokemon team.

## About the environment
**`pokeemerald-expansion`** is a GBA ROM hack base that equips developers with a comprehensive toolkit for creating Pokémon ROM hacks. **`pokeemerald-expansion`** is built on top of [pret's `pokeemerald`](https://github.com/pret/pokeemerald) decompilation project. **It is not a playable Pokémon game on its own.**

- tiny overview of changed files, deri

## Additional background information
Pokemon Emerald was originally developed by Game Freak and published by The Pokemon Company and Nintendo in the year 2004. It is the fifth game of the Pokemon video game series and the last of the third generation.

A CTF is a gamified version of applying techniques to reach specified goals (flags) in a technical manner or with technical knowledge. To "capture" a flag, the laid out puzzle needs to be solved whether with the technical skills hands-on or with the knowledge accompanying it.