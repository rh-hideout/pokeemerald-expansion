	.include "asm/macros.inc"

	.section .rodata
	.align 1


gbs_lavendertown_Ch1:
	gbs_switch 0
	tempo 160
	volume 7, 7
	stereo_panning FALSE, TRUE
	vibrato 6, 2, 4
	duty_cycle 0
	note_type 12, 11, 3
	rest 16
	rest 16
	rest 16
	rest 16
gbs_lavendertown_Ch1.mainloop:
	sound_call gbs_lavendertown_Ch1.sub1
	volume_envelope 9, 3
	octave 5
	note D_, 2
	volume_envelope 4, 3
	note D_, 2
	volume_envelope 9, 3
	note Fs, 2
	volume_envelope 4, 3
	note Fs, 2
	volume_envelope 9, 3
	note B_, 2
	volume_envelope 4, 3
	note B_, 2
	volume_envelope 9, 3
	note A_, 2
	volume_envelope 4, 3
	note A_, 2
	sound_call gbs_lavendertown_Ch1.sub2
	volume_envelope 9, 3
	volume_envelope 9, 3
	note F_, 2
	volume_envelope 8, 3
	note F_, 2
	volume_envelope 9, 3
	note D_, 2
	volume_envelope 4, 3
	note D_, 2
	volume_envelope 9, 3
	octave 4
	note B_, 2
	volume_envelope 4, 3
	note B_, 2
	volume_envelope 9, 3
	note G_, 2
	volume_envelope 4, 3
	note G_, 2
	sound_call gbs_lavendertown_Ch1.sub1
	volume_envelope 9, 3
	octave 5
	note D_, 2
	volume_envelope 4, 3
	note D_, 2
	volume_envelope 9, 3
	note G_, 2
	volume_envelope 4, 3
	note G_, 2
	volume_envelope 9, 3
	note B_, 2
	volume_envelope 4, 3
	note B_, 2
	volume_envelope 9, 3
	note G_, 2
	volume_envelope 4, 3
	note G_, 2
	sound_call gbs_lavendertown_Ch1.sub2
	volume_envelope 9, 3
	octave 6
	note C_, 2
	volume_envelope 4, 3
	note C_, 2
	volume_envelope 9, 3
	octave 5
	note G_, 2
	volume_envelope 4, 3
	note G_, 2
	volume_envelope 9, 3
	note E_, 2
	volume_envelope 4, 3
	note E_, 2
	volume_envelope 9, 3
	note C_, 2
	volume_envelope 4, 3
	note C_, 2
	octave 3
	note F_, 2
	note A_, 2
	octave 4
	note C_, 2
	note E_, 2
	note F_, 2
	note C_, 2
	octave 3
	note A_, 2
	note F_, 2
gbs_lavendertown_Ch1.loop1:
	octave 3
	note C_, 2
	note E_, 2
	note G_, 2
	note B_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	note E_, 2
	note C_, 2
	note F_, 2
	note A_, 2
	octave 4
	note C_, 2
	note E_, 2
	note F_, 2
	note C_, 2
	octave 3
	note A_, 2
	note F_, 2
	sound_loop 2, gbs_lavendertown_Ch1.loop1
	note Fs, 2
	note A_, 2
	octave 4
	note C_, 2
	note Fs, 2
	note A_, 2
	note C_, 2
	octave 3
	note A_, 2
	note Fs, 2
	note G_, 2
	octave 4
	note C_, 2
	note D_, 2
	note F_, 2
	note G_, 2
	note F_, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 8
	note B_, 8
	sound_loop 0, gbs_lavendertown_Ch1.mainloop

gbs_lavendertown_Ch1.sub1:
	volume_envelope 8, 3
	octave 5
	note C_, 2
	volume_envelope 4, 3
	note C_, 2
	volume_envelope 8, 3
	note G_, 2
	volume_envelope 4, 3
	note G_, 2
	volume_envelope 8, 3
	octave 6
	note C_, 2
	volume_envelope 4, 3
	note C_, 2
	volume_envelope 8, 3
	octave 5
	note G_, 2
	volume_envelope 4, 3
	note G_, 2
	volume_envelope 8, 3
	note D_, 2
	volume_envelope 4, 3
	note D_, 2
	volume_envelope 8, 3
	note A_, 2
	volume_envelope 4, 3
	note A_, 2
	volume_envelope 8, 3
	octave 6
	note D_, 2
	volume_envelope 4, 3
	note D_, 2
	volume_envelope 8, 3
	octave 5
	note A_, 2
	volume_envelope 4, 3
	note A_, 2
	volume_envelope 8, 3
	note E_, 2
	volume_envelope 4, 3
	note E_, 2
	volume_envelope 8, 3
	note B_, 2
	volume_envelope 4, 3
	note B_, 2
	volume_envelope 8, 3
	octave 6
	note E_, 2
	volume_envelope 4, 3
	note E_, 2
	volume_envelope 8, 3
	octave 5
	note B_, 2
	volume_envelope 4, 3
	note B_, 2
	volume_envelope 8, 3
	note Cs, 2
	volume_envelope 4, 3
	note Cs, 2
	volume_envelope 8, 3
	note G_, 2
	volume_envelope 4, 3
	note G_, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 4, 3
	note As, 2
	volume_envelope 8, 3
	note G_, 2
	volume_envelope 4, 3
	note G_, 2
	volume_envelope 8, 3
	note C_, 2
	volume_envelope 4, 3
	note C_, 2
	volume_envelope 8, 3
	note F_, 2
	volume_envelope 4, 3
	note F_, 2
	volume_envelope 8, 3
	octave 6
	note C_, 2
	volume_envelope 4, 3
	note C_, 2
	volume_envelope 8, 3
	octave 5
	note F_, 2
	volume_envelope 4, 3
	note F_, 2
	sound_ret

gbs_lavendertown_Ch1.sub2:
	volume_envelope 9, 3
	octave 5
	note G_, 2
	volume_envelope 8, 3
	note G_, 2
	volume_envelope 8, 3
	note F_, 2
	volume_envelope 4, 3
	note F_, 2
	volume_envelope 8, 3
	note D_, 2
	volume_envelope 4, 3
	note D_, 2
	volume_envelope 8, 3
	note G_, 2
	volume_envelope 4, 3
	note G_, 2
	sound_ret

gbs_lavendertown_Ch2:
	gbs_switch 1
	duty_cycle 1
	vibrato 8, 2, 4
	stereo_panning TRUE, TRUE
gbs_lavendertown_Ch2.loop1:
	note_type 12, 10, 3
	octave 5
	note C_, 2
	volume_envelope 6, 3
	note C_, 2
	volume_envelope 10, 3
	note G_, 2
	volume_envelope 6, 3
	note G_, 2
	volume_envelope 10, 3
	note B_, 2
	volume_envelope 6, 3
	note B_, 2
	volume_envelope 10, 3
	note Fs, 2
	volume_envelope 6, 3
	note Fs, 2
	sound_loop 3, gbs_lavendertown_Ch2.loop1
	volume_envelope 10, 3
	note C_, 2
	volume_envelope 6, 3
	note C_, 2
	volume_envelope 10, 3
	note G_, 2
	volume_envelope 6, 3
	note G_, 2
	volume_envelope 10, 3
	note B_, 2
	volume_envelope 6, 3
	note B_, 2
	volume_envelope 10, 3
	octave 6
	note D_, 2
	volume_envelope 6, 3
	note D_, 2
gbs_lavendertown_Ch2.mainloop:
	volume_envelope 11, 5
	sound_call gbs_lavendertown_Ch2.sub1
	octave 2
	note Fs, 4
	octave 3
	note C_, 4
	note Fs, 4
	note A_, 4
	octave 2
	note G_, 4
	octave 3
	note C_, 4
	note D_, 4
	note G_, 4
	note F_, 4
	note D_, 4
	octave 2
	note B_, 4
	note G_, 4
	sound_call gbs_lavendertown_Ch2.sub1
	octave 2
	note G_, 4
	octave 3
	note C_, 4
	note F_, 4
	note G_, 4
	note C_, 4
	note F_, 4
	note G_, 4
	note F_, 4
	note C_, 4
	note E_, 4
	note G_, 4
	octave 4
	note C_, 4
	volume_envelope 11, 7
	octave 2
	note F_, 16
	note C_, 16
	note F_, 16
	note C_, 16
	note F_, 16
	note Fs, 16
	note G_, 16
	octave 1
	note G_, 8
	volume_envelope 5, 7
	octave 5
	note D_, 1
	note F_, 1
	note G_, 6
	sound_loop 0, gbs_lavendertown_Ch2.mainloop

gbs_lavendertown_Ch2.sub1:
	octave 2
	note C_, 4
	note G_, 4
	octave 3
	note E_, 4
	octave 2
	note G_, 4
	note D_, 4
	note A_, 4
	octave 3
	note F_, 4
	octave 2
	note A_, 4
	note E_, 4
	note B_, 4
	octave 3
	note G_, 4
	note F_, 4
	note E_, 4
	note Cs, 4
	octave 2
	note As, 4
	note G_, 4
	note F_, 4
	octave 3
	note C_, 4
	note A_, 4
	note C_, 4
	sound_ret

gbs_lavendertown_Ch3:
	gbs_switch 2
	vibrato 18, 2, 4
	note_type 12, 1, 3
	stereo_panning TRUE, FALSE
	rest 16
	rest 16
	rest 16
	rest 8
	octave 5
	note E_, 4
	note F_, 4
gbs_lavendertown_Ch3.mainloop:
	volume_envelope 1, 2
	octave 5
	note G_, 4
	rest 4
	note G_, 4
	rest 4
	note E_, 4
	rest 4
	note E_, 4
	note F_, 4
	note G_, 4
	note F_, 4
	note E_, 4
	note B_, 4
	note Cs, 8
	rest 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note F_, 10
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 8
	octave 4
	note A_, 4
	octave 5
	note D_, 4
	note E_, 12
	note F_, 2
	note E_, 2
	note D_, 12
	note E_, 2
	note F_, 2
	note G_, 4
	rest 4
	note G_, 4
	rest 4
	note E_, 4
	rest 4
	note E_, 4
	note F_, 4
	note G_, 4
	note F_, 4
	note E_, 4
	note B_, 4
	note Cs, 8
	rest 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note F_, 10
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 12
	note C_, 2
	note D_, 2
	note C_, 16
	note C_, 12
	rest 4
	volume_envelope 2, 4
	note A_, 2
	note G_, 2
	note A_, 2
	note B_, 2
	octave 6
	note C_, 4
	octave 5
	note G_, 4
	note F_, 4
	note E_, 4
	note D_, 4
	note C_, 4
	note A_, 2
	note G_, 2
	note A_, 2
	note B_, 2
	octave 6
	note C_, 4
	octave 5
	note G_, 4
	octave 6
	note F_, 4
	note_type 8, 2, 4
	note E_, 2
	note F_, 2
	note E_, 2
	note_type 12, 2, 4
	note D_, 4
	note C_, 4
	octave 5
	note A_, 2
	note G_, 2
	note A_, 2
	note B_, 2
	octave 6
	note C_, 4
	octave 5
	note G_, 4
	note A_, 2
	note G_, 2
	note A_, 2
	note B_, 2
	octave 6
	note C_, 4
	note Cs, 4
	note D_, 12
	note C_, 4
	octave 5
	note B_, 12
	note E_, 2
	note F_, 2
	sound_loop 0, gbs_lavendertown_Ch3.mainloop

	.align 4
	.global gbs_lavendertown_Header
gbs_lavendertown_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_lavendertown_Ch1
	.int gbs_lavendertown_Ch2
	.int gbs_lavendertown_Ch3
