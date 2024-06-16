ZHouse_MapScripts::
	.byte 0


ZHouse_Fossil_ITEM_EMPLOYEE::
# 6 "data/maps/ZHouse/scripts.pory"
	lock
# 7 "data/maps/ZHouse/scripts.pory"
	faceplayer
# 8 "data/maps/ZHouse/scripts.pory"
	message ZHouse_Fossil_ITEM_EMPLOYEE_Text_0
# 9 "data/maps/ZHouse/scripts.pory"
	waitmessage
# 10 "data/maps/ZHouse/scripts.pory"
	pokemart FOSSILSANDMINTS_ITEMS
# 11 "data/maps/ZHouse/scripts.pory"
	msgbox ZHouse_Fossil_ITEM_EMPLOYEE_Text_1
# 12 "data/maps/ZHouse/scripts.pory"
	release
	end


ZHouse_Z_ITEM_EMPLOYEE::
# 17 "data/maps/ZHouse/scripts.pory"
	lock
# 18 "data/maps/ZHouse/scripts.pory"
	faceplayer
# 19 "data/maps/ZHouse/scripts.pory"
	message ZHouse_Fossil_ITEM_EMPLOYEE_Text_0
# 20 "data/maps/ZHouse/scripts.pory"
	waitmessage
# 21 "data/maps/ZHouse/scripts.pory"
	pokemart Z_ITEMS
# 22 "data/maps/ZHouse/scripts.pory"
	msgbox ZHouse_Fossil_ITEM_EMPLOYEE_Text_1
# 23 "data/maps/ZHouse/scripts.pory"
	release
	end


# 27 "data/maps/ZHouse/scripts.pory"

# 28 "data/maps/ZHouse/scripts.pory"

# 29 "data/maps/ZHouse/scripts.pory"
EventScript_ZMan::
# 30 "data/maps/ZHouse/scripts.pory"
    lock
# 31 "data/maps/ZHouse/scripts.pory"
    faceplayer
# 32 "data/maps/ZHouse/scripts.pory"
    message gText_ZMan
# 33 "data/maps/ZHouse/scripts.pory"
    waitmessage
# 34 "data/maps/ZHouse/scripts.pory"
    checkitem ITEM_Z_POWER_RING, 1
# 35 "data/maps/ZHouse/scripts.pory"
    compare VAR_RESULT, 1
# 36 "data/maps/ZHouse/scripts.pory"
    goto_if_eq Script_Havezring
# 37 "data/maps/ZHouse/scripts.pory"
    waitmessage
# 38 "data/maps/ZHouse/scripts.pory"
    message gText_Hereiszring
# 39 "data/maps/ZHouse/scripts.pory"
    giveitem ITEM_Z_POWER_RING
# 40 "data/maps/ZHouse/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 41 "data/maps/ZHouse/scripts.pory"
    release
# 42 "data/maps/ZHouse/scripts.pory"
    end
# 43 "data/maps/ZHouse/scripts.pory"

# 44 "data/maps/ZHouse/scripts.pory"
.align 2
# 45 "data/maps/ZHouse/scripts.pory"
FOSSILSANDMINTS_ITEMS::
# 46 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_HELIX_FOSSIL
# 47 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_DOME_FOSSIL
# 48 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_OLD_AMBER
# 49 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_ROOT_FOSSIL
# 50 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_CLAW_FOSSIL
# 51 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_ARMOR_FOSSIL
# 52 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_SKULL_FOSSIL
# 53 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_COVER_FOSSIL
# 54 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_PLUME_FOSSIL
# 55 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_JAW_FOSSIL
# 56 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_SAIL_FOSSIL
# 57 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_FOSSILIZED_BIRD
# 58 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_FOSSILIZED_DINO
# 59 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_FOSSILIZED_DRAKE
# 60 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_FOSSILIZED_FISH
# 61 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_LONELY_MINT
# 62 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_ADAMANT_MINT
# 63 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_NAUGHTY_MINT
# 64 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_BRAVE_MINT
# 65 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_BOLD_MINT
# 66 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_IMPISH_MINT
# 67 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_LAX_MINT
# 68 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_RELAXED_MINT
# 69 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_MODEST_MINT
# 70 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_MILD_MINT
# 71 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_RASH_MINT
# 72 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_QUIET_MINT
# 73 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_CALM_MINT
# 74 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_GENTLE_MINT
# 75 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_CAREFUL_MINT
# 76 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_SASSY_MINT
# 77 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_TIMID_MINT
# 78 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_HASTY_MINT
# 79 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_JOLLY_MINT
# 80 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_NAIVE_MINT
# 81 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_SERIOUS_MINT
# 82 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_ABILITY_CAPSULE
# 83 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_ABILITY_PATCH
# 84 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_NONE
# 85 "data/maps/ZHouse/scripts.pory"
    release
# 86 "data/maps/ZHouse/scripts.pory"
    end
# 87 "data/maps/ZHouse/scripts.pory"

# 88 "data/maps/ZHouse/scripts.pory"
.align 2
# 89 "data/maps/ZHouse/scripts.pory"
Z_ITEMS::
# 90 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_NORMALIUM_Z
# 91 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_FIRIUM_Z
# 92 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_WATERIUM_Z
# 93 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_ELECTRIUM_Z
# 94 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_GRASSIUM_Z
# 95 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_ICIUM_Z
# 96 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_FIGHTINIUM_Z
# 97 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_POISONIUM_Z
# 98 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_GROUNDIUM_Z
# 99 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_FLYINIUM_Z
# 100 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_PSYCHIUM_Z
# 101 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_BUGINIUM_Z
# 102 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_ROCKIUM_Z
# 103 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_GHOSTIUM_Z
# 104 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_DRAGONIUM_Z
# 105 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_DARKINIUM_Z
# 106 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_STEELIUM_Z
# 107 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_FAIRIUM_Z
# 108 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_PIKANIUM_Z
# 109 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_EEVIUM_Z
# 110 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_SNORLIUM_Z
# 111 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_MEWNIUM_Z
# 112 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_DECIDIUM_Z
# 113 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_INCINIUM_Z
# 114 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_PRIMARIUM_Z
# 115 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_LYCANIUM_Z
# 116 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_MIMIKIUM_Z
# 117 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_KOMMONIUM_Z
# 118 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_TAPUNIUM_Z
# 119 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_SOLGANIUM_Z
# 120 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_LUNALIUM_Z
# 121 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_MARSHADIUM_Z
# 122 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_ALORAICHIUM_Z
# 123 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_PIKASHUNIUM_Z
# 124 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_ULTRANECROZIUM_Z
# 125 "data/maps/ZHouse/scripts.pory"
    .2byte ITEM_NONE
# 126 "data/maps/ZHouse/scripts.pory"
    release
# 127 "data/maps/ZHouse/scripts.pory"
    end
# 128 "data/maps/ZHouse/scripts.pory"

# 129 "data/maps/ZHouse/scripts.pory"
Script_Havezring::
# 130 "data/maps/ZHouse/scripts.pory"
    msgbox gText_Haveazring
# 131 "data/maps/ZHouse/scripts.pory"
    release
# 132 "data/maps/ZHouse/scripts.pory"
    end
# 133 "data/maps/ZHouse/scripts.pory"

# 134 "data/maps/ZHouse/scripts.pory"
gText_ZMan::
# 135 "data/maps/ZHouse/scripts.pory"
    .string "Hi! I am Zee the Z Move Man!\p"
# 136 "data/maps/ZHouse/scripts.pory"
    .string "Here join me in this adventure!\p $"
# 137 "data/maps/ZHouse/scripts.pory"

# 138 "data/maps/ZHouse/scripts.pory"
gText_Haveazring::
# 139 "data/maps/ZHouse/scripts.pory"
    .string "You already have a Z-POWER RING!$"
# 140 "data/maps/ZHouse/scripts.pory"

# 141 "data/maps/ZHouse/scripts.pory"
gText_Hereiszring::
# 142 "data/maps/ZHouse/scripts.pory"
    .string "Here is your Z-Power Ring!$"

ZHouse_Fossil_ITEM_EMPLOYEE_Text_0:
# 8 "data/maps/ZHouse/scripts.pory"
	.string "How may I serve you?$"

ZHouse_Fossil_ITEM_EMPLOYEE_Text_1:
# 11 "data/maps/ZHouse/scripts.pory"
	.string "Please Come Again.$"
