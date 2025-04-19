# 1 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 2 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
.set LOCALID_FOSSIL_MANIAC, 1
# 3 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 4 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_MapScripts::
# 5 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
# 6 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
# 7 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.byte 0
# 8 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 9 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_OnTransition:
# 10 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
# 11 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 12 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 13 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
# 14 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
# 15 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
# 16 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	return
# 17 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 18 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_OnLoad:
# 19 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
# 20 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 21 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 22 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
# 23 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
# 24 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
# 25 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	return
# 26 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 27 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
# 28 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	lockall
# 29 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
# 30 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 31 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	waitmovement 0
# 32 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
# 33 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	setvar VAR_FOSSIL_MANIAC_STATE, 2
# 34 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	releaseall
# 35 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 36 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 37 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_FossilManiac::
# 38 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	lock
# 39 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	faceplayer
# 40 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
# 41 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 42 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
# 43 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 44 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
# 45 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
# 46 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	release
# 47 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 48 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 49 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
# 50 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
# 51 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	release
# 52 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 53 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 54 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
# 55 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
# 56 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	release
# 57 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 58 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 59 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
# 60 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I'm the FOSSIL MANIAC…\n"
# 61 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I'm a nice guy who loves FOSSILS…\p"
# 62 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "Do you want a FOSSIL?\p"
# 63 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "But the FOSSILS around these parts all\n"
# 64 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "belong to me… None for you…\p"
# 65 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "If you can't bear to go without\n"
# 66 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "a FOSSIL, look in a desert where there\l"
# 67 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "are boulders and sand that may hide\l"
# 68 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSILS…$"
# 69 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 70 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
# 71 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "You found a FOSSIL, didn't you?\n"
# 72 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "That's so nice… It's so dreamy…\p"
# 73 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "What are you going to do with that\n"
# 74 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSIL?\p"
# 75 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "From what I've heard, DEVON is doing\n"
# 76 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "research on reviving POKéMON from\l"
# 77 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSILS…\p"
# 78 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I love my FOSSILS, so I would never\n"
# 79 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "do anything like that…$"
# 80 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 81 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
# 82 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSILS are so… Wonderful…\n"
# 83 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "It's so dreamy…$"
# 84 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"

# 85 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
# 86 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "Oh…\n"
# 87 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "It's not safe that way…\p"
# 88 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I was digging away, you see…\n"
# 89 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "When the whole wall collapsed…\p"
# 90 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I think there's a giant cavern\n"
# 91 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "underneath now…\p"
# 92 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "But I've left it alone because I don't\n"
# 93 "data/maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "think there are any FOSSILS there…$"
