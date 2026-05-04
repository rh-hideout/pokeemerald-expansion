SaffronCity_CopyCatsHouse_1F_MapScripts::
	.byte 0

SaffronCity_CopyCatsHouse_1F_EventScript_Mom::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter
	msgbox CopycatsHouse1F_Text_PokefanF, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter::
	msgbox CopycatsHouse1F_Text_PokefanF_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Dad::
	msgbox CopycatsHouse1F_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Blissey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	msgbox CopycatsHouse1F_Text_Blissey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CopycatsHouse1F_Text_PokefanM:
	.string "My daughter likes to mimic people.\p"
	.string "Her mimicry has earned her the\n"
	.string "nickname COPYCAT around here.$"

CopycatsHouse1F_Text_PokefanF:
	.string "My daughter is so self-centered…\p"
	.string "She only has a few friends.$"

CopycatsHouse1F_Text_PokefanF_ReturnedPart:
	.string "She recently lost the POKé DOLL\n"
	.string "that a boy gave her three years\l"
	.string "ago.\p"
	.string "Ever since then, she's gotten even\n"
	.string "better at mimicry…$"

CopycatsHouse1F_Text_Blissey:
	.string "BLISSEY: Bliisii!$"
