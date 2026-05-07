BattleFrontier_BattleArenaCorridor_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaCorridor_OnFrame_hns
	.byte 0

BattleFrontier_BattleArenaCorridor_OnFrame_hns:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaCorridor_EventScript_WalkToBattleRoom_hns
	.2byte 0

BattleFrontier_BattleArenaCorridor_EventScript_WalkToBattleRoom_hns::
	delay 16
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ARENA_CORRIDOR_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantWalkToDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaCorridor_Movement_PlayerWalkToDoor_hns
	waitmovement 0
	applymovement LOCALID_ARENA_CORRIDOR_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantFacePlayer_hns
	waitmovement 0
	msgbox BattleFrontier_BattleArenaCorridor_Text_PleaseStepIn_hns, MSGBOX_SIGN
	applymovement LOCALID_ARENA_CORRIDOR_ATTENDANT, BattleFrontier_BattleArenaCorridor_Movement_AttendantMoveOutOfWay_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaCorridor_Movement_PlayerEnterDoor_hns
	waitmovement 0
	setvar VAR_0x8006, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM_HNS, 7, 5
	waitstate
	end

BattleFrontier_BattleArenaCorridor_Movement_PlayerWalkToDoor_hns:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

BattleFrontier_BattleArenaCorridor_Movement_PlayerEnterDoor_hns:
	walk_right
	set_invisible
	step_end

BattleFrontier_BattleArenaCorridor_Movement_AttendantWalkToDoor_hns:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BattleFrontier_BattleArenaCorridor_Movement_AttendantFacePlayer_hns:
	walk_in_place_faster_left
	step_end

BattleFrontier_BattleArenaCorridor_Movement_AttendantMoveOutOfWay_hns:
	walk_up
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleArenaCorridor_Text_PleaseStepIn_hns:
	.string "Your battles shall be waged in\n"
	.string "the next room. Please step in!$"

