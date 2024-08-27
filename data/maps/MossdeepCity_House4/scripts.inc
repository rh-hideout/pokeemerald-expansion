MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer 
	goto_if_set FLAG_GIFT_STARTER, MossdeepCity_House4_EventScript_ServiceThanks
	message MossdeepCity_House4_Text_WhatStarterGeneration
	multichoice 20, 2, MULTI_CHOICE_STARTER, 0
	closemessage
	switch VAR_RESULT
	case 0, MossdeepCity_House4_EventScript_Gen1
	case 1,	MossdeepCity_House4_EventScript_Gen2
	case 2, MossdeepCity_House4_EventScript_Gen4
	case 3, MossdeepCity_House4_EventScript_Gen5
	case 4, MossdeepCity_House4_EventScript_Gen6
	case 5, MossdeepCity_House4_EventScript_Gen7
	case 6, MossdeepCity_House4_EventScript_Gen8
	release
	end

MossdeepCity_House4_EventScript_Gen1::
	message MossdeepCity_House4_Text_WhatStarterType
	multichoice 25, 5, MULTI_CHOICE_STARTER_GEN_1, 1
	closemessage
	switch VAR_RESULT
	case 0, MossdeepCity_House4_EventScript_1Gen1
	case 1, MossdeepCity_House4_EventScript_2Gen1
	case 2, MossdeepCity_House4_EventScript_3Gen1
	return

MossdeepCity_House4_EventScript_Gen2::
	message MossdeepCity_House4_Text_WhatStarterType
	multichoice 25, 5, MULTI_CHOICE_STARTER_GEN_2, 1
	closemessage
	switch VAR_RESULT
	case 0, MossdeepCity_House4_EventScript_1Gen2
	case 1, MossdeepCity_House4_EventScript_2Gen2
	case 2, MossdeepCity_House4_EventScript_3Gen2
	return

MossdeepCity_House4_EventScript_Gen4::
	message MossdeepCity_House4_Text_WhatStarterType
	multichoice 25, 5, MULTI_CHOICE_STARTER_GEN_4, 1
	closemessage
	switch VAR_RESULT
	case 0, MossdeepCity_House4_EventScript_1Gen4
	case 1, MossdeepCity_House4_EventScript_2Gen4
	case 2, MossdeepCity_House4_EventScript_3Gen4
	return

MossdeepCity_House4_EventScript_Gen5::
	message MossdeepCity_House4_Text_WhatStarterType
	multichoice 25, 5, MULTI_CHOICE_STARTER_GEN_5, 1
	closemessage
	switch VAR_RESULT
	case 0, MossdeepCity_House4_EventScript_1Gen5
	case 1, MossdeepCity_House4_EventScript_2Gen5
	case 2, MossdeepCity_House4_EventScript_3Gen5
	return

MossdeepCity_House4_EventScript_Gen6::
	message MossdeepCity_House4_Text_WhatStarterType
	multichoice 25, 5, MULTI_CHOICE_STARTER_GEN_6, 1
	closemessage
	switch VAR_RESULT
	case 0, MossdeepCity_House4_EventScript_1Gen6
	case 1, MossdeepCity_House4_EventScript_2Gen6
	case 2, MossdeepCity_House4_EventScript_3Gen6
	return

MossdeepCity_House4_EventScript_Gen7::
	message MossdeepCity_House4_Text_WhatStarterType
	multichoice 25, 5, MULTI_CHOICE_STARTER_GEN_7, 1
	closemessage
	switch VAR_RESULT
	case 0, MossdeepCity_House4_EventScript_1Gen7
	case 1, MossdeepCity_House4_EventScript_2Gen7
	case 2, MossdeepCity_House4_EventScript_3Gen7
	return

MossdeepCity_House4_EventScript_Gen8::
	message MossdeepCity_House4_Text_WhatStarterType
	multichoice 25, 5, MULTI_CHOICE_STARTER_GEN_8, 1
	closemessage
	switch VAR_RESULT
	case 0, MossdeepCity_House4_EventScript_1Gen8
	case 1, MossdeepCity_House4_EventScript_2Gen8
	case 2, MossdeepCity_House4_EventScript_3Gen8
	return

MossdeepCity_House4_EventScript_1Gen1::
	givemon SPECIES_CHARMANDER, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_2Gen1::
	givemon SPECIES_SQUIRTLE, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_3Gen1::
	givemon SPECIES_BULBASAUR, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_1Gen2::
	givemon SPECIES_CYNDAQUIL, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_2Gen2::
	givemon SPECIES_TOTODILE, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_3Gen2::
	givemon SPECIES_CHIKORITA, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_1Gen4::
	givemon SPECIES_CHIMCHAR, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_2Gen4::
	givemon SPECIES_PIPLUP, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_3Gen4::
	givemon SPECIES_TURTWIG, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_1Gen5::
	givemon SPECIES_TEPIG, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_2Gen5::
	givemon SPECIES_OSHAWOTT, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_3Gen5::
	givemon SPECIES_SNIVY, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_1Gen6::
	givemon SPECIES_FENNEKIN, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_2Gen6::
	givemon SPECIES_FROAKIE, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_3Gen6::
	givemon SPECIES_CHESPIN, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_1Gen7::
	givemon SPECIES_LITTEN, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_2Gen7::
	givemon SPECIES_POPPLIO, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_3Gen7::
	givemon SPECIES_ROWLET, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_1Gen8::
	givemon SPECIES_SCORBUNNY, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_2Gen8::
	givemon SPECIES_SOBBLE, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_3Gen8::
	givemon SPECIES_GROOKEY, 85
	setflag FLAG_GIFT_STARTER
	return

MossdeepCity_House4_EventScript_ServiceThanks::
	msgbox MossdeepCity_House4_Text_ServiceThanks, MSGBOX_AUTOCLOSE
	release
	end

MossdeepCity_House4_Text_ServiceThanks:
	.string "Thank you for visiting me$"
		
MossdeepCity_House4_Text_WhatStarterGeneration:
	.string "What Generation of Starter do you want?$"

MossdeepCity_House4_Text_WhatStarterType:
	.string "Which of the trio do you want?$"
