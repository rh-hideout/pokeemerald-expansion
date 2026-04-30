	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_contestresults_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	note_type 12, 5, 1
gbs_contestresults_Ch1.mainloop:
	rest 2
	octave 2
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 1
	rest 2
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	rest 2
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	rest 2
	note B_, 1
	rest 3
	note As, 1
	rest 3
	note A_, 1
	rest 3
	note G_, 1
	rest 1
	sound_loop 0, gbs_contestresults_Ch1.mainloop

gbs_contestresults_Ch2:
	gbs_switch 1
	note_type 12, 6, 1
gbs_contestresults_Ch2.mainloop:
	octave 2
	note C_, 2
	octave 3
	note E_, 1
	rest 1
	octave 1
	note G_, 2
	octave 3
	note E_, 1
	rest 1
	octave 1
	note A_, 2
	octave 3
	note E_, 1
	rest 1
	octave 1
	note B_, 2
	octave 3
	note E_, 1
	rest 1
	octave 2
	note D_, 2
	octave 3
	note F_, 1
	rest 1
	octave 1
	note A_, 2
	octave 3
	note F_, 1
	rest 1
	octave 1
	note B_, 2
	octave 3
	note F_, 1
	rest 1
	octave 2
	note Cs, 2
	octave 3
	note F_, 1
	rest 1
gbs_contestresults_Ch2.loop1:
	octave 2
	note D_, 2
	octave 3
	note F_, 1
	rest 1
	octave 1
	note A_, 2
	octave 3
	note F_, 1
	rest 1
	sound_loop 2, gbs_contestresults_Ch2.loop1
	octave 2
	note G_, 2
	octave 3
	note G_, 1
	rest 1
	octave 2
	note D_, 2
	octave 3
	note Fs, 1
	rest 1
	octave 2
	note G_, 2
	octave 3
	note F_, 1
	rest 1
	octave 2
	note D_, 2
	octave 3
	note D_, 1
	rest 1
	sound_loop 0, gbs_contestresults_Ch2.mainloop

gbs_contestresults_Ch3:
	gbs_switch 2
	vibrato 8, 2, 4
	note_type 12, 2, 3
gbs_contestresults_Ch3.mainloop:
	octave 4
	note E_, 5
	rest 1
	note E_, 1
	note F_, 1
	note G_, 4
	octave 5
	note C_, 4
	octave 4
	note B_, 8
	note A_, 8
	note D_, 5
	rest 1
	note D_, 1
	note E_, 1
	note F_, 4
	note B_, 4
	note A_, 8
	note G_, 8
	sound_loop 0, gbs_contestresults_Ch3.mainloop

gbs_contestresults_Ch4:
	gbs_switch 3
	toggle_noise 4
	drum_speed 6
gbs_contestresults_Ch4.mainloop:
	drum_note 2, 4
	drum_note 2, 4
	drum_note 2, 2
	drum_note 2, 2
	drum_note 2, 2
	drum_note 2, 2
	drum_note 2, 4
	drum_note 2, 4
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	sound_loop 0, gbs_contestresults_Ch4.mainloop

	.align 4
	.global gbs_contestresults_Header
gbs_contestresults_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_contestresults_Ch1
	.int gbs_contestresults_Ch2
	.int gbs_contestresults_Ch3
	.int gbs_contestresults_Ch4
