.set LOCALID_NURSE, 1

BlackthornCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY
	end

BlackthornCity_PokemonCenter_EventScript_Gent::
	msgbox BlackthornCity_PokemonCenter1FGentlemanText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_EventScript_Twin::
	msgbox BlackthornCity_PokemonCenter1FTwinText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter1FGentlemanText:
	.string "Deep inside far-off INDIGO\n"
	.string "PLATEAU is the POKéMON LEAGUE.\p"
	.string "I hear the best trainers gather\n"
	.string "there from around the country.$"

BlackthornCity_PokemonCenter1FTwinText:
	.string "There was this move I just had\n"
	.string "to teach my POKéMON.\p"
	.string "So I got the MOVE DELETER to make\n"
	.string "it forget an HM move.$"
