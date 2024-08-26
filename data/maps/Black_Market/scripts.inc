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
Script_Black_Market_BERRY_BOY::
# 35 "data/maps/Black_Market/scripts.pory"
    lock
# 36 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 37 "data/maps/Black_Market/scripts.pory"
    message Text_BMBERRYBOY
# 38 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 39 "data/maps/Black_Market/scripts.pory"
    pokemart BM_BERRIES_ITEMS
# 40 "data/maps/Black_Market/scripts.pory"
    msgbox Text_BMBERRYEND
# 41 "data/maps/Black_Market/scripts.pory"
    release
# 42 "data/maps/Black_Market/scripts.pory"
    end
# 43 "data/maps/Black_Market/scripts.pory"

# 44 "data/maps/Black_Market/scripts.pory"
.align 2
# 45 "data/maps/Black_Market/scripts.pory"
BM_SHARD_ITEMS:
# 46 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RED_SHARD
# 47 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BLUE_SHARD
# 48 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_YELLOW_SHARD
# 49 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GREEN_SHARD
# 50 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STRAWBERRY_SWEET
# 51 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LOVE_SWEET
# 52 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BERRY_SWEET
# 53 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CLOVER_SWEET
# 54 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FLOWER_SWEET
# 55 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STAR_SWEET
# 56 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RIBBON_SWEET
# 57 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RED_NECTAR
# 58 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_YELLOW_NECTAR
# 59 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PINK_NECTAR
# 60 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PURPLE_NECTAR
# 61 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DYNAMAX_CANDY
# 62 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LIGHT_BALL
# 63 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LEEK
# 64 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_THICK_CLUB
# 65 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUCKY_PUNCH
# 66 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_METAL_POWDER
# 67 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_QUICK_POWDER
# 68 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BRIGHT_POWDER
# 69 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ADAMANT_ORB
# 70 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUSTROUS_ORB
# 71 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GRISEOUS_ORB
# 72 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROCKY_HELMET
# 73 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_AIR_BALLOON
# 74 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WEAKNESS_POLICY
# 75 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BLUNDER_POLICY
# 76 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EXPERT_BELT
# 77 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WISE_GLASSES
# 78 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MUSCLE_BAND
# 79 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SHELL_BELL
# 80 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WIDE_LENS
# 81 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ZOOM_LENS
# 82 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SCOPE_LENS
# 83 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_QUICK_CLAW
# 84 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ASSAULT_VEST
# 85 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SAFETY_GOGGLES
# 86 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TERRAIN_EXTENDER
# 87 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PROTECTIVE_PADS
# 88 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_THROAT_SPRAY
# 89 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEAVY_DUTY_BOOTS
# 90 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROOM_SERVICE
# 91 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_METRONOME
# 92 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_UTILITY_UMBRELLA
# 93 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_COVERT_CLOAK
# 94 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LOADED_DICE
# 95 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RING_TARGET
# 96 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RED_CARD
# 97 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MIRROR_HERB
# 98 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BINDING_BAND
# 99 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ADAMANT_CRYSTAL
# 100 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GRISEOUS_CORE
# 101 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUSTROUS_GLOBE
# 102 "data/maps/Black_Market/scripts.pory"

# 103 "data/maps/Black_Market/scripts.pory"

# 104 "data/maps/Black_Market/scripts.pory"

# 105 "data/maps/Black_Market/scripts.pory"

# 106 "data/maps/Black_Market/scripts.pory"
.align 2
# 107 "data/maps/Black_Market/scripts.pory"
BM_BALL_ITEMS:
# 108 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MASTER_BALL
# 109 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SAFARI_BALL
# 110 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHERISH_BALL
# 111 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUXURY_BALL
# 112 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ABILITY_CAPSULE
# 113 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ABILITY_PATCH
# 114 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LURE
# 115 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SUPER_LURE
# 116 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAX_LURE
# 117 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PP_MAX
# 118 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAX_ELIXIR
# 119 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BERRY_JUICE
# 120 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEART_SCALE
# 121 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EVERSTONE
# 122 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DOUSE_DRIVE
# 123 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SHOCK_DRIVE
# 124 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BURN_DRIVE
# 125 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHILL_DRIVE
# 126 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WELLSPRING_MASK
# 127 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CORNERSTONE_MASK
# 128 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEARTHFLAME_MASK
# 129 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_BAND
# 130 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_SPECS
# 131 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_SCARF
# 132 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STICKY_BARB
# 133 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LEFTOVERS
# 134 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_KINGS_ROCK
# 135 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CLEANSE_TAG
# 136 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SOOTHE_BELL
# 137 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FLAME_ORB
# 138 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TOXIC_ORB
# 139 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LIFE_ORB
# 140 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SMOKE_BALL
# 141 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DAMP_ROCK
# 142 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEAT_ROCK
# 143 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SMOOTH_ROCK
# 144 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BLACK_SLUDGE
# 145 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CLEAR_AMULET
# 146 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GRIP_CLAW
# 147 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PUNCHING_GLOVE
# 148 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EXP_SHARE
# 149 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_AMULET_COIN
# 150 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MACHO_BRACE
# 151 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUCKY_EGG
# 152 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DESTINY_KNOT
# 153 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FOCUS_BAND
# 154 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FOCUS_SASH
# 155 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EVIOLITE
# 156 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BERSERK_GENE
# 157 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BOOSTER_ENERGY
# 158 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NONE
# 159 "data/maps/Black_Market/scripts.pory"
    release
# 160 "data/maps/Black_Market/scripts.pory"
    end
# 161 "data/maps/Black_Market/scripts.pory"

# 162 "data/maps/Black_Market/scripts.pory"
.align 2
# 163 "data/maps/Black_Market/scripts.pory"
BM_BERRIES_ITEMS:
# 164 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHERI_BERRY
# 165 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHESTO_BERRY
# 166 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PECHA_BERRY
# 167 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RAWST_BERRY
# 168 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ASPEAR_BERRY
# 169 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LEPPA_BERRY
# 170 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ORAN_BERRY
# 171 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PERSIM_BERRY
# 172 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUM_BERRY
# 173 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SITRUS_BERRY
# 174 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FIGY_BERRY
# 175 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WIKI_BERRY
# 176 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAGO_BERRY
# 177 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_AGUAV_BERRY
# 178 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_IAPAPA_BERRY
# 179 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RAZZ_BERRY
# 180 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BLUK_BERRY
# 181 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NANAB_BERRY
# 182 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WEPEAR_BERRY
# 183 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PINAP_BERRY
# 184 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_POMEG_BERRY
# 185 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_KELPSY_BERRY
# 186 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_QUALOT_BERRY
# 187 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HONDEW_BERRY
# 188 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GREPA_BERRY
# 189 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TAMATO_BERRY
# 190 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CORNN_BERRY
# 191 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAGOST_BERRY
# 192 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RABUTA_BERRY
# 193 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NOMEL_BERRY
# 194 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SPELON_BERRY
# 195 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PAMTRE_BERRY
# 196 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WATMEL_BERRY
# 197 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DURIN_BERRY
# 198 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BELUE_BERRY
# 199 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHILAN_BERRY
# 200 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_OCCA_BERRY
# 201 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PASSHO_BERRY
# 202 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WACAN_BERRY
# 203 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RINDO_BERRY
# 204 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_YACHE_BERRY
# 205 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOPLE_BERRY
# 206 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_KEBIA_BERRY
# 207 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SHUCA_BERRY
# 208 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_COBA_BERRY
# 209 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PAYAPA_BERRY
# 210 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TANGA_BERRY
# 211 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHARTI_BERRY
# 212 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_KASIB_BERRY
# 213 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HABAN_BERRY
# 214 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_COLBUR_BERRY
# 215 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BABIRI_BERRY
# 216 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROSELI_BERRY
# 217 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LIECHI_BERRY
# 218 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GANLON_BERRY
# 219 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SALAC_BERRY
# 220 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PETAYA_BERRY
# 221 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_APICOT_BERRY
# 222 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LANSAT_BERRY
# 223 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STARF_BERRY
# 224 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ENIGMA_BERRY
# 225 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MICLE_BERRY
# 226 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CUSTAP_BERRY
# 227 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_JABOCA_BERRY
# 228 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROWAP_BERRY
# 229 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_KEE_BERRY
# 230 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MARANGA_BERRY
# 231 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ENIGMA_BERRY_E_READER
# 232 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NONE
# 233 "data/maps/Black_Market/scripts.pory"
    release
# 234 "data/maps/Black_Market/scripts.pory"
    end
# 235 "data/maps/Black_Market/scripts.pory"

# 236 "data/maps/Black_Market/scripts.pory"
Text_BMBALL:
# 237 "data/maps/Black_Market/scripts.pory"
    .string "I got some nice stuff from a Warehouse.\p"
# 238 "data/maps/Black_Market/scripts.pory"
    .string "How can I help you?$"
# 239 "data/maps/Black_Market/scripts.pory"

# 240 "data/maps/Black_Market/scripts.pory"
Text_BMSHARD:
# 241 "data/maps/Black_Market/scripts.pory"
    .string "I got some nice stuff from a Ship.\p"
# 242 "data/maps/Black_Market/scripts.pory"
    .string "How can I help you?$"
# 243 "data/maps/Black_Market/scripts.pory"

# 244 "data/maps/Black_Market/scripts.pory"
Text_BMSHARDEND:
# 245 "data/maps/Black_Market/scripts.pory"
    .string "Please come again!$"
# 246 "data/maps/Black_Market/scripts.pory"

# 247 "data/maps/Black_Market/scripts.pory"
Text_BMBALLEND:
# 248 "data/maps/Black_Market/scripts.pory"
    .string "Please come again!$"
# 249 "data/maps/Black_Market/scripts.pory"

# 250 "data/maps/Black_Market/scripts.pory"
Text_BMBERRYBOY:
# 251 "data/maps/Black_Market/scripts.pory"
    .string "I am the Berry Masters Son. \p"
# 252 "data/maps/Black_Market/scripts.pory"
    .string "Please don't tell my dad. \p"
# 253 "data/maps/Black_Market/scripts.pory"
    .string "How can I help you?$"
# 254 "data/maps/Black_Market/scripts.pory"

# 255 "data/maps/Black_Market/scripts.pory"
Text_BMBERRYEND:
# 256 "data/maps/Black_Market/scripts.pory"
    .string "Please come again!$"
# 257 "data/maps/Black_Market/scripts.pory"

# 258 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_EggWoman::
# 259 "data/maps/Black_Market/scripts.pory"
    lock
# 260 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 261 "data/maps/Black_Market/scripts.pory"
    showmoneybox 0, 0
# 262 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_EggsJust5000, MSGBOX_YESNO
# 263 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, GatchaBegg_EventScript_DeclineEgg
# 264 "data/maps/Black_Market/scripts.pory"
    checkmoney 5000
# 265 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, FALSE, GatchaBegg_EventScript_NotEnoughMoney
# 266 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_ThankYouDear, MSGBOX_DEFAULT
# 267 "data/maps/Black_Market/scripts.pory"
    getpartysize
# 268 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, PARTY_SIZE, GatchaBegg_EventScript_NoRoomForEgg
# 269 "data/maps/Black_Market/scripts.pory"
    removemoney 5000
# 270 "data/maps/Black_Market/scripts.pory"
    updatemoneybox
# 271 "data/maps/Black_Market/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 272 "data/maps/Black_Market/scripts.pory"
    message GatchaBegg_Text_ReceivedTheEgg
# 273 "data/maps/Black_Market/scripts.pory"
    waitfanfare
# 274 "data/maps/Black_Market/scripts.pory"
    specialvar VAR_RESULT, ChooseRandomEggSpeciesIII
# 275 "data/maps/Black_Market/scripts.pory"
    giveegg VAR_RESULT
# 276 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 277 "data/maps/Black_Market/scripts.pory"
    release
# 278 "data/maps/Black_Market/scripts.pory"
    end
# 279 "data/maps/Black_Market/scripts.pory"

# 280 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_EggsJust5000:
# 281 "data/maps/Black_Market/scripts.pory"
    .string "Pokémon eggs that were locally taken.\n"
# 282 "data/maps/Black_Market/scripts.pory"
    .string "These ones were hand picked.\p"
# 283 "data/maps/Black_Market/scripts.pory"
    .string "Buy a hot one. It's just ¥5000.$"
# 284 "data/maps/Black_Market/scripts.pory"

# 285 "data/maps/Black_Market/scripts.pory"

# 286 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_DeclineEgg::
# 287 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_OhFineThen, MSGBOX_DEFAULT
# 288 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 289 "data/maps/Black_Market/scripts.pory"
    release
# 290 "data/maps/Black_Market/scripts.pory"
    end
# 291 "data/maps/Black_Market/scripts.pory"

# 292 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_OhFineThen:
# 293 "data/maps/Black_Market/scripts.pory"
    .string "Oh, fine then. Scram!$"
# 294 "data/maps/Black_Market/scripts.pory"

# 295 "data/maps/Black_Market/scripts.pory"

# 296 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_NotEnoughMoney::
# 297 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 298 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 299 "data/maps/Black_Market/scripts.pory"
    release
# 300 "data/maps/Black_Market/scripts.pory"
    end
# 301 "data/maps/Black_Market/scripts.pory"

# 302 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_YouveNotGotTheMoney:
# 303 "data/maps/Black_Market/scripts.pory"
    .string "You know… You can't buy a thing if\n"
# 304 "data/maps/Black_Market/scripts.pory"
    .string "you've not got the money!$"
# 305 "data/maps/Black_Market/scripts.pory"

# 306 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_ThankYouDear:
# 307 "data/maps/Black_Market/scripts.pory"
    .string "Thank you, dearie! Come Again!$"
# 308 "data/maps/Black_Market/scripts.pory"

# 309 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_NoRoomForEgg::
# 310 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 311 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 312 "data/maps/Black_Market/scripts.pory"
    release
# 313 "data/maps/Black_Market/scripts.pory"
    end
# 314 "data/maps/Black_Market/scripts.pory"

# 315 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_NoRoomForThisEgg:
# 316 "data/maps/Black_Market/scripts.pory"
    .string "Oh? You've too many POKéMON.\n"
# 317 "data/maps/Black_Market/scripts.pory"
    .string "There's no room for this EGG…$"
# 318 "data/maps/Black_Market/scripts.pory"

# 319 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_ReceivedTheEgg:
# 320 "data/maps/Black_Market/scripts.pory"
    .string "{PLAYER} received the EGG.$"
# 321 "data/maps/Black_Market/scripts.pory"

# 322 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_CandyMan::
# 323 "data/maps/Black_Market/scripts.pory"
    lock
# 324 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 325 "data/maps/Black_Market/scripts.pory"
    showmoneybox 0, 0
# 326 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_CandyJust5000, MSGBOX_YESNO
# 327 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, BlackMarket_EventScript_DeclineCandy
# 328 "data/maps/Black_Market/scripts.pory"
    checkmoney 5000
# 329 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, FALSE, BlackMarket_EventScript_NotEnoughMonies
# 330 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_ThankYouDear, MSGBOX_DEFAULT
# 331 "data/maps/Black_Market/scripts.pory"
    checkitemspace ITEM_RARE_CANDY
# 332 "data/maps/Black_Market/scripts.pory"
    call_if_eq VAR_RESULT, TRUE, BlackMarket_EventScript_RemoveMonies
# 333 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_RARE_CANDY
# 334 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, FALSE, BlackMarket_EventScript_BagIsFull
# 335 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 336 "data/maps/Black_Market/scripts.pory"
    release
# 337 "data/maps/Black_Market/scripts.pory"
    end
# 338 "data/maps/Black_Market/scripts.pory"

# 339 "data/maps/Black_Market/scripts.pory"

# 340 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_BagIsFull::
# 341 "data/maps/Black_Market/scripts.pory"
    msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 342 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 343 "data/maps/Black_Market/scripts.pory"
    release
# 344 "data/maps/Black_Market/scripts.pory"
    end
# 345 "data/maps/Black_Market/scripts.pory"

# 346 "data/maps/Black_Market/scripts.pory"

# 347 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_RemoveMonies::
# 348 "data/maps/Black_Market/scripts.pory"
    removemoney 5000
# 349 "data/maps/Black_Market/scripts.pory"
    updatemoneybox
# 350 "data/maps/Black_Market/scripts.pory"
    return
# 351 "data/maps/Black_Market/scripts.pory"

# 352 "data/maps/Black_Market/scripts.pory"

# 353 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_DeclineCandy::
# 354 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_OhFineThen, MSGBOX_DEFAULT
# 355 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 356 "data/maps/Black_Market/scripts.pory"
    release
# 357 "data/maps/Black_Market/scripts.pory"
    end
# 358 "data/maps/Black_Market/scripts.pory"

# 359 "data/maps/Black_Market/scripts.pory"

# 360 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_NotEnoughMonies::
# 361 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_YouveNotGotTheMonies, MSGBOX_DEFAULT
# 362 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 363 "data/maps/Black_Market/scripts.pory"
    release
# 364 "data/maps/Black_Market/scripts.pory"
    end
# 365 "data/maps/Black_Market/scripts.pory"

# 366 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_CandyJust5000:
# 367 "data/maps/Black_Market/scripts.pory"
    .string "Want some Candy? It is a\n"
# 368 "data/maps/Black_Market/scripts.pory"
    .string "local specialty.\p"
# 369 "data/maps/Black_Market/scripts.pory"
    .string "Try one. It's just ¥5000.$"
# 370 "data/maps/Black_Market/scripts.pory"

# 371 "data/maps/Black_Market/scripts.pory"

# 372 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_ThankYouDear:
# 373 "data/maps/Black_Market/scripts.pory"
    .string "Thank you, dearie!$"
# 374 "data/maps/Black_Market/scripts.pory"

# 375 "data/maps/Black_Market/scripts.pory"

# 376 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_YouveNotGotTheMonies:
# 377 "data/maps/Black_Market/scripts.pory"
    .string "You know… You can't buy a thing if\n"
# 378 "data/maps/Black_Market/scripts.pory"
    .string "you've not got the money!$"
# 379 "data/maps/Black_Market/scripts.pory"

# 380 "data/maps/Black_Market/scripts.pory"

# 381 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_OhFineThen:
# 382 "data/maps/Black_Market/scripts.pory"
    .string "Oh, fine then. Scram!$"
# 383 "data/maps/Black_Market/scripts.pory"

# 384 "data/maps/Black_Market/scripts.pory"
EventScript_SHINYCHARMGift::
# 385 "data/maps/Black_Market/scripts.pory"
    lock
# 386 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 387 "data/maps/Black_Market/scripts.pory"
    message gText_Charmtext
# 388 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 389 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_SHINY_CHARM, 1
# 390 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 391 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 392 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 393 "data/maps/Black_Market/scripts.pory"
    message gText_Hereischarm
# 394 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_SHINY_CHARM
# 395 "data/maps/Black_Market/scripts.pory"
    release
# 396 "data/maps/Black_Market/scripts.pory"
    end
# 397 "data/maps/Black_Market/scripts.pory"

# 398 "data/maps/Black_Market/scripts.pory"

# 399 "data/maps/Black_Market/scripts.pory"
Script_havecharm::
# 400 "data/maps/Black_Market/scripts.pory"
    msgbox gText_havecharm
# 401 "data/maps/Black_Market/scripts.pory"
    release
# 402 "data/maps/Black_Market/scripts.pory"
    end
# 403 "data/maps/Black_Market/scripts.pory"

# 404 "data/maps/Black_Market/scripts.pory"

# 405 "data/maps/Black_Market/scripts.pory"
gText_Charmtext::
# 406 "data/maps/Black_Market/scripts.pory"
    .string "Hey I have a gift from Team Aqua!\p $"
# 407 "data/maps/Black_Market/scripts.pory"

# 408 "data/maps/Black_Market/scripts.pory"

# 409 "data/maps/Black_Market/scripts.pory"
gText_havecharm::
# 410 "data/maps/Black_Market/scripts.pory"
    .string "Have I threatened you before?$"
# 411 "data/maps/Black_Market/scripts.pory"

# 412 "data/maps/Black_Market/scripts.pory"

# 413 "data/maps/Black_Market/scripts.pory"
gText_Hereischarm::
# 414 "data/maps/Black_Market/scripts.pory"
    .string "Here! You better join our team!$"
# 415 "data/maps/Black_Market/scripts.pory"

# 416 "data/maps/Black_Market/scripts.pory"
EventScript_EXPCHARMGift::
# 417 "data/maps/Black_Market/scripts.pory"
    lock
# 418 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 419 "data/maps/Black_Market/scripts.pory"
    message gText_CharmEtext
# 420 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 421 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_EXP_CHARM, 1
# 422 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 423 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 424 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 425 "data/maps/Black_Market/scripts.pory"
    message gText_Hereischarm
# 426 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_EXP_CHARM
# 427 "data/maps/Black_Market/scripts.pory"
    release
# 428 "data/maps/Black_Market/scripts.pory"
    end
# 429 "data/maps/Black_Market/scripts.pory"

# 430 "data/maps/Black_Market/scripts.pory"
    gText_CharmEtext::
# 431 "data/maps/Black_Market/scripts.pory"
    .string "Hey I have a gift from Team Magma!\p $"
# 432 "data/maps/Black_Market/scripts.pory"

# 433 "data/maps/Black_Market/scripts.pory"
EventScript_EGGCHARMGift::
# 434 "data/maps/Black_Market/scripts.pory"
    lock
# 435 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 436 "data/maps/Black_Market/scripts.pory"
    message gText_CharmEggtext
# 437 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 438 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_OVAL_CHARM, 1
# 439 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 440 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 441 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 442 "data/maps/Black_Market/scripts.pory"
    message gText_HereisEggcharm
# 443 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_OVAL_CHARM
# 444 "data/maps/Black_Market/scripts.pory"
    release
# 445 "data/maps/Black_Market/scripts.pory"
    end
# 446 "data/maps/Black_Market/scripts.pory"

# 447 "data/maps/Black_Market/scripts.pory"
    gText_CharmEggtext::
# 448 "data/maps/Black_Market/scripts.pory"
    .string "Do I have an amazing gift for you!\p $"
# 449 "data/maps/Black_Market/scripts.pory"

# 450 "data/maps/Black_Market/scripts.pory"
    gText_HereisEggcharm::
# 451 "data/maps/Black_Market/scripts.pory"
    .string "Hope you use this charm wisely....\p $"
# 452 "data/maps/Black_Market/scripts.pory"

# 453 "data/maps/Black_Market/scripts.pory"
EventScript_CATCHCHARMGift::
# 454 "data/maps/Black_Market/scripts.pory"
    lock
# 455 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 456 "data/maps/Black_Market/scripts.pory"
    message gText_CharmCatchtext
# 457 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 458 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_CATCHING_CHARM, 1
# 459 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 460 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 461 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 462 "data/maps/Black_Market/scripts.pory"
    message gText_HereisCatchcharm
# 463 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_CATCHING_CHARM
# 464 "data/maps/Black_Market/scripts.pory"
    release
# 465 "data/maps/Black_Market/scripts.pory"
    end
# 466 "data/maps/Black_Market/scripts.pory"

# 467 "data/maps/Black_Market/scripts.pory"
    gText_CharmCatchtext::
# 468 "data/maps/Black_Market/scripts.pory"
    .string "Do I have an amazing gift for you!\p $"
# 469 "data/maps/Black_Market/scripts.pory"

# 470 "data/maps/Black_Market/scripts.pory"
    gText_HereisCatchcharm::
# 471 "data/maps/Black_Market/scripts.pory"
    .string "Hope you use this charm a lot....\p $"
# 472 "data/maps/Black_Market/scripts.pory"

# 473 "data/maps/Black_Market/scripts.pory"
EventScript_DBANDGift::
# 474 "data/maps/Black_Market/scripts.pory"
    lock
# 475 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 476 "data/maps/Black_Market/scripts.pory"
    message gText_DBANDtext
# 477 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 478 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_DYNAMAX_BAND, 1
# 479 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 480 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 481 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 482 "data/maps/Black_Market/scripts.pory"
    message gText_DBANDcharm
# 483 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_DYNAMAX_BAND
# 484 "data/maps/Black_Market/scripts.pory"
    setflag FLAG_DYNAMAX_BATTLE
# 485 "data/maps/Black_Market/scripts.pory"
    release
# 486 "data/maps/Black_Market/scripts.pory"
    end
# 487 "data/maps/Black_Market/scripts.pory"

# 488 "data/maps/Black_Market/scripts.pory"
gText_DBANDtext::
# 489 "data/maps/Black_Market/scripts.pory"
    .string "First timers get a free gift!\p $"
# 490 "data/maps/Black_Market/scripts.pory"

# 491 "data/maps/Black_Market/scripts.pory"
    gText_DBANDcharm::
# 492 "data/maps/Black_Market/scripts.pory"
    .string "Hope you use this band wisely....\p $"
# 493 "data/maps/Black_Market/scripts.pory"

# 494 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceiveMarshadow::
# 495 "data/maps/Black_Market/scripts.pory"
    lock
# 496 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 497 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
# 498 "data/maps/Black_Market/scripts.pory"
    setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MARSHADOW
# 499 "data/maps/Black_Market/scripts.pory"
    givemon SPECIES_MARSHADOW, 20, item=ITEM_MARSHADIUM_Z, ball=ITEM_DUSK_BALL, nature=NATURE_JOLLY; 
# 500 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BlackMarket_EventScript_ReceiveMarshadowParty
# 501 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BlackMarket_EventScript_ReceiveMarshadowPC
# 502 "data/maps/Black_Market/scripts.pory"
    goto Common_EventScript_NoMoreRoomForPokemon
# 503 "data/maps/Black_Market/scripts.pory"
    end
# 504 "data/maps/Black_Market/scripts.pory"

# 505 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceiveMarshadowParty::
# 506 "data/maps/Black_Market/scripts.pory"
    call BlackMarket_EventScript_ReceivedMarshadowFanfare
# 507 "data/maps/Black_Market/scripts.pory"
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 508 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, BlackMarket_EventScript_ExplainMarshadow
# 509 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_GetGiftMonPartySlot
# 510 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_NameReceivedPartyMon
# 511 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_ExplainMarshadow
# 512 "data/maps/Black_Market/scripts.pory"
    end
# 513 "data/maps/Black_Market/scripts.pory"

# 514 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceiveMarshadowPC::
# 515 "data/maps/Black_Market/scripts.pory"
    call BlackMarket_EventScript_ReceivedMarshadowFanfare
# 516 "data/maps/Black_Market/scripts.pory"
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 517 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, BlackMarket_EventScript_SendMarshadowToPC
# 518 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_NameReceivedBoxMon
# 519 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_SendMarshadowToPC
# 520 "data/maps/Black_Market/scripts.pory"
    end
# 521 "data/maps/Black_Market/scripts.pory"

# 522 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_SendMarshadowToPC::
# 523 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_TransferredToPC
# 524 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_ExplainMarshadow
# 525 "data/maps/Black_Market/scripts.pory"
    end
# 526 "data/maps/Black_Market/scripts.pory"

# 527 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceivedMarshadowFanfare::
# 528 "data/maps/Black_Market/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 529 "data/maps/Black_Market/scripts.pory"
    message BlackMarket_Text_PlayerReceivedMarshadow
# 530 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 531 "data/maps/Black_Market/scripts.pory"
    waitfanfare
# 532 "data/maps/Black_Market/scripts.pory"
    bufferspeciesname STR_VAR_1, SPECIES_MARSHADOW
# 533 "data/maps/Black_Market/scripts.pory"
    return
# 534 "data/maps/Black_Market/scripts.pory"

# 535 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ExplainMarshadow::
# 536 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_PokemonChanges, MSGBOX_DEFAULT
# 537 "data/maps/Black_Market/scripts.pory"
    setflag FLAG_RECEIVED_MARSHADOW
# 538 "data/maps/Black_Market/scripts.pory"
    release
# 539 "data/maps/Black_Market/scripts.pory"
    end
# 540 "data/maps/Black_Market/scripts.pory"

# 541 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_HaveMarshadow::
# 542 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_PokemonChanges, MSGBOX_DEFAULT
# 543 "data/maps/Black_Market/scripts.pory"
    release
# 544 "data/maps/Black_Market/scripts.pory"
    end
# 545 "data/maps/Black_Market/scripts.pory"

# 546 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_HEXMANIAC::
# 547 "data/maps/Black_Market/scripts.pory"
    lock
# 548 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 549 "data/maps/Black_Market/scripts.pory"
    goto_if_set FLAG_RECEIVED_MARSHADOW, BlackMarket_EventScript_HaveMarshadow
# 550 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_ReceiveMarshadow
# 551 "data/maps/Black_Market/scripts.pory"
    end
# 552 "data/maps/Black_Market/scripts.pory"

# 553 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_PlayerReceivedMarshadow:
# 554 "data/maps/Black_Market/scripts.pory"
    .string "{PLAYER} received MARSHADOW!$"
# 555 "data/maps/Black_Market/scripts.pory"

# 556 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_ThanksPleaseTakePokemon:
# 557 "data/maps/Black_Market/scripts.pory"
    .string "Thanks for not snitching!\n"
# 558 "data/maps/Black_Market/scripts.pory"
    .string "Thanks to you, we're safe!\p"
# 559 "data/maps/Black_Market/scripts.pory"
    .string "It might be an odd way of welcoming you,\n"
# 560 "data/maps/Black_Market/scripts.pory"
    .string "but take this POKéMON.$"
# 561 "data/maps/Black_Market/scripts.pory"

# 562 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_PokemonChanges:
# 563 "data/maps/Black_Market/scripts.pory"
    .string "That POKéMON hides according\n"
# 564 "data/maps/Black_Market/scripts.pory"
    .string "to the area conditions.\p"
# 565 "data/maps/Black_Market/scripts.pory"
    .string "There're plenty of them in the…\n"
# 566 "data/maps/Black_Market/scripts.pory"
    .string "nevermind--go ahead and take it.$"
# 567 "data/maps/Black_Market/scripts.pory"

# 568 "data/maps/Black_Market/scripts.pory"
EventScript_PanicingGuyGift::
# 569 "data/maps/Black_Market/scripts.pory"
    lock
# 570 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 571 "data/maps/Black_Market/scripts.pory"
    message gText_Panicingtext
# 572 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 573 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_ROTOM_CATALOG, 1
# 574 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_GRACIDEA, 1
# 575 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_REVEAL_GLASS, 1
# 576 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_DNA_SPLICERS, 1
# 577 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_ZYGARDE_CUBE, 1
# 578 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_PRISON_BOTTLE, 1
# 579 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_N_SOLARIZER, 1
# 580 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_N_LUNARIZER, 1
# 581 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_REINS_OF_UNITY, 1
# 582 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_TERA_ORB, 1
# 583 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 584 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 585 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 586 "data/maps/Black_Market/scripts.pory"
    message gText_Hereiseverythings
# 587 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_ROTOM_CATALOG
# 588 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_GRACIDEA
# 589 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_REVEAL_GLASS
# 590 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_DNA_SPLICERS
# 591 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_ZYGARDE_CUBE
# 592 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_PRISON_BOTTLE
# 593 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_N_LUNARIZER
# 594 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_N_SOLARIZER
# 595 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_REINS_OF_UNITY
# 596 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_TERA_ORB
# 597 "data/maps/Black_Market/scripts.pory"
    release
# 598 "data/maps/Black_Market/scripts.pory"
    end
# 599 "data/maps/Black_Market/scripts.pory"

# 600 "data/maps/Black_Market/scripts.pory"
    gText_Panicingtext::
# 601 "data/maps/Black_Market/scripts.pory"
    .string "I have very hot gifts for you!\p $"
# 602 "data/maps/Black_Market/scripts.pory"

# 603 "data/maps/Black_Market/scripts.pory"
    gText_Hereiseverythings::
# 604 "data/maps/Black_Market/scripts.pory"
    .string "Hope you can keep the heat off..\p $"

Black_Market_EventScript_Sign_Text_0:
# 6 "data/maps/Black_Market/scripts.pory"
	.string "EMPLOYEES ONLY!!!!\p"
	.string "KEEP OUT WE MEAN IT!!!!\p"
	.string "$"
