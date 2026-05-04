CeladonCity_House1_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_Chef::
	msgbox CeladonCity_House1_Text_ChefEatathon, MSGBOX_NPC
	end

CeladonCity_House1_EventScript_Fisher1::
	lock
	msgbox CeladonCity_House1_Text_Fisher1Snarfle, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher1Concentration, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Fisher2::
	lock
	msgbox CeladonCity_House1_Text_Fisher2GulpChew, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher2Quantity, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Fisher3::
	lock
	msgbox CeladonCity_House1_Text_Fisher3MunchMunch, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher3GoldenrodIsBest, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Teacher::
	lock
	msgbox CeladonCity_House1_Text_TeacherCrunchCrunch, MSGBOX_DEFAULT
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_House1_EventScript_TeacherCoincase
	msgbox CeladonCity_House1_Text_TeacherKeepEating, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_TeacherCoincase::
	msgbox CeladonCity_House1_Text_TeacherNoCoinCase, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Sign::
	msgbox CeladonCity_House1_Text_EatathonContestPoster, MSGBOX_SIGN
	end

CeladonCity_House1_Text_ChefEatathon:
	.string "Hi!\p"
	.string "We're holding an eatathon contest.\p"
	.string "We can't serve you right now.\n"
	.string "Sorry.$"

CeladonCity_House1_Text_Fisher1Snarfle:
	.string "…Snarfle, chew…$"

CeladonCity_House1_Text_Fisher1Concentration:
	.string "Don't talk to me!\p"
	.string "You'll break my concentration!$"

CeladonCity_House1_Text_Fisher2GulpChew:
	.string "…Gulp… Chew…$"

CeladonCity_House1_Text_Fisher2Quantity:
	.string "I take quantity over quality!\p"
	.string "I'm happy when I'm full!$"

CeladonCity_House1_Text_Fisher3MunchMunch:
	.string "Munch, munch…$"

CeladonCity_House1_Text_Fisher3GoldenrodIsBest:
	.string "The food is good here, but\n"
	.string "GOLDENROD has the best food\l"
	.string "anywhere.$"

CeladonCity_House1_Text_TeacherCrunchCrunch:
	.string "Crunch… Crunch…$"

CeladonCity_House1_Text_TeacherNoCoinCase:
	.string "Nobody here will give you a COIN\n"
	.string "CASE. You should look in JOHTO.$"

CeladonCity_House1_Text_TeacherKeepEating:
	.string "Crunch… Crunch…\p"
	.string "I can keep eating!\p"
	.string "More, CHEF!$"

CeladonCity_House1_Text_EatathonContestPoster:
	.string "Eatathon Contest! No time limit!\p"
	.string "A battle without end! The biggest\n"
	.string "muncher gets it all for free!$"

