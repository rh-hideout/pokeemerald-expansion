SeafoamIslands_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SeafoamIslands_1F_SetHoleWarp
	.byte 0

SeafoamIslands_1F_OnTransition: 
	copyvar VAR_ICE_STEP_COUNT, 1
	end

SeafoamIslands_1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SEAFOAM_ISLANDS_B1F
	end

