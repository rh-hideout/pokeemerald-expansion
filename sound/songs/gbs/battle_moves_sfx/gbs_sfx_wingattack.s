	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_wingattack_Ch8:
	gbs_switch 7
gbs_sfx_wingattack_Ch8.loop:
	noise_note 8, 4, -7, 35
	noise_note 4, 12, 4, 34
	noise_note 6, 15, 2, 35
	sound_loop 4, gbs_sfx_wingattack_Ch8.loop
	sound_ret

	.align 4
	.global gbs_sfx_wingattack_Header
gbs_sfx_wingattack_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_wingattack_Ch8
