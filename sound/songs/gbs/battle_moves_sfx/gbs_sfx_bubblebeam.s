	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_bubblebeam_Ch5:
	gbs_switch 4
gbs_sfx_bubblebeam_Ch5.loop:
	duty_cycle_pattern 0, 3, 2, 1
	square_note 4, 15, 4, 1536
	square_note 3, 12, 4, 1280
	square_note 5, 11, 5, 1536
	square_note 13, 14, 2, 1728
	sound_loop 3, gbs_sfx_bubblebeam_Ch5.loop
	square_note 8, 13, 1, 1536
	sound_ret

gbs_sfx_bubblebeam_Ch6:
	gbs_switch 5
gbs_sfx_bubblebeam_Ch6.loop:
	duty_cycle_pattern 2, 0, 3, 1
	square_note 5, 14, 4, 1504
	square_note 4, 11, 4, 1248
	square_note 6, 10, 5, 1512
	square_note 14, 13, 1, 1696
	sound_loop 3, gbs_sfx_bubblebeam_Ch6.loop
	sound_ret

gbs_sfx_bubblebeam_Ch8:
	gbs_switch 7
gbs_sfx_bubblebeam_Ch8.loop:
	noise_note 5, 12, 3, 51
	noise_note 3, 9, 2, 67
	noise_note 10, 11, 5, 51
	noise_note 15, 12, 3, 50
	sound_loop 2, gbs_sfx_bubblebeam_Ch8.loop
	sound_ret

	.align 4
	.global gbs_sfx_bubblebeam_Header
gbs_sfx_bubblebeam_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_bubblebeam_Ch5
	.int gbs_sfx_bubblebeam_Ch6
	.int gbs_sfx_bubblebeam_Ch8
