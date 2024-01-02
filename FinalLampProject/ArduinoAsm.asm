.include "m328pdef.inc"
.include "delay_Macro.inc"
.include "UART_Macros.inc"

.cseg
.org 0x0000
	
	SBI DDRB, PB5		; PB5 set as an OUTPUT pin (Blue)
	SBI DDRB, PB4		; PB4 set as an OUTPUT pin (Green)
	SBI DDRB, PB3		; PB3 set as an OUTPUT pin (Red)
	SBI DDRB, PB2		; PB2 set as an OUTPUT pin (Buzzer)
	SBI DDRB, PB1		; PB1 set as an OUTPUT pin (BIG LIGHT)
	CBI DDRB, PD7	; 7 number
	CBI DDRB, PD6
	CBI DDRB, PD5

	; Initialize UART for serial communication at 9600 bps
	Serial_begin

loop:
	; Check if there is data available in the UART receive buffer


	; Read the received byte from the UART
	; Now r16 contains the received byte

	; Check the received byte and select the appropriate sequence
	SBIS PIND,PD7
	rjmp P1
	
yellow_sequence:
	SBI PORTB, PB4		; PB4 pin --> HIGH (5V) --> Green LED ON
	SBI PORTB, PB3		; PB3 pin --> HIGH (5V) --> Red LED ON
	SBI PORTB, PB2		; PB2 pin --> HIGH (5V) --> Buzzer ON
	delay 1000
	CBI PORTB, PB4		; PB4 pin --> LOW  (0V) --> Green LED OFF
	CBI PORTB, PB3		; PB3 pin --> LOW  (0V) --> Red LED OFF
	CBI PORTB, PB2		; PB2 pin --> LOW  (0V) --> Buzzer OFF
	rjmp delay_and_continue
P1:
	SBIS PIND,PD6
	rjmp P2
	
magenta_sequence:
	SBI PORTB, PB3		; PB3 pin --> HIGH (5V) --> Red LED ON
	SBI PORTB, PB5		; PB5 pin --> HIGH (5V) --> Blue LED ON
	SBI PORTB, PB2		; PB2 pin --> HIGH (5V) --> Buzzer ON
	delay 1000
	CBI PORTB, PB3		; PB3 pin --> LOW  (0V) --> Red LED OFF
	CBI PORTB, PB5		; PB5 pin --> LOW  (0V) --> Blue LED OFF
	CBI PORTB, PB2		; PB2 pin --> LOW  (0V) --> Buzzer OFF
	rjmp delay_and_continue
P2:
	SBIS PIND,PD5
	rjmp P3

white_sequence:
	SBI PORTB, PB3		; PB3 pin --> HIGH (5V) --> Red LED ON
	SBI PORTB, PB4		; PB4 pin --> HIGH (5V) --> Green LED ON
	SBI PORTB, PB5		; PB5 pin --> HIGH (5V) --> Blue LED ON
	SBI PORTB, PB2		; PB2 pin --> HIGH (5V) --> Buzzer ON
	delay 1000
	CBI PORTB, PB3		; PB3 pin --> LOW  (0V) --> Red LED OFF
	CBI PORTB, PB4		; PB4 pin --> LOW  (0V) --> Green LED OFF
	CBI PORTB, PB5		; PB5 pin --> LOW  (0V) --> Blue LED OFF
	CBI PORTB, PB2		; PB2 pin --> LOW  (0V) --> Buzzer OFF
	rjmp delay_and_continue
P3:
	SBIS PIND,PD4
	rjmp P4

lamp_sequence:
		delay 1000
	SBI PORTB, PB1		; 
	rjmp delay_and_continue
P4:
	CBI PORTB, PB3		; PB3 pin --> LOW  (0V) --> Red LED OFF
	CBI PORTB, PB4		; PB4 pin --> LOW  (0V) --> Green LED OFF
	CBI PORTB, PB5		; PB5 pin --> LOW  (0V) --> Blue LED OFF
	CBI PORTB, PB2		; PB2 pin --> LOW  (0V) --> Buzzer OFF
	CBI PORTB, PB1		; PB2 pin --> LOW  (0V) --> Buzzer OFF
	
delay_and_continue:
	; Common delay and continue logic

	rjmp loop


