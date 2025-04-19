# 1 "data/maps/Route116/scripts.pory"

# 2 "data/maps/Route116/scripts.pory"
.set LOCALID_BRINEY, 11
# 3 "data/maps/Route116/scripts.pory"
.set LOCALID_WANDAS_BF_OUTSIDE, 21
# 4 "data/maps/Route116/scripts.pory"

# 5 "data/maps/Route116/scripts.pory"
Route116_MapScripts::
# 6 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
# 7 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
# 8 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
# 9 "data/maps/Route116/scripts.pory"
	.byte 0
# 10 "data/maps/Route116/scripts.pory"

# 11 "data/maps/Route116/scripts.pory"
Route116_OnTransition:
# 12 "data/maps/Route116/scripts.pory"
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
# 13 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 14 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_StartGroudonWeather
# 15 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_StartGroudonWeather
# 16 "data/maps/Route116/scripts.pory"
	end
# 17 "data/maps/Route116/scripts.pory"

# 18 "data/maps/Route116/scripts.pory"
Route116_EventScript_SetWandasBoyfriendPos::
# 19 "data/maps/Route116/scripts.pory"
	setobjectxyperm LOCALID_WANDAS_BF_OUTSIDE, 38, 10
# 20 "data/maps/Route116/scripts.pory"
	return
# 21 "data/maps/Route116/scripts.pory"

# 22 "data/maps/Route116/scripts.pory"
Route116_OnLoad:
# 23 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute116North
# 24 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute116South
# 25 "data/maps/Route116/scripts.pory"
	end
# 26 "data/maps/Route116/scripts.pory"

# 27 "data/maps/Route116/scripts.pory"
Route116_OnFrame:
# 28 "data/maps/Route116/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 29 "data/maps/Route116/scripts.pory"
	.2byte 0
# 30 "data/maps/Route116/scripts.pory"

# 31 "data/maps/Route116/scripts.pory"
Route116_EventScript_WandasBoyfriend::
# 32 "data/maps/Route116/scripts.pory"
	lock
# 33 "data/maps/Route116/scripts.pory"
	faceplayer
# 34 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
# 35 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
# 36 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
# 37 "data/maps/Route116/scripts.pory"
	release
# 38 "data/maps/Route116/scripts.pory"
	end
# 39 "data/maps/Route116/scripts.pory"

# 40 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntLeftTunnel::
# 41 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
# 42 "data/maps/Route116/scripts.pory"
	release
# 43 "data/maps/Route116/scripts.pory"
	end
# 44 "data/maps/Route116/scripts.pory"

# 45 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntInTunnel::
# 46 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
# 47 "data/maps/Route116/scripts.pory"
	release
# 48 "data/maps/Route116/scripts.pory"
	end
# 49 "data/maps/Route116/scripts.pory"

# 50 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployee::
# 51 "data/maps/Route116/scripts.pory"
	lock
# 52 "data/maps/Route116/scripts.pory"
	faceplayer
# 53 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
# 54 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
# 55 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 56 "data/maps/Route116/scripts.pory"
	end
# 57 "data/maps/Route116/scripts.pory"

# 58 "data/maps/Route116/scripts.pory"
Route116_EventScript_GiveRepeatBall::
# 59 "data/maps/Route116/scripts.pory"
	setflag FLAG_MET_DEVON_EMPLOYEE
# 60 "data/maps/Route116/scripts.pory"
	giveitem ITEM_REPEAT_BALL
# 61 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
# 62 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
# 63 "data/maps/Route116/scripts.pory"
	closemessage
# 64 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
# 65 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
# 66 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
# 67 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
# 68 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 69 "data/maps/Route116/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 70 "data/maps/Route116/scripts.pory"
	setflag FLAG_RECEIVED_REPEAT_BALL
# 71 "data/maps/Route116/scripts.pory"
	release
# 72 "data/maps/Route116/scripts.pory"
	end
# 73 "data/maps/Route116/scripts.pory"

# 74 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExit::
# 75 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
# 76 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 77 "data/maps/Route116/scripts.pory"
	return
# 78 "data/maps/Route116/scripts.pory"

# 79 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExitEast::
# 80 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
# 81 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 82 "data/maps/Route116/scripts.pory"
	return
# 83 "data/maps/Route116/scripts.pory"

# 84 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryGiveRepeatBallAgain::
# 85 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
# 86 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 87 "data/maps/Route116/scripts.pory"
	end
# 88 "data/maps/Route116/scripts.pory"

# 89 "data/maps/Route116/scripts.pory"
Route116_EventScript_NoRoomForRepeatBall::
# 90 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
# 91 "data/maps/Route116/scripts.pory"
	release
# 92 "data/maps/Route116/scripts.pory"
	end
# 93 "data/maps/Route116/scripts.pory"

# 94 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExit:
# 95 "data/maps/Route116/scripts.pory"
	walk_left
# 96 "data/maps/Route116/scripts.pory"
	walk_left
# 97 "data/maps/Route116/scripts.pory"
	walk_left
# 98 "data/maps/Route116/scripts.pory"
	walk_left
# 99 "data/maps/Route116/scripts.pory"
	walk_left
# 100 "data/maps/Route116/scripts.pory"
	walk_left
# 101 "data/maps/Route116/scripts.pory"
	walk_left
# 102 "data/maps/Route116/scripts.pory"
	walk_left
# 103 "data/maps/Route116/scripts.pory"
	step_end
# 104 "data/maps/Route116/scripts.pory"

# 105 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExitEast:
# 106 "data/maps/Route116/scripts.pory"
	walk_down
# 107 "data/maps/Route116/scripts.pory"
	walk_left
# 108 "data/maps/Route116/scripts.pory"
	walk_left
# 109 "data/maps/Route116/scripts.pory"
	walk_left
# 110 "data/maps/Route116/scripts.pory"
	walk_left
# 111 "data/maps/Route116/scripts.pory"
	walk_left
# 112 "data/maps/Route116/scripts.pory"
	walk_left
# 113 "data/maps/Route116/scripts.pory"
	walk_left
# 114 "data/maps/Route116/scripts.pory"
	walk_left
# 115 "data/maps/Route116/scripts.pory"
	walk_left
# 116 "data/maps/Route116/scripts.pory"
	step_end
# 117 "data/maps/Route116/scripts.pory"

# 118 "data/maps/Route116/scripts.pory"
Route116_EventScript_RouteSignRustboro::
# 119 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
# 120 "data/maps/Route116/scripts.pory"
	end
# 121 "data/maps/Route116/scripts.pory"

# 122 "data/maps/Route116/scripts.pory"
Route116_EventScript_RusturfTunnelSign::
# 123 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
# 124 "data/maps/Route116/scripts.pory"
	end
# 125 "data/maps/Route116/scripts.pory"

# 126 "data/maps/Route116/scripts.pory"
Route116_EventScript_TunnelersRestHouseSign::
# 127 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
# 128 "data/maps/Route116/scripts.pory"
	end
# 129 "data/maps/Route116/scripts.pory"

# 130 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBToStopEvolution::
# 131 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
# 132 "data/maps/Route116/scripts.pory"
	end
# 133 "data/maps/Route116/scripts.pory"

# 134 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBagHasPockets::
# 135 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
# 136 "data/maps/Route116/scripts.pory"
	end
# 137 "data/maps/Route116/scripts.pory"

# 138 "data/maps/Route116/scripts.pory"
Route116_EventScript_Briney::
# 139 "data/maps/Route116/scripts.pory"
	lock
# 140 "data/maps/Route116/scripts.pory"
	faceplayer
# 141 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 142 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 143 "data/maps/Route116/scripts.pory"
	release
# 144 "data/maps/Route116/scripts.pory"
	end
# 145 "data/maps/Route116/scripts.pory"

# 146 "data/maps/Route116/scripts.pory"
Route116_EventScript_BrineyTrigger::
# 147 "data/maps/Route116/scripts.pory"
	lockall
# 148 "data/maps/Route116/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterRight
# 149 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 150 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 151 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 152 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 153 "data/maps/Route116/scripts.pory"
	releaseall
# 154 "data/maps/Route116/scripts.pory"
	end
# 155 "data/maps/Route116/scripts.pory"

# 156 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesMan::
# 157 "data/maps/Route116/scripts.pory"
	lock
# 158 "data/maps/Route116/scripts.pory"
	faceplayer
# 159 "data/maps/Route116/scripts.pory"
	checkitem ITEM_BLACK_GLASSES
# 160 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
# 161 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 162 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
# 163 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 164 "data/maps/Route116/scripts.pory"
	release
# 165 "data/maps/Route116/scripts.pory"
	end
# 166 "data/maps/Route116/scripts.pory"

# 167 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesNotOnPlayer::
# 168 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
# 169 "data/maps/Route116/scripts.pory"
	closemessage
# 170 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 171 "data/maps/Route116/scripts.pory"
	end
# 172 "data/maps/Route116/scripts.pory"

# 173 "data/maps/Route116/scripts.pory"
Route116_EventScript_PlayerHasGlasses::
# 174 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 175 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
# 176 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 177 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
# 178 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
# 179 "data/maps/Route116/scripts.pory"
	release
# 180 "data/maps/Route116/scripts.pory"
	end
# 181 "data/maps/Route116/scripts.pory"

# 182 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesOnPlayer::
# 183 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
# 184 "data/maps/Route116/scripts.pory"
	closemessage
# 185 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 186 "data/maps/Route116/scripts.pory"
	end
# 187 "data/maps/Route116/scripts.pory"

# 188 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExit::
# 189 "data/maps/Route116/scripts.pory"
	delay 20
# 190 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
# 191 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
# 192 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
# 193 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
# 194 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 195 "data/maps/Route116/scripts.pory"
	release
# 196 "data/maps/Route116/scripts.pory"
	end
# 197 "data/maps/Route116/scripts.pory"

# 198 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitNormal::
# 199 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
# 200 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 201 "data/maps/Route116/scripts.pory"
	return
# 202 "data/maps/Route116/scripts.pory"

# 203 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitEast::
# 204 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
# 205 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 206 "data/maps/Route116/scripts.pory"
	return
# 207 "data/maps/Route116/scripts.pory"

# 208 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExit:
# 209 "data/maps/Route116/scripts.pory"
	walk_left
# 210 "data/maps/Route116/scripts.pory"
	walk_left
# 211 "data/maps/Route116/scripts.pory"
	walk_left
# 212 "data/maps/Route116/scripts.pory"
	walk_left
# 213 "data/maps/Route116/scripts.pory"
	walk_left
# 214 "data/maps/Route116/scripts.pory"
	walk_left
# 215 "data/maps/Route116/scripts.pory"
	walk_left
# 216 "data/maps/Route116/scripts.pory"
	walk_left
# 217 "data/maps/Route116/scripts.pory"
	walk_left
# 218 "data/maps/Route116/scripts.pory"
	step_end
# 219 "data/maps/Route116/scripts.pory"

# 220 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExitEast:
# 221 "data/maps/Route116/scripts.pory"
	walk_up
# 222 "data/maps/Route116/scripts.pory"
	walk_left
# 223 "data/maps/Route116/scripts.pory"
	walk_left
# 224 "data/maps/Route116/scripts.pory"
	walk_left
# 225 "data/maps/Route116/scripts.pory"
	walk_left
# 226 "data/maps/Route116/scripts.pory"
	walk_left
# 227 "data/maps/Route116/scripts.pory"
	walk_left
# 228 "data/maps/Route116/scripts.pory"
	walk_left
# 229 "data/maps/Route116/scripts.pory"
	walk_left
# 230 "data/maps/Route116/scripts.pory"
	walk_left
# 231 "data/maps/Route116/scripts.pory"
	step_end
# 232 "data/maps/Route116/scripts.pory"

# 233 "data/maps/Route116/scripts.pory"
Route116_EventScript_Joey::
# 234 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
# 235 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
# 236 "data/maps/Route116/scripts.pory"
	end
# 237 "data/maps/Route116/scripts.pory"

# 238 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jose::
# 239 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
# 240 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
# 241 "data/maps/Route116/scripts.pory"
	end
# 242 "data/maps/Route116/scripts.pory"

# 243 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jerry::
# 244 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
# 245 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 246 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
# 247 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_JERRY_1
# 248 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 249 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterJerry
# 250 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 251 "data/maps/Route116/scripts.pory"
	release
# 252 "data/maps/Route116/scripts.pory"
	end
# 253 "data/maps/Route116/scripts.pory"

# 254 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerryAfterBattle::
# 255 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
# 256 "data/maps/Route116/scripts.pory"
	release
# 257 "data/maps/Route116/scripts.pory"
	end
# 258 "data/maps/Route116/scripts.pory"

# 259 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerryAfterBattle::
# 260 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 261 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 262 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
# 263 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 264 "data/maps/Route116/scripts.pory"
	release
# 265 "data/maps/Route116/scripts.pory"
	end
# 266 "data/maps/Route116/scripts.pory"

# 267 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerry::
# 268 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
# 269 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 270 "data/maps/Route116/scripts.pory"
	release
# 271 "data/maps/Route116/scripts.pory"
	end
# 272 "data/maps/Route116/scripts.pory"

# 273 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerry::
# 274 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
# 275 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 276 "data/maps/Route116/scripts.pory"
	release
# 277 "data/maps/Route116/scripts.pory"
	end
# 278 "data/maps/Route116/scripts.pory"

# 279 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchJerry::
# 280 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
# 281 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
# 282 "data/maps/Route116/scripts.pory"
	end
# 283 "data/maps/Route116/scripts.pory"

# 284 "data/maps/Route116/scripts.pory"
Route116_EventScript_Clark::
# 285 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
# 286 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
# 287 "data/maps/Route116/scripts.pory"
	end
# 288 "data/maps/Route116/scripts.pory"

# 289 "data/maps/Route116/scripts.pory"
Route116_EventScript_Janice::
# 290 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
# 291 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
# 292 "data/maps/Route116/scripts.pory"
	end
# 293 "data/maps/Route116/scripts.pory"

# 294 "data/maps/Route116/scripts.pory"
Route116_EventScript_Karen::
# 295 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
# 296 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 297 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
# 298 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_KAREN_1
# 299 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 300 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterKaren
# 301 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 302 "data/maps/Route116/scripts.pory"
	release
# 303 "data/maps/Route116/scripts.pory"
	end
# 304 "data/maps/Route116/scripts.pory"

# 305 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKarenAfterBattle::
# 306 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
# 307 "data/maps/Route116/scripts.pory"
	release
# 308 "data/maps/Route116/scripts.pory"
	end
# 309 "data/maps/Route116/scripts.pory"

# 310 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKarenAfterBattle::
# 311 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 312 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 313 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
# 314 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 315 "data/maps/Route116/scripts.pory"
	release
# 316 "data/maps/Route116/scripts.pory"
	end
# 317 "data/maps/Route116/scripts.pory"

# 318 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKaren::
# 319 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
# 320 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 321 "data/maps/Route116/scripts.pory"
	release
# 322 "data/maps/Route116/scripts.pory"
	end
# 323 "data/maps/Route116/scripts.pory"

# 324 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKaren::
# 325 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
# 326 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 327 "data/maps/Route116/scripts.pory"
	release
# 328 "data/maps/Route116/scripts.pory"
	end
# 329 "data/maps/Route116/scripts.pory"

# 330 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchKaren::
# 331 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
# 332 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
# 333 "data/maps/Route116/scripts.pory"
	end
# 334 "data/maps/Route116/scripts.pory"

# 335 "data/maps/Route116/scripts.pory"
Route116_EventScript_Sarah::
# 336 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
# 337 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
# 338 "data/maps/Route116/scripts.pory"
	end
# 339 "data/maps/Route116/scripts.pory"

# 340 "data/maps/Route116/scripts.pory"
Route116_EventScript_Dawson::
# 341 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
# 342 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 343 "data/maps/Route116/scripts.pory"
	end
# 344 "data/maps/Route116/scripts.pory"

# 345 "data/maps/Route116/scripts.pory"
Route116_EventScript_Devan::
# 346 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
# 347 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
# 348 "data/maps/Route116/scripts.pory"
	end
# 349 "data/maps/Route116/scripts.pory"

# 350 "data/maps/Route116/scripts.pory"
Route116_EventScript_Johnson::
# 351 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
# 352 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
# 353 "data/maps/Route116/scripts.pory"
	end
# 354 "data/maps/Route116/scripts.pory"

# 355 "data/maps/Route116/scripts.pory"
Route116_Text_ScoundrelMadeOffWithPeeko:
# 356 "data/maps/Route116/scripts.pory"
	.string "Ohhh, what am I to do?\p"
# 357 "data/maps/Route116/scripts.pory"
	.string "We were on our walk, PEEKO and I, when\n"
# 358 "data/maps/Route116/scripts.pory"
	.string "we were jumped by an odd thug…\p"
# 359 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
# 360 "data/maps/Route116/scripts.pory"
	.string "darling PEEKO!\p"
# 361 "data/maps/Route116/scripts.pory"
	.string "Wrrrooooooaaaar! PEEKO!$"
# 362 "data/maps/Route116/scripts.pory"

# 363 "data/maps/Route116/scripts.pory"
Route116_Text_WantToDigTunnel:
# 364 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 365 "data/maps/Route116/scripts.pory"
	.string "I want to dig that tunnel!$"
# 366 "data/maps/Route116/scripts.pory"

# 367 "data/maps/Route116/scripts.pory"
Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
# 368 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\n"
# 369 "data/maps/Route116/scripts.pory"
	.string "What's going on?\p"
# 370 "data/maps/Route116/scripts.pory"
	.string "I was digging the tunnel without any\n"
# 371 "data/maps/Route116/scripts.pory"
	.string "tools when some goon ordered me out!\p"
# 372 "data/maps/Route116/scripts.pory"
	.string "That tunnel's filled with POKéMON\n"
# 373 "data/maps/Route116/scripts.pory"
	.string "that react badly to loud noises.\l"
# 374 "data/maps/Route116/scripts.pory"
	.string "They could cause an uproar.\p"
# 375 "data/maps/Route116/scripts.pory"
	.string "That's why we stopped using heavy\n"
# 376 "data/maps/Route116/scripts.pory"
	.string "equipment for tunneling…\p"
# 377 "data/maps/Route116/scripts.pory"
	.string "I'm worried that the goon will do\n"
# 378 "data/maps/Route116/scripts.pory"
	.string "something stupid and startle the\l"
# 379 "data/maps/Route116/scripts.pory"
	.string "POKéMON into an uproar.$"
# 380 "data/maps/Route116/scripts.pory"

# 381 "data/maps/Route116/scripts.pory"
Route116_Text_GoonHightailedItOutOfTunnel:
# 382 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 383 "data/maps/Route116/scripts.pory"
	.string "That goofy goon hightailed it out of\n"
# 384 "data/maps/Route116/scripts.pory"
	.string "the tunnel! I can go back to digging!$"
# 385 "data/maps/Route116/scripts.pory"

# 386 "data/maps/Route116/scripts.pory"
Route116_Text_ThankYouTokenOfAppreciation:
# 387 "data/maps/Route116/scripts.pory"
	.string "Oh! It's you!\p"
# 388 "data/maps/Route116/scripts.pory"
	.string "You're that person who not only helped\n"
# 389 "data/maps/Route116/scripts.pory"
	.string "me in PETALBURG WOODS, but also got\l"
# 390 "data/maps/Route116/scripts.pory"
	.string "back my stolen package and then even\l"
# 391 "data/maps/Route116/scripts.pory"
	.string "graciously delivered it to SLATEPORT!\p"
# 392 "data/maps/Route116/scripts.pory"
	.string "CAPT. STERN informed us that the\n"
# 393 "data/maps/Route116/scripts.pory"
	.string "package arrived, too!\p"
# 394 "data/maps/Route116/scripts.pory"
	.string "I thank you very, very much!\p"
# 395 "data/maps/Route116/scripts.pory"
	.string "Why, if I were a rain cloud, I would\n"
# 396 "data/maps/Route116/scripts.pory"
	.string "shower you with gratitude and hail\l"
# 397 "data/maps/Route116/scripts.pory"
	.string "you as a hero!\p"
# 398 "data/maps/Route116/scripts.pory"
	.string "For you, the most wonderful TRAINER,\n"
# 399 "data/maps/Route116/scripts.pory"
	.string "I bear good news!\p"
# 400 "data/maps/Route116/scripts.pory"
	.string "Recently, our company developed\n"
# 401 "data/maps/Route116/scripts.pory"
	.string "a new kind of POKé BALL.\p"
# 402 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation, this\n"
# 403 "data/maps/Route116/scripts.pory"
	.string "is our gift to our wonderful TRAINER!$"
# 404 "data/maps/Route116/scripts.pory"

# 405 "data/maps/Route116/scripts.pory"
Route116_Text_NewBallAvailableAtMart:
# 406 "data/maps/Route116/scripts.pory"
	.string "Our new POKé BALL will be available\n"
# 407 "data/maps/Route116/scripts.pory"
	.string "at the POKéMON MART in RUSTBORO.\p"
# 408 "data/maps/Route116/scripts.pory"
	.string "Please do try it out!\n"
# 409 "data/maps/Route116/scripts.pory"
	.string "Thank you and bye-bye!$"
# 410 "data/maps/Route116/scripts.pory"

# 411 "data/maps/Route116/scripts.pory"
Route116_Text_BagIsJamPacked:
# 412 "data/maps/Route116/scripts.pory"
	.string "Your BAG is jam-packed.\n"
# 413 "data/maps/Route116/scripts.pory"
	.string "I can't give you this REPEAT BALL.$"
# 414 "data/maps/Route116/scripts.pory"

# 415 "data/maps/Route116/scripts.pory"
Route116_Text_TokenOfAppreciation:
# 416 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation for\n"
# 417 "data/maps/Route116/scripts.pory"
	.string "your delivering our package, I have\l"
# 418 "data/maps/Route116/scripts.pory"
	.string "a gift of a new kind of POKé BALL\l"
# 419 "data/maps/Route116/scripts.pory"
	.string "for our most wonderful TRAINER!$"
# 420 "data/maps/Route116/scripts.pory"

# 421 "data/maps/Route116/scripts.pory"
Route116_Text_CanYouHelpMeFindGlasses:
# 422 "data/maps/Route116/scripts.pory"
	.string "I dropped my glasses…\n"
# 423 "data/maps/Route116/scripts.pory"
	.string "Can you help me find them?$"
# 424 "data/maps/Route116/scripts.pory"

# 425 "data/maps/Route116/scripts.pory"
Route116_Text_MayISeeThoseGlasses:
# 426 "data/maps/Route116/scripts.pory"
	.string "Those glasses!\n"
# 427 "data/maps/Route116/scripts.pory"
	.string "May I see them for a second?$"
# 428 "data/maps/Route116/scripts.pory"

# 429 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
# 430 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 431 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 432 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…\p"
# 433 "data/maps/Route116/scripts.pory"
	.string "Maybe my glasses aren't around\n"
# 434 "data/maps/Route116/scripts.pory"
	.string "here…$"
# 435 "data/maps/Route116/scripts.pory"

# 436 "data/maps/Route116/scripts.pory"
Route116_Text_CantFindGlassesNotHere:
# 437 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 438 "data/maps/Route116/scripts.pory"
	.string "I can't find my glasses anywhere…\l"
# 439 "data/maps/Route116/scripts.pory"
	.string "Maybe they're not around here…$"
# 440 "data/maps/Route116/scripts.pory"

# 441 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingFor:
# 442 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 443 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 444 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…$"
# 445 "data/maps/Route116/scripts.pory"

# 446 "data/maps/Route116/scripts.pory"
Route116_Text_RouteSignRustboro:
# 447 "data/maps/Route116/scripts.pory"
	.string "ROUTE 116\n"
# 448 "data/maps/Route116/scripts.pory"
	.string "{LEFT_ARROW} RUSTBORO CITY$"
# 449 "data/maps/Route116/scripts.pory"

# 450 "data/maps/Route116/scripts.pory"
Route116_Text_RusturfTunnelSign:
# 451 "data/maps/Route116/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 452 "data/maps/Route116/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 453 "data/maps/Route116/scripts.pory"
	.string "“The tunnel project has been\n"
# 454 "data/maps/Route116/scripts.pory"
	.string "canceled.”$"
# 455 "data/maps/Route116/scripts.pory"

# 456 "data/maps/Route116/scripts.pory"
Route116_Text_TunnelersRestHouse:
# 457 "data/maps/Route116/scripts.pory"
	.string "TUNNELER'S REST HOUSE$"
# 458 "data/maps/Route116/scripts.pory"

# 459 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBToStopEvolution:
# 460 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 461 "data/maps/Route116/scripts.pory"
	.string "If you want to stop a POKéMON from\n"
# 462 "data/maps/Route116/scripts.pory"
	.string "evolving, press the B Button while it\l"
# 463 "data/maps/Route116/scripts.pory"
	.string "is trying to evolve.\l"
# 464 "data/maps/Route116/scripts.pory"
	.string "The startled POKéMON will stop.\p"
# 465 "data/maps/Route116/scripts.pory"
	.string "This is called an evolution cancel.$"
# 466 "data/maps/Route116/scripts.pory"

# 467 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBagHasPockets:
# 468 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 469 "data/maps/Route116/scripts.pory"
	.string "Your BAG has several POCKETS.\p"
# 470 "data/maps/Route116/scripts.pory"
	.string "Items you obtain are automatically\n"
# 471 "data/maps/Route116/scripts.pory"
	.string "placed in the appropriate POCKETS.\p"
# 472 "data/maps/Route116/scripts.pory"
	.string "No TRAINER can afford to be without\n"
# 473 "data/maps/Route116/scripts.pory"
	.string "a BAG of their own.$"
