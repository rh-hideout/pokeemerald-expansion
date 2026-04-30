	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_dragonsden_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	duty_cycle 0
	pitch_offset 4
	stereo_panning TRUE, FALSE
	note_type 12, 8, 0
gbs_dragonsden_Ch1.mainloop:
	sound_call gbs_dragonsden_Ch1.sub1
	rest 16
	sound_call gbs_dragonsden_Ch1.sub2
	rest 2
	sound_call gbs_dragonsden_Ch1.sub2
	rest 2
	sound_call gbs_dragonsden_Ch1.sub2
	rest 2
	sound_call gbs_dragonsden_Ch1.sub2
	rest 10
	note_type 12, 11, 7
	sound_loop 0, gbs_dragonsden_Ch1.mainloop

gbs_dragonsden_Ch1.sub1:
	octave 3
	note As, 12
	note A_, 4
	note As, 12
	note A_, 4
	note As, 6
	octave 4
	note C_, 4
	note Cs, 6
	note E_, 16
	note Ds, 12
	note D_, 4
	octave 3
	note Gs, 16
	sound_ret

gbs_dragonsden_Ch1.sub2:
	volume_envelope 11, 1
	rest 2
	octave 4
	note Cs, 3
	note Cs, 3
	note Cs, 3
	note Cs, 3
	note Cs, 4
	note Cs, 3
	note Cs, 3
	note Cs, 4
	note Cs, 2
	note Cs, 2
	sound_ret

gbs_dragonsden_Ch2:
	gbs_switch 1
	duty_cycle 0
	pitch_offset 4
	stereo_panning FALSE, TRUE
	note_type 12, 9, 0
gbs_dragonsden_Ch2.mainloop:
	sound_call gbs_dragonsden_Ch2.sub1
	rest 16
	sound_call gbs_dragonsden_Ch2.sub2
	sound_call gbs_dragonsden_Ch2.sub2
	sound_call gbs_dragonsden_Ch2.sub2
	sound_call gbs_dragonsden_Ch2.sub2
	rest 16
	note_type 12, 12, 7
	sound_loop 0, gbs_dragonsden_Ch2.mainloop

gbs_dragonsden_Ch2.sub1:
	octave 4
	note Ds, 12
	note D_, 4
	note Ds, 12
	note D_, 4
	note Ds, 6
	note F_, 4
	note Fs, 6
	note A_, 16
	note Gs, 12
	note G_, 4
	note Cs, 16
	sound_ret

gbs_dragonsden_Ch2.sub2:
	volume_envelope 12, 1
gbs_dragonsden_Ch2.sub2loop1:
	octave 5
	note Cs, 4
	octave 4
	note Gs, 4
	note Gs, 4
	note Gs, 4
	sound_loop 2, gbs_dragonsden_Ch2.sub2loop1
	sound_ret

gbs_dragonsden_Ch3:
	gbs_switch 2
gbs_dragonsden_Ch3.mainloop:
gbs_dragonsden_Ch3.loop1:
	note_type 12, 1, 4
	octave 4
	note Cs, 2
	octave 3
	note Gs, 1
	octave 4
	note Cs, 1
	octave 3
	note Gs, 2
	octave 4
	note Cs, 2
	octave 3
	note Gs, 1
	octave 4
	note Cs, 1
	octave 3
	note Gs, 2
	octave 4
	note Cs, 2
	octave 3
	note Gs, 1
	octave 4
	note Cs, 1
	sound_loop 15, gbs_dragonsden_Ch3.loop1
	rest 16
	note_type 6, 2, 7
gbs_dragonsden_Ch3.loop2:
	octave 3
	note Cs, 4
	octave 2
	note Gs, 2
	octave 3
	note Cs, 2
	octave 2
	note Gs, 4
	octave 3
	note Cs, 4
	octave 2
	note Gs, 2
	octave 3
	note Cs, 2
	octave 2
	note Gs, 4
	octave 3
	note Cs, 4
	octave 2
	note Gs, 2
	octave 3
	note Cs, 2
	sound_loop 16, gbs_dragonsden_Ch3.loop2
	sound_loop 0, gbs_dragonsden_Ch3.mainloop

gbs_dragonsden_Ch4:
	gbs_switch 3
	toggle_noise 0
	drum_speed 12
	rest 16
	rest 16
gbs_dragonsden_Ch4.mainloop:
	stereo_panning TRUE, FALSE
	drum_note 6, 4
	stereo_panning FALSE, TRUE
	drum_note 7, 4
	drum_note 7, 4
	stereo_panning TRUE, FALSE
	drum_note 7, 4
	sound_loop 0, gbs_dragonsden_Ch4.mainloop

	.align 4
	.global gbs_dragonsden_Header
gbs_dragonsden_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_dragonsden_Ch1
	.int gbs_dragonsden_Ch2
	.int gbs_dragonsden_Ch3
	.int gbs_dragonsden_Ch4
