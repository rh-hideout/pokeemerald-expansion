Gate_GoldenrodCity_Route35_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "Excuse me, kid! Can you do a guy\n"
	.string "a favor?\p"
	.string "Can you take this POKéMON with MAIL\n"
	.string "to my friend?\p"
	.string "He's on ROUTE 31.$"

Route35GoldenrodGate_Text_RandyThanks:
	.string "You will? Perfect! Thanks, kid!\p"
	.string "My pal's a chubby guy who snoozes\n"
	.string "all the time.\p"
	.string "You'll recognize him right away!$"

Route35GoldenrodGate_Text_ReceivedMonWithMail:
	.string "{PLAYER} received a POKéMON with MAIL.$"

Route35GoldenrodGate_Text_RandyWeirdTree:
	.string "Make sure to put it at the front of\n"
	.string "your team when you find my friend!\p"
	.string "ROUTE 31!\p"
	.string "Oh, yeah. There was a weird tree\n"
	.string "blocking the road.\p"
	.string "I wonder if it's been cleared?$"

Route35GoldenrodGate_Text_CantCarryMoreMon:
	.string "You can't carry another POKéMON…$"

Route35GoldenrodGate_Text_RandyNeverMind:
	.string "Oh… Never mind, then…$"

Route35GoldenrodGate_Text_ThanksForDelivery:
	.string "Thanks, kid! You made the delivery\n"
	.string "for me!\p"
	.string "Here's something for your trouble!$"

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
	.string "My pal was snoozing, right? Heh,\n"
	.string "what'd I say?$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "A strange tree is blocking the road.\p"
	.string "It wriggles around if you talk to it.\p"
	.string "I heard it became wild when someone\n"
	.string "watered it with a SQUIRTBOTTLE.$"

Route35GoldenrodGate_Text_PokefanF_Lullaby:
	.string "I like the POKéMON Lullaby they play\n"
	.string "on the radio.$"

Route35GoldenrodGate_Text_Fisher:
	.string "I wonder how many kinds of POKéMON\n"
	.string "there are in the world.\p"
	.string "Three years ago, PROF.OAK said that\n"
	.string "there were 150 different kinds.\p"
	.string "But recently I heard there's\n"
	.string "over 400!$"
