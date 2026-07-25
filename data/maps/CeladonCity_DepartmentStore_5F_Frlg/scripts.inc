CeladonCity_DepartmentStore_5F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_5F_EventScript_Gentleman::
	msgbox CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_Sailor::
	msgbox CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_5F_Text_Drugstore, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_XItems
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_XItems::
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_Vitamins
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_Vitamins::
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CALCIUM
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers::
	.string "[Pokémon] stat enhancers can be\n"
	.string "bought only here.\p"
	.string "[HP Up] increases the base HP of a\n"
	.string "[Pokémon].\p"
	.string "[Calcium] raises the base [Sp. Atk]\n"
	.string "stat of one [Pokémon].\p"
	.string "[Zinc] boosts the base [Sp. Def] stat\n"
	.string "of one [Pokémon].\p"
	.string "[Carbos] enhances the base [Speed]\n"
	.string "stat.$"

CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers::
	.string "I'm here for [Pokémon] stat\n"
	.string "enhancers.\p"
	.string "[Protein] increases the base [Attack]\n"
	.string "power.\p"
	.string "[Iron] increases the base [Defense]\n"
	.string "stat.$"

CeladonCity_DepartmentStore_5F_Text_Drugstore::
	.string "5F: [Drugstore]$"
