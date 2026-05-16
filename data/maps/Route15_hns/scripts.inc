Route15_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route15_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route15_EventScript_Colette::
	trainerbattle_single TRAINER_COLETTE_HNS, Route15_Text_TeacherColetteSeen, Route15_Text_TeacherColetteBeaten
	msgbox Route15_Text_TeacherColetteAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY_HNS, Route15_Text_TeacherHillarySeen, Route15_Text_TeacherHillaryBeaten, Route15_EventScript_RegisterHillary
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchHillary
	msgbox Route15_Text_TeacherHillaryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterHillary::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_HillaryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HILLARY_HNS
	release
	end

Route15_EventScript_RematchHillary::
	trainerbattle_rematch TRAINER_HILLARY_HNS, Route15_Text_HillaryRematchIntro, Route15_Text_HillaryRematchDefeat
	msgbox Route15_Text_HillaryPostRematch, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Kipp::
	trainerbattle_single TRAINER_KIPP_HNS, Route15_Text_SchoolboyKippSeen, Route15_Text_SchoolboyKippBeaten
	msgbox Route15_Text_SchoolboyKippAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY_HNS, Route15_Text_SchoolboyTommySeen, Route15_Text_SchoolboyTommyBeaten
	msgbox Route15_Text_SchoolboyTommyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Johnny::
	trainerbattle_single TRAINER_JOHNNY_HNS, Route15_Text_SchoolboyJohnnySeen, Route15_Text_SchoolboyJohnnyBeaten
	msgbox Route15_Text_SchoolboyJohnnyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY_HNS, Route15_Text_SchoolboyBillySeen, Route15_Text_SchoolboyBillyBeaten, Route15_EventScript_RegisterBilly
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchBilly
	msgbox Route15_Text_SchoolboyBillyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterBilly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_BillyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BILLY_HNS
	release
	end

Route15_EventScript_RematchBilly::
	trainerbattle_rematch TRAINER_BILLY_HNS, Route15_Text_BillyRematchIntro, Route15_Text_BillyRematchDefeat
	msgbox Route15_Text_BillyPostRematch, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_SIGN
	end

Route15_EventScript_PPup::
	finditem ITEM_PP_UP
	end

Route15_Text_TeacherColetteSeen:
	.string "Have you forgotten anything?$"

Route15_Text_TeacherColetteBeaten:
	.string "Kyaaah!$"

Route15_Text_TeacherColetteAfterBattle:
	.string "Before I became a teacher, I used\n"
	.string "to forget a lot of things.$"

Route15_Text_TeacherHillarySeen:
	.string "On sunny days, I think that the\n"
	.string "kids would rather be playing in the\l"
	.string "schoolyard than studying in class.$"

Route15_Text_TeacherHillaryBeaten:
	.string "I didn't want to lose…$"

Route15_Text_TeacherHillaryAfterBattle:
	.string "Studying is important, but\n"
	.string "exercise is just as vital.$"

Route15_Text_HillaryRegister:
	.string "You've taught me a lesson!\n"
	.string "May I have your number?$"

Route15_Text_HillaryRematchIntro:
	.string "I'll school you this time!$"

Route15_Text_HillaryRematchDefeat:
	.string "Back to the drawing board…$"

Route15_Text_HillaryPostRematch:
	.string "Teaching POKéMON is just like\n"
	.string "teaching children. Patience!$"

Route15_Text_SchoolboyKippSeen:
	.string "Hang on. I have to phone my mom.$"

Route15_Text_SchoolboyKippBeaten:
	.string "Sorry, Mom! I was beaten!$"

Route15_Text_SchoolboyKippAfterBattle:
	.string "My mom worries so much about me, I\n"
	.string "have to phone her all the time.$"

Route15_Text_SchoolboyTommySeen:
	.string "Let's battle. I won't lose!$"

Route15_Text_SchoolboyTommyBeaten:
	.string "I forgot to do my homework!$"

Route15_Text_SchoolboyTommyAfterBattle:
	.string "Sayonara! I just learned that in\n"
	.string "my Japanese class.$"

Route15_Text_SchoolboyJohnnySeen:
	.string "We're on a field trip to LAVENDER\n"
	.string "RADIO TOWER for social studies.$"

Route15_Text_SchoolboyJohnnyBeaten:
	.string "You're wickedly tough!$"

Route15_Text_SchoolboyJohnnyAfterBattle:
	.string "I'm tired of walking. I need to\n"
	.string "take a break.$"

Route15_Text_SchoolboyBillySeen:
	.string "My favorite class is Gym!$"

Route15_Text_SchoolboyBillyBeaten:
	.string "Oh, no! How could I lose?$"

Route15_Text_SchoolboyBillyAfterBattle:
	.string "If POKéMON were a subject at\n"
	.string "school, I'd be the best!$"

Route15_Text_BillyRegister:
	.string "I should've paid more attention in class.\n"
	.string "Can I have your number?$"

Route15_Text_BillyRematchIntro:
	.string "I've been studying hard!\n"
	.string "Let me show you what I learned!$"

Route15_Text_BillyRematchDefeat:
	.string "I need to study more…$"

Route15_Text_BillyPostRematch:
	.string "Book smarts aren't everything.\n"
	.string "I need battle experience too!$"

Route15_Text_Sign:
	.string "ROUTE 15\p"
	.string "FUCHSIA CITY - LAVENDER TOWN$"

