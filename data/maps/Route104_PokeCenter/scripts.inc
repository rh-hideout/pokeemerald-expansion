Route104_PokeCenter_MapScripts::
	.byte 0
.set LOCALID_NURSE, 1

Route104_PokeCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Route104_PokeCenter_EventScript_Util::
	call Common_EventScript_PkmnCenterUtil
	waitmessage
	waitbuttonpress
	release
	end
