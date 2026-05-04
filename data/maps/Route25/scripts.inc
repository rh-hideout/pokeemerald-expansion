.set LOCALID_ROUTE25_MISTY, 10
.set LOCALID_ROUTE25_MAN, 11
.set LOCALID_ROUTE25_SUICUNE, 16
.set LOCALID_ROUTE25_EUSINE, 15
.set LOCALID_CAPE_MISTY, 20

Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route25_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 7, Route25_EventScript_SetSuicuneSceneMid
	end

Route25_EventScript_SetSuicuneSceneMid::
	setobjectxyperm LOCALID_ROUTE25_EUSINE, 65, 9
	end

Route25_EventScript_MistyRematch::
    lock
    faceplayer
    msgbox Route25_Text_Misty, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CAPE_MISTY
    removeobject LOCALID_CAPE_MISTY
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_MISTY
    release
    end

Route25_Text_Misty:
    .string "MISTY: I love the sunset here!\n"
	.string "It gives me the courage to go on,\l"
	.string "you know?\p"
	.string "Right!\p"
	.string "If you're ready for a real splash,\n"
	.string "meet me at the FIGHTING DOJO!$"

Route25_EventScript_Dudley::
	trainerbattle_single TRAINER_DUDLEY Route25_Text_SchoolboyDudleySeen, Route25_Text_SchoolboyDudleyBeaten
	msgbox Route25_Text_SchoolboyDudleyAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Ellen::
	trainerbattle_single TRAINER_ELLEN Route25_Text_LassEllenSeen, Route25_Text_LassEllenBeaten
	msgbox Route25_Text_LassEllenAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Joe::
	trainerbattle_single TRAINER_JOE Route25_Text_SchoolboyJoeSeen, Route25_Text_SchoolboyJoeBeaten
	msgbox Route25_Text_SchoolboyJoeAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA Route25_Text_LassLauraSeen, Route25_Text_LassLauraBeaten
	msgbox Route25_Text_LassLauraAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Lloyd::
	trainerbattle_single TRAINER_LLOYD Route25_Text_CamperLloydSeen, Route25_Text_CamperLloydBeaten
	msgbox Route25_Text_CamperLloydAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON Route25_Text_LassShannonSeen, Route25_Text_LassShannonBeaten
	msgbox Route25_Text_LassShannonAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Pat::
	trainerbattle_single TRAINER_PAT Route25_Text_SupernerdPatSeen, Route25_Text_SupernerdPatBeaten
	msgbox Route25_Text_SupernerdPatAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Kevin::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE25_GOT_NUGGET, Route25_EventScript_KevinAfter
	msgbox Route25_Text_CooltrainerKevinNugget, MSGBOX_DEFAULT
	giveitem ITEM_BIG_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE25_GOT_NUGGET
	msgbox Route25_Text_CooltrainerKevinSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KEVIN, Route25_Text_CooltrainerKevinBeaten
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_DEFAULT
	closemessage
	release
	end
Route25_EventScript_KevinAfter::
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_NPC
	end

Route25_EventScript_BillsHouseSign::
	msgbox Route25_Text_BillsHouseSign, MSGBOX_SIGN
	end

Route25_Trigger_MistyRight::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement2 LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveRight
	waitmovement 0
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerRight
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route25_EventScript_Misty
Route25_Trigger_MistyLeft::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement2 LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveLeft
	waitmovement 0
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerLeft
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto Route25_EventScript_Misty
Route25_EventScript_Misty::
	msgbox Route25_Text_MistyDate, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_MISTY
	removeobject LOCALID_ROUTE25_MAN
	setflag FLAG_HIDE_ROUTE25_MISTY
	clearflag FLAG_HIDE_CERULEAN_GYM_TRAINERS
	setflag FLAG_HIDE_CERULEAN_GYM_POKEMON
	setvar VAR_CERULEAN_CITY_STATE, 3
	release
	end

Route25_Trigger_SuicuneLeft::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_Trigger_SuicuneRight::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_EventScript_SuicuneMerge::
	clearflag FLAG_HIDE_ROUTE25_EUSINE
	addobject LOCALID_ROUTE25_EUSINE
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox Route25_Text_Eusine1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineSide
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox Route25_Text_Eusine2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SUICUNE_ENCOUNTERS, 7
	release
	end
	
Route25_Text_Eusine1:
	.string "EUSINE: Puff, puff...\n"
	.string "I am... no match for you.\p"
	.string "...As I predicted.\n"
	.string "..........................\l"
	.string "... Go ahead.\p"
	.string "Since I met you in the BURNED TOWER\n"
	.string "at ECRUTEAK CITY, I've sort of\l"
	.string "known that SUICUNE would choose\l"
	.string "you.$"

Route25_Text_Eusine2:
	.string "Take a look at it!\p"
	.string "SUICUNE is waiting for you!\n"
	.string "It has been waiting for a battle\l"
	.string "with a worthy trainer to whom it\l"
	.string "can entrust itself.$"

Route25_Text_Eusine3:
	.string "{PLAYER}...\n"
	.string "You two are truly amazing...\p"
	.string "I have never seen a battle this\n"
	.string "intense!\l"
	.string "I have no regrets...\p"
	.string "Farewell, SUICUNE!\n"
	.string "Farewell... {PLAYER}!$"

Route25_EventScript_Eusine::
	msgbox Route25_Text_Eusine2, MSGBOX_NPC
	end

Route25_EventScript_Suicune::
	lock
	faceplayer
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_SUICUNE, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route25_EventScript_SuicuneRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE25_SUICUNE
	setflag FLAG_HIDE_ROUTE25_SUICUNE
	fadescreenswapbuffers FADE_FROM_BLACK
	goto_if_ge VAR_SUICUNE_ENCOUNTERS, 8, Route25_EventScript_SuicunePostGame
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 66, Route25_AdjustPlayer
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	turnobject LOCALID_ROUTE25_EUSINE, DIR_NORTH
	msgbox Route25_Text_Eusine3, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_EUSINE
	setflag FLAG_HIDE_ROUTE25_EUSINE
	clearflag FLAG_HIDE_CELADON_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 8
	release
	end

Route25_EventScript_SuicuneRan::
	release
	end

Route25_AdjustPlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

Route25_EventScript_SuicunePostGame::
	release
	end

Route25_Movement_EusineLeave:
	walk_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route25_Movement_EusineSide:
	walk_slow_left
	walk_slow_up
	step_end

Route25_Movement_EusineEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_slow_up
	step_end

Route25_Movement_Suicune1:
	jump_in_place_down
	step_end

Route25_Movement_WalkToSuicune:
	walk_up
	walk_up
	step_end

Route25_Movement_MistyLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route25_Movement_ManLeaveRight:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
Route25_Movement_ManLeaveLeft:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route25_Movement_MistyWalkToPlayerRight:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end
Route25_Movement_MistyWalkToPlayerLeft:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Route25_Text_MistyDate:
	.string "MISTY: Aww! Why did you have to\n"
	.string "show up and bug us now?\p"
	.string "Do you know what they call\n"
	.string "people like you?\p"
	.string "Pests! You heard me right,\n"
	.string "pest!\p"
	.string "…\p"
	.string "…Oh? Those BADGES you have…\n"
	.string "Are they JOHTO GYM BADGES?\p"
	.string "If you have eight, you must be\n"
	.string "good.\p"
	.string "OK, then. Come to CERULEAN GYM.\p"
	.string "I'll be happy to take you on.\p"
	.string "I'm MISTY, the GYM LEADER in\n"
	.string "CERULEAN.$"

Route25_Text_SchoolboyDudleySeen:
	.string "Beat the six of us trainers to\n"
	.string "win a fabulous prize!\p"
	.string "Think you've got what it takes?$"

Route25_Text_SchoolboyDudleyBeaten:
	.string "Whoo! Good stuff.$"

Route25_Text_SchoolboyDudleyAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_LassEllenSeen:
	.string "I'm second.\n"
	.string "Now it's serious!$"

Route25_Text_LassEllenBeaten:
	.string "How could I lose?$"

Route25_Text_LassEllenAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_SchoolboyJoeSeen:
	.string "Here's No. 3!\n"
	.string "I won't be easy.$"

Route25_Text_SchoolboyJoeBeaten:
	.string "Ow! Stomped flat!$"

Route25_Text_SchoolboyJoeAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_LassLauraSeen:
	.string "I'm No. 4!\n"
	.string "Getting tired?$"

Route25_Text_LassLauraBeaten:
	.string "I lost too…$"

Route25_Text_LassLauraAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_CamperLloydSeen:
	.string "OK! I'm No. 5.\n"
	.string "I'll stomp you!$"

Route25_Text_CamperLloydBeaten:
	.string "Whoa! Too much.$"

Route25_Text_CamperLloydAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_LassShannonSeen:
	.string "I'm the last in line, but I tell\n"
	.string "you, I'm tough!$"

Route25_Text_LassShannonBeaten:
	.string "You're kidding.$"

Route25_Text_LassShannonAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_SupernerdPatSeen:
	.string "Mufufufu…\p"
	.string "I have nothing to do with the\n"
	.string "six-pack trainers.\p"
	.string "I waited here to beat you when\n"
	.string "you were tired out by all the\l"
	.string "battles.$"

Route25_Text_SupernerdPatBeaten:
	.string "Aren't you tired at all?$"

Route25_Text_SupernerdPatAfter:
	.string "I'm sorry… I won't cheat\n"
	.string "anymore…$"

Route25_Text_CooltrainerKevinNugget:
	.string "You took on one more battle than\n"
	.string "you expected, but you won\l"
	.string "anyway.\p"
	.string "As promised, you win a prize.$"

Route25_Text_CooltrainerKevinSeen:
	.string "But after seeing how you battle,\n"
	.string "I want to see how I'll fare.\p"
	.string "How about it? Let me take you\n"
	.string "on.$"

Route25_Text_CooltrainerKevinBeaten:
	.string "I've never had a battle this\n"
	.string "good!$"

Route25_Text_CooltrainerKevinAfter:
	.string "That was a great battle!\p"
	.string "You and your POKéMON are truly\n"
	.string "outstanding!$"

Route25_Text_BillsHouseSign:
	.string "SEA COTTAGE\n"
	.string "BILL'S HOUSE$"

