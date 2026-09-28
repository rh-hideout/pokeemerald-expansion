Brambleton_Mart_MapScripts::
	.byte 0

Brambleton_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Brambleton_Mart_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Brambleton_Mart_EventScript_Woman::
	msgbox Brambleton_Mart_Text_1, MSGBOX_NPC
	end

	.align 2
Brambleton_Mart_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_REST
	.2byte ITEM_TM_FLAME_CHARGE
	.2byte ITEM_TM_WATER_PULSE
	.2byte ITEM_TM_MAGICAL_LEAF
	.2byte ITEM_TM_AERIAL_ACE
	.2byte ITEM_TM_ROCK_TOMB
	.2byte ITEM_TM_BUG_BITE
	pokemartlistend

Brambleton_Mart_Text_1::
	.string "TMs here never break, so you can\n"
	.string "teach them to your whole team!\p"
	.string "Cobblecross, further west, even\n"
	.string "sells Master Balls. Can you\l"
	.string "believe it?$"

