# 1 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ On this map the player will automatically walk into the room, but the camera is supposed to remain still.
# 3 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ To do this GF sets the player (LOCALID_PLAYER) invisible and creates a fake player object (LOCALID_DOME_PLAYER).
# 4 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ The graphics of this fake player object are represented with VAR_OBJ_GFX_ID_1.
# 5 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ The graphics of the opponent are represented with VAR_OBJ_GFX_ID_0, which will ultimately be set by dome_setopponentgfx.
# 6 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set NO_DRAW,       0
# 8 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set DRAW_TRAINER,  1
# 9 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set DRAW_TUCKER,   2
# 10 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_MapScripts::
# 12 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleDomeBattleRoom_OnTransition
# 13 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeBattleRoom_OnFrame
# 14 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeBattleRoom_OnWarp
# 15 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeBattleRoom_OnResume
# 16 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.byte 0
# 17 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 18 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnTransition:
# 19 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
# 20 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_setopponentgfx
# 21 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 22 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 23 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos
# 24 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 25 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 26 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 27 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx::
# 28 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	checkplayergender
# 29 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale
# 30 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale
# 31 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 32 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 33 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale::
# 34 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 35 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 36 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 37 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale::
# 38 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 39 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 40 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 41 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnFrame:
# 42 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom
# 43 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.2byte 0
# 44 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 45 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom::
# 46 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lockall
# 47 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 48 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat
# 49 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 50 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer
# 52 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome, MSGBOX_DEFAULT
# 53 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 54 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	showobjectat LOCALID_DOME_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
# 55 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter
# 56 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker
# 57 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter::
# 58 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter
# 59 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer
# 60 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 61 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker::
# 62 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker
# 63 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer::
# 64 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 65 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 66 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 67 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent
# 68 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker
# 69 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent::
# 70 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getopponentname
# 71 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer, MSGBOX_DEFAULT
# 72 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 73 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward
# 74 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward
# 75 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 76 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 77 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 78 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 79 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_initopponentparty
# 80 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
# 81 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, NO_DRAW
# 82 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 83 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
# 84 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
# 85 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
# 86 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, DRAW_TRAINER
# 87 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_Draw::
# 88 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait, MSGBOX_DEFAULT
# 89 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 90 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 91 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 92 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 93 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter
# 94 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 95 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft
# 96 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 97 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 180
# 98 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit
# 99 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 100 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_2, DRAW_TUCKER, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent @ Tucker always wins on a draw
# 101 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_compareseeds
# 102 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 103 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
# 104 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent::
# 105 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 106 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 107 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getopponentname
# 108 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, NO_DRAW, BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon
# 109 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TRAINER, BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw
# 110 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TUCKER, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw
# 111 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 112 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 113 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 114 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney::
# 115 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_LOST_MATCH
# 116 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobbyLost::
# 117 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 118 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby
# 119 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 120 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon::
# 121 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_gettrainername STR_VAR_2
# 122 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner
# 123 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 124 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 125 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 126 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw::
# 127 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_gettrainername STR_VAR_1
# 128 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer
# 129 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 130 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 131 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 132 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw::
# 133 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker
# 134 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 135 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 136 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 137 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent::
# 138 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 139 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 140 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, NO_DRAW, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon
# 141 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TRAINER, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw
# 142 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 143 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 144 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 145 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getroundtext
# 146 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 147 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 148 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 149 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 150 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 151 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUNDS_COUNT, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 152 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8006, 1
# 153 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 5, 3
# 154 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 155 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 156 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney::
# 157 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience
# 158 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 159 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 160 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 161 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney
# 162 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ, MSGBOX_DEFAULT
# 163 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin
# 164 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 165 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney::
# 166 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp, MSGBOX_DEFAULT
# 167 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin::
# 168 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special DoDomeConfetti
# 169 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 170 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 171 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 172 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 173 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby
# 174 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 175 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon::
# 176 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner, MSGBOX_DEFAULT
# 177 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 178 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 179 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw::
# 180 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer, MSGBOX_DEFAULT
# 181 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 182 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 183 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer::
# 184 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_ATTEMPTED_CHALLENGE
# 185 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt
# 186 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_HAS_WON_CHALLENGE
# 187 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon
# 188 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_WIN_STREAK_ACTIVE
# 189 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak
# 190 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion
# 191 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 192 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 193 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt::
# 194 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 195 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 196 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1
# 197 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2
# 198 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal
# 199 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal
# 200 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 201 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 202 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1::
# 203 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope
# 204 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 205 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 206 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 207 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2::
# 208 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RisingStar
# 209 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 210 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 211 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 212 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal::
# 213 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship
# 214 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 215 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 216 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 217 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal::
# 218 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry
# 219 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 220 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 221 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 222 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon::
# 223 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 224 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 225 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1
# 226 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2
# 227 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal
# 228 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal
# 229 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 230 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 231 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1::
# 232 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged
# 233 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 234 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 235 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 236 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2::
# 237 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship
# 238 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 239 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 240 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 241 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal::
# 242 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal
# 243 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 244 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 245 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 246 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal::
# 247 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue
# 248 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 249 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 250 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 251 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion::
# 252 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker
# 253 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 254 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
# 255 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
# 256 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
# 257 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
# 258 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker::
# 259 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 260 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 261 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1
# 262 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2
# 263 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal
# 264 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal
# 265 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 266 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 267 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1::
# 268 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion
# 269 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 270 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 271 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 272 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2::
# 273 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer
# 274 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 275 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 276 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 277 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal::
# 278 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer
# 279 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 280 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 281 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 282 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal::
# 283 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle
# 284 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 285 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 286 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 287 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver::
# 288 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster, MSGBOX_DEFAULT
# 289 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 290 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 291 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold::
# 292 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched, MSGBOX_DEFAULT
# 293 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 294 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 295 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak::
# 296 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 297 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 298 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1
# 299 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2
# 300 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal
# 301 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal
# 302 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 303 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 304 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1::
# 305 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned
# 306 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 307 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 308 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 309 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2::
# 310 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned
# 311 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 312 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 313 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 314 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal::
# 315 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals
# 316 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 317 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 318 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 319 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal::
# 320 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory
# 321 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 322 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 323 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 324 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum::
# 325 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 326 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 327 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 328 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker::
# 329 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 330 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
# 331 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold
# 332 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
# 333 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold
# 334 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 335 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver::
# 336 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker, MSGBOX_DEFAULT
# 337 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter
# 338 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 339 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold::
# 340 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker, MSGBOX_DEFAULT
# 341 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter::
# 342 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 343 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_AUDIENCE_TWIN, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump
# 344 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance
# 345 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance
# 346 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 347 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 348 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 349 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 350 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 351 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 352 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 353 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 354 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 355 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 356 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 357 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 358 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 359 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 360 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 361 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 362 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant
# 363 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 364 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 365 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 366 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 367 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 368 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro
# 369 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
# 370 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
# 371 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 372 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
# 373 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro, MSGBOX_DEFAULT
# 374 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 375 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver::
# 376 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy, MSGBOX_DEFAULT
# 377 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
# 378 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 379 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 380 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 381 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
# 382 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
# 383 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 384 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getsymbols
# 385 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 386 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 387 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
# 388 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 389 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass, MSGBOX_DEFAULT
# 390 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 391 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol
# 392 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 393 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitfanfare
# 394 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_givesymbol
# 395 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime, MSGBOX_DEFAULT
# 396 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 397 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 398 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro::
# 399 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 400 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
# 401 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro, MSGBOX_DEFAULT
# 402 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 403 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold::
# 404 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess, MSGBOX_DEFAULT
# 405 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
# 406 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 407 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 408 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 409 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
# 410 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
# 411 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 412 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getsymbols
# 413 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 414 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 415 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
# 416 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 417 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed, MSGBOX_DEFAULT
# 418 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 419 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine
# 420 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 421 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitfanfare
# 422 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_givesymbol
# 423 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter, MSGBOX_DEFAULT
# 424 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 425 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 426 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle::
# 427 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker, MSGBOX_DEFAULT
# 428 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 429 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2
# 430 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward
# 431 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 432 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
# 433 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 434 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 435 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker::
# 436 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker, MSGBOX_DEFAULT
# 437 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 438 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 439 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 440 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney
# 441 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 442 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw::
# 443 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, DRAW_TUCKER
# 444 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_Draw
# 445 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 446 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle::
# 447 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 448 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special HealPlayerParty
# 449 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_DOME
# 450 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 451 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_9, 1
# 452 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 453 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 454 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_9, 0
# 455 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_restorehelditems
# 456 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special HealPlayerParty
# 457 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resetsketch
# 458 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 459 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 460 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnWarp:
# 461 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects
# 462 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.2byte 0
# 463 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 464 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects::
# 465 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	hideobjectat LOCALID_DOME_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
# 466 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
# 467 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 468 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 469 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible
# 470 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 471 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
# 472 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 473 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_E, VAR_RESULT
# 474 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
# 475 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 476 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_DOME_OPPONENT, 13, 9
# 477 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	removeobject LOCALID_DOME_OPPONENT
# 478 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 1
# 479 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	addobject LOCALID_DOME_OPPONENT
# 480 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp
# 481 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects::
# 482 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 483 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 484 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnResume:
# 485 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience
# 486 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 487 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 488 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience::
# 489 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
# 490 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 491 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 492 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Add audience members to supplement the permanent object event audience
# 493 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience::
# 494 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience
# 495 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience
# 496 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience
# 497 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience
# 498 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 499 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 500 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience::
# 501 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 502 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 503 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience::
# 504 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 505 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 506 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 507 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 508 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 509 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0
# 510 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 511 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 512 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 513 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 514 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 515 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 516 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 517 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience::
# 518 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 519 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 520 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 521 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0
# 522 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 523 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0
# 524 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 525 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0
# 526 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1
# 527 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1
# 528 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1
# 529 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 530 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1
# 531 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 532 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1
# 533 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 534 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 535 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2
# 536 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 537 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2
# 538 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2
# 539 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 540 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 541 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience::
# 542 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 0, 2, 0
# 543 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 544 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 2, 15, 0
# 545 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 3, 5, 0
# 546 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 547 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 5, 7, 0
# 548 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 549 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0
# 550 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 8, 10, 0
# 551 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 552 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0
# 553 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 554 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 12, 14, 0
# 555 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 2
# 556 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 14, 12, 2
# 557 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1
# 558 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1
# 559 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1
# 560 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 18, 6, 1
# 561 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 562 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1
# 563 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_2, 21, 10, 1
# 564 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 565 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1
# 566 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 24, 14, 1
# 567 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 568 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 569 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_FAT_MAN, 27, 3, 2
# 570 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2
# 571 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 572 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2
# 573 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2
# 574 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 575 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 576 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible:
# 577 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_invisible
# 578 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 579 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 580 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter:
# 581 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 582 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 583 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 584 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 585 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 586 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 587 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward:
# 588 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 589 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 590 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 591 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience:
# 592 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 593 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 594 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 595 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Identical to Movement_PlayerEnter
# 596 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker:
# 597 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 598 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 599 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 600 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 601 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 602 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 603 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 604 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 605 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 606 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2:
# 607 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 608 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 609 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 610 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward:
# 611 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 612 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 613 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 614 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp:
# 615 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 616 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_invisible
# 617 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 618 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 619 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance:
# 620 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 621 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 622 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 623 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 624 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 625 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 626 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 627 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 628 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 629 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 630 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 631 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 632 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 633 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 634 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 635 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 636 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 637 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 638 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_fast_up
# 639 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_fast_up
# 640 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 641 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 642 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 643 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 644 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 645 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 646 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 647 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 648 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 649 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 650 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 651 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 652 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 653 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 654 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 655 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 656 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 657 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 658 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 659 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 660 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 661 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 662 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 663 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 664 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 665 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 666 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 667 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 668 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 669 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 670 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 671 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 672 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 673 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 674 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 675 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 676 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 677 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 678 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 679 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 680 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 681 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 682 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 683 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 684 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 685 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 686 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 687 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 688 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 689 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 690 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 691 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 692 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 693 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 694 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 695 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 696 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 697 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_slow_right
# 698 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 699 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_slow_right
# 700 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 701 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 702 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 703 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 704 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 705 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 706 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 707 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 708 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 709 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 710 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 711 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 712 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 713 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 714 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 715 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 716 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 717 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 718 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 719 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 720 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 721 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 722 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 723 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 724 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 725 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 726 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 727 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 728 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance:
# 729 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 730 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 731 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 732 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 733 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 734 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 735 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 736 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 737 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 738 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 739 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 740 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 741 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 742 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 743 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 744 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 745 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 746 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 747 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 748 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 749 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 750 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 751 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 752 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 753 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 754 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 755 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 756 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 757 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 758 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 759 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 760 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 761 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 762 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 763 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 764 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 765 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 766 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 767 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 768 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 769 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 770 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 771 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 772 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 773 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 774 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 775 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 776 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 777 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 778 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward:
# 779 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 780 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 781 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 782 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer:
# 783 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 784 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 785 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 786 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 787 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround::
# 788 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 0, DIR_EAST
# 789 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 2, DIR_EAST
# 790 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 4, DIR_EAST
# 791 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 6, DIR_EAST
# 792 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 8, DIR_EAST
# 793 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 10, DIR_WEST
# 794 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 12, DIR_WEST
# 795 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 14, DIR_WEST
# 796 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 16, DIR_WEST
# 797 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 18, DIR_WEST
# 798 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 20, DIR_EAST
# 799 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 22, DIR_EAST
# 800 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 24, DIR_EAST
# 801 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 26, DIR_EAST
# 802 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 28, DIR_EAST
# 803 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 30, DIR_EAST
# 804 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 805 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 0, DIR_SOUTH
# 806 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 2, DIR_SOUTH
# 807 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 4, DIR_SOUTH
# 808 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 6, DIR_SOUTH
# 809 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 8, DIR_SOUTH
# 810 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 10, DIR_SOUTH
# 811 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 12, DIR_SOUTH
# 812 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 14, DIR_SOUTH
# 813 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 16, DIR_SOUTH
# 814 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 18, DIR_SOUTH
# 815 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 20, DIR_SOUTH
# 816 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 22, DIR_SOUTH
# 817 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 24, DIR_SOUTH
# 818 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 26, DIR_SOUTH
# 819 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 28, DIR_SOUTH
# 820 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 30, DIR_SOUTH
# 821 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 822 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 1, DIR_EAST
# 823 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 3, DIR_EAST
# 824 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 5, DIR_EAST
# 825 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 7, DIR_EAST
# 826 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 9, DIR_EAST
# 827 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 11, DIR_WEST
# 828 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 13, DIR_WEST
# 829 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 15, DIR_WEST
# 830 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 17, DIR_WEST
# 831 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 19, DIR_WEST
# 832 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 21, DIR_EAST
# 833 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 23, DIR_EAST
# 834 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 25, DIR_EAST
# 835 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 27, DIR_WEST
# 836 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 31, DIR_WEST
# 837 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 838 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 1, DIR_SOUTH
# 839 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 3, DIR_SOUTH
# 840 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 5, DIR_SOUTH
# 841 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 7, DIR_SOUTH
# 842 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 9, DIR_SOUTH
# 843 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 11, DIR_SOUTH
# 844 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 13, DIR_SOUTH
# 845 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 15, DIR_SOUTH
# 846 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 17, DIR_SOUTH
# 847 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 19, DIR_SOUTH
# 848 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 21, DIR_SOUTH
# 849 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 23, DIR_SOUTH
# 850 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 25, DIR_SOUTH
# 851 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 27, DIR_SOUTH
# 852 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 31, DIR_SOUTH
# 853 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 854 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 855 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 856 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby::
# 857 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 858 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles
# 859 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 5, 11
# 860 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 861 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 862 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 863 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles::
# 864 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 17, 11
# 865 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 866 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 867 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 868 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ On round 1 there's a 50% chance that a specific audience member will walk to his seat
# 869 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos::
# 870 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	random 2
# 871 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_D, VAR_RESULT
# 872 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_D, 0, Common_EventScript_NopReturn
# 873 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_DOME_AUDIENCE_WALKING, 2, 0
# 874 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectmovementtype LOCALID_DOME_AUDIENCE_WALKING, MOVEMENT_TYPE_FACE_RIGHT
# 875 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 876 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 877 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat::
# 878 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_D, 0, Common_EventScript_NopReturn
# 879 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_AUDIENCE_WALKING, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat
# 880 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 881 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 882 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump:
# 883 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 884 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 885 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 886 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 887 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 888 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 889 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 890 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 891 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 892 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 893 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 894 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 895 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 896 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 897 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_down
# 898 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 899 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_down
# 900 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	enable_jump_landing_ground_effect
# 901 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 902 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 903 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat:
# 904 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 905 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 906 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 907 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 908 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 909 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 910 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 911 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter:
# 912 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 913 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 914 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 915 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 916 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 917 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 918 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft:
# 919 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 920 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 921 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 922 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit:
# 923 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 924 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 925 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 926 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 927 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 928 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 929 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome:
# 930 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} has entered the BATTLE DOME!$"
# 931 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 932 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer:
# 933 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{STR_VAR_1}\n"
# 934 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "match!\p"
# 935 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} versus {STR_VAR_2}!\p"
# 936 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let the battle begin!$"
# 937 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 938 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner:
# 939 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the winner!\n"
# 940 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 941 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 942 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner:
# 943 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{STR_VAR_2} is the winner!\n"
# 944 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 945 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 946 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ:
# 947 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Level 50\n"
# 948 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 949 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 950 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 951 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp:
# 952 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Open Level\n"
# 953 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 954 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 955 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 956 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait:
# 957 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "What an unbelievable finish!\n"
# 958 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "We have a double knockout!\p"
# 959 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "In this event, the Battle Tournament\n"
# 960 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "rules call for a REFEREE'S decision.\p"
# 961 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Please wait while the judging\n"
# 962 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "is under way.$"
# 963 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 964 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer:
# 965 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 966 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 967 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 968 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 969 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is {STR_VAR_1}!\l"
# 970 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 971 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 972 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer:
# 973 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 974 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 975 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 976 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 977 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is {PLAYER}!\l"
# 978 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 979 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 980 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope:
# 981 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The bright new hope!\p"
# 982 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 983 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 984 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RisingStar:
# 985 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The rising star!\p"
# 986 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 987 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 988 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship:
# 989 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will this TRAINER race to\n"
# 990 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the championship?\p"
# 991 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 992 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 993 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry:
# 994 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the feat of a championship\n"
# 995 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "on the first try be achieved?\p"
# 996 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 997 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 998 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged:
# 999 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the loss of the last match\n"
# 1000 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "be avenged?\p"
# 1001 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1002 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1003 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship:
# 1004 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The TRAINER is on fire for\n"
# 1005 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the first championship try!\p"
# 1006 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1007 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1008 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal:
# 1009 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "A win here means this TRAINER\n"
# 1010 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "advances to the final!\p"
# 1011 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1012 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1013 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue:
# 1014 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will the long-held dream of\n"
# 1015 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a championship finally come true?\p"
# 1016 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1017 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1018 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion:
# 1019 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The invincible champion!\p"
# 1020 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1021 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1022 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer:
# 1023 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can anyone hope to beat this\n"
# 1024 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TRAINER?\p"
# 1025 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1026 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1027 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer:
# 1028 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Do battles exist solely for\n"
# 1029 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "this TRAINER?\p"
# 1030 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1031 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1032 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle:
# 1033 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The current champion aiming to\n"
# 1034 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "retain the title!\p"
# 1035 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1036 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1037 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned:
# 1038 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The former champion has returned!\p"
# 1039 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1040 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1041 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned:
# 1042 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The former toughness has returned!\p"
# 1043 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1044 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1045 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals:
# 1046 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will this TRAINER do as expected\n"
# 1047 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "and advance to the finals?\p"
# 1048 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1049 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1050 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory:
# 1051 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will the former champ regain\n"
# 1052 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "lost glory?\p"
# 1053 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1054 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1055 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster:
# 1056 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Feel the glow of a true master!$"
# 1057 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1058 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker:
# 1059 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "And now… The TRAINER standing in\n"
# 1060 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER}'s record-setting path…\p"
# 1061 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes! The one and only!\n"
# 1062 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The BATTLE DOME COMMISSIONER!\l"
# 1063 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Our very own DOME ACE!\l"
# 1064 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Make way for TUCKER!$"
# 1065 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1066 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant:
# 1067 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Spectators: TUCKER! TUCKER!\n"
# 1068 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER! TUCKER! TUCKER!$"
# 1069 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1070 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro:
# 1071 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Ahahah!\p"
# 1072 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Do you hear it? This crowd!\n"
# 1073 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "They're all itching to see our match!\p"
# 1074 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Ahahah!\p"
# 1075 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I bet you're twitching all over from\n"
# 1076 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the tension of getting to battle me!\p"
# 1077 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "But don't you worry about a thing!\p"
# 1078 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I'm the no. 1 star of the BATTLE DOME!\n"
# 1079 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I, TUCKER the DOME ACE, will bathe you\l"
# 1080 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "in my brilliant glow!$"
# 1081 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1082 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy:
# 1083 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Your strategy!\n"
# 1084 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let's see it!$"
# 1085 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1086 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer:
# 1087 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Unbelievable! It's incredible!\n"
# 1088 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The victor is {PLAYER}!$"
# 1089 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1090 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker:
# 1091 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is TUCKER!\n"
# 1092 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The DOME ACE has prevailed!\p"
# 1093 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations, TUCKER!$"
# 1094 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1095 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass:
# 1096 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Rules are rules!\n"
# 1097 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let me see your FRONTIER PASS.$"
# 1098 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1099 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol:
# 1100 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The Tactics Symbol was embossed on\n"
# 1101 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 1102 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1103 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime:
# 1104 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "… … … … … …\p"
# 1105 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I sorely underestimated you. I won't\n"
# 1106 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "make the same mistake next time…$"
# 1107 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1108 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched:
# 1109 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the win streak be stretched?\n"
# 1110 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The confidence is there!$"
# 1111 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1112 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker:
# 1113 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Ladies and gentlemen!\n"
# 1114 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Boys, girls, and POKéMON!\p"
# 1115 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Finally!\n"
# 1116 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Finally, the legend has returned!\p"
# 1117 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes, the name of that legend!\n"
# 1118 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Our very own DOME ACE!\l"
# 1119 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "It's none other than TUCKER!$"
# 1120 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1121 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro:
# 1122 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Ah…\n"
# 1123 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The pummeling roar of the crowd…\l"
# 1124 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Their furnace-like heat of excitement…\l"
# 1125 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "This is a wonderful place…\p"
# 1126 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "To the crowd, I am the DOME ACE…\n"
# 1127 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I represent their hopes and dreams…\l"
# 1128 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must never fade from their sight…\p"
# 1129 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must burn!\n"
# 1130 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Brighter and more brilliant!\l"
# 1131 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must light all that gather here!$"
# 1132 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1133 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess:
# 1134 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I will unleash all the power that\n"
# 1135 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I possess! Right here and now!$"
# 1136 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1137 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed:
# 1138 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: You're genuinely fantastic!\p"
# 1139 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Never before! I haven't ever lost in the\n"
# 1140 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "times I've had to unleash my power.\p"
# 1141 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes, quite fantastic!\n"
# 1142 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Your FRONTIER PASS, please?$"
# 1143 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1144 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine:
# 1145 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The Tactics Symbol took on\n"
# 1146 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 1147 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1148 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter:
# 1149 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "You're strong, but above all,\n"
# 1150 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "you have a unique charm!\p"
# 1151 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "In you, I see a definite potential for\n"
# 1152 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a superstar like me.\p"
# 1153 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I will very much look forward to\n"
# 1154 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "our next encounter!$"
# 1155 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1156 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Unused
# 1157 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ2:
# 1158 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Level 50\n"
# 1159 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 1160 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1161 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1162 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Unused
# 1163 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp2:
# 1164 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Open Level\n"
# 1165 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 1166 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1167 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1168 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker:
# 1169 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The final match!\p"
# 1170 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} versus the DOME ACE, TUCKER!\p"
# 1171 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let the battle begin!$"
# 1172 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1173 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker:
# 1174 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 1175 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 1176 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 1177 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 1178 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is our very own DOME ACE!\l"
# 1179 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "It's TUCKER!\p"
# 1180 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations! And thank you!\n"
# 1181 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let's hear it for the DOME ACE, TUCKER!$"
