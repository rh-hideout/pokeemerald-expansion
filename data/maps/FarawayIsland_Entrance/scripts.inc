# 1 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 2 "data/maps/FarawayIsland_Entrance/scripts.pory"
.set LOCALID_SAILOR, 1
# 3 "data/maps/FarawayIsland_Entrance/scripts.pory"
.set LOCALID_SS_TIDAL, 2
# 4 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 5 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_MapScripts::
# 6 "data/maps/FarawayIsland_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_OnTransition
# 7 "data/maps/FarawayIsland_Entrance/scripts.pory"
	.byte 0
# 8 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 9 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_OnTransition:
# 10 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setflag FLAG_ARRIVED_ON_FARAWAY_ISLAND
# 11 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 12 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 13 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_SetCloudsWeather::
# 14 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 15 "data/maps/FarawayIsland_Entrance/scripts.pory"
	doweather
# 16 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 17 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 18 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_ClearWeather::
# 19 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setweather WEATHER_NONE
# 20 "data/maps/FarawayIsland_Entrance/scripts.pory"
	doweather
# 21 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 22 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 23 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_Sailor::
# 24 "data/maps/FarawayIsland_Entrance/scripts.pory"
	lock
# 25 "data/maps/FarawayIsland_Entrance/scripts.pory"
	faceplayer
# 26 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
# 27 "data/maps/FarawayIsland_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FarawayIsland_Entrance_EventScript_AsYouLike
# 28 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
# 29 "data/maps/FarawayIsland_Entrance/scripts.pory"
	closemessage
# 30 "data/maps/FarawayIsland_Entrance/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 31 "data/maps/FarawayIsland_Entrance/scripts.pory"
	waitmovement 0
# 32 "data/maps/FarawayIsland_Entrance/scripts.pory"
	delay 30
# 33 "data/maps/FarawayIsland_Entrance/scripts.pory"
	hideobjectat LOCALID_SAILOR, MAP_FARAWAY_ISLAND_ENTRANCE
# 34 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 35 "data/maps/FarawayIsland_Entrance/scripts.pory"
	call Common_EventScript_FerryDepartIsland
# 36 "data/maps/FarawayIsland_Entrance/scripts.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
# 37 "data/maps/FarawayIsland_Entrance/scripts.pory"
	waitstate
# 38 "data/maps/FarawayIsland_Entrance/scripts.pory"
	release
# 39 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 40 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 41 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_AsYouLike::
# 42 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
# 43 "data/maps/FarawayIsland_Entrance/scripts.pory"
	release
# 44 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 45 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 46 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_Sign::
# 47 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox FarawayIsland_Entrance_Text_Sign, MSGBOX_SIGN
# 48 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
