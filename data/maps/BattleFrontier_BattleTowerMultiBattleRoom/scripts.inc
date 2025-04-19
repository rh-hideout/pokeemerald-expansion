# 1 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_OPPONENT_1, 1
# 3 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT_1, 2
# 4 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT_2, 3
# 5 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_OPPONENT_2, 4
# 6 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 5
# 7 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_PARTNER, 6
# 8 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 9 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_MapScripts::
# 10 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiBattleRoom_OnTransition
# 11 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_OnWarp
# 12 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_OnFrame
# 13 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.byte 0
# 14 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 15 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 16 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_F
# 17 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	@ The multi partner is represented by LOCALID_PARTNER, which has the gfx id VAR_OBJ_GFX_ID_E
# 18 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 19 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnTransition:
# 20 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetObjGfx
# 21 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetLinkPlayerGfx
# 22 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 23 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 24 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetObjGfx::
# 25 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setpartnergfx
# 26 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	checkplayergender
# 27 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetPlayerGfxFemale
# 28 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 29 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 30 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 31 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetPlayerGfxFemale::
# 32 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_MAY_NORMAL
# 33 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 34 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 35 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetLinkPlayerGfx::
# 36 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special SetBattleTowerLinkPlayerGfx
# 37 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 38 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 39 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnWarp:
# 40 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_HidePlayerObj
# 41 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.2byte 0
# 42 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 43 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_HidePlayerObj::
# 44 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM
# 45 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 46 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 47 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnFrame:
# 48 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_EnterRoom
# 49 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.2byte 0
# 50 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 51 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_EnterRoom::
# 52 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 53 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_PlayerEnterRoom
# 54 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_PartnerEnterRoom
# 55 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 56 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 57 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter
# 58 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 59 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 60 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 61 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 62 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 63 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 64 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 65 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 66 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 67 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter::
# 68 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setopponent
# 69 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT_1
# 70 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT_2
# 71 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Enter
# 72 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Enter
# 73 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 74 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoOpponentIntrosLink
# 75 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 76 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 15
# 77 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 78 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 79 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 80 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 81 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 1
# 82 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 83 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 84 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 85 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 86 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoTowerBattle
# 87 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 88 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoOpponentIntrosLink::
# 89 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 90 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 15
# 91 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 92 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 93 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll gStringVar4
# 94 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 95 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 96 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 1
# 97 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 98 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 99 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll gStringVar4
# 100 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 101 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 102 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoTowerBattle::
# 103 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 104 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 105 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DefeatedOpponents
# 106 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost::
# 107 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 108 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 109 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 110 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 111 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 112 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 113 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DefeatedOpponents::
# 114 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 115 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setbattlewon
# 116 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 117 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyWon
# 118 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Exit
# 119 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Exit
# 120 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 121 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT_1
# 122 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT_2
# 123 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 124 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 125 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 126 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 127 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 128 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 129 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetorePartyMsgLink
# 130 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
# 131 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RestoreParty
# 132 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 133 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetorePartyMsgLink::
# 134 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth
# 135 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 136 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 137 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RestoreParty::
# 138 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LoadPlayerParty
# 139 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_MULTI_PARTY_SIZE
# 140 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReconnectLink
# 141 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 142 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitfanfare
# 143 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special HealPlayerParty
# 144 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents::
# 145 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 146 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSet
# 147 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 148 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 149 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsNoRecord
# 150 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 151 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 152 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 153 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattle
# 154 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge
# 155 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge
# 156 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 157 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 158 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsNoRecord::
# 159 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 160 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 161 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 162 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge
# 163 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge
# 164 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 165 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 166 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattle::
# 167 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 168 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 169 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 170 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 171 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 172 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RecordBattle
# 173 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 174 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 175 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RecordBattle::
# 176 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 177 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 178 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 179 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge::
# 180 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 181 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 182 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 183 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_PauseChallenge
# 184 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 185 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 186 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge::
# 187 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
# 188 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 189 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 190 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 191 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 192 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 193 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 194 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 195 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge::
# 196 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	closemessage
# 197 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 198 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle
# 199 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle
# 200 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 201 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos
# 202 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos
# 203 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 204 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter
# 205 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 206 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 207 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyWon::
# 208 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 209 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 210 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 211 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 212 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 213 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 214 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_PauseChallenge::
# 215 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
# 216 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 217 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_save CHALLENGE_STATUS_PAUSED
# 218 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	playse SE_SAVE
# 219 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitse
# 220 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	fadescreen 1
# 221 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_reset
# 222 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 223 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 224 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSet::
# 225 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSetLink
# 226 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 227 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 228 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSet
# 229 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSet
# 230 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSet
# 231 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSet
# 232 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSet
# 233 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 6, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSet
# 234 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 235 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSet::
# 236 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet
# 237 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 238 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 239 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 240 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSet::
# 241 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet
# 242 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 243 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 244 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 245 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSet::
# 246 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet
# 247 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 248 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 249 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 250 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSet::
# 251 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet
# 252 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 253 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 254 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 255 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSet::
# 256 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet
# 257 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 258 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 259 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 260 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSet::
# 261 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet
# 262 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 263 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 264 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 265 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSetLink::
# 266 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 267 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 268 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSetLink
# 269 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSetLink
# 270 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSetLink
# 271 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSetLink
# 272 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSetLink
# 273 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 6, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSetLink
# 274 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 275 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSetLink::
# 276 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet
# 277 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 278 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 279 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 280 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 281 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSetLink::
# 282 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet
# 283 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 284 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 285 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 286 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 287 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSetLink::
# 288 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet
# 289 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 290 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 291 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 292 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 293 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSetLink::
# 294 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet
# 295 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 296 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 297 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 298 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 299 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSetLink::
# 300 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet
# 301 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 302 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 303 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 304 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 305 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSetLink::
# 306 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet
# 307 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 308 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 309 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 310 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 311 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_LinkDelayForMsg::
# 312 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 313 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 314 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 315 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 316 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink::
# 317 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_set FLAG_TEMP_2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLinkNoRecord
# 318 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 19, 6, MULTI_GO_ON_RECORD_RETIRE, TRUE
# 319 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 320 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink
# 321 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattleLink
# 322 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 323 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 324 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 325 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 326 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLinkNoRecord::
# 327 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 20, 8, MULTI_GO_ON_RETIRE, TRUE
# 328 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 329 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink
# 330 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 331 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 332 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 333 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 334 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink::
# 335 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, BATTLE_TOWER_LINK_CONTINUE
# 336 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 337 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message gText_LinkStandby3
# 338 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 339 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LinkRetireStatusWithBattleTowerPartner
# 340 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitstate
# 341 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, BATTLE_TOWER_LINKSTAT_CONTINUE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 342 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_LinkDelayForMsg
# 343 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 344 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 345 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattleLink::
# 346 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 347 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 348 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 349 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 350 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 351 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 352 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 353 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 354 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 355 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 356 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 357 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink::
# 358 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
# 359 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 360 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 361 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetireChallengeLink
# 362 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 363 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 364 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 365 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetireChallengeLink::
# 366 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, BATTLE_TOWER_LINK_RETIRE
# 367 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 368 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message gText_LinkStandby3
# 369 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 370 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LinkRetireStatusWithBattleTowerPartner
# 371 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitstate
# 372 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 373 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 374 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 375 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReconnectLink::
# 376 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special BattleTowerReconnectLink
# 377 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 378 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 379 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_PlayerEnterRoom:
# 380 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 381 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 382 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 383 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 384 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_right
# 385 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 386 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 387 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_PartnerEnterRoom:
# 388 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 389 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 390 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 391 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 392 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_right
# 393 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 394 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 395 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant:
# 396 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 397 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 398 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 399 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle:
# 400 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 401 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 402 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 403 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Enter:
# 404 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 405 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 406 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 407 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 408 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 409 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 410 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 411 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Enter:
# 412 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 413 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 414 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 415 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 416 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 417 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 418 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 419 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Exit:
# 420 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 421 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 422 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 423 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	set_invisible
# 424 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 425 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 426 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Exit:
# 427 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 428 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 429 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 430 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 431 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 432 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 433 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer:
# 434 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 435 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 436 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 437 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 438 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos:
# 439 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 440 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 441 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 442 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 443 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 444 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft:
# 445 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_left
# 446 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 447 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 448 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet:
# 449 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 2nd set of opponents is next.\n"
# 450 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 451 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 452 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet:
# 453 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 3rd set of opponents is next.\n"
# 454 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 455 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 456 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet:
# 457 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 4th set of opponents is next.\n"
# 458 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 459 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 460 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet:
# 461 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 5th set of opponents is next.\n"
# 462 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 463 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 464 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet:
# 465 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 6th set of opponents is next.\n"
# 466 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 467 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 468 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet:
# 469 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 7th set of opponents is next.\n"
# 470 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 471 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 472 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 473 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_2ndOpponentSetNext:
# 474 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 2nd set of opponents is next.\n"
# 475 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 476 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 477 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 478 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_3rdOpponentSetNext:
# 479 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 3rd set of opponents is next.\n"
# 480 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 481 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 482 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 483 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_4thOpponentSetNext:
# 484 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 4th set of opponents is next.\n"
# 485 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 486 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 487 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 488 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_5thOpponentSetNext:
# 489 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 5th set of opponents is next.\n"
# 490 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 491 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 492 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 493 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_6thOpponentSetNext:
# 494 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 6th set of opponents is next.\n"
# 495 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 496 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 497 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 498 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_7thOpponentSetNext:
# 499 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 7th set of opponents is next.\n"
# 500 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 501 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 502 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
gText_LinkStandby3::
# 503 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Link standby…$"
# 504 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 505 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
gText_YourPartnerHasRetired::
# 506 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Your partner has retired.\p"
# 507 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Your BATTLE ROOM challenge\n"
# 508 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "will be canceled.$"
