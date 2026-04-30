	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_beatup_Ch8:
	gbs_switch 7
	noise_note 2, 14, 8, 105
	noise_note 6, 13, 8, 36
	noise_note 2, 14, 8, 108
	noise_note 4, 12, 8, 70
	noise_note 6, 13, 1, 36
	sound_ret

	.align 4
	.global gbs_sfx_beatup_Header
gbs_sfx_beatup_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_beatup_Ch8
