PetalburgCity_House3_MapScripts::
	.byte 0


PetalburgCity_EventScript_LavaridgeMigrant::
# 4 "data/maps/PetalburgCity_House3/scripts.pory"
	lock
# 5 "data/maps/PetalburgCity_House3/scripts.pory"
	faceplayer
# 6 "data/maps/PetalburgCity_House3/scripts.pory"
	goto_if_set FLAG_RECEIVED_ARMOR, PetalburgCity_EventScript_GaveArmor
# 7 "data/maps/PetalburgCity_House3/scripts.pory"
	msgbox PetalburgCity_EventScript_LavaridgeMigrant_Text_0, MSGBOX_DEFAULT
# 8 "data/maps/PetalburgCity_House3/scripts.pory"
	msgbox PetalburgCity_EventScript_LavaridgeMigrant_Text_1, MSGBOX_DEFAULT
# 9 "data/maps/PetalburgCity_House3/scripts.pory"
	msgbox PetalburgCity_EventScript_LavaridgeMigrant_Text_2, MSGBOX_DEFAULT
# 10 "data/maps/PetalburgCity_House3/scripts.pory"
	message PetalburgCity_EventScript_LavaridgeMigrant_Text_3
# 11 "data/maps/PetalburgCity_House3/scripts.pory"
	multichoice 25, 8, MULTI_CHARCADET_EVOLVE, 0
# 12 "data/maps/PetalburgCity_House3/scripts.pory"
	closemessage
# 13 "data/maps/PetalburgCity_House3/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_EventScript_LavaridgeMigrant_2
# 16 "data/maps/PetalburgCity_House3/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_EventScript_LavaridgeMigrant_3
PetalburgCity_EventScript_LavaridgeMigrant_1:
# 19 "data/maps/PetalburgCity_House3/scripts.pory"
	waitmessage
# 20 "data/maps/PetalburgCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_ARMOR
# 21 "data/maps/PetalburgCity_House3/scripts.pory"
	release
	end

PetalburgCity_EventScript_LavaridgeMigrant_2:
# 14 "data/maps/PetalburgCity_House3/scripts.pory"
	giveitem ITEM_AUSPICIOUS_ARMOR
	goto PetalburgCity_EventScript_LavaridgeMigrant_1

PetalburgCity_EventScript_LavaridgeMigrant_3:
# 17 "data/maps/PetalburgCity_House3/scripts.pory"
	giveitem ITEM_MALICIOUS_ARMOR
	goto PetalburgCity_EventScript_LavaridgeMigrant_1


PetalburgCity_EventScript_GaveArmor::
# 26 "data/maps/PetalburgCity_House3/scripts.pory"
	msgbox PetalburgCity_EventScript_GaveArmor_Text_0, MSGBOX_DEFAULT
# 27 "data/maps/PetalburgCity_House3/scripts.pory"
	waitmessage
# 28 "data/maps/PetalburgCity_House3/scripts.pory"
	closemessage
# 29 "data/maps/PetalburgCity_House3/scripts.pory"
	release
	end


PetalburgCity_EventScript_LavaridgeMigrant_Text_0:
# 7 "data/maps/PetalburgCity_House3/scripts.pory"
	.string "Hey there young lad, I just moved here\n"
	.string "from Lavaridge Town. I must say the\l"
	.string "differences between here and there are\l"
	.string "scorching.$"

PetalburgCity_EventScript_LavaridgeMigrant_Text_1:
# 8 "data/maps/PetalburgCity_House3/scripts.pory"
	.string "I am a collector of curiosities and\n"
	.string "artifacts from all over HOENN. I'm\l"
	.string "especially interested in . . . dark pasts,\l"
	.string "shall we say.$"

PetalburgCity_EventScript_LavaridgeMigrant_Text_2:
# 9 "data/maps/PetalburgCity_House3/scripts.pory"
	.string "Since you seem trustworthy, I'll give\n"
	.string "you the choice of one of my artifacts.$"

PetalburgCity_EventScript_LavaridgeMigrant_Text_3:
# 10 "data/maps/PetalburgCity_House3/scripts.pory"
	.string "Choose wisely.$"

PetalburgCity_EventScript_GaveArmor_Text_0:
# 26 "data/maps/PetalburgCity_House3/scripts.pory"
	.string "I heard that certain POKéMON react\n"
	.string "differently when in the presence of\l"
	.string "these mysterious artifacts.$"
