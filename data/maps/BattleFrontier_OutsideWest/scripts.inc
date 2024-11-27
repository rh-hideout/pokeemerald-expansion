# 1 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 2 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 3 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_SS_TIDAL, 2
# 4 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_FERRY_ATTENDANT, 3
# 5 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_MANIAC_1, 9
# 6 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_MANIAC_2, 10
# 7 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_GIRL, 12
# 8 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_CAMPER, 14
# 9 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_FISHERMAN_2, 18
# 10 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_MAN_4, 23
# 11 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 12 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_MapScripts::
# 13 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
# 14 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.byte 0
# 15 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 16 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_OnTransition:
# 17 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
# 18 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
# 19 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 20 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 21 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FerryAttendant::
# 22 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 23 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 24 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 25 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	checkitem ITEM_SS_TICKET
# 26 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
# 27 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
# 28 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 29 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
# 30 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 31 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 32 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
# 33 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
# 34 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	switch VAR_RESULT
# 35 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
# 36 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
# 37 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
# 38 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
# 39 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 40 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 41 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_NoSSTicket::
# 42 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
# 43 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 44 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 45 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 46 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
# 47 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
# 48 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
# 49 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
# 50 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
# 51 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
# 52 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitstate
# 53 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 54 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 55 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 56 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
# 57 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
# 58 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
# 59 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
# 60 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
# 61 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
# 62 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitstate
# 63 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 64 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 65 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 66 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
# 67 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
# 68 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 69 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
# 70 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 71 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 72 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BoardFerry::
# 73 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	closemessage
# 74 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 75 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 76 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 30
# 77 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
# 78 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 79 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call Common_EventScript_FerryDepartIsland
# 80 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 81 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 82 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
# 83 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
# 84 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 85 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 86 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 87 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
# 88 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
# 89 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 90 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 91 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
# 92 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
# 93 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 94 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 95 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
# 96 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
# 97 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 98 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 99 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused. Of note, Battle Tower is in the East section in the final release
# 100 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
# 101 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
# 102 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 103 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 104 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused
# 105 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
# 106 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
# 107 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 108 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 109 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Boy1::
# 110 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
# 111 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 112 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 113 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Fisherman2::
# 114 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 115 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 116 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
# 117 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 118 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
# 119 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 120 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitbuttonpress
# 121 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 122 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 123 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 124 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man1::
# 125 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
# 126 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 127 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 128 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Maniac1::
# 129 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 130 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
# 131 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 132 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 133 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Maniac2::
# 134 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 135 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
# 136 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 137 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 138 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
# 139 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
# 140 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 141 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
# 142 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
# 143 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 144 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
# 145 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	closemessage
# 146 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 25
# 147 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
# 148 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
# 149 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 150 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 151 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 152 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 153 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Camper::
# 154 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 155 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 156 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 20
# 157 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 158 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
# 159 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 160 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 161 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
# 162 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 163 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 164 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 165 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
# 166 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
# 167 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 168 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 169 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 170 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
# 171 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 172 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 173 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Girl::
# 174 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 175 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 176 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
# 177 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 178 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
# 179 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
# 180 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
# 181 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
# 182 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitbuttonpress
# 183 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 184 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 185 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 186 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
# 187 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
# 188 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 189 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 190 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 191 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
# 192 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
# 193 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 194 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 195 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 196 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
# 197 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
# 198 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 199 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 200 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 201 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
# 202 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
# 203 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 204 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 205 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 206 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
# 207 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_down
# 208 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_down
# 209 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 210 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 211 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
# 212 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_up
# 213 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_up
# 214 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 215 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 216 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderWest:
# 217 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_right
# 218 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_right
# 219 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 220 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 221 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderEast:
# 222 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_left
# 223 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_left
# 224 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 225 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 226 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman2::
# 227 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 228 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 229 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
# 230 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	random 2
# 231 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
# 232 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
# 233 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 234 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 235 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
# 236 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
# 237 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 238 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 239 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 240 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
# 241 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
# 242 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 243 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 244 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 245 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Fisherman1::
# 246 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
# 247 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 248 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 249 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused
# 250 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
# 251 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
# 252 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 253 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 254 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Gentleman::
# 255 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
# 256 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 257 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 258 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Lass::
# 259 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
# 260 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 261 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 262 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_ExpertM::
# 263 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
# 264 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 265 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 266 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man2::
# 267 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
# 268 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 269 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 270 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman1::
# 271 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
# 272 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 273 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 274 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FatMan1::
# 275 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
# 276 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 277 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 278 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FatMan2::
# 279 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
# 280 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 281 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 282 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman3::
# 283 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 284 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
# 285 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 286 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 287 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 288 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Boy2::
# 289 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 290 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
# 291 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 292 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 293 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 294 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_OldMan::
# 295 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
# 296 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 297 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 298 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man4::
# 299 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 300 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 301 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
# 302 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	closemessage
# 303 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
# 304 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 305 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 306 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 307 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 308 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_PokefanF::
# 309 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
# 310 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 311 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 312 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattleDomeSign:
# 313 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the BATTLE DOME!\n"
# 314 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Your path to the invincible superstar!$"
# 315 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 316 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattleFactorySign:
# 317 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the BATTLE FACTORY!\n"
# 318 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Seek out the toughest POKéMON!$"
# 319 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 320 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattlePikeSign:
# 321 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the BATTLE PIKE!\n"
# 322 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Choose one of three paths!$"
# 323 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 324 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
# 325 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the BATTLE TOWER.\p"
# 326 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "TRAINERS bring their best-raised\n"
# 327 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "POKéMON for elimination-style matches.$"
# 328 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 329 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
# 330 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 331 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "May I see your TICKET?$"
# 332 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 333 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
# 334 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "{PLAYER} doesn't have the TICKET…\p"
# 335 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm terribly sorry.\p"
# 336 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You must have a TICKET to board\n"
# 337 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "the ferry.$"
# 338 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 339 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
# 340 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "{PLAYER} flashed the TICKET.\p"
# 341 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 342 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "And where would you like to go?$"
# 343 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 344 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SlateportItIs:
# 345 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "SLATEPORT CITY it is, then!$"
# 346 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 347 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LilycoveItIs:
# 348 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "LILYCOVE CITY it is, then!$"
# 349 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 350 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
# 351 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Please sail with us another time!$"
# 352 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 353 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
# 354 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 355 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "departure.$"
# 356 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 357 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
# 358 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Then, where would you like to go?$"
# 359 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 360 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
# 361 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm the best out of all my friends.\n"
# 362 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But here…\l"
# 363 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I've been useless!$"
# 364 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 365 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_CantFindBattleTower:
# 366 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I want to go to the BATTLE TOWER,\n"
# 367 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "but I can't find it even though I have\l"
# 368 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "a map of the BATTLE FRONTIER.\p"
# 369 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This place is just too big!$"
# 370 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 371 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
# 372 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I wanted to take a challenge as soon\n"
# 373 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "as I arrived here.\p"
# 374 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But on the way, I got seasick…\n"
# 375 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Urrrrp…$"
# 376 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 377 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
# 378 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It's not as if just anyone can come\n"
# 379 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "here, you know?\p"
# 380 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Only those TRAINERS who've been\n"
# 381 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "recognized as tough are brought here.\p"
# 382 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's why many TRAINERS don't even\n"
# 383 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "know about the BATTLE FRONTIER.$"
# 384 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 385 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
# 386 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Hey, bro…\p"
# 387 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Are you sure we can make challenges\n"
# 388 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "even if we don't have any POKéMON?$"
# 389 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 390 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
# 391 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Uh…\n"
# 392 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm sure it'll be okay.\p"
# 393 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I think…\p"
# 394 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But remember that big scary guy?\n"
# 395 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "He said, “I'll lend you POKéMON!”$"
# 396 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 397 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
# 398 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's the BATTLE FACTORY.\n"
# 399 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You can rent strong POKéMON there.\p"
# 400 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But it makes me wonder.\n"
# 401 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Who's raising those rental POKéMON?$"
# 402 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 403 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
# 404 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm scared of going into the BATTLE\n"
# 405 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "PIKE because of SEVIPER…\p"
# 406 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "B-but I came all the way here, so I will\n"
# 407 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "try to conquer everything!\l"
# 408 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "…Shudder…$"
# 409 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 410 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
# 411 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Let's play rock, paper, scissors!\n"
# 412 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "One, two, three!\p"
# 413 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "… … … … … …$"
# 414 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 415 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
# 416 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Yay! I won!\n"
# 417 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I will take the BATTLE PIKE challenge!$"
# 418 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 419 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
# 420 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, no…\n"
# 421 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I lost.\p"
# 422 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I guess I'm not very lucky today.\n"
# 423 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll put off my BATTLE PIKE challenge\l"
# 424 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "until tomorrow.$"
# 425 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 426 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
# 427 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I believe I'm the only person here who,\n"
# 428 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "for some unknown reason, would choose\l"
# 429 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "fishing over battling.\p"
# 430 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Huh? You can't catch anything here?\n"
# 431 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's disappointing…$"
# 432 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 433 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
# 434 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Today, I'm going to keep battling, no\n"
# 435 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "matter what, until I get a Symbol.$"
# 436 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 437 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
# 438 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh? You're off to challenge\n"
# 439 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "the BATTLE DOME?\p"
# 440 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll wish you the best of luck.\n"
# 441 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Let us both win our way up and meet\l"
# 442 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "in challenges.$"
# 443 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 444 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
# 445 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Grandpa, over here!\n"
# 446 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The BATTLE DOME is here!\l"
# 447 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Go get 'em, Grandpa!$"
# 448 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 449 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
# 450 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Ah, so this here is the BATTLE DOME?\n"
# 451 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I won't let GENTLEMEN beat me!\p"
# 452 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But where is the entrance?$"
# 453 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 454 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
# 455 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "There used to be nothing here not all\n"
# 456 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "that long ago.\p"
# 457 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But, now look at this place! Amazing!\n"
# 458 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll bring my mother out to see this.$"
# 459 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 460 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
# 461 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I've finally arrived at the BATTLE\n"
# 462 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "FRONTIER!\p"
# 463 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm sure to grab attention with\n"
# 464 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "my looks and ability!$"
# 465 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 466 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
# 467 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Munch, munch…\p"
# 468 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It looks like this square's filled with\n"
# 469 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "tough people.\p"
# 470 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Munch, munch…$"
# 471 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 472 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
# 473 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…\p"
# 474 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "A while back, I met this older girl\n"
# 475 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "at the BATTLE PIKE.\p"
# 476 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "She had these eyes that were scary\n"
# 477 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "in a real ornery way.\p"
# 478 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…\p"
# 479 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "She got all furious: “Will you quit\n"
# 480 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "eating!” Then she whaled on me.\p"
# 481 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It was a hair-raising kind of\n"
# 482 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "scary experience, sure enough.\p"
# 483 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…$"
# 484 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 485 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
# 486 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Huh? Will you listen to yourself?\n"
# 487 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's nothing!\p"
# 488 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Why, the last time I cheered for him,\n"
# 489 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "our eyes met and sparks flew!$"
# 490 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 491 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
# 492 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Whaaaaaat?!\n"
# 493 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Pfft!\p"
# 494 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That only happened because\n"
# 495 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I happened to be sitting next to you!\p"
# 496 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The DOME ACE only looked our way\n"
# 497 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "because my cheering was so loud!$"
# 498 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 499 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeAceIsMine:
# 500 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, shush!\n"
# 501 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Keep that racket down!\p"
# 502 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You fair-weather fans should stick\n"
# 503 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "to cheering for some GYM LEADER!\p"
# 504 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The DOME ACE is mine!\n"
# 505 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The only idol for me!$"
# 506 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 507 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
# 508 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Those people squabbling over there…\p"
# 509 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It's hard to believe, but they once\n"
# 510 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "were TRAINERS, and good ones, too.\p"
# 511 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They used to be incredibly tough,\n"
# 512 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "and they were famous, too.\p"
# 513 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But they were obliterated by this\n"
# 514 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "certain TRAINER at a tournament.\p"
# 515 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They were so thoroughly whipped,\n"
# 516 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "they became smitten by the TRAINER.\p"
# 517 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Now they're just fans of the TRAINER.\n"
# 518 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They go cheer for their idol at the\l"
# 519 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "BATTLE DOME every day now.$"
# 520 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 521 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
# 522 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I heard a rumor that someone saw\n"
# 523 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "a POKéMON with an unusually long tail\l"
# 524 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "somewhere in the BATTLE FRONTIER.\p"
# 525 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It must be adorable. I'm sure of it…\p"
# 526 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, challenges can wait. I feel driven\n"
# 527 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "to find the delightful creature!$"
# 528 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 529 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 530 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
EventScript_EonGift::
# 531 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    lock
# 532 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    faceplayer
# 533 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    message gText_EONtext
# 534 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    waitmessage
# 535 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    checkitem ITEM_EON_TICKET, 1
# 536 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    compare VAR_RESULT, 1
# 537 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    goto_if_eq Script_haveEticket
# 538 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    waitmessage
# 539 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    message gText_HereisEticket
# 540 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    giveitem ITEM_EON_TICKET
# 541 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 542 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
# 543 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    release
# 544 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    end
# 545 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 546 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
Script_haveEticket::
# 547 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    msgbox gText_haveEticket
# 548 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    release
# 549 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    end
# 550 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 551 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
gText_EONtext::
# 552 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    .string "You seem like the correct person...\p $"
# 553 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 554 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
gText_haveEticket::
# 555 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    .string "Oh Wait! How did it go?$"
# 556 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 557 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
gText_HereisEticket::
# 558 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
    .string "Here you go! I hope your confident!$"
