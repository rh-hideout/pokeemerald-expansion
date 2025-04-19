# 1 "data/maps/Route112_CableCarStation/scripts.pory"

# 2 "data/maps/Route112_CableCarStation/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/Route112_CableCarStation/scripts.pory"

# 4 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_MapScripts::
# 5 "data/maps/Route112_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_CableCarStation_OnTransition
# 6 "data/maps/Route112_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route112_CableCarStation_OnFrame
# 7 "data/maps/Route112_CableCarStation/scripts.pory"
	.byte 0
# 8 "data/maps/Route112_CableCarStation/scripts.pory"

# 9 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_OnTransition:
# 10 "data/maps/Route112_CableCarStation/scripts.pory"
	setescapewarp MAP_ROUTE112, 28, 28
# 11 "data/maps/Route112_CableCarStation/scripts.pory"
	call_if_eq VAR_CABLE_CAR_STATION_STATE, 2, Route112_CableCarStation_EventScript_MoveAttendantAside
# 12 "data/maps/Route112_CableCarStation/scripts.pory"
	end
# 13 "data/maps/Route112_CableCarStation/scripts.pory"

# 14 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_EventScript_MoveAttendantAside::
# 15 "data/maps/Route112_CableCarStation/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 7, 4
# 16 "data/maps/Route112_CableCarStation/scripts.pory"
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_LEFT
# 17 "data/maps/Route112_CableCarStation/scripts.pory"
	return
# 18 "data/maps/Route112_CableCarStation/scripts.pory"

# 19 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_OnFrame:
# 20 "data/maps/Route112_CableCarStation/scripts.pory"
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 2, Route112_CableCarStation_EventScript_ExitCableCar
# 21 "data/maps/Route112_CableCarStation/scripts.pory"
	.2byte 0
# 22 "data/maps/Route112_CableCarStation/scripts.pory"

# 23 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_EventScript_ExitCableCar::
# 24 "data/maps/Route112_CableCarStation/scripts.pory"
	lockall
# 25 "data/maps/Route112_CableCarStation/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route112_CableCarStation_Movement_ExitCableCar
# 26 "data/maps/Route112_CableCarStation/scripts.pory"
	applymovement LOCALID_ATTENDANT, Route112_CableCarStation_Movement_FollowPlayerOutFromCableCar
# 27 "data/maps/Route112_CableCarStation/scripts.pory"
	waitmovement 0
# 28 "data/maps/Route112_CableCarStation/scripts.pory"
	setvar VAR_CABLE_CAR_STATION_STATE, 0
# 29 "data/maps/Route112_CableCarStation/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 6, 7
# 30 "data/maps/Route112_CableCarStation/scripts.pory"
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
# 31 "data/maps/Route112_CableCarStation/scripts.pory"
	releaseall
# 32 "data/maps/Route112_CableCarStation/scripts.pory"
	end
# 33 "data/maps/Route112_CableCarStation/scripts.pory"

# 34 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_EventScript_Attendant::
# 35 "data/maps/Route112_CableCarStation/scripts.pory"
	lock
# 36 "data/maps/Route112_CableCarStation/scripts.pory"
	faceplayer
# 37 "data/maps/Route112_CableCarStation/scripts.pory"
	msgbox Route112_CableCarStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
# 38 "data/maps/Route112_CableCarStation/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route112_CableCarStation_EventScript_RideCableCar
# 39 "data/maps/Route112_CableCarStation/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route112_CableCarStation_EventScript_DeclineRide
# 40 "data/maps/Route112_CableCarStation/scripts.pory"
	end
# 41 "data/maps/Route112_CableCarStation/scripts.pory"

# 42 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_EventScript_RideCableCar::
# 43 "data/maps/Route112_CableCarStation/scripts.pory"
	msgbox Route112_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
# 44 "data/maps/Route112_CableCarStation/scripts.pory"
	closemessage
# 45 "data/maps/Route112_CableCarStation/scripts.pory"
	applymovement LOCALID_ATTENDANT, Route112_CableCarStation_Movement_LeadPlayerToCableCar
# 46 "data/maps/Route112_CableCarStation/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route112_CableCarStation_Movement_BoardCableCar
# 47 "data/maps/Route112_CableCarStation/scripts.pory"
	waitmovement 0
# 48 "data/maps/Route112_CableCarStation/scripts.pory"
	setvar VAR_0x8004, FALSE  @ Going up
# 49 "data/maps/Route112_CableCarStation/scripts.pory"
	setvar VAR_CABLE_CAR_STATION_STATE, 1
# 50 "data/maps/Route112_CableCarStation/scripts.pory"
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
# 51 "data/maps/Route112_CableCarStation/scripts.pory"
	special CableCarWarp
# 52 "data/maps/Route112_CableCarStation/scripts.pory"
	special CableCar
# 53 "data/maps/Route112_CableCarStation/scripts.pory"
	waitstate
# 54 "data/maps/Route112_CableCarStation/scripts.pory"
	release
# 55 "data/maps/Route112_CableCarStation/scripts.pory"
	end
# 56 "data/maps/Route112_CableCarStation/scripts.pory"

# 57 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_EventScript_DeclineRide::
# 58 "data/maps/Route112_CableCarStation/scripts.pory"
	msgbox Route112_CableCarStation_Text_RideAnotherTime, MSGBOX_DEFAULT
# 59 "data/maps/Route112_CableCarStation/scripts.pory"
	release
# 60 "data/maps/Route112_CableCarStation/scripts.pory"
	end
# 61 "data/maps/Route112_CableCarStation/scripts.pory"

# 62 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Movement_LeadPlayerToCableCar:
# 63 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_up
# 64 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_up
# 65 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_right
# 66 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_in_place_faster_left
# 67 "data/maps/Route112_CableCarStation/scripts.pory"
	step_end
# 68 "data/maps/Route112_CableCarStation/scripts.pory"

# 69 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Movement_FollowPlayerOutFromCableCar:
# 70 "data/maps/Route112_CableCarStation/scripts.pory"
	delay_16
# 71 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_left
# 72 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_down
# 73 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_down
# 74 "data/maps/Route112_CableCarStation/scripts.pory"
	step_end
# 75 "data/maps/Route112_CableCarStation/scripts.pory"

# 76 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Movement_BoardCableCar:
# 77 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_up
# 78 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_up
# 79 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_up
# 80 "data/maps/Route112_CableCarStation/scripts.pory"
	delay_16
# 81 "data/maps/Route112_CableCarStation/scripts.pory"
	step_end
# 82 "data/maps/Route112_CableCarStation/scripts.pory"

# 83 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Movement_ExitCableCar:
# 84 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_down
# 85 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_down
# 86 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_down
# 87 "data/maps/Route112_CableCarStation/scripts.pory"
	delay_16
# 88 "data/maps/Route112_CableCarStation/scripts.pory"
	step_end
# 89 "data/maps/Route112_CableCarStation/scripts.pory"

# 90 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Text_CableCarReadyGetOn:
# 91 "data/maps/Route112_CableCarStation/scripts.pory"
	.string "The CABLE CAR is ready to go up.\n"
# 92 "data/maps/Route112_CableCarStation/scripts.pory"
	.string "Would you like to be on it?$"
# 93 "data/maps/Route112_CableCarStation/scripts.pory"

# 94 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Text_StepThisWay:
# 95 "data/maps/Route112_CableCarStation/scripts.pory"
	.string "Please step this way.$"
# 96 "data/maps/Route112_CableCarStation/scripts.pory"

# 97 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Text_RideAnotherTime:
# 98 "data/maps/Route112_CableCarStation/scripts.pory"
	.string "Please ride with us another time.$"
