# 1 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 2 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
.set LOCALID_OLD_MAN, 1
# 3 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 4 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_MapScripts::
# 5 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_1F_OnTransition
# 6 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_1F_OnFrame
# 7 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.byte 0
# 8 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 9 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_OnTransition:
# 10 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	frontier_checkvisittrainer
# 11 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq VAR_RESULT, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout
# 12 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_ne VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor
# 13 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 14 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 15 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout::
# 16 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 17 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_OLD_MAN, 3, 2
# 18 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_DOWN
# 19 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED
# 20 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 21 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 22 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor::
# 23 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_OLD_MAN, 2, 2
# 24 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
# 25 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 26 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 27 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_OnFrame:
# 28 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
# 29 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
# 30 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
# 31 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.2byte 0
# 32 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 33 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle::
# 34 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	lockall
# 35 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs
# 36 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 37 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement LOCALID_OLD_MAN, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer
# 38 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 39 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	copyobjectxytoperm LOCALID_OLD_MAN
# 40 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 41 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 42 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleWonComment
# 43 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2, SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleLostComment
# 44 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3, SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleTiedComment
# 45 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special LoadPlayerParty
# 46 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0
# 47 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	releaseall
# 48 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 49 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 50 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleWonComment::
# 51 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative, MSGBOX_DEFAULT
# 52 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 53 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 54 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleLostComment::
# 55 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou, MSGBOX_DEFAULT
# 56 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 57 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 58 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleTiedComment::
# 59 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff, MSGBOX_DEFAULT
# 60 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 61 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 62 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs:
# 63 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_down
# 64 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 65 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 66 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer:
# 67 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_right
# 68 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_in_place_faster_down
# 69 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 70 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 71 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_OldMan::
# 72 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	lock
# 73 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	faceplayer
# 74 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	frontier_checkvisittrainer
# 75 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer
# 76 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq VAR_TEMP_1, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting
# 77 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
# 78 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	release
# 79 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 80 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 81 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer::
# 82 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
# 83 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	release
# 84 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 85 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 86 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting::
# 87 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special SavePlayerParty
# 88 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special BufferEReaderTrainerName
# 89 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer, MSGBOX_YESNO
# 90 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
# 91 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty
# 92 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
# 93 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle, MSGBOX_YESNO
# 94 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
# 95 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special LoadPlayerParty
# 96 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call Common_EventScript_SaveGame
# 97 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
# 98 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special SavePlayerParty
# 99 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 100 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch, MSGBOX_DEFAULT
# 101 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	closemessage
# 102 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth
# 103 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast
# 104 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest
# 105 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F, 3, 1
# 106 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitstate
# 107 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	release
# 108 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 109 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 110 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle::
# 111 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special LoadPlayerParty
# 112 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle, MSGBOX_DEFAULT
# 113 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	release
# 114 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 115 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 116 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty::
# 117 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3, MSGBOX_DEFAULT
# 118 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 119 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special ChooseHalfPartyForBattle
# 120 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitstate
# 121 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 122 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 123 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth::
# 124 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
# 125 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth
# 126 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 127 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 128 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 129 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast::
# 130 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight
# 131 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast
# 132 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 133 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 134 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 135 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest::
# 136 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
# 137 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest
# 138 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 139 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 140 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 141 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth:
# 142 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	delay_16
# 143 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_up
# 144 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_up
# 145 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 146 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 147 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast:
# 148 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	delay_16
# 149 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_right
# 150 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_up
# 151 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 152 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 153 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest:
# 154 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	delay_16
# 155 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_left
# 156 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_up
# 157 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 158 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 159 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft:
# 160 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_left
# 161 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 162 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 163 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 164 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight:
# 165 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_right
# 166 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 167 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 168 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 169 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles:
# 170 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "When I was young, I traveled the world\n"
# 171 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "as a POKéMON TRAINER.\p"
# 172 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Now that I've become an old buzzard,\n"
# 173 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "my only amusement is watching young\l"
# 174 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "TRAINERS battle.$"
# 175 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 176 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_DoorAppearsToBeLocked:
# 177 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "The door appears to be locked.$"
# 178 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 179 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer:
# 180 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "A TRAINER named {STR_VAR_1}\n"
# 181 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "is visiting my home.\p"
# 182 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Would you like to challenge\n"
# 183 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "{STR_VAR_1}?$"
# 184 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 185 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle:
# 186 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "You won't battle? I'm disappointed\n"
# 187 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "that I can't see you battle…$"
# 188 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 189 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3:
# 190 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Oh, good, good!\p"
# 191 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "But my house isn't all that sturdy.\p"
# 192 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Could I ask you to keep it down to\n"
# 193 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "a 3-on-3 match?$"
# 194 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 195 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle:
# 196 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Before you two battle, you should\n"
# 197 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "save your progress.$"
# 198 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 199 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch:
# 200 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "I hope to see a good match!$"
# 201 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 202 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
@ Unused
# 203 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Tie:
# 204 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "{STR_VAR_1}$"
# 205 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 206 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw:
# 207 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "The match ended up a draw.$"
# 208 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 209 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff:
# 210 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "So, it became a standoff.\p"
# 211 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "It was a brilliant match in which\n"
# 212 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "neither side conceded a step!$"
# 213 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 214 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
@ Unused
# 215 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Won:
# 216 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "{STR_VAR_1}$"
# 217 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 218 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative:
# 219 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "That was superlative!\p"
# 220 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Why, it was like seeing myself in\n"
# 221 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "my youth again!$"
# 222 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 223 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
@ Unused
# 224 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Lost:
# 225 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "{STR_VAR_1}$"
# 226 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 227 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou:
# 228 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Ah, too bad for you!\p"
# 229 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "But it was a good match.\n"
# 230 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "I hope you can win next time.$"
