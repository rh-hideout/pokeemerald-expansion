	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_lookhiker_Ch1:
	gbs_switch 0
	tempo 132
	volume 7, 7
	pitch_offset 1
	vibrato 18, 2, 4
	duty_cycle 2
	stereo_panning FALSE, TRUE
	note_type 12, 6, 8
	octave 3
	note Fs, 2
	note F_, 2
	note Fs, 8
gbs_lookhiker_Ch1.mainloop:
	note D_, 2
	note Ds, 2
	note E_, 2
	note F_, 2
	note Fs, 2
	rest 4
	note Fs, 2
	rest 4
	note Fs, 2
	rest 2
	note Fs, 2
	rest 6
	sound_loop 0, gbs_lookhiker_Ch1.mainloop

gbs_lookhiker_Ch2:
	gbs_switch 1
	duty_cycle 0
	note_type 12, 10, 1
	rest 4
	octave 1
	note B_, 1
	note B_, 5
	octave 2
	note Fs, 1
	note Fs, 5
	octave 1
	note B_, 1
	octave 2
	note D_, 1
	note Fs, 1
	note D_, 1
	volume_envelope 10, 1
gbs_lookhiker_Ch2.mainloop:
	octave 1
	note B_, 1
	note B_, 2
	octave 2
	note D_, 1
	note D_, 2
	note Fs, 1
	note Fs, 2
	note As, 1
	note As, 2
	octave 1
	note B_, 1
	octave 2
	note D_, 1
	note Fs, 1
	note D_, 1
	sound_loop 0, gbs_lookhiker_Ch2.mainloop

gbs_lookhiker_Ch3:
	gbs_switch 2
	vibrato 18, 2, 4
	stereo_panning TRUE, FALSE
	note_type 12, 1, 4
	octave 4
	note B_, 2
	note As, 2
	note B_, 8
gbs_lookhiker_Ch3.mainloop:
	octave 5
	note Ds, 2
	note D_, 2
	note Cs, 2
	note C_, 2
	sound_call gbs_lookhiker_Ch3.sub1
	note G_, 2
	note Gs, 2
	note A_, 2
	note As, 2
	sound_call gbs_lookhiker_Ch3.sub1
	sound_loop 0, gbs_lookhiker_Ch3.mainloop

gbs_lookhiker_Ch3.sub1:
	octave 4
	note B_, 2
	rest 4
	note B_, 2
	rest 4
	note B_, 2
	rest 2
	note B_, 2
	rest 6
	sound_ret

gbs_lookhiker_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	drum_note 6, 4
	rest 16
gbs_lookhiker_Ch4.mainloop:
	drum_note 4, 2
	drum_note 8, 2
	drum_note 3, 2
	drum_note 8, 2
	sound_loop 0, gbs_lookhiker_Ch4.mainloop

	.align 4
	.global gbs_lookhiker_Header
gbs_lookhiker_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_lookhiker_Ch1
	.int gbs_lookhiker_Ch2
	.int gbs_lookhiker_Ch3
	.int gbs_lookhiker_Ch4
