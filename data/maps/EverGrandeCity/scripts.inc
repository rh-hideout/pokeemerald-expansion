EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_NurseGift::
	lockall
	faceplayer
	goto_if_unset FLAG_RESTRITCED_EXPLAINED, EverGrandeCity_EventScript_ExplainRestricted
	goto_if_set FLAG_RESTRICTED_GIVEN, EverGrandeCity_EventScript_Hacker
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
	case 0, EverGrandeCity_EventScript_GiveMewtwo
	case 1, EverGrandeCity_EventScript_GiveMew
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
	case 4, EverGrandeCity_EventScript_GiveTornadusT
	case 5, EverGrandeCity_EventScript_GiveLandorusT
	case 6, EverGrandeCity_EventScript_GiveThundurusI
	case 7, EverGrandeCity_EventScript_GiveThundurusT
	case 8, EverGrandeCity_EventScript_GiveKeldeo
	case 9, EverGrandeCity_EventScript_GiveCobalion
	case 10, EverGrandeCity_EventScript_GiveTerrakion
	case 11, EverGrandeCity_EventScript_GiveVirizion
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
	return

EverGrandeCity_EventScript_GiveMewtwo::
	givemon SPECIES_MEWTWO, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveMew::
	givemon SPECIES_MEW, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveLugia::
	givemon SPECIES_LUGIA, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveHooh::
	givemon SPECIES_HO_OH, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveCelebi::
	givemon SPECIES_CELEBI, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveLatias::
	givemon SPECIES_LATIOS, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveLatios::
	givemon SPECIES_LATIAS, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveJirachi::
	givemon SPECIES_JIRACHI, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveHeatran::
	givemon SPECIES_HEATRAN, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveCresselia::
	givemon SPECIES_CRESSELIA, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveShayminS::
	givemon SPECIES_SHAYMIN_SKY, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveDialga::
	givemon SPECIES_DIALGA, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GivePalkia::
	givemon SPECIES_PALKIA, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveGiratina::
	givemon SPECIES_GIRATINA, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveReshiram::
	givemon SPECIES_RESHIRAM, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveZekrom::
	givemon SPECIES_ZEKROM, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveKyurem::
	givemon SPECIES_KYUREM, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveGenesect::
	givemon SPECIES_GENESECT, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveTornadusT::
	givemon SPECIES_TORNADUS_THERIAN, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveLandorusT::
	givemon SPECIES_LANDORUS_THERIAN, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveThundurusI::
	givemon SPECIES_THUNDURUS_INCARNATE, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveThundurusT::
	givemon SPECIES_THUNDURUS_THERIAN, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveKeldeo::
	givemon SPECIES_KELDEO, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveCobalion::
	givemon SPECIES_COBALION, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveTerrakion::
	givemon SPECIES_TERRAKION, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveVirizion::
	givemon SPECIES_VIRIZION, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveHoopaU::
	givemon SPECIES_HOOPA_UNBOUND, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveVolcanion::
	givemon SPECIES_VOLCANION, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveMagearna::
	givemon SPECIES_MAGEARNA, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveMarshadow::
	givemon SPECIES_MARSHADOW, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveZeraora::
	givemon SPECIES_ZERAORA, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveMelmetal::
	givemon SPECIES_MELMETAL, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveZarude::
	givemon SPECIES_ZARUDE, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveUrshifuR::
	givemon SPECIES_URSHIFU_RAPID_STRIKE_STYLE, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveUrshifuS::
	givemon SPECIES_URSHIFU_SINGLE_STRIKE_STYLE, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end

EverGrandeCity_EventScript_GiveEternatus::
	givemon SPECIES_ETERNATUS, 95
	setflag FLAG_RESTRICTED_GIVEN
	releaseall
	end


EverGrandeCity_EventScript_ExplainRestricted::
	msgbox EverGrandeCity_Text_ExplainRestricteds, MSGBOX_AUTOCLOSE

EverGrandeCity_Text_ExplainRestricteds:
	.string "You only get 1 Restricted Pokemon\n"
	.string "for the Elite Four. You get to\n"
	.string "choose from a list I will show.\p"
	.string "The list can be found on the Google\n"
	.string "Sheets for Locations under the Static\l"
	.string "Encounters tab and is divided by gen.$"

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
	.string "What Pokemon would you like?"
