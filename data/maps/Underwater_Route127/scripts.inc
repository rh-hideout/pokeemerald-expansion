# 1 "data/maps/Underwater_Route127/scripts.pory"

# 2 "data/maps/Underwater_Route127/scripts.pory"
Underwater_Route127_MapScripts::
# 3 "data/maps/Underwater_Route127/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route127_OnResume
# 4 "data/maps/Underwater_Route127/scripts.pory"
	.byte 0
# 5 "data/maps/Underwater_Route127/scripts.pory"

# 6 "data/maps/Underwater_Route127/scripts.pory"
Underwater_Route127_OnResume:
# 7 "data/maps/Underwater_Route127/scripts.pory"
	call AbnormalWeather_Underwater_SetupEscapeWarp
# 8 "data/maps/Underwater_Route127/scripts.pory"
	end
