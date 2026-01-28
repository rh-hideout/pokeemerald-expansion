Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_StartBirchRescue::
	lockall
	playbgm MUS_HELP, TRUE

	@ Szene sichtbar machen
	clearflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG

	@ Zigzagoon am Anfang unsichtbar
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON

	@ Bum + Zig Startposition
	setobjectxy LOCALID_ROUTE101_BIRCH, 6, 14
	setobjectxy LOCALID_ROUTE101_ZIGZAGOON, 5, 14

	@ Gate zurücksetzen (Bum muss einmal angesprochen werden)
	clearflag FLAG_TEMP_4

	@ 2 Schritte ins Bild (WICHTIG: erst bewegen, dann STATE=2 setzen!)
	applymovement LOCALID_PLAYER, Route101_Movement_PlayerUp2
	waitmovement 0

	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT

	@ Ab jetzt Ausgänge blocken
	setvar VAR_ROUTE101_STATE, 2

	releaseall
	end

Route101_Movement_PlayerUp2:
	walk_up
	walk_up
	step_end

Route101_EventScript_BumTalk::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, Route101_BumTalk_Done

	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4

Route101_BumTalk_Done:
	release
	end

Route101_EventScript_PreventExitSouth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth:
	walk_up
	step_end

Route101_Movement_PreventExitWest:
	walk_right
	step_end

Route101_Movement_PreventExitNorth:
	walk_down
	step_end

@ Leftover data? This command is unused.
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
	lock
	faceplayer

	@ Bag erst nutzen, wenn Bum angesprochen wurde
	goto_if_set FLAG_TEMP_4, Route101_Bag_DoChoose
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	release
	end

Route101_Bag_DoChoose:
	setflag FLAG_SYS_POKEMON_GET
	fadescreen FADE_TO_BLACK

	special ChooseStarter
	waitstate

	fadescreen FADE_FROM_BLACK
	waitstate

	bufferleadmonspeciesname STR_VAR_1
	msgbox Route101_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route101_EventScript_NicknameStarter
	goto Route101_EventScript_AfterNickname

Route101_EventScript_NicknameStarter:
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon

Route101_EventScript_AfterNickname:
	@ Zig erscheint neben Bum
	clearflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	setobjectxy LOCALID_ROUTE101_ZIGZAGOON, 8, 14

	@ Text kommt direkt nach Auswahl/Nickname (wie gewünscht)
	msgbox Route101_Text_Battle, MSGBOX_DEFAULT

	release
	end


Route101_EventScript_ZigzagoonInteract::
	lockall
	setwildbattle SPECIES_ZIGZAGOON, 2, ITEM_NONE
	dowildbattle
	waitstate

	specialvar VAR_RESULT, GetBattleOutcome

	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route101_Zig_BattleWon
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Route101_Zig_BattleWon

	releaseall
	end

Route101_Zig_BattleWon:
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON

	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT

	special HealPlayerParty

	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BumLeaveScene
	waitmovement 0

	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG

	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_ROUTE101_STATE, 3
	setvar VAR_BIRCH_LAB_STATE, 3

	clearflag FLAG_HIDE_MAP_NAME_POPUP
	fadedefaultbgm

	releaseall
	end

Route101_Movement_BumLeaveScene:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer:
	face_right
	face_down
	step_end

Route101_Movement_BumLeave:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end


Route101_Text_HelpMe:
	.string "BUM: Yo Kid, come over 'ere!$"


Route101_Text_PleaseHelp:
	.string "BUM: Hello! You interested?!\n"
	.string "{PLAYER}: You wanna sell me drugs?\n"
	.string "BUM: No, no, I'll show you the hottest shit!!\n"
	.string "In my BAG!\n"
	.string "Take a look and pick one!$"

Route101_Text_WhyNotGiveNicknameToMon:
	.string "BUM: Why not give your new POKéMON a nickname?\n"

Route101_Text_DontLeaveMe:
	.string "BUM: Don't leave kid! Come here!$"

Route101_Text_Battle:
	.string "BUM: Nice pick! \n"
	.string "Here, fight my ZIGZAGOON!$"

Route101_Text_YouSavedMe:
	.string "BUM: Nice one, kid!\p"
	.string "You had fun?\n"
	.string "{PLAYER}: Yeah!\n"
	.string "BUM: You want to keep it?\p"
	.string "{PLAYER}: Sure, what do you want for it?\p"
	.string "BUM: First one is always free.\p"
	.string "This is not the place to chat,\n"
	.string "see you later!$"

Route101_Text_TakeTiredPokemonToPokeCenter:
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route101_Text_WildPokemonInTallGrass:
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign:
	.string "ROUTE 101\n"
	.string "{UP_ARROW} NEUOSTHEIM$"

