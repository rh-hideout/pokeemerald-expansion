# 1 "data/maps/Underwater_Route129/scripts.pory"

# 2 "data/maps/Underwater_Route129/scripts.pory"
Underwater_Route129_MapScripts::
# 3 "data/maps/Underwater_Route129/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route129_OnResume
# 4 "data/maps/Underwater_Route129/scripts.pory"
	.byte 0
# 5 "data/maps/Underwater_Route129/scripts.pory"

# 6 "data/maps/Underwater_Route129/scripts.pory"
Underwater_Route129_OnResume:
# 7 "data/maps/Underwater_Route129/scripts.pory"
	call AbnormalWeather_Underwater_SetupEscapeWarp
# 8 "data/maps/Underwater_Route129/scripts.pory"
	end
