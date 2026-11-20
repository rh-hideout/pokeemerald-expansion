@ Local IDs = order of object_events in map.json (1-indexed).
@ Intro state (VAR_PROTAG_INTRO_STATE): 0 start, 1 open the box, 2 choosing, 3 room trashed, 4 done.

.set LOCALID_CHEREN, 1
.set LOCALID_BIANCA, 2
.set LOCALID_GIFT_BOX, 3

ProtagHouse2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ProtagHouse2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ProtagHouse2F_OnFrame
	.byte 0

ProtagHouse2F_OnTransition:
	setflag FLAG_TEMP_2
	goto_if_ge VAR_PROTAG_INTRO_STATE, 4, ProtagHouse2F_OnTransition_Done
	goto_if_ge VAR_PROTAG_INTRO_STATE, 1, ProtagHouse2F_OnTransition_BiancaHere
	end

ProtagHouse2F_OnTransition_BiancaHere:
	clearflag FLAG_TEMP_2
	savebgm MUS_E_FRIEND
	end

ProtagHouse2F_OnTransition_Done:
	setflag FLAG_TEMP_3
	end

ProtagHouse2F_OnFrame:
	map_script_2 VAR_PROTAG_INTRO_STATE, 0, ProtagHouse2F_EventScript_Intro
	.2byte 0

@ ---------------------------------------------------------------- intro

ProtagHouse2F_EventScript_Intro::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, ProtagHouse2F_Movement_FaceLeft
	applymovement LOCALID_CHEREN, ProtagHouse2F_Movement_FaceRight
	waitmovement 0
	msgbox ProtagHouse2F_Text_0, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_1, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	addobject LOCALID_BIANCA
	playbgm MUS_E_FRIEND, TRUE
	applymovement LOCALID_BIANCA, ProtagHouse2F_Movement_BiancaEnter
	waitmovement 0
	msgbox ProtagHouse2F_Text_2, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_3, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_4, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_5, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_6, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_7, MSGBOX_DEFAULT
	setvar VAR_PROTAG_INTRO_STATE, 1
	releaseall
	end

ProtagHouse2F_EventScript_Cheren::
	lock
	faceplayer
	goto_if_eq VAR_PROTAG_INTRO_STATE, 1, ProtagHouse2F_EventScript_CherenHurryUp
	release
	end

ProtagHouse2F_EventScript_CherenHurryUp::
	msgbox ProtagHouse2F_Text_9, MSGBOX_DEFAULT
	release
	end

ProtagHouse2F_EventScript_Bianca::
	lock
	faceplayer
	goto_if_eq VAR_PROTAG_INTRO_STATE, 1, ProtagHouse2F_EventScript_BiancaHurryUp
	release
	end

ProtagHouse2F_EventScript_BiancaHurryUp::
	msgbox ProtagHouse2F_Text_10, MSGBOX_DEFAULT
	release
	end

@ Coord event on the exit tile while the player still has to open the box
ProtagHouse2F_EventScript_DontLeaveYet::
	lockall
	msgbox ProtagHouse2F_Text_8, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, ProtagHouse2F_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

@ ---------------------------------------------------------------- gift box + starters

ProtagHouse2F_EventScript_GiftBox::
	lockall
	goto_if_eq VAR_PROTAG_INTRO_STATE, 1, ProtagHouse2F_EventScript_OpenGiftBox
	msgbox ProtagHouse2F_Text_31, MSGBOX_DEFAULT   @ "...The box is empty."
	releaseall
	end

ProtagHouse2F_EventScript_OpenGiftBox::
	msgbox ProtagHouse2F_Text_11, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_12, MSGBOX_DEFAULT
	special ChooseStarterNoBattle
	switch VAR_STARTER_MON
	case 0, ProtagHouse2F_EventScript_GiveSnivy
	case 1, ProtagHouse2F_EventScript_GiveTepig
	case 2, ProtagHouse2F_EventScript_GiveOshawott
	end

ProtagHouse2F_EventScript_GiveSnivy::
	givemon SPECIES_SNIVY, 5
	bufferspeciesname STR_VAR_1, SPECIES_SNIVY
	goto ProtagHouse2F_EventScript_StarterChosen

ProtagHouse2F_EventScript_GiveTepig::
	givemon SPECIES_TEPIG, 5
	bufferspeciesname STR_VAR_1, SPECIES_TEPIG
	goto ProtagHouse2F_EventScript_StarterChosen

ProtagHouse2F_EventScript_GiveOshawott::
	givemon SPECIES_OSHAWOTT, 5
	bufferspeciesname STR_VAR_1, SPECIES_OSHAWOTT
	goto ProtagHouse2F_EventScript_StarterChosen

@ Cheren gets the starter that beats yours, Bianca the one yours beats.
@ VAR_STARTER_MON: 0 Snivy (grass), 1 Tepig (fire), 2 Oshawott (water)
ProtagHouse2F_EventScript_StarterChosen::
	setvar VAR_PROTAG_INTRO_STATE, 2
	msgbox ProtagHouse2F_Text_24, MSGBOX_DEFAULT   @ "{PLAYER} chose {STR_VAR_1}!" (STR_VAR_1 still = your starter)
	switch VAR_STARTER_MON
	case 0, ProtagHouse2F_EventScript_CherenHasTepig
	case 1, ProtagHouse2F_EventScript_CherenHasOshawott
	case 2, ProtagHouse2F_EventScript_CherenHasSnivy
	end

ProtagHouse2F_EventScript_CherenHasTepig::
	bufferspeciesname STR_VAR_1, SPECIES_TEPIG
	goto ProtagHouse2F_EventScript_RivalsPick

ProtagHouse2F_EventScript_CherenHasOshawott::
	bufferspeciesname STR_VAR_1, SPECIES_OSHAWOTT
	goto ProtagHouse2F_EventScript_RivalsPick

ProtagHouse2F_EventScript_CherenHasSnivy::
	bufferspeciesname STR_VAR_1, SPECIES_SNIVY
	goto ProtagHouse2F_EventScript_RivalsPick

ProtagHouse2F_EventScript_RivalsPick::
	msgbox ProtagHouse2F_Text_25, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_26, MSGBOX_DEFAULT   @ uses {STR_VAR_1} = Cheren's starter
	msgbox ProtagHouse2F_Text_27, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_28, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_29, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, ProtagHouse2F_EventScript_BiancaBattle_VsOshawott
	case 1, ProtagHouse2F_EventScript_BiancaBattle_VsSnivy
	case 2, ProtagHouse2F_EventScript_BiancaBattle_VsTepig
	end

@ ---------------------------------------------------------------- battle 1: Bianca

ProtagHouse2F_EventScript_BiancaBattle_VsSnivy::
	trainerbattle_earlyrival TRAINER_BIANCA_VS_SNIVY_NUVEMA_TOWN, RIVAL_BATTLE_HEAL_AFTER, ProtagHouse2F_Text_37, gText_EmptyString2
	goto ProtagHouse2F_EventScript_AfterBiancaBattle

ProtagHouse2F_EventScript_BiancaBattle_VsTepig::
	trainerbattle_earlyrival TRAINER_BIANCA_VS_TEPIG_NUVEMA_TOWN, RIVAL_BATTLE_HEAL_AFTER, ProtagHouse2F_Text_37, gText_EmptyString2
	goto ProtagHouse2F_EventScript_AfterBiancaBattle

ProtagHouse2F_EventScript_BiancaBattle_VsOshawott::
	trainerbattle_earlyrival TRAINER_BIANCA_VS_OSHAWOTT_NUVEMA_TOWN, RIVAL_BATTLE_HEAL_AFTER, ProtagHouse2F_Text_37, gText_EmptyString2
	goto ProtagHouse2F_EventScript_AfterBiancaBattle

ProtagHouse2F_EventScript_AfterBiancaBattle::
	goto_if_eq VAR_RESULT, FALSE, ProtagHouse2F_EventScript_RoomTrashed
	msgbox ProtagHouse2F_Text_38, MSGBOX_DEFAULT
	goto ProtagHouse2F_EventScript_RoomTrashed

ProtagHouse2F_EventScript_RoomTrashed::
	setvar VAR_PROTAG_INTRO_STATE, 3
	msgbox ProtagHouse2F_Text_39, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_40, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_41, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_42, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	message ProtagHouse2F_Text_43
	waitmessage
	waitfanfare
	closemessage
	msgbox ProtagHouse2F_Text_44, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	message ProtagHouse2F_Text_45
	waitmessage
	waitfanfare
	closemessage
	
	@ Check health and store in VAR_RESULT
	specialvar VAR_RESULT, IsFirstMonAtFullHP
	compare VAR_RESULT, 1
	goto_if_ne ProtagHouse2F_SkipText46

	msgbox ProtagHouse2F_Text_46, MSGBOX_DEFAULT  

ProtagHouse2F_SkipText46:: 
	msgbox ProtagHouse2F_Text_47, MSGBOX_DEFAULT
	msgbox ProtagHouse2F_Text_48, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, ProtagHouse2F_EventScript_CherenHasTepig2
	case 1, ProtagHouse2F_EventScript_CherenHasOshawott2
	case 2, ProtagHouse2F_EventScript_CherenHasSnivy2
	end


@ Re-buffer Cheren's starter name for msg 53 (STR_VAR_1 gets overwritten by other commands)
ProtagHouse2F_EventScript_CherenHasTepig2::
	bufferspeciesname STR_VAR_1, SPECIES_TEPIG
	msgbox ProtagHouse2F_Text_53, MSGBOX_DEFAULT
	trainerbattle_earlyrival TRAINER_CHEREN_VS_TEPIG_NUVEMA_TOWN, RIVAL_BATTLE_HEAL_AFTER, ProtagHouse2F_Text_55, gText_EmptyString2
	goto ProtagHouse2F_EventScript_AfterCherenBattle

ProtagHouse2F_EventScript_CherenHasOshawott2::
	bufferspeciesname STR_VAR_1, SPECIES_OSHAWOTT
	msgbox ProtagHouse2F_Text_53, MSGBOX_DEFAULT
	trainerbattle_earlyrival TRAINER_CHEREN_VS_OSHAWOTT_NUVEMA_TOWN, RIVAL_BATTLE_HEAL_AFTER, ProtagHouse2F_Text_55, gText_EmptyString2
	goto ProtagHouse2F_EventScript_AfterCherenBattle

ProtagHouse2F_EventScript_CherenHasSnivy2::
	bufferspeciesname STR_VAR_1, SPECIES_SNIVY
	msgbox ProtagHouse2F_Text_53, MSGBOX_DEFAULT
	trainerbattle_earlyrival TRAINER_CHEREN_VS_SNIVY_NUVEMA_TOWN, RIVAL_BATTLE_HEAL_AFTER, ProtagHouse2F_Text_55, gText_EmptyString2
	goto ProtagHouse2F_EventScript_AfterCherenBattle
@ ---------------------------------------------------------------- battle 2 aftermath

ProtagHouse2F_EventScript_AfterCherenBattle::
	goto_if_eq VAR_RESULT, FALSE, ProtagHouse2F_EventScript_IntroWrapUp
	msgbox ProtagHouse2F_Text_56, MSGBOX_DEFAULT
	goto ProtagHouse2F_EventScript_IntroWrapUp

ProtagHouse2F_EventScript_IntroWrapUp::
	msgbox ProtagHouse2F_Text_57, MSGBOX_DEFAULT
	@ Both walk to the exit tile and leave. Adjust paths to your layout.
	applymovement LOCALID_BIANCA, ProtagHouse2F_Movement_BiancaLeave
	waitmovement 0
	removeobject LOCALID_BIANCA
	setflag FLAG_TEMP_2
	applymovement LOCALID_CHEREN, ProtagHouse2F_Movement_CherenLeave
	waitmovement 0
	removeobject LOCALID_CHEREN
	setflag FLAG_TEMP_3
	setvar VAR_PROTAG_INTRO_STATE, 4
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

@ ---------------------------------------------------------------- room objects (bg events)

ProtagHouse2F_EventScript_Wii::
	lockall
	goto_if_ge VAR_PROTAG_INTRO_STATE, 3, ProtagHouse2F_EventScript_WiiAfter
	msgbox ProtagHouse2F_Text_58, MSGBOX_DEFAULT
	releaseall
	end

ProtagHouse2F_EventScript_WiiAfter::
	msgbox ProtagHouse2F_Text_59, MSGBOX_DEFAULT
	releaseall
	end

ProtagHouse2F_EventScript_TV::
	msgbox ProtagHouse2F_Text_60, MSGBOX_SIGN
	end

ProtagHouse2F_EventScript_Bed::
	lockall
	goto_if_ge VAR_PROTAG_INTRO_STATE, 3, ProtagHouse2F_EventScript_BedAfter
	msgbox ProtagHouse2F_Text_61, MSGBOX_DEFAULT
	releaseall
	end

ProtagHouse2F_EventScript_BedAfter::
	msgbox ProtagHouse2F_Text_62, MSGBOX_DEFAULT
	releaseall
	end

ProtagHouse2F_EventScript_PC::
	msgbox ProtagHouse2F_Text_63, MSGBOX_SIGN
	end

@ ---------------------------------------------------------------- movements

ProtagHouse2F_Movement_FaceLeft:
	face_left
	step_end

ProtagHouse2F_Movement_FaceRight:
	face_right
	step_end

ProtagHouse2F_Movement_WalkLeft:
	walk_left
	step_end

@ Bianca starts on the door tile (9,2), ends at (7,4) beside the player at (6,4)
ProtagHouse2F_Movement_BiancaEnter:
	walk_down
	walk_down
	walk_left
	walk_left
	face_left
	step_end

ProtagHouse2F_Movement_BiancaLeave:
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

ProtagHouse2F_Movement_CherenLeave:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

@ ---------------------------------------------------------------- text
ProtagHouse2F_Text_0:
        .string "Cheren: {PLAYER}!\p"
        .string "I heard from Professor Juniper.\n"
        .string "We can have a Pokémon?$"

ProtagHouse2F_Text_1:
        .string "...\n"
        .string "...\p"
        .string "What's keeping Bianca?$"

ProtagHouse2F_Text_2:
        .string "Bianca: Am I a little late again?\n"
        .string "So-oooo-orry!$"

ProtagHouse2F_Text_3:
        .string "Cheren: Bianca...\p"
        .string "I've known for ten years that you\n"
        .string "have no sense of time, but...seriously...\p"
        .string "Today's the day we can get a\n"
        .string "Pokémon from Professor Juniper!$"

ProtagHouse2F_Text_4:
        .string "Bianca: I know. Sorry, {PLAYER}.\n"
        .string "Sorry, Cheren.$"

ProtagHouse2F_Text_5:
        .string "Bianca: So, where are the Pokémon?\p"
        .string "They were delivered to {PLAYER}'s\n"
        .string "house, so {PLAYER} gets first pick.$"

ProtagHouse2F_Text_6:
        .string "Cheren: Naturally.$"

ProtagHouse2F_Text_7:
        .string "The Pokémon are waiting for us\n"
        .string "inside that gift box.\p"
        .string "OK, {PLAYER}, you go first and take\n"
        .string "a peek at the gift box.\p"
        .string "I want to meet the Pokémon right now!$"

ProtagHouse2F_Text_8:
        .string "Cheren: Aren't you going to check\n"
        .string "out the gift box? Where are you going?$"

ProtagHouse2F_Text_9:
        .string "Cheren: Would you get a move on\n"
        .string "and open the gift box already?\p"
        .string "I'm sure the Pokémon are just as\n"
        .string "excited to meet us!$"

ProtagHouse2F_Text_10:
        .string "Bianca: Ooh!\n"
        .string "What kind of Pokémon could they be?$"

ProtagHouse2F_Text_11:
        .string "{PLAYER} opened the gift box!$"

ProtagHouse2F_Text_12:
        .string "I've brought three Pokémon,\n"
        .string "one for you and one for each\l"
        .string "of your friends. Please settle\l"
        .string "your choices politely.\l"
        .string "Enjoy your Pokémon!\l"
        .string "                --Professor Juniper$"

ProtagHouse2F_Text_16:
        .string "The Water-type Pokémon\n"
        .string "{STR_VAR_1}$"

ProtagHouse2F_Text_17:
        .string "The Fire-type Pokémon\n"
        .string "{STR_VAR_1}$"

ProtagHouse2F_Text_18:
        .string "The Grass-type Pokémon\n"
        .string "{STR_VAR_1}$"

ProtagHouse2F_Text_19:
        .string "Choose a Pokémon.$"

ProtagHouse2F_Text_20:
        .string "Is this the Pokémon you want?$"

ProtagHouse2F_Text_21:
        .string "Pick this one!$"

ProtagHouse2F_Text_22:
        .string "YES$"

ProtagHouse2F_Text_23:
        .string "NO$"

ProtagHouse2F_Text_24:
        .string "{PLAYER} chose\n"
        .string "{STR_VAR_1}!$"

ProtagHouse2F_Text_25:
        .string "Bianca: OK, I'll take this Pokémon!\n"
        .string "Cheren, that one's yours!$"

ProtagHouse2F_Text_26:
        .string "Cheren: Hey, how come you get to pick\n"
        .string "out my Pokémon?\p"
        .string "Oh, never mind. I wanted {STR_VAR_1}\n"
        .string "from the start, anyway.$"

ProtagHouse2F_Text_27:
        .string "Bianca: Everyone has chosen a Pokémon!\n"
        .string "...So that's that!\p"
        .string "Hey, I know!\n"
        .string "Let's have a Pokémon battle!$"

ProtagHouse2F_Text_28:
        .string "Cheren: Honestly, Bianca...\p"
        .string "Even though they're still weak Pokémon,\n"
        .string "you shouldn't have Pokémon battles\l"
        .string "inside a house.$"

ProtagHouse2F_Text_29:
        .string "Bianca: Don't be a worrywart!\n"
        .string "These little ones are weak, like you said.\p"
        .string "We have to let them battle so they'll get\n"
        .string "stronger. It's settled, {PLAYER}!\l"
        .string "Get ready for a Pokémon battle!$"

ProtagHouse2F_Text_31:
        .string "...The box is empty.$"

ProtagHouse2F_Text_37:
        .string "Bianca: Wow...\p"
        .string "{PLAYER}, you're gonna be\n"
        .string "an awesome Trainer someday, I can tell!\p"
        .string "No doubt!$"

ProtagHouse2F_Text_38:
        .string "Bianca: Wha...?\p"
        .string "I got so absorbed in having my Pokémon\n"
        .string "use moves, I won before even realizing...$"

ProtagHouse2F_Text_39:
        .string "Cheren: Uh...\n"
        .string "...\p"
        .string "Bianca, would you take a look around?$"

ProtagHouse2F_Text_40:
        .string "Bianca: Wh-whoa!\n"
        .string "What happened?!$"

ProtagHouse2F_Text_41:
        .string "Wow! Pokémon are amaaaaazing!!\n"
        .string "So little, but so strong!\p"
        .string "I'm so glad that I get to have a Pokémon!\p"
        .string "...Oh.\n"
        .string "Um, sorry about your room, {PLAYER}.$"

ProtagHouse2F_Text_42:
        .string "Cheren: You...are completely hopeless.\p"
        .string "Here!\n"
        .string "I'll restore your Pokémon for you.$"

ProtagHouse2F_Text_43:
        .string "Cheren healed Bianca's Pokémon!$"

ProtagHouse2F_Text_44:
        .string "{PLAYER}'s Pokémon needs\n"
        .string "to be fixed up, too.$"

ProtagHouse2F_Text_45:
        .string "Cheren healed {PLAYER}'s Pokémon!$"

ProtagHouse2F_Text_46:
        .string "Cheren: It's amazing that you won\n"
        .string "without your Pokémon's losing any\l"
        .string "energy, which is called HP.\p"
        .string "But you used some of the moves'\n"
        .string "Power Points, or PP, though.$"

ProtagHouse2F_Text_47:
        .string "Bianca: Hey, Cheren!\n"
        .string "How about you battle, too?\p"
        .string "With all you know, I'm sure you can\n"
        .string "battle without turning the room into\l"
        .string "a disaster area like I did!$"

ProtagHouse2F_Text_48:
        .string "Cheren: I believe you're right!\p"
        .string "It'll be no problem for me to keep\n"
        .string "the room from getting any messier.\p"
        .string "Besides, it's not fair if you two are the\n"
        .string "only ones who get to have fun battling!$"

ProtagHouse2F_Text_53:
        .string "It's decided. You'll be my opponent...\n"
        .string "in our first Pokémon battle!\p"
        .string "Let's see what you can do, {STR_VAR_1}!$"

ProtagHouse2F_Text_55:
        .string "Cheren: I made a strange blunder\n"
        .string "in my first battle, but\l"
        .string "this feeling I have...\l"
        .string "...I'm finally a Trainer.\p"
        .string "But first, we'd better go apologize to\n"
        .string "your mother about this messed-up room.$"

ProtagHouse2F_Text_56:
        .string "Cheren: This feeling...\n"
        .string "Finally, I'm a Trainer.\p"
        .string "On top of that, we'd better go apologize\n"
        .string "to your mother about this room.$"

ProtagHouse2F_Text_57:
        .string "Bianca: Oh!\n"
        .string "I'd better come, too!$"

ProtagHouse2F_Text_58:
        .string "It's a Wii console!\n"
        .string "It has a Wii Remote!$"

ProtagHouse2F_Text_59:
        .string "It's a Wii console!\p"
        .string "It's not even scratched!$"

ProtagHouse2F_Text_60:
        .string "It's a flat-screen television\n"
        .string "that Dad bought!$"

ProtagHouse2F_Text_61:
        .string "It's a bed.\p"
        .string "The sheets smell great because\n"
        .string "Mom just washed them!$"

ProtagHouse2F_Text_62:
        .string "The bed's a mess!$"

ProtagHouse2F_Text_63:
        .string "{PLAYER} checked the PC.\p"
        .string "Pokémon Basics...\p"
        .string "People live alongside Pokémon in\n"
        .string "this world.\p"
        .string "The people who battle with Pokémon\n"
        .string "are called Pokémon Trainers.$"
