	@ Set some ARENA_DATA_* to val. See SetArenaData for the data types that can be set
	.macro arena_set data:req, val:req
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val >= VARS_START
	copyvar VAR_0x8006, \val
	.else
	setvar VAR_0x8006, \val
	.endif
	special CallBattleArenaFunction
	.endm

	@ Save the game and set the challenge status
	.macro arena_save challengeStatus:req
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallBattleArenaFunction
	.endm

	@ Buffer the opponents name to STR_VAR_1
	.macro arena_gettrainername
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_GET_TRAINER_NAME
	special CallBattleArenaFunction
	.endm
