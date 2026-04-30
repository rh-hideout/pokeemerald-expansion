	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_burnedtower_Ch1:
	gbs_switch 0
	tempo 168
	volume 7, 7
	duty_cycle 1
	pitch_offset 4
	vibrato 8, 4, 5
	stereo_panning TRUE, FALSE
	note_type 12, 9, 1
	rest 2
	octave 2
	note A_, 4
	note A_, 4
	note A_, 2
	volume_envelope 8, 0
	octave 3
	note Ds, 6
	volume_envelope 9, 1
	note D_, 4
	note D_, 4
	note D_, 2
	volume_envelope 8, 0
	note Cs, 6
gbs_burnedtower_Ch1.loop1:
	volume_envelope 9, 1
	octave 2
	note A_, 4
	note A_, 4
	note A_, 2
	volume_envelope 8, 0
	note As, 6
	sound_loop 2, gbs_burnedtower_Ch1.loop1
	tempo 150
gbs_burnedtower_Ch1.mainloop:
	volume_envelope 11, 1
	octave 2
	note A_, 4
	note A_, 4
	note A_, 2
	volume_envelope 10, 0
	octave 3
	note Ds, 6
	volume_envelope 11, 1
	note D_, 4
	note D_, 4
	note D_, 2
	volume_envelope 10, 0
	note Cs, 6
	volume_envelope 11, 1
	octave 2
	note A_, 4
	note A_, 4
	note A_, 2
	volume_envelope 10, 0
	note As, 6
	volume_envelope 11, 1
	note A_, 4
	note A_, 4
	note A_, 2
	volume_envelope 11, 3
	note As, 16
	note As, 16
	note As, 16
	note Gs, 6
	volume_envelope 11, 1
	note A_, 4
	note A_, 4
	note A_, 2
	volume_envelope 10, 0
	note As, 6
	volume_envelope 11, 1
	note B_, 4
	note B_, 4
	note B_, 2
	volume_envelope 10, 0
	octave 3
	note F_, 6
	volume_envelope 11, 1
	note E_, 4
	note E_, 4
	note E_, 2
	volume_envelope 10, 0
	note Ds, 6
gbs_burnedtower_Ch1.loop2:
	volume_envelope 11, 1
	octave 2
	note B_, 4
	note B_, 4
	note B_, 2
	volume_envelope 10, 0
	octave 3
	note C_, 6
	sound_loop 2, gbs_burnedtower_Ch1.loop2
	sound_loop 0, gbs_burnedtower_Ch1.mainloop

gbs_burnedtower_Ch2:
	gbs_switch 1
	duty_cycle 2
	vibrato 32, 8, 2
	pitch_offset 2
	note_type 12, 7, 0
	sound_call gbs_burnedtower_Ch2.sub1
	volume_envelope 12, 5
gbs_burnedtower_Ch2.mainloop:
	sound_call gbs_burnedtower_Ch2.sub1
	volume_envelope 12, 1
	duty_cycle 3
	rest 2
	octave 2
	note A_, 4
	note A_, 4
	note A_, 2
	volume_envelope 11, 0
	octave 3
	note Ds, 6
	volume_envelope 12, 1
	note D_, 4
	note D_, 4
	note D_, 2
	volume_envelope 11, 0
	note Cs, 6
	volume_envelope 12, 1
	octave 2
	note A_, 4
	note A_, 4
	note A_, 2
	volume_envelope 11, 0
	note As, 4
	volume_envelope 12, 1
	volume_envelope 12, 2
	octave 3
	note A_, 1
	note G_, 1
	note A_, 1
	octave 4
	note C_, 1
	vibrato 0, 0, 0
	volume_envelope 3, -5
	note E_, 8
	vibrato 32, 8, 3
	volume_envelope 11, 0
	octave 2
	note G_, 4
	duty_cycle 2
	volume_envelope 11, 0
	octave 3
	note Fs, 4
	note E_, 2
	note Fs, 2
	note G_, 4
	note B_, 4
	octave 4
	note Cs, 4
	note D_, 2
	note Cs, 2
	octave 3
	note B_, 4
	note G_, 4
	note Fs, 4
	note E_, 2
	note Fs, 2
	note G_, 4
	note E_, 4
	volume_envelope 11, 7
	note Fs, 16
	sound_loop 0, gbs_burnedtower_Ch2.mainloop

gbs_burnedtower_Ch2.sub1:
	octave 3
	note E_, 4
	note D_, 2
	note E_, 2
	note F_, 4
	note A_, 4
	note B_, 4
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note A_, 4
	note F_, 4
	note E_, 4
	note D_, 2
	note E_, 2
	note F_, 4
	note D_, 4
	note E_, 16
	sound_ret

gbs_burnedtower_Ch3:
	gbs_switch 2
	stereo_panning FALSE, TRUE
	note_type 12, 1, 4
	rest 16
	rest 16
	rest 16
	rest 12
	octave 3
	note Ds, 4
gbs_burnedtower_Ch3.mainloop:
gbs_burnedtower_Ch3.loop1:
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note E_, 2
	note F_, 4
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note E_, 2
	note Ds, 4
	sound_loop 4, gbs_burnedtower_Ch3.loop1
gbs_burnedtower_Ch3.loop2:
	octave 2
	note B_, 2
	octave 3
	note Fs, 2
	rest 2
	note Fs, 2
	rest 2
	note Fs, 2
	note G_, 4
	octave 2
	note B_, 2
	octave 3
	note Fs, 2
	rest 2
	note Fs, 2
	rest 2
	note Fs, 2
	note F_, 4
	sound_loop 2, gbs_burnedtower_Ch3.loop2
	sound_loop 0, gbs_burnedtower_Ch3.mainloop

gbs_burnedtower_Ch4:
	gbs_switch 3
	toggle_noise 0
	drum_speed 12
gbs_burnedtower_Ch4.loop1:
	rest 16
	sound_loop 4, gbs_burnedtower_Ch4.loop1
	rest 2
gbs_burnedtower_Ch4.mainloop:
	stereo_panning TRUE, FALSE
	drum_note 8, 2
	drum_note 9, 2
	drum_note 8, 4
	drum_note 9, 2
	drum_note 8, 4
	sound_loop 0, gbs_burnedtower_Ch4.mainloop

	.align 4
	.global gbs_burnedtower_Header
gbs_burnedtower_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_burnedtower_Ch1
	.int gbs_burnedtower_Ch2
	.int gbs_burnedtower_Ch3
	.int gbs_burnedtower_Ch4
