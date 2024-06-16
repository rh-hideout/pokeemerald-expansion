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
    waitmessage
# 38 "data/maps/Megahouse/scripts.pory"
    message gText_Hereisring
# 39 "data/maps/Megahouse/scripts.pory"
    giveitem ITEM_MEGA_RING
# 40 "data/maps/Megahouse/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 41 "data/maps/Megahouse/scripts.pory"
    release
# 42 "data/maps/Megahouse/scripts.pory"
    end
# 43 "data/maps/Megahouse/scripts.pory"

# 44 "data/maps/Megahouse/scripts.pory"
Common_EventScript_PkmnCenterWonderLady::
# 45 "data/maps/Megahouse/scripts.pory"
    lock
# 46 "data/maps/Megahouse/scripts.pory"
    faceplayer
# 47 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_ReturnToStart::
# 48 "data/maps/Megahouse/scripts.pory"
    message gText_WonderLadyDoYouWantToUse
# 49 "data/maps/Megahouse/scripts.pory"
    waitmessage
# 50 "data/maps/Megahouse/scripts.pory"
    multichoice 18, 6, MULTI_WONDER_USE_OR_EXPLAIN, FALSE
# 51 "data/maps/Megahouse/scripts.pory"
	switch VAR_RESULT
# 52 "data/maps/Megahouse/scripts.pory"
    case 0, EventScript_PkmnCenterWonderLady_TryUse
# 53 "data/maps/Megahouse/scripts.pory"
    case 1, EventScript_PkmnCenterWonderLady_Explain
# 54 "data/maps/Megahouse/scripts.pory"
    case 2, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 55 "data/maps/Megahouse/scripts.pory"
    case MULTI_B_PRESSED, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 56 "data/maps/Megahouse/scripts.pory"
    end
# 57 "data/maps/Megahouse/scripts.pory"

# 58 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_TryUse::
# 59 "data/maps/Megahouse/scripts.pory"
	getpartysize
# 60 "data/maps/Megahouse/scripts.pory"
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 61 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterWonderLady_PickPokemonForWonderTrade
# 62 "data/maps/Megahouse/scripts.pory"
    end
# 63 "data/maps/Megahouse/scripts.pory"

# 64 "data/maps/Megahouse/scripts.pory"

# 65 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_Explain::
# 66 "data/maps/Megahouse/scripts.pory"
    msgbox gText_WonderLadyExplainService, MSGBOX_DEFAULT
# 67 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterWonderLady_ReturnToStart
# 68 "data/maps/Megahouse/scripts.pory"

# 69 "data/maps/Megahouse/scripts.pory"

# 70 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_PickPokemonForWonderTrade::
# 71 "data/maps/Megahouse/scripts.pory"
    msgbox gText_PleaseSelectAPokemon, MSGBOX_DEFAULT
# 72 "data/maps/Megahouse/scripts.pory"
	special ChoosePartyMon
# 73 "data/maps/Megahouse/scripts.pory"
	waitstate
# 74 "data/maps/Megahouse/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 75 "data/maps/Megahouse/scripts.pory"
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterWonderLady_AreYouSure
# 76 "data/maps/Megahouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 77 "data/maps/Megahouse/scripts.pory"
    end
# 78 "data/maps/Megahouse/scripts.pory"

# 79 "data/maps/Megahouse/scripts.pory"

# 80 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_AreYouSure::
# 81 "data/maps/Megahouse/scripts.pory"
    specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 82 "data/maps/Megahouse/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_RESULT
# 83 "data/maps/Megahouse/scripts.pory"
    msgbox gText_WonderLadyAreYouSure, MSGBOX_YESNO
# 84 "data/maps/Megahouse/scripts.pory"
    goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterWonderLady_DoWonder
# 85 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterGlobalLady_DeclineTrade
# 86 "data/maps/Megahouse/scripts.pory"
    end
# 87 "data/maps/Megahouse/scripts.pory"

# 88 "data/maps/Megahouse/scripts.pory"

# 89 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_DoWonder::
# 90 "data/maps/Megahouse/scripts.pory"
    message gText_ConnectingToGlobalNetwork
# 91 "data/maps/Megahouse/scripts.pory"
    waitmessage
# 92 "data/maps/Megahouse/scripts.pory"
    delay 120
# 93 "data/maps/Megahouse/scripts.pory"
    playse SE_SAVE
# 94 "data/maps/Megahouse/scripts.pory"
    delay 20
# 95 "data/maps/Megahouse/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8004
# 96 "data/maps/Megahouse/scripts.pory"
	special CreateWonderTradePokemon
# 97 "data/maps/Megahouse/scripts.pory"
	special DoInGameTradeScene
# 98 "data/maps/Megahouse/scripts.pory"
	waitstate
# 99 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterGlobalLady_FinishTrade
# 100 "data/maps/Megahouse/scripts.pory"
    end
# 101 "data/maps/Megahouse/scripts.pory"

# 102 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterGlobalLady_DeclineTrade::
# 103 "data/maps/Megahouse/scripts.pory"
    msgbox gText_GlobalPleaseComeAgain, MSGBOX_DEFAULT
# 104 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterGlobalLady_FinishTrade::
# 105 "data/maps/Megahouse/scripts.pory"
    release
# 106 "data/maps/Megahouse/scripts.pory"
    end
# 107 "data/maps/Megahouse/scripts.pory"

# 108 "data/maps/Megahouse/scripts.pory"

# 109 "data/maps/Megahouse/scripts.pory"
.align 2
# 110 "data/maps/Megahouse/scripts.pory"
EVO_ITEMS::
# 111 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_FIRE_STONE
# 112 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_WATER_STONE
# 113 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_THUNDER_STONE
# 114 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LEAF_STONE
# 115 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ICE_STONE
# 116 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SUN_STONE
# 117 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MOON_STONE
# 118 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SHINY_STONE
# 119 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DUSK_STONE
# 120 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DAWN_STONE
# 121 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_METAL_COAT
# 122 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_RAZOR_CLAW
# 123 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_RAZOR_FANG
# 124 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DEEP_SEA_TOOTH
# 125 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DEEP_SEA_SCALE
# 126 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SWEET_APPLE
# 127 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_TART_APPLE
# 128 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CRACKED_POT
# 129 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CHIPPED_POT
# 130 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GALARICA_CUFF
# 131 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GALARICA_WREATH
# 132 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DRAGON_SCALE
# 133 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_UPGRADE
# 134 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DUBIOUS_DISC
# 135 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PROTECTOR
# 136 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ELECTIRIZER
# 137 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MAGMARIZER
# 138 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_REAPER_CLOTH
# 139 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PRISM_SCALE
# 140 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_WHIPPED_DREAM
# 141 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SACHET
# 142 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_OVAL_STONE
# 143 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PEAT_BLOCK
# 144 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLACK_AUGURITE
# 145 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LINKING_CORD
# 146 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AUSPICIOUS_ARMOR
# 147 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MALICIOUS_ARMOR
# 148 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GIMMIGHOUL_COIN
# 149 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LEADERS_CREST
# 150 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCROLL_OF_DARKNESS
# 151 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCROLL_OF_WATERS
# 152 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SYRUPY_APPLE
# 153 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MASTERPIECE_TEACUP
# 154 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_UNREMARKABLE_TEACUP
# 155 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_METAL_ALLOY
# 156 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_NONE
# 157 "data/maps/Megahouse/scripts.pory"
    release
# 158 "data/maps/Megahouse/scripts.pory"
    end
# 159 "data/maps/Megahouse/scripts.pory"

# 160 "data/maps/Megahouse/scripts.pory"
.align 2
# 161 "data/maps/Megahouse/scripts.pory"
MEGA_ITEMS::
# 162 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_VENUSAURITE
# 163 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLASTOISINITE
# 164 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CHARIZARDITE_X
# 165 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CHARIZARDITE_Y
# 166 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PIDGEOTITE
# 167 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BEEDRILLITE
# 168 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ALAKAZITE
# 169 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SLOWBRONITE
# 170 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GENGARITE
# 171 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_KANGASKHANITE
# 172 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PINSIRITE
# 173 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GYARADOSITE
# 174 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AERODACTYLITE
# 175 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MEWTWONITE_X
# 176 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MEWTWONITE_Y
# 177 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AMPHAROSITE
# 178 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_STEELIXITE
# 179 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCIZORITE
# 180 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_HERACRONITE
# 181 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_HOUNDOOMINITE
# 182 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_TYRANITARITE
# 183 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCEPTILITE
# 184 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SWAMPERTITE
# 185 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLAZIKENITE
# 186 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GARDEVOIRITE
# 187 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GALLADITE
# 188 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SABLENITE
# 189 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MAWILITE
# 190 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AGGRONITE
# 191 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MEDICHAMITE
# 192 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MANECTITE
# 193 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SHARPEDONITE
# 194 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CAMERUPTITE
# 195 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ALTARIANITE
# 196 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BANETTITE
# 197 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ABSOLITE
# 198 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GLALITITE
# 199 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SALAMENCITE
# 200 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_METAGROSSITE
# 201 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LATIASITE
# 202 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LATIOSITE
# 203 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LOPUNNITE
# 204 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LUCARIONITE
# 205 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GARCHOMPITE
# 206 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ABOMASITE
# 207 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AUDINITE
# 208 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DIANCITE
# 209 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_RED_ORB
# 210 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLUE_ORB
# 211 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_NONE
# 212 "data/maps/Megahouse/scripts.pory"
    release
# 213 "data/maps/Megahouse/scripts.pory"
    end
# 214 "data/maps/Megahouse/scripts.pory"

# 215 "data/maps/Megahouse/scripts.pory"
gText_WonderLadyDoYouWantToUse::
# 216 "data/maps/Megahouse/scripts.pory"
    .string "Would you like to use the\n"
# 217 "data/maps/Megahouse/scripts.pory"
    .string "Wonder Trade service?$"
# 218 "data/maps/Megahouse/scripts.pory"

# 219 "data/maps/Megahouse/scripts.pory"
gText_WonderLadyExplainService::
# 220 "data/maps/Megahouse/scripts.pory"
    .string "The Wonder Trade service allows\n"
# 221 "data/maps/Megahouse/scripts.pory"
    .string "you to trade Pokémon with somebody,\l"
# 222 "data/maps/Megahouse/scripts.pory"
    .string "completely at random.\p"
# 223 "data/maps/Megahouse/scripts.pory"
    .string "What you get from a Wonder Trade\n"
# 224 "data/maps/Megahouse/scripts.pory"
    .string "will always be a surprise!\p"
# 225 "data/maps/Megahouse/scripts.pory"
    .string "The Pokémon come from all across the\n"
# 226 "data/maps/Megahouse/scripts.pory"
    .string "globe, so you may just find yourself\l"
# 227 "data/maps/Megahouse/scripts.pory"
    .string "with a rare species.\p"
# 228 "data/maps/Megahouse/scripts.pory"
    .string "Just be aware that there is no way\n"
# 229 "data/maps/Megahouse/scripts.pory"
    .string "to recover the Pokémon you trade away\l"
# 230 "data/maps/Megahouse/scripts.pory"
    .string "with our service.$"
# 231 "data/maps/Megahouse/scripts.pory"

# 232 "data/maps/Megahouse/scripts.pory"
gText_PleaseSelectAPokemon::
# 233 "data/maps/Megahouse/scripts.pory"
    .string "Please select a Pokémon to be\n"
# 234 "data/maps/Megahouse/scripts.pory"
    .string "traded.$"
# 235 "data/maps/Megahouse/scripts.pory"

# 236 "data/maps/Megahouse/scripts.pory"
gText_WonderLadyAreYouSure::
# 237 "data/maps/Megahouse/scripts.pory"
    .string "Are you sure you want to trade\n"
# 238 "data/maps/Megahouse/scripts.pory"
    .string "{STR_VAR_2}?$"
# 239 "data/maps/Megahouse/scripts.pory"

# 240 "data/maps/Megahouse/scripts.pory"
gText_ConnectingToGlobalNetwork::
# 241 "data/maps/Megahouse/scripts.pory"
    .string "Connecting to the Global Network.\n"
# 242 "data/maps/Megahouse/scripts.pory"
    .string "Please wait…$"
# 243 "data/maps/Megahouse/scripts.pory"

# 244 "data/maps/Megahouse/scripts.pory"
gText_GlobalPleaseComeAgain::
# 245 "data/maps/Megahouse/scripts.pory"
    .string "Please come again.$"
# 246 "data/maps/Megahouse/scripts.pory"

# 247 "data/maps/Megahouse/scripts.pory"
Script_HaveMegaRing::
# 248 "data/maps/Megahouse/scripts.pory"
    msgbox gText_HaveMegaRing
# 249 "data/maps/Megahouse/scripts.pory"
    release
# 250 "data/maps/Megahouse/scripts.pory"
    end
# 251 "data/maps/Megahouse/scripts.pory"

# 252 "data/maps/Megahouse/scripts.pory"
gText_MegaMan::
# 253 "data/maps/Megahouse/scripts.pory"
    .string "Hi! I am the MEGA MAN!\p"
# 254 "data/maps/Megahouse/scripts.pory"
    .string "Here join me in this adventure!\p $"
# 255 "data/maps/Megahouse/scripts.pory"

# 256 "data/maps/Megahouse/scripts.pory"
gText_HaveMegaRing::
# 257 "data/maps/Megahouse/scripts.pory"
    .string "You already have a Mega Ring!$"
# 258 "data/maps/Megahouse/scripts.pory"

# 259 "data/maps/Megahouse/scripts.pory"
gText_Hereisring::
# 260 "data/maps/Megahouse/scripts.pory"
    .string "Here is your Mega Ring!$"

Megahouse_EVO_ITEM_EMPLOYEE_Text_0:
# 8 "data/maps/Megahouse/scripts.pory"
	.string "How may I serve you?$"

Megahouse_EVO_ITEM_EMPLOYEE_Text_1:
# 11 "data/maps/Megahouse/scripts.pory"
	.string "Please Come Again.$"
