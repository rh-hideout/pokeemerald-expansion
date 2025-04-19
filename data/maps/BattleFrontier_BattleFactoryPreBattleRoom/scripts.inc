# 1 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 4 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_MapScripts::
# 5 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnFrame
# 6 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnWarp
# 7 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.byte 0
# 8 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 9 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_OnWarp:
# 10 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects
# 11 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.2byte 0
# 12 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 13 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects::
# 14 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 15 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_ne VAR_0x8006, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth
# 16 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setobjectxy LOCALID_ATTENDANT, 8, 7
# 17 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	turnobject LOCALID_ATTENDANT, DIR_SOUTH
# 18 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth::
# 19 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 20 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 21 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 22 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_OnFrame:
# 23 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom
# 24 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.2byte 0
# 25 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 26 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom::
# 27 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle
# 28 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 29 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom
# 30 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom
# 31 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 32 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_0x8006, 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge
# 33 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generaterentalmons
# 34 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generateopponentmons
# 35 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentmontype
# 36 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8005, VAR_RESULT
# 37 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentstyle
# 38 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 39 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
# 40 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
# 41 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
# 42 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 43 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setswapped
# 44 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_rentmons
# 45 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 46 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom::
# 47 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
# 48 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 49 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 50 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50
# 51 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen
# 52 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 53 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM, 6, 11
# 54 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 55 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 56 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 57 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle::
# 58 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setopponentmons
# 59 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_resethelditems
# 60 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
# 61 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 62 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitfanfare
# 63 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special HealPlayerParty
# 64 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 65 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent
# 66 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 67 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitse
# 68 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments, MSGBOX_DEFAULT
# 69 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 70 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall
# 71 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 72 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo, MSGBOX_DEFAULT
# 73 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 74 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer
# 75 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 76 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow, MSGBOX_DEFAULT
# 77 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 78 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	delay 16
# 79 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 80 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 81 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 82 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent::
# 83 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 84 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 85 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent::
# 86 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 87 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent
# 88 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent
# 89 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent
# 90 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent
# 91 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent
# 92 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent
# 93 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 94 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 95 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 96 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 97 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
# 98 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
# 99 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 100 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 101 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 102 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 103 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord::
# 104 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 105 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 106 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
# 107 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 108 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 109 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 110 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 111 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle::
# 112 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle
# 113 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 114 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 115 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 116 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 117 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle
# 118 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 119 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 120 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle::
# 121 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 122 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 123 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 124 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge::
# 125 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 126 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 127 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 128 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge
# 129 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 130 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 131 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge::
# 132 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
# 133 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 134 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 135 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 136 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 137 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost
# 138 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 139 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 140 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon::
# 141 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generateopponentmons
# 142 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentmontype
# 143 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8005, VAR_RESULT
# 144 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentstyle
# 145 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 146 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
# 147 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
# 148 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
# 149 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 150 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 151 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
# 152 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 153 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 154 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons::
# 155 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 156 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_swapmons
# 157 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 158 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom  @ Did player keep current pokemon
# 159 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setswapped
# 160 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
# 161 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 162 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 163 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent::
# 164 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
# 165 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 166 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 167 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 168 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent::
# 169 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
# 170 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 171 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 172 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 173 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent::
# 174 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent
# 175 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 176 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 177 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 178 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent::
# 179 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent
# 180 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 181 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 182 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 183 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent::
# 184 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent
# 185 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 186 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 187 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 188 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent::
# 189 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent
# 190 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 191 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 192 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 193 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge::
# 194 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
# 195 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 196 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_save CHALLENGE_STATUS_PAUSED
# 197 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playse SE_SAVE
# 198 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitse
# 199 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 200 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_reset
# 201 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 202 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 203 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge::
# 204 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special SavePlayerParty
# 205 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setparties 0
# 206 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 207 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special CalculatePlayerPartyCount
# 208 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 209 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 210 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType::
# 211 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent, MSGBOX_DEFAULT
# 212 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_NORMAL, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal
# 213 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_FIGHTING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting
# 214 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_FLYING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying
# 215 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_POISON, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison
# 216 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_GROUND, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround
# 217 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_ROCK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock
# 218 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_BUG, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug
# 219 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_GHOST, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost
# 220 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_STEEL, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel
# 221 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_FIRE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire
# 222 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_WATER, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater
# 223 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_GRASS, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass
# 224 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_ELECTRIC, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric
# 225 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_PSYCHIC, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic
# 226 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_ICE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce
# 227 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_DRAGON, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon
# 228 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_DARK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark
# 229 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_FAIRY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFairy
# 230 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, NUMBER_OF_MON_TYPES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType
# 231 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 232 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 233 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal::
# 234 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType, MSGBOX_DEFAULT
# 235 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 236 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 237 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting::
# 238 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType, MSGBOX_DEFAULT
# 239 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 240 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 241 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying::
# 242 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType, MSGBOX_DEFAULT
# 243 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 244 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 245 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison::
# 246 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType, MSGBOX_DEFAULT
# 247 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 248 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 249 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround::
# 250 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType, MSGBOX_DEFAULT
# 251 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 252 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 253 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock::
# 254 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType, MSGBOX_DEFAULT
# 255 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 256 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 257 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug::
# 258 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType, MSGBOX_DEFAULT
# 259 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 260 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 261 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost::
# 262 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType, MSGBOX_DEFAULT
# 263 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 264 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 265 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel::
# 266 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType, MSGBOX_DEFAULT
# 267 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 268 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 269 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire::
# 270 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType, MSGBOX_DEFAULT
# 271 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 272 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 273 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater::
# 274 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType, MSGBOX_DEFAULT
# 275 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 276 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 277 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass::
# 278 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType, MSGBOX_DEFAULT
# 279 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 280 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 281 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric::
# 282 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType, MSGBOX_DEFAULT
# 283 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 284 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 285 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic::
# 286 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType, MSGBOX_DEFAULT
# 287 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 288 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 289 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce::
# 290 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType, MSGBOX_DEFAULT
# 291 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 292 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 293 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon::
# 294 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType, MSGBOX_DEFAULT
# 295 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 296 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 297 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark::
# 298 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType, MSGBOX_DEFAULT
# 299 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 300 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 301 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFairy::
# 302 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFairyType, MSGBOX_DEFAULT
# 303 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 304 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 305 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType::
# 306 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite, MSGBOX_DEFAULT
# 307 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 308 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 309 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle::
# 310 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_NONE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained
# 311 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_PREPARATION, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation
# 312 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_SLOW_STEADY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady
# 313 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_ENDURANCE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance
# 314 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_HIGH_RISK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk
# 315 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_WEAKENING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe
# 316 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_UNPREDICTABLE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict
# 317 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_WEATHER, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow
# 318 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_NUM_STYLES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible
# 319 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 320 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 321 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained::
# 322 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained, MSGBOX_DEFAULT
# 323 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 324 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 325 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation::
# 326 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation, MSGBOX_DEFAULT
# 327 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 328 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 329 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady::
# 330 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady, MSGBOX_DEFAULT
# 331 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 332 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 333 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance::
# 334 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance, MSGBOX_DEFAULT
# 335 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 336 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 337 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk::
# 338 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk, MSGBOX_DEFAULT
# 339 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 340 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 341 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe::
# 342 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe, MSGBOX_DEFAULT
# 343 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 344 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 345 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict::
# 346 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict, MSGBOX_DEFAULT
# 347 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 348 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 349 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow::
# 350 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow, MSGBOX_DEFAULT
# 351 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 352 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 353 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible::
# 354 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible, MSGBOX_DEFAULT
# 355 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 356 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 357 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead::
# 358 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead
# 359 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 360 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 361 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord
# 362 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 363 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 364 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
# 365 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
# 366 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 367 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 368 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 369 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 370 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord::
# 371 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 372 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 373 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
# 374 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 375 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 376 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 377 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 378 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead::
# 379 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead, MSGBOX_DEFAULT
# 380 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
# 381 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 382 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 383 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
# 384 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 385 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 386 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50::
# 387 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50
# 388 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50
# 389 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 390 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 391 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen::
# 392 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen
# 393 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen
# 394 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 395 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 396 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom:
# 397 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 398 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 399 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 400 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 401 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 402 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 403 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 404 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50:
# 405 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 406 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 407 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 408 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 409 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 410 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 411 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 412 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen:
# 413 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 414 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 415 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 416 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 417 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 418 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 419 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 420 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom:
# 421 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 422 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 423 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 424 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 425 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 426 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	face_down
# 427 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 428 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 429 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50:
# 430 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 431 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 432 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 433 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 434 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	set_invisible
# 435 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 436 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 437 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen:
# 438 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 439 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 440 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 441 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 442 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	set_invisible
# 443 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 444 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 445 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall:
# 446 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 447 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 448 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 449 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 450 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 451 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer:
# 452 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 453 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 454 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 455 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	face_down
# 456 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 457 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 458 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection:
# 459 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "First, we will hold your POKéMON for\n"
# 460 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "safekeeping.\p"
# 461 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "You may then choose from our\n"
# 462 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "selection of POKéMON.$"
# 463 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 464 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons:
# 465 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Thank you for competing!\n"
# 466 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Let us restore your POKéMON!$"
# 467 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 468 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent:
# 469 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 2nd match is next!\n"
# 470 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 471 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 472 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent:
# 473 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 3rd match is next!\n"
# 474 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 475 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 476 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent:
# 477 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 4th match is next!\n"
# 478 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 479 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 480 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent:
# 481 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 5th match is next!\n"
# 482 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 483 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 484 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent:
# 485 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 6th match is next!\n"
# 486 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 487 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 488 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent:
# 489 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Finally, the 7th match is next!\n"
# 490 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 491 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 492 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame:
# 493 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to save and quit\n"
# 494 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "the game?$"
# 495 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 496 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge:
# 497 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to retire from your\n"
# 498 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Battle Swap challenge?$"
# 499 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 500 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent:
# 501 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I've conducted a little investigation\n"
# 502 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "about your upcoming opponent.$"
# 503 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 504 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType:
# 505 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 506 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the NORMAL type.$"
# 507 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 508 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType:
# 509 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 510 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FIRE type.$"
# 511 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 512 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType:
# 513 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 514 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the WATER type.$"
# 515 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 516 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType:
# 517 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 518 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ELECTRIC type.$"
# 519 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 520 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType:
# 521 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 522 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GRASS type.$"
# 523 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 524 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType:
# 525 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 526 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ICE type.$"
# 527 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 528 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType:
# 529 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 530 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FIGHTING type.$"
# 531 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 532 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType:
# 533 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 534 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the POISON type.$"
# 535 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 536 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType:
# 537 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 538 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GROUND type.$"
# 539 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 540 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType:
# 541 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 542 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FLYING type.$"
# 543 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 544 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType:
# 545 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 546 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the PSYCHIC type.$"
# 547 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 548 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType:
# 549 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 550 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the BUG type.$"
# 551 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 552 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType:
# 553 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 554 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ROCK type.$"
# 555 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 556 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType:
# 557 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 558 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GHOST type.$"
# 559 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 560 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType:
# 561 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 562 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the DRAGON type.$"
# 563 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 564 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType:
# 565 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 566 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the DARK type.$"
# 567 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 568 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFairyType:
# 569 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 570 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FAIRY type.$"
# 571 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 572 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType:
# 573 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 574 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the STEEL type.$"
# 575 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 576 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite:
# 577 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER appears to have no clear\n"
# 578 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "favorites when it comes to type.$"
# 579 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 580 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady:
# 581 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 582 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be slow and steady.$"
# 583 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 584 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance:
# 585 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 586 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be one of endurance.$"
# 587 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 588 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk:
# 589 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 590 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be high risk, high return.$"
# 591 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 592 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow:
# 593 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 594 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "depend on the battle's flow.$"
# 595 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 596 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation:
# 597 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 598 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be one based on total preparation.$"
# 599 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 600 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe:
# 601 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears\n"
# 602 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "to be weakening the foe to start.$"
# 603 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 604 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible:
# 605 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 606 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be flexibly adaptable to the situation.$"
# 607 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 608 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict:
# 609 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 610 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be impossible to predict.$"
# 611 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 612 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained:
# 613 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 614 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be free-spirited and unrestrained.$"
# 615 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 616 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon:
# 617 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Before starting the battle, would you\n"
# 618 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "like to swap a POKéMON?$"
# 619 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 620 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete:
# 621 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Thank you!\n"
# 622 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Your POKéMON swap is complete.$"
# 623 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 624 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay:
# 625 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Right this way, please!$"
# 626 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 627 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait:
# 628 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I am saving your data.\n"
# 629 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Please wait.$"
# 630 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 631 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle:
# 632 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to record your latest\n"
# 633 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "battle on your FRONTIER PASS?$"
# 634 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 635 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments:
# 636 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Excuse me! Excuse me, please!\n"
# 637 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "May I get you to wait a few moments?$"
# 638 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 639 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo:
# 640 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "…Uh-huh? What?! …Whoa!\n"
# 641 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Understood, sir! Will do!$"
# 642 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 643 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow:
# 644 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Oh, my…\n"
# 645 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Sorry to keep you waiting!\p"
# 646 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I have a message from this facility's\n"
# 647 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "boss, the FACTORY HEAD.\p"
# 648 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "He says, “We're going to do it!\n"
# 649 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Come here right now!”$"
# 650 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 651 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead:
# 652 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The FACTORY HEAD is demanding you.\n"
# 653 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you prepared to face him?$"
# 654 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 655 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead:
# 656 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I'm terribly sorry, but I can't tell you\n"
# 657 "data//maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "anything about the FACTORY HEAD.$"
