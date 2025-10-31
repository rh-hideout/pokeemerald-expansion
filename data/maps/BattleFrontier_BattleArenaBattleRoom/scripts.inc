# 1 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
@ On this map the player will automatically walk into the room, but the camera is supposed to remain still.
# 3 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
@ To do this GF sets the player (LOCALID_PLAYER) invisible and creates a fake player object (LOCALID_ARENA_BATTLE_PLAYER).
# 4 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
@ The graphics of this fake player object are represented with VAR_OBJ_GFX_ID_1.
# 5 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
@ The graphics of the opponent are represented with VAR_OBJ_GFX_ID_0, which will ultimately be set by tower_setopponent.
# 6 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_MapScripts::
# 7 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleArenaBattleRoom_OnTransition
# 8 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaBattleRoom_OnFrame
# 9 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaBattleRoom_OnWarp
# 10 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleArenaBattleRoom_OnResume
# 11 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.byte 0
# 12 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 13 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnResume:
# 14 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special OffsetCameraForBattle
# 15 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 16 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 17 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnTransition:
# 18 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_settrainers
# 19 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfx
# 20 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 21 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 22 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfx::
# 23 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	checkplayergender
# 24 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxMale
# 25 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxFemale
# 26 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 27 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 28 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxMale::
# 29 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 30 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 31 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 32 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxFemale::
# 33 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 34 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 35 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 36 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnFrame:
# 37 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_EnterRoom
# 38 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.2byte 0
# 39 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 40 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_EnterRoom::
# 41 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	lockall
# 42 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	showobjectat LOCALID_ARENA_BATTLE_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM
# 43 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerEnter
# 44 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 45 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 46 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_AnnounceTrainers
# 47 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceDown
# 48 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceLeft
# 49 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 50 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 51 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 52 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 53 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AnnounceTrainers::
# 54 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	tower_setopponent
# 55 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	addobject LOCALID_ARENA_BATTLE_OPPONENT
# 56 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentEnter
# 57 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 58 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 59 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 60 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 61 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 62 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_PlayerStepForward, MSGBOX_DEFAULT
# 63 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 64 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForward
# 65 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 66 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 67 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 68 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 69 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 70 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	arena_gettrainername
# 71 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_OpponentStepForward, MSGBOX_DEFAULT
# 72 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 73 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward
# 74 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 75 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 76 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 77 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 78 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 79 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin, MSGBOX_DEFAULT
# 80 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 81 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForward
# 82 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward
# 83 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 84 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	palace_getopponentintro
# 85 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 86 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 87 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle
# 88 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 89 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedOpponent
# 90 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DeclareOpponentWinner::
# 91 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 92 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_BLACK_BELT_1, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 93 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_BLACK_BELT_2, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 94 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_BLACK_BELT_3, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 95 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_BLACK_BELT_4, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 96 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_SNORE
# 97 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 98 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 99 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	arena_gettrainername
# 100 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsOpponent, MSGBOX_DEFAULT
# 101 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_WarpToLobbyLost::
# 102 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 103 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 7, 8
# 104 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 105 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 106 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedOpponent::
# 107 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner
# 108 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 109 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 110 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 111 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 112 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 113 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerWalkBackToLine
# 114 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentExit
# 115 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 116 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	removeobject LOCALID_ARENA_BATTLE_OPPONENT
# 117 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceDown
# 118 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceLeft
# 119 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 120 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_MonsWillBeRestored, MSGBOX_DEFAULT
# 121 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special LoadPlayerParty
# 122 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special SavePlayerParty
# 123 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 124 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 125 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitfanfare
# 126 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special HealPlayerParty
# 127 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent::
# 128 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 129 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 130 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleArenaBattleRoom_EventScript_TycoonUpNext
# 131 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 132 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor2ndOpponent
# 133 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor3rdOpponent
# 134 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor4thOpponent
# 135 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor5thOpponent
# 136 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor6thOpponent
# 137 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor7thOpponent
# 138 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 139 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 140 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 141 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 142 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_ContinueChallenge
# 143 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRecordBattle
# 144 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 145 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 146 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 147 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 148 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponentNoRecord::
# 149 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 150 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 151 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_ContinueChallenge
# 152 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 153 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 154 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 155 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 156 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskRecordBattle::
# 157 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_RecordLastBattle
# 158 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 159 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 160 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 161 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 162 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_RecordBattle
# 163 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 164 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 165 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_RecordBattle::
# 166 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 167 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 168 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 169 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge::
# 170 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SaveAndShutDown, MSGBOX_YESNO
# 171 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 172 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 173 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleArenaBattleRoom_EventScript_PauseChallenge
# 174 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 175 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 176 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge::
# 177 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_RetireFromChallenge
# 178 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 179 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 180 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 181 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 182 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_WarpToLobbyLost
# 183 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 184 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 185 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ContinueChallenge::
# 186 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 187 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 188 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 189 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 190 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_AnnounceTrainers
# 191 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 192 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon::
# 193 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay 60
# 194 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 195 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 7, 8
# 196 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 197 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 198 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor2ndOpponent::
# 199 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor2ndOpponent
# 200 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 201 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 202 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 203 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor3rdOpponent::
# 204 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor3rdOpponent
# 205 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 206 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 207 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 208 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor4thOpponent::
# 209 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor4thOpponent
# 210 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 211 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 212 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 213 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor5thOpponent::
# 214 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor5thOpponent
# 215 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 216 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 217 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 218 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor6thOpponent::
# 219 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor6thOpponent
# 220 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 221 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 222 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 223 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor7thOpponent::
# 224 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor7thOpponent
# 225 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 226 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 227 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 228 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_PauseChallenge::
# 229 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_SavingPleaseWait
# 230 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 231 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	arena_save CHALLENGE_STATUS_PAUSED
# 232 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_SAVE
# 233 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 234 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 235 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_reset
# 236 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 237 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 238 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_TycoonUpNext::
# 239 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon
# 240 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_NowFaceTycoon, MSGBOX_DEFAULT
# 241 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 242 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon::
# 243 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_PreparedForTycoon
# 244 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 245 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 246 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoonNoRecord
# 247 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 248 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 249 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGreta
# 250 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRecordBattle
# 251 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 252 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 253 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon
# 254 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 255 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoonNoRecord::
# 256 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 257 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 258 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGreta
# 259 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 260 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 261 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon
# 262 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 263 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGreta::
# 264 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 265 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 266 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 267 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 268 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 269 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 270 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 271 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 272 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_PlayerStepForward, MSGBOX_DEFAULT
# 273 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 274 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForwardLong
# 275 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 276 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 277 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 278 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 279 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 280 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_MakeWayForGreta, MSGBOX_DEFAULT
# 281 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 282 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	addobject LOCALID_ARENA_BATTLE_OPPONENT
# 283 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaEnter
# 284 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 285 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward
# 286 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 287 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 288 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleArenaBattleRoom_EventScript_IntroGretaGold
# 289 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaSilver
# 290 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaGold
# 291 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 292 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaSilver
# 293 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureChallenger, MSGBOX_DEFAULT
# 294 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 295 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 296 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaLookAroundPlayer
# 297 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 298 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_IsThatRight, MSGBOX_DEFAULT
# 299 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 300 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaWalkBackToCenter
# 301 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 302 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_YouLookWeakTakeThingsEasy, MSGBOX_DEFAULT
# 303 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaSilver::
# 304 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_IgniteMyPassionForBattle, MSGBOX_DEFAULT
# 305 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_StartArenaBattle
# 306 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaSilver
# 307 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_DeclareOpponentWinner
# 308 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 309 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaSilver::
# 310 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner
# 311 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_getsymbols
# 312 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 313 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForwardLong
# 314 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 315 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureToughAfterAll, MSGBOX_DEFAULT
# 316 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 317 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReceivedGutsSymbol
# 318 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 319 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitfanfare
# 320 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_givesymbol
# 321 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GoingToBeFunNextTime, MSGBOX_DEFAULT
# 322 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 323 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 324 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_IntroGretaGold::
# 325 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 326 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaGold
# 327 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaLookingForwardToSeeingAgain, MSGBOX_DEFAULT
# 328 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 329 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 330 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaLookAroundPlayer
# 331 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 332 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SoAreYouReady, MSGBOX_DEFAULT
# 333 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 334 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaWalkBackToCenter
# 335 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 336 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WontAllowHalfheartedEffort, MSGBOX_DEFAULT
# 337 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaGold::
# 338 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_LetsGetThisStarted, MSGBOX_DEFAULT
# 339 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_StartArenaBattle
# 340 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaGold
# 341 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_DeclareOpponentWinner
# 342 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 343 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaGold::
# 344 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner
# 345 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_getsymbols
# 346 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 347 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForwardLong
# 348 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 349 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaBlownAway, MSGBOX_DEFAULT
# 350 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 351 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_GutsSymbolTookGoldenShine
# 352 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 353 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitfanfare
# 354 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_givesymbol
# 355 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_IfWeBattleAgainWontLose, MSGBOX_DEFAULT
# 356 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 357 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 358 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_StartArenaBattle::
# 359 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin, MSGBOX_DEFAULT
# 360 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle
# 361 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 362 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 363 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle::
# 364 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 365 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 366 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 367 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special HealPlayerParty
# 368 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_ARENA
# 369 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 370 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 371 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 372 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_restorehelditems
# 373 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special HealPlayerParty
# 374 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_resetsketch
# 375 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 376 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 377 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner::
# 378 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 379 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_BLACK_BELT_1, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 380 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_BLACK_BELT_2, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 381 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_BLACK_BELT_3, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 382 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ARENA_BATTLE_BLACK_BELT_4, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 383 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_BANG
# 384 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 385 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 386 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsPlayer, MSGBOX_DEFAULT
# 387 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 388 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 389 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 390 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 391 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerEnter:
# 392 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 393 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 394 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForwardLong:
# 395 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 396 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForward:
# 397 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 398 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 399 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 400 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerWalkBackToLine:
# 401 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 402 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 403 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 404 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 405 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 406 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceLeft:
# 407 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_up
# 408 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 409 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 410 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight:
# 411 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 412 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 413 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 414 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentEnter:
# 415 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 416 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 417 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForwardLong:
# 418 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 419 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward:
# 420 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 421 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 422 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 423 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_GretaEnter:
# 424 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 425 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 426 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 427 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 428 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 429 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 430 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 431 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentExit:
# 432 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 433 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 434 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 435 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 436 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 437 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 438 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 439 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 440 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 441 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown:
# 442 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 443 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	jump_in_place_down
# 444 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 445 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 446 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp:
# 447 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 448 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	jump_in_place_up
# 449 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 450 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 451 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceDown:
# 452 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 453 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 454 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 455 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
@ Unused, redundant
# 456 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight2:
# 457 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 458 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 459 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 460 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnWarp:
# 461 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_SetUpRoomObjects
# 462 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.2byte 0
# 463 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 464 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetUpRoomObjects::
# 465 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	hideobjectat LOCALID_ARENA_BATTLE_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM
# 466 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	removeobject LOCALID_ARENA_BATTLE_OPPONENT
# 467 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 468 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible
# 469 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 470 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 471 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 472 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_GretaLookAroundPlayer:
# 473 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_down
# 474 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 475 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 476 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 477 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 478 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 479 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_up
# 480 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_up
# 481 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 482 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 483 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 484 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_GretaWalkBackToCenter:
# 485 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_down
# 486 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 487 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 488 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 489 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_PlayerStepForward:
# 490 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: TRAINER {PLAYER}!\n"
# 491 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Step forward, please!$"
# 492 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 493 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_OpponentStepForward:
# 494 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: TRAINER {STR_VAR_1}!\n"
# 495 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Step forward, please!$"
# 496 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 497 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin:
# 498 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: Set KO Tourney!\n"
# 499 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Begin!$"
# 500 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 501 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsPlayer:
# 502 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: The winner is {PLAYER}!$"
# 503 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 504 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsOpponent:
# 505 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: The winner is {STR_VAR_1}!$"
# 506 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 507 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_MonsWillBeRestored:
# 508 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Your POKéMON will be restored to\n"
# 509 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "full health.$"
# 510 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 511 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor2ndOpponent:
# 512 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your second opponent!\n"
# 513 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 514 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 515 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor3rdOpponent:
# 516 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your third opponent!\n"
# 517 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 518 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 519 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor4thOpponent:
# 520 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your fourth opponent!\n"
# 521 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 522 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 523 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor5thOpponent:
# 524 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your fifth opponent!\n"
# 525 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 526 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 527 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor6thOpponent:
# 528 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your sixth opponent!\n"
# 529 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 530 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 531 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor7thOpponent:
# 532 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your seventh opponent!\n"
# 533 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 534 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 535 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SaveAndShutDown:
# 536 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Would you like to save the game and\n"
# 537 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "shut down now?$"
# 538 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 539 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_RetireFromChallenge:
# 540 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Would you like to retire from your\n"
# 541 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Set KO Tourney challenge?$"
# 542 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 543 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SavingPleaseWait:
# 544 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I am saving your game data.\n"
# 545 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Please wait.$"
# 546 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 547 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_RecordLastBattle:
# 548 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Would you like to record your last\n"
# 549 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "battle on your FRONTIER PASS?$"
# 550 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 551 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_NowFaceTycoon:
# 552 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "My dear challenger!\p"
# 553 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Your skill level is truly astounding!\p"
# 554 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "We now would like you to face our\n"
# 555 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "leader, the ARENA TYCOON!$"
# 556 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 557 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_PreparedForTycoon:
# 558 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "A battle with the ARENA TYCOON!\n"
# 559 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 560 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 561 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_MakeWayForGreta:
# 562 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: The ARENA TYCOON!\n"
# 563 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Make way for GRETA!$"
# 564 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 565 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureChallenger:
# 566 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Hey!\n"
# 567 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Howdy!\p"
# 568 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "…Wait, are you the challenger?$"
# 569 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 570 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_IsThatRight:
# 571 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Is that right? Hmm…\n"
# 572 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Hmhm…$"
# 573 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 574 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_YouLookWeakTakeThingsEasy:
# 575 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I don't know how to say it, but…\n"
# 576 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "To put it bluntly, you look pretty weak.\l"
# 577 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you sure you're up for me?\p"
# 578 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Hmm…\p"
# 579 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Well, all right!\n"
# 580 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "We'll take things easy to start with!$"
# 581 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 582 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_IgniteMyPassionForBattle:
# 583 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Okay! Let's see you ignite my passion\n"
# 584 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "for battle!$"
# 585 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 586 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureToughAfterAll:
# 587 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Ow, wait a second!\n"
# 588 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "You are tough after all!\p"
# 589 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I like you!\n"
# 590 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS.$"
# 591 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 592 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReceivedGutsSymbol:
# 593 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "The Guts Symbol was embossed on\n"
# 594 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 595 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 596 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GoingToBeFunNextTime:
# 597 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Hmm…\p"
# 598 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "It's going to be fun the next time!\n"
# 599 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I'm looking forward to it!$"
# 600 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 601 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaLookingForwardToSeeingAgain:
# 602 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Hey! Howdy!\n"
# 603 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "You finally won your way up to me!\p"
# 604 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I was getting worried waiting for you!\n"
# 605 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I was really looking forward to seeing\l"
# 606 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "you again!$"
# 607 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 608 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SoAreYouReady:
# 609 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "… … …\n"
# 610 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "So, are you ready?$"
# 611 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 612 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_WontAllowHalfheartedEffort:
# 613 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I won't allow a halfhearted effort!\n"
# 614 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Be ready for a thrashing!$"
# 615 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 616 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_LetsGetThisStarted:
# 617 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Come on, REFEREE!\n"
# 618 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Let's get this started!$"
# 619 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 620 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaBlownAway:
# 621 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Gaaah! Blown away!\n"
# 622 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS!$"
# 623 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 624 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GutsSymbolTookGoldenShine:
# 625 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "The Guts Symbol took on\n"
# 626 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 627 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 628 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_IfWeBattleAgainWontLose:
# 629 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Arrrgh!\n"
# 630 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "This is so infuriating!\p"
# 631 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "If we ever battle again, I won't lose!\n"
# 632 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Don't you forget it! Bye-bye!$"
