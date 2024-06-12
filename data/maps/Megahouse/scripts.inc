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
Common_EventScript_PkmnCenterWonderLady::
# 30 "data/maps/Megahouse/scripts.pory"
    lock
# 31 "data/maps/Megahouse/scripts.pory"
    faceplayer
# 32 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_ReturnToStart::
# 33 "data/maps/Megahouse/scripts.pory"
    message gText_WonderLadyDoYouWantToUse
# 34 "data/maps/Megahouse/scripts.pory"
    waitmessage
# 35 "data/maps/Megahouse/scripts.pory"
    multichoice 18, 6, MULTI_WONDER_USE_OR_EXPLAIN, FALSE
# 36 "data/maps/Megahouse/scripts.pory"
	switch VAR_RESULT
# 37 "data/maps/Megahouse/scripts.pory"
    case 0, EventScript_PkmnCenterWonderLady_TryUse
# 38 "data/maps/Megahouse/scripts.pory"
    case 1, EventScript_PkmnCenterWonderLady_Explain
# 39 "data/maps/Megahouse/scripts.pory"
    case 2, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 40 "data/maps/Megahouse/scripts.pory"
    case MULTI_B_PRESSED, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 41 "data/maps/Megahouse/scripts.pory"
    end
# 42 "data/maps/Megahouse/scripts.pory"

# 43 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_TryUse::
# 44 "data/maps/Megahouse/scripts.pory"
	getpartysize
# 45 "data/maps/Megahouse/scripts.pory"
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 46 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterWonderLady_PickPokemonForWonderTrade
# 47 "data/maps/Megahouse/scripts.pory"
    end
# 48 "data/maps/Megahouse/scripts.pory"

# 49 "data/maps/Megahouse/scripts.pory"

# 50 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_Explain::
# 51 "data/maps/Megahouse/scripts.pory"
    msgbox gText_WonderLadyExplainService, MSGBOX_DEFAULT
# 52 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterWonderLady_ReturnToStart
# 53 "data/maps/Megahouse/scripts.pory"

# 54 "data/maps/Megahouse/scripts.pory"

# 55 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_PickPokemonForWonderTrade::
# 56 "data/maps/Megahouse/scripts.pory"
    msgbox gText_PleaseSelectAPokemon, MSGBOX_DEFAULT
# 57 "data/maps/Megahouse/scripts.pory"
	special ChoosePartyMon
# 58 "data/maps/Megahouse/scripts.pory"
	waitstate
# 59 "data/maps/Megahouse/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 60 "data/maps/Megahouse/scripts.pory"
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterWonderLady_AreYouSure
# 61 "data/maps/Megahouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterGlobalLady_DeclineTrade
# 62 "data/maps/Megahouse/scripts.pory"
    end
# 63 "data/maps/Megahouse/scripts.pory"

# 64 "data/maps/Megahouse/scripts.pory"

# 65 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_AreYouSure::
# 66 "data/maps/Megahouse/scripts.pory"
    specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 67 "data/maps/Megahouse/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_RESULT
# 68 "data/maps/Megahouse/scripts.pory"
    msgbox gText_WonderLadyAreYouSure, MSGBOX_YESNO
# 69 "data/maps/Megahouse/scripts.pory"
    goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterWonderLady_DoWonder
# 70 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterGlobalLady_DeclineTrade
# 71 "data/maps/Megahouse/scripts.pory"
    end
# 72 "data/maps/Megahouse/scripts.pory"

# 73 "data/maps/Megahouse/scripts.pory"

# 74 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterWonderLady_DoWonder::
# 75 "data/maps/Megahouse/scripts.pory"
    message gText_ConnectingToGlobalNetwork
# 76 "data/maps/Megahouse/scripts.pory"
    waitmessage
# 77 "data/maps/Megahouse/scripts.pory"
    delay 120
# 78 "data/maps/Megahouse/scripts.pory"
    playse SE_SAVE
# 79 "data/maps/Megahouse/scripts.pory"
    delay 20
# 80 "data/maps/Megahouse/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8004
# 81 "data/maps/Megahouse/scripts.pory"
	special CreateWonderTradePokemon
# 82 "data/maps/Megahouse/scripts.pory"
	special DoInGameTradeScene
# 83 "data/maps/Megahouse/scripts.pory"
	waitstate
# 84 "data/maps/Megahouse/scripts.pory"
    goto EventScript_PkmnCenterGlobalLady_FinishTrade
# 85 "data/maps/Megahouse/scripts.pory"
    end
# 86 "data/maps/Megahouse/scripts.pory"

# 87 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterGlobalLady_DeclineTrade::
# 88 "data/maps/Megahouse/scripts.pory"
    msgbox gText_GlobalPleaseComeAgain, MSGBOX_DEFAULT
# 89 "data/maps/Megahouse/scripts.pory"
EventScript_PkmnCenterGlobalLady_FinishTrade::
# 90 "data/maps/Megahouse/scripts.pory"
    release
# 91 "data/maps/Megahouse/scripts.pory"
    end
# 92 "data/maps/Megahouse/scripts.pory"

# 93 "data/maps/Megahouse/scripts.pory"

# 94 "data/maps/Megahouse/scripts.pory"
.align 2
# 95 "data/maps/Megahouse/scripts.pory"
EVO_ITEMS::
# 96 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_FIRE_STONE
# 97 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_WATER_STONE
# 98 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_THUNDER_STONE
# 99 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LEAF_STONE
# 100 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ICE_STONE
# 101 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SUN_STONE
# 102 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MOON_STONE
# 103 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SHINY_STONE
# 104 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DUSK_STONE
# 105 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DAWN_STONE
# 106 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_METAL_COAT
# 107 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_RAZOR_CLAW
# 108 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_RAZOR_FANG
# 109 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DEEP_SEA_TOOTH
# 110 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DEEP_SEA_SCALE
# 111 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SWEET_APPLE
# 112 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_TART_APPLE
# 113 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CRACKED_POT
# 114 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CHIPPED_POT
# 115 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GALARICA_CUFF
# 116 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GALARICA_WREATH
# 117 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DRAGON_SCALE
# 118 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_UPGRADE
# 119 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DUBIOUS_DISC
# 120 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PROTECTOR
# 121 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ELECTIRIZER
# 122 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MAGMARIZER
# 123 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_REAPER_CLOTH
# 124 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PRISM_SCALE
# 125 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_WHIPPED_DREAM
# 126 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SACHET
# 127 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_OVAL_STONE
# 128 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PEAT_BLOCK
# 129 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLACK_AUGURITE
# 130 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LINKING_CORD
# 131 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AUSPICIOUS_ARMOR
# 132 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MALICIOUS_ARMOR
# 133 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GIMMIGHOUL_COIN
# 134 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LEADERS_CREST
# 135 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCROLL_OF_DARKNESS
# 136 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCROLL_OF_WATERS
# 137 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SYRUPY_APPLE
# 138 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MASTERPIECE_TEACUP
# 139 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_UNREMARKABLE_TEACUP
# 140 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_METAL_ALLOY
# 141 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_NONE
# 142 "data/maps/Megahouse/scripts.pory"
    release
# 143 "data/maps/Megahouse/scripts.pory"
    end
# 144 "data/maps/Megahouse/scripts.pory"

# 145 "data/maps/Megahouse/scripts.pory"
.align 2
# 146 "data/maps/Megahouse/scripts.pory"
MEGA_ITEMS::
# 147 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_VENUSAURITE
# 148 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLASTOISINITE
# 149 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CHARIZARDITE_X
# 150 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CHARIZARDITE_Y
# 151 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PIDGEOTITE
# 152 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BEEDRILLITE
# 153 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ALAKAZITE
# 154 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SLOWBRONITE
# 155 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GENGARITE
# 156 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_KANGASKHANITE
# 157 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_PINSIRITE
# 158 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GYARADOSITE
# 159 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AERODACTYLITE
# 160 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MEWTWONITE_X
# 161 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MEWTWONITE_Y
# 162 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AMPHAROSITE
# 163 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_STEELIXITE
# 164 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCIZORITE
# 165 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_HERACRONITE
# 166 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_HOUNDOOMINITE
# 167 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_TYRANITARITE
# 168 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SCEPTILITE
# 169 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SWAMPERTITE
# 170 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLAZIKENITE
# 171 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GARDEVOIRITE
# 172 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GALLADITE
# 173 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SABLENITE
# 174 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MAWILITE
# 175 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AGGRONITE
# 176 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MEDICHAMITE
# 177 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_MANECTITE
# 178 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SHARPEDONITE
# 179 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_CAMERUPTITE
# 180 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ALTARIANITE
# 181 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BANETTITE
# 182 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ABSOLITE
# 183 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GLALITITE
# 184 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_SALAMENCITE
# 185 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_METAGROSSITE
# 186 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LATIASITE
# 187 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LATIOSITE
# 188 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LOPUNNITE
# 189 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_LUCARIONITE
# 190 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_GARCHOMPITE
# 191 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_ABOMASITE
# 192 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_AUDINITE
# 193 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_DIANCITE
# 194 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_RED_ORB
# 195 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_BLUE_ORB
# 196 "data/maps/Megahouse/scripts.pory"
    .2byte ITEM_NONE
# 197 "data/maps/Megahouse/scripts.pory"
    release
# 198 "data/maps/Megahouse/scripts.pory"
    end
# 199 "data/maps/Megahouse/scripts.pory"

# 200 "data/maps/Megahouse/scripts.pory"
gText_WonderLadyDoYouWantToUse::
# 201 "data/maps/Megahouse/scripts.pory"
    .string "Would you like to use the\n"
# 202 "data/maps/Megahouse/scripts.pory"
    .string "Wonder Trade service?$"
# 203 "data/maps/Megahouse/scripts.pory"

# 204 "data/maps/Megahouse/scripts.pory"
gText_WonderLadyExplainService::
# 205 "data/maps/Megahouse/scripts.pory"
    .string "The Wonder Trade service allows\n"
# 206 "data/maps/Megahouse/scripts.pory"
    .string "you to trade Pokémon with somebody,\l"
# 207 "data/maps/Megahouse/scripts.pory"
    .string "completely at random.\p"
# 208 "data/maps/Megahouse/scripts.pory"
    .string "What you get from a Wonder Trade\n"
# 209 "data/maps/Megahouse/scripts.pory"
    .string "will always be a surprise!\p"
# 210 "data/maps/Megahouse/scripts.pory"
    .string "The Pokémon come from all across the\n"
# 211 "data/maps/Megahouse/scripts.pory"
    .string "globe, so you may just find yourself\l"
# 212 "data/maps/Megahouse/scripts.pory"
    .string "with a rare species.\p"
# 213 "data/maps/Megahouse/scripts.pory"
    .string "Just be aware that there is no way\n"
# 214 "data/maps/Megahouse/scripts.pory"
    .string "to recover the Pokémon you trade away\l"
# 215 "data/maps/Megahouse/scripts.pory"
    .string "with our service.$"
# 216 "data/maps/Megahouse/scripts.pory"

# 217 "data/maps/Megahouse/scripts.pory"
gText_PleaseSelectAPokemon::
# 218 "data/maps/Megahouse/scripts.pory"
    .string "Please select a Pokémon to be\n"
# 219 "data/maps/Megahouse/scripts.pory"
    .string "traded.$"
# 220 "data/maps/Megahouse/scripts.pory"

# 221 "data/maps/Megahouse/scripts.pory"
gText_WonderLadyAreYouSure::
# 222 "data/maps/Megahouse/scripts.pory"
    .string "Are you sure you want to trade\n"
# 223 "data/maps/Megahouse/scripts.pory"
    .string "{STR_VAR_2}?$"
# 224 "data/maps/Megahouse/scripts.pory"

# 225 "data/maps/Megahouse/scripts.pory"
gText_ConnectingToGlobalNetwork::
# 226 "data/maps/Megahouse/scripts.pory"
    .string "Connecting to the Global Network.\n"
# 227 "data/maps/Megahouse/scripts.pory"
    .string "Please wait…$"
# 228 "data/maps/Megahouse/scripts.pory"

# 229 "data/maps/Megahouse/scripts.pory"
gText_GlobalPleaseComeAgain::
# 230 "data/maps/Megahouse/scripts.pory"
    .string "Please come again.$"

Megahouse_EVO_ITEM_EMPLOYEE_Text_0:
# 8 "data/maps/Megahouse/scripts.pory"
	.string "How may I serve you?$"

Megahouse_EVO_ITEM_EMPLOYEE_Text_1:
# 11 "data/maps/Megahouse/scripts.pory"
	.string "Please Come Again.$"
