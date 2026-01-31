SongFlagArena_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SongFlagArena_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SongFlagArena_OnWarp
	.byte 0

SongFlagArena_OnTransition:
	end

SongFlagArena_OnWarp:
	.2byte 0


SongFlagArena_EventScript_Kali::
	lock
	faceplayer
	trainerbattle_single TRAINER_KALI, SongFlagArena_Text_KaliIntro, SongFlagArena_Text_KaliDefeat, SongFlagArena_EventScript_KaliAfter, NO_MUSIC
	end


SongFlagArena_EventScript_KaliAfter::
	@ 1) Wenn der Orden noch nicht vergeben wurde: Orden-Sequence + TM geben
	goto_if_set FLAG_BADGE06_GET, SongFlagArena_EventScript_CheckTmOnly

	message SongFlagArena_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare

	msgbox SongFlagArena_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT

	@ Flags für Progress / Badge 6
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET

	@ TM geben (falls Beutel voll -> Hinweistext)
	call SongFlagArena_EventScript_GiveAerialAce
	goto SongFlagArena_EventScript_KaliPostBattle


SongFlagArena_EventScript_CheckTmOnly::
	@ 2) Orden ist schon da, aber TM noch nicht? Dann nur TM geben.
	goto_if_set FLAG_RECEIVED_TM_AERIAL_ACE, SongFlagArena_EventScript_KaliPostBattle

	msgbox SongFlagArena_Text_KaliTakeThis, MSGBOX_DEFAULT
	call SongFlagArena_EventScript_GiveAerialAce
	@ fallthrough


SongFlagArena_EventScript_KaliPostBattle::
	msgbox SongFlagArena_Text_KaliPostBattle, MSGBOX_DEFAULT
	release
	end


SongFlagArena_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, SongFlagArena_EventScript_BagFull
	msgbox SongFlagArena_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

SongFlagArena_EventScript_BagFull::
	msgbox SongFlagArena_Text_BagFull, MSGBOX_DEFAULT
	return


@ ----------------------
@ Texte
@ ----------------------

SongFlagArena_Text_KaliIntro:
	.string "I am KALI.\p"
	.string "Show me your strength in battle!$"

SongFlagArena_Text_KaliDefeat:
	.string "Never before have I seen a TRAINER\n"
	.string "command POKéMON with more grace\l"
	.string "than I…\p"
	.string "In recognition of your prowess,\n"
	.string "I present to you this GYM BADGE.$"

SongFlagArena_Text_ReceivedFeatherBadge:
	.string "{PLAYER} received the FEATHER BADGE\n"
	.string "from KALI.$"

SongFlagArena_Text_ExplainFeatherBadgeTakeThis:
	.string "With the FEATHER BADGE, all POKéMON up\n"
	.string "to LV 70, even those received through\l"
	.string "trades, will obey your every command.\p"
	.string "You will also be able to use\n"
	.string "the HM move FLY outside of battle.\p"
	.string "And this…\n"
	.string "This is a gift from me.$"

SongFlagArena_Text_KaliTakeThis:
	.string "KALI: Take this, too.$"

SongFlagArena_Text_ExplainAerialAce:
	.string "TM40 contains AERIAL ACE.\p"
	.string "Its speed…\n"
	.string "No POKéMON should be able to avoid it.\p"
	.string "… … … … … …$"

SongFlagArena_Text_BagFull:
	.string "Your BAG is full.\n"
	.string "Make some space and come back.$"

SongFlagArena_Text_KaliPostBattle:
	.string "Though I fell to you, I will remain\n"
	.string "devoted to my POKéMON.$"
