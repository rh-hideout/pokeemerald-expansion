# 1 "data/maps/PacifidlogTown_House5/scripts.pory"

# 2 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_MapScripts::
# 3 "data/maps/PacifidlogTown_House5/scripts.pory"
	.byte 0
# 4 "data/maps/PacifidlogTown_House5/scripts.pory"

# 5 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_EventScript_MirageIslandWatcher::
# 6 "data/maps/PacifidlogTown_House5/scripts.pory"
	lock
# 7 "data/maps/PacifidlogTown_House5/scripts.pory"
	faceplayer
# 8 "data/maps/PacifidlogTown_House5/scripts.pory"
	specialvar VAR_RESULT, IsMirageIslandPresent
# 9 "data/maps/PacifidlogTown_House5/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
# 10 "data/maps/PacifidlogTown_House5/scripts.pory"
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
# 11 "data/maps/PacifidlogTown_House5/scripts.pory"
	release
# 12 "data/maps/PacifidlogTown_House5/scripts.pory"
	end
# 13 "data/maps/PacifidlogTown_House5/scripts.pory"

# 14 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_EventScript_MirageIslandPresent::
# 15 "data/maps/PacifidlogTown_House5/scripts.pory"
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
# 16 "data/maps/PacifidlogTown_House5/scripts.pory"
	release
# 17 "data/maps/PacifidlogTown_House5/scripts.pory"
	end
# 18 "data/maps/PacifidlogTown_House5/scripts.pory"

# 19 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_EventScript_Gentleman::
# 20 "data/maps/PacifidlogTown_House5/scripts.pory"
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
# 21 "data/maps/PacifidlogTown_House5/scripts.pory"
	end
# 22 "data/maps/PacifidlogTown_House5/scripts.pory"

# 23 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
# 24 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "I can't see MIRAGE ISLAND today…$"
# 25 "data/maps/PacifidlogTown_House5/scripts.pory"

# 26 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
# 27 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "Oh! Oh my!\n"
# 28 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "I can see MIRAGE ISLAND today!$"
# 29 "data/maps/PacifidlogTown_House5/scripts.pory"

# 30 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
# 31 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "MIRAGE ISLAND…\p"
# 32 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "It must become visible and invisible\n"
# 33 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "depending on the weather conditions\l"
# 34 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "that make mirages appear.\p"
# 35 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "Or is it really appearing and\n"
# 36 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "disappearing?$"
