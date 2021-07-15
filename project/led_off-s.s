	.arch msp430g2553
	.p2align 1,0
	.text

	.global led_off
	.extern red_on
	.extern green_on

led_off:
	mov #0, &red_on
	mov #0, &green_on
	pop r0
