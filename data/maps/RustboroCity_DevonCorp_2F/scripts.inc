# 1 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 2 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
.set LOCALID_FOSSIL_SCIENTIST, 5
# 3 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 4 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_MapScripts::
# 5 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
# 6 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.byte 0
# 7 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 8 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_OnTransition:
# 9 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 10 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 11 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 12 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
# 13 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
# 14 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 15 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 16 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
# 17 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 18 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 19 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 20 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
# 21 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 22 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 23 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 24 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_BallScientist::
# 25 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 26 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 27 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 28 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
# 29 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
# 30 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 31 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 32 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 33 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
# 34 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
# 35 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 36 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 37 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 38 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
# 39 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 40 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 41 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 42 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
# 43 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
# 44 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 45 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 46 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 47 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
# 48 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
# 49 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 50 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 51 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 52 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
# 53 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 54 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 55 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 56 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
# 57 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 58 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 59 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 60 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
# 61 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 62 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 63 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 64 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
# 65 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
# 66 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 67 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 68 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 69 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
# 70 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
# 71 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 72 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 73 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 74 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
# 75 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We're developing a device for talking\n"
# 76 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "with Pokémon.\p"
# 77 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But we haven't had much success…$"
# 78 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 79 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
# 80 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm developing new kinds of\n"
# 81 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Poké Balls…\p"
# 82 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But I haven't made much headway…$"
# 83 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 84 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
# 85 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We finally made new kinds of\n"
# 86 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Poké Balls!\p"
# 87 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The Repeat Ball makes it easier to\n"
# 88 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "catch Pokémon you've caught before.\p"
# 89 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The Timer Ball gets better at catching\n"
# 90 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Pokémon the longer a battle runs.\p"
# 91 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Both are proudly developed by\n"
# 92 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the Devon Corporation.\p"
# 93 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Please give them a try!$"
# 94 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 95 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_IMadePokenav:
# 96 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I made the PokéNav!\p"
# 97 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "As an engineer, I feel blessed to have\n"
# 98 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "made something so great!$"
# 99 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 100 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
# 101 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, wow!\n"
# 102 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "That's a PokéNav!\p"
# 103 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "It came about as a result of our\n"
# 104 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "President's desire to learn about\l"
# 105 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the feelings of Pokémon.\p"
# 106 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like me to describe its\n"
# 107 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "features in detail?\p"
# 108 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "No, no. I think you'll find out just by\n"
# 109 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "trying the PokéNav out.$"
# 110 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 111 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
# 112 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a device that\n"
# 113 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "visually reproduces the dreams of\l"
# 114 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Pokémon…\p"
# 115 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 116 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 117 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ Unused
# 118 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
# 119 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Uh-oh, you've got too many Pokémon.\n"
# 120 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have no room for this one.$"
# 121 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 122 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
# 123 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a new feature\n"
# 124 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "for the PokéNav…\p"
# 125 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 126 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 127 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
# 128 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Well, now what shall I work on\n"
# 129 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "developing next?\p"
# 130 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Our company allows us to make our\n"
# 131 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "inspirations into reality.\p"
# 132 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "One couldn't ask for a better\n"
# 133 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "environment as an engineer.$"

RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
# 137 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 138 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 139 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2
# 140 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRessurectionDevice, MSGBOX_NPC
	end


RustboroCity_DevonCorp_2F_EventScript_FossilScientist2::
# 145 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, Devon_FossilMonReady
# 146 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, Devon_FossilStillRegenerating
# 147 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
# 148 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox DevonShowAFossil, MSGBOX_YESNO
# 149 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_2
# 154 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_OpenBag
# 155 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_ITEM_ID
# 156 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 165, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_6
# 159 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 166, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_7
# 162 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 167, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_8
# 165 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 168, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_9
# 168 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 169, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_10
# 171 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 170, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_11
# 174 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 171, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_12
# 177 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 172, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_13
# 180 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 173, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_14
# 183 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 174, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_15
# 186 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 175, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_16
# 189 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 176, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_17
# 192 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 177, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_18
# 195 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 178, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_19
# 198 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 179, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_20
# 201 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 0, RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_21
# 204 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox ThatsNotAFossil, MSGBOX_NPC
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1:
# 208 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_2:
# 150 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox DevonShowAFossil_Decline, MSGBOX_NPC
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_6:
# 157 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 158 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveHelixFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_7:
# 160 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 161 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveDomeFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_8:
# 163 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 164 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveAmberFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_9:
# 166 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 167 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveRootFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_10:
# 169 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 170 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveClawFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_11:
# 172 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 173 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveArmorFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_12:
# 175 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 176 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveSkullFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_13:
# 178 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 179 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveCoverFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_14:
# 181 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 182 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GivePlumeFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_15:
# 184 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 185 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveJawFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_16:
# 187 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 188 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveSailFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_17:
# 190 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 191 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilizedBird
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_18:
# 193 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 194 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilizedFish
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_19:
# 196 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 197 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilizedDrake
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_20:
# 199 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call NoticesAFossil
# 200 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilizedDino
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1

RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_21:
# 202 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Devon_DeclineGiveFossil
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist2_1


NoticesAFossil::
# 213 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 214 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NoticesAFossil_1
	return

NoticesAFossil_1:
# 215 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Devon_DeclineGiveFossil
	return


GiveFossilFinish::
# 222 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_NPC
# 223 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	end


Devon_DeclineGiveFossil::
# 227 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_NPC
	end


Devon_FossilStillRegenerating::
# 231 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox Devon_Text_FossilRegeneratorTakesTime, MSGBOX_NPC
	end


GiveHelixFossil::
# 239 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_HELIX_FOSSIL
# 240 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
# 241 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
# 242 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveDomeFossil::
# 245 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_DOME_FOSSIL
# 246 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_DOME_FOSSIL
# 247 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
# 248 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveAmberFossil::
# 251 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_OLD_AMBER
# 252 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
# 253 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 3
# 254 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveRootFossil::
# 257 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 258 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
# 259 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 4
# 260 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveClawFossil::
# 263 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 264 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
# 265 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 5
# 266 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveArmorFossil::
# 269 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_ARMOR_FOSSIL
# 270 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ARMOR_FOSSIL
# 271 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 6
# 272 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveSkullFossil::
# 275 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_SKULL_FOSSIL
# 276 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_SKULL_FOSSIL
# 277 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 7
# 278 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveCoverFossil::
# 281 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_COVER_FOSSIL
# 282 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_COVER_FOSSIL
# 283 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 8
# 284 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GivePlumeFossil::
# 287 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_PLUME_FOSSIL
# 288 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PLUME_FOSSIL
# 289 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 9
# 290 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveJawFossil::
# 293 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_JAW_FOSSIL
# 294 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_JAW_FOSSIL
# 295 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 10
# 296 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveSailFossil::
# 299 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_SAIL_FOSSIL
# 300 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_SAIL_FOSSIL
# 301 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 11
# 302 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveFossilizedBird::
# 305 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_FOSSILIZED_BIRD
# 306 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_BIRD
# 307 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 12
# 308 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveFossilizedFish::
# 311 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_FOSSILIZED_FISH
# 312 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_FISH
# 313 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 13
# 314 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveFossilizedDrake::
# 317 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_FOSSILIZED_DRAKE
# 318 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_DRAKE
# 319 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 14
# 320 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


GiveFossilizedDino::
# 323 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_FOSSILIZED_DINO
# 324 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_DINO
# 325 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 15
# 326 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto GiveFossilFinish
	return


Devon_FossilMonReady::
# 332 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_WHICH_FOSSIL_REVIVED
# 333 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 1, Devon_FossilMonReady_3
# 334 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 2, Devon_FossilMonReady_4
# 335 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 3, Devon_FossilMonReady_5
# 336 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 4, Devon_FossilMonReady_6
# 337 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 5, Devon_FossilMonReady_7
# 338 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 6, Devon_FossilMonReady_8
# 339 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 7, Devon_FossilMonReady_9
# 340 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 8, Devon_FossilMonReady_10
# 341 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 9, Devon_FossilMonReady_11
# 342 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 10, Devon_FossilMonReady_12
# 343 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 11, Devon_FossilMonReady_13
# 344 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 12, Devon_FossilMonReady_14
# 345 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 13, Devon_FossilMonReady_15
# 346 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 14, Devon_FossilMonReady_16
# 347 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 15, Devon_FossilMonReady_17
Devon_FossilMonReady_1:
	end

Devon_FossilMonReady_3:
# 333 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto OmanyteReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_4:
# 334 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto KabutoReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_5:
# 335 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto AerodactylReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_6:
# 336 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto LileepReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_7:
# 337 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto AnorithReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_8:
# 338 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto CranidosReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_9:
# 339 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ShieldonReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_10:
# 340 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto TirtougaReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_11:
# 341 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ArchenReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_12:
# 342 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto TyruntReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_13:
# 343 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto AmauraReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_14:
# 344 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ArctozoltReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_15:
# 345 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ArctovishReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_16:
# 346 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto DracovishReady
	goto Devon_FossilMonReady_1

Devon_FossilMonReady_17:
# 347 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto DracozoltReady
	goto Devon_FossilMonReady_1


OmanyteReady::
# 366 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
# 367 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 368 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_OMANYTE
# 369 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_OMANYTE, 0
# 370 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
# 371 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 372 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq OmanyteReady_2
OmanyteReady_1:
# 375 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq OmanyteReady_5
OmanyteReady_4:
# 378 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OmanyteReady_2:
# 373 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto OmanyteReady_1

OmanyteReady_5:
# 376 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto OmanyteReady_4


KabutoReady::
# 383 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
# 384 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 385 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KABUTO
# 386 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_KABUTO, 0
# 387 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
# 388 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 389 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq KabutoReady_2
KabutoReady_1:
# 392 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq KabutoReady_5
KabutoReady_4:
# 395 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

KabutoReady_2:
# 390 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto KabutoReady_1

KabutoReady_5:
# 393 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto KabutoReady_4


AerodactylReady::
# 400 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
# 401 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 402 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AERODACTYL
# 403 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_AERODACTYL, 0, ITEM_AERODACTYLITE
# 404 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
# 405 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 406 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq AerodactylReady_2
AerodactylReady_1:
# 409 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq AerodactylReady_5
AerodactylReady_4:
# 412 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

AerodactylReady_2:
# 407 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto AerodactylReady_1

AerodactylReady_5:
# 410 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto AerodactylReady_4


LileepReady::
# 417 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 418 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 419 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
# 420 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_LILEEP, 0
# 421 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
# 422 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 423 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq LileepReady_2
LileepReady_1:
# 426 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq LileepReady_5
LileepReady_4:
# 429 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LileepReady_2:
# 424 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto LileepReady_1

LileepReady_5:
# 427 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto LileepReady_4


AnorithReady::
# 434 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 435 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 436 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
# 437 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ANORITH, 0
# 438 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
# 439 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 440 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq AnorithReady_2
AnorithReady_1:
# 443 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq AnorithReady_5
AnorithReady_4:
# 446 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

AnorithReady_2:
# 441 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto AnorithReady_1

AnorithReady_5:
# 444 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto AnorithReady_4


CranidosReady::
# 451 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_CRANIDOS
# 452 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 453 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CRANIDOS
# 454 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_CRANIDOS, 0
# 455 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CRANIDOS
# 456 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 457 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq CranidosReady_2
CranidosReady_1:
# 460 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq CranidosReady_5
CranidosReady_4:
# 463 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

CranidosReady_2:
# 458 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto CranidosReady_1

CranidosReady_5:
# 461 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto CranidosReady_4


ShieldonReady::
# 468 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_SHIELDON
# 469 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 470 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHIELDON
# 471 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_SHIELDON, 0
# 472 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_SHIELDON
# 473 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 474 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShieldonReady_2
ShieldonReady_1:
# 477 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ShieldonReady_5
ShieldonReady_4:
# 480 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

ShieldonReady_2:
# 475 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto ShieldonReady_1

ShieldonReady_5:
# 478 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto ShieldonReady_4


TirtougaReady::
# 485 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_TIRTOUGA
# 486 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 487 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TIRTOUGA
# 488 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_TIRTOUGA, 0
# 489 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TIRTOUGA
# 490 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 491 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TirtougaReady_2
TirtougaReady_1:
# 494 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TirtougaReady_5
TirtougaReady_4:
# 497 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

TirtougaReady_2:
# 492 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto TirtougaReady_1

TirtougaReady_5:
# 495 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto TirtougaReady_4


ArchenReady::
# 502 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ARCHEN
# 503 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 504 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARCHEN
# 505 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ARCHEN, 0
# 506 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARCHEN
# 507 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 508 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ArchenReady_2
ArchenReady_1:
# 511 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ArchenReady_5
ArchenReady_4:
# 514 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

ArchenReady_2:
# 509 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto ArchenReady_1

ArchenReady_5:
# 512 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto ArchenReady_4


TyruntReady::
# 519 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_TYRUNT
# 520 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 521 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYRUNT
# 522 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_TYRUNT, 0
# 523 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TYRUNT
# 524 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 525 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TyruntReady_2
TyruntReady_1:
# 528 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TyruntReady_5
TyruntReady_4:
# 531 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

TyruntReady_2:
# 526 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto TyruntReady_1

TyruntReady_5:
# 529 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto TyruntReady_4


AmauraReady::
# 536 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_AMAURA
# 537 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 538 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AMAURA
# 539 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_AMAURA, 0
# 540 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AMAURA
# 541 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 542 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq AmauraReady_2
AmauraReady_1:
# 545 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq AmauraReady_5
AmauraReady_4:
# 548 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

AmauraReady_2:
# 543 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto AmauraReady_1

AmauraReady_5:
# 546 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto AmauraReady_4


ArctozoltReady::
# 553 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ARCTOZOLT
# 554 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 555 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARCTOZOLT
# 556 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ARCTOZOLT, 0
# 557 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARCTOZOLT
# 558 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 559 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ArctozoltReady_2
ArctozoltReady_1:
# 562 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ArctozoltReady_5
ArctozoltReady_4:
# 565 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

ArctozoltReady_2:
# 560 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto ArctozoltReady_1

ArctozoltReady_5:
# 563 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto ArctozoltReady_4


ArctovishReady::
# 570 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ARCTOVISH
# 571 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 572 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARCTOVISH
# 573 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ARCTOVISH, 0
# 574 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARCTOVISH
# 575 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 576 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ArctovishReady_2
ArctovishReady_1:
# 579 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ArctovishReady_5
ArctovishReady_4:
# 582 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

ArctovishReady_2:
# 577 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto ArctovishReady_1

ArctovishReady_5:
# 580 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto ArctovishReady_4


DracovishReady::
# 587 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_DRACOVISH
# 588 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 589 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRACOVISH
# 590 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_DRACOVISH, 0
# 591 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DRACOVISH
# 592 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 593 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq DracovishReady_2
DracovishReady_1:
# 596 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq DracovishReady_5
DracovishReady_4:
# 599 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

DracovishReady_2:
# 594 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto DracovishReady_1

DracovishReady_5:
# 597 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto DracovishReady_4


DracozoltReady::
# 604 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_DRACOZOLT
# 605 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox FossilBroughtBackToLife, MSGBOX_DEFAULT
# 606 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRACOZOLT
# 607 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_DRACOZOLT, 0
# 608 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DRACOZOLT
# 609 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call ReceivedFossilMonFanfare
# 610 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq DracozoltReady_2
DracozoltReady_1:
# 613 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq DracozoltReady_5
DracozoltReady_4:
# 616 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	end

DracozoltReady_2:
# 611 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilParty
	goto DracozoltReady_1

DracozoltReady_5:
# 614 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto ReceiveFossilPC
	goto DracozoltReady_4


ReceiveFossilParty::
# 621 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 622 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FinishReceivingFossilMon
# 623 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 624 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 625 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto FinishReceivingFossilMon
	end


ReceiveFossilPC::
# 629 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 630 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ReceiveFossilPC_2
ReceiveFossilPC_1:
# 634 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 635 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 636 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto FinishReceivingFossilMon
	end

ReceiveFossilPC_2:
# 631 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 632 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto FinishReceivingFossilMon
	goto ReceiveFossilPC_1


FinishReceivingFossilMon::
# 640 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 641 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 642 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end


ReceivedFossilMonFanfare::
# 646 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 647 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message ReceivedMonFromResearcher
# 648 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 649 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
	return


FossilBroughtBackToLife::
# 351 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Thanks for waiting!\p"
	.string "Your fossilized Pokémon has been\n"
	.string "brought back to life!\p"
	.string "The fossil was an ancient Pokémon.\n"
	.string "{STR_VAR_2}, it was!$"

ReceivedMonFromResearcher::
# 358 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_2} from\n"
	.string "the Devon researcher.$"

RustboroCity_DevonCorp_2F_Text_FossilRessurectionDevice::
# 657 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I've been trying to develop a device\n"
	.string "that resurrects Pokémon from fossils…\p"
	.string "I feel like I've got some ways to go!$"

RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils::
# 663 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I've been trying to develop a device\n"
	.string "that resurrects Pokémon from fossils…\p"
	.string "And, it's working!$"

RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife::
# 669 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait! That thing you have there…\n"
	.string "Is that an actual Pokémon fossil?\p"
	.string "Would you like to bring that Pokémon\n"
	.string "back to life?\p"
	.string "I can with my newly developed\n"
	.string "Fossil Regenerator.$"

RustboroCity_DevonCorp_2F_Text_OhIsThatSo::
# 678 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, is that so?\p"
	.string "Devon's technological expertise\n"
	.string "is outstanding, I tell you.$"

RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher::
# 684 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Excellent!\n"
	.string "Let's do this right away.\p"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
	.string "the Devon researcher.$"

Devon_Text_FossilRegeneratorTakesTime::
# 691 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The Fossil Regenerator, which I made,\n"
	.string "is incredible.\p"
	.string "But it has one drawback--it takes\n"
	.string "a long time to work.\p"
	.string "So, uh… How about you go for a stroll\n"
	.string "and look around for a while?$"

DevonShowAFossil::
# 700 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You look like an experienced traveler.\p"
	.string "Tell me, have you come across any\n"
	.string "fossils you would like to show me?$"

DevonShowAFossil_Decline::
# 706 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, that's a shame…$"

ThatsNotAFossil::
# 710 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Um… I'm not sure why you're\n"
	.string "showing me that.\l"
	.string "That's not a Pokémon fossil…$"
