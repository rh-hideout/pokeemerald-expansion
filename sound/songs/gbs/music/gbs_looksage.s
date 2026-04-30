	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_looksage_Ch1:
	gbs_switch 0
	tempo 144
	stereo_panning FALSE, TRUE
	volume 7, 7
	duty_cycle 3
	note_type 12, 11, 3
	rest 2
	rest 16
	sound_call gbs_looksage_Ch1.sub1
	volume_envelope 11, 3
	octave 3
	note D_, 2
	volume_envelope 9, 3
	note D_, 2
	volume_envelope 11, 3
	note E_, 2
	volume_envelope 9, 3
	note E_, 2
	volume_envelope 11, 3
	note A_, 2
	volume_envelope 9, 3
	note A_, 2
	volume_envelope 11, 3
	note F_, 2
	volume_envelope 9, 3
	note F_, 2
gbs_looksage_Ch1.mainloop:
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 9, 3
	note D_, 2
	volume_envelope 11, 3
	octave 2
	note B_, 2
	volume_envelope 9, 3
	note B_, 2
	volume_envelope 11, 3
	note A_, 2
	volume_envelope 9, 3
	note A_, 2
	volume_envelope 11, 3
	note B_, 2
	volume_envelope 9, 3
	note B_, 2
	volume_envelope 11, 3
	octave 3
	note D_, 2
	volume_envelope 9, 3
	note D_, 2
	volume_envelope 11, 3
	octave 2
	note B_, 2
	volume_envelope 9, 3
	note B_, 2
	volume_envelope 11, 3
	octave 3
	note D_, 2
	volume_envelope 9, 3
	note D_, 2
	volume_envelope 11, 3
	note E_, 2
	volume_envelope 9, 3
	note E_, 2
	volume_envelope 11, 3
	note F_, 2
	volume_envelope 9, 3
	note F_, 2
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 9, 3
	note D_, 2
	volume_envelope 11, 3
	note E_, 2
	volume_envelope 9, 3
	note E_, 2
	volume_envelope 11, 3
	note A_, 2
	volume_envelope 9, 3
	note A_, 2
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 9, 3
	note D_, 2
	volume_envelope 11, 3
	octave 2
	note B_, 2
	volume_envelope 9, 3
	note B_, 2
	volume_envelope 11, 3
	note A_, 2
	volume_envelope 9, 3
	note A_, 2
	volume_envelope 11, 3
	note B_, 2
	volume_envelope 9, 3
	note B_, 2
	sound_call gbs_looksage_Ch1.sub1
	sound_loop 0, gbs_looksage_Ch1.mainloop

gbs_looksage_Ch1.sub1:
	volume_envelope 11, 3
	octave 2
	note E_, 2
	volume_envelope 9, 3
	note E_, 2
	volume_envelope 11, 3
	note A_, 2
	volume_envelope 9, 3
	note A_, 2
	volume_envelope 11, 3
	note B_, 2
	volume_envelope 9, 3
	note B_, 2
	volume_envelope 11, 3
	note A_, 2
	volume_envelope 9, 3
	note A_, 2
	sound_ret

gbs_looksage_Ch3:
	gbs_switch 2
	stereo_panning TRUE, FALSE
	vibrato 22, 2, 3
	note_type 12, 1, 0
	octave 5
	note B_, 1
	octave 6
	note C_, 1
	octave 5
	note B_, 16
	vibrato 7, 2, 3
	note B_, 8
	vibrato 20, 2, 3
	octave 6
	note D_, 6
	note E_, 1
	note F_, 1
	note E_, 14
	note G_, 1
	note Gs, 1
gbs_looksage_Ch3.mainloop:
	note A_, 12
	note B_, 4
	note D_, 9
	note E_, 1
	note F_, 1
	note D_, 1
	vibrato 0, 0, 0
	note E_, 4
	vibrato 7, 2, 3
	note E_, 8
	vibrato 20, 2, 3
	octave 5
	note B_, 8
	octave 6
	note F_, 8
	note_type 6, 1, 0
	note E_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	note C_, 1
	octave 5
	note B_, 1
	note As, 1
	note A_, 1
	rest 4
	octave 6
	note E_, 2
	note F_, 2
	note_type 12, 1, 0
	note E_, 14
	note G_, 1
	note Gs, 1
	sound_loop 0, gbs_looksage_Ch3.mainloop

	.align 4
	.global gbs_looksage_Header
gbs_looksage_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_looksage_Ch1
	.int gbs_looksage_Ch3
