# 1 "data//maps/BirthIsland_Harbor/scripts.pory"

# 2 "data//maps/BirthIsland_Harbor/scripts.pory"
.set LOCALID_SAILOR, 1
# 3 "data//maps/BirthIsland_Harbor/scripts.pory"
.set LOCALID_SS_TIDAL, 2
# 4 "data//maps/BirthIsland_Harbor/scripts.pory"

# 5 "data//maps/BirthIsland_Harbor/scripts.pory"
BirthIsland_Harbor_MapScripts::
# 6 "data//maps/BirthIsland_Harbor/scripts.pory"
	.byte 0
# 7 "data//maps/BirthIsland_Harbor/scripts.pory"

# 8 "data//maps/BirthIsland_Harbor/scripts.pory"
BirthIsland_Harbor_EventScript_Sailor::
# 9 "data//maps/BirthIsland_Harbor/scripts.pory"
	lock
# 10 "data//maps/BirthIsland_Harbor/scripts.pory"
	faceplayer
# 11 "data//maps/BirthIsland_Harbor/scripts.pory"
	msgbox BirthIsland_Harbor_Text_SailorReturn, MSGBOX_YESNO
# 12 "data//maps/BirthIsland_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BirthIsland_Harbor_EventScript_AsYouLike
# 13 "data//maps/BirthIsland_Harbor/scripts.pory"
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
# 14 "data//maps/BirthIsland_Harbor/scripts.pory"
	closemessage
# 15 "data//maps/BirthIsland_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 16 "data//maps/BirthIsland_Harbor/scripts.pory"
	waitmovement 0
# 17 "data//maps/BirthIsland_Harbor/scripts.pory"
	delay 30
# 18 "data//maps/BirthIsland_Harbor/scripts.pory"
	hideobjectat LOCALID_SAILOR, MAP_BIRTH_ISLAND_HARBOR
# 19 "data//maps/BirthIsland_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 20 "data//maps/BirthIsland_Harbor/scripts.pory"
	call Common_EventScript_FerryDepartIsland
# 21 "data//maps/BirthIsland_Harbor/scripts.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
# 22 "data//maps/BirthIsland_Harbor/scripts.pory"
	waitstate
# 23 "data//maps/BirthIsland_Harbor/scripts.pory"
	release
# 24 "data//maps/BirthIsland_Harbor/scripts.pory"
	end
# 25 "data//maps/BirthIsland_Harbor/scripts.pory"

# 26 "data//maps/BirthIsland_Harbor/scripts.pory"
BirthIsland_Harbor_EventScript_AsYouLike::
# 27 "data//maps/BirthIsland_Harbor/scripts.pory"
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
# 28 "data//maps/BirthIsland_Harbor/scripts.pory"
	release
# 29 "data//maps/BirthIsland_Harbor/scripts.pory"
	end
