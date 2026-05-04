.set LOCALID_DIGLETT_BROCK, 1

DiglettsCave_EntranceNorth_MapScripts::
	.byte 0


DiglettsCave_EntranceNorth_EventScript_Brock::
    lock
    faceplayer
    msgbox DiglettsCave_EntranceNorth_Text_Brock, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DIGLETT_BROCK
    removeobject LOCALID_DIGLETT_BROCK
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BROCK
    release
    end

DiglettsCave_EntranceNorth_Text_Brock:
    .string "BROCK: Small spaces surrounded by\n"
    .string "rocks make you feel peaceful,\l"
    .string "don't you agree?\p"
	.string "If you want another match, I'll be\n"
	.string "at the FIGHTING DOJO.$"




