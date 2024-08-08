@ Script commands are tagged with:
@ 1. NOT_MUTATING if they definitely don't have an effect that is
@    visible in-game.
@ 2. MAYBE_MUTATING if they contain code which can check whether they
@    have an effect that is visible in-game.
@ 3. MUTATING if they definitely have an effect that is visible in-game,
@    or they don't contain code which can check whether they have an
@    effect that is visible in-game, or it's not known whether they have
@    an effect that is visible in-game.
@ If you don't know what to pick, MUTATING is the safe choice. See
@ Script_HasNoEffect for an explanation of what specifically counts as
@ an effect that is visible in-game.
#define NOT_MUTATING(symbol) ((symbol) + ROM_SIZE)
#define MAYBE_MUTATING(symbol) ((symbol) + ROM_SIZE)
#define MUTATING(symbol) (symbol)

	.align 2
gScriptCmdTable::
	.4byte NOT_MUTATING(ScrCmd_nop)                         @ 0x00
	.4byte NOT_MUTATING(ScrCmd_nop1)                        @ 0x01
	.4byte NOT_MUTATING(ScrCmd_end)                         @ 0x02
	.4byte NOT_MUTATING(ScrCmd_return)                      @ 0x03
	.4byte NOT_MUTATING(ScrCmd_call)                        @ 0x04
	.4byte NOT_MUTATING(ScrCmd_goto)                        @ 0x05
	.4byte NOT_MUTATING(ScrCmd_goto_if)                     @ 0x06
	.4byte NOT_MUTATING(ScrCmd_call_if)                     @ 0x07
	.4byte NOT_MUTATING(ScrCmd_gotostd)                     @ 0x08
	.4byte NOT_MUTATING(ScrCmd_callstd)                     @ 0x09
	.4byte NOT_MUTATING(ScrCmd_gotostd_if)                  @ 0x0a
	.4byte NOT_MUTATING(ScrCmd_callstd_if)                  @ 0x0b
	.4byte MUTATING(ScrCmd_returnram)                       @ 0x0c
	.4byte MUTATING(ScrCmd_endram)                          @ 0x0d
	.4byte MUTATING(ScrCmd_setmysteryeventstatus)           @ 0x0e
	.4byte NOT_MUTATING(ScrCmd_loadword)                    @ 0x0f
	.4byte NOT_MUTATING(ScrCmd_loadbyte)                    @ 0x10
	.4byte MUTATING(ScrCmd_setptr)                          @ 0x11
	.4byte NOT_MUTATING(ScrCmd_loadbytefromptr)             @ 0x12
	.4byte MUTATING(ScrCmd_setptrbyte)                      @ 0x13
	.4byte NOT_MUTATING(ScrCmd_copylocal)                   @ 0x14
	.4byte MUTATING(ScrCmd_copybyte)                        @ 0x15
	.4byte MAYBE_MUTATING(ScrCmd_setvar)                    @ 0x16
	.4byte MAYBE_MUTATING(ScrCmd_addvar)                    @ 0x17
	.4byte MAYBE_MUTATING(ScrCmd_subvar)                    @ 0x18
	.4byte MAYBE_MUTATING(ScrCmd_copyvar)                   @ 0x19
	.4byte MAYBE_MUTATING(ScrCmd_setorcopyvar)              @ 0x1a
	.4byte NOT_MUTATING(ScrCmd_compare_local_to_local)      @ 0x1b
	.4byte NOT_MUTATING(ScrCmd_compare_local_to_value)      @ 0x1c
	.4byte NOT_MUTATING(ScrCmd_compare_local_to_ptr)        @ 0x1d
	.4byte NOT_MUTATING(ScrCmd_compare_ptr_to_local)        @ 0x1e
	.4byte NOT_MUTATING(ScrCmd_compare_ptr_to_value)        @ 0x1f
	.4byte NOT_MUTATING(ScrCmd_compare_ptr_to_ptr)          @ 0x20
	.4byte NOT_MUTATING(ScrCmd_compare_var_to_value)        @ 0x21
	.4byte NOT_MUTATING(ScrCmd_compare_var_to_var)          @ 0x22
	.4byte MAYBE_MUTATING(ScrCmd_callnative)                @ 0x23
	.4byte MUTATING(ScrCmd_gotonative)                      @ 0x24
	.4byte MAYBE_MUTATING(ScrCmd_special)                   @ 0x25
	.4byte MAYBE_MUTATING(ScrCmd_specialvar)                @ 0x26
	.4byte MUTATING(ScrCmd_waitstate)                       @ 0x27
	.4byte MUTATING(ScrCmd_delay)                           @ 0x28
	.4byte MUTATING(ScrCmd_setflag)                         @ 0x29
	.4byte MUTATING(ScrCmd_clearflag)                       @ 0x2a
	.4byte NOT_MUTATING(ScrCmd_checkflag)                   @ 0x2b
	.4byte MUTATING(ScrCmd_initclock)                       @ 0x2c
	.4byte MUTATING(ScrCmd_dotimebasedevents)               @ 0x2d
	.4byte NOT_MUTATING(ScrCmd_gettime)                     @ 0x2e
	.4byte MUTATING(ScrCmd_playse)                          @ 0x2f
	.4byte MUTATING(ScrCmd_waitse)                          @ 0x30
	.4byte MUTATING(ScrCmd_playfanfare)                     @ 0x31
	.4byte MUTATING(ScrCmd_waitfanfare)                     @ 0x32
	.4byte MUTATING(ScrCmd_playbgm)                         @ 0x33
	.4byte MUTATING(ScrCmd_savebgm)                         @ 0x34
	.4byte MUTATING(ScrCmd_fadedefaultbgm)                  @ 0x35
	.4byte MUTATING(ScrCmd_fadenewbgm)                      @ 0x36
	.4byte MUTATING(ScrCmd_fadeoutbgm)                      @ 0x37
	.4byte MUTATING(ScrCmd_fadeinbgm)                       @ 0x38
	.4byte MUTATING(ScrCmd_warp)                            @ 0x39
	.4byte MUTATING(ScrCmd_warpsilent)                      @ 0x3a
	.4byte MUTATING(ScrCmd_warpdoor)                        @ 0x3b
	.4byte MUTATING(ScrCmd_warphole)                        @ 0x3c
	.4byte MUTATING(ScrCmd_warpteleport)                    @ 0x3d
	.4byte MUTATING(ScrCmd_setwarp)                         @ 0x3e
	.4byte MUTATING(ScrCmd_setdynamicwarp)                  @ 0x3f
	.4byte MUTATING(ScrCmd_setdivewarp)                     @ 0x40
	.4byte MUTATING(ScrCmd_setholewarp)                     @ 0x41
	.4byte MAYBE_MUTATING(ScrCmd_getplayerxy)               @ 0x42
	.4byte MAYBE_MUTATING(ScrCmd_getpartysize)              @ 0x43
	.4byte MUTATING(ScrCmd_additem)                         @ 0x44
	.4byte MUTATING(ScrCmd_removeitem)                      @ 0x45
	.4byte NOT_MUTATING(ScrCmd_checkitemspace)              @ 0x46
	.4byte NOT_MUTATING(ScrCmd_checkitem)                   @ 0x47
	.4byte NOT_MUTATING(ScrCmd_checkitemtype)               @ 0x48
	.4byte MUTATING(ScrCmd_addpcitem)                       @ 0x49
	.4byte NOT_MUTATING(ScrCmd_checkpcitem)                 @ 0x4a
	.4byte MUTATING(ScrCmd_adddecoration)                   @ 0x4b
	.4byte MUTATING(ScrCmd_removedecoration)                @ 0x4c
	.4byte NOT_MUTATING(ScrCmd_checkdecor)                  @ 0x4d
	.4byte NOT_MUTATING(ScrCmd_checkdecorspace)             @ 0x4e
	.4byte MUTATING(ScrCmd_applymovement)                   @ 0x4f
	.4byte MUTATING(ScrCmd_applymovementat)                 @ 0x50
	.4byte MUTATING(ScrCmd_waitmovement)                    @ 0x51
	.4byte MUTATING(ScrCmd_waitmovementat)                  @ 0x52
	.4byte MUTATING(ScrCmd_removeobject)                    @ 0x53
	.4byte MUTATING(ScrCmd_removeobjectat)                  @ 0x54
	.4byte MUTATING(ScrCmd_addobject)                       @ 0x55
	.4byte MUTATING(ScrCmd_addobjectat)                     @ 0x56
	.4byte MUTATING(ScrCmd_setobjectxy)                     @ 0x57
	.4byte MUTATING(ScrCmd_showobjectat)                    @ 0x58
	.4byte MUTATING(ScrCmd_hideobjectat)                    @ 0x59
	.4byte MUTATING(ScrCmd_faceplayer)                      @ 0x5a
	.4byte MUTATING(ScrCmd_turnobject)                      @ 0x5b
	.4byte MUTATING(ScrCmd_trainerbattle)                   @ 0x5c
	.4byte MUTATING(ScrCmd_dotrainerbattle)                 @ 0x5d
	.4byte MUTATING(ScrCmd_gotopostbattlescript)            @ 0x5e
	.4byte MUTATING(ScrCmd_gotobeatenscript)                @ 0x5f
	.4byte NOT_MUTATING(ScrCmd_checktrainerflag)            @ 0x60
	.4byte MUTATING(ScrCmd_settrainerflag)                  @ 0x61
	.4byte MUTATING(ScrCmd_cleartrainerflag)                @ 0x62
	.4byte MUTATING(ScrCmd_setobjectxyperm)                 @ 0x63
	.4byte MUTATING(ScrCmd_copyobjectxytoperm)              @ 0x64
	.4byte MUTATING(ScrCmd_setobjectmovementtype)           @ 0x65
	.4byte MUTATING(ScrCmd_waitmessage)                     @ 0x66
	.4byte MUTATING(ScrCmd_message)                         @ 0x67
	.4byte MUTATING(ScrCmd_closemessage)                    @ 0x68
	.4byte MAYBE_MUTATING(ScrCmd_lockall)                   @ 0x69
	.4byte MAYBE_MUTATING(ScrCmd_lock)                      @ 0x6a
	.4byte MAYBE_MUTATING(ScrCmd_releaseall)                @ 0x6b
	.4byte MAYBE_MUTATING(ScrCmd_release)                   @ 0x6c
	.4byte MUTATING(ScrCmd_waitbuttonpress)                 @ 0x6d
	.4byte MUTATING(ScrCmd_yesnobox)                        @ 0x6e
	.4byte MUTATING(ScrCmd_multichoice)                     @ 0x6f
	.4byte MUTATING(ScrCmd_multichoicedefault)              @ 0x70
	.4byte MUTATING(ScrCmd_multichoicegrid)                 @ 0x71
	.4byte MUTATING(ScrCmd_drawbox)                         @ 0x72
	.4byte MUTATING(ScrCmd_erasebox)                        @ 0x73
	.4byte MUTATING(ScrCmd_drawboxtext)                     @ 0x74
	.4byte MUTATING(ScrCmd_showmonpic)                      @ 0x75
	.4byte MUTATING(ScrCmd_hidemonpic)                      @ 0x76
	.4byte MUTATING(ScrCmd_showcontestpainting)             @ 0x77
	.4byte MUTATING(ScrCmd_braillemessage)                  @ 0x78
	.4byte MUTATING(ScrCmd_nop1)                            @ 0x79
	.4byte MUTATING(ScrCmd_giveegg)                         @ 0x7a
	.4byte MUTATING(ScrCmd_setmonmove)                      @ 0x7b
	.4byte NOT_MUTATING(ScrCmd_checkpartymove)              @ 0x7c
	.4byte NOT_MUTATING(ScrCmd_bufferspeciesname)           @ 0x7d
	.4byte MUTATING(ScrCmd_bufferleadmonspeciesname)        @ 0x7e
	.4byte NOT_MUTATING(ScrCmd_bufferpartymonnick)          @ 0x7f
	.4byte NOT_MUTATING(ScrCmd_bufferitemname)              @ 0x80
	.4byte NOT_MUTATING(ScrCmd_bufferdecorationname)        @ 0x81
	.4byte NOT_MUTATING(ScrCmd_buffermovename)              @ 0x82
	.4byte NOT_MUTATING(ScrCmd_buffernumberstring)          @ 0x83
	.4byte NOT_MUTATING(ScrCmd_bufferstdstring)             @ 0x84
	.4byte NOT_MUTATING(ScrCmd_bufferstring)                @ 0x85
	.4byte MUTATING(ScrCmd_pokemart)                        @ 0x86
	.4byte MUTATING(ScrCmd_pokemartdecoration)              @ 0x87
	.4byte MUTATING(ScrCmd_pokemartdecoration2)             @ 0x88
	.4byte MUTATING(ScrCmd_playslotmachine)                 @ 0x89
	.4byte MUTATING(ScrCmd_setberrytree)                    @ 0x8a
	.4byte MUTATING(ScrCmd_choosecontestmon)                @ 0x8b
	.4byte MUTATING(ScrCmd_startcontest)                    @ 0x8c
	.4byte MUTATING(ScrCmd_showcontestresults)              @ 0x8d
	.4byte MUTATING(ScrCmd_contestlinktransfer)             @ 0x8e
	.4byte NOT_MUTATING(ScrCmd_random)                      @ 0x8f
	.4byte MUTATING(ScrCmd_addmoney)                        @ 0x90
	.4byte MUTATING(ScrCmd_removemoney)                     @ 0x91
	.4byte NOT_MUTATING(ScrCmd_checkmoney)                  @ 0x92
	.4byte MUTATING(ScrCmd_showmoneybox)                    @ 0x93
	.4byte MUTATING(ScrCmd_hidemoneybox)                    @ 0x94
	.4byte MUTATING(ScrCmd_updatemoneybox)                  @ 0x95
	.4byte NOT_MUTATING(ScrCmd_getpokenewsactive)           @ 0x96
	.4byte MUTATING(ScrCmd_fadescreen)                      @ 0x97
	.4byte MUTATING(ScrCmd_fadescreenspeed)                 @ 0x98
	.4byte MUTATING(ScrCmd_setflashlevel)                   @ 0x99
	.4byte MUTATING(ScrCmd_animateflash)                    @ 0x9a
	.4byte MUTATING(ScrCmd_messageautoscroll)               @ 0x9b
	.4byte MUTATING(ScrCmd_dofieldeffect)                   @ 0x9c
	.4byte MUTATING(ScrCmd_setfieldeffectargument)          @ 0x9d
	.4byte MUTATING(ScrCmd_waitfieldeffect)                 @ 0x9e
	.4byte MUTATING(ScrCmd_setrespawn)                      @ 0x9f
	.4byte NOT_MUTATING(ScrCmd_checkplayergender)           @ 0xa0
	.4byte MUTATING(ScrCmd_playmoncry)                      @ 0xa1
	.4byte MUTATING(ScrCmd_setmetatile)                     @ 0xa2
	.4byte MUTATING(ScrCmd_resetweather)                    @ 0xa3
	.4byte MUTATING(ScrCmd_setweather)                      @ 0xa4
	.4byte MUTATING(ScrCmd_doweather)                       @ 0xa5
	.4byte MUTATING(ScrCmd_setstepcallback)                 @ 0xa6
	.4byte MUTATING(ScrCmd_setmaplayoutindex)               @ 0xa7
	.4byte MUTATING(ScrCmd_setobjectsubpriority)            @ 0xa8
	.4byte MUTATING(ScrCmd_resetobjectsubpriority)          @ 0xa9
	.4byte MUTATING(ScrCmd_createvobject)                   @ 0xaa
	.4byte MUTATING(ScrCmd_turnvobject)                     @ 0xab
	.4byte MUTATING(ScrCmd_opendoor)                        @ 0xac
	.4byte MUTATING(ScrCmd_closedoor)                       @ 0xad
	.4byte MUTATING(ScrCmd_waitdooranim)                    @ 0xae
	.4byte MUTATING(ScrCmd_setdooropen)                     @ 0xaf
	.4byte MUTATING(ScrCmd_setdoorclosed)                   @ 0xb0
	.4byte MUTATING(ScrCmd_addelevmenuitem)                 @ 0xb1
	.4byte MUTATING(ScrCmd_showelevmenu)                    @ 0xb2
	.4byte MAYBE_MUTATING(ScrCmd_checkcoins)                @ 0xb3
	.4byte MUTATING(ScrCmd_addcoins)                        @ 0xb4
	.4byte MUTATING(ScrCmd_removecoins)                     @ 0xb5
	.4byte MUTATING(ScrCmd_setwildbattle)                   @ 0xb6
	.4byte MUTATING(ScrCmd_dowildbattle)                    @ 0xb7
	.4byte MUTATING(ScrCmd_setvaddress)                     @ 0xb8
	.4byte NOT_MUTATING(ScrCmd_vgoto)                       @ 0xb9
	.4byte NOT_MUTATING(ScrCmd_vcall)                       @ 0xba
	.4byte NOT_MUTATING(ScrCmd_vgoto_if)                    @ 0xbb
	.4byte NOT_MUTATING(ScrCmd_vcall_if)                    @ 0xbc
	.4byte MUTATING(ScrCmd_vmessage)                        @ 0xbd
	.4byte NOT_MUTATING(ScrCmd_vbuffermessage)              @ 0xbe
	.4byte NOT_MUTATING(ScrCmd_vbufferstring)               @ 0xbf
	.4byte MUTATING(ScrCmd_showcoinsbox)                    @ 0xc0
	.4byte MUTATING(ScrCmd_hidecoinsbox)                    @ 0xc1
	.4byte MUTATING(ScrCmd_updatecoinsbox)                  @ 0xc2
	.4byte MUTATING(ScrCmd_incrementgamestat)               @ 0xc3
	.4byte MUTATING(ScrCmd_setescapewarp)                   @ 0xc4
	.4byte MUTATING(ScrCmd_waitmoncry)                      @ 0xc5
	.4byte NOT_MUTATING(ScrCmd_bufferboxname)               @ 0xc6
	.4byte NOT_MUTATING(ScrCmd_nop1)                        @ 0xc7
	.4byte NOT_MUTATING(ScrCmd_nop1)                        @ 0xc8
	.4byte NOT_MUTATING(ScrCmd_nop1)                        @ 0xc9
	.4byte NOT_MUTATING(ScrCmd_nop1)                        @ 0xca
	.4byte NOT_MUTATING(ScrCmd_nop1)                        @ 0xcb
	.4byte NOT_MUTATING(ScrCmd_nop1)                        @ 0xcc
	.4byte MUTATING(ScrCmd_setmodernfatefulencounter)       @ 0xcd
	.4byte NOT_MUTATING(ScrCmd_checkmodernfatefulencounter) @ 0xce
	.4byte MUTATING(ScrCmd_trywondercardscript)             @ 0xcf
	.4byte NOT_MUTATING(ScrCmd_nop1)                        @ 0xd0
	.4byte MUTATING(ScrCmd_warpspinenter)                   @ 0xd1
	.4byte MUTATING(ScrCmd_setmonmetlocation)               @ 0xd2
	.4byte MUTATING(ScrCmd_moverotatingtileobjects)         @ 0xd3
	.4byte MUTATING(ScrCmd_turnrotatingtileobjects)         @ 0xd4
	.4byte MUTATING(ScrCmd_initrotatingtilepuzzle)          @ 0xd5
	.4byte MUTATING(ScrCmd_freerotatingtilepuzzle)          @ 0xd6
	.4byte MUTATING(ScrCmd_warpmossdeepgym)                 @ 0xd7
	.4byte MUTATING(ScrCmd_selectapproachingtrainer)        @ 0xd8
	.4byte MUTATING(ScrCmd_lockfortrainer)                  @ 0xd9
	.4byte MUTATING(ScrCmd_closebraillemessage)             @ 0xda
	.4byte MUTATING(ScrCmd_messageinstant)                  @ 0xdb
	.4byte MUTATING(ScrCmd_fadescreenswapbuffers)           @ 0xdc
	.4byte NOT_MUTATING(ScrCmd_buffertrainerclassname)      @ 0xdd
	.4byte NOT_MUTATING(ScrCmd_buffertrainername)           @ 0xde
	.4byte MUTATING(ScrCmd_pokenavcall)                     @ 0xdf
	.4byte MUTATING(ScrCmd_warpwhitefade)                   @ 0xe0
	.4byte NOT_MUTATING(ScrCmd_buffercontestname)           @ 0xe1
	.4byte NOT_MUTATING(ScrCmd_bufferitemnameplural)        @ 0xe2
	.4byte MUTATING(ScrCmd_dynmultichoice)                  @ 0xe3
	.4byte MUTATING(ScrCmd_dynmultipush)                    @ 0xe4

gScriptCmdTableEnd::
	.4byte ScrCmd_nop

#undef MUTATING
#undef MAYBE_MUTATING
#undef NOT_MUTATING
