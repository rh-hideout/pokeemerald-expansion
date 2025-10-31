# 1 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 2 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_MapScripts::
# 3 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.byte 0
# 4 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 5 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_Wally::
# 6 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	lock
# 7 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	faceplayer
# 8 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
# 9 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
# 10 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	setflag FLAG_WALLY_SPEECH
# 11 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 12 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 13 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 14 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
# 15 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
# 16 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 17 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 18 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 19 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysUncle::
# 20 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	lock
# 21 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	faceplayer
# 22 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
# 23 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
# 24 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
# 25 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 26 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 27 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 28 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
# 29 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
# 30 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 31 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 32 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 33 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
# 34 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
# 35 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 36 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 37 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 38 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
# 39 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
# 40 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 41 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 42 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_Wanda::
# 43 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	lock
# 44 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	faceplayer
# 45 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
# 46 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
# 47 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
# 48 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 49 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 50 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 51 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_MeetWanda::
# 52 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
# 53 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 54 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 55 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 56 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
# 57 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
# 58 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 59 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 60 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 61 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysAunt::
# 62 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	lock
# 63 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	faceplayer
# 64 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
# 65 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
# 66 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
# 67 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
# 68 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 69 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 70 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 71 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
# 72 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
# 73 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 74 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 75 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 76 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
# 77 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
# 78 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 79 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 80 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 81 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
# 82 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
# 83 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 84 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 85 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 86 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_StrongerSpeech:
# 87 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "WALLY: I lost to you, {PLAYER}, but I'm\n"
# 88 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "not feeling down anymore.\p"
# 89 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Because I have a new purpose in life.\n"
# 90 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Together with my RALTS, I'm going\l"
# 91 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "to challenge POKéMON GYMS and become\l"
# 92 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "a great TRAINER.\p"
# 93 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Please watch me, {PLAYER}.\n"
# 94 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I'm going to be stronger than you.\p"
# 95 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "When I do, I'm going to challenge you\n"
# 96 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "to another battle.$"
# 97 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 98 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
# 99 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "WALLY: Please watch me, {PLAYER}.\n"
# 100 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I'm going to get stronger than you.\p"
# 101 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "When I do, I'm going to challenge you\n"
# 102 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "to another battle.$"
# 103 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 104 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_WallysNextDoor:
# 105 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "UNCLE: Oh! {PLAYER}{KUN}!\n"
# 106 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "WALLY's next door.\p"
# 107 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "But, boy, there's something I have to\n"
# 108 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "tell you.\p"
# 109 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "This natural environment is doing\n"
# 110 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "wonders for WALLY's health.\p"
# 111 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Maybe it's not just the environment.\n"
# 112 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "It could be POKéMON that are giving\l"
# 113 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "the boy hope.$"
# 114 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 115 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_WallySlippedOff:
# 116 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "WALLY's gone away…\n"
# 117 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "He slipped off on his own…$"
# 118 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 119 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
# 120 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "UNCLE: Is that right?\n"
# 121 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "WALLY's gone away that far all by\l"
# 122 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "himself…\p"
# 123 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Well, I have to give him credit--he is\n"
# 124 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "my little brother's son.$"
# 125 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 126 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_MeetWanda:
# 127 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "WANDA: You are?\n"
# 128 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Oh, right, I get it!\p"
# 129 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "You're the {PLAYER} who WALLY was\n"
# 130 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "telling me about.\p"
# 131 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I'm WALLY's cousin.\n"
# 132 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Glad to meet you!\p"
# 133 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I think WALLY's become a lot more lively\n"
# 134 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "and healthy since he came here.$"
# 135 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 136 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
# 137 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "WANDA: Don't worry about WALLY.\n"
# 138 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "He'll be just fine.\p"
# 139 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I know my little cousin, and he has\n"
# 140 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "POKéMON with him, too.$"
# 141 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 142 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
# 143 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Thanks to you, I can see my girlfriend\n"
# 144 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "every day.\l"
# 145 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Happy? You bet I am!$"
# 146 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 147 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
# 148 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "My daughter's boyfriend is a very\n"
# 149 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "driven and passionate sort of person.\p"
# 150 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "He's been digging a tunnel nonstop\n"
# 151 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "just so he can see my daughter.\p"
# 152 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "My daughter's a little concerned,\n"
# 153 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "so she goes out to the tunnel a lot.$"
# 154 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 155 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
# 156 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "It's amazing. My daughter's boyfriend\n"
# 157 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "was digging the tunnel by hand!\p"
# 158 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "It's so incredible!$"
# 159 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 160 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
# 161 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "If anything were to happen to WALLY,\n"
# 162 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I would never be able to look his\l"
# 163 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "parents in PETALBURG in the eye…$"
# 164 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 165 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
# 166 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "WALLY was in EVER GRANDE?\p"
# 167 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "His parents in PETALBURG would be\n"
# 168 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "astonished to hear that!$"
