# 1 "data/maps/VerdanturfTown/scripts.pory"

# 2 "data/maps/VerdanturfTown/scripts.pory"
.set LOCALID_TWIN, 2
# 3 "data/maps/VerdanturfTown/scripts.pory"

# 4 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_MapScripts::
# 5 "data/maps/VerdanturfTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
# 6 "data/maps/VerdanturfTown/scripts.pory"
	.byte 0
# 7 "data/maps/VerdanturfTown/scripts.pory"

# 8 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_OnTransition:
# 9 "data/maps/VerdanturfTown/scripts.pory"
	setflag FLAG_VISITED_VERDANTURF_TOWN
# 10 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 11 "data/maps/VerdanturfTown/scripts.pory"
	end
# 12 "data/maps/VerdanturfTown/scripts.pory"

# 13 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Twin::
# 14 "data/maps/VerdanturfTown/scripts.pory"
	lock
# 15 "data/maps/VerdanturfTown/scripts.pory"
	faceplayer
# 16 "data/maps/VerdanturfTown/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
# 17 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
# 18 "data/maps/VerdanturfTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 19 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement 0
# 20 "data/maps/VerdanturfTown/scripts.pory"
	release
# 21 "data/maps/VerdanturfTown/scripts.pory"
	end
# 22 "data/maps/VerdanturfTown/scripts.pory"

# 23 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_TwinTunnelOpen::
# 24 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
# 25 "data/maps/VerdanturfTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 26 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement 0
# 27 "data/maps/VerdanturfTown/scripts.pory"
	release
# 28 "data/maps/VerdanturfTown/scripts.pory"
	end
# 29 "data/maps/VerdanturfTown/scripts.pory"

# 30 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Man::
# 31 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
# 32 "data/maps/VerdanturfTown/scripts.pory"
	end
# 33 "data/maps/VerdanturfTown/scripts.pory"

# 34 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Camper::
# 35 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
# 36 "data/maps/VerdanturfTown/scripts.pory"
	end
# 37 "data/maps/VerdanturfTown/scripts.pory"

# 38 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Boy::
# 39 "data/maps/VerdanturfTown/scripts.pory"
	lock
# 40 "data/maps/VerdanturfTown/scripts.pory"
	faceplayer
# 41 "data/maps/VerdanturfTown/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
# 42 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
# 43 "data/maps/VerdanturfTown/scripts.pory"
	release
# 44 "data/maps/VerdanturfTown/scripts.pory"
	end
# 45 "data/maps/VerdanturfTown/scripts.pory"

# 46 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_BoyTunnelOpen::
# 47 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
# 48 "data/maps/VerdanturfTown/scripts.pory"
	release
# 49 "data/maps/VerdanturfTown/scripts.pory"
	end
# 50 "data/maps/VerdanturfTown/scripts.pory"

# 51 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_TownSign::
# 52 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
# 53 "data/maps/VerdanturfTown/scripts.pory"
	end
# 54 "data/maps/VerdanturfTown/scripts.pory"

# 55 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_WandasHouseSign::
# 56 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
# 57 "data/maps/VerdanturfTown/scripts.pory"
	end
# 58 "data/maps/VerdanturfTown/scripts.pory"

# 59 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_BattleTentSign::
# 60 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
# 61 "data/maps/VerdanturfTown/scripts.pory"
	end
# 62 "data/maps/VerdanturfTown/scripts.pory"

# 63 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_RusturfTunnelSign::
# 64 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
# 65 "data/maps/VerdanturfTown/scripts.pory"
	end
# 66 "data/maps/VerdanturfTown/scripts.pory"

# 67 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_ManTryingToDigTunnel:
# 68 "data/maps/VerdanturfTown/scripts.pory"
	.string "My papa told me.\p"
# 69 "data/maps/VerdanturfTown/scripts.pory"
	.string "He says this tunnel is full of\n"
# 70 "data/maps/VerdanturfTown/scripts.pory"
	.string "timid POKéMON.\p"
# 71 "data/maps/VerdanturfTown/scripts.pory"
	.string "They get all scared of loud noise and\n"
# 72 "data/maps/VerdanturfTown/scripts.pory"
	.string "make a big uproar.\p"
# 73 "data/maps/VerdanturfTown/scripts.pory"
	.string "So they had to stop the big tunnel\n"
# 74 "data/maps/VerdanturfTown/scripts.pory"
	.string "project.\p"
# 75 "data/maps/VerdanturfTown/scripts.pory"
	.string "But there's one man. He's trying to dig\n"
# 76 "data/maps/VerdanturfTown/scripts.pory"
	.string "the tunnel by himself!$"
# 77 "data/maps/VerdanturfTown/scripts.pory"

# 78 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_ManDugTunnelForLove:
# 79 "data/maps/VerdanturfTown/scripts.pory"
	.string "There was a man who dug a tunnel for\n"
# 80 "data/maps/VerdanturfTown/scripts.pory"
	.string "a lady he loved.\p"
# 81 "data/maps/VerdanturfTown/scripts.pory"
	.string "I don't really get it, but hey!$"
# 82 "data/maps/VerdanturfTown/scripts.pory"

# 83 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_AirCleanHere:
# 84 "data/maps/VerdanturfTown/scripts.pory"
	.string "The way the winds blow, volcanic ash\n"
# 85 "data/maps/VerdanturfTown/scripts.pory"
	.string "is never blown in this direction.\p"
# 86 "data/maps/VerdanturfTown/scripts.pory"
	.string "The air is clean and delicious here.\n"
# 87 "data/maps/VerdanturfTown/scripts.pory"
	.string "Living here should do wonders for even\l"
# 88 "data/maps/VerdanturfTown/scripts.pory"
	.string "frail and sickly people.$"
# 89 "data/maps/VerdanturfTown/scripts.pory"

# 90 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_MakeBattleTentDebut:
# 91 "data/maps/VerdanturfTown/scripts.pory"
	.string "My POKéMON and I, we've been riding\n"
# 92 "data/maps/VerdanturfTown/scripts.pory"
	.string "a hot winning streak.\p"
# 93 "data/maps/VerdanturfTown/scripts.pory"
	.string "So I decided to make my BATTLE TENT\n"
# 94 "data/maps/VerdanturfTown/scripts.pory"
	.string "debut in this town.$"
# 95 "data/maps/VerdanturfTown/scripts.pory"

# 96 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_GuyTryingToBustThroughCave:
# 97 "data/maps/VerdanturfTown/scripts.pory"
	.string "Did you see the cave next to the\n"
# 98 "data/maps/VerdanturfTown/scripts.pory"
	.string "POKéMON MART?\p"
# 99 "data/maps/VerdanturfTown/scripts.pory"
	.string "There's a guy in there who's trying to\n"
# 100 "data/maps/VerdanturfTown/scripts.pory"
	.string "bust up boulders so he can bust out\l"
# 101 "data/maps/VerdanturfTown/scripts.pory"
	.string "through to the other side.\p"
# 102 "data/maps/VerdanturfTown/scripts.pory"
	.string "It'd be great if we could go through…\n"
# 103 "data/maps/VerdanturfTown/scripts.pory"
	.string "It'll make it easy to visit RUSTBORO.$"
# 104 "data/maps/VerdanturfTown/scripts.pory"

# 105 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_EasyToGetToRustboroNow:
# 106 "data/maps/VerdanturfTown/scripts.pory"
	.string "That cave next to the POKéMON MART\n"
# 107 "data/maps/VerdanturfTown/scripts.pory"
	.string "is now a tunnel to the other side.\p"
# 108 "data/maps/VerdanturfTown/scripts.pory"
	.string "It's great--it's easy to go shop for\n"
# 109 "data/maps/VerdanturfTown/scripts.pory"
	.string "new DEVON products in RUSTBORO now.$"
# 110 "data/maps/VerdanturfTown/scripts.pory"

# 111 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_TownSign:
# 112 "data/maps/VerdanturfTown/scripts.pory"
	.string "VERDANTURF TOWN\p"
# 113 "data/maps/VerdanturfTown/scripts.pory"
	.string "“The windswept highlands with the\n"
# 114 "data/maps/VerdanturfTown/scripts.pory"
	.string "sweet fragrance of grass.”$"
# 115 "data/maps/VerdanturfTown/scripts.pory"

# 116 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_WandasHouse:
# 117 "data/maps/VerdanturfTown/scripts.pory"
	.string "WANDA'S HOUSE$"
# 118 "data/maps/VerdanturfTown/scripts.pory"

# 119 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_BattleTentSign:
# 120 "data/maps/VerdanturfTown/scripts.pory"
	.string "BATTLE TENT VERDANTURF SITE\n"
# 121 "data/maps/VerdanturfTown/scripts.pory"
	.string "“Feast Your Eyes on Battles!”$"
# 122 "data/maps/VerdanturfTown/scripts.pory"

# 123 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_RusturfTunnelSign:
# 124 "data/maps/VerdanturfTown/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 125 "data/maps/VerdanturfTown/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 126 "data/maps/VerdanturfTown/scripts.pory"
	.string "“The tunnel project has been\n"
# 127 "data/maps/VerdanturfTown/scripts.pory"
	.string "canceled.”$"
