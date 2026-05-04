.set LOCALID_NURSE, 1

MtSilver_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_PokemonCenter_OnTransition
	.byte 0

MtSilver_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MT_SILVER
	end

MtSilver_PokemonCenter_EventScript_Meara::
	msgbox MtSilver_PokemonCenter_Text_Meara, MSGBOX_NPC
	end

MtSilver_PokemonCenter_Text_Meara:
	.string "I'm a researcher from the PEWTER\n"
	.string "CITY museum.\p"
	.string "An unusual amount of artifacts have\n"
	.string "been discovered in this area, so\l"
	.string "I've come here to investigate.\p"
	.string "There are no records of a civilization\n"
	.string "around the mountain, but the\l"
	.string "artifacts are almost certainly\l"
	.string "man-made.\p"
	.string "It is really quite mysterious.$"
