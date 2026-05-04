PalletTown_Lab_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_PALLETTOWN_LABSTATE, 2
	release
	end

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "How is your POKéDEX coming?$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "OAK: Ah, {PLAYER}!\n"
	.string "It's good of you to come all this\l"
	.string "way to KANTO.\p"
	.string "What do you think of the trainers\n"
	.string "out here? Pretty tough, huh?$"

PalletTown_Lab_Text_OakLabGoodbye:
	.string "If you're in the area, I hope you\n"
	.string "come visit again.$"

PalletTown_Lab_Text_OakOpenMtSilver:
	.string "OAK: Wow! That's excellent!\p"
	.string "You collected the BADGES of GYMS\n"
	.string "in KANTO. Well done!\p"
	.string "I was right in my assessment of\n"
	.string "you.\p"
	.string "Tell you what, {PLAYER}. I'll make\n"
	.string "arrangements so that you can go\l"
	.string "to MT.SILVER.\p"
	.string "MT.SILVER is a big mountain that\n"
	.string "is home to many wild POKéMON.\p"
	.string "It's too dangerous for your average\n"
	.string "trainer, so it's off limits. But\l"
	.string "we can make an exception in your\l"
	.string "case, {PLAYER}.\p"
	.string "Go up to INDIGO PLATEAU. You can\n"
	.string "reach MT.SILVER from there.$"

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "OAK: Hmm? You're not collecting\n"
	.string "KANTO GYM BADGES?\p"
	.string "The GYM LEADERS in KANTO are as\n"
	.string "tough as any you battled in JOHTO.\p"
	.string "I recommend that you challenge them.$"

PalletTown_Lab_Text_OakYesKantoBadges:
	.string "OAK: Ah, you're collecting KANTO\n"
	.string "GYM BADGES.\p"
	.string "I imagine that it's hard, but the\n"
	.string "experience is sure to help you.\p"
	.string "Come see me when you get them all.\p"
	.string "I'll have a gift for you.\p"
	.string "Keep trying hard, {PLAYER}!$"

PalletTown_Lab_Text_OaksAssistant1:
	.string "The PROF's POKéMON TALK radio\n"
	.string "program isn't aired here in KANTO.\p"
	.string "It's a shame--I'd like to hear it.$"

PalletTown_Lab_Text_OaksAssistant2:
	.string "Thanks to your work on the POKéDEX,\n"
	.string "the PROF's research is coming along\l"
	.string "great.$"

PalletTown_Lab_Text_OaksAssistant3:
	.string "Don't tell anyone, but PROF.OAK'S\n"
	.string "POKéMON TALK isn't a live broadcast.$"

PalletTown_Lab_Text_OaksLabPC:
	.string "There's an e-mail message on the PC.\p"
	.string "…\p"
	.string "PROF.OAK, how is your research\n"
	.string "coming along?\p"
	.string "I'm still plugging away.\p"
	.string "I heard rumors that {PLAYER} is\n"
	.string "getting quite a reputation.\p"
	.string "I'm delighted to hear that.\p"
	.string "ELM in NEW BARK TOWN 8-)$"
