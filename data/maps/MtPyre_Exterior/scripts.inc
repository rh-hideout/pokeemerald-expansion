# 1 "data/maps/MtPyre_Exterior/scripts.pory"

# 2 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_MapScripts::
# 3 "data/maps/MtPyre_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
# 4 "data/maps/MtPyre_Exterior/scripts.pory"
	.byte 0
# 5 "data/maps/MtPyre_Exterior/scripts.pory"

# 6 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_OnTransition:
# 7 "data/maps/MtPyre_Exterior/scripts.pory"
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
# 8 "data/maps/MtPyre_Exterior/scripts.pory"
	end
# 9 "data/maps/MtPyre_Exterior/scripts.pory"

# 10 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_CheckEnterFromSummit::
# 11 "data/maps/MtPyre_Exterior/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 12 "data/maps/MtPyre_Exterior/scripts.pory"
	goto_if_lt VAR_TEMP_1, 12, MtPyre_Exterior_EventScript_EnterFromSummit
# 13 "data/maps/MtPyre_Exterior/scripts.pory"
	return
# 14 "data/maps/MtPyre_Exterior/scripts.pory"

# 15 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_EnterFromSummit::
# 16 "data/maps/MtPyre_Exterior/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 17 "data/maps/MtPyre_Exterior/scripts.pory"
	return
# 18 "data/maps/MtPyre_Exterior/scripts.pory"

# 19 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_FogTrigger::
# 20 "data/maps/MtPyre_Exterior/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 21 "data/maps/MtPyre_Exterior/scripts.pory"
	doweather
# 22 "data/maps/MtPyre_Exterior/scripts.pory"
	end
# 23 "data/maps/MtPyre_Exterior/scripts.pory"

# 24 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_SunTrigger::
# 25 "data/maps/MtPyre_Exterior/scripts.pory"
	setweather WEATHER_SUNNY
# 26 "data/maps/MtPyre_Exterior/scripts.pory"
	doweather
# 27 "data/maps/MtPyre_Exterior/scripts.pory"
	end
