SouthCampus_PokemonCenter_1F_MapScripts::
# 2 "data/maps/SouthCampus_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SouthCampus_PokemonCenter_1F_OnTransition
# 3 "data/maps/SouthCampus_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0


SouthCampus_PokemonCenter_1F_OnTransition::
# 7 "data/maps/SouthCampus_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_SOUTH_CAMPUS
	end


SouthCampus_PokemonCenter_1F_EventScript_NurseJoy::
# 16 "data/maps/SouthCampus_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, 1
# 17 "data/maps/SouthCampus_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 18 "data/maps/SouthCampus_PokemonCenter_1F/scripts.pory"
	waitmessage
# 19 "data/maps/SouthCampus_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 20 "data/maps/SouthCampus_PokemonCenter_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 21 "data/maps/SouthCampus_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 22 "data/maps/SouthCampus_PokemonCenter_1F/scripts.pory"
	release
	end


Joy::
# 11 "data/maps/SouthCampus_PokemonCenter_1F/scripts.pory"
	.string "Nurse Joy$"
