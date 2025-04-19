# 1 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 2 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
.set LOCALID_DOCK, 1
# 3 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 4 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_MapScripts::
# 5 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.byte 0
# 6 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 7 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Dock::
# 8 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	lockall
# 9 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
# 10 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
# 11 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
# 12 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
# 13 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
# 14 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 15 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 16 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
# 17 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	closemessage
# 18 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
# 19 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 20 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
# 21 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
# 22 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 23 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 24 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 25 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
# 26 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 27 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 28 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
# 29 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 30 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 31 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 32 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
# 33 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 34 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 35 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
# 36 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 37 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 38 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 39 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
# 40 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 41 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 42 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
# 43 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	closemessage
# 44 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
# 45 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 46 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 47 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 48 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 49 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
# 50 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 51 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 52 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
# 53 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 54 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 55 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 56 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
# 57 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
# 58 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 59 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 60 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
# 61 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
# 62 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 63 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 64 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Briney::
# 65 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
# 66 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 67 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 68 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
# 69 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Umm… If this goes here, and that\n"
# 70 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "goes over there…\p"
# 71 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Then where does this thing go?\n"
# 72 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "And what about that doohickey?\p"
# 73 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Aaargh! I can't make heads or tails\n"
# 74 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "of this!$"
# 75 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 76 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
# 77 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Hm?\n"
# 78 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Hi, I'm DOCK.\p"
# 79 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "CAPT. STERN commissioned me to\n"
# 80 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "design a ferry.\p"
# 81 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Oh! That there…\n"
# 82 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Are they DEVON GOODS?\p"
# 83 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "But, hmm…\n"
# 84 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "This won't do…\p"
# 85 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "CAPT. STERN went off somewhere.\n"
# 86 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "He said he had some work to do.\p"
# 87 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Could I get you to go find CAPT.\n"
# 88 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "STERN and deliver that to him?$"
# 89 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 90 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
# 91 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "DOCK: Where could CAPT. STERN have\n"
# 92 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "gone off to?\p"
# 93 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Could you go find CAPT. STERN and\n"
# 94 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "deliver that parcel to him?$"
# 95 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 96 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
# 97 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "DOCK: Shipbuilding is an art.\p"
# 98 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "A lot of things can't be figured out\n"
# 99 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "just by calculating.\p"
# 100 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "I really could use advice from a veteran\n"
# 101 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "who knows the seas…$"
# 102 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 103 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
# 104 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "DOCK: Hi! MR. BRINEY's joined us to\n"
# 105 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "lend us his help.\p"
# 106 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Thanks to the veteran sailor, the\n"
# 107 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "ferry is steadily coming together.$"
# 108 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 109 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
# 110 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "DOCK: The ferry is finally ready!\p"
# 111 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "The new S.S. TIDAL is truly a marvel\n"
# 112 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "of technology!\p"
# 113 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "But, I get the feeling that we can\n"
# 114 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "make something even better.\p"
# 115 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "You know, there's never an end to\n"
# 116 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "technology's march.$"
# 117 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 118 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
# 119 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "MR. BRINEY: Ah, {PLAYER}{KUN}!\n"
# 120 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "It's been too long!\p"
# 121 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Aye, since I met you, this old sea dog's\n"
# 122 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "been feeling frisky!\p"
# 123 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "So I've decided to help DOCK make\n"
# 124 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "a ferry.\p"
# 125 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Aye, after all, a ferry would be able\n"
# 126 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "to carry a lot of people.\p"
# 127 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "But, you know, that DOCK is really\n"
# 128 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "something special.\p"
# 129 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "With his knack for technology and\n"
# 130 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "my experience, I'm sure that we can\l"
# 131 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "build one great ship, aye!$"
# 132 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 133 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
# 134 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "The seasons, the weather, where\n"
# 135 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "the moon sits in the sky…\p"
# 136 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "These and other conditions make\n"
# 137 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "the sea change its expression.\p"
# 138 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "That's right!\n"
# 139 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "The sea is like a living thing!$"
# 140 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 141 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
# 142 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "I get seasick real easily.\n"
# 143 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "So I get to help out here instead.$"
