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


Megahouse_MEGA_ITEM_EMPLOYEE::
# 17 "data/maps/Megahouse/scripts.pory"
	lock
# 18 "data/maps/Megahouse/scripts.pory"
	faceplayer
# 19 "data/maps/Megahouse/scripts.pory"
	message Megahouse_EVO_ITEM_EMPLOYEE_Text_0
# 20 "data/maps/Megahouse/scripts.pory"
	waitmessage
# 21 "data/maps/Megahouse/scripts.pory"
	pokemart MEGA_ITEMS
# 22 "data/maps/Megahouse/scripts.pory"
	msgbox Megahouse_EVO_ITEM_EMPLOYEE_Text_1
# 23 "data/maps/Megahouse/scripts.pory"
	release
	end


# 27 "data/maps/Megahouse/scripts.pory"

# 28 "data/maps/Megahouse/scripts.pory"

# 29 "data/maps/Megahouse/scripts.pory"
EventScript_MegaMan::
# 30 "data/maps/Megahouse/scripts.pory"
    lock
# 31 "data/maps/Megahouse/scripts.pory"
    faceplayer
# 32 "data/maps/Megahouse/scripts.pory"
    message gText_MegaMan
# 33 "data/maps/Megahouse/scripts.pory"
    waitmessage
# 34 "data/maps/Megahouse/scripts.pory"
    checkitem ITEM_MEGA_RING, 1
# 35 "data/maps/Megahouse/scripts.pory"
    compare VAR_RESULT, 1
# 36 "data/maps/Megahouse/scripts.pory"
    goto_if_eq Script_HaveMegaRing
# 37 "data/maps/Megahouse/scripts.pory"
    message gText_Hereisring
# 38 "data/maps/Megahouse/scripts.pory"
    giveitem ITEM_MEGA_RING
# 39 "data/maps/Megahouse/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 40 "data/maps/Megahouse/scripts.pory"
    release
# 41 "data/maps/Megahouse/scripts.pory"
    end
# 42 "data/maps/Megahouse/scripts.pory"

# 43 "data/maps/Megahouse/scripts.pory"
Common_EventScript_PkmnCenterWonderLady::
# 44 "data/maps/Megahouse/scripts.pory"
    lock
# 45 "data/maps/Megahouse/scripts.pory"
    faceplayer
# 46 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_ReturnToStart::
# 47 "data/maps/Megahouse/scripts.pory"
    message gText_WonderLadyDoYouWantToUse
# 48 "data/maps/Megahouse/scripts.pory"
    waitmessage
# 49 "data/maps/Megahouse/scripts.pory"
    multichoice 18, 6, MULTI_WONDER_USE_OR_EXPLAIN, FALSE
# 50 "data/maps/Megahouse/scripts.pory"
	switch VAR_RESULT
# 51 "data/maps/Megahouse/scripts.pory"
    case 0, EventScript_PkmnCenterWonderLady_TryUse
# 52 "data/maps/Megahouse/scripts.pory"
    case 1, EventScript_PkmnCenterWonderLady_Explain
# 53 "data/maps/Megahouse/scripts.pory"
    case 2, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 54 "data/maps/Megahouse/scripts.pory"
    case MULTI_B_PRESSED, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 55 "data/maps/Megahouse/scripts.pory"
    end
# 56 "data/maps/Megahouse/scripts.pory"

# 57 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_TryUse::
# 58 "data/maps/Megahouse/scripts.pory"
	getpartysize
# 59 "data/maps/Megahouse/scripts.pory"
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 60 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterWonderLady_PickPokemonForWonderTrade
# 61 "data/maps/Megahouse/scripts.pory"
    end
# 62 "data/maps/Megahouse/scripts.pory"

# 63 "data/maps/Megahouse/scripts.pory"

# 64 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_Explain::
# 65 "data/maps/Megahouse/scripts.pory"
    msgbox gText_WonderLadyExplainService, MSGBOX_DEFAULT
# 66 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterWonderLady_ReturnToStart
# 67 "data/maps/Megahouse/scripts.pory"

# 68 "data/maps/Megahouse/scripts.pory"

# 69 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_PickPokemonForWonderTrade::
# 70 "data/maps/Megahouse/scripts.pory"
    msgbox gText_PleaseSelectAPokemon, MSGBOX_DEFAULT
# 71 "data/maps/Megahouse/scripts.pory"
	special ChoosePartyMon
# 72 "data/maps/Megahouse/scripts.pory"
	waitstate
# 73 "data/maps/Megahouse/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 74 "data/maps/Megahouse/scripts.pory"
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterWonderLady_AreYouSure
# 75 "data/maps/Megahouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 76 "data/maps/Megahouse/scripts.pory"
    end
# 77 "data/maps/Megahouse/scripts.pory"

# 78 "data/maps/Megahouse/scripts.pory"

# 79 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_AreYouSure::
# 80 "data/maps/Megahouse/scripts.pory"
    specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 81 "data/maps/Megahouse/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_RESULT
# 82 "data/maps/Megahouse/scripts.pory"
    msgbox gText_WonderLadyAreYouSure, MSGBOX_YESNO
# 83 "data/maps/Megahouse/scripts.pory"
    goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterWonderLady_DoWonder
# 84 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterGlobalLady_DeclineTrade
# 85 "data/maps/Megahouse/scripts.pory"
    end
# 86 "data/maps/Megahouse/scripts.pory"

# 87 "data/maps/Megahouse/scripts.pory"

# 88 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_DoWonder::
# 89 "data/maps/Megahouse/scripts.pory"
    message gText_ConnectingToGlobalNetwork
# 90 "data/maps/Megahouse/scripts.pory"
    waitmessage
# 91 "data/maps/Megahouse/scripts.pory"
    delay 120
# 92 "data/maps/Megahouse/scripts.pory"
    playse SE_SAVE
# 93 "data/maps/Megahouse/scripts.pory"
    delay 20
# 94 "data/maps/Megahouse/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8004
# 95 "data/maps/Megahouse/scripts.pory"
	special CreateWonderTradePokemon
# 96 "data/maps/Megahouse/scripts.pory"
	special DoInGameTradeScene
# 97 "data/maps/Megahouse/scripts.pory"
	waitstate
# 98 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterGlobalLady_FinishTrade
# 99 "data/maps/Megahouse/scripts.pory"
    end
# 100 "data/maps/Megahouse/scripts.pory"

# 101 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterGlobalLady_DeclineTrade::
# 102 "data/maps/Megahouse/scripts.pory"
    msgbox gText_GlobalPleaseComeAgain, MSGBOX_DEFAULT
# 103 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterGlobalLady_FinishTrade::
# 104 "data/maps/Megahouse/scripts.pory"
    release
# 105 "data/maps/Megahouse/scripts.pory"
    end
# 106 "data/maps/Megahouse/scripts.pory"

# 107 "data/maps/Megahouse/scripts.pory"

# 108 "data/maps/Megahouse/scripts.pory"
.align 2
# 109 "data/maps/Megahouse/scripts.pory"
EVO_ITEMS::
# 110 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_FIRE_STONE
# 111 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_WATER_STONE
# 112 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_THUNDER_STONE
# 113 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LEAF_STONE
# 114 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ICE_STONE
# 115 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SUN_STONE
# 116 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MOON_STONE
# 117 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SHINY_STONE
# 118 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DUSK_STONE
# 119 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DAWN_STONE
# 120 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_METAL_COAT
# 121 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_RAZOR_CLAW
# 122 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_RAZOR_FANG
# 123 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DEEP_SEA_TOOTH
# 124 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DEEP_SEA_SCALE
# 125 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SWEET_APPLE
# 126 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_TART_APPLE
# 127 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CRACKED_POT
# 128 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CHIPPED_POT
# 129 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GALARICA_CUFF
# 130 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GALARICA_WREATH
# 131 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DRAGON_SCALE
# 132 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_UPGRADE
# 133 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DUBIOUS_DISC
# 134 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PROTECTOR
# 135 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ELECTIRIZER
# 136 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MAGMARIZER
# 137 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_REAPER_CLOTH
# 138 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PRISM_SCALE
# 139 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_WHIPPED_DREAM
# 140 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SACHET
# 141 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_OVAL_STONE
# 142 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PEAT_BLOCK
# 143 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLACK_AUGURITE
# 144 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LINKING_CORD
# 145 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AUSPICIOUS_ARMOR
# 146 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MALICIOUS_ARMOR
# 147 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GIMMIGHOUL_COIN
# 148 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LEADERS_CREST
# 149 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCROLL_OF_DARKNESS
# 150 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCROLL_OF_WATERS
# 151 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SYRUPY_APPLE
# 152 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MASTERPIECE_TEACUP
# 153 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_UNREMARKABLE_TEACUP
# 154 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_METAL_ALLOY
# 155 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_NONE
# 156 "data/maps/Megahouse/scripts.pory"
    release
# 157 "data/maps/Megahouse/scripts.pory"
    end
# 158 "data/maps/Megahouse/scripts.pory"

# 159 "data/maps/Megahouse/scripts.pory"
.align 2
# 160 "data/maps/Megahouse/scripts.pory"
MEGA_ITEMS::
# 161 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_VENUSAURITE
# 162 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLASTOISINITE
# 163 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CHARIZARDITE_X
# 164 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CHARIZARDITE_Y
# 165 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PIDGEOTITE
# 166 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BEEDRILLITE
# 167 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ALAKAZITE
# 168 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SLOWBRONITE
# 169 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GENGARITE
# 170 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_KANGASKHANITE
# 171 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PINSIRITE
# 172 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GYARADOSITE
# 173 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AERODACTYLITE
# 174 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MEWTWONITE_X
# 175 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MEWTWONITE_Y
# 176 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AMPHAROSITE
# 177 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_STEELIXITE
# 178 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCIZORITE
# 179 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_HERACRONITE
# 180 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_HOUNDOOMINITE
# 181 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_TYRANITARITE
# 182 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCEPTILITE
# 183 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SWAMPERTITE
# 184 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLAZIKENITE
# 185 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GARDEVOIRITE
# 186 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GALLADITE
# 187 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SABLENITE
# 188 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MAWILITE
# 189 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AGGRONITE
# 190 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MEDICHAMITE
# 191 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MANECTITE
# 192 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SHARPEDONITE
# 193 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CAMERUPTITE
# 194 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ALTARIANITE
# 195 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BANETTITE
# 196 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ABSOLITE
# 197 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GLALITITE
# 198 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SALAMENCITE
# 199 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_METAGROSSITE
# 200 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LATIASITE
# 201 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LATIOSITE
# 202 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LOPUNNITE
# 203 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LUCARIONITE
# 204 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GARCHOMPITE
# 205 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ABOMASITE
# 206 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AUDINITE
# 207 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DIANCITE
# 208 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_RED_ORB
# 209 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLUE_ORB
# 210 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_NONE
# 211 "data/maps/Megahouse/scripts.pory"
    release
# 212 "data/maps/Megahouse/scripts.pory"
    end
# 213 "data/maps/Megahouse/scripts.pory"

# 214 "data/maps/Megahouse/scripts.pory"
gText_WonderLadyDoYouWantToUse::
# 215 "data/maps/Megahouse/scripts.pory"
    .string "Would you like to use the\n"
# 216 "data/maps/Megahouse/scripts.pory"
    .string "Wonder Trade service?$"
# 217 "data/maps/Megahouse/scripts.pory"

# 218 "data/maps/Megahouse/scripts.pory"
gText_WonderLadyExplainService::
# 219 "data/maps/Megahouse/scripts.pory"
    .string "The Wonder Trade service allows\n"
# 220 "data/maps/Megahouse/scripts.pory"
    .string "you to trade Pokémon with somebody,\l"
# 221 "data/maps/Megahouse/scripts.pory"
    .string "completely at random.\p"
# 222 "data/maps/Megahouse/scripts.pory"
    .string "What you get from a Wonder Trade\n"
# 223 "data/maps/Megahouse/scripts.pory"
    .string "will always be a surprise!\p"
# 224 "data/maps/Megahouse/scripts.pory"
    .string "The Pokémon come from all across the\n"
# 225 "data/maps/Megahouse/scripts.pory"
    .string "globe, so you may just find yourself\l"
# 226 "data/maps/Megahouse/scripts.pory"
    .string "with a rare species.\p"
# 227 "data/maps/Megahouse/scripts.pory"
    .string "Just be aware that there is no way\n"
# 228 "data/maps/Megahouse/scripts.pory"
    .string "to recover the Pokémon you trade away\l"
# 229 "data/maps/Megahouse/scripts.pory"
    .string "with our service.$"
# 230 "data/maps/Megahouse/scripts.pory"

# 231 "data/maps/Megahouse/scripts.pory"
gText_PleaseSelectAPokemon::
# 232 "data/maps/Megahouse/scripts.pory"
    .string "Please select a Pokémon to be\n"
# 233 "data/maps/Megahouse/scripts.pory"
    .string "traded.$"
# 234 "data/maps/Megahouse/scripts.pory"

# 235 "data/maps/Megahouse/scripts.pory"
gText_WonderLadyAreYouSure::
# 236 "data/maps/Megahouse/scripts.pory"
    .string "Are you sure you want to trade\n"
# 237 "data/maps/Megahouse/scripts.pory"
    .string "{STR_VAR_2}?$"
# 238 "data/maps/Megahouse/scripts.pory"

# 239 "data/maps/Megahouse/scripts.pory"
gText_ConnectingToGlobalNetwork::
# 240 "data/maps/Megahouse/scripts.pory"
    .string "Connecting to the Global Network.\n"
# 241 "data/maps/Megahouse/scripts.pory"
    .string "Please wait…$"
# 242 "data/maps/Megahouse/scripts.pory"

# 243 "data/maps/Megahouse/scripts.pory"
gText_GlobalPleaseComeAgain::
# 244 "data/maps/Megahouse/scripts.pory"
    .string "Please come again.$"
# 245 "data/maps/Megahouse/scripts.pory"

# 246 "data/maps/Megahouse/scripts.pory"
Script_HaveMegaRing::
# 247 "data/maps/Megahouse/scripts.pory"
    msgbox gText_HaveMegaRing
# 248 "data/maps/Megahouse/scripts.pory"
    release
# 249 "data/maps/Megahouse/scripts.pory"
    end
# 250 "data/maps/Megahouse/scripts.pory"

# 251 "data/maps/Megahouse/scripts.pory"
gText_MegaMan::
# 252 "data/maps/Megahouse/scripts.pory"
    .string "Hi! I am the MEGA MAN!\n"
# 253 "data/maps/Megahouse/scripts.pory"
    .string "Here join me in this adventure!$"
# 254 "data/maps/Megahouse/scripts.pory"

# 255 "data/maps/Megahouse/scripts.pory"
gText_HaveMegaRing::
# 256 "data/maps/Megahouse/scripts.pory"
    .string "You already have a Mega Ring!$"
# 257 "data/maps/Megahouse/scripts.pory"

# 258 "data/maps/Megahouse/scripts.pory"
gText_Hereisring::
# 259 "data/maps/Megahouse/scripts.pory"
    .string "Here is your Mega Ring!$"

Megahouse_EVO_ITEM_EMPLOYEE_Text_0:
# 8 "data/maps/Megahouse/scripts.pory"
	.string "How may I serve you?$"

Megahouse_EVO_ITEM_EMPLOYEE_Text_1:
# 11 "data/maps/Megahouse/scripts.pory"
	.string "Please Come Again.$"
