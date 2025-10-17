#ifndef GUARD_CONSTANTS_TEACHING_TYPES_H
#define GUARD_CONSTANTS_TEACHING_TYPES_H

/*
Teaching Types are not used directly by the ROM but they are used by
make_teachables.py to generate teachable learnset. To save ROM space, the info is 
stored in 1 bit and the python script reads the name of the define.
You could add additional learning types but they would need to be described in the
python script.
*/


#define DEFAULT_LEARNING    0
/* DEFAULT_LEARNING
Vanilla uses: most pokemon
Allow a pokemon to learn all universal moves
*/

#define TM_ILLITERATE       1
/* TM_ILLITERATE
Vanilla uses: pokemon with "gimmick" moveset (Ditto, Smeargle, Magikarp, ...)
Pokemon can't learn any universal moves (unless it was added to their teachable learnset)
*/

#define ALL_TEACHABLES      1
/* ALL_TEACHABLES
Vanilla uses: Mew
Allows a pokemon to learn almost every teachable move (wether from TM or tutors)
Some moves are excluded, the are listed in SignatureTeachables
*/

#endif  // GUARD_CONSTANTS_TEACHING_TYPES_H