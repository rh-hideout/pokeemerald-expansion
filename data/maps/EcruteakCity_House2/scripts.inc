EcruteakCity_House2_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "Ah. You're on an adventure with\n"
	.string "your POKéMON?\p"
	.string "Well, what's an adventure without\n"
	.string "treasure hunting?\p"
	.string "Am I right, or am I right?$"

Ecruteak_Text_ItemfinderTrueSpirit:
	.string "Good! You understand the true\n"
	.string "spirit of adventure.\p"
	.string "I like that! Take this with you.$"

Ecruteak_Text_ItemfinderExplanation:
	.string "There are many items lying about\n"
	.string "that aren't obvious.\p"
	.string "Use ITEMFINDER to check if there\n"
	.string "is an item on the ground near you.\p"
	.string "It doesn't show the exact spot,\n"
	.string "so you'll have to look yourself.\p"
	.string "Oh yeah--I heard there are items\n"
	.string "in ECRUTEAK's BURNED TOWER.$"

Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "Oh… To each his own, I suppose…$"

EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	msgbox Ecruteak_Text_ItemFinderMan, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "ECRUTEAK is a very old city.\n"
	.string "Many generations passed down\l"
	.string "their history in books like these.$"

Ecruteak_Text_HistoryBook:
	.string "HISTORY OF ECRUTEAK\p"
	.string "Want to read it?$"

Ecruteak_Text_TwoTowers:
	.string "In ECRUTEAK, there were two towers.\p"
	.string "Each tower was the roost of\n"
	.string "powerful flying POKéMON.\p"
	.string "But one of the towers burned to\n"
	.string "the ground.\p"
	.string "The two POKéMON haven't been seen\n"
	.string "since…\p"
	.string "Keep reading?$"

Ecruteak_Text_ThreeMon:
	.string "ECRUTEAK was also home to three\n"
	.string "POKéMON that raced around the town.\p"
	.string "They were said to have been born\n"
	.string "of water, lightning and fire.\p"
	.string "But they could not contain their\n"
	.string "excessive power.\p"
	.string "So they say the three ran like the\n"
	.string "wind off into the grassland.$"
