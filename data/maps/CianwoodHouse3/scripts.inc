CianwoodHouse3_MapScripts::
	.byte 0

CianwoodCity_EventScript_Kirk::
	lock
	faceplayer
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
	givenamedmon 2
	call Common_EventScript_GiftMonNamed

	setvar VAR_SHUCKIE, 1
	release
	end

CianwoodCity_EventScript_KirkDeclined::
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkGivenShuckie::
	goto_if_set FLAG_BADGE01_GET, CianwoodCity_EventScript_KirkReturnShuckie
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkReturnShuckie::
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
	removenamedmon 2
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
	playse MUS_OBTAIN_ITEM
	callnative UpdateFollowingPokemon
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
	waitse
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkDeclineReturnShuckie::
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkNotRight::
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkKeepShuckie::
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkReturnedShuckie::
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_Text_ManiacAskShuckle:
	.string "I, I'm in shock!\p"
	.string "A guy about your age with piercing\n"
	.string "eyes and long hair came in.\p"
	.string "He scared me into giving him my\n"
	.string "prized POKéMON!\p"
	.string "I still have one left, but what if\n"
	.string "he comes back?\p"
	.string "You look strong. Could you look\n"
	.string "after my POKéMON for a while?$"

CianwoodCity_Text_ManiacTakeCareShuckle:
	.string "Oh, thank you!\p"
	.string "Take good care of it, please!$"

CianwoodCity_Text_ManiacGotShuckle:
	.string "{PLAYER} received a POKéMON.$"

CianwoodCity_Text_ManiacPartyFull:
	.string "Your POKéMON party is full.$"

CianwoodCity_Text_ManiacIfHeComesBack:
	.string "Oh, no… What'll I do if he comes\n"
	.string "back?$"

CianwoodCity_Text_ManiacHowsdoing:
	.string "Hi! How's my POKéMON?$"

CianwoodCity_Text_ManiacAskReturn:
	.string "Hi! How's my POKéMON?\p"
	.string "I think I'm safe now, so may I\n"
	.string "have it back?$"

CianwoodCity_Text_ManiacThankYou:
	.string "Thank you!$"

CianwoodCity_Text_ManiacShuckleNotThere:
	.string "Hey, you don't have my POKéMON\n"
	.string "with you.$"

CianwoodCity_Text_ManiacShuckleLikesYou:
	.string "My POKéMON has come to like you.\p"
	.string "All right, you should keep it.\p"
	.string "But promise to be good to it!$"

CianwoodCity_Text_ManiacRobbed:
	.string "Huh, something's not right.$"

CianwoodCity_Text_ManiacRobbed2:
	.string "Oh, no, no… That's the same as\n"
	.string "being robbed.$"

CianwoodCity_Text_ManiacHappinessSpeech:
	.string "For POKéMON, happiness is being\n"
	.string "with a person who treats them well.$"

CianwoodCity_Text_ManiacLastMon:
	.string "If I take my POKéMON back,\n"
	.string "what are you going to use\n"
	.string "in battle?$"


CianwoodCity_Text_ManiacReturnedMon:
	.string "{PLAYER} returned SHUCKIE.$"
