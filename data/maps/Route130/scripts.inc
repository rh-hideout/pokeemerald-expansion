# 1 "data/maps/Route130/scripts.pory"

# 2 "data/maps/Route130/scripts.pory"
Route130_MapScripts::
# 3 "data/maps/Route130/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route130_OnTransition
# 4 "data/maps/Route130/scripts.pory"
	.byte 0
# 5 "data/maps/Route130/scripts.pory"

# 6 "data/maps/Route130/scripts.pory"
Route130_OnTransition:
# 7 "data/maps/Route130/scripts.pory"
	call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, Route130_EventScript_CheckSetAbnormalWeather
# 8 "data/maps/Route130/scripts.pory"
	specialvar VAR_RESULT, IsMirageIslandPresent
# 9 "data/maps/Route130/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route130_EventScript_SetMirageIslandLayout
# 10 "data/maps/Route130/scripts.pory"
@ Mirage Island isn't currently visible, hide any objects on the island. Only the first flag is actually associated with anything.
# 11 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_HIDE_MIRAGE_ISLAND_BERRY_TREE
# 12 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_12
# 13 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_13
# 14 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_14
# 15 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_15
# 16 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_16
# 17 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_17
# 18 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_18
# 19 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_19
# 20 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_1A
# 21 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_1B
# 22 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_1C
# 23 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_1D
# 24 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_1E
# 25 "data/maps/Route130/scripts.pory"
	setflag FLAG_TEMP_1F
# 26 "data/maps/Route130/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE130
# 27 "data/maps/Route130/scripts.pory"
	end
# 28 "data/maps/Route130/scripts.pory"

# 29 "data/maps/Route130/scripts.pory"
Route130_EventScript_SetMirageIslandLayout::
# 30 "data/maps/Route130/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE130_MIRAGE_ISLAND
# 31 "data/maps/Route130/scripts.pory"
	end
# 32 "data/maps/Route130/scripts.pory"

# 33 "data/maps/Route130/scripts.pory"
Route130_EventScript_CheckSetAbnormalWeather::
# 34 "data/maps/Route130/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 35 "data/maps/Route130/scripts.pory"
	return
# 36 "data/maps/Route130/scripts.pory"

# 37 "data/maps/Route130/scripts.pory"
Route130_EventScript_Rodney::
# 38 "data/maps/Route130/scripts.pory"
	trainerbattle_single TRAINER_RODNEY, Route130_Text_RodneyIntro, Route130_Text_RodneyDefeat
# 39 "data/maps/Route130/scripts.pory"
	msgbox Route130_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
# 40 "data/maps/Route130/scripts.pory"
	end
# 41 "data/maps/Route130/scripts.pory"

# 42 "data/maps/Route130/scripts.pory"
Route130_EventScript_Katie::
# 43 "data/maps/Route130/scripts.pory"
	trainerbattle_single TRAINER_KATIE, Route130_Text_KatieIntro, Route130_Text_KatieDefeat
# 44 "data/maps/Route130/scripts.pory"
	msgbox Route130_Text_KatiePostBattle, MSGBOX_AUTOCLOSE
# 45 "data/maps/Route130/scripts.pory"
	end
# 46 "data/maps/Route130/scripts.pory"

# 47 "data/maps/Route130/scripts.pory"
Route130_EventScript_Santiago::
# 48 "data/maps/Route130/scripts.pory"
	trainerbattle_single TRAINER_SANTIAGO, Route130_Text_SantiagoIntro, Route130_Text_SantiagoDefeat
# 49 "data/maps/Route130/scripts.pory"
	msgbox Route130_Text_SantiagoPostBattle, MSGBOX_AUTOCLOSE
# 50 "data/maps/Route130/scripts.pory"
	end
