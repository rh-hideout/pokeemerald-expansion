	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_getbadge_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 120
	volume 7, 7
	duty_cycle 2
	vibrato 8, 2, 4
	note_type 6, 9, 2
	octave 4
	note F_, 3
	sound_call gbs_sfx_getbadge_Ch5.sub1
	note As, 3
	transpose 0, 2
	sound_call gbs_sfx_getbadge_Ch5.sub1
	transpose 0, 0
	volume_envelope 10, 7
	note A_, 16
	rest 6
	sound_ret

	toggle_sfx @ unused

gbs_sfx_getbadge_Ch5.sub1:
	rest 5
	octave 3
	note F_, 2
	note Gs, 2
	octave 4
	note Cs, 2
	note F_, 2
	note Cs, 2
	octave 3
	note F_, 2
	note Gs, 2
	octave 4
	note Cs, 2
	octave 3
	note F_, 2
	note Gs, 2
	octave 4
	note Cs, 2
	note F_, 2
	sound_ret

gbs_sfx_getbadge_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 3
	vibrato 8, 2, 4
	note_type 6, 11, 5
	octave 5
	note Cs, 3
	rest 3
	octave 4
	note Gs, 1
	rest 1
	note Gs, 8
	octave 3
	note Cs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 1
	volume_envelope 9, 5
	octave 5
	note C_, 1
	volume_envelope 11, 5
	note Cs, 2
	rest 2
	note D_, 2
	rest 2
	note Ds, 3
	rest 3
	octave 4
	note As, 1
	rest 1
	note As, 8
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note As, 2
	rest 1
	volume_envelope 9, 5
	octave 5
	note D_, 1
	volume_envelope 11, 5
	note Ds, 8
	note F_, 16
	rest 6
	sound_ret

	toggle_sfx @ unused

gbs_sfx_getbadge_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 6, 2, 5
	octave 2
	note Gs, 3
	rest 3
	octave 3
	note Cs, 1
	rest 1
	note Cs, 8
	note Gs, 2
	rest 2
	note F_, 2
	rest 2
	note Cs, 2
	note C_, 2
	octave 2
	note As, 2
	note Gs, 2
	note G_, 3
	rest 3
	octave 3
	note Ds, 1
	rest 1
	note Ds, 8
	note As, 2
	rest 2
	note G_, 2
	rest 2
	note G_, 2
	note F_, 2
	note G_, 2
	note Ds, 2
	note F_, 16
	rest 6
	sound_ret

	toggle_sfx @ unused

gbs_sfx_getbadge_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 6
gbs_sfx_getbadge_Ch8.loop1:
	note B_, 12
	note D_, 1
	note D_, 1
	note D_, 2
	note D_, 4
	note D_, 4
	note D_, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	sound_loop 2, gbs_sfx_getbadge_Ch8.loop1
	note B_, 16
	rest 6
	sound_ret

	toggle_sfx @ unused

	.align 4
	.global gbs_sfx_getbadge_Header
gbs_sfx_getbadge_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_getbadge_Ch5
	.int gbs_sfx_getbadge_Ch6
	.int gbs_sfx_getbadge_Ch7
	.int gbs_sfx_getbadge_Ch8
