# 1 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 2 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ On this map the player will automatically walk into the room, but the camera is supposed to remain still.
# 3 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ To do this GF sets the player (LOCALID_PLAYER) invisible and creates a fake player object (LOCALID_FALLARBOR_TENT_BATTLE_PLAYER).
# 4 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ The graphics of this fake player object are represented with VAR_OBJ_GFX_ID_1.
# 5 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ The graphics of the opponent are represented with VAR_OBJ_GFX_ID_0, which will ultimately be set by tower_setopponent.
# 6 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_MapScripts::
# 7 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_BattleTentBattleRoom_OnTransition
# 8 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentBattleRoom_OnFrame
# 9 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FallarborTown_BattleTentBattleRoom_OnWarp
# 10 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	.byte 0
# 11 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 12 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_OnTransition:
# 13 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 14 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
# 15 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 16 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfx::
# 17 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	checkplayergender
# 18 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale
# 19 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale
# 20 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 21 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 22 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale::
# 23 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 24 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 25 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 26 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 27 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale::
# 28 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 29 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 30 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 31 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 32 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_OnFrame:
# 33 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentBattleRoom_EventScript_EnterRoom
# 34 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 35 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 36 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_EnterRoom::
# 37 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	lockall
# 38 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	showobjectat LOCALID_FALLARBOR_TENT_BATTLE_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 39 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerEnter
# 40 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 41 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 42 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, FallarborTown_BattleTentBattleRoom_EventScript_ResumeChallenge
# 43 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_NextOpponentEnter::
# 44 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	tower_setopponent
# 45 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	addobject LOCALID_FALLARBOR_TENT_BATTLE_OPPONENT
# 46 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_OPPONENT, FallarborTown_BattleTentBattleRoom_Movement_OpponentEnter
# 47 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 48 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantJump
# 49 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 50 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 51 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 52 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin, MSGBOX_DEFAULT
# 53 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	battletent_getopponentintro
# 54 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 55 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 56 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle
# 57 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 58 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 1, FallarborTown_BattleTentBattleRoom_EventScript_DefeatedOpponent
# 59 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantJump
# 60 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_M_SNORE
# 61 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 62 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 63 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	fallarbortent_getopponentname
# 64 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsOpponent, MSGBOX_DEFAULT
# 65 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost::
# 66 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 67 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 68 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY, 6, 6
# 69 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 70 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 71 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_DefeatedOpponent::
# 72 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantJump
# 73 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_BANG
# 74 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 75 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 76 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsPlayer, MSGBOX_DEFAULT
# 77 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	closemessage
# 78 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_IncrementBattleNum::
# 79 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 80 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 81 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 82 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 83 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 3, FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon
# 84 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_OPPONENT, FallarborTown_BattleTentBattleRoom_Movement_OpponentExit
# 85 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 86 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_FALLARBOR_TENT_BATTLE_OPPONENT
# 87 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantApproachPlayer
# 88 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 89 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceAttendant
# 90 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 91 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_MonsWillBeRestored, MSGBOX_DEFAULT
# 92 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 93 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special SavePlayerParty
# 94 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 95 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 96 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitfanfare
# 97 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special HealPlayerParty
# 98 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge::
# 99 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 100 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent
# 101 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent
# 102 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 103 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 104 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 0, FallarborTown_BattleTentBattleRoom_EventScript_ContinueChallenge
# 105 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 1, FallarborTown_BattleTentBattleRoom_EventScript_AskPauseChallenge
# 106 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 2, FallarborTown_BattleTentBattleRoom_EventScript_AskRetireChallenge
# 107 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 108 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_AskPauseChallenge::
# 109 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SaveAndShutDown, MSGBOX_YESNO
# 110 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 111 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case NO, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 112 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case YES, FallarborTown_BattleTentBattleRoom_EventScript_PauseChallenge
# 113 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 114 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 115 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_AskRetireChallenge::
# 116 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_RetireFromChallenge
# 117 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 118 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 119 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 120 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 1, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 121 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 0, FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost
# 122 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 123 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 124 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ContinueChallenge::
# 125 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	closemessage
# 126 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantReturnToPos
# 127 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 128 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceBattle
# 129 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 130 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto FallarborTown_BattleTentBattleRoom_EventScript_NextOpponentEnter
# 131 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 132 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 133 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon::
# 134 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	delay 60
# 135 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 136 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 137 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY, 6, 6
# 138 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 139 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 140 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ Unreachable code block? The flow into the next block also doesnt make sense
# 141 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	arena_get ARENA_DATA_WIN_STREAK
# 142 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MAX_STREAK, FallarborTown_BattleTentBattleRoom_EventScript_IncrementBattleNum
# 143 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 144 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	arena_set ARENA_DATA_WIN_STREAK, VAR_RESULT
# 145 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ See above
# 146 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 147 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent::
# 148 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor2ndOpponent
# 149 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 150 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 151 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 152 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent::
# 153 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor3rdOpponent
# 154 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 155 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 156 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 157 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_PauseChallenge::
# 158 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_SavingPleaseWait
# 159 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 160 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	fallarbortent_save CHALLENGE_STATUS_PAUSED
# 161 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_SAVE
# 162 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 163 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 164 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_reset
# 165 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
# 166 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 167 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ResumeChallenge::
# 168 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantApproachPlayer
# 169 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 170 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_BATTLE_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceAttendant
# 171 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 172 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 173 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
# 174 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 175 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_PlayerEnter:
# 176 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 177 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 178 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 179 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 180 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 181 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 182 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceBattle:
# 183 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 184 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 185 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 186 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceAttendant:
# 187 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 188 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 189 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 190 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_OpponentEnter:
# 191 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 192 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 193 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 194 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 195 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 196 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 197 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 198 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ Unused
# 199 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_OpponentStepForward:
# 200 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_left
# 201 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 202 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 203 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_OpponentExit:
# 204 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 206 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 207 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 208 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 209 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 210 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_AttendantJump:
# 211 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 212 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	jump_in_place_down
# 213 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 214 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 215 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_AttendantApproachPlayer:
# 216 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 217 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 218 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 219 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 220 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 221 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 222 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_AttendantReturnToPos:
# 223 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 224 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 225 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 226 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 227 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 228 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 229 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_OnWarp:
# 230 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, FallarborTown_BattleTentBattleRoom_EventScript_SetUpObjects
# 231 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 232 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 233 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetUpObjects::
# 234 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 235 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_FALLARBOR_TENT_BATTLE_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 236 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_FALLARBOR_TENT_BATTLE_OPPONENT
# 237 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 238 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
