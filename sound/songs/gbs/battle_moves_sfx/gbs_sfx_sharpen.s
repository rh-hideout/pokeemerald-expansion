	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_sharpen_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 6, 15, 1, 1280
	square_note 6, 15, 1, 1408
	square_note 6, 15, 1, 1536
	square_note 6, 15, 1, 1664
	square_note 8, 15, 1, 1792
	sound_ret

gbs_sfx_sharpen_Ch6:
	gbs_switch 5
	duty_cycle 3
	square_note 6, 14, 1, 1296
	square_note 6, 14, 1, 1424
	square_note 6, 14, 1, 1552
	square_note 6, 14, 1, 1680
	square_note 8, 14, 1, 1808
	sound_ret

	.align 4
	.global gbs_sfx_sharpen_Header
gbs_sfx_sharpen_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_sharpen_Ch5
	.int gbs_sfx_sharpen_Ch6
