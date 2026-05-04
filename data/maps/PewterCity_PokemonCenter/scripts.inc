.set LOCALID_NURSE, 1

PewterCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_OnTransition
	.byte 0

PewterCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_PokemonCenter_EventScript_Teacher::
	msgbox PewterCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

PewterCity_PokemonCenter_EventScript_BugCatcher::
	msgbox PewterCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_PokemonCenter1F_Text_Teacher:
	.string "…Yeah, and the GYM in CINNABAR's gone.\p"
	.string "I was really amazed.\p"
	.string "…Yes? I'm on the phone. Go away!$"

PewterCity_PokemonCenter1F_Text_Jigglypuff:
	.string "JIGGLYPUFF: Puu pupuu.$"

PewterCity_PokemonCenter1F_Text_BugCatcher:
	.string "Most POKéMON get drowsy if they hear a\n"
	.string "JIGGLYPUFF singing.\p"
	.string "There are several moves that can be\n"
	.string "used only while a POKéMON is asleep.$"
