	.arch msp430g2553
	.p2align 1,0
	.text

	.global red_control
	.extern red_on

	.data
	.align 2
red_state: .word 0
	
	.text
red_control:
	add.b	#1, &red_state
	cmp.b   &red_state, r12
	jhs 	skip
	mov.b   #1, &red_on
	mov.b   #0, &red_state
	jmp 	end
skip:
	mov.b   #0, &red_on
end:
	ret
