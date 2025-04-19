# 1 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 1
# 3 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 2
# 4 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT, 3
# 5 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
.set LOCALID_DUSCLOPS, 4
# 6 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
.set LOCALID_AZURILL, 5
# 7 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 8 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_MapScripts::
# 9 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePalaceBattleRoom_OnTransition
# 10 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnFrame
# 11 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnWarp
# 12 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.byte 0
# 13 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 14 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 15 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_0
# 16 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	@ The opponent is represented by LOCALID_OPPONENT, which has the gfx id VAR_OBJ_GFX_ID_1
# 17 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 18 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnTransition:
# 19 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_settrainers
# 20 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
# 21 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 22 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 23 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx::
# 24 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	checkplayergender
# 25 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale
# 26 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale
# 27 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 28 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 29 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
@ The opponent's gfx are set to the players by default
# 30 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale::
# 31 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 32 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 33 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 34 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 35 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale::
# 36 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 37 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 38 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 39 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 40 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnFrame:
# 41 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom
# 42 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.2byte 0
# 43 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 44 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom::
# 45 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 46 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 47 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge
# 48 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge
# 49 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 50 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 51 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 52 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 53 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 54 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 55 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge::
# 56 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom
# 57 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 58 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter::
# 59 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	tower_setopponent
# 60 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 61 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter
# 62 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 63 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_getopponentintro
# 64 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 65 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 66 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 67 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 68 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent
# 69 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost::
# 70 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 71 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby
# 72 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 73 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent::
# 74 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 75 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 76 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 77 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 78 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 79 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 80 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit
# 81 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 82 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 83 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 84 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 85 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 86 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons, MSGBOX_DEFAULT
# 87 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special LoadPlayerParty
# 88 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special SavePlayerParty
# 89 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 90 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 91 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 92 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 93 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent::
# 94 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 95 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 96 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext
# 97 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 98 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent
# 99 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent
# 100 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent
# 101 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent
# 102 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent
# 103 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent
# 104 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 105 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 106 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 107 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 108 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
# 109 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
# 110 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 111 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 112 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 113 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 114 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord::
# 115 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 116 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 117 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
# 118 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 119 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 120 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 121 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 122 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle::
# 123 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch
# 124 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 125 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 126 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 127 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 128 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle
# 129 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 130 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 131 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle::
# 132 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 133 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 134 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 135 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge::
# 136 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 137 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 138 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 139 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge
# 140 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 141 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 142 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge::
# 143 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge
# 144 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 145 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 146 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 147 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 148 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 149 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 150 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 151 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge::
# 152 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 153 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 154 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 155 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter
# 156 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 157 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon::
# 158 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 159 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby
# 160 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 161 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge::
# 162 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SavingData
# 163 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 164 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_save CHALLENGE_STATUS_PAUSED
# 165 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playse SE_SAVE
# 166 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitse
# 167 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 168 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_reset
# 169 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 170 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 171 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext::
# 172 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 173 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven, MSGBOX_DEFAULT
# 174 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 175 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven::
# 176 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven
# 177 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 178 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 179 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord
# 180 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 181 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 182 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
# 183 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
# 184 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 185 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 186 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 187 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 188 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord::
# 189 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 190 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 191 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
# 192 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 193 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 194 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 195 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 196 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser::
# 197 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 198 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser, MSGBOX_DEFAULT
# 199 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 200 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 201 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 202 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_OPPONENT, 15, 1
# 203 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 204 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	hideobjectat LOCALID_OPPONENT, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 205 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxy LOCALID_OPPONENT, 13, 1
# 206 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_OPPONENT, 13, 1
# 207 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter
# 208 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter
# 209 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter
# 210 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 211 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 212 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold
# 213 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
# 214 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
# 215 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 216 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
# 217 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro, MSGBOX_DEFAULT
# 218 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 219 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver::
# 220 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons, MSGBOX_DEFAULT
# 221 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 222 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver
# 223 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 224 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 225 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver::
# 226 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_incrementstreak
# 227 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getsymbols
# 228 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 229 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle, MSGBOX_DEFAULT
# 230 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 231 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 232 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass, MSGBOX_DEFAULT
# 233 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 234 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol
# 235 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 236 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 237 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_givesymbol
# 238 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, Common_Movement_WalkInPlaceLeft
# 239 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 240 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 241 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
# 242 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 243 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime, MSGBOX_DEFAULT
# 244 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 245 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 246 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold::
# 247 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 248 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
# 249 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack, MSGBOX_DEFAULT
# 250 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 251 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold::
# 252 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah, MSGBOX_DEFAULT
# 253 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 254 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold
# 255 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 256 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 257 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold::
# 258 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_incrementstreak
# 259 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getsymbols
# 260 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 261 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable, MSGBOX_DEFAULT
# 262 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 263 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 264 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass, MSGBOX_DEFAULT
# 265 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 266 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine
# 267 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 268 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 269 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_givesymbol
# 270 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, Common_Movement_WalkInPlaceLeft
# 271 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 272 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 273 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
# 274 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 275 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain, MSGBOX_DEFAULT
# 276 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 277 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 278 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle::
# 279 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 280 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 281 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 282 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 283 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PALACE
# 284 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 285 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 286 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 287 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_restorehelditems
# 288 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 289 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_resetsketch
# 290 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 291 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 292 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnWarp:
# 293 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects
# 294 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.2byte 0
# 295 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 296 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects::
# 297 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 298 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
# 299 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 300 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 301 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 302 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 303 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 304 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 305 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 306 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent::
# 307 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
# 308 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 309 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 310 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 311 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent::
# 312 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
# 313 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 314 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 315 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 316 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent::
# 317 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent
# 318 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 319 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 320 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 321 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent::
# 322 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent
# 323 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 324 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 325 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 326 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent::
# 327 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent
# 328 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 329 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 330 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 331 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent::
# 332 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent
# 333 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 334 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 335 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 336 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible:
# 337 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_invisible
# 338 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 339 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 340 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom:
# 341 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 342 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 343 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 344 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 345 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 346 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight:
# 347 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_right
# 348 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 349 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 350 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp:
# 351 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_up
# 352 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 353 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 354 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge:
# 355 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 356 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 357 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 358 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 359 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 360 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 361 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 362 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter:
# 363 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 364 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 365 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 366 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 367 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 368 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 369 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 370 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit:
# 371 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 372 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 373 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 374 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 375 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 376 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 377 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown:
# 378 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_down
# 379 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 380 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 381 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter1:
# 382 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 383 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 384 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 385 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 386 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 387 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 388 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter2:
# 389 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 390 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 391 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 392 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 393 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter3:
# 394 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 395 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 396 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 397 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 398 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 399 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 400 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby::
# 401 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 402 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles
# 403 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 5, 7
# 404 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 405 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 406 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 407 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles::
# 408 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 19, 7
# 409 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 410 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 411 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 412 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter:
# 413 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 414 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 415 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 416 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 417 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_right
# 418 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 419 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 420 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 421 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 422 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter:
# 423 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 424 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 425 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_right
# 426 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 427 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 428 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 429 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 430 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 431 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 432 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 433 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 434 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 435 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter:
# 436 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 437 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 438 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 439 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 440 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 441 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 442 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 443 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 444 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 445 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 446 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 447 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 448 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 449 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 450 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 451 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons:
# 452 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Excellent…\n"
# 453 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let me restore your POKéMON.$"
# 454 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 455 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent:
# 456 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 2nd opponent is next.\n"
# 457 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 458 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 459 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent:
# 460 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 3rd opponent is next.\n"
# 461 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 462 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 463 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent:
# 464 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 4th opponent is next.\n"
# 465 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 466 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 467 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent:
# 468 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 5th opponent is next.\n"
# 469 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 470 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 471 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent:
# 472 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 6th opponent is next.\n"
# 473 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 474 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 475 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent:
# 476 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 7th opponent is next.\n"
# 477 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 478 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 479 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame:
# 480 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Would you like to save and quit\n"
# 481 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "the game?$"
# 482 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 483 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge:
# 484 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you wish to quit your challenge?$"
# 485 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 486 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SavingData:
# 487 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Saving the data.\n"
# 488 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Have patience…$"
# 489 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 490 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch:
# 491 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you wish to record your latest\n"
# 492 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "match on your FRONTIER PASS?$"
# 493 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 494 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven:
# 495 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "And now…\p"
# 496 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "By winning consistently, you have\n"
# 497 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "earned the privilege of challenging\l"
# 498 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "our master, the PALACE MAVEN…$"
# 499 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 500 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven:
# 501 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "I shall send for the PALACE MAVEN.\n"
# 502 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 503 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 504 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser:
# 505 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let great fanfare announce the arrival\n"
# 506 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "of the PALACE MAVEN, SPENSER!$"
# 507 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 508 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro:
# 509 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: My physical being is with\n"
# 510 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "POKéMON always!\p"
# 511 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My heart beats as one with\n"
# 512 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "POKéMON always!\p"
# 513 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Young one of a TRAINER!\n"
# 514 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you believe in your POKéMON?\p"
# 515 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Can you believe them through\n"
# 516 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "and through?\p"
# 517 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "If your bonds of trust are frail,\n"
# 518 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "you will never beat my brethren!$"
# 519 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 520 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons:
# 521 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The bond you share with your POKéMON!\n"
# 522 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Prove it to me here!$"
# 523 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 524 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle:
# 525 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\p"
# 526 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Hah, you never fell for my bluster!\n"
# 527 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Sorry for trying that stunt!\p"
# 528 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 529 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Bring me the thing!$"
# 530 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 531 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass:
# 532 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My, my, if only you could maintain that\n"
# 533 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "facade of distinguished authority…\p"
# 534 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 535 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS!$"
# 536 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 537 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol:
# 538 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The Spirits Symbol was embossed on\n"
# 539 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 540 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 541 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime:
# 542 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Your POKéMON's eyes are \n"
# 543 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "truly clear and unclouded.\p"
# 544 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "I will eagerly await the next\n"
# 545 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "opportunity to see you.$"
# 546 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 547 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack:
# 548 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\n"
# 549 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "You've battled your way up again?\p"
# 550 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "You must have developed a truly\n"
# 551 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "formidable bond with your POKéMON.\p"
# 552 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "So be it!\p"
# 553 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "This time, I won't bluster or hold back.\n"
# 554 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "This time, there's no fooling around.\p"
# 555 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Ready now?\n"
# 556 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Prepare to lose!$"
# 557 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 558 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah:
# 559 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "… … …Kaaah!$"
# 560 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 561 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable:
# 562 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Well, that was some display!\n"
# 563 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Even fully unleashed, my brethren\l"
# 564 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "could not overpower you.\p"
# 565 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Your team spirit is truly admirable!\p"
# 566 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 567 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Bring me that thing, will you?$"
# 568 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 569 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass:
# 570 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My, my, if only you could maintain\n"
# 571 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "a certain level of decorum…\p"
# 572 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Gaaah, here!\n"
# 573 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Hurry with that FRONTIER PASS, you!$"
# 574 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 575 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine:
# 576 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The Spirits Symbol took on\n"
# 577 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 578 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 579 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain:
# 580 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\p"
# 581 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Come see me time and again!\n"
# 582 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My brethren and I will be waiting!$"
