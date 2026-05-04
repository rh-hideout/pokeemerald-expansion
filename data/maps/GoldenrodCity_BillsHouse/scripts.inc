GoldenrodCity_BillsHouse_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed

    

	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
    .string "BILL: Hi, {PLAYER}! Do us a favor and\n"
    .string "take this EEVEE.\p"
    .string "It was left in our care while\n"
    .string "I was away working on my system.\p"
    .string "Someone has to take care of it,\n"
    .string "but I don't like being outside.\p"
    .string "Can I count on you to play with it,\n"
    .string "{PLAYER}?$"

BillHouse_Text_CountingOnYou:
    .string "BILL: I knew you'd come through!\p"
    .string "Way to go! You're the real deal!\p"
    .string "OK, I'm counting on you.\p"
    .string "Take good care of it!$"

BillHouse_Text_ReceivedEevee:
    .string "{PLAYER} received EEVEE!$"

BillHouse_Text_EeveeMayEvolve:
    .string "BILL: PROF.ELM claims EEVEE may\n"
    .string "evolve in new and unknown ways.$"

BillHouse_Text_PartyFull:
    .string "Whoa, wait. You can't carry any\n"
    .string "more POKéMON.$"

BillHouse_Text_NoEevee:
    .string "Oh… Now what to do?$"

BillHouse_Text_PopWontWork:
    .string "BILL: My pop, he won't work. All he\n"
    .string "does is goof off all day long.\p"
    .string "He's getting to be a real headache…$"

BillHouse_Text_MomBeforeEcruteak:
    .string "Oh, you collect POKéMON? My son\n"
    .string "BILL is an expert.\p"
    .string "He just got called to the POKéMON\n"
    .string "CENTER in ECRUTEAK CITY.\p"
    .string "My husband went off to the GAME\n"
    .string "CORNER without being called…$"

BillHouse_Text_MomAfterEcruteak:
    .string "My husband was once known as a\n"
    .string "POKéMANIAC.\p"
    .string "BILL must have taken after his\n"
    .string "father.$"

BillHouse_Text_SisterUsefulNumber:
    .string "Are you a TRAINER?\p"
    .string "I've got a useful phone number\n"
    .string "for you.$"

BillHouse_Text_RecordedBillsNumber:
    .string "{PLAYER} recorded BILL's number.$"

BillHouse_Text_SisterRefusedNumber:
    .string "My brother made the PC POKéMON\n"
    .string "storage system.\p"
    .string "I was going to give you BILL's\n"
    .string "number…$"

BillHouse_Text_SisterPhoneFull:
    .string "You can't record any more numbers.$"

BillHouse_Text_SisterStorageSystem:
    .string "My big brother BILL made the PC\n"
    .string "POKéMON storage system.$"
