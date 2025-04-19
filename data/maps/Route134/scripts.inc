# 1 "data/maps/Route134/scripts.pory"

# 2 "data/maps/Route134/scripts.pory"
Route134_MapScripts::
# 3 "data/maps/Route134/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route134_OnResume
# 4 "data/maps/Route134/scripts.pory"
	.byte 0
# 5 "data/maps/Route134/scripts.pory"

# 6 "data/maps/Route134/scripts.pory"
Route134_OnResume:
# 7 "data/maps/Route134/scripts.pory"
	setdivewarp MAP_UNDERWATER_ROUTE134, 8, 6
# 8 "data/maps/Route134/scripts.pory"
	end
# 9 "data/maps/Route134/scripts.pory"

# 10 "data/maps/Route134/scripts.pory"
Route134_EventScript_Jack::
# 11 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_JACK, Route134_Text_JackIntro, Route134_Text_JackDefeat
# 12 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_JackPostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/Route134/scripts.pory"
	end
# 14 "data/maps/Route134/scripts.pory"

# 15 "data/maps/Route134/scripts.pory"
Route134_EventScript_Laurel::
# 16 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_LAUREL, Route134_Text_LaurelIntro, Route134_Text_LaurelDefeat
# 17 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
# 18 "data/maps/Route134/scripts.pory"
	end
# 19 "data/maps/Route134/scripts.pory"

# 20 "data/maps/Route134/scripts.pory"
Route134_EventScript_Alex::
# 21 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_ALEX, Route134_Text_AlexIntro, Route134_Text_AlexDefeat
# 22 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
# 23 "data/maps/Route134/scripts.pory"
	end
# 24 "data/maps/Route134/scripts.pory"

# 25 "data/maps/Route134/scripts.pory"
Route134_EventScript_Aaron::
# 26 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_AARON, Route134_Text_AaronIntro, Route134_Text_AaronDefeat
# 27 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
# 28 "data/maps/Route134/scripts.pory"
	end
# 29 "data/maps/Route134/scripts.pory"

# 30 "data/maps/Route134/scripts.pory"
Route134_EventScript_Hitoshi::
# 31 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_HITOSHI, Route134_Text_HitoshiIntro, Route134_Text_HitoshiDefeat
# 32 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
# 33 "data/maps/Route134/scripts.pory"
	end
# 34 "data/maps/Route134/scripts.pory"

# 35 "data/maps/Route134/scripts.pory"
Route134_EventScript_Hudson::
# 36 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_HUDSON, Route134_Text_HudsonIntro, Route134_Text_HudsonDefeat
# 37 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_HudsonPostBattle, MSGBOX_AUTOCLOSE
# 38 "data/maps/Route134/scripts.pory"
	end
# 39 "data/maps/Route134/scripts.pory"

# 40 "data/maps/Route134/scripts.pory"
Route134_EventScript_Reyna::
# 41 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_REYNA, Route134_Text_ReynaIntro, Route134_Text_ReynaDefeat
# 42 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_ReynaPostBattle, MSGBOX_AUTOCLOSE
# 43 "data/maps/Route134/scripts.pory"
	end
# 44 "data/maps/Route134/scripts.pory"

# 45 "data/maps/Route134/scripts.pory"
Route134_EventScript_Marley::
# 46 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_MARLEY, Route134_Text_MarleyIntro, Route134_Text_MarleyDefeat
# 47 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_MarleyPostBattle, MSGBOX_AUTOCLOSE
# 48 "data/maps/Route134/scripts.pory"
	end
# 49 "data/maps/Route134/scripts.pory"

# 50 "data/maps/Route134/scripts.pory"
Route134_EventScript_Kelvin::
# 51 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_KELVIN, Route134_Text_KelvinIntro, Route134_Text_KelvinDefeat
# 52 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_KelvinPostBattle, MSGBOX_AUTOCLOSE
# 53 "data/maps/Route134/scripts.pory"
	end
