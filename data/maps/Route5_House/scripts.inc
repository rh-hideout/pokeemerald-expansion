Route5_House_MapScripts::
	.byte 0

Route5_House_EventScript_Granny::
	goto_if_set FLAG_GOT_CLEANSE_TAG, Route5_House_EventScript_GrannyAfter
	msgbox Route5_House_Text_Granny1, MSGBOX_NPC
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_CLEANSE_TAG
	release
	end

Route5_House_EventScript_GrannyAfter::
	msgbox Route5_House_Text_Granny2, MSGBOX_NPC
	end

Route5_House_EventScript_Woman::
	msgbox Route5_House_Text_Woman, MSGBOX_NPC
	end

Route5_House_Text_Granny1:
	.string "Eeyaaaah!\p"
	.string "I sense a sinister shadow\n"
	.string "hovering over you.\l"
	.string "Take this to ward it off!$"

Route5_House_Text_Granny2:
	.string "You were in mortal danger, but\n"
	.string "you're protected now.$"

Route5_House_Text_Woman:
	.string "My grandma is into warding off what\n"
	.string "she believes to be evil spirits.\p"
	.string "I'm sorry that she startled you.$"
