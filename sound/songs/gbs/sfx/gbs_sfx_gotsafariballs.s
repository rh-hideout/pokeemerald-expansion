	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_gotsafariballs_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 1, 5
	square_note 15, 15, 0, 1264
	square_note 15, 15, 2, 1616
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_gotsafariballs_Header
gbs_sfx_gotsafariballs_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_gotsafariballs_Ch5
