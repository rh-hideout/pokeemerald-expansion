# 1 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 2 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_MapScripts::
# 3 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
# 4 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
# 5 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.byte 0
# 6 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 7 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_OnTransition:
# 8 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
# 9 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 10 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 11 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
# 12 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
# 13 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
# 14 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	return
# 15 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 16 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_OnLoad:
# 17 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
# 18 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 19 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 20 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
# 21 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
# 22 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
# 23 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	return
# 24 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 25 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
# 26 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	lockall
# 27 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
# 28 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 29 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	waitmovement 0
# 30 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
# 31 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	setvar VAR_FOSSIL_MANIAC_STATE, 2
# 32 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	releaseall
# 33 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 34 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 35 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_FossilManiac::
# 36 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	lock
# 37 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	faceplayer
# 38 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
# 39 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 40 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
# 41 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 42 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
# 43 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
# 44 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	release
# 45 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 46 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 47 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
# 48 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
# 49 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	release
# 50 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 51 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 52 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
# 53 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
# 54 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	release
# 55 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 56 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 57 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
# 58 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I'm the FOSSIL MANIAC…\n"
# 59 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I'm a nice guy who loves FOSSILS…\p"
# 60 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "Do you want a FOSSIL?\p"
# 61 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "But the FOSSILS around these parts all\n"
# 62 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "belong to me… None for you…\p"
# 63 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "If you can't bear to go without\n"
# 64 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "a FOSSIL, look in a desert where there\l"
# 65 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "are boulders and sand that may hide\l"
# 66 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSILS…$"
# 67 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 68 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
# 69 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "You found a FOSSIL, didn't you?\n"
# 70 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "That's so nice… It's so dreamy…\p"
# 71 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "What are you going to do with that\n"
# 72 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSIL?\p"
# 73 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "From what I've heard, DEVON is doing\n"
# 74 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "research on reviving POKéMON from\l"
# 75 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSILS…\p"
# 76 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I love my FOSSILS, so I would never\n"
# 77 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "do anything like that…$"
# 78 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 79 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
# 80 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSILS are so… Wonderful…\n"
# 81 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "It's so dreamy…$"
# 82 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 83 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
# 84 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "Oh…\n"
# 85 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "It's not safe that way…\p"
# 86 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I was digging away, you see…\n"
# 87 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "When the whole wall collapsed…\p"
# 88 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I think there's a giant cavern\n"
# 89 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "underneath now…\p"
# 90 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "But I've left it alone because I don't\n"
# 91 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "think there are any FOSSILS there…$"
