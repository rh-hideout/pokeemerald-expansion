Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_DANNY, Route1_Text_SchoolboyDanny_Seen, Route1_Text_SchoolboyDanny_Beaten
	msgbox Route1_Text_SchoolboyDanny_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Quinn::
	trainerbattle_single TRAINER_QUINN, Route1_Text_CooltrainerFQuinn_Seen, Route1_Text_CooltrainerFQuinn_Beaten
	msgbox Route1_Text_CooltrainerFQuinn_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_Text_SchoolboyDanny_Seen:
	.string "If trainers meet, the first\n"
	.string "thing to do is battle.$"

Route1_Text_SchoolboyDanny_Beaten:
	.string "Awww… I've got a losing record…$"

Route1_Text_SchoolboyDanny_AfterBattle:
	.string "For trainers, it's a given that\n"
	.string "we'll battle whenever we meet.$"

Route1_Text_CooltrainerFQuinn_Seen:
	.string "You there! Want to battle?$"

Route1_Text_CooltrainerFQuinn_Beaten:
	.string "Down and out…$"

Route1_Text_CooltrainerFQuinn_AfterBattle:
	.string "You're strong.\p"
	.string "You obviously must have trained\n"
	.string "hard.$"

Route1_Text_Sign:
	.string "ROUTE 1\p"
	.string "PALLET TOWN - VIRIDIAN CITY$"
