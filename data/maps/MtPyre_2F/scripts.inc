# 1 "data/maps/MtPyre_2F/scripts.pory"

# 2 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_MapScripts::
# 3 "data/maps/MtPyre_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
# 4 "data/maps/MtPyre_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
# 5 "data/maps/MtPyre_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
# 6 "data/maps/MtPyre_2F/scripts.pory"
	.byte 0
# 7 "data/maps/MtPyre_2F/scripts.pory"

# 8 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_SetHoleWarp:
# 9 "data/maps/MtPyre_2F/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 10 "data/maps/MtPyre_2F/scripts.pory"
	setholewarp MAP_MT_PYRE_1F
# 11 "data/maps/MtPyre_2F/scripts.pory"
	end
# 12 "data/maps/MtPyre_2F/scripts.pory"

# 13 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_EventScript_Woman::
# 14 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
# 15 "data/maps/MtPyre_2F/scripts.pory"
	end
# 16 "data/maps/MtPyre_2F/scripts.pory"

# 17 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_EventScript_PokefanM::
# 18 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
# 19 "data/maps/MtPyre_2F/scripts.pory"
	end
# 20 "data/maps/MtPyre_2F/scripts.pory"

# 21 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_EventScript_Mark::
# 22 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
# 23 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
# 24 "data/maps/MtPyre_2F/scripts.pory"
	end
# 25 "data/maps/MtPyre_2F/scripts.pory"

# 26 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_EventScript_Luke::
# 27 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
# 28 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
# 29 "data/maps/MtPyre_2F/scripts.pory"
	end
# 30 "data/maps/MtPyre_2F/scripts.pory"

# 31 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_EventScript_Dez::
# 32 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
# 33 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
# 34 "data/maps/MtPyre_2F/scripts.pory"
	end
# 35 "data/maps/MtPyre_2F/scripts.pory"

# 36 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_EventScript_Leah::
# 37 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
# 38 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
# 39 "data/maps/MtPyre_2F/scripts.pory"
	end
# 40 "data/maps/MtPyre_2F/scripts.pory"

# 41 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_EventScript_Zander::
# 42 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
# 43 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
# 44 "data/maps/MtPyre_2F/scripts.pory"
	end
# 45 "data/maps/MtPyre_2F/scripts.pory"

# 46 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_MemoriesOfSkitty:
# 47 "data/maps/MtPyre_2F/scripts.pory"
	.string "Memories of my darling SKITTY…\n"
# 48 "data/maps/MtPyre_2F/scripts.pory"
	.string "My eyes overflow thinking about it.$"
# 49 "data/maps/MtPyre_2F/scripts.pory"

# 50 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_TumbledFromFloorAbove:
# 51 "data/maps/MtPyre_2F/scripts.pory"
	.string "Ooch, ouch… There are holes in the\n"
# 52 "data/maps/MtPyre_2F/scripts.pory"
	.string "ground here and there.\p"
# 53 "data/maps/MtPyre_2F/scripts.pory"
	.string "I didn't notice and took a tumble from\n"
# 54 "data/maps/MtPyre_2F/scripts.pory"
	.string "the floor above.$"
# 55 "data/maps/MtPyre_2F/scripts.pory"

# 56 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_MarkIntro:
# 57 "data/maps/MtPyre_2F/scripts.pory"
	.string "Hey! Are you searching for POKéMON?\n"
# 58 "data/maps/MtPyre_2F/scripts.pory"
	.string "You came along after me! You're rude!$"
# 59 "data/maps/MtPyre_2F/scripts.pory"

# 60 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_MarkDefeat:
# 61 "data/maps/MtPyre_2F/scripts.pory"
	.string "Ayieeeeh!\n"
# 62 "data/maps/MtPyre_2F/scripts.pory"
	.string "I'm sorry, forgive me, please!$"
# 63 "data/maps/MtPyre_2F/scripts.pory"

# 64 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_MarkPostBattle:
# 65 "data/maps/MtPyre_2F/scripts.pory"
	.string "People don't come here often, so\n"
# 66 "data/maps/MtPyre_2F/scripts.pory"
	.string "I thought there'd be rare POKéMON.$"
# 67 "data/maps/MtPyre_2F/scripts.pory"

# 68 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_LukeIntro:
# 69 "data/maps/MtPyre_2F/scripts.pory"
	.string "LUKE: We're here on a dare.\p"
# 70 "data/maps/MtPyre_2F/scripts.pory"
	.string "Heheh, if I show her how cool I am,\n"
# 71 "data/maps/MtPyre_2F/scripts.pory"
	.string "she'll fall for me. I know it!\p"
# 72 "data/maps/MtPyre_2F/scripts.pory"
	.string "I know! I'll cream you and show her\n"
# 73 "data/maps/MtPyre_2F/scripts.pory"
	.string "how cool I am!$"
# 74 "data/maps/MtPyre_2F/scripts.pory"

# 75 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_LukeDefeat:
# 76 "data/maps/MtPyre_2F/scripts.pory"
	.string "LUKE: Whoopsie!$"
# 77 "data/maps/MtPyre_2F/scripts.pory"

# 78 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_LukePostBattle:
# 79 "data/maps/MtPyre_2F/scripts.pory"
	.string "LUKE: Well, we lost but that's okay!\n"
# 80 "data/maps/MtPyre_2F/scripts.pory"
	.string "I'm right here by your side.\l"
# 81 "data/maps/MtPyre_2F/scripts.pory"
	.string "We'll make it through this dare!$"
# 82 "data/maps/MtPyre_2F/scripts.pory"

# 83 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_LukeNotEnoughMons:
# 84 "data/maps/MtPyre_2F/scripts.pory"
	.string "LUKE: If you want to take me on,\n"
# 85 "data/maps/MtPyre_2F/scripts.pory"
	.string "bring some more POKéMON.\p"
# 86 "data/maps/MtPyre_2F/scripts.pory"
	.string "If you don't, I won't be able to show\n"
# 87 "data/maps/MtPyre_2F/scripts.pory"
	.string "off to my girl how cool I am!$"
# 88 "data/maps/MtPyre_2F/scripts.pory"

# 89 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_DezIntro:
# 90 "data/maps/MtPyre_2F/scripts.pory"
	.string "DEZ: I came here on a dare with my\n"
# 91 "data/maps/MtPyre_2F/scripts.pory"
	.string "boyfriend.\p"
# 92 "data/maps/MtPyre_2F/scripts.pory"
	.string "It's really scary, but I'm with my\n"
# 93 "data/maps/MtPyre_2F/scripts.pory"
	.string "boyfriend. It's okay.\p"
# 94 "data/maps/MtPyre_2F/scripts.pory"
	.string "I know! I'll get my boyfriend to look\n"
# 95 "data/maps/MtPyre_2F/scripts.pory"
	.string "cool by beating you!$"
# 96 "data/maps/MtPyre_2F/scripts.pory"

# 97 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_DezDefeat:
# 98 "data/maps/MtPyre_2F/scripts.pory"
	.string "DEZ: Waaaah! I'm scared!$"
# 99 "data/maps/MtPyre_2F/scripts.pory"

# 100 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_DezPostBattle:
# 101 "data/maps/MtPyre_2F/scripts.pory"
	.string "DEZ: We're lovey-dovey, so we don't\n"
# 102 "data/maps/MtPyre_2F/scripts.pory"
	.string "care if we lose!$"
# 103 "data/maps/MtPyre_2F/scripts.pory"

# 104 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_DezNotEnoughMons:
# 105 "data/maps/MtPyre_2F/scripts.pory"
	.string "DEZ: If you want to challenge us, you\n"
# 106 "data/maps/MtPyre_2F/scripts.pory"
	.string "should bring at least two POKéMON.\p"
# 107 "data/maps/MtPyre_2F/scripts.pory"
	.string "My boyfriend's strong.\n"
# 108 "data/maps/MtPyre_2F/scripts.pory"
	.string "Just one POKéMON won't do at all.$"
# 109 "data/maps/MtPyre_2F/scripts.pory"

# 110 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_LeahIntro:
# 111 "data/maps/MtPyre_2F/scripts.pory"
	.string "You are an unfamiliar sight…\n"
# 112 "data/maps/MtPyre_2F/scripts.pory"
	.string "Depart before anything befalls you!$"
# 113 "data/maps/MtPyre_2F/scripts.pory"

# 114 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_LeahDefeat:
# 115 "data/maps/MtPyre_2F/scripts.pory"
	.string "Hmm…\n"
# 116 "data/maps/MtPyre_2F/scripts.pory"
	.string "You're durable.$"
# 117 "data/maps/MtPyre_2F/scripts.pory"

# 118 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_LeahPostBattle:
# 119 "data/maps/MtPyre_2F/scripts.pory"
	.string "Our family has been TRAINERS here\n"
# 120 "data/maps/MtPyre_2F/scripts.pory"
	.string "since my great-grandmother's time…\p"
# 121 "data/maps/MtPyre_2F/scripts.pory"
	.string "It is my duty to protect this\n"
# 122 "data/maps/MtPyre_2F/scripts.pory"
	.string "mountain…$"
# 123 "data/maps/MtPyre_2F/scripts.pory"

# 124 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_ZanderIntro:
# 125 "data/maps/MtPyre_2F/scripts.pory"
	.string "Kiyaaaaah!\n"
# 126 "data/maps/MtPyre_2F/scripts.pory"
	.string "I'm terrified!$"
# 127 "data/maps/MtPyre_2F/scripts.pory"

# 128 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_ZanderDefeat:
# 129 "data/maps/MtPyre_2F/scripts.pory"
	.string "Nooooooo!\n"
# 130 "data/maps/MtPyre_2F/scripts.pory"
	.string "I lost my wits!$"
# 131 "data/maps/MtPyre_2F/scripts.pory"

# 132 "data/maps/MtPyre_2F/scripts.pory"
MtPyre_2F_Text_ZanderPostBattle:
# 133 "data/maps/MtPyre_2F/scripts.pory"
	.string "I get freaked out every time I see\n"
# 134 "data/maps/MtPyre_2F/scripts.pory"
	.string "anything move…\p"
# 135 "data/maps/MtPyre_2F/scripts.pory"
	.string "I shouldn't have come here to train…$"
