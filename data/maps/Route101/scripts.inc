# 1 "data/maps/Route101/scripts.pory"

# 2 "data/maps/Route101/scripts.pory"
Route101_MapScripts::
# 3 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
# 4 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
# 5 "data/maps/Route101/scripts.pory"
	.byte 0
# 6 "data/maps/Route101/scripts.pory"

# 7 "data/maps/Route101/scripts.pory"
Route101_OnTransition:
# 8 "data/maps/Route101/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 9 "data/maps/Route101/scripts.pory"
	end
# 10 "data/maps/Route101/scripts.pory"

# 11 "data/maps/Route101/scripts.pory"
Route101_OnFrame:
# 12 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
# 13 "data/maps/Route101/scripts.pory"
	.2byte 0
# 14 "data/maps/Route101/scripts.pory"

# 15 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideMapNamePopup::
# 16 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 17 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 1
# 18 "data/maps/Route101/scripts.pory"
	end
# 19 "data/maps/Route101/scripts.pory"

# 20 "data/maps/Route101/scripts.pory"
Route101_EventScript_StartBirchRescue::
# 21 "data/maps/Route101/scripts.pory"
	lockall
# 22 "data/maps/Route101/scripts.pory"
	playbgm MUS_HELP, TRUE
# 23 "data/maps/Route101/scripts.pory"
	speakername(Unknown)
# 24 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
# 25 "data/maps/Route101/scripts.pory"
	closemessage
# 26 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_ROUTE101_BIRCH, 0, 15
# 27 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_ROUTE101_ZIGZAGOON, 0, 16
# 28 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_EnterScene
# 29 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunAway1
# 30 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
# 31 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 32 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
# 33 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunInCircles
# 34 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 35 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 36 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 37 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
# 38 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchFaceZigzagoon
# 39 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 40 "data/maps/Route101/scripts.pory"
	speakername(Birch)
# 41 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
# 42 "data/maps/Route101/scripts.pory"
	closemessage
# 43 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 2
# 44 "data/maps/Route101/scripts.pory"
	releaseall
# 45 "data/maps/Route101/scripts.pory"
	end
# 46 "data/maps/Route101/scripts.pory"

# 47 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitSouth::
# 48 "data/maps/Route101/scripts.pory"
	lockall
# 49 "data/maps/Route101/scripts.pory"
	speakername(Birch)
# 50 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 51 "data/maps/Route101/scripts.pory"
	closemessage
# 52 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitSouth
# 53 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 54 "data/maps/Route101/scripts.pory"
	releaseall
# 55 "data/maps/Route101/scripts.pory"
	end
# 56 "data/maps/Route101/scripts.pory"

# 57 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitWest::
# 58 "data/maps/Route101/scripts.pory"
	lockall
# 59 "data/maps/Route101/scripts.pory"
	speakername(Birch)
# 60 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 61 "data/maps/Route101/scripts.pory"
	closemessage
# 62 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitWest
# 63 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 64 "data/maps/Route101/scripts.pory"
	releaseall
# 65 "data/maps/Route101/scripts.pory"
	end
# 66 "data/maps/Route101/scripts.pory"

# 67 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitNorth::
# 68 "data/maps/Route101/scripts.pory"
	lockall
# 69 "data/maps/Route101/scripts.pory"
	speakername(Birch)
# 70 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 71 "data/maps/Route101/scripts.pory"
	closemessage
# 72 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitNorth
# 73 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 74 "data/maps/Route101/scripts.pory"
	releaseall
# 75 "data/maps/Route101/scripts.pory"
	end
# 76 "data/maps/Route101/scripts.pory"

# 77 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitSouth:
# 78 "data/maps/Route101/scripts.pory"
	walk_up
# 79 "data/maps/Route101/scripts.pory"
	step_end
# 80 "data/maps/Route101/scripts.pory"

# 81 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitWest:
# 82 "data/maps/Route101/scripts.pory"
	walk_right
# 83 "data/maps/Route101/scripts.pory"
	step_end
# 84 "data/maps/Route101/scripts.pory"

# 85 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitNorth:
# 86 "data/maps/Route101/scripts.pory"
	walk_down
# 87 "data/maps/Route101/scripts.pory"
	step_end
# 88 "data/maps/Route101/scripts.pory"

# 89 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChaseInCircles:
# 90 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 91 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 92 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 93 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 94 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 95 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 96 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 97 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 98 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 99 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 100 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 101 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 102 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 103 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 104 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 105 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 106 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 107 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 108 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 109 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 110 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 111 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 112 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 113 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 114 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 115 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 116 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 117 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 118 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 119 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 120 "data/maps/Route101/scripts.pory"
	step_end
# 121 "data/maps/Route101/scripts.pory"

# 122 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChase1:
# 123 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 124 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 125 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 126 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 127 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 128 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 129 "data/maps/Route101/scripts.pory"
	step_end
# 130 "data/maps/Route101/scripts.pory"

# 131 "data/maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 132 "data/maps/Route101/scripts.pory"
	step_end
# 133 "data/maps/Route101/scripts.pory"

# 134 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonFaceBirch:
# 135 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 136 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 137 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 138 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 139 "data/maps/Route101/scripts.pory"
	step_end
# 140 "data/maps/Route101/scripts.pory"

# 141 "data/maps/Route101/scripts.pory"
Route101_Movement_EnterScene:
# 142 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 143 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 144 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 145 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 146 "data/maps/Route101/scripts.pory"
	walk_in_place_faster_left
# 147 "data/maps/Route101/scripts.pory"
	step_end
# 148 "data/maps/Route101/scripts.pory"

# 149 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunInCircles:
# 150 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 151 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 152 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 153 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 154 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 155 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 156 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 157 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 158 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 159 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 160 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 161 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 162 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 163 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 164 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 166 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 167 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 168 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 169 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 170 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 171 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 172 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 173 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 174 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 175 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 176 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 177 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 178 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 179 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 180 "data/maps/Route101/scripts.pory"
	step_end
# 181 "data/maps/Route101/scripts.pory"

# 182 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunAway1:
# 183 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 184 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 186 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 187 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 188 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 189 "data/maps/Route101/scripts.pory"
	step_end
# 190 "data/maps/Route101/scripts.pory"

# 191 "data/maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 192 "data/maps/Route101/scripts.pory"
	step_end
# 193 "data/maps/Route101/scripts.pory"

# 194 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchFaceZigzagoon:
# 195 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 196 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 197 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 198 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 199 "data/maps/Route101/scripts.pory"
	step_end
# 200 "data/maps/Route101/scripts.pory"

# 201 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused1:
# 202 "data/maps/Route101/scripts.pory"
	walk_up
# 203 "data/maps/Route101/scripts.pory"
	walk_up
# 204 "data/maps/Route101/scripts.pory"
	step_end
# 205 "data/maps/Route101/scripts.pory"

# 206 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused2:
# 207 "data/maps/Route101/scripts.pory"
	walk_up
# 208 "data/maps/Route101/scripts.pory"
	walk_left
# 209 "data/maps/Route101/scripts.pory"
	walk_up
# 210 "data/maps/Route101/scripts.pory"
	step_end
# 211 "data/maps/Route101/scripts.pory"

# 212 "data/maps/Route101/scripts.pory"
Route101_EventScript_Youngster::
# 213 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
# 214 "data/maps/Route101/scripts.pory"
	end
# 215 "data/maps/Route101/scripts.pory"

# 216 "data/maps/Route101/scripts.pory"
Route101_EventScript_Boy::
# 217 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
# 218 "data/maps/Route101/scripts.pory"
	end
# 219 "data/maps/Route101/scripts.pory"

# 220 "data/maps/Route101/scripts.pory"
Route101_EventScript_RouteSign::
# 221 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
# 222 "data/maps/Route101/scripts.pory"
	end
# 223 "data/maps/Route101/scripts.pory"

# 224 "data/maps/Route101/scripts.pory"
Route101_EventScript_BirchsBag::
# 225 "data/maps/Route101/scripts.pory"
	lock
# 226 "data/maps/Route101/scripts.pory"
	faceplayer
# 227 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 228 "data/maps/Route101/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 229 "data/maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 230 "data/maps/Route101/scripts.pory"
	removeobject LOCALID_ROUTE101_ZIGZAGOON
# 231 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_PLAYER, 6, 13
# 232 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 233 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 234 "data/maps/Route101/scripts.pory"
	special ChooseStarter
# 235 "data/maps/Route101/scripts.pory"
	waitstate
# 236 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchApproachPlayer
# 237 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 238 "data/maps/Route101/scripts.pory"
	speakername(Birch)
# 239 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
# 240 "data/maps/Route101/scripts.pory"
	special HealPlayerParty
# 241 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 242 "data/maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 243 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 244 "data/maps/Route101/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 2
# 245 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 246 "data/maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 247 "data/maps/Route101/scripts.pory"
	checkplayergender
# 248 "data/maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 249 "data/maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
# 250 "data/maps/Route101/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 251 "data/maps/Route101/scripts.pory"
	waitstate
# 252 "data/maps/Route101/scripts.pory"
	release
# 253 "data/maps/Route101/scripts.pory"
	end
# 254 "data/maps/Route101/scripts.pory"

# 255 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideMayInBedroom::
# 256 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 257 "data/maps/Route101/scripts.pory"
	return
# 258 "data/maps/Route101/scripts.pory"

# 259 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideBrendanInBedroom::
# 260 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 261 "data/maps/Route101/scripts.pory"
	return
# 262 "data/maps/Route101/scripts.pory"

# 263 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchApproachPlayer:
# 264 "data/maps/Route101/scripts.pory"
	walk_right
# 265 "data/maps/Route101/scripts.pory"
	step_end
# 266 "data/maps/Route101/scripts.pory"

# 267 "data/maps/Route101/scripts.pory"
Route101_Text_HelpMe:
# 268 "data/maps/Route101/scripts.pory"
	.string "H-help me!$"
# 269 "data/maps/Route101/scripts.pory"

# 270 "data/maps/Route101/scripts.pory"
Route101_Text_PleaseHelp:
# 271 "data/maps/Route101/scripts.pory"
	.string "Hello! You over there!\n"
# 272 "data/maps/Route101/scripts.pory"
	.string "Please! Help!\p"
# 273 "data/maps/Route101/scripts.pory"
	.string "In my BAG!\n"
# 274 "data/maps/Route101/scripts.pory"
	.string "There's a POKé BALL!$"
# 275 "data/maps/Route101/scripts.pory"

# 276 "data/maps/Route101/scripts.pory"
Route101_Text_DontLeaveMe:
# 277 "data/maps/Route101/scripts.pory"
	.string "Wh-Where are you going?!\n"
# 278 "data/maps/Route101/scripts.pory"
	.string "Don't leave me like this!$"
# 279 "data/maps/Route101/scripts.pory"

# 280 "data/maps/Route101/scripts.pory"
Route101_Text_YouSavedMe:
# 281 "data/maps/Route101/scripts.pory"
	.string "PROF. BIRCH: Whew…\p"
# 282 "data/maps/Route101/scripts.pory"
	.string "I was in the tall grass studying wild\n"
# 283 "data/maps/Route101/scripts.pory"
	.string "POKéMON when I was jumped.\p"
# 284 "data/maps/Route101/scripts.pory"
	.string "You saved me.\n"
# 285 "data/maps/Route101/scripts.pory"
	.string "Thanks a lot!\p"
# 286 "data/maps/Route101/scripts.pory"
	.string "Oh?\p"
# 287 "data/maps/Route101/scripts.pory"
	.string "Hi, you're {PLAYER}{KUN}!\p"
# 288 "data/maps/Route101/scripts.pory"
	.string "This is not the place to chat, so come\n"
# 289 "data/maps/Route101/scripts.pory"
	.string "by my POKéMON LAB later, okay?$"
# 290 "data/maps/Route101/scripts.pory"

# 291 "data/maps/Route101/scripts.pory"
Route101_Text_TakeTiredPokemonToPokeCenter:
# 292 "data/maps/Route101/scripts.pory"
	.string "If POKéMON get tired, take them to\n"
# 293 "data/maps/Route101/scripts.pory"
	.string "a POKéMON CENTER.\p"
# 294 "data/maps/Route101/scripts.pory"
	.string "There's a POKéMON CENTER in OLDALE\n"
# 295 "data/maps/Route101/scripts.pory"
	.string "TOWN right close by.$"
# 296 "data/maps/Route101/scripts.pory"

# 297 "data/maps/Route101/scripts.pory"
Route101_Text_WildPokemonInTallGrass:
# 298 "data/maps/Route101/scripts.pory"
	.string "Wild POKéMON will jump out at you in\n"
# 299 "data/maps/Route101/scripts.pory"
	.string "tall grass.\p"
# 300 "data/maps/Route101/scripts.pory"
	.string "If you want to catch POKéMON, you have\n"
# 301 "data/maps/Route101/scripts.pory"
	.string "to go into the tall grass and search.$"
# 302 "data/maps/Route101/scripts.pory"

# 303 "data/maps/Route101/scripts.pory"
Route101_Text_RouteSign:
# 304 "data/maps/Route101/scripts.pory"
	.string "ROUTE 101\n"
# 305 "data/maps/Route101/scripts.pory"
	.string "{UP_ARROW} OLDALE TOWN$"
