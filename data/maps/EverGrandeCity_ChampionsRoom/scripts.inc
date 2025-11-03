# 1 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_MapScripts::
# 3 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
# 4 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
# 5 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
# 6 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.byte 0
# 7 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 8 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnTransition:
# 9 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 10 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 11 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 12 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnWarp:
# 13 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
# 14 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.2byte 0
# 15 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 16 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
# 17 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 18 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 19 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 20 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnFrame:
# 21 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
# 22 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.2byte 0
# 23 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 24 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
# 25 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	lockall
# 26 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
# 27 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 28 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 29 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
# 30 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 31 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 32 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
# 33 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 34 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 35 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 36 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
# 37 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 38 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 39 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 40 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 41 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Wallace::
# 42 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
# 43 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 44 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
# 45 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
# 46 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 47 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 48 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Defeated::
# 49 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 50 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
# 51 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
# 52 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	special DrawWholeMapView
# 53 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 54 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 55 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 56 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 57 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
# 58 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
# 59 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
# 60 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
# 61 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 62 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
# 63 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
# 64 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 65 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 66 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
# 67 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, FALSE
# 68 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 69 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 70 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
# 71 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
# 72 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 73 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 74 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
# 75 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
# 76 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 77 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 78 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
# 79 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 80 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
# 81 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 82 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 83 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
# 84 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 85 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 86 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 87 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
# 88 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
# 89 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 90 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 91 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
# 92 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 93 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
# 94 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 95 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 96 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
# 97 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 98 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 99 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 100 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
# 101 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 102 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
# 103 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
# 104 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 105 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 106 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 107 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
# 108 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call ProfBirch_EventScript_RatePokedex
# 109 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
# 110 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
# 111 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 112 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 113 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
# 114 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 115 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
# 116 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 117 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 30
# 118 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
# 119 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
# 120 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
# 121 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
# 122 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 123 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 124 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 125 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 126 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
# 127 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 128 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
# 129 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
# 130 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 131 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
# 132 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
# 133 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 134 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
# 135 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
# 136 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitstate
# 137 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 138 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 139 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 140 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
# 141 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
# 142 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 143 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 144 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
# 145 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
# 146 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 147 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 148 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
# 149 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
# 150 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 151 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 152 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 153 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 154 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 155 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
# 156 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
# 157 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 158 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 159 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 160 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
# 161 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 162 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 163 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 164 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 165 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
# 166 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 167 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 168 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 169 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 170 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 171 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 172 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 173 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
# 174 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 175 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 176 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 177 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 178 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 179 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_left
# 180 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 181 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 182 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 183 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 184 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
# 185 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 186 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 187 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 188 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 189 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 190 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 191 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 192 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 193 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 194 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 195 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
# 196 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 197 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 198 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 199 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 200 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
# 201 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 202 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 203 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_down
# 204 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 205 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 206 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
# 207 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 208 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 209 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 210 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 211 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 212 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
# 213 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 214 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 215 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 216 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 217 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 218 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 219 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 220 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_left
# 221 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 222 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 223 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
# 224 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: Welcome, {PLAYER}{KUN}.\p"
# 225 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That incident in SOOTOPOLIS CITY…\n"
# 226 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was superb work, putting an end\l"
# 227 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to that crisis all by yourself.\p"
# 228 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Oops!\p"
# 229 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It wouldn't be fair to say that you\n"
# 230 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "alone ended the crisis.\p"
# 231 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You overcame that difficult situation\n"
# 232 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "by working as one with your POKéMON.\p"
# 233 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "We TRAINERS raise POKéMON by giving\n"
# 234 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "them items and by teaching them new\l"
# 235 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "techniques for battle.\p"
# 236 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "But we ourselves also learn many\n"
# 237 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "things from POKéMON.\p"
# 238 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And this is where your achievements\n"
# 239 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "are put to the test against what\l"
# 240 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "others like you have achieved.\p"
# 241 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now!\p"
# 242 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Who can most elegantly dance with\n"
# 243 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "their POKéMON in HOENN?\p"
# 244 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Show me right here and now!$"
# 245 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 246 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_Defeat:
# 247 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I, the CHAMPION, fall in defeat…\p"
# 248 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was wonderful work.\n"
# 249 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You were elegant, infuriatingly so.\l"
# 250 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And yet it was utterly glorious!\p"
# 251 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
# 252 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You are a truly noble POKéMON\n"
# 253 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "TRAINER!$"
# 254 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 255 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
# 256 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: The POKéMON you sent into\n"
# 257 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "battle…\p"
# 258 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "At times they danced like a spring\n"
# 259 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "breeze, and at times they struck\l"
# 260 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "like lightning.\p"
# 261 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It was with light, yet surefooted,\n"
# 262 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "elegance that you led your POKéMON.\p"
# 263 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Even I felt bedazzled by your\n"
# 264 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "masterful performance!\p"
# 265 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You now stand at the glorious peak\n"
# 266 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "of the POKéMON LEAGUE.\p"
# 267 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I now proclaim you to be the new\n"
# 268 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "HOENN region…$"
# 269 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 270 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayAdvice:
# 271 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
# 272 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here's some advice before you challenge\n"
# 273 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION…$"
# 274 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 275 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
# 276 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Huh?\n"
# 277 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What, what, what?\p"
# 278 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}…\n"
# 279 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Could it be that…\l"
# 280 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It's already over?$"
# 281 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 282 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
# 283 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}!\p"
# 284 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "How would you like some advice before\n"
# 285 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "you challenge the CHAMPION?…$"
# 286 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 287 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
# 288 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}…\p"
# 289 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Are you trying to tell me…\n"
# 290 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You've beaten the CHAMPION?$"
# 291 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 292 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
# 293 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: See?\n"
# 294 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What did I tell you, {RIVAL}?\p"
# 295 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Didn't I tell you that you don't need\n"
# 296 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to worry about {PLAYER}{KUN}?\p"
# 297 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 298 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
# 299 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "When I heard that you defeated your\n"
# 300 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "own father at the PETALBURG GYM,\l"
# 301 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I thought perhaps you had a chance…\p"
# 302 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "But to think you've actually become\n"
# 303 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION!\p"
# 304 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Ah, yes!\p"
# 305 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What became of your POKéDEX?\n"
# 306 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here, let me see.$"
# 307 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 308 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
# 309 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: Anyways,\n"
# 310 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "congratulations!\p"
# 311 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now, go proudly into the final room!$"
# 312 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 313 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
# 314 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\p"
# 315 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "No, let me rephrase that properly.\p"
# 316 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "The new CHAMPION!\p"
# 317 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Come with me.$"
# 318 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 319 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
# 320 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: I'm sorry, but…\p"
# 321 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "From here on, only those TRAINERS who\n"
# 322 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "have become CHAMPIONS may enter.\p"
# 323 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You'll have to wait outside with\n"
# 324 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH.$"
# 325 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 326 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
# 327 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Groan…\p"
# 328 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 329 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 330 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I'm just joking! That's okay!\n"
# 331 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That's the rule!\p"
# 332 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 333 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Honestly, congratulations!$"
# 334 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 335 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
# 336 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: Whaaaat?! … … … … …\n"
# 337 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 338 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It can't be helped if that's the rule.\p"
# 339 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}, way to go!\n"
# 340 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Congratulations!$"
