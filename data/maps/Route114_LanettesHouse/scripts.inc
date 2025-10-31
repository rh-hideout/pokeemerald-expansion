# 1 "data/maps/Route114_LanettesHouse/scripts.pory"

# 2 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_MapScripts::
# 3 "data/maps/Route114_LanettesHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
# 4 "data/maps/Route114_LanettesHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route114_LanettesHouse/scripts.pory"

# 6 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_OnTransition:
# 7 "data/maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_LANDMARK_LANETTES_HOUSE
# 8 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 9 "data/maps/Route114_LanettesHouse/scripts.pory"

# 10 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_Lanette::
# 11 "data/maps/Route114_LanettesHouse/scripts.pory"
	lock
# 12 "data/maps/Route114_LanettesHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
# 14 "data/maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_SYS_PC_LANETTE
# 15 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
# 16 "data/maps/Route114_LanettesHouse/scripts.pory"
	givedecoration DECOR_LOTAD_DOLL
# 17 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
# 18 "data/maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_RECEIVED_DOLL_LANETTE
# 19 "data/maps/Route114_LanettesHouse/scripts.pory"
	release
# 20 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 21 "data/maps/Route114_LanettesHouse/scripts.pory"

# 22 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_OfferAdvice::
# 23 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
# 24 "data/maps/Route114_LanettesHouse/scripts.pory"
	release
# 25 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 26 "data/maps/Route114_LanettesHouse/scripts.pory"

# 27 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_Notebook::
# 28 "data/maps/Route114_LanettesHouse/scripts.pory"
	lockall
# 29 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
# 30 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
# 31 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
# 32 "data/maps/Route114_LanettesHouse/scripts.pory"
	releaseall
# 33 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 34 "data/maps/Route114_LanettesHouse/scripts.pory"

# 35 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_NotebookPage2::
# 36 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
# 37 "data/maps/Route114_LanettesHouse/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
# 38 "data/maps/Route114_LanettesHouse/scripts.pory"
	releaseall
# 39 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 40 "data/maps/Route114_LanettesHouse/scripts.pory"

# 41 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_NotebookPage3::
# 42 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
# 43 "data/maps/Route114_LanettesHouse/scripts.pory"
	return
# 44 "data/maps/Route114_LanettesHouse/scripts.pory"

# 45 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_PC::
# 46 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
# 47 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 48 "data/maps/Route114_LanettesHouse/scripts.pory"

# 49 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
# 50 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
# 51 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "I'm sorry everything is so cluttered…\n"
# 52 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "When I get engrossed in research,\l"
# 53 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "things end up this way…\p"
# 54 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "This is embarrassing… Please keep\n"
# 55 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "this a secret in exchange for this.$"
# 56 "data/maps/Route114_LanettesHouse/scripts.pory"

# 57 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_OrganizeYourBoxes:
# 58 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "May I offer advice about my POKéMON\n"
# 59 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Storage System?\p"
# 60 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "You should organize your BOXES so you\n"
# 61 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "can tell which POKéMON are in them.$"
# 62 "data/maps/Route114_LanettesHouse/scripts.pory"

# 63 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage1:
# 64 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "It's LANETTE's research notes.\n"
# 65 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "There's information about BOXES.\p"
# 66 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Design BOXES to hold 30 POKéMON each.\p"
# 67 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Each TRAINER should be able to store\n"
# 68 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "420 POKéMON on the PC system.\p"
# 69 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Keep reading?$"
# 70 "data/maps/Route114_LanettesHouse/scripts.pory"

# 71 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage2:
# 72 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "A marking system should be added to\n"
# 73 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "make POKéMON easier to organize.\p"
# 74 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "The name and wallpaper design of each\n"
# 75 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "BOX will be made changeable to please\l"
# 76 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "the stored POKéMON.\p"
# 77 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Keep reading?$"
# 78 "data/maps/Route114_LanettesHouse/scripts.pory"

# 79 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage3:
# 80 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "When storing a POKéMON, it should be\n"
# 81 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "sent to the BOX inspected last.\p"
# 82 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "If that BOX is full, the received\n"
# 83 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "POKéMON is stored in the next BOX.\p"
# 84 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "In other words, when a BOX is examined,\n"
# 85 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "it is automatically selected as the BOX\l"
# 86 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "to which POKéMON are sent.$"
# 87 "data/maps/Route114_LanettesHouse/scripts.pory"

# 88 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ClosedTheNotebook:
# 89 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "{PLAYER} closed the notebook.$"
# 90 "data/maps/Route114_LanettesHouse/scripts.pory"

# 91 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_EmailFromBill:
# 92 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "There's an e-mail from someone on\n"
# 93 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "the PC.\p"
# 94 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“… … … … … … …\p"
# 95 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“Your Storage System offers more\n"
# 96 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "convenience than mine.\p"
# 97 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“It has a lot of user-friendly features\n"
# 98 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "that make it fun and useful, too.\p"
# 99 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“It makes me proud that I played\n"
# 100 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "a part in its development.\p"
# 101 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“Here's hoping that you'll continue\n"
# 102 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "research in Storage Systems.\p"
# 103 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“From BILL\n"
# 104 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "… … … … … … … …”$"
