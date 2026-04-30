	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Mantine calls bodies from Natu_Ch5 and Sunflora_Ch6/Ch8 (shared with Natu_Ch6/Ch8).
@ All referenced subroutine data is inlined below.

@ Inlined Natu Ch5 body1 (falls through into body2; sound_ret at end of body2 returns to caller)
gbs_cry_mantine_natu_ch5_body1:
	square_note 4, 15, 8, 1969
	square_note 4, 15, 8, 1968
	square_note 4, 4, 8, 1967
gbs_cry_mantine_natu_ch5_body2:
	square_note 4, 15, 8, 1970
	square_note 4, 15, 8, 1971
	square_note 4, 4, 8, 1972
	sound_ret

@ Inlined Sunflora/Natu Ch6 body1 (falls through into body2)
gbs_cry_mantine_sunflora_ch6_body1:
	duty_cycle_pattern 3, 3, 0, 2
	square_note 4, 15, 8, 1970
	square_note 4, 15, 8, 1969
	square_note 4, 2, 8, 1968
gbs_cry_mantine_sunflora_ch6_body2:
	square_note 4, 15, 8, 1972
	square_note 4, 15, 8, 1974
	square_note 4, 4, 8, 1976
	sound_ret

@ Inlined Sunflora/Natu Ch8 body1 (falls through into body2)
gbs_cry_mantine_sunflora_ch8_body1:
	noise_note 4, 8, 8, 5
	noise_note 4, 8, 8, 4
	noise_note 4, 3, 8, 3
gbs_cry_mantine_sunflora_ch8_body2:
	noise_note 4, 8, 8, 5
	noise_note 4, 8, 8, 4
	noise_note 4, 8, 7, 4
	sound_ret

gbs_cry_mantine_Ch5:
	gbs_switch 4
	duty_cycle 0
	sound_call gbs_cry_mantine_natu_ch5_body1
	sound_call gbs_cry_mantine_natu_ch5_body2
	sound_ret

gbs_cry_mantine_Ch6:
	gbs_switch 5
	sound_call gbs_cry_mantine_sunflora_ch6_body1
	sound_call gbs_cry_mantine_sunflora_ch6_body2
	sound_ret

gbs_cry_mantine_Ch8:
	gbs_switch 7
	sound_call gbs_cry_mantine_sunflora_ch8_body1
	sound_call gbs_cry_mantine_sunflora_ch8_body2
	sound_ret

	.align 4
	.global gbs_cry_mantine_Header
gbs_cry_mantine_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_mantine_Ch5
	.int gbs_cry_mantine_Ch6
	.int gbs_cry_mantine_Ch8
