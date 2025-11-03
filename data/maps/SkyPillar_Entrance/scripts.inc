# 1 "data/maps/SkyPillar_Entrance/scripts.pory"

# 2 "data/maps/SkyPillar_Entrance/scripts.pory"
SkyPillar_Entrance_MapScripts::
# 3 "data/maps/SkyPillar_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Entrance_OnTransition
# 4 "data/maps/SkyPillar_Entrance/scripts.pory"
	.byte 0
# 5 "data/maps/SkyPillar_Entrance/scripts.pory"

# 6 "data/maps/SkyPillar_Entrance/scripts.pory"
SkyPillar_Entrance_OnTransition:
# 7 "data/maps/SkyPillar_Entrance/scripts.pory"
	setflag FLAG_LANDMARK_SKY_PILLAR
# 8 "data/maps/SkyPillar_Entrance/scripts.pory"
	end
