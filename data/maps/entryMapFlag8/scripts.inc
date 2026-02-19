entryMapFlag8_MapScripts::
    .byte 0

entryMapFlag8_After:
    end

entryMapFlag8_AfterWin:
    end





@ =========================================================
@ entryMapFlag8 — NPC #1: Ditto schenken (nur 1x)
@ =========================================================

entryMapFlag8_EventScript_GiveDitto::
	lock
	faceplayer

	goto_if_set FLAG_ENTRYMAPFLAG8_GOT_DITTO, entryMapFlag8_EventScript_GiveDitto_Already

	msgbox entryMapFlag8_Text_DittoOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq entryMapFlag8_EventScript_GiveDitto_Refused

	@ Gibt Ditto. VAR_RESULT wird auf MON_GIVEN_TO_PARTY / MON_GIVEN_TO_PC / MON_CANT_GIVE gesetzt.
	givemon SPECIES_DITTO, 5, ITEM_NONE
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq entryMapFlag8_EventScript_GiveDitto_NoRoom

	setflag FLAG_ENTRYMAPFLAG8_GOT_DITTO

	bufferspeciesname STR_VAR_1, SPECIES_DITTO
	playfanfare MUS_OBTAIN_ITEM
	msgbox entryMapFlag8_Text_DittoReceived, MSGBOX_DEFAULT
	waitfanfare

	release
	end

entryMapFlag8_EventScript_GiveDitto_NoRoom::
	msgbox entryMapFlag8_Text_DittoNoRoom, MSGBOX_DEFAULT
	release
	end

entryMapFlag8_EventScript_GiveDitto_Refused::
	msgbox entryMapFlag8_Text_DittoRefused, MSGBOX_DEFAULT
	release
	end

entryMapFlag8_EventScript_GiveDitto_Already::
	msgbox entryMapFlag8_Text_DittoAlready, MSGBOX_DEFAULT
	release
	end


@ Texte Ditto-NPC
entryMapFlag8_Text_DittoOffer:
	.string " Willst du dieses Ditto?$"

entryMapFlag8_Text_DittoReceived:
	.string " Du hast {STR_VAR_1} erhalten!$"

entryMapFlag8_Text_DittoNoRoom:
	.string " Kein Platz im Team/PC.$"

entryMapFlag8_Text_DittoRefused:
	.string " Vielleicht später.$"

entryMapFlag8_Text_DittoAlready:
	.string " Viel Spaß mit dem Ditto!$"


@ =========================================================
@ entryMapFlag8 — NPC #2: Trainerkampf NUR beim Ansprechen
@ (kein "Entdecken"/Sichtweite)
@ =========================================================

entryMapFlag8_EventScript_TalkTrainerBattle::
	lock
	faceplayer
	goto_if_defeated TRAINER_MARLEY, entryMapFlag8_After

	trainerbattle_single TRAINER_MARLEY, entryMapFlag8_Text_TrainerIntro, entryMapFlag8_Text_TrainerDefeat, entryMapFlag8_AfterWin
	release
	end

entryMapFlag8_EventScript_TalkTrainerBattle_AfterWin::
	@ zur Sicherheit (meist setzt das System das ohnehin, aber schadet nicht)
	settrainerflag TRAINER_MARLEY
	msgbox entryMapFlag8_Text_TrainerAfterWin, MSGBOX_DEFAULT
	release
	end

entryMapFlag8_EventScript_TalkTrainerBattle_After::
	msgbox entryMapFlag8_Text_TrainerAfter, MSGBOX_DEFAULT
	release
	end


@ Texte Trainerkampf-NPC
entryMapFlag8_Text_TrainerIntro:
	.string " Ich kämpfe nur,\n"
	.string "wenn du mich ansprichst!$"

entryMapFlag8_Text_TrainerDefeat:
	.string "Okay, du hast gewonnen...$"

entryMapFlag8_Text_TrainerAfterWin:
	.string " Respekt. Das war stark.$"

entryMapFlag8_Text_TrainerAfter:
	.string " Wir haben schon gekämpft.$"

