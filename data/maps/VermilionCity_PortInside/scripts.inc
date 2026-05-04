.set LOCALID_VERMILIONMARINA_SAILOR, 1
.set LOCALID_VERMILIONMARINA_BOAT, 2

VermilionCity_PortInside_MapScripts::
	.byte 0

VermilionPortIndoor_EventScript_Teacher::
	msgbox VermilionPortPassage_Text_Teacher, MSGBOX_NPC
	end
VermilionPortIndoor_EventScript_Nerd::
	msgbox VermilionPort_Text_SuperNerd, MSGBOX_NPC
	end

VermilionPortPassage_Text_Teacher:
	.string "The FAST SHIP sails every day!$"

VermilionPort_Text_SuperNerd:
	.string "You came from JOHTO?\p"
	.string "I hear many rare POKéMON live\n"
	.string "over there.$"

VermilionPort_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_RETURNED_MACHINE_PART, VermilionPort_EventScript_SailorCantSail
	goto_if_ge VAR_SSAQUA_STATE, 7, VermilionPort_EventScript_Sailor_AfterKanto
	msgbox VermilionPort_Text_AskBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_Refused
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, TRUE, VermilionPort_EventScript_Sailor_MaidenVoyage
	msgbox VermilionPort_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPort_EventScript_SailorCantSail::
	msgbox VermilionPort_Text_SailorCantSail, MSGBOX_NPC
	closemessage
	release
	end

VermilionPort_EventScript_Sailor_AfterKanto::
	message VermilionPort_Text_WhereSail
	multichoice 20, 0, MULTI_VERMILION_HARBOR, FALSE
	switch VAR_RESULT
	case 0, VermilionPort_EventScript_ChoseOlivine
	case 1, VermilionPort_EventScript_ChoseSouthernIsland
	case 2, VermilionPort_EventScript_ChoseBirthIsland
	case 3, VermilionPort_EventScript_ChoseFarawayIsland
	case 4, VermilionPort_EventScript_ChoseBattleFrontier
	case 5, VermilionPort_EventScript_Sailor_Refused
	case MULTI_B_PRESSED, VermilionPort_EventScript_Sailor_Refused
	release
	end

VermilionPort_EventScript_ChoseOlivine::
	closemessage
	delay 20
	checkitem ITEM_SS_TICKET
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE, 8, 16
	release
	end

VermilionPort_EventScript_ChoseSouthernIsland::
	closemessage
	delay 20
	checkitem ITEM_EON_TICKET
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	warpsilent MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
	release
	end

VermilionPort_EventScript_ChoseBirthIsland::
	closemessage
	delay 20
	checkitem ITEM_AURORA_TICKET
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	warpsilent MAP_BIRTH_ISLAND_EXTERIOR, 13, 23
	release
	end

VermilionPort_EventScript_ChoseFarawayIsland::
	closemessage
	delay 20
	checkitem ITEM_OLD_SEA_MAP
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	warpsilent MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	release
	end	

VermilionPort_EventScript_ChoseBattleFrontier::
	closemessage
	delay 20
	call VermilionPort_EventScript_EnterShip
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 20, 67
	release
	end	

VermilionPort_EventScript_Sailor_MaidenVoyage::
	msgbox VermilionPort_Text_FlashTicket, MSGBOX_DEFAULT
	call VermilionPort_EventScript_EnterShip
	setvar VAR_SSAQUA_STATE, 1
	warpsilent MAP_SSAQUA_1F, 29, 3
	release
	end

VermilionPort_EventScript_EnterShip::
	msgbox VermilionPort_Text_SailorGetOnBoard, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_VERMILIONMARINA_SAILOR, VermilionPort_Movement_SailorEnterBoat
	waitmovement 0
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, VermilionPort_Movement_PlayerEnterBoat
	waitmovement 0
	special SpawnCameraObject
	playse SE_EXIT
	removeobject OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement LOCALID_VERMILIONMARINA_SAILOR, VermilionPort_Movement_BoatLeave
	applymovement LOCALID_VERMILIONMARINA_BOAT, VermilionPort_Movement_BoatLeave
	waitmovement LOCALID_VERMILIONMARINA_BOAT
	setrespawn HEAL_LOCATION_VERMILION_CITY
	return

VermilionPort_EventScript_Sailor_Refused::
	msgbox VermilionPort_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPort_EventScript_Sailor_NoCredentials::
	msgbox VermilionPort_Text_NoPass, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPort_Movement_SailorEnterBoat:
	walk_down
	walk_down
	step_end

VermilionPort_Movement_PlayerEnterBoat:
	walk_down
	walk_down
	walk_in_place_down
	step_end

VermilionPort_Movement_BoatLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

VermilionPort_Text_SailorCantSail:
	.string "There's been a break-in at the\n"
	.string "POWER PLANT, so we cannot set sail\l"
	.string "until the THIEF is found.$"

VermilionPort_Text_NoPass:
    .string "{PLAYER} tried to show the\n"
    .string "{STR_VAR_1}…\p"
    .string "…But no {STR_VAR_1}!\p"
    .string "Sorry!\n"
    .string "You may board only if you have an\l"
    .string "{STR_VAR_1}.$"

VermilionPort_Text_SailorGetOnBoard:
    .string "We're departing soon.\n"
    .string "Please get on board.$"

VermilionPort_Text_CantBoard:
    .string "Sorry. You can't board now.$"

VermilionPort_Text_WhereSail:
    .string "Where would you like to sail?$"

VermilionPort_Text_AskBoard:
    .string "Welcome to FAST SHIP S.S.AQUA.\p"
    .string "Will you be boarding today?$"

VermilionPort_Text_AskTicket:
    .string "May I see your S.S.TICKET?$"

VermilionPort_Text_ComeAgain:
    .string "We hope to see you again!$"

VermilionPort_Text_FlashTicket:
    .string "{PLAYER} flashed the S.S.TICKET.\p"
    .string "That's it. Thank you!$"

VermilionPort_Text_NoTicket:
    .string "{PLAYER} tried to show the\n"
    .string "S.S.TICKET…\p"
    .string "…But no TICKET!\p"
    .string "Sorry!\n"
    .string "You may board only\l"
    .string "if you have an S.S.TICKET.$"
