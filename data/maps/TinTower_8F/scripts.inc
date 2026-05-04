TinTower_8F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_8F_EventScript_SetWarp::
	lock
	goto_if_set FLAG_NIGHT_POKEMON, TinTower_8F_EventScript_SetWarpDay
	setdynamicwarp MAP_TIN_TOWER_ROOF_NIGHT, 10, 14
	release
	end

TinTower_8F_EventScript_SetWarpDay::
	setdynamicwarp MAP_TIN_TOWER_ROOF_DAY, 10, 14
	release
	end
