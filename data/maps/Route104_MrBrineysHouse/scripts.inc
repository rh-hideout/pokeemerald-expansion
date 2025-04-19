# 1 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 2 "data/maps/Route104_MrBrineysHouse/scripts.pory"
.set LOCALID_BRINEY, 1
# 3 "data/maps/Route104_MrBrineysHouse/scripts.pory"
.set LOCALID_PEEKO, 2
# 4 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 5 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_MapScripts::
# 6 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
# 7 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.byte 0
# 8 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 9 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_OnTransition:
# 10 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
# 11 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
# 12 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
# 13 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 14 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 15 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_HideRustboroRival::
# 16 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 17 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	return
# 18 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 19 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
# 20 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectxyperm LOCALID_BRINEY, 9, 3
# 21 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectmovementtype LOCALID_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
# 22 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectxyperm LOCALID_PEEKO, 9, 6
# 23 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectmovementtype LOCALID_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
# 24 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	return
# 25 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 26 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_Briney::
# 27 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	lock
# 28 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	faceplayer
# 29 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
# 30 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
# 31 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
# 32 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
# 33 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 34 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 35 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailingIntro::
# 36 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_MR_BRINEY_SAILING_INTRO
# 37 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
# 38 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
# 39 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
# 40 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
# 41 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 42 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 43 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
# 44 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
# 45 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitmessage
# 46 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
# 47 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	switch VAR_RESULT
# 48 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
# 49 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
# 50 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
# 51 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 52 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 53 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
# 54 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
# 55 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
# 56 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
# 57 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 58 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 59 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
# 60 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
# 61 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
# 62 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
# 63 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 64 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 65 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
# 66 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
# 67 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	release
# 68 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 69 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 70 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_DeclineSailing::
# 71 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
# 72 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	release
# 73 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 74 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 75 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailToDewford::
# 76 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
# 77 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call EventScript_BackupMrBrineyLocation
# 78 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
# 79 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
# 80 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 81 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 82 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 83 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 84 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 85 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_RIVAL
# 86 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	warp MAP_ROUTE104, 13, 51
# 87 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitstate
# 88 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	releaseall
# 89 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 90 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 91 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_Peeko::
# 92 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	lock
# 93 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	faceplayer
# 94 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitse
# 95 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 96 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
# 97 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitmoncry
# 98 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	release
# 99 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 100 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 101 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_WaitUpPeeko:
# 102 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Hold on, lass!\n"
# 103 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Wait up, PEEKO!$"
# 104 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 105 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
# 106 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Hm? You're {PLAYER}{KUN}!\n"
# 107 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You saved my darling PEEKO!\l"
# 108 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "We owe so much to you!\p"
# 109 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "What's that?\n"
# 110 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You want to sail with me?\p"
# 111 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Hmhm…\p"
# 112 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You have a LETTER bound for DEWFORD\n"
# 113 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "and a package for SLATEPORT, then?\p"
# 114 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Quite the busy life you must lead!\p"
# 115 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "But, certainly, what you're asking is\n"
# 116 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "no problem at all.\p"
# 117 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You've come to the right man!\n"
# 118 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "We'll set sail for DEWFORD.$"
# 119 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 120 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_SetSailForDewford:
# 121 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: DEWFORD it is, then!\p"
# 122 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Anchors aweigh!\n"
# 123 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "PEEKO, we're setting sail, my darling!$"
# 124 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 125 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_DeclineDeliverySail:
# 126 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Is that so?\n"
# 127 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Your deliveries can wait?\p"
# 128 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You just go on and tell me whenever\n"
# 129 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "you want to set sail!$"
# 130 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 131 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
# 132 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Ahoy!\n"
# 133 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "I know exactly what you want to say!\p"
# 134 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You're to deliver a LETTER to DEWFORD\n"
# 135 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "and a package to SLATEPORT.\p"
# 136 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "What you need me to do is no problem\n"
# 137 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "at all--I'm the man for the job!\p"
# 138 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "First, we'll set sail for DEWFORD.$"
# 139 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 140 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
# 141 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Ahoy!\n"
# 142 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "I know exactly what you want to say!\p"
# 143 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You're to deliver a package to\n"
# 144 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "CAPT. STERN in SLATEPORT.\p"
# 145 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "What you need me to do is no problem\n"
# 146 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "at all--I'm the man for the job!\p"
# 147 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "First, we'll set sail for DEWFORD.$"
# 148 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 149 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_WhereAreWeBound:
# 150 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Ahoy!\n"
# 151 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "For you, I'll go out to sea anytime!\p"
# 152 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Now, my friend, where are we bound?$"
# 153 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 154 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
# 155 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Is that so?\n"
# 156 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Well, PEEKO owes her life to you.\p"
# 157 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You just go on and tell me whenever\n"
# 158 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "you want to set sail!$"
# 159 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 160 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_Peeko:
# 161 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "PEEKO: Pii piihyoro!$"
