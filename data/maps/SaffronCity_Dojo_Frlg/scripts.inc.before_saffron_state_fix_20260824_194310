SaffronCity_Dojo_Frlg_MapScripts::
        .byte 0


@ =============================================================================
@ THE TWELVE MONTHS — FIXED MEMORY
@
@ Casey is present physically on the map but is NOT perceived by anyone.
@ The council members only respond to one another.
@ =============================================================================

SaffronCity_Dojo_Frlg_EventScript_TwelveMeeting::
        lockall

        delay 20

        msgbox SaffronCity_Dojo_Frlg_Text_VoicesEcho, MSGBOX_DEFAULT
        closemessage

        @ Blaine has the floor.
        applymovement LOCALID_SAFFRON_DOJO_BLAINE, Common_Movement_WalkInPlaceFasterDown
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_BlaineWastingTime, MSGBOX_DEFAULT
        closemessage

        @ Lorelei addresses Blaine.
        applymovement LOCALID_SAFFRON_DOJO_LORELEI, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_LoreleiFallWinter, MSGBOX_DEFAULT
        closemessage

        @ Erika answers Lorelei from across the room.
        applymovement LOCALID_SAFFRON_DOJO_LORELEI, Common_Movement_WalkInPlaceFasterRight
        applymovement LOCALID_SAFFRON_DOJO_ERIKA, Common_Movement_WalkInPlaceFasterLeft
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_ErikaSixMonths, MSGBOX_DEFAULT
        closemessage

        @ Tia speaks toward the center.
        applymovement LOCALID_SAFFRON_DOJO_MOM, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_TiaNotMonths, MSGBOX_DEFAULT
        closemessage

        @ Elias turns toward Tia.
        applymovement LOCALID_SAFFRON_DOJO_NORMAN, Common_Movement_WalkInPlaceFasterLeft
        applymovement LOCALID_SAFFRON_DOJO_MOM, Common_Movement_WalkInPlaceFasterRight
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_EliasSixDays, MSGBOX_DEFAULT
        closemessage

        @ Blaine answers the room.
        applymovement LOCALID_SAFFRON_DOJO_BLAINE, Common_Movement_WalkInPlaceFasterDown
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_BlaineSeven, MSGBOX_DEFAULT
        closemessage

        @ Lorelei turns toward Blaine again.
        applymovement LOCALID_SAFFRON_DOJO_LORELEI, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_LoreleiOrder, MSGBOX_DEFAULT
        closemessage

        @ Erika faces inward to address the council generally.
        applymovement LOCALID_SAFFRON_DOJO_ERIKA, Common_Movement_WalkInPlaceFasterLeft
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_ErikaBalance, MSGBOX_DEFAULT
        closemessage

        @ Blaine responds.
        msgbox SaffronCity_Dojo_Frlg_Text_BlaineNewOrder, MSGBOX_DEFAULT
        closemessage

        @ Tia and Elias react to one another.
        applymovement LOCALID_SAFFRON_DOJO_MOM, Common_Movement_WalkInPlaceFasterRight
        applymovement LOCALID_SAFFRON_DOJO_NORMAN, Common_Movement_WalkInPlaceFasterLeft
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_TiaConsequence, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Dojo_Frlg_Text_EliasTooLate, MSGBOX_DEFAULT
        closemessage

        @ Erika closes the practical discussion.
        applymovement LOCALID_SAFFRON_DOJO_ERIKA, Common_Movement_WalkInPlaceFasterLeft
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_ErikaReconvene, MSGBOX_DEFAULT
        closemessage

        @ Lorelei looks across toward Erika.
        applymovement LOCALID_SAFFRON_DOJO_LORELEI, Common_Movement_WalkInPlaceFasterRight
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_LoreleiIfAnythingLeft, MSGBOX_DEFAULT
        closemessage

        @ Blaine cuts across the room.
        applymovement LOCALID_SAFFRON_DOJO_BLAINE, Common_Movement_WalkInPlaceFasterDown
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_BlaineEnough, MSGBOX_DEFAULT
        closemessage

        @ Elias answers the room.
        applymovement LOCALID_SAFFRON_DOJO_NORMAN, Common_Movement_WalkInPlaceFasterUp
        waitmovement 0

        msgbox SaffronCity_Dojo_Frlg_Text_EliasForNow, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_Dojo_Frlg_Text_BlaineAdjourned, MSGBOX_DEFAULT
        closemessage

        @ Fixed memory ends.
        setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 5

        fadescreen FADE_TO_BLACK
        delay 30

        @ Place Casey just outside the Dojo in explorable historical Saffron.
        warp MAP_SAFFRON_CITY, 40, 13

        waitstate
        end


@ =============================================================================
@ DIALOGUE
@ =============================================================================

SaffronCity_Dojo_Frlg_Text_VoicesEcho:
        .string "Voices echo through the room...$"


SaffronCity_Dojo_Frlg_Text_BlaineWastingTime:
        .string "BLAINE: We're wasting time.\p"
        .string "The fracture has already begun.$"


SaffronCity_Dojo_Frlg_Text_LoreleiFallWinter:
        .string "LORELEI: Fall and Winter have\n"
        .string "withdrawn together.$"


SaffronCity_Dojo_Frlg_Text_ErikaSixMonths:
        .string "ERIKA: Six Months.\p"
        .string "Half the cycle.$"


SaffronCity_Dojo_Frlg_Text_TiaNotMonths:
        .string "TIA: They're not calling themselves\n"
        .string "Months anymore.$"


SaffronCity_Dojo_Frlg_Text_EliasSixDays:
        .string "ELIAS: Six Days.$"


SaffronCity_Dojo_Frlg_Text_BlaineSeven:
        .string "BLAINE: There are seven.$"


SaffronCity_Dojo_Frlg_Text_LoreleiOrder:
        .string "LORELEI: Twelve Months.\p"
        .string "Four Seasons.\p"
        .string "Three to each.\p"
        .string "That was the order.$"


SaffronCity_Dojo_Frlg_Text_ErikaBalance:
        .string "ERIKA: Not control.\p"
        .string "Balance.$"


SaffronCity_Dojo_Frlg_Text_BlaineNewOrder:
        .string "BLAINE: And now six believe they\n"
        .string "can create an order of their own.$"


SaffronCity_Dojo_Frlg_Text_TiaConsequence:
        .string "TIA: Whether they can and whether\n"
        .string "they should are different questions.$"


SaffronCity_Dojo_Frlg_Text_EliasTooLate:
        .string "ELIAS: That distinction may already\n"
        .string "be too late to matter.$"


SaffronCity_Dojo_Frlg_Text_ErikaReconvene:
        .string "ERIKA: Then we reconvene when we\n"
        .string "know more.$"


SaffronCity_Dojo_Frlg_Text_LoreleiIfAnythingLeft:
        .string "LORELEI: If there's anything left\n"
        .string "to reconvene.$"


SaffronCity_Dojo_Frlg_Text_BlaineEnough:
        .string "BLAINE: Enough.$"


SaffronCity_Dojo_Frlg_Text_EliasForNow:
        .string "ELIAS: For now.$"


SaffronCity_Dojo_Frlg_Text_BlaineAdjourned:
        .string "BLAINE: Meeting adjourned.$"
