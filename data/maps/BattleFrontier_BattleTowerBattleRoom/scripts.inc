# 1 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_MapScripts::
# 3 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerBattleRoom_OnFrame
# 4 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerBattleRoom_OnWarp
# 5 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_OnWarp:
# 8 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects
# 9 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.2byte 0
# 10 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects::
# 12 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 13 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible
# 14 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 15 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 16 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_OnFrame:
# 17 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom
# 18 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.2byte 0
# 19 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 20 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom::
# 21 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 22 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter
# 23 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 24 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 25 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter
# 26 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
# 27 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 28 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
# 29 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 30 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 31 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 32 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 33 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 34 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter::
# 35 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_setopponent
# 36 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	addobject LOCALID_TOWER_BATTLE_OPPONENT
# 37 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter
# 38 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 39 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 40 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 41 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 42 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 43 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 44 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent
# 45 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTower_EventScript_WarpToLobbyLost::
# 46 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 47 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 48 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 49 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 50 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 51 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 52 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent::
# 53 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 54 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_setbattlewon
# 55 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 56 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 57 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit
# 58 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 59 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	removeobject LOCALID_TOWER_BATTLE_OPPONENT
# 60 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 61 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter
# 62 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
# 63 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 64 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
# 65 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 66 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
# 67 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 68 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitfanfare
# 69 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special HealPlayerParty
# 70 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent::
# 71 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 72 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 73 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext
# 74 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 75 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent
# 76 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 77 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 78 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 79 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 80 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
# 81 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
# 82 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 83 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 84 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 85 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 86 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord::
# 87 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 88 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 89 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
# 90 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 91 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 92 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 93 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 94 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle::
# 95 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 96 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 97 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 98 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 99 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 100 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle
# 101 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 102 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 103 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle::
# 104 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 105 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 106 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 107 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge::
# 108 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 109 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 110 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 111 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge
# 112 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 113 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 114 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge::
# 115 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
# 116 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 117 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 118 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 119 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 120 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge
# 121 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 122 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 123 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge::
# 124 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	closemessage
# 125 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
# 126 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 127 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
# 128 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 129 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter
# 130 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 131 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon::
# 132 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 133 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 134 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 135 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 136 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 137 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 138 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge::
# 139 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
# 140 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 141 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_save CHALLENGE_STATUS_PAUSED
# 142 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playse SE_SAVE
# 143 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitse
# 144 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 145 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_reset
# 146 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 147 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 148 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent::
# 149 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 150 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 151 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent
# 152 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent
# 153 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent
# 154 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent
# 155 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent
# 156 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 6, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent
# 157 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 158 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent::
# 159 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent
# 160 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 161 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 162 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 163 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent::
# 164 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent
# 165 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 166 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 167 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 168 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent::
# 169 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent
# 170 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 171 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 172 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 173 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent::
# 174 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent
# 175 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 176 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 177 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 178 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent::
# 179 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent
# 180 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 181 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 182 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 183 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent::
# 184 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent
# 185 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 186 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 187 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 188 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_EventScript_IncrementWinStreak::
# 189 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_incrementstreak
# 190 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 191 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 192 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter::
# 193 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter
# 194 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 195 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, Common_Movement_WalkInPlaceLeft
# 196 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 197 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playse SE_PIN
# 198 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, Common_Movement_ExclamationMark
# 199 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 200 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, Common_Movement_Delay48
# 201 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 202 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay
# 203 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant
# 204 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 205 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit
# 206 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 207 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 208 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 209 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext::
# 210 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
# 211 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay, MSGBOX_DEFAULT
# 212 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 213 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden::
# 214 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden
# 215 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 216 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 217 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord
# 218 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 219 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 220 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
# 221 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
# 222 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 223 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 224 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
# 225 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 226 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord::
# 227 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 228 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 229 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
# 230 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 231 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 232 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
# 233 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 234 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel::
# 235 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 236 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	closemessage
# 237 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
# 238 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 239 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
# 240 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 241 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	addobject LOCALID_TOWER_BATTLE_OPPONENT
# 242 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter
# 243 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 244 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 245 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro
# 246 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
# 247 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
# 248 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 249 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
# 250 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel, MSGBOX_DEFAULT
# 251 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 252 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver::
# 253 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent, MSGBOX_DEFAULT
# 254 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 255 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver
# 256 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 257 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 258 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver::
# 259 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 260 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getsymbols
# 261 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 262 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized, MSGBOX_DEFAULT
# 263 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 264 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol
# 265 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 266 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitfanfare
# 267 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_givesymbol
# 268 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime, MSGBOX_DEFAULT
# 269 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 270 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 271 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro::
# 272 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 273 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
# 274 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack, MSGBOX_DEFAULT
# 275 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 276 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold::
# 277 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe, MSGBOX_DEFAULT
# 278 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 279 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold
# 280 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 281 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 282 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold::
# 283 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 284 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getsymbols
# 285 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 286 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease, MSGBOX_DEFAULT
# 287 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 288 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine
# 289 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 290 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitfanfare
# 291 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_givesymbol
# 292 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain, MSGBOX_DEFAULT
# 293 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 294 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 295 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle::
# 296 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	closemessage
# 297 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 298 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 299 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special HealPlayerParty
# 300 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_TOWER
# 301 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 302 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 303 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 304 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
# 305 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_0x8004, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle
# 306 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_restorehelditems
# 307 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special HealPlayerParty
# 308 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_resetsketch
# 309 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle::
# 310 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_setinterviewdata
# 311 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 312 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 313 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 314 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_EventScript_SetBrainObjectGfx::
# 315 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_setbrainobj
# 316 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 317 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 318 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter:
# 319 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 320 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 321 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 322 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 323 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 324 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 325 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant:
# 326 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_down
# 327 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 328 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 329 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle:
# 330 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 331 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 332 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 333 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter:
# 334 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 335 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 336 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 337 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 338 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_left
# 339 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 340 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 341 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit:
# 342 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 343 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 344 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 345 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 347 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 348 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer:
# 349 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 350 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 351 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 352 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 353 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 354 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 355 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos:
# 356 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 357 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 358 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 359 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 360 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 361 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 362 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 363 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible:
# 364 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	set_invisible
# 365 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 366 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 367 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter:
# 368 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	set_visible
# 369 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 370 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 371 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 372 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 373 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_8
# 374 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 375 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 376 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit:
# 377 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 378 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 379 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 380 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	set_invisible
# 381 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 382 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 383 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay:
# 384 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 385 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 386 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 387 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 388 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 389 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 390 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant:
# 391 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 392 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 393 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 394 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 395 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 396 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_in_place_right
# 397 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 398 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 399 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter:
# 400 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 401 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 402 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 403 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 404 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_left
# 405 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 406 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 407 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby::
# 408 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 409 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles
# 410 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis
# 411 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis
# 412 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 6, 6
# 413 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 414 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 415 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 416 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles::
# 417 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 10, 6
# 418 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 419 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 420 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 421 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis::
# 422 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 14, 6
# 423 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 424 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 425 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 426 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis::
# 427 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_closelink
# 428 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 18, 6
# 429 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 430 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 431 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 432 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge::
# 433 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 434 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 435 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 436 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 437 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth:
# 438 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "We will restore your POKéMON to\n"
# 439 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "full health.$"
# 440 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 441 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
@ Unused
# 442 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyForOpponent:
# 443 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. {STR_VAR_1}.\n"
# 444 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 445 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 446 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent:
# 447 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 2.\n"
# 448 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 449 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 450 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent:
# 451 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 3.\n"
# 452 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 453 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 454 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent:
# 455 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 4.\n"
# 456 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 457 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 458 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent:
# 459 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 5.\n"
# 460 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 461 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 462 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent:
# 463 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 6.\n"
# 464 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 465 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 466 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent:
# 467 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 7.\n"
# 468 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 469 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 470 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle:
# 471 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Record your battle on your\n"
# 472 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "FRONTIER PASS?$"
# 473 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 474 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass:
# 475 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "{PLAYER}'s battle was recorded\n"
# 476 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "on the FRONTIER PASS.$"
# 477 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 478 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame:
# 479 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Would you like to save and\n"
# 480 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "quit the game?$"
# 481 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 482 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait:
# 483 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Saving your battle data.\n"
# 484 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Please wait.$"
# 485 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 486 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge:
# 487 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Would you like to cancel your BATTLE\n"
# 488 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ROOM challenge?$"
# 489 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 490 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved::
# 491 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "There was an error of some sort.\n"
# 492 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your record could not be saved.$"
# 493 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 494 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay:
# 495 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Excuse me, but…\p"
# 496 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Our leader, the SALON MAIDEN, is on\n"
# 497 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "her way here in hopes of battling you.\p"
# 498 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "She should be arriving very shortly.$"
# 499 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 500 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden:
# 501 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing the SALON MAIDEN.\n"
# 502 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 503 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 504 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel:
# 505 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Greetings…\n"
# 506 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "My name is ANABEL.\p"
# 507 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I am the SALON MAIDEN, and I am in\n"
# 508 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "charge of running the BATTLE TOWER…\p"
# 509 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I have heard several rumors\n"
# 510 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "about you…\p"
# 511 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "In all honesty, what I have heard does\n"
# 512 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "not seem attractive in any way…\p"
# 513 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "The reason I've come to see you…\n"
# 514 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Well, there is but one reason…$"
# 515 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 516 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent:
# 517 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Let me see your talent in\n"
# 518 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "its entirety…$"
# 519 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 520 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized:
# 521 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ANABEL: Fufufu, nicely done…\p"
# 522 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your FRONTIER PASS, please…\n"
# 523 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your talent shall be recognized.$"
# 524 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 525 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol:
# 526 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "The Ability Symbol was embossed on\n"
# 527 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 528 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 529 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime:
# 530 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "… … … … … …\p"
# 531 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You have confidence in your POKéMON\n"
# 532 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "battling talent, don't you?\p"
# 533 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I urge you to keep battling and\n"
# 534 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "keep on winning.\p"
# 535 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I will be waiting for you.\n"
# 536 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Until the next time we meet…$"
# 537 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 538 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack:
# 539 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ANABEL: You really did come back to\n"
# 540 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "see me…\p"
# 541 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "… … … … … …\p"
# 542 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You've won straight matches to see me…\n"
# 543 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I won't have to hold back against you…\p"
# 544 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "It's been too long now…\p"
# 545 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Too long since I've been able to battle\n"
# 546 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "without thinking about anything…$"
# 547 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 548 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe:
# 549 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Let's begin, shall we?$"
# 550 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 551 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease:
# 552 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ANABEL: Fufu, congratulations…\n"
# 553 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your FRONTIER PASS, please…$"
# 554 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 555 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine:
# 556 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "The Ability Symbol took on\n"
# 557 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 558 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 559 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain:
# 560 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "That was fun…\p"
# 561 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I have never had a POKéMON battle\n"
# 562 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "so enjoyable before…\p"
# 563 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I wish I could battle with you again…$"
