# Document Purpose

This document is a guide for contributors and Senate to decide if a feature is within "scope" for pokeemerald-expansion. If a feature is not in scope, then it should not be merged. Even if an opened PR is within scope, this does not mean it will be merged, as acceptance criteria will often come down to the details of the implementation.

# Definitions

* **Showdown Supported (SS)**: A core series game who's metagame can be played on Showdown.
  * Notably, this is every [core series game](https://bulbapedia.bulbagarden.net/wiki/Core_series#List_of_core_series_games) except Pokémon Legends: Arceus.  
* **Base Expansion Version**: "A .gba file built from an unmodified `master` or `upcoming` branch of `pokeemerald-expansion`.  
* **Vanilla Emerald Version**: A .gba file built from an unmodified `master` branch of pret's `pokeemerald`.

# Guidelines

A pull request meets the scope criteria if:
* The feature does not belong to a category considered “not in scope” AND
* The feature belongs to a category considered “in scope”

## In Scope Categories

1. **SS Species:** Adds Species that have appeared in a Showdown-supported title  
2. **SS Moves:** Adds Moves and Move Animations that have appeared in a Showdown-supported title  
3. **SS Abilities:** Adds Abilities that have appeared in a Showdown-supported title  
4. **SS Items:** Adds Items that have appeared in a Showdown-supported title  
5. **SS Gimmicks:** Adds Gimmicks that have appeared in a Showdown-supported title  
6. **SS Battle Types:** Adds Special Battle Types that have appeared in a Showdown-supported title  
7. **SS Battle Mechanics:** Adds mechanical battle changes that have appeared in a Showdown-supported title
8. **Improve Battle AI:** Improve the Battle AI in a way that allows it to approach the skill and capability of a human competitive player  
9. **Base Link Compatibility:** Link compatibility with base  
10. **SS Overworld / Menu Updates:** Replicate overworld or menu changes from Showdown-supported Pokémon titles  
11. **Speed Up:** Speed up the player experience of features found in base  
12. **Compression:** Automatically compress assets  
13. **Novel Experience:** Adds a novel experience included in another Showdown Supported title
15. **Helper Features:** Eases the addition or inclusion of any of the aforementioned

## Not In Scope Categories

1. **Non-SS Species**: Adds Species that have NOT appeared in a Showdown-supported title  
2. **Non-SS Moves**: Adds Moves and Move Animations that have NOT appeared in a Showdown-supported title  
3. **Non-SS Abilities**: Adds Abilities that have NOT appeared in a Showdown-supported title  
4. **Non-SS Items**: Adds Items that have NOT appeared in a Showdown-supported title  
5. **Non-SS Gimmicks**: Adds Gimmicks that have NOT appeared in a Showdown-supported title  
6. **Non-SS Battle Types**: Adds Special Battle Types that have NOT appeared in a Showdown-supported title  
7. **Duplicate Feature UI**: Adds functionality that duplicates the core functionality of an existing vanilla feature
8. **Vanilla Link Compatibility**: Link compatibility with vanilla

## Discussion Required Categories

Pull Requests that fall into this category should be brought up to maintainers, who will discuss and vote as to whether or not the feature is considered in scope. Considerations for acceptance may include invasiveness of implementation, popularity, ease of maintenance, etc.

1. **Developer Ease of Use:** Lowers barrier of entry for developers to use existing behavior  
2. **Fangame Features:** Adds a popular feature from other fangames  
3. **Popular Non-SS Features:** Exceptions can be made for uniquely popular or requested features (Drowsy, PLA Legend Plate, etc.)
4. **External Program**: External programs like poryscript, porymoves, etc.

