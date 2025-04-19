# 1 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 4 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_MapScripts::
# 5 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BattleFrontier_BattleTowerCorridor_OnLoad
# 6 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerCorridor_OnFrame
# 7 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	.byte 0
# 8 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 9 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_OnLoad:
# 10 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleTowerCorridor_EventScript_OpenFarDoor
# 11 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 12, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, FALSE
# 12 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 12, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, FALSE
# 13 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	end
# 14 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 15 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_OpenFarDoor::
# 16 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 15, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, FALSE
# 17 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 15, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, FALSE
# 18 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	end
# 19 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 20 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_OnFrame:
# 21 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor
# 22 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	.2byte 0
# 23 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 24 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor::
# 25 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 26 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleTowerCorridor_EventScript_WalkToFarDoor
# 27 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToDoor
# 28 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToDoor
# 29 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	waitmovement 0
# 30 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	goto BattleFrontier_BattleTowerCorridor_EventScript_WarpToBattleRoom
# 31 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 32 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_WalkToFarDoor::
# 33 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToFarDoor
# 34 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToFarDoor
# 35 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	waitmovement 0
# 36 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 37 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_WarpToBattleRoom::
# 38 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setvar VAR_TEMP_0, 0
# 39 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM, 4, 8
# 40 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	waitstate
# 41 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	end
# 42 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 43 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToFarDoor:
# 44 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 45 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToFarDoor:
# 46 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 47 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 48 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToDoor:
# 49 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 50 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToDoor:
# 51 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 52 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 53 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 54 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_up
# 55 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	set_invisible
# 56 "data//maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	step_end
