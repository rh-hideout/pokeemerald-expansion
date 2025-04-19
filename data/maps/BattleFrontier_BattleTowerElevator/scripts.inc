# 1 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 4 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_MapScripts::
# 5 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerElevator_OnFrame
# 6 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerElevator_OnWarp
# 7 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	.byte 0
# 8 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 9 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_OnFrame:
# 10 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerElevator_EventScript_EnterElevator
# 11 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	.2byte 0
# 12 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 13 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_EnterElevator::
# 14 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	setvar VAR_TEMP_0, 1
# 15 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerElevator_Movement_AttendantEnter
# 16 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerElevator_Movement_PlayerEnter
# 17 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitmovement 0
# 18 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	special BufferBattleTowerElevatorFloors
# 19 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitse
# 20 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	special MoveElevator
# 21 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 22 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	delay 48
# 23 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerElevator_Movement_AttendantExit
# 24 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerElevator_Movement_PlayerExit
# 25 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitmovement 0
# 26 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom
# 27 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	end
# 28 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 29 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom::
# 30 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridor
# 31 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridor
# 32 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti
# 33 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridorMulti
# 34 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 35 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 36 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridor::
# 37 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR, 8, 1
# 38 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 39 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 40 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 41 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti::
# 42 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	goto_if_unset FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerElevator_EventScript_WarpToPartnerRoom
# 43 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR, 7, 2
# 44 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 45 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 46 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 47 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridorMulti::
# 48 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR, 7, 2
# 49 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 50 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 51 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 52 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToPartnerRoom::
# 53 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 1
# 54 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 55 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 56 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 57 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_AttendantEnter:
# 58 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 59 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_right
# 60 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	face_down
# 61 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 62 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 63 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_PlayerEnter:
# 64 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 65 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 66 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	face_down
# 67 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 68 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 69 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_AttendantExit:
# 70 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 71 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 72 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	set_invisible
# 73 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 74 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 75 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_PlayerExit:
# 76 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_right
# 77 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 78 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 79 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 80 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 81 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_OnWarp:
# 82 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerElevator_EventScript_TurnPlayerNorth
# 83 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	.2byte 0
# 84 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 85 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_TurnPlayerNorth::
# 86 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	setvar VAR_TEMP_1, 1
# 87 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 88 "data//maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	end
