.set LOCALID_NURSE, 1

CeruleanCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "For battles, I'd much rather use\n"
	.string "POKéMON I've been raising, even if\p"
	.string "they're weaker than some newly\n"
	.string "caught POKéMON.$"

CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "The MAGNET TRAIN travels at over\n"
	.string "340 mph. It goes between KANTO and\l"
	.string "JOHTO in almost no time at all.\p"
	.string "It really makes JOHTO accessible.$"
