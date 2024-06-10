Megahouse_MapScripts::
	.byte 0


Megahouse_EVO_ITEM_EMPLOYEE::
# 6 "data/maps/Megahouse/scripts.pory"
	lock
# 7 "data/maps/Megahouse/scripts.pory"
	faceplayer
# 8 "data/maps/Megahouse/scripts.pory"
	message Megahouse_EVO_ITEM_EMPLOYEE_Text_0
# 9 "data/maps/Megahouse/scripts.pory"
	waitmessage
# 10 "data/maps/Megahouse/scripts.pory"
	pokemart EVO_ITEMS
# 11 "data/maps/Megahouse/scripts.pory"
	msgbox Megahouse_EVO_ITEM_EMPLOYEE_Text_1
# 12 "data/maps/Megahouse/scripts.pory"
	release
	end


# 16 "data/maps/Megahouse/scripts.pory"

# 17 "data/maps/Megahouse/scripts.pory"

# 18 "data/maps/Megahouse/scripts.pory"
.align 2
# 19 "data/maps/Megahouse/scripts.pory"
EVO_ITEMS::
# 20 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_FIRE_STONE
# 21 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_WATER_STONE
# 22 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_THUNDER_STONE
# 23 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LEAF_STONE
# 24 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ICE_STONE
# 25 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SUN_STONE
# 26 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MOON_STONE
# 27 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SHINY_STONE
# 28 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DUSK_STONE
# 29 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DAWN_STONE
# 30 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_METAL_COAT
# 31 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_RAZOR_CLAW
# 32 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_RAZOR_FANG
# 33 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DEEP_SEA_TOOTH
# 34 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DEEP_SEA_SCALE
# 35 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SWEET_APPLE
# 36 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_TART_APPLE
# 37 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CRACKED_POT
# 38 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CHIPPED_POT
# 39 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GALARICA_CUFF
# 40 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GALARICA_WREATH
# 41 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DRAGON_SCALE
# 42 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_UPGRADE
# 43 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DUBIOUS_DISC
# 44 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PROTECTOR
# 45 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ELECTIRIZER
# 46 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MAGMARIZER
# 47 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_REAPER_CLOTH
# 48 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PRISM_SCALE
# 49 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_WHIPPED_DREAM
# 50 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SACHET
# 51 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_OVAL_STONE
# 52 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PEAT_BLOCK
# 53 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLACK_AUGURITE
# 54 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LINKING_CORD
# 55 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AUSPICIOUS_ARMOR
# 56 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MALICIOUS_ARMOR
# 57 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GIMMIGHOUL_COIN
# 58 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LEADERS_CREST
# 59 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCROLL_OF_DARKNESS
# 60 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCROLL_OF_WATERS
# 61 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SYRUPY_APPLE
# 62 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MASTERPIECE_TEACUP
# 63 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_UNREMARKABLE_TEACUP
# 64 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_METAL_ALLOY
# 65 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_NONE
# 66 "data/maps/Megahouse/scripts.pory"
    release
# 67 "data/maps/Megahouse/scripts.pory"
    end

Megahouse_EVO_ITEM_EMPLOYEE_Text_0:
# 8 "data/maps/Megahouse/scripts.pory"
	.string "How may I serve you?$"

Megahouse_EVO_ITEM_EMPLOYEE_Text_1:
# 11 "data/maps/Megahouse/scripts.pory"
	.string "Please Come Again.$"
