SaffronCity_Tunnel_NS_hns_MapScripts::
	.byte 0

SaffronCity_Tunnel_NS_EventScript_BaldingMan::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION, SaffronCity_Tunnel_NS_EventScript_BaldingManAfter
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManIntro, MSGBOX_DEFAULT
	checkitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_Tunnel_NS_EventScript_BaldingManDetected
	closemessage
	release
	end

SaffronCity_Tunnel_NS_EventScript_BaldingManDetected::
	playse SE_PIN
	applymovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE, Common_Movement_ExclamationMark
	delay 60
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected, MSGBOX_DEFAULT
	removeitem ITEM_RAGE_CANDY_BAR
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar, MSGBOX_DEFAULT
	giveitem ITEM_TM_EXPLOSION
	setflag FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION
SaffronCity_Tunnel_NS_EventScript_BaldingManAfter::
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveTm, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Tunnel_NS_Text_BaldingManIntro:
	.string "Don't be afraid, I'm not a bad\n"
	.string "person.\p"
	.string "A place like this...\n"
	.string "attracts mean people.\p"
	.string "They would eventually cause\n"
	.string "trouble...\p"
	.string "It makes me mad just thinking about\n"
	.string "it.$"

SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected:
	.string "Aha!\n"
	.string "That's a RAGE CANDYBAR!\p"
	.string "Can I have it?\n"
	.string "Please!$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar:
	.string "{PLAYER} Gave the RageCandyBar to the\n"
	.string "guy at the underground path.\p"
	.string "Munch!\p"
	.string "How upsetting!\p"
	.string "But this is so good!\p"
	.string "Munch munch!\p"
	.string "Aargh! It makes me mad!\p"
	.string "Munch munch!\p"
	.string "Aargh...\p"
	.string "...................Phew!\p"
	.string "I am feeling much better!\n"
	.string "Thank you for your candy!\l"
	.string "I want you to have this!$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveTm:
	.string "TM 64 contains........\p"
	.string "tick-\n"
	.string "            tock\l"
	.string "tick-\l"
	.string "            tock\l"
	.string "tick-\l"
	.string "            tock\l"
	.string "tick-\l"
	.string "            tock\l"
	.string "tick.....\l"
	.string "......................\l"
	.string "......................\l"
	.string "KA-BOOM!!!$"	

