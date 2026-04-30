	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_lighthouse_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	duty_cycle 3
	pitch_offset 4
	vibrato 8, 4, 5
	stereo_panning FALSE, TRUE
gbs_lighthouse_Ch1.mainloop:
	note_type 12, 11, 3
	octave 3
	note Cs, 8
	octave 2
	note Fs, 2
	note Gs, 2
	note A_, 2
	note B_, 2
	octave 3
	note Cs, 4
	octave 2
	note B_, 4
	note A_, 4
	note B_, 4
	note Gs, 1
	rest 7
	octave 3
	note C_, 4
	octave 2
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note C_, 2
	note Ds, 1
	rest 1
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	octave 3
	note Cs, 8
	octave 2
	note Cs, 2
	note Fs, 2
	note Gs, 2
	octave 3
	note C_, 2
	note D_, 2
	note Cs, 2
	octave 2
	note A_, 2
	note Gs, 2
	note A_, 2
	note Gs, 2
	note Fs, 2
	note A_, 2
	note Gs, 1
	rest 7
	octave 3
	note C_, 12
	octave 2
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 1
	rest 3
	octave 3
	note C_, 1
	rest 3
	octave 2
	note A_, 4
	octave 3
	note A_, 4
	note Gs, 4
	note Fs, 4
	note E_, 4
	note Ds, 4
	note Cs, 4
	note E_, 4
	note Fs, 2
	note E_, 2
	note Ds, 12
	octave 2
	note B_, 2
	note A_, 2
	note B_, 2
	note A_, 2
	note Gs, 8
	note A_, 4
	octave 3
	note A_, 4
	note Gs, 2
	note Fs, 2
	note E_, 2
	note Fs, 2
	note E_, 2
	note Ds, 2
	note Cs, 2
	octave 2
	note B_, 2
	note A_, 2
	note B_, 2
	octave 3
	note Cs, 2
	note Ds, 2
	note E_, 2
	note Fs, 2
	note Gs, 12
	octave 2
	note B_, 2
	note A_, 2
	note B_, 2
	note A_, 2
	note Gs, 8
	sound_loop 0, gbs_lighthouse_Ch1.mainloop

gbs_lighthouse_Ch2:
	gbs_switch 1
	duty_cycle 3
	pitch_offset 2
	vibrato 16, 4, 5
gbs_lighthouse_Ch2.mainloop:
	note_type 12, 12, 5
	octave 3
	note Gs, 12
	note Fs, 2
	note Gs, 2
	note A_, 8
	octave 4
	note Cs, 8
	note C_, 1
	rest 7
	octave 3
	note Gs, 16
	volume_envelope 12, 5
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	note Gs, 12
	note Fs, 2
	note Gs, 2
	note A_, 8
	octave 4
	note Cs, 8
	note C_, 1
	rest 7
	note Ds, 12
	octave 3
	note Ds, 1
	rest 1
	note Ds, 1
	rest 1
	note Ds, 1
	rest 3
	note Ds, 1
	rest 3
	octave 4
	note E_, 12
	note Ds, 2
	note Cs, 2
	octave 3
	note Gs, 12
	note As, 4
	note B_, 2
	octave 4
	note Cs, 2
	note Ds, 12
	octave 3
	note Ds, 2
	note Cs, 2
	note Ds, 2
	note Cs, 2
	note C_, 8
	octave 4
	note E_, 12
	note Ds, 2
	note Cs, 2
	octave 3
	note Gs, 12
	octave 4
	note C_, 4
	octave 3
	note B_, 2
	octave 4
	note C_, 2
	note Ds, 12
	octave 3
	note Ds, 2
	note Cs, 2
	note Ds, 2
	note Cs, 2
	note C_, 8
	sound_loop 0, gbs_lighthouse_Ch2.mainloop

gbs_lighthouse_Ch3:
	gbs_switch 2
	note_type 12, 1, 9
	stereo_panning TRUE, FALSE
gbs_lighthouse_Ch3.mainloop:
	octave 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Fs, 2
	rest 2
	note G_, 2
	rest 2
gbs_lighthouse_Ch3.loop1:
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Fs, 2
	rest 2
	note A_, 2
	rest 2
	sound_loop 2, gbs_lighthouse_Ch3.loop1
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Fs, 2
	rest 2
	note A_, 2
	octave 3
	note C_, 2
	note Cs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	note A_, 2
	rest 2
	octave 3
	note C_, 2
	rest 2
gbs_lighthouse_Ch3.loop2:
	note Cs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	note A_, 2
	rest 2
	octave 3
	note D_, 2
	rest 2
	sound_loop 2, gbs_lighthouse_Ch3.loop2
	note Cs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	note A_, 2
	rest 2
	octave 3
	note Ds, 2
	note Fs, 2
gbs_lighthouse_Ch3.loop3:
	note E_, 2
	rest 2
	octave 2
	note B_, 2
	rest 2
	octave 3
	note C_, 2
	rest 2
	note F_, 2
	rest 2
	sound_loop 8, gbs_lighthouse_Ch3.loop3
	sound_loop 0, gbs_lighthouse_Ch3.mainloop

gbs_lighthouse_Ch4:
	gbs_switch 3
	toggle_noise 0
	drum_speed 12
gbs_lighthouse_Ch4.mainloop:
	stereo_panning FALSE, TRUE
	drum_note 9, 4
	drum_note 6, 2
	drum_note 9, 4
	drum_note 6, 2
	drum_note 10, 2
	drum_note 11, 2
	stereo_panning TRUE, TRUE
	drum_note 9, 2
	drum_note 6, 4
	drum_note 9, 2
	drum_note 6, 4
	drum_note 9, 2
	drum_note 10, 2
	sound_loop 0, gbs_lighthouse_Ch4.mainloop

	.align 4
	.global gbs_lighthouse_Header
gbs_lighthouse_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_lighthouse_Ch1
	.int gbs_lighthouse_Ch2
	.int gbs_lighthouse_Ch3
	.int gbs_lighthouse_Ch4
