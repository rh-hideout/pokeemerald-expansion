	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_metronome_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 5, -7
	square_note 4, 4, 0, 2016
	square_note 4, 6, 0, 2016
	square_note 4, 8, 0, 2016
	square_note 8, 10, 0, 2016
	square_note 8, 10, 0, 2016
	square_note 8, 8, 0, 2016
	square_note 8, 6, 0, 2016
	square_note 8, 3, 0, 2016
	square_note 15, 1, 2, 2016
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_metronome_Header
gbs_sfx_metronome_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_metronome_Ch5
