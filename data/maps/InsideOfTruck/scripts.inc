InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end

InsideOfTruck_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBox::
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end

InsideOfTruck_Text_BoxPrintedWithMonLogo:
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"





    .align 2

CtfTruck_Terminal::
    lock
    faceplayer
    msgbox CtfTruck_Text_Prompt, MSGBOX_DEFAULT

    setvar VAR_0x8000, 1        @ Gym 1 (Index 1)
    callnative Ctf_FlagTerminal
    waitstate

    compare VAR_RESULT, 1
    goto_if_eq CtfTruck_Terminal_Ok

    msgbox CtfTruck_Text_Wrong, MSGBOX_DEFAULT
    release
    end

CtfTruck_Terminal_Ok::
    setflag FLAG_CTF_TRUCK_TELEPORT
    msgbox CtfTruck_Text_Ok, MSGBOX_DEFAULT
    release
    end


CtfTruck_Teleporter::
    lock
    checkplayergender
    compare VAR_RESULT, FEMALE
    goto_if_eq CtfTruck_Teleporter_May

    @ Brendan House (male)
    warp MAP_GROUP(LITTLEROOT_TOWN_BRENDANS_HOUSE_1F), MAP_NUM(LITTLEROOT_TOWN_BRENDANS_HOUSE_1F), 0, 6, 7
    release
    end

CtfTruck_Teleporter_May::
    @ May House (female)
    warp MAP_GROUP(LITTLEROOT_TOWN_MAYS_HOUSE_1F), MAP_NUM(LITTLEROOT_TOWN_MAYS_HOUSE_1F), 0, 6, 7
    release
    end


CtfTruck_Text_Prompt::
    .string "CTF-Terminal: Gib die erste Flag ein.@"

CtfTruck_Text_Wrong::
    .string "Falsch.@"

CtfTruck_Text_Ok::
    .string "Korrekt! Ein Teleporter ist erschienen.@"
