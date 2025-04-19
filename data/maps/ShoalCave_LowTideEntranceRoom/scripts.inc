# 1 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 2 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_MapScripts::
# 3 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideEntranceRoom_OnTransition
# 4 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	.byte 0
# 5 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 6 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_OnTransition:
# 7 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	special UpdateShoalTideFlag
# 8 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_set FLAG_SYS_SHOAL_TIDE, ShoalCave_LowTideEntranceRoom_EventScript_SetHighTide
# 9 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto ShoalCave_LowTideEntranceRoom_EventScript_SetLowTide
# 10 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 11 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_SetHighTide::
# 12 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	setmaplayoutindex LAYOUT_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM
# 13 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 14 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 15 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_SetLowTide::
# 16 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	setmaplayoutindex LAYOUT_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM
# 17 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 18 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 19 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_ShellBellExpert::
# 20 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	lock
# 21 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	faceplayer
# 22 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	dotimebasedevents
# 23 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	call_if_set FLAG_SYS_SHOAL_ITEM, ShoalCave_LowTideEntranceRoom_EventScript_ResetShoalItems
# 24 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SALT, 4
# 25 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, ShoalCave_LowTideEntranceRoom_EventScript_NotEnoughShoalSaltOrShells
# 26 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SHELL, 4
# 27 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, ShoalCave_LowTideEntranceRoom_EventScript_NotEnoughShoalSaltOrShells
# 28 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_WouldYouLikeShellBell, MSGBOX_YESNO
# 29 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, ShoalCave_LowTideEntranceRoom_EventScript_DeclineShellBell
# 30 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitemspace ITEM_SHELL_BELL
# 31 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, ShoalCave_LowTideEntranceRoom_EventScript_CheckSpaceWillBeFreed
# 32 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, ShoalCave_LowTideEntranceRoom_EventScript_NoRoomForShellBell
# 33 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_MakeShellBellRightAway, MSGBOX_DEFAULT
# 34 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	removeitem ITEM_SHOAL_SALT, 4
# 35 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	removeitem ITEM_SHOAL_SHELL, 4
# 36 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	giveitem ITEM_SHELL_BELL
# 37 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull  @ Never FALSE, we already made sure there will be room in the bag.
# 38 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_ExplainShellBell, MSGBOX_DEFAULT
# 39 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	setflag FLAG_TEMP_2  @ Not read. Perhaps meant to stop him from re-explaining the Shell Bell if multiple are received in one sitting.
# 40 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	release
# 41 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 42 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 43 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
@ If the bag is full, check if a slot will be freed when 4 Shoal Salt or Shells are given
# 44 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_CheckSpaceWillBeFreed::
# 45 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SALT, 5
# 46 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, ShoalCave_LowTideEntranceRoom_EventScript_CheckSpaceWillBeFreedShells
# 47 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	return
# 48 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 49 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_CheckSpaceWillBeFreedShells::
# 50 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SHELL, 5
# 51 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, ShoalCave_LowTideEntranceRoom_EventScript_NoSpaceWillBeFreed
# 52 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	return
# 53 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 54 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_NoSpaceWillBeFreed::
# 55 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	setvar VAR_RESULT, 2
# 56 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	return
# 57 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 58 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_NoRoomForShellBell::
# 59 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_NoSpaceInYourBag, MSGBOX_DEFAULT
# 60 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	release
# 61 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 62 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 63 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_NotEnoughShoalSaltOrShells::
# 64 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SALT
# 65 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, ShoalCave_LowTideEntranceRoom_EventScript_HasSomeShoalSaltOrShell
# 66 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SHELL
# 67 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, ShoalCave_LowTideEntranceRoom_EventScript_HasSomeShoalSaltOrShell
# 68 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_AreYouPlanningOnGoingInThere, MSGBOX_DEFAULT
# 69 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	release
# 70 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 71 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 72 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_HasSomeShoalSaltOrShell::
# 73 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_BringMe4ShoalSaltAndShells, MSGBOX_DEFAULT
# 74 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	release
# 75 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 76 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 77 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_DeclineShellBell::
# 78 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_WantedToMakeShellBell, MSGBOX_DEFAULT
# 79 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	release
# 80 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 81 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 82 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_ResetShoalItems::
# 83 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SALT_1
# 84 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SALT_2
# 85 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SALT_3
# 86 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SALT_4
# 87 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SHELL_1
# 88 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SHELL_2
# 89 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SHELL_3
# 90 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SHELL_4
# 91 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_SYS_SHOAL_ITEM
# 92 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	return
