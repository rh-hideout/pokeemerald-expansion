	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_magnettrain_Ch1:
	gbs_switch 0
	tempo 110
	volume 7, 7
	stereo_panning FALSE, TRUE
	vibrato 20, 2, 3
	duty_cycle 2
	note_type 12, 11, 2
	rest 16
	rest 16
	volume_envelope 11, 7
	octave 4
	note D_, 1
	note C_, 1
	octave 3
	note G_, 1
	octave 4
	note C_, 1
	note D_, 1
	note C_, 1
	octave 3
	note G_, 1
	octave 4
	note C_, 1
	note D_, 1
	note C_, 1
	octave 3
	note G_, 1
	octave 4
	note C_, 1
	note D_, 1
	note C_, 1
	octave 3
	note G_, 1
	octave 4
	note C_, 1
	note E_, 1
	note C_, 1
	octave 3
	note A_, 1
	octave 4
	note C_, 1
	note E_, 1
	note C_, 1
	octave 3
	note A_, 1
	octave 4
	note C_, 1
	note E_, 1
	note C_, 1
	octave 3
	note A_, 1
	octave 4
	note C_, 1
	note E_, 1
	note C_, 1
	note_type 6, 11, 7
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note_type 12, 11, 7
	note D_, 16
	sound_ret

gbs_magnettrain_Ch2:
	gbs_switch 1
	vibrato 20, 2, 3
	duty_cycle 1
	note_type 12, 13, 2
	stereo_panning TRUE, FALSE
	note_type 12, 13, 8
	octave 1
	note F_, 12
	rest 2
	note_type 6, 13, 7
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	octave 2
	note F_, 4
	rest 4
	note F_, 4
	rest 4
	note F_, 4
	rest 4
	note F_, 4
	rest 4
	duty_cycle 3
	note_type 12, 13, 7
	octave 4
	note G_, 16
	note A_, 13
	rest 1
	note_type 6, 13, 7
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note_type 12, 13, 7
	note A_, 16
	sound_ret

gbs_magnettrain_Ch3:
	gbs_switch 2
	stereo_panning TRUE, TRUE
	vibrato 16, 2, 3
	note_type 12, 1, 5
	octave 6
	note C_, 1
	octave 5
	note G_, 1
	note Ds, 1
	note C_, 1
	note G_, 1
	note Ds, 1
	note C_, 1
	octave 4
	note G_, 1
	octave 5
	note Ds, 1
	note C_, 1
	octave 4
	note G_, 1
	note Ds, 1
	octave 5
	note C_, 1
	octave 4
	note G_, 1
	note Ds, 1
	note C_, 1
	note G_, 1
	note Ds, 1
	note C_, 1
	octave 3
	note G_, 1
	octave 4
	note C_, 1
	note Ds, 1
	note G_, 1
	note C_, 1
	note Ds, 1
	note G_, 1
	octave 5
	note C_, 1
	octave 4
	note G_, 1
	octave 5
	note C_, 1
	note Ds, 1
	note G_, 1
	note C_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	octave 2
	note D_, 16
	sound_ret

gbs_magnettrain_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	drum_note 12, 12
	drum_note 3, 2
	drum_note 11, 1
	drum_note 11, 1
	drum_speed 6
	drum_note 4, 4
	drum_note 7, 4
	drum_note 4, 4
	drum_note 7, 4
	drum_note 11, 4
	drum_note 7, 4
	drum_note 11, 4
	drum_note 3, 2
	drum_note 3, 2
	sound_call gbs_magnettrain_Ch4.sub2
	sound_call gbs_magnettrain_Ch4.sub2
	drum_speed 12
	drum_note 12, 16
	sound_ret

gbs_magnettrain_Ch4.sub1: @ unreferenced:
	drum_note 9, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 9, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 9, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 9, 1
	drum_note 8, 1
	drum_note 8, 1
	sound_ret

gbs_magnettrain_Ch4.sub2:
	drum_note 9, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 9, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 9, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 9, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 8, 2
	sound_ret

	.align 4
	.global gbs_magnettrain_Header
gbs_magnettrain_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_magnettrain_Ch1
	.int gbs_magnettrain_Ch2
	.int gbs_magnettrain_Ch3
	.int gbs_magnettrain_Ch4
