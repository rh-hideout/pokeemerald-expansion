# 1 "data/maps/Route105/scripts.pory"

# 2 "data/maps/Route105/scripts.pory"
Route105_MapScripts::
# 3 "data/maps/Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route105_OnLoad
# 4 "data/maps/Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route105_OnTransition
# 5 "data/maps/Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route105_OnFrame
# 6 "data/maps/Route105/scripts.pory"
	.byte 0
# 7 "data/maps/Route105/scripts.pory"

# 8 "data/maps/Route105/scripts.pory"
Route105_OnLoad:
# 9 "data/maps/Route105/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route105_CloseRegiEntrance
# 10 "data/maps/Route105/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute105North
# 11 "data/maps/Route105/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute105South
# 12 "data/maps/Route105/scripts.pory"
	end
# 13 "data/maps/Route105/scripts.pory"

# 14 "data/maps/Route105/scripts.pory"
Route105_CloseRegiEntrance::
# 15 "data/maps/Route105/scripts.pory"
	setmetatile 9, 19, METATILE_General_RockWall_RockBase, TRUE
# 16 "data/maps/Route105/scripts.pory"
	setmetatile 9, 20, METATILE_General_RockWall_SandBase, TRUE
# 17 "data/maps/Route105/scripts.pory"
	return
# 18 "data/maps/Route105/scripts.pory"

# 19 "data/maps/Route105/scripts.pory"
Route105_OnTransition:
# 20 "data/maps/Route105/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 21 "data/maps/Route105/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH, AbnormalWeather_StartKyogreWeather
# 22 "data/maps/Route105/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH, AbnormalWeather_StartKyogreWeather
# 23 "data/maps/Route105/scripts.pory"
	end
# 24 "data/maps/Route105/scripts.pory"

# 25 "data/maps/Route105/scripts.pory"
Route105_OnFrame:
# 26 "data/maps/Route105/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 27 "data/maps/Route105/scripts.pory"
	.2byte 0
# 28 "data/maps/Route105/scripts.pory"

# 29 "data/maps/Route105/scripts.pory"
Route105_EventScript_Foster::
# 30 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_FOSTER, Route105_Text_FosterIntro, Route105_Text_FosterDefeated
# 31 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
# 32 "data/maps/Route105/scripts.pory"
	end
# 33 "data/maps/Route105/scripts.pory"

# 34 "data/maps/Route105/scripts.pory"
Route105_EventScript_Luis::
# 35 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_LUIS, Route105_Text_LuisIntro, Route105_Text_LuisDefeated
# 36 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
# 37 "data/maps/Route105/scripts.pory"
	end
# 38 "data/maps/Route105/scripts.pory"

# 39 "data/maps/Route105/scripts.pory"
Route105_EventScript_Dominik::
# 40 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_DOMINIK, Route105_Text_DominikIntro, Route105_Text_DominikDefeated
# 41 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_DominikPostBattle, MSGBOX_AUTOCLOSE
# 42 "data/maps/Route105/scripts.pory"
	end
# 43 "data/maps/Route105/scripts.pory"

# 44 "data/maps/Route105/scripts.pory"
Route105_EventScript_Beverly::
# 45 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_BEVERLY, Route105_Text_BeverlyIntro, Route105_Text_BeverlyDefeated
# 46 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_PostBattle, MSGBOX_AUTOCLOSE
# 47 "data/maps/Route105/scripts.pory"
	end
# 48 "data/maps/Route105/scripts.pory"

# 49 "data/maps/Route105/scripts.pory"
Route105_EventScript_Imani::
# 50 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_IMANI, Route105_Text_ImaniIntro, Route105_Text_ImaniDefeated
# 51 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_ImaniPostBattle, MSGBOX_AUTOCLOSE
# 52 "data/maps/Route105/scripts.pory"
	end
# 53 "data/maps/Route105/scripts.pory"

# 54 "data/maps/Route105/scripts.pory"
Route105_EventScript_Josue::
# 55 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_JOSUE, Route105_Text_JosueIntro, Route105_Text_JosueDefeated
# 56 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_JosuePostBattle, MSGBOX_AUTOCLOSE
# 57 "data/maps/Route105/scripts.pory"
	end
# 58 "data/maps/Route105/scripts.pory"

# 59 "data/maps/Route105/scripts.pory"
Route105_EventScript_Andres::
# 60 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_ANDRES_1, Route105_Text_AndresIntro, Route105_Text_AndresDefeated, Route105_EventScript_AndresRegisterMatchCallAfterBattle
# 61 "data/maps/Route105/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 62 "data/maps/Route105/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route105_EventScript_AndresRematch
# 63 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_AndresPostBattle, MSGBOX_DEFAULT
# 64 "data/maps/Route105/scripts.pory"
	release
# 65 "data/maps/Route105/scripts.pory"
	end
# 66 "data/maps/Route105/scripts.pory"

# 67 "data/maps/Route105/scripts.pory"
Route105_EventScript_AndresRegisterMatchCallAfterBattle::
# 68 "data/maps/Route105/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 69 "data/maps/Route105/scripts.pory"
	waitmovement 0
# 70 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_AndresRegister, MSGBOX_DEFAULT
# 71 "data/maps/Route105/scripts.pory"
	register_matchcall TRAINER_ANDRES_1
# 72 "data/maps/Route105/scripts.pory"
	release
# 73 "data/maps/Route105/scripts.pory"
	end
# 74 "data/maps/Route105/scripts.pory"

# 75 "data/maps/Route105/scripts.pory"
Route105_EventScript_AndresRematch::
# 76 "data/maps/Route105/scripts.pory"
	trainerbattle_rematch TRAINER_ANDRES_1, Route105_Text_AndresRematchIntro, Route105_Text_AndresRematchDefeated
# 77 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_AndresRematchPostBattle, MSGBOX_AUTOCLOSE
# 78 "data/maps/Route105/scripts.pory"
	end
# 79 "data/maps/Route105/scripts.pory"

# 80 "data/maps/Route105/scripts.pory"
Route104_Text_DadPokenavCall:
# 81 "data/maps/Route105/scripts.pory"
	.string "… … … … … …\n"
# 82 "data/maps/Route105/scripts.pory"
	.string "… … … … … Beep!\p"
# 83 "data/maps/Route105/scripts.pory"
	.string "DAD: Oh, {PLAYER}?\p"
# 84 "data/maps/Route105/scripts.pory"
	.string "… … … … … …\n"
# 85 "data/maps/Route105/scripts.pory"
	.string "Where are you now?\l"
# 86 "data/maps/Route105/scripts.pory"
	.string "It sounds windy wherever you are.\p"
# 87 "data/maps/Route105/scripts.pory"
	.string "I just heard from DEVON's MR. STONE\n"
# 88 "data/maps/Route105/scripts.pory"
	.string "about your POKéNAV, so I decided\l"
# 89 "data/maps/Route105/scripts.pory"
	.string "to give you a call.\p"
# 90 "data/maps/Route105/scripts.pory"
	.string "It sounds like you're doing fine,\n"
# 91 "data/maps/Route105/scripts.pory"
	.string "so that's fine with me.\p"
# 92 "data/maps/Route105/scripts.pory"
	.string "You take care now.\p"
# 93 "data/maps/Route105/scripts.pory"
	.string "… … … … … …\n"
# 94 "data/maps/Route105/scripts.pory"
	.string "… … … … … Click!$"
# 95 "data/maps/Route105/scripts.pory"

# 96 "data/maps/Route105/scripts.pory"
Route104_Text_RegisteredDadInPokenav:
# 97 "data/maps/Route105/scripts.pory"
	.string "Registered DAD NORMAN\n"
# 98 "data/maps/Route105/scripts.pory"
	.string "in the POKéNAV.$"
