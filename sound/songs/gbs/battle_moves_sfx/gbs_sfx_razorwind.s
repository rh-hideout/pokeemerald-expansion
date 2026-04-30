	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_razorwind_Ch8:
	gbs_switch 7
	noise_note 2, 15, 4, 68
	noise_note 2, 15, 4, 20
	noise_note 15, 15, 1, 50
	sound_ret

	.align 4
	.global gbs_sfx_razorwind_Header
gbs_sfx_razorwind_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_razorwind_Ch8
