# 1 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 2 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_MapScripts::
# 3 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.byte 0
# 4 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 5 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
# 6 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	lock
# 7 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	faceplayer
# 8 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
# 9 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
# 10 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	switch VAR_RESULT
# 11 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
# 12 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
# 13 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
# 14 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
# 15 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
# 16 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
# 17 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
# 18 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 19 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 20 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 21 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
# 22 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
# 23 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 24 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 25 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 26 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
# 27 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
# 28 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 29 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 30 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 31 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
# 32 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
# 33 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 34 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 35 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 36 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
# 37 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
# 38 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 39 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 40 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 41 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
# 42 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
# 43 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 44 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 45 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 46 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
# 47 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
# 48 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 49 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 50 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 51 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
# 52 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
# 53 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 54 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 55 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 56 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
# 57 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	lock
# 58 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	faceplayer
# 59 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	waitse
# 60 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
# 61 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
# 62 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	waitmoncry
# 63 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 64 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 65 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 66 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
# 67 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Let me see your POKéMON.\n"
# 68 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "I'll check to see how much it likes you.\p"
# 69 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Oh.\n"
# 70 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Your POKéMON…$"
# 71 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 72 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
# 73 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It adores you.\n"
# 74 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It can't possibly love you any more.\l"
# 75 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "I even feel happy seeing it.$"
# 76 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 77 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
# 78 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It seems to be very happy.\n"
# 79 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It obviously likes you a whole lot.$"
# 80 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 81 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
# 82 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It likes you quite a lot.\n"
# 83 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It seems to want to be babied a little.$"
# 84 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 85 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
# 86 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It's getting used to you.\n"
# 87 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It seems to believe in you.$"
# 88 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 89 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
# 90 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It's not very used to you yet.\n"
# 91 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It neither loves nor hates you.$"
# 92 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 93 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
# 94 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It's very wary.\n"
# 95 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It has scary viciousness in its eyes.\l"
# 96 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It doesn't like you much at all.$"
# 97 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 98 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
# 99 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "This is a little hard for me to say…\p"
# 100 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Your POKéMON simply detests you.\n"
# 101 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Doesn't that make you uncomfortable?$"
# 102 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 103 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
# 104 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "PIKACHU: Pika pika!$"
