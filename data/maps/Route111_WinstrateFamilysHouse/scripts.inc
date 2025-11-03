# 1 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 2 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_MapScripts::
# 3 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.byte 0
# 4 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 5 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_Victor::
# 6 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	lock
# 7 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	faceplayer
# 8 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
# 9 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
# 10 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 11 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 12 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 13 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_Victoria::
# 14 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	lock
# 15 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	faceplayer
# 16 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
# 17 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
# 18 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
# 19 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	giveitem ITEM_MACHO_BRACE
# 20 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 21 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setflag FLAG_RECEIVED_MACHO_BRACE
# 22 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 23 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 24 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 25 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
# 26 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
# 27 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 28 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 29 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 30 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_Vivi::
# 31 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	lock
# 32 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	faceplayer
# 33 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
# 34 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
# 35 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 36 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 37 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 38 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_Vicky::
# 39 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	lock
# 40 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	faceplayer
# 41 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
# 42 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
# 43 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
# 44 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setflag FLAG_TEMP_4
# 45 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 46 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 47 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 48 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
# 49 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
# 50 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 51 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 52 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 53 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
# 54 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	closemessage
# 55 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
# 56 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	waitmovement 0
# 57 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	release
# 58 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 59 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 60 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
# 61 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "You're the first TRAINER I've seen who\n"
# 62 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "deploys POKéMON so masterfully.\p"
# 63 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "But, I should tell you--my son is\n"
# 64 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "stronger than you.\p"
# 65 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "He even took the POKéMON LEAGUE\n"
# 66 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "challenge, I'll have you know.$"
# 67 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 68 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
# 69 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "We use this MACHO BRACE to more\n"
# 70 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "effectively strengthen our POKéMON\l"
# 71 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "in training.\p"
# 72 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "Since you've beaten all of us here,\n"
# 73 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "I don't know if you need it, but we\l"
# 74 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "would like you to have our MACHO BRACE.$"
# 75 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 76 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
# 77 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "When it comes to POKéMON battles,\n"
# 78 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "we tend to be pretty passionate.$"
# 79 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 80 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
# 81 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "Mommy is stronger than Daddy.\p"
# 82 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "I'm stronger than Mommy.\p"
# 83 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "And Grandma's stronger than me!\p"
# 84 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "But my big brother is even stronger\n"
# 85 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "than Grandma.$"
# 86 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 87 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
# 88 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "There's no question that you're strong.\p"
# 89 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "But if you were to battle my grandson,\n"
# 90 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "you'd end up crying in frustration.\p"
# 91 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "He's much stronger than any TRAINER\n"
# 92 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "our family knows.\p"
# 93 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "He must be challenging the POKéMON\n"
# 94 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "LEAGUE CHAMPION by now.\p"
# 95 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "Knowing my grandson, he could be the\n"
# 96 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "CHAMPION already!$"
# 97 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 98 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
# 99 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "My grandson must be challenging the\n"
# 100 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "POKéMON LEAGUE CHAMPION by now.\p"
# 101 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "Knowing my grandson, he could be the\n"
# 102 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "CHAMPION already!$"
