	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_mainmenu_Ch1:
	gbs_switch 0
	tempo 160
	volume 7, 7
	duty_cycle 3
	pitch_offset 1
	vibrato 16, 1, 5
	stereo_panning TRUE, FALSE
	note_type 12, 0, -7
	octave 3
	note D_, 8
gbs_mainmenu_Ch1.mainloop:
gbs_mainmenu_Ch1.loop1:
	note_type 12, 9, 2
	octave 3
	note Cs, 6
	note Cs, 1
	note Cs, 1
	note Cs, 2
	note Cs, 2
	note Cs, 4
	sound_loop 2, gbs_mainmenu_Ch1.loop1
	note Ds, 6
	note Ds, 1
	note Ds, 1
	note Ds, 2
	note Ds, 2
	note Ds, 4
	octave 2
	note B_, 6
	note B_, 1
	note B_, 1
	note B_, 2
	note B_, 2
	note_type 12, 9, 4
	octave 3
	note C_, 4
	sound_loop 0, gbs_mainmenu_Ch1.mainloop

gbs_mainmenu_Ch2:
	gbs_switch 1
	duty_cycle 3
	stereo_panning FALSE, TRUE
	note_type 12, 0, -7
	octave 3
	note G_, 8
gbs_mainmenu_Ch2.mainloop:
gbs_mainmenu_Ch2.loop1:
	note_type 12, 10, 2
	note Fs, 6
	note Fs, 1
	note Fs, 1
	note Fs, 2
	note Fs, 2
	note Fs, 4
	sound_loop 2, gbs_mainmenu_Ch2.loop1
	note Gs, 6
	note Gs, 1
	note Gs, 1
	note Gs, 2
	note Gs, 2
	note Gs, 4
	note E_, 6
	note E_, 1
	note E_, 1
	note E_, 2
	note E_, 2
	note_type 12, 10, 4
	note F_, 4
	sound_loop 0, gbs_mainmenu_Ch2.mainloop

gbs_mainmenu_Ch3:
	gbs_switch 2
	stereo_panning TRUE, FALSE
	note_type 12, 2, 5
	rest 8
gbs_mainmenu_Ch3.mainloop:
gbs_mainmenu_Ch3.loop1:
	octave 2
	note Fs, 1
	rest 5
	note Fs, 1
	note Fs, 1
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note Fs, 1
	rest 3
	sound_loop 2, gbs_mainmenu_Ch3.loop1
	note Gs, 1
	rest 5
	note Gs, 1
	note Gs, 1
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 1
	rest 3
	note E_, 1
	rest 5
	note E_, 1
	note E_, 1
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note F_, 1
	rest 3
	sound_loop 0, gbs_mainmenu_Ch3.mainloop

gbs_mainmenu_Ch4:
	gbs_switch 3
	stereo_panning FALSE, TRUE
	toggle_noise 3
	drum_speed 12
	rest 8
	rest 16
	rest 16
	rest 16
	rest 12
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
gbs_mainmenu_Ch4.mainloop:
	drum_note 3, 6
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 4
	drum_note 3, 6
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 4, 1
	drum_note 4, 1
	drum_note 3, 1
	drum_note 3, 1
	sound_loop 0, gbs_mainmenu_Ch4.mainloop

	.align 4
	.global gbs_mainmenu_Header
gbs_mainmenu_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_mainmenu_Ch1
	.int gbs_mainmenu_Ch2
	.int gbs_mainmenu_Ch3
	.int gbs_mainmenu_Ch4
