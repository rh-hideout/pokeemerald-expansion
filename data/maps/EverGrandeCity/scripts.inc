EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_NurseGift::
	lockall
	faceplayer
	call_if_unset FLAG_RESTRITCED_EXPLAINED, EverGrandeCity_EventScript_ExplainRestricted
	goto_if_set FLAG_RESTRICTED_GIVEN, EverGrandeCity_EventScript_Hacker
	goto_if_unset FLAG_FIRST_RESTRICTED, EverGrandeCity_EventScript_NurseFirstGift
	goto_if_set FLAG_HARDCORE_MODE_ENABLED, EverGrandeCity_EventScript_Hacker
	message EverGrandeCity_Text_WhatGeneration
	multichoice 25, 2, MULTI_CHOICE_GENERATIONS, 0
	closemessage
	switch VAR_RESULT
	case 0, EverGrandeCity_EventScript_Generation1
	case 1, EverGrandeCity_EventScript_Generation2
	case 2, EverGrandeCity_EventScript_Generation3
	case 3, EverGrandeCity_EventScript_Generation4
	case 4, EverGrandeCity_EventScript_Generation5
	case 5, EverGrandeCity_EventScript_Generation6
	case 6, EverGrandeCity_EventScript_Generation7
	case 7, EverGrandeCity_EventScript_Generation8
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end
EverGrandeCity_EventScript_NurseFirstGift::
	message EverGrandeCity_Text_WhatGeneration
	multichoice 20, 2, MULTI_CHOICE_GENERATIONS, 0
	closemessage
	switch VAR_RESULT
	case 0, EverGrandeCity_EventScript_Generation1
	case 1, EverGrandeCity_EventScript_Generation2
	case 2, EverGrandeCity_EventScript_Generation3
	case 3, EverGrandeCity_EventScript_Generation4
	case 4, EverGrandeCity_EventScript_Generation5
	case 5, EverGrandeCity_EventScript_Generation6
	case 6, EverGrandeCity_EventScript_Generation7
	case 7, EverGrandeCity_EventScript_Generation8
	releaseall
	end

EverGrandeCity_EventScript_Hacker::
	msgbox EverGrandeCity_Text_Hacker
	releaseall
	end
	
EverGrandeCity_EventScript_Generation1::
	message EverGrandeCity_Text_WhatMonGeneration
	multichoice 20, 2, MULTI_CHOICE_RESTRICTED_GEN_1, 0
	closemessage
	switch VAR_RESULT
	case 0, EverGrandeCity_EventScript_GiveMew
	case 1, EverGrandeCity_EventScript_GiveMewtwo
	return
	
EverGrandeCity_EventScript_Generation2::
	message EverGrandeCity_Text_WhatMonGeneration
	multichoice 20, 2, MULTI_CHOICE_RESTRICTED_GEN_2, 0
	closemessage
	switch VAR_RESULT
	case 0, EverGrandeCity_EventScript_GiveLugia
	case 1, EverGrandeCity_EventScript_GiveHooh
	case 2, EverGrandeCity_EventScript_GiveCelebi
	return

EverGrandeCity_EventScript_Generation3::
	message EverGrandeCity_Text_WhatMonGeneration
	multichoice 20, 2, MULTI_CHOICE_RESTRICTED_GEN_3, 0
	closemessage
	switch VAR_RESULT
	case 0, EverGrandeCity_EventScript_GiveLatias
	case 1, EverGrandeCity_EventScript_GiveLatios
	case 2, EverGrandeCity_EventScript_GiveJirachi
	case 3, EverGrandeCity_EventScript_GiveRaikou
	case 4, EverGrandeCity_EventScript_GiveEntei
	case 5, EverGrandeCity_EventScript_GiveSuicune
	return
EverGrandeCity_EventScript_Generation4::
	message EverGrandeCity_Text_WhatMonGeneration
	multichoice 20, 2, MULTI_CHOICE_RESTRICTED_GEN_4, 0
	closemessage
	switch VAR_RESULT
	case 0, EverGrandeCity_EventScript_GiveHeatran
	case 1, EverGrandeCity_EventScript_GiveCresselia
	case 2, EverGrandeCity_EventScript_GiveShayminS
	case 3, EverGrandeCity_EventScript_GiveDialga
	case 4, EverGrandeCity_EventScript_GivePalkia
	case 5, EverGrandeCity_EventScript_GiveGiratina
	return

EverGrandeCity_EventScript_Generation5::
	message EverGrandeCity_Text_WhatMonGeneration
	multichoice 20, 2, MULTI_CHOICE_RESTRICTED_GEN_5, 0
	switch VAR_RESULT
	case 0, EverGrandeCity_EventScript_GiveReshiram
	case 1, EverGrandeCity_EventScript_GiveZekrom
	case 2, EverGrandeCity_EventScript_GiveKyurem
	case 3, EverGrandeCity_EventScript_GiveGenesect
	case 4, EverGrandeCity_EventScript_GiveTornadusI
	case 5, EverGrandeCity_EventScript_GiveTornadusT
	case 6, EverGrandeCity_EventScript_GiveLandorusI
	case 7, EverGrandeCity_EventScript_GiveLandorusT
	case 8, EverGrandeCity_EventScript_GiveThundurusI
	case 9, EverGrandeCity_EventScript_GiveThundurusT
	case 10, EverGrandeCity_EventScript_GiveKeldeo
	case 11, EverGrandeCity_EventScript_GiveCobalion
	case 12, EverGrandeCity_EventScript_GiveTerrakion
	case 13, EverGrandeCity_EventScript_GiveVirizion
	closemessage
	return

EverGrandeCity_EventScript_Generation6::
	message EverGrandeCity_Text_WhatMonGeneration
	multichoice 20, 2, MULTI_CHOICE_RESTRICTED_GEN_6, 0
	closemessage
	switch VAR_RESULT
	case 0,  EverGrandeCity_EventScript_GiveHoopaU
	case 1, EverGrandeCity_EventScript_GiveVolcanion
	return

EverGrandeCity_EventScript_Generation7::
	message EverGrandeCity_Text_WhatMonGeneration
	multichoice 20, 2, MULTI_CHOICE_RESTRICTED_GEN_7, 0
	closemessage
	switch VAR_RESULT
	case 0, EverGrandeCity_EventScript_GiveMagearna
	case 1, EverGrandeCity_EventScript_GiveMarshadow
	case 2, EverGrandeCity_EventScript_GiveZeraora
	case 3, EverGrandeCity_EventScript_GiveMelmetal 
	case 4, EverGrandeCity_EventScript_GiveNecrozma
	return

EverGrandeCity_EventScript_Generation8::
	message EverGrandeCity_Text_WhatMonGeneration
	multichoice 20, 2, MULTI_CHOICE_RESTRICTED_GEN_8, 0
	closemessage
	switch VAR_RESULT
	case 0, EverGrandeCity_EventScript_GiveZarude
	case 1, EverGrandeCity_EventScript_GiveUrshifuR
	case 2, EverGrandeCity_EventScript_GiveUrshifuS
	case 3, EverGrandeCity_EventScript_GiveEternatus
	case 4, EverGrandeCity_EventScript_GiveRegidrago
	case 5, EverGrandeCity_EventScript_GiveRegieleki
	return

EverGrandeCity_EventScript_SetFlags::
	goto_if_set FLAG_FIRST_RESTRICTED, EverGrandeCity_EventScript_SetFlag2
	setflag FLAG_FIRST_RESTRICTED
	return

EverGrandeCity_EventScript_SetFlag2::
	setflag FLAG_RESTRICTED_GIVEN
	return

EverGrandeCity_EventScript_GiveMewtwo::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_MEWTWO, 95
	return

EverGrandeCity_EventScript_GiveMew::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_MEW, 95
	return

EverGrandeCity_EventScript_GiveLugia::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_LUGIA, 95
	return

EverGrandeCity_EventScript_GiveHooh::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_HO_OH, 95
	return

EverGrandeCity_EventScript_GiveCelebi::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_CELEBI, 95
	return

EverGrandeCity_EventScript_GiveLatias::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_LATIOS, 95
	return

EverGrandeCity_EventScript_GiveLatios::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_LATIAS, 95
	return

EverGrandeCity_EventScript_GiveJirachi::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_JIRACHI, 95
	return

EverGrandeCity_EventScript_GiveRaikou::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_JIRACHI, 95
	return

EverGrandeCity_EventScript_GiveEntei::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_JIRACHI, 95
	return

EverGrandeCity_EventScript_GiveSuicune::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_JIRACHI, 95
	return

EverGrandeCity_EventScript_GiveHeatran::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_HEATRAN, 95
	return

EverGrandeCity_EventScript_GiveCresselia::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_CRESSELIA, 95
	return

EverGrandeCity_EventScript_GiveShayminS::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_SHAYMIN_SKY, 95
	giveitem ITEM_GRACIDEA
	return

EverGrandeCity_EventScript_GiveDialga::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_DIALGA, 95, ITEM_ADAMANT_ORB
	releaseall
	end

EverGrandeCity_EventScript_GivePalkia::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_PALKIA, 95, ITEM_LUSTROUS_ORB
	releaseall
	end

EverGrandeCity_EventScript_GiveGiratina::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_GIRATINA, 95, ITEM_GRISEOUS_ORB
	releaseall
	end

EverGrandeCity_EventScript_GiveReshiram::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_RESHIRAM, 95
	return

EverGrandeCity_EventScript_GiveZekrom::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_ZEKROM, 95
	return

EverGrandeCity_EventScript_GiveKyurem::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_KYUREM, 95
	return

EverGrandeCity_EventScript_GiveGenesect::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_GENESECT, 95
	message EverGrandeCity_Text_WhatDrive
	multichoice 20, 2, MULTI_CHOICE_GENESECT_DRIVE, 0
	closemessage
	switch VAR_RESULT
	case 0, EverGrandeCity_EventScript_BurnDrive
	case 1, EverGrandeCity_EventScript_ChillDrive
	case 2, EverGrandeCity_EventScript_DouseDrive
	case 3, EverGrandeCity_EventScript_ShockDrive
	releaseall
	end
EverGrandeCity_EventScript_BurnDrive::
	giveitem ITEM_BURN_DRIVE
	releaseall
	end
EverGrandeCity_EventScript_ChillDrive::
	giveitem ITEM_CHILL_DRIVE
	releaseall
	end
EverGrandeCity_EventScript_DouseDrive::
	giveitem ITEM_DOUSE_DRIVE
	releaseall
	end
EverGrandeCity_EventScript_ShockDrive::
	giveitem ITEM_SHOCK_DRIVE
	releaseall
	end

EverGrandeCity_EventScript_GiveTornadusT::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_TORNADUS_THERIAN, 95
	return

EverGrandeCity_EventScript_GiveTornadusI::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_TORNADUS_INCARNATE, 95
	return

EverGrandeCity_EventScript_GiveLandorusT::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_LANDORUS_THERIAN, 95
	return

EverGrandeCity_EventScript_GiveLandorusI::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_LANDORUS_INCARNATE, 95
	return

EverGrandeCity_EventScript_GiveThundurusI::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_THUNDURUS_INCARNATE, 95
	return

EverGrandeCity_EventScript_GiveThundurusT::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_THUNDURUS_THERIAN, 95
	return

EverGrandeCity_EventScript_GiveKeldeo::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_KELDEO, 95
	return

EverGrandeCity_EventScript_GiveCobalion::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_COBALION, 95
	return

EverGrandeCity_EventScript_GiveTerrakion::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_TERRAKION, 95
	return

EverGrandeCity_EventScript_GiveVirizion::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_VIRIZION, 95
	return

EverGrandeCity_EventScript_GiveHoopaU::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_HOOPA_UNBOUND, 95
	return

EverGrandeCity_EventScript_GiveVolcanion::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_VOLCANION, 95
	return

EverGrandeCity_EventScript_GiveMagearna::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_MAGEARNA, 95
	return

EverGrandeCity_EventScript_GiveMarshadow::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_MARSHADOW, 95
	return

EverGrandeCity_EventScript_GiveZeraora::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_ZERAORA, 95
	return

EverGrandeCity_EventScript_GiveMelmetal::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_MELMETAL, 95
	return

EverGrandeCity_EventScript_GiveNecrozma::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_NECROZMA, 95
	return

EverGrandeCity_EventScript_GiveZarude::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_ZARUDE, 95
	return

EverGrandeCity_EventScript_GiveUrshifuR::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_URSHIFU_RAPID_STRIKE, 95
	return

EverGrandeCity_EventScript_GiveUrshifuS::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_URSHIFU_SINGLE_STRIKE, 95
	return

EverGrandeCity_EventScript_GiveEternatus::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_ETERNATUS, 95
	return

EverGrandeCity_EventScript_GiveRegidrago::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_REGIDRAGO, 95
	return

EverGrandeCity_EventScript_GiveRegieleki::
	call EverGrandeCity_EventScript_SetFlags
	givemon SPECIES_REGIELEKI, 95
	return


EverGrandeCity_EventScript_ExplainRestricted::
	msgbox EverGrandeCity_Text_ExplainRestricteds, MSGBOX_AUTOCLOSE
	return

EverGrandeCity_Text_ExplainRestricteds:
	.string "You only get 1 Restricted Pokemon\n"
	.string "for the Elite 4. You get to\n"
	.string "choose from a list I will show.\p"
	.string "If you are not playing in hardcore mode,\n"
	.string "you can have a second Pokemon from me.$"

EverGrandeCity_Text_WhatGeneration:
	.string "What Generation do you want?$"

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"

EverGrandeCity_Text_Hacker:
	.string "Trying to get more restricted mons?\p"
	.string "You're pretty cheeky, huh.\n"
	.string "I can't blame you though, it's\l"
	.string "not a bad idea at all.$"

EverGrandeCity_Text_WhatMonGeneration:
	.string "What Pokemon would you like?$"

EverGrandeCity_Text_WhatDrive:
	.string "Which Drive would you like?$"
