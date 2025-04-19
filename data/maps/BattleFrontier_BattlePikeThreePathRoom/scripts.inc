# 1 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
.set LOCALID_HINT_GIVER, 2
# 3 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 4 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_MapScripts::
# 5 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
# 6 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnFrame
# 7 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnWarp
# 8 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.byte 0
# 9 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 10 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_OnFrame:
# 11 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus
# 12 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby
# 13 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge
# 14 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	map_script_2 VAR_TEMP_5, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom
# 15 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	map_script_2 VAR_TEMP_5, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint
# 16 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.2byte 0
# 17 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 18 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_OnWarp:
# 19 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth
# 20 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.2byte 0
# 21 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 22 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth::
# 23 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	setvar VAR_TEMP_4, 1
# 24 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 25 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 26 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 27 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus::
# 28 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	frontier_getstatus
# 29 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 30 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 31 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby::
# 32 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
# 33 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	waitstate
# 34 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 35 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 36 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge::
# 37 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	lockall
# 38 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	message BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume
# 39 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	waitmessage
# 40 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	pike_save CHALLENGE_STATUS_SAVING
# 41 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	playse SE_SAVE
# 42 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	waitse
# 43 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 44 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 45 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	special SavePlayerParty
# 46 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 47 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge, MSGBOX_DEFAULT
# 48 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	closemessage
# 49 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	releaseall
# 50 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	frontier_settrainers
# 51 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 99
# 52 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 53 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 54 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant::
# 55 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Room number
# 56 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	switch VAR_RESULT
# 57 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1
# 58 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case 3, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3
# 59 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case 5, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5
# 60 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case 7, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7
# 61 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case 9, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9
# 62 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case 11, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11
# 63 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case 13, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13
# 64 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 65 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 66 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1::
# 67 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	lock
# 68 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	faceplayer
# 69 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1, MSGBOX_DEFAULT
# 70 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
# 71 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 72 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 73 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3::
# 74 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	lock
# 75 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	faceplayer
# 76 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3, MSGBOX_DEFAULT
# 77 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
# 78 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 79 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 80 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5::
# 81 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	lock
# 82 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	faceplayer
# 83 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5, MSGBOX_DEFAULT
# 84 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
# 85 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 86 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 87 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7::
# 88 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	lock
# 89 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	faceplayer
# 90 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7, MSGBOX_DEFAULT
# 91 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
# 92 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 93 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 94 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9::
# 95 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	lock
# 96 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	faceplayer
# 97 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9, MSGBOX_DEFAULT
# 98 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
# 99 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 100 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 101 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11::
# 102 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	lock
# 103 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	faceplayer
# 104 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11, MSGBOX_DEFAULT
# 105 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
# 106 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 107 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 108 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13::
# 109 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	lock
# 110 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	faceplayer
# 111 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13, MSGBOX_DEFAULT
# 112 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
# 113 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 114 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 115 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge::
# 116 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge, MSGBOX_YESNO
# 117 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	switch VAR_RESULT
# 118 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
# 119 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
# 120 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	release
# 121 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 122 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 123 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge::
# 124 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	frontier_saveparty
# 125 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	message BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData
# 126 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	waitmessage
# 127 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	special LoadPlayerParty
# 128 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	pike_save CHALLENGE_STATUS_PAUSED
# 129 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	playse SE_SAVE
# 130 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	waitse
# 131 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 132 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	frontier_reset
# 133 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 134 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 135 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge::
# 136 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit, MSGBOX_YESNO
# 137 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	switch VAR_RESULT
# 138 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge
# 139 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
# 140 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
# 141 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	release
# 142 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 143 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 144 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge::
# 145 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	message BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge
# 146 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	waitmessage
# 147 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 148 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	switch VAR_RESULT
# 149 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case 0, BattleFrontier_BattlePike_EventScript_Retire
# 150 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	release
# 151 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 152 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 153 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom::
# 154 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	pike_sethintroom
# 155 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint
# 156 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	setvar VAR_TEMP_5, 255
# 157 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 158 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 159 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint::
# 160 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	setvar VAR_TEMP_5, 1
# 161 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 162 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 163 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint::
# 164 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	applymovement LOCALID_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer
# 165 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	waitmovement 0
# 166 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	lockall
# 167 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent, MSGBOX_DEFAULT
# 168 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	releaseall
# 169 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	applymovement LOCALID_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos
# 170 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	waitmovement 0
# 171 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	setvar VAR_TEMP_5, 255
# 172 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 173 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 174 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_HintGiver::
# 175 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	pike_gethint
# 176 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto_if_eq VAR_RESULT, PIKE_HINT_BRAIN, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint
# 177 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	lock
# 178 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	faceplayer
# 179 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose, MSGBOX_YESNO
# 180 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	switch VAR_RESULT
# 181 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint
# 182 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
# 183 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
# 184 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	release
# 185 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 186 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 187 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint::
# 188 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence, MSGBOX_DEFAULT
# 189 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	release
# 190 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 191 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 192 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint::
# 193 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	pike_gethintroomid
# 194 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	switch VAR_RESULT
# 195 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case PIKE_ROOM_LEFT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint
# 196 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case PIKE_ROOM_CENTER, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint
# 197 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case PIKE_ROOM_RIGHT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint
# 198 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 199 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 200 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint::
# 201 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath, MSGBOX_DEFAULT
# 202 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint
# 203 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 204 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint::
# 205 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath, MSGBOX_DEFAULT
# 206 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint
# 207 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 208 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint::
# 209 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath, MSGBOX_DEFAULT
# 210 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint
# 211 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 212 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint::
# 213 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	pike_gethint
# 214 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	switch VAR_RESULT
# 215 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case PIKE_HINT_NOSTALGIA, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia
# 216 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case PIKE_HINT_WHISPERING, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering
# 217 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case PIKE_HINT_POKEMON, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon
# 218 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	case PIKE_HINT_PEOPLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople
# 219 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 220 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 221 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia::
# 222 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga, MSGBOX_DEFAULT
# 223 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	release
# 224 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 225 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 226 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering::
# 227 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering, MSGBOX_DEFAULT
# 228 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	release
# 229 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 230 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 231 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon::
# 232 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon, MSGBOX_DEFAULT
# 233 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	release
# 234 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 235 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 236 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople::
# 237 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople, MSGBOX_DEFAULT
# 238 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	release
# 239 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 240 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 241 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint::
# 242 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	lock
# 243 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	faceplayer
# 244 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence, MSGBOX_DEFAULT
# 245 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	release
# 246 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	end
# 247 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 248 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer:
# 249 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_left
# 250 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_left
# 251 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_down
# 252 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_down
# 253 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_down
# 254 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_down
# 255 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	step_end
# 256 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 257 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos:
# 258 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_up
# 259 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_up
# 260 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_up
# 261 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_up
# 262 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_right
# 263 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	walk_right
# 264 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	face_down
# 265 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	step_end
# 266 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 267 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1:
# 268 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "You are currently in\n"
# 269 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "the 1st room…$"
# 270 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 271 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3:
# 272 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "You are currently in\n"
# 273 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "the 3rd room…$"
# 274 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 275 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5:
# 276 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "You are currently in\n"
# 277 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "the 5th room…$"
# 278 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 279 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7:
# 280 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "You are currently in\n"
# 281 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "the 7th room…$"
# 282 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 283 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9:
# 284 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "You are currently in\n"
# 285 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "the 9th room…$"
# 286 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 287 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11:
# 288 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "You are currently in\n"
# 289 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "the 11th room…$"
# 290 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 291 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13:
# 292 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "You are currently in\n"
# 293 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "the 13th room…$"
# 294 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 295 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge:
# 296 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "Will you continue with\n"
# 297 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "your challenge?$"
# 298 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 299 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit:
# 300 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "Would you like to save your challenge\n"
# 301 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "and quit the game for now?$"
# 302 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 303 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge:
# 304 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "Do you wish to retire from your\n"
# 305 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "Battle Choice challenge?$"
# 306 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 307 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume:
# 308 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "We've been awaiting your return…\p"
# 309 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "Before resuming your Battle Choice\n"
# 310 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "challenge, let me save the game…$"
# 311 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 312 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge:
# 313 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "Please do enjoy your Battle Choice\n"
# 314 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "challenge…$"
# 315 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 316 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData:
# 317 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "I am saving your data…\n"
# 318 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "A little time, please…$"
# 319 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 320 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack:
# 321 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "The path is blocked!\n"
# 322 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "And there is no turning back…$"
# 323 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 324 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose:
# 325 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "I beg your pardon, but…\p"
# 326 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "Are you perhaps finding it difficult\n"
# 327 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "to choose your path?$"
# 328 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 329 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence:
# 330 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "I see…\n"
# 331 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "I apologize for my impertinence…$"
# 332 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 333 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath:
# 334 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "Ah, let me see… There is something\n"
# 335 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "about the path on the right…$"
# 336 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 337 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath:
# 338 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "Ah, let me see… There is something\n"
# 339 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "about the path in the center…$"
# 340 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 341 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath:
# 342 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "Ah, let me see… There is something\n"
# 343 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "about the path on the left…$"
# 344 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 345 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon:
# 346 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "It seems to have the distinct aroma\n"
# 347 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "of POKéMON wafting around it…$"
# 348 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 349 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople:
# 350 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "Is it… A TRAINER?\n"
# 351 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "I sense the presence of people…$"
# 352 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 353 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering:
# 354 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "I seem to have heard something…\n"
# 355 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "It may have been whispering…$"
# 356 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 357 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga:
# 358 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "For some odd reason, I felt a wave\n"
# 359 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "of nostalgia coming from it…$"
# 360 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 361 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent:
# 362 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "I am sorry to say…\p"
# 363 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "A terrifying event, yes, a horrible one,\n"
# 364 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "is about to befall you…\p"
# 365 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "I urge you to pay the utmost care\n"
# 366 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "and prepare for the worst…$"
# 367 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"

# 368 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence:
# 369 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "From every path I sense a dreadful\n"
# 370 "data//maps/BattleFrontier_BattlePikeThreePathRoom/scripts.pory"
	.string "presence…$"
