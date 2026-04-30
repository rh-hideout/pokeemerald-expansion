	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_peck_Ch8:
	gbs_switch 7
	noise_note 2, 10, 1, 18
	sound_ret

	.align 4
	.global gbs_sfx_peck_Header
gbs_sfx_peck_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_peck_Ch8
