Black_Market_MapScripts::
	.byte 0


Black_Market_EventScript_Sign::
# 5 "data/maps/Black_Market/scripts.pory"
	lockall
# 6 "data/maps/Black_Market/scripts.pory"
	msgbox Black_Market_EventScript_Sign_Text_0
# 8 "data/maps/Black_Market/scripts.pory"
	releaseall
	return


# 11 "data/maps/Black_Market/scripts.pory"

# 12 "data/maps/Black_Market/scripts.pory"

# 13 "data/maps/Black_Market/scripts.pory"
Script_Black_Market_BALL_ITEM_EMPLOYEE::
# 14 "data/maps/Black_Market/scripts.pory"
    lock
# 15 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 16 "data/maps/Black_Market/scripts.pory"
    message Text_BMBALL
# 17 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 18 "data/maps/Black_Market/scripts.pory"
    pokemart BM_BALL_ITEMS
# 19 "data/maps/Black_Market/scripts.pory"
    msgbox Text_BMBALLEND
# 20 "data/maps/Black_Market/scripts.pory"
    release
# 21 "data/maps/Black_Market/scripts.pory"
    end
# 22 "data/maps/Black_Market/scripts.pory"

# 23 "data/maps/Black_Market/scripts.pory"
    .align 2
# 24 "data/maps/Black_Market/scripts.pory"
BM_BALL_ITEMS:
# 25 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MASTER_BALL, 80000
# 26 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SAFARI_BALL, 300
# 27 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHERISH_BALL, 3000
# 28 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUXURY_BALL, 800
# 29 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ABILITY_CAPSULE, 8000
# 30 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ABILITY_PATCH, 10000
# 31 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LURE, 400
# 32 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SUPER_LURE, 700
# 33 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAX_LURE, 900
# 34 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEART_SCALE, 500
# 35 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EVERSTONE, 3000
# 36 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DOUSE_DRIVE, 1000
# 37 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SHOCK_DRIVE, 1000
# 38 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BURN_DRIVE, 1000
# 39 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHILL_DRIVE, 1000
# 40 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_BAND, 8000
# 41 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_SPECS, 8000
# 42 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_SCARF, 8000
# 43 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FLAME_ORB, 5000
# 44 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TOXIC_ORB, 5000
# 45 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EXP_SHARE, 8000
# 46 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_AMULET_COIN, 8000
# 47 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUCKY_EGG, 8000
# 48 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DESTINY_KNOT, 3000
# 49 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EVIOLITE, 8000
# 50 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BERSERK_GENE, 5000
# 51 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NONE
# 52 "data/maps/Black_Market/scripts.pory"
    release
# 53 "data/maps/Black_Market/scripts.pory"
    end
# 54 "data/maps/Black_Market/scripts.pory"

# 55 "data/maps/Black_Market/scripts.pory"
Text_BMBALL:
# 56 "data/maps/Black_Market/scripts.pory"
    .string "I got some nice stuff from a Warehouse.\n"
# 57 "data/maps/Black_Market/scripts.pory"
    .string "How can I help you?$"
# 58 "data/maps/Black_Market/scripts.pory"

# 59 "data/maps/Black_Market/scripts.pory"
Text_BMBALLEND:
# 60 "data/maps/Black_Market/scripts.pory"
    .string "Please come again!$"

Black_Market_EventScript_Sign_Text_0:
# 6 "data/maps/Black_Market/scripts.pory"
	.string "EMPLOYEES ONLY!!!!\p"
	.string "KEEP OUT WE MEAN IT!!!!$"
