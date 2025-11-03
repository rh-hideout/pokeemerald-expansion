# 1 "data/maps/Underwater_Route125/scripts.pory"

# 2 "data/maps/Underwater_Route125/scripts.pory"
Underwater_Route125_MapScripts::
# 3 "data/maps/Underwater_Route125/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route125_OnResume
# 4 "data/maps/Underwater_Route125/scripts.pory"
	.byte 0
# 5 "data/maps/Underwater_Route125/scripts.pory"

# 6 "data/maps/Underwater_Route125/scripts.pory"
Underwater_Route125_OnResume:
# 7 "data/maps/Underwater_Route125/scripts.pory"
	call AbnormalWeather_Underwater_SetupEscapeWarp
# 8 "data/maps/Underwater_Route125/scripts.pory"
	end
