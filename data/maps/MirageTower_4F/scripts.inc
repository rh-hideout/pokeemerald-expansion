# 1 "data/maps/MirageTower_4F/scripts.pory"

# 2 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_MapScripts::
# 3 "data/maps/MirageTower_4F/scripts.pory"
	.byte 0
# 4 "data/maps/MirageTower_4F/scripts.pory"

# 5 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_RootFossil::
# 6 "data/maps/MirageTower_4F/scripts.pory"
	lock
# 7 "data/maps/MirageTower_4F/scripts.pory"
	faceplayer
# 8 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_TakeRootFossil, MSGBOX_YESNO
# 9 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveRootFossil
# 10 "data/maps/MirageTower_4F/scripts.pory"
	giveitem ITEM_ROOT_FOSSIL
# 11 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 12 "data/maps/MirageTower_4F/scripts.pory"
	closemessage
# 13 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
# 14 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
# 15 "data/maps/MirageTower_4F/scripts.pory"
	removeobject LOCALID_MIRAGE_ROOT_FOSSIL
# 16 "data/maps/MirageTower_4F/scripts.pory"
	delay 30
# 17 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_CHOSE_ROOT_FOSSIL
# 18 "data/maps/MirageTower_4F/scripts.pory"
	goto MirageTower_4F_EventScript_CollapseMirageTower
# 19 "data/maps/MirageTower_4F/scripts.pory"
	end
# 20 "data/maps/MirageTower_4F/scripts.pory"

# 21 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_LeaveRootFossil::
# 22 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_LeftRootFossilAlone, MSGBOX_DEFAULT
# 23 "data/maps/MirageTower_4F/scripts.pory"
	release
# 24 "data/maps/MirageTower_4F/scripts.pory"
	end
# 25 "data/maps/MirageTower_4F/scripts.pory"

# 26 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_ClawFossil::
# 27 "data/maps/MirageTower_4F/scripts.pory"
	lock
# 28 "data/maps/MirageTower_4F/scripts.pory"
	faceplayer
# 29 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_TakeClawFossil, MSGBOX_YESNO
# 30 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveClawFossil
# 31 "data/maps/MirageTower_4F/scripts.pory"
	giveitem ITEM_CLAW_FOSSIL
# 32 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 33 "data/maps/MirageTower_4F/scripts.pory"
	closemessage
# 34 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
# 35 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
# 36 "data/maps/MirageTower_4F/scripts.pory"
	removeobject LOCALID_MIRAGE_CLAW_FOSSIL
# 37 "data/maps/MirageTower_4F/scripts.pory"
	delay 30
# 38 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_CHOSE_CLAW_FOSSIL
# 39 "data/maps/MirageTower_4F/scripts.pory"
	goto MirageTower_4F_EventScript_CollapseMirageTower
# 40 "data/maps/MirageTower_4F/scripts.pory"
	end
# 41 "data/maps/MirageTower_4F/scripts.pory"

# 42 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_LeaveClawFossil::
# 43 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_LeaveClawFossilAlone, MSGBOX_DEFAULT
# 44 "data/maps/MirageTower_4F/scripts.pory"
	release
# 45 "data/maps/MirageTower_4F/scripts.pory"
	end
# 46 "data/maps/MirageTower_4F/scripts.pory"

# 47 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_CollapseMirageTower::
# 48 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 49 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 50 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8006, 32  @ num shakes
# 51 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8007, 2   @ shake delay
# 52 "data/maps/MirageTower_4F/scripts.pory"
	special ShakeCamera
# 53 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 54 "data/maps/MirageTower_4F/scripts.pory"
	special DoMirageTowerCeilingCrumble
# 55 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 56 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 1
# 57 "data/maps/MirageTower_4F/scripts.pory"
	clearflag FLAG_LANDMARK_MIRAGE_TOWER
# 58 "data/maps/MirageTower_4F/scripts.pory"
	warp MAP_ROUTE111, 19, 59
# 59 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 60 "data/maps/MirageTower_4F/scripts.pory"
	release
# 61 "data/maps/MirageTower_4F/scripts.pory"
	end
# 62 "data/maps/MirageTower_4F/scripts.pory"

# 63 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_TakeRootFossil:
# 64 "data/maps/MirageTower_4F/scripts.pory"
	.string "You found the ROOT FOSSIL.\p"
# 65 "data/maps/MirageTower_4F/scripts.pory"
	.string "If this FOSSIL is taken, the ground\n"
# 66 "data/maps/MirageTower_4F/scripts.pory"
	.string "around it will likely crumble away…\p"
# 67 "data/maps/MirageTower_4F/scripts.pory"
	.string "Take the ROOT FOSSIL anyway?$"
# 68 "data/maps/MirageTower_4F/scripts.pory"

# 69 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_LeftRootFossilAlone:
# 70 "data/maps/MirageTower_4F/scripts.pory"
	.string "{PLAYER} left the ROOT FOSSIL alone.$"
# 71 "data/maps/MirageTower_4F/scripts.pory"

# 72 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_TakeClawFossil:
# 73 "data/maps/MirageTower_4F/scripts.pory"
	.string "You found the CLAW FOSSIL.\p"
# 74 "data/maps/MirageTower_4F/scripts.pory"
	.string "If this FOSSIL is taken, the ground\n"
# 75 "data/maps/MirageTower_4F/scripts.pory"
	.string "around it will likely crumble away…\p"
# 76 "data/maps/MirageTower_4F/scripts.pory"
	.string "Take the CLAW FOSSIL anyway?$"
# 77 "data/maps/MirageTower_4F/scripts.pory"

# 78 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_LeaveClawFossilAlone:
# 79 "data/maps/MirageTower_4F/scripts.pory"
	.string "{PLAYER} left the CLAW FOSSIL alone.$"
