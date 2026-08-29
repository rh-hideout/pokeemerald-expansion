CeruleanCity_House2_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CeruleanCity_House2_Frlg_SetCounterpartGraphics
	.byte 0


@ ============================================================
@ DYNAMIC COUNTERPART GRAPHICS
@ ============================================================

CeruleanCity_House2_Frlg_SetCounterpartGraphics:
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, CeruleanCity_House2_Frlg_SetCounterpartBrendan
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, CeruleanCity_House2_Frlg_SetCounterpartMay
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, CeruleanCity_House2_Frlg_SetCounterpartLexy
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, CeruleanCity_House2_Frlg_SetCounterpartJustin
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, CeruleanCity_House2_Frlg_SetCounterpartMaam
	goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, CeruleanCity_House2_Frlg_SetCounterpartSir

	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
	return


CeruleanCity_House2_Frlg_SetCounterpartBrendan:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
	return

CeruleanCity_House2_Frlg_SetCounterpartMay:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
	return

CeruleanCity_House2_Frlg_SetCounterpartLexy:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
	return

CeruleanCity_House2_Frlg_SetCounterpartJustin:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
	return

CeruleanCity_House2_Frlg_SetCounterpartMaam:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
	return

CeruleanCity_House2_Frlg_SetCounterpartSir:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
	return


@ ============================================================
@ HIKER / DAD
@ ============================================================

CeruleanCity_House2_Frlg_EventScript_Hiker::
	lock
	faceplayer

	msgbox CeruleanCity_House2_Frlg_Text_HikerStory, MSGBOX_DEFAULT

	release
	end


@ ============================================================
@ DAUGHTER
@ ============================================================

CeruleanCity_House2_Frlg_EventScript_Daughter::
	lock
	faceplayer

	msgbox CeruleanCity_House2_Frlg_Text_DaughterStory, MSGBOX_DEFAULT

	release
	end


@ ============================================================
@ COUNTERPART
@ This is the follow-up AFTER hearing the family's story.
@ ============================================================

CeruleanCity_House2_Frlg_EventScript_Counterpart::
	lockall

	applymovement LOCALID_COUNTERPART_CERULEANHOUSE2, Common_Movement_FacePlayer
	waitmovement 0

	msgbox CeruleanCity_House2_Frlg_Text_CounterpartJames, MSGBOX_DEFAULT
	closemessage

	msgbox CeruleanCity_House2_Frlg_Text_PlayerLibrary, MSGBOX_DEFAULT
	closemessage

	msgbox CeruleanCity_House2_Frlg_Text_CounterpartKnowsJames, MSGBOX_DEFAULT
	closemessage

	msgbox CeruleanCity_House2_Frlg_Text_BookMoney, MSGBOX_DEFAULT
	closemessage

	@ Look at the giant busted wall.
	applymovement LOCALID_COUNTERPART_CERULEANHOUSE2, CeruleanCity_House2_Frlg_Movement_FaceUp
	applymovement LOCALID_PLAYER, CeruleanCity_House2_Frlg_Movement_FaceUp
	waitmovement 0

	msgbox CeruleanCity_House2_Frlg_Text_FollowThem, MSGBOX_DEFAULT
	closemessage

	releaseall
	end


@ ============================================================
@ MOVEMENT
@ ============================================================

CeruleanCity_House2_Frlg_Movement_FaceUp:
	face_up
	step_end


@ ============================================================
@ TEXT
@ ============================================================

CeruleanCity_House2_Frlg_Text_HikerStory:
	.string "HIKER: We were literally just\n"
	.string "having dinner.\p"
	.string "Then a TEAM ROCKET grunt came in\n"
	.string "with this other guy.\p"
	.string "I mean...he LOOKED like a bad guy,\n"
	.string "but he was wearing blue.\p"
	.string "He kept saying something about\n"
	.string "needing money for books.\p"
	.string "Then they smashed that hole through\n"
	.string "our wall and ran off.$"


CeruleanCity_House2_Frlg_Text_DaughterStory:
	.string "GIRL: The guy in blue wouldn't stop\n"
	.string "talking about books.\p"
	.string "Like...at all.$"


CeruleanCity_House2_Frlg_Text_CounterpartJames:
	.string "{RIVAL}: Wait.\p"
	.string "Blue?\p"
	.string "Book money?\p"
	.string "...JAMES?$"


CeruleanCity_House2_Frlg_Text_PlayerLibrary:
	.string "{PLAYER}: That's what I was\n"
	.string "thinking.\p"
	.string "I met him at the library back in\n"
	.string "LITTLEROOT.$"


CeruleanCity_House2_Frlg_Text_CounterpartKnowsJames:
	.string "{RIVAL}: Oh, I know JAMES.\p"
	.string "I live in LITTLEROOT too,\n"
	.string "remember?\p"
	.string "I've met him before.$"


CeruleanCity_House2_Frlg_Text_BookMoney:
	.string "{RIVAL}: And...\p"
	.string "I genuinely cannot believe I'm\n"
	.string "saying this...\p"
	.string "but he WOULD do basically anything\n"
	.string "for book money.\p"
	.string "So...yeah.$"


CeruleanCity_House2_Frlg_Text_FollowThem:
	.string "{RIVAL}: Welp.\p"
	.string "Guess we're following two criminals\n"
	.string "through the giant hole they made\l"
	.string "in these people's house.$"