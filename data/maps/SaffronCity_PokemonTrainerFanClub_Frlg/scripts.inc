SaffronCity_PokemonTrainerFanClub_Frlg_MapScripts::
        map_script MAP_SCRIPT_ON_LOAD, SaffronCity_PokemonTrainerFanClub_Frlg_SetTwinGraphics
        map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonTrainerFanClub_Frlg_SetTwinVisibility
        .byte 0


@ =============================================================================
@ SOL / XIE GRAPHICS
@ =============================================================================

SaffronCity_PokemonTrainerFanClub_Frlg_SetTwinGraphics:
        goto_if_set FLAG_HIDE_HOME_MOM, SaffronCity_PokemonTrainerFanClub_Frlg_SetXieGraphics

        setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SOL
        return


SaffronCity_PokemonTrainerFanClub_Frlg_SetXieGraphics:
        setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_XIE
        return


@ =============================================================================
@ TWIN VISIBILITY
@
@ Before Giovanni: hidden.
@ After Giovanni: waiting quietly in the back.
@ =============================================================================

SaffronCity_PokemonTrainerFanClub_Frlg_SetTwinVisibility:
        goto_if_set FLAG_SILPH_GIOVANNI_MET, SaffronCity_PokemonTrainerFanClub_Frlg_ShowTwin

        setflag FLAG_HIDE_SAFFRON_FANCLUB_TWIN
        hideobjectat LOCALID_SAFFRON_FANCLUB_TWIN, MAP_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB
        end


SaffronCity_PokemonTrainerFanClub_Frlg_ShowTwin:
        clearflag FLAG_HIDE_SAFFRON_FANCLUB_TWIN
        showobjectat LOCALID_SAFFRON_FANCLUB_TWIN, MAP_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB
        end


@ =============================================================================
@ FAN CLUB NONSENSE
@ =============================================================================

SaffronCity_PokemonTrainerFanClub_Frlg_EventScript_CrushGirl::
        msgbox SaffronCity_PokemonTrainerFanClub_Frlg_Text_CrushGirl, MSGBOX_NPC
        end

SaffronCity_PokemonTrainerFanClub_Frlg_EventScript_LittleGirl::
        msgbox SaffronCity_PokemonTrainerFanClub_Frlg_Text_LittleGirl, MSGBOX_NPC
        end

SaffronCity_PokemonTrainerFanClub_Frlg_EventScript_Youngster::
        msgbox SaffronCity_PokemonTrainerFanClub_Frlg_Text_Youngster, MSGBOX_NPC
        end

SaffronCity_PokemonTrainerFanClub_Frlg_EventScript_Gentleman::
        msgbox SaffronCity_PokemonTrainerFanClub_Frlg_Text_Gentleman, MSGBOX_NPC
        end

SaffronCity_PokemonTrainerFanClub_Frlg_EventScript_Woman::
        msgbox SaffronCity_PokemonTrainerFanClub_Frlg_Text_Woman, MSGBOX_NPC
        end

SaffronCity_PokemonTrainerFanClub_Frlg_EventScript_Rocker::
        msgbox SaffronCity_PokemonTrainerFanClub_Frlg_Text_Rocker, MSGBOX_NPC
        end

SaffronCity_PokemonTrainerFanClub_Frlg_EventScript_Beauty::
        msgbox SaffronCity_PokemonTrainerFanClub_Frlg_Text_Beauty, MSGBOX_NPC
        end

SaffronCity_PokemonTrainerFanClub_Frlg_EventScript_BlackBelt::
        msgbox SaffronCity_PokemonTrainerFanClub_Frlg_Text_BlackBelt, MSGBOX_NPC
        end


@ =============================================================================
@ TEMP TWIN INTERACTION
@
@ Intentionally NOT the final debrief yet.
@ This lets us test placement/visibility without triggering the warp-home chain.
@ =============================================================================

SaffronCity_PokemonTrainerFanClub_Frlg_EventScript_Twin::
        lock
        faceplayer

        goto_if_set FLAG_HIDE_HOME_MOM, SaffronCity_PokemonTrainerFanClub_Frlg_BufferXieName

        bufferstring STR_VAR_1, SaffronCity_PokemonTrainerFanClub_Frlg_Text_NameSol
        goto SaffronCity_PokemonTrainerFanClub_Frlg_TwinContinue


SaffronCity_PokemonTrainerFanClub_Frlg_BufferXieName:
        bufferstring STR_VAR_1, SaffronCity_PokemonTrainerFanClub_Frlg_Text_NameXie


SaffronCity_PokemonTrainerFanClub_Frlg_TwinContinue:
        msgbox SaffronCity_PokemonTrainerFanClub_Frlg_Text_TwinFoundMe, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_PokemonTrainerFanClub_Frlg_Text_PlayerThisPlace, MSGBOX_DEFAULT
        closemessage

        msgbox SaffronCity_PokemonTrainerFanClub_Frlg_Text_TwinPerfect, MSGBOX_DEFAULT
        closemessage

        release
        end


@ =============================================================================
@ TEXT
@ =============================================================================

SaffronCity_PokemonTrainerFanClub_Frlg_Text_CrushGirl:
        .string "My MACHOKE could beat anybody's\n"
        .string "favorite POKEMON.$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_LittleGirl:
        .string "That's not what a FAN CLUB is\n"
        .string "supposed to be about!$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_Youngster:
        .string "I changed my favorite POKEMON\n"
        .string "three times this week.$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_Gentleman:
        .string "A true favorite requires years\n"
        .string "of careful consideration.$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_Woman:
        .string "He says that every week.$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_Rocker:
        .string "You ever hear a MAGNEMITE hum?\p"
        .string "Music.$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_Beauty:
        .string "My favorite is whichever one\n"
        .string "looks best next to me.$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_BlackBelt:
        .string "Strength matters.\p"
        .string "Cuteness also matters.\p"
        .string "This is complicated.$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_TwinFoundMe:
        .string "{STR_VAR_1}: Took you long enough.$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_PlayerThisPlace:
        .string "{PLAYER}: You picked THIS place?$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_TwinPerfect:
        .string "{STR_VAR_1}: It's perfect.\p"
        .string "Nobody here asks useful\n"
        .string "questions.$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_NameSol:
        .string "SOL$"


SaffronCity_PokemonTrainerFanClub_Frlg_Text_NameXie:
        .string "XIE$"
