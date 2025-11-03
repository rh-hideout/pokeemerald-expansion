# 1 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 2 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_MapScripts::
# 3 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideInnerRoom_OnLoad
# 4 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideInnerRoom_OnTransition
# 5 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	.byte 0
# 6 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 7 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_OnTransition:
# 8 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_SYS_SHOAL_TIDE, ShoalCave_LowTideInnerRoom_EventScript_SetHighTide
# 9 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetLowTide
# 10 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 11 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetHighTide::
# 12 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmaplayoutindex LAYOUT_SHOAL_CAVE_HIGH_TIDE_INNER_ROOM
# 13 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 14 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 15 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetLowTide::
# 16 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmaplayoutindex LAYOUT_SHOAL_CAVE_LOW_TIDE_INNER_ROOM
# 17 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 18 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 19 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_OnLoad:
# 20 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	call ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles
# 21 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 22 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 23 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles::
# 24 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_1, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2
# 25 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_SYS_SHOAL_TIDE, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2
# 26 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 31, 8, METATILE_Cave_ShoalCave_DirtPile_Large, TRUE
# 27 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2
# 28 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 29 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 30 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2::
# 31 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_2, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3
# 32 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_SYS_SHOAL_TIDE, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3
# 33 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 14, 26, METATILE_Cave_ShoalCave_DirtPile_Large, TRUE
# 34 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3
# 35 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 36 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 37 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3::
# 38 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_1, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles4
# 39 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 41, 20, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
# 40 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles4
# 41 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 42 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 43 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles4::
# 44 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_2, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles5
# 45 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 41, 10, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
# 46 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles5
# 47 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 48 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 49 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles5::
# 50 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_3, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles6
# 51 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 6, 9, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
# 52 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles6
# 53 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 54 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 55 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles6::
# 56 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_4, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatilesEnd
# 57 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 16, 13, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
# 58 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	return
# 59 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 60 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatilesEnd::
# 61 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	return
# 62 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 63 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell1::
# 64 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 65 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_1, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
# 66 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 67 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 68 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 41, 20, METATILE_Cave_ShoalCave_BlueStone_Small, FALSE
# 69 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 70 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SHELL_1
# 71 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 72 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 73 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 74 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell::
# 75 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	msgbox ShoalCave_Text_WasShoallShellNowNothing, MSGBOX_DEFAULT
# 76 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 77 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 78 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 79 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell2::
# 80 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 81 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_2, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
# 82 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 83 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 84 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 41, 10, METATILE_Cave_ShoalCave_BlueStone_Small, FALSE
# 85 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 86 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SHELL_2
# 87 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 88 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 89 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 90 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell3::
# 91 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 92 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_3, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
# 93 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 94 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 95 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 6, 9, METATILE_Cave_ShoalCave_BlueStone_Small, FALSE
# 96 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 97 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SHELL_3
# 98 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 99 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 100 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 101 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell4::
# 102 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 103 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_4, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
# 104 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 105 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 106 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 16, 13, METATILE_Cave_ShoalCave_BlueStone_Small, FALSE
# 107 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 108 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SHELL_4
# 109 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 110 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 111 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 112 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalSalt1::
# 113 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 114 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_1, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalSalt
# 115 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SALT
# 116 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 117 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 31, 8, METATILE_Cave_ShoalCave_DirtPile_Small, FALSE
# 118 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 119 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SALT_1
# 120 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 121 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 122 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 123 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalSalt::
# 124 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	msgbox ShoalCave_Text_WasShoalSaltNowNothing, MSGBOX_DEFAULT
# 125 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 126 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 127 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 128 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalSalt2::
# 129 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 130 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_2, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalSalt
# 131 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SALT
# 132 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 133 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 14, 26, METATILE_Cave_ShoalCave_DirtPile_Small, FALSE
# 134 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 135 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SALT_2
# 136 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 137 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
