# 1 "data/maps/TrainerHill_Elevator/scripts.pory"

# 2 "data/maps/TrainerHill_Elevator/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/TrainerHill_Elevator/scripts.pory"

# 4 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_MapScripts::
# 5 "data/maps/TrainerHill_Elevator/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Elevator_OnFrame
# 6 "data/maps/TrainerHill_Elevator/scripts.pory"
	.byte 0
# 7 "data/maps/TrainerHill_Elevator/scripts.pory"

# 8 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_OnFrame:
# 9 "data/maps/TrainerHill_Elevator/scripts.pory"
	map_script_2 VAR_TEMP_4, 0, TrainerHill_Elevator_EventScript_EnterElevator
# 10 "data/maps/TrainerHill_Elevator/scripts.pory"
	.2byte 0
# 11 "data/maps/TrainerHill_Elevator/scripts.pory"

# 12 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_Attendant::
# 13 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 14 "data/maps/TrainerHill_Elevator/scripts.pory"

# 15 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_ExitToRoof::
# 16 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerExitElevatorToRoof
# 17 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 18 "data/maps/TrainerHill_Elevator/scripts.pory"
	releaseall
# 19 "data/maps/TrainerHill_Elevator/scripts.pory"
	warp MAP_TRAINER_HILL_ROOF, 15, 5
# 20 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitstate
# 21 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 22 "data/maps/TrainerHill_Elevator/scripts.pory"

# 23 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_EnterElevator::
# 24 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerApproachAttendant
# 25 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 26 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement LOCALID_ATTENDANT, TrainerHill_Elevator_Movement_AttendantFacePlayer
# 27 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 28 "data/maps/TrainerHill_Elevator/scripts.pory"
	lockall
# 29 "data/maps/TrainerHill_Elevator/scripts.pory"
	msgbox TrainerHill_Elevator_Text_ReturnToReception, MSGBOX_YESNO
# 30 "data/maps/TrainerHill_Elevator/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Elevator_EventScript_ExitToRoof
# 31 "data/maps/TrainerHill_Elevator/scripts.pory"
	releaseall
# 32 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement LOCALID_ATTENDANT, TrainerHill_Elevator_Movement_AttendantFaceDown
# 33 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 34 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerMoveToCenterOfElevator
# 35 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 36 "data/maps/TrainerHill_Elevator/scripts.pory"
	call TrainerHill_Elevator_EventScript_MoveElevator
# 37 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay 25
# 38 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerExitElevator
# 39 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 40 "data/maps/TrainerHill_Elevator/scripts.pory"
	warp MAP_TRAINER_HILL_ENTRANCE, 17, 8
# 41 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitstate
# 42 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 43 "data/maps/TrainerHill_Elevator/scripts.pory"

# 44 "data/maps/TrainerHill_Elevator/scripts.pory"
@ Unused
# 45 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_ExitFloorSelect::
# 46 "data/maps/TrainerHill_Elevator/scripts.pory"
	goto TrainerHill_Elevator_EventScript_CloseFloorSelect
# 47 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 48 "data/maps/TrainerHill_Elevator/scripts.pory"

# 49 "data/maps/TrainerHill_Elevator/scripts.pory"
@ Functionally unused
# 50 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_CloseFloorSelect::
# 51 "data/maps/TrainerHill_Elevator/scripts.pory"
	special CloseDeptStoreElevatorWindow
# 52 "data/maps/TrainerHill_Elevator/scripts.pory"
	releaseall
# 53 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 54 "data/maps/TrainerHill_Elevator/scripts.pory"

# 55 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_MoveElevator::
# 56 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitse
# 57 "data/maps/TrainerHill_Elevator/scripts.pory"
	special MoveElevator
# 58 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitstate
# 59 "data/maps/TrainerHill_Elevator/scripts.pory"
	return
# 60 "data/maps/TrainerHill_Elevator/scripts.pory"

# 61 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerMoveToCenterOfElevator:
# 62 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_up
# 63 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_up
# 64 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_right
# 65 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_down
# 66 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 67 "data/maps/TrainerHill_Elevator/scripts.pory"

# 68 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerApproachAttendant:
# 69 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay_16
# 70 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_left
# 71 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 72 "data/maps/TrainerHill_Elevator/scripts.pory"

# 73 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerExitElevator:
# 74 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay_16
# 75 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_down
# 76 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_down
# 77 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 78 "data/maps/TrainerHill_Elevator/scripts.pory"

# 79 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerExitElevatorToRoof:
# 80 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_down
# 81 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay_16
# 82 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 83 "data/maps/TrainerHill_Elevator/scripts.pory"

# 84 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_AttendantFacePlayer:
# 85 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_right
# 86 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 87 "data/maps/TrainerHill_Elevator/scripts.pory"

# 88 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_AttendantFaceDown:
# 89 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_down
# 90 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
