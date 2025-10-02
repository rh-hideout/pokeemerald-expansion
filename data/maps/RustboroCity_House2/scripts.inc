# 1 "data/maps/RustboroCity_House2/scripts.pory"

# 2 "data/maps/RustboroCity_House2/scripts.pory"
RustboroCity_House2_MapScripts::
# 3 "data/maps/RustboroCity_House2/scripts.pory"
	.byte 0

RustboroCity_House2_EventScript_Give_LowKick::
# 10 "data/maps/RustboroCity_House2/scripts.pory"
	faceplayer
# 11 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 12 "data/maps/RustboroCity_House2/scripts.pory"
	goto_if_unset FLAG_LOW_SWEEP_TM, RustboroCity_House2_EventScript_Give_LowKick_1
# 21 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_Give_LowKick_Text_1, MSGBOX_DEFAULT
# 22 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end

RustboroCity_House2_EventScript_Give_LowKick_1:
# 14 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_Give_LowKick_Text_0
# 15 "data/maps/RustboroCity_House2/scripts.pory"
	giveitem ITEM_TM_LOW_SWEEP, 1
# 16 "data/maps/RustboroCity_House2/scripts.pory"
	setflag FLAG_LOW_SWEEP_TM
# 17 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end


RustboroCity_House2_EventScript_KantoStarter::
# 28 "data/maps/RustboroCity_House2/scripts.pory"
	faceplayer
# 29 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 30 "data/maps/RustboroCity_House2/scripts.pory"
	goto_if_unset FLAG_KANTO_STARTER_GET, RustboroCity_House2_EventScript_KantoStarter_2
# 38 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_Text_0, MSGBOX_DEFAULT
# 39 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end

# 42 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end

RustboroCity_House2_EventScript_KantoStarter_2:
# 32 "data/maps/RustboroCity_House2/scripts.pory"
	call RustboroCity_House2_EventScript_KantoStarter_Start
# 33 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end


RustboroCity_House2_EventScript_KantoStarter_Start::
# 49 "data/maps/RustboroCity_House2/scripts.pory"
	getpartysize
# 50 "data/maps/RustboroCity_House2/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_ne RustboroCity_House2_EventScript_KantoStarter_Start_1
# 68 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_Start_Text_2, MSGBOX_DEFAULT
# 69 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end

RustboroCity_House2_EventScript_KantoStarter_Start_1:
# 52 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_Start_Text_0, MSGBOX_YESNO
# 55 "data/maps/RustboroCity_House2/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_House2_EventScript_KantoStarter_Start_4
# 61 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_Start_Text_1, MSGBOX_DEFAULT
# 62 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end

RustboroCity_House2_EventScript_KantoStarter_Start_4:
# 57 "data/maps/RustboroCity_House2/scripts.pory"
	call RustboroCity_House2_EventScript_KantoStarter_GenerateEgg
	return


RustboroCity_House2_EventScript_KantoStarter_GenerateEgg::
# 76 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 77 "data/maps/RustboroCity_House2/scripts.pory"
	faceplayer
# 78 "data/maps/RustboroCity_House2/scripts.pory"
	random 3
# 79 "data/maps/RustboroCity_House2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_2
# 88 "data/maps/RustboroCity_House2/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_3
# 97 "data/maps/RustboroCity_House2/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_4
# 108 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_1
	return

# 111 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_2, MSGBOX_DEFAULT
	return

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_2:
# 81 "data/maps/RustboroCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 82 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 83 "data/maps/RustboroCity_House2/scripts.pory"
	waitfanfare
# 84 "data/maps/RustboroCity_House2/scripts.pory"
	giveegg SPECIES_BULBASAUR
# 85 "data/maps/RustboroCity_House2/scripts.pory"
	setflag FLAG_KANTO_STARTER_GET
	return

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_3:
# 90 "data/maps/RustboroCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 91 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 92 "data/maps/RustboroCity_House2/scripts.pory"
	waitfanfare
# 93 "data/maps/RustboroCity_House2/scripts.pory"
	giveegg SPECIES_SQUIRTLE
# 94 "data/maps/RustboroCity_House2/scripts.pory"
	setflag FLAG_KANTO_STARTER_GET
	return

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_4:
# 99 "data/maps/RustboroCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 100 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 101 "data/maps/RustboroCity_House2/scripts.pory"
	waitfanfare
# 102 "data/maps/RustboroCity_House2/scripts.pory"
	giveegg SPECIES_CHARMANDER
# 103 "data/maps/RustboroCity_House2/scripts.pory"
	setflag FLAG_KANTO_STARTER_GET
	return


RustboroCity_House2_EventScript_Bulbasaur::
# 117 "data/maps/RustboroCity_House2/scripts.pory"
	applymovement 3, RustboroCity_House2_EventScript_Bulbasaur_Movement_0
# 118 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 119 "data/maps/RustboroCity_House2/scripts.pory"
	playmoncry SPECIES_BULBASAUR, CRY_MODE_ENCOUNTER
# 120 "data/maps/RustboroCity_House2/scripts.pory"
	waitmoncry
# 121 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_Bulbasaur_Text_0, MSGBOX_DEFAULT
# 122 "data/maps/RustboroCity_House2/scripts.pory"
	turnobject 3, DIR_WEST
# 123 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end


RustboroCity_House2_EventScript_Squirtle::
# 128 "data/maps/RustboroCity_House2/scripts.pory"
	applymovement 4, RustboroCity_House2_EventScript_Bulbasaur_Movement_0
# 129 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 130 "data/maps/RustboroCity_House2/scripts.pory"
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_ENCOUNTER
# 131 "data/maps/RustboroCity_House2/scripts.pory"
	waitmoncry
# 132 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_Squirtle_Text_0, MSGBOX_DEFAULT
# 133 "data/maps/RustboroCity_House2/scripts.pory"
	turnobject 4, DIR_SOUTH
# 134 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end


RustboroCity_House2_EventScript_Charmander::
# 139 "data/maps/RustboroCity_House2/scripts.pory"
	applymovement 5, RustboroCity_House2_EventScript_Bulbasaur_Movement_0
# 140 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 141 "data/maps/RustboroCity_House2/scripts.pory"
	playmoncry SPECIES_CHARMANDER, CRY_MODE_ENCOUNTER
# 142 "data/maps/RustboroCity_House2/scripts.pory"
	waitmoncry
# 143 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_Charmander_Text_0, MSGBOX_DEFAULT
# 144 "data/maps/RustboroCity_House2/scripts.pory"
	turnobject 5, DIR_NORTH
# 145 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end


# 117 "data/maps/RustboroCity_House2/scripts.pory"
RustboroCity_House2_EventScript_Bulbasaur_Movement_0:
# 117 "data/maps/RustboroCity_House2/scripts.pory"
	face_player
	step_end

RustboroCity_House2_EventScript_Give_LowKick_Text_0:
# 14 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Here, take this!!$"

RustboroCity_House2_EventScript_Give_LowKick_Text_1:
# 21 "data/maps/RustboroCity_House2/scripts.pory"
	.string "My mom says that move is really\n"
	.string "powerful!$"

RustboroCity_House2_EventScript_KantoStarter_Text_0:
# 38 "data/maps/RustboroCity_House2/scripts.pory"
	.string "POKéMON are the essential bonds that\n"
	.string "bring us together. Please treat that\l"
	.string "POKéMON with love.$"

RustboroCity_House2_EventScript_KantoStarter_Start_Text_0:
# 52 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Hello, dear. I lived in the Kanto region\n"
	.string "for many years, raising starter POKéMON\l"
	.string "for all new trainers. I have moved to\l"
	.string "the Hoenn region to help the developing\l"
	.string "trainer school. You seem relatively new\l"
	.string "to your adventure; would you like a\l"
	.string "starter egg from Kanto?$"

RustboroCity_House2_EventScript_KantoStarter_Start_Text_1:
# 61 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Oh, well. You know where to find me.$"

RustboroCity_House2_EventScript_KantoStarter_Start_Text_2:
# 68 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Oh hello, dear. I have a Kanto starter\n"
	.string "egg to give away, so please return with\l"
	.string "room.$"

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_0:
# 82 "data/maps/RustboroCity_House2/scripts.pory"
	.string "{PLAYER} obtained the egg!$"

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_1:
# 108 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Hmmm, try again.$"

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_2:
# 111 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Please, raise this POKéMON with care.$"

RustboroCity_House2_EventScript_Bulbasaur_Text_0:
# 121 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Bulbasaur looks like it's smirking.$"

RustboroCity_House2_EventScript_Squirtle_Text_0:
# 132 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Squirtle looks like they want you to\n"
	.string "scratch their shell.$"

RustboroCity_House2_EventScript_Charmander_Text_0:
# 143 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Charmander is looking around for\n"
	.string "anything flammable.$"
