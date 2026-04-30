	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_ecruteakcity_Ch1:
	gbs_switch 0
	tempo 197
	volume 7, 7
	stereo_panning FALSE, TRUE
	vibrato 18, 2, 5
	duty_cycle 2
gbs_ecruteakcity_Ch1.mainloop:
	note_type 12, 5, 7
	rest 10
	octave 4
	note C_, 6
	rest 10
	note C_, 6
	rest 16
	octave 3
	note B_, 4
	octave 4
	note C_, 4
	note D_, 4
	volume_envelope 6, 0
	rest 4
	rest 16
	rest 10
	note G_, 2
	note A_, 2
	note As, 2
	rest 8
	note Gs, 2
	note G_, 2
	note F_, 2
	octave 5
	note C_, 6
	note_type 6, 6, 7
	note Cs, 4
	note D_, 10
	rest 2
	stereo_panning TRUE, TRUE
	octave 4
	note B_, 8
	stereo_panning FALSE, TRUE
	octave 3
	note As, 1
	note B_, 11
	octave 4
	note C_, 4
	note E_, 4
	note G_, 12
	note As, 12
	note G_, 4
	rest 4
	note As, 4
	octave 5
	note Cs, 4
	note E_, 2
	rest 2
	octave 3
	note A_, 8
	octave 4
	note C_, 8
	note F_, 4
	rest 12
	note E_, 1
	note F_, 11
	note G_, 2
	rest 2
	note A_, 4
	note G_, 4
	rest 8
	volume_envelope 5, 2
	sound_call gbs_ecruteakcity_Ch1.sub1
	note D_, 2
	octave 4
	note B_, 2
	note A_, 2
	note B_, 2
	note A_, 2
	note B_, 2
	octave 5
	note D_, 2
	octave 4
	note B_, 2
	octave 5
	note D_, 2
	octave 4
	note B_, 2
	note A_, 2
	note B_, 2
	note A_, 2
	note B_, 2
	note A_, 2
	note B_, 2
	sound_call gbs_ecruteakcity_Ch1.sub2
	volume_envelope 5, 2
	note As, 2
	note G_, 2
	note E_, 2
	note Cs, 2
	note G_, 2
	note E_, 2
	note Cs, 2
	octave 4
	note As, 2
	octave 5
	note E_, 2
	note Cs, 2
	octave 4
	note As, 2
	note G_, 2
	note As, 2
	note G_, 2
	note E_, 2
	note Cs, 2
	sound_call gbs_ecruteakcity_Ch1.sub1
	note D_, 2
	note C_, 2
	octave 4
	note Gs, 2
	octave 5
	note C_, 2
	octave 4
	note Gs, 2
	octave 5
	note C_, 2
	note D_, 2
	note C_, 2
	note D_, 2
	note C_, 2
	octave 4
	note Gs, 2
	octave 5
	note C_, 2
	octave 4
	note Gs, 2
	octave 5
	note C_, 2
	octave 4
	note Gs, 2
	octave 5
	note C_, 2
	sound_call gbs_ecruteakcity_Ch1.sub2
	sound_loop 0, gbs_ecruteakcity_Ch1.mainloop

gbs_ecruteakcity_Ch1.sub1:
	octave 5
	note E_, 2
	note C_, 2
	octave 4
	note A_, 2
	octave 5
	note C_, 2
	octave 4
	note A_, 2
	octave 5
	note C_, 2
	note E_, 2
	note C_, 2
	sound_loop 2, gbs_ecruteakcity_Ch1.sub1
	sound_ret

gbs_ecruteakcity_Ch1.sub2:
	octave 5
	note D_, 2
	octave 4
	note B_, 2
	note G_, 2
	note B_, 2
	note G_, 2
	note B_, 2
	octave 5
	note D_, 2
	octave 4
	note B_, 2
	octave 5
	note D_, 2
	octave 4
	note B_, 2
	note G_, 2
	note B_, 2
	note G_, 2
	note B_, 2
	octave 5
	note D_, 2
	note F_, 2
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
	octave 5
	note C_, 2
	octave 4
	note A_, 2
	note E_, 2
	note C_, 2
	note A_, 2
	note E_, 2
	note C_, 2
	octave 3
	note A_, 2
gbs_ecruteakcity_Ch1.sub2loop1:
	octave 4
	note F_, 2
	note A_, 2
	octave 5
	note C_, 2
	octave 4
	note A_, 2
	octave 5
	note C_, 2
	octave 4
	note A_, 2
	octave 5
	note C_, 2
	note F_, 2
	sound_loop 2, gbs_ecruteakcity_Ch1.sub2loop1
gbs_ecruteakcity_Ch1.sub2loop2:
	octave 4
	note G_, 2
	note B_, 2
	octave 5
	note D_, 2
	octave 4
	note B_, 2
	octave 5
	note D_, 2
	octave 4
	note B_, 2
	octave 5
	note D_, 2
	note G_, 2
	sound_loop 2, gbs_ecruteakcity_Ch1.sub2loop2
	volume_envelope 5, 0
	duty_cycle 0
	note E_, 16
	note G_, 16
	duty_cycle 2
	sound_ret

gbs_ecruteakcity_Ch2:
	gbs_switch 1
	vibrato 18, 2, 5
	duty_cycle 3
	stereo_panning TRUE, FALSE
gbs_ecruteakcity_Ch2.mainloop:
	note_type 6, 6, 7
	rest 16
	rest 5
	octave 4
	note G_, 1
	octave 5
	note D_, 1
	note E_, 9
	rest 16
	rest 5
	octave 4
	note A_, 1
	octave 5
	note E_, 1
	note F_, 9
	note_type 12, 7, 7
	rest 10
	note D_, 2
	note C_, 2
	octave 4
	note Gs, 2
	note G_, 4
	note A_, 4
	note B_, 4
	note_type 6, 9, 3
	volume_envelope 9, 7
	duty_cycle 2
	octave 3
	note G_, 7
	octave 4
	note Cs, 1
	note D_, 11
	rest 1
	note C_, 2
	rest 2
	note C_, 16
	note F_, 8
	rest 4
	note E_, 4
	rest 4
	note E_, 4
	note F_, 4
	note G_, 4
	note E_, 4
	note C_, 2
	rest 2
	note C_, 4
	octave 3
	note A_, 2
	note F_, 1
	note A_, 1
	octave 4
	note C_, 16
	note E_, 4
	note G_, 2
	rest 2
	note E_, 4
	note D_, 10
	rest 1
	stereo_panning TRUE, TRUE
	note Ds, 9
	stereo_panning TRUE, FALSE
	duty_cycle 0
	octave 5
	note Cs, 1
	note D_, 11
	note C_, 2
	rest 2
	note C_, 16
	note F_, 12
	note E_, 4
	rest 4
	note E_, 4
	note F_, 4
	note G_, 2
	octave 4
	note A_, 1
	octave 5
	note C_, 1
	note E_, 1
	note A_, 3
	note E_, 2
	rest 2
	note E_, 4
	note C_, 2
	rest 2
	note C_, 4
	octave 4
	note A_, 2
	rest 2
	note B_, 4
	octave 5
	note C_, 2
	octave 4
	note G_, 1
	note B_, 1
	octave 5
	note Ds, 1
	note E_, 11
	note D_, 2
	rest 2
	note D_, 8
	duty_cycle 1
	octave 4
	note E_, 4
	note G_, 3
	note Gs, 1
	note A_, 16
	octave 3
	note A_, 4
	octave 4
	note C_, 2
	rest 2
	note E_, 4
	note D_, 12
	note C_, 4
	rest 4
	octave 3
	note B_, 4
	rest 4
	octave 4
	note F_, 8
	note G_, 12
	note F_, 8
	rest 4
	note E_, 8
	note D_, 4
	note C_, 2
	rest 2
	octave 3
	note B_, 4
	octave 4
	note C_, 2
	rest 6
	octave 3
	note B_, 4
	rest 4
	octave 4
	note C_, 4
	octave 3
	note A_, 16
	rest 4
	octave 4
	note F_, 4
	note E_, 4
	note D_, 4
	note C_, 12
	octave 3
	note B_, 4
	rest 4
	octave 4
	note C_, 4
	note D_, 4
	note Ds, 4
	note_type 12, 8, 3
	note E_, 16
	volume_envelope 8, 0
	note D_, 4
	note Cs, 4
	note F_, 4
	note_type 6, 8, 0
	note G_, 7
	note Gs, 1
	volume_envelope 8, 7
	note A_, 12
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note E_, 3
	note Gs, 1
	note A_, 4
	note E_, 2
	rest 2
	note E_, 4
	note D_, 2
	rest 2
	note Cs, 4
	note D_, 12
	octave 3
	note B_, 4
	octave 4
	note F_, 4
	note G_, 12
	note D_, 2
	rest 2
	note D_, 2
	rest 2
	note D_, 4
	note G_, 4
	note D_, 2
	rest 1
	note As, 1
	note B_, 12
	octave 5
	note C_, 4
	octave 4
	note A_, 8
	octave 3
	note A_, 4
	octave 4
	note C_, 4
	note_type 12, 8, 7
	note F_, 10
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 8
	rest 2
	octave 3
	note B_, 2
	octave 4
	note C_, 2
	note D_, 2
	note E_, 16
	sound_loop 0, gbs_ecruteakcity_Ch2.mainloop

gbs_ecruteakcity_Ch3:
	gbs_switch 2
	stereo_panning TRUE, TRUE
gbs_ecruteakcity_Ch3.mainloop:
	vibrato 18, 2, 5
	note_type 12, 2, 5
	octave 3
	note C_, 2
	note G_, 2
	octave 4
	note D_, 2
	note E_, 10
	octave 3
	note C_, 2
	note A_, 2
	octave 4
	note E_, 2
	note F_, 10
	octave 3
	note C_, 2
	note G_, 2
	octave 4
	note D_, 2
	note E_, 10
	note G_, 4
	note Fs, 4
	note F_, 4
	octave 3
	note B_, 2
	note G_, 2
	note C_, 2
	note G_, 2
	octave 4
	note D_, 2
	note E_, 10
	octave 3
	note Cs, 2
	note G_, 2
	note As, 2
	octave 4
	note D_, 2
	rest 2
	note Cs, 2
	note D_, 2
	note E_, 2
	octave 3
	note D_, 2
	note A_, 1
	rest 1
	octave 4
	note E_, 2
	note F_, 1
	rest 1
	note Gs, 8
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	note F_, 2
	note Gs, 2
	note B_, 2
	note G_, 1
	note Gs, 5
	octave 3
	note C_, 2
	note G_, 2
	octave 4
	note D_, 2
	note E_, 2
	note G_, 2
	octave 5
	note C_, 2
	note D_, 2
	note E_, 2
	octave 3
	note Cs, 2
	note As, 2
	octave 4
	note D_, 2
	note Cs, 2
	note E_, 2
	note D_, 2
	note F_, 2
	note G_, 1
	rest 1
	octave 3
	note F_, 8
	octave 4
	note A_, 2
	octave 5
	note C_, 1
	rest 1
	note D_, 2
	note E_, 1
	rest 1
	octave 2
	note G_, 2
	octave 3
	note D_, 2
	note G_, 2
	note Fs, 2
	note A_, 2
	note G_, 2
	note B_, 2
	octave 4
	note D_, 2
	sound_call gbs_ecruteakcity_Ch3.sub1
	octave 4
	note C_, 8
	note E_, 8
	note G_, 8
	note B_, 8
	note As, 8
	note G_, 8
	note E_, 8
	note Cs, 8
	note_type 12, 2, 5
	sound_call gbs_ecruteakcity_Ch3.sub1
	octave 4
	note C_, 8
	octave 3
	note G_, 8
	note E_, 8
	note D_, 8
	sound_loop 0, gbs_ecruteakcity_Ch3.mainloop

gbs_ecruteakcity_Ch3.sub1:
	octave 3
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note F_, 4
	rest 2
	note C_, 1
	rest 1
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 2
	rest 2
	note F_, 1
	rest 1
	note E_, 4
	rest 2
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note E_, 2
	rest 2
	note B_, 1
	rest 1
	note A_, 4
	rest 2
	note A_, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note D_, 4
	rest 2
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note F_, 1
	rest 1
	note G_, 4
	rest 2
	octave 4
	note D_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note A_, 1
	rest 1
	note As, 1
	note_type 6, 2, 5
	rest 1
	note B_, 1
	sound_ret

	.align 4
	.global gbs_ecruteakcity_Header
gbs_ecruteakcity_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_ecruteakcity_Ch1
	.int gbs_ecruteakcity_Ch2
	.int gbs_ecruteakcity_Ch3
