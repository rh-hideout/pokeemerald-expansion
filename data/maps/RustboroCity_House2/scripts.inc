# 1 "data/maps/RustboroCity_House2/scripts.pory"

# 2 "data/maps/RustboroCity_House2/scripts.pory"
RustboroCity_House2_MapScripts::
# 3 "data/maps/RustboroCity_House2/scripts.pory"
	.byte 0

RustboroCity_House2_EventScript_Girl::
# 10 "data/maps/RustboroCity_House2/scripts.pory"
	faceplayer
# 11 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 12 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_Girl_Text_0, MSGBOX_DEFAULT
# 13 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end


RustboroCity_House2_EventScript_KantoStarter::
# 19 "data/maps/RustboroCity_House2/scripts.pory"
	faceplayer
# 20 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 21 "data/maps/RustboroCity_House2/scripts.pory"
	goto_if_unset FLAG_KANTO_STARTER_GET, RustboroCity_House2_EventScript_KantoStarter_2
# 29 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_Text_0, MSGBOX_DEFAULT
# 30 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end

# 33 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end

RustboroCity_House2_EventScript_KantoStarter_2:
# 23 "data/maps/RustboroCity_House2/scripts.pory"
	call RustboroCity_House2_EventScript_KantoStarter_Start
# 24 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end


RustboroCity_House2_EventScript_KantoStarter_Start::
# 40 "data/maps/RustboroCity_House2/scripts.pory"
	getpartysize
# 41 "data/maps/RustboroCity_House2/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_ne RustboroCity_House2_EventScript_KantoStarter_Start_1
# 59 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_Start_Text_2, MSGBOX_DEFAULT
# 60 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end

RustboroCity_House2_EventScript_KantoStarter_Start_1:
# 43 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_Start_Text_0, MSGBOX_YESNO
# 46 "data/maps/RustboroCity_House2/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_House2_EventScript_KantoStarter_Start_4
# 52 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_Start_Text_1, MSGBOX_DEFAULT
# 53 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end

RustboroCity_House2_EventScript_KantoStarter_Start_4:
# 48 "data/maps/RustboroCity_House2/scripts.pory"
	call RustboroCity_House2_EventScript_KantoStarter_GenerateEgg
	return


RustboroCity_House2_EventScript_KantoStarter_GenerateEgg::
# 67 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 68 "data/maps/RustboroCity_House2/scripts.pory"
	faceplayer
# 69 "data/maps/RustboroCity_House2/scripts.pory"
	random 3
# 70 "data/maps/RustboroCity_House2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_2
# 79 "data/maps/RustboroCity_House2/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_3
# 88 "data/maps/RustboroCity_House2/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_4
# 99 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_1
	return

# 102 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_2, MSGBOX_DEFAULT
	return

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_2:
# 72 "data/maps/RustboroCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 73 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 74 "data/maps/RustboroCity_House2/scripts.pory"
	waitfanfare
# 75 "data/maps/RustboroCity_House2/scripts.pory"
	giveegg SPECIES_BULBASAUR
# 76 "data/maps/RustboroCity_House2/scripts.pory"
	setflag FLAG_KANTO_STARTER_GET
	return

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_3:
# 81 "data/maps/RustboroCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 82 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 83 "data/maps/RustboroCity_House2/scripts.pory"
	waitfanfare
# 84 "data/maps/RustboroCity_House2/scripts.pory"
	giveegg SPECIES_SQUIRTLE
# 85 "data/maps/RustboroCity_House2/scripts.pory"
	setflag FLAG_KANTO_STARTER_GET
	return

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_4:
# 90 "data/maps/RustboroCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 91 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 92 "data/maps/RustboroCity_House2/scripts.pory"
	waitfanfare
# 93 "data/maps/RustboroCity_House2/scripts.pory"
	giveegg SPECIES_CHARMANDER
# 94 "data/maps/RustboroCity_House2/scripts.pory"
	setflag FLAG_KANTO_STARTER_GET
	return


RustboroCity_House2_EventScript_Bulbasaur::
# 108 "data/maps/RustboroCity_House2/scripts.pory"
	applymovement 3, RustboroCity_House2_EventScript_Bulbasaur_Movement_0
# 109 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 110 "data/maps/RustboroCity_House2/scripts.pory"
	playmoncry SPECIES_BULBASAUR, CRY_MODE_ENCOUNTER
# 111 "data/maps/RustboroCity_House2/scripts.pory"
	waitmoncry
# 112 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_Bulbasaur_Text_0, MSGBOX_DEFAULT
# 113 "data/maps/RustboroCity_House2/scripts.pory"
	turnobject 3, DIR_WEST
# 114 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end


RustboroCity_House2_EventScript_Squirtle::
# 119 "data/maps/RustboroCity_House2/scripts.pory"
	applymovement 4, RustboroCity_House2_EventScript_Bulbasaur_Movement_0
# 120 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 121 "data/maps/RustboroCity_House2/scripts.pory"
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_ENCOUNTER
# 122 "data/maps/RustboroCity_House2/scripts.pory"
	waitmoncry
# 123 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_Squirtle_Text_0, MSGBOX_DEFAULT
# 124 "data/maps/RustboroCity_House2/scripts.pory"
	turnobject 4, DIR_SOUTH
# 125 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end


RustboroCity_House2_EventScript_Charmander::
# 130 "data/maps/RustboroCity_House2/scripts.pory"
	applymovement 5, RustboroCity_House2_EventScript_Bulbasaur_Movement_0
# 131 "data/maps/RustboroCity_House2/scripts.pory"
	lock
# 132 "data/maps/RustboroCity_House2/scripts.pory"
	playmoncry SPECIES_CHARMANDER, CRY_MODE_ENCOUNTER
# 133 "data/maps/RustboroCity_House2/scripts.pory"
	waitmoncry
# 134 "data/maps/RustboroCity_House2/scripts.pory"
	msgbox RustboroCity_House2_EventScript_Charmander_Text_0, MSGBOX_DEFAULT
# 135 "data/maps/RustboroCity_House2/scripts.pory"
	turnobject 5, DIR_NORTH
# 136 "data/maps/RustboroCity_House2/scripts.pory"
	release
	end


# 108 "data/maps/RustboroCity_House2/scripts.pory"
RustboroCity_House2_EventScript_Bulbasaur_Movement_0:
# 108 "data/maps/RustboroCity_House2/scripts.pory"
	face_player
	step_end

RustboroCity_House2_EventScript_Girl_Text_0:
# 12 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Bulbasaur is my favorite! But Squirtle\n"
	.string "is tough! And Charmander is so cute...$"

RustboroCity_House2_EventScript_KantoStarter_Text_0:
# 29 "data/maps/RustboroCity_House2/scripts.pory"
	.string "POKéMON are the essential bonds that\n"
	.string "bring us together. Please treat that\l"
	.string "POKéMON with love.$"

RustboroCity_House2_EventScript_KantoStarter_Start_Text_0:
# 43 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Hello, dear. I lived in the Kanto region\n"
	.string "for many years, raising starter POKéMON\l"
	.string "for all new trainers. I have moved to\l"
	.string "the Hoenn region to help the developing\l"
	.string "trainer school. You seem relatively new\l"
	.string "to your adventure; would you like a\l"
	.string "starter egg from Kanto?$"

RustboroCity_House2_EventScript_KantoStarter_Start_Text_1:
# 52 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Oh, well. You know where to find me.$"

RustboroCity_House2_EventScript_KantoStarter_Start_Text_2:
# 59 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Oh hello, dear. I have a Kanto starter\n"
	.string "egg to give away, so please return with\l"
	.string "room.$"

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_0:
# 73 "data/maps/RustboroCity_House2/scripts.pory"
	.string "{PLAYER} obtained the egg!$"

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_1:
# 99 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Hmmm, try again.$"

RustboroCity_House2_EventScript_KantoStarter_GenerateEgg_Text_2:
# 102 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Please, raise this POKéMON with care.$"

RustboroCity_House2_EventScript_Bulbasaur_Text_0:
# 112 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Bulbasaur looks like it's smirking.$"

RustboroCity_House2_EventScript_Squirtle_Text_0:
# 123 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Squirtle looks like they want you to\n"
	.string "scratch their shell.$"

RustboroCity_House2_EventScript_Charmander_Text_0:
# 134 "data/maps/RustboroCity_House2/scripts.pory"
	.string "Charmander is looking around for\n"
	.string "anything flammable.$"
