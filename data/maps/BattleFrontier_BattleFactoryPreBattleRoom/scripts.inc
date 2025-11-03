# 1 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_MapScripts::
# 3 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnFrame
# 4 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnWarp
# 5 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_OnWarp:
# 8 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects
# 9 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.2byte 0
# 10 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects::
# 12 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 13 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_ne VAR_0x8006, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth
# 14 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setobjectxy LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, 8, 7
# 15 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	turnobject LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, DIR_SOUTH
# 16 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth::
# 17 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 18 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 19 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 20 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_OnFrame:
# 21 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom
# 22 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.2byte 0
# 23 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 24 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom::
# 25 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle
# 26 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 27 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom
# 28 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom
# 29 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 30 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_0x8006, 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge
# 31 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generaterentalmons
# 32 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generateopponentmons
# 33 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentmontype
# 34 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8005, VAR_RESULT
# 35 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentstyle
# 36 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 37 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
# 38 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
# 39 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
# 40 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 41 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setswapped
# 42 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_rentmons
# 43 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 44 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom::
# 45 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
# 46 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 47 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 48 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50
# 49 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen
# 50 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM, 6, 11
# 52 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 53 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 54 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 55 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle::
# 56 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setopponentmons
# 57 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_resethelditems
# 58 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
# 59 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 60 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitfanfare
# 61 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special HealPlayerParty
# 62 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 63 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent
# 64 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 65 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitse
# 66 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments, MSGBOX_DEFAULT
# 67 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 68 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall
# 69 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 70 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo, MSGBOX_DEFAULT
# 71 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 72 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer
# 73 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 74 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow, MSGBOX_DEFAULT
# 75 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 76 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	delay 16
# 77 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 78 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 79 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 80 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent::
# 81 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 82 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 83 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent::
# 84 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 85 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent
# 86 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent
# 87 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent
# 88 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent
# 89 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent
# 90 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent
# 91 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 92 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 93 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 94 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 95 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
# 96 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
# 97 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 98 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 99 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 100 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 101 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord::
# 102 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 103 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 104 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
# 105 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 106 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 107 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 108 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 109 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle::
# 110 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle
# 111 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 112 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 113 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 114 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 115 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle
# 116 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 117 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 118 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle::
# 119 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 120 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 121 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 122 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge::
# 123 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 124 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 125 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 126 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge
# 127 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 128 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 129 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge::
# 130 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
# 131 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 132 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 133 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 134 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 135 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost
# 136 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 137 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 138 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon::
# 139 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generateopponentmons
# 140 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentmontype
# 141 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8005, VAR_RESULT
# 142 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentstyle
# 143 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 144 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
# 145 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
# 146 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
# 147 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 148 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 149 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
# 150 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 151 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 152 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons::
# 153 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 154 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_swapmons
# 155 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 156 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom  @ Did player keep current pokemon
# 157 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setswapped
# 158 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
# 159 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 160 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 161 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent::
# 162 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
# 163 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 164 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 165 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 166 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent::
# 167 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
# 168 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 169 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 170 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 171 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent::
# 172 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent
# 173 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 174 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 175 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 176 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent::
# 177 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent
# 178 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 179 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 180 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 181 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent::
# 182 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent
# 183 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 184 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 185 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 186 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent::
# 187 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent
# 188 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 189 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 190 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 191 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge::
# 192 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
# 193 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 194 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_save CHALLENGE_STATUS_PAUSED
# 195 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playse SE_SAVE
# 196 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitse
# 197 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 198 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_reset
# 199 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 200 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 201 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge::
# 202 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special SavePlayerParty
# 203 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setparties 0
# 204 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 205 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special CalculatePlayerPartyCount
# 206 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 207 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 208 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType::
# 209 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent, MSGBOX_DEFAULT
# 210 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_NORMAL, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal
# 211 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_FIGHTING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting
# 212 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_FLYING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying
# 213 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_POISON, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison
# 214 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_GROUND, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround
# 215 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_ROCK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock
# 216 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_BUG, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug
# 217 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_GHOST, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost
# 218 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_STEEL, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel
# 219 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_FIRE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire
# 220 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_WATER, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater
# 221 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_GRASS, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass
# 222 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_ELECTRIC, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric
# 223 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_PSYCHIC, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic
# 224 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_ICE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce
# 225 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_DRAGON, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon
# 226 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_DARK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark
# 227 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_FAIRY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFairy
# 228 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, NUMBER_OF_MON_TYPES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType
# 229 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 230 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 231 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal::
# 232 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType, MSGBOX_DEFAULT
# 233 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 234 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 235 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting::
# 236 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType, MSGBOX_DEFAULT
# 237 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 238 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 239 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying::
# 240 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType, MSGBOX_DEFAULT
# 241 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 242 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 243 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison::
# 244 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType, MSGBOX_DEFAULT
# 245 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 246 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 247 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround::
# 248 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType, MSGBOX_DEFAULT
# 249 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 250 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 251 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock::
# 252 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType, MSGBOX_DEFAULT
# 253 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 254 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 255 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug::
# 256 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType, MSGBOX_DEFAULT
# 257 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 258 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 259 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost::
# 260 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType, MSGBOX_DEFAULT
# 261 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 262 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 263 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel::
# 264 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType, MSGBOX_DEFAULT
# 265 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 266 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 267 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire::
# 268 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType, MSGBOX_DEFAULT
# 269 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 270 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 271 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater::
# 272 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType, MSGBOX_DEFAULT
# 273 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 274 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 275 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass::
# 276 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType, MSGBOX_DEFAULT
# 277 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 278 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 279 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric::
# 280 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType, MSGBOX_DEFAULT
# 281 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 282 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 283 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic::
# 284 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType, MSGBOX_DEFAULT
# 285 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 286 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 287 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce::
# 288 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType, MSGBOX_DEFAULT
# 289 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 290 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 291 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon::
# 292 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType, MSGBOX_DEFAULT
# 293 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 294 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 295 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark::
# 296 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType, MSGBOX_DEFAULT
# 297 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 298 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 299 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFairy::
# 300 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFairyType, MSGBOX_DEFAULT
# 301 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 302 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 303 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType::
# 304 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite, MSGBOX_DEFAULT
# 305 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 306 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 307 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle::
# 308 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_NONE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained
# 309 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_PREPARATION, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation
# 310 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_SLOW_STEADY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady
# 311 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_ENDURANCE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance
# 312 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_HIGH_RISK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk
# 313 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_WEAKENING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe
# 314 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_UNPREDICTABLE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict
# 315 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_WEATHER, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow
# 316 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_NUM_STYLES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible
# 317 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 318 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 319 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained::
# 320 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained, MSGBOX_DEFAULT
# 321 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 322 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 323 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation::
# 324 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation, MSGBOX_DEFAULT
# 325 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 326 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 327 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady::
# 328 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady, MSGBOX_DEFAULT
# 329 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 330 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 331 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance::
# 332 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance, MSGBOX_DEFAULT
# 333 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 334 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 335 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk::
# 336 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk, MSGBOX_DEFAULT
# 337 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 338 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 339 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe::
# 340 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe, MSGBOX_DEFAULT
# 341 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 342 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 343 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict::
# 344 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict, MSGBOX_DEFAULT
# 345 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 346 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 347 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow::
# 348 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow, MSGBOX_DEFAULT
# 349 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 350 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 351 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible::
# 352 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible, MSGBOX_DEFAULT
# 353 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 354 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 355 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead::
# 356 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead
# 357 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 358 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 359 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord
# 360 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 361 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 362 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
# 363 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
# 364 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 365 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 366 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 367 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 368 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord::
# 369 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 370 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 371 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
# 372 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 373 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 374 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 375 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 376 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead::
# 377 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead, MSGBOX_DEFAULT
# 378 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
# 379 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 380 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 381 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
# 382 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 383 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 384 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50::
# 385 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50
# 386 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50
# 387 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 388 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 389 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen::
# 390 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen
# 391 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen
# 392 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 393 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 394 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom:
# 395 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 396 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 397 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 398 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 399 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 400 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 401 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 402 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50:
# 403 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 404 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 405 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 406 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 407 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 408 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 409 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 410 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen:
# 411 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 412 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 413 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 414 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 415 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 416 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 417 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 418 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom:
# 419 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 420 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 421 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 422 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 423 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 424 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	face_down
# 425 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 426 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 427 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50:
# 428 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 429 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 430 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 431 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 432 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	set_invisible
# 433 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 434 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 435 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen:
# 436 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 437 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 438 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 439 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 440 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	set_invisible
# 441 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 442 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 443 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall:
# 444 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 445 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 446 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 447 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 448 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 449 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer:
# 450 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 451 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 452 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 453 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	face_down
# 454 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 455 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 456 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection:
# 457 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "First, we will hold your POKéMON for\n"
# 458 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "safekeeping.\p"
# 459 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "You may then choose from our\n"
# 460 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "selection of POKéMON.$"
# 461 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 462 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons:
# 463 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Thank you for competing!\n"
# 464 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Let us restore your POKéMON!$"
# 465 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 466 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent:
# 467 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 2nd match is next!\n"
# 468 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 469 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 470 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent:
# 471 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 3rd match is next!\n"
# 472 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 473 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 474 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent:
# 475 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 4th match is next!\n"
# 476 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 477 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 478 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent:
# 479 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 5th match is next!\n"
# 480 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 481 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 482 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent:
# 483 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 6th match is next!\n"
# 484 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 485 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 486 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent:
# 487 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Finally, the 7th match is next!\n"
# 488 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 489 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 490 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame:
# 491 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to save and quit\n"
# 492 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "the game?$"
# 493 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 494 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge:
# 495 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to retire from your\n"
# 496 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Battle Swap challenge?$"
# 497 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 498 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent:
# 499 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I've conducted a little investigation\n"
# 500 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "about your upcoming opponent.$"
# 501 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 502 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType:
# 503 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 504 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the NORMAL type.$"
# 505 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 506 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType:
# 507 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 508 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FIRE type.$"
# 509 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 510 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType:
# 511 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 512 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the WATER type.$"
# 513 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 514 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType:
# 515 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 516 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ELECTRIC type.$"
# 517 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 518 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType:
# 519 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 520 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GRASS type.$"
# 521 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 522 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType:
# 523 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 524 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ICE type.$"
# 525 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 526 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType:
# 527 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 528 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FIGHTING type.$"
# 529 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 530 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType:
# 531 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 532 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the POISON type.$"
# 533 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 534 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType:
# 535 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 536 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GROUND type.$"
# 537 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 538 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType:
# 539 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 540 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FLYING type.$"
# 541 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 542 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType:
# 543 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 544 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the PSYCHIC type.$"
# 545 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 546 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType:
# 547 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 548 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the BUG type.$"
# 549 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 550 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType:
# 551 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 552 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ROCK type.$"
# 553 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 554 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType:
# 555 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 556 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GHOST type.$"
# 557 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 558 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType:
# 559 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 560 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the DRAGON type.$"
# 561 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 562 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType:
# 563 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 564 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the DARK type.$"
# 565 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 566 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFairyType:
# 567 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 568 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FAIRY type.$"
# 569 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 570 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType:
# 571 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 572 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the STEEL type.$"
# 573 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 574 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite:
# 575 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER appears to have no clear\n"
# 576 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "favorites when it comes to type.$"
# 577 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 578 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady:
# 579 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 580 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be slow and steady.$"
# 581 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 582 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance:
# 583 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 584 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be one of endurance.$"
# 585 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 586 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk:
# 587 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 588 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be high risk, high return.$"
# 589 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 590 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow:
# 591 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 592 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "depend on the battle's flow.$"
# 593 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 594 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation:
# 595 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 596 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be one based on total preparation.$"
# 597 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 598 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe:
# 599 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears\n"
# 600 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "to be weakening the foe to start.$"
# 601 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 602 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible:
# 603 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 604 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be flexibly adaptable to the situation.$"
# 605 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 606 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict:
# 607 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 608 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be impossible to predict.$"
# 609 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 610 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained:
# 611 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 612 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be free-spirited and unrestrained.$"
# 613 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 614 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon:
# 615 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Before starting the battle, would you\n"
# 616 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "like to swap a POKéMON?$"
# 617 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 618 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete:
# 619 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Thank you!\n"
# 620 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Your POKéMON swap is complete.$"
# 621 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 622 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay:
# 623 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Right this way, please!$"
# 624 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 625 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait:
# 626 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I am saving your data.\n"
# 627 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Please wait.$"
# 628 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 629 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle:
# 630 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to record your latest\n"
# 631 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "battle on your FRONTIER PASS?$"
# 632 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 633 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments:
# 634 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Excuse me! Excuse me, please!\n"
# 635 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "May I get you to wait a few moments?$"
# 636 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 637 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo:
# 638 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "…Uh-huh? What?! …Whoa!\n"
# 639 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Understood, sir! Will do!$"
# 640 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 641 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow:
# 642 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Oh, my…\n"
# 643 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Sorry to keep you waiting!\p"
# 644 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I have a message from this facility's\n"
# 645 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "boss, the FACTORY HEAD.\p"
# 646 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "He says, “We're going to do it!\n"
# 647 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Come here right now!”$"
# 648 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 649 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead:
# 650 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The FACTORY HEAD is demanding you.\n"
# 651 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you prepared to face him?$"
# 652 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 653 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead:
# 654 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I'm terribly sorry, but I can't tell you\n"
# 655 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "anything about the FACTORY HEAD.$"
