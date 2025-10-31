# 1 "data/maps/LavaridgeTown_House/scripts.pory"

# 2 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_MapScripts::
# 3 "data/maps/LavaridgeTown_House/scripts.pory"
	.byte 0
# 4 "data/maps/LavaridgeTown_House/scripts.pory"

# 5 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_EventScript_OldMan::
# 6 "data/maps/LavaridgeTown_House/scripts.pory"
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
# 7 "data/maps/LavaridgeTown_House/scripts.pory"
	end
# 8 "data/maps/LavaridgeTown_House/scripts.pory"

# 9 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_EventScript_Zigzagoon::
# 10 "data/maps/LavaridgeTown_House/scripts.pory"
	lock
# 11 "data/maps/LavaridgeTown_House/scripts.pory"
	faceplayer
# 12 "data/maps/LavaridgeTown_House/scripts.pory"
	waitse
# 13 "data/maps/LavaridgeTown_House/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
# 14 "data/maps/LavaridgeTown_House/scripts.pory"
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
# 15 "data/maps/LavaridgeTown_House/scripts.pory"
	waitmoncry
# 16 "data/maps/LavaridgeTown_House/scripts.pory"
	release
# 17 "data/maps/LavaridgeTown_House/scripts.pory"
	end
# 18 "data/maps/LavaridgeTown_House/scripts.pory"

# 19 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
# 20 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "My wife's warming an EGG in the hot\n"
# 21 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "springs. This is what she told me.\p"
# 22 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "She left two POKéMON with the DAY CARE.\n"
# 23 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "And they discovered that EGG!$"
# 24 "data/maps/LavaridgeTown_House/scripts.pory"

# 25 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_Text_Zigzagoon:
# 26 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "ZIGZAGOON: Pshoo!$"
