; HAL_Boot.asm - Copyright Luke A.C.A. Rieff - ROC Nijmegen
; Prettty cool huh ;P I know fucking assembly, didn't see that comming right.

; Called after startup.
.extern __HAL_Entry

; Memory Constants
.equ ramend,    0x08FF

; Registers
.equ spl,       0x3D
.equ sph,       0x3E

; Reset Interrupt Handler
.section .text
.globl SYS_Interrupt_Reset
.type SYS_Interrupt_Reset, %function
SYS_Interrupt_Reset:
    ; Sets the stack pointer
    ldi     r16,    ((ramend >> 8) & 0xF)
    out     sph,    r16
    ldi     r16,    ((ramend >> 0) & 0xF)
    out     spl,    r16
    ; Jumps to the __HAL_Entry which basically is the application.
    call    __HAL_Entry
    ; Infinite loop to ensure no undefined behaviour will occur.
    SYS_Interrupt_Reset__SecureLoop:
    rjmp    SYS_Interrupt_Reset__SecureLoop

; Default Interrupt Handler
.section .text
.globl SYS_Interrupt_DefaultHandler
.type SYS_Interrupt_DefaultHandler, %function
SYS_Interrupt_DefaultHandler:
    reti ; Not safe, I know.. Suck my dick.

; Other Interrupt Handlers (Weak-Defs)
.globl SYS_Interrupt_INT0
.weak SYS_Interrupt_INT0
.set SYS_Interrupt_INT0, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_INT1
.weak SYS_Interrupt_INT1
.set SYS_Interrupt_INT1, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_PCINT0
.weak SYS_Interrupt_PCINT0
.set SYS_Interrupt_PCINT0, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_PCINT1
.weak SYS_Interrupt_PCINT1
.set SYS_Interrupt_PCINT1, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_PCINT2
.weak SYS_Interrupt_PCINT2
.set SYS_Interrupt_PCINT2, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_WDT
.weak SYS_Interrupt_WDT
.set SYS_Interrupt_WDT, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_TIMER2_COMPA
.weak SYS_Interrupt_TIMER2_COMPA
.set SYS_Interrupt_TIMER2_COMPA, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_TIMER2_COMPB
.weak SYS_Interrupt_TIMER2_COMPB
.set SYS_Interrupt_TIMER2_COMPB, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_TIMER2_OVF
.weak SYS_Interrupt_TIMER2_OVF
.set SYS_Interrupt_TIMER2_OVF, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_TIMER1_CAPT
.weak SYS_Interrupt_TIMER1_CAPT
.set SYS_Interrupt_TIMER1_CAPT, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_TIMER1_COMPA
.weak SYS_Interrupt_TIMER1_COMPA
.set SYS_Interrupt_TIMER1_COMPA, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_TIMER1_COMPB
.weak SYS_Interrupt_TIMER1_COMPB
.set SYS_Interrupt_TIMER1_COMPB, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_TIMER1_OVF
.weak SYS_Interrupt_TIMER1_OVF
.set SYS_Interrupt_TIMER1_OVF, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_TIMER0_COMPA
.weak SYS_Interrupt_TIMER0_COMPA
.set SYS_Interrupt_TIMER0_COMPA, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_TIMER0_COMPB
.weak SYS_Interrupt_TIMER0_COMPB
.set SYS_Interrupt_TIMER0_COMPB, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_TIMER0_OVF
.weak SYS_Interrupt_TIMER0_OVF
.set SYS_Interrupt_TIMER0_OVF, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_SPI_STC
.weak SYS_Interrupt_SPI_STC
.set SYS_Interrupt_SPI_STC, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_USART_RX
.weak SYS_Interrupt_USART_RX
.set SYS_Interrupt_USART_RX, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_USART_TX
.weak SYS_Interrupt_USART_TX
.set SYS_Interrupt_USART_TX, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_ADC
.weak SYS_Interrupt_ADC
.set SYS_Interrupt_ADC, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_EE_READY
.weak SYS_Interrupt_EE_READY
.set SYS_Interrupt_EE_READY, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_ANALOG_COMP
.weak SYS_Interrupt_ANALOG_COMP
.set SYS_Interrupt_ANALOG_COMP, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_ANALOG_COMP
.weak SYS_Interrupt_ANALOG_COMP
.set SYS_Interrupt_ANALOG_COMP, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_TWI
.weak SYS_Interrupt_TWI
.set SYS_Interrupt_TWI, SYS_Interrupt_DefaultHandler

.globl SYS_Interrupt_SPM_READY
.weak SYS_Interrupt_SPM_READY
.set SYS_Interrupt_SPM_READY, SYS_Interrupt_DefaultHandler

; Interrupt Vectors
.section .vector
.globl SYS_InterruptVector
.type SYS_InterruptVector, %function
SYS_InterruptVector:
    jmp     SYS_Interrupt_Reset ; 1
    jmp     SYS_Interrupt_INT0 ; 2
    jmp     SYS_Interrupt_INT1 ; 3
    jmp     SYS_Interrupt_PCINT0 ; 4
    jmp     SYS_Interrupt_PCINT1 ; 5
    jmp     SYS_Interrupt_PCINT2 ; 6
    jmp     SYS_Interrupt_WDT ; 7
    jmp     SYS_Interrupt_TIMER2_COMPA ; 8
    jmp     SYS_Interrupt_TIMER2_COMPB ; 9
    jmp     SYS_Interrupt_TIMER2_OVF ; 10
    jmp     SYS_Interrupt_TIMER1_CAPT ; 11
    jmp     SYS_Interrupt_TIMER1_COMPA ; 12
    jmp     SYS_Interrupt_TIMER1_COMPB ; 13
    jmp     SYS_Interrupt_TIMER1_OVF ; 14
    jmp     SYS_Interrupt_TIMER0_COMPA ; 15
    jmp     SYS_Interrupt_TIMER0_COMPB ; 16
    jmp     SYS_Interrupt_TIMER0_OVF ; 17
    jmp     SYS_Interrupt_SPI_STC ; 18
    jmp     SYS_Interrupt_USART_RX ; 19
    jmp     SYS_Interrupt_USART_TX ; 20
    jmp     SYS_Interrupt_ADC ; 21
    jmp     SYS_Interrupt_EE_READY ; 22
    jmp     SYS_Interrupt_ANALOG_COMP ; 23
    jmp     SYS_Interrupt_ANALOG_COMP ; 24
    jmp     SYS_Interrupt_TWI ; 25
    jmp     SYS_Interrupt_SPM_READY ; 26
