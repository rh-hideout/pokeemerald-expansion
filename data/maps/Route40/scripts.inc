Route40_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route40_MapScript_OnTransition
	.byte 0

Route40_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, Route40_MapScript_ClearWeather
	end

Route40_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "You have to warm up before\n"
	.string "going into the water.\p"
	.string "That's basic.$"

Route40_Text_SwimmermSimonBeaten:
	.string "OK! Uncle! I give!$"

Route40_Text_SwimmermSimonAfter:
	.string "CIANWOOD CITY is a good\n"
	.string "distance away from here.$"

Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "Hey, you're young and fit!\p"
	.string "Don't ride your POKéMON!\n"
	.string "Swim!$"

Route40_Text_SwimmermRandallBeaten:
	.string "Uh-oh. I lost…$"

Route40_Text_SwimmermRandallAfter:
	.string "Swimming exercises your\n"
	.string "entire body. It's healthy.$"

Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "Are you going to CIANWOOD?\p"
	.string "How about a quick battle\n"
	.string "first?$"

Route40_Text_SwimmerfElaineBeaten:
	.string "I lost that one!$"

Route40_Text_SwimmerfElaineAfter:
	.string "I'd say I'm a better swimmer\n"
	.string "than you. Yeah!$"

Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "No inner tube for me.\p"
	.string "I'm hanging on to a sea\n"
	.string "POKéMON!$"

Route40_Text_SwimmerfPaulaBeaten:
	.string "Ooh, I'm feeling dizzy!$"

Route40_Text_SwimmerfPaulaAfter:
	.string "While I float like this,\n"
	.string "the waves carry me along.$"

Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "Although you can't see it from here,\n"
	.string "CIANWOOD is across the sea.$"

Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "I came to OLIVINE by ship to see\n"
	.string "the sights and soak up the\l"
	.string "atmosphere.\p"
	.string "Being a port, it feels so\n"
	.string "different from a big city.$"

Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "Have you gone to the TRAINER\n"
	.string "HILL?\p"
	.string "I think a lot of tough trainers\n"
	.string "have gathered there already.\p"
	.string "But since you have so many BADGES\n"
	.string "you shouldn't do badly at all.$"

Route40_Text_Monica:
	.string "MONICA: Glad to meet you.\n"
	.string "I'm MONICA of the WEEKDAY FAMILY.\p"
	.string "I bet you can't guess my favorite\n"
	.string "day of the week!$"

Route40_Text_MonicaGivesGift:
	.string "That's right!\p"
	.string "As a token of our friendship,\n"
	.string "I have a gift for you!$"

Route40_Text_MonicaGaveGift:
	.string "MONICA: It's an item that raises\n"
	.string "the power of FLYING-type moves.\p"
	.string "You should equip a bird\n"
	.string "POKéMON with that item.$"

Route40_Text_MonicaMonday:
	.string "MONICA: My brothers and\n"
	.string "sisters are all over the place.\p"
	.string "See if you could find\n"
	.string "them all!$"

Route40_Text_MonicaNotMonday:
	.string "MONICA: I don't think today\n"
	.string "is Monday. How sad…$"

Route40_Text_MonicaNope:
	.string "Not that one.$"

Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end
