# 1 "data/maps/PacifidlogTown_House4/scripts.pory"

# 2 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_MapScripts::
# 3 "data/maps/PacifidlogTown_House4/scripts.pory"
	.byte 0
# 4 "data/maps/PacifidlogTown_House4/scripts.pory"

# 5 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_EventScript_LittleGirl::
# 6 "data/maps/PacifidlogTown_House4/scripts.pory"
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
# 7 "data/maps/PacifidlogTown_House4/scripts.pory"
	end
# 8 "data/maps/PacifidlogTown_House4/scripts.pory"

# 9 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_EventScript_Woman::
# 10 "data/maps/PacifidlogTown_House4/scripts.pory"
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
# 11 "data/maps/PacifidlogTown_House4/scripts.pory"
	end
# 12 "data/maps/PacifidlogTown_House4/scripts.pory"

# 13 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_EventScript_Boy::
# 14 "data/maps/PacifidlogTown_House4/scripts.pory"
	lock
# 15 "data/maps/PacifidlogTown_House4/scripts.pory"
	faceplayer
# 16 "data/maps/PacifidlogTown_House4/scripts.pory"
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
# 17 "data/maps/PacifidlogTown_House4/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
# 18 "data/maps/PacifidlogTown_House4/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
# 19 "data/maps/PacifidlogTown_House4/scripts.pory"
	end
# 20 "data/maps/PacifidlogTown_House4/scripts.pory"

# 21 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_EventScript_Yes::
# 22 "data/maps/PacifidlogTown_House4/scripts.pory"
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
# 23 "data/maps/PacifidlogTown_House4/scripts.pory"
	release
# 24 "data/maps/PacifidlogTown_House4/scripts.pory"
	end
# 25 "data/maps/PacifidlogTown_House4/scripts.pory"

# 26 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_EventScript_No::
# 27 "data/maps/PacifidlogTown_House4/scripts.pory"
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
# 28 "data/maps/PacifidlogTown_House4/scripts.pory"
	release
# 29 "data/maps/PacifidlogTown_House4/scripts.pory"
	end
# 30 "data/maps/PacifidlogTown_House4/scripts.pory"

# 31 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
# 32 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "People were saying they saw a POKéMON\n"
# 33 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "flying high above HOENN.\p"
# 34 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "Is it flying around all the time?\n"
# 35 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "Doesn't it need to rest somewhere?$"
# 36 "data/maps/PacifidlogTown_House4/scripts.pory"

# 37 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_Text_SkyPokemon:
# 38 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "A sky POKéMON!\n"
# 39 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "A sky POKéMON!$"
# 40 "data/maps/PacifidlogTown_House4/scripts.pory"

# 41 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_Text_WhereDidYouComeFrom:
# 42 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "Where did you come from?$"
# 43 "data/maps/PacifidlogTown_House4/scripts.pory"

# 44 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_Text_YesTown:
# 45 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "Yes?\n"
# 46 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "YES TOWN?\p"
# 47 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "I've never heard of a place like that.$"
# 48 "data/maps/PacifidlogTown_House4/scripts.pory"

# 49 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
# 50 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "No? That doesn't make any sense.\n"
# 51 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "You have to come from somewhere.\p"
# 52 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "Oh! Wait! You're not going to say you\n"
# 53 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "were born at the bottom of the sea?$"
