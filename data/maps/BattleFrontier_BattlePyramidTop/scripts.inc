# 1 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 2 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
.set LOCALID_BRANDON, 2
# 4 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 5 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_MapScripts::
# 6 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidTop_OnResume
# 7 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidTop_OnFrame
# 8 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidTop_OnTransition
# 9 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePyramidTop_OnWarp
# 10 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.byte 0
# 11 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 12 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_OnTransition:
# 13 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	pyramid_updatelight 200, PYRAMID_LIGHT_SET_RADIUS
# 14 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_F, 1
# 15 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 16 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 17 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_OnWarp:
# 18 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects
# 19 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.2byte 0
# 20 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 21 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects::
# 22 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_1, 1
# 23 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 24 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne VAR_TEMP_C, 0, BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects
# 25 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setobjectxyperm LOCALID_BRANDON, 0, 0
# 26 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects::
# 27 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 28 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 29 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_OnResume:
# 30 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_getbrainstatus
# 31 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus
# 32 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 33 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus::
# 34 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	copyvar VAR_TEMP_C, VAR_RESULT
# 35 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_getstatus
# 36 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	switch VAR_TEMP_CHALLENGE_STATUS
# 37 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case 0, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
# 38 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
# 39 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
# 40 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 41 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 42 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 43 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 44 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 45 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 46 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_OnFrame:
# 47 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic
# 48 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidTop_EventScript_ShowMapName
# 49 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.2byte 0
# 50 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 51 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic::
# 52 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playbgm MUS_B_PYRAMID_TOP, FALSE
# 53 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
# 54 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 55 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 56 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_ShowMapName::
# 57 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	special ShowMapNamePopup
# 58 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_F, 0
# 59 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 60 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 61 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge::
# 62 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	pyramid_save CHALLENGE_STATUS_SAVING
# 63 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	special SavePlayerParty
# 64 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 65 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	pyramid_settrainers
# 66 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 67 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_F, 1
# 68 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 69 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 70 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_Attendant::
# 71 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	lock
# 72 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	faceplayer
# 73 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne VAR_TEMP_D, 0, BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady
# 74 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne VAR_TEMP_C, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside
# 75 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo, MSGBOX_DEFAULT
# 76 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 77 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
# 78 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 79 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop
# 80 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 81 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath
# 82 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 83 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	message BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid
# 84 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmessage
# 85 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 86 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitfanfare
# 87 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 88 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon::
# 89 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 90 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
# 91 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitstate
# 92 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 93 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 94 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady::
# 95 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady, MSGBOX_DEFAULT
# 96 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 97 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 98 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 99 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside::
# 100 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere, MSGBOX_DEFAULT
# 101 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
# 102 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_D, 1
# 103 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 104 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 105 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 106 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon::
# 107 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	lockall
# 108 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	switch VAR_TEMP_C
# 109 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold
# 110 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
# 111 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
# 112 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 113 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
# 114 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	special SpawnCameraObject
# 115 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
# 116 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 117 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure, MSGBOX_DEFAULT
# 118 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 119 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 120 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
# 121 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 122 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon, MSGBOX_DEFAULT
# 123 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver
# 124 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 125 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 126 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech::
# 127 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
# 128 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 129 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver::
# 130 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle, MSGBOX_DEFAULT
# 131 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
# 132 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playbgm MUS_B_PYRAMID_TOP, FALSE
# 133 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver
# 134 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 135 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 136 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver::
# 137 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_getsymbols
# 138 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
# 139 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease, MSGBOX_DEFAULT
# 140 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 141 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	message BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol
# 142 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmessage
# 143 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitfanfare
# 144 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_givesymbol
# 145 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting, MSGBOX_DEFAULT
# 146 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
# 147 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 148 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold::
# 149 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 150 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
# 151 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	special SpawnCameraObject
# 152 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
# 153 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 154 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned, MSGBOX_DEFAULT
# 155 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 156 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 157 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
# 158 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 159 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter, MSGBOX_DEFAULT
# 160 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold
# 161 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 162 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 163 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech::
# 164 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
# 165 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 166 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold::
# 167 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_EverythingYouHave, MSGBOX_DEFAULT
# 168 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
# 169 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playbgm MUS_B_PYRAMID_TOP, FALSE
# 170 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold
# 171 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 172 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 173 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold::
# 174 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_getsymbols
# 175 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
# 176 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis, MSGBOX_DEFAULT
# 177 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 178 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	message BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine
# 179 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmessage
# 180 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitfanfare
# 181 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_givesymbol
# 182 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_FarewellForNow, MSGBOX_DEFAULT
# 183 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
# 184 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 185 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle::
# 186 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 187 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PYRAMID
# 188 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_0x8005, 0
# 189 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	special DoSpecialTrainerBattle
# 190 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitstate
# 191 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	return
# 192 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 193 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside:
# 194 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_right
# 195 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_in_place_faster_left
# 196 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	step_end
# 197 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 198 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath:
# 199 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_left
# 200 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_in_place_faster_up
# 201 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	step_end
# 202 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 203 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop:
# 204 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_up
# 205 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_up
# 206 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_up
# 207 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_up
# 208 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_up
# 209 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_in_place_faster_down
# 210 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	step_end
# 211 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 212 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer:
# 213 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_fast_down
# 214 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	step_end
# 215 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 216 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Movement_CameraPanUp:
# 217 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_slow_up
# 218 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_slow_up
# 219 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	delay_16
# 220 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	step_end
# 221 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 222 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo:
# 223 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "It is a delight to see you here!\n"
# 224 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "You have reached the summit of\l"
# 225 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "the BATTLE PYRAMID!\p"
# 226 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Above here is the PYRAMID's\n"
# 227 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "lookout point.\p"
# 228 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "It is a place open only to those\n"
# 229 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "who have conquered the PYRAMID.\p"
# 230 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Now, please!\n"
# 231 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Up you go!$"
# 232 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 233 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid:
# 234 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The PYRAMID's new conqueror!\n"
# 235 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Let the name {PLAYER} be known!$"
# 236 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 237 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere:
# 238 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "It is a delight to see you here!\p"
# 239 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Unfortunately, you were second by\n"
# 240 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "a mere fraction of time!\p"
# 241 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Our chief has already conquered\n"
# 242 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "the PYRAMID ahead of you.\p"
# 243 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "However, my young explorer…\n"
# 244 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "You are a TRAINER!\p"
# 245 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Assert your power and take the glory\n"
# 246 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "of the pinnacle from our chief!\p"
# 247 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Now, please! When you are ready,\n"
# 248 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "take one more step of courage!$"
# 249 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 250 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure:
# 251 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Young adventurer…\p"
# 252 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Wouldn't you agree that explorations\n"
# 253 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "are the grandest of adventures?\p"
# 254 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Your own wits!\p"
# 255 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Your own strength!\p"
# 256 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Your own POKéMON!\p"
# 257 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "And, above all, only your own courage\n"
# 258 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "to lead you through unknown worlds…$"
# 259 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 260 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon:
# 261 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Aah, yes, indeed this life is grand!\n"
# 262 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Grand, it is! Eh?\p"
# 263 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I'm BRANDON!\p"
# 264 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I'm the PYRAMID KING, which means\n"
# 265 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I'm in charge here.\p"
# 266 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Most people call me the chief!\p"
# 267 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "You coming here means you have\n"
# 268 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "that much confidence in yourself,\l"
# 269 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "am I right?\p"
# 270 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Hahahah!\n"
# 271 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "This should be exciting!$"
# 272 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 273 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle:
# 274 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Now, then!\n"
# 275 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Bring your courage to our battle!$"
# 276 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 277 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease:
# 278 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "BRANDON: Hahahah! Grand it was!\n"
# 279 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Grand, yes, indeed!\p"
# 280 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Well done! You've earned recognition!\n"
# 281 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Your FRONTIER PASS, please!$"
# 282 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 283 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol:
# 284 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The Brave Symbol was embossed on\n"
# 285 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "the FRONTIER PASS!$"
# 286 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 287 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting:
# 288 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Young explorer!\n"
# 289 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I look forward to our next meeting!$"
# 290 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 291 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned:
# 292 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "BRANDON: …You've finally returned,\n"
# 293 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "young explorer…\p"
# 294 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Your love of adventure seems to come\n"
# 295 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "deep from within your heart…\p"
# 296 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Yes… You are exactly as I was in\n"
# 297 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "my own youth…\p"
# 298 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "… … …Ah…\p"
# 299 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The passionate!\p"
# 300 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The dangerous!\p"
# 301 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The desperate!\p"
# 302 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Those days of death-defying,\n"
# 303 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "life-affirming adventures are back…$"
# 304 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 305 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter:
# 306 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Now, then!\p"
# 307 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I sense my own courage is off\n"
# 308 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "the meter!$"
# 309 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 310 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_EverythingYouHave:
# 311 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Everything you have!\n"
# 312 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I'm braced for it all!$"
# 313 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 314 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis:
# 315 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "BRANDON: Hahahah!\n"
# 316 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Remarkable!\l"
# 317 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Yes, it's grand, indeed!\p"
# 318 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Young explorer!\p"
# 319 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "You've bested me through and through!\n"
# 320 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Here! I want you to have this!$"
# 321 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 322 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine:
# 323 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The Brave Symbol took on\n"
# 324 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "a golden shine!$"
# 325 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 326 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_FarewellForNow:
# 327 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Ah, yes! It just goes to show that\n"
# 328 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I have much to learn still!\p"
# 329 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "May our paths cross again!\n"
# 330 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Farewell for now, young explorer!$"
# 331 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 332 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady:
# 333 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Now, when you are ready, take courage\n"
# 334 "data//maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "and step forward.$"
