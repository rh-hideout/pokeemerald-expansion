# 1 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 1
# 3 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT_1, 2
# 4 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT_2, 3
# 5 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 6 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_MapScripts::
# 7 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerBattleRoom_OnFrame
# 8 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerBattleRoom_OnWarp
# 9 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.byte 0
# 10 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 11 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_OnWarp:
# 12 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects
# 13 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.2byte 0
# 14 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 15 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects::
# 16 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 17 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible
# 18 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 19 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 20 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_OnFrame:
# 21 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom
# 22 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.2byte 0
# 23 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 24 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom::
# 25 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 26 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter
# 27 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 28 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 29 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter
# 30 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
# 31 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 32 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
# 33 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 34 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 35 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 36 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 37 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 38 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter::
# 39 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_setopponent
# 40 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 41 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter
# 42 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 43 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 44 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 45 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 46 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 47 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 48 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent
# 49 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTower_EventScript_WarpToLobbyLost::
# 50 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 51 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 52 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 53 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 54 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 55 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 56 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent::
# 57 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 58 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_setbattlewon
# 59 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 60 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 61 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit
# 62 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 63 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 64 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 65 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter
# 66 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
# 67 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 68 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
# 69 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 70 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
# 71 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 72 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitfanfare
# 73 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special HealPlayerParty
# 74 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent::
# 75 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 76 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 77 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext
# 78 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 79 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent
# 80 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 81 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 82 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 83 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 84 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
# 85 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
# 86 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 87 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 88 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 89 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 90 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord::
# 91 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 92 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 93 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
# 94 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 95 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 96 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 97 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 98 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle::
# 99 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 100 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 101 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 102 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 103 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 104 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle
# 105 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 106 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 107 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle::
# 108 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 109 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 110 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 111 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge::
# 112 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 113 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 114 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 115 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge
# 116 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 117 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 118 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge::
# 119 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
# 120 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 121 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 122 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 123 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 124 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge
# 125 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 126 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 127 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge::
# 128 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	closemessage
# 129 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
# 130 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 131 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
# 132 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 133 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter
# 134 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 135 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon::
# 136 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 137 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 138 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 139 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 140 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 141 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 142 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge::
# 143 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
# 144 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 145 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_save CHALLENGE_STATUS_PAUSED
# 146 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playse SE_SAVE
# 147 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitse
# 148 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 149 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_reset
# 150 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 151 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 152 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent::
# 153 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 154 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 155 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent
# 156 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent
# 157 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent
# 158 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent
# 159 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent
# 160 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 6, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent
# 161 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 162 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent::
# 163 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent
# 164 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 165 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 166 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 167 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent::
# 168 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent
# 169 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 170 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 171 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 172 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent::
# 173 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent
# 174 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 175 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 176 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 177 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent::
# 178 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent
# 179 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 180 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 181 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 182 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent::
# 183 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent
# 184 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 185 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 186 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 187 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent::
# 188 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent
# 189 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 190 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 191 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 192 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_EventScript_IncrementWinStreak::
# 193 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_incrementstreak
# 194 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 195 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 196 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter::
# 197 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter
# 198 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 199 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, Common_Movement_WalkInPlaceLeft
# 200 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 201 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playse SE_PIN
# 202 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, Common_Movement_ExclamationMark
# 203 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 204 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, Common_Movement_Delay48
# 205 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 206 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay
# 207 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant
# 208 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 209 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit
# 210 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 211 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 212 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 213 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext::
# 214 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
# 215 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay, MSGBOX_DEFAULT
# 216 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 217 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden::
# 218 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden
# 219 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 220 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 221 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord
# 222 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 223 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 224 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
# 225 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
# 226 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 227 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 228 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
# 229 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 230 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord::
# 231 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 232 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 233 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
# 234 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 235 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 236 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
# 237 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 238 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel::
# 239 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 240 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	closemessage
# 241 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
# 242 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 243 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
# 244 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 245 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 246 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter
# 247 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 248 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 249 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro
# 250 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
# 251 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
# 252 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 253 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
# 254 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel, MSGBOX_DEFAULT
# 255 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 256 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver::
# 257 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent, MSGBOX_DEFAULT
# 258 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 259 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver
# 260 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 261 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 262 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver::
# 263 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 264 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getsymbols
# 265 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 266 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized, MSGBOX_DEFAULT
# 267 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 268 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol
# 269 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 270 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitfanfare
# 271 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_givesymbol
# 272 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime, MSGBOX_DEFAULT
# 273 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 274 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 275 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro::
# 276 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 277 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
# 278 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack, MSGBOX_DEFAULT
# 279 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 280 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold::
# 281 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe, MSGBOX_DEFAULT
# 282 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 283 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold
# 284 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 285 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 286 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold::
# 287 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 288 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getsymbols
# 289 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 290 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease, MSGBOX_DEFAULT
# 291 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 292 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine
# 293 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 294 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitfanfare
# 295 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_givesymbol
# 296 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain, MSGBOX_DEFAULT
# 297 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 298 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 299 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle::
# 300 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	closemessage
# 301 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 302 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 303 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special HealPlayerParty
# 304 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_TOWER
# 305 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 306 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 307 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 308 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
# 309 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_0x8004, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle
# 310 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_restorehelditems
# 311 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special HealPlayerParty
# 312 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_resetsketch
# 313 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle::
# 314 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_setinterviewdata
# 315 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 316 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 317 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 318 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_EventScript_SetBrainObjectGfx::
# 319 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_setbrainobj
# 320 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 321 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 322 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter:
# 323 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 324 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 325 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 326 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 327 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 328 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 329 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant:
# 330 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_down
# 331 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 332 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 333 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle:
# 334 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 335 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 336 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 337 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter:
# 338 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 339 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 340 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 341 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 342 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_left
# 343 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 344 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 345 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit:
# 346 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 347 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 348 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 349 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 350 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 351 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 352 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer:
# 353 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 354 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 355 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 356 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 357 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 358 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 359 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos:
# 360 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 361 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 362 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 363 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 364 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 365 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 366 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 367 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible:
# 368 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	set_invisible
# 369 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 370 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 371 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter:
# 372 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	set_visible
# 373 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 374 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 375 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 376 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 377 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_8
# 378 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 379 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 380 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit:
# 381 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 382 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 383 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 384 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	set_invisible
# 385 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 386 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 387 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay:
# 388 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 389 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 390 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 391 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 392 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 393 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 394 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant:
# 395 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 396 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 397 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 398 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 399 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 400 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_in_place_right
# 401 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 402 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 403 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter:
# 404 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 405 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 406 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 407 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 408 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_left
# 409 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 410 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 411 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby::
# 412 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 413 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles
# 414 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis
# 415 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis
# 416 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 6, 6
# 417 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 418 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 419 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 420 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles::
# 421 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 10, 6
# 422 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 423 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 424 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 425 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis::
# 426 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 14, 6
# 427 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 428 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 429 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 430 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis::
# 431 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_closelink
# 432 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 18, 6
# 433 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 434 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 435 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 436 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge::
# 437 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 438 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 439 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 440 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 441 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth:
# 442 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "We will restore your POKéMON to\n"
# 443 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "full health.$"
# 444 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 445 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
@ Unused
# 446 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyForOpponent:
# 447 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. {STR_VAR_1}.\n"
# 448 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 449 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 450 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent:
# 451 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 2.\n"
# 452 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 453 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 454 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent:
# 455 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 3.\n"
# 456 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 457 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 458 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent:
# 459 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 4.\n"
# 460 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 461 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 462 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent:
# 463 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 5.\n"
# 464 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 465 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 466 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent:
# 467 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 6.\n"
# 468 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 469 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 470 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent:
# 471 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 7.\n"
# 472 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 473 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 474 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle:
# 475 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Record your battle on your\n"
# 476 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "FRONTIER PASS?$"
# 477 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 478 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass:
# 479 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "{PLAYER}'s battle was recorded\n"
# 480 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "on the FRONTIER PASS.$"
# 481 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 482 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame:
# 483 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Would you like to save and\n"
# 484 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "quit the game?$"
# 485 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 486 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait:
# 487 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Saving your battle data.\n"
# 488 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Please wait.$"
# 489 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 490 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge:
# 491 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Would you like to cancel your BATTLE\n"
# 492 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ROOM challenge?$"
# 493 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 494 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved::
# 495 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "There was an error of some sort.\n"
# 496 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your record could not be saved.$"
# 497 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 498 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay:
# 499 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Excuse me, but…\p"
# 500 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Our leader, the SALON MAIDEN, is on\n"
# 501 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "her way here in hopes of battling you.\p"
# 502 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "She should be arriving very shortly.$"
# 503 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 504 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden:
# 505 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing the SALON MAIDEN.\n"
# 506 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 507 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 508 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel:
# 509 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Greetings…\n"
# 510 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "My name is ANABEL.\p"
# 511 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I am the SALON MAIDEN, and I am in\n"
# 512 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "charge of running the BATTLE TOWER…\p"
# 513 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I have heard several rumors\n"
# 514 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "about you…\p"
# 515 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "In all honesty, what I have heard does\n"
# 516 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "not seem attractive in any way…\p"
# 517 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "The reason I've come to see you…\n"
# 518 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Well, there is but one reason…$"
# 519 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 520 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent:
# 521 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Let me see your talent in\n"
# 522 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "its entirety…$"
# 523 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 524 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized:
# 525 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ANABEL: Fufufu, nicely done…\p"
# 526 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your FRONTIER PASS, please…\n"
# 527 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your talent shall be recognized.$"
# 528 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 529 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol:
# 530 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "The Ability Symbol was embossed on\n"
# 531 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 532 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 533 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime:
# 534 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "… … … … … …\p"
# 535 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You have confidence in your POKéMON\n"
# 536 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "battling talent, don't you?\p"
# 537 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I urge you to keep battling and\n"
# 538 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "keep on winning.\p"
# 539 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I will be waiting for you.\n"
# 540 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Until the next time we meet…$"
# 541 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 542 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack:
# 543 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ANABEL: You really did come back to\n"
# 544 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "see me…\p"
# 545 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "… … … … … …\p"
# 546 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You've won straight matches to see me…\n"
# 547 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I won't have to hold back against you…\p"
# 548 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "It's been too long now…\p"
# 549 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Too long since I've been able to battle\n"
# 550 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "without thinking about anything…$"
# 551 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 552 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe:
# 553 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Let's begin, shall we?$"
# 554 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 555 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease:
# 556 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ANABEL: Fufu, congratulations…\n"
# 557 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your FRONTIER PASS, please…$"
# 558 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 559 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine:
# 560 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "The Ability Symbol took on\n"
# 561 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 562 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 563 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain:
# 564 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "That was fun…\p"
# 565 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I have never had a POKéMON battle\n"
# 566 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "so enjoyable before…\p"
# 567 "data//maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I wish I could battle with you again…$"
