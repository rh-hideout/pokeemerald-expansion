# 1 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 2 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_MapScripts::
# 3 "data/maps/Route113_GlassWorkshop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_GlassWorkshop_OnTransition
# 4 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.byte 0
# 5 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 6 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set BLUE_FLUTE_PRICE,   250
# 7 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set YELLOW_FLUTE_PRICE, 500
# 8 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set RED_FLUTE_PRICE,    500
# 9 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set WHITE_FLUTE_PRICE,  1000
# 10 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set BLACK_FLUTE_PRICE,  1000
# 11 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set PRETTY_CHAIR_PRICE, 6000
# 12 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set PRETTY_DESK_PRICE,  8000
# 13 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set LOWEST_ASH_PRICE,   BLUE_FLUTE_PRICE
# 14 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 15 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_OnTransition:
# 16 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setflag FLAG_LANDMARK_GLASS_WORKSHOP
# 17 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call_if_eq VAR_GLASS_WORKSHOP_STATE, 1, Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack
# 18 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 19 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 20 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack::
# 21 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 2
# 22 "data/maps/Route113_GlassWorkshop/scripts.pory"
	return
# 23 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 24 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GlassWorker::
# 25 "data/maps/Route113_GlassWorkshop/scripts.pory"
	lock
# 26 "data/maps/Route113_GlassWorkshop/scripts.pory"
	faceplayer
# 27 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_ge VAR_GLASS_WORKSHOP_STATE, 10, Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom
# 28 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_GLASS_WORKSHOP_STATE, 2, Route113_GlassWorkshop_EventScript_CheckCollectedAsh
# 29 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_GLASS_WORKSHOP_STATE, 1, Route113_GlassWorkshop_EventScript_ExplainSootSack
# 30 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_GoCollectAshWithThis, MSGBOX_DEFAULT
# 31 "data/maps/Route113_GlassWorkshop/scripts.pory"
	giveitem ITEM_SOOT_SACK
# 32 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 33 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 1
# 34 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
# 35 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 36 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 37 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 38 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_ExplainSootSack::
# 39 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
# 40 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 41 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 42 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 43 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_CheckCollectedAsh::
# 44 "data/maps/Route113_GlassWorkshop/scripts.pory"
	checkitem ITEM_SOOT_SACK
# 45 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_SootSackNotInBag
# 46 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_LetsSeeCollectedAshes, MSGBOX_DEFAULT
# 47 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt VAR_ASH_GATHER_COUNT, LOWEST_ASH_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAsh
# 48 "data/maps/Route113_GlassWorkshop/scripts.pory"
	message Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike
# 49 "data/maps/Route113_GlassWorkshop/scripts.pory"
	waitmessage
# 50 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
# 51 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 52 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 53 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_SootSackNotInBag::
# 54 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_HaventGotYourSootSack, MSGBOX_DEFAULT
# 55 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 56 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 57 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 58 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_ChooseGlassItem::
# 59 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 60 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_GLASS_WORKSHOP_VENDOR
# 61 "data/maps/Route113_GlassWorkshop/scripts.pory"
	special ShowScrollableMultichoice
# 62 "data/maps/Route113_GlassWorkshop/scripts.pory"
	waitstate
# 63 "data/maps/Route113_GlassWorkshop/scripts.pory"
	switch VAR_RESULT
# 64 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 0, Route113_GlassWorkshop_EventScript_BlueFlute
# 65 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 1, Route113_GlassWorkshop_EventScript_YellowFlute
# 66 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 2, Route113_GlassWorkshop_EventScript_RedFlute
# 67 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 3, Route113_GlassWorkshop_EventScript_WhiteFlute
# 68 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 4, Route113_GlassWorkshop_EventScript_BlackFlute
# 69 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 5, Route113_GlassWorkshop_EventScript_PrettyChair
# 70 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 6, Route113_GlassWorkshop_EventScript_PrettyDesk
# 71 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 7, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
# 72 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case MULTI_B_PRESSED, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
# 73 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 74 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 75 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_BlueFlute::
# 76 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
# 77 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8008
# 78 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, BLUE_FLUTE_PRICE
# 79 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 80 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 81 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 82 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 10
# 83 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE
# 84 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 85 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 86 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 87 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_YellowFlute::
# 88 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
# 89 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8008
# 90 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, YELLOW_FLUTE_PRICE
# 91 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 92 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 93 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 94 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 11
# 95 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE
# 96 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 97 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 98 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 99 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_RedFlute::
# 100 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_RED_FLUTE
# 101 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8008
# 102 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, RED_FLUTE_PRICE
# 103 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 104 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 105 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 106 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 12
# 107 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE
# 108 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 109 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 110 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 111 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_WhiteFlute::
# 112 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
# 113 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8008
# 114 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, WHITE_FLUTE_PRICE
# 115 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 116 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 117 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 118 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 13
# 119 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE
# 120 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 121 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 122 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 123 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_BlackFlute::
# 124 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
# 125 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8008
# 126 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, BLACK_FLUTE_PRICE
# 127 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 128 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 129 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 130 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 14
# 131 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE
# 132 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 133 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 134 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 135 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_PrettyChair::
# 136 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 1
# 137 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
# 138 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferdecorationname STR_VAR_1, VAR_0x8008
# 139 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, PRETTY_CHAIR_PRICE
# 140 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 141 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 142 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 143 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 15
# 144 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE
# 145 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 146 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 147 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 148 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_PrettyDesk::
# 149 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 1
# 150 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, DECOR_PRETTY_DESK
# 151 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferdecorationname STR_VAR_1, VAR_0x8008
# 152 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, PRETTY_DESK_PRICE
# 153 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 154 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 155 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 156 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 16
# 157 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE
# 158 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 159 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 160 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 161 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_CancelGlassItemSelect::
# 162 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything, MSGBOX_DEFAULT
# 163 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 164 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 165 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 166 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_NotEnoughAsh::
# 167 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, LOWEST_ASH_PRICE
# 168 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
# 169 "data/maps/Route113_GlassWorkshop/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x800A
# 170 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_NotEnoughAshNeedX, MSGBOX_DEFAULT
# 171 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 172 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 173 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 174 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_NotEnoughAshForItem::
# 175 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
# 176 "data/maps/Route113_GlassWorkshop/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x800A
# 177 "data/maps/Route113_GlassWorkshop/scripts.pory"
	message Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem
# 178 "data/maps/Route113_GlassWorkshop/scripts.pory"
	waitmessage
# 179 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
# 180 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 181 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 182 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_ChooseDifferentItem::
# 183 "data/maps/Route113_GlassWorkshop/scripts.pory"
	message Route113_GlassWorkshop_Text_WhichWouldYouLike
# 184 "data/maps/Route113_GlassWorkshop/scripts.pory"
	waitmessage
# 185 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
# 186 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 187 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 188 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_MakeGlassItem::
# 189 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IllMakeItemForYou, MSGBOX_DEFAULT
# 190 "data/maps/Route113_GlassWorkshop/scripts.pory"
	closemessage
# 191 "data/maps/Route113_GlassWorkshop/scripts.pory"
	fadescreen FADE_TO_BLACK
# 192 "data/maps/Route113_GlassWorkshop/scripts.pory"
	playse SE_SELECT
# 193 "data/maps/Route113_GlassWorkshop/scripts.pory"
	delay 30
# 194 "data/maps/Route113_GlassWorkshop/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 195 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
# 196 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call_if_eq VAR_0x8009, 0, Route113_GlassWorkshop_EventScript_GiveGlassFlute
# 197 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call_if_eq VAR_0x8009, 1, Route113_GlassWorkshop_EventScript_GiveGlassDecor
# 198 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 2
# 199 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 200 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 201 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 202 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveGlassFlute::
# 203 "data/maps/Route113_GlassWorkshop/scripts.pory"
	giveitem VAR_0x8008
# 204 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_NoRoomForFlute
# 205 "data/maps/Route113_GlassWorkshop/scripts.pory"
	return
# 206 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 207 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveGlassDecor::
# 208 "data/maps/Route113_GlassWorkshop/scripts.pory"
	givedecoration VAR_0x8008
# 209 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_NoRoomForDecor
# 210 "data/maps/Route113_GlassWorkshop/scripts.pory"
	return
# 211 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 212 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_NoRoomForFlute::
# 213 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call Common_EventScript_BagIsFull
# 214 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_NoRoomInBag, MSGBOX_DEFAULT
# 215 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 216 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 217 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 218 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_NoRoomForDecor::
# 219 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 220 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_NoRoomInPC, MSGBOX_DEFAULT
# 221 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 222 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 223 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 224 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom::
# 225 "data/maps/Route113_GlassWorkshop/scripts.pory"
	switch VAR_GLASS_WORKSHOP_STATE
# 226 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 10, Route113_GlassWorkshop_EventScript_GiveBlueFlute
# 227 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 11, Route113_GlassWorkshop_EventScript_GiveYellowFlute
# 228 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 12, Route113_GlassWorkshop_EventScript_GiveRedFlute
# 229 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 13, Route113_GlassWorkshop_EventScript_GiveWhiteFlute
# 230 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 14, Route113_GlassWorkshop_EventScript_GiveBlackFlute
# 231 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 15, Route113_GlassWorkshop_EventScript_GivePrettyChair
# 232 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 16, Route113_GlassWorkshop_EventScript_GivePrettyDesk
# 233 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 234 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 235 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveBlueFlute::
# 236 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 237 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
# 238 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8008
# 239 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 240 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 241 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 242 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveYellowFlute::
# 243 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 244 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
# 245 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8008
# 246 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 247 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 248 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 249 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveRedFlute::
# 250 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 251 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_RED_FLUTE
# 252 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8008
# 253 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 254 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 255 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 256 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveWhiteFlute::
# 257 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 258 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
# 259 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8008
# 260 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 261 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 262 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 263 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveBlackFlute::
# 264 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 265 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
# 266 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8008
# 267 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 268 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 269 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 270 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GivePrettyChair::
# 271 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 1
# 272 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
# 273 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_CHAIR
# 274 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 275 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 276 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 277 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GivePrettyDesk::
# 278 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 1
# 279 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, DECOR_PRETTY_DESK
# 280 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_DESK
# 281 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 282 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 283 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 284 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_TryGiveItemAgain::
# 285 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
# 286 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call_if_eq VAR_0x8009, 0, Route113_GlassWorkshop_EventScript_GiveGlassFlute
# 287 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call_if_eq VAR_0x8009, 1, Route113_GlassWorkshop_EventScript_GiveGlassDecor
# 288 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 2
# 289 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 290 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 291 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 292 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_NinjaBoy::
# 293 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_FunToBlowGlassFlute, MSGBOX_NPC
# 294 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 295 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 296 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_GoCollectAshWithThis:
# 297 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "This area is covered in volcanic ash,\n"
# 298 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "huff-puff!\p"
# 299 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I'm specially gifted, huff-puff.\p"
# 300 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I make glass out of volcanic ash\n"
# 301 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "and make items, huff-puff.\p"
# 302 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Go collect ashes with this, huff-puff.$"
# 303 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 304 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_ExplainSootSack:
# 305 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Just take that SOOT SACK and walk\n"
# 306 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "through piles of ash, huff-puff.\p"
# 307 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "And it will fill up with the volcanic ash,\n"
# 308 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "huff-puff.\p"
# 309 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Once you think you've collected a good\n"
# 310 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "amount, come see me, huff-puff.$"
# 311 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 312 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_LetsSeeCollectedAshes:
# 313 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Have you collected ashes, huff-puff?\n"
# 314 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Let me see, huff-puff.$"
# 315 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 316 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_NotEnoughAshNeedX:
# 317 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Hmmm…\n"
# 318 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "There's not enough ash here, huff-puff.\l"
# 319 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I can't make glass with this, huff-puff.\p"
# 320 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Let's see… {STR_VAR_1} is the number of steps\n"
# 321 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "you'll need to walk for me to make you\l"
# 322 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "a BLUE FLUTE, huff-puff.$"
# 323 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 324 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike:
# 325 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Oh!\n"
# 326 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "You've got a lot of ashes, huff-puff!\p"
# 327 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I'll make you a glass item, huff-puff!\n"
# 328 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Which one would you like, huff-puff?$"
# 329 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 330 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_IsThatTheItemForYou:
# 331 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "A {STR_VAR_1}, huff-puff?\n"
# 332 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Is that the one for you, huff-puff?$"
# 333 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 334 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_WhichWouldYouLike:
# 335 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Which one would you like, huff-puff?$"
# 336 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 337 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_IllMakeItemForYou:
# 338 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "A {STR_VAR_1} it is, then, huff-puff!\p"
# 339 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Okay! I'll make it for you, huff-puff.\n"
# 340 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Just wait a little while, huff-puff.$"
# 341 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 342 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem:
# 343 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "A {STR_VAR_1}, huff-puff?\p"
# 344 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "There's not enough ash here to make\n"
# 345 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "that, though, huff-puff.\p"
# 346 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Let's see… {STR_VAR_2} is the number of steps\n"
# 347 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "you'll need to walk through volcanic ash\l"
# 348 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "for me to make that item, huff-puff.\p"
# 349 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Which item would you rather have me\n"
# 350 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "make instead, huff-puff?$"
# 351 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 352 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything:
# 353 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "You've collected all that ash, but you\n"
# 354 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "don't want anything, huff-puff?$"
# 355 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 356 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_IveFinishedGlassItem:
# 357 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Ah, I've finished your {STR_VAR_1}.\n"
# 358 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Take it, huff-puff.$"
# 359 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 360 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_NoRoomInBag:
# 361 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Oh?\n"
# 362 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "You've no room in your BAG, huff-puff.\p"
# 363 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I'll hold on to it, so come back later,\n"
# 364 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "huff-puff.$"
# 365 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 366 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_NoRoomInPC:
# 367 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Oh?\n"
# 368 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "You've no room in your PC, huff-puff?\p"
# 369 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I'll hold on to it, so come back later,\n"
# 370 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "huff-puff.$"
# 371 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 372 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_HaventGotYourSootSack:
# 373 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Hah? You haven't got your SOOT SACK\n"
# 374 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "with you, huff-puff.\p"
# 375 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "You have to keep it with you to collect\n"
# 376 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "volcanic ash, huff-puff.$"
# 377 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 378 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_FunToBlowGlassFlute:
# 379 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "It's fun to blow a glass flute while\n"
# 380 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "my boss is talking.\p"
# 381 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Huff-huff! Puff-puff!$"
