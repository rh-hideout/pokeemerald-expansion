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
**Description:** The player is asked to note one's matriculation number. However, recalling it requires to take oneself back to the moment of receiving it. 
Now situated on the third floor, a moment later, the player needs to figure out how matriculation numbers are generated to be able to recall the missing pieces. 
The DHBW's main building's plannings can be described as a square with four floors each with the same length. Every floor provides rooms for lectures and sometimes
provide huge learning spaces for a small group of students. Who would dare to join strangers in a big room? No one would want to interrupt their doings. Noone but the player.
Nevertheless, the player cannot go back from one's memories before recalling the matriculation number. Solve the puzzle to be able to provide it to Prof. Dr. Houvert.
**Solution:** Search all floors and their rooms for clues by talking to students. Some are discussing numbers, others are talking about the DHBW's past.
The south hallway consists of the entry of the third floor and the secretary with the terminal.
The east hallway's lower room grants lore, the upper one grants a hint about the "number 5".
The north hallway's room on the east side grants lore, the room on the west offers a crucial item.
The west hallway's upper room offers a hint on the "number 3", while the lower one offers lore.

The crucial collected item is a TM. Teach it to one of the Pokémon via the bag. In the Pokémon entry, choose the Pokémon with the TM and activate the "secret power".
It's not a secret art of combat, it's a power which reveals secrets. Try using the power in different locations that feel suspicious.
The south hallway offers only one room, apart from the other three. At some point, even a student notes that the south hallway seems off.

Use the power in the south hallway. A secret door opens.
By entering the secret door, a statue provides the hinted algorithm in the lore to calculate the solution of the flag.

The algorithm needs to be terminated in an external engine. Before, the player needs to determine the required numbers for the two question mark placeholders "?".
The hints on the numbers also point on their position, but trying both combinations is also sufficient.
The player ID can be found in the menu section under the own player's name.

```python
def trainer_code(trainer_id: int, name: str) -> int:
    s = (str(trainer_id) + name).encode("utf-8")
    x = 0
    for b in s:
        x ^= b
        x ^= (x << 3 & 0xFFFFFFFF)
        x ^= (x >> 5)
    x &= 0xFFFFFFFF
    return 1_000_000 + (x % 9_000_000)
```
example: if the player ID is 3750 and the chosen name is "lilh4cs", then the flag solution is the printed value of trainer_code(3750, "lilh4cs")

**Flag solution:** *an integer, derived from the function: trainer_code("your ID", "your player name")*

## Flag 3: Mr. Wörner's coding cellar
**Description:** The player enters some kind of cave with no way to go any further.
The cave is filled with rocks and boulders, a CD and a weird field on the ground.
Upon going further, the next cave's section consists of craters and pillars. However, a rock blocks the exit and high-pitched sounds are played.
**Solution:** To advance to stage 2, the player must understand the hint, carved into a wall centered at the cave's entrance area.
It indicates on taking a step back. Metaphorically, this often helps for orientation to afterward going even further.
The weird field on the ground displays a dollar sign which is usually used to mark the beginning of a new line in terminals.
The three moveable objects in the cave are a compact disk and two boulders.
To solve the puzzle, the compact disc must be placed behind the dollar sign by pushing it forward with X.
The same applies for the two boulders, which must be redirected next to the compact disc. It draws a picture looking like the command for going back one directory: $ cd..

The 2nd stage plays high-pitched sounds, which replays after a while. The NPC to the east hints, that it is some kind of melody. It is a morse code which after decryption shows the searched flag.
Don't forget to recognise the pauses between groups of sounds as well to receive the correct letters.
The morse code sounds the following pattern: "... .-.. . . .--."
**Flag solution:** "Sleep"

## Flag 4: 

## Flag 5

## Flag 6

## Flag 7

## Flag 8

## Flag final