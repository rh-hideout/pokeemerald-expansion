	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_profoak_Ch1:
	gbs_switch 0
	tempo 118
	volume 7, 7
	vibrato 18, 3, 4
	pitch_offset 1
	stereo_panning TRUE, FALSE
	duty_cycle 3
	note_type 12, 9, 8
	octave 2
	note Fs, 1
	note B_, 1
	octave 3
	note Ds, 1
	note Fs, 1
	note A_, 16
	note Gs, 8
	volume_envelope 9, 7
	note Gs, 8
gbs_profoak_Ch1.loop1:
	volume_envelope 9, 1
	sound_call gbs_profoak_Ch1.sub1
	sound_call gbs_profoak_Ch1.sub1
	sound_call gbs_profoak_Ch1.sub2
	sound_call gbs_profoak_Ch1.sub2
	sound_loop 2, gbs_profoak_Ch1.loop1
gbs_profoak_Ch1.mainloop:
	sound_call gbs_profoak_Ch1.sub3
	sound_call gbs_profoak_Ch1.sub3
	sound_call gbs_profoak_Ch1.sub4
	sound_call gbs_profoak_Ch1.sub4
	transpose 0, 2
	sound_call gbs_profoak_Ch1.sub3
	sound_call gbs_profoak_Ch1.sub3
	transpose 0, 0
	sound_call gbs_profoak_Ch1.sub4
	sound_call gbs_profoak_Ch1.sub4
	sound_loop 0, gbs_profoak_Ch1.mainloop

gbs_profoak_Ch1.sub1:
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	note Gs, 2
	note E_, 2
	note B_, 2
	note E_, 2
	note Gs, 2
	note E_, 2
	sound_ret

gbs_profoak_Ch1.sub2:
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	note Fs, 2
	note Ds, 2
	note B_, 2
	note Ds, 2
	note Fs, 2
	note Ds, 2
	sound_ret

gbs_profoak_Ch1.sub3:
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	note E_, 2
	note Cs, 1
	note E_, 1
	note Cs, 2
	volume_envelope 9, 2
	note A_, 2
	volume_envelope 9, 1
	note Cs, 2
	volume_envelope 9, 2
	note E_, 2
	volume_envelope 9, 1
	sound_ret

gbs_profoak_Ch1.sub4:
	octave 2
	note B_, 1
	octave 3
	note E_, 1
	volume_envelope 9, 2
	note Gs, 4
	note E_, 4
	volume_envelope 9, 1
	note E_, 1
	note Gs, 1
	volume_envelope 9, 2
	note B_, 4
	volume_envelope 9, 1
	sound_ret

gbs_profoak_Ch2:
	gbs_switch 1
	vibrato 18, 3, 4
	duty_cycle 3
	note_type 12, 10, 8
	octave 3
	note B_, 1
	octave 4
	note Ds, 1
	note Fs, 1
	note As, 1
	note B_, 16
	volume_envelope 10, 7
	note B_, 10
	duty_cycle 2
gbs_profoak_Ch2.loop1:
	volume_envelope 11, 2
	octave 3
	note B_, 2
	octave 4
	note Cs, 2
	note Ds, 2
	note E_, 4
	note Ds, 2
	note Cs, 4
	volume_envelope 9, 1
	note B_, 2
	octave 5
	note Cs, 2
	note Ds, 2
	note E_, 4
	note Ds, 2
	note Cs, 4
	volume_envelope 11, 2
	octave 3
	note B_, 2
	note A_, 2
	note Gs, 2
	note A_, 4
	note B_, 1
	rest 1
	note B_, 4
	volume_envelope 9, 1
	octave 4
	note B_, 2
	note A_, 2
	note Gs, 2
	note A_, 4
	note B_, 2
	note B_, 4
	sound_loop 2, gbs_profoak_Ch2.loop1
	rest 6
	volume_envelope 11, 4
gbs_profoak_Ch2.mainloop:
	note Cs, 6
	octave 3
	note A_, 1
	octave 4
	note Cs, 1
	note E_, 6
	note Cs, 1
	note E_, 1
	note Fs, 4
	note E_, 4
	note Ds, 4
	note Cs, 4
	octave 3
	note B_, 6
	note Gs, 1
	note B_, 1
	octave 4
	note E_, 8
	volume_envelope 8, 2
	note B_, 6
	note Gs, 1
	note B_, 1
	volume_envelope 8, 3
	octave 5
	note E_, 8
	volume_envelope 11, 4
	octave 3
	note A_, 6
	note Fs, 1
	note A_, 1
	octave 4
	note Ds, 8
	note E_, 4
	note Ds, 4
	note Cs, 4
	note C_, 4
	octave 3
	note B_, 6
	note Gs, 1
	note B_, 1
	octave 4
	note E_, 6
	octave 3
	note B_, 1
	octave 4
	note E_, 1
	note Gs, 16
	sound_loop 0, gbs_profoak_Ch2.mainloop

gbs_profoak_Ch3:
	gbs_switch 2
	stereo_panning FALSE, TRUE
	note_type 12, 1, 4
	rest 4
	octave 3
	note E_, 2
	rest 2
	octave 4
	note E_, 1
	rest 1
	octave 3
	note A_, 2
	rest 2
	octave 2
	note B_, 2
	octave 3
	note B_, 1
	rest 1
	note E_, 2
	sound_call gbs_profoak_Ch3.sub1
gbs_profoak_Ch3.loop1:
	sound_call gbs_profoak_Ch3.sub1
	sound_call gbs_profoak_Ch3.sub1
	sound_call gbs_profoak_Ch3.sub2
	sound_call gbs_profoak_Ch3.sub2
	sound_loop 2, gbs_profoak_Ch3.loop1
gbs_profoak_Ch3.mainloop:
	sound_call gbs_profoak_Ch3.sub3
	sound_call gbs_profoak_Ch3.sub3
	sound_call gbs_profoak_Ch3.sub4
	sound_call gbs_profoak_Ch3.sub4
	transpose 0, 2
	sound_call gbs_profoak_Ch3.sub3
	sound_call gbs_profoak_Ch3.sub3
	transpose 0, 0
	sound_call gbs_profoak_Ch3.sub4
	sound_call gbs_profoak_Ch3.sub4
	sound_loop 0, gbs_profoak_Ch3.mainloop

gbs_profoak_Ch3.sub1:
	note E_, 2
	rest 2
	octave 4
	note E_, 1
	rest 1
	octave 3
	note Gs, 2
	rest 2
	octave 2
	note B_, 2
	octave 3
	note B_, 1
	rest 1
	note E_, 2
	sound_ret

gbs_profoak_Ch3.sub2:
	octave 2
	note B_, 2
	rest 2
	octave 4
	note Ds, 1
	rest 1
	octave 3
	note Ds, 2
	rest 2
	note Fs, 2
	note B_, 1
	rest 1
	note Ds, 2
	sound_ret

gbs_profoak_Ch3.sub3:
	octave 2
	note A_, 2
	rest 2
	octave 3
	note A_, 1
	rest 1
	octave 2
	note A_, 2
	rest 2
	octave 3
	note E_, 2
	note A_, 1
	rest 1
	note Cs, 2
	sound_ret

gbs_profoak_Ch3.sub4:
	octave 2
	note Gs, 2
	rest 2
	octave 3
	note Gs, 1
	rest 1
	octave 2
	note Gs, 2
	rest 2
	octave 3
	note E_, 2
	note Gs, 1
	rest 1
	octave 2
	note B_, 2
	sound_ret

	.align 4
	.global gbs_profoak_Header
gbs_profoak_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_profoak_Ch1
	.int gbs_profoak_Ch2
	.int gbs_profoak_Ch3
