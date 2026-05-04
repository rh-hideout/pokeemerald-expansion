.set LOCALID_MTSILVER_RED, 1

MtSilver_SummitDay_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_SummitDay_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtSilver_SummitDay_OnFrame
	.byte 0

MtSilver_SummitDay_OnFrame::
	map_script_2 VAR_TEMP_0, 0 MtSilver_SummitDay_Blizzard
	.2byte 0

MtSilver_SummitDay_Blizzard::
	playse SE_M_BLIZZARD
	setvar VAR_TEMP_0, 1
	end

MtSilver_SummitDay_OnTransition:
	setescapewarp MAP_MT_SILVER_OUTSIDE, 17, 8
	call_if_set FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetDay
	end

MtSilver_SummitDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_MT_SILVER_SUMMIT_NIGHT
	return

MtSilver_SummitDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_MT_SILVER_SUMMIT_DAY
	return

MtSilver_SummitDay_EventScript_Red::
	lock
	faceplayer
	msgbox MtSilver_SummitDay_Text_Red, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_RED_2, MtSilver_SummitDay_Text_RedBeaten
	playse SE_M_BLIZZARD
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	msgbox MtSilver_SummitDay_Text_Red, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_MTSILVER_RED
	removeobject LOCALID_MTSILVER_RED
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 180
	fadescreenspeed FADE_TO_BLACK, 24
	setflag FLAG_DEFEATED_RED
	clearflag FLAG_HIDE_MTSILVER_RED
	special GameClear
	waitstate
	releaseall
	end

MtSilver_SummitDay_Text_Red:
	.string ".........................\n"
	.string ".........................$"

MtSilver_SummitDay_Text_RedBeaten:
	.string "...!$"


