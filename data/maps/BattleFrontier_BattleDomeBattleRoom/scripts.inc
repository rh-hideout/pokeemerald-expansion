# 1 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_ANNOUNCER, 1
# 3 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_AUDIENCE_TWIN, 2
# 4 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_AUDIENCE_WALKING, 6
# 5 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_REFEREE, 9
# 6 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 13
# 7 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 15
# 8 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 9 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set NO_DRAW,       0
# 10 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set DRAW_TRAINER,  1
# 11 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set DRAW_TUCKER,   2
# 12 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 13 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_MapScripts::
# 14 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleDomeBattleRoom_OnTransition
# 15 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeBattleRoom_OnFrame
# 16 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeBattleRoom_OnWarp
# 17 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeBattleRoom_OnResume
# 18 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.byte 0
# 19 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 20 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnTransition:
# 21 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
# 22 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_setopponentgfx
# 23 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 24 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 25 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos
# 26 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 27 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 28 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 29 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx::
# 30 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	checkplayergender
# 31 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale
# 32 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale
# 33 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 34 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 35 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale::
# 36 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 37 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 38 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 39 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale::
# 40 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 41 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 42 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 43 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnFrame:
# 44 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom
# 45 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.2byte 0
# 46 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 47 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom::
# 48 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lockall
# 49 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 50 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat
# 51 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 52 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 53 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer
# 54 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome, MSGBOX_DEFAULT
# 55 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 56 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
# 57 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter
# 58 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker
# 59 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter::
# 60 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter
# 61 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer
# 62 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 63 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker::
# 64 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker
# 65 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer::
# 66 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 67 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 68 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 69 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent
# 70 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker
# 71 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent::
# 72 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getopponentname
# 73 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer, MSGBOX_DEFAULT
# 74 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 75 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward
# 76 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward
# 77 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 78 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 79 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 80 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 81 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_initopponentparty
# 82 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
# 83 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, NO_DRAW
# 84 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 85 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
# 86 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
# 87 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
# 88 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, DRAW_TRAINER
# 89 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_Draw::
# 90 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait, MSGBOX_DEFAULT
# 91 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 92 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 93 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 94 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 95 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter
# 96 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 97 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft
# 98 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 99 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 180
# 100 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit
# 101 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 102 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_2, DRAW_TUCKER, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent @ Tucker always wins on a draw
# 103 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_compareseeds
# 104 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 105 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
# 106 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent::
# 107 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 108 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 109 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getopponentname
# 110 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, NO_DRAW, BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon
# 111 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TRAINER, BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw
# 112 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TUCKER, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw
# 113 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 114 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 115 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 116 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney::
# 117 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_LOST_MATCH
# 118 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobbyLost::
# 119 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 120 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby
# 121 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 122 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon::
# 123 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_gettrainername STR_VAR_2
# 124 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner
# 125 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 126 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 127 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 128 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw::
# 129 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_gettrainername STR_VAR_1
# 130 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer
# 131 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 132 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 133 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 134 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw::
# 135 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker
# 136 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 137 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 138 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 139 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent::
# 140 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 141 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 142 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, NO_DRAW, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon
# 143 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TRAINER, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw
# 144 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 145 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 146 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 147 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getroundtext
# 148 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 149 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 150 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 151 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 152 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 153 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUNDS_COUNT, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 154 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8006, 1
# 155 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 5, 3
# 156 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 157 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 158 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney::
# 159 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience
# 160 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 161 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 162 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 163 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney
# 164 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ, MSGBOX_DEFAULT
# 165 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin
# 166 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 167 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney::
# 168 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp, MSGBOX_DEFAULT
# 169 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin::
# 170 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special DoDomeConfetti
# 171 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 172 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 173 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 174 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 175 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby
# 176 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 177 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon::
# 178 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner, MSGBOX_DEFAULT
# 179 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 180 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 181 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw::
# 182 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer, MSGBOX_DEFAULT
# 183 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 184 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 185 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer::
# 186 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_ATTEMPTED_CHALLENGE
# 187 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt
# 188 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_HAS_WON_CHALLENGE
# 189 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon
# 190 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_WIN_STREAK_ACTIVE
# 191 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak
# 192 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion
# 193 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 194 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 195 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt::
# 196 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 197 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 198 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1
# 199 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2
# 200 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal
# 201 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal
# 202 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 203 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 204 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1::
# 205 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope
# 206 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 207 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 208 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 209 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2::
# 210 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RisingStar
# 211 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 212 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 213 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 214 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal::
# 215 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship
# 216 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 217 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 218 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 219 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal::
# 220 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry
# 221 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 222 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 223 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 224 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon::
# 225 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 226 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 227 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1
# 228 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2
# 229 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal
# 230 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal
# 231 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 232 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 233 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1::
# 234 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged
# 235 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 236 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 237 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 238 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2::
# 239 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship
# 240 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 241 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 242 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 243 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal::
# 244 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal
# 245 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 246 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 247 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 248 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal::
# 249 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue
# 250 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 251 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 252 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 253 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion::
# 254 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker
# 255 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 256 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
# 257 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
# 258 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
# 259 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
# 260 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker::
# 261 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 262 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 263 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1
# 264 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2
# 265 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal
# 266 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal
# 267 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 268 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 269 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1::
# 270 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion
# 271 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 272 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 273 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 274 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2::
# 275 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer
# 276 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 277 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 278 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 279 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal::
# 280 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer
# 281 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 282 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 283 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 284 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal::
# 285 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle
# 286 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 287 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 288 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 289 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver::
# 290 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster, MSGBOX_DEFAULT
# 291 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 292 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 293 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold::
# 294 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched, MSGBOX_DEFAULT
# 295 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 296 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 297 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak::
# 298 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 299 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 300 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1
# 301 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2
# 302 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal
# 303 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal
# 304 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 305 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 306 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1::
# 307 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned
# 308 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 309 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 310 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 311 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2::
# 312 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned
# 313 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 314 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 315 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 316 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal::
# 317 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals
# 318 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 319 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 320 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 321 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal::
# 322 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory
# 323 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 324 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 325 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 326 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum::
# 327 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 328 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 329 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 330 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker::
# 331 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 332 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
# 333 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold
# 334 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
# 335 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold
# 336 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 337 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver::
# 338 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker, MSGBOX_DEFAULT
# 339 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter
# 340 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 341 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold::
# 342 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker, MSGBOX_DEFAULT
# 343 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter::
# 344 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 345 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_AUDIENCE_TWIN, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump
# 346 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance
# 347 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance
# 348 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 349 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 350 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 351 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 352 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 353 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 354 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 355 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 356 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 357 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 358 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 359 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 360 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 361 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 362 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 363 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 364 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant
# 365 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 366 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 367 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 368 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 369 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 370 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro
# 371 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
# 372 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
# 373 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 374 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
# 375 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro, MSGBOX_DEFAULT
# 376 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 377 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver::
# 378 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy, MSGBOX_DEFAULT
# 379 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
# 380 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 381 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 382 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 383 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
# 384 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
# 385 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 386 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getsymbols
# 387 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 388 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 389 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
# 390 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 391 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass, MSGBOX_DEFAULT
# 392 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 393 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol
# 394 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 395 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitfanfare
# 396 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_givesymbol
# 397 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime, MSGBOX_DEFAULT
# 398 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 399 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 400 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro::
# 401 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 402 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
# 403 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro, MSGBOX_DEFAULT
# 404 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 405 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold::
# 406 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess, MSGBOX_DEFAULT
# 407 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
# 408 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 409 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 410 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 411 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
# 412 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
# 413 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 414 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getsymbols
# 415 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 416 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 417 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
# 418 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 419 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed, MSGBOX_DEFAULT
# 420 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 421 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine
# 422 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 423 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitfanfare
# 424 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_givesymbol
# 425 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter, MSGBOX_DEFAULT
# 426 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 427 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 428 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle::
# 429 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker, MSGBOX_DEFAULT
# 430 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 431 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2
# 432 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward
# 433 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 434 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
# 435 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 436 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 437 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker::
# 438 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker, MSGBOX_DEFAULT
# 439 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 440 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 441 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 442 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney
# 443 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 444 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw::
# 445 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, DRAW_TUCKER
# 446 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_Draw
# 447 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 448 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle::
# 449 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 450 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special HealPlayerParty
# 451 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_DOME
# 452 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 453 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_9, 1
# 454 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 455 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 456 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_9, 0
# 457 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_restorehelditems
# 458 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special HealPlayerParty
# 459 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resetsketch
# 460 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 461 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 462 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnWarp:
# 463 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects
# 464 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.2byte 0
# 465 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 466 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects::
# 467 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
# 468 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
# 469 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 470 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 471 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible
# 472 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 473 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
# 474 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 475 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_E, VAR_RESULT
# 476 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
# 477 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 478 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_OPPONENT, 13, 9
# 479 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 480 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 481 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp
# 482 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects::
# 483 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 484 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 485 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnResume:
# 486 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience
# 487 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 488 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 489 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience::
# 490 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
# 491 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 492 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 493 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Add audience members to supplement the permanent object event audience
# 494 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience::
# 495 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience
# 496 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience
# 497 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience
# 498 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience
# 499 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 500 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 501 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience::
# 502 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 503 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 504 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience::
# 505 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 506 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 507 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 508 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 509 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 510 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0
# 511 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 512 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 513 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 514 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 515 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 516 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 517 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 518 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience::
# 519 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 520 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 521 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 522 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0
# 523 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 524 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0
# 525 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 526 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0
# 527 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1
# 528 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1
# 529 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1
# 530 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 531 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1
# 532 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 533 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1
# 534 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 535 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 536 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2
# 537 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 538 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2
# 539 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2
# 540 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 541 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 542 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience::
# 543 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 0, 2, 0
# 544 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 545 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 2, 15, 0
# 546 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 3, 5, 0
# 547 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 548 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 5, 7, 0
# 549 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 550 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0
# 551 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 8, 10, 0
# 552 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 553 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0
# 554 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 555 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 12, 14, 0
# 556 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 2
# 557 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 14, 12, 2
# 558 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1
# 559 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1
# 560 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1
# 561 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 18, 6, 1
# 562 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 563 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1
# 564 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_2, 21, 10, 1
# 565 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 566 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1
# 567 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 24, 14, 1
# 568 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 569 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 570 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_FAT_MAN, 27, 3, 2
# 571 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2
# 572 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 573 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2
# 574 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2
# 575 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 576 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 577 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible:
# 578 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_invisible
# 579 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 580 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 581 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter:
# 582 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 583 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 584 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 585 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 586 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 587 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 588 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward:
# 589 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 590 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 591 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 592 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience:
# 593 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 594 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 595 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 596 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Identical to Movement_PlayerEnter
# 597 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker:
# 598 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 599 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 600 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 601 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 602 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 603 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 604 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 605 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 606 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 607 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2:
# 608 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 609 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 610 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 611 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward:
# 612 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 613 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 614 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 615 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp:
# 616 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 617 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_invisible
# 618 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 619 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 620 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance:
# 621 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 622 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 623 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 624 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 625 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 626 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 627 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 628 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 629 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 630 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 631 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 632 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 633 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 634 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 635 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 636 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 637 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 638 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 639 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_fast_up
# 640 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_fast_up
# 641 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 642 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 643 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 644 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 645 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 646 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 647 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 648 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 649 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 650 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 651 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 652 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 653 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 654 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 655 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 656 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 657 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 658 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 659 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 660 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 661 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 662 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 663 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 664 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 665 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 666 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 667 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 668 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 669 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 670 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 671 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 672 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 673 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 674 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 675 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 676 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 677 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 678 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 679 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 680 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 681 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 682 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 683 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 684 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 685 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 686 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 687 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 688 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 689 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 690 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 691 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 692 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 693 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 694 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 695 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 696 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 697 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 698 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_slow_right
# 699 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 700 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_slow_right
# 701 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 702 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 703 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 704 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 705 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 706 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 707 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 708 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 709 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 710 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 711 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 712 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 713 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 714 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 715 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 716 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 717 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 718 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 719 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 720 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 721 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 722 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 723 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 724 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 725 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 726 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 727 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 728 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 729 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance:
# 730 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 731 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 732 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 733 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 734 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 735 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 736 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 737 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 738 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 739 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 740 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 741 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 742 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 743 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 744 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 745 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 746 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 747 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 748 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 749 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 750 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 751 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 752 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 753 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 754 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 755 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 756 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 757 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 758 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 759 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 760 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 761 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 762 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 763 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 764 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 765 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 766 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 767 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 768 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 769 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 770 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 771 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 772 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 773 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 774 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 775 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 776 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 777 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 778 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 779 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward:
# 780 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 781 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 782 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 783 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer:
# 784 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 785 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 786 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 787 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 788 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround::
# 789 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 0, DIR_EAST
# 790 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 2, DIR_EAST
# 791 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 4, DIR_EAST
# 792 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 6, DIR_EAST
# 793 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 8, DIR_EAST
# 794 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 10, DIR_WEST
# 795 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 12, DIR_WEST
# 796 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 14, DIR_WEST
# 797 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 16, DIR_WEST
# 798 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 18, DIR_WEST
# 799 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 20, DIR_EAST
# 800 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 22, DIR_EAST
# 801 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 24, DIR_EAST
# 802 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 26, DIR_EAST
# 803 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 28, DIR_EAST
# 804 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 30, DIR_EAST
# 805 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 806 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 0, DIR_SOUTH
# 807 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 2, DIR_SOUTH
# 808 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 4, DIR_SOUTH
# 809 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 6, DIR_SOUTH
# 810 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 8, DIR_SOUTH
# 811 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 10, DIR_SOUTH
# 812 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 12, DIR_SOUTH
# 813 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 14, DIR_SOUTH
# 814 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 16, DIR_SOUTH
# 815 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 18, DIR_SOUTH
# 816 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 20, DIR_SOUTH
# 817 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 22, DIR_SOUTH
# 818 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 24, DIR_SOUTH
# 819 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 26, DIR_SOUTH
# 820 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 28, DIR_SOUTH
# 821 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 30, DIR_SOUTH
# 822 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 823 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 1, DIR_EAST
# 824 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 3, DIR_EAST
# 825 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 5, DIR_EAST
# 826 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 7, DIR_EAST
# 827 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 9, DIR_EAST
# 828 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 11, DIR_WEST
# 829 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 13, DIR_WEST
# 830 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 15, DIR_WEST
# 831 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 17, DIR_WEST
# 832 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 19, DIR_WEST
# 833 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 21, DIR_EAST
# 834 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 23, DIR_EAST
# 835 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 25, DIR_EAST
# 836 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 27, DIR_WEST
# 837 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 31, DIR_WEST
# 838 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 839 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 1, DIR_SOUTH
# 840 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 3, DIR_SOUTH
# 841 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 5, DIR_SOUTH
# 842 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 7, DIR_SOUTH
# 843 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 9, DIR_SOUTH
# 844 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 11, DIR_SOUTH
# 845 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 13, DIR_SOUTH
# 846 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 15, DIR_SOUTH
# 847 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 17, DIR_SOUTH
# 848 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 19, DIR_SOUTH
# 849 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 21, DIR_SOUTH
# 850 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 23, DIR_SOUTH
# 851 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 25, DIR_SOUTH
# 852 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 27, DIR_SOUTH
# 853 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 31, DIR_SOUTH
# 854 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 855 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 856 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 857 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby::
# 858 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 859 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles
# 860 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 5, 11
# 861 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 862 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 863 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 864 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles::
# 865 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 17, 11
# 866 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 867 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 868 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 869 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ On round 1 there's a 50% chance that a specific audience member will walk to his seat
# 870 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos::
# 871 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	random 2
# 872 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_D, VAR_RESULT
# 873 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_D, 0, Common_EventScript_NopReturn
# 874 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_AUDIENCE_WALKING, 2, 0
# 875 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectmovementtype LOCALID_AUDIENCE_WALKING, MOVEMENT_TYPE_FACE_RIGHT
# 876 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 877 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 878 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat::
# 879 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_D, 0, Common_EventScript_NopReturn
# 880 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_AUDIENCE_WALKING, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat
# 881 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 882 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 883 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump:
# 884 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 885 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 886 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 887 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 888 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 889 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 890 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 891 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 892 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 893 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 894 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 895 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 896 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 897 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 898 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_down
# 899 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 900 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_down
# 901 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	enable_jump_landing_ground_effect
# 902 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 903 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 904 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat:
# 905 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 906 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 907 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 908 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 909 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 910 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 911 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 912 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter:
# 913 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 914 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 915 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 916 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 917 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 918 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 919 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft:
# 920 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 921 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 922 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 923 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit:
# 924 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 925 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 926 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 927 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 928 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 929 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 930 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome:
# 931 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} has entered the BATTLE DOME!$"
# 932 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 933 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer:
# 934 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{STR_VAR_1}\n"
# 935 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "match!\p"
# 936 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} versus {STR_VAR_2}!\p"
# 937 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let the battle begin!$"
# 938 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 939 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner:
# 940 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the winner!\n"
# 941 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 942 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 943 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner:
# 944 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{STR_VAR_2} is the winner!\n"
# 945 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 946 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 947 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ:
# 948 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Level 50\n"
# 949 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 950 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 951 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 952 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp:
# 953 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Open Level\n"
# 954 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 955 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 956 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 957 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait:
# 958 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "What an unbelievable finish!\n"
# 959 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "We have a double knockout!\p"
# 960 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "In this event, the Battle Tournament\n"
# 961 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "rules call for a REFEREE'S decision.\p"
# 962 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Please wait while the judging\n"
# 963 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "is under way.$"
# 964 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 965 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer:
# 966 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 967 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 968 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 969 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 970 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is {STR_VAR_1}!\l"
# 971 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 972 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 973 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer:
# 974 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 975 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 976 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 977 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 978 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is {PLAYER}!\l"
# 979 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 980 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 981 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope:
# 982 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The bright new hope!\p"
# 983 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 984 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 985 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RisingStar:
# 986 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The rising star!\p"
# 987 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 988 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 989 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship:
# 990 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will this TRAINER race to\n"
# 991 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the championship?\p"
# 992 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 993 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 994 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry:
# 995 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the feat of a championship\n"
# 996 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "on the first try be achieved?\p"
# 997 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 998 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 999 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged:
# 1000 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the loss of the last match\n"
# 1001 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "be avenged?\p"
# 1002 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1003 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1004 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship:
# 1005 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The TRAINER is on fire for\n"
# 1006 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the first championship try!\p"
# 1007 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1008 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1009 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal:
# 1010 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "A win here means this TRAINER\n"
# 1011 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "advances to the final!\p"
# 1012 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1013 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1014 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue:
# 1015 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will the long-held dream of\n"
# 1016 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a championship finally come true?\p"
# 1017 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1018 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1019 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion:
# 1020 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The invincible champion!\p"
# 1021 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1022 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1023 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer:
# 1024 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can anyone hope to beat this\n"
# 1025 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TRAINER?\p"
# 1026 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1027 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1028 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer:
# 1029 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Do battles exist solely for\n"
# 1030 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "this TRAINER?\p"
# 1031 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1032 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1033 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle:
# 1034 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The current champion aiming to\n"
# 1035 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "retain the title!\p"
# 1036 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1037 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1038 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned:
# 1039 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The former champion has returned!\p"
# 1040 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1041 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1042 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned:
# 1043 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The former toughness has returned!\p"
# 1044 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1045 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1046 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals:
# 1047 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will this TRAINER do as expected\n"
# 1048 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "and advance to the finals?\p"
# 1049 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1050 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1051 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory:
# 1052 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will the former champ regain\n"
# 1053 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "lost glory?\p"
# 1054 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1055 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1056 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster:
# 1057 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Feel the glow of a true master!$"
# 1058 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1059 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker:
# 1060 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "And now… The TRAINER standing in\n"
# 1061 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER}'s record-setting path…\p"
# 1062 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes! The one and only!\n"
# 1063 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The BATTLE DOME COMMISSIONER!\l"
# 1064 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Our very own DOME ACE!\l"
# 1065 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Make way for TUCKER!$"
# 1066 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1067 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant:
# 1068 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Spectators: TUCKER! TUCKER!\n"
# 1069 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER! TUCKER! TUCKER!$"
# 1070 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1071 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro:
# 1072 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Ahahah!\p"
# 1073 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Do you hear it? This crowd!\n"
# 1074 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "They're all itching to see our match!\p"
# 1075 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Ahahah!\p"
# 1076 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I bet you're twitching all over from\n"
# 1077 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the tension of getting to battle me!\p"
# 1078 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "But don't you worry about a thing!\p"
# 1079 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I'm the no. 1 star of the BATTLE DOME!\n"
# 1080 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I, TUCKER the DOME ACE, will bathe you\l"
# 1081 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "in my brilliant glow!$"
# 1082 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1083 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy:
# 1084 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Your strategy!\n"
# 1085 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let's see it!$"
# 1086 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1087 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer:
# 1088 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Unbelievable! It's incredible!\n"
# 1089 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The victor is {PLAYER}!$"
# 1090 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1091 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker:
# 1092 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is TUCKER!\n"
# 1093 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The DOME ACE has prevailed!\p"
# 1094 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations, TUCKER!$"
# 1095 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1096 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass:
# 1097 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Rules are rules!\n"
# 1098 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let me see your FRONTIER PASS.$"
# 1099 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1100 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol:
# 1101 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The Tactics Symbol was embossed on\n"
# 1102 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 1103 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1104 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime:
# 1105 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "… … … … … …\p"
# 1106 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I sorely underestimated you. I won't\n"
# 1107 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "make the same mistake next time…$"
# 1108 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1109 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched:
# 1110 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the win streak be stretched?\n"
# 1111 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The confidence is there!$"
# 1112 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1113 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker:
# 1114 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Ladies and gentlemen!\n"
# 1115 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Boys, girls, and POKéMON!\p"
# 1116 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Finally!\n"
# 1117 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Finally, the legend has returned!\p"
# 1118 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes, the name of that legend!\n"
# 1119 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Our very own DOME ACE!\l"
# 1120 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "It's none other than TUCKER!$"
# 1121 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1122 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro:
# 1123 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Ah…\n"
# 1124 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The pummeling roar of the crowd…\l"
# 1125 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Their furnace-like heat of excitement…\l"
# 1126 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "This is a wonderful place…\p"
# 1127 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "To the crowd, I am the DOME ACE…\n"
# 1128 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I represent their hopes and dreams…\l"
# 1129 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must never fade from their sight…\p"
# 1130 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must burn!\n"
# 1131 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Brighter and more brilliant!\l"
# 1132 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must light all that gather here!$"
# 1133 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1134 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess:
# 1135 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I will unleash all the power that\n"
# 1136 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I possess! Right here and now!$"
# 1137 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1138 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed:
# 1139 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: You're genuinely fantastic!\p"
# 1140 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Never before! I haven't ever lost in the\n"
# 1141 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "times I've had to unleash my power.\p"
# 1142 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes, quite fantastic!\n"
# 1143 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Your FRONTIER PASS, please?$"
# 1144 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1145 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine:
# 1146 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The Tactics Symbol took on\n"
# 1147 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 1148 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1149 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter:
# 1150 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "You're strong, but above all,\n"
# 1151 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "you have a unique charm!\p"
# 1152 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "In you, I see a definite potential for\n"
# 1153 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a superstar like me.\p"
# 1154 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I will very much look forward to\n"
# 1155 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "our next encounter!$"
# 1156 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1157 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Unused
# 1158 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ2:
# 1159 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Level 50\n"
# 1160 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 1161 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1162 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1163 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Unused
# 1164 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp2:
# 1165 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Open Level\n"
# 1166 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 1167 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1168 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1169 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker:
# 1170 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The final match!\p"
# 1171 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} versus the DOME ACE, TUCKER!\p"
# 1172 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let the battle begin!$"
# 1173 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1174 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker:
# 1175 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 1176 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 1177 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 1178 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 1179 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is our very own DOME ACE!\l"
# 1180 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "It's TUCKER!\p"
# 1181 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations! And thank you!\n"
# 1182 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let's hear it for the DOME ACE, TUCKER!$"
