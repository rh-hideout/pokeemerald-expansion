# 1 "data/maps/LilycoveCity_House2/scripts.pory"

# 2 "data/maps/LilycoveCity_House2/scripts.pory"
LilycoveCity_House2_MapScripts::
# 3 "data/maps/LilycoveCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_House2/scripts.pory"

# 5 "data/maps/LilycoveCity_House2/scripts.pory"
LilycoveCity_House2_EventScript_FatMan::
# 6 "data/maps/LilycoveCity_House2/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_House2/scripts.pory"
	faceplayer
# 8 "data/maps/LilycoveCity_House2/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_REST, LilycoveCity_House2_EventScript_ReceivedRest
# 9 "data/maps/LilycoveCity_House2/scripts.pory"
	msgbox LilycoveCity_House2_Text_NotAwakeYetHaveThis, MSGBOX_DEFAULT
# 10 "data/maps/LilycoveCity_House2/scripts.pory"
	giveitem ITEM_TM_REST
# 11 "data/maps/LilycoveCity_House2/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 12 "data/maps/LilycoveCity_House2/scripts.pory"
	setflag FLAG_RECEIVED_TM_REST
# 13 "data/maps/LilycoveCity_House2/scripts.pory"
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
# 14 "data/maps/LilycoveCity_House2/scripts.pory"
	release
# 15 "data/maps/LilycoveCity_House2/scripts.pory"
	end
# 16 "data/maps/LilycoveCity_House2/scripts.pory"

# 17 "data/maps/LilycoveCity_House2/scripts.pory"
LilycoveCity_House2_EventScript_ReceivedRest::
# 18 "data/maps/LilycoveCity_House2/scripts.pory"
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
# 19 "data/maps/LilycoveCity_House2/scripts.pory"
	release
# 20 "data/maps/LilycoveCity_House2/scripts.pory"
	end
# 21 "data/maps/LilycoveCity_House2/scripts.pory"

# 22 "data/maps/LilycoveCity_House2/scripts.pory"
LilycoveCity_House2_Text_NotAwakeYetHaveThis:
# 23 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "Huh? What? What's that?\p"
# 24 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "I'm not near awake yet…\n"
# 25 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "You can have this…$"
# 26 "data/maps/LilycoveCity_House2/scripts.pory"

# 27 "data/maps/LilycoveCity_House2/scripts.pory"
LilycoveCity_House2_Text_SleepIsEssential:
# 28 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "Yawn…\p"
# 29 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "Sleep is essential for good health…\n"
# 30 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "Sleep and regain health…$"
