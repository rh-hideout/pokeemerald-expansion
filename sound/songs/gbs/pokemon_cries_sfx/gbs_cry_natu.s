	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch6 and Ch8 share labels with Sunflora in Crystal; data is identical.
gbs_cry_natu_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 1, 3, 2
	square_note 4, 15, 8, 1969
	square_note 4, 15, 8, 1968
	square_note 4, 4, 8, 1967
	square_note 4, 15, 8, 1970
	square_note 4, 15, 8, 1971
	square_note 4, 4, 8, 1972
	sound_ret

gbs_cry_natu_Ch6:
	gbs_switch 5
	duty_cycle_pattern 3, 3, 0, 2
	square_note 4, 15, 8, 1970
	square_note 4, 15, 8, 1969
	square_note 4, 2, 8, 1968
	square_note 4, 15, 8, 1972
	square_note 4, 15, 8, 1974
	square_note 4, 4, 8, 1976
	sound_ret

gbs_cry_natu_Ch8:
	gbs_switch 7
	noise_note 4, 8, 8, 5
	noise_note 4, 8, 8, 4
	noise_note 4, 3, 8, 3
	noise_note 4, 8, 8, 5
	noise_note 4, 8, 8, 4
	noise_note 4, 8, 7, 4
	sound_ret

	.align 4
	.global gbs_cry_natu_Header
gbs_cry_natu_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_natu_Ch5
	.int gbs_cry_natu_Ch6
	.int gbs_cry_natu_Ch8
