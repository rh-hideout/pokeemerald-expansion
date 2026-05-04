LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "That's quite some building, eh?\p"
	.string "It's KANTO's RADIO TOWER.$"

LavenderTown_Text_Teacher:
	.string "KANTO has many good radio shows.$"

LavenderTown_Text_Gramps:
	.string "People come from all over to pay\n"
	.string "their respects to the departed\l"
	.string "souls of POKéMON.$"

LavenderTown_Text_Youngster:
	.string "You need a POKé FLUTE to wake\n"
	.string "sleeping POKéMON.\p"
	.string "Every trainer has to know that!$"

LavenderTown_Text_Sign:
	.string "LAVENDER TOWN\p"
	.string "The Noble Purple Town$"

LavenderTown_Text_KantoRadioStationSign:
	.string "KANTO RADIO STATION\p"
	.string "Your Favorite Programs On-Air\n"
	.string "Around the Clock!$"

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "LAVENDER VOLUNTEER POKéMON\n"
	.string "HOUSE$"

LavenderTown_Text_SoulHouseSign:
	.string "SOUL HOUSE\p"
	.string "May the Souls of POKéMON Rest\n"
	.string "Easy$"
