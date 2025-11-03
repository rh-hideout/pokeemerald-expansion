# 1 "data/maps/TrainerHill_Elevator/scripts.pory"

# 2 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_MapScripts::
# 3 "data/maps/TrainerHill_Elevator/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Elevator_OnFrame
# 4 "data/maps/TrainerHill_Elevator/scripts.pory"
	.byte 0
# 5 "data/maps/TrainerHill_Elevator/scripts.pory"

# 6 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_OnFrame:
# 7 "data/maps/TrainerHill_Elevator/scripts.pory"
	map_script_2 VAR_TEMP_4, 0, TrainerHill_Elevator_EventScript_EnterElevator
# 8 "data/maps/TrainerHill_Elevator/scripts.pory"
	.2byte 0
# 9 "data/maps/TrainerHill_Elevator/scripts.pory"

# 10 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_Attendant::
# 11 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 12 "data/maps/TrainerHill_Elevator/scripts.pory"

# 13 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_ExitToRoof::
# 14 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Elevator_Movement_PlayerExitElevatorToRoof
# 15 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 16 "data/maps/TrainerHill_Elevator/scripts.pory"
	releaseall
# 17 "data/maps/TrainerHill_Elevator/scripts.pory"
	warp MAP_TRAINER_HILL_ROOF, 15, 5
# 18 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitstate
# 19 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 20 "data/maps/TrainerHill_Elevator/scripts.pory"

# 21 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_EnterElevator::
# 22 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Elevator_Movement_PlayerApproachAttendant
# 23 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 24 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement LOCALID_TRAINER_HILL_ELEVATOR_ATTENDANT, TrainerHill_Elevator_Movement_AttendantFacePlayer
# 25 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 26 "data/maps/TrainerHill_Elevator/scripts.pory"
	lockall
# 27 "data/maps/TrainerHill_Elevator/scripts.pory"
	msgbox TrainerHill_Elevator_Text_ReturnToReception, MSGBOX_YESNO
# 28 "data/maps/TrainerHill_Elevator/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Elevator_EventScript_ExitToRoof
# 29 "data/maps/TrainerHill_Elevator/scripts.pory"
	releaseall
# 30 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement LOCALID_TRAINER_HILL_ELEVATOR_ATTENDANT, TrainerHill_Elevator_Movement_AttendantFaceDown
# 31 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 32 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Elevator_Movement_PlayerMoveToCenterOfElevator
# 33 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 34 "data/maps/TrainerHill_Elevator/scripts.pory"
	call TrainerHill_Elevator_EventScript_MoveElevator
# 35 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay 25
# 36 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Elevator_Movement_PlayerExitElevator
# 37 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 38 "data/maps/TrainerHill_Elevator/scripts.pory"
	warp MAP_TRAINER_HILL_ENTRANCE, 17, 8
# 39 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitstate
# 40 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 41 "data/maps/TrainerHill_Elevator/scripts.pory"

# 42 "data/maps/TrainerHill_Elevator/scripts.pory"
@ Unused
# 43 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_ExitFloorSelect::
# 44 "data/maps/TrainerHill_Elevator/scripts.pory"
	goto TrainerHill_Elevator_EventScript_CloseFloorSelect
# 45 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 46 "data/maps/TrainerHill_Elevator/scripts.pory"

# 47 "data/maps/TrainerHill_Elevator/scripts.pory"
@ Functionally unused
# 48 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_CloseFloorSelect::
# 49 "data/maps/TrainerHill_Elevator/scripts.pory"
	special CloseDeptStoreElevatorWindow
# 50 "data/maps/TrainerHill_Elevator/scripts.pory"
	releaseall
# 51 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 52 "data/maps/TrainerHill_Elevator/scripts.pory"

# 53 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_MoveElevator::
# 54 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitse
# 55 "data/maps/TrainerHill_Elevator/scripts.pory"
	special MoveElevator
# 56 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitstate
# 57 "data/maps/TrainerHill_Elevator/scripts.pory"
	return
# 58 "data/maps/TrainerHill_Elevator/scripts.pory"

# 59 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerMoveToCenterOfElevator:
# 60 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_up
# 61 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_up
# 62 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_right
# 63 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_down
# 64 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 65 "data/maps/TrainerHill_Elevator/scripts.pory"

# 66 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerApproachAttendant:
# 67 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay_16
# 68 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_left
# 69 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 70 "data/maps/TrainerHill_Elevator/scripts.pory"

# 71 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerExitElevator:
# 72 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay_16
# 73 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_down
# 74 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_down
# 75 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 76 "data/maps/TrainerHill_Elevator/scripts.pory"

# 77 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerExitElevatorToRoof:
# 78 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_down
# 79 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay_16
# 80 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 81 "data/maps/TrainerHill_Elevator/scripts.pory"

# 82 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_AttendantFacePlayer:
# 83 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_right
# 84 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 85 "data/maps/TrainerHill_Elevator/scripts.pory"

# 86 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_AttendantFaceDown:
# 87 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_down
# 88 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
