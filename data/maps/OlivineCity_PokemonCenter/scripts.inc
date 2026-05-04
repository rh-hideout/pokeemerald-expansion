.set LOCALID_NURSE, 1

OlivineCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	end

OlivineCity_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterFisher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PokecenterFisher:
	.string "The SAILOR in the OLIVINE CAFE\n"
	.string "next door is really generous.\p"
	.string "He taught my POKéMON STRENGTH.\p"
	.string "Now it can move big boulders\n"
	.string "without breaking a sweat.$"

OlivineCity_Text_PokecenterTeacher:
	.string "There's a person in CIANWOOD\n"
	.string "CITY across the sea.\p"
	.string "I heard him bragging about his\n"
	.string "rare POKéMON all the time.$"
