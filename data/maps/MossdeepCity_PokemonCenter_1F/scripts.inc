.set LOCALID_NURSE, 1

MossdeepCity_PokemonCentre_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCentre_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCentre_1F_OnTransition:
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCentre_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCentreNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCentre_1F_EventScript_Woman::
	msgbox MossdeepCity_PokemonCentre_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCentre_1F_EventScript_Girl::
	msgbox MossdeepCity_PokemonCentre_1F_Text_AbilitiesMightChangeMoves, MSGBOX_NPC
	end

MossdeepCity_PokemonCentre_1F_Text_GymLeaderDuoFormidable:
	.string "The GYM LEADERS in this town are\n"
	.string "a formidable duo.\p"
	.string "Their combination attacks are, like,\n"
	.string "excellent and wow!$"

MossdeepCity_PokemonCentre_1F_Text_AbilitiesMightChangeMoves:
	.string "Depending on the special abilities of\n"
	.string "POKéMON, some moves might change\l"
	.string "or not work at all.$"

