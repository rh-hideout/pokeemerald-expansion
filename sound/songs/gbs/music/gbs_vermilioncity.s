	.include "asm/macros.inc"

	.section .rodata
	.align 1


gbs_vermilioncity_Ch1:
	gbs_switch 0
	stereo_panning FALSE, TRUE
	tempo 176
	volume 7, 7
	duty_cycle 2
	note_type 12, 6, 5
	octave 4
	note B_, 4
	note Gs, 4
	note Fs, 4
	note E_, 4
	note D_, 4
	octave 3
	note B_, 4
	note A_, 2
	note B_, 1
	octave 4
	note D_, 1
	note E_, 1
	note Gs, 1
	note B_, 1
	octave 5
	note D_, 1
	vibrato 16, 2, 3
gbs_vermilioncity_Ch1.mainloop:
	duty_cycle 1
	note_type 12, 8, 5
	sound_call gbs_vermilioncity_Ch1.sub1
	note F_, 4
	octave 4
	note D_, 4
	note Cs, 4
	note E_, 4
	sound_call gbs_vermilioncity_Ch1.sub1
	sound_call gbs_vermilioncity_Ch1.sub2
	duty_cycle 2
	note_type 12, 8, 5
	sound_call gbs_vermilioncity_Ch1.sub1
	note F_, 4
	octave 4
	note D_, 4
	note E_, 1
	note Cs, 1
	octave 3
	note A_, 1
	note E_, 1
	octave 4
	note Cs, 1
	octave 3
	note A_, 1
	note E_, 1
	note C_, 1
	sound_call gbs_vermilioncity_Ch1.sub1
	sound_call gbs_vermilioncity_Ch1.sub2
	volume_envelope 9, 3
	duty_cycle 0
	rest 2
	note Fs, 2
	rest 2
	note Fs, 2
	rest 2
	note Fs, 2
	rest 2
	note Fs, 2
	sound_call gbs_vermilioncity_Ch1.sub3
	sound_call gbs_vermilioncity_Ch1.sub3
	volume_envelope 8, 7
	duty_cycle 2
	octave 4
	note D_, 8
	octave 3
	note Gs, 8
	note E_, 8
	note B_, 8
	note A_, 4
	note Gs, 4
	note Fs, 4
	note E_, 4
	octave 2
	note B_, 4
	note Gs, 4
	note B_, 4
	octave 3
	note D_, 4
	sound_loop 0, gbs_vermilioncity_Ch1.mainloop

gbs_vermilioncity_Ch1.sub1:
	octave 3
	note Cs, 4
	note E_, 4
	note Fs, 2
	note A_, 2
	note E_, 2
	note Gs, 2
	sound_ret

gbs_vermilioncity_Ch1.sub2:
	note D_, 2
	note F_, 2
	note A_, 2
	octave 4
	note D_, 2
	note E_, 2
	note Cs, 2
	octave 3
	note A_, 2
	note E_, 2
	sound_ret

gbs_vermilioncity_Ch1.sub3:
	rest 2
	note Fs, 2
	note A_, 2
	note Fs, 2
	octave 4
	note D_, 2
	octave 3
	note Fs, 2
	note A_, 2
	note Fs, 2
	rest 2
	note Gs, 2
	note B_, 2
	note Gs, 2
	octave 4
	note E_, 2
	octave 3
	note Gs, 2
	note B_, 2
	note Gs, 2
	sound_ret

gbs_vermilioncity_Ch2:
	gbs_switch 1
	stereo_panning TRUE, TRUE
	duty_cycle 3
	note_type 12, 7, 7
	vibrato 16, 2, 3
	octave 5
	note E_, 4
	note D_, 4
	octave 4
	note B_, 4
	note Gs, 4
	note Fs, 4
	note E_, 4
	note Fs, 4
	note Gs, 4
gbs_vermilioncity_Ch2.mainloop:
	note_type 12, 9, 7
	sound_call gbs_vermilioncity_Ch2.sub1
	note Gs, 2
	sound_call gbs_vermilioncity_Ch2.sub1
	note E_, 2
	volume_envelope 11, 7
	octave 3
	note B_, 4
	octave 4
	note Cs, 4
	note D_, 4
	note E_, 4
	sound_call gbs_vermilioncity_Ch2.sub2
	sound_call gbs_vermilioncity_Ch2.sub2
	note Fs, 6
	note E_, 1
	note Fs, 1
	note E_, 8
	note A_, 6
	note Gs, 1
	note A_, 1
	note Gs, 8
	note Gs, 14
	note_type 6, 5, 7
	rest 1
	octave 4
	note E_, 1
	note Gs, 1
	note B_, 1
	note_type 12, 8, 7
	octave 5
	note E_, 16
	sound_loop 0, gbs_vermilioncity_Ch2.mainloop

gbs_vermilioncity_Ch2.sub1:
	octave 1
	note A_, 8
	octave 2
	note Fs, 4
	note E_, 4
	note D_, 6
	note Cs, 1
	note D_, 1
	note E_, 8
	octave 1
	note A_, 8
	octave 2
	note Fs, 4
	note E_, 4
	note D_, 6
	note E_, 1
	note D_, 1
	note Cs, 2
	note E_, 2
	octave 1
	note A_, 2
	sound_ret

gbs_vermilioncity_Ch2.sub2:
	note Fs, 8
	note B_, 8
	note A_, 4
	note Gs, 4
	note Fs, 4
	note E_, 4
	sound_ret

gbs_vermilioncity_Ch3:
	gbs_switch 2
	stereo_panning TRUE, FALSE
	vibrato 34, 2, 3
	note_type 12, 2, 5
	octave 2
	note E_, 4
	note B_, 4
	octave 3
	note E_, 4
	note B_, 4
	note D_, 4
	note E_, 4
	note D_, 2
	octave 3
	note B_, 1
	note Gs, 1
	note Fs, 1
	note E_, 1
	note D_, 1
	octave 2
	note B_, 1
gbs_vermilioncity_Ch3.mainloop:
	note_type 12, 2, 2
	sound_call gbs_vermilioncity_Ch3.sub1
	octave 5
	note A_, 6
	volume_envelope 2, 4
	note E_, 1
	note Gs, 1
	sound_call gbs_vermilioncity_Ch3.sub1
	note A_, 8
	volume_envelope 1, 4
	octave 3
	note D_, 4
	note Cs, 4
	octave 2
	note B_, 4
	note A_, 4
	octave 3
	note D_, 2
	rest 4
	note D_, 1
	note D_, 1
	sound_call gbs_vermilioncity_Ch3.sub2
	octave 4
	note D_, 2
	octave 3
	note D_, 2
	rest 2
	note D_, 2
	sound_call gbs_vermilioncity_Ch3.sub2
	volume_envelope 2, 5
	octave 3
	note E_, 8
	octave 4
	note E_, 8
	octave 3
	note B_, 8
	octave 4
	note E_, 8
	octave 2
	note E_, 16
	octave 3
	note E_, 14
	volume_envelope 2, 2
	octave 5
	note E_, 1
	note Gs, 1
	sound_loop 0, gbs_vermilioncity_Ch3.mainloop

gbs_vermilioncity_Ch3.sub1:
	octave 5
	note A_, 8
	octave 6
	note D_, 4
	note Cs, 4
	octave 5
	note B_, 6
	note A_, 1
	note B_, 1
	octave 6
	note Cs, 8
	octave 5
	note A_, 8
	octave 6
	note D_, 4
	note Cs, 4
	octave 5
	note B_, 6
	octave 6
	note Cs, 1
	octave 5
	note B_, 1
	sound_ret

gbs_vermilioncity_Ch3.sub2:
	note A_, 1
	rest 1
	note A_, 2
	rest 2
	note Fs, 2
	note E_, 2
	rest 4
	note E_, 1
	note E_, 1
	octave 4
	note E_, 1
	rest 1
	note D_, 2
	rest 2
	octave 3
	note B_, 1
	octave 4
	note Cs, 1
	sound_ret

	.align 4
	.global gbs_vermilioncity_Header
gbs_vermilioncity_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_vermilioncity_Ch1
	.int gbs_vermilioncity_Ch2
	.int gbs_vermilioncity_Ch3
