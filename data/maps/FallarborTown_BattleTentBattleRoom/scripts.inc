# 1 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 2 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 1
# 3 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT, 2
# 4 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 3
# 5 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

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
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 13 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	@ The player is represented instead by object event 1, which has the gfx id VAR_OBJ_GFX_ID_1
# 14 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	@ The opponent is represented by object event 3, which has the gfx id VAR_OBJ_GFX_ID_0
# 15 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 16 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_OnTransition:
# 17 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 18 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
# 19 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 20 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfx::
# 21 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	checkplayergender
# 22 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale
# 23 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale
# 24 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 25 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 26 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale::
# 27 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 28 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 29 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 30 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 31 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale::
# 32 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 33 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 34 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 35 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 36 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_OnFrame:
# 37 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentBattleRoom_EventScript_EnterRoom
# 38 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 39 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 40 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_EnterRoom::
# 41 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	lockall
# 42 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 43 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerEnter
# 44 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 45 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 46 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, FallarborTown_BattleTentBattleRoom_EventScript_ResumeChallenge
# 47 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_NextOpponentEnter::
# 48 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	tower_setopponent
# 49 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 50 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, FallarborTown_BattleTentBattleRoom_Movement_OpponentEnter
# 51 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 52 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantJump
# 53 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 54 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 55 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 56 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin, MSGBOX_DEFAULT
# 57 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	battletent_getopponentintro
# 58 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 59 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 60 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle
# 61 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 62 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 1, FallarborTown_BattleTentBattleRoom_EventScript_DefeatedOpponent
# 63 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantJump
# 64 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_M_SNORE
# 65 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 66 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 67 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	fallarbortent_getopponentname
# 68 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsOpponent, MSGBOX_DEFAULT
# 69 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost::
# 70 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 71 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 72 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY, 6, 6
# 73 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 74 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 75 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_DefeatedOpponent::
# 76 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantJump
# 77 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_BANG
# 78 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 79 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 80 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsPlayer, MSGBOX_DEFAULT
# 81 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	closemessage
# 82 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_IncrementBattleNum::
# 83 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 84 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 85 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 86 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 87 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 3, FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon
# 88 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, FallarborTown_BattleTentBattleRoom_Movement_OpponentExit
# 89 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 90 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 91 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantApproachPlayer
# 92 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 93 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceAttendant
# 94 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 95 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_MonsWillBeRestored, MSGBOX_DEFAULT
# 96 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 97 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special SavePlayerParty
# 98 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 99 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 100 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitfanfare
# 101 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special HealPlayerParty
# 102 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge::
# 103 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 104 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent
# 105 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent
# 106 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 107 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 108 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 0, FallarborTown_BattleTentBattleRoom_EventScript_ContinueChallenge
# 109 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 1, FallarborTown_BattleTentBattleRoom_EventScript_AskPauseChallenge
# 110 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 2, FallarborTown_BattleTentBattleRoom_EventScript_AskRetireChallenge
# 111 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 112 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_AskPauseChallenge::
# 113 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SaveAndShutDown, MSGBOX_YESNO
# 114 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 115 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case NO, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 116 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case YES, FallarborTown_BattleTentBattleRoom_EventScript_PauseChallenge
# 117 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 118 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 119 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_AskRetireChallenge::
# 120 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_RetireFromChallenge
# 121 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 122 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 123 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 124 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 1, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 125 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 0, FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost
# 126 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 127 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 128 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ContinueChallenge::
# 129 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	closemessage
# 130 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantReturnToPos
# 131 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 132 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceBattle
# 133 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 134 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto FallarborTown_BattleTentBattleRoom_EventScript_NextOpponentEnter
# 135 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 136 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 137 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon::
# 138 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	delay 60
# 139 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 140 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 141 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY, 6, 6
# 142 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 143 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 144 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ Unreachable code block? The flow into the next block also doesnt make sense
# 145 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	arena_get ARENA_DATA_WIN_STREAK
# 146 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MAX_STREAK, FallarborTown_BattleTentBattleRoom_EventScript_IncrementBattleNum
# 147 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 148 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	arena_set ARENA_DATA_WIN_STREAK, VAR_RESULT
# 149 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ See above
# 150 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 151 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent::
# 152 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor2ndOpponent
# 153 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 154 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 155 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 156 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent::
# 157 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor3rdOpponent
# 158 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 159 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 160 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 161 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_PauseChallenge::
# 162 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_SavingPleaseWait
# 163 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 164 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	fallarbortent_save CHALLENGE_STATUS_PAUSED
# 165 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_SAVE
# 166 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 167 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 168 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_reset
# 169 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
# 170 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 171 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ResumeChallenge::
# 172 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantApproachPlayer
# 173 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 174 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceAttendant
# 175 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 176 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 177 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
# 178 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 179 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_PlayerEnter:
# 180 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 181 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 182 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 184 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 185 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 186 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceBattle:
# 187 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 188 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 189 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 190 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceAttendant:
# 191 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 192 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 193 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 194 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_OpponentEnter:
# 195 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 196 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 197 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 198 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 199 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 200 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 201 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 202 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ Unused
# 203 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_OpponentStepForward:
# 204 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_left
# 205 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 206 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 207 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_OpponentExit:
# 208 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 209 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 210 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 211 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 212 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 213 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 214 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_AttendantJump:
# 215 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 216 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	jump_in_place_down
# 217 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 218 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 219 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_AttendantApproachPlayer:
# 220 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 221 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 222 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 223 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 224 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 225 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 226 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_AttendantReturnToPos:
# 227 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 228 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 229 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 230 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 231 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 232 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 233 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_OnWarp:
# 234 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, FallarborTown_BattleTentBattleRoom_EventScript_SetUpObjects
# 235 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 236 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 237 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetUpObjects::
# 238 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 239 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 240 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 241 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 242 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
