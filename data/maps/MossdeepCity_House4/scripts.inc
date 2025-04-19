# 1 "data/maps/MossdeepCity_House4/scripts.pory"

# 2 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_MapScripts::
# 3 "data/maps/MossdeepCity_House4/scripts.pory"
	.byte 0
# 4 "data/maps/MossdeepCity_House4/scripts.pory"

# 5 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_EventScript_Woman::
# 6 "data/maps/MossdeepCity_House4/scripts.pory"
	lock
# 7 "data/maps/MossdeepCity_House4/scripts.pory"
	faceplayer
# 8 "data/maps/MossdeepCity_House4/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
# 9 "data/maps/MossdeepCity_House4/scripts.pory"
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
# 10 "data/maps/MossdeepCity_House4/scripts.pory"
	release
# 11 "data/maps/MossdeepCity_House4/scripts.pory"
	end
# 12 "data/maps/MossdeepCity_House4/scripts.pory"

# 13 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
# 14 "data/maps/MossdeepCity_House4/scripts.pory"
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
# 15 "data/maps/MossdeepCity_House4/scripts.pory"
	release
# 16 "data/maps/MossdeepCity_House4/scripts.pory"
	end
# 17 "data/maps/MossdeepCity_House4/scripts.pory"

# 18 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_EventScript_NinjaBoy::
# 19 "data/maps/MossdeepCity_House4/scripts.pory"
	lock
# 20 "data/maps/MossdeepCity_House4/scripts.pory"
	faceplayer
# 21 "data/maps/MossdeepCity_House4/scripts.pory"
	special CheckPlayerHasSecretBase
# 22 "data/maps/MossdeepCity_House4/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
# 23 "data/maps/MossdeepCity_House4/scripts.pory"
	special GetSecretBaseNearbyMapName
# 24 "data/maps/MossdeepCity_House4/scripts.pory"
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
# 25 "data/maps/MossdeepCity_House4/scripts.pory"
	release
# 26 "data/maps/MossdeepCity_House4/scripts.pory"
	end
# 27 "data/maps/MossdeepCity_House4/scripts.pory"

# 28 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_EventScript_NoSecretBase::
# 29 "data/maps/MossdeepCity_House4/scripts.pory"
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
# 30 "data/maps/MossdeepCity_House4/scripts.pory"
	release
# 31 "data/maps/MossdeepCity_House4/scripts.pory"
	end
# 32 "data/maps/MossdeepCity_House4/scripts.pory"

# 33 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_EventScript_Skitty::
# 34 "data/maps/MossdeepCity_House4/scripts.pory"
	lock
# 35 "data/maps/MossdeepCity_House4/scripts.pory"
	faceplayer
# 36 "data/maps/MossdeepCity_House4/scripts.pory"
	waitse
# 37 "data/maps/MossdeepCity_House4/scripts.pory"
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
# 38 "data/maps/MossdeepCity_House4/scripts.pory"
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
# 39 "data/maps/MossdeepCity_House4/scripts.pory"
	waitmoncry
# 40 "data/maps/MossdeepCity_House4/scripts.pory"
	release
# 41 "data/maps/MossdeepCity_House4/scripts.pory"
	end
# 42 "data/maps/MossdeepCity_House4/scripts.pory"

# 43 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_Text_BrotherLikesToFindBases:
# 44 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "My little brother says he likes to go\n"
# 45 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "find people's SECRET BASES.$"
# 46 "data/maps/MossdeepCity_House4/scripts.pory"

# 47 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
# 48 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "My little brother says he likes to\n"
# 49 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "visit people's SECRET BASES and have\l"
# 50 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "POKéMON battles.$"
# 51 "data/maps/MossdeepCity_House4/scripts.pory"

# 52 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
# 53 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "Was it you who made a SECRET BASE\n"
# 54 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "near {STR_VAR_1}?$"
# 55 "data/maps/MossdeepCity_House4/scripts.pory"

# 56 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_Text_MakeSecretBase:
# 57 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "You should make a SECRET BASE\n"
# 58 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "somewhere. I'll go find it!$"
# 59 "data/maps/MossdeepCity_House4/scripts.pory"

# 60 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_Text_Skitty:
# 61 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "SKITTY: Miyaan?$"
