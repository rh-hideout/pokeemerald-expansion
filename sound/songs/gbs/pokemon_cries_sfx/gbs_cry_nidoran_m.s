	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_nidoran_m_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 1, 1
	square_note 4, 15, 3, 1816
	square_note 15, 14, 5, 1944
	square_note 8, 9, 1, 1880
	sound_ret

gbs_cry_nidoran_m_Ch6:
	gbs_switch 5
	duty_cycle_pattern 2, 2, 0, 0
	square_note 5, 11, 3, 1800
	square_note 15, 12, 5, 1928
	square_note 8, 7, 1, 1864
	sound_ret

gbs_cry_nidoran_m_Ch8:
	gbs_switch 7
	noise_note 3, 10, 1, 28
	noise_note 14, 9, 4, 44
	noise_note 8, 8, 1, 28
	sound_ret

	.align 4
	.global gbs_cry_nidoran_m_Header
gbs_cry_nidoran_m_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_nidoran_m_Ch5
	.int gbs_cry_nidoran_m_Ch6
	.int gbs_cry_nidoran_m_Ch8
