BattleFrontier_BattleDomeCorridor_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeCorridor_OnFrame_hns
	.byte 0

BattleFrontier_BattleDomeCorridor_OnFrame_hns:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor_hns
	.2byte 0

BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor_hns::
	delay 16
	setvar VAR_TEMP_0, 1
	frontier_get FRONTIER_DATA_LVL_MODE
	goto_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen_hns
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50_hns
	waitmovement 0
	opendoor 13, 3
	waitdooranim
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50_hns
	waitmovement 0
	closedoor 13, 3
	waitdooranim
	goto BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom_hns

BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen_hns::
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen_hns
	waitmovement 0
	opendoor 37, 3
	waitdooranim
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen_hns
	waitmovement 0
	closedoor 37, 3
	waitdooranim
BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom_hns::
	waitmovement 0
	setvar VAR_0x8006, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 5, 7
	waitstate
	end

BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50_hns:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50_hns:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen_hns:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen_hns:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen_hns:
	walk_up
	set_invisible
	step_end

@ Unused
BattleFrontier_BattleDomeCorridor_Movement_WalkToBattleRoomMidRight_hns:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end
