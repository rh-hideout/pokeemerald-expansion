# 1 "data/maps/SootopolisCity_House4/scripts.pory"

# 2 "data/maps/SootopolisCity_House4/scripts.pory"
SootopolisCity_House4_MapScripts::
# 3 "data/maps/SootopolisCity_House4/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_House4/scripts.pory"

# 5 "data/maps/SootopolisCity_House4/scripts.pory"
SootopolisCity_House4_EventScript_Man::
# 6 "data/maps/SootopolisCity_House4/scripts.pory"
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
# 7 "data/maps/SootopolisCity_House4/scripts.pory"
	end
# 8 "data/maps/SootopolisCity_House4/scripts.pory"

# 9 "data/maps/SootopolisCity_House4/scripts.pory"
SootopolisCity_House4_EventScript_Woman::
# 10 "data/maps/SootopolisCity_House4/scripts.pory"
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
# 11 "data/maps/SootopolisCity_House4/scripts.pory"
	end
# 12 "data/maps/SootopolisCity_House4/scripts.pory"

# 13 "data/maps/SootopolisCity_House4/scripts.pory"
SootopolisCity_House4_EventScript_Azumarill::
# 14 "data/maps/SootopolisCity_House4/scripts.pory"
	lock
# 15 "data/maps/SootopolisCity_House4/scripts.pory"
	faceplayer
# 16 "data/maps/SootopolisCity_House4/scripts.pory"
	waitse
# 17 "data/maps/SootopolisCity_House4/scripts.pory"
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
# 18 "data/maps/SootopolisCity_House4/scripts.pory"
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
# 19 "data/maps/SootopolisCity_House4/scripts.pory"
	waitmoncry
# 20 "data/maps/SootopolisCity_House4/scripts.pory"
	release
# 21 "data/maps/SootopolisCity_House4/scripts.pory"
	end
# 22 "data/maps/SootopolisCity_House4/scripts.pory"

# 23 "data/maps/SootopolisCity_House4/scripts.pory"
SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
# 24 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "Listen up, and I'll tell you something\n"
# 25 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "good.\p"
# 26 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "There's supposed to be an ancient\n"
# 27 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "ruin in the sea around here.\p"
# 28 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "There could be treasures just waiting\n"
# 29 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "to be discovered down there.$"
# 30 "data/maps/SootopolisCity_House4/scripts.pory"

# 31 "data/maps/SootopolisCity_House4/scripts.pory"
SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
# 32 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "Ancient treasures…\p"
# 33 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "It would be nice if they existed, but\n"
# 34 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "even if they didn't, it would be so\l"
# 35 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "beautiful to take an underwater\l"
# 36 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "stroll with my POKéMON.$"
# 37 "data/maps/SootopolisCity_House4/scripts.pory"

# 38 "data/maps/SootopolisCity_House4/scripts.pory"
SootopolisCity_House4_Text_Azumarill:
# 39 "data/maps/SootopolisCity_House4/scripts.pory"
	.string "AZUMARILL: Marurii.$"
