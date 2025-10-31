# 1 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_MapScripts::
# 3 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerElevator_OnFrame
# 4 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerElevator_OnWarp
# 5 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_OnFrame:
# 8 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerElevator_EventScript_EnterElevator
# 9 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	.2byte 0
# 10 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_EnterElevator::
# 12 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	setvar VAR_TEMP_0, 1
# 13 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement LOCALID_TOWER_ELEVATOR_ATTENDANT, BattleFrontier_BattleTowerElevator_Movement_AttendantEnter
# 14 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerElevator_Movement_PlayerEnter
# 15 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitmovement 0
# 16 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	special BufferBattleTowerElevatorFloors
# 17 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitse
# 18 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	special MoveElevator
# 19 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 20 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	delay 48
# 21 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement LOCALID_TOWER_ELEVATOR_ATTENDANT, BattleFrontier_BattleTowerElevator_Movement_AttendantExit
# 22 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerElevator_Movement_PlayerExit
# 23 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitmovement 0
# 24 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom
# 25 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	end
# 26 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 27 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom::
# 28 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridor
# 29 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridor
# 30 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti
# 31 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridorMulti
# 32 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 33 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 34 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridor::
# 35 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR, 8, 1
# 36 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 37 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 38 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 39 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti::
# 40 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	goto_if_unset FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerElevator_EventScript_WarpToPartnerRoom
# 41 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR, 7, 2
# 42 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 43 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 44 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 45 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridorMulti::
# 46 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR, 7, 2
# 47 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 48 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 49 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 50 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToPartnerRoom::
# 51 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 1
# 52 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 53 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 54 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 55 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_AttendantEnter:
# 56 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 57 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_right
# 58 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	face_down
# 59 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 60 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 61 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_PlayerEnter:
# 62 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 63 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 64 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	face_down
# 65 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 66 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 67 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_AttendantExit:
# 68 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 69 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 70 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	set_invisible
# 71 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 72 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 73 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_PlayerExit:
# 74 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_right
# 75 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 76 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 77 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 78 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 79 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_OnWarp:
# 80 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerElevator_EventScript_TurnPlayerNorth
# 81 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	.2byte 0
# 82 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 83 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_TurnPlayerNorth::
# 84 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	setvar VAR_TEMP_1, 1
# 85 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 86 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	end
