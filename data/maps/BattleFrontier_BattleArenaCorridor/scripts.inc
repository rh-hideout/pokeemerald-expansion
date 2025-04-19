# 1 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 4 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_MapScripts::
# 5 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaCorridor_OnFrame
# 6 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	.byte 0
# 7 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 8 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_OnFrame:
# 9 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaCorridor_EventScript_WalkToBattleRoom
# 10 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	.2byte 0
# 11 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 12 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_EventScript_WalkToBattleRoom::
# 13 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	delay 16
# 14 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 15 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantWalkToDoor
# 16 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaCorridor_Movement_PlayerWalkToDoor
# 17 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	waitmovement 0
# 18 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantFacePlayer
# 19 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	waitmovement 0
# 20 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	msgbox BattleFrontier_BattleArenaCorridor_Text_PleaseStepIn, MSGBOX_SIGN
# 21 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantMoveOutOfWay
# 22 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	waitmovement 0
# 23 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaCorridor_Movement_PlayerEnterDoor
# 24 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	waitmovement 0
# 25 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	setvar VAR_0x8006, 0
# 26 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM, 7, 5
# 27 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	waitstate
# 28 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	end
# 29 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 30 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Movement_PlayerWalkToDoor:
# 31 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 32 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 33 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 34 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 35 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 36 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 37 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 38 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 39 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 40 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 41 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 42 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 43 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 44 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 45 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 46 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 47 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 48 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 49 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 50 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 51 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	step_end
# 52 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 53 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Movement_PlayerEnterDoor:
# 54 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 55 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	set_invisible
# 56 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	step_end
# 57 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 58 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Movement_AttendantWalkToDoor:
# 59 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 60 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 61 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 62 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 63 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 64 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 65 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 66 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 67 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 68 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 69 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 70 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 71 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 72 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 73 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 74 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 75 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 76 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 77 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 78 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 79 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	step_end
# 80 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 81 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Movement_AttendantFacePlayer:
# 82 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_in_place_faster_left
# 83 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	step_end
# 84 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 85 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Movement_AttendantMoveOutOfWay:
# 86 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 87 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_in_place_faster_down
# 88 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	step_end
# 89 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 90 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Text_PleaseStepIn:
# 91 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	.string "Your battles shall be waged in\n"
# 92 "data//maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	.string "the next room. Please step in!$"
