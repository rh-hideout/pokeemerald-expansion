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


# 12 "data/maps/Black_Market/scripts.pory"

# 13 "data/maps/Black_Market/scripts.pory"

# 14 "data/maps/Black_Market/scripts.pory"
Script_Black_Market_BALL_ITEM_EMPLOYEE::
# 15 "data/maps/Black_Market/scripts.pory"
    lock
# 16 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 17 "data/maps/Black_Market/scripts.pory"
    message Text_BMBALL
# 18 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 19 "data/maps/Black_Market/scripts.pory"
    pokemart BM_BALL_ITEMS, 1
# 20 "data/maps/Black_Market/scripts.pory"
    msgbox Text_BMBALLEND
# 21 "data/maps/Black_Market/scripts.pory"
    release
# 22 "data/maps/Black_Market/scripts.pory"
    end
# 23 "data/maps/Black_Market/scripts.pory"

# 24 "data/maps/Black_Market/scripts.pory"
.align 2
# 25 "data/maps/Black_Market/scripts.pory"
BM_BALL_ITEMS:
# 26 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MASTER_BALL, 80000
# 27 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SAFARI_BALL, 300
# 28 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHERISH_BALL, 3000
# 29 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUXURY_BALL, 800
# 30 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ABILITY_CAPSULE, 8000
# 31 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ABILITY_PATCH, 10000
# 32 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LURE, 400
# 33 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SUPER_LURE, 700
# 34 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAX_LURE, 900
# 35 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEART_SCALE, 500
# 36 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EVERSTONE, 3000
# 37 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DOUSE_DRIVE, 1000
# 38 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SHOCK_DRIVE, 1000
# 39 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BURN_DRIVE, 1000
# 40 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHILL_DRIVE, 1000
# 41 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_BAND, 8000
# 42 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_SPECS, 8000
# 43 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_SCARF, 8000
# 44 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FLAME_ORB, 5000
# 45 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TOXIC_ORB, 5000
# 46 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EXP_SHARE, 8000
# 47 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_AMULET_COIN, 8000
# 48 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUCKY_EGG, 8000
# 49 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DESTINY_KNOT, 3000
# 50 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EVIOLITE, 8000
# 51 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BERSERK_GENE, 5000
# 52 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NONE
# 53 "data/maps/Black_Market/scripts.pory"
    release
# 54 "data/maps/Black_Market/scripts.pory"
    end
# 55 "data/maps/Black_Market/scripts.pory"

# 56 "data/maps/Black_Market/scripts.pory"
Text_BMBALL:
# 57 "data/maps/Black_Market/scripts.pory"
    .string "I got some nice stuff from a Warehouse.\n"
# 58 "data/maps/Black_Market/scripts.pory"
    .string "How can I help you?$"
# 59 "data/maps/Black_Market/scripts.pory"

# 60 "data/maps/Black_Market/scripts.pory"
Text_BMBALLEND:
# 61 "data/maps/Black_Market/scripts.pory"
    .string "Please come again!$"

Black_Market_EventScript_Sign_Text_0:
# 6 "data/maps/Black_Market/scripts.pory"
	.string "EMPLOYEES ONLY!!!!\p"
	.string "KEEP OUT WE MEAN IT!!!!$"
