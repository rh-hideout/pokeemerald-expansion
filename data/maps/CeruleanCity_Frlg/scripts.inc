CeruleanCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CeruleanCity_Frlg_SetCounterpartGraphics
	.byte 0


@ ============================================================
@ DYNAMIC COUNTERPART GRAPHICS
@ OBJ_EVENT_GFX_VAR_0
@ ============================================================

CeruleanCity_Frlg_SetCounterpartGraphics:
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, CeruleanCity_Frlg_SetCounterpartBrendan
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, CeruleanCity_Frlg_SetCounterpartMay
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, CeruleanCity_Frlg_SetCounterpartLexy
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, CeruleanCity_Frlg_SetCounterpartJustin
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, CeruleanCity_Frlg_SetCounterpartMaam
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, CeruleanCity_Frlg_SetCounterpartSir

	@ Fallback
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
	return


CeruleanCity_Frlg_SetCounterpartBrendan:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
	return


CeruleanCity_Frlg_SetCounterpartMay:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
	return


CeruleanCity_Frlg_SetCounterpartLexy:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
	return


CeruleanCity_Frlg_SetCounterpartJustin:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
	return


CeruleanCity_Frlg_SetCounterpartMaam:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
	return


CeruleanCity_Frlg_SetCounterpartSir:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
	return


@ ============================================================
@ COUNTERPART
@ Porymap:
@ Graphics = OBJ_EVENT_GFX_VAR_0
@ Script   = CeruleanCity_Frlg_EventScript_Counterpart
@ ============================================================

CeruleanCity_Frlg_EventScript_Counterpart::
	lockall

	applymovement LOCALID_COUNTERPART_CERULEAN, Common_Movement_FacePlayer
	waitmovement 0

	msgbox CeruleanCity_Frlg_Text_GuestOfHonor, MSGBOX_DEFAULT
	closemessage

	msgbox CeruleanCity_Frlg_Text_TalkedToOfficer, MSGBOX_DEFAULT
	closemessage

	@ Three virtue responses
	multichoice 0, 0, MULTICHOICE_CERULEAN_FIRST_RESPONSE, FALSE

	switch VAR_RESULT
	case 0, CeruleanCity_Frlg_EventScript_ResponseCompassion
	case 1, CeruleanCity_Frlg_EventScript_ResponseWisdom
	case 2, CeruleanCity_Frlg_EventScript_ResponseResolve

	releaseall
	end


@ ============================================================
@ VIRTUE RESPONSES
@ ============================================================

CeruleanCity_Frlg_EventScript_ResponseCompassion:
	addvar VAR_COMPASSION, 1

	msgbox CeruleanCity_Frlg_Text_PlayerCompassion, MSGBOX_DEFAULT
	closemessage

	msgbox CeruleanCity_Frlg_Text_CounterpartCompassion, MSGBOX_DEFAULT
	closemessage

	goto CeruleanCity_Frlg_EventScript_Continue


CeruleanCity_Frlg_EventScript_ResponseWisdom:
	addvar VAR_WISDOM, 1

	msgbox CeruleanCity_Frlg_Text_PlayerWisdom, MSGBOX_DEFAULT
	closemessage

	msgbox CeruleanCity_Frlg_Text_CounterpartWisdom, MSGBOX_DEFAULT
	closemessage

	goto CeruleanCity_Frlg_EventScript_Continue


CeruleanCity_Frlg_EventScript_ResponseResolve:
	addvar VAR_RESOLVE, 1

	msgbox CeruleanCity_Frlg_Text_PlayerResolve, MSGBOX_DEFAULT
	closemessage

	msgbox CeruleanCity_Frlg_Text_CounterpartResolve, MSGBOX_DEFAULT
	closemessage

	goto CeruleanCity_Frlg_EventScript_Continue


CeruleanCity_Frlg_EventScript_Continue:
	msgbox CeruleanCity_Frlg_Text_CheckHouse, MSGBOX_DEFAULT
	closemessage

	releaseall
	end

CeruleanCity_Frlg_EventScript_LibrarySign::
    msgbox CeruleanCity_Frlg_Text_LibrarySign, MSGBOX_SIGN
    end



@ ============================================================
@ OFFICER
@ Assign this script to the officer object in Porymap.
@ ============================================================

CeruleanCity_Frlg_EventScript_Officer::
	lock
	faceplayer

	msgbox CeruleanCity_Frlg_Text_Officer, MSGBOX_DEFAULT

	release
	end


@ ============================================================
@ TEXT
@ ============================================================

CeruleanCity_Frlg_Text_GuestOfHonor:
	.string "OAK'S GRANDCHILD: Well, well...\p"
	.string "Our guest of honor finally made it.$"


CeruleanCity_Frlg_Text_TalkedToOfficer:
	.string "OAK'S GRANDCHILD: I talked to this\n"
	.string "officer.\p"
	.string "Apparently the warp the intruders\n"
	.string "used brought them to the house\l"
	.string "right behind us.\p"
	.string "I told him MISTY sent us.\p"
	.string "He looked extremely confused...\p"
	.string "but he said we're cool, so hey.$"


CeruleanCity_Frlg_Text_PlayerCompassion:
	.string "{PLAYER}: Are the people inside\n"
	.string "okay?$"


CeruleanCity_Frlg_Text_CounterpartCompassion:
	.string "OAK'S GRANDCHILD: Yeah.\p"
	.string "Shaken up, but nobody was hurt.$"


CeruleanCity_Frlg_Text_PlayerWisdom:
	.string "{PLAYER}: What exactly did they\n"
	.string "see?$"


CeruleanCity_Frlg_Text_CounterpartWisdom:
	.string "OAK'S GRANDCHILD: That's what I\n"
	.string "want to find out.\p"
	.string "Apparently they got a pretty good\n"
	.string "look at both of them.$"


CeruleanCity_Frlg_Text_PlayerResolve:
	.string "{PLAYER}: Then let's go after them.$"


CeruleanCity_Frlg_Text_CounterpartResolve:
	.string "OAK'S GRANDCHILD: See?\p"
	.string "That's the energy I was hoping for.$"


CeruleanCity_Frlg_Text_CheckHouse:
	.string "OAK'S GRANDCHILD: Come on.\p"
	.string "Let's check out the house.$"


CeruleanCity_Frlg_Text_Officer:
	.string "OFFICER: Your friend says MISTY\n"
	.string "sent you two.\p"
	.string "...I'm still not entirely sure how\n"
	.string "that makes sense.\p"
	.string "But the family inside is unharmed.\p"
	.string "Please don't disturb anything more\n"
	.string "than necessary.$"

@ ============================================================
@ ROCKET GRUNT OUTSIDE THE HOUSE
@ He is arguing with James, who has already wandered off.
@ ============================================================

CeruleanCity_Frlg_EventScript_RocketGrunt::
    lockall

    applymovement LOCALID_CERULEAN_ROCKET_GRUNT, Common_Movement_FaceRight
    waitmovement 0

    msgbox CeruleanCity_Frlg_Text_RocketComplaining, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_CERULEAN_ROCKET_GRUNT, CeruleanCity_Frlg_Movement_RocketLeaves
    waitmovement 0

    setflag FLAG_HIDE_CERULEAN_ROCKET_GRUNT
    removeobject LOCALID_CERULEAN_ROCKET_GRUNT

    releaseall
    end


CeruleanCity_Frlg_Movement_RocketLeaves:
    walk_right
    walk_right
    walk_right
    walk_down
    walk_down
	walk_down
	walk_down
	walk_down
	walk_down
    step_end


CeruleanCity_Frlg_Text_RocketComplaining:
    .string "ROCKET GRUNT: WAIT! NO!\p"
    .string "WE HAD A PLAN!\p"
    .string "You can't just scrap the whole\n"
    .string "thing because somebody mentioned\l"
    .string "a LIBRARY!\p"
    .string "Come on, man!\n"
    .string "We're BAD GUYS!$"

CeruleanCity_Frlg_Text_LibrarySign:
    .string "CERULEAN LIBRARY$"