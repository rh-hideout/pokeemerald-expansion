	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_evolution_Ch1:
	gbs_switch 0
	tempo 132
	volume 7, 7
	vibrato 6, 3, 4
	pitch_offset 1
	duty_cycle 3
	note_type 12, 10, 2
	octave 3
	stereo_panning FALSE, TRUE
gbs_evolution_Ch1.mainloop:
gbs_evolution_Ch1.loop1:
	sound_call gbs_evolution_Ch1.sub1
	note_type 12, 10, 4
	note Fs, 4
	sound_call gbs_evolution_Ch1.sub1
	note_type 12, 10, 4
	note Fs, 4
	sound_loop 2, gbs_evolution_Ch1.loop1
	sound_call gbs_evolution_Ch1.sub2
	note_type 12, 10, 4
	note Gs, 4
	sound_call gbs_evolution_Ch1.sub2
	note_type 12, 10, 4
	note Gs, 4
	sound_loop 0, gbs_evolution_Ch1.mainloop

gbs_evolution_Ch1.sub1:
	note_type 12, 10, 2
	octave 3
	note C_, 4
	note G_, 4
	note C_, 4
	note G_, 4
	note C_, 4
	note G_, 4
	note C_, 4
	sound_ret

gbs_evolution_Ch1.sub2:
	note_type 12, 10, 2
	octave 3
	note D_, 4
	note A_, 4
	note D_, 4
	note A_, 4
	note D_, 4
	note A_, 4
	note D_, 4
	sound_ret

gbs_evolution_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 8, 2, 5
	note_type 12, 11, 2
	octave 4
	stereo_panning TRUE, FALSE
gbs_evolution_Ch2.mainloop:
gbs_evolution_Ch2.loop1:
	sound_call gbs_evolution_Ch2.sub1
	note_type 12, 11, 5
	note A_, 4
	sound_call gbs_evolution_Ch2.sub1
	note_type 12, 11, 5
	note B_, 4
	sound_loop 2, gbs_evolution_Ch2.loop1
	sound_call gbs_evolution_Ch2.sub2
	note_type 12, 11, 5
	note B_, 4
	sound_call gbs_evolution_Ch2.sub2
	note_type 12, 11, 5
	octave 4
	note Cs, 4
	octave 3
	sound_loop 0, gbs_evolution_Ch2.mainloop

gbs_evolution_Ch2.sub1:
	note_type 12, 11, 2
	octave 3
	note G_, 4
	note D_, 4
	note G_, 4
	note D_, 4
	note G_, 4
	note D_, 4
	note G_, 4
	sound_ret

gbs_evolution_Ch2.sub2:
	note_type 12, 11, 2
	octave 3
	note A_, 4
	note E_, 4
	note A_, 4
	note E_, 4
	note A_, 4
	note E_, 4
	note A_, 4
	sound_ret

gbs_evolution_Ch3:
	gbs_switch 2
	note_type 12, 1, 6
gbs_evolution_Ch3.mainloop:
gbs_evolution_Ch3.loop1:
	sound_call gbs_evolution_Ch3.sub1
	octave 3
	note A_, 4
	sound_call gbs_evolution_Ch3.sub1
	octave 3
	note B_, 4
	sound_loop 2, gbs_evolution_Ch3.loop1
	sound_call gbs_evolution_Ch3.sub2
	octave 3
	note B_, 4
	sound_call gbs_evolution_Ch3.sub2
	octave 4
	note Cs, 4
	sound_loop 0, gbs_evolution_Ch3.mainloop

gbs_evolution_Ch3.sub1:
	octave 2
	note A_, 2
	rest 2
	octave 3
	note D_, 2
	rest 2
	octave 2
	note A_, 2
	rest 2
	octave 3
	note D_, 2
	rest 2
	octave 2
	note A_, 2
	rest 2
	octave 3
	note D_, 2
	rest 2
	octave 2
	note A_, 2
	rest 2
	sound_ret

gbs_evolution_Ch3.sub2:
	octave 2
	note B_, 2
	rest 2
	octave 3
	note E_, 2
	rest 2
	octave 2
	note B_, 2
	rest 2
	octave 3
	note E_, 2
	rest 2
	octave 2
	note B_, 2
	rest 2
	octave 3
	note E_, 2
	rest 2
	octave 2
	note A_, 2
	rest 2
	sound_ret

gbs_evolution_Ch4:
	gbs_switch 3
	toggle_noise 5
	drum_speed 12
gbs_evolution_Ch4.mainloop:
	stereo_panning TRUE, FALSE
	drum_note 11, 6
	drum_note 11, 4
	stereo_panning FALSE, TRUE
	drum_note 5, 2
	drum_note 5, 2
	drum_note 5, 2
	sound_loop 0, gbs_evolution_Ch4.mainloop

	.align 4
	.global gbs_evolution_Header
gbs_evolution_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_evolution_Ch1
	.int gbs_evolution_Ch2
	.int gbs_evolution_Ch3
	.int gbs_evolution_Ch4
