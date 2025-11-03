# 1 "data/maps/SootopolisCity_House3/scripts.pory"

# 2 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_MapScripts::
# 3 "data/maps/SootopolisCity_House3/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_House3/scripts.pory"

# 5 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Woman::
# 6 "data/maps/SootopolisCity_House3/scripts.pory"
	lock
# 7 "data/maps/SootopolisCity_House3/scripts.pory"
	faceplayer
# 8 "data/maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
# 9 "data/maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
# 10 "data/maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
# 11 "data/maps/SootopolisCity_House3/scripts.pory"
	release
# 12 "data/maps/SootopolisCity_House3/scripts.pory"
	end
# 13 "data/maps/SootopolisCity_House3/scripts.pory"

# 14 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_HaveFans::
# 15 "data/maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
# 16 "data/maps/SootopolisCity_House3/scripts.pory"
	release
# 17 "data/maps/SootopolisCity_House3/scripts.pory"
	end
# 18 "data/maps/SootopolisCity_House3/scripts.pory"

# 19 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Girl::
# 20 "data/maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
# 21 "data/maps/SootopolisCity_House3/scripts.pory"
	end
# 22 "data/maps/SootopolisCity_House3/scripts.pory"

# 23 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_JuanHasManyFansDoYou:
# 24 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\p"
# 25 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "SOOTOPOLIS's JUAN has many fans.\n"
# 26 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Even more than his student WALLACE!\p"
# 27 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Do you have any?$"
# 28 "data/maps/SootopolisCity_House3/scripts.pory"

# 29 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_YouMustBePrettyStrong:
# 30 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, then you must be pretty strong.$"
# 31 "data/maps/SootopolisCity_House3/scripts.pory"

# 32 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
# 33 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, dear…\n"
# 34 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "That's a little lonesome.\p"
# 35 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Try working a little harder to get\n"
# 36 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "a fan following.$"
# 37 "data/maps/SootopolisCity_House3/scripts.pory"

# 38 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_TrainerFanClubWasWild:
# 39 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Dedicated fans come over from even\n"
# 40 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "outside of HOENN.\p"
# 41 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "It was really wild when I went to the\n"
# 42 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "TRAINER FAN CLUB in LILYCOVE.$"
