.set LOCALID_SSAQUA_SLEEPYSAILOR, 1

SSAqua_RoomNW_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomNW_OnTransition
	.byte 0

SSAqua_RoomNW_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 3, SSAqua_RoomNW_SetTrainerPos
    end

SSAqua_RoomNW_SetTrainerPos::
    setobjectxyperm 2, 2, 6
    setobjectxyperm 3, 4, 3
    end

SSAqua_RoomNW_EventScript_Stanly::
    lock
    faceplayer
    msgbox SSAqua_RoomNW_Text_SailorStanlySeen, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_STANLY, SSAqua_RoomNW_Text_SailorStanlyBeaten
	msgbox SSAqua_RoomNW_Text_SailorStanlyAfterBattle, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    delay 60
    playse SE_DOOR
    removeobject LOCALID_SSAQUA_SLEEPYSAILOR
    fadescreenswapbuffers FADE_FROM_BLACK
    setvar VAR_SSAQUA_STATE, 3
	end

SSAqua_RoomNW_EventScript_Edward::
    trainerbattle_single TRAINER_EDWARD SSAqua_RoomNW_Text_GentlemanEdwardSeen, SSAqua_RoomNW_Text_GentlemanEdwardBeaten
	msgbox SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNW_EventScript_Corey::
    trainerbattle_single TRAINER_COREY SSAqua_RoomNW_Text_BurglarCoreySeen, SSAqua_RoomNW_Text_BurglarCoreyBeaten
	msgbox SSAqua_RoomNW_Text_BurglarCoreyAfterBattle, MSGBOX_AUTOCLOSE
	end


SSAqua_RoomNW_Text_SailorStanlySeen:
	.string "Yeah, I'm a sailor, all right.\p"
	.string "I wasn't goofing off!\p"
	.string "This cabin was vacant, so I\n"
	.string "just took a quick nap!\p"
	.string "Ah, forget it! Let's battle!$"

SSAqua_RoomNW_Text_SailorStanlyBeaten:
	.string "Sorry! It's all my fault!$"

SSAqua_RoomNW_Text_SailorStanlyAfterBattle:
	.string "Being a sailor, I have to do\n"
	.string "physical labor. It's exhausting!$"

SSAqua_RoomNW_Text_GentlemanEdwardSeen:
	.string "Oh, no. I've lost something\n"
	.string "that's very important.$"

SSAqua_RoomNW_Text_GentlemanEdwardBeaten:
	.string "I… I can't find it…$"

SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle:
	.string "I give up. You don't have to\n"
	.string "look.\p"
	.string "Just forget about it!$"

SSAqua_RoomNW_Text_BurglarCoreySeen:
	.string "Yeehaw! Lucky!$"

SSAqua_RoomNW_Text_BurglarCoreyBeaten:
	.string "How unlucky! I lost!$"

SSAqua_RoomNW_Text_BurglarCoreyAfterBattle:
	.string "I found a pretty coin here.\p"
	.string "Someone must have lost it…$"
