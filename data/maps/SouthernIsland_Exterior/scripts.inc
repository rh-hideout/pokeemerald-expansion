# 1 "data/maps/SouthernIsland_Exterior/scripts.pory"

# 2 "data/maps/SouthernIsland_Exterior/scripts.pory"
.set LOCALID_SAILOR, 1
# 3 "data/maps/SouthernIsland_Exterior/scripts.pory"
.set LOCALID_SS_TIDAL, 2
# 4 "data/maps/SouthernIsland_Exterior/scripts.pory"

# 5 "data/maps/SouthernIsland_Exterior/scripts.pory"
SouthernIsland_Exterior_MapScripts::
# 6 "data/maps/SouthernIsland_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Exterior_OnTransition
# 7 "data/maps/SouthernIsland_Exterior/scripts.pory"
	.byte 0
# 8 "data/maps/SouthernIsland_Exterior/scripts.pory"

# 9 "data/maps/SouthernIsland_Exterior/scripts.pory"
SouthernIsland_Exterior_OnTransition:
# 10 "data/maps/SouthernIsland_Exterior/scripts.pory"
	setflag FLAG_LANDMARK_SOUTHERN_ISLAND
# 11 "data/maps/SouthernIsland_Exterior/scripts.pory"
	end
# 12 "data/maps/SouthernIsland_Exterior/scripts.pory"

# 13 "data/maps/SouthernIsland_Exterior/scripts.pory"
SouthernIsland_Exterior_EventScript_Sailor::
# 14 "data/maps/SouthernIsland_Exterior/scripts.pory"
	lock
# 15 "data/maps/SouthernIsland_Exterior/scripts.pory"
	faceplayer
# 16 "data/maps/SouthernIsland_Exterior/scripts.pory"
	msgbox EventTicket_Text_SouthernIslandSailBack, MSGBOX_YESNO
# 17 "data/maps/SouthernIsland_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SouthernIsland_Exterior_EventScript_AsYouLike
# 18 "data/maps/SouthernIsland_Exterior/scripts.pory"
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
# 19 "data/maps/SouthernIsland_Exterior/scripts.pory"
	closemessage
# 20 "data/maps/SouthernIsland_Exterior/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 21 "data/maps/SouthernIsland_Exterior/scripts.pory"
	waitmovement 0
# 22 "data/maps/SouthernIsland_Exterior/scripts.pory"
	delay 30
# 23 "data/maps/SouthernIsland_Exterior/scripts.pory"
	hideobjectat LOCALID_SAILOR, MAP_SOUTHERN_ISLAND_EXTERIOR
# 24 "data/maps/SouthernIsland_Exterior/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 25 "data/maps/SouthernIsland_Exterior/scripts.pory"
	call Common_EventScript_FerryDepartIsland
# 26 "data/maps/SouthernIsland_Exterior/scripts.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
# 27 "data/maps/SouthernIsland_Exterior/scripts.pory"
	waitstate
# 28 "data/maps/SouthernIsland_Exterior/scripts.pory"
	release
# 29 "data/maps/SouthernIsland_Exterior/scripts.pory"
	end
# 30 "data/maps/SouthernIsland_Exterior/scripts.pory"

# 31 "data/maps/SouthernIsland_Exterior/scripts.pory"
SouthernIsland_Exterior_EventScript_AsYouLike::
# 32 "data/maps/SouthernIsland_Exterior/scripts.pory"
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
# 33 "data/maps/SouthernIsland_Exterior/scripts.pory"
	release
# 34 "data/maps/SouthernIsland_Exterior/scripts.pory"
	end
# 35 "data/maps/SouthernIsland_Exterior/scripts.pory"

# 36 "data/maps/SouthernIsland_Exterior/scripts.pory"
Ferry_EventScript_DepartIslandSouth::
# 37 "data/maps/SouthernIsland_Exterior/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Ferry_Movement_DepartIslandBoardSouth
# 38 "data/maps/SouthernIsland_Exterior/scripts.pory"
	waitmovement 0
# 39 "data/maps/SouthernIsland_Exterior/scripts.pory"
	return
# 40 "data/maps/SouthernIsland_Exterior/scripts.pory"

# 41 "data/maps/SouthernIsland_Exterior/scripts.pory"
Ferry_EventScript_DepartIslandWest::
# 42 "data/maps/SouthernIsland_Exterior/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Ferry_Movement_DepartIslandBoardWest
# 43 "data/maps/SouthernIsland_Exterior/scripts.pory"
	waitmovement 0
# 44 "data/maps/SouthernIsland_Exterior/scripts.pory"
	return
# 45 "data/maps/SouthernIsland_Exterior/scripts.pory"

# 46 "data/maps/SouthernIsland_Exterior/scripts.pory"
Ferry_Movement_DepartIslandBoardSouth:
# 47 "data/maps/SouthernIsland_Exterior/scripts.pory"
	walk_down
# 48 "data/maps/SouthernIsland_Exterior/scripts.pory"
	step_end
# 49 "data/maps/SouthernIsland_Exterior/scripts.pory"

# 50 "data/maps/SouthernIsland_Exterior/scripts.pory"
Ferry_Movement_DepartIslandBoardWest:
# 51 "data/maps/SouthernIsland_Exterior/scripts.pory"
	walk_left
# 52 "data/maps/SouthernIsland_Exterior/scripts.pory"
	walk_in_place_faster_down
# 53 "data/maps/SouthernIsland_Exterior/scripts.pory"
	step_end
# 54 "data/maps/SouthernIsland_Exterior/scripts.pory"

# 55 "data/maps/SouthernIsland_Exterior/scripts.pory"
SouthernIsland_Exterior_EventScript_Sign::
# 56 "data/maps/SouthernIsland_Exterior/scripts.pory"
	msgbox SouthernIsland_Exterior_Text_Sign, MSGBOX_SIGN
# 57 "data/maps/SouthernIsland_Exterior/scripts.pory"
	end
