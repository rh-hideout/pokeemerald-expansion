# 1 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_MapScripts::
# 3 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeCorridor_OnFrame
# 4 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeCorridor_OnWarp
# 5 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 7 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_OnFrame:
# 8 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeCorridor_EventScript_EnterCorridor
# 9 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	.2byte 0
# 10 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 11 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_EventScript_EnterCorridor::
# 12 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	delay 16
# 13 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, 1
# 14 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	pike_cleartrainerids
# 15 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	pike_nohealing TRUE
# 16 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeCorridor_Movement_PlayerEnterCorridor
# 17 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	applymovement LOCALID_PIKE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePikeCorridor_Movement_AttendantEnterCorridor
# 18 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	waitmovement 0
# 19 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	lockall
# 20 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePikeCorridor_Text_YourChallengeHasBegun, MSGBOX_DEFAULT
# 21 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	closemessage
# 22 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	releaseall
# 23 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeCorridor_Movement_PlayerExitCorridor
# 24 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	waitmovement 0
# 25 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 99
# 26 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
# 27 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM, 6, 10
# 28 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	waitstate
# 29 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	end
# 30 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 31 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_OnWarp:
# 32 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeCorridor_EventScript_TurnPlayerNorth
# 33 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	.2byte 0
# 34 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 35 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_EventScript_TurnPlayerNorth::
# 36 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 37 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 38 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	end
# 39 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 40 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_Movement_PlayerEnterCorridor:
# 41 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 42 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 43 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	step_end
# 44 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 45 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_Movement_PlayerExitCorridor:
# 46 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 47 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 48 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	set_invisible
# 49 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	step_end
# 50 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 51 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_Movement_AttendantEnterCorridor:
# 52 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 53 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 54 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_left
# 55 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	face_down
# 56 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	step_end
# 57 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 58 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_Text_YourChallengeHasBegun:
# 59 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	.string "Your Battle Choice challenge\n"
# 60 "data/maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	.string "has now begun…$"
