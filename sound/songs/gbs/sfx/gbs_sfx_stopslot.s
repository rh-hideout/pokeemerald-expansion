	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_stopslot_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 1, 15, 8, 1888
	square_note 4, 8, 2, 1888
	sound_ret

	.align 4
	.global gbs_sfx_stopslot_Header
gbs_sfx_stopslot_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_stopslot_Ch5
