# 1 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 2 "data/maps/MeteorFalls_StevensCave/scripts.pory"
.set LOCALID_STEVEN, 1
# 3 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 4 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_MapScripts::
# 5 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.byte 0
# 6 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 7 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_EventScript_Steven::
# 8 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	lock
# 9 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
# 10 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitse
# 11 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	playse SE_PIN
# 12 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
# 13 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitmovement 0
# 14 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
# 15 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitmovement 0
# 16 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
# 17 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitmovement 0
# 18 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
# 19 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
# 20 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
# 21 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
# 22 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	release
# 23 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	end
# 24 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 25 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_EventScript_Defeated::
# 26 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
# 27 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitmovement 0
# 28 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
# 29 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	release
# 30 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	end
# 31 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 32 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
# 33 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "STEVEN: Oh, wow, {PLAYER}{KUN}.\n"
# 34 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "I'm amazed you knew where to find me.\p"
# 35 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Do you, uh…maybe think of me as\n"
# 36 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "just a rock maniac?\p"
# 37 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "No, that can't be right.\p"
# 38 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "We battled alongside each other at\n"
# 39 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "the SOOTOPOLIS SPACE CENTER.\p"
# 40 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "You should have a very good idea\n"
# 41 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "about how good I am.\p"
# 42 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Okay, {PLAYER}{KUN}, if you're going to mount\n"
# 43 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "a serious challenge, expect the worst!$"
# 44 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 45 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_Text_StevenDefeat:
# 46 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "You…\n"
# 47 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "I had no idea you'd become so strong…$"
# 48 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 49 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
# 50 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "STEVEN: Come to think of it, ever since\n"
# 51 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "our paths first crossed in GRANITE\l"
# 52 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "CAVE in DEWFORD, I had this feeling.\p"
# 53 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "I thought that you would eventually\n"
# 54 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "become the CHAMPION.\p"
# 55 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "My predictions usually come true.\p"
# 56 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "And where will you go from here?\p"
# 57 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "… … … … … …\n"
# 58 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "… … … … … …\p"
# 59 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Fufufu, even I couldn't tell you that.$"
