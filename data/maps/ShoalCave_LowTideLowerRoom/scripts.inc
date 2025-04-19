# 1 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"

# 2 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
ShoalCave_LowTideLowerRoom_MapScripts::
# 3 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideLowerRoom_OnLoad
# 4 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	.byte 0
# 5 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"

# 6 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
ShoalCave_LowTideLowerRoom_OnLoad:
# 7 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	call ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatiles
# 8 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	end
# 9 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"

# 10 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatiles::
# 11 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_4, ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatilesEnd
# 12 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	setmetatile 18, 2, METATILE_Cave_ShoalCave_DirtPile_Large, TRUE
# 13 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	return
# 14 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"

# 15 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatilesEnd::
# 16 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	return
# 17 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"

# 18 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
ShoalCave_LowTideLowerRoom_EventScript_ShoalSalt4::
# 19 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	lockall
# 20 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_4, ShoalCave_LowTideLowerRoom_EventScript_ReceivedShoalSalt
# 21 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SALT
# 22 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 23 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	setmetatile 18, 2, METATILE_Cave_ShoalCave_DirtPile_Small, FALSE
# 24 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	special DrawWholeMapView
# 25 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SALT_4
# 26 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	releaseall
# 27 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	end
# 28 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"

# 29 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
ShoalCave_LowTideLowerRoom_EventScript_ReceivedShoalSalt::
# 30 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	msgbox ShoalCave_Text_WasShoalSaltNowNothing, MSGBOX_DEFAULT
# 31 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	releaseall
# 32 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	end
# 33 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"

# 34 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
ShoalCave_LowTideLowerRoom_EventScript_BlackBelt::
# 35 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	lock
# 36 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	faceplayer
# 37 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_FOCUS_BAND, ShoalCave_LowTideLowerRoom_EventScript_ReceivedFocusBand
# 38 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	msgbox ShoalCave_LowTideLowerRoom_Text_CanOvercomeColdWithFocus, MSGBOX_DEFAULT
# 39 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	giveitem ITEM_FOCUS_BAND
# 40 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 41 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	setflag FLAG_RECEIVED_FOCUS_BAND
# 42 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	release
# 43 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	end
# 44 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"

# 45 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
ShoalCave_LowTideLowerRoom_EventScript_ReceivedFocusBand::
# 46 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	msgbox ShoalCave_LowTideLowerRoom_Text_EverythingStartsWithFocus, MSGBOX_DEFAULT
# 47 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	release
# 48 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	end
# 49 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"

# 50 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
ShoalCave_LowTideLowerRoom_Text_CanOvercomeColdWithFocus:
# 51 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	.string "The penetrating cold around these\n"
# 52 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	.string "parts is an impediment to training.\p"
# 53 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	.string "But with focus, one can overcome!\p"
# 54 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	.string "With this FOCUS BAND, buckle down and\n"
# 55 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	.string "withstand the cold!$"
# 56 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"

# 57 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
ShoalCave_LowTideLowerRoom_Text_EverythingStartsWithFocus:
# 58 "data/maps/ShoalCave_LowTideLowerRoom/scripts.pory"
	.string "Everything starts with focus!$"
