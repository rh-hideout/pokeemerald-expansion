# 1 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 2 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
.set LOCALID_LITTLE_BOY, 5
# 3 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 4 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_MapScripts::
# 5 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
# 6 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.byte 0
# 7 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 8 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_OnTransition:
# 9 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
# 10 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 11 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 12 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
# 13 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
# 14 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
# 15 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	return
# 16 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 17 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_LittleBoy::
# 18 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	lock
# 19 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	faceplayer
# 20 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	special GetPlayerBigGuyGirlString
# 21 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
# 22 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
# 23 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 24 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 25 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 26 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
# 27 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
# 28 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 29 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 30 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 31 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
# 32 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	lock
# 33 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	faceplayer
# 34 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
# 35 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setvar VAR_0x8004, 0
# 36 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
# 37 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
# 38 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
# 39 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
# 40 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 41 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 42 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 43 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
# 44 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	addvar VAR_0x8004, 1
# 45 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	return
# 46 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 47 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_StudyingRain::
# 48 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
# 49 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 50 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 51 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 52 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
# 53 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
# 54 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 55 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 56 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_Bed::
# 57 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	lockall
# 58 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
# 59 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	closemessage
# 60 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 61 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	releaseall
# 62 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 63 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 64 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_Grunt1::
# 65 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
# 66 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 67 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 68 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 69 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_Grunt4::
# 70 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
# 71 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 72 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 73 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 74 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt1Intro:
# 75 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "The BOSS got interested in\n"
# 76 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "the research they have going here,\l"
# 77 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "so he sent us out.\p"
# 78 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "You quit meddling!$"
# 79 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 80 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
# 81 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Blast it…\n"
# 82 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Blasted by a kid…$"
# 83 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 84 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
# 85 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Our BOSS knows everything.\p"
# 86 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "But I'm just a GRUNT. What would I know\n"
# 87 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "about what he's thinking?$"
# 88 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 89 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt4Intro:
# 90 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Huh?\n"
# 91 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "What's a kid doing here?$"
# 92 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 93 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
# 94 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Huh?\n"
# 95 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I lost?!$"
# 96 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 97 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
# 98 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Oh, no…\n"
# 99 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I'll catch an earful for losing to a kid…\p"
# 100 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I should just take a nap in the bed…$"
# 101 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 102 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
# 103 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "While I was sleeping, everyone went\n"
# 104 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "upstairs!$"
# 105 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 106 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_WowYoureStrong:
# 107 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Wow, you're really strong!\p"
# 108 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I wish I could be a POKéMON TRAINER\n"
# 109 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "like you!$"
# 110 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 111 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
# 112 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "The PROFESSOR loves rain.\n"
# 113 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "That's a fact.\p"
# 114 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "But if it keeps raining, people will be in\n"
# 115 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "trouble. That's another fact.\p"
# 116 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "And thus, the PROFESSOR is studying\n"
# 117 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "if the rain can be put to good use.$"
# 118 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 119 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
# 120 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "On the 2nd floor of the INSTITUTE,\n"
# 121 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "we study the weather patterns over\l"
# 122 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "the HOENN region.\p"
# 123 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "We've been noticing temporary and\n"
# 124 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "isolated cases of droughts and\l"
# 125 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "heavy rain lately…$"
# 126 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 127 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
# 128 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Hello!\n"
# 129 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "We've been saved by your actions!\p"
# 130 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "What I don't understand is what on\n"
# 131 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "earth the AQUAS were up to.$"
# 132 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 133 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_TakeRestInBed:
# 134 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "There's a bed…\n"
# 135 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Let's take a rest.$"
