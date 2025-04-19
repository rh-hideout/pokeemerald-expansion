# 1 "data/maps/Route119_House/scripts.pory"

# 2 "data/maps/Route119_House/scripts.pory"
Route119_House_MapScripts::
# 3 "data/maps/Route119_House/scripts.pory"
	.byte 0
# 4 "data/maps/Route119_House/scripts.pory"

# 5 "data/maps/Route119_House/scripts.pory"
Route119_House_EventScript_Woman::
# 6 "data/maps/Route119_House/scripts.pory"
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
# 7 "data/maps/Route119_House/scripts.pory"
	end
# 8 "data/maps/Route119_House/scripts.pory"

# 9 "data/maps/Route119_House/scripts.pory"
Route119_House_EventScript_Wingull::
# 10 "data/maps/Route119_House/scripts.pory"
	lock
# 11 "data/maps/Route119_House/scripts.pory"
	faceplayer
# 12 "data/maps/Route119_House/scripts.pory"
	waitse
# 13 "data/maps/Route119_House/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 14 "data/maps/Route119_House/scripts.pory"
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
# 15 "data/maps/Route119_House/scripts.pory"
	waitmoncry
# 16 "data/maps/Route119_House/scripts.pory"
	release
# 17 "data/maps/Route119_House/scripts.pory"
	end
# 18 "data/maps/Route119_House/scripts.pory"

# 19 "data/maps/Route119_House/scripts.pory"
Route119_House_Text_RumorAboutCaveOfOrigin:
# 20 "data/maps/Route119_House/scripts.pory"
	.string "I heard about a cave called the CAVE\n"
# 21 "data/maps/Route119_House/scripts.pory"
	.string "OF ORIGIN.\p"
# 22 "data/maps/Route119_House/scripts.pory"
	.string "People rumor that the spirits of\n"
# 23 "data/maps/Route119_House/scripts.pory"
	.string "POKéMON are revived there. Could\l"
# 24 "data/maps/Route119_House/scripts.pory"
	.string "something like that really happen?$"
# 25 "data/maps/Route119_House/scripts.pory"

# 26 "data/maps/Route119_House/scripts.pory"
Route119_House_Text_Wingull:
# 27 "data/maps/Route119_House/scripts.pory"
	.string "WINGULL: Pihyoh!$"
