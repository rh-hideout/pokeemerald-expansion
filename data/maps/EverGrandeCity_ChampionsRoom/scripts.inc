# 1 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 2 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
.set LOCALID_WALLACE, 1
# 3 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
.set LOCALID_RIVAL, 2
# 4 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
.set LOCALID_BIRCH, 3
# 5 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 6 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_MapScripts::
# 7 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
# 8 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
# 9 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
# 10 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.byte 0
# 11 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 12 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnTransition:
# 13 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 14 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 15 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 16 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnWarp:
# 17 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
# 18 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.2byte 0
# 19 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 20 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
# 21 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 22 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 23 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 24 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnFrame:
# 25 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
# 26 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.2byte 0
# 27 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 28 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
# 29 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	lockall
# 30 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
# 31 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 32 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 33 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
# 34 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 35 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 36 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
# 37 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 38 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 39 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 40 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
# 41 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 42 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 43 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 44 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 45 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Wallace::
# 46 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
# 47 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 48 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
# 49 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
# 50 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 51 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 52 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Defeated::
# 53 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 54 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
# 55 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
# 56 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	special DrawWholeMapView
# 57 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 58 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 59 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 60 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 61 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
# 62 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
# 63 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_RIVAL
# 64 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
# 65 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 66 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
# 67 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
# 68 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 69 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 70 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
# 71 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, FALSE
# 72 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 73 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 74 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
# 75 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
# 76 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 77 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 78 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
# 79 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
# 80 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 81 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 82 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 83 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 84 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 85 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 86 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 87 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
# 88 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 89 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 90 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 91 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
# 92 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
# 93 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 94 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 95 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 96 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 97 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 98 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 99 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 100 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
# 101 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 102 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 103 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 104 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
# 105 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 106 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_BIRCH
# 107 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
# 108 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 109 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 110 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 111 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
# 112 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call ProfBirch_EventScript_RatePokedex
# 113 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
# 114 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
# 115 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 116 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 117 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
# 118 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 119 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
# 120 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 121 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 30
# 122 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
# 123 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
# 124 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterUp
# 125 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
# 126 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 127 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 128 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 129 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 130 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
# 131 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 132 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
# 133 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
# 134 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 135 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
# 136 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
# 137 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 138 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
# 139 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
# 140 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitstate
# 141 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 142 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 143 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 144 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
# 145 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
# 146 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 147 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 148 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
# 149 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
# 150 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 151 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 152 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
# 153 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
# 154 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 155 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 156 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 157 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 158 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 159 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
# 160 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
# 161 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 162 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 163 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 164 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
# 165 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 166 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 167 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 168 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 169 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
# 170 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 171 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 172 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 173 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 174 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 175 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 176 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 177 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
# 178 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 179 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 180 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 181 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 182 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 183 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_left
# 184 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 185 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 186 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 187 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 188 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
# 189 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 190 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 191 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 192 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 193 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 194 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 195 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 196 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 197 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 198 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 199 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
# 200 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 201 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 202 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 203 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 204 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
# 205 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 206 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 207 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_down
# 208 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 209 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 210 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
# 211 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 212 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 213 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 214 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 215 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 216 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
# 217 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 218 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 219 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 220 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 221 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 222 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 223 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 224 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_left
# 225 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 226 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 227 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
# 228 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: Welcome, {PLAYER}{KUN}.\p"
# 229 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That incident in SOOTOPOLIS CITY…\n"
# 230 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was superb work, putting an end\l"
# 231 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to that crisis all by yourself.\p"
# 232 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Oops!\p"
# 233 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It wouldn't be fair to say that you\n"
# 234 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "alone ended the crisis.\p"
# 235 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You overcame that difficult situation\n"
# 236 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "by working as one with your POKéMON.\p"
# 237 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "We TRAINERS raise POKéMON by giving\n"
# 238 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "them items and by teaching them new\l"
# 239 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "techniques for battle.\p"
# 240 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "But we ourselves also learn many\n"
# 241 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "things from POKéMON.\p"
# 242 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And this is where your achievements\n"
# 243 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "are put to the test against what\l"
# 244 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "others like you have achieved.\p"
# 245 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now!\p"
# 246 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Who can most elegantly dance with\n"
# 247 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "their POKéMON in HOENN?\p"
# 248 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Show me right here and now!$"
# 249 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 250 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_Defeat:
# 251 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I, the CHAMPION, fall in defeat…\p"
# 252 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was wonderful work.\n"
# 253 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You were elegant, infuriatingly so.\l"
# 254 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And yet it was utterly glorious!\p"
# 255 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
# 256 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You are a truly noble POKéMON\n"
# 257 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "TRAINER!$"
# 258 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 259 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
# 260 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: The POKéMON you sent into\n"
# 261 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "battle…\p"
# 262 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "At times they danced like a spring\n"
# 263 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "breeze, and at times they struck\l"
# 264 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "like lightning.\p"
# 265 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It was with light, yet surefooted,\n"
# 266 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "elegance that you led your POKéMON.\p"
# 267 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Even I felt bedazzled by your\n"
# 268 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "masterful performance!\p"
# 269 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You now stand at the glorious peak\n"
# 270 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "of the POKéMON LEAGUE.\p"
# 271 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I now proclaim you to be the new\n"
# 272 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "HOENN region…$"
# 273 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 274 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayAdvice:
# 275 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
# 276 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here's some advice before you challenge\n"
# 277 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION…$"
# 278 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 279 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
# 280 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Huh?\n"
# 281 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What, what, what?\p"
# 282 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}…\n"
# 283 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Could it be that…\l"
# 284 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It's already over?$"
# 285 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 286 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
# 287 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}!\p"
# 288 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "How would you like some advice before\n"
# 289 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "you challenge the CHAMPION?…$"
# 290 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 291 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
# 292 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}…\p"
# 293 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Are you trying to tell me…\n"
# 294 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You've beaten the CHAMPION?$"
# 295 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 296 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
# 297 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: See?\n"
# 298 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What did I tell you, {RIVAL}?\p"
# 299 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Didn't I tell you that you don't need\n"
# 300 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to worry about {PLAYER}{KUN}?\p"
# 301 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 302 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
# 303 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "When I heard that you defeated your\n"
# 304 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "own father at the PETALBURG GYM,\l"
# 305 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I thought perhaps you had a chance…\p"
# 306 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "But to think you've actually become\n"
# 307 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION!\p"
# 308 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Ah, yes!\p"
# 309 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What became of your POKéDEX?\n"
# 310 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here, let me see.$"
# 311 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 312 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
# 313 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: Anyways,\n"
# 314 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "congratulations!\p"
# 315 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now, go proudly into the final room!$"
# 316 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 317 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
# 318 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\p"
# 319 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "No, let me rephrase that properly.\p"
# 320 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "The new CHAMPION!\p"
# 321 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Come with me.$"
# 322 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 323 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
# 324 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: I'm sorry, but…\p"
# 325 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "From here on, only those TRAINERS who\n"
# 326 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "have become CHAMPIONS may enter.\p"
# 327 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You'll have to wait outside with\n"
# 328 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH.$"
# 329 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 330 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
# 331 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Groan…\p"
# 332 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 333 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 334 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I'm just joking! That's okay!\n"
# 335 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That's the rule!\p"
# 336 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 337 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Honestly, congratulations!$"
# 338 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 339 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
# 340 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: Whaaaat?! … … … … …\n"
# 341 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 342 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It can't be helped if that's the rule.\p"
# 343 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}, way to go!\n"
# 344 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Congratulations!$"
