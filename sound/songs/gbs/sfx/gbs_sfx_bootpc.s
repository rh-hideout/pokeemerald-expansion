	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_bootpc_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 15, 15, 2, 1984
	square_note 15, 0, 0, 0
	square_note 3, 10, 1, 1920
	square_note 3, 10, 1, 1792
	square_note 3, 10, 1, 1856
	square_note 3, 10, 1, 1792
	square_note 3, 10, 1, 1920
	square_note 3, 10, 1, 1792
	square_note 3, 10, 1, 1984
	square_note 8, 10, 1, 1792
	sound_ret

	.align 4
	.global gbs_sfx_bootpc_Header
gbs_sfx_bootpc_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_bootpc_Ch5
