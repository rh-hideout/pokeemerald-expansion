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
	.byte 0
# 14 "data/maps/Route111/scripts.pory"

# 15 "data/maps/Route111/scripts.pory"
Route111_OnLoad:
# 16 "data/maps/Route111/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_CloseDesertRuins
# 17 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_ShowTemporaryMirageTower
# 18 "data/maps/Route111/scripts.pory"
	end
# 19 "data/maps/Route111/scripts.pory"

# 20 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseDesertRuins::
# 21 "data/maps/Route111/scripts.pory"
	setmetatile 29, 86, METATILE_General_RockWall_RockBase, TRUE
# 22 "data/maps/Route111/scripts.pory"
	setmetatile 29, 87, METATILE_General_RockWall_SandBase, TRUE
# 23 "data/maps/Route111/scripts.pory"
	return
# 24 "data/maps/Route111/scripts.pory"

# 25 "data/maps/Route111/scripts.pory"
@ Show Mirage Tower just prior to disintegration. Mirage Tower is otherwise handled by the map layout
# 26 "data/maps/Route111/scripts.pory"
Route111_EventScript_ShowTemporaryMirageTower::
# 27 "data/maps/Route111/scripts.pory"
	setmetatile 18, 53, METATILE_Mauville_MirageTower_Tile0, FALSE
# 28 "data/maps/Route111/scripts.pory"
	setmetatile 19, 53, METATILE_Mauville_MirageTower_Tile1, FALSE
# 29 "data/maps/Route111/scripts.pory"
	setmetatile 20, 53, METATILE_Mauville_MirageTower_Tile2, FALSE
# 30 "data/maps/Route111/scripts.pory"
	setmetatile 18, 54, METATILE_Mauville_MirageTower_Tile3, FALSE
# 31 "data/maps/Route111/scripts.pory"
	setmetatile 19, 54, METATILE_Mauville_MirageTower_Tile4, FALSE
# 32 "data/maps/Route111/scripts.pory"
	setmetatile 20, 54, METATILE_Mauville_MirageTower_Tile5, FALSE
# 33 "data/maps/Route111/scripts.pory"
	setmetatile 18, 55, METATILE_Mauville_MirageTower_Tile6, FALSE
# 34 "data/maps/Route111/scripts.pory"
	setmetatile 19, 55, METATILE_Mauville_MirageTower_Tile7, FALSE
# 35 "data/maps/Route111/scripts.pory"
	setmetatile 20, 55, METATILE_Mauville_MirageTower_Tile8, FALSE
# 36 "data/maps/Route111/scripts.pory"
	setmetatile 18, 56, METATILE_Mauville_MirageTower_Tile9, FALSE
# 37 "data/maps/Route111/scripts.pory"
	setmetatile 19, 56, METATILE_Mauville_MirageTower_TileA, FALSE
# 38 "data/maps/Route111/scripts.pory"
	setmetatile 20, 56, METATILE_Mauville_MirageTower_TileB, FALSE
# 39 "data/maps/Route111/scripts.pory"
	setmetatile 18, 57, METATILE_Mauville_MirageTower_TileC, FALSE
# 40 "data/maps/Route111/scripts.pory"
	setmetatile 19, 57, METATILE_Mauville_MirageTower_TileD, FALSE
# 41 "data/maps/Route111/scripts.pory"
	setmetatile 20, 57, METATILE_Mauville_MirageTower_TileE, FALSE
# 42 "data/maps/Route111/scripts.pory"
	setmetatile 18, 58, METATILE_Mauville_MirageTower_TileF, FALSE
# 43 "data/maps/Route111/scripts.pory"
	setmetatile 19, 58, METATILE_Mauville_MirageTower_Tile10, FALSE
# 44 "data/maps/Route111/scripts.pory"
	setmetatile 20, 58, METATILE_Mauville_MirageTower_Tile11, FALSE
# 45 "data/maps/Route111/scripts.pory"
	return
# 46 "data/maps/Route111/scripts.pory"

# 47 "data/maps/Route111/scripts.pory"
Route111_OnTransition:
# 48 "data/maps/Route111/scripts.pory"
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
# 49 "data/maps/Route111/scripts.pory"
	special SetMirageTowerVisibility
# 50 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_SetFallingPlayerGfx
# 51 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CheckSetSandstorm
# 52 "data/maps/Route111/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 53 "data/maps/Route111/scripts.pory"
	goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated
# 54 "data/maps/Route111/scripts.pory"
	end
# 55 "data/maps/Route111/scripts.pory"

# 56 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfx::
# 57 "data/maps/Route111/scripts.pory"
	checkplayergender
# 58 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route111_EventScript_SetFallingPlayerGfxMale
# 59 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route111_EventScript_SetFallingPlayerGfxFemale
# 60 "data/maps/Route111/scripts.pory"
	return
# 61 "data/maps/Route111/scripts.pory"

# 62 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxMale::
# 63 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 64 "data/maps/Route111/scripts.pory"
	return
# 65 "data/maps/Route111/scripts.pory"

# 66 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxFemale::
# 67 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 68 "data/maps/Route111/scripts.pory"
	return
# 69 "data/maps/Route111/scripts.pory"

# 70 "data/maps/Route111/scripts.pory"
Route111_EventScript_CheckSetSandstorm::
# 71 "data/maps/Route111/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 72 "data/maps/Route111/scripts.pory"
	goto_if_lt VAR_TEMP_1, 34, Route111_EventScript_EndCheckSetSandstorm
# 73 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_1, 107, Route111_EventScript_EndCheckSetSandstorm
# 74 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_1, 72, Route111_EventScript_SetSandstorm
# 75 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_0, 2000, Route111_EventScript_EndCheckSetSandstorm
# 76 "data/maps/Route111/scripts.pory"
	goto_if_lt VAR_TEMP_0, 8, Route111_EventScript_EndCheckSetSandstorm
# 77 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetSandstorm::
# 78 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 79 "data/maps/Route111/scripts.pory"
Route111_EventScript_EndCheckSetSandstorm::
# 80 "data/maps/Route111/scripts.pory"
	return
# 81 "data/maps/Route111/scripts.pory"

# 82 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetWinstratesNotDefeated::
# 83 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
# 84 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
# 85 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
# 86 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
# 87 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTOR
# 88 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTORIA
# 89 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VIVI
# 90 "data/maps/Route111/scripts.pory"
	end
# 91 "data/maps/Route111/scripts.pory"

# 92 "data/maps/Route111/scripts.pory"
@ Unused
# 93 "data/maps/Route111/scripts.pory"
Route111_Movement_PlayerFall::
# 94 "data/maps/Route111/scripts.pory"
	lock_anim
# 95 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 96 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 97 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 98 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 99 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 100 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 101 "data/maps/Route111/scripts.pory"
	step_end
# 102 "data/maps/Route111/scripts.pory"

# 103 "data/maps/Route111/scripts.pory"
Route111_EventScript_Girl::
# 104 "data/maps/Route111/scripts.pory"
	lock
# 105 "data/maps/Route111/scripts.pory"
	faceplayer
# 106 "data/maps/Route111/scripts.pory"
	dotimebasedevents
# 107 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
# 108 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
# 109 "data/maps/Route111/scripts.pory"
	giveitem ITEM_RAZZ_BERRY
# 110 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 111 "data/maps/Route111/scripts.pory"
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
# 112 "data/maps/Route111/scripts.pory"
	special GetPlayerBigGuyGirlString
# 113 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
# 114 "data/maps/Route111/scripts.pory"
	release
# 115 "data/maps/Route111/scripts.pory"
	end
# 116 "data/maps/Route111/scripts.pory"

# 117 "data/maps/Route111/scripts.pory"
Route111_EventScript_ReceivedBerry::
# 118 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
# 119 "data/maps/Route111/scripts.pory"
	release
# 120 "data/maps/Route111/scripts.pory"
	end
# 121 "data/maps/Route111/scripts.pory"

# 122 "data/maps/Route111/scripts.pory"
@ Unused
# 123 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerUp::
# 124 "data/maps/Route111/scripts.pory"
	lockall
# 125 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 0
# 126 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 127 "data/maps/Route111/scripts.pory"
	end
# 128 "data/maps/Route111/scripts.pory"

# 129 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerDown::
# 130 "data/maps/Route111/scripts.pory"
	lockall
# 131 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 1
# 132 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 133 "data/maps/Route111/scripts.pory"
	end
# 134 "data/maps/Route111/scripts.pory"

# 135 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerLeft::
# 136 "data/maps/Route111/scripts.pory"
	lockall
# 137 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 2
# 138 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 139 "data/maps/Route111/scripts.pory"
	end
# 140 "data/maps/Route111/scripts.pory"

# 141 "data/maps/Route111/scripts.pory"
@ Unused
# 142 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerRight::
# 143 "data/maps/Route111/scripts.pory"
	lockall
# 144 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 3
# 145 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 146 "data/maps/Route111/scripts.pory"
	end
# 147 "data/maps/Route111/scripts.pory"

# 148 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTrigger::
# 149 "data/maps/Route111/scripts.pory"
	checkitem ITEM_GO_GOGGLES
# 150 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_PreventRouteAccess
# 151 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 1
# 152 "data/maps/Route111/scripts.pory"
	releaseall
# 153 "data/maps/Route111/scripts.pory"
	end
# 154 "data/maps/Route111/scripts.pory"

# 155 "data/maps/Route111/scripts.pory"
Route111_EventScript_PreventRouteAccess::
# 156 "data/maps/Route111/scripts.pory"
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
# 157 "data/maps/Route111/scripts.pory"
	closemessage
# 158 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 0, Route111_EventScript_PushUpFromRoute
# 159 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 1, Route111_EventScript_PushDownFromRoute
# 160 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 2, Route111_EventScript_PushLeftFromRoute
# 161 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 3, Route111_EventScript_PushRightFromRoute
# 162 "data/maps/Route111/scripts.pory"
	releaseall
# 163 "data/maps/Route111/scripts.pory"
	end
# 164 "data/maps/Route111/scripts.pory"

# 165 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushUpFromRoute::
# 166 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushUpFromRoute
# 167 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 168 "data/maps/Route111/scripts.pory"
	return
# 169 "data/maps/Route111/scripts.pory"

# 170 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushDownFromRoute::
# 171 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushDownFromRoute
# 172 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 173 "data/maps/Route111/scripts.pory"
	return
# 174 "data/maps/Route111/scripts.pory"

# 175 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushLeftFromRoute::
# 176 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushLeftFromRoute
# 177 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 178 "data/maps/Route111/scripts.pory"
	return
# 179 "data/maps/Route111/scripts.pory"

# 180 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushRightFromRoute::
# 181 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushRightFromRoute
# 182 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 183 "data/maps/Route111/scripts.pory"
	return
# 184 "data/maps/Route111/scripts.pory"

# 185 "data/maps/Route111/scripts.pory"
Route111_Movement_PushUpFromRoute:
# 186 "data/maps/Route111/scripts.pory"
	walk_up
# 187 "data/maps/Route111/scripts.pory"
	step_end
# 188 "data/maps/Route111/scripts.pory"

# 189 "data/maps/Route111/scripts.pory"
Route111_Movement_PushDownFromRoute:
# 190 "data/maps/Route111/scripts.pory"
	walk_down
# 191 "data/maps/Route111/scripts.pory"
	step_end
# 192 "data/maps/Route111/scripts.pory"

# 193 "data/maps/Route111/scripts.pory"
Route111_Movement_PushLeftFromRoute:
# 194 "data/maps/Route111/scripts.pory"
	walk_left
# 195 "data/maps/Route111/scripts.pory"
	step_end
# 196 "data/maps/Route111/scripts.pory"

# 197 "data/maps/Route111/scripts.pory"
Route111_Movement_PushRightFromRoute:
# 198 "data/maps/Route111/scripts.pory"
	walk_right
# 199 "data/maps/Route111/scripts.pory"
	step_end
# 200 "data/maps/Route111/scripts.pory"

# 201 "data/maps/Route111/scripts.pory"
Route111_EventScript_SunTrigger::
# 202 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SUNNY
# 203 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_ROUTE110
# 204 "data/maps/Route111/scripts.pory"
	doweather
# 205 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 0
# 206 "data/maps/Route111/scripts.pory"
	end
# 207 "data/maps/Route111/scripts.pory"

# 208 "data/maps/Route111/scripts.pory"
Route111_EventScript_SandstormTrigger::
# 209 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 210 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_DESERT
# 211 "data/maps/Route111/scripts.pory"
	doweather
# 212 "data/maps/Route111/scripts.pory"
	end
# 213 "data/maps/Route111/scripts.pory"

# 214 "data/maps/Route111/scripts.pory"
Route111_EventScript_Victor::
# 215 "data/maps/Route111/scripts.pory"
	lock
# 216 "data/maps/Route111/scripts.pory"
	faceplayer
# 217 "data/maps/Route111/scripts.pory"
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
# 218 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
# 219 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_BattleWinstrates
# 220 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
# 221 "data/maps/Route111/scripts.pory"
	release
# 222 "data/maps/Route111/scripts.pory"
	end
# 223 "data/maps/Route111/scripts.pory"

# 224 "data/maps/Route111/scripts.pory"
Route111_EventScript_BattleWinstrates::
# 225 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
# 226 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
# 227 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTOR, Common_Movement_WalkInPlaceFasterUp
# 228 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 229 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 230 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
# 231 "data/maps/Route111/scripts.pory"
	closemessage
# 232 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTOR, Route111_Movement_WinstrateEnterHouse
# 233 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 234 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICTOR
# 235 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 236 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 237 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 238 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 239 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VICTORIA
# 240 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateExitHouse
# 241 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 242 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 243 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
# 244 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
# 245 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Common_Movement_WalkInPlaceFasterUp
# 246 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 247 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 248 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
# 249 "data/maps/Route111/scripts.pory"
	closemessage
# 250 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateEnterHouse
# 251 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 252 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICTORIA
# 253 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 254 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 255 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 256 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 257 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VIVI
# 258 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateExitHouse
# 259 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 260 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 261 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
# 262 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
# 263 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Common_Movement_WalkInPlaceFasterUp
# 264 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 265 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 266 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
# 267 "data/maps/Route111/scripts.pory"
	closemessage
# 268 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateEnterHouse
# 269 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 270 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VIVI
# 271 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 272 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 273 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 274 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 275 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VICKY
# 276 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateExitHouse
# 277 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 278 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 279 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
# 280 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
# 281 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
# 282 "data/maps/Route111/scripts.pory"
	closemessage
# 283 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Common_Movement_WalkInPlaceFasterUp
# 284 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 285 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 286 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateEnterHouse
# 287 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 288 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICKY
# 289 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 290 "data/maps/Route111/scripts.pory"
	release
# 291 "data/maps/Route111/scripts.pory"
	end
# 292 "data/maps/Route111/scripts.pory"

# 293 "data/maps/Route111/scripts.pory"
Route111_EventScript_OpenWinstrateDoor::
# 294 "data/maps/Route111/scripts.pory"
	opendoor 13, 113
# 295 "data/maps/Route111/scripts.pory"
	waitdooranim
# 296 "data/maps/Route111/scripts.pory"
	return
# 297 "data/maps/Route111/scripts.pory"

# 298 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseWinstrateDoor::
# 299 "data/maps/Route111/scripts.pory"
	closedoor 13, 113
# 300 "data/maps/Route111/scripts.pory"
	waitdooranim
# 301 "data/maps/Route111/scripts.pory"
	return
# 302 "data/maps/Route111/scripts.pory"

# 303 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateEnterHouse:
# 304 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_up
# 305 "data/maps/Route111/scripts.pory"
	walk_up
# 306 "data/maps/Route111/scripts.pory"
	step_end
# 307 "data/maps/Route111/scripts.pory"

# 308 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateExitHouse:
# 309 "data/maps/Route111/scripts.pory"
	walk_down
# 310 "data/maps/Route111/scripts.pory"
	step_end
# 311 "data/maps/Route111/scripts.pory"

# 312 "data/maps/Route111/scripts.pory"
Route111_Movement_WaitForNextWinstrate:
# 313 "data/maps/Route111/scripts.pory"
	delay_16
# 314 "data/maps/Route111/scripts.pory"
	delay_16
# 315 "data/maps/Route111/scripts.pory"
	delay_16
# 316 "data/maps/Route111/scripts.pory"
	step_end
# 317 "data/maps/Route111/scripts.pory"

# 318 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSignMauville::
# 319 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
# 320 "data/maps/Route111/scripts.pory"
	end
# 321 "data/maps/Route111/scripts.pory"

# 322 "data/maps/Route111/scripts.pory"
Route111_EventScript_WinstrateHouseSign::
# 323 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
# 324 "data/maps/Route111/scripts.pory"
	end
# 325 "data/maps/Route111/scripts.pory"

# 326 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign112::
# 327 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
# 328 "data/maps/Route111/scripts.pory"
	end
# 329 "data/maps/Route111/scripts.pory"

# 330 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign113::
# 331 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
# 332 "data/maps/Route111/scripts.pory"
	end
# 333 "data/maps/Route111/scripts.pory"

# 334 "data/maps/Route111/scripts.pory"
Route111_EventScript_OldLadysRestStopSign::
# 335 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
# 336 "data/maps/Route111/scripts.pory"
	end
# 337 "data/maps/Route111/scripts.pory"

# 338 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerTipsSpAtkSpDef::
# 339 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
# 340 "data/maps/Route111/scripts.pory"
	end
# 341 "data/maps/Route111/scripts.pory"

# 342 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man1::
# 343 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
# 344 "data/maps/Route111/scripts.pory"
	end
# 345 "data/maps/Route111/scripts.pory"

# 346 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man2::
# 347 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
# 348 "data/maps/Route111/scripts.pory"
	end
# 349 "data/maps/Route111/scripts.pory"

# 350 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hiker::
# 351 "data/maps/Route111/scripts.pory"
	lock
# 352 "data/maps/Route111/scripts.pory"
	faceplayer
# 353 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 3, Route111_EventScript_HikerMirageTowerGone
# 354 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_HikerMirageTowerDisintegrated
# 355 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
# 356 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
# 357 "data/maps/Route111/scripts.pory"
	release
# 358 "data/maps/Route111/scripts.pory"
	end
# 359 "data/maps/Route111/scripts.pory"

# 360 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerGone::
# 361 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
# 362 "data/maps/Route111/scripts.pory"
	release
# 363 "data/maps/Route111/scripts.pory"
	end
# 364 "data/maps/Route111/scripts.pory"

# 365 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerDisintegrated::
# 366 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
# 367 "data/maps/Route111/scripts.pory"
	release
# 368 "data/maps/Route111/scripts.pory"
	end
# 369 "data/maps/Route111/scripts.pory"

# 370 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerVisible::
# 371 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
# 372 "data/maps/Route111/scripts.pory"
	release
# 373 "data/maps/Route111/scripts.pory"
	end
# 374 "data/maps/Route111/scripts.pory"

# 375 "data/maps/Route111/scripts.pory"
Route111_EventScript_RockSmashTipFatMan::
# 376 "data/maps/Route111/scripts.pory"
	lockall
# 377 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROCK_SMASH_MAN, Common_Movement_FacePlayer
# 378 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 379 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MauvilleUncleToldMeToTakeRockSmash, MSGBOX_DEFAULT
# 380 "data/maps/Route111/scripts.pory"
	closemessage
# 381 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROCK_SMASH_MAN, Common_Movement_FaceOriginalDirection
# 382 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 383 "data/maps/Route111/scripts.pory"
	releaseall
# 384 "data/maps/Route111/scripts.pory"
	end
# 385 "data/maps/Route111/scripts.pory"

# 386 "data/maps/Route111/scripts.pory"
Route111_EventScript_Drew::
# 387 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
# 388 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
# 389 "data/maps/Route111/scripts.pory"
	end
# 390 "data/maps/Route111/scripts.pory"

# 391 "data/maps/Route111/scripts.pory"
Route111_EventScript_Heidi::
# 392 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
# 393 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
# 394 "data/maps/Route111/scripts.pory"
	end
# 395 "data/maps/Route111/scripts.pory"

# 396 "data/maps/Route111/scripts.pory"
Route111_EventScript_Beau::
# 397 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
# 398 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
# 399 "data/maps/Route111/scripts.pory"
	end
# 400 "data/maps/Route111/scripts.pory"

# 401 "data/maps/Route111/scripts.pory"
Route111_EventScript_Becky::
# 402 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
# 403 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
# 404 "data/maps/Route111/scripts.pory"
	end
# 405 "data/maps/Route111/scripts.pory"

# 406 "data/maps/Route111/scripts.pory"
Route111_EventScript_Dusty::
# 407 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
# 408 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 409 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchDusty
# 410 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
# 411 "data/maps/Route111/scripts.pory"
	release
# 412 "data/maps/Route111/scripts.pory"
	end
# 413 "data/maps/Route111/scripts.pory"

# 414 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterDusty::
# 415 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 416 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 417 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
# 418 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_DUSTY_1
# 419 "data/maps/Route111/scripts.pory"
	release
# 420 "data/maps/Route111/scripts.pory"
	end
# 421 "data/maps/Route111/scripts.pory"

# 422 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchDusty::
# 423 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
# 424 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
# 425 "data/maps/Route111/scripts.pory"
	end
# 426 "data/maps/Route111/scripts.pory"

# 427 "data/maps/Route111/scripts.pory"
Route111_EventScript_Travis::
# 428 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
# 429 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
# 430 "data/maps/Route111/scripts.pory"
	end
# 431 "data/maps/Route111/scripts.pory"

# 432 "data/maps/Route111/scripts.pory"
Route111_EventScript_Irene::
# 433 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
# 434 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
# 435 "data/maps/Route111/scripts.pory"
	end
# 436 "data/maps/Route111/scripts.pory"

# 437 "data/maps/Route111/scripts.pory"
Route111_EventScript_Daisuke::
# 438 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
# 439 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
# 440 "data/maps/Route111/scripts.pory"
	end
# 441 "data/maps/Route111/scripts.pory"

# 442 "data/maps/Route111/scripts.pory"
Route111_EventScript_Wilton::
# 443 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
# 444 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 445 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchWilton
# 446 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
# 447 "data/maps/Route111/scripts.pory"
	release
# 448 "data/maps/Route111/scripts.pory"
	end
# 449 "data/maps/Route111/scripts.pory"

# 450 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterWilton::
# 451 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 452 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 453 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
# 454 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_WILTON_1
# 455 "data/maps/Route111/scripts.pory"
	release
# 456 "data/maps/Route111/scripts.pory"
	end
# 457 "data/maps/Route111/scripts.pory"

# 458 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchWilton::
# 459 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
# 460 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
# 461 "data/maps/Route111/scripts.pory"
	end
# 462 "data/maps/Route111/scripts.pory"

# 463 "data/maps/Route111/scripts.pory"
Route111_EventScript_Brooke::
# 464 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
# 465 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 466 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchBrooke
# 467 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
# 468 "data/maps/Route111/scripts.pory"
	release
# 469 "data/maps/Route111/scripts.pory"
	end
# 470 "data/maps/Route111/scripts.pory"

# 471 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterBrooke::
# 472 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 473 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 474 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
# 475 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_BROOKE_1
# 476 "data/maps/Route111/scripts.pory"
	release
# 477 "data/maps/Route111/scripts.pory"
	end
# 478 "data/maps/Route111/scripts.pory"

# 479 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchBrooke::
# 480 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
# 481 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
# 482 "data/maps/Route111/scripts.pory"
	end
# 483 "data/maps/Route111/scripts.pory"

# 484 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hayden::
# 485 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
# 486 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
# 487 "data/maps/Route111/scripts.pory"
	end
# 488 "data/maps/Route111/scripts.pory"

# 489 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bianca::
# 490 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BIANCA, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
# 491 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
# 492 "data/maps/Route111/scripts.pory"
	end
# 493 "data/maps/Route111/scripts.pory"

# 494 "data/maps/Route111/scripts.pory"
Route111_EventScript_Tyron::
# 495 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TYRON, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
# 496 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
# 497 "data/maps/Route111/scripts.pory"
	end
# 498 "data/maps/Route111/scripts.pory"

# 499 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celina::
# 500 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELINA, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
# 501 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
# 502 "data/maps/Route111/scripts.pory"
	end
# 503 "data/maps/Route111/scripts.pory"

# 504 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celia::
# 505 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELIA, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
# 506 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
# 507 "data/maps/Route111/scripts.pory"
	end
# 508 "data/maps/Route111/scripts.pory"

# 509 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bryan::
# 510 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
# 511 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
# 512 "data/maps/Route111/scripts.pory"
	end
# 513 "data/maps/Route111/scripts.pory"

# 514 "data/maps/Route111/scripts.pory"
Route111_EventScript_Branden::
# 515 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
# 516 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
# 517 "data/maps/Route111/scripts.pory"
	end
# 518 "data/maps/Route111/scripts.pory"

# 519 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerHillSign::
# 520 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
# 521 "data/maps/Route111/scripts.pory"
	end
# 522 "data/maps/Route111/scripts.pory"

# 523 "data/maps/Route111/scripts.pory"
Route111_Text_BattleOurFamily:
# 524 "data/maps/Route111/scripts.pory"
	.string "Hello! I take it you're a traveler.\p"
# 525 "data/maps/Route111/scripts.pory"
	.string "How's this? What do you say to taking\n"
# 526 "data/maps/Route111/scripts.pory"
	.string "on our family of four in a series of\l"
# 527 "data/maps/Route111/scripts.pory"
	.string "POKéMON battles?$"
# 528 "data/maps/Route111/scripts.pory"

# 529 "data/maps/Route111/scripts.pory"
Route111_Text_IsThatSo:
# 530 "data/maps/Route111/scripts.pory"
	.string "Is that so?\n"
# 531 "data/maps/Route111/scripts.pory"
	.string "Drop in, if you change your mind!$"
# 532 "data/maps/Route111/scripts.pory"

# 533 "data/maps/Route111/scripts.pory"
Route111_Text_VictorIntro:
# 534 "data/maps/Route111/scripts.pory"
	.string "That's the spirit! I like you!$"
# 535 "data/maps/Route111/scripts.pory"

# 536 "data/maps/Route111/scripts.pory"
Route111_Text_VictorDefeat:
# 537 "data/maps/Route111/scripts.pory"
	.string "Aiyah!\n"
# 538 "data/maps/Route111/scripts.pory"
	.string "You're a lot tougher than I expected!$"
# 539 "data/maps/Route111/scripts.pory"

# 540 "data/maps/Route111/scripts.pory"
Route111_Text_VictorPostBattle:
# 541 "data/maps/Route111/scripts.pory"
	.string "Hey, all!\n"
# 542 "data/maps/Route111/scripts.pory"
	.string "I've found a pretty strong TRAINER!$"
# 543 "data/maps/Route111/scripts.pory"

# 544 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaIntro:
# 545 "data/maps/Route111/scripts.pory"
	.string "Oh, my goodness! Aren't you young?\p"
# 546 "data/maps/Route111/scripts.pory"
	.string "You must be quite the TRAINER to beat\n"
# 547 "data/maps/Route111/scripts.pory"
	.string "my husband, though.\p"
# 548 "data/maps/Route111/scripts.pory"
	.string "It's my turn to battle now!$"
# 549 "data/maps/Route111/scripts.pory"

# 550 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaDefeat:
# 551 "data/maps/Route111/scripts.pory"
	.string "Oh, gosh!\n"
# 552 "data/maps/Route111/scripts.pory"
	.string "I can't get over how strong you are!$"
# 553 "data/maps/Route111/scripts.pory"

# 554 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaPostBattle:
# 555 "data/maps/Route111/scripts.pory"
	.string "There's a strong TRAINER here!\n"
# 556 "data/maps/Route111/scripts.pory"
	.string "This one's really strong!$"
# 557 "data/maps/Route111/scripts.pory"

# 558 "data/maps/Route111/scripts.pory"
Route111_Text_ViviIntro:
# 559 "data/maps/Route111/scripts.pory"
	.string "You're stronger than Mommy? Wow!\p"
# 560 "data/maps/Route111/scripts.pory"
	.string "But I'm strong, too!\n"
# 561 "data/maps/Route111/scripts.pory"
	.string "Really! Honestly!$"
# 562 "data/maps/Route111/scripts.pory"

# 563 "data/maps/Route111/scripts.pory"
Route111_Text_ViviDefeat:
# 564 "data/maps/Route111/scripts.pory"
	.string "Huh? Did I just lose?$"
# 565 "data/maps/Route111/scripts.pory"

# 566 "data/maps/Route111/scripts.pory"
Route111_Text_ViviPostBattle:
# 567 "data/maps/Route111/scripts.pory"
	.string "This stinks…\p"
# 568 "data/maps/Route111/scripts.pory"
	.string "…Snivel… Grandma!$"
# 569 "data/maps/Route111/scripts.pory"

# 570 "data/maps/Route111/scripts.pory"
Route111_Text_VickyIntro:
# 571 "data/maps/Route111/scripts.pory"
	.string "How dare you make my granddaughter\n"
# 572 "data/maps/Route111/scripts.pory"
	.string "cry!\p"
# 573 "data/maps/Route111/scripts.pory"
	.string "For that, I'm going to smack you!\n"
# 574 "data/maps/Route111/scripts.pory"
	.string "Prepare to lose!$"
# 575 "data/maps/Route111/scripts.pory"

# 576 "data/maps/Route111/scripts.pory"
Route111_Text_VickyDefeat:
# 577 "data/maps/Route111/scripts.pory"
	.string "Kwah! You are strong…\n"
# 578 "data/maps/Route111/scripts.pory"
	.string "My granddaughter was right…$"
# 579 "data/maps/Route111/scripts.pory"

# 580 "data/maps/Route111/scripts.pory"
Route111_Text_VickyPostBattle:
# 581 "data/maps/Route111/scripts.pory"
	.string "If you're not in any hurry,\n"
# 582 "data/maps/Route111/scripts.pory"
	.string "visit with us awhile.$"
# 583 "data/maps/Route111/scripts.pory"

# 584 "data/maps/Route111/scripts.pory"
Route111_Text_ToughToKeepWinningUpTheRanks:
# 585 "data/maps/Route111/scripts.pory"
	.string "If you don't raise your POKéMON some\n"
# 586 "data/maps/Route111/scripts.pory"
	.string "more, it could be tough to keep winning\l"
# 587 "data/maps/Route111/scripts.pory"
	.string "up through the ranks.\p"
# 588 "data/maps/Route111/scripts.pory"
	.string "I've heard the POKéMON LEAGUE's\n"
# 589 "data/maps/Route111/scripts.pory"
	.string "ELITE FOUR are far stronger than\l"
# 590 "data/maps/Route111/scripts.pory"
	.string "any GYM LEADER.$"
# 591 "data/maps/Route111/scripts.pory"

# 592 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateFamilyDestroyedMe:
# 593 "data/maps/Route111/scripts.pory"
	.string "I challenged the WINSTRATE family,\n"
# 594 "data/maps/Route111/scripts.pory"
	.string "but four matches in a row is tough\l"
# 595 "data/maps/Route111/scripts.pory"
	.string "going… They destroyed me.$"
# 596 "data/maps/Route111/scripts.pory"

# 597 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSignMauville:
# 598 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 599 "data/maps/Route111/scripts.pory"
	.string "{DOWN_ARROW} MAUVILLE CITY$"
# 600 "data/maps/Route111/scripts.pory"

# 601 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateHouseSign:
# 602 "data/maps/Route111/scripts.pory"
	.string "“Our family's hearts beat as one!”\n"
# 603 "data/maps/Route111/scripts.pory"
	.string "THE WINSTRATE'S HOUSE$"
# 604 "data/maps/Route111/scripts.pory"

# 605 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign112:
# 606 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 607 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 112$"
# 608 "data/maps/Route111/scripts.pory"

# 609 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign113:
# 610 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 611 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 113$"
# 612 "data/maps/Route111/scripts.pory"

# 613 "data/maps/Route111/scripts.pory"
Route111_Text_OldLadysRestStopSign:
# 614 "data/maps/Route111/scripts.pory"
	.string "OLD LADY'S REST STOP\n"
# 615 "data/maps/Route111/scripts.pory"
	.string "“Come in and rest your tired bones.”$"
# 616 "data/maps/Route111/scripts.pory"

# 617 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerTipsSpAtkSpDef:
# 618 "data/maps/Route111/scripts.pory"
	.string "TRAINER TIPS\p"
# 619 "data/maps/Route111/scripts.pory"
	.string "One of the indicators of a POKéMON's\n"
# 620 "data/maps/Route111/scripts.pory"
	.string "powerfulness is SP. ATK. It stands for\l"
# 621 "data/maps/Route111/scripts.pory"
	.string "“SPECIAL ATTACK.”\p"
# 622 "data/maps/Route111/scripts.pory"
	.string "Likewise, SP. DEF stands for “SPECIAL\n"
# 623 "data/maps/Route111/scripts.pory"
	.string "DEFENSE.”$"
# 624 "data/maps/Route111/scripts.pory"

# 625 "data/maps/Route111/scripts.pory"
Route111_Text_ShouldBeMirageTowerAroundHere:
# 626 "data/maps/Route111/scripts.pory"
	.string "There should be a tower made of sand\n"
# 627 "data/maps/Route111/scripts.pory"
	.string "around here somewhere.\p"
# 628 "data/maps/Route111/scripts.pory"
	.string "But for some reason, it can be seen\n"
# 629 "data/maps/Route111/scripts.pory"
	.string "sometimes, and sometimes not.\p"
# 630 "data/maps/Route111/scripts.pory"
	.string "That's why I call it the MIRAGE TOWER.$"
# 631 "data/maps/Route111/scripts.pory"

# 632 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerClearlyVisible:
# 633 "data/maps/Route111/scripts.pory"
	.string "I see it!\n"
# 634 "data/maps/Route111/scripts.pory"
	.string "The tower of sand!\p"
# 635 "data/maps/Route111/scripts.pory"
	.string "The sand tower they called a mirage\n"
# 636 "data/maps/Route111/scripts.pory"
	.string "is clearly visible!\p"
# 637 "data/maps/Route111/scripts.pory"
	.string "But it looks so fragile…\n"
# 638 "data/maps/Route111/scripts.pory"
	.string "It could crumble away anytime…\p"
# 639 "data/maps/Route111/scripts.pory"
	.string "I want to go inside it, but I can't\n"
# 640 "data/maps/Route111/scripts.pory"
	.string "get my courage up for it…$"
# 641 "data/maps/Route111/scripts.pory"

# 642 "data/maps/Route111/scripts.pory"
Route111_Text_ThatWasShockingSandRainedDown:
# 643 "data/maps/Route111/scripts.pory"
	.string "Whoa…\n"
# 644 "data/maps/Route111/scripts.pory"
	.string "That was shocking.\p"
# 645 "data/maps/Route111/scripts.pory"
	.string "Sand rained down in chunks all of\n"
# 646 "data/maps/Route111/scripts.pory"
	.string "a sudden.\p"
# 647 "data/maps/Route111/scripts.pory"
	.string "What was it like inside?\n"
# 648 "data/maps/Route111/scripts.pory"
	.string "Were there sandy ghosts and such?$"
# 649 "data/maps/Route111/scripts.pory"

# 650 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerHasntBeenSeenSince:
# 651 "data/maps/Route111/scripts.pory"
	.string "Since I spoke to you, the tower of sand\n"
# 652 "data/maps/Route111/scripts.pory"
	.string "hasn't been seen.\p"
# 653 "data/maps/Route111/scripts.pory"
	.string "Perhaps it really was\n"
# 654 "data/maps/Route111/scripts.pory"
	.string "the MIRAGE TOWER…$"
# 655 "data/maps/Route111/scripts.pory"

# 656 "data/maps/Route111/scripts.pory"
Route111_Text_ClawFossilDisappeared:
# 657 "data/maps/Route111/scripts.pory"
	.string "The CLAW FOSSIL disappeared into\n"
# 658 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 659 "data/maps/Route111/scripts.pory"

# 660 "data/maps/Route111/scripts.pory"
Route111_Text_RootFossilDisappeared:
# 661 "data/maps/Route111/scripts.pory"
	.string "The ROOT FOSSIL disappeared into\n"
# 662 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 663 "data/maps/Route111/scripts.pory"

# 664 "data/maps/Route111/scripts.pory"
Route111_Text_MauvilleUncleToldMeToTakeRockSmash:
# 665 "data/maps/Route111/scripts.pory"
	.string "Oh, no!\p"
# 666 "data/maps/Route111/scripts.pory"
	.string "My uncle in MAUVILLE told me to take\n"
# 667 "data/maps/Route111/scripts.pory"
	.string "ROCK SMASH with me if I was going to\l"
# 668 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111!\p"
# 669 "data/maps/Route111/scripts.pory"
	.string "My uncle? He lives across from\n"
# 670 "data/maps/Route111/scripts.pory"
	.string "the bike shop in MAUVILLE.$"
# 671 "data/maps/Route111/scripts.pory"

# 672 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerHillSign:
# 673 "data/maps/Route111/scripts.pory"
	.string "{RIGHT_ARROW} TRAINER HILL ENTRANCE\p"
# 674 "data/maps/Route111/scripts.pory"
	.string "“Scale the heights, you hot-blooded\n"
# 675 "data/maps/Route111/scripts.pory"
	.string "TRAINERS!”$"
