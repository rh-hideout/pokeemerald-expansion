# 1 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 2 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_MapScripts::
# 3 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
# 4 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 6 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_OnTransition:
# 7 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
# 8 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
# 9 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
# 10 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 11 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 12 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_HideRustboroRival::
# 13 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 14 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	return
# 15 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 16 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
# 17 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 9, 3
# 18 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
# 19 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 9, 6
# 20 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
# 21 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	return
# 22 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 23 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_Briney::
# 24 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	lock
# 25 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	faceplayer
# 26 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
# 27 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
# 28 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
# 29 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
# 30 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 31 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 32 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailingIntro::
# 33 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_MR_BRINEY_SAILING_INTRO
# 34 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
# 35 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
# 36 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
# 37 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
# 38 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 39 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 40 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
# 41 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
# 42 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitmessage
# 43 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
# 44 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	switch VAR_RESULT
# 45 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
# 46 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
# 47 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
# 48 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 49 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 50 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
# 51 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
# 52 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
# 53 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
# 54 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 55 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 56 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
# 57 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
# 58 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
# 59 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
# 60 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 61 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 62 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
# 63 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
# 64 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	release
# 65 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 66 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 67 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_DeclineSailing::
# 68 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
# 69 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	release
# 70 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 71 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 72 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailToDewford::
# 73 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
# 74 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call EventScript_BackupMrBrineyLocation
# 75 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
# 76 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
# 77 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 78 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 79 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 80 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 81 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 82 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_RIVAL
# 83 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	warp MAP_ROUTE104, 13, 51
# 84 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitstate
# 85 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	releaseall
# 86 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 87 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 88 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_Peeko::
# 89 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	lock
# 90 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	faceplayer
# 91 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitse
# 92 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 93 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
# 94 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitmoncry
# 95 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	release
# 96 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 97 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 98 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_WaitUpPeeko:
# 99 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Hold on, lass!\n"
# 100 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Wait up, PEEKO!$"
# 101 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 102 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
# 103 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Hm? You're {PLAYER}{KUN}!\n"
# 104 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You saved my darling PEEKO!\l"
# 105 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "We owe so much to you!\p"
# 106 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "What's that?\n"
# 107 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You want to sail with me?\p"
# 108 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Hmhm…\p"
# 109 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You have a LETTER bound for DEWFORD\n"
# 110 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "and a package for SLATEPORT, then?\p"
# 111 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Quite the busy life you must lead!\p"
# 112 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "But, certainly, what you're asking is\n"
# 113 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "no problem at all.\p"
# 114 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You've come to the right man!\n"
# 115 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "We'll set sail for DEWFORD.$"
# 116 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 117 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_SetSailForDewford:
# 118 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: DEWFORD it is, then!\p"
# 119 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Anchors aweigh!\n"
# 120 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "PEEKO, we're setting sail, my darling!$"
# 121 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 122 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_DeclineDeliverySail:
# 123 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Is that so?\n"
# 124 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Your deliveries can wait?\p"
# 125 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You just go on and tell me whenever\n"
# 126 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "you want to set sail!$"
# 127 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 128 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
# 129 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Ahoy!\n"
# 130 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "I know exactly what you want to say!\p"
# 131 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You're to deliver a LETTER to DEWFORD\n"
# 132 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "and a package to SLATEPORT.\p"
# 133 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "What you need me to do is no problem\n"
# 134 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "at all--I'm the man for the job!\p"
# 135 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "First, we'll set sail for DEWFORD.$"
# 136 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 137 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
# 138 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Ahoy!\n"
# 139 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "I know exactly what you want to say!\p"
# 140 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You're to deliver a package to\n"
# 141 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "CAPT. STERN in SLATEPORT.\p"
# 142 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "What you need me to do is no problem\n"
# 143 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "at all--I'm the man for the job!\p"
# 144 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "First, we'll set sail for DEWFORD.$"
# 145 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 146 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_WhereAreWeBound:
# 147 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Ahoy!\n"
# 148 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "For you, I'll go out to sea anytime!\p"
# 149 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Now, my friend, where are we bound?$"
# 150 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 151 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
# 152 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "MR. BRINEY: Is that so?\n"
# 153 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Well, PEEKO owes her life to you.\p"
# 154 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You just go on and tell me whenever\n"
# 155 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "you want to set sail!$"
# 156 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 157 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_Peeko:
# 158 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "PEEKO: Pii piihyoro!$"
