    .include "asm/macros.inc"

    .section .rodata
    .align 1

@ Sfx_1stPlace — 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_1stplace_Ch5:
    gbs_switch 4
    toggle_sfx
    tempo 124
    volume 7, 7
	duty_cycle 3
	vibrato 12, 3, 4
	note_type 12, 10, 1
	octave 5
	note D_, 2
	octave 4
	note B_, 2
	octave 5
	note D_, 2
	note As, 1
	note F_, 1
	note D_, 1
	note F_, 1
	volume_envelope 9, 1
	note D_, 1
	octave 4
	note As, 1
	note F_, 1
	note As, 1
	volume_envelope 8, 1
	octave 5
	note D_, 1
	octave 4
	note As, 1
	note F_, 1
	note D_, 1
	volume_envelope 10, 1
	note C_, 2
	note E_, 2
	note G_, 2
	volume_envelope 10, 7
	note A_, 10
	rest 6
	sound_ret

gbs_sfx_1stplace_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 3
	vibrato 12, 3, 4
	note_type 12, 12, 1
	octave 3
	note B_, 2
	note G_, 2
	note B_, 2
    volume_envelope 11, 6
	octave 4
	note D_, 12
	volume_envelope 12, 1
	note E_, 2
	note G_, 2
	octave 5
	note C_, 2
	volume_envelope 11, 7
	note D_, 10
	rest 6
	sound_ret

gbs_sfx_1stplace_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 12, 2, 5
    octave 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note As, 6
	note F_, 6
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note D_, 10
	rest 6
	sound_ret

gbs_sfx_1stplace_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 6
	note D_, 4
	note D_, 4
	note D_, 4
	note B_, 12
	note B_, 10
	note Cs, 1
	note Cs, 1
	note D_, 4
	note D_, 4
	note D_, 4
	drum_speed 12
	note B_, 10
	rest 6
	sound_ret

	.align 4
	.global gbs_sfx_1stplace_Header
gbs_sfx_1stplace_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_1stplace_Ch5
    .int gbs_sfx_1stplace_Ch6
	.int gbs_sfx_1stplace_Ch7
	.int gbs_sfx_1stplace_Ch8
