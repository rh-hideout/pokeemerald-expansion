GraniteCave_StevensRoom_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, GraniteCave_StevensRoom_SetSiblingGraphics
    .byte 0

GraniteCave_StevensRoom_SetSiblingGraphics:
    @ Dad-raised path -> Xie.
    @ Mom-raised path -> Sol.
    goto_if_set FLAG_HIDE_HOME_MOM, GraniteCave_StevensRoom_SetXieGraphics

    setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SOL
    return

GraniteCave_StevensRoom_SetXieGraphics:
    setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_XIE
    return


GraniteCave_StevensRoom_EventScript_Twin::
        goto_if_set FLAG_GRANITE_CAVE_TWIN_SCENE_DONE, GraniteCave_StevensRoom_EventScript_TwinDone
        goto GraniteCave_StevensRoom_EventScript_TwinScene

GraniteCave_StevensRoom_EventScript_TwinDone::
        end


GraniteCave_StevensRoom_EventScript_TwinScene::
        goto_if_set FLAG_GRANITE_CAVE_TWIN_SCENE_DONE, GraniteCave_StevensRoom_EventScript_TwinDone
        lockall
        goto_if_set FLAG_HIDE_HOME_MOM, GraniteCave_StevensRoom_EventScript_BufferXieName
        bufferstring STR_VAR_1, GraniteCave_StevensRoom_Text_NameSol
        goto GraniteCave_StevensRoom_EventScript_TwinSceneContinue

GraniteCave_StevensRoom_EventScript_BufferXieName:
        bufferstring STR_VAR_1, GraniteCave_StevensRoom_Text_NameXie

GraniteCave_StevensRoom_EventScript_TwinSceneContinue:

        @ Steven and sibling are already arguing with each other.
        applymovement LOCALID_GRANITE_CAVE_STEVEN, Common_Movement_FaceLeft
        waitmovement 0

        call GraniteCave_StevensRoom_EventScript_SiblingFaceSteven

        msgbox GraniteCave_StevensRoom_Text_StevenTwinBackAndForth1, MSGBOX_DEFAULT
        closemessage

        msgbox GraniteCave_StevensRoom_Text_SiblingBackAndForth1, MSGBOX_DEFAULT
        closemessage

        msgbox GraniteCave_StevensRoom_Text_StevenTwinBackAndForth2, MSGBOX_DEFAULT
        closemessage

        msgbox GraniteCave_StevensRoom_Text_SiblingBackAndForth2, MSGBOX_DEFAULT
        closemessage

        @ Casey catches their attention.
        applymovement LOCALID_PLAYER, Common_Movement_FaceDown
        waitmovement 0

        applymovement LOCALID_GRANITE_CAVE_STEVEN, Common_Movement_FaceUp
        waitmovement 0

        call GraniteCave_StevensRoom_EventScript_SiblingFacePlayer

        msgbox GraniteCave_StevensRoom_Text_SiblingInteresting, MSGBOX_DEFAULT
        closemessage

        msgbox GraniteCave_StevensRoom_Text_PlayerWhat, MSGBOX_DEFAULT
        closemessage

        msgbox GraniteCave_StevensRoom_Text_SiblingFlowerShop, MSGBOX_DEFAULT
        closemessage

        msgbox GraniteCave_StevensRoom_Text_SiblingRemindMe, MSGBOX_DEFAULT
        closemessage

        msgbox GraniteCave_StevensRoom_Text_PlayerWho, MSGBOX_DEFAULT
        closemessage

        msgbox GraniteCave_StevensRoom_Text_SiblingGottaBlast, MSGBOX_DEFAULT
        closemessage

        @ Visible Twin leaves.
        call GraniteCave_StevensRoom_EventScript_TwinLeave

        setflag FLAG_GRANITE_CAVE_TWIN_SCENE_DONE

        msgbox GraniteCave_StevensRoom_Text_PlayerWhatWasThat, MSGBOX_DEFAULT
        closemessage

        applymovement LOCALID_GRANITE_CAVE_STEVEN, Common_Movement_FaceUp
        waitmovement 0

        msgbox GraniteCave_StevensRoom_Text_StevenDontAsk, MSGBOX_DEFAULT
        closemessage

        releaseall
        end


@ Which Twin is active follows the same visibility logic already used
@ by the Flower Shop objects.
GraniteCave_StevensRoom_EventScript_SiblingFaceSteven:
    applymovement LOCALID_GRANITE_CAVE_SIBLING, Common_Movement_FaceRight
    waitmovement 0
    return


GraniteCave_StevensRoom_EventScript_SiblingFacePlayer:
    applymovement LOCALID_GRANITE_CAVE_SIBLING, Common_Movement_FaceUp
    waitmovement 0
    return


GraniteCave_StevensRoom_EventScript_TwinLeave:
    applymovement LOCALID_GRANITE_CAVE_SIBLING, GraniteCave_StevensRoom_Movement_TwinLeave
    waitmovement 0
    removeobject LOCALID_GRANITE_CAVE_SIBLING
    return


GraniteCave_StevensRoom_Movement_TwinLeave:
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_right
    walk_right
    step_end


GraniteCave_StevensRoom_Text_NameXie:
        .string "XIE$"

GraniteCave_StevensRoom_Text_NameSol:
        .string "SOL$"

GraniteCave_StevensRoom_Text_StevenTwinBackAndForth1:
        .string "STEVEN: That's not what I said.$"

GraniteCave_StevensRoom_Text_SiblingBackAndForth1:
        .string "{STR_VAR_1}: It's what you meant.$"

GraniteCave_StevensRoom_Text_StevenTwinBackAndForth2:
        .string "STEVEN: You have an interesting habit\n"
        .string "of deciding what other people mean.$"

GraniteCave_StevensRoom_Text_SiblingBackAndForth2:
        .string "{STR_VAR_1}: Saves time.$"

GraniteCave_StevensRoom_Text_SiblingInteresting:
        .string "{STR_VAR_1}: ...\p"
        .string "Interesting.$"

GraniteCave_StevensRoom_Text_PlayerWhat:
        .string "{PLAYER}: What?$"

GraniteCave_StevensRoom_Text_SiblingFlowerShop:
        .string "{STR_VAR_1}: I've seen you before.\p"
        .string "The flower shop.$"

GraniteCave_StevensRoom_Text_SiblingRemindMe:
        .string "{STR_VAR_1}: You remind me of someone.$"

GraniteCave_StevensRoom_Text_PlayerWho:
        .string "{PLAYER}: Who?$"

GraniteCave_StevensRoom_Text_SiblingGottaBlast:
        .string "{STR_VAR_1}: Hm...\p"
        .string "Oh well.\p"
        .string "Gotta blast.$"

GraniteCave_StevensRoom_Text_PlayerWhatWasThat:
        .string "{PLAYER}: ...What?$"

GraniteCave_StevensRoom_Text_StevenDontAsk:
        .string "STEVEN: Don't ask me.$"


GraniteCave_StevensRoom_Text_AfterSiblingScene:
    .string "Well... that was interesting.$"

GraniteCave_StevensRoom_Text_AfterSiblingScene2:
    .string "I get the feeling there's more to\n"
    .string "that person than they're letting on.$"

GraniteCave_StevensRoom_Text_AfterSiblingScene3:
    .string "Anyway... you came all this way to\n"
    .string "see me. Was there something you needed?$"

GraniteCave_StevensRoom_EventScript_Steven::
	lock
GraniteCave_StevensRoom_EventScript_SkipSiblingComment:
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
    msgbox GraniteCave_StevensRoom_Text_StevenNoticesBook, MSGBOX_DEFAULT
    closemessage

    msgbox GraniteCave_StevensRoom_Text_StevenExaminesBook, MSGBOX_DEFAULT
    closemessage

    msgbox GraniteCave_StevensRoom_Text_StevenMentionsKey, MSGBOX_DEFAULT
    closemessage

    msgbox GraniteCave_StevensRoom_Text_StevenStrangeDay, MSGBOX_DEFAULT
    closemessage

    msgbox GraniteCave_StevensRoom_Text_StevenWarning, MSGBOX_DEFAULT
    closemessage

    msgbox GraniteCave_StevensRoom_Text_StevenThingsNotWhatTheySeem, MSGBOX_DEFAULT
    closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	release
	end

GraniteCave_StevensRoom_Text_StevenNoticesBook:
    .string "STEVEN: Wait...\p"
    .string "That book you're carrying.\p"
    .string "May I see it?$"

GraniteCave_StevensRoom_Text_StevenExaminesBook:
    .string "STEVEN: Hm...\p"
    .string "Interesting.\p"
    .string "I've seen markings like these before,\n"
    .string "but never on a book.$"

GraniteCave_StevensRoom_Text_StevenMentionsKey:
    .string "STEVEN: That strange kid who was here\n"
    .string "before you had a key with similar\l"
    .string "markings.$"

GraniteCave_StevensRoom_Text_StevenStrangeDay:
    .string "STEVEN: A strange key, a strange book...\p"
    .string "Today's getting weirder by the minute.$"

GraniteCave_StevensRoom_Text_StevenWarning:
    .string "STEVEN: {PLAYER}, I'd be careful with\n"
    .string "this.\p"
    .string "There are people looking for objects\n"
    .string "like this.\p"
    .string "And not everyone looking for them has\n"
    .string "good intentions.$"

GraniteCave_StevensRoom_Text_StevenThingsNotWhatTheySeem:
    .string "STEVEN: Things aren't always what they\n"
    .string "seem.\p"
    .string "Keep it close.$"


GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "My name is STEVEN.\p"
	.string "I'm interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Oh?\n"
	.string "A LETTER for me?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "STEVEN: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains my favorite move,\n"
	.string "STEEL WING.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "STEVEN: Your POKéMON appear quite\n"
	.string "capable.\p"
	.string "If you keep training, you could even\n"
	.string "become the CHAMPION of the POKéMON\l"
	.string "LEAGUE one day. That's what I think.\p"
	.string "I know, since we've gotten to know each\n"
	.string "other, let's register one another in\l"
	.string "our POKéNAVS.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Registered STEVEN\n"
	.string "in the POKéNAV.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Now, I've got to hurry along.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Oh, your BAG is full…\n"
	.string "That's too bad, then.$"

