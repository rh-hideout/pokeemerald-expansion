# 1 "data/maps/Route120/scripts.pory"

# 2 "data/maps/Route120/scripts.pory"
@ LOCALID_BRIDGE_KECLEON_SHADOW is a second object which is identical to LOCALID_BRIDGE_KECLEON but has a reflection palette tag for the bridge shadow
# 3 "data/maps/Route120/scripts.pory"
Route120_MapScripts::
# 4 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route120_OnResume
# 5 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_OnTransition
# 6 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route120_OnLoad
# 7 "data/maps/Route120/scripts.pory"
	.byte 0
# 8 "data/maps/Route120/scripts.pory"

# 9 "data/maps/Route120/scripts.pory"
Route120_OnResume:
# 10 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route120_EventScript_RemoveKecleonObject
# 11 "data/maps/Route120/scripts.pory"
	end
# 12 "data/maps/Route120/scripts.pory"

# 13 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleonObject::
# 14 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 0, Route120_EventScript_RemoveBridgeKecleon
# 15 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 1, Route120_EventScript_RemoveKecleon
# 16 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 2, Route120_EventScript_RemoveKecleon
# 17 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 3, Route120_EventScript_RemoveKecleon
# 18 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 4, Route120_EventScript_RemoveKecleon
# 19 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 5, Route120_EventScript_RemoveKecleon
# 20 "data/maps/Route120/scripts.pory"
	return
# 21 "data/maps/Route120/scripts.pory"

# 22 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleon::
# 23 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 24 "data/maps/Route120/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 25 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON
# 26 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
# 27 "data/maps/Route120/scripts.pory"
	return
# 28 "data/maps/Route120/scripts.pory"

# 29 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleon::
# 30 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 31 "data/maps/Route120/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 32 "data/maps/Route120/scripts.pory"
	removeobject VAR_LAST_TALKED
# 33 "data/maps/Route120/scripts.pory"
	return
# 34 "data/maps/Route120/scripts.pory"

# 35 "data/maps/Route120/scripts.pory"
Route120_OnLoad:
# 36 "data/maps/Route120/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route120_EventScript_CloseAncientTomb
# 37 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeClearMetatiles
# 38 "data/maps/Route120/scripts.pory"
	call_if_unset FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeKecleonMovement
# 39 "data/maps/Route120/scripts.pory"
	end
# 40 "data/maps/Route120/scripts.pory"

# 41 "data/maps/Route120/scripts.pory"
Route120_EventScript_CloseAncientTomb::
# 42 "data/maps/Route120/scripts.pory"
	setmetatile 7, 54, METATILE_General_RockWall_RockBase, TRUE
# 43 "data/maps/Route120/scripts.pory"
	setmetatile 7, 55, METATILE_General_RockWall_SandBase, TRUE
# 44 "data/maps/Route120/scripts.pory"
	return
# 45 "data/maps/Route120/scripts.pory"

# 46 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeClearMetatiles::
# 47 "data/maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
# 48 "data/maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
# 49 "data/maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
# 50 "data/maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
# 51 "data/maps/Route120/scripts.pory"
	return
# 52 "data/maps/Route120/scripts.pory"

# 53 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeKecleonMovement::
# 54 "data/maps/Route120/scripts.pory"
	setobjectmovementtype LOCALID_BRIDGE_KECLEON_SHADOW, MOVEMENT_TYPE_FACE_RIGHT
# 55 "data/maps/Route120/scripts.pory"
	return
# 56 "data/maps/Route120/scripts.pory"

# 57 "data/maps/Route120/scripts.pory"
Route120_OnTransition:
# 58 "data/maps/Route120/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 59 "data/maps/Route120/scripts.pory"
	call Route120_EventScript_SetWeather
# 60 "data/maps/Route120/scripts.pory"
	end
# 61 "data/maps/Route120/scripts.pory"

# 62 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetWeather::
# 63 "data/maps/Route120/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 64 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_1, 14, Route120_EventScript_SetSunnyWeather
# 65 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_1, 60, Route120_EventScript_TrySetRainyWeather
# 66 "data/maps/Route120/scripts.pory"
	goto_if_ge VAR_TEMP_1, 61, Route120_EventScript_SetCloudyWeather
# 67 "data/maps/Route120/scripts.pory"
	return
# 68 "data/maps/Route120/scripts.pory"

# 69 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetCloudyWeather::
# 70 "data/maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 71 "data/maps/Route120/scripts.pory"
	return
# 72 "data/maps/Route120/scripts.pory"

# 73 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetSunnyWeather::
# 74 "data/maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY
# 75 "data/maps/Route120/scripts.pory"
	return
# 76 "data/maps/Route120/scripts.pory"

# 77 "data/maps/Route120/scripts.pory"
Route120_EventScript_TrySetRainyWeather::
# 78 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_0, 7, Route120_EventScript_SetRainyWeather
# 79 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_0, 19, Route120_EventScript_SetSunnyWeather
# 80 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_SetRainyWeather
# 81 "data/maps/Route120/scripts.pory"
	end
# 82 "data/maps/Route120/scripts.pory"

# 83 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetRainyWeather::
# 84 "data/maps/Route120/scripts.pory"
	setweather WEATHER_RAIN
# 85 "data/maps/Route120/scripts.pory"
	return
# 86 "data/maps/Route120/scripts.pory"

# 87 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryBeauty::
# 88 "data/maps/Route120/scripts.pory"
	lock
# 89 "data/maps/Route120/scripts.pory"
	faceplayer
# 90 "data/maps/Route120/scripts.pory"
	dotimebasedevents
# 91 "data/maps/Route120/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_120_RECEIVED_BERRY, Route120_EventScript_ReceivedBerry
# 92 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_BerriesExpressionOfLoveIsntIt, MSGBOX_YESNO
# 93 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route120_EventScript_BerryLove
# 94 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route120_EventScript_BerryNotLove
# 95 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
# 96 "data/maps/Route120/scripts.pory"
	switch VAR_RESULT
# 97 "data/maps/Route120/scripts.pory"
	case 0, Route120_EventScript_GiveFigyBerry
# 98 "data/maps/Route120/scripts.pory"
	case 5, Route120_EventScript_GiveFigyBerry
# 99 "data/maps/Route120/scripts.pory"
	case 1, Route120_EventScript_GiveWikiBerry
# 100 "data/maps/Route120/scripts.pory"
	case 6, Route120_EventScript_GiveWikiBerry
# 101 "data/maps/Route120/scripts.pory"
	case 2, Route120_EventScript_GiveMagoBerry
# 102 "data/maps/Route120/scripts.pory"
	case 7, Route120_EventScript_GiveMagoBerry
# 103 "data/maps/Route120/scripts.pory"
	case 3, Route120_EventScript_GiveAguavBerry
# 104 "data/maps/Route120/scripts.pory"
	case 8, Route120_EventScript_GiveAguavBerry
# 105 "data/maps/Route120/scripts.pory"
	case 4, Route120_EventScript_GiveIapapaBerry
# 106 "data/maps/Route120/scripts.pory"
	case 9, Route120_EventScript_GiveIapapaBerry
# 107 "data/maps/Route120/scripts.pory"
	end
# 108 "data/maps/Route120/scripts.pory"

# 109 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveFigyBerry::
# 110 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_FIGY_BERRY
# 111 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 112 "data/maps/Route120/scripts.pory"
	end
# 113 "data/maps/Route120/scripts.pory"

# 114 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveWikiBerry::
# 115 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_WIKI_BERRY
# 116 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 117 "data/maps/Route120/scripts.pory"
	end
# 118 "data/maps/Route120/scripts.pory"

# 119 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveMagoBerry::
# 120 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_MAGO_BERRY
# 121 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 122 "data/maps/Route120/scripts.pory"
	end
# 123 "data/maps/Route120/scripts.pory"

# 124 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveAguavBerry::
# 125 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_AGUAV_BERRY
# 126 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 127 "data/maps/Route120/scripts.pory"
	end
# 128 "data/maps/Route120/scripts.pory"

# 129 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveIapapaBerry::
# 130 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_IAPAPA_BERRY
# 131 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 132 "data/maps/Route120/scripts.pory"
	end
# 133 "data/maps/Route120/scripts.pory"

# 134 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveBerry::
# 135 "data/maps/Route120/scripts.pory"
	giveitem VAR_0x8004
# 136 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 137 "data/maps/Route120/scripts.pory"
	setflag FLAG_DAILY_ROUTE_120_RECEIVED_BERRY
# 138 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_BerryIsRareRaiseItWithCare, MSGBOX_DEFAULT
# 139 "data/maps/Route120/scripts.pory"
	release
# 140 "data/maps/Route120/scripts.pory"
	end
# 141 "data/maps/Route120/scripts.pory"

# 142 "data/maps/Route120/scripts.pory"
Route120_EventScript_ReceivedBerry::
# 143 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_IllGetMoreBerriesFromBerryMaster, MSGBOX_DEFAULT
# 144 "data/maps/Route120/scripts.pory"
	release
# 145 "data/maps/Route120/scripts.pory"
	end
# 146 "data/maps/Route120/scripts.pory"

# 147 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryLove::
# 148 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_YesYouUnderstand, MSGBOX_DEFAULT
# 149 "data/maps/Route120/scripts.pory"
	return
# 150 "data/maps/Route120/scripts.pory"

# 151 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryNotLove::
# 152 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_MakeYourOwnImpressions, MSGBOX_DEFAULT
# 153 "data/maps/Route120/scripts.pory"
	return
# 154 "data/maps/Route120/scripts.pory"

# 155 "data/maps/Route120/scripts.pory"
Route120_EventScript_Steven::
# 156 "data/maps/Route120/scripts.pory"
	lock
# 157 "data/maps/Route120/scripts.pory"
	faceplayer
# 158 "data/maps/Route120/scripts.pory"
	goto_if_set FLAG_NOT_READY_FOR_BATTLE_ROUTE_120, Route120_EventScript_StevenAskReadyForBattle
# 159 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGreeting, MSGBOX_YESNO
# 160 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
# 161 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 162 "data/maps/Route120/scripts.pory"
	end
# 163 "data/maps/Route120/scripts.pory"

# 164 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenNotReady::
# 165 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenIllWaitHere, MSGBOX_DEFAULT
# 166 "data/maps/Route120/scripts.pory"
	setflag FLAG_NOT_READY_FOR_BATTLE_ROUTE_120
# 167 "data/maps/Route120/scripts.pory"
	release
# 168 "data/maps/Route120/scripts.pory"
	end
# 169 "data/maps/Route120/scripts.pory"

# 170 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenAskReadyForBattle::
# 171 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenReadyForBattle, MSGBOX_YESNO
# 172 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
# 173 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 174 "data/maps/Route120/scripts.pory"
	end
# 175 "data/maps/Route120/scripts.pory"

# 176 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenBattleKecleon::
# 177 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenShowMeYourPower, MSGBOX_DEFAULT
# 178 "data/maps/Route120/scripts.pory"
	closemessage
# 179 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route120_EventScript_PlayerApproachKecleonNorth
# 180 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route120_EventScript_PlayerApproachKecleonWest
# 181 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_ROUTE120_STEVEN, Common_Movement_WalkInPlaceFasterLeft
# 182 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 183 "data/maps/Route120/scripts.pory"
	delay 20
# 184 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenUsedDevonScope, MSGBOX_DEFAULT
# 185 "data/maps/Route120/scripts.pory"
	closemessage
# 186 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_BRIDGE_KECLEON, Common_Movement_WalkInPlaceFasterRight
# 187 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 188 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_BRIDGE_KECLEON, Movement_KecleonAppears
# 189 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 190 "data/maps/Route120/scripts.pory"
	waitse
# 191 "data/maps/Route120/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
# 192 "data/maps/Route120/scripts.pory"
	delay 40
# 193 "data/maps/Route120/scripts.pory"
	waitmoncry
# 194 "data/maps/Route120/scripts.pory"
	setwildbattle SPECIES_KECLEON, 30
# 195 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8009, 0
# 196 "data/maps/Route120/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 197 "data/maps/Route120/scripts.pory"
	dowildbattle
# 198 "data/maps/Route120/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 199 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 200 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 201 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 202 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 203 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 204 "data/maps/Route120/scripts.pory"
	end
# 205 "data/maps/Route120/scripts.pory"

# 206 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleonPostBattle::
# 207 "data/maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 208 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON
# 209 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
# 210 "data/maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 211 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 212 "data/maps/Route120/scripts.pory"
	end
# 213 "data/maps/Route120/scripts.pory"

# 214 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenGiveDeconScope::
# 215 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_ROUTE120_STEVEN, Common_Movement_WalkInPlaceFasterDown
# 216 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 217 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 218 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGiveDevonScope, MSGBOX_DEFAULT
# 219 "data/maps/Route120/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 220 "data/maps/Route120/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 221 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGoodbye, MSGBOX_DEFAULT
# 222 "data/maps/Route120/scripts.pory"
	closemessage
# 223 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_ROUTE120_STEVEN, Common_Movement_WalkInPlaceFasterDown
# 224 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 225 "data/maps/Route120/scripts.pory"
	delay 50
# 226 "data/maps/Route120/scripts.pory"
	setfieldeffectargument 0, 1
# 227 "data/maps/Route120/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 228 "data/maps/Route120/scripts.pory"
	delay 15
# 229 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_ROUTE120_STEVEN
# 230 "data/maps/Route120/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 231 "data/maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
# 232 "data/maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
# 233 "data/maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
# 234 "data/maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
# 235 "data/maps/Route120/scripts.pory"
	special DrawWholeMapView
# 236 "data/maps/Route120/scripts.pory"
	release
# 237 "data/maps/Route120/scripts.pory"
	end
# 238 "data/maps/Route120/scripts.pory"

# 239 "data/maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonNorth::
# 240 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 241 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 242 "data/maps/Route120/scripts.pory"
	return
# 243 "data/maps/Route120/scripts.pory"

# 244 "data/maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonWest::
# 245 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_PLAYER, Route120_Movement_ApproachKecleonWest
# 246 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 247 "data/maps/Route120/scripts.pory"
	return
# 248 "data/maps/Route120/scripts.pory"

# 249 "data/maps/Route120/scripts.pory"
Route120_Movement_ApproachKecleonWest:
# 250 "data/maps/Route120/scripts.pory"
	walk_down
# 251 "data/maps/Route120/scripts.pory"
	walk_left
# 252 "data/maps/Route120/scripts.pory"
	step_end
# 253 "data/maps/Route120/scripts.pory"

# 254 "data/maps/Route120/scripts.pory"
Route120_EventScript_BridgeKecleon::
# 255 "data/maps/Route120/scripts.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_NPC
# 256 "data/maps/Route120/scripts.pory"
	end
# 257 "data/maps/Route120/scripts.pory"

# 258 "data/maps/Route120/scripts.pory"
Route120_EventScript_RouteSignFortree::
# 259 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSignFortree, MSGBOX_SIGN
# 260 "data/maps/Route120/scripts.pory"
	end
# 261 "data/maps/Route120/scripts.pory"

# 262 "data/maps/Route120/scripts.pory"
Route120_EventScript_RouteSign121::
# 263 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSign121, MSGBOX_SIGN
# 264 "data/maps/Route120/scripts.pory"
	end
# 265 "data/maps/Route120/scripts.pory"

# 266 "data/maps/Route120/scripts.pory"
Route120_EventScript_Colin::
# 267 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_COLIN, Route120_Text_ColinIntro, Route120_Text_ColinDefeat
# 268 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
# 269 "data/maps/Route120/scripts.pory"
	end
# 270 "data/maps/Route120/scripts.pory"

# 271 "data/maps/Route120/scripts.pory"
Route120_EventScript_Robert::
# 272 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_ROBERT_1, Route120_Text_RobertIntro, Route120_Text_RobertDefeat, Route120_EventScript_RegisterRobert
# 273 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 274 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchRobert
# 275 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostBattle, MSGBOX_DEFAULT
# 276 "data/maps/Route120/scripts.pory"
	release
# 277 "data/maps/Route120/scripts.pory"
	end
# 278 "data/maps/Route120/scripts.pory"

# 279 "data/maps/Route120/scripts.pory"
Route120_EventScript_RegisterRobert::
# 280 "data/maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 281 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 282 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertRegister, MSGBOX_DEFAULT
# 283 "data/maps/Route120/scripts.pory"
	register_matchcall TRAINER_ROBERT_1
# 284 "data/maps/Route120/scripts.pory"
	release
# 285 "data/maps/Route120/scripts.pory"
	end
# 286 "data/maps/Route120/scripts.pory"

# 287 "data/maps/Route120/scripts.pory"
Route120_EventScript_RematchRobert::
# 288 "data/maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_ROBERT_1, Route120_Text_RobertRematchIntro, Route120_Text_RobertRematchDefeat
# 289 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostRematch, MSGBOX_AUTOCLOSE
# 290 "data/maps/Route120/scripts.pory"
	end
# 291 "data/maps/Route120/scripts.pory"

# 292 "data/maps/Route120/scripts.pory"
Route120_EventScript_Lorenzo::
# 293 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_LORENZO, Route120_Text_LorenzoIntro, Route120_Text_LorenzoDefeat
# 294 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LorenzoPostBattle, MSGBOX_AUTOCLOSE
# 295 "data/maps/Route120/scripts.pory"
	end
# 296 "data/maps/Route120/scripts.pory"

# 297 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jenna::
# 298 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JENNA, Route120_Text_JennaIntro, Route120_Text_JennaDefeat
# 299 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
# 300 "data/maps/Route120/scripts.pory"
	end
# 301 "data/maps/Route120/scripts.pory"

# 302 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jeffrey::
# 303 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JEFFREY_1, Route120_Text_JeffreyIntro, Route120_Text_JeffreyDefeat, Route120_EventScript_RegisterJeffrey
# 304 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 305 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchJeffrey
# 306 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostBattle, MSGBOX_DEFAULT
# 307 "data/maps/Route120/scripts.pory"
	release
# 308 "data/maps/Route120/scripts.pory"
	end
# 309 "data/maps/Route120/scripts.pory"

# 310 "data/maps/Route120/scripts.pory"
Route120_EventScript_RegisterJeffrey::
# 311 "data/maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 312 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 313 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyRegister, MSGBOX_DEFAULT
# 314 "data/maps/Route120/scripts.pory"
	register_matchcall TRAINER_JEFFREY_1
# 315 "data/maps/Route120/scripts.pory"
	release
# 316 "data/maps/Route120/scripts.pory"
	end
# 317 "data/maps/Route120/scripts.pory"

# 318 "data/maps/Route120/scripts.pory"
Route120_EventScript_RematchJeffrey::
# 319 "data/maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_JEFFREY_1, Route120_Text_JeffreyRematchIntro, Route120_Text_JeffreyRematchDefeat
# 320 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostRematch, MSGBOX_AUTOCLOSE
# 321 "data/maps/Route120/scripts.pory"
	end
# 322 "data/maps/Route120/scripts.pory"

# 323 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jennifer::
# 324 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JENNIFER, Route120_Text_JenniferIntro, Route120_Text_JenniferDefeat
# 325 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
# 326 "data/maps/Route120/scripts.pory"
	end
# 327 "data/maps/Route120/scripts.pory"

# 328 "data/maps/Route120/scripts.pory"
Route120_EventScript_Chip::
# 329 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CHIP, Route120_Text_ChipIntro, Route120_Text_ChipDefeat
# 330 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
# 331 "data/maps/Route120/scripts.pory"
	end
# 332 "data/maps/Route120/scripts.pory"

# 333 "data/maps/Route120/scripts.pory"
Route120_EventScript_Clarissa::
# 334 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CLARISSA, Route120_Text_ClarissaIntro, Route120_Text_ClarissaDefeat
# 335 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ClarissaPostBattle, MSGBOX_AUTOCLOSE
# 336 "data/maps/Route120/scripts.pory"
	end
# 337 "data/maps/Route120/scripts.pory"

# 338 "data/maps/Route120/scripts.pory"
Route120_EventScript_Angelica::
# 339 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_ANGELICA, Route120_Text_AngelicaIntro, Route120_Text_AngelicaDefeat
# 340 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
# 341 "data/maps/Route120/scripts.pory"
	end
# 342 "data/maps/Route120/scripts.pory"

# 343 "data/maps/Route120/scripts.pory"
Route120_EventScript_Keigo::
# 344 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_KEIGO, Route120_Text_KeigoIntro, Route120_Text_KeigoDefeat
# 345 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
# 346 "data/maps/Route120/scripts.pory"
	end
# 347 "data/maps/Route120/scripts.pory"

# 348 "data/maps/Route120/scripts.pory"
Route120_EventScript_Riley::
# 349 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_RILEY, Route120_Text_RileyIntro, Route120_Text_RileyDefeat
# 350 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
# 351 "data/maps/Route120/scripts.pory"
	end
# 352 "data/maps/Route120/scripts.pory"

# 353 "data/maps/Route120/scripts.pory"
Route120_EventScript_Leonel::
# 354 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_LEONEL, Route120_Text_LeonelIntro, Route120_Text_LeonelDefeat
# 355 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LeonelPostBattle, MSGBOX_AUTOCLOSE
# 356 "data/maps/Route120/scripts.pory"
	end
# 357 "data/maps/Route120/scripts.pory"

# 358 "data/maps/Route120/scripts.pory"
Route120_EventScript_Callie::
# 359 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CALLIE, Route120_Text_CallieIntro, Route120_Text_CallieDefeat
# 360 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_CalliePostBattle, MSGBOX_AUTOCLOSE
# 361 "data/maps/Route120/scripts.pory"
	end
# 362 "data/maps/Route120/scripts.pory"

# 363 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGreeting:
# 364 "data/maps/Route120/scripts.pory"
	.string "STEVEN: Hm? {PLAYER}{KUN}, hi.\n"
# 365 "data/maps/Route120/scripts.pory"
	.string "It's been a while.\p"
# 366 "data/maps/Route120/scripts.pory"
	.string "There's something here that you can't\n"
# 367 "data/maps/Route120/scripts.pory"
	.string "see, right?\p"
# 368 "data/maps/Route120/scripts.pory"
	.string "Now, if I were to use this device on\n"
# 369 "data/maps/Route120/scripts.pory"
	.string "the invisible obstacle…\p"
# 370 "data/maps/Route120/scripts.pory"
	.string "No, no. Rather than describing it,\n"
# 371 "data/maps/Route120/scripts.pory"
	.string "I should just show you.\l"
# 372 "data/maps/Route120/scripts.pory"
	.string "That would be more fun.\p"
# 373 "data/maps/Route120/scripts.pory"
	.string "{PLAYER}{KUN}, are your POKéMON ready for\n"
# 374 "data/maps/Route120/scripts.pory"
	.string "battle?$"
# 375 "data/maps/Route120/scripts.pory"

# 376 "data/maps/Route120/scripts.pory"
Route120_Text_StevenIllWaitHere:
# 377 "data/maps/Route120/scripts.pory"
	.string "STEVEN: No?\p"
# 378 "data/maps/Route120/scripts.pory"
	.string "I'll wait here, so you can get ready.$"
# 379 "data/maps/Route120/scripts.pory"

# 380 "data/maps/Route120/scripts.pory"
Route120_Text_StevenReadyForBattle:
# 381 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, are your POKéMON\n"
# 382 "data/maps/Route120/scripts.pory"
	.string "ready for battle?$"
# 383 "data/maps/Route120/scripts.pory"

# 384 "data/maps/Route120/scripts.pory"
Route120_Text_StevenShowMeYourPower:
# 385 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, show me your true\n"
# 386 "data/maps/Route120/scripts.pory"
	.string "power as a TRAINER!$"
# 387 "data/maps/Route120/scripts.pory"

# 388 "data/maps/Route120/scripts.pory"
Route120_Text_StevenUsedDevonScope:
# 389 "data/maps/Route120/scripts.pory"
	.string "STEVEN used the DEVON SCOPE.\p"
# 390 "data/maps/Route120/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 391 "data/maps/Route120/scripts.pory"
	.string "visible!\p"
# 392 "data/maps/Route120/scripts.pory"
	.string "The startled POKéMON attacked!$"
# 393 "data/maps/Route120/scripts.pory"

# 394 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGiveDevonScope:
# 395 "data/maps/Route120/scripts.pory"
	.string "STEVEN: I see…\n"
# 396 "data/maps/Route120/scripts.pory"
	.string "Your battle style is intriguing.\p"
# 397 "data/maps/Route120/scripts.pory"
	.string "Your POKéMON have obviously grown\n"
# 398 "data/maps/Route120/scripts.pory"
	.string "since I first met you in DEWFORD.\p"
# 399 "data/maps/Route120/scripts.pory"
	.string "I'd like you to have this\n"
# 400 "data/maps/Route120/scripts.pory"
	.string "DEVON SCOPE.\p"
# 401 "data/maps/Route120/scripts.pory"
	.string "Who knows, there may be other\n"
# 402 "data/maps/Route120/scripts.pory"
	.string "concealed POKéMON.$"
# 403 "data/maps/Route120/scripts.pory"

# 404 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGoodbye:
# 405 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}.\p"
# 406 "data/maps/Route120/scripts.pory"
	.string "I enjoy seeing POKéMON and TRAINERS\n"
# 407 "data/maps/Route120/scripts.pory"
	.string "who strive together.\p"
# 408 "data/maps/Route120/scripts.pory"
	.string "I think you're doing great.\p"
# 409 "data/maps/Route120/scripts.pory"
	.string "Well, let's meet again somewhere.$"
# 410 "data/maps/Route120/scripts.pory"

# 411 "data/maps/Route120/scripts.pory"
Kecleon_Text_SomethingUnseeable:
# 412 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.$"
# 413 "data/maps/Route120/scripts.pory"

# 414 "data/maps/Route120/scripts.pory"
Kecleon_Text_WantToUseDevonScope:
# 415 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.\p"
# 416 "data/maps/Route120/scripts.pory"
	.string "Want to use the DEVON SCOPE?$"
# 417 "data/maps/Route120/scripts.pory"

# 418 "data/maps/Route120/scripts.pory"
Kecleon_Text_UseDevonScopeMonAttacked:
# 419 "data/maps/Route120/scripts.pory"
	.string "{PLAYER} used the DEVON SCOPE.\p"
# 420 "data/maps/Route120/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 421 "data/maps/Route120/scripts.pory"
	.string "visible!\p"
# 422 "data/maps/Route120/scripts.pory"
	.string "The startled POKéMON attacked!$"
# 423 "data/maps/Route120/scripts.pory"

# 424 "data/maps/Route120/scripts.pory"
Route120_Text_RouteSignFortree:
# 425 "data/maps/Route120/scripts.pory"
	.string "ROUTE 120\n"
# 426 "data/maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} FORTREE CITY$"
# 427 "data/maps/Route120/scripts.pory"

# 428 "data/maps/Route120/scripts.pory"
Route120_Text_RouteSign121:
# 429 "data/maps/Route120/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 121\n"
# 430 "data/maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 120$"
