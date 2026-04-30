	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_raindance_Ch8:
	gbs_switch 7
gbs_sfx_raindance_Ch8.loop:
	noise_note 11, 7, -5, 80
	noise_note 6, 7, -5, 79
	noise_note 11, 7, -7, 71
	noise_note 15, 6, -6, 34
	sound_loop 3, gbs_sfx_raindance_Ch8.loop
	noise_note 6, 6, -5, 80
	noise_note 5, 5, -5, 79
	noise_note 5, 4, -7, 71
	noise_note 10, 3, 2, 70
	sound_ret

	.align 4
	.global gbs_sfx_raindance_Header
gbs_sfx_raindance_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_raindance_Ch8
