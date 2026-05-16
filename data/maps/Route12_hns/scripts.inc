Route12_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route12_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route12_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN_HNS, Route12_Text_FisherMartinSeen, Route12_Text_FisherMartinBeaten
	msgbox Route12_Text_FisherMartinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Stephen::
	trainerbattle_single TRAINER_STEPHEN_HNS, Route12_Text_FisherStephenSeen, Route12_Text_FisherStephenBeaten
	msgbox Route12_Text_FisherStephenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY_HNS, Route12_Text_FisherBarneySeen, Route12_Text_FisherBarneyBeaten
	msgbox Route12_Text_FisherBarneyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE_HNS, Route12_Text_FisherKyleSeen, Route12_Text_FisherKyleBeaten, Route12_EventScript_RegisterKyle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_RematchKyle
	msgbox Route12_Text_FisherKyleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_RegisterKyle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_KyleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KYLE_HNS
	release
	end

Route12_EventScript_RematchKyle::
	trainerbattle_rematch TRAINER_KYLE_HNS, Route12_Text_KyleRematchIntro, Route12_Text_KyleRematchDefeat
	msgbox Route12_Text_KylePostRematch, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_NewFisher::
	msgbox Route12_Text_NewFisher, MSGBOX_NPC
	end

Route12_EventScript_Elixir::
	finditem ITEM_ELIXIR
	end

Route12_EventScript_Calcium::
	finditem ITEM_CALCIUM
	end

Route12_EventScript_Tentacruel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_Text_NewFisher:
	.string "Careful, something vicious lives in\n"
	.string "these waters.$"

Route12_Text_FisherMartinSeen:
	.string "Patience is the key to both\n"
	.string "fishing and POKéMON.$"

Route12_Text_FisherMartinBeaten:
	.string "Gwaaah!$"

Route12_Text_FisherMartinAfterBattle:
	.string "I'm too impatient for fishing…$"

Route12_Text_FisherStephenSeen:
	.string "I feel so content, fishing while\n"
	.string "listening to some tunes on my\l"
	.string "radio.$"

Route12_Text_FisherStephenBeaten:
	.string "My stupid radio distracted me!$"

Route12_Text_FisherStephenAfterBattle:
	.string "Have you checked out KANTO's radio\n"
	.string "programs? We get a good variety\l"
	.string "here.$"

Route12_Text_FisherBarneySeen:
	.string "What's most important in our\n"
	.string "everyday lives?$"

Route12_Text_FisherBarneyBeaten:
	.string "The answer is coming up next!$"

Route12_Text_FisherBarneyAfterBattle:
	.string "I think electricity is the most\n"
	.string "important thing in our daily\l"
	.string "lives.\p"
	.string "If it weren't, people wouldn't\n"
	.string "have made such a fuss when the\l"
	.string "POWER PLANT went out of\l"
	.string "commission.$"

Route12_Text_KyleRegister:
	.string "I'll remember this.\n"
	.string "Give me your number!$"

Route12_Text_KyleRematchIntro:
	.string "Did you forget?\n"
	.string "Let's see!$"

Route12_Text_KyleRematchDefeat:
	.string "You remembered.$"

Route12_Text_KylePostRematch:
	.string "The thrill of battle is almost\n"
	.string "as good as a big catch!$"

Route12_Text_FisherKyleSeen:
	.string "Do you remember?$"

Route12_Text_FisherKyleBeaten:
	.string "You do remember?$"

Route12_Text_FisherKyleAfterBattle:
	.string "The tug you feel on the ROD when\n"
	.string "you hook a POKéMON…\p"
	.string "That's the best feeling ever for\n"
	.string "an angler like me.$"

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "ROUTE 12\p"
	.string "NORTH TO LAVENDER TOWN$"

Route12_Text_FishingSpotSign:
	.string "FISHING SPOT$"

