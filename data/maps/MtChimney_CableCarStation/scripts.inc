# 1 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 2 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_MapScripts::
# 3 "data/maps/MtChimney_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_CableCarStation_OnTransition
# 4 "data/maps/MtChimney_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtChimney_CableCarStation_OnFrame
# 5 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.byte 0
# 6 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 7 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_OnTransition:
# 8 "data/maps/MtChimney_CableCarStation/scripts.pory"
	call_if_eq VAR_CABLE_CAR_STATION_STATE, 1, MtChimney_CableCarStation_EventScript_MoveAttendantAside
# 9 "data/maps/MtChimney_CableCarStation/scripts.pory"
	end
# 10 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 11 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_MoveAttendantAside::
# 12 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setobjectxyperm LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, 5, 4
# 13 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setobjectmovementtype LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, MOVEMENT_TYPE_FACE_RIGHT
# 14 "data/maps/MtChimney_CableCarStation/scripts.pory"
	return
# 15 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 16 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_OnFrame:
# 17 "data/maps/MtChimney_CableCarStation/scripts.pory"
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 1, MtChimney_CableCarStation_EventScript_ExitCableCar
# 18 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.2byte 0
# 19 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 20 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_ExitCableCar::
# 21 "data/maps/MtChimney_CableCarStation/scripts.pory"
	lockall
# 22 "data/maps/MtChimney_CableCarStation/scripts.pory"
	applymovement LOCALID_PLAYER, MtChimney_CableCarStation_Movement_ExitCableCar
# 23 "data/maps/MtChimney_CableCarStation/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, MtChimney_CableCarStation_Movement_FollowPlayerOutFromCableCar
# 24 "data/maps/MtChimney_CableCarStation/scripts.pory"
	waitmovement 0
# 25 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setvar VAR_CABLE_CAR_STATION_STATE, 0
# 26 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setobjectxyperm LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, 6, 7
# 27 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setobjectmovementtype LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
# 28 "data/maps/MtChimney_CableCarStation/scripts.pory"
	releaseall
# 29 "data/maps/MtChimney_CableCarStation/scripts.pory"
	end
# 30 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 31 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_Attendant::
# 32 "data/maps/MtChimney_CableCarStation/scripts.pory"
	lock
# 33 "data/maps/MtChimney_CableCarStation/scripts.pory"
	faceplayer
# 34 "data/maps/MtChimney_CableCarStation/scripts.pory"
	msgbox MtChimney_CableCarStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
# 35 "data/maps/MtChimney_CableCarStation/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MtChimney_CableCarStation_EventScript_RideCableCar
# 36 "data/maps/MtChimney_CableCarStation/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_CableCarStation_EventScript_DeclineRide
# 37 "data/maps/MtChimney_CableCarStation/scripts.pory"
	end
# 38 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 39 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_RideCableCar::
# 40 "data/maps/MtChimney_CableCarStation/scripts.pory"
	msgbox MtChimney_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
# 41 "data/maps/MtChimney_CableCarStation/scripts.pory"
	closemessage
# 42 "data/maps/MtChimney_CableCarStation/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, MtChimney_CableCarStation_Movement_LeadPlayerToCableCar
# 43 "data/maps/MtChimney_CableCarStation/scripts.pory"
	applymovement LOCALID_PLAYER, MtChimney_CableCarStation_Movement_BoardCableCar
# 44 "data/maps/MtChimney_CableCarStation/scripts.pory"
	waitmovement 0
# 45 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setvar VAR_0x8004, TRUE  @ Going down
# 46 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setvar VAR_CABLE_CAR_STATION_STATE, 2
# 47 "data/maps/MtChimney_CableCarStation/scripts.pory"
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
# 48 "data/maps/MtChimney_CableCarStation/scripts.pory"
	special CableCarWarp
# 49 "data/maps/MtChimney_CableCarStation/scripts.pory"
	special CableCar
# 50 "data/maps/MtChimney_CableCarStation/scripts.pory"
	waitstate
# 51 "data/maps/MtChimney_CableCarStation/scripts.pory"
	release
# 52 "data/maps/MtChimney_CableCarStation/scripts.pory"
	end
# 53 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 54 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_DeclineRide::
# 55 "data/maps/MtChimney_CableCarStation/scripts.pory"
	msgbox MtChimney_CableCarStation_Text_RideAnotherTime, MSGBOX_DEFAULT
# 56 "data/maps/MtChimney_CableCarStation/scripts.pory"
	release
# 57 "data/maps/MtChimney_CableCarStation/scripts.pory"
	end
# 58 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 59 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_LeadPlayerToCableCar:
# 60 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 61 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 62 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_left
# 63 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_in_place_faster_right
# 64 "data/maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 65 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 66 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_FollowPlayerOutFromCableCar:
# 67 "data/maps/MtChimney_CableCarStation/scripts.pory"
	delay_16
# 68 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_right
# 69 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 70 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 71 "data/maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 72 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 73 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_BoardCableCar:
# 74 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 75 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 76 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 77 "data/maps/MtChimney_CableCarStation/scripts.pory"
	delay_16
# 78 "data/maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 79 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 80 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_ExitCableCar:
# 81 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 82 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 83 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 84 "data/maps/MtChimney_CableCarStation/scripts.pory"
	delay_16
# 85 "data/maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 86 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 87 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Text_CableCarReadyGetOn:
# 88 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.string "The CABLE CAR is ready to go down.\n"
# 89 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.string "Would you like to be on it?$"
# 90 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 91 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Text_StepThisWay:
# 92 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.string "Please step this way.$"
# 93 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 94 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Text_RideAnotherTime:
# 95 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.string "Please ride with us another time.$"
