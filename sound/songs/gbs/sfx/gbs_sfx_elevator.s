	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_elevator_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 5, -2
gbs_sfx_elevator_Ch5.loop:
	square_note 2, 15, 1, 768
	sound_loop 48, gbs_sfx_elevator_Ch5.loop
	pitch_sweep 0, 8
	duty_cycle 2
	square_note 15, 15, 3, 1840
	square_note 8, 6, 5, 1840
	square_note 15, 15, 4, 1792
	square_note 15, 7, 4, 1792
	square_note 15, 4, 4, 1792
	square_note 15, 2, 4, 1792
	sound_ret

gbs_sfx_elevator_Ch6:
	gbs_switch 5
	square_note 96, 0, 0, 0
	square_note 83, 0, 0, 0
	sound_ret

gbs_sfx_elevator_Ch7:
	gbs_switch 6
	square_note 96, 0, 0, 0
	square_note 83, 0, 0, 0
	sound_ret

gbs_sfx_elevator_Ch8:
	gbs_switch 7
	noise_note 96, 0, 0, 0
	noise_note 83, 0, 0, 0
	sound_ret

	.align 4
	.global gbs_sfx_elevator_Header
gbs_sfx_elevator_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_elevator_Ch5
	.int gbs_sfx_elevator_Ch6
	.int gbs_sfx_elevator_Ch7
	.int gbs_sfx_elevator_Ch8
