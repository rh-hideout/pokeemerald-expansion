# 1 "data/maps/MirageTower_4F/scripts.pory"

# 2 "data/maps/MirageTower_4F/scripts.pory"
.set LOCALID_ROOT_FOSSIL, 1
# 3 "data/maps/MirageTower_4F/scripts.pory"
.set LOCALID_CLAW_FOSSIL, 2
# 4 "data/maps/MirageTower_4F/scripts.pory"

# 5 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_MapScripts::
# 6 "data/maps/MirageTower_4F/scripts.pory"
	.byte 0
# 7 "data/maps/MirageTower_4F/scripts.pory"

# 8 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_Fossil::
# 9 "data/maps/MirageTower_4F/scripts.pory"
	lock
# 10 "data/maps/MirageTower_4F/scripts.pory"
	random 15
# 11 "data/maps/MirageTower_4F/scripts.pory"
	addvar VAR_RESULT, ITEM_HELIX_FOSSIL
# 12 "data/maps/MirageTower_4F/scripts.pory"
	finditem VAR_RESULT
# 13 "data/maps/MirageTower_4F/scripts.pory"
	waitmessage
# 14 "data/maps/MirageTower_4F/scripts.pory"
	waitfanfare
# 15 "data/maps/MirageTower_4F/scripts.pory"
	delay 30
# 16 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_DAILY_FOSSIL_RECEIVED
# 17 "data/maps/MirageTower_4F/scripts.pory"
    clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
# 18 "data/maps/MirageTower_4F/scripts.pory"
	end
