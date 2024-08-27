PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet::
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	return

LittlerootTown_BrendansHouse_2F_EventScript_WallClock::
	lockall
	setvar VAR_0x8004, MALE
	goto PlayersHouse_2F_EventScript_WallClock
	end

PlayersHouse_2F_EventScript_WallClock::
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	setflag FLAG_SET_WALL_CLOCK
	removeobject VAR_0x8008
	releaseall
	end

PlayersHouse_2F_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return

PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_BIRCH, PlayersHouse_1F_EventScript_HealParty
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_Text_IsntItNiceInHere::
	.string "Best be on your way, bud.$"

PlayersHouse_1F_EventScript_HealParty::
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	release
	end
