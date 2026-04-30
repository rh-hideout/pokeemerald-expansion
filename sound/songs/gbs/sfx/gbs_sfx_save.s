	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_save_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 2, 15, 1, 1792
	square_note 1, 14, 1, 1536
	square_note 1, 14, 1, 1664
	square_note 1, 14, 1, 1728
	square_note 2, 14, 1, 1792
	square_note 2, 14, 1, 1984
	square_note 15, 15, 2, 2016
	sound_ret

gbs_sfx_save_Ch6:
	gbs_switch 5
	duty_cycle 2
	square_note 2, 0, 8, 0
	square_note 2, 10, 1, 1793
	square_note 1, 9, 1, 1537
	square_note 1, 9, 1, 1665
	square_note 1, 9, 1, 1729
	square_note 2, 9, 1, 1793
	square_note 2, 9, 1, 1985
	square_note 15, 13, 2, 2017
	sound_ret

	.align 4
	.global gbs_sfx_save_Header
gbs_sfx_save_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_save_Ch5
	.int gbs_sfx_save_Ch6
