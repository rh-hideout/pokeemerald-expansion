	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_credits_Ch1:
	gbs_switch 0
	tempo 139
	volume 7, 7
	stereo_panning FALSE, TRUE
	duty_cycle 3
	note_type 12, 2, -7
	octave 2
	note G_, 16
	note_type 6, 10, 7
	octave 3
	note B_, 12
	note As, 2
	note A_, 2
	note B_, 1
	octave 4
	note C_, 7
	note D_, 8
	sound_call gbs_credits_Ch1.sub1
	rest 4
	octave 3
	note B_, 2
	rest 2
	note A_, 2
	note B_, 2
	rest 2
	note A_, 2
	note B_, 2
	volume_envelope 9, 6
	note A_, 1
	note G_, 1
	octave 3
	note D_, 1
	note C_, 1
	octave 2
	note B_, 1
	note A_, 1
	volume_envelope 9, 4
	note G_, 1
	note F_, 1
	note E_, 1
	note D_, 1
	note C_, 1
	octave 1
	note B_, 1
	note A_, 1
	octave 3
	rest 1
	volume_envelope 10, 7
	sound_call gbs_credits_Ch1.sub1
	sound_call gbs_credits_Ch1.sub2
	volume_envelope 9, 7
	sound_call gbs_credits_Ch1.sub3
	octave 3
	note B_, 2
	octave 4
	note G_, 2
	note D_, 2
	note G_, 2
	note F_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	octave 3
	note B_, 2
	octave 4
	note G_, 2
	note D_, 2
	note G_, 2
	octave 3
	note B_, 2
	octave 4
	note G_, 2
	note D_, 2
	note G_, 2
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note D_, 2
	note E_, 2
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note D_, 2
	note B_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note B_, 2
	note G_, 2
	note A_, 2
	note E_, 2
	note C_, 2
	note E_, 2
	note Gs, 2
	note E_, 2
	note C_, 2
	note E_, 2
	note G_, 2
	note E_, 2
	note C_, 2
	note E_, 2
	note Fs, 2
	note E_, 2
	note C_, 2
	octave 3
	note B_, 2
	sound_call gbs_credits_Ch1.sub3
	sound_call gbs_credits_Ch1.sub4
	note B_, 1
	octave 4
	note C_, 7
	note D_, 8
	volume_envelope 10, 7
	octave 5
	note E_, 2
	note Cs, 2
	octave 4
	note A_, 2
	note E_, 2
	octave 5
	note Cs, 2
	octave 4
	note A_, 2
	note E_, 2
	note Cs, 2
	note Cs, 1
	note D_, 7
	note E_, 7
	octave 3
	rest 1
	transpose 0, 2
	sound_call gbs_credits_Ch1.sub1
	sound_call gbs_credits_Ch1.sub2
	sound_call gbs_credits_Ch1.sub3
	sound_call gbs_credits_Ch1.sub4
	transpose 0, 0
	octave 3
	note A_, 12
	note_type 8, 10, 7
	note D_, 1
	note D_, 1
	note D_, 1
	sound_call gbs_credits_Ch1.sub5
	octave 3
	note B_, 6
	note A_, 6
	note A_, 6
	note G_, 6
	note As, 6
	note As, 6
	note A_, 6
	octave 4
	note Cs, 6
	sound_call gbs_credits_Ch1.sub5
	tempo 143
	octave 4
	note D_, 6
	octave 3
	note B_, 6
	note G_, 6
	octave 4
	note D_, 6
	tempo 146
	note E_, 6
	note Fs, 6
	note A_, 6
	octave 5
	note Cs, 6
	note_type 12, 10, 7
gbs_credits_Ch1.loop1:
	octave 3
	note A_, 1
	octave 4
	note D_, 1
	sound_loop 6, gbs_credits_Ch1.loop1
	note_type 8, 10, 7
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note Gs, 1
	rest 1
	tempo 153
	note_type 12, 10, 7
	octave 3
	note C_, 1
	note E_, 1
	note G_, 1
	octave 4
	note C_, 1
	octave 3
	note E_, 1
	note G_, 1
	octave 4
	note C_, 1
	note E_, 1
	octave 3
	note G_, 1
	octave 4
	note C_, 1
	note E_, 1
	note G_, 1
	note_type 8, 10, 7
	note C_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note_type 12, 10, 7
	octave 3
	note D_, 1
	note Fs, 1
	note A_, 1
	octave 4
	note D_, 1
	octave 3
	note Fs, 1
	note A_, 1
	octave 4
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note_type 8, 10, 7
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	tempo 160
	note_type 12, 10, 7
	octave 2
	note G_, 1
	rest 3
	note E_, 1
	rest 3
	note_type 8, 10, 7
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note Cs, 1
	rest 1
	note_type 12, 10, 7
	octave 2
	note D_, 1
	rest 7
	volume_envelope 12, 7
	octave 2
	note D_, 16
	volume_envelope 11, 8
	volume_envelope 11, 7
	rest 16
	rest 16
	rest 16
	sound_ret

gbs_credits_Ch1.sub1:
	note C_, 16
	note Fs, 1
	note G_, 3
	note E_, 4
	note D_, 4
	note E_, 4
	note D_, 4
	octave 3
	note B_, 2
	rest 2
	note As, 2
	note B_, 2
	rest 2
	note As, 2
	note B_, 4
	note G_, 4
	rest 4
	octave 4
	note D_, 4
	rest 4
	note E_, 4
	octave 3
	note As, 4
	note G_, 4
	note E_, 4
	note G_, 4
	octave 4
	note G_, 4
	note C_, 4
	note D_, 4
	note C_, 2
	rest 2
	octave 3
	note B_, 2
	octave 4
	note C_, 2
	rest 2
	octave 3
	note B_, 2
	octave 4
	note C_, 4
	octave 3
	note A_, 4
	rest 4
	octave 4
	note C_, 4
	octave 3
	note Gs, 8
	note F_, 4
	note C_, 7
	note Gs, 1
	note A_, 1
	note As, 7
	note Gs, 4
	rest 4
	octave 4
	note C_, 4
	octave 3
	note G_, 4
	note E_, 4
	note C_, 4
	note E_, 4
	note G_, 4
	octave 4
	note C_, 4
	octave 5
	note D_, 1
	rest 1
	octave 4
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	octave 5
	note D_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	octave 6
	note C_, 1
	rest 1
	sound_ret

gbs_credits_Ch1.sub2:
	octave 4
	note C_, 4
	octave 3
	note D_, 4
	note G_, 4
	note B_, 8
	octave 4
	note D_, 4
	note C_, 4
	note Ds, 4
	sound_ret

gbs_credits_Ch1.sub3:
	octave 3
	note A_, 2
	octave 4
	note E_, 2
	note C_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note C_, 2
	note E_, 2
	octave 3
	note A_, 2
	octave 4
	note E_, 2
	note D_, 2
	note E_, 2
	note A_, 4
	note B_, 2
	octave 5
	note C_, 2
	octave 4
	note B_, 2
	note G_, 2
	note F_, 2
	note D_, 2
	note G_, 2
	note F_, 2
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note F_, 2
	note D_, 2
	octave 3
	note B_, 2
	note G_, 2
	note B_, 2
	octave 4
	note D_, 2
	note F_, 2
	note Fs, 2
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note D_, 2
	note C_, 2
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note D_, 2
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note D_, 2
	note G_, 4
	note A_, 2
	note B_, 2
	octave 3
	note A_, 4
	octave 4
	note C_, 4
	note E_, 4
	octave 3
	note Gs, 8
	octave 4
	note C_, 8
	note E_, 4
	octave 3
	note A_, 2
	octave 4
	note F_, 2
	note C_, 2
	note F_, 2
	note D_, 2
	note F_, 2
	note C_, 2
	note F_, 2
	octave 3
	note A_, 2
	octave 4
	note F_, 2
	note C_, 2
	note F_, 2
	note E_, 2
	note F_, 2
	note C_, 2
	note F_, 2
	sound_ret

gbs_credits_Ch1.sub4:
	octave 3
	note A_, 2
	octave 4
	note Fs, 2
	note C_, 2
	note Fs, 2
	note D_, 2
	note Fs, 2
	note C_, 2
	note Fs, 2
	note E_, 2
	note Fs, 2
	note C_, 2
	note Fs, 2
	octave 3
	note A_, 2
	octave 4
	note Fs, 2
	note C_, 2
	note Fs, 2
	note C_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note F_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note F_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note C_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	octave 3
	note B_, 12
	note As, 2
	note A_, 2
	sound_ret

gbs_credits_Ch1.sub5:
	rest 6
	octave 3
	note D_, 6
	note E_, 6
	note F_, 6
	note Fs, 6
	note A_, 6
	octave 4
	note Fs, 6
	note Cs, 6
	sound_ret

gbs_credits_Ch2:
	gbs_switch 1
	duty_cycle 1
	vibrato 20, 2, 3
	note_type 12, 2, -7
	stereo_panning TRUE, FALSE
	octave 4
	note G_, 16
	volume_envelope 12, 7
	octave 5
	note G_, 8
	octave 3
	note G_, 4
	note F_, 4
	note_type 6, 12, 7
	sound_call gbs_credits_Ch2.sub1
	octave 1
	note G_, 2
	rest 2
	octave 2
	note G_, 2
	rest 2
	note Fs, 2
	note G_, 2
	rest 2
	octave 3
	note C_, 2
	octave 2
	note G_, 2
	rest 2
	note G_, 2
	rest 2
	note G_, 2
	volume_envelope 9, 7
	note Fs, 1
	note F_, 1
	note E_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	volume_envelope 12, 7
	sound_call gbs_credits_Ch2.sub1
	sound_call gbs_credits_Ch2.sub2
	sound_call gbs_credits_Ch2.sub3
	octave 4
	note B_, 1
	octave 5
	note C_, 11
	octave 4
	note B_, 8
	note A_, 8
	note B_, 4
	note Fs, 1
	note G_, 15
	note_type 12, 12, 7
	octave 5
	note E_, 15
	note_type 6, 12, 7
	note G_, 1
	note Gs, 1
	note A_, 2
	note E_, 2
	note C_, 2
	octave 4
	note A_, 2
	octave 5
	note E_, 2
	note C_, 2
	octave 4
	note A_, 2
	note E_, 2
	sound_call gbs_credits_Ch2.sub3
	octave 4
	note B_, 1
	octave 5
	note C_, 11
	octave 4
	note B_, 8
	octave 5
	note C_, 12
	note_type 12, 12, 7
	note D_, 16
	note G_, 8
	octave 3
	note G_, 4
	note F_, 4
	octave 5
	note A_, 1
	note E_, 1
	note Cs, 1
	octave 4
	note A_, 1
	octave 5
	note E_, 1
	note Cs, 1
	octave 4
	note A_, 1
	note E_, 1
	octave 3
	note A_, 4
	note G_, 4
	note_type 6, 12, 7
	transpose 0, 2
	sound_call gbs_credits_Ch2.sub1
	sound_call gbs_credits_Ch2.sub2
	sound_call gbs_credits_Ch2.sub3
	transpose 0, 0
	octave 5
	note Cs, 1
	note D_, 11
	note Cs, 8
	note D_, 12
	note_type 12, 12, 7
	note E_, 16
	note A_, 14
	note_type 8, 12, 7
	octave 2
	note D_, 1
	note D_, 1
	note D_, 1
	note D_, 6
	octave 3
	note Fs, 6
	note G_, 6
	note Gs, 6
	note A_, 6
	octave 4
	note Cs, 6
	note A_, 6
	note G_, 6
	note G_, 6
	note Fs, 6
	note Fs, 6
	note E_, 6
	note E_, 6
	note D_, 6
	note Cs, 6
	note E_, 6
	octave 1
	note D_, 3
	rest 3
	note D_, 3
	rest 3
	note D_, 3
	rest 3
	note D_, 3
	rest 3
	note Fs, 3
	rest 3
	note Fs, 3
	rest 3
	note Fs, 3
	note_type 12, 12, 7
	octave 2
	note Fs, 1
	rest 1
	octave 1
	note Fs, 2
	octave 2
	note Fs, 1
	rest 1
gbs_credits_Ch2.loop1:
	octave 1
	note G_, 2
	octave 2
	note G_, 1
	rest 1
	sound_loop 4, gbs_credits_Ch2.loop1
	octave 1
	note A_, 1
	octave 2
	note A_, 1
	note E_, 1
	note A_, 1
	octave 1
	note A_, 1
	octave 2
	note A_, 1
	note E_, 1
	note A_, 1
	octave 1
	note A_, 1
	octave 3
	note Cs, 1
	note E_, 1
	note G_, 1
	note E_, 1
	note G_, 1
	note A_, 1
	octave 4
	note Cs, 1
	octave 5
	note D_, 12
	note_type 8, 12, 7
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note Cs, 1
	rest 1
	note_type 12, 12, 7
	note D_, 12
	note_type 8, 12, 7
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note Cs, 1
	rest 1
	note D_, 9
	note_type 12, 12, 7
	octave 4
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note_type 8, 12, 7
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note_type 12, 12, 7
	note C_, 1
	rest 3
	note C_, 1
	rest 3
	note_type 8, 12, 7
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note Cs, 1
	rest 1
	note_type 12, 12, 7
	note D_, 1
	rest 7
	volume_envelope 12, 8
	volume_envelope 12, 7
	octave 1
	note D_, 16
	volume_envelope 12, 7
	rest 16
	rest 16
	rest 16
	sound_ret

gbs_credits_Ch2.sub1:
	octave 2
	note C_, 4
	volume_envelope 11, 1
	octave 5
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 2
	rest 2
	volume_envelope 12, 7
	octave 2
	note C_, 1
	rest 1
	note C_, 4
	rest 12
	octave 1
	note B_, 4
	rest 10
	note B_, 1
	rest 1
	note B_, 2
	rest 2
	note B_, 2
	rest 2
	octave 2
	note G_, 2
	octave 1
	note B_, 6
	note As, 4
	volume_envelope 11, 1
	octave 5
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note Ds, 1
	rest 1
	note E_, 2
	rest 2
	volume_envelope 12, 7
	octave 1
	note As, 1
	rest 1
	note As, 4
	rest 12
	note A_, 4
	rest 10
	note A_, 1
	rest 1
	note A_, 2
	rest 2
	note A_, 2
	rest 2
	octave 2
	note F_, 2
	octave 1
	note A_, 6
	note Gs, 4
	volume_envelope 11, 1
	octave 5
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	octave 4
	note B_, 1
	rest 1
	octave 5
	note C_, 2
	rest 2
	volume_envelope 12, 7
	octave 1
	note Gs, 1
	rest 1
	note Gs, 4
	rest 12
	note G_, 4
	rest 10
	note G_, 1
	rest 1
	note G_, 2
	rest 2
	note G_, 2
	rest 2
	octave 2
	note E_, 2
	octave 1
	note G_, 6
	note Fs, 4
	rest 2
	note Fs, 2
	note Fs, 2
	octave 2
	note D_, 2
	octave 1
	note Fs, 4
	note A_, 2
	octave 2
	note D_, 2
	note Fs, 2
	note A_, 2
	note D_, 2
	note Fs, 2
	note A_, 2
	octave 3
	note C_, 2
	sound_ret

gbs_credits_Ch2.sub2:
	octave 1
	note G_, 4
	rest 4
	note G_, 2
	rest 2
	octave 2
	note G_, 12
	note Fs, 8
	sound_ret

gbs_credits_Ch2.sub3:
	octave 4
	note A_, 8
	note B_, 8
	octave 5
	note C_, 8
	note E_, 8
	note_type 12, 12, 7
	note D_, 16
	octave 4
	note G_, 4
	note A_, 4
	note B_, 4
	octave 5
	note D_, 4
	note C_, 10
	note_type 6, 12, 7
	octave 4
	note B_, 1
	octave 5
	note C_, 3
	octave 4
	note B_, 4
	octave 5
	note C_, 4
	note_type 12, 12, 7
	octave 4
	note A_, 10
	note_type 6, 12, 7
	note Gs, 1
	note A_, 3
	note B_, 4
	octave 5
	note C_, 4
	sound_ret

gbs_credits_Ch3:
	gbs_switch 2
	vibrato 22, 2, 3
	note_type 12, 3, 4
	stereo_panning TRUE, TRUE
	octave 6
	note G_, 1
	note D_, 1
	note C_, 1
	octave 5
	note G_, 1
	octave 6
	note G_, 1
	note D_, 1
	note C_, 1
	octave 5
	note G_, 1
	volume_envelope 2, 4
	octave 6
	note G_, 1
	note D_, 1
	note C_, 1
	octave 5
	note G_, 1
	volume_envelope 1, 4
	octave 6
	note G_, 1
	note D_, 1
	note C_, 1
	octave 5
	note G_, 1
	octave 6
	note G_, 1
	note D_, 1
	octave 5
	note B_, 1
	note G_, 1
	octave 6
	note D_, 1
	octave 5
	note B_, 1
	note G_, 1
	note D_, 1
	note_type 6, 1, 4
	note Ds, 1
	note E_, 7
	note F_, 8
	sound_call gbs_credits_Ch3.sub1
	octave 4
	note G_, 1
	rest 1
	octave 5
	note G_, 1
	rest 1
	note Fs, 1
	note G_, 1
	rest 1
	note Fs, 1
	note G_, 1
	note_type 6, 1, 4
	volume_envelope 2, 4
	note F_, 1
	note E_, 1
	volume_envelope 1, 4
	note E_, 4
	rest 4
	note F_, 4
	sound_call gbs_credits_Ch3.sub1
	sound_call gbs_credits_Ch3.sub2
	sound_call gbs_credits_Ch3.sub3
	sound_call gbs_credits_Ch3.sub4
	octave 2
	note G_, 4
	rest 2
	note G_, 1
	rest 1
	note G_, 2
	octave 3
	note G_, 2
	rest 2
	octave 2
	note G_, 1
	rest 1
	note G_, 2
	octave 3
	note G_, 2
	octave 2
	note G_, 4
	note B_, 2
	octave 3
	note D_, 2
	note Fs, 2
	note G_, 2
	octave 2
	note E_, 4
	rest 2
	note E_, 1
	rest 1
	note E_, 2
	octave 3
	note E_, 2
	rest 2
	octave 2
	note E_, 1
	rest 1
	note E_, 2
	octave 3
	note E_, 2
	octave 2
	note E_, 4
	note Gs, 2
	note B_, 2
	octave 3
	note Ds, 2
	note E_, 2
	octave 2
	note A_, 4
	octave 3
	note E_, 2
	rest 2
	octave 2
	note Gs, 2
	octave 3
	note E_, 2
	rest 2
	octave 2
	note Gs, 2
	note G_, 2
	octave 3
	note E_, 2
	rest 2
	octave 2
	note G_, 2
	note Fs, 4
	octave 3
	note E_, 4
	sound_call gbs_credits_Ch3.sub3
	sound_call gbs_credits_Ch3.sub4
	sound_call gbs_credits_Ch3.sub5
	octave 5
	note Ds, 1
	note E_, 7
	note F_, 8
	octave 2
	note A_, 2
	rest 2
	octave 3
	note E_, 2
	rest 2
	note A_, 2
	rest 2
	octave 4
	note Cs, 2
	rest 2
	octave 5
	note F_, 1
	note Fs, 7
	note G_, 8
	transpose 0, 2
	sound_call gbs_credits_Ch3.sub1
	sound_call gbs_credits_Ch3.sub2
	transpose 1, 2
	sound_call gbs_credits_Ch3.sub3
	transpose 0, 2
	sound_call gbs_credits_Ch3.sub4
	sound_call gbs_credits_Ch3.sub5
	transpose 0, 0
	octave 6
	note Cs, 2
	octave 5
	note A_, 2
	note E_, 2
	note Cs, 2
	note A_, 2
	note E_, 2
	note_type 8, 1, 4
	octave 2
	note D_, 1
	note D_, 1
	note D_, 1
	note_type 12, 1, 4
	note D_, 16
	note Fs, 16
	note G_, 16
	note G_, 8
	note A_, 8
	rest 4
	octave 4
	note Fs, 4
	note G_, 4
	note Gs, 4
	note A_, 4
	octave 5
	note Cs, 4
	note A_, 4
	note G_, 4
	note G_, 4
	note Fs, 4
	note E_, 4
	note G_, 4
	note A_, 4
	note B_, 4
	octave 6
	note Cs, 4
	note E_, 4
	volume_envelope 1, 5
	octave 4
	note D_, 6
	note Fs, 2
	note A_, 8
	note E_, 6
	note G_, 2
	octave 5
	note C_, 6
	octave 4
	note B_, 1
	note As, 1
	note A_, 8
	volume_envelope 1, 4
	octave 2
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note_type 8, 1, 4
	octave 3
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note_type 12, 1, 4
	octave 5
	note G_, 1
	rest 3
	note E_, 1
	rest 3
	note_type 8, 1, 4
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note Gs, 1
	rest 1
	note_type 12, 1, 4
	note A_, 1
	rest 16
	rest 16
	rest 16
	sound_ret

gbs_credits_Ch3.sub1:
	note G_, 16
	octave 6
	note Cs, 1
	note D_, 3
	note C_, 4
	octave 5
	note B_, 4
	octave 6
	note C_, 4
	note_type 12, 1, 4
	octave 5
	note G_, 10
	note E_, 2
	rest 2
	note F_, 2
	note G_, 10
	note_type 6, 1, 4
	note Gs, 1
	note A_, 7
	note E_, 4
	note G_, 12
	note F_, 8
	note D_, 4
	rest 4
	note E_, 4
	note_type 12, 1, 4
	note F_, 10
	note_type 6, 1, 4
	note Fs, 1
	note G_, 7
	note F_, 4
	note E_, 4
	note Ds, 4
	note E_, 4
	note B_, 12
	note A_, 8
	note_type 12, 1, 4
	note D_, 16
	sound_ret

gbs_credits_Ch3.sub2:
	note_type 6, 1, 4
	note Fs, 1
	note G_, 3
	octave 4
	note G_, 4
	octave 5
	note D_, 4
	note G_, 12
	note Gs, 8
	sound_ret

gbs_credits_Ch3.sub3:
	octave 3
	note F_, 4
	rest 2
	note F_, 2
	rest 2
	octave 4
	note C_, 2
	octave 3
	note A_, 2
	note F_, 2
	octave 4
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note F_, 4
	note G_, 4
	rest 2
	note G_, 2
	rest 2
	octave 4
	note D_, 2
	octave 3
	note B_, 2
	note G_, 2
	octave 4
	note D_, 2
	rest 2
	note D_, 2
	rest 2
	octave 3
	note B_, 2
	octave 4
	note D_, 2
	octave 3
	note G_, 4
	note E_, 4
	rest 2
	note E_, 2
	rest 2
	note B_, 2
	note G_, 2
	note E_, 2
	note B_, 2
	rest 2
	note B_, 2
	rest 2
	note G_, 2
	note B_, 2
	note E_, 4
	note A_, 4
	rest 2
	note A_, 2
	rest 2
	octave 4
	note E_, 2
	note C_, 2
	octave 3
	note Gs, 2
	octave 4
	note C_, 2
	octave 3
	note Gs, 2
	rest 2
	note Gs, 2
	octave 4
	note C_, 2
	note E_, 2
	note C_, 2
	octave 3
	note Gs, 2
	sound_ret

gbs_credits_Ch3.sub4:
	octave 2
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note F_, 2
	octave 3
	note F_, 2
	rest 2
	octave 2
	note F_, 1
	rest 1
	note F_, 2
	octave 3
	note F_, 2
	octave 2
	note F_, 4
	note A_, 2
	octave 3
	note C_, 2
	note E_, 2
	note F_, 2
	sound_ret

gbs_credits_Ch3.sub5:
	octave 2
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	note Fs, 2
	octave 3
	note Fs, 2
	rest 2
	octave 2
	note Fs, 1
	rest 1
	note Fs, 2
	octave 3
	note Fs, 2
	octave 2
	note Fs, 4
	note A_, 2
	octave 3
	note C_, 2
	note F_, 2
	note Fs, 2
	note G_, 8
	octave 4
	note C_, 8
	note D_, 8
	note F_, 8
	octave 6
	note G_, 2
	note D_, 2
	octave 5
	note B_, 2
	note G_, 2
	octave 6
	note D_, 2
	octave 5
	note B_, 2
	note G_, 2
	note D_, 2
	sound_ret

gbs_credits_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	drum_note 9, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 9, 1
	drum_note 8, 1
	drum_note 12, 2
	drum_note 9, 1
	drum_note 8, 1
	drum_note 9, 1
	drum_note 8, 1
	drum_note 11, 4
	drum_note 11, 4
	sound_call gbs_credits_Ch4.sub1
	sound_call gbs_credits_Ch4.sub1
	sound_call gbs_credits_Ch4.sub1
	sound_call gbs_credits_Ch4.sub2
	sound_call gbs_credits_Ch4.sub1
	sound_call gbs_credits_Ch4.sub1
	sound_call gbs_credits_Ch4.sub1
	sound_call gbs_credits_Ch4.sub2
gbs_credits_Ch4.loop1:
	drum_note 11, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 11, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 7, gbs_credits_Ch4.loop1
	drum_note 9, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 7, 2
	drum_note 3, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 1
	drum_note 3, 1
gbs_credits_Ch4.loop2:
	drum_note 11, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 11, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 7, gbs_credits_Ch4.loop2
	drum_note 9, 1
	drum_note 8, 1
	drum_note 7, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 11, 4
	drum_note 2, 4
	drum_note 9, 1
	drum_note 8, 1
	drum_note 12, 2
	drum_note 9, 1
	drum_note 8, 1
	drum_note 12, 2
	drum_note 11, 4
	drum_note 11, 4
	sound_call gbs_credits_Ch4.sub1
	sound_call gbs_credits_Ch4.sub1
	sound_call gbs_credits_Ch4.sub1
	sound_call gbs_credits_Ch4.sub2
gbs_credits_Ch4.loop3:
	drum_note 11, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 11, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 7, gbs_credits_Ch4.loop3
	drum_note 9, 1
	drum_note 8, 1
	drum_note 7, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 7
	drum_speed 8
	drum_note 11, 1
	drum_note 11, 1
	drum_note 11, 1
	drum_speed 12
	drum_note 12, 16
	rest 16
	drum_note 12, 15
	rest 1
	drum_note 12, 8
	drum_note 12, 8
	drum_note 12, 16
	rest 16
	drum_note 12, 16
	drum_note 12, 8
	drum_note 12, 6
	drum_note 3, 1
	drum_note 3, 1
	drum_note 12, 12
	drum_speed 8
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_speed 12
	drum_note 12, 12
	drum_speed 8
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 12, 12
	drum_speed 12
	drum_note 3, 1
	rest 1
	drum_note 3, 1
	rest 1
	drum_speed 8
	drum_note 2, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_speed 12
	drum_note 3, 1
	rest 3
	drum_note 3, 1
	rest 3
	drum_speed 8
	drum_note 2, 2
	drum_note 2, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_speed 12
	drum_note 3, 1
	rest 7
	drum_note 11, 8
	rest 16
	rest 16
	rest 16
	sound_ret

gbs_credits_Ch4.sub1:
	drum_note 9, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 9, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 7, 2
	sound_ret

gbs_credits_Ch4.sub2:
	drum_note 9, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 9, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 9, 1
	drum_note 3, 1
	drum_note 7, 2
	drum_note 3, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 11, 1
	drum_note 3, 1
	sound_ret

	.align 4
	.global gbs_credits_Header
gbs_credits_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_credits_Ch1
	.int gbs_credits_Ch2
	.int gbs_credits_Ch3
	.int gbs_credits_Ch4
