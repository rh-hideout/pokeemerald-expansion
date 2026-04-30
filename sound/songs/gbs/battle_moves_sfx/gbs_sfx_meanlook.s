	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_meanlook_Ch5:
	gbs_switch 4
	pitch_sweep 7, 7
	duty_cycle 3
	square_note 2, 15, 8, 1824
gbs_sfx_meanlook_Ch5.loop:
	square_note 1, 8, 8, 1632
	square_note 2, 15, 8, 1936
	sound_loop 5, gbs_sfx_meanlook_Ch5.loop
	square_note 12, 15, 8, 1792
	square_note 12, 12, 8, 1824
	square_note 12, 10, 8, 1792
	square_note 12, 7, 8, 1824
	square_note 12, 4, 8, 1792
	square_note 12, 2, 8, 1824
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_meanlook_Header
gbs_sfx_meanlook_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_meanlook_Ch5
