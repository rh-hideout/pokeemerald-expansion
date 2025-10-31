# 1 "data/maps/PacifidlogTown_House2/scripts.pory"

# 2 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_MapScripts::
# 3 "data/maps/PacifidlogTown_House2/scripts.pory"
	.byte 0
# 4 "data/maps/PacifidlogTown_House2/scripts.pory"

# 5 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
# 6 "data/maps/PacifidlogTown_House2/scripts.pory"
	lock
# 7 "data/maps/PacifidlogTown_House2/scripts.pory"
	faceplayer
# 8 "data/maps/PacifidlogTown_House2/scripts.pory"
	dotimebasedevents
# 9 "data/maps/PacifidlogTown_House2/scripts.pory"
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
# 10 "data/maps/PacifidlogTown_House2/scripts.pory"
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
# 11 "data/maps/PacifidlogTown_House2/scripts.pory"
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
# 12 "data/maps/PacifidlogTown_House2/scripts.pory"
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
# 13 "data/maps/PacifidlogTown_House2/scripts.pory"
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
# 14 "data/maps/PacifidlogTown_House2/scripts.pory"
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
# 15 "data/maps/PacifidlogTown_House2/scripts.pory"
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn
# 16 "data/maps/PacifidlogTown_House2/scripts.pory"
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
# 17 "data/maps/PacifidlogTown_House2/scripts.pory"
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
# 18 "data/maps/PacifidlogTown_House2/scripts.pory"
	goto PacifidlogTown_House2_EventScript_GiveFrustration
# 19 "data/maps/PacifidlogTown_House2/scripts.pory"
	end
# 20 "data/maps/PacifidlogTown_House2/scripts.pory"

# 21 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
# 22 "data/maps/PacifidlogTown_House2/scripts.pory"
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
# 23 "data/maps/PacifidlogTown_House2/scripts.pory"
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
# 24 "data/maps/PacifidlogTown_House2/scripts.pory"
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
# 25 "data/maps/PacifidlogTown_House2/scripts.pory"
	return
# 26 "data/maps/PacifidlogTown_House2/scripts.pory"

# 27 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_MonAssessment::
# 28 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
# 29 "data/maps/PacifidlogTown_House2/scripts.pory"
	return
# 30 "data/maps/PacifidlogTown_House2/scripts.pory"

# 31 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_FirstMonAssessment::
# 32 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
# 33 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
# 34 "data/maps/PacifidlogTown_House2/scripts.pory"
	return
# 35 "data/maps/PacifidlogTown_House2/scripts.pory"

# 36 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
# 37 "data/maps/PacifidlogTown_House2/scripts.pory"
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
# 38 "data/maps/PacifidlogTown_House2/scripts.pory"
	return
# 39 "data/maps/PacifidlogTown_House2/scripts.pory"

# 40 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_GiveReturn::
# 41 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
# 42 "data/maps/PacifidlogTown_House2/scripts.pory"
	giveitem ITEM_TM_RETURN
# 43 "data/maps/PacifidlogTown_House2/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 44 "data/maps/PacifidlogTown_House2/scripts.pory"
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
# 45 "data/maps/PacifidlogTown_House2/scripts.pory"
	special SetPacifidlogTMReceivedDay
# 46 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
# 47 "data/maps/PacifidlogTown_House2/scripts.pory"
	release
# 48 "data/maps/PacifidlogTown_House2/scripts.pory"
	end
# 49 "data/maps/PacifidlogTown_House2/scripts.pory"

# 50 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_PutInEffort::
# 51 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
# 52 "data/maps/PacifidlogTown_House2/scripts.pory"
	release
# 53 "data/maps/PacifidlogTown_House2/scripts.pory"
	end
# 54 "data/maps/PacifidlogTown_House2/scripts.pory"

# 55 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_GiveFrustration::
# 56 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
# 57 "data/maps/PacifidlogTown_House2/scripts.pory"
	giveitem ITEM_TM_FRUSTRATION
# 58 "data/maps/PacifidlogTown_House2/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 59 "data/maps/PacifidlogTown_House2/scripts.pory"
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
# 60 "data/maps/PacifidlogTown_House2/scripts.pory"
	special SetPacifidlogTMReceivedDay
# 61 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
# 62 "data/maps/PacifidlogTown_House2/scripts.pory"
	release
# 63 "data/maps/PacifidlogTown_House2/scripts.pory"
	end
# 64 "data/maps/PacifidlogTown_House2/scripts.pory"

# 65 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_ComeBackInXDays::
# 66 "data/maps/PacifidlogTown_House2/scripts.pory"
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
# 67 "data/maps/PacifidlogTown_House2/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 68 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
# 69 "data/maps/PacifidlogTown_House2/scripts.pory"
	release
# 70 "data/maps/PacifidlogTown_House2/scripts.pory"
	end
# 71 "data/maps/PacifidlogTown_House2/scripts.pory"

# 72 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_HappyAzurill::
# 73 "data/maps/PacifidlogTown_House2/scripts.pory"
	lock
# 74 "data/maps/PacifidlogTown_House2/scripts.pory"
	faceplayer
# 75 "data/maps/PacifidlogTown_House2/scripts.pory"
	waitse
# 76 "data/maps/PacifidlogTown_House2/scripts.pory"
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
# 77 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
# 78 "data/maps/PacifidlogTown_House2/scripts.pory"
	waitmoncry
# 79 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
# 80 "data/maps/PacifidlogTown_House2/scripts.pory"
	release
# 81 "data/maps/PacifidlogTown_House2/scripts.pory"
	end
# 82 "data/maps/PacifidlogTown_House2/scripts.pory"

# 83 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_UnhappyAzurill::
# 84 "data/maps/PacifidlogTown_House2/scripts.pory"
	lock
# 85 "data/maps/PacifidlogTown_House2/scripts.pory"
	faceplayer
# 86 "data/maps/PacifidlogTown_House2/scripts.pory"
	waitse
# 87 "data/maps/PacifidlogTown_House2/scripts.pory"
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
# 88 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
# 89 "data/maps/PacifidlogTown_House2/scripts.pory"
	waitmoncry
# 90 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
# 91 "data/maps/PacifidlogTown_House2/scripts.pory"
	release
# 92 "data/maps/PacifidlogTown_House2/scripts.pory"
	end
# 93 "data/maps/PacifidlogTown_House2/scripts.pory"

# 94 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
# 95 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Er-hem!\p"
# 96 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "I am the POKéMON FAN CLUB's most\n"
# 97 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "important person, the CHAIRMAN's\l"
# 98 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "younger brother.\p"
# 99 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "I'm here enjoying my vacation with\n"
# 100 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "POKéMON, yes, indeed.$"
# 101 "data/maps/PacifidlogTown_House2/scripts.pory"

# 102 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_AhYourPokemon:
# 103 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Ah!\n"
# 104 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Your POKéMON…$"
# 105 "data/maps/PacifidlogTown_House2/scripts.pory"

# 106 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
# 107 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "It clearly likes you very much.\p"
# 108 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "A POKéMON that adoring and adorable\n"
# 109 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "deserves a TM like this, no?$"
# 110 "data/maps/PacifidlogTown_House2/scripts.pory"

# 111 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_PutInSomeMoreEffort:
# 112 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Hmm…\n"
# 113 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "It's not bad, but it's also not good.\p"
# 114 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "You, as the TRAINER, need to put in\n"
# 115 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "some more effort.$"
# 116 "data/maps/PacifidlogTown_House2/scripts.pory"

# 117 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
# 118 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "It has a vicious look to it.\p"
# 119 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "A frightening POKéMON like that\n"
# 120 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "deserves a TM like this.$"
# 121 "data/maps/PacifidlogTown_House2/scripts.pory"

# 122 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_ExplainReturnFrustration:
# 123 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "If a POKéMON likes you a lot, RETURN's\n"
# 124 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "power is enhanced.\p"
# 125 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "If it doesn't like you, FRUSTRATION's\n"
# 126 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "power goes up.$"
# 127 "data/maps/PacifidlogTown_House2/scripts.pory"

# 128 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_GetGoodTMInXDays:
# 129 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Oh, yes. In about {STR_VAR_1} or so days,\n"
# 130 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "I should be getting a good TM or two.\p"
# 131 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "You should come see me then.\n"
# 132 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "I'll give you a TM that's suitable for\l"
# 133 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "your POKéMON.$"
# 134 "data/maps/PacifidlogTown_House2/scripts.pory"

# 135 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_Rurii:
# 136 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "AZURILL: Rurii.$"
# 137 "data/maps/PacifidlogTown_House2/scripts.pory"

# 138 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
# 139 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "It appears to be very friendly with the\n"
# 140 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "TRAINER.$"
# 141 "data/maps/PacifidlogTown_House2/scripts.pory"

# 142 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_Rururi:
# 143 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "AZURILL: Rururi!$"
# 144 "data/maps/PacifidlogTown_House2/scripts.pory"

# 145 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
# 146 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "It doesn't appear to like the TRAINER\n"
# 147 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "very much.$"
