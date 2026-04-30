	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_victoryroad_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	stereo_panning FALSE, TRUE
	duty_cycle 3
	pitch_offset 2
	note_type 12, 11, 3
gbs_victoryroad_Ch1.mainloop:
gbs_victoryroad_Ch1.loop1:
	sound_call gbs_victoryroad_Ch1.sub1
	sound_loop 6, gbs_victoryroad_Ch1.loop1
gbs_victoryroad_Ch1.loop2:
	volume_envelope 11, 2
	octave 2
	note A_, 1
	octave 3
	note Cs, 1
	note D_, 1
	rest 1
	octave 2
	note A_, 1
	volume_envelope 11, 7
	octave 3
	note Cs, 3
	octave 2
	note A_, 1
	octave 3
	note D_, 3
	octave 2
	note A_, 1
	octave 3
	note Gs, 3
	sound_loop 2, gbs_victoryroad_Ch1.loop2
gbs_victoryroad_Ch1.loop3:
	sound_call gbs_victoryroad_Ch1.sub1
	sound_loop 2, gbs_victoryroad_Ch1.loop3
	sound_loop 0, gbs_victoryroad_Ch1.mainloop

gbs_victoryroad_Ch1.sub1:
	volume_envelope 11, 2
	octave 2
	note G_, 1
	note B_, 1
	octave 3
	note C_, 1
	rest 1
	octave 2
	note G_, 1
	volume_envelope 11, 7
	note B_, 3
	note G_, 1
	octave 3
	note C_, 3
	octave 2
	note G_, 1
	octave 3
	note Fs, 3
	sound_ret

gbs_victoryroad_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 16, 2, 4
gbs_victoryroad_Ch2.mainloop:
	note_type 12, 12, 2
	sound_call gbs_victoryroad_Ch2.sub1
	rest 2
	sound_call gbs_victoryroad_Ch2.sub1
	rest 1
	octave 4
	note C_, 1
	note_type 12, 11, 0
	note E_, 8
	octave 5
	note C_, 4
	octave 4
	note B_, 4
	note E_, 15
	note Ds, 1
	note_type 12, 11, 0
	note E_, 8
	octave 5
	note C_, 4
	octave 4
	note B_, 4
	note_type 12, 11, 0
	octave 5
	note E_, 8
	note_type 12, 11, 7
	note E_, 8
	note_type 12, 12, 7
	note D_, 8
	stereo_panning TRUE, FALSE
	note Cs, 4
	stereo_panning FALSE, TRUE
	octave 4
	note A_, 4
	stereo_panning TRUE, TRUE
	octave 5
	note C_, 8
	stereo_panning FALSE, TRUE
	octave 4
	note As, 4
	stereo_panning TRUE, FALSE
	note F_, 4
	stereo_panning TRUE, TRUE
	note A_, 12
	note D_, 1
	note Fs, 1
	note A_, 1
	octave 5
	note Cs, 1
	note D_, 16
	sound_loop 0, gbs_victoryroad_Ch2.mainloop

gbs_victoryroad_Ch2.sub1:
	octave 3
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	note Fs, 1
	rest 2
	note Gs, 1
	note Gs, 1
	rest 2
	note A_, 1
	note A_, 1
	sound_ret

gbs_victoryroad_Ch3:
	gbs_switch 2
	stereo_panning TRUE, FALSE
	note_type 12, 2, 8
gbs_victoryroad_Ch3.mainloop:
gbs_victoryroad_Ch3.loop1:
	sound_call gbs_victoryroad_Ch3.sub1
	sound_loop 6, gbs_victoryroad_Ch3.loop1
gbs_victoryroad_Ch3.loop2:
	note D_, 1
	rest 1
	note B_, 1
	rest 1
	note F_, 1
	note A_, 3
	note D_, 1
	note B_, 1
	rest 2
	note D_, 1
	note B_, 3
	sound_loop 2, gbs_victoryroad_Ch3.loop2
gbs_victoryroad_Ch3.loop3:
	sound_call gbs_victoryroad_Ch3.sub1
	sound_loop 2, gbs_victoryroad_Ch3.loop3
	sound_loop 0, gbs_victoryroad_Ch3.mainloop

gbs_victoryroad_Ch3.sub1:
	octave 3
	note C_, 1
	rest 1
	note A_, 1
	rest 1
	note Ds, 1
	note G_, 3
	note C_, 1
	note A_, 1
	rest 2
	note C_, 1
	note A_, 3
	sound_ret

gbs_victoryroad_Ch4:
	gbs_switch 3
	toggle_noise 0
	drum_speed 12
gbs_victoryroad_Ch4.mainloop:
	drum_note 3, 2
	drum_note 3, 2
	drum_note 4, 1
	drum_note 3, 3
	drum_note 4, 1
	drum_note 3, 3
	drum_note 4, 1
	drum_note 3, 3
	drum_note 3, 2
	drum_note 3, 2
	drum_note 4, 1
	drum_note 3, 3
	drum_note 4, 1
	drum_note 4, 1
	drum_note 3, 2
	drum_note 4, 1
	drum_note 3, 2
	drum_note 4, 1
	sound_loop 0, gbs_victoryroad_Ch4.mainloop

	.align 4
	.global gbs_victoryroad_Header
gbs_victoryroad_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_victoryroad_Ch1
	.int gbs_victoryroad_Ch2
	.int gbs_victoryroad_Ch3
	.int gbs_victoryroad_Ch4
