# 1 "data/maps/BeachCave_1F/scripts.pory"

# 2 "data/maps/BeachCave_1F/scripts.pory"
BeachCave_1F_MapScripts::
# 3 "data/maps/BeachCave_1F/scripts.pory"
	.byte 0

BeachCave_1F_EventScript_GetItem::
# 8 "data/maps/BeachCave_1F/scripts.pory"
	lock
# 9 "data/maps/BeachCave_1F/scripts.pory"
	removeobject 2
# 10 "data/maps/BeachCave_1F/scripts.pory"
	giveitem ITEM_SLOWBRONITE, 1
# 11 "data/maps/BeachCave_1F/scripts.pory"
	setflag FLAG_BEACH_CAVE_ITEM
# 12 "data/maps/BeachCave_1F/scripts.pory"
	release
	end


BeachCave_1F_EventScript_OldMan::
# 18 "data/maps/BeachCave_1F/scripts.pory"
	faceplayer
# 19 "data/maps/BeachCave_1F/scripts.pory"
	lock
# 20 "data/maps/BeachCave_1F/scripts.pory"
	msgbox BeachCave_1F_EventScript_OldMan_Text_0, MSGBOX_DEFAULT
# 22 "data/maps/BeachCave_1F/scripts.pory"
	waitmessage
# 23 "data/maps/BeachCave_1F/scripts.pory"
	turnobject 3, DIR_SOUTH
# 24 "data/maps/BeachCave_1F/scripts.pory"
	release
	end


BeachCave_1F_EventScript_OldMan_Text_0:
# 20 "data/maps/BeachCave_1F/scripts.pory"
	.string "Hello there! This cave has recently\n"
	.string "opened up due to the instability of the\l"
	.string "region. I have lived here for many\l"
	.string "years, and have never seen such\l"
	.string "POKéMON on the surface. Be careful.$"
