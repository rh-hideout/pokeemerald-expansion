# 1 "data/maps/VerdanturfTown/scripts.pory"

# 2 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_MapScripts::
# 3 "data/maps/VerdanturfTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
# 4 "data/maps/VerdanturfTown/scripts.pory"
	.byte 0
# 5 "data/maps/VerdanturfTown/scripts.pory"

# 6 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_OnTransition:
# 7 "data/maps/VerdanturfTown/scripts.pory"
	setflag FLAG_VISITED_VERDANTURF_TOWN
# 8 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 9 "data/maps/VerdanturfTown/scripts.pory"
	end
# 10 "data/maps/VerdanturfTown/scripts.pory"

# 11 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Twin::
# 12 "data/maps/VerdanturfTown/scripts.pory"
	lock
# 13 "data/maps/VerdanturfTown/scripts.pory"
	faceplayer
# 14 "data/maps/VerdanturfTown/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
# 15 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
# 16 "data/maps/VerdanturfTown/scripts.pory"
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
# 17 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement 0
# 18 "data/maps/VerdanturfTown/scripts.pory"
	release
# 19 "data/maps/VerdanturfTown/scripts.pory"
	end
# 20 "data/maps/VerdanturfTown/scripts.pory"

# 21 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_TwinTunnelOpen::
# 22 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
# 23 "data/maps/VerdanturfTown/scripts.pory"
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
# 24 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement 0
# 25 "data/maps/VerdanturfTown/scripts.pory"
	release
# 26 "data/maps/VerdanturfTown/scripts.pory"
	end
# 27 "data/maps/VerdanturfTown/scripts.pory"

# 28 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Man::
# 29 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
# 30 "data/maps/VerdanturfTown/scripts.pory"
	end
# 31 "data/maps/VerdanturfTown/scripts.pory"

# 32 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Camper::
# 33 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
# 34 "data/maps/VerdanturfTown/scripts.pory"
	end
# 35 "data/maps/VerdanturfTown/scripts.pory"

# 36 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Boy::
# 37 "data/maps/VerdanturfTown/scripts.pory"
	lock
# 38 "data/maps/VerdanturfTown/scripts.pory"
	faceplayer
# 39 "data/maps/VerdanturfTown/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
# 40 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
# 41 "data/maps/VerdanturfTown/scripts.pory"
	release
# 42 "data/maps/VerdanturfTown/scripts.pory"
	end
# 43 "data/maps/VerdanturfTown/scripts.pory"

# 44 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_BoyTunnelOpen::
# 45 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
# 46 "data/maps/VerdanturfTown/scripts.pory"
	release
# 47 "data/maps/VerdanturfTown/scripts.pory"
	end
# 48 "data/maps/VerdanturfTown/scripts.pory"

# 49 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_TownSign::
# 50 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
# 51 "data/maps/VerdanturfTown/scripts.pory"
	end
# 52 "data/maps/VerdanturfTown/scripts.pory"

# 53 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_WandasHouseSign::
# 54 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
# 55 "data/maps/VerdanturfTown/scripts.pory"
	end
# 56 "data/maps/VerdanturfTown/scripts.pory"

# 57 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_BattleTentSign::
# 58 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
# 59 "data/maps/VerdanturfTown/scripts.pory"
	end
# 60 "data/maps/VerdanturfTown/scripts.pory"

# 61 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_RusturfTunnelSign::
# 62 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
# 63 "data/maps/VerdanturfTown/scripts.pory"
	end
# 64 "data/maps/VerdanturfTown/scripts.pory"

# 65 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_ManTryingToDigTunnel:
# 66 "data/maps/VerdanturfTown/scripts.pory"
	.string "My papa told me.\p"
# 67 "data/maps/VerdanturfTown/scripts.pory"
	.string "He says this tunnel is full of\n"
# 68 "data/maps/VerdanturfTown/scripts.pory"
	.string "timid POKéMON.\p"
# 69 "data/maps/VerdanturfTown/scripts.pory"
	.string "They get all scared of loud noise and\n"
# 70 "data/maps/VerdanturfTown/scripts.pory"
	.string "make a big uproar.\p"
# 71 "data/maps/VerdanturfTown/scripts.pory"
	.string "So they had to stop the big tunnel\n"
# 72 "data/maps/VerdanturfTown/scripts.pory"
	.string "project.\p"
# 73 "data/maps/VerdanturfTown/scripts.pory"
	.string "But there's one man. He's trying to dig\n"
# 74 "data/maps/VerdanturfTown/scripts.pory"
	.string "the tunnel by himself!$"
# 75 "data/maps/VerdanturfTown/scripts.pory"

# 76 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_ManDugTunnelForLove:
# 77 "data/maps/VerdanturfTown/scripts.pory"
	.string "There was a man who dug a tunnel for\n"
# 78 "data/maps/VerdanturfTown/scripts.pory"
	.string "a lady he loved.\p"
# 79 "data/maps/VerdanturfTown/scripts.pory"
	.string "I don't really get it, but hey!$"
# 80 "data/maps/VerdanturfTown/scripts.pory"

# 81 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_AirCleanHere:
# 82 "data/maps/VerdanturfTown/scripts.pory"
	.string "The way the winds blow, volcanic ash\n"
# 83 "data/maps/VerdanturfTown/scripts.pory"
	.string "is never blown in this direction.\p"
# 84 "data/maps/VerdanturfTown/scripts.pory"
	.string "The air is clean and delicious here.\n"
# 85 "data/maps/VerdanturfTown/scripts.pory"
	.string "Living here should do wonders for even\l"
# 86 "data/maps/VerdanturfTown/scripts.pory"
	.string "frail and sickly people.$"
# 87 "data/maps/VerdanturfTown/scripts.pory"

# 88 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_MakeBattleTentDebut:
# 89 "data/maps/VerdanturfTown/scripts.pory"
	.string "My POKéMON and I, we've been riding\n"
# 90 "data/maps/VerdanturfTown/scripts.pory"
	.string "a hot winning streak.\p"
# 91 "data/maps/VerdanturfTown/scripts.pory"
	.string "So I decided to make my BATTLE TENT\n"
# 92 "data/maps/VerdanturfTown/scripts.pory"
	.string "debut in this town.$"
# 93 "data/maps/VerdanturfTown/scripts.pory"

# 94 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_GuyTryingToBustThroughCave:
# 95 "data/maps/VerdanturfTown/scripts.pory"
	.string "Did you see the cave next to the\n"
# 96 "data/maps/VerdanturfTown/scripts.pory"
	.string "POKéMON MART?\p"
# 97 "data/maps/VerdanturfTown/scripts.pory"
	.string "There's a guy in there who's trying to\n"
# 98 "data/maps/VerdanturfTown/scripts.pory"
	.string "bust up boulders so he can bust out\l"
# 99 "data/maps/VerdanturfTown/scripts.pory"
	.string "through to the other side.\p"
# 100 "data/maps/VerdanturfTown/scripts.pory"
	.string "It'd be great if we could go through…\n"
# 101 "data/maps/VerdanturfTown/scripts.pory"
	.string "It'll make it easy to visit RUSTBORO.$"
# 102 "data/maps/VerdanturfTown/scripts.pory"

# 103 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_EasyToGetToRustboroNow:
# 104 "data/maps/VerdanturfTown/scripts.pory"
	.string "That cave next to the POKéMON MART\n"
# 105 "data/maps/VerdanturfTown/scripts.pory"
	.string "is now a tunnel to the other side.\p"
# 106 "data/maps/VerdanturfTown/scripts.pory"
	.string "It's great--it's easy to go shop for\n"
# 107 "data/maps/VerdanturfTown/scripts.pory"
	.string "new DEVON products in RUSTBORO now.$"
# 108 "data/maps/VerdanturfTown/scripts.pory"

# 109 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_TownSign:
# 110 "data/maps/VerdanturfTown/scripts.pory"
	.string "VERDANTURF TOWN\p"
# 111 "data/maps/VerdanturfTown/scripts.pory"
	.string "“The windswept highlands with the\n"
# 112 "data/maps/VerdanturfTown/scripts.pory"
	.string "sweet fragrance of grass.”$"
# 113 "data/maps/VerdanturfTown/scripts.pory"

# 114 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_WandasHouse:
# 115 "data/maps/VerdanturfTown/scripts.pory"
	.string "WANDA'S HOUSE$"
# 116 "data/maps/VerdanturfTown/scripts.pory"

# 117 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_BattleTentSign:
# 118 "data/maps/VerdanturfTown/scripts.pory"
	.string "BATTLE TENT VERDANTURF SITE\n"
# 119 "data/maps/VerdanturfTown/scripts.pory"
	.string "“Feast Your Eyes on Battles!”$"
# 120 "data/maps/VerdanturfTown/scripts.pory"

# 121 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_RusturfTunnelSign:
# 122 "data/maps/VerdanturfTown/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 123 "data/maps/VerdanturfTown/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 124 "data/maps/VerdanturfTown/scripts.pory"
	.string "“The tunnel project has been\n"
# 125 "data/maps/VerdanturfTown/scripts.pory"
	.string "canceled.”$"
