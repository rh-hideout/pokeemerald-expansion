# 1 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 2 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_MapScripts::
# 3 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.byte 0
# 4 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 5 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_NameRater::
# 6 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	lock
# 7 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	faceplayer
# 8 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
# 9 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
# 10 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
# 11 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 12 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 13 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
# 14 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
# 15 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	special ChoosePartyMon
# 16 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	waitstate
# 17 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
# 18 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
# 19 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 20 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 21 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
# 22 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
# 23 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	release
# 24 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 25 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 26 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
# 27 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 28 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
# 29 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	special BufferMonNickname
# 30 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	special IsMonOTIDNotPlayers
# 31 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
# 32 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	specialvar VAR_RESULT, MonOTNameNotPlayer
# 33 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	special BufferMonNickname
# 34 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
# 35 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
# 36 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
# 37 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
# 38 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 39 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 40 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
# 41 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
# 42 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	release
# 43 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 44 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 45 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
# 46 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
# 47 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	release
# 48 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 49 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 50 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
# 51 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
# 52 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 53 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
# 54 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	special BufferMonNickname
# 55 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
# 56 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
# 57 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	release
# 58 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 59 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 60 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
# 61 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
# 62 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	release
# 63 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 64 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 65 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
# 66 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Hi, hi! I'm the NAME RATER!\n"
# 67 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "I'm the fortune-teller of names!\p"
# 68 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "I shall be pleased to rate your\n"
# 69 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "POKéMON's nickname.$"
# 70 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 71 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
# 72 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Which POKéMON's nickname should\n"
# 73 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "I critique?$"
# 74 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 75 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
# 76 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Hmmm… {STR_VAR_1}, is it? That is\n"
# 77 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "quite a fine name you bestowed.\p"
# 78 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "But! What say you, if I were to\n"
# 79 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "suggest a slightly better name?$"
# 80 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 81 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
# 82 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Ah, good. Then, what shall the new\n"
# 83 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "nickname be?$"
# 84 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 85 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
# 86 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Done! From now on, this POKéMON\n"
# 87 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "shall be known as {STR_VAR_1}!\p"
# 88 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "It is a better name than before!\n"
# 89 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "How fortunate for you!$"
# 90 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 91 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_DoVisitAgain:
# 92 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "I see.\n"
# 93 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Do come visit again.$"
# 94 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 95 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
# 96 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Done! From now on, this POKéMON\n"
# 97 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "shall be known as {STR_VAR_1}!\p"
# 98 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "It looks no different from before,\n"
# 99 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "and yet, this is vastly superior!\p"
# 100 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "How fortunate for you!$"
# 101 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 102 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_MagnificentName:
# 103 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Hmmm… {STR_VAR_1} it is!\p"
# 104 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "This is a magnificent nickname!\n"
# 105 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "It is impeccably beyond reproach!\p"
# 106 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "You'll do well to cherish your\n"
# 107 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "{STR_VAR_1} now and beyond.$"
# 108 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 109 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
# 110 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Now, now.\n"
# 111 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "That is merely an EGG!$"
