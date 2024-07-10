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
Script_Black_Market_SHARD_ITEM_EMPLOYEE::
# 15 "data/maps/Black_Market/scripts.pory"
    lock
# 16 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 17 "data/maps/Black_Market/scripts.pory"
    message Text_BMSHARD
# 18 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 19 "data/maps/Black_Market/scripts.pory"
    pokemart BM_SHARD_ITEMS
# 20 "data/maps/Black_Market/scripts.pory"
    msgbox Text_BMSHARDEND
# 21 "data/maps/Black_Market/scripts.pory"
    release
# 22 "data/maps/Black_Market/scripts.pory"
    end
# 23 "data/maps/Black_Market/scripts.pory"

# 24 "data/maps/Black_Market/scripts.pory"
Script_Black_Market_BALL_ITEM_EMPLOYEE::
# 25 "data/maps/Black_Market/scripts.pory"
    lock
# 26 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 27 "data/maps/Black_Market/scripts.pory"
    message Text_BMBALL
# 28 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 29 "data/maps/Black_Market/scripts.pory"
    pokemart BM_BALL_ITEMS
# 30 "data/maps/Black_Market/scripts.pory"
    msgbox Text_BMBALLEND
# 31 "data/maps/Black_Market/scripts.pory"
    release
# 32 "data/maps/Black_Market/scripts.pory"
    end
# 33 "data/maps/Black_Market/scripts.pory"

# 34 "data/maps/Black_Market/scripts.pory"
.align 2
# 35 "data/maps/Black_Market/scripts.pory"
BM_SHARD_ITEMS:
# 36 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RED_SHARD
# 37 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BLUE_SHARD
# 38 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_YELLOW_SHARD
# 39 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GREEN_SHARD
# 40 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STRAWBERRY_SWEET
# 41 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LOVE_SWEET
# 42 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BERRY_SWEET
# 43 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CLOVER_SWEET
# 44 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FLOWER_SWEET
# 45 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STAR_SWEET
# 46 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RIBBON_SWEET
# 47 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RED_NECTAR
# 48 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_YELLOW_NECTAR
# 49 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PINK_NECTAR
# 50 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PURPLE_NECTAR
# 51 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DYNAMAX_CANDY
# 52 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LIGHT_BALL
# 53 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LEEK
# 54 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_THICK_CLUB
# 55 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUCKY_PUNCH
# 56 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_METAL_POWDER
# 57 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_QUICK_POWDER
# 58 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BRIGHT_POWDER
# 59 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ADAMANT_ORB
# 60 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUSTROUS_ORB
# 61 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GRISEOUS_ORB
# 62 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROCKY_HELMET
# 63 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_AIR_BALLOON
# 64 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WEAKNESS_POLICY
# 65 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BLUNDER_POLICY
# 66 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EXPERT_BELT
# 67 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WISE_GLASSES
# 68 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MUSCLE_BAND
# 69 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SHELL_BELL
# 70 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WIDE_LENS
# 71 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ZOOM_LENS
# 72 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SCOPE_LENS
# 73 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_QUICK_CLAW
# 74 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ASSAULT_VEST
# 75 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SAFETY_GOGGLES
# 76 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TERRAIN_EXTENDER
# 77 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PROTECTIVE_PADS
# 78 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_THROAT_SPRAY
# 79 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEAVY_DUTY_BOOTS
# 80 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROOM_SERVICE
# 81 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_METRONOME
# 82 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_UTILITY_UMBRELLA
# 83 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_COVERT_CLOAK
# 84 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LOADED_DICE
# 85 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RING_TARGET
# 86 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RED_CARD
# 87 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MIRROR_HERB
# 88 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BINDING_BAND
# 89 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ADAMANT_CRYSTAL
# 90 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GRISEOUS_CORE
# 91 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUSTROUS_GLOBE
# 92 "data/maps/Black_Market/scripts.pory"

# 93 "data/maps/Black_Market/scripts.pory"

# 94 "data/maps/Black_Market/scripts.pory"

# 95 "data/maps/Black_Market/scripts.pory"

# 96 "data/maps/Black_Market/scripts.pory"
.align 2
# 97 "data/maps/Black_Market/scripts.pory"
BM_BALL_ITEMS:
# 98 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MASTER_BALL
# 99 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SAFARI_BALL
# 100 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHERISH_BALL
# 101 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUXURY_BALL
# 102 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ABILITY_CAPSULE
# 103 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ABILITY_PATCH
# 104 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LURE
# 105 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SUPER_LURE
# 106 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAX_LURE
# 107 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PP_MAX
# 108 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAX_ELIXIR
# 109 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BERRY_JUICE
# 110 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEART_SCALE
# 111 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EVERSTONE
# 112 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DOUSE_DRIVE
# 113 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SHOCK_DRIVE
# 114 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BURN_DRIVE
# 115 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHILL_DRIVE
# 116 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WELLSPRING_MASK
# 117 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CORNERSTONE_MASK
# 118 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEARTHFLAME_MASK
# 119 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_BAND
# 120 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_SPECS
# 121 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_SCARF
# 122 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STICKY_BARB
# 123 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LEFTOVERS
# 124 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_KINGS_ROCK
# 125 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CLEANSE_TAG
# 126 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SOOTHE_BELL
# 127 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FLAME_ORB
# 128 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TOXIC_ORB
# 129 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LIFE_ORB
# 130 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SMOKE_BALL
# 131 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DAMP_ROCK
# 132 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEAT_ROCK
# 133 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SMOOTH_ROCK
# 134 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BLACK_SLUDGE
# 135 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CLEAR_AMULET
# 136 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GRIP_CLAW
# 137 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PUNCHING_GLOVE
# 138 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EXP_SHARE
# 139 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_AMULET_COIN
# 140 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MACHO_BRACE
# 141 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUCKY_EGG
# 142 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DESTINY_KNOT
# 143 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FOCUS_BAND
# 144 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FOCUS_SASH
# 145 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EVIOLITE
# 146 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BERSERK_GENE
# 147 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BOOSTER_ENERGY
# 148 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NONE
# 149 "data/maps/Black_Market/scripts.pory"
    release
# 150 "data/maps/Black_Market/scripts.pory"
    end
# 151 "data/maps/Black_Market/scripts.pory"

# 152 "data/maps/Black_Market/scripts.pory"
Text_BMBALL:
# 153 "data/maps/Black_Market/scripts.pory"
    .string "I got some nice stuff from a Warehouse.\p"
# 154 "data/maps/Black_Market/scripts.pory"
    .string "How can I help you?$"
# 155 "data/maps/Black_Market/scripts.pory"

# 156 "data/maps/Black_Market/scripts.pory"
Text_BMSHARD:
# 157 "data/maps/Black_Market/scripts.pory"
    .string "I got some nice stuff from a Ship.\p"
# 158 "data/maps/Black_Market/scripts.pory"
    .string "How can I help you?$"
# 159 "data/maps/Black_Market/scripts.pory"

# 160 "data/maps/Black_Market/scripts.pory"
Text_BMSHARDEND:
# 161 "data/maps/Black_Market/scripts.pory"
    .string "Please come again!$"
# 162 "data/maps/Black_Market/scripts.pory"

# 163 "data/maps/Black_Market/scripts.pory"
Text_BMBALLEND:
# 164 "data/maps/Black_Market/scripts.pory"
    .string "Please come again!$"
# 165 "data/maps/Black_Market/scripts.pory"

# 166 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_EggWoman::
# 167 "data/maps/Black_Market/scripts.pory"
    lock
# 168 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 169 "data/maps/Black_Market/scripts.pory"
    showmoneybox 0, 0
# 170 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_EggsJust5000, MSGBOX_YESNO
# 171 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, GatchaBegg_EventScript_DeclineEgg
# 172 "data/maps/Black_Market/scripts.pory"
    checkmoney 5000
# 173 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, FALSE, GatchaBegg_EventScript_NotEnoughMoney
# 174 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_ThankYouDear, MSGBOX_DEFAULT
# 175 "data/maps/Black_Market/scripts.pory"
    getpartysize
# 176 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, PARTY_SIZE, GatchaBegg_EventScript_NoRoomForEgg
# 177 "data/maps/Black_Market/scripts.pory"
    removemoney 5000
# 178 "data/maps/Black_Market/scripts.pory"
    updatemoneybox
# 179 "data/maps/Black_Market/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 180 "data/maps/Black_Market/scripts.pory"
    message GatchaBegg_Text_ReceivedTheEgg
# 181 "data/maps/Black_Market/scripts.pory"
    waitfanfare
# 182 "data/maps/Black_Market/scripts.pory"
    specialvar VAR_RESULT, ChooseRandomEggSpeciesIII
# 183 "data/maps/Black_Market/scripts.pory"
    giveegg VAR_RESULT
# 184 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 185 "data/maps/Black_Market/scripts.pory"
    release
# 186 "data/maps/Black_Market/scripts.pory"
    end
# 187 "data/maps/Black_Market/scripts.pory"

# 188 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_EggsJust5000:
# 189 "data/maps/Black_Market/scripts.pory"
    .string "Pokémon eggs that were locally taken.\n"
# 190 "data/maps/Black_Market/scripts.pory"
    .string "These ones were hand picked.\p"
# 191 "data/maps/Black_Market/scripts.pory"
    .string "Buy a hot one. It's just ¥5000.$"
# 192 "data/maps/Black_Market/scripts.pory"

# 193 "data/maps/Black_Market/scripts.pory"

# 194 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_DeclineEgg::
# 195 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_OhFineThen, MSGBOX_DEFAULT
# 196 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 197 "data/maps/Black_Market/scripts.pory"
    release
# 198 "data/maps/Black_Market/scripts.pory"
    end
# 199 "data/maps/Black_Market/scripts.pory"

# 200 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_OhFineThen:
# 201 "data/maps/Black_Market/scripts.pory"
    .string "Oh, fine then. Scram!$"
# 202 "data/maps/Black_Market/scripts.pory"

# 203 "data/maps/Black_Market/scripts.pory"

# 204 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_NotEnoughMoney::
# 205 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 206 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 207 "data/maps/Black_Market/scripts.pory"
    release
# 208 "data/maps/Black_Market/scripts.pory"
    end
# 209 "data/maps/Black_Market/scripts.pory"

# 210 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_YouveNotGotTheMoney:
# 211 "data/maps/Black_Market/scripts.pory"
    .string "You know… You can't buy a thing if\n"
# 212 "data/maps/Black_Market/scripts.pory"
    .string "you've not got the money!$"
# 213 "data/maps/Black_Market/scripts.pory"

# 214 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_ThankYouDear:
# 215 "data/maps/Black_Market/scripts.pory"
    .string "Thank you, dearie! Come Again!$"
# 216 "data/maps/Black_Market/scripts.pory"

# 217 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_NoRoomForEgg::
# 218 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 219 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 220 "data/maps/Black_Market/scripts.pory"
    release
# 221 "data/maps/Black_Market/scripts.pory"
    end
# 222 "data/maps/Black_Market/scripts.pory"

# 223 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_NoRoomForThisEgg:
# 224 "data/maps/Black_Market/scripts.pory"
    .string "Oh? You've too many POKéMON.\n"
# 225 "data/maps/Black_Market/scripts.pory"
    .string "There's no room for this EGG…$"
# 226 "data/maps/Black_Market/scripts.pory"

# 227 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_ReceivedTheEgg:
# 228 "data/maps/Black_Market/scripts.pory"
    .string "{PLAYER} received the EGG.$"
# 229 "data/maps/Black_Market/scripts.pory"

# 230 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_CandyMan::
# 231 "data/maps/Black_Market/scripts.pory"
    lock
# 232 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 233 "data/maps/Black_Market/scripts.pory"
    showmoneybox 0, 0
# 234 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_CandyJust5000, MSGBOX_YESNO
# 235 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, BlackMarket_EventScript_DeclineCandy
# 236 "data/maps/Black_Market/scripts.pory"
    checkmoney 5000
# 237 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, FALSE, BlackMarket_EventScript_NotEnoughMonies
# 238 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_ThankYouDear, MSGBOX_DEFAULT
# 239 "data/maps/Black_Market/scripts.pory"
    checkitemspace ITEM_RARE_CANDY
# 240 "data/maps/Black_Market/scripts.pory"
    call_if_eq VAR_RESULT, TRUE, BlackMarket_EventScript_RemoveMonies
# 241 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_RARE_CANDY
# 242 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, FALSE, BlackMarket_EventScript_BagIsFull
# 243 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 244 "data/maps/Black_Market/scripts.pory"
    release
# 245 "data/maps/Black_Market/scripts.pory"
    end
# 246 "data/maps/Black_Market/scripts.pory"

# 247 "data/maps/Black_Market/scripts.pory"

# 248 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_BagIsFull::
# 249 "data/maps/Black_Market/scripts.pory"
    msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 250 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 251 "data/maps/Black_Market/scripts.pory"
    release
# 252 "data/maps/Black_Market/scripts.pory"
    end
# 253 "data/maps/Black_Market/scripts.pory"

# 254 "data/maps/Black_Market/scripts.pory"

# 255 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_RemoveMonies::
# 256 "data/maps/Black_Market/scripts.pory"
    removemoney 5000
# 257 "data/maps/Black_Market/scripts.pory"
    updatemoneybox
# 258 "data/maps/Black_Market/scripts.pory"
    return
# 259 "data/maps/Black_Market/scripts.pory"

# 260 "data/maps/Black_Market/scripts.pory"

# 261 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_DeclineCandy::
# 262 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_OhFineThen, MSGBOX_DEFAULT
# 263 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 264 "data/maps/Black_Market/scripts.pory"
    release
# 265 "data/maps/Black_Market/scripts.pory"
    end
# 266 "data/maps/Black_Market/scripts.pory"

# 267 "data/maps/Black_Market/scripts.pory"

# 268 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_NotEnoughMonies::
# 269 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_YouveNotGotTheMonies, MSGBOX_DEFAULT
# 270 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 271 "data/maps/Black_Market/scripts.pory"
    release
# 272 "data/maps/Black_Market/scripts.pory"
    end
# 273 "data/maps/Black_Market/scripts.pory"

# 274 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_CandyJust5000:
# 275 "data/maps/Black_Market/scripts.pory"
    .string "Want some Candy? It is a\n"
# 276 "data/maps/Black_Market/scripts.pory"
    .string "local specialty.\p"
# 277 "data/maps/Black_Market/scripts.pory"
    .string "Try one. It's just ¥5000.$"
# 278 "data/maps/Black_Market/scripts.pory"

# 279 "data/maps/Black_Market/scripts.pory"

# 280 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_ThankYouDear:
# 281 "data/maps/Black_Market/scripts.pory"
    .string "Thank you, dearie!$"
# 282 "data/maps/Black_Market/scripts.pory"

# 283 "data/maps/Black_Market/scripts.pory"

# 284 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_YouveNotGotTheMonies:
# 285 "data/maps/Black_Market/scripts.pory"
    .string "You know… You can't buy a thing if\n"
# 286 "data/maps/Black_Market/scripts.pory"
    .string "you've not got the money!$"
# 287 "data/maps/Black_Market/scripts.pory"

# 288 "data/maps/Black_Market/scripts.pory"

# 289 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_OhFineThen:
# 290 "data/maps/Black_Market/scripts.pory"
    .string "Oh, fine then. Scram!$"
# 291 "data/maps/Black_Market/scripts.pory"

# 292 "data/maps/Black_Market/scripts.pory"
EventScript_SHINYCHARMGift::
# 293 "data/maps/Black_Market/scripts.pory"
    lock
# 294 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 295 "data/maps/Black_Market/scripts.pory"
    message gText_Charmtext
# 296 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 297 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_SHINY_CHARM, 1
# 298 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 299 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 300 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 301 "data/maps/Black_Market/scripts.pory"
    message gText_Hereischarm
# 302 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_SHINY_CHARM
# 303 "data/maps/Black_Market/scripts.pory"
    release
# 304 "data/maps/Black_Market/scripts.pory"
    end
# 305 "data/maps/Black_Market/scripts.pory"

# 306 "data/maps/Black_Market/scripts.pory"

# 307 "data/maps/Black_Market/scripts.pory"
Script_havecharm::
# 308 "data/maps/Black_Market/scripts.pory"
    msgbox gText_havecharm
# 309 "data/maps/Black_Market/scripts.pory"
    release
# 310 "data/maps/Black_Market/scripts.pory"
    end
# 311 "data/maps/Black_Market/scripts.pory"

# 312 "data/maps/Black_Market/scripts.pory"

# 313 "data/maps/Black_Market/scripts.pory"
gText_Charmtext::
# 314 "data/maps/Black_Market/scripts.pory"
    .string "Hey I have a gift from Team Aqua!\p $"
# 315 "data/maps/Black_Market/scripts.pory"

# 316 "data/maps/Black_Market/scripts.pory"

# 317 "data/maps/Black_Market/scripts.pory"
gText_havecharm::
# 318 "data/maps/Black_Market/scripts.pory"
    .string "Have I threatened you before?$"
# 319 "data/maps/Black_Market/scripts.pory"

# 320 "data/maps/Black_Market/scripts.pory"

# 321 "data/maps/Black_Market/scripts.pory"
gText_Hereischarm::
# 322 "data/maps/Black_Market/scripts.pory"
    .string "Here! You better join our team!$"
# 323 "data/maps/Black_Market/scripts.pory"

# 324 "data/maps/Black_Market/scripts.pory"
EventScript_EXPCHARMGift::
# 325 "data/maps/Black_Market/scripts.pory"
    lock
# 326 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 327 "data/maps/Black_Market/scripts.pory"
    message gText_CharmEtext
# 328 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 329 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_EXP_CHARM, 1
# 330 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 331 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 332 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 333 "data/maps/Black_Market/scripts.pory"
    message gText_Hereischarm
# 334 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_EXP_CHARM
# 335 "data/maps/Black_Market/scripts.pory"
    release
# 336 "data/maps/Black_Market/scripts.pory"
    end
# 337 "data/maps/Black_Market/scripts.pory"

# 338 "data/maps/Black_Market/scripts.pory"
    gText_CharmEtext::
# 339 "data/maps/Black_Market/scripts.pory"
    .string "Hey I have a gift from Team Magma!\p $"
# 340 "data/maps/Black_Market/scripts.pory"

# 341 "data/maps/Black_Market/scripts.pory"
EventScript_EGGCHARMGift::
# 342 "data/maps/Black_Market/scripts.pory"
    lock
# 343 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 344 "data/maps/Black_Market/scripts.pory"
    message gText_CharmEggtext
# 345 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 346 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_OVAL_CHARM, 1
# 347 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 348 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 349 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 350 "data/maps/Black_Market/scripts.pory"
    message gText_HereisEggcharm
# 351 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_OVAL_CHARM
# 352 "data/maps/Black_Market/scripts.pory"
    release
# 353 "data/maps/Black_Market/scripts.pory"
    end
# 354 "data/maps/Black_Market/scripts.pory"

# 355 "data/maps/Black_Market/scripts.pory"
    gText_CharmEggtext::
# 356 "data/maps/Black_Market/scripts.pory"
    .string "Do I have an amazing gift for you!\p $"
# 357 "data/maps/Black_Market/scripts.pory"

# 358 "data/maps/Black_Market/scripts.pory"
    gText_HereisEggcharm::
# 359 "data/maps/Black_Market/scripts.pory"
    .string "Hope you use this charm wisely....\p $"
# 360 "data/maps/Black_Market/scripts.pory"

# 361 "data/maps/Black_Market/scripts.pory"
EventScript_CATCHCHARMGift::
# 362 "data/maps/Black_Market/scripts.pory"
    lock
# 363 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 364 "data/maps/Black_Market/scripts.pory"
    message gText_CharmCatchtext
# 365 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 366 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_CATCHING_CHARM, 1
# 367 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 368 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 369 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 370 "data/maps/Black_Market/scripts.pory"
    message gText_HereisCatchcharm
# 371 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_CATCHING_CHARM
# 372 "data/maps/Black_Market/scripts.pory"
    release
# 373 "data/maps/Black_Market/scripts.pory"
    end
# 374 "data/maps/Black_Market/scripts.pory"

# 375 "data/maps/Black_Market/scripts.pory"
    gText_CharmCatchtext::
# 376 "data/maps/Black_Market/scripts.pory"
    .string "Do I have an amazing gift for you!\p $"
# 377 "data/maps/Black_Market/scripts.pory"

# 378 "data/maps/Black_Market/scripts.pory"
    gText_HereisCatchcharm::
# 379 "data/maps/Black_Market/scripts.pory"
    .string "Hope you use this charm a lot....\p $"
# 380 "data/maps/Black_Market/scripts.pory"

# 381 "data/maps/Black_Market/scripts.pory"
EventScript_DBANDGift::
# 382 "data/maps/Black_Market/scripts.pory"
    lock
# 383 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 384 "data/maps/Black_Market/scripts.pory"
    message gText_DBANDtext
# 385 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 386 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_DYNAMAX_BAND, 1
# 387 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 388 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 389 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 390 "data/maps/Black_Market/scripts.pory"
    message gText_DBANDcharm
# 391 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_DYNAMAX_BAND
# 392 "data/maps/Black_Market/scripts.pory"
    setflag FLAG_DYNAMAX_BATTLE
# 393 "data/maps/Black_Market/scripts.pory"
    release
# 394 "data/maps/Black_Market/scripts.pory"
    end
# 395 "data/maps/Black_Market/scripts.pory"

# 396 "data/maps/Black_Market/scripts.pory"
gText_DBANDtext::
# 397 "data/maps/Black_Market/scripts.pory"
    .string "First timers get a free gift!\p $"
# 398 "data/maps/Black_Market/scripts.pory"

# 399 "data/maps/Black_Market/scripts.pory"
    gText_DBANDcharm::
# 400 "data/maps/Black_Market/scripts.pory"
    .string "Hope you use this band wisely....\p $"
# 401 "data/maps/Black_Market/scripts.pory"

# 402 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceiveMarshadow::
# 403 "data/maps/Black_Market/scripts.pory"
    lock
# 404 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 405 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
# 406 "data/maps/Black_Market/scripts.pory"
    setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MARSHADOW
# 407 "data/maps/Black_Market/scripts.pory"
    givemon SPECIES_MARSHADOW, 20, item=ITEM_MARSHADIUM_Z, ball=ITEM_DUSK_BALL, nature=NATURE_JOLLY; 
# 408 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BlackMarket_EventScript_ReceiveMarshadowParty
# 409 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BlackMarket_EventScript_ReceiveMarshadowPC
# 410 "data/maps/Black_Market/scripts.pory"
    goto Common_EventScript_NoMoreRoomForPokemon
# 411 "data/maps/Black_Market/scripts.pory"
    end
# 412 "data/maps/Black_Market/scripts.pory"

# 413 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceiveMarshadowParty::
# 414 "data/maps/Black_Market/scripts.pory"
    call BlackMarket_EventScript_ReceivedMarshadowFanfare
# 415 "data/maps/Black_Market/scripts.pory"
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 416 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, BlackMarket_EventScript_ExplainMarshadow
# 417 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_GetGiftMonPartySlot
# 418 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_NameReceivedPartyMon
# 419 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_ExplainMarshadow
# 420 "data/maps/Black_Market/scripts.pory"
    end
# 421 "data/maps/Black_Market/scripts.pory"

# 422 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceiveMarshadowPC::
# 423 "data/maps/Black_Market/scripts.pory"
    call BlackMarket_EventScript_ReceivedMarshadowFanfare
# 424 "data/maps/Black_Market/scripts.pory"
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 425 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, BlackMarket_EventScript_SendMarshadowToPC
# 426 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_NameReceivedBoxMon
# 427 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_SendMarshadowToPC
# 428 "data/maps/Black_Market/scripts.pory"
    end
# 429 "data/maps/Black_Market/scripts.pory"

# 430 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_SendMarshadowToPC::
# 431 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_TransferredToPC
# 432 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_ExplainMarshadow
# 433 "data/maps/Black_Market/scripts.pory"
    end
# 434 "data/maps/Black_Market/scripts.pory"

# 435 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceivedMarshadowFanfare::
# 436 "data/maps/Black_Market/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 437 "data/maps/Black_Market/scripts.pory"
    message BlackMarket_Text_PlayerReceivedMarshadow
# 438 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 439 "data/maps/Black_Market/scripts.pory"
    waitfanfare
# 440 "data/maps/Black_Market/scripts.pory"
    bufferspeciesname STR_VAR_1, SPECIES_MARSHADOW
# 441 "data/maps/Black_Market/scripts.pory"
    return
# 442 "data/maps/Black_Market/scripts.pory"

# 443 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ExplainMarshadow::
# 444 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_PokemonChanges, MSGBOX_DEFAULT
# 445 "data/maps/Black_Market/scripts.pory"
    setflag FLAG_RECEIVED_MARSHADOW
# 446 "data/maps/Black_Market/scripts.pory"
    release
# 447 "data/maps/Black_Market/scripts.pory"
    end
# 448 "data/maps/Black_Market/scripts.pory"

# 449 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_HaveMarshadow::
# 450 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_PokemonChanges, MSGBOX_DEFAULT
# 451 "data/maps/Black_Market/scripts.pory"
    release
# 452 "data/maps/Black_Market/scripts.pory"
    end
# 453 "data/maps/Black_Market/scripts.pory"

# 454 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_HEXMANIAC::
# 455 "data/maps/Black_Market/scripts.pory"
    lock
# 456 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 457 "data/maps/Black_Market/scripts.pory"
    goto_if_set FLAG_RECEIVED_MARSHADOW, BlackMarket_EventScript_HaveMarshadow
# 458 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_ReceiveMarshadow
# 459 "data/maps/Black_Market/scripts.pory"
    end
# 460 "data/maps/Black_Market/scripts.pory"

# 461 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_PlayerReceivedMarshadow:
# 462 "data/maps/Black_Market/scripts.pory"
    .string "{PLAYER} received MARSHADOW!$"
# 463 "data/maps/Black_Market/scripts.pory"

# 464 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_ThanksPleaseTakePokemon:
# 465 "data/maps/Black_Market/scripts.pory"
    .string "Thanks for not snitching!\n"
# 466 "data/maps/Black_Market/scripts.pory"
    .string "Thanks to you, we're safe!\p"
# 467 "data/maps/Black_Market/scripts.pory"
    .string "It might be an odd way of welcoming you,\n"
# 468 "data/maps/Black_Market/scripts.pory"
    .string "but take this POKéMON.$"
# 469 "data/maps/Black_Market/scripts.pory"

# 470 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_PokemonChanges:
# 471 "data/maps/Black_Market/scripts.pory"
    .string "That POKéMON hides according\n"
# 472 "data/maps/Black_Market/scripts.pory"
    .string "to the area conditions.\p"
# 473 "data/maps/Black_Market/scripts.pory"
    .string "There're plenty of them in the…\n"
# 474 "data/maps/Black_Market/scripts.pory"
    .string "nevermind--go ahead and take it.$"
# 475 "data/maps/Black_Market/scripts.pory"

# 476 "data/maps/Black_Market/scripts.pory"
EventScript_PanicingGuyGift::
# 477 "data/maps/Black_Market/scripts.pory"
    lock
# 478 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 479 "data/maps/Black_Market/scripts.pory"
    message gText_Panicingtext
# 480 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 481 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_ROTOM_CATALOG, 1
# 482 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_GRACIDEA, 1
# 483 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_REVEAL_GLASS, 1
# 484 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_DNA_SPLICERS, 1
# 485 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_ZYGARDE_CUBE, 1
# 486 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_PRISON_BOTTLE, 1
# 487 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_N_SOLARIZER, 1
# 488 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_N_LUNARIZER, 1
# 489 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_REINS_OF_UNITY, 1
# 490 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 491 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 492 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 493 "data/maps/Black_Market/scripts.pory"
    message gText_Hereiseverythings
# 494 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_ROTOM_CATALOG
# 495 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_GRACIDEA
# 496 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_REVEAL_GLASS
# 497 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_DNA_SPLICERS
# 498 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_ZYGARDE_CUBE
# 499 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_PRISON_BOTTLE
# 500 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_N_LUNARIZER
# 501 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_N_SOLARIZER
# 502 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_REINS_OF_UNITY
# 503 "data/maps/Black_Market/scripts.pory"
    release
# 504 "data/maps/Black_Market/scripts.pory"
    end
# 505 "data/maps/Black_Market/scripts.pory"

# 506 "data/maps/Black_Market/scripts.pory"
    gText_Panicingtext::
# 507 "data/maps/Black_Market/scripts.pory"
    .string "I have very hot gifts for you!\p $"
# 508 "data/maps/Black_Market/scripts.pory"

# 509 "data/maps/Black_Market/scripts.pory"
    gText_Hereiseverythings::
# 510 "data/maps/Black_Market/scripts.pory"
    .string "Hope you can keep the heat off..\p $"

Black_Market_EventScript_Sign_Text_0:
# 6 "data/maps/Black_Market/scripts.pory"
	.string "EMPLOYEES ONLY!!!!\p"
	.string "KEEP OUT WE MEAN IT!!!!\p"
	.string "$"
