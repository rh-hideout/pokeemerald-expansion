Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route4_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route4_EventScript_HpUp::
	finditem ITEM_HP_UP
	end

Route4_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route4_EventScript_Hank::
	trainerbattle_single TRAINER_HANK, Route4_Text_BirdKeeperHank_Seen, Route4_Text_BirdKeeperHank_Beaten
	msgbox Route4_Text_BirdKeeperHank_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, Route4_Text_PicnickerHope_Seen, Route4_Text_PicnickerHope_Beaten
	msgbox Route4_Text_PicnickerHope_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sharon::
	trainerbattle_single TRAINER_SHARON, Route4_Text_PicnickerSharon_Seen, Route4_Text_PicnickerSharon_Beaten
	msgbox Route4_Text_PicnickerSharon_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_Text_BirdKeeperHank_Seen:
	.string "I'm raising my POKéMON. Want to battle\n"
	.string "with me?$"

Route4_Text_BirdKeeperHank_Beaten:
	.string "Ack! I lost that one…$"

Route4_Text_BirdKeeperHank_AfterBattle:
	.string "If you have a specific POKéMON that you\n"
	.string "want to raise, put it out first, then\l"
	.string "switch it right away.\p"
	.string "That's how to do it.$"

Route4_Text_PicnickerHope_Seen:
	.string "I have a feeling that I can win.\p"
	.string "Let's see if I'm right!$"

Route4_Text_PicnickerHope_Beaten:
	.string "Aww, you are too strong.$"

Route4_Text_PicnickerHope_AfterBattle:
	.string "I heard CLEFAIRY appear at MT.MOON.\p"
	.string "But where could they be?$"

Route4_Text_PicnickerSharon_Seen:
	.string "Um…\n"
	.string "I…$"

Route4_Text_PicnickerSharon_Beaten:
	.string "…$"

Route4_Text_PicnickerSharon_AfterBattle:
	.string "……I'll go train some more…$"

Route4_Text_MtMoonSquareSign:
	.string "MT.MOON NEW ENTRANCE\n"
	.string "DUE TO CAVE-IN\p"
	.string "WATCH YOUR STEP$"

