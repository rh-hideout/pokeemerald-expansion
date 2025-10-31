# 1 "data/maps/LilycoveCity_House3/scripts.pory"

# 2 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_MapScripts::
# 3 "data/maps/LilycoveCity_House3/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
# 4 "data/maps/LilycoveCity_House3/scripts.pory"
	.byte 0
# 5 "data/maps/LilycoveCity_House3/scripts.pory"

# 6 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_OnTransition:
# 7 "data/maps/LilycoveCity_House3/scripts.pory"
	random 4
# 8 "data/maps/LilycoveCity_House3/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 9 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 10 "data/maps/LilycoveCity_House3/scripts.pory"

# 11 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_PokefanF::
# 12 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 13 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 14 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
# 15 "data/maps/LilycoveCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
# 16 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
# 17 "data/maps/LilycoveCity_House3/scripts.pory"
	closemessage
# 18 "data/maps/LilycoveCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 19 "data/maps/LilycoveCity_House3/scripts.pory"
	waitmovement 0
# 20 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 21 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 22 "data/maps/LilycoveCity_House3/scripts.pory"

# 23 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
# 24 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
# 25 "data/maps/LilycoveCity_House3/scripts.pory"
	closemessage
# 26 "data/maps/LilycoveCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 27 "data/maps/LilycoveCity_House3/scripts.pory"
	waitmovement 0
# 28 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 29 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 30 "data/maps/LilycoveCity_House3/scripts.pory"

# 31 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_Man::
# 32 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 33 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 34 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
# 35 "data/maps/LilycoveCity_House3/scripts.pory"
	closemessage
# 36 "data/maps/LilycoveCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 37 "data/maps/LilycoveCity_House3/scripts.pory"
	waitmovement 0
# 38 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 39 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 40 "data/maps/LilycoveCity_House3/scripts.pory"

# 41 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_GameBoyKid1::
# 42 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 43 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 44 "data/maps/LilycoveCity_House3/scripts.pory"
	switch VAR_TEMP_1
# 45 "data/maps/LilycoveCity_House3/scripts.pory"
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
# 46 "data/maps/LilycoveCity_House3/scripts.pory"
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
# 47 "data/maps/LilycoveCity_House3/scripts.pory"
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
# 48 "data/maps/LilycoveCity_House3/scripts.pory"
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
# 49 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 50 "data/maps/LilycoveCity_House3/scripts.pory"

# 51 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_GameBoyKid2::
# 52 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 53 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 54 "data/maps/LilycoveCity_House3/scripts.pory"
	switch VAR_TEMP_1
# 55 "data/maps/LilycoveCity_House3/scripts.pory"
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
# 56 "data/maps/LilycoveCity_House3/scripts.pory"
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
# 57 "data/maps/LilycoveCity_House3/scripts.pory"
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
# 58 "data/maps/LilycoveCity_House3/scripts.pory"
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
# 59 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 60 "data/maps/LilycoveCity_House3/scripts.pory"

# 61 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_GameBoyKid3::
# 62 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 63 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 64 "data/maps/LilycoveCity_House3/scripts.pory"
	switch VAR_TEMP_1
# 65 "data/maps/LilycoveCity_House3/scripts.pory"
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
# 66 "data/maps/LilycoveCity_House3/scripts.pory"
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
# 67 "data/maps/LilycoveCity_House3/scripts.pory"
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
# 68 "data/maps/LilycoveCity_House3/scripts.pory"
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
# 69 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 70 "data/maps/LilycoveCity_House3/scripts.pory"

# 71 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_GameBoyKid4::
# 72 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 73 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 74 "data/maps/LilycoveCity_House3/scripts.pory"
	switch VAR_TEMP_1
# 75 "data/maps/LilycoveCity_House3/scripts.pory"
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
# 76 "data/maps/LilycoveCity_House3/scripts.pory"
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
# 77 "data/maps/LilycoveCity_House3/scripts.pory"
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
# 78 "data/maps/LilycoveCity_House3/scripts.pory"
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
# 79 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 80 "data/maps/LilycoveCity_House3/scripts.pory"

# 81 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_WereDoingMultiBattle::
# 82 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
# 83 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 84 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 85 "data/maps/LilycoveCity_House3/scripts.pory"

# 86 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_WereMixingRecords::
# 87 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
# 88 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 89 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 90 "data/maps/LilycoveCity_House3/scripts.pory"

# 91 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_WereBlendingBerries::
# 92 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
# 93 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 94 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 95 "data/maps/LilycoveCity_House3/scripts.pory"

# 96 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_WereDoingContest::
# 97 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
# 98 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 99 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 100 "data/maps/LilycoveCity_House3/scripts.pory"

# 101 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
# 102 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Oh, my, my! Are you traveling alone?\n"
# 103 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "But you're so young! Good for you!\p"
# 104 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "I'm sure my kids could learn a thing\n"
# 105 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "or two from you!\p"
# 106 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Me? I'm a master of {POKEBLOCK}S.\p"
# 107 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "If I get serious just a little, why,\n"
# 108 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "I can concoct great {POKEBLOCK}S.\p"
# 109 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Would you like to learn from me,\n"
# 110 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "a master of {POKEBLOCK}S?$"
# 111 "data/maps/LilycoveCity_House3/scripts.pory"

# 112 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_OhAreYouSure:
# 113 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Oh? Are you sure?\p"
# 114 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "You shouldn't always try to do\n"
# 115 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "everything by yourself, dear!$"
# 116 "data/maps/LilycoveCity_House3/scripts.pory"

# 117 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_ExplainPokeblocks:
# 118 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Oh, good! You're a smart soul!\n"
# 119 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "This is a bit long, so listen up!\p"
# 120 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Are you ready?\p"
# 121 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "If you look at {POKEBLOCK}S, you should see\n"
# 122 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "that they are rated on how they feel.\p"
# 123 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "The lower the feel rating,\n"
# 124 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "the better it is. Don't forget this!\p"
# 125 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "A good {POKEBLOCK} has a low feel\n"
# 126 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "rating and a high level.\p"
# 127 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "A POKéMON can eat more good\n"
# 128 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "{POKEBLOCK}S than ordinary ones, too.\p"
# 129 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "And this is important.\p"
# 130 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "If you want to make smooth {POKEBLOCK}S,\n"
# 131 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "use different kinds of BERRIES.\p"
# 132 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Don't be stingy--the kinds of BERRIES\n"
# 133 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "affect the smoothness of {POKEBLOCK}S.\p"
# 134 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "And another thing.\p"
# 135 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "The more people blending BERRIES,\n"
# 136 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "the smoother the {POKEBLOCK}S.\p"
# 137 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "That's why you should talk to other\n"
# 138 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "people and make {POKEBLOCK}S together.\p"
# 139 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "That's about all you need to know to\n"
# 140 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "make good {POKEBLOCK}S.\p"
# 141 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "If everyone had POKéMON they love,\n"
# 142 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "smooth {POKEBLOCK}S, and a loving family,\l"
# 143 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "the world would be a happier place.\p"
# 144 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Don't give up, dear!$"
# 145 "data/maps/LilycoveCity_House3/scripts.pory"

# 146 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_HappyToHaveQuadruplets:
# 147 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "When my wife gave birth to quadruplets,\n"
# 148 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "you bet I was shocked.\p"
# 149 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "But, now, seeing them play together,\n"
# 150 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "it makes me happy.$"
# 151 "data/maps/LilycoveCity_House3/scripts.pory"

# 152 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_GoingToWinMultiBattles:
# 153 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "We're having MULTI BATTLES, but I know\n"
# 154 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "I'm going to win.$"
# 155 "data/maps/LilycoveCity_House3/scripts.pory"

# 156 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
# 157 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "We like mixing stuff at\n"
# 158 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "the RECORD CORNER.\p"
# 159 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "But what gets mixed up?$"
# 160 "data/maps/LilycoveCity_House3/scripts.pory"

# 161 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
# 162 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "We're going to make super {POKEBLOCK}S\n"
# 163 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "with a BERRY BLENDER!$"
# 164 "data/maps/LilycoveCity_House3/scripts.pory"

# 165 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_GoingToEnterContest:
# 166 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "I want to brag about how tough my\n"
# 167 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "POKéMON is, so we're going to enter\l"
# 168 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "a CONTEST together.$"
