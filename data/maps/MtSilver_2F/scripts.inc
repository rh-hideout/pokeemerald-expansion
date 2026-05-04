MtSilver_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end
