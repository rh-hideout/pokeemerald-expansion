MtSilver_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	setescapewarp MAP_MT_SILVER_OUTSIDE_HNS, 17, 8
	end
