Route25_BillsHouse_MapScripts::
	.byte 0


@VAR_BILLS_GRANDPA

Route25_BillsHouse_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_BILLS_GRANDPA, 1, Route25_BillsHouse_EventScript_Gramps_Spinda
	goto_if_eq VAR_BILLS_GRANDPA, 2, Route25_BillsHouse_EventScript_Gramps_Roselia
	goto_if_eq VAR_BILLS_GRANDPA, 3, Route25_BillsHouse_EventScript_Gramps_Lotad
	goto_if_eq VAR_BILLS_GRANDPA, 4, Route25_BillsHouse_EventScript_Gramps_Growlithe
	goto_if_eq VAR_BILLS_GRANDPA, 5, Route25_BillsHouse_EventScript_Gramps_Pichu
	goto_if_eq VAR_BILLS_GRANDPA, 6, Route25_BillsHouse_EventScript_Gramps_ShownAll
	msgbox Route25_BillsHouse_Text_GrandpaIntro, MSGBOX_DEFAULT
	setvar VAR_BILLS_GRANDPA, 1
	goto Route25_BillsHouse_EventScript_Gramps_Spinda

Route25_BillsHouse_EventScript_Gramps_Declined::
	msgbox Route25_BillsHouse_Text_YouDontHaveIt, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_WrongMon::
	msgbox Route25_BillsHouse_Text_WrongPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_Spinda::
	msgbox Route25_BillsHouse_Text_Spinda, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	@ Store selected slot in VAR_0x800A
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	@ Get the species of the selected Pokémon
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	@ Check if it's Spinda
	goto_if_ne VAR_RESULT, SPECIES_SPINDA, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_SPINDA
	setvar VAR_TEMP_0, ITEM_EVERSTONE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Roselia::
	msgbox Route25_BillsHouse_Text_Roselia, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_ROSELIA, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_ROSELIA
	setvar VAR_TEMP_0, ITEM_LEAF_STONE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Lotad::
	msgbox Route25_BillsHouse_Text_Lotad, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_LOTAD, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_LOTAD
	setvar VAR_TEMP_0, ITEM_DEEP_SEA_TOOTH
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Growlithe::
	msgbox Route25_BillsHouse_Text_Growlithe, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_GROWLITHE, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
	setvar VAR_TEMP_0, ITEM_SUN_STONE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Pichu::
	msgbox Route25_BillsHouse_Text_Pichu, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_PICHU, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_PICHU
	setvar VAR_TEMP_0, ITEM_DEEP_SEA_SCALE
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_ShownAll::
	msgbox Route25_BillsHouse_Text_ShownAll, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_Correctmon::
	msgbox Route25_BillsHouse_Text_ShownPokemon, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_Appreciation, MSGBOX_DEFAULT
	giveitem VAR_TEMP_0
	call_if_eq VAR_TEMP_0, ITEM_LEAF_STONE, Route25_BillsHouse_EventScript_Gramps_ExtraLeafStones
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route25_BillsHouse_Text_ComeAgain, MSGBOX_DEFAULT
	addvar VAR_BILLS_GRANDPA, 1
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_ExtraLeafStones::
	additem VAR_TEMP_0
	additem VAR_TEMP_0
	return

Route25_BillsHouse_Test::
	givemon SPECIES_SPINDA, 10
	givemon SPECIES_LOTAD, 10
	givemon SPECIES_ROSELIA, 10
	givemon SPECIES_GROWLITHE, 10
	givemon SPECIES_PICHU, 10
	end

Route25_BillsHouse_Text_GrandpaIntro:
	.string "Hm? You know BILL? He's my\n"
	.string "grandson.\p"
	.string "He's in JOHTO. He does\n"
	.string "something with PCs, so I'm\l"
	.string "housesitting.$"

Route25_BillsHouse_Text_Spinda:
	.string "My grandson BILL told me about\n"
	.string "a POKéMON that is covered in\l"
	.string "a random pattern.$"

Route25_BillsHouse_Text_Roselia:
	.string "Ah, my grandson mentioned a\n"
	.string "green POKéMON that has flowers\l"
	.string "growing from its wrists.$"

Route25_BillsHouse_Text_Lotad:
	.string "Do you know of a water POKéMON\n"
	.string "that has a big lily pad on\l"
	.string "its head?"
	.string "I heard there are some at the\n"
	.string "FUCHSIA SAFARI ZONE.\p"
	.string "I would surely like to see it.$"

Route25_BillsHouse_Text_Growlithe:
	.string "BILL told me about a POKéMON\n"
	.string "that is\l"
	.string "very loyal to its trainer.\p"
	.string "It's supposed to ROAR well.$"

Route25_BillsHouse_Text_Pichu:
	.string "Do you know that hugely popular\n"
	.string "POKéMON?\p"
	.string "The POKéMON that has a yellow\n"
	.string "body and red cheeks.\p"
	.string "I would love to see what it\n"
	.string "looks like before it evolves$"

Route25_BillsHouse_Text_AskToSeeMon:
	.string "If you have that POKéMON, may I\n"
	.string "see it, please?$"

Route25_BillsHouse_Text_ExcitedToSee:
	.string "You will show me? How good of\n"
	.string "you!$"

Route25_BillsHouse_Text_YouDontHaveIt:
	.string "You don't have it?\n"
	.string "That's too bad…$"

Route25_BillsHouse_Text_ShownPokemon:
	.string "Ah, so that is {STR_VAR_1}?\p"
	.string "Isn't it cute! That's so kind\n"
	.string "of you.$"

Route25_BillsHouse_Text_Appreciation:
	.string "Thanks!\p"
	.string "This is a token of my\n"
	.string "appreciation.$"

Route25_BillsHouse_Text_ComeAgain:
	.string "Come visit again sometime.$"

Route25_BillsHouse_Text_ShownAll:
	.string "Thanks for showing me so many\n"
	.string "cute POKéMON.\p"
	.string "I really enjoyed myself. I'm\n"
	.string "glad\l"
	.string "I've lived such a long life.$"

Route25_BillsHouse_Text_WrongPokemon:
	.string "Hm?\p"
	.string "That's not the POKéMON that I\n"
	.string "was told about.$"


