# 1 "data/maps/SkyPillar_4F/scripts.pory"

# 2 "data/maps/SkyPillar_4F/scripts.pory"
SkyPillar_4F_MapScripts::
# 3 "data/maps/SkyPillar_4F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
# 4 "data/maps/SkyPillar_4F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_4F_OnTransition
# 5 "data/maps/SkyPillar_4F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_4F_SetHoleWarp
# 6 "data/maps/SkyPillar_4F/scripts.pory"
	.byte 0
# 7 "data/maps/SkyPillar_4F/scripts.pory"

# 8 "data/maps/SkyPillar_4F/scripts.pory"
SkyPillar_4F_OnTransition:
# 9 "data/maps/SkyPillar_4F/scripts.pory"
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_4F_EventScript_CleanFloor
# 10 "data/maps/SkyPillar_4F/scripts.pory"
	copyvar VAR_ICE_STEP_COUNT, 1
# 11 "data/maps/SkyPillar_4F/scripts.pory"
	end
# 12 "data/maps/SkyPillar_4F/scripts.pory"

# 13 "data/maps/SkyPillar_4F/scripts.pory"
SkyPillar_4F_EventScript_CleanFloor::
# 14 "data/maps/SkyPillar_4F/scripts.pory"
	setmaplayoutindex LAYOUT_SKY_PILLAR_4F_CLEAN
# 15 "data/maps/SkyPillar_4F/scripts.pory"
	return
# 16 "data/maps/SkyPillar_4F/scripts.pory"

# 17 "data/maps/SkyPillar_4F/scripts.pory"
SkyPillar_4F_SetHoleWarp:
# 18 "data/maps/SkyPillar_4F/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 19 "data/maps/SkyPillar_4F/scripts.pory"
	setholewarp MAP_SKY_PILLAR_3F
# 20 "data/maps/SkyPillar_4F/scripts.pory"
	end
