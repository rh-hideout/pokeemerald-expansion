	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_gettm_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 144
	volume 7, 7
	duty_cycle 3
	vibrato 8, 2, 4
	note_type 12, 10, 3
	octave 4
	note D_, 1
	rest 1
	octave 3
	note B_, 1
	octave 4
	note D_, 1
	note G_, 6
	volume_envelope 11, 1
	note E_, 2
	note Fs, 2
	note G_, 2
	volume_envelope 10, 5
	note Fs, 8
	sound_ret

	toggle_sfx @ unused

gbs_sfx_gettm_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 3
	vibrato 8, 2, 4
	note_type 12, 11, 3
	octave 4
	note G_, 1
	rest 1
	note D_, 1
	note G_, 1
	note B_, 6
	volume_envelope 12, 1
	note A_, 2
	note B_, 2
	octave 5
	note C_, 2
	volume_envelope 11, 5
	note D_, 8
	sound_ret

	toggle_sfx @ unused

gbs_sfx_gettm_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 6, 2, 5
	octave 2
	note B_, 2
	rest 2
	note G_, 2
	note B_, 2
	octave 3
	note D_, 4
	octave 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 4
	octave 3
	note C_, 2
	rest 2
	octave 2
	note B_, 2
	rest 2
	octave 3
	note C_, 4
	octave 2
	note A_, 16
	sound_ret

	toggle_sfx @ unused

gbs_sfx_gettm_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 6
	note D_, 4
	note Cs, 2
	note D_, 2
	note B_, 8
	note D_, 4
	note Cs, 4
	note D_, 4
	note Cs, 1
	note Cs, 1
	note D_, 2
	note B_, 16
	sound_ret

	toggle_sfx @ unused

	.align 4
	.global gbs_sfx_gettm_Header
gbs_sfx_gettm_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_gettm_Ch5
	.int gbs_sfx_gettm_Ch6
	.int gbs_sfx_gettm_Ch7
	.int gbs_sfx_gettm_Ch8
