Common_EventScript_CheckLevelCapIncrease::
	specialvar VAR_TEMP_1, GetCurrentLevelCapSpecial
	compare VAR_RESULT, VAR_TEMP_1
	goto_if_lt Common_EventScript_LevelCapIncreased
	return

Common_EventScript_LevelCapIncreased::
	copyvar VAR_RESULT, VAR_TEMP_1
	buffernumberstring STR_VAR_1, VAR_TEMP_1
	message sText_LevelCapIncreased
	waitmessage
	playse SE_EXP_MAX
	waitse
	return

sText_LevelCapIncreased:
	.string "The level cap has increased!$"