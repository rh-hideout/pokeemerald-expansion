# 1 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 2 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_MapScripts::
# 3 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
# 4 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.byte 0
# 5 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 6 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_OnTransition:
# 7 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
# 8 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
# 9 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 10 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 11 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FerryAttendant::
# 12 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 13 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 14 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 15 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	checkitem ITEM_SS_TICKET
# 16 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
# 17 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
# 18 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 19 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
# 20 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 21 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 22 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
# 23 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
# 24 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	switch VAR_RESULT
# 25 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
# 26 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
# 27 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
# 28 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
# 29 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 30 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 31 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_NoSSTicket::
# 32 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
# 33 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 34 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 35 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 36 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
# 37 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
# 38 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
# 39 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
# 40 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
# 41 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
# 42 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitstate
# 43 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 44 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 45 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 46 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
# 47 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
# 48 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
# 49 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
# 50 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
# 51 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
# 52 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitstate
# 53 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 54 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 55 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 56 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
# 57 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
# 58 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 59 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
# 60 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 61 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 62 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BoardFerry::
# 63 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	closemessage
# 64 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 65 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 66 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 30
# 67 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
# 68 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
# 69 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call Common_EventScript_FerryDepartIsland
# 70 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 71 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 72 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
# 73 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
# 74 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 75 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 76 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 77 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
# 78 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
# 79 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 80 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 81 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
# 82 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
# 83 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 84 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 85 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
# 86 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
# 87 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 88 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 89 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused. Of note, Battle Tower is in the East section in the final release
# 90 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
# 91 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
# 92 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 93 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 94 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused
# 95 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
# 96 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
# 97 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 98 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 99 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Boy1::
# 100 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
# 101 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 102 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 103 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Fisherman2::
# 104 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 105 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 106 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
# 107 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 108 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
# 109 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 110 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitbuttonpress
# 111 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 112 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 113 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 114 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man1::
# 115 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
# 116 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 117 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 118 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Maniac1::
# 119 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 120 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
# 121 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 122 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 123 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Maniac2::
# 124 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 125 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
# 126 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 127 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 128 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
# 129 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
# 130 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 131 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
# 132 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
# 133 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 134 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
# 135 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	closemessage
# 136 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 25
# 137 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
# 138 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
# 139 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 140 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 141 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 142 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 143 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Camper::
# 144 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 145 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 146 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 20
# 147 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 148 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
# 149 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 150 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 151 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
# 152 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 153 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 154 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 155 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
# 156 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
# 157 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 158 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 159 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 160 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
# 161 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 162 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 163 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Girl::
# 164 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 165 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 166 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
# 167 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 168 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
# 169 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
# 170 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
# 171 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
# 172 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitbuttonpress
# 173 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 174 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 175 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 176 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
# 177 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
# 178 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 179 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 180 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 181 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
# 182 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
# 183 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 184 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 185 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 186 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
# 187 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
# 188 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 189 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 190 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 191 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
# 192 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
# 193 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 194 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 195 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 196 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
# 197 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_down
# 198 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_down
# 199 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 200 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 201 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
# 202 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_up
# 203 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_up
# 204 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 205 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 206 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderWest:
# 207 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_right
# 208 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_right
# 209 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 210 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 211 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderEast:
# 212 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_left
# 213 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_left
# 214 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 215 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 216 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman2::
# 217 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 218 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 219 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
# 220 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	random 2
# 221 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
# 222 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
# 223 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 224 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 225 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
# 226 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
# 227 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 228 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 229 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 230 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
# 231 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
# 232 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 233 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 234 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 235 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Fisherman1::
# 236 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
# 237 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 238 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 239 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused
# 240 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
# 241 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
# 242 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 243 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 244 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Gentleman::
# 245 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
# 246 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 247 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 248 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Lass::
# 249 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
# 250 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 251 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 252 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_ExpertM::
# 253 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
# 254 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 255 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 256 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man2::
# 257 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
# 258 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 259 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 260 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman1::
# 261 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
# 262 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 263 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 264 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FatMan1::
# 265 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
# 266 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 267 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 268 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FatMan2::
# 269 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
# 270 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 271 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 272 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman3::
# 273 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 274 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
# 275 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 276 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 277 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 278 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Boy2::
# 279 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 280 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
# 281 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 282 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 283 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 284 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_OldMan::
# 285 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
# 286 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 287 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 288 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man4::
# 289 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 290 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 291 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
# 292 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	closemessage
# 293 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
# 294 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 295 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 296 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 297 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 298 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_PokefanF::
# 299 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
# 300 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 301 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 302 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattleDomeSign:
# 303 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the BATTLE DOME!\n"
# 304 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Your path to the invincible superstar!$"
# 305 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 306 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattleFactorySign:
# 307 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the BATTLE FACTORY!\n"
# 308 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Seek out the toughest POKéMON!$"
# 309 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 310 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattlePikeSign:
# 311 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the BATTLE PIKE!\n"
# 312 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Choose one of three paths!$"
# 313 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 314 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
# 315 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the BATTLE TOWER.\p"
# 316 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "TRAINERS bring their best-raised\n"
# 317 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "POKéMON for elimination-style matches.$"
# 318 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 319 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
# 320 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 321 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "May I see your TICKET?$"
# 322 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 323 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
# 324 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "{PLAYER} doesn't have the TICKET…\p"
# 325 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm terribly sorry.\p"
# 326 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You must have a TICKET to board\n"
# 327 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "the ferry.$"
# 328 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 329 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
# 330 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "{PLAYER} flashed the TICKET.\p"
# 331 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 332 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "And where would you like to go?$"
# 333 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 334 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SlateportItIs:
# 335 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "SLATEPORT CITY it is, then!$"
# 336 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 337 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LilycoveItIs:
# 338 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "LILYCOVE CITY it is, then!$"
# 339 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 340 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
# 341 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Please sail with us another time!$"
# 342 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 343 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
# 344 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 345 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "departure.$"
# 346 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 347 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
# 348 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Then, where would you like to go?$"
# 349 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 350 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
# 351 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm the best out of all my friends.\n"
# 352 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But here…\l"
# 353 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I've been useless!$"
# 354 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 355 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_CantFindBattleTower:
# 356 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I want to go to the BATTLE TOWER,\n"
# 357 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "but I can't find it even though I have\l"
# 358 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "a map of the BATTLE FRONTIER.\p"
# 359 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This place is just too big!$"
# 360 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 361 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
# 362 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I wanted to take a challenge as soon\n"
# 363 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "as I arrived here.\p"
# 364 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But on the way, I got seasick…\n"
# 365 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Urrrrp…$"
# 366 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 367 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
# 368 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It's not as if just anyone can come\n"
# 369 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "here, you know?\p"
# 370 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Only those TRAINERS who've been\n"
# 371 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "recognized as tough are brought here.\p"
# 372 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's why many TRAINERS don't even\n"
# 373 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "know about the BATTLE FRONTIER.$"
# 374 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 375 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
# 376 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Hey, bro…\p"
# 377 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Are you sure we can make challenges\n"
# 378 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "even if we don't have any POKéMON?$"
# 379 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 380 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
# 381 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Uh…\n"
# 382 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm sure it'll be okay.\p"
# 383 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I think…\p"
# 384 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But remember that big scary guy?\n"
# 385 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "He said, “I'll lend you POKéMON!”$"
# 386 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 387 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
# 388 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's the BATTLE FACTORY.\n"
# 389 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You can rent strong POKéMON there.\p"
# 390 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But it makes me wonder.\n"
# 391 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Who's raising those rental POKéMON?$"
# 392 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 393 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
# 394 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm scared of going into the BATTLE\n"
# 395 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "PIKE because of SEVIPER…\p"
# 396 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "B-but I came all the way here, so I will\n"
# 397 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "try to conquer everything!\l"
# 398 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "…Shudder…$"
# 399 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 400 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
# 401 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Let's play rock, paper, scissors!\n"
# 402 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "One, two, three!\p"
# 403 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "… … … … … …$"
# 404 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 405 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
# 406 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Yay! I won!\n"
# 407 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I will take the BATTLE PIKE challenge!$"
# 408 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 409 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
# 410 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, no…\n"
# 411 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I lost.\p"
# 412 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I guess I'm not very lucky today.\n"
# 413 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll put off my BATTLE PIKE challenge\l"
# 414 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "until tomorrow.$"
# 415 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 416 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
# 417 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I believe I'm the only person here who,\n"
# 418 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "for some unknown reason, would choose\l"
# 419 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "fishing over battling.\p"
# 420 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Huh? You can't catch anything here?\n"
# 421 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's disappointing…$"
# 422 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 423 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
# 424 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Today, I'm going to keep battling, no\n"
# 425 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "matter what, until I get a Symbol.$"
# 426 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 427 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
# 428 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh? You're off to challenge\n"
# 429 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "the BATTLE DOME?\p"
# 430 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll wish you the best of luck.\n"
# 431 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Let us both win our way up and meet\l"
# 432 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "in challenges.$"
# 433 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 434 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
# 435 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Grandpa, over here!\n"
# 436 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The BATTLE DOME is here!\l"
# 437 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Go get 'em, Grandpa!$"
# 438 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 439 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
# 440 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Ah, so this here is the BATTLE DOME?\n"
# 441 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I won't let GENTLEMEN beat me!\p"
# 442 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But where is the entrance?$"
# 443 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 444 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
# 445 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "There used to be nothing here not all\n"
# 446 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "that long ago.\p"
# 447 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But, now look at this place! Amazing!\n"
# 448 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll bring my mother out to see this.$"
# 449 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 450 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
# 451 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I've finally arrived at the BATTLE\n"
# 452 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "FRONTIER!\p"
# 453 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm sure to grab attention with\n"
# 454 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "my looks and ability!$"
# 455 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 456 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
# 457 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Munch, munch…\p"
# 458 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It looks like this square's filled with\n"
# 459 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "tough people.\p"
# 460 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Munch, munch…$"
# 461 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 462 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
# 463 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…\p"
# 464 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "A while back, I met this older girl\n"
# 465 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "at the BATTLE PIKE.\p"
# 466 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "She had these eyes that were scary\n"
# 467 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "in a real ornery way.\p"
# 468 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…\p"
# 469 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "She got all furious: “Will you quit\n"
# 470 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "eating!” Then she whaled on me.\p"
# 471 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It was a hair-raising kind of\n"
# 472 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "scary experience, sure enough.\p"
# 473 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…$"
# 474 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 475 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
# 476 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Huh? Will you listen to yourself?\n"
# 477 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's nothing!\p"
# 478 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Why, the last time I cheered for him,\n"
# 479 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "our eyes met and sparks flew!$"
# 480 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 481 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
# 482 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Whaaaaaat?!\n"
# 483 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Pfft!\p"
# 484 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That only happened because\n"
# 485 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I happened to be sitting next to you!\p"
# 486 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The DOME ACE only looked our way\n"
# 487 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "because my cheering was so loud!$"
# 488 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 489 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeAceIsMine:
# 490 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, shush!\n"
# 491 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Keep that racket down!\p"
# 492 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You fair-weather fans should stick\n"
# 493 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "to cheering for some GYM LEADER!\p"
# 494 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The DOME ACE is mine!\n"
# 495 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The only idol for me!$"
# 496 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 497 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
# 498 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Those people squabbling over there…\p"
# 499 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It's hard to believe, but they once\n"
# 500 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "were TRAINERS, and good ones, too.\p"
# 501 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They used to be incredibly tough,\n"
# 502 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "and they were famous, too.\p"
# 503 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But they were obliterated by this\n"
# 504 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "certain TRAINER at a tournament.\p"
# 505 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They were so thoroughly whipped,\n"
# 506 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "they became smitten by the TRAINER.\p"
# 507 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Now they're just fans of the TRAINER.\n"
# 508 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They go cheer for their idol at the\l"
# 509 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "BATTLE DOME every day now.$"
# 510 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 511 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
# 512 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I heard a rumor that someone saw\n"
# 513 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "a POKéMON with an unusually long tail\l"
# 514 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "somewhere in the BATTLE FRONTIER.\p"
# 515 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It must be adorable. I'm sure of it…\p"
# 516 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, challenges can wait. I feel driven\n"
# 517 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "to find the delightful creature!$"
