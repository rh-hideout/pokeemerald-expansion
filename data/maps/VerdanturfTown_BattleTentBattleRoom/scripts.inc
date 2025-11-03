# 1 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 2 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
@ On this map the player will automatically walk into the room, but the camera is supposed to remain still.
# 3 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
@ To do this GF sets the player (LOCALID_PLAYER) invisible and creates a fake player object (LOCALID_VERDANTURF_TENT_BATTLE_PLAYER).
# 4 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
@ The graphics of this fake player object are represented with VAR_OBJ_GFX_ID_1.
# 5 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
@ The graphics of the opponent are represented with VAR_OBJ_GFX_ID_0, which will ultimately be set by tower_setopponent.
# 6 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_MapScripts::
# 7 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_BattleTentBattleRoom_OnTransition
# 8 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentBattleRoom_OnFrame
# 9 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VerdanturfTown_BattleTentBattleRoom_OnWarp
# 10 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	.byte 0
# 11 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 12 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnTransition:
# 13 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 14 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 15 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 16 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx::
# 17 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	checkplayergender
# 18 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale
# 19 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale
# 20 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 21 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 22 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale::
# 23 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 24 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 25 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 26 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 27 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale::
# 28 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 29 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 30 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 31 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 32 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnFrame:
# 33 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_EnterRoom
# 34 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 35 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 36 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_EnterRoom::
# 37 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	showobjectat LOCALID_VERDANTURF_TENT_BATTLE_PLAYER, MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
# 38 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_PLAYER, VerdanturfTown_BattleTentBattleRoom_Movement_PlayerEnter
# 39 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 40 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 41 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 42 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_NextOpponentEnter::
# 43 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	tower_setopponent
# 44 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	addobject LOCALID_VERDANTURF_TENT_BATTLE_OPPONENT
# 45 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_OPPONENT, VerdanturfTown_BattleTentBattleRoom_Movement_OpponentEnter
# 46 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 47 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	battletent_getopponentintro
# 48 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 49 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 50 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 51 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 52 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_DefeatedOpponent
# 53 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost::
# 54 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 55 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 56 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY, 6, 6
# 57 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 58 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 59 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_DefeatedOpponent::
# 60 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 61 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 62 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 63 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 64 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 3, VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon
# 65 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_OPPONENT, VerdanturfTown_BattleTentBattleRoom_Movement_OpponentExit
# 66 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 67 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_VERDANTURF_TENT_BATTLE_OPPONENT
# 68 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_ATTENDANT, Common_Movement_WalkInPlaceFasterDown
# 69 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 70 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 71 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons, MSGBOX_DEFAULT
# 72 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 73 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special SavePlayerParty
# 74 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 75 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 76 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitfanfare
# 77 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special HealPlayerParty
# 78 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 79 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge::
# 80 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 81 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent
# 82 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent
# 83 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 84 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 85 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 0, VerdanturfTown_BattleTentBattleRoom_EventScript_ContinueChallenge
# 86 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_AskPauseChallenge
# 87 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 2, VerdanturfTown_BattleTentBattleRoom_EventScript_AskRetireChallenge
# 88 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 89 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskPauseChallenge::
# 90 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 91 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 92 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case NO, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 93 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case YES, VerdanturfTown_BattleTentBattleRoom_EventScript_PauseChallenge
# 94 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 95 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 96 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskRetireChallenge::
# 97 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge
# 98 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 99 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 100 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 101 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 102 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 0, VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost
# 103 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 104 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 105 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ContinueChallenge::
# 106 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
# 107 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 108 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 109 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	closemessage
# 110 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto VerdanturfTown_BattleTentBattleRoom_EventScript_NextOpponentEnter
# 111 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 112 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon::
# 113 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 114 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 115 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY, 6, 6
# 116 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 117 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 118 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_PauseChallenge::
# 119 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SavingData
# 120 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 121 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	verdanturftent_save CHALLENGE_STATUS_PAUSED
# 122 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	playse SE_SAVE
# 123 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 124 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 125 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_reset
# 126 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 127 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 128 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnWarp:
# 129 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_SetUpObjects
# 130 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 131 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 132 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetUpObjects::
# 133 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_VERDANTURF_TENT_BATTLE_PLAYER, MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
# 134 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 135 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 136 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentBattleRoom_Movement_SetInvisible
# 137 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_VERDANTURF_TENT_BATTLE_OPPONENT
# 138 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 139 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 140 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent::
# 141 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
# 142 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 143 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 144 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 145 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent::
# 146 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
# 147 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 148 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 149 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 150 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_SetInvisible:
# 151 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	set_invisible
# 152 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 153 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 154 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_PlayerEnter:
# 155 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	set_visible
# 156 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 157 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 158 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 159 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	face_right
# 160 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 161 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 162 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_OpponentEnter:
# 163 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 164 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 165 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 166 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 167 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	face_left
# 168 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 169 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 170 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_OpponentExit:
# 171 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 172 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 173 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 174 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 175 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
