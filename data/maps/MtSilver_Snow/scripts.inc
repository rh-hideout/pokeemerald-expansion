MtSilver_Snow_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_Snow_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver_Snow_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtSilver_Snow_EventScript_RareCandy::
	finditem ITEM_RARE_CANDY
	end
MtSilver_Snow_EventScript_NevermeltIce::	
	finditem ITEM_NEVER_MELT_ICE
	end
