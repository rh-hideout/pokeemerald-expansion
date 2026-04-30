	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_elevatorend_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 15, 15, 3, 1840
	square_note 8, 6, 5, 1840
	square_note 15, 15, 4, 1792
	square_note 15, 7, 4, 1792
	square_note 15, 4, 4, 1792
	square_note 15, 2, 4, 1792
	sound_ret

	.align 4
	.global gbs_sfx_elevatorend_Header
gbs_sfx_elevatorend_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_elevatorend_Ch5
