Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end
	

Route102_Text_WatchMeCatchPokemon:
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt:
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

Route102_Text_LetsGoBack:
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

Route102_Text_ImNotVeryTall:
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

Route102_Text_RouteSignOldale:
	.string "Pokemon in grass: Seedot, Lotad,\n"
	.string "and Ralts. \p"
	.string "Fishing Pokemon: Corphish\p"
	.string "Surfing Pokemon: Marill$"

Route102_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"

// Calvin battle code -----------------------------------------------------------------------------

TrainerBattleCalvin::
	lockall
	faceplayer
	goto_if_not_defeated TRAINER_DALTON_2 Calvin_AskforInitialBattle
	goto_if_eq Calvin_AskforRematch
	end

//if you have battled them before	
Calvin_AskforRematch:
	msgbox CalvinReBattle_Text_Ask, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq CalvinBattleStart
	goto_if_ne CalvinDecline
	releaseall
	end
//if you haven't battled them before
Calvin_AskforInitialBattle:
	msgbox CalvinInitialBattle_Text_ask, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq CalvinBattleStart
	goto_if_ne CalvinDecline
	releaseall
	end
//regardless, this is the start of the battle. 
CalvinBattleStart:
	cleartrainerflag TRAINER_DALTON_2
	trainerbattle_single TRAINER_DALTON_2, CalvinBattle_Text_BattleBegin, CalvinBattle_Text_BattleEnd
	releaseall
	end
//if you decline the battle	
CalvinDecline:
	msgbox Calvin_Text_Decline, MSGBOX_DEFAULT
    releaseall
    end

//what they say if you haven't battled before
CalvinInitialBattle_Text_ask:
	.string "If you have POKéMON with you, then\n"
	.string "you're an official POKéMON TRAINER!\l"
	.string "You can't say no to my challenge!$"

//what you say if you HAVE battled before
CalvinReBattle_Text_Ask:
	.string "Ever since I lost to you, I desperately\n"
	.string "trained my POKéMON.\l"
	.string "You can't say no to my challenge!$"

//what they say once you've agreed to battle
CalvinBattle_Text_BattleBegin:
	.string "Yes! Let's go!$"
	
//what they say after you beat them	
CalvinBattle_Text_BattleEnd:
	.string "Arrgh, I lost…\n"
	.string "Is my training method not right?$"
	
//what they say if you decline to battle	
Calvin_Text_Decline:
	.string "If you're going to get stronger,\n"
	.string "I'll get stronger, too.$"
