CeruleanCity_Frlg_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, CeruleanCity_Frlg_OnLoad
    map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_Frlg_OnTransition
    map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, CeruleanCity_Frlg_OnReturnToField
    .byte 0


CeruleanCity_Frlg_OnLoad:
    @ Graphics only. Do not reposition live objects here.
    call CeruleanCity_Frlg_SetCounterpartGraphics
    end


CeruleanCity_Frlg_OnReturnToField:
    compare VAR_BROCK_INGREDIENT_QUEST, 5
    goto_if_ne CeruleanCity_Frlg_OnReturnToField_End

    goto_if_unset FLAG_CERULEAN_GARY_TOUR_ARRIVED, CeruleanCity_Frlg_OnReturnToField_End

    @ Continue-from-save restores the saved live object first.
    @ Repair that live object to the final Gary-side position.
    clearflag FLAG_HIDE_CERULEAN_GARY_TOUR_COUNTERPART
    showobjectat LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, MAP_CERULEAN_CITY
    setobjectxy LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, 22, 1
    setobjectmovementtype LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, MOVEMENT_TYPE_FACE_UP

CeruleanCity_Frlg_OnReturnToField_End:
    end


CeruleanCity_Frlg_OnTransition:
    compare VAR_BROCK_INGREDIENT_QUEST, 5
    goto_if_eq CeruleanCity_Frlg_OnTransition_GaryTourState5

    @ Tour inactive outside state 5.
    setflag FLAG_HIDE_CERULEAN_GARY_TOUR_COUNTERPART
    end


CeruleanCity_Frlg_OnTransition_GaryTourState5:
    goto_if_set FLAG_CERULEAN_GARY_TOUR_ARRIVED, CeruleanCity_Frlg_OnTransition_GaryTourArrived

    @ Before the walk:
    @ establish the template at the library BEFORE object spawn.
    setobjectxyperm LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, 20, 13
    setobjectmovementtype LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, MOVEMENT_TYPE_FACE_LEFT
    clearflag FLAG_HIDE_CERULEAN_GARY_TOUR_COUNTERPART
    end


CeruleanCity_Frlg_OnTransition_GaryTourArrived:
    @ After the walk:
    @ establish the template below Gary BEFORE object spawn.
    setobjectxyperm LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, 22, 1
    setobjectmovementtype LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, MOVEMENT_TYPE_FACE_UP
    clearflag FLAG_HIDE_CERULEAN_GARY_TOUR_COUNTERPART
    end


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

@ ============================================================
@ TOUR DE GARY - OUTSIDE LIBRARY
@ ============================================================

CeruleanCity_Frlg_EventScript_GaryTourCounterpart::
    lockall

    compare VAR_BROCK_INGREDIENT_QUEST, 5
    goto_if_ne CeruleanCity_Frlg_EventScript_GaryTourCounterpartInactive

    goto_if_set FLAG_CERULEAN_GARY_TOUR_ARRIVED, CeruleanCity_Frlg_EventScript_GaryTourCounterpartAtGary

    applymovement LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, Common_Movement_FacePlayer
    waitmovement 0

    msgbox CeruleanCity_Frlg_Text_GaryTourOutsideLibrary, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, CeruleanCity_Frlg_Movement_GaryTourCounterpartLeaves
    waitmovement 0

    @ The live movement has finished.
    @ Canonical Gary-side staging position.
    setobjectxy LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, 22, 1
    setobjectmovementtype LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, MOVEMENT_TYPE_FACE_UP

    @ Persist the completed state and exact canonical position.
    setflag FLAG_CERULEAN_GARY_TOUR_ARRIVED
    copyobjectxytoperm LOCALID_COUNTERPART_CERULEAN_GARY_TOUR

    releaseall
    end


CeruleanCity_Frlg_EventScript_GaryTourCounterpartAtGary:
    applymovement LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, Common_Movement_FacePlayer
    waitmovement 0

    msgbox CeruleanCity_Frlg_Text_GaryTourAtGary, MSGBOX_DEFAULT

    releaseall
    end


CeruleanCity_Frlg_Text_GaryTourAtGary:
    .string "{RIVAL}: Well?\n"
    .string "Talk to GARY.$"


CeruleanCity_Frlg_EventScript_GaryTourCounterpartInactive:
    hideobjectat LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, MAP_CERULEAN_CITY
    releaseall
    end


CeruleanCity_Frlg_Text_GaryTourOutsideLibrary:
    .string "{RIVAL}: Come on.\p"
    .string "{PLAYER}: Where are we going?\p"
    .string "{RIVAL}: North.\p"
    .string "{PLAYER}: That's not an answer.\p"
    .string "{RIVAL}: It is if you start walking.\p"
    .string "{PLAYER}: ...\p"
    .string "{RIVAL}: Nugget Bridge.\p"
    .string "{PLAYER}: What's at Nugget Bridge?\p"
    .string "{RIVAL}: Someone annoying.\p"
    .string "{PLAYER}: You?\p"
    .string "{RIVAL}: Keep talking and we're\n"
    .string "walking to FUCHSIA.$"


CeruleanCity_Frlg_Movement_GaryTourCounterpartLeaves:
    walk_down

    walk_right
    walk_right

    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up

    step_end


CeruleanCity_Frlg_EventScript_Counterpart::
	lockall

	applymovement LOCALID_COUNTERPART_CERULEAN, Common_Movement_FacePlayer
	waitmovement 0

	compare VAR_BROCK_INGREDIENT_QUEST, 3
     goto_if_eq CeruleanCity_Frlg_EventScript_IngredientLibraryLead

     compare VAR_BROCK_INGREDIENT_QUEST, 4
     goto_if_eq CeruleanCity_Frlg_EventScript_IngredientLibraryRepeat

     goto_if_set FLAG_CERULEAN_COUNTERPART_BRIEFED, CeruleanCity_Frlg_EventScript_CounterpartRepeat

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

	setflag FLAG_CERULEAN_COUNTERPART_BRIEFED

	releaseall
	end


CeruleanCity_Frlg_EventScript_CounterpartRepeat:
	msgbox CeruleanCity_Frlg_Text_CounterpartRepeat, MSGBOX_DEFAULT
	closemessage

	releaseall
	end

@ ============================================================
@ BROCK INGREDIENT QUEST - CERULEAN LIBRARY LEAD
@ State 3 = Savvy sent us to Cerulean
@ State 4 = Counterpart identified the library lead
@ ============================================================

CeruleanCity_Frlg_EventScript_IngredientLibraryLead:
    msgbox CeruleanCity_Frlg_Text_IngredientTiredOfThis, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_IngredientCopTheory, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_IngredientGetToPoint, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_IngredientLibraryThought, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_IngredientLibraryFinish, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_IngredientMeetAtLibrary, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_COUNTERPART_CERULEAN, CeruleanCity_Frlg_Movement_CounterpartLeavesForLibrary
    waitmovement 0

    setvar VAR_BROCK_INGREDIENT_QUEST, 4
    setflag FLAG_HIDE_CERULEAN_INGREDIENT_COUNTERPART
    removeobject LOCALID_COUNTERPART_CERULEAN

    releaseall
    end


CeruleanCity_Frlg_Movement_CounterpartLeavesForLibrary:
    walk_right
    walk_down
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end


CeruleanCity_Frlg_EventScript_IngredientLibraryRepeat:
    msgbox CeruleanCity_Frlg_Text_IngredientLibraryRepeat, MSGBOX_DEFAULT
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


CeruleanCity_Frlg_EventScript_OfficerIngredientQuest:
    msgbox CeruleanCity_Frlg_Text_OfficerIngredientQuest, MSGBOX_DEFAULT
    release
    end


@ ============================================================
@ TEXT
@ ============================================================

CeruleanCity_Frlg_Text_GuestOfHonor:
	.string "{RIVAL}: Well, well...\p"
	.string "Our guest of honor finally made it.$"


CeruleanCity_Frlg_Text_TalkedToOfficer:
	.string "{RIVAL}: I talked to this\n"
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
	.string "{RIVAL}: Yeah.\p"
	.string "Shaken up, but nobody was hurt.$"


CeruleanCity_Frlg_Text_PlayerWisdom:
	.string "{PLAYER}: What exactly did they\n"
	.string "see?$"


CeruleanCity_Frlg_Text_CounterpartWisdom:
	.string "{RIVAL}: That's what I\n"
	.string "want to find out.\p"
	.string "Apparently they got a pretty good\n"
	.string "look at both of them.$"


CeruleanCity_Frlg_Text_PlayerResolve:
	.string "{PLAYER}: Then let's go after them.$"


CeruleanCity_Frlg_Text_CounterpartResolve:
	.string "{RIVAL}: See?\p"
	.string "That's the energy I was hoping for.$"


CeruleanCity_Frlg_Text_CheckHouse:
	.string "{RIVAL}: Come on.\p"
	.string "Let's check out the house.$"


CeruleanCity_Frlg_Text_CounterpartRepeat:
	.string "{RIVAL}: Come on.\p"
	.string "We already know where they went.\p"
	.string "Let's check out that house.$"


CeruleanCity_Frlg_Text_IngredientTiredOfThis:
    .string "{PLAYER}: ...I'm getting tired of this.\p"
    .string "{RIVAL}: Whatever do you mean?\p"
    .string "{PLAYER}: You.\n"
    .string "Being here first. Again.\p"
    .string "{RIVAL}: We have a lady to find,\n"
    .string "buddy. Focus.$"


CeruleanCity_Frlg_Text_IngredientCopTheory:
    .string "{RIVAL}: I'm talking to the cop guy.\p"
    .string "Just like last time.\p"
    .string "Cops always know stuff, right?\p"
    .string "{PLAYER}: That's becoming a very\n"
    .string "concerning theory of yours.\p"
    .string "{RIVAL}: ANYWAY.\p"
    .string "He said someone said that\n"
    .string "someone said--$"


CeruleanCity_Frlg_Text_IngredientGetToPoint:
    .string "{PLAYER}: GET TO THE POINT.\p"
    .string "{RIVAL}: ...The library.\p"
    .string "{PLAYER}: The library?\p"
    .string "{PLAYER}: ...\p"
    .string "...Wait.\p"
    .string "That man...\p"
    .string "He noticed the book.\p"
    .string "The cover.$"


CeruleanCity_Frlg_Text_IngredientLibraryThought:
    .string "{RIVAL}: ...You good?\p"
    .string "{PLAYER}: We need to go to the\n"
    .string "library.\p"
    .string "{RIVAL}: That's what I just said.\p"
    .string "{PLAYER}: I know.$"


CeruleanCity_Frlg_Text_IngredientLibraryFinish:
    .string "{RIVAL}: Then why did you say it\n"
    .string "like you solved something?\p"
    .string "{PLAYER}: Let's go.\p"
    .string "{RIVAL}: ...Okay, detective.$"


CeruleanCity_Frlg_Text_IngredientMeetAtLibrary:
    .string "{RIVAL}: I'll meet you there.\p"
    .string "{PLAYER}: You're already going?\p"
    .string "{RIVAL}: Unlike some people, I don't\n"
    .string "need five minutes to dramatically\l"
    .string "realize we're going to the place\l"
    .string "I just said.\p"
    .string "{PLAYER}: ...\p"
    .string "{RIVAL}: LIBRARY!$"


CeruleanCity_Frlg_Text_IngredientLibraryRepeat:
    .string "{RIVAL}: Library.\p"
    .string "You know, the place I told you\n"
    .string "about before you solved it.$"


CeruleanCity_Frlg_Text_OfficerIngredientQuest:
    .string "OFFICER: Back again?\p"
    .string "Your friend has been asking around.\p"
    .string "Someone matching that woman's\n"
    .string "description was here recently.\p"
    .string "I heard she'd been asking about\n"
    .string "some old records.\p"
    .string "If you're following her trail,\n"
    .string "I'd check the LIBRARY.$"


CeruleanCity_Frlg_Text_Officer:
    .string "OFFICER: Your friend says MISTY\n"
    .string "sent you two.\p"
    .string "...I'm still not entirely sure how\n"
    .string "that makes sense.\p"
    .string "And now you're asking questions\n"
    .string "around here again.\p"
    .string "Just try not to make my paperwork\n"
    .string "any worse, alright?$"

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

@ ============================================================
@ GARY / OAK FAMILY FORESHADOW
@ ============================================================

CeruleanCity_Frlg_EventScript_Gary::
    lock
    faceplayer

    compare VAR_BROCK_INGREDIENT_QUEST, 3
    goto_if_eq CeruleanCity_Frlg_EventScript_OfficerIngredientQuest

    compare VAR_BROCK_INGREDIENT_QUEST, 4
    goto_if_eq CeruleanCity_Frlg_EventScript_OfficerIngredientQuest

    compare VAR_BROCK_INGREDIENT_QUEST, 5
    goto_if_eq CeruleanCity_Frlg_EventScript_GaryFuchsiaRide


    msgbox CeruleanCity_Frlg_Text_GaryIntro, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_PlayerGaryThought, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_PlayerAskOak, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_GaryOakReaction, MSGBOX_DEFAULT
    closemessage

	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Frlg_Movement_GaryLeaves
    waitmovement 0

    setflag FLAG_HIDE_CERULEAN_RIVAL
    removeobject LOCALID_CERULEAN_RIVAL

    release
    end



@ ============================================================
@ GARY / FUCHSIA RIDE - BROCK INGREDIENT QUEST
@ ============================================================

CeruleanCity_Frlg_EventScript_GaryFuchsiaRide::
    lockall

    @ Player initiated the conversation with Gary.
    applymovement LOCALID_CERULEAN_RIVAL, Common_Movement_FacePlayer
    waitmovement 0

    msgbox CeruleanCity_Frlg_Text_GaryFuchsiaRecognizesPlayer, MSGBOX_DEFAULT
    closemessage

    @ Player and Gary are north of the counterpart here.
    applymovement LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, Common_Movement_FaceUp
    waitmovement 0

    msgbox CeruleanCity_Frlg_Text_GaryFuchsiaCounterpartArrives, MSGBOX_DEFAULT
    closemessage

    @ Gary and counterpart turn toward one another for the favor argument.
    applymovement LOCALID_CERULEAN_RIVAL, Common_Movement_FaceDown
    applymovement LOCALID_COUNTERPART_CERULEAN_GARY_TOUR, Common_Movement_FaceUp
    waitmovement 0

    msgbox CeruleanCity_Frlg_Text_GaryFuchsiaFavorSetup, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_GaryFuchsiaPlease, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_GaryFuchsiaAgrees, MSGBOX_DEFAULT
    closemessage

    @ Gary has agreed to transport them.
    clearflag FLAG_HIDE_FUCHSIA_GARY
    setvar VAR_BROCK_INGREDIENT_QUEST, 6

    @ Cut directly to Fuchsia.
    warp MAP_FUCHSIA_CITY, 43, 21
    waitstate
    end


CeruleanCity_Frlg_Text_GaryFuchsiaRecognizesPlayer:
    .string "GARY: ...YOU again?\p"
    .string "{PLAYER}: Oh, you've got to be\n"
    .string "kidding me.$"


CeruleanCity_Frlg_Text_GaryFuchsiaCounterpartArrives:
    .string "{RIVAL}: ...You know him?\p"
    .string "GARY: Unfortunately.\p"
    .string "{PLAYER}: Why do YOU know GARY?\p"
    .string "{RIVAL}: Why do YOU know GARY?\p"
    .string "GARY: Wow.\n"
    .string "Good to see both of you too.$"


CeruleanCity_Frlg_Text_GaryFuchsiaFavorSetup:
    .string "{RIVAL}: Whatever.\n"
    .string "We need a favor.\p"
    .string "GARY: No.\p"
    .string "{RIVAL}: I HAVEN'T ASKED YET!\p"
    .string "GARY: You walked all the way\n"
    .string "over here.\p"
    .string "With company.\p"
    .string "And you're being weirdly quiet.\p"
    .string "You want something.\p"
    .string "{RIVAL}: I am NOT being\n"
    .string "weirdly quiet.\p"
    .string "GARY: You haven't insulted me yet.\p"
    .string "{RIVAL}: Your hair looks stupid.\p"
    .string "GARY: There it is.$"


CeruleanCity_Frlg_Text_GaryFuchsiaPlease:
    .string "{RIVAL}: Can you get us to\n"
    .string "FUCHSIA?\p"
    .string "GARY: Sure.\p"
    .string "{RIVAL}: ...Really?\p"
    .string "GARY: If you say please.\p"
    .string "{RIVAL}: I'll walk.\p"
    .string "GARY: It's pretty far.\p"
    .string "{RIVAL}: I'll swim.\p"
    .string "GARY: There are mountains.\p"
    .string "{RIVAL}: I'll die.\p"
    .string "GARY: Before saying please?\p"
    .string "{RIVAL}: Gladly.\p"
    .string "{PLAYER}: I'm starting to\n"
    .string "understand the family dynamic.\p"
    .string "GARY: See? They get it.\p"
    .string "{RIVAL}: Shut up.$"


CeruleanCity_Frlg_Text_GaryFuchsiaAgrees:
    .string "GARY: Fine.\p"
    .string "{RIVAL}: ...Fine what?\p"
    .string "GARY: I'll take you.\p"
    .string "{RIVAL}: Really?\p"
    .string "GARY: Grandpa would never let me\n"
    .string "hear the end of it if I left you\n"
    .string "stranded.\p"
    .string "{RIVAL}: You could've just\n"
    .string "said yes.\p"
    .string "GARY: And miss all that?\p"
    .string "Not a chance.$"


CeruleanCity_Frlg_Text_GaryIntro:
    .string "GARY: Huh?\p"
    .string "I've never seen you around here\n"
    .string "before.\p"
    .string "And trust me...\n"
    .string "I'd remember.$"


CeruleanCity_Frlg_Text_PlayerGaryThought:
    .string "{PLAYER}:...Somehow, this particular flavor\n"
    .string "of arrogance feels familiar.\p"
    .string "...Sigh.$"


CeruleanCity_Frlg_Text_PlayerAskOak:
    .string "{PLAYER}: You remind me of someone.\p"
    .string "Are you an OAK?$"


CeruleanCity_Frlg_Text_GaryOakReaction:
    .string "GARY: ...What?\p"
    .string "How do YOU know that?\p"
    .string "Who even are you?\p"
    .string "{PLAYER}: ...It's complicated.\p"
    .string "GARY: Yeah. Whatever.\p"
    .string "I've got better things to do than\n"
    .string "stand around talking to weirdos.\p"
    .string "Smell ya later!$"

CeruleanCity_Frlg_Movement_GaryLeaves:
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
	walk_down
	walk_down
    walk_down
    step_end

@ ============================================================
@ CERULEAN OVERWORLD NPC CLEANUP
@ ============================================================

CeruleanCity_Frlg_EventScript_LittleBoy::
    lock
    faceplayer
    goto_if_set FLAG_CERULEAN_MISSION_COMPLETE, CeruleanCity_Frlg_EventScript_LittleBoyPostMisty

    msgbox CeruleanCity_Frlg_Text_LittleBoy, MSGBOX_DEFAULT
    release
    end

CeruleanCity_Frlg_EventScript_LittleBoyPostMisty:
    msgbox CeruleanCity_Frlg_Text_LittleBoyPostMisty, MSGBOX_DEFAULT
    release
    end


CeruleanCity_Frlg_EventScript_BaldingMan::
    lock
    faceplayer
    goto_if_set FLAG_CERULEAN_MISSION_COMPLETE, CeruleanCity_Frlg_EventScript_BaldingManPostMisty

    msgbox CeruleanCity_Frlg_Text_BaldingMan, MSGBOX_DEFAULT
    release
    end

CeruleanCity_Frlg_EventScript_BaldingManPostMisty:
    msgbox CeruleanCity_Frlg_Text_BaldingManPostMisty, MSGBOX_DEFAULT
    release
    end


CeruleanCity_Frlg_EventScript_Youngster::
    lock
    faceplayer
    goto_if_set FLAG_CERULEAN_MISSION_COMPLETE, CeruleanCity_Frlg_EventScript_YoungsterPostMisty

    msgbox CeruleanCity_Frlg_Text_Youngster, MSGBOX_DEFAULT
    release
    end

CeruleanCity_Frlg_EventScript_YoungsterPostMisty:
    msgbox CeruleanCity_Frlg_Text_YoungsterPostMisty, MSGBOX_DEFAULT
    release
    end


CeruleanCity_Frlg_EventScript_Woman::
    lock
    faceplayer
    goto_if_set FLAG_CERULEAN_MISSION_COMPLETE, CeruleanCity_Frlg_EventScript_WomanPostMisty

    msgbox CeruleanCity_Frlg_Text_Woman, MSGBOX_DEFAULT
    release
    end

CeruleanCity_Frlg_EventScript_WomanPostMisty:
    msgbox CeruleanCity_Frlg_Text_WomanPostMisty, MSGBOX_DEFAULT
    release
    end


CeruleanCity_Frlg_EventScript_Lass::
    lock
    faceplayer
    goto_if_set FLAG_CERULEAN_MISSION_COMPLETE, CeruleanCity_Frlg_EventScript_LassPostMisty

    msgbox CeruleanCity_Frlg_Text_Lass, MSGBOX_DEFAULT
    release
    end

CeruleanCity_Frlg_EventScript_LassPostMisty:
    msgbox CeruleanCity_Frlg_Text_LassPostMisty, MSGBOX_DEFAULT
    release
    end


CeruleanCity_Frlg_EventScript_Slowbro::
    lock
    faceplayer
    msgbox CeruleanCity_Frlg_Text_Slowbro, MSGBOX_DEFAULT
    release
    end

CeruleanCity_Frlg_EventScript_CaveGuard::
    lock
    faceplayer
    msgbox CeruleanCity_Frlg_Text_CaveGuard, MSGBOX_DEFAULT
    release
    end


CeruleanCity_Frlg_Text_LittleBoy:
    .string "That house up there has been weird\n"
    .string "all day.$"


CeruleanCity_Frlg_Text_BaldingMan:
    .string "People keep saying something strange\n"
    .string "happened near the northern houses.$"


CeruleanCity_Frlg_Text_Youngster:
    .string "CERULEAN'S usually way less weird\n"
    .string "than this.$"


CeruleanCity_Frlg_Text_Woman:
    .string "You look like you're searching for\n"
    .string "someone.\p"
    .string "Good luck.$"


CeruleanCity_Frlg_Text_Lass:
    .string "SLOWBRO and I are just staying out\n"
    .string "of everybody's business.$"


CeruleanCity_Frlg_Text_Slowbro:
    .string "SLOWBRO: ...Brooo.$"


CeruleanCity_Frlg_Text_CaveGuard:
    .string "The cave ahead isn't open to\n"
    .string "visitors right now.$"



@ ============================================================
@ CERULEAN POST-MISTY NPC DIALOGUE
@ ============================================================

CeruleanCity_Frlg_Text_LittleBoyPostMisty:
    .string "Hey! You're back!\p"
    .string "Are you looking for somebody\n"
    .string "again?$"

CeruleanCity_Frlg_Text_BaldingManPostMisty:
    .string "First all that commotion up north,\n"
    .string "and now people are asking questions\l"
    .string "around town again.\p"
    .string "CERULEAN'S had a strange week.$"

CeruleanCity_Frlg_Text_YoungsterPostMisty:
    .string "Wait... I remember you.\p"
    .string "You're the one who was mixed up in\n"
    .string "all that weird stuff before.\p"
    .string "You really came BACK?$"

CeruleanCity_Frlg_Text_WomanPostMisty:
    .string "Searching for someone again?\p"
    .string "If you're asking around town,\n"
    .string "the LIBRARY might know something.$"

CeruleanCity_Frlg_Text_LassPostMisty:
    .string "Whatever you're investigating this\n"
    .string "time, SLOWBRO and I are staying\l"
    .string "out of it too.$"


@ ============================================================
@ CERULEAN EXTERIOR FINALE
@ ============================================================

CeruleanCity_Frlg_EventScript_CeruleanFinale::
    lockall

    goto_if_set FLAG_CERULEAN_MISSION_COMPLETE, CeruleanCity_Frlg_EventScript_CeruleanFinaleEnd
    goto_if_unset FLAG_CERULEAN_LAB_COMPLETE, CeruleanCity_Frlg_EventScript_CeruleanFinaleEnd

    clearflag FLAG_HIDE_CERULEAN_FINALE_DUO

    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
    waitmovement 0

    msgbox CeruleanCity_Frlg_Text_FinaleMistyWhatHappened, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_FinalePlayerExplains, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_FinaleReaction, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_Frlg_Text_FinaleRewardLeadIn, MSGBOX_DEFAULT
    closemessage

    warp MAP_MISTYS_HOUSE, 6, 4
    waitstate

    releaseall
    end


CeruleanCity_Frlg_EventScript_CeruleanFinaleEnd:
    releaseall
    end


CeruleanCity_Frlg_EventScript_FinaleMisty::
    msgbox CeruleanCity_Frlg_Text_FinaleMistyIdle, MSGBOX_NPC
    end


CeruleanCity_Frlg_EventScript_FinaleRoxanne::
    msgbox CeruleanCity_Frlg_Text_FinaleRoxanneIdle, MSGBOX_NPC
    end


CeruleanCity_Frlg_Text_FinaleMistyWhatHappened:
    .string "MISTY: THERE you are!\p"
    .string "What happened in there?$"


CeruleanCity_Frlg_Text_FinalePlayerExplains:
    .string "{PLAYER}: It's... a long story.\p"
    .string "There was a ROCKET GRUNT,\n"
    .string "JAMES, an experiment...\p"
    .string "and they left with a shiny\n"
    .string "MAGIKARP.$"


CeruleanCity_Frlg_Text_FinaleReaction:
    .string "MISTY: ...\p"
    .string "ROXANNE: ...\p"
    .string "MISTY: Yeah, okay.\p"
    .string "There was absolutely no way we\n"
    .string "could've expected that.\p"
    .string "ROXANNE: Agreed.$"


CeruleanCity_Frlg_Text_FinaleRewardLeadIn:
    .string "MISTY: But you handled it.\p"
    .string "ROXANNE: And successfully, from\n"
    .string "the sound of it.\p"
    .string "MISTY: Which means you earned\n"
    .string "your reward.\p"
    .string "Come on. Let's get back.$"


CeruleanCity_Frlg_Text_FinaleMistyIdle:
    .string "MISTY: Let's get back.$"


CeruleanCity_Frlg_Text_FinaleRoxanneIdle:
    .string "ROXANNE: We should return.$"
