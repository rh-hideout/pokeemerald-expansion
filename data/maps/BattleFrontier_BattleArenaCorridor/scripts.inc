# 1 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_MapScripts::
# 3 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaCorridor_OnFrame
# 4 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	.byte 0
# 5 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 6 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_OnFrame:
# 7 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaCorridor_EventScript_WalkToBattleRoom
# 8 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	.2byte 0
# 9 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 10 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_EventScript_WalkToBattleRoom::
# 11 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	delay 16
# 12 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 13 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	applymovement LOCALID_ARENA_CORRIDOR_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantWalkToDoor
# 14 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaCorridor_Movement_PlayerWalkToDoor
# 15 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	waitmovement 0
# 16 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	applymovement LOCALID_ARENA_CORRIDOR_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantFacePlayer
# 17 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	waitmovement 0
# 18 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	msgbox BattleFrontier_BattleArenaCorridor_Text_PleaseStepIn, MSGBOX_SIGN
# 19 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	applymovement LOCALID_ARENA_CORRIDOR_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantMoveOutOfWay
# 20 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	waitmovement 0
# 21 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaCorridor_Movement_PlayerEnterDoor
# 22 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	waitmovement 0
# 23 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	setvar VAR_0x8006, 0
# 24 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM, 7, 5
# 25 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	waitstate
# 26 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	end
# 27 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 28 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Movement_PlayerWalkToDoor:
# 29 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 30 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 31 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 32 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 33 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 34 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 35 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 36 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 37 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 38 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 39 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 40 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 41 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 42 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 43 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 44 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 45 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 46 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 47 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 48 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 49 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	step_end
# 50 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 51 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Movement_PlayerEnterDoor:
# 52 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 53 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	set_invisible
# 54 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	step_end
# 55 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 56 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Movement_AttendantWalkToDoor:
# 57 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 58 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 59 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 60 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 61 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 62 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 63 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 64 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_left
# 65 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 66 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 67 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 68 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 69 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 70 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 71 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 72 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 73 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 74 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 75 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 76 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_right
# 77 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	step_end
# 78 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 79 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Movement_AttendantFacePlayer:
# 80 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_in_place_faster_left
# 81 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	step_end
# 82 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 83 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Movement_AttendantMoveOutOfWay:
# 84 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_up
# 85 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	walk_in_place_faster_down
# 86 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	step_end
# 87 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"

# 88 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
BattleFrontier_BattleArenaCorridor_Text_PleaseStepIn:
# 89 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	.string "Your battles shall be waged in\n"
# 90 "data/maps/BattleFrontier_BattleArenaCorridor/scripts.pory"
	.string "the next room. Please step in!$"
