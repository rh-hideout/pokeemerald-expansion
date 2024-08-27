Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_AUTOCLOSE
	giveitem ITEM_REVIVAL_HERB
	release
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
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
	.string "…Whoa!$"

Route102_Text_ImNotVeryTall:
	.string "I'm allergic to grass.\n"
	.string "Atleast you can touch grass.$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

Route102_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

Route102_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"
    
Route102_EventScript_Boy::
	lockall
	faceplayer
	goto_if_set FLAG_SUNKERN_GIFT, Route102_EventScript_AlreadyDone
	msgbox Route102_Text_HasCandyGivemon, MSGBOX_DEFAULT
	givemon SPECIES_SUNKERN, 14
	giveitem ITEM_SUN_STONE
	setflag FLAG_SUNKERN_GIFT
	releaseall
	return

Route102_Text_HasCandyGivemon:
	.string "Good luck on the Roxanne Split.\p"
	.string "{PLAYER} received a SUNKERN!$"

Route102_EventScript_AlreadyDone::
	msgbox Route102_Text_Done, MSGBOX_DEFAULT
	release
	end

Route102_Text_Done:
	.string "Best be on your way now.$"

Route102_Text_BoyText:
	.string "Make sure to get a rare candy. The \n"
	.string "lady outside the pokecenter gives one.\p"
	.string "{PLAYER} received a SUNKERN!$"
