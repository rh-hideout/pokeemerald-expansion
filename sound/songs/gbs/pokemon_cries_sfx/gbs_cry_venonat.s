	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_venonat_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 6, 15, 7, 1856
	square_note 12, 14, 6, 1860
	square_note 6, 13, 5, 1872
	square_note 4, 12, 3, 1888
	square_note 3, 12, 3, 1920
	square_note 8, 13, 1, 1952
	sound_ret

gbs_cry_venonat_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 0, 2, 2
	square_note 6, 12, 7, 1793
	square_note 11, 11, 6, 1794
	square_note 6, 10, 5, 1809
	square_note 4, 9, 3, 1825
	square_note 3, 10, 3, 1857
	square_note 8, 9, 1, 1890
	sound_ret

gbs_cry_venonat_Ch8:
	gbs_switch 7
	noise_note 3, 14, 2, 60
	noise_note 8, 13, 6, 76
	noise_note 5, 13, 4, 60
	noise_note 12, 12, 7, 76
	noise_note 2, 14, 2, 60
	noise_note 8, 13, 1, 44
	sound_ret

	.align 4
	.global gbs_cry_venonat_Header
gbs_cry_venonat_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_venonat_Ch5
	.int gbs_cry_venonat_Ch6
	.int gbs_cry_venonat_Ch8
