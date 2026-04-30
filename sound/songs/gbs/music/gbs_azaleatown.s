	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_azaleatown_Ch1:
	gbs_switch 0
	tempo 160
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	note_type 12, 10, 1
	rest 2
gbs_azaleatown_Ch1.introloop:
	volume_envelope 10, 1
	octave 3
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	note F_, 2
	volume_envelope 10, 1
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	note F_, 2
	note F_, 2
	note F_, 2
	sound_loop 2, gbs_azaleatown_Ch1.introloop
gbs_azaleatown_Ch1.mainloop:
	sound_call gbs_azaleatown_Ch1.sub1
	stereo_panning TRUE, FALSE
	volume_envelope 10, 4
	note Gs, 2
	note As, 1
	rest 3
	octave 4
	note C_, 4
	note_type 6, 10, 4
	note G_, 1
	note Gs, 3
	note Fs, 4
	note Ds, 2
	rest 2
	stereo_panning FALSE, TRUE
	sound_call gbs_azaleatown_Ch1.sub1
	stereo_panning TRUE, FALSE
	note_type 6, 10, 4
	note Ds, 4
	note C_, 4
	rest 3
	note B_, 1
	octave 4
	note C_, 12
	octave 3
	note As, 4
	note Fs, 4
	stereo_panning FALSE, TRUE
	sound_call gbs_azaleatown_Ch1.sub2
	volume_envelope 10, 3
	note As, 4
	octave 4
	note Cs, 2
	rest 2
	note C_, 2
	rest 2
	volume_envelope 10, 1
	octave 3
	note Cs, 4
	note A_, 2
	rest 14
	sound_call gbs_azaleatown_Ch1.sub2
	volume_envelope 10, 3
	octave 4
	note C_, 1
	note Cs, 3
	note F_, 2
	rest 2
	note Cs, 2
	rest 2
	volume_envelope 10, 1
	octave 3
	note G_, 4
	note As, 4
	note G_, 8
	volume_envelope 10, 2
	note As, 4
	octave 4
	note Cs, 4
	octave 3
	note As, 4
	note Fs, 4
	note Cs, 8
	note Fs, 4
	rest 4
	note As, 4
	octave 4
	note Cs, 4
	octave 3
	note As, 4
	note G_, 4
	note Cs, 4
	rest 4
	note G_, 4
	rest 4
	octave 4
	note Cs, 4
	note Ds, 4
	note Cs, 4
	octave 3
	note Gs, 4
	note Ds, 4
	note Cs, 4
	octave 2
	note Gs, 4
	rest 8
	note_type 12, 2, -7
	octave 3
	note Gs, 14
	rest 2
	sound_loop 0, gbs_azaleatown_Ch1.mainloop

gbs_azaleatown_Ch1.sub1:
	note_type 12, 10, 1
	octave 4
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	note F_, 2
	volume_envelope 10, 1
	note Ds, 2
	volume_envelope 6, 1
	note Ds, 2
	note Ds, 2
	volume_envelope 10, 1
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	volume_envelope 10, 1
	note As, 2
	volume_envelope 6, 1
	note As, 2
	note As, 2
	volume_envelope 10, 1
	note Gs, 2
	volume_envelope 6, 1
	note Gs, 2
	note Gs, 2
	volume_envelope 10, 1
	note A_, 2
	volume_envelope 6, 1
	note A_, 2
	volume_envelope 10, 1
	note C_, 2
	volume_envelope 6, 1
	note C_, 2
	note C_, 2
	volume_envelope 10, 1
	note Cs, 2
	volume_envelope 6, 1
	note Cs, 2
	note Cs, 2
	note Cs, 2
	note Cs, 2
	volume_envelope 10, 1
	note Ds, 2
	volume_envelope 6, 1
	note Ds, 2
	note Ds, 2
	volume_envelope 10, 1
	note Cs, 2
	volume_envelope 6, 1
	note Cs, 2
	note Cs, 2
	note Cs, 2
	rest 2
	volume_envelope 10, 1
	octave 3
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	note F_, 2
	volume_envelope 10, 1
	note Fs, 2
	volume_envelope 6, 1
	note Fs, 2
	note Fs, 2
	note Fs, 2
	note Fs, 2
	volume_envelope 10, 1
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	note F_, 2
	volume_envelope 10, 1
	note Ds, 2
	volume_envelope 6, 1
	note Ds, 2
	note Ds, 2
	volume_envelope 10, 1
	note Cs, 2
	volume_envelope 6, 1
	note Cs, 2
	volume_envelope 10, 1
	note C_, 2
	volume_envelope 6, 1
	note C_, 2
	note C_, 2
	volume_envelope 10, 1
	octave 2
	note As, 2
	volume_envelope 6, 1
	note As, 2
	note As, 2
	volume_envelope 10, 1
	octave 3
	note Cs, 2
	volume_envelope 6, 1
	note Cs, 2
	sound_ret

gbs_azaleatown_Ch1.sub2:
	volume_envelope 6, 1
	note Gs, 8
	note Gs, 8
	volume_envelope 8, 1
	note A_, 8
	volume_envelope 10, 1
	note A_, 8
	sound_ret

gbs_azaleatown_Ch2:
	gbs_switch 1
	vibrato 18, 2, 3
	duty_cycle 2
	stereo_panning TRUE, FALSE
	note_type 12, 6, 2
	rest 1
	octave 4
	note D_, 1
	volume_envelope 11, 1
	note Ds, 2
	volume_envelope 7, 1
	note Ds, 2
	note Ds, 2
	volume_envelope 11, 1
	note Cs, 2
	volume_envelope 7, 1
	note Cs, 2
	note Cs, 2
	volume_envelope 5, 1
	note Cs, 2
	note Cs, 2
	volume_envelope 11, 1
	note C_, 2
	volume_envelope 7, 1
	note C_, 2
	note C_, 2
	volume_envelope 11, 1
	note Cs, 2
	volume_envelope 7, 1
	note Cs, 2
	note Cs, 2
	note_type 6, 11, 4
	note F_, 7
	duty_cycle 1
	octave 5
	note C_, 1
gbs_azaleatown_Ch2.mainloop:
	sound_call gbs_azaleatown_Ch2.sub1
	note Cs, 4
	note C_, 2
	note Cs, 1
	rest 3
	note_type 6, 11, 4
	note Ds, 11
	rest 8
	duty_cycle 1
	octave 5
	note C_, 1
	sound_call gbs_azaleatown_Ch2.sub1
	rest 2
	note Cs, 2
	note C_, 2
	octave 3
	note Gs, 2
	note_type 6, 11, 4
	rest 3
	octave 4
	note G_, 1
	note Gs, 12
	note Fs, 4
	note F_, 4
	duty_cycle 0
	note D_, 1
	note Ds, 3
	note Cs, 4
	note C_, 2
	rest 2
	note Gs, 4
	rest 4
	note Fs, 4
	rest 4
	note F_, 4
	note Ds, 4
	note F_, 2
	rest 2
	note Ds, 2
	rest 2
	note Cs, 8
	rest 12
	note D_, 1
	note Ds, 3
	note Cs, 4
	note C_, 2
	rest 2
	note Gs, 4
	rest 4
	note A_, 4
	rest 4
	octave 5
	note C_, 4
	octave 4
	note B_, 1
	octave 5
	note C_, 3
	note Cs, 2
	rest 2
	note C_, 2
	rest 2
	octave 4
	note F_, 4
	rest 4
	note Ds, 4
	rest 4
	note Cs, 4
	duty_cycle 2
	note F_, 4
	note Ds, 4
	note Cs, 4
	note F_, 4
	rest 4
	note Ds, 4
	rest 4
	note Cs, 4
	note F_, 4
	note Ds, 4
	note Cs, 4
	note F_, 4
	rest 4
	note As, 4
	rest 4
	octave 5
	note C_, 4
	note_type 12, 11, 7
	octave 4
	note Gs, 12
	note Ds, 4
	volume_envelope 1, -7
	note C_, 14
	note_type 6, 11, 4
	duty_cycle 1
	note Gs, 2
	octave 5
	note C_, 2
	sound_loop 0, gbs_azaleatown_Ch2.mainloop

gbs_azaleatown_Ch2.sub1:
	note Cs, 4
	octave 4
	note Gs, 2
	rest 2
	octave 5
	note C_, 2
	rest 2
	note Cs, 8
	note Ds, 8
	note F_, 2
	rest 1
	note G_, 1
	note Gs, 12
	note F_, 2
	rest 6
	note Ds, 8
	note F_, 2
	rest 1
	note C_, 1
	note_type 12, 10, 8
	vibrato 0, 0, 0
	note Cs, 8
	volume_envelope 10, 7
	vibrato 18, 2, 3
	note Cs, 16
	rest 4
	volume_envelope 11, 4
	duty_cycle 2
	octave 3
	note As, 2
	octave 4
	note Cs, 1
	rest 1
	note Fs, 8
	rest 2
	note Fs, 2
	note F_, 2
	note Ds, 1
	rest 1
	note Cs, 6
	note C_, 2
	rest 2
	note C_, 4
	note Cs, 1
	note_type 6, 11, 4
	rest 1
	note D_, 1
	note_type 12, 11, 7
	note Ds, 12
	volume_envelope 11, 4
	sound_ret

gbs_azaleatown_Ch3:
	gbs_switch 2
	stereo_panning TRUE, TRUE
	vibrato 6, 2, 6
	note_type 12, 2, 5
	octave 2
	note Gs, 1
	octave 3
	note C_, 1
	note Cs, 1
	rest 5
	note Cs, 1
	rest 3
	note Cs, 1
	rest 1
	octave 2
	note Gs, 4
	octave 3
	note Cs, 1
	rest 5
	note Cs, 1
	rest 3
	note Cs, 1
	rest 1
	note Gs, 4
gbs_azaleatown_Ch3.mainloop:
	sound_call gbs_azaleatown_Ch3.sub1
	note Gs, 4
	note Ds, 2
	sound_call gbs_azaleatown_Ch3.sub1
	note Gs, 2
	rest 2
	note Fs, 2
	sound_call gbs_azaleatown_Ch3.sub2
	note As, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note F_, 2
	octave 3
	note A_, 4
	octave 4
	note Cs, 1
	rest 3
	note F_, 1
	rest 1
	sound_call gbs_azaleatown_Ch3.sub2
	octave 2
	note As, 2
	octave 3
	note F_, 1
	rest 1
	note As, 1
	rest 1
	note Ds, 2
	octave 2
	note As, 2
	octave 3
	note Ds, 1
	rest 3
	note G_, 2
	octave 2
	note Fs, 1
	rest 5
	note Fs, 1
	note Fs, 1
	note Fs, 1
	rest 1
	octave 3
	note Cs, 2
	rest 2
	octave 2
	note F_, 1
	note Fs, 1
	note G_, 1
	rest 5
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	octave 3
	note Cs, 2
	rest 2
	octave 2
	note Fs, 1
	note G_, 1
	note Gs, 1
	rest 5
	note Gs, 1
	note Gs, 1
	note Gs, 1
	rest 1
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note Fs, 1
	note G_, 1
	note Gs, 1
	rest 5
	note Gs, 1
	note Gs, 1
	note Gs, 1
	rest 1
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note B_, 1
	octave 3
	note C_, 1
	sound_loop 0, gbs_azaleatown_Ch3.mainloop

gbs_azaleatown_Ch3.sub1:
	note Cs, 1
	rest 5
	note Cs, 1
	rest 3
	note Cs, 1
	rest 1
	octave 2
	note Gs, 4
	octave 3
	note F_, 1
	rest 5
	note F_, 1
	rest 1
	note C_, 1
	rest 1
	note F_, 4
	note A_, 2
	volume_envelope 1, 5
	note As, 1
	rest 1
	volume_envelope 2, 5
	octave 4
	note Cs, 1
	rest 1
	note F_, 1
	rest 1
	octave 3
	note A_, 4
	octave 4
	note Cs, 1
	rest 1
	note F_, 1
	rest 1
	octave 3
	note Gs, 4
	note As, 1
	rest 1
	note Gs, 1
	rest 1
	note G_, 6
	rest 4
	note Fs, 1
	rest 5
	note Fs, 1
	rest 3
	note Fs, 1
	rest 1
	note Cs, 4
	note G_, 1
	rest 5
	note G_, 1
	rest 3
	note Cs, 4
	note G_, 1
	rest 1
	note Gs, 1
	rest 5
	note Gs, 1
	rest 1
	note Ds, 1
	rest 1
	note Cs, 4
	note Gs, 1
	rest 1
	note Gs, 1
	rest 5
	note Gs, 1
	rest 1
	note C_, 1
	rest 1
	sound_ret

gbs_azaleatown_Ch3.sub2:
	volume_envelope 3, 5
	octave 3
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	volume_envelope 2, 5
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	sound_ret

gbs_azaleatown_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	drum_note 6, 2
gbs_azaleatown_Ch4.mainloop:
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 4, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 4, 2
	drum_note 3, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 4, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 4, 2
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 0, gbs_azaleatown_Ch4.mainloop

	.align 4
	.global gbs_azaleatown_Header
gbs_azaleatown_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_azaleatown_Ch1
	.int gbs_azaleatown_Ch2
	.int gbs_azaleatown_Ch3
	.int gbs_azaleatown_Ch4
