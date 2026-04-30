	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 sets duty cycle then plays inline Mareep Ch6 body data (cross-cry jump inlined).
@ Ch8 data is shared with Cyndaquil in Crystal; duplicated here.
gbs_cry_gligar_Ch5:
	gbs_switch 4
	duty_cycle_pattern 2, 2, 0, 2
	@ Inlined from Mareep_Ch6 body
	square_note 4, 3, -2, 1853
	square_note 6, 15, 8, 1890
	square_note 6, 15, 8, 1888
	square_note 6, 15, 1, 1886
	sound_ret

gbs_cry_gligar_Ch8:
	gbs_switch 7
	noise_note 8, 3, -7, 82
	noise_note 32, 9, 3, 79
	sound_ret

	.align 4
	.global gbs_cry_gligar_Header
gbs_cry_gligar_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_gligar_Ch5
	.int gbs_cry_gligar_Ch8
