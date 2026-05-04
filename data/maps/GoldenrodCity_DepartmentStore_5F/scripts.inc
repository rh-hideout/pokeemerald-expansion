GoldenrodCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_HighFriendship
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, GoldenrodDeptStore5_EventScript_Receptionist_PutInEffort
	goto GoldenrodDeptStore5_EventScript_Receptionist_LowFriendship
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_HighFriendship::
	call_if_unset FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_LowFriendship::
	call_if_unset FLAG_GOT_FRUSTRATION, GoldenrodDeptStore5_EventScript_Receptionist_GiveFrustration
	msgbox GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	return

GoldenrodDeptStore5_EventScript_Receptionist_GiveFrustration::
	giveitem ITEM_TM_FRUSTRATION
	setflag FLAG_GOT_FRUSTRATION
	return

GoldenrodDeptStore5_EventScript_Receptionist_PutInEffort::
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end



GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
    .string "Hello. Oh, your POKéMON…$"

GoldenrodDeptStore_Text_5FReceptionistWait:
    .string "Wait, I already gave you that TM!$"

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "Hmm…\n"
	.string "It's not bad, but it's also not good.\p"
	.string "You, as the TRAINER, need to put in\n"
	.string "some more effort.$"


GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
    .string "It's very attached to you.\p"
    .string "This move should be perfect for a\n"
    .string "pair like you.$"

GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
    .string "It looks evil. How about this TM\n"
    .string "for it?$"

GoldenrodDeptStore_Text_5FReceptionistThereAreTMsPerfectForMon:
    .string "There are sure to be TMs that are\n"
    .string "just perfect for your POKéMON.$"

GoldenrodDeptStore_Text_5FLass:
    .string "During the day, a lady comes to check\n"
    .string "out POKéMON.\p"
    .string "She even gives away TMs!$"

GoldenrodDeptStore_Text_5FPokefanM:
    .string "You can't rename a POKéMON you get\n"
    .string "in a trade.\p"
    .string "The name is a reflection of the\n"
    .string "original trainer's feelings for it.$"

GoldenrodDeptStore_Text_Girl:
	.string "The lady gave me RETURN!\n"
    .string "My POKéMON must really like me!$"

GoldenrodDeptStore_Text_5FDirectory:
    .string "Customize Your POKéMON\p"
    .string "5F TM CORNER$"
