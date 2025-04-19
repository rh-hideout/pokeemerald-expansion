# 1 "data/maps/NewMauville_Entrance/scripts.pory"

# 2 "data/maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_MapScripts::
# 3 "data/maps/NewMauville_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_OnLoad
# 4 "data/maps/NewMauville_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
# 5 "data/maps/NewMauville_Entrance/scripts.pory"
	.byte 0
# 6 "data/maps/NewMauville_Entrance/scripts.pory"

# 7 "data/maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_OnLoad:
# 8 "data/maps/NewMauville_Entrance/scripts.pory"
	call_if_eq VAR_NEW_MAUVILLE_STATE, 0, NewMauville_Entrance_EventScript_CloseDoor
# 9 "data/maps/NewMauville_Entrance/scripts.pory"
	end
# 10 "data/maps/NewMauville_Entrance/scripts.pory"

# 11 "data/maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_EventScript_CloseDoor::
# 12 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile0, TRUE
# 13 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile1, TRUE
# 14 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile2, TRUE
# 15 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile3, TRUE
# 16 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile4, TRUE
# 17 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile5, TRUE
# 18 "data/maps/NewMauville_Entrance/scripts.pory"
	return
# 19 "data/maps/NewMauville_Entrance/scripts.pory"

# 20 "data/maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_OnTransition:
# 21 "data/maps/NewMauville_Entrance/scripts.pory"
	setflag FLAG_LANDMARK_NEW_MAUVILLE
# 22 "data/maps/NewMauville_Entrance/scripts.pory"
	end
# 23 "data/maps/NewMauville_Entrance/scripts.pory"

# 24 "data/maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_EventScript_Door::
# 25 "data/maps/NewMauville_Entrance/scripts.pory"
	lockall
# 26 "data/maps/NewMauville_Entrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 27 "data/maps/NewMauville_Entrance/scripts.pory"
	waitmovement 0
# 28 "data/maps/NewMauville_Entrance/scripts.pory"
	msgbox NewMauville_Entrance_Text_DoorIsLocked, MSGBOX_DEFAULT
# 29 "data/maps/NewMauville_Entrance/scripts.pory"
	checkitem ITEM_BASEMENT_KEY
# 30 "data/maps/NewMauville_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, NewMauville_Entrance_EventScript_DontOpenDoor
# 31 "data/maps/NewMauville_Entrance/scripts.pory"
	msgbox NewMauville_Entrance_Text_UseBasementKey, MSGBOX_YESNO
# 32 "data/maps/NewMauville_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewMauville_Entrance_EventScript_DontOpenDoor
# 33 "data/maps/NewMauville_Entrance/scripts.pory"
	msgbox NewMauville_Entrance_Text_UsedBasementKey, MSGBOX_DEFAULT
# 34 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile0, FALSE
# 35 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1, FALSE
# 36 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile2, FALSE
# 37 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile3, TRUE
# 38 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4, FALSE
# 39 "data/maps/NewMauville_Entrance/scripts.pory"
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile5, TRUE
# 40 "data/maps/NewMauville_Entrance/scripts.pory"
	special DrawWholeMapView
# 41 "data/maps/NewMauville_Entrance/scripts.pory"
	playse SE_BANG
# 42 "data/maps/NewMauville_Entrance/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 1
# 43 "data/maps/NewMauville_Entrance/scripts.pory"
	releaseall
# 44 "data/maps/NewMauville_Entrance/scripts.pory"
	end
# 45 "data/maps/NewMauville_Entrance/scripts.pory"

# 46 "data/maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_EventScript_DontOpenDoor::
# 47 "data/maps/NewMauville_Entrance/scripts.pory"
	releaseall
# 48 "data/maps/NewMauville_Entrance/scripts.pory"
	end
# 49 "data/maps/NewMauville_Entrance/scripts.pory"

# 50 "data/maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_Text_DoorIsLocked:
# 51 "data/maps/NewMauville_Entrance/scripts.pory"
	.string "The door is locked.$"
# 52 "data/maps/NewMauville_Entrance/scripts.pory"

# 53 "data/maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_Text_UseBasementKey:
# 54 "data/maps/NewMauville_Entrance/scripts.pory"
	.string "Use the BASEMENT KEY?$"
# 55 "data/maps/NewMauville_Entrance/scripts.pory"

# 56 "data/maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_Text_UsedBasementKey:
# 57 "data/maps/NewMauville_Entrance/scripts.pory"
	.string "{PLAYER} used the BASEMENT KEY.\p"
# 58 "data/maps/NewMauville_Entrance/scripts.pory"
	.string "The door opened!$"
