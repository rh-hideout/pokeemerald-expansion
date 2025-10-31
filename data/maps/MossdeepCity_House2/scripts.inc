# 1 "data/maps/MossdeepCity_House2/scripts.pory"

# 2 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_MapScripts::
# 3 "data/maps/MossdeepCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/MossdeepCity_House2/scripts.pory"

# 5 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_EventScript_Man::
# 6 "data/maps/MossdeepCity_House2/scripts.pory"
	msgbox MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree, MSGBOX_NPC
# 7 "data/maps/MossdeepCity_House2/scripts.pory"
	end
# 8 "data/maps/MossdeepCity_House2/scripts.pory"

# 9 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_EventScript_Twin::
# 10 "data/maps/MossdeepCity_House2/scripts.pory"
	msgbox MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth, MSGBOX_NPC
# 11 "data/maps/MossdeepCity_House2/scripts.pory"
	end
# 12 "data/maps/MossdeepCity_House2/scripts.pory"

# 13 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_EventScript_Wingull::
# 14 "data/maps/MossdeepCity_House2/scripts.pory"
	lock
# 15 "data/maps/MossdeepCity_House2/scripts.pory"
	faceplayer
# 16 "data/maps/MossdeepCity_House2/scripts.pory"
	waitse
# 17 "data/maps/MossdeepCity_House2/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 18 "data/maps/MossdeepCity_House2/scripts.pory"
	msgbox MossdeepCity_House2_Text_Wingull, MSGBOX_DEFAULT
# 19 "data/maps/MossdeepCity_House2/scripts.pory"
	waitmoncry
# 20 "data/maps/MossdeepCity_House2/scripts.pory"
	closemessage
# 21 "data/maps/MossdeepCity_House2/scripts.pory"
	setflag FLAG_WINGULL_DELIVERED_MAIL
# 22 "data/maps/MossdeepCity_House2/scripts.pory"
	clearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL
# 23 "data/maps/MossdeepCity_House2/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_House2_EventScript_WingullExitNorth
# 24 "data/maps/MossdeepCity_House2/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, MossdeepCity_House2_EventScript_WingullExitWest
# 25 "data/maps/MossdeepCity_House2/scripts.pory"
	removeobject LOCALID_MOSSDEEP_HOUSE_WINGULL
# 26 "data/maps/MossdeepCity_House2/scripts.pory"
	release
# 27 "data/maps/MossdeepCity_House2/scripts.pory"
	end
# 28 "data/maps/MossdeepCity_House2/scripts.pory"

# 29 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_EventScript_WingullExitNorth::
# 30 "data/maps/MossdeepCity_House2/scripts.pory"
	applymovement LOCALID_MOSSDEEP_HOUSE_WINGULL, MossdeepCity_House2_Movement_WingullExitNorth
# 31 "data/maps/MossdeepCity_House2/scripts.pory"
	waitmovement 0
# 32 "data/maps/MossdeepCity_House2/scripts.pory"
	return
# 33 "data/maps/MossdeepCity_House2/scripts.pory"

# 34 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_EventScript_WingullExitWest::
# 35 "data/maps/MossdeepCity_House2/scripts.pory"
	applymovement LOCALID_MOSSDEEP_HOUSE_WINGULL, MossdeepCity_House2_Movement_WingullExitEast
# 36 "data/maps/MossdeepCity_House2/scripts.pory"
	waitmovement 0
# 37 "data/maps/MossdeepCity_House2/scripts.pory"
	return
# 38 "data/maps/MossdeepCity_House2/scripts.pory"

# 39 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_Movement_WingullExitNorth:
# 40 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_right
# 41 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 42 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 43 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_left
# 44 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 45 "data/maps/MossdeepCity_House2/scripts.pory"
	delay_8
# 46 "data/maps/MossdeepCity_House2/scripts.pory"
	step_end
# 47 "data/maps/MossdeepCity_House2/scripts.pory"

# 48 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_Movement_WingullExitEast:
# 49 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 50 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 51 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 52 "data/maps/MossdeepCity_House2/scripts.pory"
	delay_8
# 53 "data/maps/MossdeepCity_House2/scripts.pory"
	step_end
# 54 "data/maps/MossdeepCity_House2/scripts.pory"

# 55 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree:
# 56 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "My little sister exchanges MAIL with\n"
# 57 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "her boyfriend in FORTREE.\p"
# 58 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "I don't envy her one bit at all.$"
# 59 "data/maps/MossdeepCity_House2/scripts.pory"

# 60 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth:
# 61 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "Even though I can't see my friend in\n"
# 62 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "FORTREE, my POKéMON carries MAIL\l"
# 63 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "back and forth for us.\p"
# 64 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "I'm not lonesome, even though we're\n"
# 65 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "apart.$"
# 66 "data/maps/MossdeepCity_House2/scripts.pory"

# 67 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_Text_Wingull:
# 68 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "WINGULL: Pihyoh!$"
