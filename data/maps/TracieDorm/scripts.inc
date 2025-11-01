TracieDorm_MapScripts::
# 2 "data/maps/TracieDorm/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TracieDorm_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TracieDorm_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/TracieDorm/scripts.pory"
	map_script_2 VAR_PLAYERDORM_STATE, 3, TracieDorm_Enter
	.2byte 0


TracieDorm_Enter::
# 8 "data/maps/TracieDorm/scripts.pory"
	clearflag FLAG_HIDE_TRACIE
# 9 "data/maps/TracieDorm/scripts.pory"
	lockall
# 10 "data/maps/TracieDorm/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TracieDorm_Enter_Movement_0
# 11 "data/maps/TracieDorm/scripts.pory"
	waitmovement 0
# 12 "data/maps/TracieDorm/scripts.pory"
	msgbox TracieDorm_Enter_Text_0
# 13 "data/maps/TracieDorm/scripts.pory"
	closemessage
# 14 "data/maps/TracieDorm/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 15 "data/maps/TracieDorm/scripts.pory"
	msgbox TracieDorm_Enter_Text_1
# 16 "data/maps/TracieDorm/scripts.pory"
	waitfanfare
# 17 "data/maps/TracieDorm/scripts.pory"
	closemessage
# 18 "data/maps/TracieDorm/scripts.pory"
	applymovement LOCALID_TRACIE, TracieDorm_Enter_Movement_1
# 19 "data/maps/TracieDorm/scripts.pory"
	waitmovement 0
# 20 "data/maps/TracieDorm/scripts.pory"
	msgbox TracieDorm_Enter_Text_2
# 21 "data/maps/TracieDorm/scripts.pory"
	closemessage
# 22 "data/maps/TracieDorm/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 23 "data/maps/TracieDorm/scripts.pory"
	msgbox TracieDorm_Enter_Text_3
# 24 "data/maps/TracieDorm/scripts.pory"
	waitfanfare
# 25 "data/maps/TracieDorm/scripts.pory"
	msgbox TracieDorm_Enter_Text_4
# 26 "data/maps/TracieDorm/scripts.pory"
	closemessage
# 27 "data/maps/TracieDorm/scripts.pory"
	setflag FLAG_SYS_QUEST_MENU_GET
# 28 "data/maps/TracieDorm/scripts.pory"
	questmenu QUEST_MENU_SET_ACTIVE, QUEST_ORIENTATION
# 29 "data/maps/TracieDorm/scripts.pory"
	playse SE_DEX_SEARCH
# 30 "data/maps/TracieDorm/scripts.pory"
	msgbox TracieDorm_Enter_Text_5
# 31 "data/maps/TracieDorm/scripts.pory"
	waitse
# 32 "data/maps/TracieDorm/scripts.pory"
	openquestmenu
# 33 "data/maps/TracieDorm/scripts.pory"
	msgbox TracieDorm_Enter_Text_6
# 34 "data/maps/TracieDorm/scripts.pory"
	closemessage
# 35 "data/maps/TracieDorm/scripts.pory"
	setfollowernpc LOCALID_TRACIE, FNPC_ALL, TracieDorm_TracieFollowDialogue, 0
# 36 "data/maps/TracieDorm/scripts.pory"
	setflag FLAG_HIDE_TRACIE
# 37 "data/maps/TracieDorm/scripts.pory"
	setvar VAR_PLAYERDORM_STATE, 4
	end


TracieDorm_TracieFollowDialogue::
# 42 "data/maps/TracieDorm/scripts.pory"
	faceplayer
# 43 "data/maps/TracieDorm/scripts.pory"
	msgbox TracieDorm_TracieFollowDialogue_Text_0
# 44 "data/maps/TracieDorm/scripts.pory"
	closemessage
	return


TracieDorm_PichuDoll::
# 48 "data/maps/TracieDorm/scripts.pory"
	msgbox TracieDorm_PichuDoll_Text_0
# 49 "data/maps/TracieDorm/scripts.pory"
	closemessage
	return


# 10 "data/maps/TracieDorm/scripts.pory"
TracieDorm_Enter_Movement_0:
# 10 "data/maps/TracieDorm/scripts.pory"
	walk_up
# 10 "data/maps/TracieDorm/scripts.pory"
	walk_up
# 10 "data/maps/TracieDorm/scripts.pory"
	walk_up
	step_end

# 18 "data/maps/TracieDorm/scripts.pory"
TracieDorm_Enter_Movement_1:
# 18 "data/maps/TracieDorm/scripts.pory"
	walk_left
# 18 "data/maps/TracieDorm/scripts.pory"
	walk_down
	step_end

TracieDorm_Enter_Text_0:
# 12 "data/maps/TracieDorm/scripts.pory"
	.string "Hmm… Where did I put it…?\n"
	.string "Let's see…\p"
	.string "Oh! Found it!\n"
	.string "My {COLOR BLUE}Quest Log{COLOR DARK_GRAY}!$"

TracieDorm_Enter_Text_1:
# 15 "data/maps/TracieDorm/scripts.pory"
	.string "Tracie found her {COLOR BLUE}Quest Log{COLOR DARK_GRAY}!$"

TracieDorm_Enter_Text_2:
# 20 "data/maps/TracieDorm/scripts.pory"
	.string "Here {PLAYER}, I actually have a\n"
	.string "second one.\p"
	.string "I'd like you to have it!$"

TracieDorm_Enter_Text_3:
# 23 "data/maps/TracieDorm/scripts.pory"
	.string "{PLAYER} obtained a {COLOR BLUE}Quest Log{COLOR DARK_GRAY} from\n"
	.string "Tracie!$"

TracieDorm_Enter_Text_4:
# 25 "data/maps/TracieDorm/scripts.pory"
	.string "You can keep track of anything you've\n"
	.string "been asked to do!\p"
	.string "Just press {START_BUTTON} and select {COLOR BLUE}Quest Log {COLOR DARK_GRAY}\n"
	.string "to view your requests!\p"
	.string "You can press {R_BUTTON} to filter them too.\p"
	.string "Why don't we test it out and add one for\n"
	.string "orientation!$"

TracieDorm_Enter_Text_5:
# 30 "data/maps/TracieDorm/scripts.pory"
	.string "{COLOR BLUE}Senior Year{COLOR DARK_GRAY} has been added to your\n"
	.string "{COLOR BLUE}Quest Log{COLOR DARK_GRAY}.$"

TracieDorm_Enter_Text_6:
# 33 "data/maps/TracieDorm/scripts.pory"
	.string "Easy! Right?\p"
	.string "Anyways, we can't lag too far behind\n"
	.string "Rotcart.\p"
	.string "Orientation is starting soon, after all.\p"
	.string "Lead the way!\n"
	.string "I'll follow.$"

TracieDorm_TracieFollowDialogue_Text_0:
# 43 "data/maps/TracieDorm/scripts.pory"
	.string "Hehehe… Senior year!\n"
	.string "Let's go! Let's go!$"

TracieDorm_PichuDoll_Text_0:
# 48 "data/maps/TracieDorm/scripts.pory"
	.string "It's a life sized Pichu doll.$"
