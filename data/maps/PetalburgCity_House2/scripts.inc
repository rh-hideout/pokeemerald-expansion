# 1 "data/maps/PetalburgCity_House2/scripts.pory"

# 2 "data/maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_MapScripts::
# 3 "data/maps/PetalburgCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/PetalburgCity_House2/scripts.pory"

# 5 "data/maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_Woman::
# 6 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
# 7 "data/maps/PetalburgCity_House2/scripts.pory"
	end
# 8 "data/maps/PetalburgCity_House2/scripts.pory"

# 9 "data/maps/PetalburgCity_House2/scripts.pory"

# 10 "data/maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_NormanBecameGymLeader:
# 11 "data/maps/PetalburgCity_House2/scripts.pory"
	.string "NORMAN became our town's new\n"
# 12 "data/maps/PetalburgCity_House2/scripts.pory"
	.string "GYM LEADER.\p"
# 13 "data/maps/PetalburgCity_House2/scripts.pory"
	.string "I think he called his family over from\n"
# 14 "data/maps/PetalburgCity_House2/scripts.pory"
	.string "somewhere far away.$"

PetalburgCity_House2_EventScript_SchoolKid::
# 19 "data/maps/PetalburgCity_House2/scripts.pory"
	faceplayer
# 20 "data/maps/PetalburgCity_House2/scripts.pory"
	lock
# 21 "data/maps/PetalburgCity_House2/scripts.pory"
	goto_if_unset FLAG_GET_PETALBURG_EGG, PetalburgCity_House2_EventScript_SchoolKid_1
# 39 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_SchoolKid_Text_2, MSGBOX_DEFAULT
# 40 "data/maps/PetalburgCity_House2/scripts.pory"
	release
	end

PetalburgCity_House2_EventScript_SchoolKid_1:
# 23 "data/maps/PetalburgCity_House2/scripts.pory"
	getpartysize
# 24 "data/maps/PetalburgCity_House2/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_ne PetalburgCity_House2_EventScript_SchoolKid_5
# 29 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_SchoolKid_Text_0, MSGBOX_DEFAULT
# 30 "data/maps/PetalburgCity_House2/scripts.pory"
	release
	end

PetalburgCity_House2_EventScript_SchoolKid_4:
# 33 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_SchoolKid_Text_1, MSGBOX_DEFAULT
# 34 "data/maps/PetalburgCity_House2/scripts.pory"
	release
	end

PetalburgCity_House2_EventScript_SchoolKid_5:
# 26 "data/maps/PetalburgCity_House2/scripts.pory"
	call PetalburgCity_House2_EventScript_GetEgg
	goto PetalburgCity_House2_EventScript_SchoolKid_4


PetalburgCity_House2_EventScript_GetEgg::
# 46 "data/maps/PetalburgCity_House2/scripts.pory"
	lock
# 47 "data/maps/PetalburgCity_House2/scripts.pory"
	faceplayer
# 48 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_GetEgg_Text_0, MSGBOX_YESNO
# 50 "data/maps/PetalburgCity_House2/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_House2_EventScript_GetEgg_1
# 57 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_GetEgg_Text_1, MSGBOX_DEFAULT
# 58 "data/maps/PetalburgCity_House2/scripts.pory"
	release
	end

PetalburgCity_House2_EventScript_GetEgg_1:
# 52 "data/maps/PetalburgCity_House2/scripts.pory"
	call PetalburgCity_House2_EventScript_GenerateEgg
	return


PetalburgCity_House2_EventScript_GenerateEgg::
# 64 "data/maps/PetalburgCity_House2/scripts.pory"
	lock
# 65 "data/maps/PetalburgCity_House2/scripts.pory"
	faceplayer
# 66 "data/maps/PetalburgCity_House2/scripts.pory"
	random 7
# 67 "data/maps/PetalburgCity_House2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_House2_EventScript_GenerateEgg_2
# 76 "data/maps/PetalburgCity_House2/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_House2_EventScript_GenerateEgg_3
# 85 "data/maps/PetalburgCity_House2/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq PetalburgCity_House2_EventScript_GenerateEgg_4
# 94 "data/maps/PetalburgCity_House2/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq PetalburgCity_House2_EventScript_GenerateEgg_5
# 103 "data/maps/PetalburgCity_House2/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq PetalburgCity_House2_EventScript_GenerateEgg_6
# 112 "data/maps/PetalburgCity_House2/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq PetalburgCity_House2_EventScript_GenerateEgg_7
# 121 "data/maps/PetalburgCity_House2/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq PetalburgCity_House2_EventScript_GenerateEgg_8
# 130 "data/maps/PetalburgCity_House2/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq PetalburgCity_House2_EventScript_GenerateEgg_9
	return

PetalburgCity_House2_EventScript_GenerateEgg_2:
# 69 "data/maps/PetalburgCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 70 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 71 "data/maps/PetalburgCity_House2/scripts.pory"
	waitfanfare
# 72 "data/maps/PetalburgCity_House2/scripts.pory"
	giveegg SPECIES_CHINGLING
# 73 "data/maps/PetalburgCity_House2/scripts.pory"
	setflag FLAG_GET_PETALBURG_EGG
	return

PetalburgCity_House2_EventScript_GenerateEgg_3:
# 78 "data/maps/PetalburgCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 79 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 80 "data/maps/PetalburgCity_House2/scripts.pory"
	waitfanfare
# 81 "data/maps/PetalburgCity_House2/scripts.pory"
	giveegg SPECIES_PICHU
# 82 "data/maps/PetalburgCity_House2/scripts.pory"
	setflag FLAG_GET_PETALBURG_EGG
	return

PetalburgCity_House2_EventScript_GenerateEgg_4:
# 87 "data/maps/PetalburgCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 88 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 89 "data/maps/PetalburgCity_House2/scripts.pory"
	waitfanfare
# 90 "data/maps/PetalburgCity_House2/scripts.pory"
	giveegg SPECIES_CLEFFA
# 91 "data/maps/PetalburgCity_House2/scripts.pory"
	setflag FLAG_GET_PETALBURG_EGG
	return

PetalburgCity_House2_EventScript_GenerateEgg_5:
# 96 "data/maps/PetalburgCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 97 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 98 "data/maps/PetalburgCity_House2/scripts.pory"
	waitfanfare
# 99 "data/maps/PetalburgCity_House2/scripts.pory"
	giveegg SPECIES_IGGLYBUFF
# 100 "data/maps/PetalburgCity_House2/scripts.pory"
	setflag FLAG_GET_PETALBURG_EGG
	return

PetalburgCity_House2_EventScript_GenerateEgg_6:
# 105 "data/maps/PetalburgCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 106 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 107 "data/maps/PetalburgCity_House2/scripts.pory"
	waitfanfare
# 108 "data/maps/PetalburgCity_House2/scripts.pory"
	giveegg SPECIES_BUDEW
# 109 "data/maps/PetalburgCity_House2/scripts.pory"
	setflag FLAG_GET_PETALBURG_EGG
	return

PetalburgCity_House2_EventScript_GenerateEgg_7:
# 114 "data/maps/PetalburgCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 115 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 116 "data/maps/PetalburgCity_House2/scripts.pory"
	waitfanfare
# 117 "data/maps/PetalburgCity_House2/scripts.pory"
	giveegg SPECIES_WOOBAT
# 118 "data/maps/PetalburgCity_House2/scripts.pory"
	setflag FLAG_GET_PETALBURG_EGG
	return

PetalburgCity_House2_EventScript_GenerateEgg_8:
# 123 "data/maps/PetalburgCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 124 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 125 "data/maps/PetalburgCity_House2/scripts.pory"
	waitfanfare
# 126 "data/maps/PetalburgCity_House2/scripts.pory"
	giveegg SPECIES_SNOM
# 127 "data/maps/PetalburgCity_House2/scripts.pory"
	setflag FLAG_GET_PETALBURG_EGG
	return

PetalburgCity_House2_EventScript_GenerateEgg_9:
# 132 "data/maps/PetalburgCity_House2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 133 "data/maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_EventScript_GenerateEgg_Text_0, MSGBOX_DEFAULT
# 134 "data/maps/PetalburgCity_House2/scripts.pory"
	waitfanfare
# 135 "data/maps/PetalburgCity_House2/scripts.pory"
	giveegg SPECIES_MUNCHLAX
# 136 "data/maps/PetalburgCity_House2/scripts.pory"
	setflag FLAG_GET_PETALBURG_EGG
	return


PetalburgCity_House2_EventScript_SchoolKid_Text_0:
# 29 "data/maps/PetalburgCity_House2/scripts.pory"
	.string "I have a gift, but it looks like you\n"
	.string "don't have room in your party.$"

PetalburgCity_House2_EventScript_SchoolKid_Text_1:
# 33 "data/maps/PetalburgCity_House2/scripts.pory"
	.string "Even I don't know what species it can\n"
	.string "be!$"

PetalburgCity_House2_EventScript_SchoolKid_Text_2:
# 39 "data/maps/PetalburgCity_House2/scripts.pory"
	.string "Treat the egg well please!$"

PetalburgCity_House2_EventScript_GetEgg_Text_0:
# 48 "data/maps/PetalburgCity_House2/scripts.pory"
	.string "The trainer school gave me an egg that\n"
	.string "will evolve via friendship, but I already\l"
	.string "have a full party. Would you like to take\l"
	.string "it?$"

PetalburgCity_House2_EventScript_GetEgg_Text_1:
# 57 "data/maps/PetalburgCity_House2/scripts.pory"
	.string "Come back if you change your mind!$"

PetalburgCity_House2_EventScript_GenerateEgg_Text_0:
# 70 "data/maps/PetalburgCity_House2/scripts.pory"
	.string "{PLAYER} obtained the egg!$"
