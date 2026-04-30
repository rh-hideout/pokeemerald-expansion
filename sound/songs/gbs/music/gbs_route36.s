	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_route36_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	duty_cycle 3
	pitch_offset 1
	vibrato 16, 1, 5
	stereo_panning FALSE, TRUE
	note_type 12, 11, 3
	octave 3
	note C_, 4
	note C_, 6
	note F_, 1
	note E_, 1
	volume_envelope 11, 5
	note F_, 8
	volume_envelope 11, 3
	note F_, 6
	note As, 1
	note A_, 1
	volume_envelope 5, -5
	note As, 4
gbs_route36_Ch1.mainloop:
	volume_envelope 11, 5
	note F_, 4
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note F_, 2
	note A_, 2
	note Ds, 2
	note As, 4
	note A_, 4
	note G_, 2
	note As, 4
	note F_, 4
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note F_, 2
	note A_, 2
	note G_, 2
	note As, 4
	note A_, 4
	octave 4
	note Ds, 4
	octave 3
	note As, 2
	volume_envelope 11, 6
	octave 4
	note F_, 10
	volume_envelope 11, 5
	note C_, 2
	note F_, 2
	note C_, 2
	octave 3
	note As, 2
	octave 4
	note Ds, 4
	note D_, 4
	note C_, 2
	octave 3
	note As, 4
	volume_envelope 11, 4
	note A_, 2
	octave 4
	note D_, 2
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note D_, 2
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note D_, 2
	volume_envelope 10, 4
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	note Fs, 2
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	note Fs, 2
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	stereo_panning TRUE, FALSE
	volume_envelope 9, 5
	octave 3
	note D_, 6
	octave 2
	note A_, 6
	octave 3
	note D_, 4
	octave 2
	note A_, 6
	octave 3
	note D_, 6
	note E_, 4
	volume_envelope 11, 5
	note D_, 6
	note A_, 6
	note G_, 4
	volume_envelope 10, 5
	octave 2
	note A_, 6
	octave 3
	note Fs, 6
	note E_, 4
	note D_, 6
	octave 2
	note A_, 6
	octave 3
	note D_, 4
	volume_envelope 11, 5
	note Fs, 6
	note E_, 6
	note Cs, 4
	note D_, 6
	note A_, 6
	note G_, 4
	octave 2
	note A_, 6
	octave 3
	note Fs, 6
	note D_, 4
	note C_, 6
	note G_, 6
	note C_, 2
	note E_, 2
	volume_envelope 11, 7
	note C_, 6
	note G_, 4
	note D_, 2
	note E_, 2
	note G_, 2
	note A_, 2
	note Gs, 2
	note A_, 2
	octave 4
	note D_, 6
	note C_, 2
	octave 3
	note B_, 2
	note A_, 6
	note D_, 6
	stereo_panning FALSE, TRUE
	volume_envelope 11, 5
	note Ds, 2
	note E_, 2
	sound_loop 0, gbs_route36_Ch1.mainloop

gbs_route36_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 16, 3, 6
	stereo_panning TRUE, FALSE
	note_type 12, 12, 2
	octave 3
	note F_, 2
	note C_, 1
	note F_, 1
	volume_envelope 12, 7
	note A_, 8
	note C_, 4
	volume_envelope 12, 3
	octave 4
	note C_, 2
	octave 3
	note A_, 1
	octave 4
	note C_, 1
	volume_envelope 12, 7
	note F_, 8
	octave 3
	note G_, 4
gbs_route36_Ch2.mainloop:
	volume_envelope 12, 7
	octave 4
	note C_, 10
	volume_envelope 12, 4
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	note A_, 2
	note G_, 3
	volume_envelope 12, 2
	note Ds, 1
	volume_envelope 12, 7
	note Ds, 12
	note C_, 10
	volume_envelope 12, 4
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	note F_, 2
	volume_envelope 12, 2
	note Ds, 2
	note Ds, 1
	note F_, 1
	volume_envelope 12, 7
	note G_, 12
	note A_, 10
	volume_envelope 12, 4
	note F_, 2
	note A_, 2
	octave 5
	note C_, 2
	octave 4
	note As, 3
	note A_, 1
	volume_envelope 12, 7
	note G_, 8
	note As, 4
	volume_envelope 11, 0
	note A_, 16
	volume_envelope 11, 7
	note A_, 16
	stereo_panning FALSE, TRUE
	volume_envelope 10, 4
	octave 3
	note A_, 6
	note G_, 6
	note Fs, 4
	note E_, 6
	note Fs, 6
	note G_, 4
	volume_envelope 11, 3
	note A_, 2
	note Fs, 1
	note A_, 1
	volume_envelope 11, 7
	octave 4
	note D_, 12
	volume_envelope 10, 4
	octave 3
	note Fs, 2
	note D_, 1
	note Fs, 1
	volume_envelope 10, 7
	note A_, 12
	volume_envelope 12, 7
	note A_, 6
	note G_, 6
	note Fs, 4
	note B_, 6
	note A_, 6
	note G_, 4
	volume_envelope 12, 3
	note A_, 2
	note Fs, 1
	note A_, 1
	volume_envelope 12, 7
	octave 4
	note D_, 12
	volume_envelope 12, 3
	octave 3
	note Fs, 2
	note D_, 1
	note Fs, 1
	volume_envelope 12, 7
	note A_, 12
	volume_envelope 12, 2
	note G_, 2
	note E_, 1
	note G_, 1
	volume_envelope 11, 0
	octave 4
	note C_, 2
	volume_envelope 11, 7
	note C_, 10
	volume_envelope 12, 5
	octave 3
	note G_, 2
	note E_, 1
	note G_, 1
	volume_envelope 12, 7
	octave 4
	note C_, 8
	note Cs, 4
	stereo_panning TRUE, TRUE
	note D_, 6
	note A_, 6
	note G_, 2
	note Fs, 2
	volume_envelope 11, 0
	note D_, 4
	volume_envelope 11, 7
	note D_, 8
	stereo_panning TRUE, FALSE
	volume_envelope 12, 4
	octave 3
	note Fs, 1
	note G_, 1
	note A_, 1
	note B_, 1
	sound_loop 0, gbs_route36_Ch2.mainloop

gbs_route36_Ch3:
	gbs_switch 2
	note_type 12, 2, 5
	octave 3
	note F_, 1
	rest 3
	note F_, 1
	rest 1
	octave 4
	note C_, 4
	octave 3
	note C_, 2
	note F_, 2
	note C_, 2
	note Ds, 1
	rest 3
	note Ds, 1
	rest 1
	octave 4
	note F_, 4
	octave 2
	note As, 2
	octave 3
	note Ds, 2
	note E_, 2
gbs_route36_Ch3.mainloop:
	note F_, 4
	note C_, 2
	note F_, 4
	note C_, 2
	note F_, 2
	note C_, 2
	note G_, 4
	note Ds, 2
	note G_, 4
	note Ds, 2
	note G_, 2
	note Ds, 2
	note F_, 4
	note C_, 2
	note F_, 4
	note C_, 2
	note F_, 2
	note C_, 2
	note G_, 4
	note Ds, 2
	note G_, 4
	note Ds, 2
	note G_, 2
	note Ds, 2
	note A_, 4
	note F_, 2
	note A_, 4
	note F_, 2
	note A_, 2
	note F_, 2
	note As, 4
	note G_, 2
	note As, 4
	note G_, 2
	note As, 2
	note G_, 2
	note Fs, 4
	note D_, 2
	note Fs, 4
	note D_, 2
	note Fs, 2
	note D_, 2
	note D_, 4
	octave 2
	note A_, 2
	octave 3
	note D_, 4
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note Fs, 4
	note D_, 2
	note Fs, 4
	note D_, 2
	note Fs, 2
	note D_, 2
	note G_, 4
	note E_, 2
	note G_, 4
	note E_, 2
	note G_, 2
	note E_, 2
	note Fs, 4
	note D_, 2
	note Fs, 4
	note D_, 2
	note Fs, 2
	note D_, 2
	note Fs, 4
	note D_, 2
	note Fs, 4
	note D_, 2
	note E_, 2
	note A_, 2
	note Fs, 4
	note D_, 2
	note Fs, 4
	note D_, 2
	note Fs, 2
	note D_, 2
	note G_, 4
	note E_, 2
	note G_, 4
	note E_, 2
	note G_, 2
	note E_, 2
	note Fs, 4
	note D_, 2
	note Fs, 4
	note D_, 2
	note Fs, 2
	note D_, 2
	note Fs, 4
	note D_, 2
	note Fs, 4
	note D_, 2
	note Fs, 2
	note D_, 2
	note G_, 4
	note C_, 2
	note G_, 4
	note C_, 2
	note G_, 2
	note C_, 2
	note G_, 4
	note C_, 2
	note G_, 4
	note C_, 2
	note E_, 2
	note G_, 2
	note A_, 6
	octave 4
	note Fs, 4
	octave 3
	note D_, 2
	note A_, 2
	octave 4
	note D_, 2
	note C_, 3
	note E_, 1
	note Fs, 6
	octave 3
	note D_, 2
	note Ds, 2
	note E_, 2
	sound_loop 0, gbs_route36_Ch3.mainloop

gbs_route36_Ch4:
	gbs_switch 3
	toggle_noise 1
	drum_speed 12
	sound_call gbs_route36_Ch4.sub1
	sound_call gbs_route36_Ch4.sub3
gbs_route36_Ch4.mainloop:
gbs_route36_Ch4.loop1:
	sound_call gbs_route36_Ch4.sub1
	sound_call gbs_route36_Ch4.sub2
	sound_call gbs_route36_Ch4.sub1
	sound_call gbs_route36_Ch4.sub3
	sound_loop 2, gbs_route36_Ch4.loop1
gbs_route36_Ch4.loop2:
	drum_note 11, 4
	drum_note 10, 2
	drum_note 6, 4
	drum_note 12, 1
	drum_note 12, 1
	drum_note 10, 4
	sound_loop 11, gbs_route36_Ch4.loop2
	sound_call gbs_route36_Ch4.sub3
	sound_loop 0, gbs_route36_Ch4.mainloop

gbs_route36_Ch4.sub1:
	drum_note 10, 4
	drum_note 10, 6
	drum_note 11, 1
	drum_note 11, 1
	drum_note 10, 2
	drum_note 11, 2
	sound_ret

gbs_route36_Ch4.sub2:
	drum_note 10, 4
	drum_note 10, 6
	drum_note 12, 1
	drum_note 11, 1
	drum_note 10, 4
	sound_ret

gbs_route36_Ch4.sub3:
	drum_note 10, 4
	drum_note 10, 6
	drum_note 11, 1
	drum_note 11, 1
	drum_note 10, 2
	drum_speed 6
	drum_note 11, 1
	drum_note 11, 1
	drum_note 10, 1
	drum_note 10, 1
	drum_speed 12
	sound_ret

	.align 4
	.global gbs_route36_Header
gbs_route36_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_route36_Ch1
	.int gbs_route36_Ch2
	.int gbs_route36_Ch3
	.int gbs_route36_Ch4
