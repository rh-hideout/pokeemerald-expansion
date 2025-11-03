# 1 "data/maps/PetalburgCity/scripts.pory"

# 2 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_MapScripts::
# 3 "data/maps/PetalburgCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
# 4 "data/maps/PetalburgCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
# 5 "data/maps/PetalburgCity/scripts.pory"
	.byte 0
# 6 "data/maps/PetalburgCity/scripts.pory"

# 7 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_OnTransition:
# 8 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_VISITED_PETALBURG_CITY
# 9 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_PETALBURG_CITY_STATE, 0, PetalburgCity_EventScript_MoveGymBoyToWestEntrance
# 10 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_DisableMapNameAndMusic
# 11 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_DisableMapNameAndMusic
# 12 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_EventScript_SetGymDoorsUnlocked
# 13 "data/maps/PetalburgCity/scripts.pory"
	end
# 14 "data/maps/PetalburgCity/scripts.pory"

# 15 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_MoveGymBoyToWestEntrance::
# 16 "data/maps/PetalburgCity/scripts.pory"
	setobjectxyperm LOCALID_GYM_BOY, 5, 11
# 17 "data/maps/PetalburgCity/scripts.pory"
	return
# 18 "data/maps/PetalburgCity/scripts.pory"

# 19 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_DisableMapNameAndMusic::
# 20 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 21 "data/maps/PetalburgCity/scripts.pory"
	savebgm MUS_FOLLOW_ME
# 22 "data/maps/PetalburgCity/scripts.pory"
	return
# 23 "data/maps/PetalburgCity/scripts.pory"

# 24 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_SetGymDoorsUnlocked::
# 25 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 7
# 26 "data/maps/PetalburgCity/scripts.pory"
	return
# 27 "data/maps/PetalburgCity/scripts.pory"

# 28 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_OnFrame:
# 29 "data/maps/PetalburgCity/scripts.pory"
	map_script_2 VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_WallyTutorial
# 30 "data/maps/PetalburgCity/scripts.pory"
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_WalkToWallyHouse
# 31 "data/maps/PetalburgCity/scripts.pory"
	.2byte 0
# 32 "data/maps/PetalburgCity/scripts.pory"

# 33 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WallyTutorial::
# 34 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 35 "data/maps/PetalburgCity/scripts.pory"
	special SavePlayerParty
# 36 "data/maps/PetalburgCity/scripts.pory"
	special LoadWallyZigzagoon
# 37 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLY, PetalburgCity_Movement_WallyTutorialWally
# 38 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WallyTutorialPlayer
# 39 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 40 "data/maps/PetalburgCity/scripts.pory"
	msgbox Route102_Text_WatchMeCatchPokemon, MSGBOX_DEFAULT
# 41 "data/maps/PetalburgCity/scripts.pory"
	special StartWallyTutorialBattle
# 42 "data/maps/PetalburgCity/scripts.pory"
	waitstate
# 43 "data/maps/PetalburgCity/scripts.pory"
	msgbox Route102_Text_WallyIDidIt, MSGBOX_DEFAULT
# 44 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLY, Common_Movement_WalkInPlaceFasterLeft, MAP_PETALBURG_CITY
# 45 "data/maps/PetalburgCity/scripts.pory"
	waitmovement LOCALID_PETALBURG_WALLY, MAP_PETALBURG_CITY
# 46 "data/maps/PetalburgCity/scripts.pory"
	msgbox Route102_Text_LetsGoBack, MSGBOX_DEFAULT
# 47 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 48 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 49 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 3
# 50 "data/maps/PetalburgCity/scripts.pory"
	fadedefaultbgm
# 51 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 52 "data/maps/PetalburgCity/scripts.pory"
	special LoadPlayerParty
# 53 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 54 "data/maps/PetalburgCity/scripts.pory"
	warp MAP_PETALBURG_CITY_GYM, 4, 108
# 55 "data/maps/PetalburgCity/scripts.pory"
	waitstate
# 56 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 57 "data/maps/PetalburgCity/scripts.pory"
	end
# 58 "data/maps/PetalburgCity/scripts.pory"

# 59 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WalkToWallyHouse::
# 60 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 61 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 62 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLYS_DAD, PetalburgCity_Movement_WalkToWallyHouseWallysDad
# 63 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WalkToWallyHousePlayer
# 64 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 65 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8004, 7
# 66 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8005, 5
# 67 "data/maps/PetalburgCity/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 68 "data/maps/PetalburgCity/scripts.pory"
	waitdooranim
# 69 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLYS_DAD, PetalburgCity_Movement_WalkInsideHouseWallysDad
# 70 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WalkInsideHousePlayer
# 71 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 72 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
# 73 "data/maps/PetalburgCity/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_PETALBURG_CITY
# 74 "data/maps/PetalburgCity/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 75 "data/maps/PetalburgCity/scripts.pory"
	waitdooranim
# 76 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 77 "data/maps/PetalburgCity/scripts.pory"
	fadedefaultbgm
# 78 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 79 "data/maps/PetalburgCity/scripts.pory"
	warp MAP_PETALBURG_CITY_WALLYS_HOUSE, 2, 4
# 80 "data/maps/PetalburgCity/scripts.pory"
	waitstate
# 81 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 82 "data/maps/PetalburgCity/scripts.pory"
	end
# 83 "data/maps/PetalburgCity/scripts.pory"

# 84 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Boy::
# 85 "data/maps/PetalburgCity/scripts.pory"
	lock
# 86 "data/maps/PetalburgCity/scripts.pory"
	faceplayer
# 87 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
# 88 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 89 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_BOY, Common_Movement_FaceOriginalDirection
# 90 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 91 "data/maps/PetalburgCity/scripts.pory"
	release
# 92 "data/maps/PetalburgCity/scripts.pory"
	end
# 93 "data/maps/PetalburgCity/scripts.pory"

# 94 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WallysMom::
# 95 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_WhereIsWally, MSGBOX_NPC
# 96 "data/maps/PetalburgCity/scripts.pory"
	end
# 97 "data/maps/PetalburgCity/scripts.pory"

# 98 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkToWallyHousePlayer:
# 99 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 100 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 101 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 102 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 103 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 104 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 105 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 106 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 107 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 108 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 109 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 110 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 111 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 112 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 113 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 114 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 115 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 116 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 117 "data/maps/PetalburgCity/scripts.pory"

# 118 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkInsideHousePlayer:
# 119 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 120 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 121 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 122 "data/maps/PetalburgCity/scripts.pory"

# 123 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkToWallyHouseWallysDad:
# 124 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 125 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 126 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 127 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 128 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 129 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 130 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 131 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 132 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 133 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 134 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 135 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 136 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 137 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 138 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 139 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 140 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 141 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 142 "data/maps/PetalburgCity/scripts.pory"

# 143 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkInsideHouseWallysDad:
# 144 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 145 "data/maps/PetalburgCity/scripts.pory"
	set_invisible
# 146 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 147 "data/maps/PetalburgCity/scripts.pory"

# 148 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WallyTutorialPlayer:
# 149 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 150 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 151 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 152 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 153 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 154 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 155 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 156 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 157 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 158 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 159 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 160 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 161 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 162 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 163 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 164 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 165 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 166 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 167 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 168 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 169 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 170 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 171 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 172 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 173 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 174 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 175 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 176 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 177 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 178 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 179 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 180 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_right
# 181 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 182 "data/maps/PetalburgCity/scripts.pory"

# 183 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WallyTutorialWally:
# 184 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 185 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 186 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 187 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 188 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 189 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 190 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 191 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 192 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 193 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 194 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 195 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 196 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 197 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 198 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 199 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 200 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 201 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 202 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 203 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 204 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 205 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 206 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 207 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 208 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 209 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 210 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 211 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 212 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 213 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 214 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 215 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 216 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 217 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 218 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 219 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_right
# 220 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 221 "data/maps/PetalburgCity/scripts.pory"

# 222 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_GymSign::
# 223 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
# 224 "data/maps/PetalburgCity/scripts.pory"
	end
# 225 "data/maps/PetalburgCity/scripts.pory"

# 226 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_CitySign::
# 227 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
# 228 "data/maps/PetalburgCity/scripts.pory"
	end
# 229 "data/maps/PetalburgCity/scripts.pory"

# 230 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Gentleman::
# 231 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
# 232 "data/maps/PetalburgCity/scripts.pory"
	end
# 233 "data/maps/PetalburgCity/scripts.pory"

# 234 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WallyHouseSign::
# 235 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
# 236 "data/maps/PetalburgCity/scripts.pory"
	end
# 237 "data/maps/PetalburgCity/scripts.pory"

# 238 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer0::
# 239 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 240 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 0
# 241 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 242 "data/maps/PetalburgCity/scripts.pory"
	end
# 243 "data/maps/PetalburgCity/scripts.pory"

# 244 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer1::
# 245 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 246 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 1
# 247 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 248 "data/maps/PetalburgCity/scripts.pory"
	end
# 249 "data/maps/PetalburgCity/scripts.pory"

# 250 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer2::
# 251 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 252 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 2
# 253 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 254 "data/maps/PetalburgCity/scripts.pory"
	end
# 255 "data/maps/PetalburgCity/scripts.pory"

# 256 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer3::
# 257 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 258 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 3
# 259 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 260 "data/maps/PetalburgCity/scripts.pory"
	end
# 261 "data/maps/PetalburgCity/scripts.pory"

# 262 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer::
# 263 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_FacePlayer
# 264 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 265 "data/maps/PetalburgCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 266 "data/maps/PetalburgCity/scripts.pory"
	playse SE_PIN
# 267 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_ExclamationMark
# 268 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 269 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_Delay48
# 270 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 271 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_BoyApproachPlayer0
# 272 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_BoyApproachPlayer1
# 273 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_BoyApproachPlayer2
# 274 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_BoyApproachPlayer3
# 275 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_DEFAULT
# 276 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 277 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_LeadPlayerToGym0
# 278 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_LeadPlayerToGym1
# 279 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_LeadPlayerToGym2
# 280 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_LeadPlayerToGym3
# 281 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_ThisIsPetalburgGym, MSGBOX_DEFAULT
# 282 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_WalkInPlaceFasterRight
# 283 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 284 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 285 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_ThisIsGymSign, MSGBOX_DEFAULT
# 286 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 287 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkAway
# 288 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 289 "data/maps/PetalburgCity/scripts.pory"
	fadedefaultbgm
# 290 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 291 "data/maps/PetalburgCity/scripts.pory"
	end
# 292 "data/maps/PetalburgCity/scripts.pory"

# 293 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer0::
# 294 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer0
# 295 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 296 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 297 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 298 "data/maps/PetalburgCity/scripts.pory"
	return
# 299 "data/maps/PetalburgCity/scripts.pory"

# 300 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer1::
# 301 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer1
# 302 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 303 "data/maps/PetalburgCity/scripts.pory"
	return
# 304 "data/maps/PetalburgCity/scripts.pory"

# 305 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer2::
# 306 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer2
# 307 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 308 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 309 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 310 "data/maps/PetalburgCity/scripts.pory"
	return
# 311 "data/maps/PetalburgCity/scripts.pory"

# 312 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer3::
# 313 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer3
# 314 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 315 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 316 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 317 "data/maps/PetalburgCity/scripts.pory"
	return
# 318 "data/maps/PetalburgCity/scripts.pory"

# 319 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym0::
# 320 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym0
# 321 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym0
# 322 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 323 "data/maps/PetalburgCity/scripts.pory"
	return
# 324 "data/maps/PetalburgCity/scripts.pory"

# 325 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym1::
# 326 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym1
# 327 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym1
# 328 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 329 "data/maps/PetalburgCity/scripts.pory"
	return
# 330 "data/maps/PetalburgCity/scripts.pory"

# 331 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym2::
# 332 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym2
# 333 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym2
# 334 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 335 "data/maps/PetalburgCity/scripts.pory"
	return
# 336 "data/maps/PetalburgCity/scripts.pory"

# 337 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym3::
# 338 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym3
# 339 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym3
# 340 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 341 "data/maps/PetalburgCity/scripts.pory"
	return
# 342 "data/maps/PetalburgCity/scripts.pory"

# 343 "data/maps/PetalburgCity/scripts.pory"
@ Unused
# 344 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_Delay48::
# 345 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 346 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 347 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 348 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 349 "data/maps/PetalburgCity/scripts.pory"

# 350 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer0:
# 351 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 352 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 353 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 354 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 355 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 356 "data/maps/PetalburgCity/scripts.pory"

# 357 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer1:
# 358 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 359 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 360 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 361 "data/maps/PetalburgCity/scripts.pory"

# 362 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer2:
# 363 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 364 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 365 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 366 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 367 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 368 "data/maps/PetalburgCity/scripts.pory"

# 369 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer3:
# 370 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 371 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 372 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 373 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 374 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 375 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 376 "data/maps/PetalburgCity/scripts.pory"

# 377 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym0:
# 378 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 379 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 380 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 381 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 382 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 383 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 384 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 385 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 386 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 387 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 388 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 389 "data/maps/PetalburgCity/scripts.pory"

# 390 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym1:
# 391 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 392 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 393 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 394 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 395 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 396 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 397 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 398 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 399 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 400 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 401 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 402 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 403 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 404 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 405 "data/maps/PetalburgCity/scripts.pory"

# 406 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym2:
# 407 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 408 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 409 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 410 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 411 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 412 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 413 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 414 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 415 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 416 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 417 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 418 "data/maps/PetalburgCity/scripts.pory"

# 419 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym3:
# 420 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 421 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 422 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 423 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 424 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 425 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 426 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 427 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 428 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 429 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 430 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 431 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 432 "data/maps/PetalburgCity/scripts.pory"

# 433 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkAway:
# 434 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 435 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 436 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 437 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 438 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 439 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 440 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 441 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 442 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 443 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 444 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 445 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 446 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 447 "data/maps/PetalburgCity/scripts.pory"

# 448 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym0:
# 449 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 450 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 451 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 452 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 453 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 454 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 455 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 456 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 457 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 458 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 459 "data/maps/PetalburgCity/scripts.pory"

# 460 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym1:
# 461 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 462 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 463 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 464 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 465 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 466 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 467 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 468 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 469 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 470 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 471 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 472 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 473 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 474 "data/maps/PetalburgCity/scripts.pory"

# 475 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym2:
# 476 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 477 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 478 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 479 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 480 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 481 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 482 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 483 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 484 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 485 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 486 "data/maps/PetalburgCity/scripts.pory"

# 487 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym3:
# 488 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 489 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 490 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 491 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 492 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 493 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 494 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 495 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 496 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 497 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 498 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 499 "data/maps/PetalburgCity/scripts.pory"

# 500 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Scott0::
# 501 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 502 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 503 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 0
# 504 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 10
# 505 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
# 506 "data/maps/PetalburgCity/scripts.pory"
	end
# 507 "data/maps/PetalburgCity/scripts.pory"

# 508 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Scott1::
# 509 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 510 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 511 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 1
# 512 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 11
# 513 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
# 514 "data/maps/PetalburgCity/scripts.pory"
	end
# 515 "data/maps/PetalburgCity/scripts.pory"

# 516 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Scott2::
# 517 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 518 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 519 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 2
# 520 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 12
# 521 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
# 522 "data/maps/PetalburgCity/scripts.pory"
	end
# 523 "data/maps/PetalburgCity/scripts.pory"

# 524 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Scott3::
# 525 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 526 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 527 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 3
# 528 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 13
# 529 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
# 530 "data/maps/PetalburgCity/scripts.pory"
	end
# 531 "data/maps/PetalburgCity/scripts.pory"

# 532 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Scott::
# 533 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottStartWalkLeft
# 534 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 535 "data/maps/PetalburgCity/scripts.pory"
	playse SE_PIN
# 536 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_ExclamationMark
# 537 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 538 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_Delay48
# 539 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 540 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottApproachPlayer
# 541 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 542 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 543 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 544 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_SCOTT_STATE, 1
# 545 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_AreYouATrainer, MSGBOX_DEFAULT
# 546 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 547 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_WalkInPlaceFasterRight
# 548 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 549 "data/maps/PetalburgCity/scripts.pory"
	delay 30
# 550 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_WellMaybeNot, MSGBOX_DEFAULT
# 551 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 552 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_WalkInPlaceFasterLeft
# 553 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 554 "data/maps/PetalburgCity/scripts.pory"
	delay 30
# 555 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_ImLookingForTalentedTrainers, MSGBOX_DEFAULT
# 556 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 557 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_ScottExit0
# 558 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_ScottExit1
# 559 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_ScottExit2
# 560 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_ScottExit3
# 561 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_SCOTT_PETALBURG_ENCOUNTER, 1
# 562 "data/maps/PetalburgCity/scripts.pory"
	removeobject LOCALID_PETALBURG_SCOTT
# 563 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 564 "data/maps/PetalburgCity/scripts.pory"
	end
# 565 "data/maps/PetalburgCity/scripts.pory"

# 566 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ScottExit0::
# 567 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit0
# 568 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit0
# 569 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 570 "data/maps/PetalburgCity/scripts.pory"
	return
# 571 "data/maps/PetalburgCity/scripts.pory"

# 572 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ScottExit1::
# 573 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit1
# 574 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit1
# 575 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 576 "data/maps/PetalburgCity/scripts.pory"
	return
# 577 "data/maps/PetalburgCity/scripts.pory"

# 578 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ScottExit2::
# 579 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit2
# 580 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit2
# 581 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 582 "data/maps/PetalburgCity/scripts.pory"
	return
# 583 "data/maps/PetalburgCity/scripts.pory"

# 584 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ScottExit3::
# 585 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit3
# 586 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit3
# 587 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 588 "data/maps/PetalburgCity/scripts.pory"
	return
# 589 "data/maps/PetalburgCity/scripts.pory"

# 590 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottStartWalkLeft:
# 591 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 592 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 593 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 594 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 595 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 596 "data/maps/PetalburgCity/scripts.pory"

# 597 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottApproachPlayer:
# 598 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 599 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 600 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 601 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 602 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 603 "data/maps/PetalburgCity/scripts.pory"

# 604 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit0:
# 605 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 606 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 607 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 608 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 609 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 610 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 611 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 612 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 613 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 614 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 615 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 616 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 617 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 618 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 619 "data/maps/PetalburgCity/scripts.pory"

# 620 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit0:
# 621 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 622 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 623 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 624 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 625 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 626 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 627 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 628 "data/maps/PetalburgCity/scripts.pory"

# 629 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit1:
# 630 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 631 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 632 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 633 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 634 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 635 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 636 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 637 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 638 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 639 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 640 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 641 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 642 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 643 "data/maps/PetalburgCity/scripts.pory"

# 644 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit1:
# 645 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 646 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 647 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 648 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 649 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 650 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 651 "data/maps/PetalburgCity/scripts.pory"

# 652 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit2:
# 653 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 654 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 655 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 656 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 657 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 658 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 659 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 660 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 661 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 662 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 663 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 664 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 665 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 666 "data/maps/PetalburgCity/scripts.pory"

# 667 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit2:
# 668 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 669 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 670 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 671 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 672 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 673 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 674 "data/maps/PetalburgCity/scripts.pory"

# 675 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit3:
# 676 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 677 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 678 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 679 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 680 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 681 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 682 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 683 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 684 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 685 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 686 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 687 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 688 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 689 "data/maps/PetalburgCity/scripts.pory"

# 690 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit3:
# 691 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 692 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 693 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 694 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 695 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 696 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 697 "data/maps/PetalburgCity/scripts.pory"

# 698 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_GymBoy::
# 699 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_NPC
# 700 "data/maps/PetalburgCity/scripts.pory"
	end
# 701 "data/maps/PetalburgCity/scripts.pory"

# 702 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_WhereIsWally:
# 703 "data/maps/PetalburgCity/scripts.pory"
	.string "Where has our WALLY gone?\p"
# 704 "data/maps/PetalburgCity/scripts.pory"
	.string "We have to leave for VERDANTURF TOWN\n"
# 705 "data/maps/PetalburgCity/scripts.pory"
	.string "very soon…$"
# 706 "data/maps/PetalburgCity/scripts.pory"

# 707 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_AreYouRookieTrainer:
# 708 "data/maps/PetalburgCity/scripts.pory"
	.string "Hiya! Are you maybe…\n"
# 709 "data/maps/PetalburgCity/scripts.pory"
	.string "A rookie TRAINER?\p"
# 710 "data/maps/PetalburgCity/scripts.pory"
	.string "Do you know what POKéMON TRAINERS\n"
# 711 "data/maps/PetalburgCity/scripts.pory"
	.string "do when they reach a new town?\p"
# 712 "data/maps/PetalburgCity/scripts.pory"
	.string "They first check what kind of GYM\n"
# 713 "data/maps/PetalburgCity/scripts.pory"
	.string "is in the town.$"
# 714 "data/maps/PetalburgCity/scripts.pory"

# 715 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_ThisIsPetalburgGym:
# 716 "data/maps/PetalburgCity/scripts.pory"
	.string "See? This is PETALBURG CITY's GYM.$"
# 717 "data/maps/PetalburgCity/scripts.pory"

# 718 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_ThisIsGymSign:
# 719 "data/maps/PetalburgCity/scripts.pory"
	.string "This is the GYM's sign. Look for it\n"
# 720 "data/maps/PetalburgCity/scripts.pory"
	.string "whenever you're looking for a GYM.$"
# 721 "data/maps/PetalburgCity/scripts.pory"

# 722 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_WaterReflection:
# 723 "data/maps/PetalburgCity/scripts.pory"
	.string "My face is reflected in the water.\p"
# 724 "data/maps/PetalburgCity/scripts.pory"
	.string "It's a shining grin full of hope…\p"
# 725 "data/maps/PetalburgCity/scripts.pory"
	.string "Or it could be a look of somber silence\n"
# 726 "data/maps/PetalburgCity/scripts.pory"
	.string "struggling with fear…\p"
# 727 "data/maps/PetalburgCity/scripts.pory"
	.string "What do you see reflected in your face?$"
# 728 "data/maps/PetalburgCity/scripts.pory"

# 729 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_FullPartyExplanation:
# 730 "data/maps/PetalburgCity/scripts.pory"
	.string "Let's say you have six POKéMON.\n"
# 731 "data/maps/PetalburgCity/scripts.pory"
	.string "If you catch another one…\p"
# 732 "data/maps/PetalburgCity/scripts.pory"
	.string "It is automatically sent to a STORAGE\n"
# 733 "data/maps/PetalburgCity/scripts.pory"
	.string "BOX over a PC connection.$"
# 734 "data/maps/PetalburgCity/scripts.pory"

# 735 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_GymSign:
# 736 "data/maps/PetalburgCity/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM\n"
# 737 "data/maps/PetalburgCity/scripts.pory"
	.string "LEADER: NORMAN\l"
# 738 "data/maps/PetalburgCity/scripts.pory"
	.string "“A man in pursuit of power!”$"
# 739 "data/maps/PetalburgCity/scripts.pory"

# 740 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_CitySign:
# 741 "data/maps/PetalburgCity/scripts.pory"
	.string "PETALBURG CITY\n"
# 742 "data/maps/PetalburgCity/scripts.pory"
	.string "“Where people mingle with nature.”$"
# 743 "data/maps/PetalburgCity/scripts.pory"

# 744 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_WallyHouseSign:
# 745 "data/maps/PetalburgCity/scripts.pory"
	.string "WALLY'S HOUSE$"
# 746 "data/maps/PetalburgCity/scripts.pory"

# 747 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_AreYouATrainer:
# 748 "data/maps/PetalburgCity/scripts.pory"
	.string "Excuse me!\p"
# 749 "data/maps/PetalburgCity/scripts.pory"
	.string "Let me guess, from the way you're\n"
# 750 "data/maps/PetalburgCity/scripts.pory"
	.string "dressed, are you a POKéMON TRAINER?$"
# 751 "data/maps/PetalburgCity/scripts.pory"

# 752 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_WellMaybeNot:
# 753 "data/maps/PetalburgCity/scripts.pory"
	.string "… … … … … …\p"
# 754 "data/maps/PetalburgCity/scripts.pory"
	.string "Well, maybe not.\n"
# 755 "data/maps/PetalburgCity/scripts.pory"
	.string "Your clothes aren't all that dirty.\p"
# 756 "data/maps/PetalburgCity/scripts.pory"
	.string "You're either a rookie TRAINER,\n"
# 757 "data/maps/PetalburgCity/scripts.pory"
	.string "or maybe you're just an ordinary kid.$"
# 758 "data/maps/PetalburgCity/scripts.pory"

# 759 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_ImLookingForTalentedTrainers:
# 760 "data/maps/PetalburgCity/scripts.pory"
	.string "I'm roaming the land in search of\n"
# 761 "data/maps/PetalburgCity/scripts.pory"
	.string "talented TRAINERS.\p"
# 762 "data/maps/PetalburgCity/scripts.pory"
	.string "I'm sorry to have taken your time.$"
