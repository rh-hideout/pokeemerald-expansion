# 1 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
@ On this map the player will automatically walk into the room, but the camera is supposed to remain still.
# 3 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
@ To do this GF sets the player (LOCALID_PLAYER) invisible and creates a fake player object (LOCALID_PALACE_BATTLE_PLAYER).
# 4 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
@ The graphics of this fake player object are represented with VAR_OBJ_GFX_ID_1.
# 5 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
@ The graphics of the opponent are represented with VAR_OBJ_GFX_ID_0, which will ultimately be set by tower_setopponent.
# 6 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 7 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_MapScripts::
# 8 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePalaceBattleRoom_OnTransition
# 9 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnFrame
# 10 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnWarp
# 11 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.byte 0
# 12 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 13 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnTransition:
# 14 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_settrainers
# 15 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
# 16 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 17 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 18 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx::
# 19 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	checkplayergender
# 20 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale
# 21 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale
# 22 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 23 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 24 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
@ The opponent's gfx are set to the players by default
# 25 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale::
# 26 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 27 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 28 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 29 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 30 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale::
# 31 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 32 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 33 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 34 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 35 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnFrame:
# 36 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom
# 37 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.2byte 0
# 38 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 39 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom::
# 40 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	showobjectat LOCALID_PALACE_BATTLE_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 41 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 42 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge
# 43 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge
# 44 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 45 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 46 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 47 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 48 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 49 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 50 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge::
# 51 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom
# 52 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 53 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter::
# 54 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	tower_setopponent
# 55 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addobject LOCALID_PALACE_BATTLE_OPPONENT
# 56 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter
# 57 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 58 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_getopponentintro
# 59 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 60 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 61 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 62 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 63 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent
# 64 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost::
# 65 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 66 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby
# 67 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 68 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent::
# 69 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 70 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 71 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 72 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 73 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 74 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 75 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit
# 76 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 77 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	removeobject LOCALID_PALACE_BATTLE_OPPONENT
# 78 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 79 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 80 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 81 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons, MSGBOX_DEFAULT
# 82 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special LoadPlayerParty
# 83 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special SavePlayerParty
# 84 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 85 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 86 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 87 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 88 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent::
# 89 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 90 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 91 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext
# 92 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 93 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent
# 94 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent
# 95 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent
# 96 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent
# 97 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent
# 98 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent
# 99 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 100 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 101 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 102 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 103 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
# 104 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
# 105 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 106 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 107 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 108 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 109 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord::
# 110 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 111 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 112 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
# 113 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 114 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 115 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 116 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 117 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle::
# 118 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch
# 119 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 120 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 121 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 122 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 123 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle
# 124 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 125 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 126 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle::
# 127 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 128 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 129 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 130 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge::
# 131 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 132 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 133 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 134 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge
# 135 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 136 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 137 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge::
# 138 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge
# 139 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 140 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 141 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 142 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 143 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 144 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 145 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 146 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge::
# 147 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 148 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 149 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 150 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter
# 151 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 152 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon::
# 153 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 154 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby
# 155 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 156 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge::
# 157 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SavingData
# 158 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 159 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_save CHALLENGE_STATUS_PAUSED
# 160 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playse SE_SAVE
# 161 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitse
# 162 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 163 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_reset
# 164 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 165 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 166 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext::
# 167 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 168 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven, MSGBOX_DEFAULT
# 169 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 170 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven::
# 171 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven
# 172 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 173 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 174 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord
# 175 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 176 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 177 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
# 178 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
# 179 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 180 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 181 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 182 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 183 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord::
# 184 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 185 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 186 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
# 187 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 188 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 189 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 190 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 191 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser::
# 192 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 193 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser, MSGBOX_DEFAULT
# 194 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 195 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 196 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 197 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_PALACE_BATTLE_OPPONENT, 15, 1
# 198 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addobject LOCALID_PALACE_BATTLE_OPPONENT
# 199 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	hideobjectat LOCALID_PALACE_BATTLE_OPPONENT, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 200 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxy LOCALID_PALACE_BATTLE_OPPONENT, 13, 1
# 201 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_PALACE_BATTLE_OPPONENT, 13, 1
# 202 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter
# 203 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter
# 204 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter
# 205 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 206 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 207 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold
# 208 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
# 209 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
# 210 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 211 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
# 212 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro, MSGBOX_DEFAULT
# 213 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 214 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver::
# 215 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons, MSGBOX_DEFAULT
# 216 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 217 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver
# 218 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 219 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 220 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver::
# 221 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_incrementstreak
# 222 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getsymbols
# 223 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 224 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle, MSGBOX_DEFAULT
# 225 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 226 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 227 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass, MSGBOX_DEFAULT
# 228 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 229 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol
# 230 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 231 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 232 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_givesymbol
# 233 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_OPPONENT, Common_Movement_WalkInPlaceLeft
# 234 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 235 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 236 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
# 237 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 238 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime, MSGBOX_DEFAULT
# 239 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 240 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 241 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold::
# 242 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 243 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
# 244 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack, MSGBOX_DEFAULT
# 245 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 246 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold::
# 247 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah, MSGBOX_DEFAULT
# 248 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 249 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold
# 250 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 251 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 252 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold::
# 253 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_incrementstreak
# 254 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getsymbols
# 255 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 256 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable, MSGBOX_DEFAULT
# 257 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 258 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 259 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass, MSGBOX_DEFAULT
# 260 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 261 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine
# 262 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 263 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 264 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_givesymbol
# 265 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_OPPONENT, Common_Movement_WalkInPlaceLeft
# 266 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 267 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 268 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
# 269 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 270 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain, MSGBOX_DEFAULT
# 271 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 272 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 273 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle::
# 274 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 275 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 276 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 277 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 278 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PALACE
# 279 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 280 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 281 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 282 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_restorehelditems
# 283 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 284 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_resetsketch
# 285 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 286 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 287 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnWarp:
# 288 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects
# 289 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.2byte 0
# 290 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 291 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects::
# 292 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	hideobjectat LOCALID_PALACE_BATTLE_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 293 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
# 294 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 295 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 296 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	removeobject LOCALID_PALACE_BATTLE_OPPONENT
# 297 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 298 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 299 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 300 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 301 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent::
# 302 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
# 303 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 304 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 305 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 306 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent::
# 307 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
# 308 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 309 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 310 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 311 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent::
# 312 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent
# 313 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 314 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 315 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 316 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent::
# 317 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent
# 318 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 319 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 320 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 321 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent::
# 322 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent
# 323 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 324 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 325 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 326 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent::
# 327 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent
# 328 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 329 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 330 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 331 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible:
# 332 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_invisible
# 333 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 334 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 335 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom:
# 336 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 337 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 338 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 339 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 340 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 341 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight:
# 342 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_right
# 343 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 344 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 345 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp:
# 346 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_up
# 347 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 348 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 349 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge:
# 350 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 351 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 352 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 353 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 354 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 355 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 356 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 357 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter:
# 358 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 359 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 360 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 361 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 362 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 363 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 364 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 365 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit:
# 366 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 367 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 368 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 369 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 370 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 371 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 372 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown:
# 373 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_down
# 374 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 375 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 376 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter1:
# 377 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 378 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 379 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 380 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 381 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 382 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 383 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter2:
# 384 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 385 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 386 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 387 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 388 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter3:
# 389 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 390 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 391 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 392 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 393 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 394 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 395 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby::
# 396 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 397 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles
# 398 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 5, 7
# 399 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 400 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 401 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 402 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles::
# 403 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 19, 7
# 404 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 405 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 406 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 407 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter:
# 408 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 409 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 410 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 411 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 412 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_right
# 413 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 414 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 415 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 416 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 417 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter:
# 418 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 419 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 420 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_right
# 421 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 422 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 423 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 424 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 425 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 426 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 427 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 428 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 429 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 430 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter:
# 431 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 432 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 433 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 434 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 435 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 436 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 437 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 438 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 439 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 440 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 441 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 442 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 443 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 444 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 445 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 446 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons:
# 447 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Excellent…\n"
# 448 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let me restore your POKéMON.$"
# 449 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 450 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent:
# 451 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 2nd opponent is next.\n"
# 452 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 453 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 454 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent:
# 455 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 3rd opponent is next.\n"
# 456 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 457 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 458 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent:
# 459 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 4th opponent is next.\n"
# 460 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 461 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 462 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent:
# 463 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 5th opponent is next.\n"
# 464 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 465 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 466 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent:
# 467 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 6th opponent is next.\n"
# 468 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 469 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 470 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent:
# 471 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 7th opponent is next.\n"
# 472 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 473 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 474 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame:
# 475 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Would you like to save and quit\n"
# 476 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "the game?$"
# 477 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 478 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge:
# 479 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you wish to quit your challenge?$"
# 480 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 481 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SavingData:
# 482 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Saving the data.\n"
# 483 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Have patience…$"
# 484 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 485 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch:
# 486 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you wish to record your latest\n"
# 487 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "match on your FRONTIER PASS?$"
# 488 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 489 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven:
# 490 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "And now…\p"
# 491 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "By winning consistently, you have\n"
# 492 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "earned the privilege of challenging\l"
# 493 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "our master, the PALACE MAVEN…$"
# 494 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 495 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven:
# 496 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "I shall send for the PALACE MAVEN.\n"
# 497 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 498 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 499 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser:
# 500 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let great fanfare announce the arrival\n"
# 501 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "of the PALACE MAVEN, SPENSER!$"
# 502 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 503 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro:
# 504 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: My physical being is with\n"
# 505 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "POKéMON always!\p"
# 506 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My heart beats as one with\n"
# 507 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "POKéMON always!\p"
# 508 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Young one of a TRAINER!\n"
# 509 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you believe in your POKéMON?\p"
# 510 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Can you believe them through\n"
# 511 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "and through?\p"
# 512 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "If your bonds of trust are frail,\n"
# 513 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "you will never beat my brethren!$"
# 514 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 515 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons:
# 516 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The bond you share with your POKéMON!\n"
# 517 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Prove it to me here!$"
# 518 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 519 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle:
# 520 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\p"
# 521 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Hah, you never fell for my bluster!\n"
# 522 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Sorry for trying that stunt!\p"
# 523 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 524 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Bring me the thing!$"
# 525 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 526 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass:
# 527 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My, my, if only you could maintain that\n"
# 528 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "facade of distinguished authority…\p"
# 529 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 530 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS!$"
# 531 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 532 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol:
# 533 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The Spirits Symbol was embossed on\n"
# 534 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 535 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 536 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime:
# 537 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Your POKéMON's eyes are \n"
# 538 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "truly clear and unclouded.\p"
# 539 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "I will eagerly await the next\n"
# 540 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "opportunity to see you.$"
# 541 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 542 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack:
# 543 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\n"
# 544 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "You've battled your way up again?\p"
# 545 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "You must have developed a truly\n"
# 546 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "formidable bond with your POKéMON.\p"
# 547 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "So be it!\p"
# 548 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "This time, I won't bluster or hold back.\n"
# 549 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "This time, there's no fooling around.\p"
# 550 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Ready now?\n"
# 551 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Prepare to lose!$"
# 552 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 553 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah:
# 554 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "… … …Kaaah!$"
# 555 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 556 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable:
# 557 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Well, that was some display!\n"
# 558 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Even fully unleashed, my brethren\l"
# 559 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "could not overpower you.\p"
# 560 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Your team spirit is truly admirable!\p"
# 561 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 562 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Bring me that thing, will you?$"
# 563 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 564 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass:
# 565 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My, my, if only you could maintain\n"
# 566 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "a certain level of decorum…\p"
# 567 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Gaaah, here!\n"
# 568 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Hurry with that FRONTIER PASS, you!$"
# 569 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 570 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine:
# 571 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The Spirits Symbol took on\n"
# 572 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 573 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 574 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain:
# 575 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\p"
# 576 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Come see me time and again!\n"
# 577 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My brethren and I will be waiting!$"
