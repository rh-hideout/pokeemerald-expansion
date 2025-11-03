# 1 "data/maps/MossdeepCity_House1/scripts.pory"

# 2 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_MapScripts::
# 3 "data/maps/MossdeepCity_House1/scripts.pory"
	.byte 0
# 4 "data/maps/MossdeepCity_House1/scripts.pory"

# 5 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_EventScript_BlackBelt::
# 6 "data/maps/MossdeepCity_House1/scripts.pory"
	lock
# 7 "data/maps/MossdeepCity_House1/scripts.pory"
	faceplayer
# 8 "data/maps/MossdeepCity_House1/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 9 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
# 10 "data/maps/MossdeepCity_House1/scripts.pory"
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
# 11 "data/maps/MossdeepCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
# 12 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
# 13 "data/maps/MossdeepCity_House1/scripts.pory"
	release
# 14 "data/maps/MossdeepCity_House1/scripts.pory"
	end
# 15 "data/maps/MossdeepCity_House1/scripts.pory"

# 16 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_EventScript_NeutralNature::
# 17 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
# 18 "data/maps/MossdeepCity_House1/scripts.pory"
	release
# 19 "data/maps/MossdeepCity_House1/scripts.pory"
	end
# 20 "data/maps/MossdeepCity_House1/scripts.pory"

# 21 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_EventScript_Woman::
# 22 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
# 23 "data/maps/MossdeepCity_House1/scripts.pory"
	end
# 24 "data/maps/MossdeepCity_House1/scripts.pory"

# 25 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_HmmYourPokemon:
# 26 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Hmm!\n"
# 27 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Your {STR_VAR_1}…$"
# 28 "data/maps/MossdeepCity_House1/scripts.pory"

# 29 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_ItLikesXPokeblocks:
# 30 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "It likes {STR_VAR_1}S,\n"
# 31 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "doesn't it?\p"
# 32 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "No, I'm positive of it! It definitely\n"
# 33 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "likes {STR_VAR_1}S!$"
# 34 "data/maps/MossdeepCity_House1/scripts.pory"

# 35 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
# 36 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "It doesn't appear to like or dislike\n"
# 37 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "any {POKEBLOCK}S.$"
# 38 "data/maps/MossdeepCity_House1/scripts.pory"

# 39 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
# 40 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "My husband can tell what kind of\n"
# 41 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "{POKEBLOCK}S a POKéMON likes at a glance.$"
