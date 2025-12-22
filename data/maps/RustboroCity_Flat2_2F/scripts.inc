# 1 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 2 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_MapScripts::
# 3 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 5 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_EventScript_OldMan::
# 6 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
# 7 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	end
# 8 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 9 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_EventScript_NinjaBoy::
# 10 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	lock
# 11 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	faceplayer
# 12 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	goto_if_set FLAG_LOW_SWEEP_TM, RustboroCity_Flat2_2F_EventScript_GavePremierBall
# 13 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
# 14 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	giveitem ITEM_TM_LOW_SWEEP
# 15 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 16 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	setflag FLAG_LOW_SWEEP_TM
# 17 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	release
# 18 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	end
# 19 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 20 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_EventScript_GavePremierBall::
# 21 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
# 22 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	release
# 23 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	end
# 24 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 25 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
# 26 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "Way back in the old days, DEVON was just\n"
# 27 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "a teeny, tiny company.$"
# 28 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 29 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 30 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
# 31 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "My daddy's working at the CORPORATION.\p"
# 32 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "When I grow up, I'm going to work for\n"
# 33 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "DEVON, too.$"
# 34 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 35 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 36 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
# 37 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
    .string "My dad got this from his job!\n"
# 38 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
    .string "This move is so tough!$"
