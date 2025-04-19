# 1 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 2 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 4 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_MapScripts::
# 5 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeCorridor_OnFrame
# 6 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeCorridor_OnWarp
# 7 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	.byte 0
# 8 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 9 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_OnFrame:
# 10 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeCorridor_EventScript_EnterCorridor
# 11 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	.2byte 0
# 12 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 13 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_EventScript_EnterCorridor::
# 14 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	delay 16
# 15 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, 1
# 16 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	pike_cleartrainerids
# 17 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	pike_nohealing TRUE
# 18 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeCorridor_Movement_PlayerEnterCorridor
# 19 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePikeCorridor_Movement_AttendantEnterCorridor
# 20 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	waitmovement 0
# 21 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	lockall
# 22 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePikeCorridor_Text_YourChallengeHasBegun, MSGBOX_DEFAULT
# 23 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	closemessage
# 24 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	releaseall
# 25 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeCorridor_Movement_PlayerExitCorridor
# 26 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	waitmovement 0
# 27 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 99
# 28 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
# 29 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM, 6, 10
# 30 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	waitstate
# 31 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	end
# 32 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 33 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_OnWarp:
# 34 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeCorridor_EventScript_TurnPlayerNorth
# 35 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	.2byte 0
# 36 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 37 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_EventScript_TurnPlayerNorth::
# 38 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 39 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 40 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	end
# 41 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 42 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_Movement_PlayerEnterCorridor:
# 43 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 44 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 45 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	step_end
# 46 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 47 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_Movement_PlayerExitCorridor:
# 48 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 49 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 50 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	set_invisible
# 51 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	step_end
# 52 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 53 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_Movement_AttendantEnterCorridor:
# 54 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 55 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_up
# 56 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	walk_left
# 57 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	face_down
# 58 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	step_end
# 59 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"

# 60 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
BattleFrontier_BattlePikeCorridor_Text_YourChallengeHasBegun:
# 61 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	.string "Your Battle Choice challenge\n"
# 62 "data//maps/BattleFrontier_BattlePikeCorridor/scripts.pory"
	.string "has now begun…$"
