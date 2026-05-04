RockTunnel_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RockTunnel_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

RockTunnel_1F_EventScript_ItemIron::
	finditem ITEM_IRON
	end

RockTunnel_1F_EventScript_PPup::
	finditem ITEM_PP_UP
	end
