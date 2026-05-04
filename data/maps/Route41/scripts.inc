Route41_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "The water's warm here.\n"
	.string "I'm loose and limber.\p"
	.string "Sure, I'll take you on!$"

Route41_Text_SwimmermCharlieBeaten:
	.string "Yikes! I've got prune skin!$"

Route41_Text_SwimmermCharlieAfter:
	.string "Isn't it relaxing just floating\n"
	.string "like this?$"

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "I'm a bit tired.\n"
	.string "If I win, lend me your POKéMON.$"

Route41_Text_SwimmermGeorgeBeaten:
	.string "Pant, pant…$"

Route41_Text_SwimmermGeorgeAfter:
	.string "It's so far to CIANWOOD.\p"
	.string "But it's no easy return trip\n"
	.string "to OLIVINE either.\p"
	.string "What should I do?$"

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "See those islands that are\n"
	.string "blocked by whirlpools?\p"
	.string "There just has to be a secret!$"

Route41_Text_SwimmermBerkeBeaten:
	.string "What's the secret to your\n"
	.string "strength?$"

Route41_Text_SwimmermBerkeAfter:
	.string "It was a dark and stormy night…\p"
	.string "I saw this giant POKéMON flying\n"
	.string "from the islands.\p"
	.string "It was scattering feathers\n"
	.string "from its silver wings.$"

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "The waves are wild here.\p"
	.string "They tire you out while\n"
	.string "you swim.$"

Route41_Text_SwimmermKirkBeaten:
	.string "I'm beat!$"

Route41_Text_SwimmermKirkAfter:
	.string "The currents keep me from\n"
	.string "reaching that island.$"

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "Are you seeking the secrets\n"
	.string "of WHIRL ISLANDS?$"

Route41_Text_SwimmermMathewBeaten:
	.string "Ooh, you've got great endurance!$"

Route41_Text_SwimmermMathewAfter:
	.string "A secret about WHIRL ISLANDS…\p"
	.string "It's pitch-black inside!$"

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "I'm on my way to WHIRL ISLANDS.\p"
	.string "I'm going exploring with friends.$"

Route41_Text_SwimmerfKayleeBeaten:
	.string "Is that how you do it?$"

Route41_Text_SwimmerfKayleeAfter:
	.string "There's supposed to be a big\n"
	.string "POKéMON deep beneath WHIRL ISLANDS.\p"
	.string "I wonder what it could be?$"

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "You look so elegant,\n"
	.string "riding your POKéMON.$"

Route41_Text_SwimmerfSusieBeaten:
	.string "I'm crushed…$"

Route41_Text_SwimmerfSusieAfter:
	.string "Wasn't there a hit song about\n"
	.string "a boy riding a LAPRAS?$"

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "The weather is so beautiful,\n"
	.string "I'm in a daze!$"

Route41_Text_SwimmerfDeniseBeaten:
	.string "Ohhh!$"

Route41_Text_SwimmerfDeniseAfter:
	.string "A sunburn is the worst for skin.\p"
	.string "But I don't use a sunblock.\p"
	.string "I won't pollute the water.$"

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "If you need to rest,\n"
	.string "just tread water.\p"
	.string "You'll get your wind back,\n"
	.string "so you can keep on going strong.$"

Route41_Text_SwimmerfKaraBeaten:
	.string "Oh! You have more energy than I do.$"

Route41_Text_SwimmerfKaraAfter:
	.string "I heard roars from deep inside\n"
	.string "the ISLANDS.$"

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "At night, STARYU gather near\n"
	.string "the water's surface.$"

Route41_Text_SwimmerfWendyBeaten:
	.string "Oh, dear…$"

Route41_Text_SwimmerfWendyAfter:
	.string "The clusters of STARYU light up\n"
	.string "at the same time.\p"
	.string "It's so beautiful, it's scary.$"

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "TENTACRUEL: Cruooo...$"

Route41_Text_TentacruelAttack:
	.string "TENTACRUEL: CRUOOOOOO!$"

Route41_Text_TentacruelHeal:
	.string "The TENTACRUEL used RECOVER!\n"
	.string "It is fully healed!$"
