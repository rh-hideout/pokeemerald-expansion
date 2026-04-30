	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_zapcannon_Ch8:
	gbs_switch 7
gbs_sfx_zapcannon_Ch8.loop:
	noise_note 2, 14, 1, 73
	noise_note 0, 0, 0, 0
	sound_loop 8, gbs_sfx_zapcannon_Ch8.loop
	noise_note 8, 14, 1, 73
	sound_ret

	.align 4
	.global gbs_sfx_zapcannon_Header
gbs_sfx_zapcannon_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_zapcannon_Ch8
