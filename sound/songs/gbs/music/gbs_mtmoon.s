	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_mtmoon_Ch1:
	gbs_switch 0
	tempo 208
	volume 7, 7
	duty_cycle 2
	pitch_offset 1
	vibrato 8, 1, 4
	stereo_panning TRUE, FALSE
	note_type 12, 4, 5
	rest 2
	sound_loop 0, gbs_mtmoon_Ch2.mainloop

gbs_mtmoon_Ch2:
	gbs_switch 1
	vibrato 11, 1, 5
	duty_cycle 2
	note_type 12, 8, 4
	stereo_panning FALSE, TRUE
gbs_mtmoon_Ch2.mainloop:
	octave 4
	note Ds, 6
	note Cs, 6
	octave 3
	note B_, 2
	octave 4
	note Cs, 2
	note Ds, 2
	note G_, 2
	note Ds, 2
	note Cs, 6
	octave 3
	note B_, 2
	octave 4
	note Cs, 2
	note Ds, 2
	note G_, 2
	note Ds, 2
	note Cs, 6
	octave 3
	note B_, 2
	note As, 2
	note B_, 6
	octave 4
	note Cs, 10
	note Gs, 6
	note Fs, 6
	note E_, 2
	note Fs, 2
	note Gs, 2
	octave 5
	note C_, 2
	octave 4
	note Gs, 2
	note Fs, 6
	note E_, 2
	note Fs, 2
	note Gs, 2
	octave 5
	note C_, 2
	octave 4
	note Gs, 2
	note Fs, 6
	note E_, 2
	note Ds, 2
	note E_, 6
	note Fs, 6
	note E_, 4
	sound_loop 0, gbs_mtmoon_Ch2.mainloop

gbs_mtmoon_Ch3:
	gbs_switch 2
gbs_mtmoon_Ch3.mainloop:
	note_type 12, 2, 8
gbs_mtmoon_Ch3.loop1:
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	note G_, 2
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	note G_, 2
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	sound_loop 3, gbs_mtmoon_Ch3.loop1
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	note G_, 2
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	note G_, 2
	note Ds, 2
	note E_, 2
gbs_mtmoon_Ch3.loop2:
	note E_, 2
	note Gs, 2
	octave 4
	note C_, 2
	octave 3
	note E_, 2
	note Gs, 2
	octave 4
	note C_, 2
	octave 3
	note E_, 2
	note Gs, 2
	sound_loop 4, gbs_mtmoon_Ch3.loop2
	sound_loop 0, gbs_mtmoon_Ch3.mainloop

gbs_mtmoon_Ch4:
	gbs_switch 3
	toggle_noise 5
	drum_speed 12
gbs_mtmoon_Ch4.mainloop:
	stereo_panning FALSE, TRUE
	drum_note 11, 4
	drum_note 11, 8
	drum_note 11, 4
	stereo_panning TRUE, FALSE
	drum_note 11, 4
	drum_note 11, 4
	drum_note 11, 4
	stereo_panning FALSE, TRUE
	drum_note 11, 4
	drum_note 11, 4
	stereo_panning TRUE, FALSE
	drum_note 11, 8
	sound_loop 0, gbs_mtmoon_Ch4.mainloop

	.align 4
	.global gbs_mtmoon_Header
gbs_mtmoon_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_mtmoon_Ch1
	.int gbs_mtmoon_Ch2
	.int gbs_mtmoon_Ch3
	.int gbs_mtmoon_Ch4
