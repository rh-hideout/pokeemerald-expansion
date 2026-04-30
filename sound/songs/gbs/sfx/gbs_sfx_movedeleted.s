	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_MoveDeleted — 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_movedeleted_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 116
	volume 7, 7
	duty_cycle 2
	vibrato 12, 4, 4
	note_type 12, 10, 4
	rest 8
	octave 2
	note G_, 1
	rest 2
	note Cs, 1
	note E_, 1
	note Ds, 1
	note E_, 4
	volume_envelope 10, 1
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note Gs, 2
	note B_, 2
	volume_envelope 10, 6
	octave 3
	note D_, 10
	rest 6
	sound_ret

gbs_sfx_movedeleted_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 3
	vibrato 12, 4, 4
	note_type 12, 7, 4
	octave 1
	note B_, 1
	octave 2
	note D_, 1
	note F_, 1
	note Gs, 1
	volume_envelope 9, 4
	note D_, 1
	note F_, 1
	note Gs, 1
	note B_, 1
	volume_envelope 11, 4
	octave 3
	note Cs, 1
	rest 2
	octave 2
	note As, 1
	octave 3
	note Cs, 4
	rest 2
	volume_envelope 11, 1
	note Cs, 2
	note Ds, 2
	note E_, 2
	volume_envelope 11, 6
	note F_, 16
	rest 6
	sound_ret

gbs_sfx_movedeleted_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 6, 2, 5
	octave 2
	note Gs, 8
	note A_, 8
	note As, 2
	rest 4
	note As, 1
	rest 1
	note As, 8
	rest 4
	octave 3
	note Cs, 2
	rest 2
	note C_, 2
	rest 2
	octave 2
	note As, 2
	rest 2
	note_type 12, 2, 0
	note B_, 16
	rest 6
	sound_ret

gbs_sfx_movedeleted_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 3
	drum_speed 12
	note F_, 8
	rest 16
	rest 16
	rest 6
	sound_ret

	.align 4
	.global gbs_sfx_movedeleted_Header
gbs_sfx_movedeleted_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_movedeleted_Ch5
	.int gbs_sfx_movedeleted_Ch6
	.int gbs_sfx_movedeleted_Ch7
	.int gbs_sfx_movedeleted_Ch8
