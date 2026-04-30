	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_nidoran_f_Ch5:
	gbs_switch 4
	duty_cycle_pattern 2, 2, 0, 0
	square_note 4, 15, 3, 1536
	square_note 8, 13, 5, 1888
	square_note 3, 14, 2, 1824
	square_note 8, 13, 1, 1808
	sound_ret

gbs_cry_nidoran_f_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 1, 2, 2
	square_note 5, 11, 3, 1777
	square_note 7, 12, 5, 1874
	square_note 3, 10, 2, 1809
	square_note 8, 11, 1, 1537
	sound_ret

gbs_cry_nidoran_f_Ch8:
	gbs_switch 7
	noise_note 3, 10, 2, 60
	noise_note 12, 9, 4, 44
	noise_note 3, 8, 2, 28
	noise_note 8, 7, 1, 44
	sound_ret

	.align 4
	.global gbs_cry_nidoran_f_Header
gbs_cry_nidoran_f_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_nidoran_f_Ch5
	.int gbs_cry_nidoran_f_Ch6
	.int gbs_cry_nidoran_f_Ch8
