HINTERHOF_MapScripts::
	.byte 0

@ Optional einstellbar
#define I3C_AND_LEVEL 20

HINTERHOF_EventScript_I3CAndObject::
    lock
    faceplayer

    @ Falls schon gefangen -> sollte eh unsichtbar sein, aber sicher ist sicher
    goto_if_set FLAG_I3C_AND_CAUGHT, I3CAnd_End

	msgbox HINTERHOF_Text_What, MSGBOX_DEFAULT

	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry

    setwildbattle SPECIES_I3C_AND, I3C_AND_LEVEL
    specialvar VAR_RESULT, BattleSetup_StartLegendaryBattle
    waitstate

    @ 1 == caught (bei den üblichen Legendary-Specials)
    compare VAR_RESULT, 1
    goto_if_eq I3CAnd_Caught

I3CAnd_End:
    release
    end

I3CAnd_Caught:
    setflag FLAG_I3C_AND_CAUGHT
    removeobject LOCALID_I3C_AND_OBJ
    release
    end


HINTERHOF_Text_What:
	.string "My name is STEVEN.\p"
	.string "I'm interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Oh?\n"
	.string "A LETTER for me?$"

