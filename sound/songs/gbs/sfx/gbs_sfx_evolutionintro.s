	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_evolutionintro_Ch1:
	gbs_switch 0
	tempo 132
	volume 7, 7
	vibrato 6, 3, 4
	pitch_offset 1
	duty_cycle 2
	note_type 12, 9, 2
	octave 3
	pitch_slide 1, 4, A_
	note C_, 1
	pitch_slide 1, 4, A_
	note G_, 1
	pitch_slide 1, 4, A_
	note C_, 1
	pitch_slide 1, 4, A_
	note G_, 1
	sound_ret

gbs_sfx_evolutionintro_Ch2:
	gbs_switch 1
	duty_cycle 2
	vibrato 8, 2, 5
	note_type 12, 10, 2
	octave 4
	note G_, 1
	note D_, 1
	note G_, 1
	note D_, 1
	sound_ret

	.align 4
	.global gbs_sfx_evolutionintro_Header
gbs_sfx_evolutionintro_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_evolutionintro_Ch1
	.int gbs_sfx_evolutionintro_Ch2
