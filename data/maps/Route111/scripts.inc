# 1 "data/maps/Route111/scripts.pory"

# 2 "data/maps/Route111/scripts.pory"
.set LOCALID_VICTOR, 1
# 3 "data/maps/Route111/scripts.pory"
.set LOCALID_VICTORIA, 2
# 4 "data/maps/Route111/scripts.pory"
.set LOCALID_VIVI, 3
# 5 "data/maps/Route111/scripts.pory"
.set LOCALID_VICKY, 4
# 6 "data/maps/Route111/scripts.pory"
.set LOCALID_ROCK_SMASH_MAN, 46
# 7 "data/maps/Route111/scripts.pory"

# 8 "data/maps/Route111/scripts.pory"
@ Note: LOCALID_ROUTE111_PLAYER_FALLING is a local id for this map used elsewhere. It's defined in event_objects.h
# 9 "data/maps/Route111/scripts.pory"

# 10 "data/maps/Route111/scripts.pory"
Route111_MapScripts::
# 11 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
# 12 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
# 13 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
# 14 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
# 15 "data/maps/Route111/scripts.pory"
	.byte 0
# 16 "data/maps/Route111/scripts.pory"

# 17 "data/maps/Route111/scripts.pory"
Route111_OnLoad:
# 18 "data/maps/Route111/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_CloseDesertRuins
# 19 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_ShowTemporaryMirageTower
# 20 "data/maps/Route111/scripts.pory"
	end
# 21 "data/maps/Route111/scripts.pory"

# 22 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseDesertRuins::
# 23 "data/maps/Route111/scripts.pory"
	setmetatile 29, 86, METATILE_General_RockWall_RockBase, TRUE
# 24 "data/maps/Route111/scripts.pory"
	setmetatile 29, 87, METATILE_General_RockWall_SandBase, TRUE
# 25 "data/maps/Route111/scripts.pory"
	return
# 26 "data/maps/Route111/scripts.pory"

# 27 "data/maps/Route111/scripts.pory"
@ Show Mirage Tower just prior to disintegration. Mirage Tower is otherwise handled by the map layout
# 28 "data/maps/Route111/scripts.pory"
Route111_EventScript_ShowTemporaryMirageTower::
# 29 "data/maps/Route111/scripts.pory"
	setmetatile 18, 53, METATILE_Mauville_MirageTower_Tile0, FALSE
# 30 "data/maps/Route111/scripts.pory"
	setmetatile 19, 53, METATILE_Mauville_MirageTower_Tile1, FALSE
# 31 "data/maps/Route111/scripts.pory"
	setmetatile 20, 53, METATILE_Mauville_MirageTower_Tile2, FALSE
# 32 "data/maps/Route111/scripts.pory"
	setmetatile 18, 54, METATILE_Mauville_MirageTower_Tile3, FALSE
# 33 "data/maps/Route111/scripts.pory"
	setmetatile 19, 54, METATILE_Mauville_MirageTower_Tile4, FALSE
# 34 "data/maps/Route111/scripts.pory"
	setmetatile 20, 54, METATILE_Mauville_MirageTower_Tile5, FALSE
# 35 "data/maps/Route111/scripts.pory"
	setmetatile 18, 55, METATILE_Mauville_MirageTower_Tile6, FALSE
# 36 "data/maps/Route111/scripts.pory"
	setmetatile 19, 55, METATILE_Mauville_MirageTower_Tile7, FALSE
# 37 "data/maps/Route111/scripts.pory"
	setmetatile 20, 55, METATILE_Mauville_MirageTower_Tile8, FALSE
# 38 "data/maps/Route111/scripts.pory"
	setmetatile 18, 56, METATILE_Mauville_MirageTower_Tile9, FALSE
# 39 "data/maps/Route111/scripts.pory"
	setmetatile 19, 56, METATILE_Mauville_MirageTower_TileA, FALSE
# 40 "data/maps/Route111/scripts.pory"
	setmetatile 20, 56, METATILE_Mauville_MirageTower_TileB, FALSE
# 41 "data/maps/Route111/scripts.pory"
	setmetatile 18, 57, METATILE_Mauville_MirageTower_TileC, FALSE
# 42 "data/maps/Route111/scripts.pory"
	setmetatile 19, 57, METATILE_Mauville_MirageTower_TileD, FALSE
# 43 "data/maps/Route111/scripts.pory"
	setmetatile 20, 57, METATILE_Mauville_MirageTower_TileE, FALSE
# 44 "data/maps/Route111/scripts.pory"
	setmetatile 18, 58, METATILE_Mauville_MirageTower_TileF, FALSE
# 45 "data/maps/Route111/scripts.pory"
	setmetatile 19, 58, METATILE_Mauville_MirageTower_Tile10, FALSE
# 46 "data/maps/Route111/scripts.pory"
	setmetatile 20, 58, METATILE_Mauville_MirageTower_Tile11, FALSE
# 47 "data/maps/Route111/scripts.pory"
	return
# 48 "data/maps/Route111/scripts.pory"

# 49 "data/maps/Route111/scripts.pory"
Route111_OnTransition:
# 50 "data/maps/Route111/scripts.pory"
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
# 51 "data/maps/Route111/scripts.pory"
	special SetMirageTowerVisibility
# 52 "data/maps/Route111/scripts.pory"
	call_if_unset FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_SetLayoutNoMirageTower
# 53 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_SetFallingPlayerGfx
# 54 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_SetMirageTowerGone
# 55 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CheckSetSandstorm
# 56 "data/maps/Route111/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 57 "data/maps/Route111/scripts.pory"
	goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated
# 58 "data/maps/Route111/scripts.pory"
	end
# 59 "data/maps/Route111/scripts.pory"

# 60 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfx::
# 61 "data/maps/Route111/scripts.pory"
	checkplayergender
# 62 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route111_EventScript_SetFallingPlayerGfxMale
# 63 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route111_EventScript_SetFallingPlayerGfxFemale
# 64 "data/maps/Route111/scripts.pory"
	return
# 65 "data/maps/Route111/scripts.pory"

# 66 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxMale::
# 67 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 68 "data/maps/Route111/scripts.pory"
	return
# 69 "data/maps/Route111/scripts.pory"

# 70 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxFemale::
# 71 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 72 "data/maps/Route111/scripts.pory"
	return
# 73 "data/maps/Route111/scripts.pory"

# 74 "data/maps/Route111/scripts.pory"
Route111_EventScript_CheckSetSandstorm::
# 75 "data/maps/Route111/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 76 "data/maps/Route111/scripts.pory"
	goto_if_lt VAR_TEMP_1, 34, Route111_EventScript_EndCheckSetSandstorm
# 77 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_1, 107, Route111_EventScript_EndCheckSetSandstorm
# 78 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_1, 72, Route111_EventScript_SetSandstorm
# 79 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_0, 2000, Route111_EventScript_EndCheckSetSandstorm
# 80 "data/maps/Route111/scripts.pory"
	goto_if_lt VAR_TEMP_0, 8, Route111_EventScript_EndCheckSetSandstorm
# 81 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetSandstorm::
# 82 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 83 "data/maps/Route111/scripts.pory"
Route111_EventScript_EndCheckSetSandstorm::
# 84 "data/maps/Route111/scripts.pory"
	return
# 85 "data/maps/Route111/scripts.pory"

# 86 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetWinstratesNotDefeated::
# 87 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
# 88 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
# 89 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
# 90 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
# 91 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTOR
# 92 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTORIA
# 93 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VIVI
# 94 "data/maps/Route111/scripts.pory"
	end
# 95 "data/maps/Route111/scripts.pory"

# 96 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetLayoutNoMirageTower::
# 97 "data/maps/Route111/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE111_NO_MIRAGE_TOWER
# 98 "data/maps/Route111/scripts.pory"
	return
# 99 "data/maps/Route111/scripts.pory"

# 100 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetMirageTowerGone::
# 101 "data/maps/Route111/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 3
# 102 "data/maps/Route111/scripts.pory"
	return
# 103 "data/maps/Route111/scripts.pory"

# 104 "data/maps/Route111/scripts.pory"
Route111_OnWarp:
# 105 "data/maps/Route111/scripts.pory"
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_HidePlayerForMirageTower
# 106 "data/maps/Route111/scripts.pory"
	.2byte 0
# 107 "data/maps/Route111/scripts.pory"

# 108 "data/maps/Route111/scripts.pory"
Route111_EventScript_HidePlayerForMirageTower::
# 109 "data/maps/Route111/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
# 110 "data/maps/Route111/scripts.pory"
	end
# 111 "data/maps/Route111/scripts.pory"

# 112 "data/maps/Route111/scripts.pory"
Route111_OnFrame:
# 113 "data/maps/Route111/scripts.pory"
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_MirageTowerDisappear
# 114 "data/maps/Route111/scripts.pory"
	.2byte 0
# 115 "data/maps/Route111/scripts.pory"

# 116 "data/maps/Route111/scripts.pory"
Route111_EventScript_MirageTowerDisappear::
# 117 "data/maps/Route111/scripts.pory"
	lockall
# 118 "data/maps/Route111/scripts.pory"
	special StartMirageTowerShake
# 119 "data/maps/Route111/scripts.pory"
	waitstate
# 120 "data/maps/Route111/scripts.pory"
	delay 24
# 121 "data/maps/Route111/scripts.pory"
	playse SE_FALL
# 122 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_PLAYER_FALLING
# 123 "data/maps/Route111/scripts.pory"
	special StartPlayerDescendMirageTower
# 124 "data/maps/Route111/scripts.pory"
	waitstate
# 125 "data/maps/Route111/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
# 126 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_PLAYER_FALLING
# 127 "data/maps/Route111/scripts.pory"
	delay 16
# 128 "data/maps/Route111/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 129 "data/maps/Route111/scripts.pory"
	delay 16
# 130 "data/maps/Route111/scripts.pory"
	special StartMirageTowerDisintegration
# 131 "data/maps/Route111/scripts.pory"
	waitstate
# 132 "data/maps/Route111/scripts.pory"
	special StartMirageTowerFossilFallAndSink
# 133 "data/maps/Route111/scripts.pory"
	waitstate
# 134 "data/maps/Route111/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 2
# 135 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
# 136 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, Route111_EventScript_RootFossilDisappeared
# 137 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
# 138 "data/maps/Route111/scripts.pory"
	releaseall
# 139 "data/maps/Route111/scripts.pory"
	end
# 140 "data/maps/Route111/scripts.pory"

# 141 "data/maps/Route111/scripts.pory"
Route111_EventScript_RootFossilDisappeared::
# 142 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
# 143 "data/maps/Route111/scripts.pory"
	releaseall
# 144 "data/maps/Route111/scripts.pory"
	end
# 145 "data/maps/Route111/scripts.pory"

# 146 "data/maps/Route111/scripts.pory"
@ Unused
# 147 "data/maps/Route111/scripts.pory"
Route111_Movement_PlayerFall::
# 148 "data/maps/Route111/scripts.pory"
	lock_anim
# 149 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 150 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 151 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 152 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 153 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 154 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 155 "data/maps/Route111/scripts.pory"
	step_end
# 156 "data/maps/Route111/scripts.pory"

# 157 "data/maps/Route111/scripts.pory"
Route111_EventScript_Girl::
# 158 "data/maps/Route111/scripts.pory"
	lock
# 159 "data/maps/Route111/scripts.pory"
	faceplayer
# 160 "data/maps/Route111/scripts.pory"
	dotimebasedevents
# 161 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
# 162 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
# 163 "data/maps/Route111/scripts.pory"
	giveitem ITEM_RAZZ_BERRY
# 164 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 165 "data/maps/Route111/scripts.pory"
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
# 166 "data/maps/Route111/scripts.pory"
	special GetPlayerBigGuyGirlString
# 167 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
# 168 "data/maps/Route111/scripts.pory"
	release
# 169 "data/maps/Route111/scripts.pory"
	end
# 170 "data/maps/Route111/scripts.pory"

# 171 "data/maps/Route111/scripts.pory"
Route111_EventScript_ReceivedBerry::
# 172 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
# 173 "data/maps/Route111/scripts.pory"
	release
# 174 "data/maps/Route111/scripts.pory"
	end
# 175 "data/maps/Route111/scripts.pory"

# 176 "data/maps/Route111/scripts.pory"
@ Unused
# 177 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerUp::
# 178 "data/maps/Route111/scripts.pory"
	lockall
# 179 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 0
# 180 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 181 "data/maps/Route111/scripts.pory"
	end
# 182 "data/maps/Route111/scripts.pory"

# 183 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerDown::
# 184 "data/maps/Route111/scripts.pory"
	lockall
# 185 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 1
# 186 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 187 "data/maps/Route111/scripts.pory"
	end
# 188 "data/maps/Route111/scripts.pory"

# 189 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerLeft::
# 190 "data/maps/Route111/scripts.pory"
	lockall
# 191 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 2
# 192 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 193 "data/maps/Route111/scripts.pory"
	end
# 194 "data/maps/Route111/scripts.pory"

# 195 "data/maps/Route111/scripts.pory"
@ Unused
# 196 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerRight::
# 197 "data/maps/Route111/scripts.pory"
	lockall
# 198 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 3
# 199 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 200 "data/maps/Route111/scripts.pory"
	end
# 201 "data/maps/Route111/scripts.pory"

# 202 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTrigger::
# 203 "data/maps/Route111/scripts.pory"
	checkitem ITEM_GO_GOGGLES
# 204 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_PreventRouteAccess
# 205 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 1
# 206 "data/maps/Route111/scripts.pory"
	releaseall
# 207 "data/maps/Route111/scripts.pory"
	end
# 208 "data/maps/Route111/scripts.pory"

# 209 "data/maps/Route111/scripts.pory"
Route111_EventScript_PreventRouteAccess::
# 210 "data/maps/Route111/scripts.pory"
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
# 211 "data/maps/Route111/scripts.pory"
	closemessage
# 212 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 0, Route111_EventScript_PushUpFromRoute
# 213 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 1, Route111_EventScript_PushDownFromRoute
# 214 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 2, Route111_EventScript_PushLeftFromRoute
# 215 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 3, Route111_EventScript_PushRightFromRoute
# 216 "data/maps/Route111/scripts.pory"
	releaseall
# 217 "data/maps/Route111/scripts.pory"
	end
# 218 "data/maps/Route111/scripts.pory"

# 219 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushUpFromRoute::
# 220 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushUpFromRoute
# 221 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 222 "data/maps/Route111/scripts.pory"
	return
# 223 "data/maps/Route111/scripts.pory"

# 224 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushDownFromRoute::
# 225 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushDownFromRoute
# 226 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 227 "data/maps/Route111/scripts.pory"
	return
# 228 "data/maps/Route111/scripts.pory"

# 229 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushLeftFromRoute::
# 230 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushLeftFromRoute
# 231 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 232 "data/maps/Route111/scripts.pory"
	return
# 233 "data/maps/Route111/scripts.pory"

# 234 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushRightFromRoute::
# 235 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushRightFromRoute
# 236 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 237 "data/maps/Route111/scripts.pory"
	return
# 238 "data/maps/Route111/scripts.pory"

# 239 "data/maps/Route111/scripts.pory"
Route111_Movement_PushUpFromRoute:
# 240 "data/maps/Route111/scripts.pory"
	walk_up
# 241 "data/maps/Route111/scripts.pory"
	step_end
# 242 "data/maps/Route111/scripts.pory"

# 243 "data/maps/Route111/scripts.pory"
Route111_Movement_PushDownFromRoute:
# 244 "data/maps/Route111/scripts.pory"
	walk_down
# 245 "data/maps/Route111/scripts.pory"
	step_end
# 246 "data/maps/Route111/scripts.pory"

# 247 "data/maps/Route111/scripts.pory"
Route111_Movement_PushLeftFromRoute:
# 248 "data/maps/Route111/scripts.pory"
	walk_left
# 249 "data/maps/Route111/scripts.pory"
	step_end
# 250 "data/maps/Route111/scripts.pory"

# 251 "data/maps/Route111/scripts.pory"
Route111_Movement_PushRightFromRoute:
# 252 "data/maps/Route111/scripts.pory"
	walk_right
# 253 "data/maps/Route111/scripts.pory"
	step_end
# 254 "data/maps/Route111/scripts.pory"

# 255 "data/maps/Route111/scripts.pory"
Route111_EventScript_SunTrigger::
# 256 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SUNNY
# 257 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_ROUTE110
# 258 "data/maps/Route111/scripts.pory"
	doweather
# 259 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 0
# 260 "data/maps/Route111/scripts.pory"
	end
# 261 "data/maps/Route111/scripts.pory"

# 262 "data/maps/Route111/scripts.pory"
Route111_EventScript_SandstormTrigger::
# 263 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 264 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_DESERT
# 265 "data/maps/Route111/scripts.pory"
	doweather
# 266 "data/maps/Route111/scripts.pory"
	end
# 267 "data/maps/Route111/scripts.pory"

# 268 "data/maps/Route111/scripts.pory"
Route111_EventScript_Victor::
# 269 "data/maps/Route111/scripts.pory"
	lock
# 270 "data/maps/Route111/scripts.pory"
	faceplayer
# 271 "data/maps/Route111/scripts.pory"
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
# 272 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
# 273 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_BattleWinstrates
# 274 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
# 275 "data/maps/Route111/scripts.pory"
	release
# 276 "data/maps/Route111/scripts.pory"
	end
# 277 "data/maps/Route111/scripts.pory"

# 278 "data/maps/Route111/scripts.pory"
Route111_EventScript_BattleWinstrates::
# 279 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
# 280 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
# 281 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTOR, Common_Movement_WalkInPlaceFasterUp
# 282 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 283 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 284 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
# 285 "data/maps/Route111/scripts.pory"
	closemessage
# 286 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTOR, Route111_Movement_WinstrateEnterHouse
# 287 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 288 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICTOR
# 289 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 290 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 291 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 292 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 293 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VICTORIA
# 294 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateExitHouse
# 295 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 296 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 297 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
# 298 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
# 299 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Common_Movement_WalkInPlaceFasterUp
# 300 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 301 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 302 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
# 303 "data/maps/Route111/scripts.pory"
	closemessage
# 304 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateEnterHouse
# 305 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 306 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICTORIA
# 307 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 308 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 309 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 310 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 311 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VIVI
# 312 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateExitHouse
# 313 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 314 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 315 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
# 316 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
# 317 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Common_Movement_WalkInPlaceFasterUp
# 318 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 319 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 320 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
# 321 "data/maps/Route111/scripts.pory"
	closemessage
# 322 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateEnterHouse
# 323 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 324 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VIVI
# 325 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 326 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 327 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 328 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 329 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VICKY
# 330 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateExitHouse
# 331 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 332 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 333 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
# 334 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
# 335 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
# 336 "data/maps/Route111/scripts.pory"
	closemessage
# 337 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Common_Movement_WalkInPlaceFasterUp
# 338 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 339 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 340 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateEnterHouse
# 341 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 342 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICKY
# 343 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 344 "data/maps/Route111/scripts.pory"
	release
# 345 "data/maps/Route111/scripts.pory"
	end
# 346 "data/maps/Route111/scripts.pory"

# 347 "data/maps/Route111/scripts.pory"
Route111_EventScript_OpenWinstrateDoor::
# 348 "data/maps/Route111/scripts.pory"
	opendoor 13, 113
# 349 "data/maps/Route111/scripts.pory"
	waitdooranim
# 350 "data/maps/Route111/scripts.pory"
	return
# 351 "data/maps/Route111/scripts.pory"

# 352 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseWinstrateDoor::
# 353 "data/maps/Route111/scripts.pory"
	closedoor 13, 113
# 354 "data/maps/Route111/scripts.pory"
	waitdooranim
# 355 "data/maps/Route111/scripts.pory"
	return
# 356 "data/maps/Route111/scripts.pory"

# 357 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateEnterHouse:
# 358 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_up
# 359 "data/maps/Route111/scripts.pory"
	walk_up
# 360 "data/maps/Route111/scripts.pory"
	step_end
# 361 "data/maps/Route111/scripts.pory"

# 362 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateExitHouse:
# 363 "data/maps/Route111/scripts.pory"
	walk_down
# 364 "data/maps/Route111/scripts.pory"
	step_end
# 365 "data/maps/Route111/scripts.pory"

# 366 "data/maps/Route111/scripts.pory"
Route111_Movement_WaitForNextWinstrate:
# 367 "data/maps/Route111/scripts.pory"
	delay_16
# 368 "data/maps/Route111/scripts.pory"
	delay_16
# 369 "data/maps/Route111/scripts.pory"
	delay_16
# 370 "data/maps/Route111/scripts.pory"
	step_end
# 371 "data/maps/Route111/scripts.pory"

# 372 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSignMauville::
# 373 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
# 374 "data/maps/Route111/scripts.pory"
	end
# 375 "data/maps/Route111/scripts.pory"

# 376 "data/maps/Route111/scripts.pory"
Route111_EventScript_WinstrateHouseSign::
# 377 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
# 378 "data/maps/Route111/scripts.pory"
	end
# 379 "data/maps/Route111/scripts.pory"

# 380 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign112::
# 381 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
# 382 "data/maps/Route111/scripts.pory"
	end
# 383 "data/maps/Route111/scripts.pory"

# 384 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign113::
# 385 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
# 386 "data/maps/Route111/scripts.pory"
	end
# 387 "data/maps/Route111/scripts.pory"

# 388 "data/maps/Route111/scripts.pory"
Route111_EventScript_OldLadysRestStopSign::
# 389 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
# 390 "data/maps/Route111/scripts.pory"
	end
# 391 "data/maps/Route111/scripts.pory"

# 392 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerTipsSpAtkSpDef::
# 393 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
# 394 "data/maps/Route111/scripts.pory"
	end
# 395 "data/maps/Route111/scripts.pory"

# 396 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man1::
# 397 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
# 398 "data/maps/Route111/scripts.pory"
	end
# 399 "data/maps/Route111/scripts.pory"

# 400 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man2::
# 401 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
# 402 "data/maps/Route111/scripts.pory"
	end
# 403 "data/maps/Route111/scripts.pory"

# 404 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hiker::
# 405 "data/maps/Route111/scripts.pory"
	lock
# 406 "data/maps/Route111/scripts.pory"
	faceplayer
# 407 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 3, Route111_EventScript_HikerMirageTowerGone
# 408 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_HikerMirageTowerDisintegrated
# 409 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
# 410 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
# 411 "data/maps/Route111/scripts.pory"
	release
# 412 "data/maps/Route111/scripts.pory"
	end
# 413 "data/maps/Route111/scripts.pory"

# 414 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerGone::
# 415 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
# 416 "data/maps/Route111/scripts.pory"
	release
# 417 "data/maps/Route111/scripts.pory"
	end
# 418 "data/maps/Route111/scripts.pory"

# 419 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerDisintegrated::
# 420 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
# 421 "data/maps/Route111/scripts.pory"
	release
# 422 "data/maps/Route111/scripts.pory"
	end
# 423 "data/maps/Route111/scripts.pory"

# 424 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerVisible::
# 425 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
# 426 "data/maps/Route111/scripts.pory"
	release
# 427 "data/maps/Route111/scripts.pory"
	end
# 428 "data/maps/Route111/scripts.pory"

# 429 "data/maps/Route111/scripts.pory"
Route111_EventScript_RockSmashTipFatMan::
# 430 "data/maps/Route111/scripts.pory"
	lockall
# 431 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROCK_SMASH_MAN, Common_Movement_FacePlayer
# 432 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 433 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MauvilleUncleToldMeToTakeRockSmash, MSGBOX_DEFAULT
# 434 "data/maps/Route111/scripts.pory"
	closemessage
# 435 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROCK_SMASH_MAN, Common_Movement_FaceOriginalDirection
# 436 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 437 "data/maps/Route111/scripts.pory"
	releaseall
# 438 "data/maps/Route111/scripts.pory"
	end
# 439 "data/maps/Route111/scripts.pory"

# 440 "data/maps/Route111/scripts.pory"
Route111_EventScript_Drew::
# 441 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
# 442 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
# 443 "data/maps/Route111/scripts.pory"
	end
# 444 "data/maps/Route111/scripts.pory"

# 445 "data/maps/Route111/scripts.pory"
Route111_EventScript_Heidi::
# 446 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
# 447 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
# 448 "data/maps/Route111/scripts.pory"
	end
# 449 "data/maps/Route111/scripts.pory"

# 450 "data/maps/Route111/scripts.pory"
Route111_EventScript_Beau::
# 451 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
# 452 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
# 453 "data/maps/Route111/scripts.pory"
	end
# 454 "data/maps/Route111/scripts.pory"

# 455 "data/maps/Route111/scripts.pory"
Route111_EventScript_Becky::
# 456 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
# 457 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
# 458 "data/maps/Route111/scripts.pory"
	end
# 459 "data/maps/Route111/scripts.pory"

# 460 "data/maps/Route111/scripts.pory"
Route111_EventScript_Dusty::
# 461 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
# 462 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 463 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchDusty
# 464 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
# 465 "data/maps/Route111/scripts.pory"
	release
# 466 "data/maps/Route111/scripts.pory"
	end
# 467 "data/maps/Route111/scripts.pory"

# 468 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterDusty::
# 469 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 470 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 471 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
# 472 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_DUSTY_1
# 473 "data/maps/Route111/scripts.pory"
	release
# 474 "data/maps/Route111/scripts.pory"
	end
# 475 "data/maps/Route111/scripts.pory"

# 476 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchDusty::
# 477 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
# 478 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
# 479 "data/maps/Route111/scripts.pory"
	end
# 480 "data/maps/Route111/scripts.pory"

# 481 "data/maps/Route111/scripts.pory"
Route111_EventScript_Travis::
# 482 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
# 483 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
# 484 "data/maps/Route111/scripts.pory"
	end
# 485 "data/maps/Route111/scripts.pory"

# 486 "data/maps/Route111/scripts.pory"
Route111_EventScript_Irene::
# 487 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
# 488 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
# 489 "data/maps/Route111/scripts.pory"
	end
# 490 "data/maps/Route111/scripts.pory"

# 491 "data/maps/Route111/scripts.pory"
Route111_EventScript_Daisuke::
# 492 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
# 493 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
# 494 "data/maps/Route111/scripts.pory"
	end
# 495 "data/maps/Route111/scripts.pory"

# 496 "data/maps/Route111/scripts.pory"
Route111_EventScript_Wilton::
# 497 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
# 498 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 499 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchWilton
# 500 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
# 501 "data/maps/Route111/scripts.pory"
	release
# 502 "data/maps/Route111/scripts.pory"
	end
# 503 "data/maps/Route111/scripts.pory"

# 504 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterWilton::
# 505 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 506 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 507 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
# 508 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_WILTON_1
# 509 "data/maps/Route111/scripts.pory"
	release
# 510 "data/maps/Route111/scripts.pory"
	end
# 511 "data/maps/Route111/scripts.pory"

# 512 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchWilton::
# 513 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
# 514 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
# 515 "data/maps/Route111/scripts.pory"
	end
# 516 "data/maps/Route111/scripts.pory"

# 517 "data/maps/Route111/scripts.pory"
Route111_EventScript_Brooke::
# 518 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
# 519 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 520 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchBrooke
# 521 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
# 522 "data/maps/Route111/scripts.pory"
	release
# 523 "data/maps/Route111/scripts.pory"
	end
# 524 "data/maps/Route111/scripts.pory"

# 525 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterBrooke::
# 526 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 527 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 528 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
# 529 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_BROOKE_1
# 530 "data/maps/Route111/scripts.pory"
	release
# 531 "data/maps/Route111/scripts.pory"
	end
# 532 "data/maps/Route111/scripts.pory"

# 533 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchBrooke::
# 534 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
# 535 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
# 536 "data/maps/Route111/scripts.pory"
	end
# 537 "data/maps/Route111/scripts.pory"

# 538 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hayden::
# 539 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
# 540 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
# 541 "data/maps/Route111/scripts.pory"
	end
# 542 "data/maps/Route111/scripts.pory"

# 543 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bianca::
# 544 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BIANCA, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
# 545 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
# 546 "data/maps/Route111/scripts.pory"
	end
# 547 "data/maps/Route111/scripts.pory"

# 548 "data/maps/Route111/scripts.pory"
Route111_EventScript_Tyron::
# 549 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TYRON, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
# 550 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
# 551 "data/maps/Route111/scripts.pory"
	end
# 552 "data/maps/Route111/scripts.pory"

# 553 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celina::
# 554 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELINA, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
# 555 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
# 556 "data/maps/Route111/scripts.pory"
	end
# 557 "data/maps/Route111/scripts.pory"

# 558 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celia::
# 559 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELIA, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
# 560 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
# 561 "data/maps/Route111/scripts.pory"
	end
# 562 "data/maps/Route111/scripts.pory"

# 563 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bryan::
# 564 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
# 565 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
# 566 "data/maps/Route111/scripts.pory"
	end
# 567 "data/maps/Route111/scripts.pory"

# 568 "data/maps/Route111/scripts.pory"
Route111_EventScript_Branden::
# 569 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
# 570 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
# 571 "data/maps/Route111/scripts.pory"
	end
# 572 "data/maps/Route111/scripts.pory"

# 573 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerHillSign::
# 574 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
# 575 "data/maps/Route111/scripts.pory"
	end
# 576 "data/maps/Route111/scripts.pory"

# 577 "data/maps/Route111/scripts.pory"
Route111_Text_BattleOurFamily:
# 578 "data/maps/Route111/scripts.pory"
	.string "Hello! I take it you're a traveler.\p"
# 579 "data/maps/Route111/scripts.pory"
	.string "How's this? What do you say to taking\n"
# 580 "data/maps/Route111/scripts.pory"
	.string "on our family of four in a series of\l"
# 581 "data/maps/Route111/scripts.pory"
	.string "POKéMON battles?$"
# 582 "data/maps/Route111/scripts.pory"

# 583 "data/maps/Route111/scripts.pory"
Route111_Text_IsThatSo:
# 584 "data/maps/Route111/scripts.pory"
	.string "Is that so?\n"
# 585 "data/maps/Route111/scripts.pory"
	.string "Drop in, if you change your mind!$"
# 586 "data/maps/Route111/scripts.pory"

# 587 "data/maps/Route111/scripts.pory"
Route111_Text_VictorIntro:
# 588 "data/maps/Route111/scripts.pory"
	.string "That's the spirit! I like you!$"
# 589 "data/maps/Route111/scripts.pory"

# 590 "data/maps/Route111/scripts.pory"
Route111_Text_VictorDefeat:
# 591 "data/maps/Route111/scripts.pory"
	.string "Aiyah!\n"
# 592 "data/maps/Route111/scripts.pory"
	.string "You're a lot tougher than I expected!$"
# 593 "data/maps/Route111/scripts.pory"

# 594 "data/maps/Route111/scripts.pory"
Route111_Text_VictorPostBattle:
# 595 "data/maps/Route111/scripts.pory"
	.string "Hey, all!\n"
# 596 "data/maps/Route111/scripts.pory"
	.string "I've found a pretty strong TRAINER!$"
# 597 "data/maps/Route111/scripts.pory"

# 598 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaIntro:
# 599 "data/maps/Route111/scripts.pory"
	.string "Oh, my goodness! Aren't you young?\p"
# 600 "data/maps/Route111/scripts.pory"
	.string "You must be quite the TRAINER to beat\n"
# 601 "data/maps/Route111/scripts.pory"
	.string "my husband, though.\p"
# 602 "data/maps/Route111/scripts.pory"
	.string "It's my turn to battle now!$"
# 603 "data/maps/Route111/scripts.pory"

# 604 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaDefeat:
# 605 "data/maps/Route111/scripts.pory"
	.string "Oh, gosh!\n"
# 606 "data/maps/Route111/scripts.pory"
	.string "I can't get over how strong you are!$"
# 607 "data/maps/Route111/scripts.pory"

# 608 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaPostBattle:
# 609 "data/maps/Route111/scripts.pory"
	.string "There's a strong TRAINER here!\n"
# 610 "data/maps/Route111/scripts.pory"
	.string "This one's really strong!$"
# 611 "data/maps/Route111/scripts.pory"

# 612 "data/maps/Route111/scripts.pory"
Route111_Text_ViviIntro:
# 613 "data/maps/Route111/scripts.pory"
	.string "You're stronger than Mommy? Wow!\p"
# 614 "data/maps/Route111/scripts.pory"
	.string "But I'm strong, too!\n"
# 615 "data/maps/Route111/scripts.pory"
	.string "Really! Honestly!$"
# 616 "data/maps/Route111/scripts.pory"

# 617 "data/maps/Route111/scripts.pory"
Route111_Text_ViviDefeat:
# 618 "data/maps/Route111/scripts.pory"
	.string "Huh? Did I just lose?$"
# 619 "data/maps/Route111/scripts.pory"

# 620 "data/maps/Route111/scripts.pory"
Route111_Text_ViviPostBattle:
# 621 "data/maps/Route111/scripts.pory"
	.string "This stinks…\p"
# 622 "data/maps/Route111/scripts.pory"
	.string "…Snivel… Grandma!$"
# 623 "data/maps/Route111/scripts.pory"

# 624 "data/maps/Route111/scripts.pory"
Route111_Text_VickyIntro:
# 625 "data/maps/Route111/scripts.pory"
	.string "How dare you make my granddaughter\n"
# 626 "data/maps/Route111/scripts.pory"
	.string "cry!\p"
# 627 "data/maps/Route111/scripts.pory"
	.string "For that, I'm going to smack you!\n"
# 628 "data/maps/Route111/scripts.pory"
	.string "Prepare to lose!$"
# 629 "data/maps/Route111/scripts.pory"

# 630 "data/maps/Route111/scripts.pory"
Route111_Text_VickyDefeat:
# 631 "data/maps/Route111/scripts.pory"
	.string "Kwah! You are strong…\n"
# 632 "data/maps/Route111/scripts.pory"
	.string "My granddaughter was right…$"
# 633 "data/maps/Route111/scripts.pory"

# 634 "data/maps/Route111/scripts.pory"
Route111_Text_VickyPostBattle:
# 635 "data/maps/Route111/scripts.pory"
	.string "If you're not in any hurry,\n"
# 636 "data/maps/Route111/scripts.pory"
	.string "visit with us awhile.$"
# 637 "data/maps/Route111/scripts.pory"

# 638 "data/maps/Route111/scripts.pory"
Route111_Text_ToughToKeepWinningUpTheRanks:
# 639 "data/maps/Route111/scripts.pory"
	.string "If you don't raise your POKéMON some\n"
# 640 "data/maps/Route111/scripts.pory"
	.string "more, it could be tough to keep winning\l"
# 641 "data/maps/Route111/scripts.pory"
	.string "up through the ranks.\p"
# 642 "data/maps/Route111/scripts.pory"
	.string "I've heard the POKéMON LEAGUE's\n"
# 643 "data/maps/Route111/scripts.pory"
	.string "ELITE FOUR are far stronger than\l"
# 644 "data/maps/Route111/scripts.pory"
	.string "any GYM LEADER.$"
# 645 "data/maps/Route111/scripts.pory"

# 646 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateFamilyDestroyedMe:
# 647 "data/maps/Route111/scripts.pory"
	.string "I challenged the WINSTRATE family,\n"
# 648 "data/maps/Route111/scripts.pory"
	.string "but four matches in a row is tough\l"
# 649 "data/maps/Route111/scripts.pory"
	.string "going… They destroyed me.$"
# 650 "data/maps/Route111/scripts.pory"

# 651 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSignMauville:
# 652 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 653 "data/maps/Route111/scripts.pory"
	.string "{DOWN_ARROW} MAUVILLE CITY$"
# 654 "data/maps/Route111/scripts.pory"

# 655 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateHouseSign:
# 656 "data/maps/Route111/scripts.pory"
	.string "“Our family's hearts beat as one!”\n"
# 657 "data/maps/Route111/scripts.pory"
	.string "THE WINSTRATE'S HOUSE$"
# 658 "data/maps/Route111/scripts.pory"

# 659 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign112:
# 660 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 661 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 112$"
# 662 "data/maps/Route111/scripts.pory"

# 663 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign113:
# 664 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 665 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 113$"
# 666 "data/maps/Route111/scripts.pory"

# 667 "data/maps/Route111/scripts.pory"
Route111_Text_OldLadysRestStopSign:
# 668 "data/maps/Route111/scripts.pory"
	.string "OLD LADY'S REST STOP\n"
# 669 "data/maps/Route111/scripts.pory"
	.string "“Come in and rest your tired bones.”$"
# 670 "data/maps/Route111/scripts.pory"

# 671 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerTipsSpAtkSpDef:
# 672 "data/maps/Route111/scripts.pory"
	.string "TRAINER TIPS\p"
# 673 "data/maps/Route111/scripts.pory"
	.string "One of the indicators of a POKéMON's\n"
# 674 "data/maps/Route111/scripts.pory"
	.string "powerfulness is SP. ATK. It stands for\l"
# 675 "data/maps/Route111/scripts.pory"
	.string "“SPECIAL ATTACK.”\p"
# 676 "data/maps/Route111/scripts.pory"
	.string "Likewise, SP. DEF stands for “SPECIAL\n"
# 677 "data/maps/Route111/scripts.pory"
	.string "DEFENSE.”$"
# 678 "data/maps/Route111/scripts.pory"

# 679 "data/maps/Route111/scripts.pory"
Route111_Text_ShouldBeMirageTowerAroundHere:
# 680 "data/maps/Route111/scripts.pory"
	.string "There should be a tower made of sand\n"
# 681 "data/maps/Route111/scripts.pory"
	.string "around here somewhere.\p"
# 682 "data/maps/Route111/scripts.pory"
	.string "But for some reason, it can be seen\n"
# 683 "data/maps/Route111/scripts.pory"
	.string "sometimes, and sometimes not.\p"
# 684 "data/maps/Route111/scripts.pory"
	.string "That's why I call it the MIRAGE TOWER.$"
# 685 "data/maps/Route111/scripts.pory"

# 686 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerClearlyVisible:
# 687 "data/maps/Route111/scripts.pory"
	.string "I see it!\n"
# 688 "data/maps/Route111/scripts.pory"
	.string "The tower of sand!\p"
# 689 "data/maps/Route111/scripts.pory"
	.string "The sand tower they called a mirage\n"
# 690 "data/maps/Route111/scripts.pory"
	.string "is clearly visible!\p"
# 691 "data/maps/Route111/scripts.pory"
	.string "But it looks so fragile…\n"
# 692 "data/maps/Route111/scripts.pory"
	.string "It could crumble away anytime…\p"
# 693 "data/maps/Route111/scripts.pory"
	.string "I want to go inside it, but I can't\n"
# 694 "data/maps/Route111/scripts.pory"
	.string "get my courage up for it…$"
# 695 "data/maps/Route111/scripts.pory"

# 696 "data/maps/Route111/scripts.pory"
Route111_Text_ThatWasShockingSandRainedDown:
# 697 "data/maps/Route111/scripts.pory"
	.string "Whoa…\n"
# 698 "data/maps/Route111/scripts.pory"
	.string "That was shocking.\p"
# 699 "data/maps/Route111/scripts.pory"
	.string "Sand rained down in chunks all of\n"
# 700 "data/maps/Route111/scripts.pory"
	.string "a sudden.\p"
# 701 "data/maps/Route111/scripts.pory"
	.string "What was it like inside?\n"
# 702 "data/maps/Route111/scripts.pory"
	.string "Were there sandy ghosts and such?$"
# 703 "data/maps/Route111/scripts.pory"

# 704 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerHasntBeenSeenSince:
# 705 "data/maps/Route111/scripts.pory"
	.string "Since I spoke to you, the tower of sand\n"
# 706 "data/maps/Route111/scripts.pory"
	.string "hasn't been seen.\p"
# 707 "data/maps/Route111/scripts.pory"
	.string "Perhaps it really was\n"
# 708 "data/maps/Route111/scripts.pory"
	.string "the MIRAGE TOWER…$"
# 709 "data/maps/Route111/scripts.pory"

# 710 "data/maps/Route111/scripts.pory"
Route111_Text_ClawFossilDisappeared:
# 711 "data/maps/Route111/scripts.pory"
	.string "The CLAW FOSSIL disappeared into\n"
# 712 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 713 "data/maps/Route111/scripts.pory"

# 714 "data/maps/Route111/scripts.pory"
Route111_Text_RootFossilDisappeared:
# 715 "data/maps/Route111/scripts.pory"
	.string "The ROOT FOSSIL disappeared into\n"
# 716 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 717 "data/maps/Route111/scripts.pory"

# 718 "data/maps/Route111/scripts.pory"
Route111_Text_MauvilleUncleToldMeToTakeRockSmash:
# 719 "data/maps/Route111/scripts.pory"
	.string "Oh, no!\p"
# 720 "data/maps/Route111/scripts.pory"
	.string "My uncle in MAUVILLE told me to take\n"
# 721 "data/maps/Route111/scripts.pory"
	.string "ROCK SMASH with me if I was going to\l"
# 722 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111!\p"
# 723 "data/maps/Route111/scripts.pory"
	.string "My uncle? He lives across from\n"
# 724 "data/maps/Route111/scripts.pory"
	.string "the bike shop in MAUVILLE.$"
# 725 "data/maps/Route111/scripts.pory"

# 726 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerHillSign:
# 727 "data/maps/Route111/scripts.pory"
	.string "{RIGHT_ARROW} TRAINER HILL ENTRANCE\p"
# 728 "data/maps/Route111/scripts.pory"
	.string "“Scale the heights, you hot-blooded\n"
# 729 "data/maps/Route111/scripts.pory"
	.string "TRAINERS!”$"
