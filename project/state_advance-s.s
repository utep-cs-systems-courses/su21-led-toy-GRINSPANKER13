	.arch msp4302553
	.p2align 1,0
	
	.data
	.align 2

jt:	.word default		; jt[0]
	.word case_1		; jt[1]
	.word case_2		; jt[2]
	.word case_3		; jt[3]

	.text
	.global state_advance
	.extern led_off
	.extern red_control
	.extern green_control
	.extern buzzer_set_period
	.extern led_changed
	.extern led_update
	
state_advance:
	cmp 	#4, r12			; 
	jhs 	default			; jmp if s >= 4
	add 	r12, r12		; 2*s
	mov 	jt(r12), r0		; r0 is pc, jmp jt[s]
case_1:
	mov.b 	#1, r12		
	call 	#red_control
	mov.b 	#1, r12
	call 	#green_control
	mov.w	#1000, r12
	call 	#buzzer_set_period
	jmp 	out
case_2:
	mov.b 	#5, r12
	call 	#red_control
	mov.b 	#5, r12
	call 	#green_control
	mov.w	#3000, r12
	call	#buzzer_set_period
	jmp out
case_3:
	mov.b 	#80, r12
	call	#red_control
	mov.b	#80, r12
	call	#green_control
	mov.w	#6000, r12
	call	#buzzer_set_period
	jmp	out
default:
	call 	#led_off
	mov.b	#0, r12
	call	#buzzer_set_period
out:
	mov.b 	#1, &led_changed
	call 	#led_update
	ret
