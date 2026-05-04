CianwoodHouse1_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "I don't remember the last time\n"
	.string "someone came to visit me.\p"
	.string "When I was young, I was a\n"
	.string "POKéMON Trainer, too.\l"
	.string "I tried to reach the tower and\l"
	.string "dive into the ocean.\p"
	.string "I put a lot of effort into many\n"
	.string "things.\p"
	.string "Well, I take things easy now,\n"
	.string "listening to the waves and winds\l"
	.string "on this beach.$"

CianwoodCity_Text_BellTowerStory:
	.string "Have you heard of the TIN TOWER\n"
	.string "in ECRUTEAK?\p"
	.string "There are what they call Clear Bells\n"
	.string "on top of the tower.\p"
	.string "They don't make a single noise\n"
	.string "in strong winds.\p"
	.string "There is only one way to make them\n"
	.string "ring.\p"
	.string "It is to obtain another CLEAR BELL\n"
	.string "just like the ones at the top of the\l"
	.string "tower.\p"
	.string "I went after it when I was young.\n"
	.string "But I never got one...$"

CianwoodCity_Text_WhirlIslandsStory:
	.string "Have you heard of WHIRL ISLANDS?\p"
	.string "There are what they call Tidal Bells\n"
	.string "at its waterfall basin.\p"
	.string "They don't make a single noise\n"
	.string "in crashing waves.\p"
	.string "There is only one way to make them\n"
	.string "ring.\p"
	.string "It is to obtain another Tidal Bell\n"
	.string "just like the ones at the waterfall\l"
	.string "basin.\p"
	.string "I went after it when I was young.\n"
	.string "But I never got one...$"

CianwoodCity_Text_ClearBellReaction:
	.string "Oh! You've managed to get a\n"
	.string "CLEAR BELL?\p"
	.string "The old-time dream of mine...\n"
	.string "I see...\p"
	.string "You've done it...\n"
	.string "...\l"
	.string "...I can hear it!\p"
	.string "The chime of the bells on the wind\n"
	.string "coming from the direction of the\l"
	.string "TIN TOWER...$"

CianwoodCity_Text_TidalBellReaction:
	.string "Oh! You've managed to get a\n"
	.string "Tidal Bell?\p"
	.string "The old-time dream of mine...\n"
	.string "I see...\p"
	.string "You've done it...\n"
	.string "...\l"
	.string "...I can hear it!\p"
	.string "The chime of the bells on the sea\n"
	.string "breeze coming from the direction of\l"
	.string "the WHIRL ISLANDS...$"
