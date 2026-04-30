	.include "asm/macros.inc"

	.section .rodata
	.align 1


gbs_route1_Ch1:
	gbs_switch 0
	stereo_panning FALSE, TRUE
	tempo 184
	volume 7, 7
	vibrato 22, 1, 1
	duty_cycle 3
	note_type 12, 8, 3
	octave 4
	note D_, 1
	note E_, 1
	note Fs, 2
	note Fs, 2
	note D_, 2
	octave 3
	note A_, 2
	octave 4
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note D_, 2
	octave 3
	note A_, 2
	note Fs, 2
	note G_, 1
	note A_, 1
	note G_, 2
	note E_, 2
	note G_, 1
	note E_, 1
	octave 4
	note D_, 1
	note E_, 1
	note Fs, 2
	note Fs, 2
	note D_, 2
	octave 3
	note A_, 2
	octave 4
	note B_, 2
	note A_, 2
	note G_, 3
	note E_, 1
	note E_, 2
	note G_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	volume_envelope 8, 1
	octave 5
	note D_, 2
	note D_, 2
	volume_envelope 8, 3
	rest 2
gbs_route1_Ch1.mainloop:
	volume_envelope 8, 3
	rest 2
	octave 4
	note D_, 2
	octave 3
	note A_, 2
	rest 4
	octave 4
	note D_, 2
	octave 3
	note A_, 2
	rest 2
	rest 2
	octave 4
	note D_, 2
	octave 3
	note A_, 3
	octave 4
	note D_, 1
	octave 3
	note E_, 2
	volume_envelope 8, 1
	note G_, 2
	note G_, 2
	volume_envelope 8, 3
	rest 2
	rest 2
	octave 4
	note Cs, 2
	octave 3
	note A_, 2
	rest 4
	octave 4
	note Cs, 2
	octave 3
	note A_, 2
	rest 2
	rest 2
	octave 4
	note Cs, 2
	note Cs, 1
	octave 3
	note B_, 1
	note A_, 1
	note G_, 1
	note Fs, 2
	note A_, 2
	octave 4
	note D_, 2
	rest 2
	rest 2
	octave 3
	note Fs, 1
	note G_, 1
	note A_, 4
	rest 2
	note D_, 1
	note E_, 1
	note Fs, 2
	note Fs, 1
	note G_, 1
	note A_, 2
	note A_, 1
	note B_, 1
	note A_, 2
	note A_, 1
	note B_, 1
	note A_, 2
	volume_envelope 8, 1
	octave 4
	note G_, 2
	note G_, 2
	volume_envelope 8, 3
	octave 3
	note Fs, 1
	note E_, 1
	rest 2
	note E_, 1
	note Fs, 1
	note G_, 6
	note E_, 1
	octave 2
	note B_, 1
	octave 3
	note Cs, 2
	note E_, 1
	note Fs, 1
	note G_, 4
	note_type 8, 8, 3
	note A_, 1
	note B_, 1
	note A_, 1
	note_type 12, 8, 3
	note G_, 1
	note E_, 1
	note Fs, 2
	volume_envelope 8, 1
	octave 4
	note A_, 2
	note A_, 2
	volume_envelope 8, 3
	octave 3
	note A_, 1
	note G_, 1
	volume_envelope 7, 7
	volume_envelope 1, -5
	note Fs, 4
	note A_, 4
	note G_, 2
	note Fs, 2
	note E_, 2
	note G_, 2
	note Fs, 4
	note A_, 3
	note Fs, 1
	note E_, 2
	note A_, 2
	octave 4
	note Cs, 2
	octave 3
	note A_, 1
	note G_, 1
	duty_cycle 2
	volume_envelope 8, 7
	octave 6
	note Fs, 4
	note A_, 4
	note G_, 2
	note Fs, 2
	note E_, 3
	note G_, 1
	note Fs, 2
	note D_, 2
	note E_, 2
	note Cs, 2
	note D_, 2
	volume_envelope 8, 1
	octave 5
	note D_, 2
	note D_, 2
	rest 2
	sound_loop 0, gbs_route1_Ch1.mainloop

gbs_route1_Ch2:
	gbs_switch 1
	stereo_panning TRUE, FALSE
	vibrato 18, 2, 2
	duty_cycle 2
	note_type 12, 9, 2
	octave 4
	note Fs, 1
	note G_, 1
	sound_call gbs_route1_Ch2.sub2
	octave 3
	note A_, 2
	note A_, 2
	octave 4
	note Fs, 1
	note G_, 1
	sound_call gbs_route1_Ch2.sub3
	note Cs, 2
	note E_, 2
	note D_, 2
	volume_envelope 8, 1
	note Fs, 2
	note Fs, 2
	volume_envelope 8, 2
	octave 4
	note D_, 1
	note E_, 1
	duty_cycle 2
gbs_route1_Ch2.mainloop:
	volume_envelope 8, 2
	sound_call gbs_route1_Ch2.sub1
	volume_envelope 8, 1
	octave 3
	note A_, 2
	note A_, 2
	volume_envelope 8, 2
	octave 4
	note Cs, 1
	note D_, 1
	note E_, 2
	note E_, 2
	note E_, 2
	note Cs, 1
	note D_, 1
	note E_, 2
	note E_, 2
	note E_, 2
	note Cs, 1
	note D_, 1
	note E_, 2
	note E_, 2
	note Fs, 1
	note E_, 1
	note E_, 1
	note Fs, 1
	note D_, 2
	rest 2
	note Fs, 2
	note D_, 1
	note E_, 1
	sound_call gbs_route1_Ch2.sub1
	volume_envelope 8, 1
	note A_, 2
	note A_, 2
	volume_envelope 8, 2
	note Cs, 1
	note D_, 1
	note E_, 2
	note G_, 2
	note Fs, 2
	note E_, 2
	note D_, 2
	note Cs, 2
	octave 3
	note B_, 2
	note A_, 2
	octave 4
	note B_, 4
	note_type 8, 9, 2
	note Cs, 1
	note D_, 1
	note Cs, 1
	note_type 12, 9, 2
	octave 3
	note B_, 1
	octave 4
	note Cs, 1
	note D_, 2
	volume_envelope 8, 1
	octave 5
	note D_, 2
	note D_, 2
	volume_envelope 8, 2
	octave 4
	note Fs, 1
	note G_, 1
	sound_call gbs_route1_Ch2.sub2
	rest 4
	note Fs, 1
	note G_, 1
	sound_call gbs_route1_Ch2.sub3
	note_type 8, 9, 2
	note Cs, 1
	note D_, 1
	note Cs, 1
	note_type 12, 9, 2
	octave 4
	note B_, 1
	octave 5
	note Cs, 1
	note D_, 2
	volume_envelope 8, 1
	note Fs, 2
	note Fs, 2
	volume_envelope 8, 2
	octave 4
	note D_, 1
	note E_, 1
	sound_loop 0, gbs_route1_Ch2.mainloop

gbs_route1_Ch2.sub1:
	note Fs, 2
	note Fs, 2
	note Fs, 2
	note D_, 1
	note E_, 1
	note Fs, 2
	note Fs, 2
	note Fs, 2
	note D_, 1
	note E_, 1
	note Fs, 2
	note Fs, 2
	note G_, 3
	note Fs, 1
	note E_, 2
	sound_ret

gbs_route1_Ch2.sub2:
	note A_, 2
	note A_, 2
	note Fs, 2
	note D_, 2
	octave 5
	note D_, 2
	note Cs, 2
	octave 4
	note B_, 2
	octave 5
	note D_, 2
	octave 4
	note A_, 2
	note Fs, 2
	note D_, 3
	note Fs, 1
	note E_, 2
	sound_ret

gbs_route1_Ch2.sub3:
	note A_, 2
	note A_, 2
	note Fs, 2
	note D_, 2
	octave 5
	note D_, 2
	note Cs, 2
	octave 4
	note B_, 3
	note G_, 1
	note A_, 2
	octave 5
	note D_, 2
	sound_ret

gbs_route1_Ch3:
	gbs_switch 2
	stereo_panning TRUE, TRUE
	vibrato 16, 2, 3
	note_type 12, 2, 5
	rest 2
	octave 3
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	octave 4
	note Fs, 1
	rest 3
	octave 3
	note D_, 1
	rest 1
	note B_, 1
	rest 1
	octave 4
	note G_, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	octave 4
	note D_, 1
	rest 3
	octave 3
	note Cs, 1
	rest 1
	note A_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note Cs, 1
	octave 3
	note A_, 1
	note D_, 1
	octave 2
	note A_, 1
	octave 3
	note D_, 1
	note Fs, 1
	octave 4
	note D_, 1
	octave 3
	note A_, 1
	note Fs, 1
	note A_, 1
	note G_, 1
	note D_, 1
	note G_, 1
	note B_, 1
	octave 4
	note G_, 1
	note D_, 1
	octave 3
	note B_, 1
	note G_, 1
	octave 2
	note A_, 1
	octave 3
	note Cs, 1
	note E_, 1
	note G_, 1
	note E_, 1
	note A_, 1
	octave 4
	note Cs, 1
	note G_, 1
	note Fs, 2
	note A_, 1
	rest 1
	note A_, 1
	rest 3
gbs_route1_Ch3.mainloop:
	octave 3
	note D_, 1
	rest 1
	octave 4
	note D_, 2
	octave 3
	note Cs, 1
	rest 1
	octave 4
	note Cs, 2
	octave 2
	note B_, 1
	rest 1
	octave 3
	note B_, 2
	octave 2
	note A_, 1
	rest 1
	octave 3
	note A_, 2
	note D_, 1
	rest 1
	octave 4
	note D_, 2
	octave 2
	note A_, 1
	rest 1
	octave 3
	note A_, 2
	octave 2
	note B_, 1
	rest 1
	octave 3
	note B_, 2
	octave 2
	note A_, 1
	rest 1
	octave 3
	note A_, 2
	note Cs, 1
	rest 1
	octave 4
	note Cs, 2
	octave 2
	note A_, 1
	rest 1
	octave 3
	note A_, 2
	octave 2
	note B_, 1
	rest 1
	octave 3
	note B_, 2
	note C_, 1
	rest 1
	octave 4
	note C_, 2
	octave 3
	note Cs, 1
	rest 1
	octave 4
	note Cs, 2
	octave 2
	note A_, 1
	rest 1
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	note Cs, 1
	octave 3
	note B_, 1
	note A_, 2
	note G_, 1
	note E_, 1
	octave 2
	note D_, 1
	rest 1
	octave 3
	note D_, 2
	octave 2
	note E_, 1
	rest 1
	octave 3
	note E_, 2
	octave 2
	note Fs, 1
	rest 1
	octave 3
	note Fs, 2
	octave 2
	note A_, 1
	rest 1
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	note Fs, 2
	note E_, 2
	octave 3
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	octave 4
	note E_, 2
	octave 3
	note Cs, 1
	rest 1
	octave 4
	note Cs, 2
	octave 2
	note B_, 1
	rest 1
	octave 3
	note B_, 2
	octave 2
	note A_, 1
	rest 1
	octave 3
	note A_, 2
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	note B_, 1
	octave 4
	note Cs, 2
	note E_, 1
	note Cs, 1
	octave 3
	note A_, 1
	note G_, 1
	note E_, 1
	note Cs, 1
	note D_, 2
	octave 4
	note Fs, 1
	rest 1
	note Fs, 1
	rest 3
	octave 3
	note D_, 4
	note Fs, 4
	note G_, 2
	note A_, 2
	note B_, 3
	note G_, 1
	note Fs, 2
	note D_, 2
	octave 2
	note A_, 3
	octave 3
	note D_, 1
	note A_, 1
	note B_, 1
	note A_, 1
	note B_, 1
	note A_, 3
	note G_, 1
	note Fs, 2
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	note G_, 2
	note Fs, 2
	note E_, 3
	note Cs, 1
	note D_, 2
	note Fs, 2
	note A_, 2
	octave 4
	note Cs, 2
	note D_, 2
	octave 5
	note A_, 1
	rest 1
	note A_, 1
	rest 3
	sound_loop 0, gbs_route1_Ch3.mainloop

	.align 4
	.global gbs_route1_Header
gbs_route1_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_route1_Ch1
	.int gbs_route1_Ch2
	.int gbs_route1_Ch3
