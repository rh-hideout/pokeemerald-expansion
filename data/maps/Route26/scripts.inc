Route26_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
    .string "I'm making my final preparations\n"
    .string "for the POKéMON LEAGUE.$"

Route26_Text_CooltrainermJakeBeaten:
    .string "I blew it!$"

Route26_Text_CooltrainermJakeAfter:
    .string "It's going to be tough to win at\n"
    .string "the LEAGUE.\p"
    .string "I need to do some more training.\p"
    .string "I hear that the LEAGUE's ELITE\n"
    .string "FOUR are tougher than GYM LEADERS.$"

Route26_Text_CooltrainermGavenSeen:
    .string "By experiencing tough battles, you\n"
    .string "gain power.$"

Route26_Text_CooltrainermGavenBeaten:
    .string "Gaah! Life is even tougher!$"

Route26_Text_CooltrainermGavenAfter:
    .string "To get to POKéMON LEAGUE, you have\n"
    .string "to get through VICTORY ROAD.\p"
    .string "But VICTORY ROAD is tough.\p"
    .string "Practically nobody goes there!$"

Route26_Text_CooltrainerfJoyceSeen:
    .string "Since you've come this far,\n"
    .string "you must be good.\p"
    .string "I'm going to give this battle\n"
    .string "everything I've got!$"

Route26_Text_CooltrainerfJoyceBeaten:
    .string "No! I don't believe this!$"

Route26_Text_CooltrainerfJoyceAfter:
    .string "I've defeated eight GYM LEADERS,\n"
    .string "so I was feeling confident.\p"
    .string "I'll have to try harder next time.$"

Route26_Text_CooltrainerfBethSeen:
    .string "I lost to a trainer named {RIVAL}.\p"
    .string "He was really strong, but…\p"
    .string "It was as if he absolutely had to\n"
    .string "win at any cost.\p"
    .string "I felt sorry for his POKéMON.$"

Route26_Text_CooltrainerfBethBeaten:
    .string "POKéMON aren't tools of war.$"

Route26_Text_CooltrainerfBethAfter:
    .string "POKéMON are in-valuable, lifelong\n"
    .string "partners.$"

Route26_Text_PsychicRichardSeen:
    .string "Wow, look at all those BADGES!\n"
    .string "I'm impressed.\p"
    .string "But you're not satisfied by just\n"
    .string "collecting them, right?$"

Route26_Text_PsychicRichardBeaten:
    .string "Good battle!$"

Route26_Text_PsychicRichardAfter:
    .string "People and POKéMON grow from their\n"
    .string "experiences.\p"
    .string "Don't get lazy and complacent.$"

Route26_Text_Sign:
    .string "ROUTE 26\p"
    .string "POKéMON LEAGUE\n"
    .string "RECEPTION GATE$"

