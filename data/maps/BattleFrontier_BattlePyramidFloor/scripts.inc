# 1 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_MapScripts::
# 3 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
# 4 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
# 5 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
# 6 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.byte 0
# 7 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 8 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_OnFrame:
# 9 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
# 10 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
# 11 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
# 12 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.2byte 0
# 13 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 14 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
# 15 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	lockall
# 16 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	@ pyramid_updatelight, cant use macro because it straddles the loop
# 17 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
# 18 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_0x8005, 4
# 19 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
# 20 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_0x8007, SE_SAVE
# 21 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_RESULT, 0
# 22 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
# 23 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	special CallBattlePyramidFunction
# 24 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	delay 2
# 25 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
# 26 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_D, 0
# 27 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	releaseall
# 28 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 29 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 30 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
# 31 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	special ShowMapNamePopup
# 32 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_F, 0
# 33 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 34 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 35 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
# 36 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	playbgm MUS_B_PYRAMID, FALSE
# 37 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
# 38 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 39 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 40 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_OnResume:
# 41 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_setfloorpal
# 42 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_getstatus
# 43 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	switch VAR_TEMP_CHALLENGE_STATUS
# 44 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
# 45 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
# 46 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
# 47 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 48 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
# 49 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
# 50 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
# 51 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 52 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 53 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 54 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
# 55 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_D, 1
# 56 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
# 57 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_resetparty
# 58 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 59 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 60 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
# 61 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 62 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
# 63 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
# 64 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
# 65 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_clearhelditems
# 66 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	special HealPlayerParty
# 67 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
# 68 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	waitstate
# 69 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 70 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 71 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
# 72 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_save CHALLENGE_STATUS_SAVING
# 73 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	special SavePlayerParty
# 74 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 75 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_settrainers
# 76 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 77 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_F, 1
# 78 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 79 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 80 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_OnTransition:
# 81 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
# 82 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_F, 1
# 83 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 84 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 85 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
# 86 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
# 87 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	return
# 88 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 89 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_WarpToNextFloor::
# 90 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 91 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
# 92 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	addvar VAR_RESULT, 1
# 93 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 94 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
# 95 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_seedfloor
# 96 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 97 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_RESULT, 0
# 98 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
# 99 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	waitstate
# 100 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 101 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 102 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_WarpToTop::
# 103 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
# 104 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	waitstate
# 105 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 106 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 107 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
@ TRAINER_PHILLIP is used as a placeholder
# 108 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_TrainerBattle::
# 109 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	trainerbattle TRAINER_BATTLE_HILL, LOCALID_NONE, TRAINER_PHILLIP, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText, NULL, LOCALID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, FALSE, FALSE, FALSE
# 110 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_showhint
# 111 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	waitmessage
# 112 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	waitbuttonpress
# 113 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	closemessage
# 114 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	releaseall
# 115 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 116 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 117 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_FindItemBall::
# 118 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_setitem
# 119 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	callstd STD_FIND_ITEM
# 120 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
# 121 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_hideitem
# 122 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_FindItemBallEnd::
# 123 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 124 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 125 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Retire::
# 126 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 127 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 128 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
@ Also used by Trainer Hill
# 129 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFacility_TrainerBattle_PlaceholderText:
# 130 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is a sample message.$"
# 131 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 132 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
gText_BattlePyramidConfirmRest::
# 133 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Your BATTLE PYRAMID quest will be\n"
# 134 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "saved so that you may quit for now.\l"
# 135 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Is that okay?$"
# 136 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 137 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
gText_BattlePyramidConfirmRetire::
# 138 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you sure you want to quit your\n"
# 139 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "PYRAMID quest?$"
# 140 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 141 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp1::
# 142 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This floor's exit is in\n"
# 143 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that direction: {UP_ARROW}$"
# 144 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 145 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft1::
# 146 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This floor's exit is in\n"
# 147 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that direction: {LEFT_ARROW}$"
# 148 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 149 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight1::
# 150 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This floor's exit is in\n"
# 151 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that direction: {RIGHT_ARROW}$"
# 152 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 153 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown1::
# 154 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This floor's exit is in\n"
# 155 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that direction: {DOWN_ARROW}$"
# 156 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 157 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp2::
# 158 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit on this floor is in\n"
# 159 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {UP_ARROW} direction.$"
# 160 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 161 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft2::
# 162 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit on this floor is in\n"
# 163 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {LEFT_ARROW} direction.$"
# 164 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 165 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight2::
# 166 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit on this floor is in\n"
# 167 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {RIGHT_ARROW} direction.$"
# 168 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 169 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown2::
# 170 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit on this floor is in\n"
# 171 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {DOWN_ARROW} direction.$"
# 172 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 173 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp3::
# 174 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit is over\n"
# 175 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that {UP_ARROW} way.$"
# 176 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 177 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft3::
# 178 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit is over\n"
# 179 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that {LEFT_ARROW} way.$"
# 180 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 181 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight3::
# 182 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit is over\n"
# 183 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that {RIGHT_ARROW} way.$"
# 184 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 185 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown3::
# 186 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit is over\n"
# 187 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that {DOWN_ARROW} way.$"
# 188 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 189 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp4::
# 190 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor, the exit is somewhere\n"
# 191 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "in the {UP_ARROW} direction.$"
# 192 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 193 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft4::
# 194 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor, the exit is somewhere\n"
# 195 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "in the {LEFT_ARROW} direction.$"
# 196 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 197 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight4::
# 198 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor, the exit is somewhere\n"
# 199 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "in the {RIGHT_ARROW} direction.$"
# 200 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 201 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown4::
# 202 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor, the exit is somewhere\n"
# 203 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "in the {DOWN_ARROW} direction.$"
# 204 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 205 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp5::
# 206 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit?\n"
# 207 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "It's that {UP_ARROW} way.$"
# 208 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 209 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft5::
# 210 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit?\n"
# 211 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "It's that {LEFT_ARROW} way.$"
# 212 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 213 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight5::
# 214 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit?\n"
# 215 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "It's that {RIGHT_ARROW} way.$"
# 216 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 217 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown5::
# 218 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit?\n"
# 219 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "It's that {DOWN_ARROW} way.$"
# 220 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 221 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp6::
# 222 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit happens to be in\n"
# 223 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {UP_ARROW} direction.$"
# 224 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 225 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft6::
# 226 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit happens to be in\n"
# 227 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {LEFT_ARROW} direction.$"
# 228 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 229 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight6::
# 230 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit happens to be in\n"
# 231 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {RIGHT_ARROW} direction.$"
# 232 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 233 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown6::
# 234 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit happens to be in\n"
# 235 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {DOWN_ARROW} direction.$"
# 236 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 237 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining1::
# 238 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 239 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are eight items left to\n"
# 240 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 241 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 242 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining1::
# 243 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 244 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are seven items left to\n"
# 245 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 246 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 247 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining1::
# 248 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 249 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are six items left to\n"
# 250 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 251 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 252 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining1::
# 253 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 254 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are five items left to\n"
# 255 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 256 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 257 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining1::
# 258 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 259 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are four items left to\n"
# 260 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 261 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 262 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining1::
# 263 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 264 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are three items left to\n"
# 265 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 266 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 267 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining1::
# 268 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 269 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are two items left to\n"
# 270 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 271 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 272 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining1::
# 273 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 274 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There is one item left to\n"
# 275 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 276 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 277 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining1::
# 278 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 279 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There isn't anything left to\n"
# 280 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found!$"
# 281 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 282 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining2::
# 283 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 284 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 285 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are eight items\n"
# 286 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 287 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 288 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining2::
# 289 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 290 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 291 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are seven items left\n"
# 292 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 293 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 294 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining2::
# 295 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 296 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 297 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are six items left\n"
# 298 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 299 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 300 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining2::
# 301 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 302 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 303 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are five items left\n"
# 304 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 305 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 306 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining2::
# 307 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 308 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 309 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are four items left\n"
# 310 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 311 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 312 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining2::
# 313 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 314 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 315 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are three items left\n"
# 316 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 317 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 318 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining2::
# 319 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 320 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 321 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are two items left\n"
# 322 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 323 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 324 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining2::
# 325 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 326 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 327 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There is just one item\n"
# 328 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 329 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 330 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining2::
# 331 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 332 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 333 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There isn't anything left\n"
# 334 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 335 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 336 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining3::
# 337 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 338 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are eight items left\n"
# 339 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 340 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 341 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining3::
# 342 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 343 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are seven items left\n"
# 344 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 345 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 346 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining3::
# 347 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 348 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are six items left\n"
# 349 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 350 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 351 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining3::
# 352 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 353 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are five items left\n"
# 354 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 355 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 356 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining3::
# 357 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 358 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are four items left\n"
# 359 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 360 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 361 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining3::
# 362 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 363 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are three items left\n"
# 364 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 365 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 366 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining3::
# 367 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 368 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are two items left\n"
# 369 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 370 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 371 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining3::
# 372 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 373 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there's but one item left\n"
# 374 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 375 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 376 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining3::
# 377 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 378 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are no more items\n"
# 379 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.\l"
# 380 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You take care now!$"
# 381 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 382 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining4::
# 383 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 384 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 385 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be eight more\n"
# 386 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 387 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 388 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining4::
# 389 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 390 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 391 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be seven more\n"
# 392 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 393 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 394 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining4::
# 395 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 396 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 397 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be six more\n"
# 398 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 399 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 400 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining4::
# 401 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 402 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 403 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be five more\n"
# 404 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 405 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 406 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining4::
# 407 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 408 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 409 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be four more\n"
# 410 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 411 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 412 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining4::
# 413 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 414 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 415 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be three more\n"
# 416 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 417 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 418 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining4::
# 419 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 420 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 421 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be two more\n"
# 422 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 423 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 424 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining4::
# 425 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 426 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 427 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appears to be only one more\n"
# 428 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "item on the ground.$"
# 429 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 430 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining4::
# 431 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 432 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 433 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be no more\n"
# 434 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 435 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 436 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining5::
# 437 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 438 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are eight items…$"
# 439 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 440 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining5::
# 441 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 442 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are seven items…$"
# 443 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 444 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining5::
# 445 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 446 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are six items…$"
# 447 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 448 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining5::
# 449 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 450 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are five items…$"
# 451 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 452 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining5::
# 453 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 454 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are four items…$"
# 455 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 456 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining5::
# 457 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 458 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are three items…$"
# 459 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 460 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining5::
# 461 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 462 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are two items…$"
# 463 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 464 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining5::
# 465 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 466 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there is one item…$"
# 467 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 468 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining5::
# 469 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 470 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are no items…$"
# 471 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 472 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining6::
# 473 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 474 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are eight more\n"
# 475 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 476 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 477 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining6::
# 478 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 479 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are seven more\n"
# 480 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 481 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 482 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining6::
# 483 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 484 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are six more\n"
# 485 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 486 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 487 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining6::
# 488 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 489 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are five more\n"
# 490 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 491 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 492 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining6::
# 493 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 494 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are four more\n"
# 495 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 496 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 497 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining6::
# 498 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 499 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are three more\n"
# 500 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 501 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 502 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining6::
# 503 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 504 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are two more\n"
# 505 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 506 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 507 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining6::
# 508 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 509 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there is one more\n"
# 510 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "item on this floor.$"
# 511 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 512 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining6::
# 513 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 514 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are no more\n"
# 515 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 516 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 517 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining1::
# 518 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 519 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still seven tough\n"
# 520 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "TRAINERS other than me!$"
# 521 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 522 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining1::
# 523 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 524 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still six tough\n"
# 525 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "TRAINERS other than me!$"
# 526 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 527 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining1::
# 528 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 529 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still five tough\n"
# 530 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "TRAINERS other than me!$"
# 531 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 532 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining1::
# 533 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 534 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still four tough\n"
# 535 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "TRAINERS other than me!$"
# 536 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 537 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining1::
# 538 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 539 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still three tough\n"
# 540 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "TRAINERS other than me!$"
# 541 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 542 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining1::
# 543 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 544 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still two tough\n"
# 545 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "TRAINERS other than me!$"
# 546 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 547 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining1::
# 548 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 549 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there's still one tough\n"
# 550 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "TRAINER other than me!$"
# 551 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 552 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining1::
# 553 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 554 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There's no one left that\n"
# 555 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "can beat you!$"
# 556 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 557 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining2::
# 558 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 559 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are seven TRAINERS left!\n"
# 560 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 561 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 562 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining2::
# 563 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 564 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are six TRAINERS left!\n"
# 565 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 566 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 567 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining2::
# 568 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 569 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are five TRAINERS left!\n"
# 570 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 571 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 572 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining2::
# 573 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 574 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are four TRAINERS left!\n"
# 575 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 576 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 577 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining2::
# 578 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 579 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are three TRAINERS left!\n"
# 580 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 581 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 582 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining2::
# 583 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 584 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are two TRAINERS left!\n"
# 585 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 586 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 587 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining2::
# 588 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 589 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there's one TRAINER left!\n"
# 590 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I'm sure you will be humbled!$"
# 591 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 592 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining2::
# 593 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 594 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are no more TRAINERS\n"
# 595 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "who can engage you!$"
# 596 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 597 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining3::
# 598 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 599 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are seven more TRAINERS\n"
# 600 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them all?$"
# 601 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 602 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining3::
# 603 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 604 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are six more TRAINERS\n"
# 605 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them all?$"
# 606 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 607 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining3::
# 608 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 609 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are five more TRAINERS\n"
# 610 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them all?$"
# 611 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 612 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining3::
# 613 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 614 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are four more TRAINERS\n"
# 615 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them all?$"
# 616 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 617 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining3::
# 618 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 619 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are three more TRAINERS\n"
# 620 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them all?$"
# 621 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 622 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining3::
# 623 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 624 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are two more TRAINERS\n"
# 625 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them both?$"
# 626 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 627 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining3::
# 628 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 629 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there's still one more TRAINER\n"
# 630 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you prevail?$"
# 631 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 632 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining3::
# 633 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 634 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You've gone through all the TRAINERS\n"
# 635 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor.$"
# 636 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 637 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining4::
# 638 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 639 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the seven TRAINERS left on this floor.$"
# 640 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 641 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining4::
# 642 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 643 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the six TRAINERS left on this floor.$"
# 644 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 645 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining4::
# 646 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 647 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the five TRAINERS left on this floor.$"
# 648 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 649 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining4::
# 650 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 651 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the four TRAINERS left on this floor.$"
# 652 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 653 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining4::
# 654 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 655 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the three TRAINERS left on this floor.$"
# 656 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 657 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining4::
# 658 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 659 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the two TRAINERS left on this floor.$"
# 660 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 661 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining4::
# 662 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could complete your sweep\n"
# 663 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "with the one TRAINER left on this floor.$"
# 664 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 665 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining4::
# 666 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There isn't a single person left who\n"
# 667 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "can defeat you now…$"
# 668 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 669 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining5::
# 670 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 671 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the seven expert TRAINERS who remain.$"
# 672 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 673 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining5::
# 674 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 675 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the six expert TRAINERS who remain.$"
# 676 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 677 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining5::
# 678 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 679 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the five expert TRAINERS who remain.$"
# 680 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 681 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining5::
# 682 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 683 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the four expert TRAINERS who remain.$"
# 684 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 685 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining5::
# 686 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 687 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the three expert TRAINERS who remain.$"
# 688 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 689 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining5::
# 690 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 691 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the two expert TRAINERS who remain.$"
# 692 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 693 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining5::
# 694 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 695 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the one expert TRAINER who remains.$"
# 696 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 697 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining5::
# 698 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Your skills are beyond reproach.\p"
# 699 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are no more TRAINERS here\n"
# 700 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "who have any chance of beating you.$"
# 701 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 702 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining6::
# 703 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 704 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the seven remaining TRAINERS?$"
# 705 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 706 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining6::
# 707 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 708 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the six remaining TRAINERS?$"
# 709 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 710 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining6::
# 711 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 712 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the five remaining TRAINERS?$"
# 713 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 714 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining6::
# 715 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 716 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the four remaining TRAINERS?$"
# 717 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 718 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining6::
# 719 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 720 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the three remaining TRAINERS?$"
# 721 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 722 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining6::
# 723 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 724 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the two remaining TRAINERS?$"
# 725 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 726 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining6::
# 727 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 728 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the last remaining TRAINER?$"
# 729 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 730 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining6::
# 731 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There aren't any TRAINERS left that\n"
# 732 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "can take you on now…$"
