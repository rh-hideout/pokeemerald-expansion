BXPY_Script_CheckErrors::
	setvar VAR_TEMP_0, 0
	callnative BXPY_OverworldRun_ErrorCheck_BringSizeTooLarge
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_2
BXPY_Script_CheckErrors_1:
	callnative BXPY_OverworldRun_ErrorCheck_BringSizeNotEnough
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_5
BXPY_Script_CheckErrors_4:
	callnative BXPY_OverworldRun_ErrorCheck_ClauseSpecies
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_8
BXPY_Script_CheckErrors_7:
	callnative BXPY_OverworldRun_ErrorCheck_ClauseItem
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_11
BXPY_Script_CheckErrors_10:
	callnative BXPY_OverworldRun_ErrorCheck_ClauseSpecialPokemon
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_14
BXPY_Script_CheckErrors_13:
	compare VAR_TEMP_0, 0
	goto_if_gt BXPY_Script_CheckErrors_16
	return

BXPY_Script_CheckErrors_2:
	addvar VAR_TEMP_0, 1
	msgbox BXPY_Script_CheckErrors_Text_0, MSGBOX_AUTOCLOSE
	closemessage
	goto BXPY_Script_CheckErrors_1

BXPY_Script_CheckErrors_5:
	addvar VAR_TEMP_0, 1
	msgbox BXPY_Script_CheckErrors_Text_1, MSGBOX_AUTOCLOSE
	closemessage
	goto BXPY_Script_CheckErrors_4

BXPY_Script_CheckErrors_8:
	addvar VAR_TEMP_0, 1
	msgbox BXPY_Script_CheckErrors_Text_2, MSGBOX_AUTOCLOSE
	closemessage
	goto BXPY_Script_CheckErrors_7

BXPY_Script_CheckErrors_11:
	addvar VAR_TEMP_0, 1
	msgbox BXPY_Script_CheckErrors_Text_3, MSGBOX_AUTOCLOSE
	closemessage
	goto BXPY_Script_CheckErrors_10

BXPY_Script_CheckErrors_14:
	addvar VAR_TEMP_0, 1
	msgbox BXPY_Script_CheckErrors_Text_4, MSGBOX_AUTOCLOSE
	closemessage
	goto BXPY_Script_CheckErrors_13

BXPY_Script_CheckErrors_16:
	release
	end


DebugBXPY_Text_0:
	.string "yes$"

BXPY_Script_CheckErrors_Text_0:
	.string "You have too many Pokemon in your\n"
	.string "party. You cannot have more than\l"
	.string "{STR_VAR_1}.$"

BXPY_Script_CheckErrors_Text_1:
	.string "You must have {STR_VAR_1} healthy\n"
	.string "Pokemon in your party to battle!$"

BXPY_Script_CheckErrors_Text_2:
	.string "All of the Pokemon in your party must be\n"
	.string "of unique species.\l"
	.string "{STR_VAR_1}\l"
	.string "appear more than once.$"

BXPY_Script_CheckErrors_Text_3:
	.string "All of the held items in your party must\n"
	.string "be unique.\l"
	.string "{STR_VAR_1}\l"
	.string "appear more than once.$"

BXPY_Script_CheckErrors_Text_4:
	.string "Some Pokemon are restricted from\n"
	.string "entering. You cannot bring\l"
	.string "{STR_VAR_1}.$"
