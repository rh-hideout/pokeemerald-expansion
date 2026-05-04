Route2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route2_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route2_EventScript_Rob::
	trainerbattle_single TRAINER_ROB, Route2_Text_BugCatcherRob_Seen, Route2_Text_BugCatcherRob_Beaten
	msgbox Route2_Text_BugCatcherRob_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Ed::
	trainerbattle_single TRAINER_ED, Route2_Text_BugCatcherEd_Seen, Route2_Text_BugCatcherEd_Beaten
	msgbox Route2_Text_BugCatcherEd_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route2_Text_BugCatcherDoug_Seen, Route2_Text_BugCatcherDoug_Beaten
	msgbox Route2_Text_BugCatcherDoug_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_EventScript_CaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_EventScript_Carbos::
    finditem ITEM_CARBOS
    end

Route2_EventScript_Nugget::
    finditem ITEM_NUGGET
    end

Route2_Text_BugCatcherRob_Seen:
	.string "My bug POKéMON are tough. Prepare to\n"
	.string "lose!$"

Route2_Text_BugCatcherRob_Beaten:
	.string "I was whipped…$"

Route2_Text_BugCatcherRob_AfterBattle:
	.string "I'm going to look for stronger bug\n"
	.string "POKéMON.$"

Route2_Text_BugCatcherEd_Seen:
	.string "If you walk in tall grass wearing\n"
	.string "shorts, do you get nicks and cuts?$"

Route2_Text_BugCatcherEd_Beaten:
	.string "Ouch, ouch, ouch!$"

Route2_Text_BugCatcherEd_AfterBattle:
	.string "They'll really sting when you take a\n"
	.string "bath.$"

Route2_Text_BugCatcherDoug_Seen:
	.string "Why don't girls like bug POKéMON?$"

Route2_Text_BugCatcherDoug_Beaten:
	.string "No good!$"

Route2_Text_BugCatcherDoug_AfterBattle:
	.string "Bug POKéMON squish like plush toys\n"
	.string "when you squeeze their bellies.\p"
	.string "I love how they feel!$"

Route2_Text_Sign:
	.string "ROUTE 2\p"
	.string "VIRIDIAN CITY - PEWTER CITY$"

Route2_Text_DiglettsCaveSign:
	.string "DIGLETT'S CAVE$"

