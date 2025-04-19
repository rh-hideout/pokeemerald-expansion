# 1 "data/maps/MirageTower_4F/scripts.pory"

# 2 "data/maps/MirageTower_4F/scripts.pory"
.set LOCALID_ROOT_FOSSIL, 1
# 3 "data/maps/MirageTower_4F/scripts.pory"
.set LOCALID_CLAW_FOSSIL, 2
# 4 "data/maps/MirageTower_4F/scripts.pory"

# 5 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_MapScripts::
# 6 "data/maps/MirageTower_4F/scripts.pory"
	.byte 0
# 7 "data/maps/MirageTower_4F/scripts.pory"

# 8 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_RootFossil::
# 9 "data/maps/MirageTower_4F/scripts.pory"
	lock
# 10 "data/maps/MirageTower_4F/scripts.pory"
	faceplayer
# 11 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_TakeRootFossil, MSGBOX_YESNO
# 12 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveRootFossil
# 13 "data/maps/MirageTower_4F/scripts.pory"
	giveitem ITEM_ROOT_FOSSIL
# 14 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 15 "data/maps/MirageTower_4F/scripts.pory"
	closemessage
# 16 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
# 17 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
# 18 "data/maps/MirageTower_4F/scripts.pory"
	removeobject LOCALID_ROOT_FOSSIL
# 19 "data/maps/MirageTower_4F/scripts.pory"
	delay 30
# 20 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_CHOSE_ROOT_FOSSIL
# 21 "data/maps/MirageTower_4F/scripts.pory"
	goto MirageTower_4F_EventScript_CollapseMirageTower
# 22 "data/maps/MirageTower_4F/scripts.pory"
	end
# 23 "data/maps/MirageTower_4F/scripts.pory"

# 24 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_LeaveRootFossil::
# 25 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_LeftRootFossilAlone, MSGBOX_DEFAULT
# 26 "data/maps/MirageTower_4F/scripts.pory"
	release
# 27 "data/maps/MirageTower_4F/scripts.pory"
	end
# 28 "data/maps/MirageTower_4F/scripts.pory"

# 29 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_ClawFossil::
# 30 "data/maps/MirageTower_4F/scripts.pory"
	lock
# 31 "data/maps/MirageTower_4F/scripts.pory"
	faceplayer
# 32 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_TakeClawFossil, MSGBOX_YESNO
# 33 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveClawFossil
# 34 "data/maps/MirageTower_4F/scripts.pory"
	giveitem ITEM_CLAW_FOSSIL
# 35 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 36 "data/maps/MirageTower_4F/scripts.pory"
	closemessage
# 37 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
# 38 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
# 39 "data/maps/MirageTower_4F/scripts.pory"
	removeobject LOCALID_CLAW_FOSSIL
# 40 "data/maps/MirageTower_4F/scripts.pory"
	delay 30
# 41 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_CHOSE_CLAW_FOSSIL
# 42 "data/maps/MirageTower_4F/scripts.pory"
	goto MirageTower_4F_EventScript_CollapseMirageTower
# 43 "data/maps/MirageTower_4F/scripts.pory"
	end
# 44 "data/maps/MirageTower_4F/scripts.pory"

# 45 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_LeaveClawFossil::
# 46 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_LeaveClawFossilAlone, MSGBOX_DEFAULT
# 47 "data/maps/MirageTower_4F/scripts.pory"
	release
# 48 "data/maps/MirageTower_4F/scripts.pory"
	end
# 49 "data/maps/MirageTower_4F/scripts.pory"

# 50 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_CollapseMirageTower::
# 51 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 52 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 53 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8006, 32  @ num shakes
# 54 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8007, 2   @ shake delay
# 55 "data/maps/MirageTower_4F/scripts.pory"
	special ShakeCamera
# 56 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 57 "data/maps/MirageTower_4F/scripts.pory"
	special DoMirageTowerCeilingCrumble
# 58 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 59 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 1
# 60 "data/maps/MirageTower_4F/scripts.pory"
	clearflag FLAG_LANDMARK_MIRAGE_TOWER
# 61 "data/maps/MirageTower_4F/scripts.pory"
	warp MAP_ROUTE111, 19, 59
# 62 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 63 "data/maps/MirageTower_4F/scripts.pory"
	release
# 64 "data/maps/MirageTower_4F/scripts.pory"
	end
# 65 "data/maps/MirageTower_4F/scripts.pory"

# 66 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_TakeRootFossil:
# 67 "data/maps/MirageTower_4F/scripts.pory"
	.string "You found the ROOT FOSSIL.\p"
# 68 "data/maps/MirageTower_4F/scripts.pory"
	.string "If this FOSSIL is taken, the ground\n"
# 69 "data/maps/MirageTower_4F/scripts.pory"
	.string "around it will likely crumble away…\p"
# 70 "data/maps/MirageTower_4F/scripts.pory"
	.string "Take the ROOT FOSSIL anyway?$"
# 71 "data/maps/MirageTower_4F/scripts.pory"

# 72 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_LeftRootFossilAlone:
# 73 "data/maps/MirageTower_4F/scripts.pory"
	.string "{PLAYER} left the ROOT FOSSIL alone.$"
# 74 "data/maps/MirageTower_4F/scripts.pory"

# 75 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_TakeClawFossil:
# 76 "data/maps/MirageTower_4F/scripts.pory"
	.string "You found the CLAW FOSSIL.\p"
# 77 "data/maps/MirageTower_4F/scripts.pory"
	.string "If this FOSSIL is taken, the ground\n"
# 78 "data/maps/MirageTower_4F/scripts.pory"
	.string "around it will likely crumble away…\p"
# 79 "data/maps/MirageTower_4F/scripts.pory"
	.string "Take the CLAW FOSSIL anyway?$"
# 80 "data/maps/MirageTower_4F/scripts.pory"

# 81 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_LeaveClawFossilAlone:
# 82 "data/maps/MirageTower_4F/scripts.pory"
	.string "{PLAYER} left the CLAW FOSSIL alone.$"
