# 1 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 2 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_MapScripts::
# 3 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_SafariZoneEntrance_OnFrame
# 4 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	.byte 0
# 5 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 6 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_OnFrame:
# 7 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, Route121_SafariZoneEntrance_EventScript_ExitSafariZone
# 8 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	.2byte 0
# 9 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 10 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_ExitSafariZone::
# 11 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	lockall
# 12 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement LOCALID_PLAYER, Route121_SafariZoneEntrance_Movement_ExitSafariZone
# 13 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 14 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 0
# 15 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	releaseall
# 16 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 17 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 18 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_Movement_ExitSafariZone:
# 19 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_up
# 20 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 21 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 22 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 23 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 24 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 25 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 26 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 27 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	step_end
# 28 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 29 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_WelcomeAttendant::
# 30 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_WelcomeToSafariZone, MSGBOX_NPC
# 31 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 32 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 33 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_InfoAttendant::
# 34 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	lock
# 35 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	faceplayer
# 36 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_WelcomeFirstTime, MSGBOX_YESNO
# 37 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_FirstTimeInfo
# 38 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_ComeInAndEnjoy, MSGBOX_DEFAULT
# 39 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	release
# 40 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 41 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 42 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_FirstTimeInfo::
# 43 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_FirstTimeInfo, MSGBOX_DEFAULT
# 44 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	release
# 45 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 46 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 47 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
# 48 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	lockall
# 49 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 50 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 51 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	showmoneybox 0, 0
# 52 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
# 53 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone
# 54 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
# 55 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 56 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 57 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 58 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone::
# 59 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	checkitem ITEM_POKEBLOCK_CASE
# 60 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NoPokeblockCase
# 61 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	call Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
# 62 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	checkmoney 500
# 63 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NotEnoughMoney
# 64 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	playse SE_SHOP
# 65 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
# 66 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	removemoney 500
# 67 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	updatemoneybox
# 68 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
# 69 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 70 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
# 71 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	waitfanfare
# 72 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
# 73 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	closemessage
# 74 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	hidemoneybox
# 75 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement LOCALID_PLAYER, Route121_SafariZoneEntrance_Movement_EnterSafariZone
# 76 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 77 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	special EnterSafariMode
# 78 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 2
# 79 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
# 80 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	warp MAP_SAFARI_ZONE_SOUTH, 32, 33
# 81 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	waitstate
# 82 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 83 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 84 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
# 85 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	getpartysize
# 86 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
# 87 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
# 88 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
# 89 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
# 90 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 91 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 92 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 93 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon::
# 94 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	return
# 95 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 96 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_NoPokeblockCase::
# 97 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
# 98 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 99 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 100 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 101 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_NotEnoughMoney::
# 102 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 103 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 104 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 105 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 106 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
# 107 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	closemessage
# 108 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	hidemoneybox
# 109 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement LOCALID_PLAYER, Route121_SafariZoneEntrance_Movement_BackAwayFromCounter
# 110 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 111 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	releaseall
# 112 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 113 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 114 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_Movement_BackAwayFromCounter:
# 115 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 116 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	step_end
# 117 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 118 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_Movement_EnterSafariZone:
# 119 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 120 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 121 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 122 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 123 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 124 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 125 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_down
# 126 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	delay_16
# 127 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	step_end
# 128 "data/maps/Route121_SafariZoneEntrance/scripts.pory"

# 129 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_TrainerTipSign::
# 130 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_TrainerTip, MSGBOX_SIGN
# 131 "data/maps/Route121_SafariZoneEntrance/scripts.pory"
	end
