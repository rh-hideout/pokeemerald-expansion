# 1 "data/maps/PetalburgCity/scripts.pory"

# 2 "data/maps/PetalburgCity/scripts.pory"
# 1 "data/maps/PetalburgCity/scripts.pory"
# 3 "data/maps/PetalburgCity/scripts.pory"

# 4 "data/maps/PetalburgCity/scripts.pory"
# 2 "data/maps/PetalburgCity/scripts.pory"
# 5 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_MapScripts::
# 6 "data/maps/PetalburgCity/scripts.pory"
# 3 "data/maps/PetalburgCity/scripts.pory"
# 7 "data/maps/PetalburgCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
# 8 "data/maps/PetalburgCity/scripts.pory"
# 4 "data/maps/PetalburgCity/scripts.pory"
# 9 "data/maps/PetalburgCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
# 10 "data/maps/PetalburgCity/scripts.pory"
# 5 "data/maps/PetalburgCity/scripts.pory"
# 11 "data/maps/PetalburgCity/scripts.pory"
	.byte 0
# 12 "data/maps/PetalburgCity/scripts.pory"
# 6 "data/maps/PetalburgCity/scripts.pory"
# 13 "data/maps/PetalburgCity/scripts.pory"

# 14 "data/maps/PetalburgCity/scripts.pory"
# 7 "data/maps/PetalburgCity/scripts.pory"
# 15 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_OnTransition:
# 16 "data/maps/PetalburgCity/scripts.pory"
# 8 "data/maps/PetalburgCity/scripts.pory"
# 17 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_VISITED_PETALBURG_CITY
# 18 "data/maps/PetalburgCity/scripts.pory"
# 9 "data/maps/PetalburgCity/scripts.pory"
# 19 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_PETALBURG_CITY_STATE, 0, PetalburgCity_EventScript_MoveGymBoyToWestEntrance
# 20 "data/maps/PetalburgCity/scripts.pory"
# 10 "data/maps/PetalburgCity/scripts.pory"
# 21 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_DisableMapNameAndMusic
# 22 "data/maps/PetalburgCity/scripts.pory"
# 11 "data/maps/PetalburgCity/scripts.pory"
# 23 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_DisableMapNameAndMusic
# 24 "data/maps/PetalburgCity/scripts.pory"
# 12 "data/maps/PetalburgCity/scripts.pory"
# 25 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_EventScript_SetGymDoorsUnlocked
# 26 "data/maps/PetalburgCity/scripts.pory"
# 13 "data/maps/PetalburgCity/scripts.pory"
# 27 "data/maps/PetalburgCity/scripts.pory"
	end
# 28 "data/maps/PetalburgCity/scripts.pory"
# 14 "data/maps/PetalburgCity/scripts.pory"
# 29 "data/maps/PetalburgCity/scripts.pory"

# 30 "data/maps/PetalburgCity/scripts.pory"
# 15 "data/maps/PetalburgCity/scripts.pory"
# 31 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_MoveGymBoyToWestEntrance::
# 32 "data/maps/PetalburgCity/scripts.pory"
# 16 "data/maps/PetalburgCity/scripts.pory"
# 33 "data/maps/PetalburgCity/scripts.pory"
	setobjectxyperm LOCALID_GYM_BOY, 5, 11
# 34 "data/maps/PetalburgCity/scripts.pory"
# 17 "data/maps/PetalburgCity/scripts.pory"
# 35 "data/maps/PetalburgCity/scripts.pory"
	return
# 36 "data/maps/PetalburgCity/scripts.pory"
# 18 "data/maps/PetalburgCity/scripts.pory"
# 37 "data/maps/PetalburgCity/scripts.pory"

# 38 "data/maps/PetalburgCity/scripts.pory"
# 19 "data/maps/PetalburgCity/scripts.pory"
# 39 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_DisableMapNameAndMusic::
# 40 "data/maps/PetalburgCity/scripts.pory"
# 20 "data/maps/PetalburgCity/scripts.pory"
# 41 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 42 "data/maps/PetalburgCity/scripts.pory"
# 21 "data/maps/PetalburgCity/scripts.pory"
# 43 "data/maps/PetalburgCity/scripts.pory"
	savebgm MUS_FOLLOW_ME
# 44 "data/maps/PetalburgCity/scripts.pory"
# 22 "data/maps/PetalburgCity/scripts.pory"
# 45 "data/maps/PetalburgCity/scripts.pory"
	return
# 46 "data/maps/PetalburgCity/scripts.pory"
# 23 "data/maps/PetalburgCity/scripts.pory"
# 47 "data/maps/PetalburgCity/scripts.pory"

# 48 "data/maps/PetalburgCity/scripts.pory"
# 24 "data/maps/PetalburgCity/scripts.pory"
# 49 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_SetGymDoorsUnlocked::
# 50 "data/maps/PetalburgCity/scripts.pory"
# 25 "data/maps/PetalburgCity/scripts.pory"
# 51 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 7
# 52 "data/maps/PetalburgCity/scripts.pory"
# 26 "data/maps/PetalburgCity/scripts.pory"
# 53 "data/maps/PetalburgCity/scripts.pory"
	return
# 54 "data/maps/PetalburgCity/scripts.pory"
# 27 "data/maps/PetalburgCity/scripts.pory"
# 55 "data/maps/PetalburgCity/scripts.pory"

# 56 "data/maps/PetalburgCity/scripts.pory"
# 28 "data/maps/PetalburgCity/scripts.pory"
# 57 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_OnFrame:
# 58 "data/maps/PetalburgCity/scripts.pory"
# 29 "data/maps/PetalburgCity/scripts.pory"
# 59 "data/maps/PetalburgCity/scripts.pory"
	map_script_2 VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_WallyTutorial
# 60 "data/maps/PetalburgCity/scripts.pory"
# 30 "data/maps/PetalburgCity/scripts.pory"
# 61 "data/maps/PetalburgCity/scripts.pory"
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_WalkToWallyHouse
# 62 "data/maps/PetalburgCity/scripts.pory"
# 31 "data/maps/PetalburgCity/scripts.pory"
# 63 "data/maps/PetalburgCity/scripts.pory"
	.2byte 0
# 64 "data/maps/PetalburgCity/scripts.pory"
# 32 "data/maps/PetalburgCity/scripts.pory"
# 65 "data/maps/PetalburgCity/scripts.pory"

# 66 "data/maps/PetalburgCity/scripts.pory"
# 33 "data/maps/PetalburgCity/scripts.pory"
# 67 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WallyTutorial::
# 68 "data/maps/PetalburgCity/scripts.pory"
# 34 "data/maps/PetalburgCity/scripts.pory"
# 69 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 70 "data/maps/PetalburgCity/scripts.pory"
# 35 "data/maps/PetalburgCity/scripts.pory"
# 71 "data/maps/PetalburgCity/scripts.pory"
	special SavePlayerParty
# 72 "data/maps/PetalburgCity/scripts.pory"
# 36 "data/maps/PetalburgCity/scripts.pory"
# 73 "data/maps/PetalburgCity/scripts.pory"
	special LoadWallyZigzagoon
# 74 "data/maps/PetalburgCity/scripts.pory"
# 37 "data/maps/PetalburgCity/scripts.pory"
# 75 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLY, PetalburgCity_Movement_WallyTutorialWally
# 76 "data/maps/PetalburgCity/scripts.pory"
# 38 "data/maps/PetalburgCity/scripts.pory"
# 77 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WallyTutorialPlayer
# 78 "data/maps/PetalburgCity/scripts.pory"
# 39 "data/maps/PetalburgCity/scripts.pory"
# 79 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 80 "data/maps/PetalburgCity/scripts.pory"
# 40 "data/maps/PetalburgCity/scripts.pory"
# 81 "data/maps/PetalburgCity/scripts.pory"
	msgbox Route102_Text_WatchMeCatchPokemon, MSGBOX_DEFAULT
# 82 "data/maps/PetalburgCity/scripts.pory"
# 41 "data/maps/PetalburgCity/scripts.pory"
# 83 "data/maps/PetalburgCity/scripts.pory"
	special StartWallyTutorialBattle
# 84 "data/maps/PetalburgCity/scripts.pory"
# 42 "data/maps/PetalburgCity/scripts.pory"
# 85 "data/maps/PetalburgCity/scripts.pory"
	waitstate
# 86 "data/maps/PetalburgCity/scripts.pory"
# 43 "data/maps/PetalburgCity/scripts.pory"
# 87 "data/maps/PetalburgCity/scripts.pory"
	msgbox Route102_Text_WallyIDidIt, MSGBOX_DEFAULT
# 88 "data/maps/PetalburgCity/scripts.pory"
# 44 "data/maps/PetalburgCity/scripts.pory"
# 89 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLY, Common_Movement_WalkInPlaceFasterLeft, MAP_PETALBURG_CITY
# 90 "data/maps/PetalburgCity/scripts.pory"
# 45 "data/maps/PetalburgCity/scripts.pory"
# 91 "data/maps/PetalburgCity/scripts.pory"
	waitmovement LOCALID_PETALBURG_WALLY, MAP_PETALBURG_CITY
# 92 "data/maps/PetalburgCity/scripts.pory"
# 46 "data/maps/PetalburgCity/scripts.pory"
# 93 "data/maps/PetalburgCity/scripts.pory"
	msgbox Route102_Text_LetsGoBack, MSGBOX_DEFAULT
# 94 "data/maps/PetalburgCity/scripts.pory"
# 47 "data/maps/PetalburgCity/scripts.pory"
# 95 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 96 "data/maps/PetalburgCity/scripts.pory"
# 48 "data/maps/PetalburgCity/scripts.pory"
# 97 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 98 "data/maps/PetalburgCity/scripts.pory"
# 49 "data/maps/PetalburgCity/scripts.pory"
# 99 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 3
# 100 "data/maps/PetalburgCity/scripts.pory"
# 50 "data/maps/PetalburgCity/scripts.pory"
# 101 "data/maps/PetalburgCity/scripts.pory"
	fadedefaultbgm
# 102 "data/maps/PetalburgCity/scripts.pory"
# 51 "data/maps/PetalburgCity/scripts.pory"
# 103 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 104 "data/maps/PetalburgCity/scripts.pory"
# 52 "data/maps/PetalburgCity/scripts.pory"
# 105 "data/maps/PetalburgCity/scripts.pory"
	special LoadPlayerParty
# 106 "data/maps/PetalburgCity/scripts.pory"
# 53 "data/maps/PetalburgCity/scripts.pory"
# 107 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 108 "data/maps/PetalburgCity/scripts.pory"
# 54 "data/maps/PetalburgCity/scripts.pory"
# 109 "data/maps/PetalburgCity/scripts.pory"
	warp MAP_PETALBURG_CITY_GYM, 4, 108
# 110 "data/maps/PetalburgCity/scripts.pory"
# 55 "data/maps/PetalburgCity/scripts.pory"
# 111 "data/maps/PetalburgCity/scripts.pory"
	waitstate
# 112 "data/maps/PetalburgCity/scripts.pory"
# 56 "data/maps/PetalburgCity/scripts.pory"
# 113 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 114 "data/maps/PetalburgCity/scripts.pory"
# 57 "data/maps/PetalburgCity/scripts.pory"
# 115 "data/maps/PetalburgCity/scripts.pory"
	end
# 116 "data/maps/PetalburgCity/scripts.pory"
# 58 "data/maps/PetalburgCity/scripts.pory"
# 117 "data/maps/PetalburgCity/scripts.pory"

# 118 "data/maps/PetalburgCity/scripts.pory"
# 59 "data/maps/PetalburgCity/scripts.pory"
# 119 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WalkToWallyHouse::
# 120 "data/maps/PetalburgCity/scripts.pory"
# 60 "data/maps/PetalburgCity/scripts.pory"
# 121 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 122 "data/maps/PetalburgCity/scripts.pory"
# 61 "data/maps/PetalburgCity/scripts.pory"
# 123 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 124 "data/maps/PetalburgCity/scripts.pory"
# 62 "data/maps/PetalburgCity/scripts.pory"
# 125 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLYS_DAD, PetalburgCity_Movement_WalkToWallyHouseWallysDad
# 126 "data/maps/PetalburgCity/scripts.pory"
# 63 "data/maps/PetalburgCity/scripts.pory"
# 127 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WalkToWallyHousePlayer
# 128 "data/maps/PetalburgCity/scripts.pory"
# 64 "data/maps/PetalburgCity/scripts.pory"
# 129 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 130 "data/maps/PetalburgCity/scripts.pory"
# 65 "data/maps/PetalburgCity/scripts.pory"
# 131 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8004, 7
# 132 "data/maps/PetalburgCity/scripts.pory"
# 66 "data/maps/PetalburgCity/scripts.pory"
# 133 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8005, 5
# 134 "data/maps/PetalburgCity/scripts.pory"
# 67 "data/maps/PetalburgCity/scripts.pory"
# 135 "data/maps/PetalburgCity/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 136 "data/maps/PetalburgCity/scripts.pory"
# 68 "data/maps/PetalburgCity/scripts.pory"
# 137 "data/maps/PetalburgCity/scripts.pory"
	waitdooranim
# 138 "data/maps/PetalburgCity/scripts.pory"
# 69 "data/maps/PetalburgCity/scripts.pory"
# 139 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLYS_DAD, PetalburgCity_Movement_WalkInsideHouseWallysDad
# 140 "data/maps/PetalburgCity/scripts.pory"
# 70 "data/maps/PetalburgCity/scripts.pory"
# 141 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WalkInsideHousePlayer
# 142 "data/maps/PetalburgCity/scripts.pory"
# 71 "data/maps/PetalburgCity/scripts.pory"
# 143 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 144 "data/maps/PetalburgCity/scripts.pory"
# 72 "data/maps/PetalburgCity/scripts.pory"
# 145 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
# 146 "data/maps/PetalburgCity/scripts.pory"
# 73 "data/maps/PetalburgCity/scripts.pory"
# 147 "data/maps/PetalburgCity/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_PETALBURG_CITY
# 148 "data/maps/PetalburgCity/scripts.pory"
# 74 "data/maps/PetalburgCity/scripts.pory"
# 149 "data/maps/PetalburgCity/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 150 "data/maps/PetalburgCity/scripts.pory"
# 75 "data/maps/PetalburgCity/scripts.pory"
# 151 "data/maps/PetalburgCity/scripts.pory"
	waitdooranim
# 152 "data/maps/PetalburgCity/scripts.pory"
# 76 "data/maps/PetalburgCity/scripts.pory"
# 153 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 154 "data/maps/PetalburgCity/scripts.pory"
# 77 "data/maps/PetalburgCity/scripts.pory"
# 155 "data/maps/PetalburgCity/scripts.pory"
	fadedefaultbgm
# 156 "data/maps/PetalburgCity/scripts.pory"
# 78 "data/maps/PetalburgCity/scripts.pory"
# 157 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 158 "data/maps/PetalburgCity/scripts.pory"
# 79 "data/maps/PetalburgCity/scripts.pory"
# 159 "data/maps/PetalburgCity/scripts.pory"
	warp MAP_PETALBURG_CITY_WALLYS_HOUSE, 2, 4
# 160 "data/maps/PetalburgCity/scripts.pory"
# 80 "data/maps/PetalburgCity/scripts.pory"
# 161 "data/maps/PetalburgCity/scripts.pory"
	waitstate
# 162 "data/maps/PetalburgCity/scripts.pory"
# 81 "data/maps/PetalburgCity/scripts.pory"
# 163 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 164 "data/maps/PetalburgCity/scripts.pory"
# 82 "data/maps/PetalburgCity/scripts.pory"
# 165 "data/maps/PetalburgCity/scripts.pory"
	end
# 166 "data/maps/PetalburgCity/scripts.pory"
# 83 "data/maps/PetalburgCity/scripts.pory"
# 167 "data/maps/PetalburgCity/scripts.pory"

# 168 "data/maps/PetalburgCity/scripts.pory"
# 84 "data/maps/PetalburgCity/scripts.pory"
# 169 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Boy::
# 170 "data/maps/PetalburgCity/scripts.pory"
# 85 "data/maps/PetalburgCity/scripts.pory"
# 171 "data/maps/PetalburgCity/scripts.pory"
	lock
# 172 "data/maps/PetalburgCity/scripts.pory"
# 86 "data/maps/PetalburgCity/scripts.pory"
# 173 "data/maps/PetalburgCity/scripts.pory"
	faceplayer
# 174 "data/maps/PetalburgCity/scripts.pory"
# 87 "data/maps/PetalburgCity/scripts.pory"
# 175 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
# 176 "data/maps/PetalburgCity/scripts.pory"
# 88 "data/maps/PetalburgCity/scripts.pory"
# 177 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 178 "data/maps/PetalburgCity/scripts.pory"
# 89 "data/maps/PetalburgCity/scripts.pory"
# 179 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_BOY, Common_Movement_FaceOriginalDirection
# 180 "data/maps/PetalburgCity/scripts.pory"
# 90 "data/maps/PetalburgCity/scripts.pory"
# 181 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 182 "data/maps/PetalburgCity/scripts.pory"
# 91 "data/maps/PetalburgCity/scripts.pory"
# 183 "data/maps/PetalburgCity/scripts.pory"
	release
# 184 "data/maps/PetalburgCity/scripts.pory"
# 92 "data/maps/PetalburgCity/scripts.pory"
# 185 "data/maps/PetalburgCity/scripts.pory"
	end
# 186 "data/maps/PetalburgCity/scripts.pory"
# 93 "data/maps/PetalburgCity/scripts.pory"
# 187 "data/maps/PetalburgCity/scripts.pory"

# 188 "data/maps/PetalburgCity/scripts.pory"
# 94 "data/maps/PetalburgCity/scripts.pory"
# 189 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WallysMom::
# 190 "data/maps/PetalburgCity/scripts.pory"
# 95 "data/maps/PetalburgCity/scripts.pory"
# 191 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_WhereIsWally, MSGBOX_NPC
# 192 "data/maps/PetalburgCity/scripts.pory"
# 96 "data/maps/PetalburgCity/scripts.pory"
# 193 "data/maps/PetalburgCity/scripts.pory"
	end
# 194 "data/maps/PetalburgCity/scripts.pory"
# 97 "data/maps/PetalburgCity/scripts.pory"
# 195 "data/maps/PetalburgCity/scripts.pory"

# 196 "data/maps/PetalburgCity/scripts.pory"
# 98 "data/maps/PetalburgCity/scripts.pory"
# 197 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkToWallyHousePlayer:
# 198 "data/maps/PetalburgCity/scripts.pory"
# 99 "data/maps/PetalburgCity/scripts.pory"
# 199 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 200 "data/maps/PetalburgCity/scripts.pory"
# 100 "data/maps/PetalburgCity/scripts.pory"
# 201 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 202 "data/maps/PetalburgCity/scripts.pory"
# 101 "data/maps/PetalburgCity/scripts.pory"
# 203 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 204 "data/maps/PetalburgCity/scripts.pory"
# 102 "data/maps/PetalburgCity/scripts.pory"
# 205 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 206 "data/maps/PetalburgCity/scripts.pory"
# 103 "data/maps/PetalburgCity/scripts.pory"
# 207 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 208 "data/maps/PetalburgCity/scripts.pory"
# 104 "data/maps/PetalburgCity/scripts.pory"
# 209 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 210 "data/maps/PetalburgCity/scripts.pory"
# 105 "data/maps/PetalburgCity/scripts.pory"
# 211 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 212 "data/maps/PetalburgCity/scripts.pory"
# 106 "data/maps/PetalburgCity/scripts.pory"
# 213 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 214 "data/maps/PetalburgCity/scripts.pory"
# 107 "data/maps/PetalburgCity/scripts.pory"
# 215 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 216 "data/maps/PetalburgCity/scripts.pory"
# 108 "data/maps/PetalburgCity/scripts.pory"
# 217 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 218 "data/maps/PetalburgCity/scripts.pory"
# 109 "data/maps/PetalburgCity/scripts.pory"
# 219 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 220 "data/maps/PetalburgCity/scripts.pory"
# 110 "data/maps/PetalburgCity/scripts.pory"
# 221 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 222 "data/maps/PetalburgCity/scripts.pory"
# 111 "data/maps/PetalburgCity/scripts.pory"
# 223 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 224 "data/maps/PetalburgCity/scripts.pory"
# 112 "data/maps/PetalburgCity/scripts.pory"
# 225 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 226 "data/maps/PetalburgCity/scripts.pory"
# 113 "data/maps/PetalburgCity/scripts.pory"
# 227 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 228 "data/maps/PetalburgCity/scripts.pory"
# 114 "data/maps/PetalburgCity/scripts.pory"
# 229 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 230 "data/maps/PetalburgCity/scripts.pory"
# 115 "data/maps/PetalburgCity/scripts.pory"
# 231 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 232 "data/maps/PetalburgCity/scripts.pory"
# 116 "data/maps/PetalburgCity/scripts.pory"
# 233 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 234 "data/maps/PetalburgCity/scripts.pory"
# 117 "data/maps/PetalburgCity/scripts.pory"
# 235 "data/maps/PetalburgCity/scripts.pory"

# 236 "data/maps/PetalburgCity/scripts.pory"
# 118 "data/maps/PetalburgCity/scripts.pory"
# 237 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkInsideHousePlayer:
# 238 "data/maps/PetalburgCity/scripts.pory"
# 119 "data/maps/PetalburgCity/scripts.pory"
# 239 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 240 "data/maps/PetalburgCity/scripts.pory"
# 120 "data/maps/PetalburgCity/scripts.pory"
# 241 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 242 "data/maps/PetalburgCity/scripts.pory"
# 121 "data/maps/PetalburgCity/scripts.pory"
# 243 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 244 "data/maps/PetalburgCity/scripts.pory"
# 122 "data/maps/PetalburgCity/scripts.pory"
# 245 "data/maps/PetalburgCity/scripts.pory"

# 246 "data/maps/PetalburgCity/scripts.pory"
# 123 "data/maps/PetalburgCity/scripts.pory"
# 247 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkToWallyHouseWallysDad:
# 248 "data/maps/PetalburgCity/scripts.pory"
# 124 "data/maps/PetalburgCity/scripts.pory"
# 249 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 250 "data/maps/PetalburgCity/scripts.pory"
# 125 "data/maps/PetalburgCity/scripts.pory"
# 251 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 252 "data/maps/PetalburgCity/scripts.pory"
# 126 "data/maps/PetalburgCity/scripts.pory"
# 253 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 254 "data/maps/PetalburgCity/scripts.pory"
# 127 "data/maps/PetalburgCity/scripts.pory"
# 255 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 256 "data/maps/PetalburgCity/scripts.pory"
# 128 "data/maps/PetalburgCity/scripts.pory"
# 257 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 258 "data/maps/PetalburgCity/scripts.pory"
# 129 "data/maps/PetalburgCity/scripts.pory"
# 259 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 260 "data/maps/PetalburgCity/scripts.pory"
# 130 "data/maps/PetalburgCity/scripts.pory"
# 261 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 262 "data/maps/PetalburgCity/scripts.pory"
# 131 "data/maps/PetalburgCity/scripts.pory"
# 263 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 264 "data/maps/PetalburgCity/scripts.pory"
# 132 "data/maps/PetalburgCity/scripts.pory"
# 265 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 266 "data/maps/PetalburgCity/scripts.pory"
# 133 "data/maps/PetalburgCity/scripts.pory"
# 267 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 268 "data/maps/PetalburgCity/scripts.pory"
# 134 "data/maps/PetalburgCity/scripts.pory"
# 269 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 270 "data/maps/PetalburgCity/scripts.pory"
# 135 "data/maps/PetalburgCity/scripts.pory"
# 271 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 272 "data/maps/PetalburgCity/scripts.pory"
# 136 "data/maps/PetalburgCity/scripts.pory"
# 273 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 274 "data/maps/PetalburgCity/scripts.pory"
# 137 "data/maps/PetalburgCity/scripts.pory"
# 275 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 276 "data/maps/PetalburgCity/scripts.pory"
# 138 "data/maps/PetalburgCity/scripts.pory"
# 277 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 278 "data/maps/PetalburgCity/scripts.pory"
# 139 "data/maps/PetalburgCity/scripts.pory"
# 279 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 280 "data/maps/PetalburgCity/scripts.pory"
# 140 "data/maps/PetalburgCity/scripts.pory"
# 281 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 282 "data/maps/PetalburgCity/scripts.pory"
# 141 "data/maps/PetalburgCity/scripts.pory"
# 283 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 284 "data/maps/PetalburgCity/scripts.pory"
# 142 "data/maps/PetalburgCity/scripts.pory"
# 285 "data/maps/PetalburgCity/scripts.pory"

# 286 "data/maps/PetalburgCity/scripts.pory"
# 143 "data/maps/PetalburgCity/scripts.pory"
# 287 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkInsideHouseWallysDad:
# 288 "data/maps/PetalburgCity/scripts.pory"
# 144 "data/maps/PetalburgCity/scripts.pory"
# 289 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 290 "data/maps/PetalburgCity/scripts.pory"
# 145 "data/maps/PetalburgCity/scripts.pory"
# 291 "data/maps/PetalburgCity/scripts.pory"
	set_invisible
# 292 "data/maps/PetalburgCity/scripts.pory"
# 146 "data/maps/PetalburgCity/scripts.pory"
# 293 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 294 "data/maps/PetalburgCity/scripts.pory"
# 147 "data/maps/PetalburgCity/scripts.pory"
# 295 "data/maps/PetalburgCity/scripts.pory"

# 296 "data/maps/PetalburgCity/scripts.pory"
# 148 "data/maps/PetalburgCity/scripts.pory"
# 297 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WallyTutorialPlayer:
# 298 "data/maps/PetalburgCity/scripts.pory"
# 149 "data/maps/PetalburgCity/scripts.pory"
# 299 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 300 "data/maps/PetalburgCity/scripts.pory"
# 150 "data/maps/PetalburgCity/scripts.pory"
# 301 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 302 "data/maps/PetalburgCity/scripts.pory"
# 151 "data/maps/PetalburgCity/scripts.pory"
# 303 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 304 "data/maps/PetalburgCity/scripts.pory"
# 152 "data/maps/PetalburgCity/scripts.pory"
# 305 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 306 "data/maps/PetalburgCity/scripts.pory"
# 153 "data/maps/PetalburgCity/scripts.pory"
# 307 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 308 "data/maps/PetalburgCity/scripts.pory"
# 154 "data/maps/PetalburgCity/scripts.pory"
# 309 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 310 "data/maps/PetalburgCity/scripts.pory"
# 155 "data/maps/PetalburgCity/scripts.pory"
# 311 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 312 "data/maps/PetalburgCity/scripts.pory"
# 156 "data/maps/PetalburgCity/scripts.pory"
# 313 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 314 "data/maps/PetalburgCity/scripts.pory"
# 157 "data/maps/PetalburgCity/scripts.pory"
# 315 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 316 "data/maps/PetalburgCity/scripts.pory"
# 158 "data/maps/PetalburgCity/scripts.pory"
# 317 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 318 "data/maps/PetalburgCity/scripts.pory"
# 159 "data/maps/PetalburgCity/scripts.pory"
# 319 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 320 "data/maps/PetalburgCity/scripts.pory"
# 160 "data/maps/PetalburgCity/scripts.pory"
# 321 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 322 "data/maps/PetalburgCity/scripts.pory"
# 161 "data/maps/PetalburgCity/scripts.pory"
# 323 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 324 "data/maps/PetalburgCity/scripts.pory"
# 162 "data/maps/PetalburgCity/scripts.pory"
# 325 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 326 "data/maps/PetalburgCity/scripts.pory"
# 163 "data/maps/PetalburgCity/scripts.pory"
# 327 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 328 "data/maps/PetalburgCity/scripts.pory"
# 164 "data/maps/PetalburgCity/scripts.pory"
# 329 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 330 "data/maps/PetalburgCity/scripts.pory"
# 165 "data/maps/PetalburgCity/scripts.pory"
# 331 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 332 "data/maps/PetalburgCity/scripts.pory"
# 166 "data/maps/PetalburgCity/scripts.pory"
# 333 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 334 "data/maps/PetalburgCity/scripts.pory"
# 167 "data/maps/PetalburgCity/scripts.pory"
# 335 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 336 "data/maps/PetalburgCity/scripts.pory"
# 168 "data/maps/PetalburgCity/scripts.pory"
# 337 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 338 "data/maps/PetalburgCity/scripts.pory"
# 169 "data/maps/PetalburgCity/scripts.pory"
# 339 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 340 "data/maps/PetalburgCity/scripts.pory"
# 170 "data/maps/PetalburgCity/scripts.pory"
# 341 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 342 "data/maps/PetalburgCity/scripts.pory"
# 171 "data/maps/PetalburgCity/scripts.pory"
# 343 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 344 "data/maps/PetalburgCity/scripts.pory"
# 172 "data/maps/PetalburgCity/scripts.pory"
# 345 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 346 "data/maps/PetalburgCity/scripts.pory"
# 173 "data/maps/PetalburgCity/scripts.pory"
# 347 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 348 "data/maps/PetalburgCity/scripts.pory"
# 174 "data/maps/PetalburgCity/scripts.pory"
# 349 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 350 "data/maps/PetalburgCity/scripts.pory"
# 175 "data/maps/PetalburgCity/scripts.pory"
# 351 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 352 "data/maps/PetalburgCity/scripts.pory"
# 176 "data/maps/PetalburgCity/scripts.pory"
# 353 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 354 "data/maps/PetalburgCity/scripts.pory"
# 177 "data/maps/PetalburgCity/scripts.pory"
# 355 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 356 "data/maps/PetalburgCity/scripts.pory"
# 178 "data/maps/PetalburgCity/scripts.pory"
# 357 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 358 "data/maps/PetalburgCity/scripts.pory"
# 179 "data/maps/PetalburgCity/scripts.pory"
# 359 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 360 "data/maps/PetalburgCity/scripts.pory"
# 180 "data/maps/PetalburgCity/scripts.pory"
# 361 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_right
# 362 "data/maps/PetalburgCity/scripts.pory"
# 181 "data/maps/PetalburgCity/scripts.pory"
# 363 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 364 "data/maps/PetalburgCity/scripts.pory"
# 182 "data/maps/PetalburgCity/scripts.pory"
# 365 "data/maps/PetalburgCity/scripts.pory"

# 366 "data/maps/PetalburgCity/scripts.pory"
# 183 "data/maps/PetalburgCity/scripts.pory"
# 367 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WallyTutorialWally:
# 368 "data/maps/PetalburgCity/scripts.pory"
# 184 "data/maps/PetalburgCity/scripts.pory"
# 369 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 370 "data/maps/PetalburgCity/scripts.pory"
# 185 "data/maps/PetalburgCity/scripts.pory"
# 371 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 372 "data/maps/PetalburgCity/scripts.pory"
# 186 "data/maps/PetalburgCity/scripts.pory"
# 373 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 374 "data/maps/PetalburgCity/scripts.pory"
# 187 "data/maps/PetalburgCity/scripts.pory"
# 375 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 376 "data/maps/PetalburgCity/scripts.pory"
# 188 "data/maps/PetalburgCity/scripts.pory"
# 377 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 378 "data/maps/PetalburgCity/scripts.pory"
# 189 "data/maps/PetalburgCity/scripts.pory"
# 379 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 380 "data/maps/PetalburgCity/scripts.pory"
# 190 "data/maps/PetalburgCity/scripts.pory"
# 381 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 382 "data/maps/PetalburgCity/scripts.pory"
# 191 "data/maps/PetalburgCity/scripts.pory"
# 383 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 384 "data/maps/PetalburgCity/scripts.pory"
# 192 "data/maps/PetalburgCity/scripts.pory"
# 385 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 386 "data/maps/PetalburgCity/scripts.pory"
# 193 "data/maps/PetalburgCity/scripts.pory"
# 387 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 388 "data/maps/PetalburgCity/scripts.pory"
# 194 "data/maps/PetalburgCity/scripts.pory"
# 389 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 390 "data/maps/PetalburgCity/scripts.pory"
# 195 "data/maps/PetalburgCity/scripts.pory"
# 391 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 392 "data/maps/PetalburgCity/scripts.pory"
# 196 "data/maps/PetalburgCity/scripts.pory"
# 393 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 394 "data/maps/PetalburgCity/scripts.pory"
# 197 "data/maps/PetalburgCity/scripts.pory"
# 395 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 396 "data/maps/PetalburgCity/scripts.pory"
# 198 "data/maps/PetalburgCity/scripts.pory"
# 397 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 398 "data/maps/PetalburgCity/scripts.pory"
# 199 "data/maps/PetalburgCity/scripts.pory"
# 399 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 400 "data/maps/PetalburgCity/scripts.pory"
# 200 "data/maps/PetalburgCity/scripts.pory"
# 401 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 402 "data/maps/PetalburgCity/scripts.pory"
# 201 "data/maps/PetalburgCity/scripts.pory"
# 403 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 404 "data/maps/PetalburgCity/scripts.pory"
# 202 "data/maps/PetalburgCity/scripts.pory"
# 405 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 406 "data/maps/PetalburgCity/scripts.pory"
# 203 "data/maps/PetalburgCity/scripts.pory"
# 407 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 408 "data/maps/PetalburgCity/scripts.pory"
# 204 "data/maps/PetalburgCity/scripts.pory"
# 409 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 410 "data/maps/PetalburgCity/scripts.pory"
# 205 "data/maps/PetalburgCity/scripts.pory"
# 411 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 412 "data/maps/PetalburgCity/scripts.pory"
# 206 "data/maps/PetalburgCity/scripts.pory"
# 413 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 414 "data/maps/PetalburgCity/scripts.pory"
# 207 "data/maps/PetalburgCity/scripts.pory"
# 415 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 416 "data/maps/PetalburgCity/scripts.pory"
# 208 "data/maps/PetalburgCity/scripts.pory"
# 417 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 418 "data/maps/PetalburgCity/scripts.pory"
# 209 "data/maps/PetalburgCity/scripts.pory"
# 419 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 420 "data/maps/PetalburgCity/scripts.pory"
# 210 "data/maps/PetalburgCity/scripts.pory"
# 421 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 422 "data/maps/PetalburgCity/scripts.pory"
# 211 "data/maps/PetalburgCity/scripts.pory"
# 423 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 424 "data/maps/PetalburgCity/scripts.pory"
# 212 "data/maps/PetalburgCity/scripts.pory"
# 425 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 426 "data/maps/PetalburgCity/scripts.pory"
# 213 "data/maps/PetalburgCity/scripts.pory"
# 427 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 428 "data/maps/PetalburgCity/scripts.pory"
# 214 "data/maps/PetalburgCity/scripts.pory"
# 429 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 430 "data/maps/PetalburgCity/scripts.pory"
# 215 "data/maps/PetalburgCity/scripts.pory"
# 431 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 432 "data/maps/PetalburgCity/scripts.pory"
# 216 "data/maps/PetalburgCity/scripts.pory"
# 433 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 434 "data/maps/PetalburgCity/scripts.pory"
# 217 "data/maps/PetalburgCity/scripts.pory"
# 435 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 436 "data/maps/PetalburgCity/scripts.pory"
# 218 "data/maps/PetalburgCity/scripts.pory"
# 437 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 438 "data/maps/PetalburgCity/scripts.pory"
# 219 "data/maps/PetalburgCity/scripts.pory"
# 439 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_right
# 440 "data/maps/PetalburgCity/scripts.pory"
# 220 "data/maps/PetalburgCity/scripts.pory"
# 441 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 442 "data/maps/PetalburgCity/scripts.pory"
# 221 "data/maps/PetalburgCity/scripts.pory"
# 443 "data/maps/PetalburgCity/scripts.pory"

# 444 "data/maps/PetalburgCity/scripts.pory"
# 222 "data/maps/PetalburgCity/scripts.pory"
# 445 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_GymSign::
# 446 "data/maps/PetalburgCity/scripts.pory"
# 223 "data/maps/PetalburgCity/scripts.pory"
# 447 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
# 448 "data/maps/PetalburgCity/scripts.pory"
# 224 "data/maps/PetalburgCity/scripts.pory"
# 449 "data/maps/PetalburgCity/scripts.pory"
	end
# 450 "data/maps/PetalburgCity/scripts.pory"
# 225 "data/maps/PetalburgCity/scripts.pory"
# 451 "data/maps/PetalburgCity/scripts.pory"

# 452 "data/maps/PetalburgCity/scripts.pory"
# 226 "data/maps/PetalburgCity/scripts.pory"
# 453 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_CitySign::
# 454 "data/maps/PetalburgCity/scripts.pory"
# 227 "data/maps/PetalburgCity/scripts.pory"
# 455 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
# 456 "data/maps/PetalburgCity/scripts.pory"
# 228 "data/maps/PetalburgCity/scripts.pory"
# 457 "data/maps/PetalburgCity/scripts.pory"
	end
# 458 "data/maps/PetalburgCity/scripts.pory"
# 229 "data/maps/PetalburgCity/scripts.pory"
# 459 "data/maps/PetalburgCity/scripts.pory"

# 460 "data/maps/PetalburgCity/scripts.pory"
# 230 "data/maps/PetalburgCity/scripts.pory"
# 461 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Gentleman::
# 462 "data/maps/PetalburgCity/scripts.pory"
# 231 "data/maps/PetalburgCity/scripts.pory"
# 463 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
# 464 "data/maps/PetalburgCity/scripts.pory"
# 232 "data/maps/PetalburgCity/scripts.pory"
# 465 "data/maps/PetalburgCity/scripts.pory"
	end
# 466 "data/maps/PetalburgCity/scripts.pory"
# 233 "data/maps/PetalburgCity/scripts.pory"
# 467 "data/maps/PetalburgCity/scripts.pory"

# 468 "data/maps/PetalburgCity/scripts.pory"
# 234 "data/maps/PetalburgCity/scripts.pory"
# 469 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WallyHouseSign::
# 470 "data/maps/PetalburgCity/scripts.pory"
# 235 "data/maps/PetalburgCity/scripts.pory"
# 471 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
# 472 "data/maps/PetalburgCity/scripts.pory"
# 236 "data/maps/PetalburgCity/scripts.pory"
# 473 "data/maps/PetalburgCity/scripts.pory"
	end
# 474 "data/maps/PetalburgCity/scripts.pory"
# 237 "data/maps/PetalburgCity/scripts.pory"
# 475 "data/maps/PetalburgCity/scripts.pory"

# 476 "data/maps/PetalburgCity/scripts.pory"
# 238 "data/maps/PetalburgCity/scripts.pory"
# 477 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer0::
# 478 "data/maps/PetalburgCity/scripts.pory"
# 239 "data/maps/PetalburgCity/scripts.pory"
# 479 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 480 "data/maps/PetalburgCity/scripts.pory"
# 240 "data/maps/PetalburgCity/scripts.pory"
# 481 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 0
# 482 "data/maps/PetalburgCity/scripts.pory"
# 241 "data/maps/PetalburgCity/scripts.pory"
# 483 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 484 "data/maps/PetalburgCity/scripts.pory"
# 242 "data/maps/PetalburgCity/scripts.pory"
# 485 "data/maps/PetalburgCity/scripts.pory"
	end
# 486 "data/maps/PetalburgCity/scripts.pory"
# 243 "data/maps/PetalburgCity/scripts.pory"
# 487 "data/maps/PetalburgCity/scripts.pory"

# 488 "data/maps/PetalburgCity/scripts.pory"
# 244 "data/maps/PetalburgCity/scripts.pory"
# 489 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer1::
# 490 "data/maps/PetalburgCity/scripts.pory"
# 245 "data/maps/PetalburgCity/scripts.pory"
# 491 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 492 "data/maps/PetalburgCity/scripts.pory"
# 246 "data/maps/PetalburgCity/scripts.pory"
# 493 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 1
# 494 "data/maps/PetalburgCity/scripts.pory"
# 247 "data/maps/PetalburgCity/scripts.pory"
# 495 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 496 "data/maps/PetalburgCity/scripts.pory"
# 248 "data/maps/PetalburgCity/scripts.pory"
# 497 "data/maps/PetalburgCity/scripts.pory"
	end
# 498 "data/maps/PetalburgCity/scripts.pory"
# 249 "data/maps/PetalburgCity/scripts.pory"
# 499 "data/maps/PetalburgCity/scripts.pory"

# 500 "data/maps/PetalburgCity/scripts.pory"
# 250 "data/maps/PetalburgCity/scripts.pory"
# 501 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer2::
# 502 "data/maps/PetalburgCity/scripts.pory"
# 251 "data/maps/PetalburgCity/scripts.pory"
# 503 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 504 "data/maps/PetalburgCity/scripts.pory"
# 252 "data/maps/PetalburgCity/scripts.pory"
# 505 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 2
# 506 "data/maps/PetalburgCity/scripts.pory"
# 253 "data/maps/PetalburgCity/scripts.pory"
# 507 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 508 "data/maps/PetalburgCity/scripts.pory"
# 254 "data/maps/PetalburgCity/scripts.pory"
# 509 "data/maps/PetalburgCity/scripts.pory"
	end
# 510 "data/maps/PetalburgCity/scripts.pory"
# 255 "data/maps/PetalburgCity/scripts.pory"
# 511 "data/maps/PetalburgCity/scripts.pory"

# 512 "data/maps/PetalburgCity/scripts.pory"
# 256 "data/maps/PetalburgCity/scripts.pory"
# 513 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer3::
# 514 "data/maps/PetalburgCity/scripts.pory"
# 257 "data/maps/PetalburgCity/scripts.pory"
# 515 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 516 "data/maps/PetalburgCity/scripts.pory"
# 258 "data/maps/PetalburgCity/scripts.pory"
# 517 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 3
# 518 "data/maps/PetalburgCity/scripts.pory"
# 259 "data/maps/PetalburgCity/scripts.pory"
# 519 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 520 "data/maps/PetalburgCity/scripts.pory"
# 260 "data/maps/PetalburgCity/scripts.pory"
# 521 "data/maps/PetalburgCity/scripts.pory"
	end
# 522 "data/maps/PetalburgCity/scripts.pory"
# 261 "data/maps/PetalburgCity/scripts.pory"
# 523 "data/maps/PetalburgCity/scripts.pory"

# 524 "data/maps/PetalburgCity/scripts.pory"
# 262 "data/maps/PetalburgCity/scripts.pory"
# 525 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer::
# 526 "data/maps/PetalburgCity/scripts.pory"
# 263 "data/maps/PetalburgCity/scripts.pory"
# 527 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_FacePlayer
# 528 "data/maps/PetalburgCity/scripts.pory"
# 264 "data/maps/PetalburgCity/scripts.pory"
# 529 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 530 "data/maps/PetalburgCity/scripts.pory"
# 265 "data/maps/PetalburgCity/scripts.pory"
# 531 "data/maps/PetalburgCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 532 "data/maps/PetalburgCity/scripts.pory"
# 266 "data/maps/PetalburgCity/scripts.pory"
# 533 "data/maps/PetalburgCity/scripts.pory"
	playse SE_PIN
# 534 "data/maps/PetalburgCity/scripts.pory"
# 267 "data/maps/PetalburgCity/scripts.pory"
# 535 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_ExclamationMark
# 536 "data/maps/PetalburgCity/scripts.pory"
# 268 "data/maps/PetalburgCity/scripts.pory"
# 537 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 538 "data/maps/PetalburgCity/scripts.pory"
# 269 "data/maps/PetalburgCity/scripts.pory"
# 539 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_Delay48
# 540 "data/maps/PetalburgCity/scripts.pory"
# 270 "data/maps/PetalburgCity/scripts.pory"
# 541 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 542 "data/maps/PetalburgCity/scripts.pory"
# 271 "data/maps/PetalburgCity/scripts.pory"
# 543 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_BoyApproachPlayer0
# 544 "data/maps/PetalburgCity/scripts.pory"
# 272 "data/maps/PetalburgCity/scripts.pory"
# 545 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_BoyApproachPlayer1
# 546 "data/maps/PetalburgCity/scripts.pory"
# 273 "data/maps/PetalburgCity/scripts.pory"
# 547 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_BoyApproachPlayer2
# 548 "data/maps/PetalburgCity/scripts.pory"
# 274 "data/maps/PetalburgCity/scripts.pory"
# 549 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_BoyApproachPlayer3
# 550 "data/maps/PetalburgCity/scripts.pory"
# 275 "data/maps/PetalburgCity/scripts.pory"
# 551 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_DEFAULT
# 552 "data/maps/PetalburgCity/scripts.pory"
# 276 "data/maps/PetalburgCity/scripts.pory"
# 553 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 554 "data/maps/PetalburgCity/scripts.pory"
# 277 "data/maps/PetalburgCity/scripts.pory"
# 555 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_LeadPlayerToGym0
# 556 "data/maps/PetalburgCity/scripts.pory"
# 278 "data/maps/PetalburgCity/scripts.pory"
# 557 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_LeadPlayerToGym1
# 558 "data/maps/PetalburgCity/scripts.pory"
# 279 "data/maps/PetalburgCity/scripts.pory"
# 559 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_LeadPlayerToGym2
# 560 "data/maps/PetalburgCity/scripts.pory"
# 280 "data/maps/PetalburgCity/scripts.pory"
# 561 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_LeadPlayerToGym3
# 562 "data/maps/PetalburgCity/scripts.pory"
# 281 "data/maps/PetalburgCity/scripts.pory"
# 563 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_ThisIsPetalburgGym, MSGBOX_DEFAULT
# 564 "data/maps/PetalburgCity/scripts.pory"
# 282 "data/maps/PetalburgCity/scripts.pory"
# 565 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_WalkInPlaceFasterRight
# 566 "data/maps/PetalburgCity/scripts.pory"
# 283 "data/maps/PetalburgCity/scripts.pory"
# 567 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 568 "data/maps/PetalburgCity/scripts.pory"
# 284 "data/maps/PetalburgCity/scripts.pory"
# 569 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 570 "data/maps/PetalburgCity/scripts.pory"
# 285 "data/maps/PetalburgCity/scripts.pory"
# 571 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_ThisIsGymSign, MSGBOX_DEFAULT
# 572 "data/maps/PetalburgCity/scripts.pory"
# 286 "data/maps/PetalburgCity/scripts.pory"
# 573 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 574 "data/maps/PetalburgCity/scripts.pory"
# 287 "data/maps/PetalburgCity/scripts.pory"
# 575 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkAway
# 576 "data/maps/PetalburgCity/scripts.pory"
# 288 "data/maps/PetalburgCity/scripts.pory"
# 577 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 578 "data/maps/PetalburgCity/scripts.pory"
# 289 "data/maps/PetalburgCity/scripts.pory"
# 579 "data/maps/PetalburgCity/scripts.pory"
	fadedefaultbgm
# 580 "data/maps/PetalburgCity/scripts.pory"
# 290 "data/maps/PetalburgCity/scripts.pory"
# 581 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 582 "data/maps/PetalburgCity/scripts.pory"
# 291 "data/maps/PetalburgCity/scripts.pory"
# 583 "data/maps/PetalburgCity/scripts.pory"
	end
# 584 "data/maps/PetalburgCity/scripts.pory"
# 292 "data/maps/PetalburgCity/scripts.pory"
# 585 "data/maps/PetalburgCity/scripts.pory"

# 586 "data/maps/PetalburgCity/scripts.pory"
# 293 "data/maps/PetalburgCity/scripts.pory"
# 587 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer0::
# 588 "data/maps/PetalburgCity/scripts.pory"
# 294 "data/maps/PetalburgCity/scripts.pory"
# 589 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer0
# 590 "data/maps/PetalburgCity/scripts.pory"
# 295 "data/maps/PetalburgCity/scripts.pory"
# 591 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 592 "data/maps/PetalburgCity/scripts.pory"
# 296 "data/maps/PetalburgCity/scripts.pory"
# 593 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 594 "data/maps/PetalburgCity/scripts.pory"
# 297 "data/maps/PetalburgCity/scripts.pory"
# 595 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 596 "data/maps/PetalburgCity/scripts.pory"
# 298 "data/maps/PetalburgCity/scripts.pory"
# 597 "data/maps/PetalburgCity/scripts.pory"
	return
# 598 "data/maps/PetalburgCity/scripts.pory"
# 299 "data/maps/PetalburgCity/scripts.pory"
# 599 "data/maps/PetalburgCity/scripts.pory"

# 600 "data/maps/PetalburgCity/scripts.pory"
# 300 "data/maps/PetalburgCity/scripts.pory"
# 601 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer1::
# 602 "data/maps/PetalburgCity/scripts.pory"
# 301 "data/maps/PetalburgCity/scripts.pory"
# 603 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer1
# 604 "data/maps/PetalburgCity/scripts.pory"
# 302 "data/maps/PetalburgCity/scripts.pory"
# 605 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 606 "data/maps/PetalburgCity/scripts.pory"
# 303 "data/maps/PetalburgCity/scripts.pory"
# 607 "data/maps/PetalburgCity/scripts.pory"
	return
# 608 "data/maps/PetalburgCity/scripts.pory"
# 304 "data/maps/PetalburgCity/scripts.pory"
# 609 "data/maps/PetalburgCity/scripts.pory"

# 610 "data/maps/PetalburgCity/scripts.pory"
# 305 "data/maps/PetalburgCity/scripts.pory"
# 611 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer2::
# 612 "data/maps/PetalburgCity/scripts.pory"
# 306 "data/maps/PetalburgCity/scripts.pory"
# 613 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer2
# 614 "data/maps/PetalburgCity/scripts.pory"
# 307 "data/maps/PetalburgCity/scripts.pory"
# 615 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 616 "data/maps/PetalburgCity/scripts.pory"
# 308 "data/maps/PetalburgCity/scripts.pory"
# 617 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 618 "data/maps/PetalburgCity/scripts.pory"
# 309 "data/maps/PetalburgCity/scripts.pory"
# 619 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 620 "data/maps/PetalburgCity/scripts.pory"
# 310 "data/maps/PetalburgCity/scripts.pory"
# 621 "data/maps/PetalburgCity/scripts.pory"
	return
# 622 "data/maps/PetalburgCity/scripts.pory"
# 311 "data/maps/PetalburgCity/scripts.pory"
# 623 "data/maps/PetalburgCity/scripts.pory"

# 624 "data/maps/PetalburgCity/scripts.pory"
# 312 "data/maps/PetalburgCity/scripts.pory"
# 625 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer3::
# 626 "data/maps/PetalburgCity/scripts.pory"
# 313 "data/maps/PetalburgCity/scripts.pory"
# 627 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer3
# 628 "data/maps/PetalburgCity/scripts.pory"
# 314 "data/maps/PetalburgCity/scripts.pory"
# 629 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 630 "data/maps/PetalburgCity/scripts.pory"
# 315 "data/maps/PetalburgCity/scripts.pory"
# 631 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 632 "data/maps/PetalburgCity/scripts.pory"
# 316 "data/maps/PetalburgCity/scripts.pory"
# 633 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 634 "data/maps/PetalburgCity/scripts.pory"
# 317 "data/maps/PetalburgCity/scripts.pory"
# 635 "data/maps/PetalburgCity/scripts.pory"
	return
# 636 "data/maps/PetalburgCity/scripts.pory"
# 318 "data/maps/PetalburgCity/scripts.pory"
# 637 "data/maps/PetalburgCity/scripts.pory"

# 638 "data/maps/PetalburgCity/scripts.pory"
# 319 "data/maps/PetalburgCity/scripts.pory"
# 639 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym0::
# 640 "data/maps/PetalburgCity/scripts.pory"
# 320 "data/maps/PetalburgCity/scripts.pory"
# 641 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym0
# 642 "data/maps/PetalburgCity/scripts.pory"
# 321 "data/maps/PetalburgCity/scripts.pory"
# 643 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym0
# 644 "data/maps/PetalburgCity/scripts.pory"
# 322 "data/maps/PetalburgCity/scripts.pory"
# 645 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 646 "data/maps/PetalburgCity/scripts.pory"
# 323 "data/maps/PetalburgCity/scripts.pory"
# 647 "data/maps/PetalburgCity/scripts.pory"
	return
# 648 "data/maps/PetalburgCity/scripts.pory"
# 324 "data/maps/PetalburgCity/scripts.pory"
# 649 "data/maps/PetalburgCity/scripts.pory"

# 650 "data/maps/PetalburgCity/scripts.pory"
# 325 "data/maps/PetalburgCity/scripts.pory"
# 651 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym1::
# 652 "data/maps/PetalburgCity/scripts.pory"
# 326 "data/maps/PetalburgCity/scripts.pory"
# 653 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym1
# 654 "data/maps/PetalburgCity/scripts.pory"
# 327 "data/maps/PetalburgCity/scripts.pory"
# 655 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym1
# 656 "data/maps/PetalburgCity/scripts.pory"
# 328 "data/maps/PetalburgCity/scripts.pory"
# 657 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 658 "data/maps/PetalburgCity/scripts.pory"
# 329 "data/maps/PetalburgCity/scripts.pory"
# 659 "data/maps/PetalburgCity/scripts.pory"
	return
# 660 "data/maps/PetalburgCity/scripts.pory"
# 330 "data/maps/PetalburgCity/scripts.pory"
# 661 "data/maps/PetalburgCity/scripts.pory"

# 662 "data/maps/PetalburgCity/scripts.pory"
# 331 "data/maps/PetalburgCity/scripts.pory"
# 663 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym2::
# 664 "data/maps/PetalburgCity/scripts.pory"
# 332 "data/maps/PetalburgCity/scripts.pory"
# 665 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym2
# 666 "data/maps/PetalburgCity/scripts.pory"
# 333 "data/maps/PetalburgCity/scripts.pory"
# 667 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym2
# 668 "data/maps/PetalburgCity/scripts.pory"
# 334 "data/maps/PetalburgCity/scripts.pory"
# 669 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 670 "data/maps/PetalburgCity/scripts.pory"
# 335 "data/maps/PetalburgCity/scripts.pory"
# 671 "data/maps/PetalburgCity/scripts.pory"
	return
# 672 "data/maps/PetalburgCity/scripts.pory"
# 336 "data/maps/PetalburgCity/scripts.pory"
# 673 "data/maps/PetalburgCity/scripts.pory"

# 674 "data/maps/PetalburgCity/scripts.pory"
# 337 "data/maps/PetalburgCity/scripts.pory"
# 675 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym3::
# 676 "data/maps/PetalburgCity/scripts.pory"
# 338 "data/maps/PetalburgCity/scripts.pory"
# 677 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym3
# 678 "data/maps/PetalburgCity/scripts.pory"
# 339 "data/maps/PetalburgCity/scripts.pory"
# 679 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym3
# 680 "data/maps/PetalburgCity/scripts.pory"
# 340 "data/maps/PetalburgCity/scripts.pory"
# 681 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 682 "data/maps/PetalburgCity/scripts.pory"
# 341 "data/maps/PetalburgCity/scripts.pory"
# 683 "data/maps/PetalburgCity/scripts.pory"
	return
# 684 "data/maps/PetalburgCity/scripts.pory"
# 342 "data/maps/PetalburgCity/scripts.pory"
# 685 "data/maps/PetalburgCity/scripts.pory"

# 686 "data/maps/PetalburgCity/scripts.pory"
# 343 "data/maps/PetalburgCity/scripts.pory"
# 687 "data/maps/PetalburgCity/scripts.pory"
@ Unused
# 688 "data/maps/PetalburgCity/scripts.pory"
# 344 "data/maps/PetalburgCity/scripts.pory"
# 689 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_Delay48::
# 690 "data/maps/PetalburgCity/scripts.pory"
# 345 "data/maps/PetalburgCity/scripts.pory"
# 691 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 692 "data/maps/PetalburgCity/scripts.pory"
# 346 "data/maps/PetalburgCity/scripts.pory"
# 693 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 694 "data/maps/PetalburgCity/scripts.pory"
# 347 "data/maps/PetalburgCity/scripts.pory"
# 695 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 696 "data/maps/PetalburgCity/scripts.pory"
# 348 "data/maps/PetalburgCity/scripts.pory"
# 697 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 698 "data/maps/PetalburgCity/scripts.pory"
# 349 "data/maps/PetalburgCity/scripts.pory"
# 699 "data/maps/PetalburgCity/scripts.pory"

# 700 "data/maps/PetalburgCity/scripts.pory"
# 350 "data/maps/PetalburgCity/scripts.pory"
# 701 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer0:
# 702 "data/maps/PetalburgCity/scripts.pory"
# 351 "data/maps/PetalburgCity/scripts.pory"
# 703 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 704 "data/maps/PetalburgCity/scripts.pory"
# 352 "data/maps/PetalburgCity/scripts.pory"
# 705 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 706 "data/maps/PetalburgCity/scripts.pory"
# 353 "data/maps/PetalburgCity/scripts.pory"
# 707 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 708 "data/maps/PetalburgCity/scripts.pory"
# 354 "data/maps/PetalburgCity/scripts.pory"
# 709 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 710 "data/maps/PetalburgCity/scripts.pory"
# 355 "data/maps/PetalburgCity/scripts.pory"
# 711 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 712 "data/maps/PetalburgCity/scripts.pory"
# 356 "data/maps/PetalburgCity/scripts.pory"
# 713 "data/maps/PetalburgCity/scripts.pory"

# 714 "data/maps/PetalburgCity/scripts.pory"
# 357 "data/maps/PetalburgCity/scripts.pory"
# 715 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer1:
# 716 "data/maps/PetalburgCity/scripts.pory"
# 358 "data/maps/PetalburgCity/scripts.pory"
# 717 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 718 "data/maps/PetalburgCity/scripts.pory"
# 359 "data/maps/PetalburgCity/scripts.pory"
# 719 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 720 "data/maps/PetalburgCity/scripts.pory"
# 360 "data/maps/PetalburgCity/scripts.pory"
# 721 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 722 "data/maps/PetalburgCity/scripts.pory"
# 361 "data/maps/PetalburgCity/scripts.pory"
# 723 "data/maps/PetalburgCity/scripts.pory"

# 724 "data/maps/PetalburgCity/scripts.pory"
# 362 "data/maps/PetalburgCity/scripts.pory"
# 725 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer2:
# 726 "data/maps/PetalburgCity/scripts.pory"
# 363 "data/maps/PetalburgCity/scripts.pory"
# 727 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 728 "data/maps/PetalburgCity/scripts.pory"
# 364 "data/maps/PetalburgCity/scripts.pory"
# 729 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 730 "data/maps/PetalburgCity/scripts.pory"
# 365 "data/maps/PetalburgCity/scripts.pory"
# 731 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 732 "data/maps/PetalburgCity/scripts.pory"
# 366 "data/maps/PetalburgCity/scripts.pory"
# 733 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 734 "data/maps/PetalburgCity/scripts.pory"
# 367 "data/maps/PetalburgCity/scripts.pory"
# 735 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 736 "data/maps/PetalburgCity/scripts.pory"
# 368 "data/maps/PetalburgCity/scripts.pory"
# 737 "data/maps/PetalburgCity/scripts.pory"

# 738 "data/maps/PetalburgCity/scripts.pory"
# 369 "data/maps/PetalburgCity/scripts.pory"
# 739 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer3:
# 740 "data/maps/PetalburgCity/scripts.pory"
# 370 "data/maps/PetalburgCity/scripts.pory"
# 741 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 742 "data/maps/PetalburgCity/scripts.pory"
# 371 "data/maps/PetalburgCity/scripts.pory"
# 743 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 744 "data/maps/PetalburgCity/scripts.pory"
# 372 "data/maps/PetalburgCity/scripts.pory"
# 745 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 746 "data/maps/PetalburgCity/scripts.pory"
# 373 "data/maps/PetalburgCity/scripts.pory"
# 747 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 748 "data/maps/PetalburgCity/scripts.pory"
# 374 "data/maps/PetalburgCity/scripts.pory"
# 749 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 750 "data/maps/PetalburgCity/scripts.pory"
# 375 "data/maps/PetalburgCity/scripts.pory"
# 751 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 752 "data/maps/PetalburgCity/scripts.pory"
# 376 "data/maps/PetalburgCity/scripts.pory"
# 753 "data/maps/PetalburgCity/scripts.pory"

# 754 "data/maps/PetalburgCity/scripts.pory"
# 377 "data/maps/PetalburgCity/scripts.pory"
# 755 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym0:
# 756 "data/maps/PetalburgCity/scripts.pory"
# 378 "data/maps/PetalburgCity/scripts.pory"
# 757 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 758 "data/maps/PetalburgCity/scripts.pory"
# 379 "data/maps/PetalburgCity/scripts.pory"
# 759 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 760 "data/maps/PetalburgCity/scripts.pory"
# 380 "data/maps/PetalburgCity/scripts.pory"
# 761 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 762 "data/maps/PetalburgCity/scripts.pory"
# 381 "data/maps/PetalburgCity/scripts.pory"
# 763 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 764 "data/maps/PetalburgCity/scripts.pory"
# 382 "data/maps/PetalburgCity/scripts.pory"
# 765 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 766 "data/maps/PetalburgCity/scripts.pory"
# 383 "data/maps/PetalburgCity/scripts.pory"
# 767 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 768 "data/maps/PetalburgCity/scripts.pory"
# 384 "data/maps/PetalburgCity/scripts.pory"
# 769 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 770 "data/maps/PetalburgCity/scripts.pory"
# 385 "data/maps/PetalburgCity/scripts.pory"
# 771 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 772 "data/maps/PetalburgCity/scripts.pory"
# 386 "data/maps/PetalburgCity/scripts.pory"
# 773 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 774 "data/maps/PetalburgCity/scripts.pory"
# 387 "data/maps/PetalburgCity/scripts.pory"
# 775 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 776 "data/maps/PetalburgCity/scripts.pory"
# 388 "data/maps/PetalburgCity/scripts.pory"
# 777 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 778 "data/maps/PetalburgCity/scripts.pory"
# 389 "data/maps/PetalburgCity/scripts.pory"
# 779 "data/maps/PetalburgCity/scripts.pory"

# 780 "data/maps/PetalburgCity/scripts.pory"
# 390 "data/maps/PetalburgCity/scripts.pory"
# 781 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym1:
# 782 "data/maps/PetalburgCity/scripts.pory"
# 391 "data/maps/PetalburgCity/scripts.pory"
# 783 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 784 "data/maps/PetalburgCity/scripts.pory"
# 392 "data/maps/PetalburgCity/scripts.pory"
# 785 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 786 "data/maps/PetalburgCity/scripts.pory"
# 393 "data/maps/PetalburgCity/scripts.pory"
# 787 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 788 "data/maps/PetalburgCity/scripts.pory"
# 394 "data/maps/PetalburgCity/scripts.pory"
# 789 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 790 "data/maps/PetalburgCity/scripts.pory"
# 395 "data/maps/PetalburgCity/scripts.pory"
# 791 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 792 "data/maps/PetalburgCity/scripts.pory"
# 396 "data/maps/PetalburgCity/scripts.pory"
# 793 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 794 "data/maps/PetalburgCity/scripts.pory"
# 397 "data/maps/PetalburgCity/scripts.pory"
# 795 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 796 "data/maps/PetalburgCity/scripts.pory"
# 398 "data/maps/PetalburgCity/scripts.pory"
# 797 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 798 "data/maps/PetalburgCity/scripts.pory"
# 399 "data/maps/PetalburgCity/scripts.pory"
# 799 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 800 "data/maps/PetalburgCity/scripts.pory"
# 400 "data/maps/PetalburgCity/scripts.pory"
# 801 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 802 "data/maps/PetalburgCity/scripts.pory"
# 401 "data/maps/PetalburgCity/scripts.pory"
# 803 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 804 "data/maps/PetalburgCity/scripts.pory"
# 402 "data/maps/PetalburgCity/scripts.pory"
# 805 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 806 "data/maps/PetalburgCity/scripts.pory"
# 403 "data/maps/PetalburgCity/scripts.pory"
# 807 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 808 "data/maps/PetalburgCity/scripts.pory"
# 404 "data/maps/PetalburgCity/scripts.pory"
# 809 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 810 "data/maps/PetalburgCity/scripts.pory"
# 405 "data/maps/PetalburgCity/scripts.pory"
# 811 "data/maps/PetalburgCity/scripts.pory"

# 812 "data/maps/PetalburgCity/scripts.pory"
# 406 "data/maps/PetalburgCity/scripts.pory"
# 813 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym2:
# 814 "data/maps/PetalburgCity/scripts.pory"
# 407 "data/maps/PetalburgCity/scripts.pory"
# 815 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 816 "data/maps/PetalburgCity/scripts.pory"
# 408 "data/maps/PetalburgCity/scripts.pory"
# 817 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 818 "data/maps/PetalburgCity/scripts.pory"
# 409 "data/maps/PetalburgCity/scripts.pory"
# 819 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 820 "data/maps/PetalburgCity/scripts.pory"
# 410 "data/maps/PetalburgCity/scripts.pory"
# 821 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 822 "data/maps/PetalburgCity/scripts.pory"
# 411 "data/maps/PetalburgCity/scripts.pory"
# 823 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 824 "data/maps/PetalburgCity/scripts.pory"
# 412 "data/maps/PetalburgCity/scripts.pory"
# 825 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 826 "data/maps/PetalburgCity/scripts.pory"
# 413 "data/maps/PetalburgCity/scripts.pory"
# 827 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 828 "data/maps/PetalburgCity/scripts.pory"
# 414 "data/maps/PetalburgCity/scripts.pory"
# 829 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 830 "data/maps/PetalburgCity/scripts.pory"
# 415 "data/maps/PetalburgCity/scripts.pory"
# 831 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 832 "data/maps/PetalburgCity/scripts.pory"
# 416 "data/maps/PetalburgCity/scripts.pory"
# 833 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 834 "data/maps/PetalburgCity/scripts.pory"
# 417 "data/maps/PetalburgCity/scripts.pory"
# 835 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 836 "data/maps/PetalburgCity/scripts.pory"
# 418 "data/maps/PetalburgCity/scripts.pory"
# 837 "data/maps/PetalburgCity/scripts.pory"

# 838 "data/maps/PetalburgCity/scripts.pory"
# 419 "data/maps/PetalburgCity/scripts.pory"
# 839 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym3:
# 840 "data/maps/PetalburgCity/scripts.pory"
# 420 "data/maps/PetalburgCity/scripts.pory"
# 841 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 842 "data/maps/PetalburgCity/scripts.pory"
# 421 "data/maps/PetalburgCity/scripts.pory"
# 843 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 844 "data/maps/PetalburgCity/scripts.pory"
# 422 "data/maps/PetalburgCity/scripts.pory"
# 845 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 846 "data/maps/PetalburgCity/scripts.pory"
# 423 "data/maps/PetalburgCity/scripts.pory"
# 847 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 848 "data/maps/PetalburgCity/scripts.pory"
# 424 "data/maps/PetalburgCity/scripts.pory"
# 849 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 850 "data/maps/PetalburgCity/scripts.pory"
# 425 "data/maps/PetalburgCity/scripts.pory"
# 851 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 852 "data/maps/PetalburgCity/scripts.pory"
# 426 "data/maps/PetalburgCity/scripts.pory"
# 853 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 854 "data/maps/PetalburgCity/scripts.pory"
# 427 "data/maps/PetalburgCity/scripts.pory"
# 855 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 856 "data/maps/PetalburgCity/scripts.pory"
# 428 "data/maps/PetalburgCity/scripts.pory"
# 857 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 858 "data/maps/PetalburgCity/scripts.pory"
# 429 "data/maps/PetalburgCity/scripts.pory"
# 859 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 860 "data/maps/PetalburgCity/scripts.pory"
# 430 "data/maps/PetalburgCity/scripts.pory"
# 861 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 862 "data/maps/PetalburgCity/scripts.pory"
# 431 "data/maps/PetalburgCity/scripts.pory"
# 863 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 864 "data/maps/PetalburgCity/scripts.pory"
# 432 "data/maps/PetalburgCity/scripts.pory"
# 865 "data/maps/PetalburgCity/scripts.pory"

# 866 "data/maps/PetalburgCity/scripts.pory"
# 433 "data/maps/PetalburgCity/scripts.pory"
# 867 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkAway:
# 868 "data/maps/PetalburgCity/scripts.pory"
# 434 "data/maps/PetalburgCity/scripts.pory"
# 869 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 870 "data/maps/PetalburgCity/scripts.pory"
# 435 "data/maps/PetalburgCity/scripts.pory"
# 871 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 872 "data/maps/PetalburgCity/scripts.pory"
# 436 "data/maps/PetalburgCity/scripts.pory"
# 873 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 874 "data/maps/PetalburgCity/scripts.pory"
# 437 "data/maps/PetalburgCity/scripts.pory"
# 875 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 876 "data/maps/PetalburgCity/scripts.pory"
# 438 "data/maps/PetalburgCity/scripts.pory"
# 877 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 878 "data/maps/PetalburgCity/scripts.pory"
# 439 "data/maps/PetalburgCity/scripts.pory"
# 879 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 880 "data/maps/PetalburgCity/scripts.pory"
# 440 "data/maps/PetalburgCity/scripts.pory"
# 881 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 882 "data/maps/PetalburgCity/scripts.pory"
# 441 "data/maps/PetalburgCity/scripts.pory"
# 883 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 884 "data/maps/PetalburgCity/scripts.pory"
# 442 "data/maps/PetalburgCity/scripts.pory"
# 885 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 886 "data/maps/PetalburgCity/scripts.pory"
# 443 "data/maps/PetalburgCity/scripts.pory"
# 887 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 888 "data/maps/PetalburgCity/scripts.pory"
# 444 "data/maps/PetalburgCity/scripts.pory"
# 889 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 890 "data/maps/PetalburgCity/scripts.pory"
# 445 "data/maps/PetalburgCity/scripts.pory"
# 891 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 892 "data/maps/PetalburgCity/scripts.pory"
# 446 "data/maps/PetalburgCity/scripts.pory"
# 893 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 894 "data/maps/PetalburgCity/scripts.pory"
# 447 "data/maps/PetalburgCity/scripts.pory"
# 895 "data/maps/PetalburgCity/scripts.pory"

# 896 "data/maps/PetalburgCity/scripts.pory"
# 448 "data/maps/PetalburgCity/scripts.pory"
# 897 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym0:
# 898 "data/maps/PetalburgCity/scripts.pory"
# 449 "data/maps/PetalburgCity/scripts.pory"
# 899 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 900 "data/maps/PetalburgCity/scripts.pory"
# 450 "data/maps/PetalburgCity/scripts.pory"
# 901 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 902 "data/maps/PetalburgCity/scripts.pory"
# 451 "data/maps/PetalburgCity/scripts.pory"
# 903 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 904 "data/maps/PetalburgCity/scripts.pory"
# 452 "data/maps/PetalburgCity/scripts.pory"
# 905 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 906 "data/maps/PetalburgCity/scripts.pory"
# 453 "data/maps/PetalburgCity/scripts.pory"
# 907 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 908 "data/maps/PetalburgCity/scripts.pory"
# 454 "data/maps/PetalburgCity/scripts.pory"
# 909 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 910 "data/maps/PetalburgCity/scripts.pory"
# 455 "data/maps/PetalburgCity/scripts.pory"
# 911 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 912 "data/maps/PetalburgCity/scripts.pory"
# 456 "data/maps/PetalburgCity/scripts.pory"
# 913 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 914 "data/maps/PetalburgCity/scripts.pory"
# 457 "data/maps/PetalburgCity/scripts.pory"
# 915 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 916 "data/maps/PetalburgCity/scripts.pory"
# 458 "data/maps/PetalburgCity/scripts.pory"
# 917 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 918 "data/maps/PetalburgCity/scripts.pory"
# 459 "data/maps/PetalburgCity/scripts.pory"
# 919 "data/maps/PetalburgCity/scripts.pory"

# 920 "data/maps/PetalburgCity/scripts.pory"
# 460 "data/maps/PetalburgCity/scripts.pory"
# 921 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym1:
# 922 "data/maps/PetalburgCity/scripts.pory"
# 461 "data/maps/PetalburgCity/scripts.pory"
# 923 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 924 "data/maps/PetalburgCity/scripts.pory"
# 462 "data/maps/PetalburgCity/scripts.pory"
# 925 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 926 "data/maps/PetalburgCity/scripts.pory"
# 463 "data/maps/PetalburgCity/scripts.pory"
# 927 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 928 "data/maps/PetalburgCity/scripts.pory"
# 464 "data/maps/PetalburgCity/scripts.pory"
# 929 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 930 "data/maps/PetalburgCity/scripts.pory"
# 465 "data/maps/PetalburgCity/scripts.pory"
# 931 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 932 "data/maps/PetalburgCity/scripts.pory"
# 466 "data/maps/PetalburgCity/scripts.pory"
# 933 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 934 "data/maps/PetalburgCity/scripts.pory"
# 467 "data/maps/PetalburgCity/scripts.pory"
# 935 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 936 "data/maps/PetalburgCity/scripts.pory"
# 468 "data/maps/PetalburgCity/scripts.pory"
# 937 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 938 "data/maps/PetalburgCity/scripts.pory"
# 469 "data/maps/PetalburgCity/scripts.pory"
# 939 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 940 "data/maps/PetalburgCity/scripts.pory"
# 470 "data/maps/PetalburgCity/scripts.pory"
# 941 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 942 "data/maps/PetalburgCity/scripts.pory"
# 471 "data/maps/PetalburgCity/scripts.pory"
# 943 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 944 "data/maps/PetalburgCity/scripts.pory"
# 472 "data/maps/PetalburgCity/scripts.pory"
# 945 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 946 "data/maps/PetalburgCity/scripts.pory"
# 473 "data/maps/PetalburgCity/scripts.pory"
# 947 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 948 "data/maps/PetalburgCity/scripts.pory"
# 474 "data/maps/PetalburgCity/scripts.pory"
# 949 "data/maps/PetalburgCity/scripts.pory"

# 950 "data/maps/PetalburgCity/scripts.pory"
# 475 "data/maps/PetalburgCity/scripts.pory"
# 951 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym2:
# 952 "data/maps/PetalburgCity/scripts.pory"
# 476 "data/maps/PetalburgCity/scripts.pory"
# 953 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 954 "data/maps/PetalburgCity/scripts.pory"
# 477 "data/maps/PetalburgCity/scripts.pory"
# 955 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 956 "data/maps/PetalburgCity/scripts.pory"
# 478 "data/maps/PetalburgCity/scripts.pory"
# 957 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 958 "data/maps/PetalburgCity/scripts.pory"
# 479 "data/maps/PetalburgCity/scripts.pory"
# 959 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 960 "data/maps/PetalburgCity/scripts.pory"
# 480 "data/maps/PetalburgCity/scripts.pory"
# 961 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 962 "data/maps/PetalburgCity/scripts.pory"
# 481 "data/maps/PetalburgCity/scripts.pory"
# 963 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 964 "data/maps/PetalburgCity/scripts.pory"
# 482 "data/maps/PetalburgCity/scripts.pory"
# 965 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 966 "data/maps/PetalburgCity/scripts.pory"
# 483 "data/maps/PetalburgCity/scripts.pory"
# 967 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 968 "data/maps/PetalburgCity/scripts.pory"
# 484 "data/maps/PetalburgCity/scripts.pory"
# 969 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 970 "data/maps/PetalburgCity/scripts.pory"
# 485 "data/maps/PetalburgCity/scripts.pory"
# 971 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 972 "data/maps/PetalburgCity/scripts.pory"
# 486 "data/maps/PetalburgCity/scripts.pory"
# 973 "data/maps/PetalburgCity/scripts.pory"

# 974 "data/maps/PetalburgCity/scripts.pory"
# 487 "data/maps/PetalburgCity/scripts.pory"
# 975 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym3:
# 976 "data/maps/PetalburgCity/scripts.pory"
# 488 "data/maps/PetalburgCity/scripts.pory"
# 977 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 978 "data/maps/PetalburgCity/scripts.pory"
# 489 "data/maps/PetalburgCity/scripts.pory"
# 979 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 980 "data/maps/PetalburgCity/scripts.pory"
# 490 "data/maps/PetalburgCity/scripts.pory"
# 981 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 982 "data/maps/PetalburgCity/scripts.pory"
# 491 "data/maps/PetalburgCity/scripts.pory"
# 983 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 984 "data/maps/PetalburgCity/scripts.pory"
# 492 "data/maps/PetalburgCity/scripts.pory"
# 985 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 986 "data/maps/PetalburgCity/scripts.pory"
# 493 "data/maps/PetalburgCity/scripts.pory"
# 987 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 988 "data/maps/PetalburgCity/scripts.pory"
# 494 "data/maps/PetalburgCity/scripts.pory"
# 989 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 990 "data/maps/PetalburgCity/scripts.pory"
# 495 "data/maps/PetalburgCity/scripts.pory"
# 991 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 992 "data/maps/PetalburgCity/scripts.pory"
# 496 "data/maps/PetalburgCity/scripts.pory"
# 993 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 994 "data/maps/PetalburgCity/scripts.pory"
# 497 "data/maps/PetalburgCity/scripts.pory"
# 995 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 996 "data/maps/PetalburgCity/scripts.pory"
# 498 "data/maps/PetalburgCity/scripts.pory"
# 997 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 998 "data/maps/PetalburgCity/scripts.pory"
# 499 "data/maps/PetalburgCity/scripts.pory"
# 999 "data/maps/PetalburgCity/scripts.pory"

# 1000 "data/maps/PetalburgCity/scripts.pory"
# 500 "data/maps/PetalburgCity/scripts.pory"
# 1001 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Scott0::
# 1002 "data/maps/PetalburgCity/scripts.pory"
# 501 "data/maps/PetalburgCity/scripts.pory"
# 1003 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 1004 "data/maps/PetalburgCity/scripts.pory"
# 502 "data/maps/PetalburgCity/scripts.pory"
# 1005 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 1006 "data/maps/PetalburgCity/scripts.pory"
# 503 "data/maps/PetalburgCity/scripts.pory"
# 1007 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 0
# 1008 "data/maps/PetalburgCity/scripts.pory"
# 504 "data/maps/PetalburgCity/scripts.pory"
# 1009 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 10
# 1010 "data/maps/PetalburgCity/scripts.pory"
# 505 "data/maps/PetalburgCity/scripts.pory"
# 1011 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
# 1012 "data/maps/PetalburgCity/scripts.pory"
# 506 "data/maps/PetalburgCity/scripts.pory"
# 1013 "data/maps/PetalburgCity/scripts.pory"
	end
# 1014 "data/maps/PetalburgCity/scripts.pory"
# 507 "data/maps/PetalburgCity/scripts.pory"
# 1015 "data/maps/PetalburgCity/scripts.pory"

# 1016 "data/maps/PetalburgCity/scripts.pory"
# 508 "data/maps/PetalburgCity/scripts.pory"
# 1017 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Scott1::
# 1018 "data/maps/PetalburgCity/scripts.pory"
# 509 "data/maps/PetalburgCity/scripts.pory"
# 1019 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 1020 "data/maps/PetalburgCity/scripts.pory"
# 510 "data/maps/PetalburgCity/scripts.pory"
# 1021 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 1022 "data/maps/PetalburgCity/scripts.pory"
# 511 "data/maps/PetalburgCity/scripts.pory"
# 1023 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 1
# 1024 "data/maps/PetalburgCity/scripts.pory"
# 512 "data/maps/PetalburgCity/scripts.pory"
# 1025 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 11
# 1026 "data/maps/PetalburgCity/scripts.pory"
# 513 "data/maps/PetalburgCity/scripts.pory"
# 1027 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
# 1028 "data/maps/PetalburgCity/scripts.pory"
# 514 "data/maps/PetalburgCity/scripts.pory"
# 1029 "data/maps/PetalburgCity/scripts.pory"
	end
# 1030 "data/maps/PetalburgCity/scripts.pory"
# 515 "data/maps/PetalburgCity/scripts.pory"
# 1031 "data/maps/PetalburgCity/scripts.pory"

# 1032 "data/maps/PetalburgCity/scripts.pory"
# 516 "data/maps/PetalburgCity/scripts.pory"
# 1033 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Scott2::
# 1034 "data/maps/PetalburgCity/scripts.pory"
# 517 "data/maps/PetalburgCity/scripts.pory"
# 1035 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 1036 "data/maps/PetalburgCity/scripts.pory"
# 518 "data/maps/PetalburgCity/scripts.pory"
# 1037 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 1038 "data/maps/PetalburgCity/scripts.pory"
# 519 "data/maps/PetalburgCity/scripts.pory"
# 1039 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 2
# 1040 "data/maps/PetalburgCity/scripts.pory"
# 520 "data/maps/PetalburgCity/scripts.pory"
# 1041 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 12
# 1042 "data/maps/PetalburgCity/scripts.pory"
# 521 "data/maps/PetalburgCity/scripts.pory"
# 1043 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
# 1044 "data/maps/PetalburgCity/scripts.pory"
# 522 "data/maps/PetalburgCity/scripts.pory"
# 1045 "data/maps/PetalburgCity/scripts.pory"
	end
# 1046 "data/maps/PetalburgCity/scripts.pory"
# 523 "data/maps/PetalburgCity/scripts.pory"
# 1047 "data/maps/PetalburgCity/scripts.pory"

# 1048 "data/maps/PetalburgCity/scripts.pory"
# 524 "data/maps/PetalburgCity/scripts.pory"
# 1049 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Scott3::
# 1050 "data/maps/PetalburgCity/scripts.pory"
# 525 "data/maps/PetalburgCity/scripts.pory"
# 1051 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 1052 "data/maps/PetalburgCity/scripts.pory"
# 526 "data/maps/PetalburgCity/scripts.pory"
# 1053 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 1054 "data/maps/PetalburgCity/scripts.pory"
# 527 "data/maps/PetalburgCity/scripts.pory"
# 1055 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 3
# 1056 "data/maps/PetalburgCity/scripts.pory"
# 528 "data/maps/PetalburgCity/scripts.pory"
# 1057 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 13
# 1058 "data/maps/PetalburgCity/scripts.pory"
# 529 "data/maps/PetalburgCity/scripts.pory"
# 1059 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
# 1060 "data/maps/PetalburgCity/scripts.pory"
# 530 "data/maps/PetalburgCity/scripts.pory"
# 1061 "data/maps/PetalburgCity/scripts.pory"
	end
# 1062 "data/maps/PetalburgCity/scripts.pory"
# 531 "data/maps/PetalburgCity/scripts.pory"
# 1063 "data/maps/PetalburgCity/scripts.pory"

# 1064 "data/maps/PetalburgCity/scripts.pory"
# 532 "data/maps/PetalburgCity/scripts.pory"
# 1065 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Scott::
# 1066 "data/maps/PetalburgCity/scripts.pory"
# 533 "data/maps/PetalburgCity/scripts.pory"
# 1067 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottStartWalkLeft
# 1068 "data/maps/PetalburgCity/scripts.pory"
# 534 "data/maps/PetalburgCity/scripts.pory"
# 1069 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 1070 "data/maps/PetalburgCity/scripts.pory"
# 535 "data/maps/PetalburgCity/scripts.pory"
# 1071 "data/maps/PetalburgCity/scripts.pory"
	playse SE_PIN
# 1072 "data/maps/PetalburgCity/scripts.pory"
# 536 "data/maps/PetalburgCity/scripts.pory"
# 1073 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_ExclamationMark
# 1074 "data/maps/PetalburgCity/scripts.pory"
# 537 "data/maps/PetalburgCity/scripts.pory"
# 1075 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 1076 "data/maps/PetalburgCity/scripts.pory"
# 538 "data/maps/PetalburgCity/scripts.pory"
# 1077 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_Delay48
# 1078 "data/maps/PetalburgCity/scripts.pory"
# 539 "data/maps/PetalburgCity/scripts.pory"
# 1079 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 1080 "data/maps/PetalburgCity/scripts.pory"
# 540 "data/maps/PetalburgCity/scripts.pory"
# 1081 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottApproachPlayer
# 1082 "data/maps/PetalburgCity/scripts.pory"
# 541 "data/maps/PetalburgCity/scripts.pory"
# 1083 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 1084 "data/maps/PetalburgCity/scripts.pory"
# 542 "data/maps/PetalburgCity/scripts.pory"
# 1085 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 1086 "data/maps/PetalburgCity/scripts.pory"
# 543 "data/maps/PetalburgCity/scripts.pory"
# 1087 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 1088 "data/maps/PetalburgCity/scripts.pory"
# 544 "data/maps/PetalburgCity/scripts.pory"
# 1089 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_SCOTT_STATE, 1
# 1090 "data/maps/PetalburgCity/scripts.pory"
# 545 "data/maps/PetalburgCity/scripts.pory"
# 1091 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_AreYouATrainer, MSGBOX_DEFAULT
# 1092 "data/maps/PetalburgCity/scripts.pory"
# 546 "data/maps/PetalburgCity/scripts.pory"
# 1093 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 1094 "data/maps/PetalburgCity/scripts.pory"
# 547 "data/maps/PetalburgCity/scripts.pory"
# 1095 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_WalkInPlaceFasterRight
# 1096 "data/maps/PetalburgCity/scripts.pory"
# 548 "data/maps/PetalburgCity/scripts.pory"
# 1097 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 1098 "data/maps/PetalburgCity/scripts.pory"
# 549 "data/maps/PetalburgCity/scripts.pory"
# 1099 "data/maps/PetalburgCity/scripts.pory"
	delay 30
# 1100 "data/maps/PetalburgCity/scripts.pory"
# 550 "data/maps/PetalburgCity/scripts.pory"
# 1101 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_WellMaybeNot, MSGBOX_DEFAULT
# 1102 "data/maps/PetalburgCity/scripts.pory"
# 551 "data/maps/PetalburgCity/scripts.pory"
# 1103 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 1104 "data/maps/PetalburgCity/scripts.pory"
# 552 "data/maps/PetalburgCity/scripts.pory"
# 1105 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_WalkInPlaceFasterLeft
# 1106 "data/maps/PetalburgCity/scripts.pory"
# 553 "data/maps/PetalburgCity/scripts.pory"
# 1107 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 1108 "data/maps/PetalburgCity/scripts.pory"
# 554 "data/maps/PetalburgCity/scripts.pory"
# 1109 "data/maps/PetalburgCity/scripts.pory"
	delay 30
# 1110 "data/maps/PetalburgCity/scripts.pory"
# 555 "data/maps/PetalburgCity/scripts.pory"
# 1111 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_ImLookingForTalentedTrainers, MSGBOX_DEFAULT
# 1112 "data/maps/PetalburgCity/scripts.pory"
# 556 "data/maps/PetalburgCity/scripts.pory"
# 1113 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 1114 "data/maps/PetalburgCity/scripts.pory"
# 557 "data/maps/PetalburgCity/scripts.pory"
# 1115 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_ScottExit0
# 1116 "data/maps/PetalburgCity/scripts.pory"
# 558 "data/maps/PetalburgCity/scripts.pory"
# 1117 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_ScottExit1
# 1118 "data/maps/PetalburgCity/scripts.pory"
# 559 "data/maps/PetalburgCity/scripts.pory"
# 1119 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_ScottExit2
# 1120 "data/maps/PetalburgCity/scripts.pory"
# 560 "data/maps/PetalburgCity/scripts.pory"
# 1121 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_ScottExit3
# 1122 "data/maps/PetalburgCity/scripts.pory"
# 561 "data/maps/PetalburgCity/scripts.pory"
# 1123 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_SCOTT_PETALBURG_ENCOUNTER, 1
# 1124 "data/maps/PetalburgCity/scripts.pory"
# 562 "data/maps/PetalburgCity/scripts.pory"
# 1125 "data/maps/PetalburgCity/scripts.pory"
	removeobject LOCALID_PETALBURG_SCOTT
# 1126 "data/maps/PetalburgCity/scripts.pory"
# 563 "data/maps/PetalburgCity/scripts.pory"
# 1127 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 1128 "data/maps/PetalburgCity/scripts.pory"
# 564 "data/maps/PetalburgCity/scripts.pory"
# 1129 "data/maps/PetalburgCity/scripts.pory"
	end
# 1130 "data/maps/PetalburgCity/scripts.pory"
# 565 "data/maps/PetalburgCity/scripts.pory"
# 1131 "data/maps/PetalburgCity/scripts.pory"

# 1132 "data/maps/PetalburgCity/scripts.pory"
# 566 "data/maps/PetalburgCity/scripts.pory"
# 1133 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ScottExit0::
# 1134 "data/maps/PetalburgCity/scripts.pory"
# 567 "data/maps/PetalburgCity/scripts.pory"
# 1135 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit0
# 1136 "data/maps/PetalburgCity/scripts.pory"
# 568 "data/maps/PetalburgCity/scripts.pory"
# 1137 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit0
# 1138 "data/maps/PetalburgCity/scripts.pory"
# 569 "data/maps/PetalburgCity/scripts.pory"
# 1139 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 1140 "data/maps/PetalburgCity/scripts.pory"
# 570 "data/maps/PetalburgCity/scripts.pory"
# 1141 "data/maps/PetalburgCity/scripts.pory"
	return
# 1142 "data/maps/PetalburgCity/scripts.pory"
# 571 "data/maps/PetalburgCity/scripts.pory"
# 1143 "data/maps/PetalburgCity/scripts.pory"

# 1144 "data/maps/PetalburgCity/scripts.pory"
# 572 "data/maps/PetalburgCity/scripts.pory"
# 1145 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ScottExit1::
# 1146 "data/maps/PetalburgCity/scripts.pory"
# 573 "data/maps/PetalburgCity/scripts.pory"
# 1147 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit1
# 1148 "data/maps/PetalburgCity/scripts.pory"
# 574 "data/maps/PetalburgCity/scripts.pory"
# 1149 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit1
# 1150 "data/maps/PetalburgCity/scripts.pory"
# 575 "data/maps/PetalburgCity/scripts.pory"
# 1151 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 1152 "data/maps/PetalburgCity/scripts.pory"
# 576 "data/maps/PetalburgCity/scripts.pory"
# 1153 "data/maps/PetalburgCity/scripts.pory"
	return
# 1154 "data/maps/PetalburgCity/scripts.pory"
# 577 "data/maps/PetalburgCity/scripts.pory"
# 1155 "data/maps/PetalburgCity/scripts.pory"

# 1156 "data/maps/PetalburgCity/scripts.pory"
# 578 "data/maps/PetalburgCity/scripts.pory"
# 1157 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ScottExit2::
# 1158 "data/maps/PetalburgCity/scripts.pory"
# 579 "data/maps/PetalburgCity/scripts.pory"
# 1159 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit2
# 1160 "data/maps/PetalburgCity/scripts.pory"
# 580 "data/maps/PetalburgCity/scripts.pory"
# 1161 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit2
# 1162 "data/maps/PetalburgCity/scripts.pory"
# 581 "data/maps/PetalburgCity/scripts.pory"
# 1163 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 1164 "data/maps/PetalburgCity/scripts.pory"
# 582 "data/maps/PetalburgCity/scripts.pory"
# 1165 "data/maps/PetalburgCity/scripts.pory"
	return
# 1166 "data/maps/PetalburgCity/scripts.pory"
# 583 "data/maps/PetalburgCity/scripts.pory"
# 1167 "data/maps/PetalburgCity/scripts.pory"

# 1168 "data/maps/PetalburgCity/scripts.pory"
# 584 "data/maps/PetalburgCity/scripts.pory"
# 1169 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ScottExit3::
# 1170 "data/maps/PetalburgCity/scripts.pory"
# 585 "data/maps/PetalburgCity/scripts.pory"
# 1171 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit3
# 1172 "data/maps/PetalburgCity/scripts.pory"
# 586 "data/maps/PetalburgCity/scripts.pory"
# 1173 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit3
# 1174 "data/maps/PetalburgCity/scripts.pory"
# 587 "data/maps/PetalburgCity/scripts.pory"
# 1175 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 1176 "data/maps/PetalburgCity/scripts.pory"
# 588 "data/maps/PetalburgCity/scripts.pory"
# 1177 "data/maps/PetalburgCity/scripts.pory"
	return
# 1178 "data/maps/PetalburgCity/scripts.pory"
# 589 "data/maps/PetalburgCity/scripts.pory"
# 1179 "data/maps/PetalburgCity/scripts.pory"

# 1180 "data/maps/PetalburgCity/scripts.pory"
# 590 "data/maps/PetalburgCity/scripts.pory"
# 1181 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottStartWalkLeft:
# 1182 "data/maps/PetalburgCity/scripts.pory"
# 591 "data/maps/PetalburgCity/scripts.pory"
# 1183 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1184 "data/maps/PetalburgCity/scripts.pory"
# 592 "data/maps/PetalburgCity/scripts.pory"
# 1185 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1186 "data/maps/PetalburgCity/scripts.pory"
# 593 "data/maps/PetalburgCity/scripts.pory"
# 1187 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1188 "data/maps/PetalburgCity/scripts.pory"
# 594 "data/maps/PetalburgCity/scripts.pory"
# 1189 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1190 "data/maps/PetalburgCity/scripts.pory"
# 595 "data/maps/PetalburgCity/scripts.pory"
# 1191 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 1192 "data/maps/PetalburgCity/scripts.pory"
# 596 "data/maps/PetalburgCity/scripts.pory"
# 1193 "data/maps/PetalburgCity/scripts.pory"

# 1194 "data/maps/PetalburgCity/scripts.pory"
# 597 "data/maps/PetalburgCity/scripts.pory"
# 1195 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottApproachPlayer:
# 1196 "data/maps/PetalburgCity/scripts.pory"
# 598 "data/maps/PetalburgCity/scripts.pory"
# 1197 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1198 "data/maps/PetalburgCity/scripts.pory"
# 599 "data/maps/PetalburgCity/scripts.pory"
# 1199 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1200 "data/maps/PetalburgCity/scripts.pory"
# 600 "data/maps/PetalburgCity/scripts.pory"
# 1201 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1202 "data/maps/PetalburgCity/scripts.pory"
# 601 "data/maps/PetalburgCity/scripts.pory"
# 1203 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1204 "data/maps/PetalburgCity/scripts.pory"
# 602 "data/maps/PetalburgCity/scripts.pory"
# 1205 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 1206 "data/maps/PetalburgCity/scripts.pory"
# 603 "data/maps/PetalburgCity/scripts.pory"
# 1207 "data/maps/PetalburgCity/scripts.pory"

# 1208 "data/maps/PetalburgCity/scripts.pory"
# 604 "data/maps/PetalburgCity/scripts.pory"
# 1209 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit0:
# 1210 "data/maps/PetalburgCity/scripts.pory"
# 605 "data/maps/PetalburgCity/scripts.pory"
# 1211 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 1212 "data/maps/PetalburgCity/scripts.pory"
# 606 "data/maps/PetalburgCity/scripts.pory"
# 1213 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 1214 "data/maps/PetalburgCity/scripts.pory"
# 607 "data/maps/PetalburgCity/scripts.pory"
# 1215 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1216 "data/maps/PetalburgCity/scripts.pory"
# 608 "data/maps/PetalburgCity/scripts.pory"
# 1217 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1218 "data/maps/PetalburgCity/scripts.pory"
# 609 "data/maps/PetalburgCity/scripts.pory"
# 1219 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1220 "data/maps/PetalburgCity/scripts.pory"
# 610 "data/maps/PetalburgCity/scripts.pory"
# 1221 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1222 "data/maps/PetalburgCity/scripts.pory"
# 611 "data/maps/PetalburgCity/scripts.pory"
# 1223 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1224 "data/maps/PetalburgCity/scripts.pory"
# 612 "data/maps/PetalburgCity/scripts.pory"
# 1225 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1226 "data/maps/PetalburgCity/scripts.pory"
# 613 "data/maps/PetalburgCity/scripts.pory"
# 1227 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1228 "data/maps/PetalburgCity/scripts.pory"
# 614 "data/maps/PetalburgCity/scripts.pory"
# 1229 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1230 "data/maps/PetalburgCity/scripts.pory"
# 615 "data/maps/PetalburgCity/scripts.pory"
# 1231 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1232 "data/maps/PetalburgCity/scripts.pory"
# 616 "data/maps/PetalburgCity/scripts.pory"
# 1233 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1234 "data/maps/PetalburgCity/scripts.pory"
# 617 "data/maps/PetalburgCity/scripts.pory"
# 1235 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1236 "data/maps/PetalburgCity/scripts.pory"
# 618 "data/maps/PetalburgCity/scripts.pory"
# 1237 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 1238 "data/maps/PetalburgCity/scripts.pory"
# 619 "data/maps/PetalburgCity/scripts.pory"
# 1239 "data/maps/PetalburgCity/scripts.pory"

# 1240 "data/maps/PetalburgCity/scripts.pory"
# 620 "data/maps/PetalburgCity/scripts.pory"
# 1241 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit0:
# 1242 "data/maps/PetalburgCity/scripts.pory"
# 621 "data/maps/PetalburgCity/scripts.pory"
# 1243 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 1244 "data/maps/PetalburgCity/scripts.pory"
# 622 "data/maps/PetalburgCity/scripts.pory"
# 1245 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 1246 "data/maps/PetalburgCity/scripts.pory"
# 623 "data/maps/PetalburgCity/scripts.pory"
# 1247 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 1248 "data/maps/PetalburgCity/scripts.pory"
# 624 "data/maps/PetalburgCity/scripts.pory"
# 1249 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 1250 "data/maps/PetalburgCity/scripts.pory"
# 625 "data/maps/PetalburgCity/scripts.pory"
# 1251 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 1252 "data/maps/PetalburgCity/scripts.pory"
# 626 "data/maps/PetalburgCity/scripts.pory"
# 1253 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 1254 "data/maps/PetalburgCity/scripts.pory"
# 627 "data/maps/PetalburgCity/scripts.pory"
# 1255 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 1256 "data/maps/PetalburgCity/scripts.pory"
# 628 "data/maps/PetalburgCity/scripts.pory"
# 1257 "data/maps/PetalburgCity/scripts.pory"

# 1258 "data/maps/PetalburgCity/scripts.pory"
# 629 "data/maps/PetalburgCity/scripts.pory"
# 1259 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit1:
# 1260 "data/maps/PetalburgCity/scripts.pory"
# 630 "data/maps/PetalburgCity/scripts.pory"
# 1261 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 1262 "data/maps/PetalburgCity/scripts.pory"
# 631 "data/maps/PetalburgCity/scripts.pory"
# 1263 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1264 "data/maps/PetalburgCity/scripts.pory"
# 632 "data/maps/PetalburgCity/scripts.pory"
# 1265 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1266 "data/maps/PetalburgCity/scripts.pory"
# 633 "data/maps/PetalburgCity/scripts.pory"
# 1267 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1268 "data/maps/PetalburgCity/scripts.pory"
# 634 "data/maps/PetalburgCity/scripts.pory"
# 1269 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1270 "data/maps/PetalburgCity/scripts.pory"
# 635 "data/maps/PetalburgCity/scripts.pory"
# 1271 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1272 "data/maps/PetalburgCity/scripts.pory"
# 636 "data/maps/PetalburgCity/scripts.pory"
# 1273 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1274 "data/maps/PetalburgCity/scripts.pory"
# 637 "data/maps/PetalburgCity/scripts.pory"
# 1275 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1276 "data/maps/PetalburgCity/scripts.pory"
# 638 "data/maps/PetalburgCity/scripts.pory"
# 1277 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1278 "data/maps/PetalburgCity/scripts.pory"
# 639 "data/maps/PetalburgCity/scripts.pory"
# 1279 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1280 "data/maps/PetalburgCity/scripts.pory"
# 640 "data/maps/PetalburgCity/scripts.pory"
# 1281 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1282 "data/maps/PetalburgCity/scripts.pory"
# 641 "data/maps/PetalburgCity/scripts.pory"
# 1283 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1284 "data/maps/PetalburgCity/scripts.pory"
# 642 "data/maps/PetalburgCity/scripts.pory"
# 1285 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 1286 "data/maps/PetalburgCity/scripts.pory"
# 643 "data/maps/PetalburgCity/scripts.pory"
# 1287 "data/maps/PetalburgCity/scripts.pory"

# 1288 "data/maps/PetalburgCity/scripts.pory"
# 644 "data/maps/PetalburgCity/scripts.pory"
# 1289 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit1:
# 1290 "data/maps/PetalburgCity/scripts.pory"
# 645 "data/maps/PetalburgCity/scripts.pory"
# 1291 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 1292 "data/maps/PetalburgCity/scripts.pory"
# 646 "data/maps/PetalburgCity/scripts.pory"
# 1293 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 1294 "data/maps/PetalburgCity/scripts.pory"
# 647 "data/maps/PetalburgCity/scripts.pory"
# 1295 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 1296 "data/maps/PetalburgCity/scripts.pory"
# 648 "data/maps/PetalburgCity/scripts.pory"
# 1297 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 1298 "data/maps/PetalburgCity/scripts.pory"
# 649 "data/maps/PetalburgCity/scripts.pory"
# 1299 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 1300 "data/maps/PetalburgCity/scripts.pory"
# 650 "data/maps/PetalburgCity/scripts.pory"
# 1301 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 1302 "data/maps/PetalburgCity/scripts.pory"
# 651 "data/maps/PetalburgCity/scripts.pory"
# 1303 "data/maps/PetalburgCity/scripts.pory"

# 1304 "data/maps/PetalburgCity/scripts.pory"
# 652 "data/maps/PetalburgCity/scripts.pory"
# 1305 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit2:
# 1306 "data/maps/PetalburgCity/scripts.pory"
# 653 "data/maps/PetalburgCity/scripts.pory"
# 1307 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 1308 "data/maps/PetalburgCity/scripts.pory"
# 654 "data/maps/PetalburgCity/scripts.pory"
# 1309 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1310 "data/maps/PetalburgCity/scripts.pory"
# 655 "data/maps/PetalburgCity/scripts.pory"
# 1311 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1312 "data/maps/PetalburgCity/scripts.pory"
# 656 "data/maps/PetalburgCity/scripts.pory"
# 1313 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1314 "data/maps/PetalburgCity/scripts.pory"
# 657 "data/maps/PetalburgCity/scripts.pory"
# 1315 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1316 "data/maps/PetalburgCity/scripts.pory"
# 658 "data/maps/PetalburgCity/scripts.pory"
# 1317 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1318 "data/maps/PetalburgCity/scripts.pory"
# 659 "data/maps/PetalburgCity/scripts.pory"
# 1319 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1320 "data/maps/PetalburgCity/scripts.pory"
# 660 "data/maps/PetalburgCity/scripts.pory"
# 1321 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1322 "data/maps/PetalburgCity/scripts.pory"
# 661 "data/maps/PetalburgCity/scripts.pory"
# 1323 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1324 "data/maps/PetalburgCity/scripts.pory"
# 662 "data/maps/PetalburgCity/scripts.pory"
# 1325 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1326 "data/maps/PetalburgCity/scripts.pory"
# 663 "data/maps/PetalburgCity/scripts.pory"
# 1327 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1328 "data/maps/PetalburgCity/scripts.pory"
# 664 "data/maps/PetalburgCity/scripts.pory"
# 1329 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1330 "data/maps/PetalburgCity/scripts.pory"
# 665 "data/maps/PetalburgCity/scripts.pory"
# 1331 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 1332 "data/maps/PetalburgCity/scripts.pory"
# 666 "data/maps/PetalburgCity/scripts.pory"
# 1333 "data/maps/PetalburgCity/scripts.pory"

# 1334 "data/maps/PetalburgCity/scripts.pory"
# 667 "data/maps/PetalburgCity/scripts.pory"
# 1335 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit2:
# 1336 "data/maps/PetalburgCity/scripts.pory"
# 668 "data/maps/PetalburgCity/scripts.pory"
# 1337 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 1338 "data/maps/PetalburgCity/scripts.pory"
# 669 "data/maps/PetalburgCity/scripts.pory"
# 1339 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 1340 "data/maps/PetalburgCity/scripts.pory"
# 670 "data/maps/PetalburgCity/scripts.pory"
# 1341 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 1342 "data/maps/PetalburgCity/scripts.pory"
# 671 "data/maps/PetalburgCity/scripts.pory"
# 1343 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 1344 "data/maps/PetalburgCity/scripts.pory"
# 672 "data/maps/PetalburgCity/scripts.pory"
# 1345 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 1346 "data/maps/PetalburgCity/scripts.pory"
# 673 "data/maps/PetalburgCity/scripts.pory"
# 1347 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 1348 "data/maps/PetalburgCity/scripts.pory"
# 674 "data/maps/PetalburgCity/scripts.pory"
# 1349 "data/maps/PetalburgCity/scripts.pory"

# 1350 "data/maps/PetalburgCity/scripts.pory"
# 675 "data/maps/PetalburgCity/scripts.pory"
# 1351 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit3:
# 1352 "data/maps/PetalburgCity/scripts.pory"
# 676 "data/maps/PetalburgCity/scripts.pory"
# 1353 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 1354 "data/maps/PetalburgCity/scripts.pory"
# 677 "data/maps/PetalburgCity/scripts.pory"
# 1355 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1356 "data/maps/PetalburgCity/scripts.pory"
# 678 "data/maps/PetalburgCity/scripts.pory"
# 1357 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1358 "data/maps/PetalburgCity/scripts.pory"
# 679 "data/maps/PetalburgCity/scripts.pory"
# 1359 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1360 "data/maps/PetalburgCity/scripts.pory"
# 680 "data/maps/PetalburgCity/scripts.pory"
# 1361 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1362 "data/maps/PetalburgCity/scripts.pory"
# 681 "data/maps/PetalburgCity/scripts.pory"
# 1363 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1364 "data/maps/PetalburgCity/scripts.pory"
# 682 "data/maps/PetalburgCity/scripts.pory"
# 1365 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1366 "data/maps/PetalburgCity/scripts.pory"
# 683 "data/maps/PetalburgCity/scripts.pory"
# 1367 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1368 "data/maps/PetalburgCity/scripts.pory"
# 684 "data/maps/PetalburgCity/scripts.pory"
# 1369 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1370 "data/maps/PetalburgCity/scripts.pory"
# 685 "data/maps/PetalburgCity/scripts.pory"
# 1371 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1372 "data/maps/PetalburgCity/scripts.pory"
# 686 "data/maps/PetalburgCity/scripts.pory"
# 1373 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1374 "data/maps/PetalburgCity/scripts.pory"
# 687 "data/maps/PetalburgCity/scripts.pory"
# 1375 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 1376 "data/maps/PetalburgCity/scripts.pory"
# 688 "data/maps/PetalburgCity/scripts.pory"
# 1377 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 1378 "data/maps/PetalburgCity/scripts.pory"
# 689 "data/maps/PetalburgCity/scripts.pory"
# 1379 "data/maps/PetalburgCity/scripts.pory"

# 1380 "data/maps/PetalburgCity/scripts.pory"
# 690 "data/maps/PetalburgCity/scripts.pory"
# 1381 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit3:
# 1382 "data/maps/PetalburgCity/scripts.pory"
# 691 "data/maps/PetalburgCity/scripts.pory"
# 1383 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 1384 "data/maps/PetalburgCity/scripts.pory"
# 692 "data/maps/PetalburgCity/scripts.pory"
# 1385 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 1386 "data/maps/PetalburgCity/scripts.pory"
# 693 "data/maps/PetalburgCity/scripts.pory"
# 1387 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 1388 "data/maps/PetalburgCity/scripts.pory"
# 694 "data/maps/PetalburgCity/scripts.pory"
# 1389 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 1390 "data/maps/PetalburgCity/scripts.pory"
# 695 "data/maps/PetalburgCity/scripts.pory"
# 1391 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 1392 "data/maps/PetalburgCity/scripts.pory"
# 696 "data/maps/PetalburgCity/scripts.pory"
# 1393 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 1394 "data/maps/PetalburgCity/scripts.pory"
# 697 "data/maps/PetalburgCity/scripts.pory"
# 1395 "data/maps/PetalburgCity/scripts.pory"

# 1396 "data/maps/PetalburgCity/scripts.pory"
# 698 "data/maps/PetalburgCity/scripts.pory"
# 1397 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_GymBoy::
# 1398 "data/maps/PetalburgCity/scripts.pory"
# 699 "data/maps/PetalburgCity/scripts.pory"
# 1399 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_NPC
# 1400 "data/maps/PetalburgCity/scripts.pory"
# 700 "data/maps/PetalburgCity/scripts.pory"
# 1401 "data/maps/PetalburgCity/scripts.pory"
	end
# 1402 "data/maps/PetalburgCity/scripts.pory"
# 701 "data/maps/PetalburgCity/scripts.pory"
# 1403 "data/maps/PetalburgCity/scripts.pory"

# 1404 "data/maps/PetalburgCity/scripts.pory"
# 702 "data/maps/PetalburgCity/scripts.pory"
# 1405 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_WhereIsWally:
# 1406 "data/maps/PetalburgCity/scripts.pory"
# 703 "data/maps/PetalburgCity/scripts.pory"
# 1407 "data/maps/PetalburgCity/scripts.pory"
	.string "Where has our WALLY gone?\p"
# 1408 "data/maps/PetalburgCity/scripts.pory"
# 704 "data/maps/PetalburgCity/scripts.pory"
# 1409 "data/maps/PetalburgCity/scripts.pory"
	.string "We have to leave for VERDANTURF TOWN\n"
# 1410 "data/maps/PetalburgCity/scripts.pory"
# 705 "data/maps/PetalburgCity/scripts.pory"
# 1411 "data/maps/PetalburgCity/scripts.pory"
	.string "very soon…$"
# 1412 "data/maps/PetalburgCity/scripts.pory"
# 706 "data/maps/PetalburgCity/scripts.pory"
# 1413 "data/maps/PetalburgCity/scripts.pory"

# 1414 "data/maps/PetalburgCity/scripts.pory"
# 707 "data/maps/PetalburgCity/scripts.pory"
# 1415 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_AreYouRookieTrainer:
# 1416 "data/maps/PetalburgCity/scripts.pory"
# 708 "data/maps/PetalburgCity/scripts.pory"
# 1417 "data/maps/PetalburgCity/scripts.pory"
	.string "Hiya! Are you maybe…\n"
# 1418 "data/maps/PetalburgCity/scripts.pory"
# 709 "data/maps/PetalburgCity/scripts.pory"
# 1419 "data/maps/PetalburgCity/scripts.pory"
	.string "A rookie TRAINER?\p"
# 1420 "data/maps/PetalburgCity/scripts.pory"
# 710 "data/maps/PetalburgCity/scripts.pory"
# 1421 "data/maps/PetalburgCity/scripts.pory"
	.string "Do you know what POKéMON TRAINERS\n"
# 1422 "data/maps/PetalburgCity/scripts.pory"
# 711 "data/maps/PetalburgCity/scripts.pory"
# 1423 "data/maps/PetalburgCity/scripts.pory"
	.string "do when they reach a new town?\p"
# 1424 "data/maps/PetalburgCity/scripts.pory"
# 712 "data/maps/PetalburgCity/scripts.pory"
# 1425 "data/maps/PetalburgCity/scripts.pory"
	.string "They first check what kind of GYM\n"
# 1426 "data/maps/PetalburgCity/scripts.pory"
# 713 "data/maps/PetalburgCity/scripts.pory"
# 1427 "data/maps/PetalburgCity/scripts.pory"
	.string "is in the town.$"
# 1428 "data/maps/PetalburgCity/scripts.pory"
# 714 "data/maps/PetalburgCity/scripts.pory"
# 1429 "data/maps/PetalburgCity/scripts.pory"

# 1430 "data/maps/PetalburgCity/scripts.pory"
# 715 "data/maps/PetalburgCity/scripts.pory"
# 1431 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_ThisIsPetalburgGym:
# 1432 "data/maps/PetalburgCity/scripts.pory"
# 716 "data/maps/PetalburgCity/scripts.pory"
# 1433 "data/maps/PetalburgCity/scripts.pory"
	.string "See? This is PETALBURG CITY's GYM.$"
# 1434 "data/maps/PetalburgCity/scripts.pory"
# 717 "data/maps/PetalburgCity/scripts.pory"
# 1435 "data/maps/PetalburgCity/scripts.pory"

# 1436 "data/maps/PetalburgCity/scripts.pory"
# 718 "data/maps/PetalburgCity/scripts.pory"
# 1437 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_ThisIsGymSign:
# 1438 "data/maps/PetalburgCity/scripts.pory"
# 719 "data/maps/PetalburgCity/scripts.pory"
# 1439 "data/maps/PetalburgCity/scripts.pory"
	.string "This is the GYM's sign. Look for it\n"
# 1440 "data/maps/PetalburgCity/scripts.pory"
# 720 "data/maps/PetalburgCity/scripts.pory"
# 1441 "data/maps/PetalburgCity/scripts.pory"
	.string "whenever you're looking for a GYM.$"
# 1442 "data/maps/PetalburgCity/scripts.pory"
# 721 "data/maps/PetalburgCity/scripts.pory"
# 1443 "data/maps/PetalburgCity/scripts.pory"

# 1444 "data/maps/PetalburgCity/scripts.pory"
# 722 "data/maps/PetalburgCity/scripts.pory"
# 1445 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_WaterReflection:
# 1446 "data/maps/PetalburgCity/scripts.pory"
# 723 "data/maps/PetalburgCity/scripts.pory"
# 1447 "data/maps/PetalburgCity/scripts.pory"
	.string "My face is reflected in the water.\p"
# 1448 "data/maps/PetalburgCity/scripts.pory"
# 724 "data/maps/PetalburgCity/scripts.pory"
# 1449 "data/maps/PetalburgCity/scripts.pory"
	.string "It's a shining grin full of hope…\p"
# 1450 "data/maps/PetalburgCity/scripts.pory"
# 725 "data/maps/PetalburgCity/scripts.pory"
# 1451 "data/maps/PetalburgCity/scripts.pory"
	.string "Or it could be a look of somber silence\n"
# 1452 "data/maps/PetalburgCity/scripts.pory"
# 726 "data/maps/PetalburgCity/scripts.pory"
# 1453 "data/maps/PetalburgCity/scripts.pory"
	.string "struggling with fear…\p"
# 1454 "data/maps/PetalburgCity/scripts.pory"
# 727 "data/maps/PetalburgCity/scripts.pory"
# 1455 "data/maps/PetalburgCity/scripts.pory"
	.string "What do you see reflected in your face?$"
# 1456 "data/maps/PetalburgCity/scripts.pory"
# 728 "data/maps/PetalburgCity/scripts.pory"
# 1457 "data/maps/PetalburgCity/scripts.pory"

# 1458 "data/maps/PetalburgCity/scripts.pory"
# 729 "data/maps/PetalburgCity/scripts.pory"
# 1459 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_FullPartyExplanation:
# 1460 "data/maps/PetalburgCity/scripts.pory"
# 730 "data/maps/PetalburgCity/scripts.pory"
# 1461 "data/maps/PetalburgCity/scripts.pory"
	.string "Let's say you have six POKéMON.\n"
# 1462 "data/maps/PetalburgCity/scripts.pory"
# 731 "data/maps/PetalburgCity/scripts.pory"
# 1463 "data/maps/PetalburgCity/scripts.pory"
	.string "If you catch another one…\p"
# 1464 "data/maps/PetalburgCity/scripts.pory"
# 732 "data/maps/PetalburgCity/scripts.pory"
# 1465 "data/maps/PetalburgCity/scripts.pory"
	.string "It is automatically sent to a STORAGE\n"
# 1466 "data/maps/PetalburgCity/scripts.pory"
# 733 "data/maps/PetalburgCity/scripts.pory"
# 1467 "data/maps/PetalburgCity/scripts.pory"
	.string "BOX over a PC connection.$"
# 1468 "data/maps/PetalburgCity/scripts.pory"
# 734 "data/maps/PetalburgCity/scripts.pory"
# 1469 "data/maps/PetalburgCity/scripts.pory"

# 1470 "data/maps/PetalburgCity/scripts.pory"
# 735 "data/maps/PetalburgCity/scripts.pory"
# 1471 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_GymSign:
# 1472 "data/maps/PetalburgCity/scripts.pory"
# 736 "data/maps/PetalburgCity/scripts.pory"
# 1473 "data/maps/PetalburgCity/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM\n"
# 1474 "data/maps/PetalburgCity/scripts.pory"
# 737 "data/maps/PetalburgCity/scripts.pory"
# 1475 "data/maps/PetalburgCity/scripts.pory"
	.string "LEADER: NORMAN\l"
# 1476 "data/maps/PetalburgCity/scripts.pory"
# 738 "data/maps/PetalburgCity/scripts.pory"
# 1477 "data/maps/PetalburgCity/scripts.pory"
	.string "“A man in pursuit of power!”$"
# 1478 "data/maps/PetalburgCity/scripts.pory"
# 739 "data/maps/PetalburgCity/scripts.pory"
# 1479 "data/maps/PetalburgCity/scripts.pory"

# 1480 "data/maps/PetalburgCity/scripts.pory"
# 740 "data/maps/PetalburgCity/scripts.pory"
# 1481 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_CitySign:
# 1482 "data/maps/PetalburgCity/scripts.pory"
# 741 "data/maps/PetalburgCity/scripts.pory"
# 1483 "data/maps/PetalburgCity/scripts.pory"
	.string "PETALBURG CITY\n"
# 1484 "data/maps/PetalburgCity/scripts.pory"
# 742 "data/maps/PetalburgCity/scripts.pory"
# 1485 "data/maps/PetalburgCity/scripts.pory"
	.string "“Where people mingle with nature.”$"
# 1486 "data/maps/PetalburgCity/scripts.pory"
# 743 "data/maps/PetalburgCity/scripts.pory"
# 1487 "data/maps/PetalburgCity/scripts.pory"

# 1488 "data/maps/PetalburgCity/scripts.pory"
# 744 "data/maps/PetalburgCity/scripts.pory"
# 1489 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_WallyHouseSign:
# 1490 "data/maps/PetalburgCity/scripts.pory"
# 745 "data/maps/PetalburgCity/scripts.pory"
# 1491 "data/maps/PetalburgCity/scripts.pory"
	.string "WALLY'S HOUSE$"
# 1492 "data/maps/PetalburgCity/scripts.pory"
# 746 "data/maps/PetalburgCity/scripts.pory"
# 1493 "data/maps/PetalburgCity/scripts.pory"

# 1494 "data/maps/PetalburgCity/scripts.pory"
# 747 "data/maps/PetalburgCity/scripts.pory"
# 1495 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_AreYouATrainer:
# 1496 "data/maps/PetalburgCity/scripts.pory"
# 748 "data/maps/PetalburgCity/scripts.pory"
# 1497 "data/maps/PetalburgCity/scripts.pory"
	.string "Excuse me!\p"
# 1498 "data/maps/PetalburgCity/scripts.pory"
# 749 "data/maps/PetalburgCity/scripts.pory"
# 1499 "data/maps/PetalburgCity/scripts.pory"
	.string "Let me guess, from the way you're\n"
# 1500 "data/maps/PetalburgCity/scripts.pory"
# 750 "data/maps/PetalburgCity/scripts.pory"
# 1501 "data/maps/PetalburgCity/scripts.pory"
	.string "dressed, are you a POKéMON TRAINER?$"
# 1502 "data/maps/PetalburgCity/scripts.pory"
# 751 "data/maps/PetalburgCity/scripts.pory"
# 1503 "data/maps/PetalburgCity/scripts.pory"

# 1504 "data/maps/PetalburgCity/scripts.pory"
# 752 "data/maps/PetalburgCity/scripts.pory"
# 1505 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_WellMaybeNot:
# 1506 "data/maps/PetalburgCity/scripts.pory"
# 753 "data/maps/PetalburgCity/scripts.pory"
# 1507 "data/maps/PetalburgCity/scripts.pory"
	.string "… … … … … …\p"
# 1508 "data/maps/PetalburgCity/scripts.pory"
# 754 "data/maps/PetalburgCity/scripts.pory"
# 1509 "data/maps/PetalburgCity/scripts.pory"
	.string "Well, maybe not.\n"
# 1510 "data/maps/PetalburgCity/scripts.pory"
# 755 "data/maps/PetalburgCity/scripts.pory"
# 1511 "data/maps/PetalburgCity/scripts.pory"
	.string "Your clothes aren't all that dirty.\p"
# 1512 "data/maps/PetalburgCity/scripts.pory"
# 756 "data/maps/PetalburgCity/scripts.pory"
# 1513 "data/maps/PetalburgCity/scripts.pory"
	.string "You're either a rookie TRAINER,\n"
# 1514 "data/maps/PetalburgCity/scripts.pory"
# 757 "data/maps/PetalburgCity/scripts.pory"
# 1515 "data/maps/PetalburgCity/scripts.pory"
	.string "or maybe you're just an ordinary kid.$"
# 1516 "data/maps/PetalburgCity/scripts.pory"
# 758 "data/maps/PetalburgCity/scripts.pory"
# 1517 "data/maps/PetalburgCity/scripts.pory"

# 1518 "data/maps/PetalburgCity/scripts.pory"
# 759 "data/maps/PetalburgCity/scripts.pory"
# 1519 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_ImLookingForTalentedTrainers:
# 1520 "data/maps/PetalburgCity/scripts.pory"
# 760 "data/maps/PetalburgCity/scripts.pory"
# 1521 "data/maps/PetalburgCity/scripts.pory"
	.string "I'm roaming the land in search of\n"
# 1522 "data/maps/PetalburgCity/scripts.pory"
# 761 "data/maps/PetalburgCity/scripts.pory"
# 1523 "data/maps/PetalburgCity/scripts.pory"
	.string "talented TRAINERS.\p"
# 1524 "data/maps/PetalburgCity/scripts.pory"
# 762 "data/maps/PetalburgCity/scripts.pory"
# 1525 "data/maps/PetalburgCity/scripts.pory"
	.string "I'm sorry to have taken your time.$"
# 1526 "data/maps/PetalburgCity/scripts.pory"

# 1527 "data/maps/PetalburgCity/scripts.pory"
PetalBurgCity_EventScript_MathieuHouseSign::
# 1528 "data/maps/PetalburgCity/scripts.pory"
# 765 "data/maps/PetalburgCity/scripts.pory"
# 1529 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 1530 "data/maps/PetalburgCity/scripts.pory"
# 766 "data/maps/PetalburgCity/scripts.pory"
# 1531 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalBurgCity_EventScript_MathieuHouseSign_Text_0
# 1532 "data/maps/PetalburgCity/scripts.pory"
# 767 "data/maps/PetalburgCity/scripts.pory"
# 1533 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 1534 "data/maps/PetalburgCity/scripts.pory"
	return
# 1535 "data/maps/PetalburgCity/scripts.pory"

# 1536 "data/maps/PetalburgCity/scripts.pory"

# 1537 "data/maps/PetalburgCity/scripts.pory"
PetalBurgCity_EventScript_MathieuHouseSign_Text_0:
# 1538 "data/maps/PetalburgCity/scripts.pory"
# 766 "data/maps/PetalburgCity/scripts.pory"
# 1539 "data/maps/PetalburgCity/scripts.pory"
	.string "Mathieu's House$"
