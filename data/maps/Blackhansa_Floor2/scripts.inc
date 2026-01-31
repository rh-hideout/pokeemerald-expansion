Blackhansa_Floor2_MapScripts::
	.byte 0

Blackhansa_Floor2_EventScript_IntruderTrigger::
	@ Wenn schon erfolgreich (Antwort 2), Trigger "verschwindet" effektiv
	goto_if_set FLAG_BLACKHANSA_F2_INTRUDER_DONE, Blackhansa_Floor2_EventScript_IntruderTrigger_End

	lockall
	turnobject LOCALID_PLAYER, DIR_SOUTH

	msgbox Blackhansa_Floor2_Text_StopIntruder, MSGBOX_DEFAULT

	applymovement LOCALID_IT_MANAGER, Blackhansa_Floor2_Movement_ITManager_Approach
	waitmovement 0

	turnobject LOCALID_IT_MANAGER, DIR_NORTH
	turnobject LOCALID_PLAYER, DIR_SOUTH

	msgbox Blackhansa_Floor2_Text_WhoAreYou, MSGBOX_DEFAULT

	@ --- 3 Antworten ohne eigenes Multichoice-List-Setup ---
	@ Wir fragen Antwort 1 als YES/NO, bei NO fragen wir Antwort 2 als YES/NO,
	@ ansonsten ist es Antwort 3.

	msgbox Blackhansa_Floor2_Text_Choice1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Blackhansa_Floor2_EventScript_Answer1

	msgbox Blackhansa_Floor2_Text_Choice2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Blackhansa_Floor2_EventScript_Answer2

	goto Blackhansa_Floor2_EventScript_Answer3


Blackhansa_Floor2_EventScript_Answer1::
	msgbox Blackhansa_Floor2_Text_Answer1_Response, MSGBOX_DEFAULT
	goto Blackhansa_Floor2_EventScript_KickOut


Blackhansa_Floor2_EventScript_Answer3::
	msgbox Blackhansa_Floor2_Text_Answer3_Response, MSGBOX_DEFAULT
	goto Blackhansa_Floor2_EventScript_KickOut


Blackhansa_Floor2_EventScript_KickOut::
	closemessage
	warpteleport MAP_PETALBURG_CITY, 12, 6
	waitstate
	releaseall
	end


Blackhansa_Floor2_EventScript_Answer2::
	msgbox Blackhansa_Floor2_Text_Answer2_Response, MSGBOX_DEFAULT

	applymovement LOCALID_IT_MANAGER, Blackhansa_Floor2_Movement_ITManager_Return
	waitmovement 0

	@ NPC verschwindet (weil Flag in Porymap am Object hängt)
	setflag FLAG_BLACKHANSA_F2_INTRUDER_DONE

	releaseall
	end


Blackhansa_Floor2_EventScript_IntruderTrigger_End::
	end




Blackhansa_Floor2_EventScript_ServerTap::
    lock
    goto_if_set FLAG_BLACKHANSA_SERVER_TAP_DONE, Blackhansa_Floor2_ServerTap_AlreadyDone  @ optional
    msgbox Blackhansa_Floor2_Text_Servers_NoDevice, MSGBOX_DEFAULT

    checkitem ITEM_RASPBERRY_PI
    compare VAR_RESULT, TRUE
    goto_if_eq Blackhansa_Floor2_ServerTap_Success

    release
    end

Blackhansa_Floor2_ServerTap_Success:
	removeitem ITEM_RASPBERRY_PI, 1
    msgbox Blackhansa_Floor2_Text_Servers_Success, MSGBOX_DEFAULT
    setflag FLAG_BLACKHANSA_SERVER_TAP_DONE
    release
    end

Blackhansa_Floor2_ServerTap_AlreadyDone:
    release
    end




@ --------------------
@ Bewegungen
@ --------------------
Blackhansa_Floor2_Movement_ITManager_Approach::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Blackhansa_Floor2_Movement_ITManager_Return::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


@ --------------------
@ Texte
@ --------------------
Blackhansa_Floor2_Text_StopIntruder:
	.string "Stop intruder$"

Blackhansa_Floor2_Text_WhoAreYou:
	.string "Who are you and what are\n"
	.string "you doing here?$"

@ “Antwortmenü” via YES/NO Prompts
Blackhansa_Floor2_Text_Choice1:
	.string "A: I work in IT and have\n"
	.string "to maintain the server.$"

Blackhansa_Floor2_Text_Choice2:
	.string "B: Please can you help me? I am \n"
	.string "looking for a maintenance port.$"

@ Reaktionen
Blackhansa_Floor2_Text_Answer1_Response:
	.string "I'm the IT manager and I don't\n"
	.string "know you. Get out of here!$"

Blackhansa_Floor2_Text_Answer2_Response:
	.string "You'll find them in the room\n"
	.string "in front of you!$"

Blackhansa_Floor2_Text_Answer3_Response:
	.string "That was just cleaned half an hour\n"
	.string "ago, now get lost!$"

Blackhansa_Floor2_Text_Servers_NoDevice:
	.string "These are Blackhansa's servers,\n"
	.string "with all their secrets. If only I\p"
	.string "had something I could connect to\n"
	.string "intercept the data traffic.$"

Blackhansa_Floor2_Text_Servers_Success:
	.string "You connect your Raspberry Pi to\n"
	.string "the server and hide it among all\p"
	.string "the cables. Traffic is now being\n"
	.string "recorded and sent.$"




