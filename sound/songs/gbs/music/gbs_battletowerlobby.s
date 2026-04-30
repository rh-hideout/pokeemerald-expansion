	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_battletowerlobby_Ch1:
	gbs_switch 0
	tempo 152
	volume 7, 7
	duty_cycle 3
	pitch_offset 1
	vibrato 8, 2, 2
	stereo_panning TRUE, FALSE
	note_type 12, 7, 2
gbs_battletowerlobby_Ch1.mainloop:
	note_type 12, 7, 2
	octave 3
	note Gs, 2
	note_type 12, 7, 3
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	note Gs, 2
	note E_, 2
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	note Gs, 2
	note_type 12, 7, 2
	note Fs, 2
	note_type 12, 7, 3
	octave 2
	note B_, 2
	octave 3
	note Fs, 2
	note E_, 2
	note Ds, 2
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	note Fs, 2
	note_type 12, 7, 2
	note Gs, 2
	note_type 12, 7, 3
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	note Gs, 2
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	note B_, 2
	octave 4
	note E_, 2
	note_type 12, 7, 2
	note Fs, 3
	note_type 12, 7, 3
	note D_, 1
	note E_, 2
	octave 3
	note B_, 2
	note Gs, 2
	note E_, 2
	note Gs, 2
	note B_, 2
	note_type 12, 7, 2
	note Cs, 2
	note_type 12, 7, 3
	note Ds, 2
	note E_, 2
	note Cs, 1
	octave 2
	note B_, 1
	note A_, 4
	note_type 12, 6, 2
	note A_, 4
	note_type 12, 7, 2
	note B_, 2
	note_type 12, 7, 3
	octave 3
	note Cs, 2
	note Ds, 2
	note E_, 1
	note Fs, 1
	note Gs, 4
	note_type 12, 6, 2
	octave 2
	note Gs, 4
	note_type 12, 7, 2
	note A_, 2
	note_type 12, 7, 3
	note B_, 2
	octave 3
	note Cs, 2
	note D_, 1
	note E_, 1
	note D_, 2
	note E_, 2
	note Fs, 2
	note A_, 2
	note_type 12, 7, 2
	note B_, 2
	note_type 12, 7, 3
	note B_, 4
	note A_, 1
	note Gs, 1
	note_type 12, 7, 2
	note Fs, 4
	note_type 12, 7, 5
	octave 2
	note B_, 4
	sound_loop 0, gbs_battletowerlobby_Ch1.mainloop

gbs_battletowerlobby_Ch2:
	gbs_switch 1
	duty_cycle 2
	vibrato 16, 3, 4
	stereo_panning FALSE, TRUE
	note_type 12, 8, 2
gbs_battletowerlobby_Ch2.mainloop:
	note_type 12, 8, 2
	octave 4
	note E_, 2
	note E_, 4
	octave 3
	note B_, 1
	octave 4
	note E_, 1
	note B_, 4
	note A_, 2
	note Gs, 2
	note A_, 3
	note E_, 1
	octave 3
	note B_, 4
	note_type 12, 6, 5
	note Fs, 4
	octave 2
	note B_, 4
	note_type 12, 8, 2
	octave 4
	note E_, 2
	note E_, 4
	octave 3
	note B_, 1
	octave 4
	note E_, 1
	note B_, 4
	note A_, 2
	note Gs, 2
	note A_, 3
	note Fs, 1
	note_type 12, 8, 7
	note Gs, 12
	note_type 12, 8, 2
	octave 3
	note A_, 2
	note_type 12, 8, 4
	note A_, 4
	note Fs, 1
	note Gs, 1
	note A_, 4
	note_type 12, 8, 2
	note Cs, 4
	octave 4
	note Gs, 2
	note_type 12, 8, 4
	note Gs, 4
	note Fs, 1
	note Gs, 1
	note E_, 4
	note_type 12, 8, 2
	octave 3
	note E_, 4
	octave 4
	note Fs, 2
	note_type 12, 8, 4
	note Fs, 4
	note A_, 1
	note Gs, 1
	note A_, 4
	note D_, 4
	note_type 12, 8, 2
	note E_, 2
	note_type 12, 8, 4
	note E_, 4
	note Fs, 1
	note E_, 1
	note Ds, 4
	note_type 12, 7, 3
	octave 3
	note Ds, 1
	note Fs, 1
	note B_, 1
	octave 4
	note Ds, 1
	sound_loop 0, gbs_battletowerlobby_Ch2.mainloop

gbs_battletowerlobby_Ch3:
	gbs_switch 2
	note_type 12, 1, 1
gbs_battletowerlobby_Ch3.mainloop:
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note E_, 2
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note Ds, 2
	rest 2
	note Ds, 2
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	rest 2
	octave 2
	note A_, 2
	note B_, 2
	octave 3
	note E_, 2
	rest 2
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	octave 2
	note E_, 2
	octave 3
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	note E_, 2
	rest 2
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	octave 2
	note E_, 2
	octave 3
	note E_, 2
	octave 2
	note Gs, 2
	note B_, 2
	octave 3
	note E_, 2
	rest 2
	note D_, 2
	octave 2
	note Fs, 2
	note A_, 2
	octave 3
	note Fs, 2
	octave 2
	note Fs, 2
	note A_, 2
	octave 3
	note D_, 2
	note Fs, 2
	note E_, 2
	octave 2
	note B_, 2
	note E_, 2
	note B_, 2
	note Fs, 2
	note E_, 2
	note Ds, 2
	note Fs, 2
	sound_loop 0, gbs_battletowerlobby_Ch3.mainloop

gbs_battletowerlobby_Ch4:
	gbs_switch 3
	toggle_noise 0
gbs_battletowerlobby_Ch4.mainloop:
	drum_speed 12
	rest 2
	drum_note 6, 4
	drum_note 6, 4
	drum_note 6, 2
	drum_note 6, 4
	sound_loop 0, gbs_battletowerlobby_Ch4.mainloop

	.align 4
	.global gbs_battletowerlobby_Header
gbs_battletowerlobby_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_battletowerlobby_Ch1
	.int gbs_battletowerlobby_Ch2
	.int gbs_battletowerlobby_Ch3
	.int gbs_battletowerlobby_Ch4
