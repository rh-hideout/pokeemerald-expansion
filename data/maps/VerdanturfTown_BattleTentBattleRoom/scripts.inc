# 1 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 2 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 1
# 3 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 2
# 4 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT, 3
# 5 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

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
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 13 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	@ The player is represented instead by object event 1, which has the gfx id VAR_OBJ_GFX_ID_1
# 14 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	@ The opponent is represented by object event 2, which has the gfx id VAR_OBJ_GFX_ID_0
# 15 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 16 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnTransition:
# 17 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 18 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 19 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 20 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx::
# 21 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	checkplayergender
# 22 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale
# 23 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale
# 24 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 25 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 26 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale::
# 27 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 28 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 29 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 30 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 31 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale::
# 32 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 33 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 34 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 35 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 36 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnFrame:
# 37 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_EnterRoom
# 38 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 39 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 40 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_EnterRoom::
# 41 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
# 42 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentBattleRoom_Movement_PlayerEnter
# 43 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 44 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 45 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 46 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_NextOpponentEnter::
# 47 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	tower_setopponent
# 48 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 49 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, VerdanturfTown_BattleTentBattleRoom_Movement_OpponentEnter
# 50 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	battletent_getopponentintro
# 52 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 53 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 54 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 55 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 56 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_DefeatedOpponent
# 57 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost::
# 58 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 59 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 60 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY, 6, 6
# 61 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 62 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 63 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_DefeatedOpponent::
# 64 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 65 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 66 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 67 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 68 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 3, VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon
# 69 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, VerdanturfTown_BattleTentBattleRoom_Movement_OpponentExit
# 70 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 71 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 72 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterDown
# 73 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 74 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 75 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons, MSGBOX_DEFAULT
# 76 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 77 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special SavePlayerParty
# 78 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 79 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 80 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitfanfare
# 81 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special HealPlayerParty
# 82 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 83 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge::
# 84 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 85 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent
# 86 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent
# 87 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 88 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 89 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 0, VerdanturfTown_BattleTentBattleRoom_EventScript_ContinueChallenge
# 90 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_AskPauseChallenge
# 91 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 2, VerdanturfTown_BattleTentBattleRoom_EventScript_AskRetireChallenge
# 92 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 93 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskPauseChallenge::
# 94 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 95 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 96 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case NO, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 97 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case YES, VerdanturfTown_BattleTentBattleRoom_EventScript_PauseChallenge
# 98 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 99 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 100 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskRetireChallenge::
# 101 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge
# 102 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 103 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 104 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 105 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 106 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 0, VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost
# 107 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 108 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 109 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ContinueChallenge::
# 110 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
# 111 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 112 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 113 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	closemessage
# 114 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto VerdanturfTown_BattleTentBattleRoom_EventScript_NextOpponentEnter
# 115 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 116 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon::
# 117 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 118 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 119 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY, 6, 6
# 120 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 121 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 122 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_PauseChallenge::
# 123 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SavingData
# 124 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 125 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	verdanturftent_save CHALLENGE_STATUS_PAUSED
# 126 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	playse SE_SAVE
# 127 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 128 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 129 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_reset
# 130 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 131 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 132 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnWarp:
# 133 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_SetUpObjects
# 134 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 135 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 136 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetUpObjects::
# 137 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
# 138 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 139 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 140 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentBattleRoom_Movement_SetInvisible
# 141 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 142 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 143 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 144 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent::
# 145 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
# 146 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 147 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 148 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 149 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent::
# 150 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
# 151 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 152 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 153 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 154 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_SetInvisible:
# 155 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	set_invisible
# 156 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 157 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 158 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_PlayerEnter:
# 159 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	set_visible
# 160 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 161 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 162 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 163 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	face_right
# 164 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 165 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 166 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_OpponentEnter:
# 167 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 168 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 169 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 170 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 171 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	face_left
# 172 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 173 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 174 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_OpponentExit:
# 175 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 176 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 177 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 178 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 179 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
