.set LOCALID_CERULEAN_WOMAN, 2
.set LOCALID_CERULEAN_SLOWBRO, 3

CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_EventScript_CityEnter
	.byte 0

CeruleanCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CERULEAN_CITY
	end

CeruleanCity_EventScript_CooltrainerM1::
	goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
	msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
	end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
	msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
	end

CeruleanCity_EventScript_Boy::
	msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_EventScript_Guard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "This is CERULEAN CAVE.\p"
    .string "Horribly strong POKéMON live inside\n"
    .string "there.\p"
    .string "It takes a very special TRAINER to\n"
    .string "be allowed inside there.\p"
    .string "You'd have to be strong enough to\n"
    .string "become the KANTO POKéMON LEAGUE\l"
    .string "CHAMPION for starters.\p"
    .string "And, you would have to have\n"
    .string "made a great achievement.$"

CeruleanCity_Text_CooltrainerM1:
	.string "KANTO's POWER PLANT?\p"
	.string "It's near the end of ROUTE 9, the\n"
	.string "road that heads east from here.\p"
	.string "I think there was an accident of\n"
	.string "some sort there.$"

CeruleanCity_Text_CooltrainerM2:
	.string "You're collecting every single\n"
	.string "kind of POKéMON?\p"
	.string "That must be quite a challenge,\n"
	.string "but it sounds fun too.$"

CeruleanCity_Text_SuperNerd:
	.string "The CAPE in the north is a good\n"
	.string "place for dates.\p"
	.string "Girls like it!$"

CeruleanCity_EventScript_Slowbro::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Slowbro, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Slowbro:
	.string "SLOWBRO: Yarah?$"

CeruleanCity_EventScript_SlowbroWoman::
	msgbox CeruleanCity_Text_CooltrainerF1, MSGBOX_NPC
	turnobject LOCALID_CERULEAN_WOMAN, DIR_EAST
	msgbox CeruleanCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	delay 20
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	applymovement2 LOCALID_CERULEAN_SLOWBRO, Common_Movement_QuestionMark
	turnobject LOCALID_CERULEAN_SLOWBRO DIR_WEST
	delay 30
	turnobject LOCALID_CERULEAN_SLOWBRO, DIR_EAST
	delay 30
	turnobject LOCALID_CERULEAN_SLOWBRO, DIR_SOUTH
	delay 70
	msgbox CeruleanCity_Text_CooltrainerF3, MSGBOX_NPC
	end

CeruleanCity_Text_CooltrainerF1:
	.string "My SLOWBRO and I make an awesome\n"
	.string "combination!$"

CeruleanCity_Text_CooltrainerF2:
	.string "SLOWBRO, show me your CONFUSION!$"

CeruleanCity_Text_CooltrainerF3:
	.string "…$"

CeruleanCity_EventScript_Fisher::
	goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
	msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
	end

CeruleanCity_EventScript_FisherDuringRocket::
	msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
	end

CeruleanCity_Text_Fisher:
	.string "I'm a huge fan of CERULEAN GYM's\n"
	.string "MISTY.$"

CeruleanCity_Text_Fisher_RocketTip:
	.string "I saw this shady guy go off toward\n"
	.string "CERULEAN's CAPE.$"

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
	end

CeruleanCity_Text_Youngster1:
	.string "The cave north of town has\n"
	.string "horribly powerful POKéMON in it.$"

CeruleanCity_Text_Youngster2:
	.string "Ayuh?\p"
	.string "My ITEMFINDER is responding…$"

CeruleanCity_EventScript_Sign::
	msgbox CeruleanCity_Text_Sign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_PoliceSign::
	msgbox CeruleanCity_Text_PoliceSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_CapeSign::
	msgbox CeruleanCity_Text_CapeSign, MSGBOX_SIGN
	end

CeruleanCity_Text_Sign:
	.string "CERULEAN CITY\p"
	.string "A Mysterious Blue Aura Surrounds It$"

CeruleanCity_Text_GymSign:
	.string "CERULEAN CITY\n"
	.string "POKéMON GYM\n"
	.string "LEADER: MISTY\p"
	.string "The Tomboyish Mermaid$"

CeruleanCity_Text_BikeShopSign:
	.string "There's a notice here…\p"
	.string "The BIKE SHOP has moved to\n"
	.string "GOLDENROD CITY in JOHTO…$"

CeruleanCity_Text_PoliceSign:
	.string "There's a notice here…\p"
	.string "Stamp out thievery and make the\n"
	.string "city a friendlier, more cheerful\l"
	.string "place!\p"
	.string "CERULEAN POLICE$"

CeruleanCity_Text_CapeSign:
	.string "CERULEAN CAPE\n"
	.string "AHEAD$"

CeruleanCity_Text_LockedDoor:
	.string "It's locked…$"

