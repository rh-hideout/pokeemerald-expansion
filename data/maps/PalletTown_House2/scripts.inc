PalletTown_House2_MapScripts::
	.byte 0

PalletTown_House2_EventScript_Daisy::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_CINNABAR_BLUE, PalletTown_House2_EventScript_Blue
	goto_if_unset FLAG_DAILY_DAISY_GROOMED, PalletTown_House2_EventScript_DaisyGrooming
	msgbox PalletTown_House2_Text_AlreadyGroomed, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_Blue::
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyDeclineGrooming::
	msgbox PalletTown_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end
PalletTown_House2_EventScript_Egg::
	msgbox PalletTown_House2_Text_CantGroomEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyGrooming::
	msgbox PalletTown_House2_Text_OfferGrooming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	msgbox PalletTown_House2_Text_WhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_House2_EventScript_Egg
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	
	msgbox PalletTown_House2_Text_Alright
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_House2_Text_AllDone
	setflag FLAG_DAILY_DAISY_GROOMED
	release
	end

PalletTown_House2_Text_Hello:
	.string "DAISY: Hi! My kid brother is the\n"
	.string "GYM LEADER in VIRIDIAN CITY.\p"
	.string "But he goes out of town so\n"
	.string "often, it causes problems for\l"
	.string "the trainers.$"

PalletTown_House2_Text_OfferGrooming:
	.string "DAISY: Hi! Good timing. I'm about\n"
	.string "to have some tea.\p"
	.string "Would you like to join me?\p"
	.string "Oh, your POKéMON are a bit dirty.\p"
	.string "Would you like me to groom one?$"

PalletTown_House2_Text_WhichMon:
	.string "DAISY: Which one should I groom?$"

PalletTown_House2_Text_Alright:
	.string "DAISY: OK, I'll get it looking\n"
	.string "nice in no time.$"

PalletTown_House2_Text_AllDone:
	.string "DAISY: There you go! All done.\p"
	.string "See? Doesn't {STR_VAR_1} look\n"
	.string "nice?\p"
	.string "It's such a cute POKéMON.$"

PalletTown_House2_Text_AlreadyGroomed:
	.string "DAISY: I always have tea around\n"
	.string "this time. Come join me.$"

PalletTown_House2_Text_Refused:
	.string "DAISY: You don't want to have one\n"
	.string "groomed?\p"
	.string "OK, we'll just have tea.$"

PalletTown_House2_Text_CantGroomEgg:
	.string "DAISY: Oh, sorry. I honestly can't\n"
	.string "groom an EGG.$"
