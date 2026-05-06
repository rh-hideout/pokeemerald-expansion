BattleFrontier_BattlePalaceCorridor_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceCorridor_OnFrame_hns
	.byte 0

BattleFrontier_BattlePalaceCorridor_OnFrame_hns:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor_hns
	.2byte 0

BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor_hns::
	delay 16
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor_hns
	waitmovement 0
	lockall
	palace_getcomment
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1_hns
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2_hns
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3_hns
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment_hns
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment_hns
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	goto_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom_hns
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom_hns
	waitmovement 0
	opendoor 6, 3
	waitdooranim
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom_hns
	waitmovement 0
	closedoor 6, 3
	waitdooranim
	goto BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom_hns

BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom_hns::
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom_hns
	waitmovement 0
	opendoor 10, 3
	waitdooranim
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom_hns
	waitmovement 0
	closedoor 10, 3
	waitdooranim
BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom_hns::
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM, 7, 4
	waitstate
	end

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1_hns::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2_hns::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3_hns::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment_hns::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment_hns::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom_hns:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom_hns:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom_hns:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom_hns:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom_hns:
	walk_up
BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame_hns:
	.string "People and POKéMON, they are but\n"
	.string "the same…\p"
	.string "Their individual nature makes them\n"
	.string "good at certain things, and not good\l"
	.string "at others.$"

BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes_hns:
	.string "Rather than trying to make a POKéMON\n"
	.string "do what it dislikes, try to let it do\l"
	.string "what it likes and is good at doing.\p"
	.string "Put yourself in the POKéMON's position\n"
	.string "and consider what moves it would like.$"

BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered_hns:
	.string "A POKéMON's nature is a remarkable\n"
	.string "thing…\p"
	.string "Some POKéMON behave in a completely\n"
	.string "different way when they are cornered.$"

BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature_hns:
	.string "Are you beginning to understand how\n"
	.string "a POKéMON's nature makes it behave?$"

BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons_hns:
	.string "Ah… I see a strong, heartfelt bond\n"
	.string "between you and your POKéMON…$"

