.set LOCALID_SAFARIATTENDANT_1, 5
.set LOCALID_SAFARIATTENDANT_2, 8
.set LOCALID_SAFARIATTENDANT_3, 6
.set LOCALID_SAFARIATTENDANT_4, 7

FuchsiaCity_SafariZoneBeach_MapScripts::
	.byte 0

SafariZoneFuchsia_EventScript_Attendant1::
	lock
	faceplayer
	msgbox SafariZoneFuchsia_Text_Attendant1, MSGBOX_DEFAULT
	call_if_ge VAR_KANTO_SAFARI_ZONE_PROGRESS, 2, SafariZoneFuchsia_Approved
	closemessage
	end

SafariZoneFuchsia_EventScript_Attendant2::
	lock
	faceplayer
	msgbox SafariZoneFuchsia_Text_Attendant2, MSGBOX_DEFAULT
	call_if_ge VAR_KANTO_SAFARI_ZONE_PROGRESS, 3, SafariZoneFuchsia_Approved
	closemessage
	end

SafariZoneFuchsia_EventScript_Attendant3::
	lock
	faceplayer
	msgbox SafariZoneFuchsia_Text_Attendant3, MSGBOX_DEFAULT
	call_if_ge VAR_KANTO_SAFARI_ZONE_PROGRESS, 4, SafariZoneFuchsia_Approved
	closemessage
	end

SafariZoneFuchsia_Trigger1::
	lock
	turnobject LOCALID_SAFARIATTENDANT_1, DIR_SOUTH
	msgbox SafariZoneFuchsia_Text_Attendant1, MSGBOX_NPC
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	release
	end

SafariZoneFuchsia_Trigger2::
	lock
	turnobject LOCALID_SAFARIATTENDANT_2, DIR_EAST
	msgbox SafariZoneFuchsia_Text_Attendant2, MSGBOX_NPC
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	turnobject LOCALID_SAFARIATTENDANT_2, DIR_SOUTH
	release
	end

SafariZoneFuchsia_Trigger3::
	lock
	turnobject LOCALID_SAFARIATTENDANT_3, DIR_EAST
	turnobject LOCALID_SAFARIATTENDANT_4, DIR_EAST
	msgbox SafariZoneFuchsia_Text_Attendant3, MSGBOX_NPC
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	turnobject LOCALID_SAFARIATTENDANT_3, DIR_SOUTH
	turnobject LOCALID_SAFARIATTENDANT_4, DIR_SOUTH
	release
	end

SafariZoneFuchsia_Approved::
	msgbox SafariZoneFuchsia_Text_Approved, MSGBOX_DEFAULT
	return

SafariZoneFuchsia_Text_Attendant1:
	.string "This area requires\n"
	.string "SAFARI LEVEL 2.$"

SafariZoneFuchsia_Text_Attendant2:
	.string "This area requires\n"
	.string "SAFARI LEVEL 3.$"

SafariZoneFuchsia_Text_Attendant3:
	.string "This area requires\n"
	.string "SAFARI LEVEL 4.$"

SafariZoneFuchsia_Text_Approved:
	.string "Go right ahead.$"
