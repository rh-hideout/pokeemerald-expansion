# 1 "data/maps/SkyPillar_1F/scripts.pory"

# 2 "data/maps/SkyPillar_1F/scripts.pory"
SkyPillar_1F_MapScripts::
# 3 "data/maps/SkyPillar_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_1F_OnTransition
# 4 "data/maps/SkyPillar_1F/scripts.pory"
	.byte 0
# 5 "data/maps/SkyPillar_1F/scripts.pory"

# 6 "data/maps/SkyPillar_1F/scripts.pory"
SkyPillar_1F_OnTransition:
# 7 "data/maps/SkyPillar_1F/scripts.pory"
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_1F_EventScript_CleanFloor
# 8 "data/maps/SkyPillar_1F/scripts.pory"
	end
# 9 "data/maps/SkyPillar_1F/scripts.pory"

# 10 "data/maps/SkyPillar_1F/scripts.pory"
SkyPillar_1F_EventScript_CleanFloor::
# 11 "data/maps/SkyPillar_1F/scripts.pory"
	setmaplayoutindex LAYOUT_SKY_PILLAR_1F_CLEAN
# 12 "data/maps/SkyPillar_1F/scripts.pory"
	return
