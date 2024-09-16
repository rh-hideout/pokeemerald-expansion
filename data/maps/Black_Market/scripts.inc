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
Script_Black_Market_PLATE_PERSON::
# 45 "data/maps/Black_Market/scripts.pory"
    lock
# 46 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 47 "data/maps/Black_Market/scripts.pory"
    message Text_BMPLATEP
# 48 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 49 "data/maps/Black_Market/scripts.pory"
    pokemart BM_PLATE_ITEMS
# 50 "data/maps/Black_Market/scripts.pory"
    msgbox Text_BMPLATEEND
# 51 "data/maps/Black_Market/scripts.pory"
    release
# 52 "data/maps/Black_Market/scripts.pory"
    end
# 53 "data/maps/Black_Market/scripts.pory"

# 54 "data/maps/Black_Market/scripts.pory"
.align 2
# 55 "data/maps/Black_Market/scripts.pory"
BM_SHARD_ITEMS:
# 56 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RED_SHARD
# 57 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BLUE_SHARD
# 58 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_YELLOW_SHARD
# 59 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GREEN_SHARD
# 60 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STRAWBERRY_SWEET
# 61 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LOVE_SWEET
# 62 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BERRY_SWEET
# 63 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CLOVER_SWEET
# 64 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FLOWER_SWEET
# 65 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STAR_SWEET
# 66 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RIBBON_SWEET
# 67 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RED_NECTAR
# 68 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_YELLOW_NECTAR
# 69 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PINK_NECTAR
# 70 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PURPLE_NECTAR
# 71 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DYNAMAX_CANDY
# 72 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LIGHT_BALL
# 73 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LEEK
# 74 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_THICK_CLUB
# 75 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUCKY_PUNCH
# 76 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_METAL_POWDER
# 77 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_QUICK_POWDER
# 78 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BRIGHT_POWDER
# 79 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ADAMANT_ORB
# 80 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUSTROUS_ORB
# 81 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GRISEOUS_ORB
# 82 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROCKY_HELMET
# 83 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_AIR_BALLOON
# 84 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WEAKNESS_POLICY
# 85 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BLUNDER_POLICY
# 86 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EXPERT_BELT
# 87 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WISE_GLASSES
# 88 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MUSCLE_BAND
# 89 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SHELL_BELL
# 90 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WIDE_LENS
# 91 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ZOOM_LENS
# 92 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SCOPE_LENS
# 93 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_QUICK_CLAW
# 94 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ASSAULT_VEST
# 95 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SAFETY_GOGGLES
# 96 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TERRAIN_EXTENDER
# 97 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PROTECTIVE_PADS
# 98 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_THROAT_SPRAY
# 99 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEAVY_DUTY_BOOTS
# 100 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROOM_SERVICE
# 101 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_METRONOME
# 102 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_UTILITY_UMBRELLA
# 103 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_COVERT_CLOAK
# 104 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LOADED_DICE
# 105 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RING_TARGET
# 106 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RED_CARD
# 107 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MIRROR_HERB
# 108 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BINDING_BAND
# 109 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ADAMANT_CRYSTAL
# 110 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GRISEOUS_CORE
# 111 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUSTROUS_GLOBE
# 112 "data/maps/Black_Market/scripts.pory"

# 113 "data/maps/Black_Market/scripts.pory"

# 114 "data/maps/Black_Market/scripts.pory"

# 115 "data/maps/Black_Market/scripts.pory"

# 116 "data/maps/Black_Market/scripts.pory"
.align 2
# 117 "data/maps/Black_Market/scripts.pory"
BM_BALL_ITEMS:
# 118 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MASTER_BALL
# 119 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SAFARI_BALL
# 120 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHERISH_BALL
# 121 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUXURY_BALL
# 122 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ABILITY_CAPSULE
# 123 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ABILITY_PATCH
# 124 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LURE
# 125 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SUPER_LURE
# 126 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAX_LURE
# 127 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PP_MAX
# 128 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAX_ELIXIR
# 129 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BERRY_JUICE
# 130 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEART_SCALE
# 131 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EVERSTONE
# 132 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DOUSE_DRIVE
# 133 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SHOCK_DRIVE
# 134 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BURN_DRIVE
# 135 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHILL_DRIVE
# 136 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WELLSPRING_MASK
# 137 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CORNERSTONE_MASK
# 138 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEARTHFLAME_MASK
# 139 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RUSTED_SWORD
# 140 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RUSTED_SHIELD
# 141 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_BAND
# 142 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_SPECS
# 143 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOICE_SCARF
# 144 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STICKY_BARB
# 145 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LEFTOVERS
# 146 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_KINGS_ROCK
# 147 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CLEANSE_TAG
# 148 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SOOTHE_BELL
# 149 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FLAME_ORB
# 150 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TOXIC_ORB
# 151 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LIFE_ORB
# 152 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SMOKE_BALL
# 153 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DAMP_ROCK
# 154 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HEAT_ROCK
# 155 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SMOOTH_ROCK
# 156 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BLACK_SLUDGE
# 157 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CLEAR_AMULET
# 158 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GRIP_CLAW
# 159 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PUNCHING_GLOVE
# 160 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EXP_SHARE
# 161 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_AMULET_COIN
# 162 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MACHO_BRACE
# 163 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUCKY_EGG
# 164 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DESTINY_KNOT
# 165 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FOCUS_BAND
# 166 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FOCUS_SASH
# 167 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EVIOLITE
# 168 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BERSERK_GENE
# 169 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BOOSTER_ENERGY
# 170 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NONE
# 171 "data/maps/Black_Market/scripts.pory"
    release
# 172 "data/maps/Black_Market/scripts.pory"
    end
# 173 "data/maps/Black_Market/scripts.pory"

# 174 "data/maps/Black_Market/scripts.pory"
.align 2
# 175 "data/maps/Black_Market/scripts.pory"
BM_BERRIES_ITEMS:
# 176 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHERI_BERRY
# 177 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHESTO_BERRY
# 178 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PECHA_BERRY
# 179 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RAWST_BERRY
# 180 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ASPEAR_BERRY
# 181 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LEPPA_BERRY
# 182 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ORAN_BERRY
# 183 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PERSIM_BERRY
# 184 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LUM_BERRY
# 185 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SITRUS_BERRY
# 186 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FIGY_BERRY
# 187 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WIKI_BERRY
# 188 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAGO_BERRY
# 189 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_AGUAV_BERRY
# 190 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_IAPAPA_BERRY
# 191 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RAZZ_BERRY
# 192 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BLUK_BERRY
# 193 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NANAB_BERRY
# 194 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WEPEAR_BERRY
# 195 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PINAP_BERRY
# 196 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_POMEG_BERRY
# 197 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_KELPSY_BERRY
# 198 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_QUALOT_BERRY
# 199 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HONDEW_BERRY
# 200 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GREPA_BERRY
# 201 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TAMATO_BERRY
# 202 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CORNN_BERRY
# 203 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MAGOST_BERRY
# 204 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RABUTA_BERRY
# 205 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NOMEL_BERRY
# 206 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SPELON_BERRY
# 207 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PAMTRE_BERRY
# 208 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WATMEL_BERRY
# 209 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DURIN_BERRY
# 210 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BELUE_BERRY
# 211 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHILAN_BERRY
# 212 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_OCCA_BERRY
# 213 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PASSHO_BERRY
# 214 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WACAN_BERRY
# 215 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_RINDO_BERRY
# 216 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_YACHE_BERRY
# 217 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHOPLE_BERRY
# 218 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_KEBIA_BERRY
# 219 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SHUCA_BERRY
# 220 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_COBA_BERRY
# 221 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PAYAPA_BERRY
# 222 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TANGA_BERRY
# 223 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHARTI_BERRY
# 224 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_KASIB_BERRY
# 225 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_HABAN_BERRY
# 226 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_COLBUR_BERRY
# 227 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BABIRI_BERRY
# 228 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROSELI_BERRY
# 229 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LIECHI_BERRY
# 230 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GANLON_BERRY
# 231 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SALAC_BERRY
# 232 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PETAYA_BERRY
# 233 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_APICOT_BERRY
# 234 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_LANSAT_BERRY
# 235 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STARF_BERRY
# 236 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ENIGMA_BERRY
# 237 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MICLE_BERRY
# 238 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CUSTAP_BERRY
# 239 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_JABOCA_BERRY
# 240 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROWAP_BERRY
# 241 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_KEE_BERRY
# 242 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MARANGA_BERRY
# 243 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ENIGMA_BERRY_E_READER
# 244 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NONE
# 245 "data/maps/Black_Market/scripts.pory"
    release
# 246 "data/maps/Black_Market/scripts.pory"
    end
# 247 "data/maps/Black_Market/scripts.pory"

# 248 "data/maps/Black_Market/scripts.pory"
.align 2
# 249 "data/maps/Black_Market/scripts.pory"
BM_PLATE_ITEMS:
# 250 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FLAME_PLATE
# 251 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SPLASH_PLATE
# 252 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ZAP_PLATE
# 253 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MEADOW_PLATE
# 254 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ICICLE_PLATE
# 255 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FIST_PLATE
# 256 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_TOXIC_PLATE
# 257 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_EARTH_PLATE
# 258 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SKY_PLATE
# 259 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_MIND_PLATE
# 260 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_INSECT_PLATE
# 261 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STONE_PLATE
# 262 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SPOOKY_PLATE
# 263 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DRACO_PLATE
# 264 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DREAD_PLATE
# 265 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_IRON_PLATE
# 266 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PIXIE_PLATE
# 267 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DOUSE_DRIVE
# 268 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_SHOCK_DRIVE
# 269 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BURN_DRIVE
# 270 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_CHILL_DRIVE
# 271 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FIRE_MEMORY
# 272 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WATER_MEMORY
# 273 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ELECTRIC_MEMORY
# 274 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GRASS_MEMORY
# 275 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ICE_MEMORY
# 276 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FIGHTING_MEMORY
# 277 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_POISON_MEMORY
# 278 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GROUND_MEMORY
# 279 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FLYING_MEMORY
# 280 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PSYCHIC_MEMORY
# 281 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BUG_MEMORY
# 282 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROCK_MEMORY
# 283 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GHOST_MEMORY
# 284 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DRAGON_MEMORY
# 285 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DARK_MEMORY
# 286 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STEEL_MEMORY
# 287 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FAIRY_MEMORY
# 288 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NORMAL_GEM
# 289 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FIRE_GEM
# 290 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_WATER_GEM
# 291 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ELECTRIC_GEM
# 292 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GRASS_GEM
# 293 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ICE_GEM
# 294 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FIGHTING_GEM
# 295 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_POISON_GEM
# 296 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GROUND_GEM
# 297 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FLYING_GEM
# 298 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_PSYCHIC_GEM
# 299 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_BUG_GEM
# 300 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_ROCK_GEM
# 301 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_GHOST_GEM
# 302 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DRAGON_GEM
# 303 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_DARK_GEM
# 304 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_STEEL_GEM
# 305 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_FAIRY_GEM
# 306 "data/maps/Black_Market/scripts.pory"
    .2byte ITEM_NONE
# 307 "data/maps/Black_Market/scripts.pory"
    release
# 308 "data/maps/Black_Market/scripts.pory"
    end
# 309 "data/maps/Black_Market/scripts.pory"

# 310 "data/maps/Black_Market/scripts.pory"
Text_BMBALL:
# 311 "data/maps/Black_Market/scripts.pory"
    .string "I got some nice stuff from a Warehouse.\p"
# 312 "data/maps/Black_Market/scripts.pory"
    .string "How can I help you?$"
# 313 "data/maps/Black_Market/scripts.pory"

# 314 "data/maps/Black_Market/scripts.pory"
Text_BMSHARD:
# 315 "data/maps/Black_Market/scripts.pory"
    .string "I got some nice stuff from a Ship.\p"
# 316 "data/maps/Black_Market/scripts.pory"
    .string "How can I help you?$"
# 317 "data/maps/Black_Market/scripts.pory"

# 318 "data/maps/Black_Market/scripts.pory"
Text_BMSHARDEND:
# 319 "data/maps/Black_Market/scripts.pory"
    .string "Please come again!$"
# 320 "data/maps/Black_Market/scripts.pory"

# 321 "data/maps/Black_Market/scripts.pory"
Text_BMBALLEND:
# 322 "data/maps/Black_Market/scripts.pory"
    .string "Please come again!$"
# 323 "data/maps/Black_Market/scripts.pory"

# 324 "data/maps/Black_Market/scripts.pory"
Text_BMBERRYBOY:
# 325 "data/maps/Black_Market/scripts.pory"
    .string "I am the Berry Masters Son. \p"
# 326 "data/maps/Black_Market/scripts.pory"
    .string "Please don't tell my dad. \p"
# 327 "data/maps/Black_Market/scripts.pory"
    .string "How can I help you?$"
# 328 "data/maps/Black_Market/scripts.pory"

# 329 "data/maps/Black_Market/scripts.pory"
Text_BMBERRYEND:
# 330 "data/maps/Black_Market/scripts.pory"
    .string "Please come again!$"
# 331 "data/maps/Black_Market/scripts.pory"

# 332 "data/maps/Black_Market/scripts.pory"
Text_BMPLATEP:
# 333 "data/maps/Black_Market/scripts.pory"
    .string "I got some museum quality stuff.\p"
# 334 "data/maps/Black_Market/scripts.pory"
    .string "How can I help you?$"
# 335 "data/maps/Black_Market/scripts.pory"

# 336 "data/maps/Black_Market/scripts.pory"
Text_BMPLATEEND:
# 337 "data/maps/Black_Market/scripts.pory"
    .string "Please come again!$"
# 338 "data/maps/Black_Market/scripts.pory"

# 339 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_EggWoman::
# 340 "data/maps/Black_Market/scripts.pory"
    lock
# 341 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 342 "data/maps/Black_Market/scripts.pory"
    showmoneybox 0, 0
# 343 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_EggsJust5000, MSGBOX_YESNO
# 344 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, GatchaBegg_EventScript_DeclineEgg
# 345 "data/maps/Black_Market/scripts.pory"
    checkmoney 5000
# 346 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, FALSE, GatchaBegg_EventScript_NotEnoughMoney
# 347 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_ThankYouDear, MSGBOX_DEFAULT
# 348 "data/maps/Black_Market/scripts.pory"
    getpartysize
# 349 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, PARTY_SIZE, GatchaBegg_EventScript_NoRoomForEgg
# 350 "data/maps/Black_Market/scripts.pory"
    removemoney 5000
# 351 "data/maps/Black_Market/scripts.pory"
    updatemoneybox
# 352 "data/maps/Black_Market/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 353 "data/maps/Black_Market/scripts.pory"
    message GatchaBegg_Text_ReceivedTheEgg
# 354 "data/maps/Black_Market/scripts.pory"
    waitfanfare
# 355 "data/maps/Black_Market/scripts.pory"
    specialvar VAR_RESULT, ChooseRandomEggSpeciesIII
# 356 "data/maps/Black_Market/scripts.pory"
    giveegg VAR_RESULT
# 357 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 358 "data/maps/Black_Market/scripts.pory"
    release
# 359 "data/maps/Black_Market/scripts.pory"
    end
# 360 "data/maps/Black_Market/scripts.pory"

# 361 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_EggsJust5000:
# 362 "data/maps/Black_Market/scripts.pory"
    .string "Pokémon eggs that were locally taken.\n"
# 363 "data/maps/Black_Market/scripts.pory"
    .string "These ones were hand picked.\p"
# 364 "data/maps/Black_Market/scripts.pory"
    .string "Buy a hot one. It's just ¥5000.$"
# 365 "data/maps/Black_Market/scripts.pory"

# 366 "data/maps/Black_Market/scripts.pory"

# 367 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_DeclineEgg::
# 368 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_OhFineThen, MSGBOX_DEFAULT
# 369 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 370 "data/maps/Black_Market/scripts.pory"
    release
# 371 "data/maps/Black_Market/scripts.pory"
    end
# 372 "data/maps/Black_Market/scripts.pory"

# 373 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_OhFineThen:
# 374 "data/maps/Black_Market/scripts.pory"
    .string "Oh, fine then. Scram!$"
# 375 "data/maps/Black_Market/scripts.pory"

# 376 "data/maps/Black_Market/scripts.pory"

# 377 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_NotEnoughMoney::
# 378 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 379 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 380 "data/maps/Black_Market/scripts.pory"
    release
# 381 "data/maps/Black_Market/scripts.pory"
    end
# 382 "data/maps/Black_Market/scripts.pory"

# 383 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_YouveNotGotTheMoney:
# 384 "data/maps/Black_Market/scripts.pory"
    .string "You know… You can't buy a thing if\n"
# 385 "data/maps/Black_Market/scripts.pory"
    .string "you've not got the money!$"
# 386 "data/maps/Black_Market/scripts.pory"

# 387 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_ThankYouDear:
# 388 "data/maps/Black_Market/scripts.pory"
    .string "Thank you, dearie! Come Again!$"
# 389 "data/maps/Black_Market/scripts.pory"

# 390 "data/maps/Black_Market/scripts.pory"
GatchaBegg_EventScript_NoRoomForEgg::
# 391 "data/maps/Black_Market/scripts.pory"
    msgbox GatchaBegg_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 392 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 393 "data/maps/Black_Market/scripts.pory"
    release
# 394 "data/maps/Black_Market/scripts.pory"
    end
# 395 "data/maps/Black_Market/scripts.pory"

# 396 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_NoRoomForThisEgg:
# 397 "data/maps/Black_Market/scripts.pory"
    .string "Oh? You've too many POKéMON.\n"
# 398 "data/maps/Black_Market/scripts.pory"
    .string "There's no room for this EGG…$"
# 399 "data/maps/Black_Market/scripts.pory"

# 400 "data/maps/Black_Market/scripts.pory"
GatchaBegg_Text_ReceivedTheEgg:
# 401 "data/maps/Black_Market/scripts.pory"
    .string "{PLAYER} received the EGG.$"
# 402 "data/maps/Black_Market/scripts.pory"

# 403 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_CandyMan::
# 404 "data/maps/Black_Market/scripts.pory"
    lock
# 405 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 406 "data/maps/Black_Market/scripts.pory"
    showmoneybox 0, 0
# 407 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_CandyJust5000, MSGBOX_YESNO
# 408 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, BlackMarket_EventScript_DeclineCandy
# 409 "data/maps/Black_Market/scripts.pory"
    checkmoney 5000
# 410 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, FALSE, BlackMarket_EventScript_NotEnoughMonies
# 411 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_ThankYouDear, MSGBOX_DEFAULT
# 412 "data/maps/Black_Market/scripts.pory"
    checkitemspace ITEM_RARE_CANDY
# 413 "data/maps/Black_Market/scripts.pory"
    call_if_eq VAR_RESULT, TRUE, BlackMarket_EventScript_RemoveMonies
# 414 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_RARE_CANDY
# 415 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, FALSE, BlackMarket_EventScript_BagIsFull
# 416 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 417 "data/maps/Black_Market/scripts.pory"
    release
# 418 "data/maps/Black_Market/scripts.pory"
    end
# 419 "data/maps/Black_Market/scripts.pory"

# 420 "data/maps/Black_Market/scripts.pory"
EventScript_BirthIslandGift::
# 421 "data/maps/Black_Market/scripts.pory"
    lock
# 422 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 423 "data/maps/Black_Market/scripts.pory"
    message gText_BIRTHIStext
# 424 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 425 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_AURORA_TICKET, 1
# 426 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 427 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havebirthticket
# 428 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 429 "data/maps/Black_Market/scripts.pory"
    message gText_Hereisbirthticket
# 430 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_AURORA_TICKET
# 431 "data/maps/Black_Market/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 432 "data/maps/Black_Market/scripts.pory"
    setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 433 "data/maps/Black_Market/scripts.pory"
    release
# 434 "data/maps/Black_Market/scripts.pory"
    end
# 435 "data/maps/Black_Market/scripts.pory"

# 436 "data/maps/Black_Market/scripts.pory"
Script_havebirthticket::
# 437 "data/maps/Black_Market/scripts.pory"
    msgbox gText_havebirthticket
# 438 "data/maps/Black_Market/scripts.pory"
    release
# 439 "data/maps/Black_Market/scripts.pory"
    end
# 440 "data/maps/Black_Market/scripts.pory"

# 441 "data/maps/Black_Market/scripts.pory"
gText_BIRTHIStext::
# 442 "data/maps/Black_Market/scripts.pory"
    .string "Did you know there is aliens...\p $"
# 443 "data/maps/Black_Market/scripts.pory"

# 444 "data/maps/Black_Market/scripts.pory"
gText_havebirthticket::
# 445 "data/maps/Black_Market/scripts.pory"
    .string "Oh Wait! Did you find any?$"
# 446 "data/maps/Black_Market/scripts.pory"

# 447 "data/maps/Black_Market/scripts.pory"
gText_Hereisbirthticket::
# 448 "data/maps/Black_Market/scripts.pory"
    .string "Here you go! I hope you find some!$"
# 449 "data/maps/Black_Market/scripts.pory"

# 450 "data/maps/Black_Market/scripts.pory"

# 451 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_BagIsFull::
# 452 "data/maps/Black_Market/scripts.pory"
    msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 453 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 454 "data/maps/Black_Market/scripts.pory"
    release
# 455 "data/maps/Black_Market/scripts.pory"
    end
# 456 "data/maps/Black_Market/scripts.pory"

# 457 "data/maps/Black_Market/scripts.pory"

# 458 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_RemoveMonies::
# 459 "data/maps/Black_Market/scripts.pory"
    removemoney 5000
# 460 "data/maps/Black_Market/scripts.pory"
    updatemoneybox
# 461 "data/maps/Black_Market/scripts.pory"
    return
# 462 "data/maps/Black_Market/scripts.pory"

# 463 "data/maps/Black_Market/scripts.pory"

# 464 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_DeclineCandy::
# 465 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_OhFineThen, MSGBOX_DEFAULT
# 466 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 467 "data/maps/Black_Market/scripts.pory"
    release
# 468 "data/maps/Black_Market/scripts.pory"
    end
# 469 "data/maps/Black_Market/scripts.pory"

# 470 "data/maps/Black_Market/scripts.pory"

# 471 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_NotEnoughMonies::
# 472 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_YouveNotGotTheMonies, MSGBOX_DEFAULT
# 473 "data/maps/Black_Market/scripts.pory"
    hidemoneybox
# 474 "data/maps/Black_Market/scripts.pory"
    release
# 475 "data/maps/Black_Market/scripts.pory"
    end
# 476 "data/maps/Black_Market/scripts.pory"

# 477 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_CandyJust5000:
# 478 "data/maps/Black_Market/scripts.pory"
    .string "Want some Candy? It is a\n"
# 479 "data/maps/Black_Market/scripts.pory"
    .string "local specialty.\p"
# 480 "data/maps/Black_Market/scripts.pory"
    .string "Try one. It's just ¥5000.$"
# 481 "data/maps/Black_Market/scripts.pory"

# 482 "data/maps/Black_Market/scripts.pory"

# 483 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_ThankYouDear:
# 484 "data/maps/Black_Market/scripts.pory"
    .string "Thank you, dearie!$"
# 485 "data/maps/Black_Market/scripts.pory"

# 486 "data/maps/Black_Market/scripts.pory"

# 487 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_YouveNotGotTheMonies:
# 488 "data/maps/Black_Market/scripts.pory"
    .string "You know… You can't buy a thing if\n"
# 489 "data/maps/Black_Market/scripts.pory"
    .string "you've not got the money!$"
# 490 "data/maps/Black_Market/scripts.pory"

# 491 "data/maps/Black_Market/scripts.pory"

# 492 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_OhFineThen:
# 493 "data/maps/Black_Market/scripts.pory"
    .string "Oh, fine then. Scram!$"
# 494 "data/maps/Black_Market/scripts.pory"

# 495 "data/maps/Black_Market/scripts.pory"
EventScript_SHINYCHARMGift::
# 496 "data/maps/Black_Market/scripts.pory"
    lock
# 497 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 498 "data/maps/Black_Market/scripts.pory"
    message gText_Charmtext
# 499 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 500 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_SHINY_CHARM, 1
# 501 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 502 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 503 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 504 "data/maps/Black_Market/scripts.pory"
    message gText_Hereischarm
# 505 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_SHINY_CHARM
# 506 "data/maps/Black_Market/scripts.pory"
    release
# 507 "data/maps/Black_Market/scripts.pory"
    end
# 508 "data/maps/Black_Market/scripts.pory"

# 509 "data/maps/Black_Market/scripts.pory"

# 510 "data/maps/Black_Market/scripts.pory"
Script_havecharm::
# 511 "data/maps/Black_Market/scripts.pory"
    msgbox gText_havecharm
# 512 "data/maps/Black_Market/scripts.pory"
    release
# 513 "data/maps/Black_Market/scripts.pory"
    end
# 514 "data/maps/Black_Market/scripts.pory"

# 515 "data/maps/Black_Market/scripts.pory"

# 516 "data/maps/Black_Market/scripts.pory"
gText_Charmtext::
# 517 "data/maps/Black_Market/scripts.pory"
    .string "Hey I have a gift from Team Aqua!\p $"
# 518 "data/maps/Black_Market/scripts.pory"

# 519 "data/maps/Black_Market/scripts.pory"

# 520 "data/maps/Black_Market/scripts.pory"
gText_havecharm::
# 521 "data/maps/Black_Market/scripts.pory"
    .string "Have I threatened you before?$"
# 522 "data/maps/Black_Market/scripts.pory"

# 523 "data/maps/Black_Market/scripts.pory"

# 524 "data/maps/Black_Market/scripts.pory"
gText_Hereischarm::
# 525 "data/maps/Black_Market/scripts.pory"
    .string "Here! You better join our team!$"
# 526 "data/maps/Black_Market/scripts.pory"

# 527 "data/maps/Black_Market/scripts.pory"
EventScript_EXPCHARMGift::
# 528 "data/maps/Black_Market/scripts.pory"
    lock
# 529 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 530 "data/maps/Black_Market/scripts.pory"
    message gText_CharmEtext
# 531 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 532 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_EXP_CHARM, 1
# 533 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 534 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 535 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 536 "data/maps/Black_Market/scripts.pory"
    message gText_Hereischarm
# 537 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_EXP_CHARM
# 538 "data/maps/Black_Market/scripts.pory"
    release
# 539 "data/maps/Black_Market/scripts.pory"
    end
# 540 "data/maps/Black_Market/scripts.pory"

# 541 "data/maps/Black_Market/scripts.pory"
    gText_CharmEtext::
# 542 "data/maps/Black_Market/scripts.pory"
    .string "Hey I have a gift from Team Magma!\p $"
# 543 "data/maps/Black_Market/scripts.pory"

# 544 "data/maps/Black_Market/scripts.pory"
EventScript_EGGCHARMGift::
# 545 "data/maps/Black_Market/scripts.pory"
    lock
# 546 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 547 "data/maps/Black_Market/scripts.pory"
    message gText_CharmEggtext
# 548 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 549 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_OVAL_CHARM, 1
# 550 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 551 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 552 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 553 "data/maps/Black_Market/scripts.pory"
    message gText_HereisEggcharm
# 554 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_OVAL_CHARM
# 555 "data/maps/Black_Market/scripts.pory"
    release
# 556 "data/maps/Black_Market/scripts.pory"
    end
# 557 "data/maps/Black_Market/scripts.pory"

# 558 "data/maps/Black_Market/scripts.pory"
    gText_CharmEggtext::
# 559 "data/maps/Black_Market/scripts.pory"
    .string "Do I have an amazing gift for you!\p $"
# 560 "data/maps/Black_Market/scripts.pory"

# 561 "data/maps/Black_Market/scripts.pory"
    gText_HereisEggcharm::
# 562 "data/maps/Black_Market/scripts.pory"
    .string "Hope you use this charm wisely....\p $"
# 563 "data/maps/Black_Market/scripts.pory"

# 564 "data/maps/Black_Market/scripts.pory"
EventScript_CATCHCHARMGift::
# 565 "data/maps/Black_Market/scripts.pory"
    lock
# 566 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 567 "data/maps/Black_Market/scripts.pory"
    message gText_CharmCatchtext
# 568 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 569 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_CATCHING_CHARM, 1
# 570 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 571 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 572 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 573 "data/maps/Black_Market/scripts.pory"
    message gText_HereisCatchcharm
# 574 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_CATCHING_CHARM
# 575 "data/maps/Black_Market/scripts.pory"
    release
# 576 "data/maps/Black_Market/scripts.pory"
    end
# 577 "data/maps/Black_Market/scripts.pory"

# 578 "data/maps/Black_Market/scripts.pory"
    gText_CharmCatchtext::
# 579 "data/maps/Black_Market/scripts.pory"
    .string "Do I have an amazing gift for you!\p $"
# 580 "data/maps/Black_Market/scripts.pory"

# 581 "data/maps/Black_Market/scripts.pory"
    gText_HereisCatchcharm::
# 582 "data/maps/Black_Market/scripts.pory"
    .string "Hope you use this charm a lot....\p $"
# 583 "data/maps/Black_Market/scripts.pory"

# 584 "data/maps/Black_Market/scripts.pory"
EventScript_DBANDGift::
# 585 "data/maps/Black_Market/scripts.pory"
    lock
# 586 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 587 "data/maps/Black_Market/scripts.pory"
    message gText_DBANDtext
# 588 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 589 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_DYNAMAX_BAND, 1
# 590 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 591 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 592 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 593 "data/maps/Black_Market/scripts.pory"
    message gText_DBANDcharm
# 594 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_DYNAMAX_BAND
# 595 "data/maps/Black_Market/scripts.pory"
    setflag FLAG_DYNAMAX_BATTLE
# 596 "data/maps/Black_Market/scripts.pory"
    release
# 597 "data/maps/Black_Market/scripts.pory"
    end
# 598 "data/maps/Black_Market/scripts.pory"

# 599 "data/maps/Black_Market/scripts.pory"
gText_DBANDtext::
# 600 "data/maps/Black_Market/scripts.pory"
    .string "First timers get a free gift!\p $"
# 601 "data/maps/Black_Market/scripts.pory"

# 602 "data/maps/Black_Market/scripts.pory"
    gText_DBANDcharm::
# 603 "data/maps/Black_Market/scripts.pory"
    .string "Hope you use this band wisely....\p $"
# 604 "data/maps/Black_Market/scripts.pory"

# 605 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceiveMarshadow::
# 606 "data/maps/Black_Market/scripts.pory"
    lock
# 607 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 608 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
# 609 "data/maps/Black_Market/scripts.pory"
    setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MARSHADOW
# 610 "data/maps/Black_Market/scripts.pory"
    givemon SPECIES_MARSHADOW, 20, item=ITEM_MARSHADIUM_Z, ball=ITEM_DUSK_BALL, nature=NATURE_JOLLY; 
# 611 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BlackMarket_EventScript_ReceiveMarshadowParty
# 612 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BlackMarket_EventScript_ReceiveMarshadowPC
# 613 "data/maps/Black_Market/scripts.pory"
    goto Common_EventScript_NoMoreRoomForPokemon
# 614 "data/maps/Black_Market/scripts.pory"
    end
# 615 "data/maps/Black_Market/scripts.pory"

# 616 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceiveMarshadowParty::
# 617 "data/maps/Black_Market/scripts.pory"
    call BlackMarket_EventScript_ReceivedMarshadowFanfare
# 618 "data/maps/Black_Market/scripts.pory"
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 619 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, BlackMarket_EventScript_ExplainMarshadow
# 620 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_GetGiftMonPartySlot
# 621 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_NameReceivedPartyMon
# 622 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_ExplainMarshadow
# 623 "data/maps/Black_Market/scripts.pory"
    end
# 624 "data/maps/Black_Market/scripts.pory"

# 625 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceiveMarshadowPC::
# 626 "data/maps/Black_Market/scripts.pory"
    call BlackMarket_EventScript_ReceivedMarshadowFanfare
# 627 "data/maps/Black_Market/scripts.pory"
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 628 "data/maps/Black_Market/scripts.pory"
    goto_if_eq VAR_RESULT, NO, BlackMarket_EventScript_SendMarshadowToPC
# 629 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_NameReceivedBoxMon
# 630 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_SendMarshadowToPC
# 631 "data/maps/Black_Market/scripts.pory"
    end
# 632 "data/maps/Black_Market/scripts.pory"

# 633 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_SendMarshadowToPC::
# 634 "data/maps/Black_Market/scripts.pory"
    call Common_EventScript_TransferredToPC
# 635 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_ExplainMarshadow
# 636 "data/maps/Black_Market/scripts.pory"
    end
# 637 "data/maps/Black_Market/scripts.pory"

# 638 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ReceivedMarshadowFanfare::
# 639 "data/maps/Black_Market/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 640 "data/maps/Black_Market/scripts.pory"
    message BlackMarket_Text_PlayerReceivedMarshadow
# 641 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 642 "data/maps/Black_Market/scripts.pory"
    waitfanfare
# 643 "data/maps/Black_Market/scripts.pory"
    bufferspeciesname STR_VAR_1, SPECIES_MARSHADOW
# 644 "data/maps/Black_Market/scripts.pory"
    return
# 645 "data/maps/Black_Market/scripts.pory"

# 646 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_ExplainMarshadow::
# 647 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_PokemonChanges, MSGBOX_DEFAULT
# 648 "data/maps/Black_Market/scripts.pory"
    setflag FLAG_RECEIVED_MARSHADOW
# 649 "data/maps/Black_Market/scripts.pory"
    release
# 650 "data/maps/Black_Market/scripts.pory"
    end
# 651 "data/maps/Black_Market/scripts.pory"

# 652 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_HaveMarshadow::
# 653 "data/maps/Black_Market/scripts.pory"
    msgbox BlackMarket_Text_PokemonChanges, MSGBOX_DEFAULT
# 654 "data/maps/Black_Market/scripts.pory"
    release
# 655 "data/maps/Black_Market/scripts.pory"
    end
# 656 "data/maps/Black_Market/scripts.pory"

# 657 "data/maps/Black_Market/scripts.pory"
BlackMarket_EventScript_HEXMANIAC::
# 658 "data/maps/Black_Market/scripts.pory"
    lock
# 659 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 660 "data/maps/Black_Market/scripts.pory"
    goto_if_set FLAG_RECEIVED_MARSHADOW, BlackMarket_EventScript_HaveMarshadow
# 661 "data/maps/Black_Market/scripts.pory"
    goto BlackMarket_EventScript_ReceiveMarshadow
# 662 "data/maps/Black_Market/scripts.pory"
    end
# 663 "data/maps/Black_Market/scripts.pory"

# 664 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_PlayerReceivedMarshadow:
# 665 "data/maps/Black_Market/scripts.pory"
    .string "{PLAYER} received MARSHADOW!$"
# 666 "data/maps/Black_Market/scripts.pory"

# 667 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_ThanksPleaseTakePokemon:
# 668 "data/maps/Black_Market/scripts.pory"
    .string "Thanks for not snitching!\n"
# 669 "data/maps/Black_Market/scripts.pory"
    .string "Thanks to you, we're safe!\p"
# 670 "data/maps/Black_Market/scripts.pory"
    .string "It might be an odd way of welcoming you,\n"
# 671 "data/maps/Black_Market/scripts.pory"
    .string "but take this POKéMON.$"
# 672 "data/maps/Black_Market/scripts.pory"

# 673 "data/maps/Black_Market/scripts.pory"
BlackMarket_Text_PokemonChanges:
# 674 "data/maps/Black_Market/scripts.pory"
    .string "That POKéMON hides according\n"
# 675 "data/maps/Black_Market/scripts.pory"
    .string "to the area conditions.\p"
# 676 "data/maps/Black_Market/scripts.pory"
    .string "There're plenty of them in the…\n"
# 677 "data/maps/Black_Market/scripts.pory"
    .string "nevermind--go ahead and take it.$"
# 678 "data/maps/Black_Market/scripts.pory"

# 679 "data/maps/Black_Market/scripts.pory"
EventScript_PanicingGuyGift::
# 680 "data/maps/Black_Market/scripts.pory"
    lock
# 681 "data/maps/Black_Market/scripts.pory"
    faceplayer
# 682 "data/maps/Black_Market/scripts.pory"
    message gText_Panicingtext
# 683 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 684 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_ROTOM_CATALOG, 1
# 685 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_GRACIDEA, 1
# 686 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_REVEAL_GLASS, 1
# 687 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_DNA_SPLICERS, 1
# 688 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_ZYGARDE_CUBE, 1
# 689 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_PRISON_BOTTLE, 1
# 690 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_N_SOLARIZER, 1
# 691 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_N_LUNARIZER, 1
# 692 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_REINS_OF_UNITY, 1
# 693 "data/maps/Black_Market/scripts.pory"
    checkitem ITEM_TERA_ORB, 1
# 694 "data/maps/Black_Market/scripts.pory"
    compare VAR_RESULT, 1
# 695 "data/maps/Black_Market/scripts.pory"
    goto_if_eq Script_havecharm
# 696 "data/maps/Black_Market/scripts.pory"
    waitmessage
# 697 "data/maps/Black_Market/scripts.pory"
    message gText_Hereiseverythings
# 698 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_ROTOM_CATALOG
# 699 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_GRACIDEA
# 700 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_REVEAL_GLASS
# 701 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_DNA_SPLICERS
# 702 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_ZYGARDE_CUBE
# 703 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_PRISON_BOTTLE
# 704 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_N_LUNARIZER
# 705 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_N_SOLARIZER
# 706 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_REINS_OF_UNITY
# 707 "data/maps/Black_Market/scripts.pory"
    giveitem ITEM_TERA_ORB
# 708 "data/maps/Black_Market/scripts.pory"
    release
# 709 "data/maps/Black_Market/scripts.pory"
    end
# 710 "data/maps/Black_Market/scripts.pory"

# 711 "data/maps/Black_Market/scripts.pory"
    gText_Panicingtext::
# 712 "data/maps/Black_Market/scripts.pory"
    .string "I have very hot gifts for you!\p $"
# 713 "data/maps/Black_Market/scripts.pory"

# 714 "data/maps/Black_Market/scripts.pory"
    gText_Hereiseverythings::
# 715 "data/maps/Black_Market/scripts.pory"
    .string "Hope you can keep the heat off..\p $"

Black_Market_EventScript_Sign_Text_0:
# 6 "data/maps/Black_Market/scripts.pory"
	.string "EMPLOYEES ONLY!!!!\p"
	.string "KEEP OUT WE MEAN IT!!!!\p"
	.string "$"
