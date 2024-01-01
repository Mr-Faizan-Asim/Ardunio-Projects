.include "m328pdef.inc"
.include "delay_Macro.inc"

.cseg
.org 0x0000
	
	SBI DDRB, PB5		; PB5 set as an OUTPUT pin (Blue)
	SBI DDRB, PB4		; PB4 set as an OUTPUT pin (Green)
	SBI DDRB, PB3		; PB3 set as an OUTPUT pin (Red)
	SBI DDRB, PB2		; PB3 set as an OUTPUT pin (Buzzer)

loop:
	; Yellow
	SBI PORTB, PB4		; PB4 pin --> HIGH (5V) --> Green LED ON
	SBI PORTB, PB3		; PB3 pin --> HIGH (5V) --> Red LED ON
	SBI PORTB, PB2		; PB2 pin --> HIGH (5V) --> Buzzer ON
	delay 1000
	CBI PORTB, PB4		; PB4 pin --> LOW  (0V) --> Green LED OFF
	CBI PORTB, PB3		; PB3 pin --> LOW  (0V) --> Red LED OFF
	CBI PORTB, PB2		; PB2 pin --> LOW  (0V) --> Buzzer OFF
	delay 1000
	; Magneta
	SBI PORTB, PB3		; PB3 pin --> HIGH (5V) --> Red LED ON
	SBI PORTB, PB5		; PB5 pin --> HIGH (5V) --> Blue LED ON
	SBI PORTB, PB2		; PB2 pin --> HIGH (5V) --> Buzzer ON
	delay 1000
	CBI PORTB, PB3		; PB3 pin --> LOW  (0V) --> Red LED OFF
	CBI PORTB, PB5		; PB5 pin --> LOW  (0V) --> Blue LED OFF
	CBI PORTB, PB2		; PB2 pin --> LOW  (0V) --> Buzzer OFF
	delay 1000
	; White Light
	SBI PORTB, PB3		; PB3 pin --> HIGH (5V) --> Red LED ON
	SBI PORTB, PB4		; PB4 pin --> HIGH (5V) --> Green LED ON
	SBI PORTB, PB5		; PB5 pin --> HIGH (5V) --> Blue LED ON
	SBI PORTB, PB2		; PB2 pin --> HIGH (5V) --> Buzzer ON
	delay 1000
	CBI PORTB, PB3		; PB3 pin --> LOW  (0V) --> Red LED OFF
	CBI PORTB, PB4		; PB4 pin --> LOW  (0V) --> Green LED OFF
	CBI PORTB, PB5		; PB5 pin --> LOW  (0V) --> Blue LED OFF
	CBI PORTB, PB2		; PB2 pin --> LOW  (0V) --> Buzzer OFF
	delay 1000
	; Musical Notes
; Play note C
    SBI PORTB, PB2      ; PB2 pin --> HIGH (5V) --> Buzzer ON
    delay 300
    CBI PORTB, PB2      ; PB2 pin --> LOW  (0V) --> Buzzer OFF
    delay 100

    ; Play note C
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Play note G
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Play note G
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Play note A
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Play note A
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Play note G
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Pause
    delay 300

    ; Play note F
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Play note F
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Play note E
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Play note E
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Play note D
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Play note D
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Play note C
    SBI PORTB, PB2
    delay 300
    CBI PORTB, PB2
    delay 100

    ; Pause
    delay 300

	
	; Musical Notes EndZ
		

rjmp loop				; stay in infinite loop

