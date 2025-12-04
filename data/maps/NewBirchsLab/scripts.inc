NewBirchsLab_MapScripts::
# 2 "data/maps/NewBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewBirchsLab_EventScript_BallDefault
	.byte 0


NewBirchsLab_EventScript_BallDefault::
# 6 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F7, 0
# 7 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F8, 0
	return


NewBirchsLab_EventScript_Birch::
# 11 "data/maps/NewBirchsLab/scripts.pory"
	lockall
# 12 "data/maps/NewBirchsLab/scripts.pory"
	faceplayer
# 13 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_ONE, NewBirchsLab_EventScript_Birch_4
NewBirchsLab_EventScript_Birch_3:
# 29 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Birch_Text_2
NewBirchsLab_EventScript_Birch_1:
# 31 "data/maps/NewBirchsLab/scripts.pory"
	waitmessage
# 32 "data/maps/NewBirchsLab/scripts.pory"
	releaseall
	end

NewBirchsLab_EventScript_Birch_2:
# 14 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Birch_Text_0, MSGBOX_YESNO
# 15 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_Birch_9
# 25 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Birch_Text_1
	goto NewBirchsLab_EventScript_Birch_1

NewBirchsLab_EventScript_Birch_4:
# 13 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_TWO, NewBirchsLab_EventScript_Birch_6
	goto NewBirchsLab_EventScript_Birch_3

NewBirchsLab_EventScript_Birch_6:
# 13 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_THREE, NewBirchsLab_EventScript_Birch_2
	goto NewBirchsLab_EventScript_Birch_3

NewBirchsLab_EventScript_Birch_9:
# 16 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_UNUSED_0x40F7, 2
	goto_if_ne NewBirchsLab_EventScript_Birch_13
# 20 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F7, 0
NewBirchsLab_EventScript_Birch_12:
# 22 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Birch_Text_1
	goto NewBirchsLab_EventScript_Birch_1

NewBirchsLab_EventScript_Birch_13:
# 17 "data/maps/NewBirchsLab/scripts.pory"
	addvar VAR_UNUSED_0x40F7, 1
	goto NewBirchsLab_EventScript_Birch_12


NewBirchsLab_EventScript_PokeballOne::
# 37 "data/maps/NewBirchsLab/scripts.pory"
	lockall
# 38 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_ONE, NewBirchsLab_EventScript_PokeballOne_4
NewBirchsLab_EventScript_PokeballOne_3:
# 53 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_PokeballOne_Text_0
NewBirchsLab_EventScript_PokeballOne_1:
# 55 "data/maps/NewBirchsLab/scripts.pory"
	waitmessage
# 56 "data/maps/NewBirchsLab/scripts.pory"
	releaseall
	end

NewBirchsLab_EventScript_PokeballOne_2:
# 39 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_UNUSED_0x40F7, 0
	goto_if_eq NewBirchsLab_EventScript_PokeballOne_9
# 43 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_UNUSED_0x40F7, 1
	goto_if_eq NewBirchsLab_EventScript_PokeballOne_10
# 47 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_UNUSED_0x40F7, 2
	goto_if_eq NewBirchsLab_EventScript_PokeballOne_11
	goto NewBirchsLab_EventScript_PokeballOne_1

NewBirchsLab_EventScript_PokeballOne_4:
# 38 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_TWO, NewBirchsLab_EventScript_PokeballOne_6
	goto NewBirchsLab_EventScript_PokeballOne_3

NewBirchsLab_EventScript_PokeballOne_6:
# 38 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_THREE, NewBirchsLab_EventScript_PokeballOne_2
	goto NewBirchsLab_EventScript_PokeballOne_3

NewBirchsLab_EventScript_PokeballOne_9:
# 40 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F8, 0
# 41 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_Mudkip
	goto NewBirchsLab_EventScript_PokeballOne_1

NewBirchsLab_EventScript_PokeballOne_10:
# 44 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F8, 1
# 45 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_Totodile
	goto NewBirchsLab_EventScript_PokeballOne_1

NewBirchsLab_EventScript_PokeballOne_11:
# 48 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F8, 2
# 49 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_Squirtle
	goto NewBirchsLab_EventScript_PokeballOne_1


NewBirchsLab_EventScript_PokeballTwo::
# 61 "data/maps/NewBirchsLab/scripts.pory"
	lockall
# 62 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_ONE, NewBirchsLab_EventScript_PokeballTwo_4
NewBirchsLab_EventScript_PokeballTwo_3:
# 77 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_PokeballOne_Text_0
NewBirchsLab_EventScript_PokeballTwo_1:
# 79 "data/maps/NewBirchsLab/scripts.pory"
	waitmessage
# 80 "data/maps/NewBirchsLab/scripts.pory"
	releaseall
	end

NewBirchsLab_EventScript_PokeballTwo_2:
# 63 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_UNUSED_0x40F7, 0
	goto_if_eq NewBirchsLab_EventScript_PokeballTwo_9
# 67 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_UNUSED_0x40F7, 1
	goto_if_eq NewBirchsLab_EventScript_PokeballTwo_10
# 71 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_UNUSED_0x40F7, 2
	goto_if_eq NewBirchsLab_EventScript_PokeballTwo_11
	goto NewBirchsLab_EventScript_PokeballTwo_1

NewBirchsLab_EventScript_PokeballTwo_4:
# 62 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_TWO, NewBirchsLab_EventScript_PokeballTwo_6
	goto NewBirchsLab_EventScript_PokeballTwo_3

NewBirchsLab_EventScript_PokeballTwo_6:
# 62 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_THREE, NewBirchsLab_EventScript_PokeballTwo_2
	goto NewBirchsLab_EventScript_PokeballTwo_3

NewBirchsLab_EventScript_PokeballTwo_9:
# 64 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F8, 3
# 65 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_Treecko
	goto NewBirchsLab_EventScript_PokeballTwo_1

NewBirchsLab_EventScript_PokeballTwo_10:
# 68 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F8, 4
# 69 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_Chikorita
	goto NewBirchsLab_EventScript_PokeballTwo_1

NewBirchsLab_EventScript_PokeballTwo_11:
# 72 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F8, 5
# 73 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_Bulbasaur
	goto NewBirchsLab_EventScript_PokeballTwo_1


NewBirchsLab_EventScript_PokeballThree::
# 85 "data/maps/NewBirchsLab/scripts.pory"
	lockall
# 86 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_ONE, NewBirchsLab_EventScript_PokeballThree_4
NewBirchsLab_EventScript_PokeballThree_3:
# 101 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_PokeballOne_Text_0
NewBirchsLab_EventScript_PokeballThree_1:
# 103 "data/maps/NewBirchsLab/scripts.pory"
	waitmessage
# 104 "data/maps/NewBirchsLab/scripts.pory"
	releaseall
	end

NewBirchsLab_EventScript_PokeballThree_2:
# 87 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_UNUSED_0x40F7, 0
	goto_if_eq NewBirchsLab_EventScript_PokeballThree_9
# 91 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_UNUSED_0x40F7, 1
	goto_if_eq NewBirchsLab_EventScript_PokeballThree_10
# 95 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_UNUSED_0x40F7, 2
	goto_if_eq NewBirchsLab_EventScript_PokeballThree_11
	goto NewBirchsLab_EventScript_PokeballThree_1

NewBirchsLab_EventScript_PokeballThree_4:
# 86 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_TWO, NewBirchsLab_EventScript_PokeballThree_6
	goto NewBirchsLab_EventScript_PokeballThree_3

NewBirchsLab_EventScript_PokeballThree_6:
# 86 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset STARTER_BALL_THREE, NewBirchsLab_EventScript_PokeballThree_2
	goto NewBirchsLab_EventScript_PokeballThree_3

NewBirchsLab_EventScript_PokeballThree_9:
# 88 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F8, 6
# 89 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_Torchic
	goto NewBirchsLab_EventScript_PokeballThree_1

NewBirchsLab_EventScript_PokeballThree_10:
# 92 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F8, 7
# 93 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_Cyndaquil
	goto NewBirchsLab_EventScript_PokeballThree_1

NewBirchsLab_EventScript_PokeballThree_11:
# 96 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F8, 8
# 97 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_Charmander
	goto NewBirchsLab_EventScript_PokeballThree_1


NewBirchsLab_EventScript_Mudkip::
# 114 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic SPECIES_MUDKIP, 10, 3
# 115 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_0, MSGBOX_YESNO
# 116 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_Mudkip_1
# 138 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 139 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_Mudkip_1:
# 117 "data/maps/NewBirchsLab/scripts.pory"
	givemon SPECIES_MUDKIP, 50, ITEM_MASTER_BALL
# 118 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_Mudkip_4
# 125 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_Mudkip_5
# 133 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 134 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_2
	return

NewBirchsLab_EventScript_Mudkip_4:
# 119 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 120 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_1
# 121 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 1
# 122 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_ONE
# 123 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	return

NewBirchsLab_EventScript_Mudkip_5:
# 126 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 127 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_1
# 128 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 1
# 129 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_ONE
# 130 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	return


NewBirchsLab_EventScript_Totodile::
# 145 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 146 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Totodile_Text_0, MSGBOX_YESNO
# 147 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_Totodile_1
# 169 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 170 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_Totodile_1:
# 148 "data/maps/NewBirchsLab/scripts.pory"
	givemon SPECIES_TOTODILE, 50, ITEM_MASTER_BALL
# 149 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_Totodile_4
# 156 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_Totodile_5
# 164 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 165 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_2
	return

NewBirchsLab_EventScript_Totodile_4:
# 150 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 151 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Totodile_Text_1
# 152 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 1
# 153 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_ONE
# 154 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	return

NewBirchsLab_EventScript_Totodile_5:
# 157 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 158 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Totodile_Text_1
# 159 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 1
# 160 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_ONE
# 161 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	return


NewBirchsLab_EventScript_Squirtle::
# 176 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic SPECIES_SQUIRTLE, 10, 3
# 177 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Squirtle_Text_0, MSGBOX_YESNO
# 178 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_Squirtle_1
# 200 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 201 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_Squirtle_1:
# 179 "data/maps/NewBirchsLab/scripts.pory"
	givemon SPECIES_SQUIRTLE, 50, ITEM_MASTER_BALL
# 180 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_Squirtle_4
# 187 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_Squirtle_5
# 195 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 196 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_2
	return

NewBirchsLab_EventScript_Squirtle_4:
# 181 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 182 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Squirtle_Text_1
# 183 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 1
# 184 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_ONE
# 185 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	return

NewBirchsLab_EventScript_Squirtle_5:
# 188 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 189 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Squirtle_Text_1
# 190 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 1
# 191 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_ONE
# 192 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	return


NewBirchsLab_EventScript_Treecko::
# 207 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic SPECIES_TREECKO, 10, 3
# 208 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Treecko_Text_0, MSGBOX_YESNO
# 209 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_Treecko_1
# 231 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 232 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_Treecko_1:
# 210 "data/maps/NewBirchsLab/scripts.pory"
	givemon SPECIES_TREECKO, 50, ITEM_MASTER_BALL
# 211 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_Treecko_4
# 218 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_Treecko_5
# 226 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 227 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_2
	return

NewBirchsLab_EventScript_Treecko_4:
# 212 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 213 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Treecko_Text_1
# 214 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 2
# 215 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_TWO
# 216 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	return

NewBirchsLab_EventScript_Treecko_5:
# 219 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 220 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Treecko_Text_1
# 221 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 2
# 222 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_TWO
# 223 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	return


NewBirchsLab_EventScript_Chikorita::
# 238 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 239 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Chikorita_Text_0, MSGBOX_YESNO
# 240 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_Chikorita_1
# 262 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 263 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_Chikorita_1:
# 241 "data/maps/NewBirchsLab/scripts.pory"
	givemon SPECIES_CHIKORITA, 50, ITEM_MASTER_BALL
# 242 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_Chikorita_4
# 249 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_Chikorita_5
# 257 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 258 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_2
	return

NewBirchsLab_EventScript_Chikorita_4:
# 243 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 244 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Chikorita_Text_1
# 245 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 2
# 246 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_TWO
# 247 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	return

NewBirchsLab_EventScript_Chikorita_5:
# 250 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 251 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Chikorita_Text_1
# 252 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 2
# 253 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_TWO
# 254 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	return


NewBirchsLab_EventScript_Bulbasaur::
# 269 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic SPECIES_BULBASAUR, 10, 3
# 270 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Bulbasaur_Text_0, MSGBOX_YESNO
# 271 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_Bulbasaur_1
# 293 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 294 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_Bulbasaur_1:
# 272 "data/maps/NewBirchsLab/scripts.pory"
	givemon SPECIES_BULBASAUR, 50, ITEM_MASTER_BALL
# 273 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_Bulbasaur_4
# 280 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_Bulbasaur_5
# 288 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 289 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_2
	return

NewBirchsLab_EventScript_Bulbasaur_4:
# 274 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 275 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Bulbasaur_Text_1
# 276 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 2
# 277 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_TWO
# 278 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	return

NewBirchsLab_EventScript_Bulbasaur_5:
# 281 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 282 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Bulbasaur_Text_1
# 283 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 2
# 284 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_TWO
# 285 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	return


NewBirchsLab_EventScript_Torchic::
# 300 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic SPECIES_TORCHIC, 10, 3
# 301 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Torchic_Text_0, MSGBOX_YESNO
# 302 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_Torchic_1
# 324 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 325 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_Torchic_1:
# 303 "data/maps/NewBirchsLab/scripts.pory"
	givemon SPECIES_TORCHIC, 50, ITEM_MASTER_BALL
# 304 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_Torchic_4
# 311 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_Torchic_5
# 319 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 320 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_2
	return

NewBirchsLab_EventScript_Torchic_4:
# 305 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 306 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Torchic_Text_1
# 307 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 3
# 308 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_THREE
# 309 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	return

NewBirchsLab_EventScript_Torchic_5:
# 312 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 313 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Torchic_Text_1
# 314 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 3
# 315 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_THREE
# 316 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	return


NewBirchsLab_EventScript_Cyndaquil::
# 331 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 332 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Cyndaquil_Text_0, MSGBOX_YESNO
# 333 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_Cyndaquil_1
# 355 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 356 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_Cyndaquil_1:
# 334 "data/maps/NewBirchsLab/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 50, ITEM_MASTER_BALL
# 335 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_Cyndaquil_4
# 342 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_Cyndaquil_5
# 350 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 351 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_2
	return

NewBirchsLab_EventScript_Cyndaquil_4:
# 336 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 337 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Cyndaquil_Text_1
# 338 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 3
# 339 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_THREE
# 340 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	return

NewBirchsLab_EventScript_Cyndaquil_5:
# 343 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 344 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Cyndaquil_Text_1
# 345 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 3
# 346 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_THREE
# 347 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	return


NewBirchsLab_EventScript_Charmander::
# 362 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic SPECIES_CHARMANDER, 10, 3
# 363 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Charmander_Text_0, MSGBOX_YESNO
# 364 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_Charmander_1
# 386 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 387 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_Charmander_1:
# 365 "data/maps/NewBirchsLab/scripts.pory"
	givemon SPECIES_CHARMANDER, 50, ITEM_MASTER_BALL
# 366 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_Charmander_4
# 373 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_Charmander_5
# 381 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 382 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Mudkip_Text_2
	return

NewBirchsLab_EventScript_Charmander_4:
# 367 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 368 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Charmander_Text_1
# 369 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 3
# 370 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_THREE
# 371 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	return

NewBirchsLab_EventScript_Charmander_5:
# 374 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 375 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_Charmander_Text_1
# 376 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 3
# 377 "data/maps/NewBirchsLab/scripts.pory"
	setflag STARTER_BALL_THREE
# 378 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	return


NicknamePartyMon::
# 394 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 395 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 396 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 397 "data/maps/NewBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 398 "data/maps/NewBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 405 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 406 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 407 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 410 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NicknameBoxMon_Text_0
	return

NicknameBoxMon_2:
# 408 "data/maps/NewBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


NewBirchsLab_EventScript_Birch_Text_0:
# 14 "data/maps/NewBirchsLab/scripts.pory"
	.string "Hello, would you like to see more?$"

NewBirchsLab_EventScript_Birch_Text_1:
# 22 "data/maps/NewBirchsLab/scripts.pory"
	.string "Choose your Pokemon wisely$"

NewBirchsLab_EventScript_Birch_Text_2:
# 29 "data/maps/NewBirchsLab/scripts.pory"
	.string "Take care of your Pokemon$"

NewBirchsLab_EventScript_PokeballOne_Text_0:
# 53 "data/maps/NewBirchsLab/scripts.pory"
	.string "Don't Take Another$"

NewBirchsLab_EventScript_Mudkip_Text_0:
# 115 "data/maps/NewBirchsLab/scripts.pory"
	.string "Do you want to choose Mudkip?$"

NewBirchsLab_EventScript_Mudkip_Text_1:
# 120 "data/maps/NewBirchsLab/scripts.pory"
	.string "Recieved Mudkip$"

NewBirchsLab_EventScript_Mudkip_Text_2:
# 134 "data/maps/NewBirchsLab/scripts.pory"
	.string "No More Room$"

NewBirchsLab_EventScript_Totodile_Text_0:
# 146 "data/maps/NewBirchsLab/scripts.pory"
	.string "Do you want to choose Totodile?$"

NewBirchsLab_EventScript_Totodile_Text_1:
# 151 "data/maps/NewBirchsLab/scripts.pory"
	.string "Recieved Totodile$"

NewBirchsLab_EventScript_Squirtle_Text_0:
# 177 "data/maps/NewBirchsLab/scripts.pory"
	.string "Do you want to choose Squirtle?$"

NewBirchsLab_EventScript_Squirtle_Text_1:
# 182 "data/maps/NewBirchsLab/scripts.pory"
	.string "Recieved Squirtle$"

NewBirchsLab_EventScript_Treecko_Text_0:
# 208 "data/maps/NewBirchsLab/scripts.pory"
	.string "Do you want to choose Treecko?$"

NewBirchsLab_EventScript_Treecko_Text_1:
# 213 "data/maps/NewBirchsLab/scripts.pory"
	.string "Recieved Treecko$"

NewBirchsLab_EventScript_Chikorita_Text_0:
# 239 "data/maps/NewBirchsLab/scripts.pory"
	.string "Do you want to choose Chikorita?$"

NewBirchsLab_EventScript_Chikorita_Text_1:
# 244 "data/maps/NewBirchsLab/scripts.pory"
	.string "Recieved Chikorita$"

NewBirchsLab_EventScript_Bulbasaur_Text_0:
# 270 "data/maps/NewBirchsLab/scripts.pory"
	.string "Do you want to choose Bulbasaur?$"

NewBirchsLab_EventScript_Bulbasaur_Text_1:
# 275 "data/maps/NewBirchsLab/scripts.pory"
	.string "Recieved Bulbasaur$"

NewBirchsLab_EventScript_Torchic_Text_0:
# 301 "data/maps/NewBirchsLab/scripts.pory"
	.string "Do you want to choose Torchic?$"

NewBirchsLab_EventScript_Torchic_Text_1:
# 306 "data/maps/NewBirchsLab/scripts.pory"
	.string "Recieved Torchic$"

NewBirchsLab_EventScript_Cyndaquil_Text_0:
# 332 "data/maps/NewBirchsLab/scripts.pory"
	.string "Do you want to choose Cyndaquil?$"

NewBirchsLab_EventScript_Cyndaquil_Text_1:
# 337 "data/maps/NewBirchsLab/scripts.pory"
	.string "Recieved Cyndaquil$"

NewBirchsLab_EventScript_Charmander_Text_0:
# 363 "data/maps/NewBirchsLab/scripts.pory"
	.string "Do you want to choose Charmander?$"

NewBirchsLab_EventScript_Charmander_Text_1:
# 368 "data/maps/NewBirchsLab/scripts.pory"
	.string "Recieved Charmander$"

NicknamePartyMon_Text_0:
# 394 "data/maps/NewBirchsLab/scripts.pory"
	.string "Give a nickname?$"

NicknameBoxMon_Text_0:
# 410 "data/maps/NewBirchsLab/scripts.pory"
	.string "Transferred to PC$"

NewBirchsLab_NotChosen::
# 413 "data/maps/NewBirchsLab/scripts.pory"
	.string "You did not choose the Pokemon$"
