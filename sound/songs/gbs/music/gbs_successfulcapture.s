	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_successfulcapture_Ch1:
	gbs_switch 0
	tempo 126
	volume 7, 7
	duty_cycle 3
	pitch_offset 1
	note_type 12, 10, 1
	sound_jump gbs_wildpokemonvictory_Ch1.body

gbs_successfulcapture_Ch2:
	gbs_switch 1
	vibrato 18, 2, 4
	note_type 12, 12, 1
	duty_cycle 2
	sound_jump gbs_wildpokemonvictory_Ch2.body

gbs_successfulcapture_Ch3:
	gbs_switch 2
	note_type 12, 2, 5
	sound_jump gbs_wildpokemonvictory_Ch3.body

	.align 4
	.global gbs_successfulcapture_Header
gbs_successfulcapture_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_successfulcapture_Ch1
	.int gbs_successfulcapture_Ch2
	.int gbs_successfulcapture_Ch3
