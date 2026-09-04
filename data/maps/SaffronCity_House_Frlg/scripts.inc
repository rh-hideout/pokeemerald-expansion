SaffronCity_House_Frlg_MapScripts::
	.byte 0

SaffronCity_House_EventScript_Lass::
	msgbox SaffronCity_House_Text_DontLookAtMyLetter, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Youngster::
	msgbox SaffronCity_House_Text_GettingCopycatPokeDoll, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Pidgey
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Letter::
	msgbox SaffronCity_House_Text_ExplainPPUp, MSGBOX_SIGN
	end

SaffronCity_House_Text_DontLookAtMyLetter::
	.string "…Thank you for writing.\n"
	.string "I hope to see you soon!\p"
	.string "…Hey!\n"
	.string "Don't look at my letter!$"

SaffronCity_House_Text_Pidgey::
	.string "[Pidgey]: Kurukkoo!$"

SaffronCity_House_Text_GettingCopycatPokeDoll::
	.string "The [Copycat] is cute!\n"
	.string "I'm getting her a [Poké Doll].$"

SaffronCity_House_Text_ExplainPPUp::
	.string "I was given a [PP Up] as a gift.\p"
	.string "It's used to increase the PP of\n"
	.string "a [Pokémon]'s move.\p"
	.string "I should use it on a powerful move\n"
	.string "with only a few PP.$"
