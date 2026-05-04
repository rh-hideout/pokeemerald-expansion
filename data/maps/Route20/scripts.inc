.set LOCALID_ROUTE20_DENNIS, 17
.set LOCALID_ROUTE20_HEADLOCKER, 16

Route20_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route20_EventScript_ShellBell::
	finditem ITEM_SHELL_BELL
	end

Route20_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route20_EventScript_Nicole::
	trainerbattle_single TRAINER_NICOLE Route20_Text_SwimmerfNicoleSeen, Route20_Text_SwimmerfNicoleBeaten
	msgbox Route20_Text_SwimmerfNicoleAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Lori::
	trainerbattle_single TRAINER_LORI Route20_Text_SwimmerfLoriSeen, Route20_Text_SwimmerfLoriBeaten
	msgbox Route20_Text_SwimmerfLoriAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON Route20_Text_SwimmermCameronSeen, Route20_Text_SwimmermCameronBeaten
	msgbox Route20_Text_SwimmermCameronAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox Route20_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox Route20_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dennis::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route20_Text_Dennis, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Headlocker::
	lock
	faceplayer
	msgbox Route20_Text_Headlocker, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE20_HEADLOCKER, DIR_SOUTH
	release
	end

Route20_Text_Dennis:
	.string "DENNIS: SHAAAAAAAA!$"

Route20_Text_Headlocker:
	.string "There's a rare POKéMON on this\n"
	.string "route.\p"
	.string "And sometimes it carries a rare\n"
	.string "evolution item.\p"
	.string "That's double rare!\p"
	.string "I need to finish my POKéDEX, so\n"
	.string "I've been fishing here for hours!$"

Route20_Text_Seel:
	.string "SEEL: Seel seel!$"

Route20_Text_Dewgong:
	.string "DEWGONG: Goooong!$"

Route20_Text_SeafoamSign:
	.string "SEAFOAM ISLANDS$"

Route20_Text_SwimmerfNicoleSeen:
	.string "I feel so much lighter in water.$"

Route20_Text_SwimmerfNicoleBeaten:
	.string "Oh, no!$"

Route20_Text_SwimmerfNicoleAfterBattle:
	.string "Swimming exercises your full body.\p"
	.string "It's really good for you.$"

Route20_Text_SwimmerfLoriSeen:
	.string "What an impressive collection of\n"
	.string "GYM BADGES. We should battle!$"

Route20_Text_SwimmerfLoriBeaten:
	.string "No!$"

Route20_Text_SwimmerfLoriAfterBattle:
	.string "SURF is no longer the only HM move\n"
	.string "you use in water.$"

Route20_Text_SwimmermCameronSeen:
	.string "I guess it's impossible to swim\n"
	.string "all the way to JOHTO.$"

Route20_Text_SwimmermCameronBeaten:
	.string "Aiyah!$"

Route20_Text_SwimmermCameronAfterBattle:
	.string "Besides the sea, I can also swim\n"
	.string "in ponds and rivers.$"

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "What does this sign say?\p"
	.string "CINNABAR GYM LEADER: BLAINE$"

