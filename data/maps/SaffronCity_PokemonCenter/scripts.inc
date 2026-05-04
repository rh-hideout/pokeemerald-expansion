.set LOCALID_NURSE, 1

SaffronCity_PokemonCenter_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "What are JOHTO's POKéMON CENTERS\n"
	.string "like?\p"
	.string "…Oh, I see. So they're not much\n"
	.string "different from the ones in KANTO.\p"
	.string "I can go to JOHTO without\n"
	.string "worrying, then!$"

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "I just happened to come through\n"
	.string "ROCK TUNNEL.\p"
	.string "There was some commotion at the\n"
	.string "POWER PLANT.$"

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "There's an odd cave in CERULEAN.\p"
	.string "As a pro HIKER, I should explore it,\n"
	.string "but that place scares even me.$"

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "SILPH CO.'s HEAD OFFICE and the\n"
	.string "MAGNET TRAIN STATION--they're the\l"
	.string "places to see in SAFFRON.$"
