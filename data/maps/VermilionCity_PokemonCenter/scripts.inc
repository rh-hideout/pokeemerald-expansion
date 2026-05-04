.set LOCALID_NURSE, 1

VermilionCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_OnTransition
	.byte 0

VermilionCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionPokeCenter_EventScript_FishingGuru::
	goto_if_set FLAG_HIDE_VERMILION_SNORLAX, VermilionPokeCenter_EventScript_FishingGuru2
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_FishingGuru2::
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Sailor::
	msgbox VermilionCity_PokemonCenter1F_Text_Sailor, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Bugcatcher::
	msgbox VermilionCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

VermilionCity_PokemonCenter1F_Text_FishingGuru:
	.string "A sleeping POKéMON is lying in\n"
	.string "front of DIGLETT'S CAVE.\p"
	.string "It's a fantastic opportunity to\n"
	.string "get it, but how do you wake it up?$"

VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax:
	.string "There used to be a sleeping\n"
	.string "POKéMON lying in front of\l"
	.string "DIGLETT'S CAVE.\p"
	.string "But it seems to have disappeared.$"

VermilionCity_PokemonCenter1F_Text_Sailor:
	.string "The FAST SHIP is a great place to\n"
	.string "meet and battle trainers.$"

VermilionCity_PokemonCenter1F_Text_BugCatcher:
	.string "Oh? You have some BADGES I've\n"
	.string "never seen before.\p"
	.string "Oh, I get it. You got them in\n"
	.string "JOHTO.$"
