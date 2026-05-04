.set LOCALID_ICEPATH2_BOULDER1, 3
.set LOCALID_ICEPATH2_BOULDER2, 4
.set LOCALID_ICEPATH2_BOULDER3, 2
.set LOCALID_ICEPATH2_BOULDER4, 1

IcePath_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, IcePath_B1F_SetHoleWarp
	.byte 0

IcePath_B1F_OnTransition: 
	copyvar VAR_ICE_STEP_COUNT, 1
	callnative SetTimeBasedEncounters
	end

IcePath_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_ICE_PATH_B2F
	callnative SetTimeBasedEncounters
	end

IcePath_B1F_EventScript_PuzzleSkipButton::
	lock
	msgbox IcePath_B1F_Text_PuzzleSkipButton, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IcePath_B1F_EventScript_PuzzleSkipButtonNo
	warp MAP_ICE_PATH_B1F, 15, 12
	release
	end

IcePath_B1F_EventScript_PuzzleSkipButtonNo::
	release
	end

IcePath_B1F_Text_PuzzleSkipButton::
	.string "Would you like to skip this\n"
	.string "puzzle?$"

IcePath_B1F_EventScript_Item_Iron::
	finditem ITEM_IRON
	end
IcePath_B1F_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

IcePath_B1F_EventScript_Sign::
	msgbox IcePath_B1F_Text_Sign, MSGBOX_SIGN
	end

IcePath_B1F_Text_Sign:
	.string "DANGER CRACKED ICE\n"
	.string "GO FAST ON BICYCLE\l"
	.string "SWITCH GEARS BY\l"
	.string "PRESSING ...\l"
	.string "The sign is faded...$"

