	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_darkcave_Ch1:
	gbs_switch 0
	tempo 128
	volume 7, 7
	duty_cycle 3
	pitch_offset 1
	vibrato 17, 1, 5
	stereo_panning TRUE, FALSE
	note_type 12, 10, 7
gbs_darkcave_Ch1.loop1:
	rest 16
	sound_loop 4, gbs_darkcave_Ch1.loop1
	octave 3
	note Ds, 16
	note D_, 16
	note Cs, 16
	note C_, 16
	volume_envelope 10, 3
gbs_darkcave_Ch1.mainloop:
gbs_darkcave_Ch1.loop2:
	sound_call gbs_darkcave_Ch1.sub1
	sound_loop 3, gbs_darkcave_Ch1.loop2
	volume_envelope 11, 7
	note Gs, 8
	note Ds, 8
	note G_, 8
	note D_, 8
	note F_, 8
	note Cs, 8
	note Ds, 8
	note G_, 8
	note Gs, 8
	note Ds, 8
	note G_, 8
	note D_, 8
	note F_, 8
	note Cs, 8
	note Ds, 8
	note C_, 8
	volume_envelope 10, 3
gbs_darkcave_Ch1.loop3:
	sound_call gbs_darkcave_Ch1.sub1
	sound_loop 2, gbs_darkcave_Ch1.loop3
	rest 16
	rest 8
	volume_envelope 11, 7
	octave 2
	note F_, 2
	note G_, 2
	note Gs, 4
	octave 3
	note Ds, 16
	rest 8
	octave 2
	note Gs, 2
	note G_, 2
	note Gs, 4
	octave 3
	note Ds, 16
	note G_, 2
	rest 6
	note F_, 2
	note G_, 2
	note Gs, 4
	note G_, 16
	note F_, 2
	rest 6
	note Gs, 2
	note G_, 2
	note Gs, 4
	volume_envelope 10, 3
gbs_darkcave_Ch1.loop4:
	sound_call gbs_darkcave_Ch1.sub1
	sound_loop 2, gbs_darkcave_Ch1.loop4
	sound_loop 0, gbs_darkcave_Ch1.mainloop

gbs_darkcave_Ch1.sub1:
	octave 4
	note Ds, 2
	octave 3
	note Gs, 2
	octave 4
	note C_, 2
	note Ds, 2
	octave 3
	note Gs, 2
	octave 4
	note C_, 2
	note Ds, 2
	note C_, 2
	note D_, 2
	octave 3
	note G_, 2
	note As, 2
	octave 4
	note D_, 2
	octave 3
	note G_, 2
	note As, 2
	octave 4
	note D_, 2
	octave 3
	note As, 2
	octave 4
	note Cs, 2
	octave 3
	note F_, 2
	note As, 2
	octave 4
	note Cs, 2
	octave 3
	note F_, 2
	note As, 2
	octave 4
	note Cs, 2
	octave 3
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note As, 2
	sound_ret

gbs_darkcave_Ch2:
	gbs_switch 1
	duty_cycle 1
	vibrato 18, 3, 6
	stereo_panning FALSE, TRUE
	note_type 12, 10, 7
gbs_darkcave_Ch2.loop1:
	rest 16
	sound_loop 4, gbs_darkcave_Ch2.loop1
	octave 3
	note G_, 16
	note As, 16
	note F_, 16
	note G_, 16
gbs_darkcave_Ch2.mainloop:
gbs_darkcave_Ch2.loop2:
	rest 16
	sound_loop 4, gbs_darkcave_Ch2.loop2
	rest 8
	stereo_panning TRUE, TRUE
	volume_envelope 12, 7
	octave 5
	note C_, 8
	volume_envelope 12, 4
	note D_, 2
	note C_, 2
	octave 4
	note As, 2
	note G_, 4
	note As, 2
	octave 5
	note D_, 4
	volume_envelope 11, 0
	note Cs, 4
	volume_envelope 11, 7
	note Cs, 12
	volume_envelope 5, -1
	note C_, 8
	volume_envelope 12, 7
	note C_, 8
	rest 8
	volume_envelope 12, 7
	note C_, 8
	volume_envelope 12, 4
	note D_, 2
	note C_, 2
	octave 4
	note As, 2
	note G_, 2
	note G_, 2
	note As, 2
	octave 5
	note D_, 4
	volume_envelope 12, 7
	note Cs, 12
	volume_envelope 12, 3
	note C_, 2
	note Cs, 2
	volume_envelope 11, 0
	note Ds, 10
	volume_envelope 11, 7
	note Ds, 6
	stereo_panning FALSE, TRUE
	volume_envelope 12, 4
	octave 4
	note F_, 4
	note Ds, 2
	note D_, 2
	note Ds, 4
	note D_, 2
	note C_, 2
	note D_, 2
	note C_, 2
	octave 3
	note As, 2
	octave 4
	note C_, 2
	note D_, 4
	note C_, 2
	octave 3
	note As, 2
	octave 4
	note Cs, 8
	octave 3
	note As, 8
	volume_envelope 11, 0
	octave 4
	note Ds, 2
	note D_, 2
	note C_, 2
	octave 3
	note As, 2
	octave 4
	note C_, 8
	note F_, 4
	note Ds, 2
	note D_, 2
	note Ds, 4
	note D_, 2
	note C_, 2
	note D_, 2
	note C_, 2
	octave 3
	note As, 2
	octave 4
	note C_, 2
	note D_, 4
	note C_, 2
	octave 3
	note As, 2
	octave 4
	note Cs, 4
	note C_, 2
	note Cs, 2
	note C_, 2
	note Cs, 2
	octave 3
	note As, 2
	octave 4
	note Cs, 2
	volume_envelope 11, 0
	note C_, 8
	volume_envelope 11, 7
	note C_, 8
	volume_envelope 12, 7
	stereo_panning TRUE, TRUE
	rest 8
	octave 5
	note C_, 8
	volume_envelope 12, 4
	note D_, 2
	note C_, 2
	octave 4
	note As, 2
	note G_, 4
	note As, 2
	octave 5
	note D_, 4
	volume_envelope 4, -1
	note Cs, 8
	volume_envelope 12, 7
	note Cs, 8
	volume_envelope 11, 0
	note C_, 8
	volume_envelope 11, 7
	note C_, 8
	rest 8
	volume_envelope 12, 7
	note C_, 8
	volume_envelope 12, 4
	note D_, 2
	note C_, 2
	octave 4
	note As, 2
	note G_, 2
	note G_, 2
	note As, 2
	octave 5
	note D_, 4
	volume_envelope 11, 0
	note Cs, 8
	volume_envelope 11, 7
	note Cs, 8
	volume_envelope 11, 0
	note C_, 8
	volume_envelope 11, 7
	note C_, 8
	volume_envelope 12, 7
	rest 16
	stereo_panning FALSE, TRUE
	rest 8
	octave 3
	note As, 2
	octave 4
	note C_, 2
	note Cs, 4
	note C_, 16
	rest 8
	note Cs, 2
	note C_, 2
	note Cs, 4
	note C_, 16
	volume_envelope 12, 2
	note Ds, 8
	volume_envelope 12, 7
	octave 3
	note As, 2
	octave 4
	note C_, 2
	note Cs, 4
	note C_, 16
	volume_envelope 12, 2
	octave 3
	note As, 8
	volume_envelope 12, 7
	octave 4
	note Cs, 2
	note C_, 2
	volume_envelope 12, 4
	note Cs, 16
	rest 4
	rest 16
	rest 16
	rest 16
	volume_envelope 11, 7
	octave 5
	note Ds, 16
	note D_, 16
	note F_, 16
	note Ds, 16
	sound_loop 0, gbs_darkcave_Ch2.mainloop

gbs_darkcave_Ch3:
	gbs_switch 2
	note_type 12, 2, 7
gbs_darkcave_Ch3.loop1:
	sound_call gbs_darkcave_Ch3.sub3
	sound_loop 2, gbs_darkcave_Ch3.loop1
gbs_darkcave_Ch3.mainloop:
gbs_darkcave_Ch3.loop2:
	sound_call gbs_darkcave_Ch3.sub3
	sound_loop 7, gbs_darkcave_Ch3.loop2
	sound_call gbs_darkcave_Ch3.sub2
	octave 3
	note C_, 4
	note G_, 2
	note Ds, 4
	note G_, 2
	note Ds, 4
	note F_, 2
	rest 2
	octave 2
	note As, 12
	sound_call gbs_darkcave_Ch3.sub2
	octave 3
	note C_, 4
	note G_, 2
	note Ds, 4
	note G_, 2
	note Ds, 4
	note F_, 2
	rest 2
	octave 2
	note As, 4
	octave 3
	note Cs, 2
	note C_, 2
	note Cs, 4
	sound_call gbs_darkcave_Ch3.sub1
	sound_call gbs_darkcave_Ch3.sub1
	sound_loop 0, gbs_darkcave_Ch3.mainloop

gbs_darkcave_Ch3.sub1:
	octave 3
	note C_, 4
	note G_, 2
	note Ds, 4
	note G_, 2
	note F_, 4
	note Ds, 2
	rest 2
	octave 2
	note As, 4
	note As, 2
	octave 3
	note C_, 2
	note Cs, 4
	note C_, 4
	note G_, 2
	note Ds, 4
	note G_, 2
	note Ds, 4
	note F_, 2
	rest 2
	octave 2
	note As, 4
	octave 3
	note Cs, 2
	note C_, 2
	note Cs, 4
	sound_ret

gbs_darkcave_Ch3.sub2:
	octave 3
	note C_, 4
	note G_, 2
	note Ds, 4
	note G_, 2
	note F_, 4
	note Ds, 2
	rest 2
	octave 2
	note As, 12
	sound_ret

gbs_darkcave_Ch3.sub3:
	octave 2
	note C_, 4
	note G_, 2
	note Ds, 4
	note G_, 2
	note F_, 4
	note Ds, 2
	rest 2
	octave 1
	note As, 4
	note As, 2
	octave 2
	note C_, 2
	note Cs, 4
	note C_, 4
	note G_, 2
	note Ds, 4
	note G_, 2
	note Ds, 4
	note F_, 2
	rest 2
	octave 1
	note As, 4
	octave 2
	note Cs, 2
	note C_, 2
	note Cs, 4
	sound_ret

gbs_darkcave_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
gbs_darkcave_Ch4.mainloop:
	stereo_panning TRUE, TRUE
	drum_note 4, 8
	drum_note 4, 8
	drum_note 4, 4
	stereo_panning TRUE, FALSE
	drum_note 2, 4
	stereo_panning FALSE, TRUE
	drum_note 2, 2
	drum_note 2, 2
	stereo_panning TRUE, FALSE
	drum_note 2, 4
	stereo_panning TRUE, TRUE
	drum_note 4, 8
	drum_note 4, 8
	drum_note 4, 4
	stereo_panning FALSE, TRUE
	drum_note 2, 8
	stereo_panning TRUE, FALSE
	drum_note 2, 2
	drum_note 2, 2
	sound_loop 0, gbs_darkcave_Ch4.mainloop

	.align 4
	.global gbs_darkcave_Header
gbs_darkcave_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_darkcave_Ch1
	.int gbs_darkcave_Ch2
	.int gbs_darkcave_Ch3
	.int gbs_darkcave_Ch4
