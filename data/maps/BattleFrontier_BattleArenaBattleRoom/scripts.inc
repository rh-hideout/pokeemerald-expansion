# 1 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_BLACK_BELT_1, 1
# 3 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_BLACK_BELT_2, 2
# 4 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_BLACK_BELT_3, 3
# 5 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_BLACK_BELT_4, 4
# 6 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT, 5
# 7 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 7
# 8 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 8
# 9 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_ANNOUNCER, 9
# 10 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 11 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_MapScripts::
# 12 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleArenaBattleRoom_OnTransition
# 13 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaBattleRoom_OnFrame
# 14 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaBattleRoom_OnWarp
# 15 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleArenaBattleRoom_OnResume
# 16 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.byte 0
# 17 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 18 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 19 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_1
# 20 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 21 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnResume:
# 22 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special OffsetCameraForBattle
# 23 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 24 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 25 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnTransition:
# 26 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_settrainers
# 27 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfx
# 28 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 29 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 30 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfx::
# 31 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	checkplayergender
# 32 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxMale
# 33 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxFemale
# 34 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 35 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 36 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxMale::
# 37 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 38 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 39 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 40 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxFemale::
# 41 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 42 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 43 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 44 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnFrame:
# 45 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_EnterRoom
# 46 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.2byte 0
# 47 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 48 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_EnterRoom::
# 49 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	lockall
# 50 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM
# 51 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerEnter
# 52 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 53 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 54 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_AnnounceTrainers
# 55 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceDown
# 56 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceLeft
# 57 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 58 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 59 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 60 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 61 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AnnounceTrainers::
# 62 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	tower_setopponent
# 63 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 64 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentEnter
# 65 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 66 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 67 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 68 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 69 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 70 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_PlayerStepForward, MSGBOX_DEFAULT
# 71 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 72 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForward
# 73 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 74 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 75 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 76 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 77 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 78 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	arena_gettrainername
# 79 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_OpponentStepForward, MSGBOX_DEFAULT
# 80 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 81 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward
# 82 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 83 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 84 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 85 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 86 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 87 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin, MSGBOX_DEFAULT
# 88 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 89 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForward
# 90 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward
# 91 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 92 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	palace_getopponentintro
# 93 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 94 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 95 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle
# 96 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 97 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedOpponent
# 98 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DeclareOpponentWinner::
# 99 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 100 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_1, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 101 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_2, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 102 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_3, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 103 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_4, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 104 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_SNORE
# 105 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 106 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 107 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	arena_gettrainername
# 108 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsOpponent, MSGBOX_DEFAULT
# 109 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_WarpToLobbyLost::
# 110 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 111 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 7, 8
# 112 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 113 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 114 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedOpponent::
# 115 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner
# 116 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 117 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 118 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 119 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 120 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 121 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerWalkBackToLine
# 122 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentExit
# 123 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 124 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 125 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceDown
# 126 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceLeft
# 127 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 128 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_MonsWillBeRestored, MSGBOX_DEFAULT
# 129 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special LoadPlayerParty
# 130 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special SavePlayerParty
# 131 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 132 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 133 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitfanfare
# 134 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special HealPlayerParty
# 135 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent::
# 136 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 137 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 138 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleArenaBattleRoom_EventScript_TycoonUpNext
# 139 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 140 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor2ndOpponent
# 141 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor3rdOpponent
# 142 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor4thOpponent
# 143 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor5thOpponent
# 144 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor6thOpponent
# 145 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor7thOpponent
# 146 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 147 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 148 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 149 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 150 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_ContinueChallenge
# 151 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRecordBattle
# 152 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 153 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 154 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 155 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 156 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponentNoRecord::
# 157 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 158 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 159 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_ContinueChallenge
# 160 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 161 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 162 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 163 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 164 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskRecordBattle::
# 165 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_RecordLastBattle
# 166 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 167 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 168 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 169 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 170 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_RecordBattle
# 171 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 172 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 173 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_RecordBattle::
# 174 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 175 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 176 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 177 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge::
# 178 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SaveAndShutDown, MSGBOX_YESNO
# 179 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 180 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 181 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleArenaBattleRoom_EventScript_PauseChallenge
# 182 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 183 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 184 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge::
# 185 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_RetireFromChallenge
# 186 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 187 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 188 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 189 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 190 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_WarpToLobbyLost
# 191 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 192 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 193 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ContinueChallenge::
# 194 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 195 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 196 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 197 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 198 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_AnnounceTrainers
# 199 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 200 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon::
# 201 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay 60
# 202 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 203 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 7, 8
# 204 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 205 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 206 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor2ndOpponent::
# 207 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor2ndOpponent
# 208 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 209 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 210 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 211 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor3rdOpponent::
# 212 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor3rdOpponent
# 213 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 214 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 215 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 216 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor4thOpponent::
# 217 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor4thOpponent
# 218 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 219 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 220 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 221 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor5thOpponent::
# 222 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor5thOpponent
# 223 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 224 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 225 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 226 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor6thOpponent::
# 227 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor6thOpponent
# 228 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 229 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 230 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 231 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor7thOpponent::
# 232 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor7thOpponent
# 233 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 234 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 235 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 236 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_PauseChallenge::
# 237 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_SavingPleaseWait
# 238 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 239 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	arena_save CHALLENGE_STATUS_PAUSED
# 240 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_SAVE
# 241 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 242 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 243 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_reset
# 244 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 245 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 246 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_TycoonUpNext::
# 247 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon
# 248 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_NowFaceTycoon, MSGBOX_DEFAULT
# 249 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 250 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon::
# 251 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_PreparedForTycoon
# 252 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 253 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 254 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoonNoRecord
# 255 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 256 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 257 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGreta
# 258 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRecordBattle
# 259 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 260 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 261 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon
# 262 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 263 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoonNoRecord::
# 264 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 265 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 266 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGreta
# 267 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 268 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 269 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon
# 270 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 271 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGreta::
# 272 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 273 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 274 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 275 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 276 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 277 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 278 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 279 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 280 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_PlayerStepForward, MSGBOX_DEFAULT
# 281 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 282 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForwardLong
# 283 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 284 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 285 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 286 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 287 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 288 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_MakeWayForGreta, MSGBOX_DEFAULT
# 289 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 290 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 291 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaEnter
# 292 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 293 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward
# 294 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 295 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 296 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleArenaBattleRoom_EventScript_IntroGretaGold
# 297 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaSilver
# 298 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaGold
# 299 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 300 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaSilver
# 301 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureChallenger, MSGBOX_DEFAULT
# 302 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 303 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 304 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaLookAroundPlayer
# 305 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 306 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_IsThatRight, MSGBOX_DEFAULT
# 307 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 308 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaWalkBackToCenter
# 309 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 310 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_YouLookWeakTakeThingsEasy, MSGBOX_DEFAULT
# 311 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaSilver::
# 312 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_IgniteMyPassionForBattle, MSGBOX_DEFAULT
# 313 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_StartArenaBattle
# 314 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaSilver
# 315 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_DeclareOpponentWinner
# 316 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 317 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaSilver::
# 318 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner
# 319 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_getsymbols
# 320 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 321 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForwardLong
# 322 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 323 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureToughAfterAll, MSGBOX_DEFAULT
# 324 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 325 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReceivedGutsSymbol
# 326 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 327 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitfanfare
# 328 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_givesymbol
# 329 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GoingToBeFunNextTime, MSGBOX_DEFAULT
# 330 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 331 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 332 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_IntroGretaGold::
# 333 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 334 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaGold
# 335 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaLookingForwardToSeeingAgain, MSGBOX_DEFAULT
# 336 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 337 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 338 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaLookAroundPlayer
# 339 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 340 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SoAreYouReady, MSGBOX_DEFAULT
# 341 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 342 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaWalkBackToCenter
# 343 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 344 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WontAllowHalfheartedEffort, MSGBOX_DEFAULT
# 345 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaGold::
# 346 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_LetsGetThisStarted, MSGBOX_DEFAULT
# 347 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_StartArenaBattle
# 348 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaGold
# 349 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_DeclareOpponentWinner
# 350 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 351 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaGold::
# 352 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner
# 353 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_getsymbols
# 354 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 355 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForwardLong
# 356 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 357 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaBlownAway, MSGBOX_DEFAULT
# 358 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 359 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_GutsSymbolTookGoldenShine
# 360 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 361 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitfanfare
# 362 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_givesymbol
# 363 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_IfWeBattleAgainWontLose, MSGBOX_DEFAULT
# 364 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 365 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 366 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_StartArenaBattle::
# 367 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin, MSGBOX_DEFAULT
# 368 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle
# 369 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 370 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 371 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle::
# 372 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 373 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 374 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 375 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special HealPlayerParty
# 376 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_ARENA
# 377 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 378 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 379 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 380 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_restorehelditems
# 381 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special HealPlayerParty
# 382 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_resetsketch
# 383 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 384 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 385 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner::
# 386 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 387 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_1, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 388 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_2, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 389 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_3, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 390 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_4, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 391 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_BANG
# 392 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 393 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 394 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsPlayer, MSGBOX_DEFAULT
# 395 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 396 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 397 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 398 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 399 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerEnter:
# 400 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 401 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 402 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForwardLong:
# 403 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 404 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForward:
# 405 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 406 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 407 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 408 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerWalkBackToLine:
# 409 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 410 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 411 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 412 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 413 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 414 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceLeft:
# 415 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_up
# 416 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 417 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 418 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight:
# 419 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 420 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 421 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 422 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentEnter:
# 423 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 424 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 425 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForwardLong:
# 426 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 427 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward:
# 428 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 429 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 430 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 431 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_GretaEnter:
# 432 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 433 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 434 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 435 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 436 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 437 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 438 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 439 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentExit:
# 440 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 441 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 442 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 443 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 444 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 445 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 446 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 447 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 448 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 449 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown:
# 450 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 451 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	jump_in_place_down
# 452 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 453 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 454 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp:
# 455 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 456 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	jump_in_place_up
# 457 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 458 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 459 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceDown:
# 460 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 461 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 462 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 463 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
@ Unused, redundant
# 464 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight2:
# 465 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 466 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 467 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 468 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnWarp:
# 469 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_SetUpRoomObjects
# 470 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.2byte 0
# 471 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 472 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetUpRoomObjects::
# 473 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM
# 474 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 475 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 476 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible
# 477 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 478 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 479 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 480 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_GretaLookAroundPlayer:
# 481 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_down
# 482 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 483 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 484 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 485 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 486 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 487 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_up
# 488 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_up
# 489 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 490 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 491 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 492 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_GretaWalkBackToCenter:
# 493 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_down
# 494 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 495 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 496 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 497 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_PlayerStepForward:
# 498 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: TRAINER {PLAYER}!\n"
# 499 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Step forward, please!$"
# 500 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 501 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_OpponentStepForward:
# 502 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: TRAINER {STR_VAR_1}!\n"
# 503 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Step forward, please!$"
# 504 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 505 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin:
# 506 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: Set KO Tourney!\n"
# 507 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Begin!$"
# 508 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 509 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsPlayer:
# 510 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: The winner is {PLAYER}!$"
# 511 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 512 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsOpponent:
# 513 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: The winner is {STR_VAR_1}!$"
# 514 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 515 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_MonsWillBeRestored:
# 516 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Your POKéMON will be restored to\n"
# 517 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "full health.$"
# 518 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 519 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor2ndOpponent:
# 520 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your second opponent!\n"
# 521 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 522 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 523 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor3rdOpponent:
# 524 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your third opponent!\n"
# 525 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 526 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 527 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor4thOpponent:
# 528 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your fourth opponent!\n"
# 529 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 530 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 531 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor5thOpponent:
# 532 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your fifth opponent!\n"
# 533 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 534 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 535 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor6thOpponent:
# 536 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your sixth opponent!\n"
# 537 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 538 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 539 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor7thOpponent:
# 540 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your seventh opponent!\n"
# 541 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 542 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 543 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SaveAndShutDown:
# 544 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Would you like to save the game and\n"
# 545 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "shut down now?$"
# 546 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 547 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_RetireFromChallenge:
# 548 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Would you like to retire from your\n"
# 549 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Set KO Tourney challenge?$"
# 550 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 551 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SavingPleaseWait:
# 552 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I am saving your game data.\n"
# 553 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Please wait.$"
# 554 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 555 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_RecordLastBattle:
# 556 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Would you like to record your last\n"
# 557 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "battle on your FRONTIER PASS?$"
# 558 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 559 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_NowFaceTycoon:
# 560 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "My dear challenger!\p"
# 561 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Your skill level is truly astounding!\p"
# 562 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "We now would like you to face our\n"
# 563 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "leader, the ARENA TYCOON!$"
# 564 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 565 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_PreparedForTycoon:
# 566 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "A battle with the ARENA TYCOON!\n"
# 567 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 568 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 569 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_MakeWayForGreta:
# 570 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: The ARENA TYCOON!\n"
# 571 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Make way for GRETA!$"
# 572 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 573 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureChallenger:
# 574 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Hey!\n"
# 575 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Howdy!\p"
# 576 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "…Wait, are you the challenger?$"
# 577 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 578 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_IsThatRight:
# 579 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Is that right? Hmm…\n"
# 580 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Hmhm…$"
# 581 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 582 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_YouLookWeakTakeThingsEasy:
# 583 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I don't know how to say it, but…\n"
# 584 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "To put it bluntly, you look pretty weak.\l"
# 585 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you sure you're up for me?\p"
# 586 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Hmm…\p"
# 587 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Well, all right!\n"
# 588 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "We'll take things easy to start with!$"
# 589 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 590 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_IgniteMyPassionForBattle:
# 591 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Okay! Let's see you ignite my passion\n"
# 592 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "for battle!$"
# 593 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 594 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureToughAfterAll:
# 595 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Ow, wait a second!\n"
# 596 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "You are tough after all!\p"
# 597 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I like you!\n"
# 598 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS.$"
# 599 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 600 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReceivedGutsSymbol:
# 601 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "The Guts Symbol was embossed on\n"
# 602 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 603 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 604 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GoingToBeFunNextTime:
# 605 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Hmm…\p"
# 606 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "It's going to be fun the next time!\n"
# 607 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I'm looking forward to it!$"
# 608 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 609 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaLookingForwardToSeeingAgain:
# 610 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Hey! Howdy!\n"
# 611 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "You finally won your way up to me!\p"
# 612 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I was getting worried waiting for you!\n"
# 613 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I was really looking forward to seeing\l"
# 614 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "you again!$"
# 615 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 616 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SoAreYouReady:
# 617 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "… … …\n"
# 618 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "So, are you ready?$"
# 619 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 620 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_WontAllowHalfheartedEffort:
# 621 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I won't allow a halfhearted effort!\n"
# 622 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Be ready for a thrashing!$"
# 623 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 624 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_LetsGetThisStarted:
# 625 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Come on, REFEREE!\n"
# 626 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Let's get this started!$"
# 627 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 628 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaBlownAway:
# 629 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Gaaah! Blown away!\n"
# 630 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS!$"
# 631 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 632 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GutsSymbolTookGoldenShine:
# 633 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "The Guts Symbol took on\n"
# 634 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 635 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 636 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_IfWeBattleAgainWontLose:
# 637 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Arrrgh!\n"
# 638 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "This is so infuriating!\p"
# 639 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "If we ever battle again, I won't lose!\n"
# 640 "data//maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Don't you forget it! Bye-bye!$"
