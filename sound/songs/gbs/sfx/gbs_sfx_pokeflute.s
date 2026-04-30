	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_pokeflute_Ch7:
	gbs_switch 6
	tempo 256
	volume 7, 7
	toggle_sfx
	vibrato 16, 1, 4
	note_type 12, 1, 0
	octave 5
	note E_, 2
	note F_, 2
	note G_, 4
	note A_, 2
	note G_, 2
	octave 6
	note C_, 4
	note C_, 2
	note D_, 2
	note C_, 2
	octave 5
	note G_, 2
	note A_, 2
	note F_, 2
	note G_, 8
	rest 12
	sound_ret

	.align 4
	.global gbs_sfx_pokeflute_Header
gbs_sfx_pokeflute_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_pokeflute_Ch7
