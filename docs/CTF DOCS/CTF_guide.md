# Capture the flag guide
This guide emphasizes on solving the flags of the pokeCTF only. Guidance on their surroundings and how to enter them, are explained in the respective chapter of the full walkthrough.

For further information on CTF, Pokèmon and flags, refer to the introduction's chapter on background information.

## Flag 0: tutorial
**Description:** The player finds oneself in front of the DHBW main building, which is blocked by an NPC. Unfortunately, talking to him fails and shaking the stranger seems rather inadequate.
**Solution:** The player must prove ones ability to gather information from ones surroundings, including another NPC suggesting a solution to the problem. A loud bang should be sufficient to wake the sleepyhead.
**Flag solution:** "bang"

## Flag 1: permutation trouble with Mr. Hyvl
**Description:** The player is inside a museum with Prof. Farmer and Team Rocket who are about to steal the Mathalizer, which is an object of power.
After defeating team rocket in battle, they flee and lock the museum, leaving the Mathalizer behind. The player must solve the flag to escape from the museum.
**Solution:** Interacting with objects reveal hints about the flag. In particular the picture on the northwestern side of the museum hints on the use of the caesar cipher.
The caesar cipher is a trivial encryption which shifts all letters of a word on their respective letter later or earlier in the alphabet.
The player must shift all seven letters O, Z, U, S, P, F and O by a specific value. These are found on interactive objects in the museum. The value "12" is written on the museum's floor.
When shifting the letters by 12, new seemingly random letters are revealed, but now with more common letters and vocals.
Putting the letters in an anagram tool, will reveal the flag solution.
**Flag solution:** "algebra"

## Flag 2: Mr. Houvert's Alzheimer's attack

## Flag 3: Mr. Wörner's coding cellar
**Description:** The player enters some kind of cave with no way to go any further.
The cave is filled with rocks and boulders, a CD and a weird field on the ground.
Upon going further, the next cave's section consists of craters and pillars. However, a rock blocks the exit and high-pitched sounds are played.
**Solution:** To advance to stage 2, the player must understand the hint, carved into a wall centered at the cave's entrance area.
It indicates on taking a step back. Metaphorically this often helps for orientation to afterward going even further.
The weird field on the ground displays a dollar sign which is usually used to mark the beginning of a new line in terminals.
The three moveable objects in the cave are a compact disk and two boulders.
To solve the puzzle, the compact disc must be placed behind the dollar sign by pushing it forward with X.
The same applies for the two boulders, redirected behind the compact disc. It draws a picture, looking like the command for going back one directory: $ cd..

The 2nd stage plays high-pitched sounds, which replays after a while. The NPC to the east hints, that it is some kind of melody. It is a morse code which after decryption shows the searched flag.
Don't forget to recognise the pauses the between sounds as well to form groups of sounds.
The morse code sounds the following pattern: "... .-.. . . .--."
**Flag solution:** "Sleep"

## Flag 4: 

## Flag 5

## Flag 6

## Flag 7

## Flag 8

## Flag final