# 1 "data/maps/DewfordTown_House1/scripts.pory"

# 2 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_MapScripts::
# 3 "data/maps/DewfordTown_House1/scripts.pory"
	.byte 0
# 4 "data/maps/DewfordTown_House1/scripts.pory"

# 5 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_EventScript_Man::
# 6 "data/maps/DewfordTown_House1/scripts.pory"
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
# 7 "data/maps/DewfordTown_House1/scripts.pory"
	end
# 8 "data/maps/DewfordTown_House1/scripts.pory"

# 9 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_EventScript_Woman::
# 10 "data/maps/DewfordTown_House1/scripts.pory"
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
# 11 "data/maps/DewfordTown_House1/scripts.pory"
	end
# 12 "data/maps/DewfordTown_House1/scripts.pory"

# 13 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_EventScript_Zigzagoon::
# 14 "data/maps/DewfordTown_House1/scripts.pory"
	lock
# 15 "data/maps/DewfordTown_House1/scripts.pory"
	faceplayer
# 16 "data/maps/DewfordTown_House1/scripts.pory"
	waitse
# 17 "data/maps/DewfordTown_House1/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
# 18 "data/maps/DewfordTown_House1/scripts.pory"
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
# 19 "data/maps/DewfordTown_House1/scripts.pory"
	waitmoncry
# 20 "data/maps/DewfordTown_House1/scripts.pory"
	release
# 21 "data/maps/DewfordTown_House1/scripts.pory"
	end
# 22 "data/maps/DewfordTown_House1/scripts.pory"

# 23 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
# 24 "data/maps/DewfordTown_House1/scripts.pory"
	.string "There's a lot to be said for living on\n"
# 25 "data/maps/DewfordTown_House1/scripts.pory"
	.string "a small island like this in harmony with\l"
# 26 "data/maps/DewfordTown_House1/scripts.pory"
	.string "POKéMON and the family.$"
# 27 "data/maps/DewfordTown_House1/scripts.pory"

# 28 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
# 29 "data/maps/DewfordTown_House1/scripts.pory"
	.string "I left the major port of SLATEPORT\n"
# 30 "data/maps/DewfordTown_House1/scripts.pory"
	.string "CITY when I married my husband here.\p"
# 31 "data/maps/DewfordTown_House1/scripts.pory"
	.string "Life goes by slowly on this little\n"
# 32 "data/maps/DewfordTown_House1/scripts.pory"
	.string "island. But being surrounded by the\l"
# 33 "data/maps/DewfordTown_House1/scripts.pory"
	.string "beautiful sea--that's happiness, too.$"
# 34 "data/maps/DewfordTown_House1/scripts.pory"

# 35 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_Text_Zigzagoon:
# 36 "data/maps/DewfordTown_House1/scripts.pory"
	.string "ZIGZAGOON: Guguuh!$"
