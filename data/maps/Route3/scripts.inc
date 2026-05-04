Route3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT, Route3_Text_FirebreatherBurt_Seen, Route3_Text_FirebreatherBurt_Beaten
	msgbox Route3_Text_FirebreatherBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "Ah! The weather's as fine as ever.$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "It's sunny, but I'm all wet…$"

Route3_Text_FirebreatherOtis_AfterBattle:
	.string "When it rains, it's hard to get\n"
	.string "ignition…$"

Route3_Text_YoungsterWarren_Seen:
	.string "Hmmm… I don't know what to do…$"

Route3_Text_YoungsterWarren_Beaten:
	.string "I knew I'd lose…$"

Route3_Text_YoungsterWarren_AfterBattle:
	.string "You looked strong.\p"
	.string "I was afraid to take you on…$"

Route3_Text_YoungsterJimmy_Seen:
	.string "I can run like the wind!$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "Blown away!$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "I wear shorts the whole year round.\p"
	.string "That's my fashion policy.$"

Route3_Text_FirebreatherBurt_Seen:
	.string "Step right up and take a look!$"

Route3_Text_FirebreatherBurt_Beaten:
	.string "Yow! That's hot!$"

Route3_Text_FirebreatherBurt_AfterBattle:
	.string "The greatest fire-breather in KANTO,\n"
	.string "that's me.\p"
	.string "But not the best trainer…$"

Route3_Text_MtMoonSquareSign:
	.string "MT.MOON SQUARE\p"
	.string "Just go up the stairs.$"

