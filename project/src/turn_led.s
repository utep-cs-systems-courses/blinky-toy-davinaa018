turn_on_leds:
    mov #0, r15             ; Initialize the loop counter i to 0

loop:
    ; Turn on LED_RED
    bis #LED_RED, &P1OUT    ; Set P1OUT to turn on LED_RED
    mov #10000, r14         ; Load 10000 into r14 (delay cycles value)
    call #delay_cycles      ; Call the delay_cycles function

    ; Turn on LED_GREEN
    bis #LED_GREEN, &P1OUT  ; Set P1OUT to turn on LED_GREEN
    mov #10000, r14         ; Load 10000 into r14 (delay cycles value)
    call #delay_cycles      ; Call the delay_cycles function

    ; Turn off LED_RED and turn on LED_GREEN
    bic #LED_RED, &P1OUT    ; Clear P1OUT to turn off LED_RED
    mov #10000, r14         ; Load 10000 into r14 (delay cycles value)
    call #delay_cycles      ; Call the delay_cycles function

    ; Turn off LED_GREEN
    bic #LED_GREEN, &P1OUT  ; Clear P1OUT to turn off LED_GREEN
    mov #10000, r14         ; Load 10000 into r14 (delay cycles value)
    call #delay_cycles      ; Call the delay_cycles function

    inc r15                 ; Increment i by 1
    cmp #1000, r15          ; Compare i with 1000
    jl loop                 ; Jump back to loop if i < 1000

    ret                     ; Return from the function
