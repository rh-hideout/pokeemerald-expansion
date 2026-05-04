PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_CityEnter
	.byte 0

PalletTown_EventScript_CityEnter::
	setflag FLAG_VISITED_PALLET_TOWN
	end

PalletTown_EventScript_Woman::
	msgbox PalletTown_Text_Teacher, MSGBOX_NPC
	end
PalletTown_EventScript_Fatman::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	end
PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_Sign, MSGBOX_SIGN
	end	
PalletTown_EventScript_RedsHouseSign::
	msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
	end
PalletTown_EventScript_BluesHouseSign::
	msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
	end	
PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end	

PalletTown_Text_Teacher:
	.string "I'm raising POKéMON too.\p"
	.string "They serve as my private\n"
	.string "guards.$"

PalletTown_Text_Fisher:
	.string "Technology is incredible!\p"
	.string "You can now trade POKéMON\n"
	.string "across time like e-mail.$"

PalletTown_Text_Sign:
	.string "PALLET TOWN\p"
	.string "A Tranquil Setting of Peace\n"
	.string "& Purity$"

PalletTown_Text_RedsHouseSign:
	.string "RED'S HOUSE$"

PalletTown_Text_OaksLabSign:
	.string "OAK POKéMON\n"
	.string "RESEARCH LAB$"

PalletTown_Text_BluesHouseSign:
	.string "BLUE'S HOUSE$"
