	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_healpokemon_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	duty_cycle 2
	pitch_offset 1
	note_type 12, 8, 1
	rest 2
	pitch_slide 1, 4, B_
	note B_, 2
	pitch_slide 1, 3, E_
	note B_, 2
	pitch_slide 1, 4, E_
	note E_, 2
	rest 4
	pitch_slide 1, 5, B_
	note E_, 4
	pitch_slide 1, 4, B_
	note B_, 4
	sound_ret

gbs_healpokemon_Ch2:
	gbs_switch 1
	duty_cycle 2
	note_type 12, 12, 3
	octave 4
	note B_, 4
	note B_, 4
	note B_, 2
	note Gs, 2
	note_type 12, 12, 4
	octave 5
	note E_, 8
	sound_ret

gbs_healpokemon_Ch3:
	gbs_switch 2
	note_type 12, 1, 0
	octave 4
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note E_, 2
	note Gs, 2
	note E_, 6
	rest 2
	sound_ret

	.align 4
	.global gbs_healpokemon_Header
gbs_healpokemon_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_healpokemon_Ch1
	.int gbs_healpokemon_Ch2
	.int gbs_healpokemon_Ch3
