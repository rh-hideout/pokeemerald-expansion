# 1 "data/maps/MtPyre_1F/scripts.pory"

# 2 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_MapScripts::
# 3 "data/maps/MtPyre_1F/scripts.pory"
	.byte 0
# 4 "data/maps/MtPyre_1F/scripts.pory"

# 5 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_EventScript_CleanseTagWoman::
# 6 "data/maps/MtPyre_1F/scripts.pory"
	lock
# 7 "data/maps/MtPyre_1F/scripts.pory"
	faceplayer
# 8 "data/maps/MtPyre_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
# 9 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
# 10 "data/maps/MtPyre_1F/scripts.pory"
	giveitem ITEM_CLEANSE_TAG
# 11 "data/maps/MtPyre_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 12 "data/maps/MtPyre_1F/scripts.pory"
	setflag FLAG_RECEIVED_CLEANSE_TAG
# 13 "data/maps/MtPyre_1F/scripts.pory"
	release
# 14 "data/maps/MtPyre_1F/scripts.pory"
	end
# 15 "data/maps/MtPyre_1F/scripts.pory"

# 16 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_EventScript_ReceivedCleanseTag::
# 17 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
# 18 "data/maps/MtPyre_1F/scripts.pory"
	release
# 19 "data/maps/MtPyre_1F/scripts.pory"
	end
# 20 "data/maps/MtPyre_1F/scripts.pory"

# 21 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_EventScript_PokefanF::
# 22 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
# 23 "data/maps/MtPyre_1F/scripts.pory"
	end
# 24 "data/maps/MtPyre_1F/scripts.pory"

# 25 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_EventScript_Man::
# 26 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
# 27 "data/maps/MtPyre_1F/scripts.pory"
	end
# 28 "data/maps/MtPyre_1F/scripts.pory"

# 29 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_Text_TakeThisForYourOwnGood:
# 30 "data/maps/MtPyre_1F/scripts.pory"
	.string "All sorts of beings wander the slopes\n"
# 31 "data/maps/MtPyre_1F/scripts.pory"
	.string "of MT. PYRE…\p"
# 32 "data/maps/MtPyre_1F/scripts.pory"
	.string "There is no telling what may happen.\n"
# 33 "data/maps/MtPyre_1F/scripts.pory"
	.string "Take this. It's for your own good.$"
# 34 "data/maps/MtPyre_1F/scripts.pory"

# 35 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_Text_ExplainCleanseTag:
# 36 "data/maps/MtPyre_1F/scripts.pory"
	.string "Have a POKéMON hold that\n"
# 37 "data/maps/MtPyre_1F/scripts.pory"
	.string "CLEANSE TAG.\p"
# 38 "data/maps/MtPyre_1F/scripts.pory"
	.string "It will help ward off wild POKéMON.$"
# 39 "data/maps/MtPyre_1F/scripts.pory"

# 40 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_Text_ComeToPayRespects:
# 41 "data/maps/MtPyre_1F/scripts.pory"
	.string "Did you come to pay your respect\n"
# 42 "data/maps/MtPyre_1F/scripts.pory"
	.string "to the spirits of departed POKéMON?\p"
# 43 "data/maps/MtPyre_1F/scripts.pory"
	.string "You must care for your POKéMON a lot.$"
# 44 "data/maps/MtPyre_1F/scripts.pory"

# 45 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_Text_RestingPlaceOfZigzagoon:
# 46 "data/maps/MtPyre_1F/scripts.pory"
	.string "This is the final resting place of my\n"
# 47 "data/maps/MtPyre_1F/scripts.pory"
	.string "ZIGZAGOON. I cherished it…$"
