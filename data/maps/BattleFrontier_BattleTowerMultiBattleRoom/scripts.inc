# 1 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ On this map the player will automatically walk into the room, but the camera is supposed to remain still.
# 3 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ To do this GF sets the player (LOCALID_PLAYER) invisible and creates a fake player object (LOCALID_TOWER_MULTI_BATTLE_PLAYER).
# 4 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ The graphics of this fake player object are represented with VAR_OBJ_GFX_ID_F.
# 5 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ The graphics of the partner are represented with VAR_OBJ_GFX_ID_E, which will ultimately be set by tower_setpartnergfx.
# 6 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ The graphics of the opponents are represented with VAR_OBJ_GFX_ID_0 and OBJ_EVENT_GFX_VAR_1, which will ultimately be set by tower_setopponent.
# 7 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 8 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_MapScripts::
# 9 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiBattleRoom_OnTransition
# 10 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_OnWarp
# 11 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_OnFrame
# 12 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.byte 0
# 13 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 14 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnTransition:
# 15 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetObjGfx
# 16 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetLinkPlayerGfx
# 17 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 18 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 19 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetObjGfx::
# 20 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setpartnergfx
# 21 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	checkplayergender
# 22 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetPlayerGfxFemale
# 23 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 24 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 25 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 26 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetPlayerGfxFemale::
# 27 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_MAY_NORMAL
# 28 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 29 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 30 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetLinkPlayerGfx::
# 31 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special SetBattleTowerLinkPlayerGfx
# 32 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 33 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 34 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnWarp:
# 35 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_HidePlayerObj
# 36 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.2byte 0
# 37 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 38 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_HidePlayerObj::
# 39 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM
# 40 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 41 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 42 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnFrame:
# 43 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_EnterRoom
# 44 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.2byte 0
# 45 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 46 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_EnterRoom::
# 47 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 48 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_PlayerEnterRoom
# 49 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_PartnerEnterRoom
# 50 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 52 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter
# 53 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 54 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 55 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 56 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 57 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 58 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 59 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 60 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 61 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 62 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter::
# 63 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setopponent
# 64 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	addobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1
# 65 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	addobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2
# 66 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Enter
# 67 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Enter
# 68 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 69 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoOpponentIntrosLink
# 70 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 71 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 15
# 72 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 73 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 74 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 75 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 76 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 1
# 77 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 78 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 79 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 80 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 81 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoTowerBattle
# 82 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 83 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoOpponentIntrosLink::
# 84 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 85 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 15
# 86 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 87 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 88 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll gStringVar4
# 89 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 90 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 91 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 1
# 92 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 93 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 94 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll gStringVar4
# 95 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 96 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 97 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoTowerBattle::
# 98 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 99 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 100 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DefeatedOpponents
# 101 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost::
# 102 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 103 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 104 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 105 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 106 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 107 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 108 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DefeatedOpponents::
# 109 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 110 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setbattlewon
# 111 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 112 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyWon
# 113 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Exit
# 114 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Exit
# 115 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 116 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	removeobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1
# 117 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	removeobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2
# 118 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 119 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 120 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 121 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 122 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 123 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 124 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetorePartyMsgLink
# 125 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
# 126 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RestoreParty
# 127 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 128 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetorePartyMsgLink::
# 129 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth
# 130 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 131 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 132 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RestoreParty::
# 133 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LoadPlayerParty
# 134 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_MULTI_PARTY_SIZE
# 135 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReconnectLink
# 136 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 137 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitfanfare
# 138 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special HealPlayerParty
# 139 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents::
# 140 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 141 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSet
# 142 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 143 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 144 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsNoRecord
# 145 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 146 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 147 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 148 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattle
# 149 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge
# 150 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge
# 151 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 152 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 153 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsNoRecord::
# 154 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 155 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 156 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 157 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge
# 158 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge
# 159 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 160 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 161 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattle::
# 162 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 163 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 164 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 165 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 166 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 167 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RecordBattle
# 168 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 169 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 170 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RecordBattle::
# 171 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 172 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 173 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 174 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge::
# 175 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 176 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 177 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 178 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_PauseChallenge
# 179 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 180 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 181 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge::
# 182 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
# 183 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 184 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 185 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 186 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 187 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 188 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 189 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 190 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge::
# 191 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	closemessage
# 192 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 193 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle
# 194 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle
# 195 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 196 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos
# 197 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos
# 198 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 199 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter
# 200 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 201 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 202 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyWon::
# 203 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 204 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 205 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 206 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 207 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 208 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 209 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_PauseChallenge::
# 210 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
# 211 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 212 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_save CHALLENGE_STATUS_PAUSED
# 213 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	playse SE_SAVE
# 214 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitse
# 215 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	fadescreen 1
# 216 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_reset
# 217 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 218 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 219 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSet::
# 220 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSetLink
# 221 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 222 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 223 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSet
# 224 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSet
# 225 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSet
# 226 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSet
# 227 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSet
# 228 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 6, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSet
# 229 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 230 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSet::
# 231 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet
# 232 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 233 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 234 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 235 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSet::
# 236 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet
# 237 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 238 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 239 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 240 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSet::
# 241 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet
# 242 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 243 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 244 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 245 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSet::
# 246 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet
# 247 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 248 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 249 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 250 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSet::
# 251 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet
# 252 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 253 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 254 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 255 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSet::
# 256 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet
# 257 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 258 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 259 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 260 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSetLink::
# 261 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 262 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 263 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSetLink
# 264 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSetLink
# 265 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSetLink
# 266 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSetLink
# 267 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSetLink
# 268 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 6, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSetLink
# 269 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 270 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSetLink::
# 271 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet
# 272 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 273 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 274 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 275 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 276 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSetLink::
# 277 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet
# 278 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 279 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 280 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 281 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 282 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSetLink::
# 283 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet
# 284 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 285 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 286 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 287 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 288 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSetLink::
# 289 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet
# 290 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 291 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 292 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 293 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 294 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSetLink::
# 295 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet
# 296 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 297 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 298 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 299 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 300 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSetLink::
# 301 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet
# 302 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 303 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 304 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 305 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 306 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_LinkDelayForMsg::
# 307 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 308 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 309 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 310 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 311 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink::
# 312 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_set FLAG_TEMP_2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLinkNoRecord
# 313 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 19, 6, MULTI_GO_ON_RECORD_RETIRE, TRUE
# 314 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 315 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink
# 316 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattleLink
# 317 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 318 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 319 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 320 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 321 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLinkNoRecord::
# 322 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 20, 8, MULTI_GO_ON_RETIRE, TRUE
# 323 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 324 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink
# 325 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 326 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 327 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 328 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 329 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink::
# 330 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, BATTLE_TOWER_LINK_CONTINUE
# 331 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 332 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message gText_LinkStandby3
# 333 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 334 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LinkRetireStatusWithBattleTowerPartner
# 335 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitstate
# 336 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, BATTLE_TOWER_LINKSTAT_CONTINUE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 337 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_LinkDelayForMsg
# 338 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 339 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 340 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattleLink::
# 341 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 342 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 343 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 344 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 345 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 346 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 347 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 348 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 349 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 350 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 351 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 352 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink::
# 353 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
# 354 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 355 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 356 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetireChallengeLink
# 357 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 358 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 359 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 360 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetireChallengeLink::
# 361 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, BATTLE_TOWER_LINK_RETIRE
# 362 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 363 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message gText_LinkStandby3
# 364 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 365 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LinkRetireStatusWithBattleTowerPartner
# 366 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitstate
# 367 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 368 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 369 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 370 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReconnectLink::
# 371 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special BattleTowerReconnectLink
# 372 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 373 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 374 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_PlayerEnterRoom:
# 375 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 376 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 377 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 378 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 379 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_right
# 380 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 381 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 382 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_PartnerEnterRoom:
# 383 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 384 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 385 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 386 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 387 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_right
# 388 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 389 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 390 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant:
# 391 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 392 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 393 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 394 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle:
# 395 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 396 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 397 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 398 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Enter:
# 399 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 400 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 401 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 402 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 403 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 404 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 405 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 406 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Enter:
# 407 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 408 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 409 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 410 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 411 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 412 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 413 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 414 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Exit:
# 415 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 416 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 417 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 418 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	set_invisible
# 419 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 420 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 421 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Exit:
# 422 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 423 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 424 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 425 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 426 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 427 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 428 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer:
# 429 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 430 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 431 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 432 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 433 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos:
# 434 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 435 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 436 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 437 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 438 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 439 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft:
# 440 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_left
# 441 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 442 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 443 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet:
# 444 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 2nd set of opponents is next.\n"
# 445 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 446 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 447 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet:
# 448 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 3rd set of opponents is next.\n"
# 449 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 450 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 451 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet:
# 452 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 4th set of opponents is next.\n"
# 453 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 454 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 455 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet:
# 456 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 5th set of opponents is next.\n"
# 457 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 458 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 459 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet:
# 460 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 6th set of opponents is next.\n"
# 461 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 462 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 463 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet:
# 464 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 7th set of opponents is next.\n"
# 465 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 466 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 467 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 468 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_2ndOpponentSetNext:
# 469 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 2nd set of opponents is next.\n"
# 470 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 471 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 472 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 473 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_3rdOpponentSetNext:
# 474 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 3rd set of opponents is next.\n"
# 475 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 476 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 477 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 478 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_4thOpponentSetNext:
# 479 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 4th set of opponents is next.\n"
# 480 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 481 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 482 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 483 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_5thOpponentSetNext:
# 484 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 5th set of opponents is next.\n"
# 485 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 486 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 487 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 488 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_6thOpponentSetNext:
# 489 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 6th set of opponents is next.\n"
# 490 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 491 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 492 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 493 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_7thOpponentSetNext:
# 494 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 7th set of opponents is next.\n"
# 495 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 496 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 497 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
gText_LinkStandby3::
# 498 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Link standby…$"
# 499 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 500 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
gText_YourPartnerHasRetired::
# 501 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Your partner has retired.\p"
# 502 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Your BATTLE ROOM challenge\n"
# 503 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "will be canceled.$"
