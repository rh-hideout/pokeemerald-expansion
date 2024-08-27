LittlerootTown_BrendansHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_2F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
	.byte 0

LittlerootTown_BrendansHouse_2F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_SetupIntroState
	end

LittlerootTown_BrendansHouse_2F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	end

LittlerootTown_BrendansHouse_2F_EventScript_SetupIntroState::
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	return

LittlerootTown_BrendansHouse_2F_EventScript_PC::
	lockall
	goto LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

PlayersHouse_2F_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
	.string "MOM: {PLAYER}, how do you like your\n"
	.string "new room?\p"
	.string "Good! Everything's put away neatly!\p"
	.string "They finished moving everything in\n"
	.string "downstairs, too.\p"
	.string "POKéMON movers are so convenient!\p"
	.string "Oh, you should make sure that\n"
	.string "everything's all there on your desk.$"

Common_Text_LookCloserAtMap:
	.string "{PLAYER} took a closer look at the\n"
	.string "HOENN region map.$"
