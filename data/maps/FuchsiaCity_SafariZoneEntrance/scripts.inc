.set LOCALID_SAFARIZONEFUCHSIA_STEVEN, 2

FuchsiaCity_SafariZoneEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZoneEntrance_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_SafariZoneEntrance_OnTransition
	.byte 0

FuchsiaCity_SafariZoneEntrance_OnFrame::
	map_script_2 VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari
	.2byte 0

FuchsiaCity_SafariZoneEntrance_OnTransition::
	call_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_FirstTime
	end

FuchsiaCity_SafariZoneEntrance_FirstTime::
	setobjectxyperm LOCALID_SAFARIZONEFUCHSIA_STEVEN, 4, 10
	setobjectmovementtype LOCALID_SAFARIZONEFUCHSIA_STEVEN, MOVEMENT_TYPE_FACE_LEFT
	end

FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone
	waitmovement 0
	release
	end
 
FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH, 0
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven::
	lock
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN

	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome, MSGBOX_DEFAULT
	closemessage
	checkitem ITEM_POKEBLOCK_CASE
	call_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase

	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable
	waitmovement 0
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 1
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	return

FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase:
	.string "Oh and you might need this.$"

FuchsiaCity_SafariZoneEntrance_Steven::
	lock
	faceplayer
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_SafariZoneEntrance_StevenAfter
	goto_if_set FLAG_IS_KANTO_CHAMPION, FuchsiaCity_SafariZoneEntrance_StevenChamp
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Steven, MSGBOX_NPC
	release
	end

FuchsiaCity_SafariZoneEntrance_StevenChamp::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenChamp, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_StevenAfter::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Steven, MSGBOX_NPC
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenChamp:
	.string "Oh, hey {PLAYER}.\n"
	.string "Or should I say KANTO champion?\p"
	.string "You know, for some time, I was the\n"
	.string "champion of the HOENN region.\p"
	.string "So welcome to the club, {PLAYER}.\p"
	.string "In fact, here.\n"
	.string "Consider this a welcome gift.$"

FuchsiaCity_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	showmoneybox 0, 0
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase
	call FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneGate_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 4, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft
	call_if_eq VAR_TEMP_0, 6, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	setflag FLAG_IN_KANTO_SAFARI_ZONE
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH, 1
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_up
	walk_up
	walk_up
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer:
	walk_right
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome:
	.string "My name is STEVEN. My family's\n"
	.string "company recently purchased this\l"
	.string "SAFARI ZONE, and we've made many\l"
	.string "improvements.\p"
	.string "You'll find very exotic POKéMON\n"
	.string "here. Especially if you increase\l"
	.string "your SAFARI LEVEL.\p"
	.string "Just speak to the attendant here\n"
	.string "any time to increase your SAFARI\l"
	.string "LEVEL.$"

FuchsiaCity_SafariZoneEntrance_UpgradeGuy::
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 1, FuchsiaCity_SafariZoneEntrance_UpgradeGuy1
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 2, FuchsiaCity_SafariZoneEntrance_UpgradeGuy2
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 3, FuchsiaCity_SafariZoneEntrance_UpgradeGuy3
	msgbox FuchsiaCity_SafariZoneEntrance_Text_MaxLevel, MSGBOX_NPC
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy1::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 200000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 200000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 2
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy2::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 300000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 300000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 3
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy3::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 400000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 400000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 4
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney::
	msgbox Route121_SafariZoneGate_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_Text_Steven:
	.string "Oh, hey, {PLAYER}.\p"
	.string "I hope you're enjoying the SAFARI.\p"
	.string "Have you seen any rare stones\n"
	.string "lately?$"

FuchsiaCity_SafariZoneEntrance_Text_Level1:
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 2? It will cost you ¥200,000.$"

FuchsiaCity_SafariZoneEntrance_Text_Level2:
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 3? It will cost you ¥300,000.$"

FuchsiaCity_SafariZoneEntrance_Text_Level3:
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 4? It will cost you ¥400,000.$"

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined:
	.string "Oh, that's too bad, then...$"

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted:
	.string "Enjoy the premium SAFARI ZONE\n"
	.string "experience!$"

FuchsiaCity_SafariZoneEntrance_Text_MaxLevel:
	.string "Hello {PLAYER}, thank you for\n"
	.string "continuing to be a premium member\l"
	.string "at the FUCHSIA SAFARI ZONE.$"
