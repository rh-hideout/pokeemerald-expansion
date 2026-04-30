	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_lookofficer_Ch1:
	gbs_switch 0
	tempo 116
	volume 7, 7
	pitch_offset 1
	vibrato 18, 3, 4
	stereo_panning FALSE, TRUE
	duty_cycle 3
	note_type 12, 10, 7
	octave 4
	note Cs, 1
	note D_, 1
	note Ds, 1
	note E_, 1
	note F_, 12
	volume_envelope 2, -7
	octave 3
	note B_, 16
gbs_lookofficer_Ch1.mainloop:
	volume_envelope 8, 2
	rest 4
	note B_, 6
	note Gs, 4
	note B_, 6
	note B_, 6
	note Gs, 4
	note B_, 2
	volume_envelope 2, -7
	note As, 16
	note A_, 16
	sound_loop 0, gbs_lookofficer_Ch1.mainloop

gbs_lookofficer_Ch2:
	gbs_switch 1
	vibrato 18, 3, 4
	duty_cycle 3
	note_type 12, 11, 7
	octave 5
	note Ds, 1
	note D_, 1
	note Cs, 1
	note C_, 1
	octave 4
	note B_, 12
	duty_cycle 3
	volume_envelope 10, 2
	octave 1
	note B_, 4
	octave 2
	note A_, 2
	octave 1
	note B_, 4
	octave 2
	note F_, 2
	octave 1
	note B_, 2
	octave 2
	note Ds, 2
gbs_lookofficer_Ch2.mainloop:
gbs_lookofficer_Ch2.loop1:
	note E_, 2
	note Gs, 2
	octave 3
	note E_, 2
	octave 2
	note E_, 2
	note Gs, 2
	note B_, 2
	note E_, 2
	note Gs, 2
	sound_loop 2, gbs_lookofficer_Ch2.loop1
	transpose 0, 1
	sound_call gbs_lookofficer_Ch2.sub1
	transpose 0, 0
	sound_call gbs_lookofficer_Ch2.sub1
	sound_loop 0, gbs_lookofficer_Ch2.mainloop

gbs_lookofficer_Ch2.sub1:
	octave 1
	note A_, 2
	octave 2
	note Cs, 2
	note A_, 2
	octave 1
	note A_, 2
	octave 2
	note Cs, 2
	note E_, 2
	octave 1
	note A_, 2
	octave 2
	note Cs, 2
	sound_ret

gbs_lookofficer_Ch3:
	gbs_switch 2
	vibrato 20, 1, 4
	stereo_panning TRUE, FALSE
	note_type 12, 1, 4
	rest 10
	octave 3
	note B_, 2
	rest 2
	note B_, 2
	volume_envelope 1, 2
	octave 5
	note Ds, 2
	rest 1
	note F_, 2
	rest 1
	note A_, 2
	note B_, 2
	rest 1
	octave 6
	note Cs, 2
	rest 1
	note Ds, 2
gbs_lookofficer_Ch3.mainloop:
	note E_, 6
	note Ds, 6
	note Cs, 4
	octave 5
	note B_, 2
	note A_, 2
	note Gs, 2
	note Fs, 2
	note Gs, 2
	note A_, 2
	note B_, 2
	octave 6
	note Cs, 2
	note F_, 8
	note D_, 8
	note E_, 8
	note Cs, 8
	sound_loop 0, gbs_lookofficer_Ch3.mainloop

	.align 4
	.global gbs_lookofficer_Header
gbs_lookofficer_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_lookofficer_Ch1
	.int gbs_lookofficer_Ch2
	.int gbs_lookofficer_Ch3
