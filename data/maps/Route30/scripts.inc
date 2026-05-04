.set LOCALID_ROUTE_30_JOEY, 6

Route30_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0
	
Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 30
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end
	
Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
	.string "MR.POKéMON's House$"

Route30_Text_UseTackle:
	.string "Go, RATTATA!\p"
	.string "TACKLE!$"

Route30_Text_ThisIsABigBattle:
	.string "What? This is a big battle!\n"
	.string "Leave me alone!$"

Route30_Text_YoungsterJoey1Seen:
	.string "I just lost, so I'm trying to\n"
	.string "find more POKéMON.\p"
	.string "Wait! You look weak! Come on,\n"
	.string "let's battle!$"

Route30_Text_YoungsterJoey1Beaten:
	.string "Ack! I lost again!\n"
	.string "Doggone it!$"

Route30_Text_YoungsterJoey1After:
	.string "Do I have to have more POKéMON\n"
	.string "in order to battle better?\p"
	.string "No! I'm sticking with this one\n"
	.string "no matter what!$"

Route30_Text_YoungsterMikeySeen:
	.string "You're a POKéMON trainer,\n"
	.string "right?\p"
	.string "Then you have to battle!$"

Route30_Text_YoungsterMikeyBeaten:
	.string "That's strange.\n"
	.string "I won before.$"

Route30_Text_YoungsterMikeyAfter:
	.string "Becoming a good trainer is\n"
	.string "really tough.\p"
	.string "I'm going to battle other\n"
	.string "people to get better.$"

Route30_Text_BugCatcherDonSeen:
	.string "Instead of a bug POKéMON,\n"
	.string "I found a trainer!$"

Route30_Text_BugCatcherDonBeaten:
	.string "Argh! You're too strong!$"

Route30_Text_BugCatcherDonAfter:
	.string "I ran out of POKé BALLS while\n"
	.string "I was catching POKéMON.\p"
	.string "I should've bought some more…$"

Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "MR. POKéMON's house?\n"
	.string "It's a bit farther ahead.$"

Route30_Text_YoungsterEveryoneIsBattling:
	.string "Everyone's having fun\n"
	.string "battling!\p"
	.string "You should too!$"

Route30_Text_CooltrainerF:
	.string "I'm not a trainer.\p"
	.string "But if you look one in the\n"
	.string "eyes, prepare to battle.$"

Route30_Text_Sign:
	.string "ROUTE 30\p"
	.string "VIOLET CITY - CHERRYGROVE CITY$"

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "MR. POKéMON'S HOUSE\n"
	.string "STRAIGHT AHEAD!$"

Route30_Text_MrPokemonsHouseSign:
	.string "MR. POKéMON'S HOUSE$"

Route30_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "No stealing other people's\n"
	.string "POKéMON!\p"
	.string "POKé BALLS are to be thrown\n"
	.string "only at wild POKéMON!$"

Route30_Text_YoungsterJoeyGiveHPUp:
	.string "I lost again…\n"
	.string "Gee, you're tough!\p"
	.string "Oh yeah, I almost forgot that\n"
	.string "I had to give you this.\p"
	.string "Use it to get even tougher,\n"
	.string "OK?\p"
	.string "I'm going to get tougher too.$"

Route30_Text_Elm_Disaster:
	.string "PROF.ELM: H-hello? {PLAYER}? It's\n"
	.string "a disaster!\p"
	.string "Uh, um, it's just terrible!\p"
	.string "What should I do? It…\n"
	.string "Oh, no…\p"
	.string "Please get back here now!$"


Route30_Text_Poliwag:
	.string "POLIWAG: Wag waag!$"
