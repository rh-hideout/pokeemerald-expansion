	.include "MPlayDef.s"

	.equ	mus_aqua_magma_hideout_grp, voicegroup076
	.equ	mus_aqua_magma_hideout_pri, 0
	.equ	mus_aqua_magma_hideout_rev, reverb_set+50
	.equ	mus_aqua_magma_hideout_mvl, 84
	.equ	mus_aqua_magma_hideout_key, 0
	.equ	mus_aqua_magma_hideout_tbs, 1
	.equ	mus_aqua_magma_hideout_exg, 1
	.equ	mus_aqua_magma_hideout_cmp, 1

	.section .rodata
	.global	mus_aqua_magma_hideout
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_aqua_magma_hideout_1:
	.byte		VOL   , 127*mus_aqua_magma_hideout_mvl/mxv
	.byte	KEYSH , mus_aqua_magma_hideout_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 90*mus_aqua_magma_hideout_tbs/2
	.byte		VOICE , 0
	.byte		N48   , Bn1 , v052
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N48   , An1 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 001   ----------------------------------------
mus_aqua_magma_hideout_1_001:
	.byte		N48   , Gn1 , v052
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N36   , Fs4 , v052, gtp3
	.byte	W36
	.byte	W03
	.byte		N03   , En4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte	PEND
@ 002   ----------------------------------------
	.byte		N12   , Bn1 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Fs2 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N24   , An2 
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An1 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Fs2 
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N24   , An2 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_aqua_magma_hideout_1_001
@ 004   ----------------------------------------
	.byte		N12   , Dn2 , v052
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        An2 
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn3 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        En3 
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N48   , Fs3 
	.byte		N12   , En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
@ 005   ----------------------------------------
	.byte		N48   , Cs2 
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N24   , Cs2 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Ds2 
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Fn2 
	.byte		N12   , Fs4 
	.byte	W12
@ 006   ----------------------------------------
	.byte		        Fs2 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        An2 
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Cs3 
	.byte		N12   , An4 
	.byte	W12
	.byte		        Fs3 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        An3 
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Bn3 
	.byte		N12   , An4 
	.byte	W12
	.byte		N24   , Cs4 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
@ 007   ----------------------------------------
	.byte		        En2 
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn2 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Bn2 
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Dn3 
	.byte		N12   , An4 
	.byte	W12
	.byte		N48   , En3 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
@ 008   ----------------------------------------
	.byte		TIE   , Dn2 
	.byte		N12   , An4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 009   ----------------------------------------
	.byte		        An4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		EOT   , Dn2 
	.byte		TIE   , Dn1 
	.byte		N12   , An3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		TIE   , Dn4 
	.byte	W12
@ 010   ----------------------------------------
	.byte	W96
	.byte		EOT   , Dn1 
	.byte		        Dn4 
@ 011   ----------------------------------------
	.byte		N48   , Dn2 
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        Cs2 
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
@ 012   ----------------------------------------
	.byte		N96   , Bn1 
	.byte		N72   , Bn3 
	.byte	W84
	.byte		N06   
	.byte	W06
	.byte		        Cs4 
	.byte	W06
@ 013   ----------------------------------------
	.byte		N48   , Bn1 
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        An1 
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
@ 014   ----------------------------------------
	.byte		N72   , Bn1 
	.byte		N72   , Fs2 
	.byte		N72   , Bn2 
	.byte		N96   , Bn3 
	.byte	W48
	.byte		N48   , Gn3 
	.byte	W24
	.byte		N24   , Fs1 
	.byte		N24   , Fs2 
	.byte	W24
@ 015   ----------------------------------------
	.byte		N96   , En1 
	.byte		N96   , En2 
	.byte		N96   , Bn2 
	.byte		N96   , Dn3 
	.byte		N96   , En3 
	.byte	W48
	.byte		N36   , Fs4 
	.byte	W36
	.byte		N06   , En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
@ 016   ----------------------------------------
	.byte		N96   , An1 
	.byte		N96   , En2 
	.byte		N96   , An2 
	.byte		N96   , Cs4 
	.byte	W48
	.byte		N24   , An3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
@ 017   ----------------------------------------
	.byte		N96   , Fs1 
	.byte		N96   , Cs2 
	.byte		N96   , Fs2 
	.byte		N96   , Cs3 
	.byte		N96   , En3 
	.byte		N96   , Fs3 
	.byte	W48
	.byte		N36   , En4 
	.byte	W36
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
@ 018   ----------------------------------------
	.byte		N48   , Bn1 
	.byte		N48   , Fs2 
	.byte		N48   , Bn2 
	.byte		N48   , Dn3 
	.byte		N48   , Fs3 
	.byte		N48   , Bn3 
	.byte	W48
	.byte		        An1 
	.byte		N48   , An2 
	.byte		N48   , Cs3 
	.byte		N48   , Fs3 
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
@ 019   ----------------------------------------
	.byte		N48   , Gn1 
	.byte		N48   , Gn2 
	.byte		N24   , Bn2 
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Dn3 
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N48   , An1 
	.byte		N48   , An2 
	.byte		N24   , Cs3 
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Dn3 
	.byte		N24   , Dn4 
	.byte	W24
@ 020   ----------------------------------------
	.byte		N48   , Dn1 
	.byte		N48   , Dn2 
	.byte		N48   , Dn3 
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        Cs1 
	.byte		N48   , Cs2 
	.byte		N24   , Cs3 
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Dn3 
	.byte		N24   , Dn4 
	.byte	W24
@ 021   ----------------------------------------
	.byte		N96   , Bn0 
	.byte		N96   , Bn1 
	.byte		N96   , Bn2 
	.byte		N84   , Bn3 
	.byte	W24
	.byte		N72   , An2 
	.byte		N72   , An4 
	.byte	W60
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
@ 022   ----------------------------------------
	.byte		N48   , Bn0 
	.byte		N48   , Bn1 
	.byte		N48   , Dn3 
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        An0 
	.byte		N48   , An1 
	.byte		N24   , Cs3 
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Fs3 
	.byte		N24   , Fs4 
	.byte	W24
@ 023   ----------------------------------------
	.byte		N96   , Bn0 
	.byte		N96   , Bn1 
	.byte		N72   , Bn2 
	.byte		N72   , Bn3 
	.byte	W24
	.byte		N36   , Gn2 
	.byte		N72   , Gn4 
	.byte	W36
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
@ 024   ----------------------------------------
	.byte		N48   , Gn0 
	.byte		N48   , Gn1 
	.byte		N48   , Fs3 
	.byte		N48   , Bn3 
	.byte		N48   , Dn4 
	.byte	W48
	.byte		N24   , Fs0 
	.byte		N24   , Fs1 
	.byte		N24   , Fs3 
	.byte		N24   , As3 
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        As0 
	.byte		N24   , As1 
	.byte		N24   , Fs3 
	.byte		N24   , Fs4 
	.byte	W24
@ 025   ----------------------------------------
	.byte		N48   , Bn0 
	.byte		N48   , Bn1 
	.byte		N48   , Dn3 
	.byte		N48   , Fs3 
	.byte		N48   , Bn3 
	.byte	W48
	.byte		        An0 
	.byte		N48   , An1 
	.byte		N24   , Cs3 
	.byte		N24   , Fs3 
	.byte		N24   , An3 
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Dn3 
	.byte		N24   , Dn4 
	.byte	W24
@ 026   ----------------------------------------
	.byte		N48   , Gn0 
	.byte		N48   , Gn1 
	.byte		N24   , Gn2 
	.byte		N24   , Dn3 
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Fs3 
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N48   , Gs0 
	.byte		N48   , Gs1 
	.byte		N24   , Bn3 
	.byte		N24   , En4 
	.byte	W24
	.byte		        Gs3 
	.byte		N24   , Dn4 
	.byte	W24
@ 027   ----------------------------------------
	.byte		N72   , An0 
	.byte		N72   , An1 
	.byte		N36   , Cs3 
	.byte		N96   , Cs4 
	.byte	W24
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N48   , An2 
	.byte	W24
	.byte		N24   , Gn0 
	.byte		N24   , Gn1 
	.byte	W24
@ 028   ----------------------------------------
	.byte		N96   , Fs0 
	.byte		N96   , Fs1 
	.byte		TIE   , An3 
	.byte		TIE   , An4 
	.byte	W24
	.byte		N12   , En2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
@ 029   ----------------------------------------
	.byte		N96   , Bn0 
	.byte		N96   , Bn1 
	.byte	W24
	.byte		N12   , An2 
	.byte	W12
	.byte		EOT   , An3 
	.byte		        An4 
	.byte		N12   , Bn2 
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Cs3 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Dn3 
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        En3 
	.byte		N12   , An4 
	.byte	W12
	.byte		        Bn2 
	.byte		N12   , Fs4 
	.byte	W12
@ 030   ----------------------------------------
	.byte		N96   , En0 
	.byte		N96   , En1 
	.byte		TIE   , Gn3 
	.byte		TIE   , Gn4 
	.byte	W24
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
@ 031   ----------------------------------------
	.byte		N96   , An0 
	.byte		N96   , An1 
	.byte	W12
	.byte		N12   , En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		EOT   , Gn3 
	.byte		        Gn4 
	.byte		N12   , An2 
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Bn2 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Cs3 
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn3 
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cs3 
	.byte		N12   , Cs4 
	.byte	W12
@ 032   ----------------------------------------
	.byte		N96   , Fs0 
	.byte		N96   , Fs1 
	.byte		N84   , An3 
	.byte		N84   , An4 
	.byte	W24
	.byte		N12   , En2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cs3 
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 
	.byte	W12
@ 033   ----------------------------------------
	.byte		N96   , Bn0 
	.byte		N96   , Bn1 
	.byte		N84   , Dn3 
	.byte		N84   , Dn4 
	.byte	W24
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
@ 034   ----------------------------------------
	.byte		N96   , Cs1 
	.byte		N96   , Cs2 
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N24   , Cs3 
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N24   , En3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N24   , Gn3 
	.byte		N12   , En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
@ 035   ----------------------------------------
	.byte		N96   , Fs1 
	.byte		N96   , Cs2 
	.byte		N96   , Fs2 
	.byte		N96   , Fs3 
	.byte		N96   , As3 
	.byte		N96   , Cs4 
	.byte	W96
@ 036   ----------------------------------------
	.byte		N24   , Bn1 
	.byte		N84   , Dn4 
	.byte	W24
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Bn2 
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Bn2 
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 037   ----------------------------------------
	.byte		N24   , En2 
	.byte		N36   , Gn3 
	.byte	W24
	.byte		N24   , Gn2 
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N24   , Gn2 
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N24   , Gn2 
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 038   ----------------------------------------
	.byte		N24   , An1 
	.byte		N84   , Cs4 
	.byte	W24
	.byte		N24   , Bn2 
	.byte		N24   , Cs3 
	.byte		N24   , En3 
	.byte	W24
	.byte		        Bn2 
	.byte		N24   , Cs3 
	.byte		N24   , En3 
	.byte	W24
	.byte		        An2 
	.byte		N24   , Cs3 
	.byte		N24   , En3 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 039   ----------------------------------------
	.byte		N24   , Dn2 
	.byte		N36   , Fs3 
	.byte	W24
	.byte		N24   , An2 
	.byte		N24   , Cs3 
	.byte		N24   , Dn3 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		N24   , An2 
	.byte		N24   , Cs3 
	.byte		N24   , Dn3 
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N24   , An2 
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 040   ----------------------------------------
	.byte		N24   , Gn1 
	.byte		N72   , Bn3 
	.byte	W24
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Bn2 
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Bn2 
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 041   ----------------------------------------
	.byte		N24   , Gs1 
	.byte		N60   , Dn4 
	.byte	W24
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Bn2 
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 042   ----------------------------------------
	.byte		N24   , Bn1 
	.byte		N96   , Fs3 
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N24   , Bn2 
	.byte		N24   , Cs3 
	.byte		N24   , En3 
	.byte		N72   , Cs4 
	.byte	W24
	.byte		N24   , Bn2 
	.byte		N24   , Cs3 
	.byte		N24   , En3 
	.byte	W24
	.byte		        Gn2 
	.byte		N24   , Cs3 
	.byte		N24   , En3 
	.byte	W24
@ 043   ----------------------------------------
	.byte		        Fs1 
	.byte		N48   , En3 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N24   , As2 
	.byte		N24   , Cs3 
	.byte		N72   , As3 
	.byte	W24
	.byte		N24   , As2 
	.byte		N24   , Cs3 
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        As2 
	.byte		N24   , Cs3 
	.byte		N24   , Fs3 
	.byte	W24
@ 044   ----------------------------------------
	.byte		N96   , Bn0 
	.byte		N96   , Bn1 
	.byte		N24   , Fs3 
	.byte		N84   , Dn4 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N12   
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Dn2 
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Dn2 
	.byte		N24   , Fs3 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N12   
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Dn2 
	.byte		N12   , Dn3 
	.byte		N12   , Fs3 
	.byte	W12
@ 045   ----------------------------------------
	.byte		N96   , En0 
	.byte		N96   , En1 
	.byte		N36   , Bn2 
	.byte		N36   , Gn3 
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs3 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        En2 
	.byte		N12   , En3 
	.byte		N12   , En4 
	.byte	W12
	.byte		        En2 
	.byte		N12   , En3 
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En2 
	.byte		N12   , En3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        En2 
	.byte		N12   , En3 
	.byte		N12   , Dn4 
	.byte	W12
@ 046   ----------------------------------------
	.byte		N96   , An0 
	.byte		N96   , An1 
	.byte		N60   , Gn3 
	.byte		N84   , Cs4 
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cs3 
	.byte		N12   , An4 
	.byte	W12
@ 047   ----------------------------------------
	.byte		N96   , Dn0 
	.byte		N96   , Dn1 
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N24   , Cs3 
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N24   , Fs3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N24   , Cs3 
	.byte		N12   , En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
@ 048   ----------------------------------------
	.byte		N96   , Gn0 
	.byte		N96   , Gn1 
	.byte		N72   , Bn3 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Bn2 
	.byte		N12   , Dn4 
	.byte	W12
@ 049   ----------------------------------------
	.byte		N96   , Gs0 
	.byte		N96   , Gs1 
	.byte		N60   , Dn4 
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fs2 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Gs2 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Bn2 
	.byte		N12   , Dn4 
	.byte	W12
@ 050   ----------------------------------------
	.byte		N96   , An0 
	.byte		N72   , An1 
	.byte		N96   , Fs3 
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N24   , Cs2 
	.byte		N24   , Cs3 
	.byte		N72   , Cs4 
	.byte	W24
	.byte		N24   , An1 
	.byte		N24   , An2 
	.byte	W24
	.byte		        Gn1 
	.byte		N24   , Gn2 
	.byte	W24
@ 051   ----------------------------------------
	.byte		N96   , Fs0 
	.byte		N96   , Fs1 
	.byte		N36   , En3 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        En3 
	.byte		N48   , As3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Gn3 
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        As3 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
@ 052   ----------------------------------------
	.byte		N96   , Bn0 
	.byte		N96   , Bn1 
	.byte		N84   , Dn4 
	.byte		N84   , Fs4 
	.byte		N84   , An4 
	.byte		N84   , Dn5 
	.byte	W24
	.byte		N24   , Dn2 
	.byte		N24   , Fs2 
	.byte		N24   , Bn2 
	.byte	W24
	.byte		        Fs2 
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Bn2 
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte	W12
	.byte		N12   
	.byte		N12   , Fs4 
	.byte	W12
@ 053   ----------------------------------------
	.byte		N96   , En0 
	.byte		N96   , En1 
	.byte		N36   , Gn3 
	.byte		N36   , Bn3 
	.byte		N36   , Dn4 
	.byte		N36   , Gn4 
	.byte	W24
	.byte		N24   , En2 
	.byte		N24   , Gn2 
	.byte		N24   , Bn2 
	.byte	W12
	.byte		N12   , Fs4 
	.byte		N12   , Fs5 
	.byte	W12
	.byte		N24   , Gn2 
	.byte		N24   , Bn2 
	.byte		N24   , En3 
	.byte		N12   , En4 
	.byte		N12   , En5 
	.byte	W12
	.byte		        Dn4 
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N24   , Bn2 
	.byte		N24   , En3 
	.byte		N24   , Gn3 
	.byte		N12   , Cs4 
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Dn4 
	.byte		N12   , Dn5 
	.byte	W12
@ 054   ----------------------------------------
	.byte		N96   , An0 
	.byte		N96   , An1 
	.byte		N84   , Cs4 
	.byte		N84   , En4 
	.byte		N84   , An4 
	.byte		N84   , Cs5 
	.byte	W24
	.byte		N24   , Cs2 
	.byte		N24   , En2 
	.byte		N24   , An2 
	.byte	W24
	.byte		        En2 
	.byte		N24   , An2 
	.byte		N24   , Cs3 
	.byte	W24
	.byte		        An2 
	.byte		N24   , Cs3 
	.byte		N24   , En3 
	.byte	W12
	.byte		N12   , An4 
	.byte		N12   , An5 
	.byte	W12
@ 055   ----------------------------------------
	.byte		N96   , Dn0 
	.byte		N96   , Dn1 
	.byte		N12   , Gn4 
	.byte		N12   , Gn5 
	.byte	W12
	.byte		        Fs4 
	.byte		N12   , Fs5 
	.byte	W12
	.byte		N24   , An1 
	.byte		N24   , Dn2 
	.byte		N24   , Fs2 
	.byte		N12   , En4 
	.byte		N12   , En5 
	.byte	W12
	.byte		        Dn4 
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N24   , Dn2 
	.byte		N24   , Fs2 
	.byte		N24   , An2 
	.byte		N12   , Cs4 
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Dn4 
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N24   , Fs2 
	.byte		N24   , An2 
	.byte		N24   , Dn3 
	.byte		N12   , En4 
	.byte		N12   , En5 
	.byte	W12
	.byte		        Fs4 
	.byte		N12   , Fs5 
	.byte	W12
@ 056   ----------------------------------------
	.byte		N96   , Gn0 
	.byte		N96   , Gn1 
	.byte		N72   , Bn3 
	.byte		N72   , Dn4 
	.byte		N72   , Fs4 
	.byte		N72   , Bn4 
	.byte	W24
	.byte		N24   , Dn2 
	.byte		N24   , Gn2 
	.byte		N24   , Bn2 
	.byte	W24
	.byte		        Gn2 
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Bn2 
	.byte		N24   , Dn3 
	.byte		N24   , Gn3 
	.byte		N12   , Cs4 
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Dn4 
	.byte		N12   , Dn5 
	.byte	W12
@ 057   ----------------------------------------
	.byte		N96   , Gs0 
	.byte		N96   , Gs1 
	.byte		N60   , Dn4 
	.byte		N60   , Fs4 
	.byte		N60   , An4 
	.byte		N60   , Dn5 
	.byte	W24
	.byte		N24   , Bn1 
	.byte		N24   , Dn2 
	.byte	W24
	.byte		N24   
	.byte		N24   , Gs2 
	.byte		N24   , Bn2 
	.byte	W12
	.byte		N12   , Bn3 
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N24   , Gs2 
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte		N12   , Cs4 
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Dn4 
	.byte		N12   , Dn5 
	.byte	W12
@ 058   ----------------------------------------
	.byte		N96   , An0 
	.byte		N96   , An1 
	.byte		N12   , Dn4 
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Cs4 
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N24   , Cs2 
	.byte		N24   , En2 
	.byte		N24   , An2 
	.byte		N72   , Cs4 
	.byte		N72   , En4 
	.byte		N72   , Gn4 
	.byte		N72   , Cs5 
	.byte	W24
	.byte		N24   , En2 
	.byte		N24   , An2 
	.byte		N24   , Cs3 
	.byte	W24
	.byte		        An2 
	.byte		N24   , Cs3 
	.byte		N24   , En3 
	.byte	W24
@ 059   ----------------------------------------
	.byte		N96   , As0 
	.byte		N60   , As1 
	.byte		N12   , Bn3 
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        En2 
	.byte		N12   , As3 
	.byte		N12   , As4 
	.byte	W12
	.byte		        Fs2 
	.byte		N72   , As3 
	.byte		N72   , Cs4 
	.byte		N72   , Fs4 
	.byte		N72   , As4 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
@ 060   ----------------------------------------
	.byte		N96   , Bn0 
	.byte		N96   , Bn1 
	.byte		N96   , Bn2 
	.byte		N96   , Dn3 
	.byte		N96   , Fs3 
	.byte		N96   , Bn3 
	.byte		N96   , Dn4 
	.byte		N96   , Fs4 
	.byte		N96   , Bn4 
	.byte	W96
@ 061   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

mus_aqua_magma_hideout:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_aqua_magma_hideout_pri	@ Priority
	.byte	mus_aqua_magma_hideout_rev	@ Reverb.

	.word	mus_aqua_magma_hideout_grp

	.word	mus_aqua_magma_hideout_1

	.end
