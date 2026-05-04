Route37_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_SunnyYes
	case 1, Route37_EventScript_SunnyNope
	case 2, Route37_EventScript_SunnyNope
	case 3, Route37_EventScript_SunnyNope
	case 4, Route37_EventScript_SunnyNope
	case 5, Route37_EventScript_SunnyNope
	case 6, Route37_EventScript_SunnyNope
	case 7 Route37_EventScript_SunnyCancel
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
	closemessage
	release
	end
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "ANN: ANNE and I are in this\n"
	.string "together!$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "ANN & ANNE: Nnn… A little too\n"
	.string "strong.$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "ANN: I can tell what my sister and\n"
	.string "my POKéMON are thinking.$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "ANNE: ANN and I are in this\n"
	.string "together!$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "ANN & ANNE: Nnn… A little too\n"
	.string "strong.$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "ANNE: We share the same feelings as\n"
	.string "our POKéMON.$"

Route37_Text_PsychicGreg_Seen:
	.string "POKéMON can't do a thing if they are\n"
	.string "asleep.\p"
	.string "I'll show you how scary that is!$"

Route37_Text_PsychicGreg_Beaten:
	.string "I lost. That's pretty sad…$"

Route37_Text_PsychicGreg_After:
	.string "Putting POKéMON to sleep or paralyz-\n"
	.string "ing them are good battle techniques.$"

Route37_Text_Sunny_Meet:
	.string "SUNNY: Hi!\p"
	.string "I'm SUNNY of the WEEKDAY family!\p"
	.string "If you can guess my favorite day,\n"
	.string "I'll give you a reward.$"

Route37_Text_Sunny_GiveGift1:
	.string "I was told to give you this if I saw\n"
	.string "you!$"

Route37_Text_Sunny_GiveGift2:
	.string "I was told to give you this if I saw\n"
	.string "you!$"

Route37_Text_Sunny_GaveGift:
	.string "SUNNY: That thing…\p"
	.string "Um…\p"
	.string "… What was it now…\p"
	.string "…\p"
	.string "Oh! I remember now!\p"
	.string "A POKéMON that knows electric\n"
	.string "moves should hold it.\p"
	.string "My sis MONICA said it powers up\n"
	.string "electric moves!$"

Route37_Text_Sunny_Sunday:
	.string "SUNNY: My sisters and brothers are\n"
	.string "MONICA, TUSCANY, WESLEY, ARTHUR,\l"
	.string "FRIEDA and SANTOS.\p"
	.string "They're all older than me!$"

Route37_Text_Sunny_NotSunday:
	.string "SUNNY: Isn't today Sunday?\n"
	.string "Um… I forgot!$"

Route37_Text_Sign:
	.string "ROUTE 37\n"
	.string "ECRUTEAK CITY AHEAD$"
