# 1 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 2 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_MapScripts::
# 3 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.byte 0
# 4 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 5 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_Steven::
# 6 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	lock
# 7 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	faceplayer
# 8 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
# 9 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setvar VAR_0x8004, ITEM_LETTER
# 10 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 11 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_DELIVERED_STEVEN_LETTER
# 12 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
# 13 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	giveitem ITEM_TM_STEEL_WING
# 14 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
# 15 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
# 16 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	closemessage
# 17 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay 30
# 18 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 19 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
# 20 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitfanfare
# 21 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	closemessage
# 22 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay 30
# 23 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_REGISTERED_STEVEN_POKENAV
# 24 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
# 25 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	closemessage
# 26 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
# 27 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
# 28 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
# 29 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
# 30 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	playse SE_EXIT
# 31 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	removeobject LOCALID_GRANITE_CAVE_STEVEN
# 32 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	release
# 33 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	end
# 34 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 35 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_StevenExitNorth::
# 36 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
# 37 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmovement 0
# 38 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 39 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 40 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
# 41 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
# 42 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
# 43 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmovement 0
# 44 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 45 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 46 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_StevenExitSouth::
# 47 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
# 48 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
# 49 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmovement 0
# 50 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 51 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 52 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_BagFull::
# 53 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
# 54 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 55 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 56 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Movement_StevenExit:
# 57 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 58 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 59 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 60 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 61 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 62 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay_8
# 63 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	step_end
# 64 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 65 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
# 66 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay_16
# 67 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay_16
# 68 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay_16
# 69 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_in_place_faster_up
# 70 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	step_end
# 71 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 72 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Movement_StevenExitSouth:
# 73 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_left
# 74 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 75 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 76 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 77 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_right
# 78 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 79 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 80 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay_8
# 81 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	step_end
# 82 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 83 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
# 84 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "My name is STEVEN.\p"
# 85 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "I'm interested in rare stones,\n"
# 86 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "so I travel here and there.\p"
# 87 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Oh?\n"
# 88 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "A LETTER for me?$"
# 89 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 90 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_ThankYouTakeThis:
# 91 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "STEVEN: Okay, thank you.\p"
# 92 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "You went through all this trouble to\n"
# 93 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "deliver that. I need to thank you.\p"
# 94 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Let me see…\n"
# 95 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "I'll give you this TM.\p"
# 96 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "It contains my favorite move,\n"
# 97 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "STEEL WING.$"
# 98 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 99 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
# 100 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "STEVEN: Your POKéMON appear quite\n"
# 101 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "capable.\p"
# 102 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "If you keep training, you could even\n"
# 103 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "become the CHAMPION of the POKéMON\l"
# 104 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "LEAGUE one day. That's what I think.\p"
# 105 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "I know, since we've gotten to know each\n"
# 106 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "other, let's register one another in\l"
# 107 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "our POKéNAVS.\p"
# 108 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "… … … … … …$"
# 109 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 110 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_RegisteredSteven:
# 111 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Registered STEVEN\n"
# 112 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "in the POKéNAV.$"
# 113 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 114 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
# 115 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Now, I've got to hurry along.$"
# 116 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 117 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_OhBagIsFull:
# 118 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Oh, your BAG is full…\n"
# 119 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "That's too bad, then.$"
