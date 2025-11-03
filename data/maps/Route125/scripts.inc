# 1 "data/maps/Route125/scripts.pory"

# 2 "data/maps/Route125/scripts.pory"
Route125_MapScripts::
# 3 "data/maps/Route125/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route125_OnTransition
# 4 "data/maps/Route125/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route125_OnLoad
# 5 "data/maps/Route125/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route125_OnFrame
# 6 "data/maps/Route125/scripts.pory"
	.byte 0
# 7 "data/maps/Route125/scripts.pory"

# 8 "data/maps/Route125/scripts.pory"
Route125_OnTransition:
# 9 "data/maps/Route125/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 10 "data/maps/Route125/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 11 "data/maps/Route125/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_125_WEST, AbnormalWeather_StartKyogreWeather
# 12 "data/maps/Route125/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_125_EAST, AbnormalWeather_StartKyogreWeather
# 13 "data/maps/Route125/scripts.pory"
	end
# 14 "data/maps/Route125/scripts.pory"

# 15 "data/maps/Route125/scripts.pory"
Route125_OnLoad:
# 16 "data/maps/Route125/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_125_WEST, AbnormalWeather_EventScript_PlaceTilesRoute125West
# 17 "data/maps/Route125/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_125_EAST, AbnormalWeather_EventScript_PlaceTilesRoute125East
# 18 "data/maps/Route125/scripts.pory"
	end
# 19 "data/maps/Route125/scripts.pory"

# 20 "data/maps/Route125/scripts.pory"
Route125_OnFrame:
# 21 "data/maps/Route125/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 22 "data/maps/Route125/scripts.pory"
	.2byte 0
# 23 "data/maps/Route125/scripts.pory"

# 24 "data/maps/Route125/scripts.pory"
Route125_EventScript_Nolen::
# 25 "data/maps/Route125/scripts.pory"
	trainerbattle_single TRAINER_NOLEN, Route125_Text_NolenIntro, Route125_Text_NolenDefeat
# 26 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_NolenPostBattle, MSGBOX_AUTOCLOSE
# 27 "data/maps/Route125/scripts.pory"
	end
# 28 "data/maps/Route125/scripts.pory"

# 29 "data/maps/Route125/scripts.pory"
Route125_EventScript_Stan::
# 30 "data/maps/Route125/scripts.pory"
	trainerbattle_single TRAINER_STAN, Route125_Text_StanIntro, Route125_Text_StanDefeat
# 31 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_StanPostBattle, MSGBOX_AUTOCLOSE
# 32 "data/maps/Route125/scripts.pory"
	end
# 33 "data/maps/Route125/scripts.pory"

# 34 "data/maps/Route125/scripts.pory"
Route125_EventScript_Tanya::
# 35 "data/maps/Route125/scripts.pory"
	trainerbattle_single TRAINER_TANYA, Route125_Text_TanyaIntro, Route125_Text_TanyaDefeat
# 36 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_TanyaPostBattle, MSGBOX_AUTOCLOSE
# 37 "data/maps/Route125/scripts.pory"
	end
# 38 "data/maps/Route125/scripts.pory"

# 39 "data/maps/Route125/scripts.pory"
Route125_EventScript_Sharon::
# 40 "data/maps/Route125/scripts.pory"
	trainerbattle_single TRAINER_SHARON, Route125_Text_SharonIntro, Route125_Text_SharonDefeat
# 41 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_SharonPostBattle, MSGBOX_AUTOCLOSE
# 42 "data/maps/Route125/scripts.pory"
	end
# 43 "data/maps/Route125/scripts.pory"

# 44 "data/maps/Route125/scripts.pory"
Route125_EventScript_Ernest::
# 45 "data/maps/Route125/scripts.pory"
	trainerbattle_single TRAINER_ERNEST_1, Route125_Text_ErnestIntro, Route125_Text_ErnestDefeat, Route125_EventScript_RegisterErnest
# 46 "data/maps/Route125/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 47 "data/maps/Route125/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route125_EventScript_RematchErnest
# 48 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_ErnestPostBattle, MSGBOX_DEFAULT
# 49 "data/maps/Route125/scripts.pory"
	release
# 50 "data/maps/Route125/scripts.pory"
	end
# 51 "data/maps/Route125/scripts.pory"

# 52 "data/maps/Route125/scripts.pory"
Route125_EventScript_RegisterErnest::
# 53 "data/maps/Route125/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 54 "data/maps/Route125/scripts.pory"
	waitmovement 0
# 55 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_ErnestRegister, MSGBOX_DEFAULT
# 56 "data/maps/Route125/scripts.pory"
	register_matchcall TRAINER_ERNEST_1
# 57 "data/maps/Route125/scripts.pory"
	release
# 58 "data/maps/Route125/scripts.pory"
	end
# 59 "data/maps/Route125/scripts.pory"

# 60 "data/maps/Route125/scripts.pory"
Route125_EventScript_RematchErnest::
# 61 "data/maps/Route125/scripts.pory"
	trainerbattle_rematch TRAINER_ERNEST_1, Route125_Text_ErnestRematchIntro, Route125_Text_ErnestRematchDefeat
# 62 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_ErnestRematchPostBattle, MSGBOX_AUTOCLOSE
# 63 "data/maps/Route125/scripts.pory"
	end
# 64 "data/maps/Route125/scripts.pory"

# 65 "data/maps/Route125/scripts.pory"
Route125_EventScript_Kim::
# 66 "data/maps/Route125/scripts.pory"
	trainerbattle_double TRAINER_KIM_AND_IRIS, Route125_Text_KimIntro, Route125_Text_KimDefeat, Route125_Text_KimNotEnoughMons
# 67 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_KimPostBattle, MSGBOX_AUTOCLOSE
# 68 "data/maps/Route125/scripts.pory"
	end
# 69 "data/maps/Route125/scripts.pory"

# 70 "data/maps/Route125/scripts.pory"
Route125_EventScript_Iris::
# 71 "data/maps/Route125/scripts.pory"
	trainerbattle_double TRAINER_KIM_AND_IRIS, Route125_Text_IrisIntro, Route125_Text_IrisDefeat, Route125_Text_IrisNotEnoughMons
# 72 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_IrisPostBattle, MSGBOX_AUTOCLOSE
# 73 "data/maps/Route125/scripts.pory"
	end
# 74 "data/maps/Route125/scripts.pory"

# 75 "data/maps/Route125/scripts.pory"
Route125_EventScript_Presley::
# 76 "data/maps/Route125/scripts.pory"
	trainerbattle_single TRAINER_PRESLEY, Route125_Text_PresleyIntro, Route125_Text_PresleyDefeat
# 77 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_PresleyPostBattle, MSGBOX_AUTOCLOSE
# 78 "data/maps/Route125/scripts.pory"
	end
# 79 "data/maps/Route125/scripts.pory"

# 80 "data/maps/Route125/scripts.pory"
Route125_EventScript_Auron::
# 81 "data/maps/Route125/scripts.pory"
	trainerbattle_single TRAINER_AURON, Route125_Text_AuronIntro, Route125_Text_AuronDefeat
# 82 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_AuronPostBattle, MSGBOX_AUTOCLOSE
# 83 "data/maps/Route125/scripts.pory"
	end
