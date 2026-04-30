	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_tintower_Ch1:
	gbs_switch 0
	tempo 208
	volume 7, 7
	duty_cycle 3
	pitch_offset 4
	vibrato 8, 4, 5
gbs_tintower_Ch1.mainloop:
	stereo_panning TRUE, FALSE
	note_type 12, 10, 5
	octave 3
	note G_, 4
	note C_, 4
	note Gs, 8
	note G_, 4
	note C_, 4
	octave 2
	note As, 2
	octave 3
	note C_, 2
	note Cs, 2
	octave 2
	note As, 2
	octave 3
	note G_, 4
	note C_, 4
	note Gs, 4
	note F_, 4
	note G_, 4
	octave 2
	note G_, 4
	octave 3
	note G_, 6
	note As, 2
	note G_, 2
	note F_, 2
	note Cs, 2
	note G_, 2
	note Gs, 8
	note G_, 4
	octave 4
	note C_, 4
	octave 3
	note Gs, 2
	note G_, 2
	note F_, 2
	note Gs, 2
	note G_, 2
	note Cs, 2
	octave 2
	note As, 2
	octave 3
	note G_, 2
	note Gs, 4
	note F_, 4
	note G_, 4
	octave 2
	note G_, 4
	octave 3
	note G_, 8
	volume_envelope 10, 2
	octave 2
	note G_, 4
	note G_, 12
	note G_, 4
	note G_, 8
	volume_envelope 10, 7
	note G_, 4
	volume_envelope 10, 2
	note Gs, 4
	note Gs, 8
	volume_envelope 10, 7
	note G_, 4
	volume_envelope 10, 2
	note Gs, 4
	note Gs, 8
	volume_envelope 10, 7
	note As, 4
	volume_envelope 10, 2
	note G_, 4
	note G_, 12
	note G_, 4
	note G_, 12
	note G_, 4
	note G_, 12
	note G_, 4
	note G_, 8
	volume_envelope 10, 5
	octave 3
	note As, 4
	sound_loop 0, gbs_tintower_Ch1.mainloop

gbs_tintower_Ch2:
	gbs_switch 1
	duty_cycle 3
	pitch_offset 2
	vibrato 24, 4, 4
gbs_tintower_Ch2.mainloop:
	stereo_panning TRUE, TRUE
gbs_tintower_Ch2.loop1:
	note_type 12, 11, 5
	octave 4
	note C_, 4
	note C_, 4
	note Cs, 2
	note C_, 2
	octave 3
	note As, 2
	octave 4
	note Cs, 2
	note C_, 4
	note F_, 4
	note Cs, 4
	octave 3
	note As, 4
	octave 4
	note C_, 4
	note C_, 4
	note Cs, 2
	note C_, 2
	octave 3
	note As, 2
	octave 4
	note Cs, 2
	note C_, 4
	octave 3
	note C_, 4
	octave 4
	note C_, 8
	stereo_panning FALSE, TRUE
	sound_loop 2, gbs_tintower_Ch2.loop1
	volume_envelope 11, 2
	octave 3
	note C_, 4
	note C_, 12
	note C_, 4
	note C_, 8
	volume_envelope 11, 7
	note C_, 4
	volume_envelope 11, 2
	note Cs, 4
	note Cs, 8
	volume_envelope 11, 7
	note C_, 4
	volume_envelope 11, 2
	note Cs, 4
	note Cs, 8
	volume_envelope 11, 7
	note Ds, 4
	volume_envelope 9, 0
	stereo_panning TRUE, TRUE
	note G_, 4
	octave 4
	note C_, 4
	octave 3
	note As, 2
	note Gs, 2
	note G_, 2
	note Gs, 2
	note G_, 4
	note C_, 4
	note G_, 8
	note G_, 4
	octave 4
	note C_, 4
	octave 3
	note As, 2
	octave 4
	note C_, 2
	note Cs, 2
	octave 3
	note As, 2
	octave 4
	note C_, 4
	octave 3
	note C_, 4
	octave 4
	note C_, 6
	volume_envelope 9, 5
	note Cs, 2
	sound_loop 0, gbs_tintower_Ch2.mainloop

gbs_tintower_Ch3:
	gbs_switch 2
	note_type 12, 1, 4
gbs_tintower_Ch3.mainloop:
	rest 16
	rest 16
	rest 16
	rest 10
	octave 2
	note G_, 2
	note Gs, 2
	note As, 2
	octave 3
	note C_, 8
	note Cs, 8
	note E_, 8
	octave 2
	note As, 2
	octave 3
	note C_, 2
	note Cs, 2
	note Ds, 2
	note C_, 8
	note Cs, 8
	note E_, 8
	octave 4
	note C_, 8
	octave 3
	note C_, 1
	rest 3
	note C_, 1
	rest 11
	note C_, 1
	rest 3
	note C_, 1
	rest 7
	note C_, 4
	note Cs, 1
	rest 3
	note Cs, 1
	rest 7
	note C_, 4
	note Cs, 1
	rest 3
	note Cs, 1
	rest 7
	note Ds, 4
	stereo_panning FALSE, TRUE
	note C_, 1
	rest 3
	note C_, 1
	rest 11
	note C_, 1
	rest 3
	note C_, 1
	rest 3
	stereo_panning TRUE, TRUE
	octave 2
	note As, 2
	octave 3
	note C_, 2
	note Cs, 2
	note Ds, 2
	stereo_panning FALSE, TRUE
	note C_, 1
	rest 3
	note C_, 1
	rest 11
	note C_, 1
	rest 3
	note C_, 1
	rest 11
	stereo_panning TRUE, TRUE
	sound_loop 0, gbs_tintower_Ch3.mainloop

gbs_tintower_Ch4:
	gbs_switch 3
	toggle_noise 0
	drum_speed 12
gbs_tintower_Ch4.mainloop:
	stereo_panning FALSE, TRUE
	drum_note 8, 2
	stereo_panning TRUE, FALSE
	drum_note 8, 1
	drum_note 8, 1
	stereo_panning FALSE, TRUE
	drum_note 8, 2
	stereo_panning TRUE, FALSE
	drum_note 6, 4
	stereo_panning FALSE, TRUE
	drum_note 8, 2
	drum_note 8, 2
	drum_note 6, 2
	stereo_panning TRUE, FALSE
	drum_note 8, 2
	stereo_panning FALSE, TRUE
	drum_note 8, 1
	drum_note 8, 1
	stereo_panning TRUE, FALSE
	drum_note 8, 2
	stereo_panning FALSE, TRUE
	drum_note 6, 4
	stereo_panning TRUE, FALSE
	drum_note 8, 2
	drum_note 8, 2
	drum_note 6, 2
	sound_loop 0, gbs_tintower_Ch4.mainloop

	.align 4
	.global gbs_tintower_Header
gbs_tintower_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_tintower_Ch1
	.int gbs_tintower_Ch2
	.int gbs_tintower_Ch3
	.int gbs_tintower_Ch4
