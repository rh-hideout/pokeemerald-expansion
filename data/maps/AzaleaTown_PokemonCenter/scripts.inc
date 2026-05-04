.set LOCALID_NURSE, 1

AzaleaTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "Do your POKéMON know HM moves?\p"
	.string "Those moves can be used even if\n"
	.string "your POKéMON has fainted.$"

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "This BILL guy created the system\n"
	.string "for storing POKéMON in a PC.\p"
	.string "BILL's PC can store up to 30\n"
	.string "POKéMON per BOX.$"

AzaleaPokecenter_Text_FishingGuru:
	.string "BILL's PC can store up to 30\n"
	.string "POKéMON per BOX.$"

AzaleaPokecenter_Text_PokefanF:
	.string "Do you know about BERRIES?\p"
	.string "Crack one open, hollow it out and\n"
	.string "fit it with a special device.\p"
	.string "Then you can catch POKéMON with it.\p"
	.string "Before POKé BALLS were invented,\n"
	.string "everyone used BERRIES.$"
