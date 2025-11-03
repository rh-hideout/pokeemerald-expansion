# 1 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_MapScripts::
# 3 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BattleFrontier_BattleTowerCorridor_OnLoad
# 4 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerCorridor_OnFrame
# 5 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_OnLoad:
# 8 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleTowerCorridor_EventScript_OpenFarDoor
# 9 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 12, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, FALSE
# 10 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 12, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, FALSE
# 11 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	end
# 12 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 13 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_OpenFarDoor::
# 14 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 15, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, FALSE
# 15 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 15, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, FALSE
# 16 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	end
# 17 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 18 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_OnFrame:
# 19 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor
# 20 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	.2byte 0
# 21 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 22 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor::
# 23 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 24 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleTowerCorridor_EventScript_WalkToFarDoor
# 25 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement LOCALID_TOWER_CORRIDOR_ATTENDANT, BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToDoor
# 26 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToDoor
# 27 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	waitmovement 0
# 28 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	goto BattleFrontier_BattleTowerCorridor_EventScript_WarpToBattleRoom
# 29 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 30 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_WalkToFarDoor::
# 31 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement LOCALID_TOWER_CORRIDOR_ATTENDANT, BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToFarDoor
# 32 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToFarDoor
# 33 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	waitmovement 0
# 34 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 35 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_WarpToBattleRoom::
# 36 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setvar VAR_TEMP_0, 0
# 37 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM, 4, 8
# 38 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	waitstate
# 39 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	end
# 40 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 41 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToFarDoor:
# 42 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 43 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToFarDoor:
# 44 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 45 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 46 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToDoor:
# 47 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 48 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToDoor:
# 49 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 50 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 51 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 52 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_up
# 53 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	set_invisible
# 54 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	step_end
