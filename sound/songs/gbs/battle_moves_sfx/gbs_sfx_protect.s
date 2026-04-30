	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_protect_Ch5:
	gbs_switch 4
	toggle_sfx
	note_type 1, 15, 1
	duty_cycle 0
gbs_sfx_protect_Ch5.loop:
	octave 5
	note F_, 5
	note A_, 5
	octave 6
	note C_, 5
	note E_, 5
	octave 5
	note Fs, 5
	note As, 5
	octave 6
	note Cs, 5
	note E_, 5
	sound_loop 3, gbs_sfx_protect_Ch5.loop
	volume_envelope 12, 1
	note F_, 5
	note A_, 5
	volume_envelope 9, 1
	note C_, 5
	note E_, 5
	volume_envelope 7, 1
	note Fs, 5
	note As, 5
	volume_envelope 5, 1
	note Cs, 5
	note E_, 5
	toggle_sfx
	sound_ret

gbs_sfx_protect_Ch8:
	gbs_switch 7
gbs_sfx_protect_Ch8.loop:
	noise_note 9, 9, -6, 0
	noise_note 9, 11, -6, 17
	sound_loop 6, gbs_sfx_protect_Ch8.loop
	noise_note 9, 10, 7, 0
	noise_note 16, 7, 5, 17
	sound_ret

	.align 4
	.global gbs_sfx_protect_Header
gbs_sfx_protect_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_protect_Ch5
	.int gbs_sfx_protect_Ch8
