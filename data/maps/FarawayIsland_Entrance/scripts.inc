# 1 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 2 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_MapScripts::
# 3 "data/maps/FarawayIsland_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_OnTransition
# 4 "data/maps/FarawayIsland_Entrance/scripts.pory"
	.byte 0
# 5 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 6 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_OnTransition:
# 7 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setflag FLAG_ARRIVED_ON_FARAWAY_ISLAND
# 8 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 9 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 10 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_SetCloudsWeather::
# 11 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 12 "data/maps/FarawayIsland_Entrance/scripts.pory"
	doweather
# 13 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 14 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 15 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_ClearWeather::
# 16 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setweather WEATHER_NONE
# 17 "data/maps/FarawayIsland_Entrance/scripts.pory"
	doweather
# 18 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 19 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 20 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_Sailor::
# 21 "data/maps/FarawayIsland_Entrance/scripts.pory"
	lock
# 22 "data/maps/FarawayIsland_Entrance/scripts.pory"
	faceplayer
# 23 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
# 24 "data/maps/FarawayIsland_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FarawayIsland_Entrance_EventScript_AsYouLike
# 25 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
# 26 "data/maps/FarawayIsland_Entrance/scripts.pory"
	closemessage
# 27 "data/maps/FarawayIsland_Entrance/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 28 "data/maps/FarawayIsland_Entrance/scripts.pory"
	waitmovement 0
# 29 "data/maps/FarawayIsland_Entrance/scripts.pory"
	delay 30
# 30 "data/maps/FarawayIsland_Entrance/scripts.pory"
	hideobjectat LOCALID_FARAWAY_ISLAND_SAILOR, MAP_FARAWAY_ISLAND_ENTRANCE
# 31 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setvar VAR_0x8004, LOCALID_FARAWAY_ISLAND_SS_TIDAL
# 32 "data/maps/FarawayIsland_Entrance/scripts.pory"
	call Common_EventScript_FerryDepartIsland
# 33 "data/maps/FarawayIsland_Entrance/scripts.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
# 34 "data/maps/FarawayIsland_Entrance/scripts.pory"
	waitstate
# 35 "data/maps/FarawayIsland_Entrance/scripts.pory"
	release
# 36 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 37 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 38 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_AsYouLike::
# 39 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
# 40 "data/maps/FarawayIsland_Entrance/scripts.pory"
	release
# 41 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 42 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 43 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_Sign::
# 44 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox FarawayIsland_Entrance_Text_Sign, MSGBOX_SIGN
# 45 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
