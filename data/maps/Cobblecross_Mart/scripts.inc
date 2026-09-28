Cobblecross_Mart_MapScripts::
	.byte 0

Cobblecross_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Cobblecross_Mart_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Cobblecross_Mart_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_MASTER_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_REST
	.2byte ITEM_TM_ROCK_TOMB
	.2byte ITEM_TM_BULLDOZE
	.2byte ITEM_TM_BRICK_BREAK
	.2byte ITEM_TM_METAL_CLAW
	.2byte ITEM_TM_SANDSTORM
	.2byte ITEM_TM_SUNNY_DAY
	.2byte ITEM_TM_RAIN_DANCE
	.2byte ITEM_TM_SWORDS_DANCE
	.2byte ITEM_TM_CALM_MIND
	.2byte ITEM_TM_BULK_UP
	pokemartlistend

