# 1 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 2 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_MapScripts::
# 3 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 5 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
# 6 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	lockall
# 7 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
# 8 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
# 9 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
# 10 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
# 11 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 12 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
# 13 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 14 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
# 15 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 16 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	releaseall
# 17 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	end
# 18 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 19 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
# 20 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
# 21 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
# 22 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 23 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
# 24 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 25 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
# 26 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 27 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	releaseall
# 28 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	end
# 29 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 30 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
# 31 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
# 32 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
# 33 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 34 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
# 35 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 36 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
# 37 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 38 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	releaseall
# 39 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	end
# 40 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 41 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
# 42 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	lockall
# 43 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	playse SE_PIN
# 44 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
# 45 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 46 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
# 47 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 48 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 49 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 50 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
# 51 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 52 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
# 53 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
# 54 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 55 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
# 56 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 57 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	release
# 58 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	end
# 59 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 60 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
# 61 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_right
# 62 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	lock_facing_direction
# 63 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_left
# 64 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	unlock_facing_direction
# 65 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	step_end
# 66 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 67 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
# 68 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_up
# 69 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	step_end
# 70 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 71 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
# 72 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_down
# 73 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_down
# 74 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_up
# 75 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	step_end
# 76 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 77 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
# 78 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Hm, so they doubled the guests by\n"
# 79 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "using POKéMON as attractions?\p"
# 80 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Hm, well, maybe I should make a cute\n"
# 81 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "POKéMON our inn's mascot.\p"
# 82 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I wonder if that will attract more\n"
# 83 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "guests to stay with us?$"
# 84 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 85 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
# 86 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Oh, sorry, sorry!\n"
# 87 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I was too involved in watching TV!\p"
# 88 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Since that TEAM AQUA came to town,\n"
# 89 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "the tourists have been staying away.$"
# 90 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 91 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
# 92 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Hey, down in front!\n"
# 93 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I can't see the TV!$"
# 94 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 95 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
# 96 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Amazing! You're telling me a POKéMON\n"
# 97 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "found someone's lost item?\p"
# 98 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "That's something. If we had some smart\n"
# 99 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "POKéMON like that…\p"
# 100 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "We could recover anything that our\n"
# 101 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "guests mislaid…$"
# 102 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 103 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
# 104 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Oh, sorry, sorry!\n"
# 105 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I was too involved in watching TV!\p"
# 106 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I heard that someone busted\n"
# 107 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "the TEAM AQUA HIDEOUT.\p"
# 108 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Thanks to that, we just booked\n"
# 109 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "a reservation from a big group.\p"
# 110 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "It was a company called… Uh…\n"
# 111 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "GAME something…$"
# 112 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 113 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
# 114 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Amazing! A house-sitting POKéMON\n"
# 115 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "caught a burglar?\p"
# 116 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "That's something. If we had a tough\n"
# 117 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "POKéMON as a security guard…\p"
# 118 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "We would be able to provide our guests\n"
# 119 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "with greater safety.$"
# 120 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 121 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
# 122 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Oh, sorry, sorry!\n"
# 123 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I was too involved in watching TV.\p"
# 124 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Oh, yes. A big group of guests arrived\n"
# 125 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "a little while ago.\p"
# 126 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "They booked in as GAME FREAK,\n"
# 127 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "so I guess they must make games.\p"
# 128 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Uh-oh, I'd better get working on\n"
# 129 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "their dinner!$"
