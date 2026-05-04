Route18_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route18_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route18_EventScript_Boris::
	trainerbattle_single TRAINER_BORIS Route18_Text_BirdKeeperBorisSeen, Route18_Text_BirdKeeperBorisBeaten
	msgbox Route18_Text_BirdKeeperBorisAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Bob::
	trainerbattle_single TRAINER_BOB Route18_Text_BirdKeeperBobSeen, Route18_Text_BirdKeeperBobBeaten
	msgbox Route18_Text_BirdKeeperBobAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Sign::
	msgbox Route18_Text_Sign, MSGBOX_SIGN
	end

Route18_Text_BirdKeeperBorisSeen:
	.string "If you're looking for POKéMON,\n"
	.string "you have to look in the tall grass.$"

Route18_Text_BirdKeeperBorisBeaten:
	.string "Ayieee!$"

Route18_Text_BirdKeeperBorisAfterBattle:
	.string "Since you're so strong, it must be\n"
	.string "fun to battle.$"

Route18_Text_BirdKeeperBobSeen:
	.string "CYCLING ROAD is a quick shortcut\n"
	.string "to CELADON.$"

Route18_Text_BirdKeeperBobBeaten:
	.string "…Whew!$"

Route18_Text_BirdKeeperBobAfterBattle:
	.string "If you don't have a BICYCLE,\n"
	.string "you're not allowed to use the\l"
	.string "shortcut.$"

Route18_Text_Sign:
	.string "ROUTE 18\p"
	.string "CELADON CITY - FUCHSIA CITY$"
