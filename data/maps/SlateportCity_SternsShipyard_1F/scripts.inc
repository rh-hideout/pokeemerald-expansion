# 1 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 2 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_MapScripts::
# 3 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.byte 0
# 4 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 5 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Dock::
# 6 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	lockall
# 7 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
# 8 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
# 9 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
# 10 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
# 11 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
# 12 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 13 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 14 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
# 15 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	closemessage
# 16 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
# 17 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 18 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
# 19 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
# 20 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 21 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 22 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 23 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
# 24 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 25 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 26 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
# 27 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 28 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 29 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 30 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
# 31 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 32 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 33 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
# 34 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 35 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 36 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 37 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
# 38 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 39 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 40 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
# 41 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	closemessage
# 42 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
# 43 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 44 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 45 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 46 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 47 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
# 48 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 49 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 50 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
# 51 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 52 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 53 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 54 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
# 55 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
# 56 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 57 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 58 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
# 59 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
# 60 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 61 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 62 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Briney::
# 63 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
# 64 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 65 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 66 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
# 67 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Umm… If this goes here, and that\n"
# 68 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "goes over there…\p"
# 69 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Then where does this thing go?\n"
# 70 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "And what about that doohickey?\p"
# 71 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Aaargh! I can't make heads or tails\n"
# 72 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "of this!$"
# 73 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 74 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
# 75 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Hm?\n"
# 76 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Hi, I'm DOCK.\p"
# 77 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "CAPT. STERN commissioned me to\n"
# 78 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "design a ferry.\p"
# 79 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Oh! That there…\n"
# 80 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Are they DEVON GOODS?\p"
# 81 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "But, hmm…\n"
# 82 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "This won't do…\p"
# 83 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "CAPT. STERN went off somewhere.\n"
# 84 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "He said he had some work to do.\p"
# 85 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Could I get you to go find CAPT.\n"
# 86 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "STERN and deliver that to him?$"
# 87 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 88 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
# 89 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "DOCK: Where could CAPT. STERN have\n"
# 90 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "gone off to?\p"
# 91 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Could you go find CAPT. STERN and\n"
# 92 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "deliver that parcel to him?$"
# 93 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 94 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
# 95 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "DOCK: Shipbuilding is an art.\p"
# 96 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "A lot of things can't be figured out\n"
# 97 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "just by calculating.\p"
# 98 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "I really could use advice from a veteran\n"
# 99 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "who knows the seas…$"
# 100 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 101 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
# 102 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "DOCK: Hi! MR. BRINEY's joined us to\n"
# 103 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "lend us his help.\p"
# 104 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Thanks to the veteran sailor, the\n"
# 105 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "ferry is steadily coming together.$"
# 106 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 107 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
# 108 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "DOCK: The ferry is finally ready!\p"
# 109 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "The new S.S. TIDAL is truly a marvel\n"
# 110 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "of technology!\p"
# 111 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "But, I get the feeling that we can\n"
# 112 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "make something even better.\p"
# 113 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "You know, there's never an end to\n"
# 114 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "technology's march.$"
# 115 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 116 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
# 117 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "MR. BRINEY: Ah, {PLAYER}{KUN}!\n"
# 118 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "It's been too long!\p"
# 119 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Aye, since I met you, this old sea dog's\n"
# 120 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "been feeling frisky!\p"
# 121 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "So I've decided to help DOCK make\n"
# 122 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "a ferry.\p"
# 123 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Aye, after all, a ferry would be able\n"
# 124 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "to carry a lot of people.\p"
# 125 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "But, you know, that DOCK is really\n"
# 126 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "something special.\p"
# 127 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "With his knack for technology and\n"
# 128 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "my experience, I'm sure that we can\l"
# 129 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "build one great ship, aye!$"
# 130 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 131 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
# 132 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "The seasons, the weather, where\n"
# 133 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "the moon sits in the sky…\p"
# 134 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "These and other conditions make\n"
# 135 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "the sea change its expression.\p"
# 136 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "That's right!\n"
# 137 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "The sea is like a living thing!$"
# 138 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 139 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
# 140 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "I get seasick real easily.\n"
# 141 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "So I get to help out here instead.$"
