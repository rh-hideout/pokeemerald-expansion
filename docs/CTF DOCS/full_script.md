# PokeCTF walk-through
This is the pokeCTF's full walkthrough, including guidance on key-bindings, pokemon-specific gamerules and hints for progression.

notes on ideas:
- easteregg with televisions that are scattered across maps by default. just alter interaction text to the easteregg context, mby like BRITNEY in players home
- 

notes on fixes: guide on counting NPC's (Route 101 Nr.2: R101-2)
- Bellas name is written twice in the tutorials TV scene
- the notebook says to open the menu with start, mby say you have to press "enter"
- BIRCH home characters monologues are not introduced by the speakers names
- dialogue with BUM can't be repeated, other than any other NPC's statements
- choosing Duskull leads to not receiving any damage 
fixed: BUM replaced BIRCH but dialogues and narrative insist on meeting BIRCH, which is not going to happen when expected. Maybe dialogue must be changed to something to lead towards the BUM. Also add more logic to why returning to the lab is reasonable.
- BUM left the scene sliding
fixed: R101-2: "If POKéMON get tired, take them to a POKéMON CENTER. There's a POKéMON CENTER in OLDALE TOWN right close by."
- Route 103 first sign reads "(arrow pointed downwards) OLDALE TOWN"
fixed: Rival on Route 103 repeats the past about the player receiving its pokemon from the prof which is incorrect
fixed: Bella after receiving pokedex seams worried like a mother, not like a new shared flat fella
- map east of Neuostheim is named "Quadrate", empty, no music, a shield on the left side of the southern building is passable.
- map DHBW has one west building which cant be entered, which is why door is passable because no trigger for entering is omitted
- when xxx is received from Professor Farmer, no item acquired sound is omitted
- xxx is not added to the inventory, instead added to a Team
- after being teleported, fighting Team Rocket doesn't seem mandatory 
- flag1: healing pokèmon by Farmer omits healing sound, but no typical black screen is omitted.
- flag1: only picture which was not destroyed: better paragraph formatting for quality of life
- flag1: museum has several impassible tiles which either consist of object's shadow or are behind a larger object as well as outer wall tiles. inconsistent shadow placement for same objects or no shadow e.g. the terminal
- flag1: after defeating team rocket, they disappear by walking into the east ee void of the map, some sparcles appear and a brunnete as well as a pokeball teleport.
- flag1: after defeating, farmer could point out that mathelyzer was saved, afterward he heals pokemon
- flag1: glassbox with readable M is only accessible from south which is counter-intuitive as the player circles around accessing objects from the center of the room
fixed: flag1: hint on shifting number: change number or letters
- flag1: no change in dialogue after freeing everyone
- flag1: after exiting hyvls room, entering DHBW again initializes whole flag1 process again, Team rocket appears etc. after speaking to jessie, pre-fight dialogue appears but no fight. After speaking again it says "they already fled" but haven't moved. the exit of flag 1 is open 
- flag2: after exiting lecture room of Houvert, the player is directed to the next flag. However, instead of walking to the next door, the character walks past walls into nothingness.
fixed: flag2: dialogue is done by "You" instead of [Name]
- flag2: We might want to be consistent with the lecture rooms
- flag3: There is no clue for leaving the lecture room to search for the blackhansa building
- flag3: entrance on phone corp is possible after truck event. however, the door cant be unlocked.
- 


## executing the gba-file || starting the VM guide whatever

-- -- -- -- --
-- -- -- -- --

## pre-requisites on the program's behaviour 
- pixel-art and synthesizer sounds prove the game's age and former peripherals
- the current peripherals of the user's PC do not match the buttons on the common game boy advanced:
  - the ingame's description's of button usage is not meant for the PC peripherals, please refer to this guide
  - to accept/interact/continue the keyboard's "X"-button is mainly used
  - to move the character and the cursor inside any menu, the keyboard's arrows are used
  - to open the game menu, e.g. to save progress, press the keyboard's "Enter"-button
  - to return to former pages or cancel actions, the "Y"-button is used
  - holding down "Y" while in the game world's environment allows for moving the character faster
- the game ties objects to in-game tiles, usually not passable, the player can interact with any to prompt a descriptive text
- although some might, interacting with objects does not necessarily output any result
- if not announced otherwise beforehand, messages in the conversation window are describing the current game's context

## description of scenes before walkthrough content
...Very descriptive text about first interactions with the CTF-program. 
...maybe way too detailed

### pre-menu scene
Pokemon-games usually start with a beginning scene, hinting on the player's character, starter-Pokemon as well as encountered legendary Pokemon.
The original game's background of the title screen was modified to show porygon, a technology related Pokemon, instead of the typical Rayquaza.
Also, the title was expanded by the subtitle "Capture the flag", indicating on game entry that this game is a modified version.

**To start the game, instead of pressing "start" on a common game boy advanced, the keyboard's "X"-button is used.
The same applies for the menu afterward: press X to enter a new game.

### pre-game scene
PROFESSOR FARMER heartily welcomes the player. A picture of him is shown, facing the player. 
To continue with his speech, press X.

*PROFESSOR FARMER:*
> Welcome to your computer science
> studies at DHBW Cooperative
> State University.
> My name is PROFESSOR FARMER and I'm your Course Director.
> This is a special CTF-Terminal. \**showing the introduced object on screen*
> To pass a semester, you must enter the correct flag into this terminal.


The typical menu for choosing a character continues the scene:
> So, what about you?
> Are you a boy? Or are you a girl? 

The player is prompted to choose. For switching between the showed options, use the keyboard's arrow keys and continue with X.
> All right. What's your name?

Next the player is prompted to choose a name. Navigate the on-screen keyboard with the arrow keys and choose the respective letters with X. Navigate to the right bar for further options and termination.
The choice of character and name are subjective and don't impact the game's processes and story, except for the player's character's best friend to fit the opposite gender.
PROFESSOR FARMER's monologue continues:

*PROFESSOR FARMER:*
> [NAME], right?
> Ah, okay! \**PROFESSOR FARMER appears back on-screen again*
> You're [NAME] who's moving to an apartment in JUNGBUSCH.
> I get it now!
> All right, are you ready? \**showing the chosen character*
> Your very own adventure is about to unfold.
> Take courage, and leap into the world of Computer Science where dreams, 
> adventure, and friendships await!

### game-intro scene
The screen is narrowed and provides a shaking square with the player in the center, surrounded by stacked boxes and furniture.
The sound of a whirring engine indicates that the player is inside a moving truck. 
Next the truck comes to a full-stop, a door shuts open and daylight shines inside the truck's tight space.

Interaction with moving boxes shows:
> The box is printed with a POKéMON logo.
> It's a POKéMON brand moving and delivery service.

The player is able to exit the vehicle by moving towards the daylight.

On exit, the game's background music starts playing and the starting town is shown with three buildings. 
The one closest to the moving truck is the player's home, referred to as [NAME]'s home. On the left hand side is PROFESSOR BIRCH's home and on the left hand bottom corner is the professor's laboratory.
> BELLA: There you are at last.
> Our shared apartment here is nothing special, but it serves its purpose.
> Well, this is JUNGBUSCH.
> How do you like it? This is our new home!
> It has a quaint feel, but it seems to be an easy place to live, don't you think?
> And, you get your own room, [NAME]! Let's go inside.

The player is moved inside the player's home automatically. The scene changes to the living room with Pokemon working on moving in.
> BELLA: See, [NAME]? The apartment isn't that bad.
> The mover's POKéMON do all the work of moving us in and cleaning up after.
> This is so convenient!
> [NAME], your room is upstairs. Is that OK with you?
> Your clock on the wall hast stopped.
> Don't forget to set it!

The player is able to move gain.

## game walkthrough
### inside player's home
Go straight ahead and upstairs to your room. 
Interact with the clock on your left hand side hanging on the wall.
> The clock is stopped...
> Better set it and start it! \**a menu opens for setting the clock*

Set the minute hand by using the arrow keys and confirm the set time is synchronous with your real-life time.
> BELLA: [NAME], how do you like your new room?
> Good! Everything's put away neatly!
> They finished moving everything in downstairs, too.
> POKéMON movers are so convenient!
> Oh, you should make sure that everything's all there on your desk.

Walk to your desk and interact with the book laying on top of it.
> [NAME] flipped open the notebook.
> ADVENTURE RULE NO. 1 Open the MENU with START.
> ADVENTURE RULE NO. 2 Record your progress with SAVE.
> The remaining pages are blank...
! please note that there is no "Start"-button on your keyboard. Use "Enter" instead.

Walk downstairs again.
> BELLA: Oh! [NAME], [NAME]! Quick! Come quickly!
> BELLA: Look, Britney did something stupid again! Maybe we'll see her cameltoe!
> INTERVIEWER: This was BRITNEY WATCH with all your nasty news!
> BELLA: Oh... It's over.
> I think they showed it, but we missed it. Too bad.
> Oh, yes. One of our new PROFESSORS lives in town.
> PROF. BIRCH is his name.
> He lives right next door, so you should go over and introduce yourself.


----------------------
INTERACTING WITH GIRL OUTSIDE TO bums PATH MAKES HER INSIST ON CATCHING POKEMON FIRST:
BUT PLAYER just needs to enter rivals home beforehand

choosing either male or female also switches  player homes position.




### inside PROFESSOR BIRCH's home
Walk outside the house by walking towards the orange matt in the bottom left hand corner.
Walk westwards to PROFESSOR BIRCH's home and enter through the front door.
> Oh, hello. And you are?
> ...
> Oh, you're [NAME], our new next-door neighbor! Hi!
> We have a [CHILD] about the same age as you.
> Our [CHILD] was excited about making a new friend.
> Our [CHILD] is upstairs, I think.

Walk upstairs and walk towards the Pokéball laying next to the bed and interact with it.
> Hey! You...
> Who are you?
> Oh, you're [NAME], aren't you? Moved in next door, right?
> I didn't know that you're a [CHILD].
> Dad, PROF. BIRCH, said that our new next-door neighbor is a student.
> My name's [RIVAL NAME].
> Huh? Hey, [NAME], don't you have a POKéMON?
> Do you want me to go catch you one?
> Aw, darn, I forgot...
> I'm supposed to go help my dad catch some wild POKéMON.
> Some other time, okay?

### fight against BUM
Leave the house again and head north. A little girl is asking you for help.
> Um, hi!
> There are scary POKéMON outside! I can hear their cries!
> I want to go see what's going on, but I don't have any POKéMON...
> Can you go see what's happening for me?

Follow her request and head north a bit further.
> BUM: Yo Kid, come over'ere!

Walk towards BUM and interact with him.
> BUM: Hello! You interested?!
> [NAME]: You wanna sell me drugs?
> BUM: No, no, I'll show you the hottest shit! It's in my BAG!
> Take a look and pick one!

Interact with the BAG to the BUM's left hand side and choose one of the three possible Pokéballs.
> BUM: Why not give your new POKéMON a nickname?
> BUM: Nice pick! Why not try it out and fight my ZIGZAGOON!

Fight the Zigzagoon, the entity to the BUM's right hand side, by interacting with it which leads to the battle-screen.
Press "Battle" and "Tackle" repetitively until your opponent faints.
> BUM: Nice one, kid!
> You had fun? 
> [NAME]: Yeah!
> BUM: You want to keep it?
> [NAME]: Sure, what do you want for it?
> BUM: First one is always free
> This is not the place to chat, see you later!
> [NAME]: I should go find [CHILD] at ROUTE 103.

------------------------end of logical introduction--------------------

...going to the lab, even though last narrative indicating going to Route 103
> PROF. BIRCH: [CHILD]? Gone home, I think.
> Or maybe that kid's scrabbling around in tall grass again somewhere...
> If you or your POKéMON get tired, you should get some rest at home.


...why is BIRCH here after BUM was defeated and walked south? Where is BUM in JUNGBUSCH now? Where did BIRCH come from?
...BIRCH never introduced himself or acted like someone who would not know the player yet
...Bella insisted on talking to Birch first, after defeating BUM, Bella starts asking:
> How are you doing, [NAME]? You look hungry.
> I made Pasta with Pesto. \**player resumes on resting automatically, restoring Pokémon's health.*
> Bella: Take care, hobo!


### travel to PROFESSOR BIRCH's child
Before traveling, you should ensure the health of your Pokémon. In this stage of progression, health is restored at home, later on mainly in Pokémon Centers.
Go talk to Bella to restore your Pokémon's health.
> How are you doing, [NAME]? You look hungry.
> I made Pasta with Pesto. \**player resumes on resting automatically, restoring Pokémon's health.*
> Bella: Take care, hobo!

Leave your home and head north. To reach your rival at Route 103, you will pass tall grass and fight against Pokémon.
For details on fighting Pokémon, refer to the guide in the introduction.
Walk past the point of the fight with BUM and head east through the tall grass, as cliffs cannot be crossed south of them.
Directly pass the NPC and head northwest to find NEUOSTHEIM further north. 
Visit the Pokémon Center to rest your Pokémon and head further north to enter Route 103.

Navigate through the tall grass by first walking east and then slightly northwest to find and interact with PROFESSOR BIRCH's child.
> [CHILD]: Okay, so it's this one and that one that live on ROUTE 103...
> Hey, it's [NAME]!
> ...Oh, yeah, Dad gave you a POKéMON.
> Since we're here, how about a little battle?
> I'll teach you what being a TRAINER's about!

Defeat [CHILD] with your Pokèmon.
> [CHILD]: I think I get it. I think I know why my dad has his eye
> out for you now.
> Look, your POKéMON already likes you, even though you just got it.
> [NAME], I get the feeling that you could befriend any POKéMON with ease.
> We should head back to the LAB.

### start CTF journey 
Head back south to JUNGBUSCH. Use the cliffs as you can skip them while approaching from their northern side.
> [CHILD]: I'm heading back to my dad's LAB now.
> [NAME], you should hustel back, too.

Head further south by skipping the cliffs and enter PROFESSOR BIRCH's laboratory.
> PROF. BIRCH: Oh, hi, [NAME]!
> I heard you beat [CHILD] on your first try. That's excellent!
> [CHILD]'s been helping with my research for a long time.
> [CHILD] has an extensive history as a TRAINER already.
> Here, [NAME], I ordered this for my research, but I think you should have 
> this POKèDEX.
> PROF. BIRCH: The POKèDEX is a high-tech tool that automatically makes a record
> of any POKèMON you meet or catch.
> My kid, [CHILD], goes everywhere with it.
> Whenever my kid catches a rare POKèMON and records its data in the POKèDEX,
> why, [CHILD] look for me while I'm out
> doing fieldwork, and shows me.
> [CHILD]: Huh... So you got a POKèDEX, too. 
> Well then, here. I'll give you these. 
> [CHILD]: You know it's more fun to have a whole bunch of POKèMON.
> I'm going to explore all over the place to find different POKèMON.
> If I find any cool POKèMON, you bet I'll try to get them with POKè BALLS.

Head back to Neuostheim.
> BELLA: Wait, [NAME]!
> BELLA: [NAME]! [NAME]! Where have you been?
> Oh! What an adorable POKèMON! You got it from a BUM? How strange!
> Here, this was still in one of your moving boxes. 
> They'll put a zip in your step! 
> ...
> BELLA: You're always on the go...
> ...
> Sometime I miss you...
> ...nevermind.
> If you use a PC, you can store items
> The power of science is staggering!

### flag 0
In Neuostheim, you are now able to head east.
You will reach the DHBW and the tutorial flag 0.
To continue, you must enter the correct keyword into the terminal.
For the solution, refer to the CTF guide.

After solving flag 0, entering the DHBW is possible.
> Ahh [NAME], we waited especially for you.
> PROF. FARMER: At the beginning of your studies, each student receives an
> X, which is intended to support you in your learning.
> PROF. FARMER: Today we will visit the museum...
> (PLatzhaltertext)

------------------------end of logical flag 0--------------------
...teleported to the museum
> PROF. FARMER: What's all this mess?
> JESSIE: Prepare for trouble!
> JAMES: And make it double!
> PROF. FARMER: Cut that crap who are you?
> JESSIE: How rude!
> JAMES: We are TEAM ROCKET and were hired by Business Informatics
> to steal your MATHALYZER!
> PROF. FARMER: Go [NAME]. Attack those punks and teach them 
> some manners!

Before fighting Team Rocket, ask Prof. Farmer to heal your Pokémon.
Interact with Jessie.
> JESSIE: You want it back? Too bad for you, losers!
> JAMES: Let's see what you've got!
> TEAM ROCKET: Let's battle!

After Team Rockets defeat. Interact with the new NPC
> They've barricaded the door. How are we going to get out
> of here?

Find a way to understand the next terminal's entry. 
For the solution, please refer to the CTF guide.

Exit the museum.
> PROF. HYVL: You saved the MATHALYZER and thus ensured our mathematical
> superiority.
> You can now take your exam with me to profe yourself worthy.

------------------------end of logical flag 1--------------------
...teleported to hyvl to fight him, by passing through door

Defeat Prof. Hyvl.
> PROF. HYVL: Excellent! You proved yourself worthy.
> Take this, the FIRST BADGE.
> PROF. HYVL: Our proof is complete. Keep studying.

...teleported to DHBW outside area, by passing through door
...DHBW main entrance exit is not the same as DHBW main entrance when entering - moving castle vibes

------some flags later (door3)-----
> [NAME]: Sorry, the train was late.
> APPLES: For today's project, we are using a Raspberry Pi. We will
> use it to program a small script that allows us to record data. The
> best script wins a Powerglove!
> [NAME]: Wow! A Raspberry Pi! Thank you, Mister Apples!

> APPLES: Now write a script that
> collects something measurable.
> Come back when you have real results.

travelling full west
a stranger approaches
> Excuse me ???
> Let me guess, from the way you're dressed, are you a POKéMON TRAINER?
> ... ... ... ... ... ... 
> Well, maybe not. Your clothes aren't all that dirty.
> You're either a rookie TRAINER, or maybe you're just an ordinary kid.
> I'm roaming the land in search of talented TRAINERS.
> I'm sorry to have taken your time.

> [NAME]: Huh, what's that Truck doing here?
> [NAME]: FUCK, he is dead! The driver is fucking dead! Better
> call the Police!
> blablaba
> afasfsafasf
receives PHONE CORP ID
going back to the company
> GUARD: Ahh, you're from the Phone Company. Please come in.
> [NAME]: <I was able to fool the security guard here, but it won't be
> so easy with the others.>
go passt the guards
> This door is locked, but it has a lock. Maybe I can open it with the
> right tools.
> 

----door 4----
> [NAME]: <Fuck, I'm late today, Class is almost over.>
> EARTHMAN: ... and because the weather is so beautiful today,
> I'll let you leave a few minutes early. You'll also all get this
> SURFBOARD from me, so you can float down the Rhine and maybe 
> visit Ludwigshafen. Keep surfing and shaka brah!

---door 6---
door 6 exit: flag with CD
full_guide:
Enter the cave.
Read the hint carved in the wall.
Find a weird field on the ground.
Solve the puzzle.
Exit the first section of the cave.
Enter the second section of the cave.
Talk to the NPC on your right hand side.
Solve the puzzle to exit the cave.
Talk to KALI.
> I am KALI.
> Show me your strength in battle!
> 

...
...traveling by surfboard westwards
bumped into some guys "BOTH"
>...

official flag 2 after solving:
> You: Right...
> You: I remember
> You: Now I can actually write the exam.
> DR. PROF. HOUVERT: Time is up.
> DR. PROF. HOUVERT: Pens down. \*walks to player
> DR. PROF. HOUVERT: Pass your papers forward.
> DR. PROF. HOUVERT: Hmm...
> You have failed.
> You: What? How can you tell already?
> DR. PROF. HOUVERT: It is trivial.
> DR. PROF. HOUVERT: Your reasoning lacks structure.
> Your execution lacks precision.
> Your result lacks merit.
> DR. PROF. HOUVERT: However.
> This is the DHBW.
> To pass this semester... You will defeat me in battle.
> DR. PROF. HOUVERT: Let us proceed.
> DR. PROF. HOUVERT: Let us see if you perform better under pressure. \*proceeds to battle
> DR. PROF. HOUVERT: Very well. You have passed this examination.
> DR. PROF. HOUVERT: You may claim the second badge.
> It proves you survived this exam.
> Keep it safe.



some flag?
> [NAME]: Better go to my desk. 
> PROF. BAMBERGER: Today in Forensics, we... 
> What was that?!
> JESSIE: Prepare for trouble... 
> JAMES: and make it double!
> [NAME]: Oh no, not again!
> JESSIE: Time to collect our Bounty from BLACKHANSA. 
> ADRIA: What is this? 

\**upon interaction*
> ADRIA: Did you find a clue about their whereabouts? 

\**upon using the GameBoy Cart:*
> A GameBoy Cartridge and a note with INSPECT written on it. But you 
> can't find anything else