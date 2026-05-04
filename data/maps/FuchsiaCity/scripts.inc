FuchsiaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_OnFrame::
	map_script_2 VAR_FUCHSIA_CITY_STATE, 0,  FuchsiaCity_EventScript_BaobaCall
	.2byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	end

FuchsiaCity_Text_Baoba:
	.string "WARDEN BAOBA: {PLAYER}!\p"
	.string "This is WARDEN BAOBA.\p"
	.string "Something awful has happened!\n"
	.string "My old SAFARI ZONE in FUCHSIA CITY\l"
	.string "was bought out and reopened!\p"
	.string "And apparently it has exotic new\n"
	.string "POKéMON!\p"
	.string "It's hurting my business!\p"
	.string "{PLAYER}, you must venture into the\n"
	.string "new SAFARI ZONE and catch a POKéMON\l"
	.string "to show me. I must know about these\l"
	.string "'exotic' POKéMON.\p"
	.string "Please {PLAYER}, my business depends\n"
	.string "on you!$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "One of the ELITE FOUR used to be\n"
	.string "the LEADER of FUCHSIA's GYM.$"

FuchsiaCity_Text_PokefanM:
	.string "KOGA's daughter succeeded him as\n"
	.string "the GYM LEADER after he joined the\l"
	.string "ELITE FOUR.$"

FuchsiaCity_Text_Teacher:
	.string "The SAFARI ZONE is under new\n"
	.string "management.\p"
	.string "And it has tons of new POKéMON!$"

FuchsiaCity_Text_Sign:
	.string "FUCHSIA CITY\p"
	.string "Behold! It's Passion Pink!$"

FuchsiaCity_Text_GymSign:
	.string "FUCHSIA CITY POKéMON GYM\n"
	.string "LEADER: JANINE\p"
	.string "The Poisonous Ninja Master$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "There's a notice here…\p"
	.string "SAFARI ZONE OFFICE is closed until\n"
	.string "further notice.$"

FuchsiaCity_Text_SafariZone:
	.string "SAFARI ZONE\n"
	.string "NOW OWNED BY\l"
	.string "DEVON CORP.$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "The WARDEN is traveling abroad.\p"
	.string "Therefore, the SAFARI ZONE is\n"
	.string "closed.$"

FuchsiaCity_Text_NoLitteringSign:
	.string "No littering.\p"
	.string "Please take your waste with you.$"

