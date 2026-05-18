MtSilver_MountainSide_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_MountainSide_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver_MountainSide_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtSilver_MountainSide_EventScript_Item_Stealth_Rock::
    finditem ITEM_TM_STEALTH_ROCK
    end
