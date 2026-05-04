Route5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route5_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route5_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route5_EventScript_UndergroundPathSign::
	msgbox Route5_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route5_Text_UndergroundPathSign:
	.string "UNDERGROUND PATH\p"
	.string "CERULEAN CITY - VERMILION CITY$"

