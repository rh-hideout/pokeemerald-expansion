LavenderTown_House1_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_Girl::
	msgbox LavenderTown_House1_Text_Girl, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Guy::
	msgbox LavenderTown_House1_Text_Guy, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Marowak::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Marowak, MSGBOX_DEFAULT
	waitmoncry
	msgbox LavenderTown_House1_Text_Marowak2, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_House1_Text_Girl:
	.string "Can you believe it?\p"
	.string "Some people get bored with taking\n"
	.string "care of POKéMON.\p"
	.string "GRANPDA takes in such poor homeless\n"
	.string "POKéMON and takes care of them.$"
LavenderTown_House1_Text_Guy:
	.string "MR. FUJI does live here but he's\n"
	.string "away now. He should be at the\l"
	.string "SOUL HOUSE.$"
LavenderTown_House1_Text_Marowak:
	.string ".............................$"

LavenderTown_House1_Text_Marowak2:
	.string "The MAROWAK is quiet, though it\n"
	.string "appears quite happy.$"

