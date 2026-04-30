	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_unknown5f_Ch5:
	gbs_switch 4
gbs_sfx_unknown5f_Ch5.loop:
	square_note 2, 15, 7, 1537
	square_note 2, 15, 7, 1793
	sound_loop 8, gbs_sfx_unknown5f_Ch5.loop
	sound_ret

gbs_sfx_unknown5f_Ch6:
	gbs_switch 5
	square_note 1, 15, 7, 65535
	square_note 2, 15, 7, 1538
	square_note 2, 15, 7, 1794
	sound_loop 8, gbs_sfx_unknown5f_Ch5.loop
	sound_ret

gbs_sfx_unknown5f_Ch8:
	gbs_switch 7
gbs_sfx_unknown5f_Ch8.loop:
	noise_note 1, 15, 8, 65
	noise_note 2, 9, -4, 36
	noise_note 0, 0, 0, 0
	noise_note 3, 5, -1, 22
	noise_note 2, 0, 0, 0
	sound_loop 3, gbs_sfx_unknown5f_Ch8.loop
	sound_ret

	.align 4
	.global gbs_sfx_unknown5f_Header
gbs_sfx_unknown5f_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_unknown5f_Ch5
	.int gbs_sfx_unknown5f_Ch6
	.int gbs_sfx_unknown5f_Ch8
