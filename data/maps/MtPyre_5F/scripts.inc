# 1 "data/maps/MtPyre_5F/scripts.pory"

# 2 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_5F_MapScripts::
# 3 "data/maps/MtPyre_5F/scripts.pory"
	.byte 0
# 4 "data/maps/MtPyre_5F/scripts.pory"

# 5 "data/maps/MtPyre_5F/scripts.pory"
@ Seems like the scripts for the 4F and 5F were swapped
# 6 "data/maps/MtPyre_5F/scripts.pory"

# 7 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_4F_EventScript_Tasha::
# 8 "data/maps/MtPyre_5F/scripts.pory"
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
# 9 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
# 10 "data/maps/MtPyre_5F/scripts.pory"
	end
# 11 "data/maps/MtPyre_5F/scripts.pory"

# 12 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_4F_Text_TashaIntro:
# 13 "data/maps/MtPyre_5F/scripts.pory"
	.string "I love all things horrifying…\n"
# 14 "data/maps/MtPyre_5F/scripts.pory"
	.string "It's like a disease…\p"
# 15 "data/maps/MtPyre_5F/scripts.pory"
	.string "When I'm here…\n"
# 16 "data/maps/MtPyre_5F/scripts.pory"
	.string "I shiver with fear…$"
# 17 "data/maps/MtPyre_5F/scripts.pory"

# 18 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_4F_Text_TashaDefeat:
# 19 "data/maps/MtPyre_5F/scripts.pory"
	.string "Losing, I dislike…$"
# 20 "data/maps/MtPyre_5F/scripts.pory"

# 21 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_4F_Text_TashaPostBattle:
# 22 "data/maps/MtPyre_5F/scripts.pory"
	.string "I want to see dreadful things…\n"
# 23 "data/maps/MtPyre_5F/scripts.pory"
	.string "I can't leave…\p"
# 24 "data/maps/MtPyre_5F/scripts.pory"
	.string "Stay…\n"
# 25 "data/maps/MtPyre_5F/scripts.pory"
	.string "Won't you stay with me?$"
